from dependency_analyzer import build_func_map, FuncMap
from pathlib import Path
from tabulate import tabulate

def main():
    caplogo_funcs = Path("caplogo-funcs.txt").read_text().splitlines()
    func_map = build_func_map()

    text = "# Caplogo progress\n\n"
    text += "This file shows progress towards porting the very first thing you see on screen – the Capcom logo.\n\n"
    text += "Notes:\n"
    text += "- Functions appear in the order that the game first calls them in.\n"
    text += "- There's no need to decompile SDK and zlib functions.\n"
    text += "\n"

    headers = ("Function", "File", "Module", "Is decompiled")
    rows = list()

    for func in caplogo_funcs:
        file_path = func_map.func_to_file[func]
        module = file_path.split("/")[0]
        status = ""

        if module == "sdk" or "zlib" in file_path:
            status = "–"

        if func in func_map.decompiled_funcs:
            status = "✅"

        rows.append((func, file_path, module, status))

    text += tabulate(rows, headers=headers, tablefmt="github")
    text += "\n"

    Path("caplogo-progress.md").write_text(text)

if __name__ == "__main__":
    main()
