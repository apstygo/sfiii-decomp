import sys
import re
from dataclasses import dataclass
from pathlib import Path
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry
from pathlib import Path
from ..convert_regs import convert_regs

@dataclass
class Run:
    entries: list[LinkerEntry]
    is_game: bool
    section: str

def split_into_runs(entries: list[LinkerEntry]) -> list[Run]:
    runs: list[Run] = list()
    runs.append(Run(list(), False, ".text"))

    for entry in entries:
        if entry.section_link_type == "pad":
            continue

        entry_is_game = "sf33rd" in str(entry.object_path)
        # print(entry_is_game, entry.object_path, entry.section_link_type)

        if entry.section_link_type != runs[-1].section or entry_is_game != runs[-1].is_game:
            runs.append(Run(list(), entry_is_game, entry.section_link_type))

        runs[-1].entries.append(entry)

    return runs

def strip_path(path: Path) -> str:
    return path.name

class LCFWriter:
    def __init__(self, config_path: Path):
        self.config_path = config_path
        self.file = None
        self.last_line_blank = False

    def __enter__(self) -> 'LCFWriter':
        self.file = open(self.config_path, "w")

        with open("tools/lcf/lcf_header.txt") as header:
            self.file.write(header.read())

        return self

    def __exit__(self, *args):
        with open("tools/lcf/lcf_footer.txt") as footer:
            self.file.write(footer.read())

        self.file.close()

    def write_line(self, line: str):
        self.file.write(f"\t\t{line}\n")
        self.last_line_blank = False

    def blank(self):
        self.file.write("\n")
        self.last_line_blank = True

    def separator(self):
        self.write_line("# " + "=" * 75)

    def begin_section(self, title: str):
        if not self.last_line_blank:
            self.blank()

        self.separator()
        self.write_line(f"# {title}")
        self.separator()
        self.blank()

    def align(self, alignment: int):
        self.write_line(f". = ALIGN(0x{alignment:X});")

    def align_all(self, alignment: int):
        self.write_line(f"ALIGNALL(0x{alignment:X});")

    def add_entry(self, entry: LinkerEntry, section: str):
        self.write_line(f"{strip_path(entry.object_path)} ({section})")

    def add_entries(self, entries: list[LinkerEntry], section: str):
        for entry in entries:
            self.add_entry(entry, section)

    def add_runs(self, runs: list[Run], section: str):
        for run in runs:
            self.add_entries(run.entries, section)

def generate_lcf():
    config_path = Path(sys.argv[1])
    split.main(["config/anniversary/sfiii.anniversary.yaml"], modes="all", verbose=False)
    runs = split_into_runs(split.linker_writer.entries)

    with LCFWriter(config_path) as lcf:
        lcf.write_line("_gp = 0x57A3F0;")

        # text

        lcf.begin_section("text sections")
        lcf.align(0x80)

        text_runs = [x for x in runs if x.section == ".text"]
        first_entry = text_runs[0].entries[0]

        # crt0 special case

        if "crt0" in str(first_entry.object_path):
            lcf.add_entry(first_entry, ".text")
            lcf.align(0x10)
            del runs[0].entries[0]

        for run in text_runs:
            path = str(run.entries[0].object_path)
            is_lib_vib = "libvib" in path
            is_cri = "cri" in path
            alignment = 0x4

            if run.is_game:
                alignment = 0x10
            elif is_lib_vib or is_cri:
                alignment = 0x8

            lcf.align_all(alignment)
            lcf.add_entries(run.entries, ".text")

        lcf.blank()

        for _ in range(2):
            lcf.write_line("WRITEW 0x0; # text section patch for EE pipeline")

        # data/rodata

        lcf.begin_section("data sections")

        data_runs = [x for x in runs if x.section == ".data"]
        lcf.begin_section(".data")
        lcf.align(0x80)
        lcf.align_all(0x8)
        lcf.add_runs(data_runs, ".data")

        rodata_runs = [x for x in runs if x.section == ".rodata"]
        lcf.begin_section(".rodata")
        lcf.align(0x80)
        # lcf.align_all(0x10)
        # lcf.add_runs(rodata_runs, ".rodata")

        rodata_alignment = 0x8

        rodata_increased_alignment = {
            "plbmp", 
            "SYS_sub2",
            "LOSE_PL",
        }

        for run in rodata_runs:
            for entry in run.entries:
                align = rodata_alignment

                if entry.object_path.stem.split(".")[0] in rodata_increased_alignment:
                    align = 0x10

                lcf.align_all(align)
                lcf.add_entry(entry, ".rodata")

        # small data

        lcf.begin_section("small data sections")

        sdata_runs = [x for x in runs if x.section == ".sdata"]
        lcf.align(0x80)
        lcf.align_all(4)
        lcf.add_runs(sdata_runs, ".sdata")

        lcf.blank()

        sbss_runs = [x for x in runs if x.section == ".sbss"]
        lcf.align(0x80)
        lcf.align_all(0x4)
        lcf.add_runs(sbss_runs, ".sbss")

        # bss

        lcf.begin_section("bss sections")

        bss_runs = [x for x in runs if x.section == ".bss"]

        # lcf.align(0x80)
        lcf.align_all(8)

        for run in bss_runs:
            for entry in run.entries:
                lcf.add_entry(entry, ".bss")

                if "cri" in str(entry.object_path):
                    lcf.add_entry(entry, "COMMON")

        lcf.blank()

        # finalize

        lcf.align(0x80)

def main():
    generate_lcf()

    # Patch asm

    nonmatchings = Path("asm/anniversary/nonmatchings")

    for asm_file in nonmatchings.rglob("*.s"):
        text = asm_file.read_text()
        is_cri = "cri" in str(asm_file).split("/")

        if is_cri:
            # spimdisasm adds `.section .rodata` before each rodata peace of CRI.
            # But GNU as expects `.rdata` instead
            text = text.replace(".section .rodata", ".rdata")

            # GNU as expects numbered registers
            text = convert_regs(text)

        text = text.replace("xyzw ACC", "xyzw $ACC")
        text = text.replace("xyz ACC", "xyz $ACC")
        text = re.sub(r"(?<!\$)\bQ\b", r"$Q", text)

        # This allows leaving some funcs that use this literal undecompiled
        text = text.replace("literal_234_00522C90", "\"@98\"")

        asm_file.write_text(text)

if __name__ == "__main__":
    main()
