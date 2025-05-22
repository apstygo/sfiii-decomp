#include "sf33rd/Source/Game/stun.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/stun", stngauge_cont_init);
#else
void stngauge_cont_init() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/stun", stngauge_cont_main);
#else
void stngauge_cont_main() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/stun", stngauge_control);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/stun", stngauge_work_clear);
#else
void stngauge_work_clear() {
    not_implemented(__func__);
}
#endif
