#include "sf33rd/Source/Game/effL4.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_L4_move(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
        }

        if ((obr_no_disp_check() == 0) && (range_x_check3(ewk, 0xD0))) {
            ewk->wu.position_x = (ewk->wu.xyz[0].disp.pos & 0xFFFF) + 1;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
            sort_push_request4(&ewk->wu);
        }
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effL4", effect_L4_init);
#else
s32 effect_L4_init() {
    not_implemented(__func__);
}
#endif

const s16 effl4_data_tbl[24] = { 0x008F, 0x0060, 0x0049, 0x0009, 0x00DF, 0x0078, 0x0049, 0x000A,
                                 0x012F, 0x0068, 0x0049, 0x000B, 0x016F, 0x0070, 0x0049, 0x000C,
                                 0x018F, 0x0090, 0x0049, 0x000D, 0x01E7, 0x0078, 0x0049, 0x000E };
