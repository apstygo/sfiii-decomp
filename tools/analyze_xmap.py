from pathlib import Path
import re
from dataclasses import dataclass

@dataclass
class SymbolTableEntry:
    name: str
    offset: int
    type: str | None = None
    size: int = 0

@dataclass
class XMAPEntry:
    name: str
    offset: int
    size: int
    section: str
    filename: str
    index_in_file: int
    # Has an associated asm file in nonmatchings
    is_nonmatching: bool
    expected_size: int = 0

    @property
    def is_decompiled(self) -> bool:
        if self.is_nonmatching:
            return False
        
        if self.name.startswith("literal_"):
            return False

        return self.filename.endswith(".c.o")
    
    @property
    def has_wrong_size(self) -> bool:
        return self.expected_size != 0 and self.size != self.expected_size

SYMBOL_ENTRY_PATTERN = re.compile(r"(\w+)\s+=\s+(\w+);(?:\s+\/\/\s+(.+))")
XMAP_ENTRY_PATTERN = re.compile(r"  (\w+) (\w+) (\S+)\s+(\S+)\s+\((\S+)\)")
SYMBOLS = Path("config/anniversary/symbols")
XMAP = Path("build/anniversary/ps2/THIRD_U.BIN.xMAP")
NONMATCHINGS = Path("asm/anniversary/nonmatchings")

def build_symbol_table() -> list[SymbolTableEntry]:
    symbol_table: list[SymbolTableEntry] = list()

    for symbol_file in SYMBOLS.rglob("*.txt"):
        lines = symbol_file.read_text().splitlines()

        for line in lines:
            if match := SYMBOL_ENTRY_PATTERN.search(line):
                name = match.group(1)
                offset = int(match.group(2), base=16)
                type = None
                size = 0
                comment = match.group(3)

                if comment:
                    type, size = parse_comment(comment)

                symbol_table.append(
                    SymbolTableEntry(
                        name=name,
                        offset=offset,
                        type=type,
                        size=size
                    )
                )

    symbol_table.sort(key=lambda x: x.offset)

    return symbol_table

def parse_comment(comment: str):
    type = None
    size = 0

    for component in comment.split():
        key, value = component.split(":")

        if key == "type":
            type = value
        elif key == "size":
            size = int(value, base=16)

    return type, size

def build_xmap() -> list[XMAPEntry]:
    xmap: list[XMAPEntry] = list()
    lines = XMAP.read_text().splitlines()
    nonmatching_filenames = collect_nonmatching_filenames()
    current_filename = ""
    index_in_file = 0

    for line in lines:
        if match := XMAP_ENTRY_PATTERN.search(line):
            name = match.group(4)

            if name in (".text", ".data", ".sdata", ".rodata", ".bss", ".sbss"):
                continue

            is_nonmatching = name in nonmatching_filenames
            filename = match.group(5)

            if current_filename != filename:
                current_filename = filename
                index_in_file = 0

            xmap.append(
                XMAPEntry(
                    name=name,
                    offset=int(match.group(1), base=16),
                    size=int(match.group(2), base=16),
                    section=match.group(3),
                    filename=filename,
                    index_in_file=index_in_file,
                    is_nonmatching=is_nonmatching
                )
            )

            index_in_file += 1

    xmap.sort(key=lambda x: x.offset)

    return xmap

def collect_nonmatching_filenames() -> set[str]:
    names: set[str] = set()

    for path in NONMATCHINGS.rglob("*.s"):
        names.add(path.stem)

    return names

def symbol_word_for_xmap_entry(entry: XMAPEntry) -> str:
    return "Function" if entry.section == ".text" else "Symbol"

def analyze():
    symbol_table = build_symbol_table()
    name_to_symbol: dict[str, SymbolTableEntry] = dict()
    offset_to_symbol: dict[int, SymbolTableEntry] = dict()

    for symbol in symbol_table:
        name_to_symbol[symbol.name] = symbol
        offset_to_symbol[symbol.offset] = symbol

    xmap = build_xmap()

    previous_entry: XMAPEntry | None = None
    misaligned_entry: XMAPEntry | None = None
    wrong_sized_entries: list[XMAPEntry] = list()
    expected_offset = 0

    for xmap_entry in xmap:
        if xmap_entry.name in name_to_symbol:
            if xmap_entry.offset != name_to_symbol[xmap_entry.name].offset:
                misaligned_entry = xmap_entry
                expected_offset = name_to_symbol[xmap_entry.name].offset
                break

            if xmap_entry.is_decompiled:
                xmap_entry.expected_size = name_to_symbol[xmap_entry.name].size

        elif xmap_entry.name.startswith("D_"):
            expected = int(xmap_entry.name[2:], base=16)

            if xmap_entry.offset != expected:
                misaligned_entry = xmap_entry
                expected_offset = expected
                break

        # Compiled literals' names start with @. But these names do not match the ones from symbol files.
        # That's why we have to look them up by their offsets.
        if xmap_entry.name.startswith("@") and (literal_symbol := offset_to_symbol[xmap_entry.offset]):
            xmap_entry.expected_size = literal_symbol.size

        if xmap_entry.has_wrong_size:
            wrong_sized_entries.append(xmap_entry)

        previous_entry = xmap_entry

    if misaligned_entry:
        actual_offset = misaligned_entry.offset
        difference = actual_offset - expected_offset
        symbol_word = symbol_word_for_xmap_entry(misaligned_entry)

        print(f"{symbol_word} {misaligned_entry.name} ({misaligned_entry.filename}) is misaligned: expected 0x{expected_offset:08X}, got 0x{actual_offset:08X} ({difference:+} bytes).")

        possible_causes: list[str] = list()

        if previous_entry != None:
            if misaligned_entry.section == ".text":
                previous_file_offset = previous_entry.offset - 0x100000 + 0x80
                possible_causes.append(f"Looks like there's an issue with the preceding function - {previous_entry.name}. To debug it run 'python3 tools/asm-differ/diff.py 0x{previous_file_offset:08X}'.")

            elif previous_entry.has_wrong_size:
                difference = previous_entry.size - previous_entry.expected_size
                possible_causes.append(f"The preceding symbol ({previous_entry.name}) has incorrect size: expected 0x{previous_entry.expected_size:X}, got 0x{previous_entry.size:X} ({difference:+} bytes). Fixing {previous_entry.name} may fix the misalignment.")

            else:
                if not misaligned_entry.is_decompiled:
                    message = f"{misaligned_entry.name} is not decompiled, which means its alignment in ELF may not be correct. "
                    stem = misaligned_entry.filename.split(".")[0]
                    message += f"You can fix this by adding '(\"{stem}\", \"{misaligned_entry.section}\", {misaligned_entry.index_in_file})' to 'special_cases' in patch_alignment.py."
                    possible_causes.append(message)

                # If the previous entry has no expected size we cannot be sure it's correct
                if previous_entry.expected_size == 0:
                    possible_causes.append(f"The preceding symbol ({previous_entry.name}) may have incorrect size.")

        if possible_causes:
            print("\nPossible causes:")

            for cause in possible_causes:
                print(f"- {cause}")

    elif wrong_sized_entries:
        for entry in wrong_sized_entries:
            symbol_word = symbol_word_for_xmap_entry(entry)
            difference = entry.size - entry.expected_size
            print(f"{symbol_word} {entry.name} ({entry.filename}) has incorrect size: expected 0x{entry.expected_size:X}, got 0x{entry.size:X} ({difference:+} bytes).")

if __name__ == "__main__":
    analyze()
