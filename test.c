// Build with:
// > python3 tools/mwccgap/mwccgap.py test.c test.o --mwcc-path bin/mwccps2.exe --macro-inc-path include/macro.inc --use-wibo --wibo-path bin/wibo --as-march r5900 --as-mabi eabi --target-encoding shift_jis -gccinc -Iinclude -Iinclude/sdk -Iinclude/cri -Iinclude/cri/ee -Iinclude/gcc -O0,p -c -lang c -str readonly -fl divbyzerocheck -sdatathreshold 128 -DTARGET_PS2 -D__mips64

#include "common.h"

#define ADX_STM_WORK_SIZE 252388

// bss
u8 adx_VS[198954];
u8 adx_EmSel[391168];
s8 adx_stm_work[ADX_STM_WORK_SIZE];

// Uncomment next line to reproduce the bug
// INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", sound_request_for_dc);
