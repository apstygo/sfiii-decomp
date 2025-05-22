#include "common.h"
#include <cri/private/libadxe/lsc.h>

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", lsc_Alloc);

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055D918);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055D948);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_Create);
#else
ADXLSC LSC_Create(SJ) {
    not_implemented(__func__);
}
#endif

// Used all over the place
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055D978);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_Destroy);
#else
void LSC_Destroy(ADXLSC) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_SetStmHndl);
#else
void LSC_SetStmHndl(void *, ADXSTM) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_EntryFname);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055D9A0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_EntryFileRange);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_ResetEntry);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_Start);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_Stop);
#else
void LSC_Stop(ADXLSC) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_Pause);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_ExecServer);
#else
void LSC_ExecServer() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetNumStm);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055D9C8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetStmId);

// Also used in LSC_GetStmStat and LSC_GetStmRdSct
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055D9E8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetStmFname);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetStmStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetStmRdSct);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055DA10);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_SetFlowLimit);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetFlowLimit);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_EntryChgStatFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_CallStatFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_SetLpFlg);
