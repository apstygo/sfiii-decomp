# Prints line information found in the .line section of a binary.
# If there is a symbol_table.txt file present uses that to name functions.
# You can generate symbol table with the following command:
#
# > mipsel-linux-gnu-readelf --syms --wide <path_to_binary> > symbol_table.txt

# Usage:
#
# > python3 tools/dump_lines.py <path_to_binary>

import sys
from pathlib import Path
import re
from dataclasses import dataclass
from sortedcontainers import SortedDict
from elftools.elf.elffile import ELFFile

SYMBOL_TABLE_PATH = Path("symbol_table.txt")

@dataclass
class LineEntry:
    line_number: int
    char_offet: int
    hex_address_offset: int

def read_val(b: bytes, offset: int, size: int) -> int:
    val = 0

    for i in range(size):
        val |= b[offset + i] << i * 8

    return val

def read_int(b: bytes, offset: int) -> int:
    return read_val(b, offset, 4)

def read_short(b: bytes, offset: int) -> int:
    return read_val(b, offset, 2)

def read_symbols() -> dict[int, str]:
    if not SYMBOL_TABLE_PATH.exists():
        return dict()

    text = SYMBOL_TABLE_PATH.read_text()

    pattern = r" \d+: (\w+)\s+(\d+)\s+(\w+)\s+(\w+)\s+\w+\s+\d+\s+(.+)"
    result: dict[int, str] = dict()

    for match in re.finditer(pattern, text):
        address_str, size_str, typ, scope, name = match.groups()
        address = int(address_str, 16)
        size = int(size_str)

        if typ == "FUNC":
            result[address] = name

    return result

def main():
    symbols = read_symbols()
    elf_path = Path(sys.argv[1])

    with open(elf_path, "rb") as f:
        elf = ELFFile(f)
        line_section = elf.get_section_by_name(".line")
        line_data = line_section.data()

        lines: SortedDict[int, list[LineEntry]] = SortedDict()
        i = 0

        while i < len(line_data):
            entry_size = read_int(line_data, i)
            entry_end = i + entry_size
            i += 4

            func_ptr = read_int(line_data, i)
            i += 4

            while i < entry_end:
                line_number = read_int(line_data, i)
                i += 4

                char_offset = read_short(line_data, i)
                i += 2

                hex_address_offset = read_int(line_data, i)
                i += 4

                if func_ptr not in lines:
                    lines[func_ptr] = list()
                
                lines[func_ptr].append(LineEntry(line_number, char_offset, hex_address_offset))

                if line_number == 0:
                    break
        
        for func_ptr, line_entries in lines.items():
            header = f"<0x{func_ptr:08X}>:"

            if func_ptr in symbols:
                header = f"{symbols[func_ptr]} " + header

            print(header)

            for entry in line_entries:
                string = "    "

                if entry.line_number != 0:
                    string += f"Line: {entry.line_number} ({entry.line_number - line_entries[0].line_number + 1})"
                else:
                    string += f"Function end"

                string += f", offset: 0x{entry.hex_address_offset:X}"

                print(string)
            
            print()

if __name__ == "__main__":
    main()
