#include "common.h"
#include <cri/private/libadxe/structs.h>

#include <cri/private/libadxe/ps2_rna.h>
#include <cri/private/libadxe/adx_crs.h>
#include <cri/private/libadxe/adx_sjd.h>
#include <cri/private/libadxe/adx_amp.h>
#include <cri/private/libadxe/adx_errs.h>
#include <cri/private/libadxe/adx_rnap.h>
#include <cri/private/libadxe/adx_sjd.h>
#include <cri/private/libadxe/adx_stmc.h>
#include <cri/private/libadxe/adx_tlk.h>
#include <cri/private/libadxe/lsc.h>

#include <cri/cri_adxt.h>
#include <string.h>

// Have to declare this one locally, because other files expect it to be non-volatile
extern volatile Sint32 adxt_vsync_cnt;

// data
Sint32 adxt_dbg_nch = 0;
Sint32 adxt_dbg_ndt = 0;
Sint32 adxt_dbg_rna_ndata = 0;

// fwd declare
void adxt_trap_entry(ADXT adxt);

void adxt_trap_entry_lps(ADXT adxt) {
    s32 lp_epos;
    s32 diff;
    s32 lp_spos;
    s32 lp_soff;
    ADXSJD sjd;

    sjd = adxt->sjd;
    lp_spos = ADXSJD_GetLpStartPos(sjd);
    lp_soff = ADXSJD_GetLpStartOfst(sjd);
    lp_epos = ADXSJD_GetLpEndPos(sjd);
    ADXSJD_TakeSnapshot(sjd);
    diff = lp_epos - lp_spos;
    ADXSJD_SetTrapCnt(sjd, 0);
    adxt->trpnsmpl = diff;
    ADXSJD_SetTrapNumSmpl(sjd, diff);
    ADXSJD_SetTrapDtLen(sjd, lp_soff);
    ADXSJD_SetDecPos(sjd, lp_spos);
    ADXSJD_EntryTrapFunc(sjd, adxt_trap_entry, adxt);
}

void adxt_trap_entry(ADXT adxt) {
    s32 temp_a1;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    ADXSJD sjd;
    SJ sj;
    SJCK sp;

    sjd = adxt->sjd;
    sj = adxt->sji;

    temp_s3 = ADXSJD_GetLpStartPos(sjd);
    temp_s5 = ADXSJD_GetLpStartOfst(sjd);
    temp_s4 = ADXSJD_GetLpEndPos(sjd);

    if ((adxt->stm == NULL) && (adxt->lpflg == 0)) {
        ADXSJD_SetTrapNumSmpl(adxt->sjd, -1);
        return;
    }

    SJ_GetChunk(sj, 1, adxt->lp_skiplen, &sp);
    if (sp.len < adxt->lp_skiplen) {
        ADXERR_CallErrFunc1("E8101201 adxt_trap_entry: not enough data");
    }

    SJ_PutChunk(sj, 0, &sp);
    ADXSJD_SetTrapCnt(sjd, 0);
    temp_a1 = temp_s4 - temp_s3;
    adxt->trpnsmpl = temp_a1;
    ADXSJD_SetTrapNumSmpl(sjd, temp_a1);
    ADXSJD_SetTrapDtLen(sjd, temp_s5);
    ADXSJD_SetDecPos(sjd, temp_s3);

    if (adxt->pmode == 2) {
        SJ_Reset(sj);
        SJ_GetChunk(sj, 1, temp_s5, &sp);
        SJ_PutChunk(sj, 0, &sp);
    }

    ADXSJD_RestoreSnapshot(sjd);
    adxt->lpcnt += 1;
}

void adxt_eos_entry(ADXT adxt) {
    s32 temp_a2;
    ADXSJD sjd;
    ADXSTM stm;

    stm = adxt->stm;
    sjd = adxt->sjd;
    
    if (stm == NULL) {
        return;
    } 
    if (sjd == NULL) {
        return;
    }

    temp_a2 = ADXSJD_GetLpStartOfst(sjd);
    if (adxt->lpflg == 0) {
        ADXSJD_SetTrapNumSmpl(adxt->sjd, -1);
        ADXSTM_SetEos(adxt->stm, 0x7FFFFFFF);
    } else {
        ADXSTM_Seek(stm, temp_a2 / 0x800);
    }
}

void adxt_set_outpan(ADXT adxt) {
    Sint32 i;
    Sint32 num_chan;
    Sint32 def_pan[2];

    num_chan = ADXSJD_GetNumChan(adxt->sjd);

    for (i = 0; i < 2; i++) {
        def_pan[i] = ADXSJD_GetDefPan(adxt->sjd, i);
    }

    if (num_chan == 1) {
        if ((adxt->outpan[0] == -0x80) && (def_pan[0] == -0x80)) {
            ADXRNA_SetOutPan(adxt->rna, 0, 0);
        } else if ((adxt->outpan[0] != -0x80) && (def_pan[0] == -0x80)){
            ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0]);
        } else if ((adxt->outpan[0] == -0x80) && (def_pan[0] != -0x80)) {
            ADXRNA_SetOutPan(adxt->rna, 0, def_pan[0]);
        } else { 
            ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0] + def_pan[0]);
        }
    } else {
        if ((adxt->outpan[0] == -0x80) && (def_pan[0] == -0x80)) {
            ADXRNA_SetOutPan(adxt->rna, 0, -0xF);
        } else if ((adxt->outpan[0] != -0x80) && (def_pan[0] == -0x80)){
            ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0]);
        } else if ((adxt->outpan[0] == -0x80) && (def_pan[0] != -0x80)) {
            ADXRNA_SetOutPan(adxt->rna, 0, def_pan[0]);
        } else { 
            ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0] + def_pan[0]);
        }

        if ((adxt->outpan[1] == -0x80) && (def_pan[1] == -0x80)) {
            ADXRNA_SetOutPan(adxt->rna, 1, 0xF);
        } else if ((adxt->outpan[1] != -0x80) && (def_pan[1] == -0x80)){
            ADXRNA_SetOutPan(adxt->rna, 1, adxt->outpan[1]);
        } else if ((adxt->outpan[1] == -0x80) && (def_pan[1] != -0x80)) {
            ADXRNA_SetOutPan(adxt->rna, 1, def_pan[1]);
        } else { 
            ADXRNA_SetOutPan(adxt->rna, 1, adxt->outpan[1] + def_pan[1]);
        }
    }
}

void adxt_nlp_trap_entry(ADXT adxt) {
    SJCK sp;
    SJCK sp10;
    SJCK sp20;
    SJCK sp30;
    s16 sp40; int x, xx;
    s16 sp42, y;
    s32 temp_v0;
    s32 var_v1;
    ADXSJD sjd;
    SJ sj;

    sjd = adxt->sjd;
    sj = adxt->sji;
    if (adxt->lnkflg == 0) {
        return;
    }
    
    sp42 = 0;
    SJ_GetChunk(sj, 1, 0x7FFFFFFF, &sp);
    SJ_GetChunk(sj, 1, 0x7FFFFFFF, &sp20);
    if (ADX_DecodeFooter(sp.data, sp.len, &sp40) != 0) {
        ADXT_SetLnkSw(adxt, 0);
        SJ_UngetChunk(sj, 1, &sp20);
        SJ_UngetChunk(sj, 1, &sp);
        return;
    }

    xx = sp40;
    temp_v0 = ADX_ScanInfoCode(sp.data + xx, sp.len - xx, &sp40);
    if (temp_v0 == 0) {
        var_v1 = -1;
    } else {
        var_v1 = ADX_ScanInfoCode(sp20.data, sp20.len, &sp42);
    }

    x = xx + sp40;
    y = sp42;
    if ((temp_v0 != 0) && (var_v1 != 0)) {
        SJ_UngetChunk(sj, 1, &sp20);
        SJ_UngetChunk(sj, 1, &sp);
        ADXT_SetLnkSw(adxt, 0);
        return;
    } else {
        if (temp_v0 == 0) {
            SJ_UngetChunk(sj, 1, &sp20);
            SJ_SplitChunk(&sp, x, &sp, &sp10);
            SJ_PutChunk(sj, 0, &sp);
            SJ_UngetChunk(sj, 1, &sp10.data);
        } else {
            SJ_PutChunk(sj, 0, &sp);
            SJ_SplitChunk(&sp20, y, &sp20, &sp30);
            SJ_PutChunk(sj, 0, &sp20);
            SJ_UngetChunk(sj, 1, &sp30.data);
        }
    }
    
    adxt->decofst += ADXSJD_GetDecNumSmpl(sjd);
    ADXSJD_Stop(sjd);
    ADXSJD_Start(sjd);
    ADXSJD_ExecHndl(sjd);
    if (ADXSJD_GetStat(sjd) != 2) {
        ADXT_SetLnkSw(adxt, 0);
    } else {
        ADXSJD_SetMaxDecSmpl(sjd, adxt->maxdecsmpl);
        ADXSJD_SetTrapNumSmpl(sjd, ADXSJD_GetTotalNumSmpl(sjd));
        ADXSJD_SetTrapDtLen(sjd, 0);
        ADXSJD_SetTrapCnt(sjd, 0);
    }
}

void adxt_stat_decinfo(ADXT adxt) {
    Sint32 transpose = 0;
    Sint32 detune = 0;
    ADXSJD sjd = adxt->sjd;
    Sint32 div = 2048;
    Char8 num_chan_str[32];
    Sint32 num_smpl;
    Sint32 sfreq;
    Sint32 num_chan;
    Sint32 num_loop;
    Sint32 blk_smpl;
    Sint32 max_dec_smpl;
    Sint32 lp_end_ofst;

    if ((adxt->pmode < 2U) && (adxt->unkAC == 1)) {
        if (ADXSTM_GetStat(adxt->stm) == 2) {
            return;
        }

        if (adxt->sjf != NULL) {
            SJ_Reset(adxt->sjf);
        }

        adxt_start_stm(adxt, adxt->padB4, adxt->padB8, adxt->padBC, adxt->padC0);
        adxt->unkAC = 0;
    }

    if (ADXSJD_GetStat(sjd) != 2) {
        return;
    }

    num_chan = ADXSJD_GetNumChan(sjd);

    if (adxt->maxnch < num_chan) {
        ADXERR_ItoA2(num_chan, adxt->maxnch, num_chan_str, 16);
        ADXERR_CallErrFunc2("E9081001 adxt_stat_decinfo: can't play this number of channels", num_chan_str);
        ADXT_Stop(adxt);
        return;
    }

    sfreq = ADXSJD_GetSfreq(sjd);
    num_loop = ADXSJD_GetNumLoop(sjd);

    if (num_loop > 0) {
        adxt->maxdecsmpl = (sfreq / adxt->svrfreq) * 3;
    } else {
        adxt->maxdecsmpl = ((sfreq / adxt->svrfreq) * 3) / 2;
    }

    blk_smpl = ADXSJD_GetBlkSmpl(sjd) * 2;
    max_dec_smpl = ((adxt->maxdecsmpl + blk_smpl) / blk_smpl) * blk_smpl;
    adxt->maxdecsmpl = max_dec_smpl;
    ADXSJD_SetMaxDecSmpl(sjd, max_dec_smpl);

    if (num_loop > 0) {
        if (adxt->pmode == 2) {
            adxt->lp_skiplen = 0;
        } else {
            lp_end_ofst = ADXSJD_GetLpEndOfst(sjd);
            adxt->lp_skiplen = div - (lp_end_ofst % div);
            lp_end_ofst += 0x7FF;
            adxt->lp_skiplen %= div;
            adxt->lesct = lp_end_ofst / div;
            ADXSTM_SetEos(adxt->stm, adxt->lesct);
            ADXSTM_EntryEosFunc(adxt->stm, adxt_eos_entry, adxt);
        }

        ADXSJD_GetLpEndPos(sjd);
        adxt->trpnsmpl = ADXSJD_GetLpStartPos(sjd);
        ADXSJD_SetTrapNumSmpl(sjd, adxt->trpnsmpl);
        ADXSJD_SetTrapDtLen(sjd, 0);
        ADXSJD_SetTrapCnt(sjd, 0);
        ADXSJD_EntryTrapFunc(sjd, adxt_trap_entry_lps, adxt);
    } else {
        if (adxt->stm != NULL) {
            ADXSTM_SetEos(adxt->stm, SJCK_LEN_MAX);
        }

        ADXSJD_SetTrapNumSmpl(sjd, ADXSJD_GetTotalNumSmpl(sjd));
        ADXSJD_SetTrapDtLen(sjd, 0);
        ADXSJD_SetTrapCnt(sjd, 0);
        ADXSJD_EntryTrapFunc(sjd, adxt_nlp_trap_entry, adxt);
    }

    sfreq = ADXSJD_GetSfreq(sjd);
    num_chan = ADXSJD_GetNumChan(sjd);
    num_smpl = ADXSJD_GetTotalNumSmpl(sjd);
    ADXRNA_SetBitPerSmpl(adxt->rna, ADXSJD_GetOutBps(sjd));
    ADXRNA_SetSfreq(adxt->rna, sfreq);
    ADXRNA_SetNumChan(adxt->rna, num_chan);
    ADXRNA_SetTotalNumSmpl(adxt->rna, num_smpl);
    ADXRNA_SetOutVol(adxt->rna, adxt->outvol + ADXSJD_GetDefOutVol(adxt->sjd));
    ADXT_GetTranspose(adxt, &transpose, &detune);

    if ((transpose != 0) || (detune != 0)) {
        ADXT_SetTranspose(adxt, transpose, detune);
    }

    adxt_set_outpan(adxt);

    if (adxt->amp != NULL) {
        ADXAMP_SetSfreq(adxt->amp, sfreq);
    }

    if (ADXSJD_GetFormat(sjd) == 2) {
        ADXRNA_SetStmHdInfo(adxt->rna, ADXSJD_GetSpsdInfo(sjd));
    }

    ADXRNA_SetTransSw(adxt->rna, 1);
    adxt->stat = ADXT_STAT_PREP;
}

void adxt_stat_prep(ADXT adxt) {
    ADXRNA rna;
    ADXSJD sjd;
    Sint32 num_data;
    Sint32 num_room;
    Sint32 num_chan;
    Sint32 i;
    Sint32 size;
    SJCK chunk_info;

    rna = adxt->rna;
    sjd = adxt->sjd;

    num_data = ADXRNA_GetNumData(rna);
    num_room = ADXRNA_GetNumRoom(rna);

    if ((num_data >= (adxt->maxdecsmpl << 1)) || (ADXSJD_GetBlkSmpl(sjd) >= num_room) ||
        (ADXSJD_GetStat(adxt->sjd) == 3)) {
        if (adxt->pstwait_flag == 0) {
            if (adxt->pause_flag == 0) {
                ADXRNA_SetPlaySw(rna, 1);
                adxt->tvofst = 0;
                adxt->svcnt = adxt_vsync_cnt;
            }

            adxt->stat = ADXT_STAT_PLAYING;
        }

        adxt->pstready_flag = 1;
    }

    if (ADXSJD_GetStat(adxt->sjd) != 3) {
        return;
    }

    num_chan = ADXT_GetNumChan(adxt);
    size = (adxt->maxdecsmpl * num_chan) << 1;

    for (i = 0; i < num_chan; i++) {
        SJ sj_obj = adxt->sjo[i];
        SJ_GetChunk(sj_obj, 0, size, &chunk_info);
        memset(chunk_info.data, 0, chunk_info.len);
        SJ_PutChunk(sj_obj, 1, &chunk_info);
    }
}

void adxt_stat_playing(ADXT adxt) {
    Sint32 i;
    Sint32 num_chan;

    if (ADXSJD_GetStat(adxt->sjd) != 3) {
        return;
    }

    num_chan = ADXSJD_GetNumChan(adxt->sjd);
    adxt_dbg_nch = num_chan;

    for (i = 0; i < num_chan; i++) {
        SJ sj_obj = adxt->sjo[i];
        adxt_dbg_ndt = SJ_GetNumData(sj_obj, 1);

        if (adxt_dbg_ndt >= 64) {
            break;
        }
    }

    if (i == num_chan) {
        adxt->flush_nsmpl = 0;
        adxt->stat = ADXT_STAT_DECEND;
    }
}

void adxt_stat_decend(ADXT adxt) {
    SJCK sp0[2];
    SJCK sp10[2];
    s32 temp_s7;
    s32 var_s1_2;
    s32 var_s4;
    s32 temp_v0_2;
    s32 var_s5;
    u32 x;

    var_s4 = 0;
    adxt_dbg_rna_ndata = ADXRNA_GetNumData(adxt->rna);
    temp_s7 = ADXSJD_GetNumChan(adxt->sjd);
    ADXCRS_Lock();
    var_s5 = adxt->maxdecsmpl;
    for (var_s4 = 0; var_s4 < temp_s7; var_s4++) {
        SJ_GetChunk(adxt->sjo[var_s4], 0, var_s5 * 2, &sp0[var_s4]);
        x = sp0[var_s4].len;
        var_s5 = (s32) (((x >> 1) < var_s5) ? (x >> 1) : var_s5);
    }
    
    for (var_s4 = 0; var_s4 < temp_s7; var_s4++) {
        SJ_SplitChunk(&sp0[var_s4], var_s5 * 2, &sp0[var_s4], &sp10[var_s4]);
        memset(sp0[var_s4].data, 0, sp0[var_s4].len);
        SJ_PutChunk(adxt->sjo[var_s4], 1, &sp0[var_s4]);
        SJ_UngetChunk(adxt->sjo[var_s4], 0, &sp10[var_s4]);
    }
    
    var_s1_2 = 0;
    adxt->flush_nsmpl += var_s5;
    ADXCRS_Unlock();
    for (var_s4 = 0; var_s4 < temp_s7; var_s4++) {
        temp_v0_2 = (u32)SJ_GetNumData(adxt->sjo[var_s4], 1) >> 1;
        var_s1_2 = ((temp_v0_2 >= var_s1_2) ? temp_v0_2 : var_s1_2);
    }
    
    if (((var_s1_2 + ADXRNA_GetNumData(adxt->rna)) - adxt->flush_nsmpl) <= 0) {
        ADXRNA_SetTransSw(adxt->rna, 0);
        ADXRNA_SetPlaySw(adxt->rna, 0);
        PS2RNA_SetDiscardSw(adxt->rna, 1);
        adxt->stat = 5;
    }
}

void adxt_stat_playend(ADXT adxt) {
    // Do nothing
}

void adxt_RcvrReplay(ADXT adxt) {
    s32 var_s2;
    ADXSTM stm;

    ADXCRS_Lock();
    ADXRNA_SetTransSw(adxt->rna, 0);
    ADXRNA_SetPlaySw(adxt->rna, 0);
    ADXSJD_Stop(adxt->sjd);
    ADXCRS_Unlock();
    
    stm = adxt->stm;
    if (stm != NULL) {
        ADXSTM_Stop(stm);
        SJ_Reset(adxt->sji);
    }

    ADXCRS_Lock();
    for (var_s2 = 0; var_s2 < adxt->maxnch; var_s2++) {
        SJ_Reset(adxt->sjo[var_s2]);
    }
    
    stm = adxt->stm;
    if (stm != NULL) {
        ADXSTM_Seek(stm, 0);
        ADXSTM_Start(adxt->stm);
    }
    adxt_start_sj(adxt, adxt->sji);
    ADXCRS_Unlock();
}

void ADXT_ExecErrChk(ADXT adxt) {
    s32 temp_v0;
    s32 var_v0_2;
    s8 temp_s1;

    temp_s1 = adxt->stat;
    if ((temp_s1 == ADXT_STAT_PLAYING) && (adxt->pause_flag == 0) && (ADXSJD_GetStat(adxt->sjd) != 3)) {
        temp_v0 = ADXSJD_GetDecNumSmpl(adxt->sjd);
        if (adxt->edecpos == temp_v0) {
            if ((adxt->svrfreq * 5) < ++adxt->edeccnt) {
                adxt->ercode = -2;
            }
        } else {
            adxt->edeccnt = 0;
        }
        
        adxt->edecpos = temp_v0;
        
        if (adxt->ercode != 0) {
            if (adxt->autorcvr == 1 || adxt->autorcvr == 2) {
                ADXT_Stop(adxt);
            }
            
            if (adxt->autorcvr != 0) {
                adxt->ercode = 0;
                adxt->edeccnt = 0;
            }
        }
    } else {
        adxt->edeccnt = 0;
    }
    
    if ((temp_s1 == ADXT_STAT_DECINFO || temp_s1 == ADXT_STAT_PREP || temp_s1 == ADXT_STAT_PLAYING) && (adxt->pause_flag == 0) && (ADXSJD_GetStat(adxt->sjd) != 3)) {
        var_v0_2 = (adxt->sji == NULL) ? 0 : SJ_GetNumData(adxt->sji, 1);
        
        if (var_v0_2 < 0x40) {
            adxt->eshrtcnt++;
            
            if (temp_s1 == 3) {
                if (adxt->svrfreq * 5 < adxt->eshrtcnt) {
                    adxt->ercode = -1;
                }
            } else {
                if (adxt->svrfreq * 20 < adxt->eshrtcnt) {
                    adxt->ercode = -1;
                }
            }
            
            
            if (adxt->ercode != 0) {
                if (adxt->autorcvr == 1) {
                    ADXT_Stop(adxt);
                } else if (adxt->autorcvr == 2) {
                    adxt_RcvrReplay(adxt);
                }
                
                if (adxt->autorcvr != 0) {
                    adxt->ercode = 0;
                    adxt->eshrtcnt = 0;
                }
            }
        } else {
            adxt->eshrtcnt = 0;
        }
    } else {
        adxt->eshrtcnt = 0;
    }
    
    if ((adxt->stm != NULL) && (ADXSTM_GetStat(adxt->stm) == 4)) {
        if (adxt->autorcvr == 1) {
            ADXT_Stop(adxt);
        } else if (adxt->autorcvr == 2) {
            adxt_RcvrReplay(adxt);
        }
        
        if (adxt->autorcvr != 0) {
            adxt->ercode = 0;
            adxt->eshrtcnt = 0;
        }
    }
}

void ADXT_ExecRdErrChk(ADXT adxt) {
    if ((adxt->stm != NULL) && (ADXSTM_GetStat(adxt->stm) == 4)) {
        adxt->ercode = -1;
        adxt->stat = ADXT_STAT_ERROR;
    }

    if ((adxt->lsc != NULL) && (LSC_GetStat(adxt->lsc) == 3)) {
        adxt->ercode = -1;
        adxt->stat = ADXT_STAT_ERROR;
    }
}

void ADXT_ExecRdCompChk(ADXT adxt) {
    Sint8 pmode;

    if ((adxt->stm == NULL) || (ADXT_GetStat(adxt) == 0)) {
        return;
    }

    pmode = adxt->pmode;

    switch (pmode) {
    case 0:
    case 1:
        if (ADXSTM_GetStat(adxt->stm) == 3) {
            ADXSJD_TermSupply(adxt->sjd);
        }

        break;

    case 2:
        ADXSJD_TermSupply(adxt->sjd);
        break;

    case 3:
    case 4:
    default:
        // Do nothing
        break;
    }
}

void ADXT_ExecHndl(ADXT adxt) {
    Sint8 stat;

    if (adxt == NULL) {
        ADXERR_CallErrFunc1("E02080842 ADXT_ExecHndl: parameter error");
        return;
    }

    stat = adxt->stat;

    if (stat == 3) {
        adxt_stat_playing(adxt);
    } else if (stat == 1) {
        adxt_stat_decinfo(adxt);
    } else if (stat == 2) {
        adxt_stat_prep(adxt);
    } else if (stat == 4) {
        adxt_stat_decend(adxt);
    } else if (stat == 5) {
        adxt_stat_playend(adxt);
    }

    ADXT_ExecRdCompChk(adxt);
    ADXT_ExecRdErrChk(adxt);
}

Sint32 ADXT_GetStatRead(ADXT adxt) {
    LSC lsc0;
    LSC lsc1;
    ADXSTM stm;

    if (adxt == NULL) {
        return 0;
    }
    
    stm = adxt->stm;
    if (stm == NULL) {
        lsc0 = adxt->lsc;
        if (lsc0 == NULL) {
            return 0;
        }
        
        lsc1 = lsc0->stm_hndl;
        if (lsc1 != NULL) {
            return ADXSTM_GetReadFlg(lsc1);
        }
        
        return 0;
    }
    return ADXSTM_GetReadFlg(stm);
}
