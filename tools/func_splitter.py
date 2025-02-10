from pycparser import c_ast, parse_file
from pathlib import Path
import subprocess
import tempfile
from dataclasses import dataclass

@dataclass
class FuncLocation:
    name: str
    full_range: tuple[int, int]
    body_range: tuple[int, int]

class FuncDefVisitor(c_ast.NodeVisitor):
    def __init__(self, text: str) -> None:
        self.text = text
        self.func_locations: list[FuncLocation] = []
        super().__init__()

    def visit_FuncDef(self, node: c_ast.FuncDef):
        coord = node.decl.coord
        start_of_line = find_nth(self.text, "\n", coord.line - 1) + 1
        # start = start_of_line + coord.column - 1
        start = start_of_line
        body_start = self.text.find("{", start)
        end = body_start + 1
        stack = ["{"]

        while len(stack) > 0:
            char = self.text[end]

            if char == "{":
                stack.append(char)
            elif char == "}":
                stack.pop()

            end += 1

        self.func_locations.append(
            FuncLocation(
                node.decl.name,
                (start, end),
                (body_start, end)
            )
        )

def find_nth(haystack: str, needle: str, n: int) -> int:
    start = haystack.find(needle)

    while start >= 0 and n > 1:
        start = haystack.find(needle, start + len(needle))
        n -= 1

    return start

def replace_range(dst: str, src: str, range: tuple[int, int]) -> str:
    return src.join((dst[:range[0]], dst[range[1]:]))

CPP_ARGS = [
    "-DM2CTX",
    "-Iinclude", 
    "-Iinclude/sdk",
    "-Iinclude/cri",
    "-Iinclude/cri/ee",
    "-Iinclude/gcc",
    "-nostdinc",
]

def split_file(src_file_path: Path, dst: Path):
    # cpp_command = ["gcc", "-E", "-P", "-dM", *CPP_ARGS, src_file_path]
    cpp_command2 = ["gcc", "-E", "-P", *CPP_ARGS, src_file_path]

    # Preprocess the C file into a temporary file and parse it
    with tempfile.NamedTemporaryFile(suffix=".c") as tmp:
        tmp_path = Path(tmp.name)

        full_text = ""
        # full_text += subprocess.check_output(cpp_command, encoding="utf-8")
        full_text += subprocess.check_output(cpp_command2, encoding="utf-8")

        tmp_path.write_text(full_text)
        ast = parse_file(tmp_path)

    visitor = FuncDefVisitor(full_text)
    visitor.visit(ast)

    for index, func_location in enumerate(visitor.func_locations):
        func_path = dst / f"{index:03}_{func_location.name}"
        func_path.mkdir(parents=True, exist_ok=True)
        definition_path = func_path / "func.c"
        context_path = func_path / "context.c"

        definition = full_text[func_location.full_range[0]:func_location.full_range[1]]
        definition_path.write_text(definition)

        # Initialize context with everything up to the func itself
        context = full_text[0:func_location.full_range[0]]

        # Reduce preceding function definitions to declarations
        for prev_func_location in reversed(visitor.func_locations[:index]):
            context = replace_range(context, ";", prev_func_location.body_range)

        context_path.write_text(context)

def make_file_dirname(file_path: Path, base_path: Path) -> str:
    base_path_len = len(str(base_path).split("/"))
    components = str(file_path).split("/")[base_path_len:]
    return "__".join(components)

def main():
    src = Path("src/anniversary")
    split_path = Path("split")

    for src_file_path in src.rglob("*.c"):
        dst = split_path / make_file_dirname(src_file_path, src)
        split_file(src_file_path, dst)

if __name__ == "__main__":
    main()
