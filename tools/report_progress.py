from colorama import init, Fore
import shutil
from math import floor
from dependency_analyzer import build_func_map

PROGRESS_BAR_LEFT_EMPTY = chr(0xEE00)
PROGRESS_BAR_MID_EMPTY = chr(0xEE01)
PROGRESS_BAR_RIGHT_EMPTY = chr(0xEE02)
PROGRESS_BAR_LEFT_FULL = chr(0xEE03)
PROGRESS_BAR_MID_FULL = chr(0xEE04)
PROGRESS_BAR_RIGHT_FULL = chr(0xEE05)

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

    func_map = build_func_map()
    
    # Print results

    c_func_count = len(func_map.decompiled_funcs)
    total_func_count = len(func_map.func_to_file)
    asm_func_count = total_func_count - c_func_count
    ratio = c_func_count / total_func_count
    ratio_message = f"{ratio * 100:.1f}%"

    progress_bar_str = progress_bar(
        width=shutil.get_terminal_size().columns - len(ratio_message) - 1,
        ratio=ratio
    )

    print(Fore.GREEN + f"{c_func_count} functions decompiled")
    print(Fore.YELLOW + f"{asm_func_count} functions to go")
    print(ratio_message, progress_bar_str)

if __name__ == "__main__":
    main()
