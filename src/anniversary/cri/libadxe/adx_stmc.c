#include "common.h"
#include <cri/private/libadxe/adx_stmc.h>

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXT_SetupRtimeNumStm);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXT_SetupNrmlNumStm);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_Init);

void ADXSTM_Reset() {}

void ADXSTM_Finish() {}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTMF_SetupHandleMember);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTMF_CreateCvfsRt);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTMF_CreateCvfs);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_Create);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_Destroy);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_BindFileNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_BindFile);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_ReleaseFileNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_ReleaseFile);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_IsOpenedFile);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_Seek);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_Tell);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", adxstm_start_sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_Start);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_Start2);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_StopNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_Stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_EntryEosFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetEos);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", adxstm_sj_internal_error);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", adxstmf_stat_exec);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", D_0055B420);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTMF_ExecHndl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_ExecServer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetCurOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetBufSize);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetBufSize);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetReqRdSize);

void ADXSTM_EntryErrFunc() {}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetFileLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetFileSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetPause);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetPause);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetCvdfsStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetFad);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetFsizeSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetFsizeByte);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetRdSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXT_SetNumRetry);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetReadFlg);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_OpenCvfs);
