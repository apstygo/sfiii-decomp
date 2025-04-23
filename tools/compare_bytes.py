#!/usr/bin/env python3

# Usage:
# > tools/compare_bytes.py THIRD_U.BIN build/anniversary/THIRD_U.BIN 0x80 0x478A00 [--fix]

import sys
from pathlib import Path

EXPECTED_ERRORS = {
    # Weird call misalignment issue.
    # For some reason are 4 bytes earlier than needed.
    # Must be a compiler/linker bug or something.
    0x2A5174: 0xF9FF0010,
    0x302580: 0xFAFFC014,
    0x3025B8: 0xF4FFC014,
    0x3025E0: 0xF8FFC014,
    0x302600: 0xFAFFC014,
    0x302658: 0xECFFC014,
    0x302690: 0xF4FFC014,
    0x3026B8: 0xF8FFC014,
    0x3026F0: 0xF4FFC014,
    0x302708: 0xFCFFA014,
    0x302720: 0xFCFFA014,
    0x302738: 0xFCFFA014,
    0x302750: 0xFCFFA014,

    # menu::Sound_Test: s2 <-> s4 regswap
    0x175A48: 0x3CA40400,
    0x175A4C: 0x3FA41400,
    0x175ACC: 0xFF005230,
    0x175C8C: 0x2D204002,

    # DEMO00::CAPLOGO_Move: misplaced nop
    0xC1284: 0x78F08287,
    0xC1288: 0x3C1C0200,
    0xC128C: 0x3F1C0300,
    0xC1290: 0x02000224,
    0xC1294: 0x43280300,
    0xC1298: 0x03006104,
    0xC129C: 0x00000000,
    0xC12A0: 0x01006224,
    0xC12A4: 0x43280200,
    0xC12A8: 0x58020424,
    0xC12AC: 0x9C02070C,
    0xC12B0: 0x00000000,
    0xC12B4: 0x78F08287,
    0xC12B8: 0x01004224,
    0xC12BC: 0x78F082A7,
    0xC12C0: 0x01000224,
    0xC12C4: 0x3C840200,
    0xC12C8: 0x3F841000,
    0xC12CC: 0x00000000,

    # flps2vram: mismatched __LINE__'s in assert
    0x2F86A4: 0x2D280000,
    0x2F87C8: 0x2D280000,
    0x2F8848: 0x2D280000,
    0x2F8938: 0x2D280000,
    0x2F9238: 0x2D280000,
    0x2FB744: 0x2D280000,
    0x2FB7CC: 0x2D280000,

    # adx_fs::adxf_SetAfsFileInfo: two lines of asm swapped
    0x2CDB7C: 0x3C0024AE,
    0x2CDB80: 0x380022AE,
}

def read_word(b: bytes, offset: int) -> int:
    word = 0

    for i in range(4):
        word |= b[offset + i] << (3 - i) * 8

    return word

def align_down(n: int, alignment: int) -> int:
    return n // alignment * alignment

def main():
    path_a = Path(sys.argv[1])
    path_b = Path(sys.argv[2])
    start = 0
    end = sys.maxsize
    should_print_fix = len(sys.argv) >= 6 and sys.argv[5] == "--fix"

    if len(sys.argv) >= 4:
        start = align_down(int(sys.argv[3], 16), 4)

    if len(sys.argv) >= 5:
        end = align_down(int(sys.argv[4], 16), 4)

    if start != 0 or end != sys.maxsize:
        print(f"Comparing range [0x{start:X}, 0x{end:X})")

    with open(path_a, 'rb') as f:
        bytes_a = f.read()

    with open(path_b, 'rb') as f:
        bytes_b = f.read()

    # Compare bytes

    bad_offsets: list[int] = list()
    misalign_offset: int | None = None

    range_end = min(
        len(bytes_a), 
        len(bytes_b),
        end
    )

    for offset in range(start, range_end, 4):
        word_a = read_word(bytes_a, offset)
        word_b = read_word(bytes_b, offset)

        if word_a != word_b:
            if offset in EXPECTED_ERRORS and EXPECTED_ERRORS[offset] == word_b:
                continue

            bad_offsets.append(offset)

            if (word_a == 0 or word_b == 0) and misalign_offset == None:
                misalign_offset = offset

    success = True

    if not bad_offsets:
        print("Files match ✅")
    else:
        success = False
        max_printed_offsets = 20
        print(f"Files diverge at {len(bad_offsets)} offsets ❌.")

        if len(bad_offsets) > max_printed_offsets:
            print(f"First {max_printed_offsets} diverging offsets:")
        else:
            print("Diverging offsets:")

        for offset in bad_offsets[:max_printed_offsets]:
            print(f"    0x{offset:X} (expected 0x{read_word(bytes_a, offset):X}, got 0x{read_word(bytes_b, offset):X})")

    if misalign_offset != None:
        print(f"Misalignment at 0x{misalign_offset:X}")

    if should_print_fix and bad_offsets:
        print("\nAdd this to EXPECTED_ERRORS to suppress this error:")

        for offset in bad_offsets:
            print(f"0x{offset:X}: 0x{read_word(bytes_b, offset):6X},")

    if success:
        sys.exit(0)
    else:
        sys.exit(1)

if __name__ == '__main__':
    main()
