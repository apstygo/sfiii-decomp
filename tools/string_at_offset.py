import sys
from pathlib import Path

# Reads bytes starting from the given offset as a null-terminated
# Shift-JIS string and prints the string to stdout.
#
# Example:
# > python3 tools/string_at_offset.py 404FA0
# '警告文のテクスチャが読み込めませんでした。\n'

def read_string(offset: int, data: bytes | None = None) -> str:
    if data is None:
        data = Path("THIRD_U.BIN").read_bytes()

    chars = []

    while data[offset] != 0:
        chars.append(data[offset])
        offset += 1

    return repr(bytes(chars).decode("sjis"))

def main():
    offset = int(sys.argv[1], base=16)
    print(read_string(offset))

if __name__ == "__main__":
    main()
