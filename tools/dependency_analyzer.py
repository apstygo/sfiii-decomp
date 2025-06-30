from pathlib import Path
import subprocess
import re
from tqdm import tqdm
from graphviz import Digraph
from dataclasses import dataclass
import pickle
import sys
import os

# Prints functions that the provided file depends on. Expects file path relative to sources directory.
# Usage:
# > python3 tools/dependency_analyzer.py sf33rd/Source/Game/Game.c [--no-cache]

running_on_ci = "CI" in os.environ

@dataclass
class FuncMap:
    calls: dict[str, set[str]]
    file_to_funcs: dict[str, list[str]]
    func_to_file: dict[str, str]
    func_to_size: dict[str, int]
    decompiled_funcs: set[str]

FUNC_HEADER_PATTERN = re.compile(r"\w{8} <(\w+)>:")
RELOC_PATTERN = re.compile(r"\s+\w+: \w+\s+(\w+)")
SYMBOL_INFO_PATTERN = re.compile(r"F\s+\.text\s+(\w+)\s+(\w+)")
SECTION_MARKER_PATTERN = re.compile(r"Disassembly of section (\.\w+):")
CACHED_PATH = Path("temp/cached_func_map.pkl")

def obj_path_to_source_path(obj_path: Path) -> Path:
    components = str(obj_path).split("/")
    # Drop build/anniversary/ps2/src/anniversary and build/anniversary/ps2/asm/anniversary
    components = components[5:]
    components[-1] = components[-1].replace(".c.o", ".c").replace(".s.o", ".c")
    return Path("/".join(components))

def _build_func_map() -> FuncMap:
    build = Path("build")
    all_calls: dict[str, set[str]] = dict()
    file_to_funcs: dict[str, list[str]] = dict()
    func_to_file: dict[str, str] = dict()
    func_to_size: dict[str, int] = dict()
    decompiled_funcs: set[str] = set()
    obj_files = [x for x in build.rglob("*.o") if "/data/" not in str(x)]

    for path in tqdm(obj_files):
        file_path = str(obj_path_to_source_path(path))
        calls = extract_func_calls(path)
        all_calls |= calls
        func_to_size |= extract_symbol_sizes(path)

        funcs = list(map(lambda x: x[0], calls.items()))
        file_to_funcs[file_path] = funcs

        for func in funcs:
            func_to_file[func] = file_path

            if check_if_decompiled(func, path):
                decompiled_funcs.add(func)

    return FuncMap(
        all_calls, 
        file_to_funcs, 
        func_to_file,
        func_to_size,
        decompiled_funcs
    )

def build_func_map(no_cache: bool = running_on_ci) -> FuncMap:
    if not no_cache and CACHED_PATH.exists():
        with open(CACHED_PATH, "rb") as f:
            return pickle.load(f)

    else:
        func_map = _build_func_map()

        if not no_cache:
            with open(CACHED_PATH, "wb") as f:
                pickle.dump(func_map, f)

        return func_map
    
def check_if_decompiled(func: str, obj_file: Path) -> bool:
    source_extension = obj_file.stem.split(".")[-1]

    if source_extension == "s":
        return False
    
    components = str(obj_file).split("/")
    components = components[5:]                         # drop 'build/anniversary/ps2/src/anniversary'
    components[-1] = components[-1].split(".")[0]       # remove extensions
    components = ["asm", "anniversary", "nonmatchings"] + components + [f"{func}.s"]

    nonmatching_path = Path("/".join(components))
    return not nonmatching_path.exists()

def extract_func_calls(path: Path) -> dict[str, set[str]]:
    output = subprocess.check_output(
        [
            "mipsel-linux-gnu-objdump",
            "-dr",
            path
        ],
        encoding="utf-8"
    )

    func_call_on_line = False
    calls: dict[str, set[str]] = dict()
    current_caller: str | None = None
    skip_disassembly = False

    for line in output.splitlines():
        if match := SECTION_MARKER_PATTERN.search(line):
            section = match.group(1)
            skip_disassembly = section != ".text"
            continue

        if skip_disassembly:
            continue

        if match := FUNC_HEADER_PATTERN.search(line):
            current_caller = match.group(1)
            calls[current_caller] = set()

        elif "jal\t" in line:
            func_call_on_line = True

        elif func_call_on_line:
            if match := RELOC_PATTERN.search(line):
                calls[current_caller].add(match.group(1))

            func_call_on_line = False

    return calls

def extract_symbol_sizes(path: Path) -> dict[str, int]:
    output = subprocess.check_output(
        [
            "mipsel-linux-gnu-objdump",
            "-t",
            path
        ],
        encoding="utf-8"
    )

    sizes: dict[str, int] = dict()

    for line in output.splitlines():
        if match := SYMBOL_INFO_PATTERN.search(line):
            size = int(match.group(1), base=16)
            func = match.group(2)
            sizes[func] = size

    return sizes

def create_dependency_graph(func_map: FuncMap) -> Digraph:
    dot = Digraph("dependency_graph")

    for caller, _ in func_map.calls.items():
        filename = func_map.func_to_file[caller]

        with dot.subgraph(name=f"cluster_{filename}", comment=filename) as c:
            c.node(caller)

    for caller, callees in func_map.calls.items():
        for callee in callees:
            dot.edge(caller, callee)

    return dot

def build_file_submap(
    filename: str, 
    func_map: FuncMap
) -> FuncMap:
    result = FuncMap(
        dict(), 
        dict(), 
        func_map.func_to_file,
        func_map.func_to_size,
        func_map.decompiled_funcs
    )

    stack: list[str] = list()
    stack.extend(func_map.file_to_funcs[filename])

    while stack:
        func = stack.pop()

        if func in result.calls:
            continue

        result.calls[func] = func_map.calls[func]
        stack.extend(func_map.calls[func])

    for filename, funcs in func_map.file_to_funcs.items():
        filtered_funcs = list(x for x in funcs if x in result.calls)

        if filtered_funcs:
            result.file_to_funcs[filename] = filtered_funcs

    return result

def main():
    target_file = sys.argv[1]
    no_cache = len(sys.argv) > 2 and sys.argv[2] == "--no-cache"
    func_map = build_func_map(no_cache=no_cache)
    target_submap = build_file_submap(target_file, func_map)

    # dot = create_dependency_graph(target_submap)
    # dot.render("dependency_graph")

    sorted_items = sorted(target_submap.file_to_funcs.items(), key=lambda x: x[0])

    total_bytes = 0
    total_decomped_bytes = 0
    total_functions = 0
    total_decomped_funcs = 0
    for filename, funcs in sorted_items:
        total_functions += len(funcs)
        print(filename)

        for func in funcs:
            is_decompiled = func in func_map.decompiled_funcs
            func_status = "✅" if is_decompiled else ""

            if is_decompiled:
                total_decomped_bytes += func_map.func_to_size[func]
                total_decomped_funcs += 1

            total_bytes += func_map.func_to_size[func]
            print("   ", func, func_status)

        print()

    print(f"{target_file} COUNT DECOMPILATION PERCENTAGE: {total_decomped_funcs / total_functions * 100:.2f}")
    print(f"{target_file} SIZE  DECOMPILATION PERCENTAGE: {total_decomped_bytes / total_bytes * 100:.2f} ")

if __name__ == "__main__":
    main()
