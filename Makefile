PLATFORM ?= ps2
VERSION ?= anniversary

OS := $(shell uname -s)
IS_WINDOWS_HOST := $(findstring MINGW,$(OS))$(findstring CYGWIN,$(OS))

CROSS_COMPILING :=
ifeq ($(PLATFORM),windows)
  ifneq ($(IS_WINDOWS_HOST),)
    # Native Windows build
  else
    # Cross-compiling from non-Windows
    CROSS_COMPILING := 1
  endif
endif

ifeq ($(OS)_$(PLATFORM),Darwin_ps2)
$(error Can't build for PS2 on macOS. Did you mean 'make PLATFORM=macos'?)
endif

ifneq ($(OS),Darwin)
ifeq ($(PLATFORM),macos)
$(error Can't build for macOS on a non-macOS machine.)
endif
endif

# Binaries

ifeq ($(PLATFORM),ps2)
	MAIN := THIRD_U.BIN
else ifeq ($(PLATFORM),windows)
	MAIN := sf33rd.exe
else
	MAIN := sf33rd
endif

# Export so that Python could see those
export PLATFORM
export VERSION
export MAIN

# Directories

BIN_DIR := bin
BUILD_DIR := build/$(VERSION)/$(PLATFORM)
SRC_DIR := src/$(VERSION)
ASM_DIR := asm/$(VERSION)
INCLUDE_DIR := include
ASSETS_DIR := assets/$(VERSION)
CONFIG_DIR := config/$(VERSION)
TOOLS_DIR := tools
EEGCC_PATHS := PATH=$(BIN_DIR)/ee/bin:$(BIN_DIR)/lib/gcc-lib/ee/2.96-ee-001003-1

# Tools

WIBO := $(BIN_DIR)/wibo
MWCCPS2 := $(BIN_DIR)/mwccps2.exe
MWLDPS2 := MWCIncludes=$(BIN_DIR) $(WIBO) $(BIN_DIR)/mwldps2.exe

EEGCC := $(BIN_DIR)/ee/bin/gcc

CCPS2 := MWCIncludes=$(BIN_DIR) $(WIBO) $(MWCCPS2)

CC := $(CCPS2)

ifeq ($(PLATFORM),ps2)
	CC := $(CCPS2)
else
	ifeq ($(CROSS_COMPILING),1)
		CC := x86_64-w64-mingw32-clang
	else
		CC := clang
	endif
endif

AS := mipsel-linux-gnu-as
LD := $(MWLDPS2)

PYTHON := python3
SPLICE_ELF := $(PYTHON) $(TOOLS_DIR)/splice_elf.py
COMPARE_BYTES := $(PYTHON) $(TOOLS_DIR)/compare_bytes.py
PATCH_ALIGNMENT := $(PYTHON) $(TOOLS_DIR)/patch_alignment.py
GENERATE_LCF := $(PYTHON) -m tools.lcf.generate_lcf

# Flags

COMMON_INCLUDES := -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/sdk -I$(INCLUDE_DIR)/cri -I$(INCLUDE_DIR)/cri/ee -Izlib
PS2_INCLUDES := $(COMMON_INCLUDES) -I$(INCLUDE_DIR)/gcc
PS2_DEFINES := -DTARGET_PS2
MWCCPS2_FLAGS := -gccinc $(PS2_INCLUDES) -O0,p -c -lang c -str readonly -fl divbyzerocheck -sdatathreshold 128 $(PS2_DEFINES)
EEGCC_FLAGS := $(PS2_INCLUDES) -O2 -G0 -c $(PS2_DEFINES) -DXPT_TGT_EE

AS_FLAGS += -EL -I $(INCLUDE_DIR) -G 128 -march=r5900 -mabi=eabi -no-pad-sections
LD_FLAGS := -main func_00100008 -map

CLANG_WARNINGS := -Wall -Werror
CLANG_WARNINGS += -Wpointer-to-int-cast
CLANG_WARNINGS += -Wno-macro-redefined -Wno-deprecated-non-prototype
CLANG_WARNINGS += -Wno-missing-braces -Wno-self-assign -Wno-format
CLANG_WARNINGS += -Wno-tautological-constant-out-of-range-compare -Wno-tautological-overlap-compare
CLANG_WARNINGS += -Wno-gcc-compat -Wno-unknown-pragmas -Wno-c2x-extensions
CLANG_WARNINGS += -Wno-unused-value -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-comparison -Wno-unused-function

# These should be enabled in the future
CLANG_WARNINGS += -Wno-int-to-pointer-cast
CLANG_WARNINGS += -Wno-int-conversion
CLANG_WARNINGS += -Wno-incompatible-pointer-types
CLANG_WARNINGS += -Wno-incompatible-function-pointer-types
CLANG_WARNINGS += -Wno-pointer-sign
CLANG_WARNINGS += -Wno-shift-count-overflow

CLANG_DEFINES := -DTARGET_SDL3 -DSOUND_DISABLED -DXPT_TGT_EE -D_POSIX_C_SOURCE -DDEBUG
CLANG_INCLUDES := $(COMMON_INCLUDES) -Ilibco
CLANG_FLAGS := $(CLANG_INCLUDES) $(CLANG_WARNINGS) $(CLANG_DEFINES) -std=c99 -O0

ifeq ($(PLATFORM),windows)
  ifeq ($(CROSS_COMPILING),1)
    LIBCO_A := libco/build/libco.a
  else
    LIBCO_A := libco/build/Debug/libco.lib
  endif
else
  LIBCO_A := libco/build/liblibco.a
endif

ifeq ($(PLATFORM),windows)
CLANG_LINKER_FLAGS := -g
else
CLANG_LINKER_FLAGS := -g -Llibco/build -llibco -lm
endif

# SDL3 dependency for Windows cross-compilation
SDL3_WINDOWS_URL := https://github.com/libsdl-org/SDL/releases/download/release-3.2.22/SDL3-devel-3.2.22-mingw.tar.gz
SDL3_WINDOWS_TAR := build/deps/SDL3-devel-3.2.22-mingw.tar.gz
SDL3_WINDOWS_DIR := build/deps/SDL3-devel-3.2.22-mingw
SDL3_PREFIX ?= $(SDL3_WINDOWS_DIR)/x86_64-w64-mingw32

ifneq ($(PLATFORM),ps2)
	ifeq ($(PLATFORM),windows)
		CLANG_FLAGS += -I"$(SDL3_PREFIX)/include" -D_CRT_SECURE_NO_WARNINGS
		CLANG_LINKER_FLAGS += -L"$(SDL3_PREFIX)/lib" -lSDL3
	else
		CLANG_FLAGS += $(shell pkg-config --cflags sdl3)
		CLANG_LINKER_FLAGS += $(shell pkg-config --libs sdl3)
	endif
endif

# Files

MAIN_TARGET := $(BUILD_DIR)/$(MAIN)

S_FILES := $(shell find $(ASM_DIR) -name '*.s' -not -path *nonmatchings* 2>/dev/null)
GAME_C_FILES := $(shell find $(SRC_DIR)/sf33rd -name '*.c' 2>/dev/null)
CRI_C_FILES := $(shell find $(SRC_DIR)/cri -name '*.c' 2>/dev/null)
BIN2OBJ_C_FILES := $(shell find $(SRC_DIR)/bin2obj -name '*.c' 2>/dev/null)
PORT_C_FILES := $(shell find $(SRC_DIR)/port -name '*.c' 2>/dev/null)
ZLIB_C_FILES := $(shell find zlib -name '*.c' 2>/dev/null)

ASM_O_FILES := $(patsubst %.s,%.s.o,$(S_FILES))
ASM_O_FILES := $(addprefix $(BUILD_DIR)/,$(ASM_O_FILES))
GAME_O_FILES := $(patsubst %.c,%.c.o,$(GAME_C_FILES))
GAME_O_FILES := $(addprefix $(BUILD_DIR)/,$(GAME_O_FILES))
CRI_O_FILES := $(patsubst %.c,%.c.o,$(CRI_C_FILES))
CRI_O_FILES := $(addprefix $(BUILD_DIR)/,$(CRI_O_FILES))
BIN2OBJ_O_FILES := $(patsubst %.c,%.c.o,$(BIN2OBJ_C_FILES))
BIN2OBJ_O_FILES := $(addprefix $(BUILD_DIR)/,$(BIN2OBJ_O_FILES))
PORT_O_FILES := $(patsubst %.c,%.c.o,$(PORT_C_FILES))
PORT_O_FILES := $(addprefix $(BUILD_DIR)/,$(PORT_O_FILES))
ZLIB_O_FILES := $(patsubst %.c,%.c.o,$(ZLIB_C_FILES))
ZLIB_O_FILES := $(addprefix $(BUILD_DIR)/,$(ZLIB_O_FILES))

ifeq ($(PLATFORM),ps2)
	ALL_O_FILES := $(GAME_O_FILES) $(CRI_O_FILES) $(BIN2OBJ_O_FILES) $(ASM_O_FILES)
	EEGCC_O_FILES := $(CRI_O_FILES) $(BIN2OBJ_O_FILES)
else
	ALL_O_FILES := $(GAME_O_FILES) $(CRI_O_FILES) $(BIN2OBJ_O_FILES) $(PORT_O_FILES) $(ZLIB_O_FILES)
endif

LINKER_SCRIPT := $(BUILD_DIR)/$(MAIN).lcf

COMPILER_TAR := mwcps2-3.0b38-030307.tar.gz
EE_COMPILER_TAR := ee-gcc2.96.tar.xz

build: $(MAIN_TARGET)

# Etc. rules

split:
	@mkdir -p $(dir $(LINKER_SCRIPT))
	$(GENERATE_LCF) $(LINKER_SCRIPT)

clean: ##@ clean extracted files, assets, and build artifacts
	git clean -fdx $(ASSETS_DIR)/
	git clean -fdx $(ASM_DIR)/
	git clean -fdx build/
	git clean -fdx .splache

# Build

ifeq ($(PLATFORM),ps2)

$(MAIN_TARGET): $(ALL_O_FILES) $(LINKER_SCRIPT)
	@$(LD) $(LD_FLAGS) -o $@ \
		$(LINKER_SCRIPT) \
		$(shell find $(BUILD_DIR) -name '*.o')

	$(COMPARE_BYTES) $(MAIN) $(MAIN_TARGET) 0x80 0x478A00

$(BUILD_DIR)/%.s.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(AS_FLAGS) -o $@ $<
	$(PATCH_ALIGNMENT) $@

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	python3 tools/mwccgap/mwccgap.py $< $@ --mwcc-path $(MWCCPS2) --macro-inc-path $(INCLUDE_DIR)/macro.inc --use-wibo --wibo-path $(WIBO) --as-march r5900 --as-mabi eabi --target-encoding shift_jis $(MWCCPS2_FLAGS)
	$(PATCH_ALIGNMENT) $@

$(CRI_O_FILES): $(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(EEGCC_PATHS) $(EEGCC) $< -o $@ $(EEGCC_FLAGS)

else

$(MAIN_TARGET): $(ALL_O_FILES) $(LIBCO_A)
ifeq ($(PLATFORM),windows)
	@find build -name '*.o' > $(BUILD_DIR)/objects.txt
	@echo $(LIBCO_A) >> $(BUILD_DIR)/objects.txt
	$(CC) @$(BUILD_DIR)/objects.txt $(CLANG_LINKER_FLAGS) -o $@
else
	$(CC) $(ALL_O_FILES) $(LIBCO_A) $(CLANG_LINKER_FLAGS) -o $@
endif

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -g -c $< -o $@ $(CLANG_FLAGS)

CMAKE_CMD = cmake ..
ifeq ($(CROSS_COMPILING),1)
CMAKE_CMD = cmake .. -DCMAKE_TOOLCHAIN_FILE=../../tools/toolchain-windows.cmake
endif

$(LIBCO_A):
	@mkdir -p $(dir $@)
	cd libco && \
		mkdir -p build && \
		cd build && \
		$(CMAKE_CMD) && \
		cmake --build .

endif

# Tools

setup_tools: $(MWCCPS2) $(WIBO) $(EEGCC)

$(SDL3_WINDOWS_DIR)/.stamp:
	@echo "Downloading and extracting SDL3 for Windows cross-compilation..."
	@mkdir -p build/deps
	@wget -O $(SDL3_WINDOWS_TAR) $(SDL3_WINDOWS_URL)
	@tar -xzf $(SDL3_WINDOWS_TAR) -C build/deps
	@mv build/deps/SDL3-3.2.22 $(SDL3_WINDOWS_DIR)
	@touch $@

ifeq ($(CROSS_COMPILING),1)
$(MAIN_TARGET): $(SDL3_WINDOWS_DIR)/.stamp
endif

$(WIBO):
	@mkdir -p $(BIN_DIR)
	wget -O $@ https://github.com/decompals/wibo/releases/download/0.6.13/wibo
	chmod +x $(WIBO)

$(MWCCPS2):
	@mkdir -p $(BIN_DIR)
	wget -O- https://github.com/decompme/compilers/releases/download/compilers/$(COMPILER_TAR) | tar xzv -C $(BIN_DIR)

$(EEGCC):
	@mkdir -p $(BIN_DIR)
	wget -O- https://github.com/decompme/compilers/releases/download/compilers/$(EE_COMPILER_TAR) | tar xJv -C $(BIN_DIR)
