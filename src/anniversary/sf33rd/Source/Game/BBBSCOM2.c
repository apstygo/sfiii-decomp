#include "sf33rd/Source/Game/BBBSCOM2.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM2", bbbs_com_execute2);
#else
void bbbs_com_execute2(PLW *wk) {
    not_implemented(__func__);
}
#endif
