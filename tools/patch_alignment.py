from elftools.elf.elffile import ELFFile
from pathlib import Path
import sys

# (file, section, index of section within sections of this type) -> alignment
special_cases = {
    ("menu", ".rodata", 9): 16,
    ("menu", ".rodata", 16): 16,
    ("flPADUSR", ".rodata", 0): 16,
    ("Demo_Dat", ".rodata", 0): 16,
    ("chren3rd", ".rodata", 0): 16,
    ("CHARSET", ".rodata", 11): 16,
    ("EFF22", ".rodata", 0): 16,
    ("EFF69", ".rodata", 0): 16,
    ("EFF78", ".rodata", 2): 16,
    ("Eff95", ".rodata", 0): 16,
    ("EFFF2", ".rodata", 0): 16,
    ("EFFF8", ".rodata", 0): 16,
    ("aboutspr", ".rodata", 0): 16,
    ("flps2vram", ".rodata", 10): 16,
    ("flps2debug", ".rodata", 22): 16,
    ("MTRANS", ".rodata", 10): 16,
    ("Sound3rd", ".rodata", 1): 16,
    ("CALDIR", ".rodata", 0): 16,
    ("mcsub", ".rodata", 13): 16,
    ("mcsub", ".rodata", 17): 16,
    ("PLCNT", ".rodata", 4): 16,
    ("EFF00", ".rodata", 0): 16,
    ("knjsub", ".rodata", 0): 16,
    ("msgsub", ".rodata", 0): 16,
    ("Com_Pl", ".rodata", 0): 16,
    ("appear", ".rodata", 1): 16,
    ("PLS02", ".rodata", 3): 16,
    ("CHARSET", ".rodata", 0): 16,

    ("bg_data", ".data", 0): 16,
    ("PulPul", ".data", 0): 16,
    ("flps2vram", ".data", 0): 16,
    ("PulPul", ".data", 1): 16,
    ("Sound3rd", ".data", 0): 16,

    ("bg_data", ".sdata", 0): 16,
    ("VM_DATA", ".sdata", 0): 16,
    ("Demo_Dat", ".sdata", 0): 16,
    ("BBBSCOM", ".sdata", 0): 16,
    ("win_pl", ".sdata", 0): 16,
    ("LOSE_PL", ".sdata", 0): 16,
    ("eff05", ".sdata", 0): 16,
    ("eff06", ".sdata", 0): 16,
    ("EFF09", ".sdata", 0): 16,
    ("EFF26", ".sdata", 0): 16,
    ("EFF48_more_sdata", ".sdata", 0): 16,
    ("sel_pl", ".sdata", 0): 16,
    ("SpuMap", ".sdata", 0): 4,
    ("msgtblj", ".sdata", 0): 16,
    ("knjsub", ".sdata", 0): 16,
    ("msgsub", ".sdata", 0): 16,
    ("msgtble", ".sdata", 0): 16,
    ("reboot", ".sdata", 0): 16,

    ("sbss_579878", ".sbss", 0): 8,
    ("EFF45", ".sbss", 0): 16,
    ("IOConv", ".sbss", 0): 16,
    ("Grade", ".sbss", 0): 16,
    ("Sound3rd", ".sbss", 0): 8,
    ("mcsub", ".sbss", 0): 16,
    ("spgauge", ".sbss", 0): 16,
    ("VITAL", ".sbss", 0): 16,
    ("RANKING", ".sbss", 0): 16,
    ("OBJTEST", ".sbss", 0): 16,
    ("CHARID", ".sbss", 0): 16,
    ("emlMemMap", ".sbss", 0): 16,

    ("bss_6BDA68", ".bss", 0): 8,
    ("iopnotify", ".bss", 0): 8,
    ("cri_cvfs", ".bss", 0): 8,
    ("libdbc", ".bss", 0): 8,
    ("libpad2", ".bss", 0): 8,
    ("color3rd", ".bss", 2): 32,
    ("Sound3rd", ".bss", 0): 256,
    ("Sound3rd", ".bss", 1): 256,
}

def alignment_to_bytes(alignment: int) -> bytes:
    return bytes([
        alignment & 0xFF,
        (alignment >> 8) & 0xFF,
        (alignment >> 16) & 0xFF,
        (alignment >> 24) & 0xFF
    ])

def alignments(path: Path) -> list[tuple[int, int]]:
    with open(path, 'rb') as f:
        elf_file = ELFFile(f)
        elf_header = elf_file.header
        is_c_file = str(path).split(".")[-2] == "c"

        alignments: list[tuple[int, int]] = list()

        # Current index of section among sections of this type.
        # .text -> 3 means this .text section is the 3rd .text section.
        section_indices = {
            ".text": 0,
            ".data": 0,
            ".rodata": 0,
            ".bss": 0,
            ".sbss": 0,
            ".sdata": 0
        }

        for section_index, section in enumerate(elf_file.iter_sections()):
            if section.name not in (".text", ".data", ".rodata", ".bss", ".sbss", ".sdata"):
                continue

            filename = path.stem.split(".")[0]
            section_key = (filename, section.name, section_indices[section.name])

            if section.name == '.rodata' and is_c_file and section_key not in special_cases:
                section_indices[section.name] += 1
                continue

            header_offset = elf_header["e_shoff"] + section_index * elf_header["e_shentsize"]
            align_offset = header_offset + 8 * 4 # 8 is the index of alignment value
            section_alignment = 1

            if section_key in special_cases:
                section_alignment = special_cases[section_key]
            elif section.name in (".bss", ".sbss", ".sdata"):
                # Don't change alignment of .bss/.sbss/.sdata sections if not explicitly stated
                section_alignment = None

            alignments.append((align_offset, section_alignment))
            section_indices[section.name] += 1

        return alignments

def main():
    path = Path(sys.argv[1])
    aligns = alignments(path)

    if not aligns:
        return

    with open(path, "r+b") as f:
        for offset, alignment in aligns:
            if not alignment:
                continue

            f.seek(offset)
            f.write(alignment_to_bytes(alignment))

if __name__ == "__main__":
    main()
