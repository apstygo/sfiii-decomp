# Decompiling

This article will guide you through the process of decompiling an assembly file into C code.

## Setup

0. Be sure to follow the [build guide](https://github.com/apstygo/sfiii-decomp/wiki/Building) first.
1. Run `make split` to generate the assembly files.
2. Download [decomp-toolkit](https://github.com/encounter/decomp-toolkit) and run `dtk dwarf dump THIRD_U.BIN`. The output of this command contains a lot of useful info, such as function signatures, argument registers, memory addresses and local variables.
3. (Optional) Use `tools/dump_lines.py` to extract line information. This may come in handy if you can't figure something out. For instructions on how to use the tool check the docstring inside the script.

## Choosing a file/function to decompile

The project is set up to allow decompiling single functions. You are free to choose any function from any file. PRs of any size are welcome!

> 💡 If you are not sure where to start, choose any of the files marked as `Good first decomp` in config/anniversary/sfiii.anniversary.yaml.

There is no need to decompile PS2 SDK and GCC files. SDK decompilation is outside the scope of this project.

SF Anniversary Collection uses CRI Middleware. Though it is necessary to decompile CRI to enable ports, not all CRI functions are actually used in the game. For a list of CRI functions to decompile and their decompilation status see [cri-progress.md](https://github.com/apstygo/sfiii-decomp/blob/main/cri-progress.md).

## Creating a C file

If the file you want to decompile is marked as `asm` in sfiii.anniversary.yaml then there won't be a corresponding C file in src folder. To fix this do the following:

1. Change the file's segment type from `asm` to `c` in config/anniversary/sfiii.anniversary.yaml. If there's a corresponding `rodata` segment change its type to `.rodata`.
2. Run `make clean && make split`. This will make splat resplit the binary and create the C file.
3. Make sure that build still matches by running `make build -j`.

## Decompiling a function using `decomp.me`

1. Choose a function to decompile.
2. Create a scratch on `decomp.me`.
    - Use preset `Street Fighter III: 3rd Strike (Anniversary Collection)`.
    - Copy the function into the `Target assembly` field.
    - Run `python3 tools/m2ctx.py <path to C file>` and copy the contents of `ctx.c` into the `Context` field.
3. If there are unrecognised symbols at the top of the decompiled code you'll have to declare them. After declaring all symbols update context, press "Decompile" and copy the code from the right pane to the left pane.
    - If a symbol is a part of the file you are decompiling and is not referenced in other files, forward declare it in the `.c` file.
    - If a symbol is a part of the file you are decompiling and is referenced in other files, declare it in the `.h` file.
    - If a symbol is not a part of the file you are decompiling, declare it in the header corresponding to the file it originates from (e.g. `Opening_Now` is defined in src/sf33rd/Source/Game/workuser.c and so should be declared in include/sf33rd/Source/Game/workuser.h). Be mindful of formatting and order of declarations. Declarations are (usually) ordered according to their VRAM offset.
4. Edit the code until you get a 100% match.
5. Replace `INCLUDE_ASM` entry corresponding to the function with the newly decompiled function.
6. Run `make build` to check if everything matches. If you see ✅, you are done. Great work!

## Decompiling rodata and strings

TODO

## Decompiling data/sdata/bss/sbss

TODO

## How to fix misalignment issues

TODO

## Decompiling functions with jumptables

TODO
