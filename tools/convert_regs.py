import sys
from pathlib import Path

# Converts ASM from numeric to named registers.
# Useful for nonmatching CRI funcs which are generated with numbered registers
# for compatibility with GNU as.

SUBSTITUTIONS = (
    ("$0", "$zero"),
    ("$1", "$at"),
    ("$2", "$v0"),
    ("$3", "$v1"),
    ("$4", "$a0"),
    ("$5", "$a1"),
    ("$6", "$a2"),
    ("$7", "$a3"),
    ("$8", "$t0"),
    ("$9", "$t1"),
    ("$10", "$t2"),
    ("$11", "$t3"),
    ("$12", "$t4"),
    ("$13", "$t5"),
    ("$14", "$t6"),
    ("$15", "$t7"),
    ("$16", "$s0"),
    ("$17", "$s1"),
    ("$18", "$s2"),
    ("$19", "$s3"),
    ("$20", "$s4"),
    ("$21", "$s5"),
    ("$22", "$s6"),
    ("$23", "$s7"),
    ("$24", "$t8"),
    ("$25", "$t9"),
    ("$28", "$gp"),
    ("$29", "$sp"),
    ("$30", "$fp"),
    ("$31", "$ra"),
)

def convert_regs(asm: str, named_regs: bool) -> str:
    for numeric, named in reversed(SUBSTITUTIONS):
        old = numeric if named_regs else named
        new = named if named_regs else numeric
        asm = asm.replace(old, new)

    return asm

def main():
    asm_path = Path(sys.argv[1])

    named_regs = True

    if len(sys.argv) > 2 and sys.argv[2] == "--numeric":
        named_regs = False

    asm = asm_path.read_text()
    asm = convert_regs(asm, named_regs=named_regs)
    print(asm)

if __name__ == "__main__":
    main()
