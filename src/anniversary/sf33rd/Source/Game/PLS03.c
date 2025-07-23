#include "sf33rd/Source/Game/PLS03.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/PulPul.h"
#include "sf33rd/Source/Game/workuser.h"

void hissatsu_setup_union(PLW *wk, s16 rno) {
    wk->wu.routine_no[1] = 4;
    wk->wu.routine_no[2] = rno;
    wk->wu.routine_no[3] = 0;
    wk->cancel_timer = 0;
    wk->wu.cg_type = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.paring_attack_flag = 0;
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", cmdixconv_table);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", cmdixconv);
#else
s16 cmdixconv(s16 ix) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_full_gauge_attack);
#else
s32 check_full_gauge_attack(PLW *wk, s8 always) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_full_gauge_attack2);
#else
s32 check_full_gauge_attack2(PLW *wk, s8 always) {
    not_implemented(__func__);
}
#endif

s16 check_super_arts_attack(PLW *wk) {
#if defined(TARGET_PS2)
    void set_super_arts_status_dc(s32 ix);
#endif

    s16 rnum = 0;
    s16 i;

    if (cmd_sel[wk->wu.id]) {
        if (wk->sa->ok != -1) {
            for (i = 0; i < 3; i++) {
                Super_Arts[wk->wu.id] = i;
                set_super_arts_status_dc(wk->wu.id);
                rnum = check_super_arts_attack_dc(wk);

                if (rnum) {
                    wk->sa->gt2 = wk->sa->gauge_type;
                    break;
                }
            }
        }
    } else {
        rnum = check_super_arts_attack_dc(wk);
    }

    return rnum;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_super_arts_attack_dc);
#else
s32 check_super_arts_attack_dc(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", execute_super_arts);
#else
s32 execute_super_arts(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_special_attack);
#else
s32 check_special_attack(PLW *wk) {
    not_implemented(__func__);
}
#endif

void chainex_spat_cancel_kidou(WORK *wk) {
    MVXY curr;

    if (wk->old_rno[1] == 4 && wk->old_rno[2] > 15) {
        curr = wk->mvxy;
        setup_mvxy_data(wk, 10);
        wk->mvxy.a[0].sp = curr.a[0].sp / 2;
        wk->mvxy.d[0].sp = 0;
        wk->mvxy.a[1].sp = curr.a[1].sp / 2;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_leap_attack);
#else
s32 check_leap_attack(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_nm_attack);
#else
s32 check_nm_attack(PLW *wk) {
    not_implemented(__func__);
}
#endif

s16 hikusugi_check(WORK *wk) {
    s16 rnum = 0;

    if ((wk->mvxy.a[1].real.h < 0) && (wk->xyz[1].disp.pos < 0x10)) {
        rnum = 1;
    }

    return rnum;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_chouhatsu);
#else
s32 check_chouhatsu(PLW *wk) {
    not_implemented(__func__);
}
#endif

s32 check_nagenuke_cmd(PLW *wk) {
    if (wk->spmv_ng_flag2 & 0x400) {
        return 0;
    }

    if (wk->cat_break_reserve) {
        return 1;
    }

    if ((wk->spmv_ng_flag2 & 0x800) && (wk->cp->sw_lvbt & 3)) {
        return 0;
    }

    if (wk->cp->sw_now & 0x660) {
        return 0;
    }

    if (wk->cp->ca14) {
        return 1;
    }

    return 0;
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", nml_catch_h2_ok);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_catch_attack);
#else
s32 check_catch_attack(PLW *wk) {
    not_implemented(__func__);
}
#endif

void set_attack_routine_number(PLW *wk) {
    wk->wu.routine_no[1] = 4;
    wk->wu.routine_no[2] = wk->as->r_no;
    wk->wu.routine_no[3] = 0;
    wk->wu.cg_type = 0;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", get_nearing_range);
#else
u16 get_nearing_range(s16 pnum, s16 kos) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", waza_select);
#else
s32 waza_select(PLW *wk, s16 kos, s16 sf) {
    not_implemented(__func__);
}
#endif

u16 decode_wst_data(PLW *wk, u16 cmd, s16 cmd_ex) {
    u16 lever;
    u16 rnum;

    if (cmd == 0) {
        return 0;
    }

    rnum = 0;
    lever = cmd & 0xF;

    switch (cmd & 0xF000) {
    case 0x4000:
        rnum = wk->cp->sw_new & lever;
        break;

    case 0x8000:
        rnum = (lever == (wk->cp->sw_new & 0xF));
        break;

    case 0x3000:
        rnum = cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex);
        break;

    case 0x7000:
        if ((wk->cp->sw_new & lever) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0xB000:
        if ((lever == (wk->cp->sw_new & 0xF)) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0x2000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0x1000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0xA000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (lever == (wk->cp->sw_new & 0xF)) &&
            (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0x9000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (lever == (wk->cp->sw_new & 0xF)) &&
            (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0x6000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = wk->cp->sw_new & lever;
        }

        break;

    case 0x5000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = wk->cp->sw_new & lever;
        }

        break;

    default:
        if (get_em_body_range(&wk->wu) >= cmd) {
            rnum = 1;
        }

        break;
    }

    return rnum;
}

s16 get_em_body_range(WORK *wk) {
#if defined(TARGET_PS2)
    s16 get_sel_hosei_tbl_ix(s32 plnum);
#endif

    WORK *em;
    s16 *dad;
    s16 res_hs;

    if (Bonus_Game_Flag == 0x14 && wk->operator != 0) {
        em = (WORK *)((WORK *)wk->target_adrs)->my_effadrs;
        dad = (s16 *)(em->hosei_adrs + (get_sel_hosei_tbl_ix(((WORK_Other *)em)->master_player) + 1));
        res_hs = wk->xyz[0].disp.pos - (em->xyz[0].disp.pos + dad[0] + (dad[1] / 2));

        if (res_hs < 0) {
            res_hs = -res_hs;
        }

        res_hs -= (dad[1] / 2);

        return res_hs;
    }

    em = (WORK *)wk->target_adrs;
    res_hs = (wk->xyz[0].disp.pos) - (em->xyz[0].disp.pos);

    if (res_hs < 0) {
        res_hs = -res_hs;
    }

    res_hs += em->hosei_adrs[1].hos_box[0];

    return res_hs;
}

s32 cmd_ex_check(s16 px, s16 cx) {
    if (cx) {
        if (cx < 0) {
            if (px + cx <= 0) {
                return 1;
            }
        } else if (px - cx >= 0) {
            return 1;
        }
    } else {
        return 1;
    }

    return 0;
}

const s16 shot_prio[6][2] = { { 256, 3 }, { 16, 0 }, { 512, 4 }, { 32, 1 }, { 1024, 5 }, { 64, 2 } };

s16 shot_data_convert(u16 sw) {
    s16 i;
    s16 rnum = -1;

    for (i = 0; i < 6; i++) {
        if (sw & shot_prio[i][0]) {
            rnum = shot_prio[i][1];
        }
    }

    return rnum;
}

const s16 shot_refresh[6] = { 16, 32, 64, 256, 512, 1024 };

s16 shot_data_refresh(s16 sw) {
    return shot_refresh[sw];
}

const s16 rc_shot_conv[16] = { 16, 32, 64, 112, 256, 512, 1024, 1792, 272, 544, 1088, 1904, 0, 0, 0, 0 };

s16 renbanshot_conpaneshot(const s16 *dadr, s16 pow) {
    return rc_shot_conv[dadr[pow] & 0xF];
}

s16 datacmd_conpanecmd(s16 dat) {
    dat = (dat & 0x700) >> 1 | (dat & 0x7F);
    return dat;
}

const u8 renda_status_table[4] = { 0, 20, 32, 0 };

s32 check_renda_cancel(PLW *wk) {
    if (wk->wu.rl_flag != wk->wu.rl_waza) {
        return 0;
    }

    wk->permited_koa |= 32;

    if (wk->wu.pat_status == renda_status_table[(wk->cp->sw_new & 3)] &&
        wk->current_attack == (wk->cp->sw_now & 0x770)) {
        setup_comm_back(&wk->wu);
        wk->wu.cg_ix = wk->wu.cg_eftype * wk->wu.cgd_type - (wk->wu.cgd_type * 2);
        wk->wu.cg_next_ix = 0;
        wk->wu.cg_ctr = 1;
        wk->wu.meoshi_hit_flag = 0;
        wk->wu.att_hit_ok = 0;
        wk->wu.hf.hit_flag = 0;
        wk->caution_flag = 1;
        wk->cancel_timer = 0;
        wk->wu.cg_cancel &= 0xE0;
        pp_pulpara_remake_at_init2(&wk->wu);
        return 1;
    }

    return 0;
}

const s16 cnmc_conv_data[16] = { 5, 8, 2, 0, 4, 7, 1, 0, 6, 9, 3, 0, 0, 0, 0, 0 };

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", cnmc_Z_lever_data);
// TODO: rename to cnmc_z_lever_data
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", _cnmc_z_lever_data);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_meoshi_cancel);
#else
s32 check_meoshi_cancel(PLW *wk) {
    not_implemented(__func__);
}
#endif

const s16 gml_real_lever_data[16] = { 0, 6, 2, 10, 4, 0, 8, 5, 1, 9, 0, 0, 4, 8, 4, 8 };

s16 get_meoshi_lever(s16 data) {
    return gml_real_lever_data[data & 0xF];
}

s16 get_meoshi_shot(s16 data) {
    return ((data & 0x700) >> 1) + (data & 0x70);
}

const s16 cmdshot_conv_tbl[32] = { 16,   32,   64,   128,  256,  512,  1024, 2048, 272,  544,  1088, 2176, 0, 0, 0, 0,
                                   1904, 1904, 1904, 1920, 1904, 1904, 1904, 2160, 1904, 1904, 1904, 2176, 0, 0, 0, 0 };
