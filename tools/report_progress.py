# from colorama import init, Fore
# import shutil
# from math import floor
from dependency_analyzer import build_func_map, FuncMap
from dataclasses import dataclass
from pathlib import Path
import json
from tabulate import tabulate

# PROGRESS_BAR_LEFT_EMPTY = chr(0xEE00)
# PROGRESS_BAR_MID_EMPTY = chr(0xEE01)
# PROGRESS_BAR_RIGHT_EMPTY = chr(0xEE02)
# PROGRESS_BAR_LEFT_FULL = chr(0xEE03)
# PROGRESS_BAR_MID_FULL = chr(0xEE04)
# PROGRESS_BAR_RIGHT_FULL = chr(0xEE05)

@dataclass
class ModuleMetrics:
    total_size: int = 0
    decompiled_size: int = 0
    total_func_count: int = 0
    decompiled_func_count: int = 0

    @property
    def decompiled_size_percentage(self) -> float:
        return (self.decompiled_size / self.total_size) * 100

    @property
    def decompiled_func_percentage(self) -> float:
        return (self.decompiled_func_count / self.total_func_count) * 100

# def clamp(n, smallest, largest): 
#     return max(smallest, min(n, largest))

# def progress_bar(width: int, ratio: float) -> str:
#     filled = floor(width * ratio)
#     result = ""

#     if filled > 0:
#         result += PROGRESS_BAR_LEFT_FULL
#     else:
#         result += PROGRESS_BAR_LEFT_EMPTY

#     result += PROGRESS_BAR_MID_FULL * clamp(filled - 1, 0, width - 2)
#     result += PROGRESS_BAR_MID_EMPTY * clamp(width - filled - 1, 0, width - 2)

#     if filled == width:
#         result += PROGRESS_BAR_RIGHT_FULL
#     else:
#         result += PROGRESS_BAR_RIGHT_EMPTY

#     return result

def path_to_module_type(path: str) -> str:
    return path.split("/")[0]

def generate_progress_report(no_cache: bool = False) -> str:
    func_map = build_func_map(no_cache=no_cache)
    cri_funcs = json.loads(Path("cri-funcs.json").read_text())
    cri_func_set = set()

    for _, funcs in cri_funcs.items():
        cri_func_set.update(funcs)

    # Collect metrics

    metrics = {
        "sf33rd": ModuleMetrics(),
        "cri": ModuleMetrics(),
        "sdk": ModuleMetrics(),
        "gcc": ModuleMetrics(),
    }

    for func, path in func_map.func_to_file.items():
        module_type = path_to_module_type(path)
        skip_func = module_type == "cri" and func not in cri_func_set

        if skip_func:
            continue

        func_size = func_map.func_to_size[func]

        metrics[module_type].total_func_count += 1
        metrics[module_type].total_size += func_size

        if func in func_map.decompiled_funcs:
            metrics[module_type].decompiled_func_count += 1
            metrics[module_type].decompiled_size += func_size

    # Generate a markdown table

    headers = ("Module", "Progress (size)", "Progress (func count)", "Notes")
    rows = []

    for module in ("sf33rd", "cri"):
        rows.append([
            module,
            f"{metrics[module].decompiled_size_percentage:.2f}%",
            f"{metrics[module].decompiled_func_percentage:.2f}%",
            ""
        ])

    # Notes
    rows[0][3] = "Game functions."
    rows[1][3] = "CRI Middleware functions. For a full list of functions see [cri-progress.md](cri-progress.md)."

    return tabulate(rows, headers=headers, tablefmt="github")

def main():
    # init(autoreset=True)
    
    # Print results

    # c_func_count = len(func_map.decompiled_funcs)
    # total_func_count = len(func_map.func_to_file)
    # asm_func_count = total_func_count - c_func_count
    # ratio = c_func_count / total_func_count
    # ratio_message = f"{ratio * 100:.1f}%"

    # progress_bar_str = progress_bar(
    #     width=shutil.get_terminal_size().columns - len(ratio_message) - 1,
    #     ratio=ratio
    # )

    # print(Fore.GREEN + f"{c_func_count} functions decompiled")
    # print(Fore.YELLOW + f"{asm_func_count} functions to go")
    # print(ratio_message, progress_bar_str)

    md_table = generate_progress_report()
    print(md_table)

if __name__ == "__main__":
    main()
