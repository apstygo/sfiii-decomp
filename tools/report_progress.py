from pycparser import c_ast, parse_file
from pathlib import Path
from colorama import init, Fore
import re
import shutil
from math import floor

PROGRESS_BAR_LEFT_EMPTY = chr(0xEE00)
PROGRESS_BAR_MID_EMPTY = chr(0xEE01)
PROGRESS_BAR_RIGHT_EMPTY = chr(0xEE02)
PROGRESS_BAR_LEFT_FULL = chr(0xEE03)
PROGRESS_BAR_MID_FULL = chr(0xEE04)
PROGRESS_BAR_RIGHT_FULL = chr(0xEE05)

class FuncDefVisitor(c_ast.NodeVisitor):
    def __init__(self) -> None:
        self.counter: int = 0
        super().__init__()

    def visit_FuncDef(self, node):
        self.counter += 1

def clamp(n, smallest, largest): 
    return max(smallest, min(n, largest))

def progress_bar(width: int, ratio: float) -> str:
    filled = floor(width * ratio)
    result = ""

    if filled > 0:
        result += PROGRESS_BAR_LEFT_FULL
    else:
        result += PROGRESS_BAR_LEFT_EMPTY

    result += PROGRESS_BAR_MID_FULL * clamp(filled - 1, 0, width - 2)
    result += PROGRESS_BAR_MID_EMPTY * clamp(width - filled - 1, 0, width - 2)

    if filled == width:
        result += PROGRESS_BAR_RIGHT_FULL
    else:
        result += PROGRESS_BAR_RIGHT_EMPTY

    return result

def main():
    init(autoreset=True)

    # Calculate C funcs

    src_path = Path("src/anniversary/sf33rd")
    v = FuncDefVisitor()
    c_file_count = 0

    for src in src_path.rglob("*.c"):
        c_file_count += 1

        ast = parse_file(
            src, 
            use_cpp=True,
            cpp_args=[
                "-DM2CTX",
                "-DTARGET_PS2",
                "-Iinclude", 
                "-Iinclude/sdk",
                "-Iinclude/cri",
                "-Iinclude/cri/ee",
                "-Iinclude/gcc",
                "-nostdinc",
            ]
        )

        v.visit(ast)

    # Calculate asm funcs

    asm_path = Path("asm/anniversary/sf33rd")
    asm_file_count = 0
    asm_func_count = 0
    asm_func_regex = re.compile(f"glabel")

    for asm in asm_path.rglob("*.s"):
        asm_file_count += 1
        asm_func_count += len(asm_func_regex.findall(asm.read_text()))
    
    # Print results

    c_func_count = v.counter
    total_func_count = c_func_count + asm_func_count
    ratio = c_func_count / total_func_count
    ratio_message = f"{ratio * 100:.1f}%"

    progress_bar_str = progress_bar(
        width=shutil.get_terminal_size().columns - len(ratio_message) - 1,
        ratio=ratio
    )

    print(Fore.GREEN + f"{c_func_count} functions in {c_file_count} files decompiled")
    print(Fore.YELLOW + f"{asm_func_count} functions in {asm_file_count} files to go")
    print(ratio_message, progress_bar_str)

if __name__ == "__main__":
    main()
