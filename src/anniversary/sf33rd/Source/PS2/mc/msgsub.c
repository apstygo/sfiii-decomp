#include "sf33rd/Source/PS2/mc/msgsub.h"
#include "common.h"

// sbss
s32 MsgLanguage;

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/msgsub", GetMemCardMsg);
#else
s8 **GetMemCardMsg(s32 msg_no) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/msgsub", FormStrDisp);
#else
s32 FormStrDisp(s32 x, s32 y, s8 *str, s32 len) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/msgsub", str_tag_get);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/msgsub", str_str_get);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/msgsub", literal_312_00560480);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/msgsub", str_tag_check);
