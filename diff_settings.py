def apply(config, args):
    config["baseimg"] = "THIRD_U.BIN"
    config["myimg"] = "build/anniversary/ps2/THIRD_U.BIN"
    config["mapfile"] = "build/anniversary/ps2/THIRD_U.BIN.xMAP"
    config["source_directories"] = ["src"]
    # config["show_line_numbers_default"] = True
    config["arch"] = "mipsee"
    config["map_format"] = "mw" # gnu, mw, ms
    # config["build_dir"] = "build/" # only needed for mw and ms map format
    config["expected_dir"] = "" # needed for -o
    # config["makeflags"] = []
    config["objdump_executable"] = "mipsel-linux-gnu-objdump"
