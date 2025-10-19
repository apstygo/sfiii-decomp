#!/usr/bin/env python3

# Usage:
# > tools/compare_bytes.py THIRD_U.BIN build/anniversary/THIRD_U.BIN 0x80 0x478A00 [--fix]

import sys
import os
from pathlib import Path
from analyze_xmap import analyze as analyze_xmap_issues

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

    # MTRANS::seqsStoreChip: string literal encoding issues
    0x422D5C: 0x82AA9792,
    0x422D60: 0xE8909482,
    0x422D64: 0xF0897A82,
    0x422D68: 0xA682C482,
    0x422D6C: 0xB582DC82,
    0x422D70: 0xA282DC82,
    0x422D74: 0xB582BD00,

    # eff36::effect_36_init: minor swap
    0xDD0B4: 0x00004384,
    0xDD0B8: 0x3E020286,
    0xDD0BC: 0x21104300,

    # adx_sjd::adxsjd_get_wr: (a1, a2, a3) regswap
    0x2D1740: 0x2DA8A000,
    0x2D1748: 0x2DB0C000,
    0x2D1750: 0x2DB8E000,
    0x2D17C8: 0x0000A3AE,
    0x2D17E8: 0x0000C4AE,
    0x2D180C: 0x0000E2AE,
    
    # efff6::effect_F6_init: lh operand swap
    0x11DB9C: 0x00004384,
    0x11DBA0: 0x3E020286,
    0x11DBA4: 0x21104300,

    # aboutspr::set_judge_area_sprite: instruction matching, regalloc issue
    0x2A8AE8: 0xFFFF6530,
    0x2A8AEC: 0x3C241000,
    0x2A8AF0: 0x3F240400,
    0x2A8AF8: 0x04188300,
    0x2A8AFC: 0x2418A300,
    0x2A8B2C: 0x96034294,
    0x2A8B30: 0xFFFF4430,
    0x2A8B44: 0x24108200,

    # aboutspr::sort_push_requestA: instruction matching, regalloc issue
    0x2AA380: 0x3C2C0200,
    0x2AA384: 0x3F2C0500,
    0x2AA39C: 0x2110A200,
    0x2AA49C: 0x3C2C0200,
    0x2AA4A0: 0x3F2C0500,
    0x2AA4B8: 0x2118A200,

    # aboutspr::sort_push_requestB: instruction matching, regalloc issue
    0x2AAA58: 0x3C2C0200,
    0x2AAA5C: 0x3F2C0500,
    0x2AAA74: 0x2110A200,
    0x2AAB74: 0x3C2C0200,
    0x2AAB78: 0x3F2C0500,
    0x2AAB90: 0x2118A200,

    # eflSifRpc::flSifRpcInit mismatched __LINE__'s in assert
    0x310EE0: 0x2D280000,
    0x310FA8: 0x2D280000,
    0x311070: 0x2D280000,

    # cse::cseCheckVTransStatus mismatched __LINE__'s in assert
    0x311A28: 0x2D280000,
}

# Weird issue with cri_srd::srd_exec_dvd. 
# For some reason CI builds codegen this one instruction differently.
if "CI" in os.environ:
    EXPECTED_ERRORS[0x2D9EE0] = 0x5600638C

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

        print()
        analyze_xmap_issues()

    # if misalign_offset != None:
    #     print(f"Misalignment at 0x{misalign_offset:X}")

    if should_print_fix and bad_offsets:
        print("\nAdd this to EXPECTED_ERRORS to suppress this error:")

        for offset in bad_offsets:
            print(f"0x{offset:X}: 0x{read_word(bytes_b, offset):08X},")

    if success:
        sys.exit(0)
    else:
        sys.exit(1)

if __name__ == '__main__':
    main()
