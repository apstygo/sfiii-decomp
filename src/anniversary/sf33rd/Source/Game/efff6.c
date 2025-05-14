#include "sf33rd/Source/Game/efff6.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/color3rd.h"
#include "sf33rd/Source/Game/texcash.h"
#include "sf33rd/Source/Game/debug/Debug.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff6", effect_F6_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff6", efff6_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff6", efff6_move_common);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff6", efff6_move01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff6", effect_F6_init);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff6", efff6_move01_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff6", efff6_data_tbl00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff6", efff6_etc_data);
