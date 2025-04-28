#include "sf33rd/Source/Game/color3rd.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", q_ldreq_color_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", cseTsbSetBankAddr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", cseMemMapSetPhdAddr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", load_any_color);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", set_hitmark_color);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", init_trans_color_ram);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", init_color_trans_req);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", push_color_trans_req);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palCopyGhostDC);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palConvSrcToRam);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palCreateGhost);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palGetChunkGhostDC);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palGetChunkGhostCP3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palUpdateGhostDC);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palUpdateGhostCP3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palConvRowTim2CI8Clut);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", hitmark_color);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", color_file);
