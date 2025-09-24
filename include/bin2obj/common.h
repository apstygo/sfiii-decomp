#ifndef BIN2OBJ_COMMON_H
#define BIN2OBJ_COMMON_H

#if defined(TARGET_PS2)
#pragma define_section __data ".data"
#define DATA_SECTION __declspec(__data)
#else
#define DATA_SECTION
#endif

#endif
