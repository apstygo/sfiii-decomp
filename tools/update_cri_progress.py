from dependency_analyzer import build_func_map, FuncMap
import json
from pathlib import Path

CRI_FUNCS = Path("cri-funcs.json")
CRI_PROGRESS = Path("cri-progress.md")

def main():
    func_map = build_func_map(no_cache=True)
    all_funcs: dict[str, list[str]] = json.loads(CRI_FUNCS.read_text())
    first_file = True

    text = "# CRI decompilation progress\n\n"
    text += "If you don't see a function in this list it doesn't need to be decompiled.\n\n"

    for file, funcs in all_funcs.items():
        if not first_file:
            text += "\n"

        first_file = False

        all_decompiled = all(x in func_map.decompiled_funcs for x in funcs)
        text += f"### {file}"

        if all_decompiled:
            text += " ✅"

        text += "\n\n"

        for func in funcs:
            text += "- ["

            if func in func_map.decompiled_funcs:
                text += "x"
            else:
                text += " "

            text += f"] {func}\n"

    CRI_PROGRESS.write_text(text)

if __name__ == "__main__":
    main()
