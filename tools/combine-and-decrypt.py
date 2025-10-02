# modified from https://github.com/Strugglemeat/3stools to take paths

import os
import sys


def rotate_left(value, n):
    value &= 0xFFFF
    aux = value >> (16 - n)
    return ((value << n) | aux) % 0x10000


def rotxor(val, xorval):
    val &= 0xFFFF
    xorval &= 0xFFFF
    res = val + rotate_left(val, 2)
    res = rotate_left(res, 4) ^ (res & (val ^ xorval))
    return res


def cps3_mask(address, key1, key2):
    address ^= key1
    val = (address & 0xFFFF) ^ 0xFFFF
    val = rotxor(val, key2 & 0xFFFF)
    val ^= (address >> 16) ^ 0xFFFF
    val = rotxor(val, key2 >> 16)
    val ^= (address & 0xFFFF) ^ (key2 & 0xFFFF)
    return val | (val << 16)


def main(input_dir, output_file):
    simm_filenames = [
        "sfiii3-simm1.0",
        "sfiii3-simm1.1",
        "sfiii3-simm1.2",
        "sfiii3-simm1.3",
    ]
    simm_paths = [os.path.join(input_dir, name) for name in simm_filenames]

    for path in simm_paths:
        if not os.path.isfile(path):
            print(f"Error: Missing SIMM file: {path}")
            return

    simm1_0 = open(simm_paths[0], "rb")
    simm1_1 = open(simm_paths[1], "rb")
    simm1_2 = open(simm_paths[2], "rb")
    simm1_3 = open(simm_paths[3], "rb")

    simm_filesize = os.path.getsize(simm_paths[0])

    with open(output_file, "wb+") as outFile:
        baseOffset = 0x6000000
        for i in range(simm_filesize):
            b0 = int.from_bytes(simm1_0.read(1), "little")
            b1 = int.from_bytes(simm1_1.read(1), "little")
            b2 = int.from_bytes(simm1_2.read(1), "little")
            b3 = int.from_bytes(simm1_3.read(1), "little")

            curData = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3
            masked = cps3_mask(baseOffset + (i * 4), 0xA55432B4, 0x0C129981)
            decrypted = curData ^ masked
            outFile.write(decrypted.to_bytes(4, "big"))

    simm1_0.close()
    simm1_1.close()
    simm1_2.close()
    simm1_3.close()

    print(f"Decryption complete. Output written to: {output_file}")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python combine-and-decrypt.py <input_directory> <output_file>")
        sys.exit(1)

    input_directory = sys.argv[1]
    output_filename = sys.argv[2]

    main(input_directory, output_filename)
