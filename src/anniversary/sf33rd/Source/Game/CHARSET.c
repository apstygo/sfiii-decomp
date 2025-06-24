#include "sf33rd/Source/Game/CHARSET.h"
#include "common.h"
#include "sf33rd/Source/Game/EFFXX.h"
#include "sf33rd/Source/Game/Grade.h"
#include "sf33rd/Source/Game/HITCHECK.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/PLS03.h"
#include "sf33rd/Source/Game/Se_Data.h"
#include "sf33rd/Source/Game/workuser.h"

#define LO_2_BYTES(_val) (((s16 *)&_val)[0])
#define HI_2_BYTES(_val) (((s16 *)&_val)[1])
#define WK_AS_PLW ((PLW *)wk)

extern const u16 acatkoa_table[65];
extern s32 (*const decode_chcmd[125])();
extern const s16 jphos_table[16];
extern const s16 kezuri_pow_table[5];

static u16 check_xcopy_filter_se_req(WORK *wk);
void setup_metamor_kezuri(WORK *wk);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", set_char_move_init);
#else
void set_char_move_init(WORK *wk, s16 koc, s16 index) {
    not_implemented(__func__);
}
#endif

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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", char_move_z);
#else
void char_move_z(WORK *wk) {
    not_implemented(__func__);
}
#endif

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

void check_cm_extended_code(WORK *wk) {
    UNK11 *cpc;

    if (wk->cg_next_ix) {
        wk->cg_ix = (wk->cg_next_ix - 1) * wk->cgd_type;
    } else {
        wk->cg_ix += wk->cgd_type;
    }

    while (1) {
        cpc = (UNK11 *)(wk->set_char_ad + wk->cg_ix);

        if (cpc->code >= 0x100) {
            check_cgd_patdat(wk);
            return;
        }

        if (decode_chcmd[cpc->code](wk, cpc) == 0) {
            break;
        }

        wk->cg_ix += wk->cgd_type;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_dummy);
#else
s32 comm_dummy(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_roa);
#else
s32 comm_roa(WORK *wk, UNK11 * /* unused */) {
    if (wk->cmoa.pat == 0) {
        wk->cmoa.koc = wk->now_koc;
        wk->cmoa.ix = wk->char_index;
        wk->cmoa.pat = 1;
    }

    set_char_move_init2(wk, wk->cmoa.koc, wk->cmoa.ix, wk->cmoa.pat, 0);
    return 0;
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_end);
#else
s32 comm_end(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_jmp);
#else
s32 comm_jmp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_jpss);
#else
s32 comm_jpss(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_jsr);
#else
s32 comm_jsr(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ret);
#else
s32 comm_ret(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_sps);
#else
s32 comm_sps(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_setr);
#else
s32 comm_setr(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_addr);
#else
s32 comm_addr(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_if_l);
#else
s32 comm_if_l(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_djmp);
#else
s32 comm_djmp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

s32 comm_for(WORK *wk, UNK11 *ctc) {
    if (ctc->pat & 0x4000) {
        wk->cmlp.code = wk->cmwk[ctc->pat & 0xF];
    } else {
        wk->cmlp.code = ctc->pat;
    }

    wk->cmlp.koc = wk->now_koc;
    wk->cmlp.ix = wk->char_index;
    wk->cmlp.pat = wk->cg_ix / wk->cgd_type + 2;
    return 1;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_nex);
#else
s32 comm_nex(WORK *wk, UNK11 *ctc) {
    if (wk->cmlp.code) {
        if (--wk->cmlp.code > 0) {
            set_char_move_init2(wk, wk->cmlp.koc, wk->cmlp.ix, wk->cmlp.pat, 1);
            return 0;
        }
    }

    return 1;
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_for2);
#else
s32 comm_for2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_nex2);
#else
s32 comm_nex2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja);
#else
s32 comm_rja(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja);
#else
s32 comm_uja(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja2);
#else
s32 comm_rja2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja2);
#else
s32 comm_uja2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja3);
#else
s32 comm_rja3(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja3);
#else
s32 comm_uja3(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja4);
#else
s32 comm_rja4(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja4);
#else
s32 comm_uja4(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja5);
#else
s32 comm_rja5(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja5);
#else
s32 comm_uja5(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja6);
#else
s32 comm_rja6(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja6);
#else
s32 comm_uja6(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rja7);
#else
s32 comm_rja7(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uja7);
#else
s32 comm_uja7(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rmja);
#else
s32 comm_rmja(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_umja);
#else
s32 comm_umja(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_mdat);
#else
s32 comm_mdat(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ydat);
#else
s32 comm_ydat(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_mpos);
#else
s32 comm_mpos(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_cafr);
#else
s32 comm_cafr(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_care);
#else
s32 comm_care(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_psxy);
#else
s32 comm_psxy(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ps_x);
#else
s32 comm_ps_x(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ps_y);
#else
s32 comm_ps_y(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_paxy);
#else
s32 comm_paxy(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_pa_x);
#else
s32 comm_pa_x(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

s32 comm_pa_y(WORK *wk, UNK11 *ctc) {
    WORK *emwk;

    switch (ctc->koc) {
    case 0:
        wk->xyz[1].cal += ctc->pat << 8;
        break;

    case 2:
        wk->xyz[1].cal += ctc->pat << 8;
        /* fallthrough */

    default:
        emwk = (WORK *)wk->target_adrs;
        emwk->xyz[1].cal += ctc->pat << 8;
        break;
    }

    return 1;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_exec);
#else
s32 comm_exec(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rngc);
#else
s32 comm_rngc(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_mxyt);
#else
s32 comm_mxyt(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_pjmp);
#else
s32 comm_pjmp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_hjmp);
#else
s32 comm_hjmp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_hclr);
#else
s32 comm_hclr(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ixfw);
#else
s32 comm_ixfw(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

s32 comm_ixbw(WORK *wk, UNK11 *ctc) {
    if ((test_flag == 0) || (ixbfw_cut == 0)) {
        wk->cg_ix -= (ctc->pat + 1) * wk->cgd_type;
    }

    return 1;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_quax);
#else
s32 comm_quax(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_quay);
#else
s32 comm_quay(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_if_s);
#else
s32 comm_if_s(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rapp);
#else
s32 comm_rapp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rapk);
#else
s32 comm_rapk(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_gets);
#else
s32 comm_gets(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_s123);
#else
s32 comm_s123(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_s456);
#else
s32 comm_s456(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_a123);
#else
s32 comm_a123(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_a456);
#else
s32 comm_a456(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_stop);
#else
s32 comm_stop(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_smhf);
#else
s32 comm_smhf(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ngme);
#else
s32 comm_ngme(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ngem);
#else
s32 comm_ngem(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_iflb);
#else
s32 comm_iflb(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_asxy);
#else
s32 comm_asxy(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_schx);
#else
s32 comm_schx(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_schy);
#else
s32 comm_schy(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_back);
#else
s32 comm_back(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_mvix);
#else
s32 comm_mvix(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_sajp);
#else
s32 comm_sajp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ccch);
#else
s32 comm_ccch(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wset);
#else
s32 comm_wset(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wswk);
#else
s32 comm_wswk(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wadd);
#else
s32 comm_wadd(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wceq);
#else
s32 comm_wceq(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wcne);
#else
s32 comm_wcne(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wcgt);
#else
s32 comm_wcgt(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wclt);
#else
s32 comm_wclt(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wadd2);
#else
s32 comm_wadd2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wceq2);
#else
s32 comm_wceq2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wcne2);
#else
s32 comm_wcne2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wcgt2);
#else
s32 comm_wcgt2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_wclt2);
#else
s32 comm_wclt2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rapp2);
#else
s32 comm_rapp2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rapk2);
#else
s32 comm_rapk2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_iflg);
#else
s32 comm_iflg(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_mpcy);
#else
s32 comm_mpcy(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_epcy);
#else
s32 comm_epcy(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_imgs);
#else
s32 comm_imgs(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_imgc);
#else
s32 comm_imgc(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rvxy);
#else
s32 comm_rvxy(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rv_x);
#else
s32 comm_rv_x(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rv_y);
#else
s32 comm_rv_y(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ccfl);
#else
s32 comm_ccfl(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_myhp);
#else
s32 comm_myhp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_emhp);
#else
s32 comm_emhp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_exbgs);
#else
s32 comm_exbgs(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_exbgc);
#else
s32 comm_exbgc(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_atmf);
#else
s32 comm_atmf(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_chkwf);
#else
s32 comm_chkwf(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_retmj);
#else
s32 comm_retmj(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_sstx);
#else
s32 comm_sstx(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ssty);
#else
s32 comm_ssty(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ngda);
#else
s32 comm_ngda(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_flip);
#else
s32 comm_flip(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_kage);
#else
s32 comm_kage(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_dspf);
#else
s32 comm_dspf(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ifrlf);
#else
s32 comm_ifrlf(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_srlf);
#else
s32 comm_srlf(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_bgrlf);
#else
s32 comm_bgrlf(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_scmd);
#else
s32 comm_scmd(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rljmp);
#else
s32 comm_rljmp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ifs2);
#else
s32 comm_ifs2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_abbak);
#else
s32 comm_abbak(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_sse);
#else
s32 comm_sse(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_s_chg);
#else
s32 comm_s_chg(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_schg2);
#else
s32 comm_schg2(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_rhsja);
#else
s32 comm_rhsja(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_uhsja);
#else
s32 comm_uhsja(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ifcom);
#else
s32 comm_ifcom(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_axjmp);
#else
s32 comm_axjmp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ayjmp);
#else
s32 comm_ayjmp(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", comm_ifs3);
#else
s32 comm_ifs3(WORK *wk, UNK11 *ctc) {
    not_implemented(__func__);
}
#endif

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

void check_cgd_patdat(WORK *wk) {
    union {
        s32 l; // offset 0x0, size 0x4
        struct {
            // total size: 0x4
            s16 l; // offset 0x0, size 0x2
            s16 h; // offset 0x2, size 0x2
        } w;       // offset 0x0, size 0x4
    } st;

    u16 *seAdrs;
    s16 *from_rom2;

    setupCharTableData(wk, 0, 0);

    switch (wk->cgd_type) {
    case 6:
        if (wk->cg_add_xy) {
            from_rom2 = wk->step_xy_table + wk->cg_add_xy;
            st.l = *from_rom2++;
            st.l <<= 8;

            if (wk->rl_flag) {
                wk->xyz[0].cal += st.l;
            } else {
                wk->xyz[0].cal -= st.l;
            }

            st.l = *from_rom2;
            st.l <<= 8;
            wk->xyz[1].cal += st.l;
        }

        if (wk->cg_status & 0x80) {
            wk->pat_status = wk->cg_status & 0x7F;
        }

        /* fallthrough */

    case 4:
        wk->cg_meoshi = wk->cg_hit_ix & 0x1FFF;
        st.w.h = wk->cg_att_ix;
        st.w.l = wk->cg_hit_ix;
        wk->cg_att_ix >>= 6;
        st.l *= 8;
        wk->cg_hit_ix = st.w.h & 0x1FF;

        if (wk->cg_att_ix) {
            set_new_attnum(wk);
        }

        if (wk->cg_effect) {
#if defined(TARGET_PS2)
            effinitjptbl[wk->cg_effect](wk, wk->cg_eftype);
#else
            fatal_error("effinitjptbl is not decompiled.");
#endif
        }

        break;
    }

    wk->cg_jphos = jphos_table[wk->cg_olc_ix & 0xF];
    wk->cg_olc_ix >>= 4;
    wk->cg_flip = wk->cg_se & 3;
    wk->cg_prio = (wk->cg_se & 0xF) >> 2;
    wk->cg_se >>= 4;

    if (wk->cg_se & 0x800) {
        seAdrs = (u16 *)(wk->se_random_table + (wk->se_random_table[wk->cg_se & 0x7FF] / 4));
        wk->cg_se = seAdrs[random_16()];
    }

    if (wk->cg_se) {
        sound_effect_request[wk->cg_se](wk, check_xcopy_filter_se_req(wk));
    }

    if (wk->work_id == 1) {
        if (wk->cg_rival == 0) {
            wk->curr_rca = NULL;
        } else {
            wk->curr_rca = wk->rival_catch_tbl + (wk->cg_rival - 0x14 + wk[1].before);
        }

        wk->cg_olc = *(wk->olc_ix_table + wk->cg_olc_ix);
    }

    if (wk->work_id < 16) {
        wk->cg_ja = *(wk->hit_ix_table + wk->cg_hit_ix);
        set_jugde_area(wk);
    }

    if ((wk->cg_type != 0xFF) && (wk->cg_type & 0x80)) {
        wk->cg_wca_ix = wk->cg_type & 0x7F;
        wk->cg_type = 0;
    }

    if (wk->work_id == 1) {
        if ((WK_AS_PLW->spmv_ng_flag2 & 1) && (wk->cg_cancel & 8) && !(wk->kow & 0xF8)) {
            if (wk->kow & 6) {
                wk->cg_cancel &= 0xF7;
                wk->cg_meoshi = 0;
            } else if (wk->cg_meoshi & 0x110) {
                wk->cg_meoshi &= 0xF99F;
            } else {
                wk->cg_cancel &= 0xF7;
                wk->cg_meoshi = 0;
            }
        }

        if (WK_AS_PLW->spmv_ng_flag2 & 8) {
            if (wk->kow & 0x60) {
                wk->cg_cancel &= 0xBF;
            }
        } else if ((wk->kow & 0x60) && (wk->cg_cancel & 0x40)) {
            wk->meoshi_hit_flag = 1;
        }

        if (!(WK_AS_PLW->spmv_ng_flag2 & 2) && !(wk->kow & 0x60) && (wk->kow & 0xF8) && (wk->cg_cancel & 0x40)) {
            wk->cg_cancel |= 0x60;
        }

        if (!(wk->kow & 0xF8) && (wk->routine_no[1] == 4) && (wk->routine_no[2] < 16)) {
            switch (plpat_rno_filter[wk->routine_no[2]]) {
            case 9:
                if (wk->routine_no[3] != 1) {
                    break;
                }

                /* fallthrough */

            case 1:
                if (!(WK_AS_PLW->spmv_ng_flag2 & 0x01000000)) {
                    wk->cg_cancel |= 1;
                }

                if (!(WK_AS_PLW->spmv_ng_flag2 & 0x02000000)) {
                    wk->cg_cancel |= 2;
                }

                if (!(WK_AS_PLW->spmv_ng_flag2 & 0x100000)) {
                    if (WK_AS_PLW->player_number == 4) {
                        wk->cg_meoshi = chain_hidou_nm_ground_table[wk->kow & 7];
                        wk->cg_cancel |= 8;
                        return;
                    }

                    wk->cg_meoshi = chain_normal_ground_table[wk->kow & 7];
                    wk->cg_cancel |= 8;
                    return;
                }

                break;

            case 2:
                if (!(WK_AS_PLW->spmv_ng_flag2 & 0x200000) && !hikusugi_check(wk)) {
                    if (WK_AS_PLW->player_number == 7) {
                        wk->cg_meoshi = chain_hidou_nm_air_table[wk->kow & 7];
                        wk->cg_cancel |= 8;
                        return;
                    }

                    wk->cg_meoshi = chain_normal_air_table[wk->kow & 7];
                    wk->cg_cancel |= 8;
                }

                break;
            }
        }
    }
}

u16 check_xcopy_filter_se_req(WORK *wk) {
    u16 voif;

    if ((voif = wk->cg_se) < 0x160) {
        return voif;
    }

    if (wk->work_id != 1) {
        if (LO_2_BYTES(WK_AS_PLW->spmv_ng_flag) != 1) {
            return voif;
        }

        if ((u16)HI_2_BYTES(WK_AS_PLW->spmv_ng_flag) > 1) {
            return voif;
        }

        if (plw[HI_2_BYTES(WK_AS_PLW->spmv_ng_flag)].metamorphose == 0) {
            return voif;
        }

        return voif + 0x600;
    }

    if (WK_AS_PLW->metamorphose == 0) {
        return voif;
    }

    return voif + 0x600;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", check_cgd_patdat2);

void set_new_attnum(WORK *wk) {
    s16 aag_sw;
    u32 dspadrs;
    static u16 att_req;

    wk->renew_attack = wk->cg_att_ix;

    if ((att_req = (++att_req & 0x7FFF)) == 0) {
        att_req++;
    }

    aag_sw = 0;

    if (wk->cg_att_ix < 0) {
        wk->cg_att_ix = -wk->cg_att_ix;
        wk->attack_num = att_req;
        wk->att_hit_ok = 1;
        aag_sw = 1;
        wk->meoshi_hit_flag = 0;

        if (wk->work_id == 1) {
            WK_AS_PLW->caution_flag = 1;
            WK_AS_PLW->total_att_hit_ok += 1;
        }

        grade_add_att_renew((WORK_Other *)wk);
    }

    wk->att = *(wk->att_ix_table + wk->cg_att_ix);
    dspadrs = (u32)(wk->att_ix_table + wk->cg_att_ix);
    wk->zu_flag = wk->att.level & 0x80;
    wk->jump_att_flag = wk->att.level & 0x40;
    wk->at_attribute = (wk->att.level >> 4) & 3;
    wk->no_death_attack = wk->att.level & 8;
    wk->att.level &= 7;
    wk->kezuri_pow = kezuri_pow_table[(wk->att.guard >> 6) & 3];
    wk->att.guard &= 0x3F;
    wk->att_zuru = (wk->att.dir >> 4) & 7;
    wk->att.dir &= 0xF;
    wk->add_arts_point = (wk->att.piyo >> 4) & 0xF;
    wk->att.piyo &= 0xF;
    wk->vs_id = (wk->att.ng_type >> 4) & 0xF;
    wk->att.ng_type &= 0xF;
    wk->dir_atthit = cal_attdir(wk);

    if (aag_sw) {
        add_sp_arts_gauge_init((PLW *)wk);
    }

    if ((wk->work_id == 1) && !(WK_AS_PLW->spmv_ng_flag & 0x4000)) {
        setup_metamor_kezuri(wk);
    }
}

void setup_metamor_kezuri(WORK *wk) {
    if (wk->kezuri_pow == 0) {
        wk->kezuri_pow = kezuri_pow_table[4];
    }
}

void set_jugde_area(WORK *wk) {
    wk->h_bod = wk->body_adrs + wk->cg_ja.boix;
    wk->h_cat = wk->catch_adrs + wk->cg_ja.caix;
    wk->h_cau = wk->caught_adrs + wk->cg_ja.cuix;
    wk->h_att = wk->attack_adrs + wk->cg_ja.atix;
    wk->h_hos = wk->hosei_adrs + wk->cg_ja.hoix;
    wk->h_han = wk->hand_adrs + (wk->cg_ja.bhix + wk->cg_ja.haix);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", get_char_data_zanzou);

const s16 jphos_table[16] = { 0x0000, 0xFFF0, 0xFFF4, 0xFFF8, 0xFFFC, 0x0004, 0x0008, 0x000C,
                              0x0010, 0x0014, 0x0018, 0x001C, 0x0020, 0x0024, 0x0028, 0x002C };

const s16 kezuri_pow_table[5] = { 0, 4, 8, 16, 24 };

s32 comm_dummy(WORK *, UNK11 *);
s32 comm_roa(WORK *, UNK11 *);
s32 comm_end(WORK *, UNK11 *);
s32 comm_jmp(WORK *, UNK11 *);
s32 comm_jpss(WORK *, UNK11 *);
s32 comm_jsr(WORK *, UNK11 *);
s32 comm_ret(WORK *, UNK11 *);
s32 comm_sps(WORK *, UNK11 *);
s32 comm_setr(WORK *, UNK11 *);
s32 comm_addr(WORK *, UNK11 *);
s32 comm_if_l(WORK *, UNK11 *);
s32 comm_djmp(WORK *, UNK11 *);
s32 comm_for(WORK *, UNK11 *);
s32 comm_nex(WORK *, UNK11 *);
s32 comm_for2(WORK *, UNK11 *);
s32 comm_nex2(WORK *, UNK11 *);
s32 comm_rja(WORK *, UNK11 *);
s32 comm_uja(WORK *, UNK11 *);
s32 comm_rja2(WORK *, UNK11 *);
s32 comm_uja2(WORK *, UNK11 *);
s32 comm_rja3(WORK *, UNK11 *);
s32 comm_uja3(WORK *, UNK11 *);
s32 comm_rja4(WORK *, UNK11 *);
s32 comm_uja4(WORK *, UNK11 *);
s32 comm_rja5(WORK *, UNK11 *);
s32 comm_uja5(WORK *, UNK11 *);
s32 comm_rja6(WORK *, UNK11 *);
s32 comm_uja6(WORK *, UNK11 *);
s32 comm_rja7(WORK *, UNK11 *);
s32 comm_uja7(WORK *, UNK11 *);
s32 comm_rmja(WORK *, UNK11 *);
s32 comm_umja(WORK *, UNK11 *);
s32 comm_mdat(WORK *, UNK11 *);
s32 comm_ydat(WORK *, UNK11 *);
s32 comm_mpos(WORK *, UNK11 *);
s32 comm_cafr(WORK *, UNK11 *);
s32 comm_care(WORK *, UNK11 *);
s32 comm_psxy(WORK *, UNK11 *);
s32 comm_ps_x(WORK *, UNK11 *);
s32 comm_ps_y(WORK *, UNK11 *);
s32 comm_paxy(WORK *, UNK11 *);
s32 comm_pa_x(WORK *, UNK11 *);
s32 comm_pa_y(WORK *, UNK11 *);
s32 comm_exec(WORK *, UNK11 *);
s32 comm_rngc(WORK *, UNK11 *);
s32 comm_mxyt(WORK *, UNK11 *);
s32 comm_pjmp(WORK *, UNK11 *);
s32 comm_hjmp(WORK *, UNK11 *);
s32 comm_hclr(WORK *, UNK11 *);
s32 comm_ixfw(WORK *, UNK11 *);
s32 comm_ixbw(WORK *, UNK11 *);
s32 comm_quax(WORK *, UNK11 *);
s32 comm_quay(WORK *, UNK11 *);
s32 comm_if_s(WORK *, UNK11 *);
s32 comm_rapp(WORK *, UNK11 *);
s32 comm_rapk(WORK *, UNK11 *);
s32 comm_gets(WORK *, UNK11 *);
s32 comm_s123(WORK *, UNK11 *);
s32 comm_s456(WORK *, UNK11 *);
s32 comm_a123(WORK *, UNK11 *);
s32 comm_a456(WORK *, UNK11 *);
s32 comm_stop(WORK *, UNK11 *);
s32 comm_smhf(WORK *, UNK11 *);
s32 comm_ngme(WORK *, UNK11 *);
s32 comm_ngem(WORK *, UNK11 *);
s32 comm_iflb(WORK *, UNK11 *);
s32 comm_asxy(WORK *, UNK11 *);
s32 comm_schx(WORK *, UNK11 *);
s32 comm_schy(WORK *, UNK11 *);
s32 comm_back(WORK *, UNK11 *);
s32 comm_mvix(WORK *, UNK11 *);
s32 comm_sajp(WORK *, UNK11 *);
s32 comm_ccch(WORK *, UNK11 *);
s32 comm_wset(WORK *, UNK11 *);
s32 comm_wswk(WORK *, UNK11 *);
s32 comm_wadd(WORK *, UNK11 *);
s32 comm_wceq(WORK *, UNK11 *);
s32 comm_wcne(WORK *, UNK11 *);
s32 comm_wcgt(WORK *, UNK11 *);
s32 comm_wclt(WORK *, UNK11 *);
s32 comm_wadd2(WORK *, UNK11 *);
s32 comm_wceq2(WORK *, UNK11 *);
s32 comm_wcne2(WORK *, UNK11 *);
s32 comm_wcgt2(WORK *, UNK11 *);
s32 comm_wclt2(WORK *, UNK11 *);
s32 comm_rapp2(WORK *, UNK11 *);
s32 comm_rapk2(WORK *, UNK11 *);
s32 comm_iflg(WORK *, UNK11 *);
s32 comm_mpcy(WORK *, UNK11 *);
s32 comm_epcy(WORK *, UNK11 *);
s32 comm_imgs(WORK *, UNK11 *);
s32 comm_imgc(WORK *, UNK11 *);
s32 comm_rvxy(WORK *, UNK11 *);
s32 comm_rv_x(WORK *, UNK11 *);
s32 comm_rv_y(WORK *, UNK11 *);
s32 comm_ccfl(WORK *, UNK11 *);
s32 comm_myhp(WORK *, UNK11 *);
s32 comm_emhp(WORK *, UNK11 *);
s32 comm_exbgs(WORK *, UNK11 *);
s32 comm_exbgc(WORK *, UNK11 *);
s32 comm_atmf(WORK *, UNK11 *);
s32 comm_chkwf(WORK *, UNK11 *);
s32 comm_retmj(WORK *, UNK11 *);
s32 comm_sstx(WORK *, UNK11 *);
s32 comm_ssty(WORK *, UNK11 *);
s32 comm_ngda(WORK *, UNK11 *);
s32 comm_flip(WORK *, UNK11 *);
s32 comm_kage(WORK *, UNK11 *);
s32 comm_dspf(WORK *, UNK11 *);
s32 comm_ifrlf(WORK *, UNK11 *);
s32 comm_srlf(WORK *, UNK11 *);
s32 comm_bgrlf(WORK *, UNK11 *);
s32 comm_scmd(WORK *, UNK11 *);
s32 comm_rljmp(WORK *, UNK11 *);
s32 comm_ifs2(WORK *, UNK11 *);
s32 comm_abbak(WORK *, UNK11 *);
s32 comm_sse(WORK *, UNK11 *);
s32 comm_s_chg(WORK *, UNK11 *);
s32 comm_schg2(WORK *, UNK11 *);
s32 comm_rhsja(WORK *, UNK11 *);
s32 comm_uhsja(WORK *, UNK11 *);
s32 comm_ifcom(WORK *, UNK11 *);
s32 comm_axjmp(WORK *, UNK11 *);
s32 comm_ayjmp(WORK *, UNK11 *);
s32 comm_ifs3(WORK *, UNK11 *);

s32 (*const decode_chcmd[125])() = {
    comm_dummy, comm_roa,   comm_end,   comm_jmp,   comm_jpss,  comm_jsr,   comm_ret,   comm_sps,   comm_setr,
    comm_addr,  comm_if_l,  comm_djmp,  comm_for,   comm_nex,   comm_for2,  comm_nex2,  comm_rja,   comm_uja,
    comm_rja2,  comm_uja2,  comm_rja3,  comm_uja3,  comm_rja4,  comm_uja4,  comm_rja5,  comm_uja5,  comm_rja6,
    comm_uja6,  comm_rja7,  comm_uja7,  comm_rmja,  comm_umja,  comm_mdat,  comm_ydat,  comm_mpos,  comm_cafr,
    comm_care,  comm_psxy,  comm_ps_x,  comm_ps_y,  comm_paxy,  comm_pa_x,  comm_pa_y,  comm_exec,  comm_rngc,
    comm_mxyt,  comm_pjmp,  comm_hjmp,  comm_hclr,  comm_ixfw,  comm_ixbw,  comm_quax,  comm_quay,  comm_if_s,
    comm_rapp,  comm_rapk,  comm_gets,  comm_s123,  comm_s456,  comm_a123,  comm_a456,  comm_stop,  comm_smhf,
    comm_ngme,  comm_ngem,  comm_iflb,  comm_asxy,  comm_schx,  comm_schy,  comm_back,  comm_mvix,  comm_sajp,
    comm_ccch,  comm_wset,  comm_wswk,  comm_wadd,  comm_wceq,  comm_wcne,  comm_wcgt,  comm_wclt,  comm_wadd2,
    comm_wceq2, comm_wcne2, comm_wcgt2, comm_wclt2, comm_rapp2, comm_rapk2, comm_iflg,  comm_mpcy,  comm_epcy,
    comm_imgs,  comm_imgc,  comm_rvxy,  comm_rv_x,  comm_rv_y,  comm_ccfl,  comm_myhp,  comm_emhp,  comm_exbgs,
    comm_exbgc, comm_atmf,  comm_chkwf, comm_retmj, comm_sstx,  comm_ssty,  comm_ngda,  comm_flip,  comm_kage,
    comm_dspf,  comm_ifrlf, comm_srlf,  comm_bgrlf, comm_scmd,  comm_rljmp, comm_ifs2,  comm_abbak, comm_sse,
    comm_s_chg, comm_schg2, comm_rhsja, comm_uhsja, comm_ifcom, comm_axjmp, comm_ayjmp, comm_ifs3
};

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARSET", decode_if_lever);

const u16 acatkoa_table[65] = { 4,   4,   8,   8,   8,   8,   8,   8,   16,  16,  16,  16,  16,  16,  16,  16,  32,
                                32,  32,  32,  32,  32,  32,  32,  64,  64,  64,  64,  64,  64,  64,  64,  128, 128,
                                128, 128, 128, 128, 128, 128, 256, 256, 256, 256, 256, 256, 256, 256, 128, 128, 128,
                                128, 128, 128, 128, 128, 256, 256, 256, 256, 256, 256, 256, 256, 2048 };
