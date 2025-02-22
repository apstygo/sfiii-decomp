#include "sf33rd/Source/Game/CHARSET.h"
#include "common.h"

extern const u16 acatkoa_table[65];

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", set_char_move_init);

void setupCharTableData(WORK *wk, s32 clr, s32 info) {
    u32 *dst = (u32 *)&wk->cg_type;
    u32 *src;
    s32 i;

    if (info != 0) {
        src = wk->set_char_ad;
        dst[-1] = src[-1];
        dst[-2] = src[-2];

        if (clr != 0) {
            for (i = 0; i < 6; i++) {
                dst[i] = 0;
            }
        }
    } else {
        src = wk->set_char_ad + wk->cg_ix;

        for (i = 0; i < wk->cgd_type; i++) {
            dst[i] = src[i];
        }
    }
}

void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf) {
    u8 pst;
    u8 kow;

    if (index < 0) {
        index = 0;
    }

    if (ip <= 0) {
        ip = 1;
    }

    pst = wk->pat_status;
    kow = wk->kind_of_waza;
    wk->now_koc = koc;
    wk->char_index = index;
    wk->set_char_ad = wk->char_table[koc] + (wk->char_table[koc][index] / 4);
    setupCharTableData(wk, 1, 1);
    wk->cg_ix = (ip - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;

    if (wk->cmoa.pat == 0) {
        wk->cmoa.koc = wk->now_koc;
        wk->cmoa.ix = wk->char_index;
        wk->cmoa.pat = 1;
    }

    if (scf) {
        wk->pat_status = pst;
        wk->kind_of_waza = kow;
    } else {
        wk->kow = wk->kind_of_waza;
    }

    if (wk->work_id & 0xF) {
        wk->at_koa = acatkoa_table[wk->kind_of_waza];
    }

    wk->K5_init_flag = 1;
    char_move(wk);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", exset_char_move_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_z);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_wca);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_wca_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wca);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_index);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_cmja);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_cmj4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_cmms);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_cmms2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_cmms3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_cmhs);

void char_move(WORK *wk) {
    wk->K5_exec_ok = 1;

    if (--wk->cg_ctr == 0) {
        check_cm_extended_code(wk);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", check_cm_extended_code);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_dummy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_roa);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_end);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_jmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_jpss);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_jsr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ret);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_sps);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_setr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_addr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_if_l);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_djmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_for);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_nex);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_for2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_nex2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja5);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja5);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja6);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja6);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja7);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja7);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rmja);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_umja);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_mdat);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ydat);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_mpos);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_cafr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_care);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_psxy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ps_x);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ps_y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_paxy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_pa_x);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_pa_y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_exec);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rngc);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_mxyt);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_pjmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_hjmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_hclr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ixfw);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ixbw);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_quax);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_quay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_if_s);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rapp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rapk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_gets);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_s123);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_s456);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_a123);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_a456);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_smhf);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ngme);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ngem);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_iflb);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_asxy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_schx);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_schy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_back);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_mvix);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_sajp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ccch);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wset);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wswk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wadd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wceq);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wcne);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wcgt);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wclt);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wadd2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wceq2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wcne2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wcgt2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wclt2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rapp2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rapk2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_iflg);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_mpcy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_epcy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_imgs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_imgc);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rvxy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rv_x);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rv_y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ccfl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_myhp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_emhp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_exbgs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_exbgc);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_atmf);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_chkwf);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_retmj);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_sstx);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ssty);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ngda);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_flip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_kage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_dspf);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ifrlf);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_srlf);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_bgrlf);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_scmd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rljmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ifs2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_abbak);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_sse);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_s_chg);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_schg2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rhsja);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uhsja);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ifcom);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_axjmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ayjmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ifs3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", decord_if_jump);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", get_comm_if_lever);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", get_comm_if_shot);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", get_comm_if_shot_now_off);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", get_comm_if_shot_now);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", get_comm_if_lvsh);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", get_comm_djmp_lever_dir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", setup_comm_back);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", setup_comm_retmj);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", setup_comm_abbak);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", check_cgd_patdat);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", check_xcopy_filter_se_req);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", check_cgd_patdat2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", set_new_attnum);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", setup_metamor_kezuri);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", set_jugde_area);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", get_char_data_zanzou);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", jphos_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", kezuri_pow_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", decode_chcmd);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", decode_if_lever);

const u16 acatkoa_table[65] = { 4,   4,   8,   8,   8,   8,   8,   8,   16,  16,  16,  16,  16,  16,  16,  16,  32,
                                32,  32,  32,  32,  32,  32,  32,  64,  64,  64,  64,  64,  64,  64,  64,  128, 128,
                                128, 128, 128, 128, 128, 128, 256, 256, 256, 256, 256, 256, 256, 256, 128, 128, 128,
                                128, 128, 128, 128, 128, 256, 256, 256, 256, 256, 256, 256, 256, 2048 };
