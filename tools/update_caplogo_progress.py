from dependency_analyzer import build_func_map, FuncMap
from pathlib import Path
from tabulate import tabulate

def main():
    caplogo_funcs = Path("caplogo-funcs.txt").read_text().splitlines()
    func_map = build_func_map()
    cri_total = 0
    cri_done = 0

    text = "# Caplogo progress\n\n"
    text += "This file shows progress towards porting the very first thing you see on screen – the Capcom logo.\n\n"
    text += "Notes:\n"
    text += "- Functions appear in the order that the game first calls them in.\n"
    text += "- There's no need to decompile SDK and zlib functions.\n"
    text += "\n"

    function_table_rows = list()

    for func in caplogo_funcs:
        file_path = func_map.func_to_file[func]
        module = file_path.split("/")[0]
        is_zlib = "zlib" in file_path
        func_size = func_map.func_to_size[func]
        status = ""

        if module == "sdk" or is_zlib:
            continue

        if func in func_map.decompiled_funcs:
            status = "✅"

            if module == "cri":
                cri_done += func_size

        if module == "cri":
            cri_total += func_size

        function_table_rows.append((func, file_path, module, status))

    progress_table_headers = ("Module", "Progress")
    progress_table_rows = (
        ("sf33rd", "100%"),
        ("cri", f"{cri_done / cri_total * 100:.2f}%"),
    )

    text += tabulate(progress_table_rows, headers=progress_table_headers, tablefmt="github")
    text += "\n\n"

    function_table_headers = ("Function", "File", "Module", "Is decompiled")
    text += tabulate(function_table_rows, headers=function_table_headers, tablefmt="github")
    text += "\n"

    Path("caplogo-progress.md").write_text(text)

if __name__ == "__main__":
    main()
