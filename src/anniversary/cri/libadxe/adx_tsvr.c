#include "common.h"

#include <cri/cri_adxt.h>

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", adxt_trap_entry_lps);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", D_0055BCD0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", adxt_trap_entry);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", adxt_eos_entry);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", adxt_set_outpan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", adxt_nlp_trap_entry);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", D_0055BD00);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", adxt_stat_decinfo);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", adxt_stat_prep);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", adxt_stat_playing);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", adxt_stat_decend);

void adxt_stat_playend() {
    // Do nothing
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", adxt_RcvrReplay);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", ADXT_ExecErrChk);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", ADXT_ExecRdErrChk);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", ADXT_ExecRdCompChk);

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", D_0055BD58);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", ADXT_ExecHndl);
#else
void ADXT_ExecHndl(ADXT adxt) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tsvr", ADXT_GetStatRead);
