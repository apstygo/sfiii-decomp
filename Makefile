PLATFORM ?= ps2
VERSION ?= anniversary

# Binaries

ifeq ($(PLATFORM),ps2)
	MAIN := THIRD_U.BIN
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
PS2_DEFINES := -DTARGET_PS2 -DDEBUG
MWCCPS2_FLAGS := -gccinc $(PS2_INCLUDES) -O0,p -c -lang c -str readonly -fl divbyzerocheck -sdatathreshold 128 $(PS2_DEFINES)
MWCCPS2_ZLIB_FLAGS := -inline off $(MWCCPS2_FLAGS)
EEGCC_FLAGS := $(PS2_INCLUDES) -O2 -G0 -c $(PS2_DEFINES) -DXPT_TGT_EE

AS_FLAGS += -EL -I $(INCLUDE_DIR) -G 128 -march=r5900 -mabi=eabi -no-pad-sections
LD_FLAGS := -main func_00100008 -map

# Files

MAIN_TARGET := $(BUILD_DIR)/$(MAIN)

S_FILES := $(shell find $(ASM_DIR) -name '*.s' -not -path *nonmatchings* 2>/dev/null)
GAME_C_FILES := $(shell find $(SRC_DIR)/sf33rd -name '*.c' -not -path '*/Compress/zlib/*' 2>/dev/null)
ZLIB_C_FILES := $(shell find $(SRC_DIR)/sf33rd/Source/Compress/zlib -name '*.c' 2>/dev/null)
CRI_C_FILES := $(shell find $(SRC_DIR)/cri -name '*.c' 2>/dev/null)
BIN2OBJ_C_FILES := $(shell find $(SRC_DIR)/bin2obj -name '*.c' 2>/dev/null)

ASM_O_FILES := $(patsubst %.s,%.s.o,$(S_FILES))
ASM_O_FILES := $(addprefix $(BUILD_DIR)/,$(ASM_O_FILES))
GAME_O_FILES := $(patsubst %.c,%.c.o,$(GAME_C_FILES))
GAME_O_FILES := $(addprefix $(BUILD_DIR)/,$(GAME_O_FILES))
ZLIB_O_FILES := $(patsubst %.c,%.c.o,$(ZLIB_C_FILES))
ZLIB_O_FILES := $(addprefix $(BUILD_DIR)/,$(ZLIB_O_FILES))
CRI_O_FILES := $(patsubst %.c,%.c.o,$(CRI_C_FILES))
CRI_O_FILES := $(addprefix $(BUILD_DIR)/,$(CRI_O_FILES))
BIN2OBJ_O_FILES := $(patsubst %.c,%.c.o,$(BIN2OBJ_C_FILES))
BIN2OBJ_O_FILES := $(addprefix $(BUILD_DIR)/,$(BIN2OBJ_O_FILES))

ALL_O_FILES := $(GAME_O_FILES) $(ZLIB_O_FILES) $(CRI_O_FILES) $(BIN2OBJ_O_FILES) $(ASM_O_FILES)
EEGCC_O_FILES := $(CRI_O_FILES) $(BIN2OBJ_O_FILES)

LINKER_SCRIPT := $(BUILD_DIR)/$(MAIN).lcf

COMPILER_TAR := mwcps2-3.0b38-030307.tar.gz
EE_COMPILER_TAR := ee-gcc2.96.tar.xz

build: $(MAIN_TARGET)

# Etc. rules

split:
	@mkdir -p $(dir $(LINKER_SCRIPT))
	$(GENERATE_LCF) $(LINKER_SCRIPT)

split_cps3:
	cargo build --release --manifest-path ./tools/saturn-splitter/rust-dis/Cargo.toml
	python3 ./tools/combine-and-decrypt.py ./sfiii3n/ ./decrypted.bin
	cargo run --release --manifest-path ./tools/saturn-splitter/rust-dis/Cargo.toml ./config/cps3/sfiii3n.yaml

clean: ##@ clean extracted files, assets, and build artifacts
	git clean -fdx $(ASM_DIR)/
	git clean -fdx build/
	git clean -fdx .splache

# Build

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

$(ZLIB_O_FILES): $(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	python3 tools/mwccgap/mwccgap.py $< $@ --mwcc-path $(MWCCPS2) --macro-inc-path $(INCLUDE_DIR)/macro.inc --use-wibo --wibo-path $(WIBO) --as-march r5900 --as-mabi eabi --target-encoding shift_jis $(MWCCPS2_ZLIB_FLAGS)
	$(PATCH_ALIGNMENT) $@

# Tools

setup_tools: $(MWCCPS2) $(WIBO) $(EEGCC)

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
