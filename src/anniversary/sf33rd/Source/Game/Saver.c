#include "sf33rd/Source/Game/Saver.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Saver", Saver_Task);
#else
void Saver_Task(struct _TASK *task_ptr) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Saver", Saver_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Saver", Saver_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Saver", Saver_Move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Saver", Saver_Exit);
