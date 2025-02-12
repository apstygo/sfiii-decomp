import sys
import re
from pathlib import Path

COMPILE_UNIT_PATTERN = re.compile(r"Compile unit: (.+)")
DWARF_PATH = Path("temp/dwarf")

def main():
    search_pattern = re.compile(r'\b' + re.escape(sys.argv[1]) + r'\b')
    dwarf_lines = DWARF_PATH.read_text().splitlines()
    unit_starts: list[tuple[str, int]] = list()
    results: list[str] = list()

    for line_index, line in enumerate(dwarf_lines):
        if match := COMPILE_UNIT_PATTERN.search(line):
            file_name = match.group(1)

            if len(unit_starts) == 0 or unit_starts[-1][0] != file_name:
                unit_starts.append((file_name, line_index))
        elif match := search_pattern.search(line):
            results.append(unit_starts[-1][0])

    for result in results:
        print(result)

if __name__ == "__main__":
    main()
