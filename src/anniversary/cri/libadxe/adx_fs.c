#include "common.h"
#include <cri/private/libadxe/adx_fs.h>

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_CALC_BYTE2SCT);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_SetCmdHstry);

void adxf_wait_1ms() {
    s32 i;

    for (i = 0; i < 50000; i++);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_ChkPrmPt);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartition);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartitionEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartitionNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartitionFromAfsNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartitionFmgLongNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartitionFromAfsFmgLongNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPtNwEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPtFromAfsNwEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPtFmgLongNwEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPtFromAfsFmgLongNwEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_LoadPtBothNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_CloseLdptnwHn);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_StopPtLd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetPtStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetPtStatEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetPtinfoSize);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_AllocAdxFs);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_CreateAdxFs);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_SetFileInfoEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_Open);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_SetAfsFileInfo);

ADXF ADXF_OpenAfs(s32 ptid, s32 flid) {
    ADXF adxf;

    adxf_SetCmdHstry(2, 0, ptid, flid, -1);
    
    adxf = adxf_CreateAdxFs();
    
    if ((adxf != NULL) && (adxf_SetAfsFileInfo(adxf, ptid, flid) < 0)) {
        ADXF_Close(adxf);
        
        adxf = NULL;
    }
    
    adxf_SetCmdHstry(2, 1, ptid, flid, -1);
    
    return adxf;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_CloseSjStm);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_Close);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_CloseAll);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_read_sj32);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_ReadSj32);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_ReadSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_ReadNw32);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_ReadNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_Stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_StopNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_ExecOne);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_ExecServer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_Seek);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_Tell);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFsizeSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFsizeByte);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetNumReqSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetNumReadSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_ChkPrmGfr);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFnameRange);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFnameRangeEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFnameFromPt);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_SetOcbiSw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_SetReqRdSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetStatRead);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFileSize);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A278);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A2B0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A2E0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A310);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A338);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A368);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A398);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A3D0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A3D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A410);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A448);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A490);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A4C8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A500);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A528);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A558);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A580);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A5A8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A5D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A600);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A630);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A668);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A690);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A6C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A6E8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A718);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A740);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A768);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A790);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A7C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A7F0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A820);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A848);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A870);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A898);
