# Caplogo progress

This file shows progress towards porting the very first thing you see on screen – the Capcom logo.

Notes:
- Functions appear in the order that the game first calls them in.
- There's no need to decompile SDK and zlib functions.

| Module   | Progress   |
|----------|------------|
| sf33rd   | 76.82%     |
| cri      | 61.86%     |

| Function                         | File                                                 | Module   | Is decompiled   |
|----------------------------------|------------------------------------------------------|----------|-----------------|
| _InitSys                         | sdk/libkernl/initsys.c                               | sdk      | –               |
| supplement_crt0                  | sdk/libkernl/initsys.c                               | sdk      | –               |
| CreateSema                       | sdk/libkernl/klib.c                                  | sdk      | –               |
| InitSystemCallTableAddress       | sdk/libkernl/initsys.c                               | sdk      | –               |
| setup_0010C278                   | sdk/libkernl/initsys.c                               | sdk      | –               |
| FindAddress                      | sdk/libkernl/initsys.c                               | sdk      | –               |
| kFindAddress                     | sdk/libkernl/initsys.c                               | sdk      | –               |
| InitAlarm                        | sdk/libkernl/alarm.c                                 | sdk      | –               |
| setup_0010C700                   | sdk/libkernl/alarm.c                                 | sdk      | –               |
| Copy_0010C710                    | sdk/libkernl/alarm.c                                 | sdk      | –               |
| kCopy_0010C720                   | sdk/libkernl/alarm.c                                 | sdk      | –               |
| FlushCache                       | sdk/libkernl/klib.c                                  | sdk      | –               |
| GetEntryAddress_0010C758         | sdk/libkernl/alarm.c                                 | sdk      | –               |
| InitTimer                        | sdk/libkernl/timer.c                                 | sdk      | –               |
| _InitAlarm                       | sdk/libkernl/timeralarm.c                            | sdk      | –               |
| AddIntcHandler2                  | sdk/libkernl/klib.c                                  | sdk      | –               |
| DIntr                            | sdk/libkernl/diei.c                                  | sdk      | –               |
| SetT2_MODE                       | sdk/libkernl/timer.c                                 | sdk      | –               |
| SetT2                            | sdk/libkernl/timer.c                                 | sdk      | –               |
| EnableIntc                       | sdk/libkernl/intr.c                                  | sdk      | –               |
| _EnableIntc                      | sdk/libkernl/klib.c                                  | sdk      | –               |
| StartTimerSystemTime             | sdk/libkernl/timer.c                                 | sdk      | –               |
| InitThread                       | sdk/libkernl/thread.c                                | sdk      | –               |
| CreateThread                     | sdk/libkernl/klib.c                                  | sdk      | –               |
| StartThread                      | sdk/libkernl/klib.c                                  | sdk      | –               |
| GetThreadId                      | sdk/libkernl/klib.c                                  | sdk      | –               |
| ChangeThreadPriority             | sdk/libkernl/klib.c                                  | sdk      | –               |
| topThread                        | sdk/libkernl/thread.c                                | sdk      | –               |
| WaitSema                         | sdk/libkernl/klib.c                                  | sdk      | –               |
| InitExecPS2                      | sdk/libkernl/libosd.c                                | sdk      | –               |
| PatchIsNeeded                    | sdk/libkernl/libosd.c                                | sdk      | –               |
| GetOsdConfigParam                | sdk/libkernl/klib.c                                  | sdk      | –               |
| SetOsdConfigParam                | sdk/libkernl/klib.c                                  | sdk      | –               |
| InitTLBFunctions                 | sdk/libkernl/tlbfunc.c                               | sdk      | –               |
| setup_0010B878                   | sdk/libkernl/tlbfunc.c                               | sdk      | –               |
| Copy_0010B820                    | sdk/libkernl/tlbfunc.c                               | sdk      | –               |
| kCopy_0010B830                   | sdk/libkernl/tlbfunc.c                               | sdk      | –               |
| GetEntryAddress_0010B868         | sdk/libkernl/tlbfunc.c                               | sdk      | –               |
| sceSifInitRebootNotify           | sdk/libkernl/iopnotify.c                             | sdk      | –               |
| main                             | sf33rd/Source/PS2/ps2main.c                          | sf33rd   | ✅               |
| AcrMain                          | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| flInitialize                     | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| system_work_init                 | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| flMemset                         | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| flPS2VramInit                    | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| sbrk                             | sdk/libkernl/glue.c                                  | sdk      | –               |
| EndOfHeap                        | sdk/libkernl/klib.c                                  | sdk      | –               |
| SignalSema                       | sdk/libkernl/klib.c                                  | sdk      | –               |
| fmsInitialize                    | sf33rd/AcrSDK/common/fbms.c                          | sf33rd   | ✅               |
| flAllocMemoryS                   | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| fmsAllocMemory                   | sf33rd/AcrSDK/common/fbms.c                          | sf33rd   | ✅               |
| mflInit                          | sf33rd/AcrSDK/common/memfound.c                      | sf33rd   | ✅               |
| plmemInit                        | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| plMemset                         | sf33rd/AcrSDK/common/prilay.c                        | sf33rd   | ✅               |
| system_hard_init                 | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| sceSifInitRpc                    | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| EIntr                            | sdk/libkernl/diei.c                                  | sdk      | –               |
| sceSifInitCmd                    | sdk/libkernl/sifcmd.c                                | sdk      | –               |
| AddDmacHandler                   | sdk/libkernl/klib.c                                  | sdk      | –               |
| EnableDmac                       | sdk/libkernl/intr.c                                  | sdk      | –               |
| _EnableDmac                      | sdk/libkernl/klib.c                                  | sdk      | –               |
| sceSifGetReg                     | sdk/libkernl/klib.c                                  | sdk      | –               |
| sceSifSendCmd                    | sdk/libkernl/sifcmd.c                                | sdk      | –               |
| _sceSifSendCmd                   | sdk/libkernl/sifcmd.c                                | sdk      | –               |
| sceSifWriteBackDCache            | sdk/libkernl/sifcmd.c                                | sdk      | –               |
| sceSifSetDma                     | sdk/libkernl/klib.c                                  | sdk      | –               |
| sceSifAddCmdHandler              | sdk/libkernl/sifcmd.c                                | sdk      | –               |
| sceSifInitIopHeap                | sdk/libkernl/iopheap.c                               | sdk      | –               |
| sceSifBindRpc                    | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| _sceRpcGetPacket                 | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| _sceSifCmdIntrHdlr               | sdk/libkernl/sifcmd.c                                | sdk      | –               |
| isceSifSetDChain                 | sdk/libkernl/klib.c                                  | sdk      | –               |
| _request_end                     | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| iSignalSema                      | sdk/libkernl/klib.c                                  | sdk      | –               |
| _sceRpcFreePacket                | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| DeleteSema                       | sdk/libkernl/klib.c                                  | sdk      | –               |
| sceCdInit                        | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| sceCdSyncS                       | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| sceSifCheckStatRpc               | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| sceSifCallRpc                    | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| cmd_sem_init                     | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| PowerOffCB                       | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| sceCdMmode                       | sdk/libcdvd/cdvd036.c                                | sdk      | –               |
| _sceCd_scmd_prechk               | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| PollSema                         | sdk/libkernl/klib.c                                  | sdk      | –               |
| ReferThreadStatus                | sdk/libkernl/klib.c                                  | sdk      | –               |
| sceSifRebootIop                  | sdk/libkernl/iopreset.c                              | sdk      | –               |
| sceSifExitRpc                    | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| sceSifExitCmd                    | sdk/libkernl/sifcmd.c                                | sdk      | –               |
| DisableDmac                      | sdk/libkernl/intr.c                                  | sdk      | –               |
| _DisableDmac                     | sdk/libkernl/klib.c                                  | sdk      | –               |
| RemoveDmacHandler                | sdk/libkernl/klib.c                                  | sdk      | –               |
| sceSifResetIop                   | sdk/libkernl/iopreset.c                              | sdk      | –               |
| sceSifExecNotifyHandler          | sdk/libkernl/iopnotify.c                             | sdk      | –               |
| sceSifStopDma                    | sdk/libkernl/klib.c                                  | sdk      | –               |
| sceSifSetReg                     | sdk/libkernl/klib.c                                  | sdk      | –               |
| sceSifSyncIop                    | sdk/libkernl/iopreset.c                              | sdk      | –               |
| cbTimerHandler                   | sdk/libkernl/timer.c                                 | sdk      | –               |
| SetNextComp                      | sdk/libkernl/timer.c                                 | sdk      | –               |
| SetT2_COMP                       | sdk/libkernl/timer.c                                 | sdk      | –               |
| sceResetttyinit                  | sdk/libkernl/glue.c                                  | sdk      | –               |
| sceSifSetDChain                  | sdk/libkernl/klib.c                                  | sdk      | –               |
| sceSifGetSreg                    | sdk/libkernl/sifcmd.c                                | sdk      | –               |
| _set_sreg                        | sdk/libkernl/sifcmd.c                                | sdk      | –               |
| sceFsReset                       | sdk/libkernl/filestub.c                              | sdk      | –               |
| flPS2IopModuleLoad               | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| sceSifLoadModule                 | sdk/libkernl/eeloadfile.c                            | sdk      | –               |
| _sceSifLoadModule                | sdk/libkernl/eeloadfile.c                            | sdk      | –               |
| _lf_bind                         | sdk/libkernl/eeloadfile.c                            | sdk      | –               |
| _lf_version                      | sdk/libkernl/eeloadfile.c                            | sdk      | –               |
| flPS2PADModuleInit               | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| flAdxModuleInit                  | sf33rd/AcrSDK/MiddleWare/PS2/ADX/flADX.c             | sf33rd   | ✅               |
| ADXPS2_SetupVoice                | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_SetupVoice                | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| sceGsResetPath                   | sdk/libgraph/graph002.c                              | sdk      | –               |
| sceDmaReset                      | sdk/libdma/libdma.c                                  | sdk      | –               |
| memclr                           | sdk/libdma/libdma.c                                  | sdk      | –               |
| sceDmaPutEnv                     | sdk/libdma/libdma.c                                  | sdk      | –               |
| sceDmaGetChan                    | sdk/libdma/libdma.c                                  | sdk      | –               |
| sceVpu0Reset                     | sdk/libvu0/libvu0.c                                  | sdk      | –               |
| flPS2DmaInitControl              | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flPS2GetSystemMemoryHandle       | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| mflRegisterS                     | sf33rd/AcrSDK/common/memfound.c                      | sf33rd   | ✅               |
| plmemRegisterS                   | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| plmemPullHandle                  | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| plmemRegister                    | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| plmemRegisterAlign               | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| plmemGetFreeSpace                | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| plmemAppendBlockList             | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| AddIntcHandler                   | sdk/libkernl/klib.c                                  | sdk      | –               |
| flPS2SystemTmpBuffInit           | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| flPS2SystemTmpBuffFlush          | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| flPS2GetSystemBuffAdrs           | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| mflRetrieve                      | sf33rd/AcrSDK/common/memfound.c                      | sf33rd   | ✅               |
| plmemRetrieve                    | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| flPS2VramFullClear               | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| flPS2_Clear_Mem16_16A            | sf33rd/AcrSDK/ps2/flps2asm.c                         | sf33rd   |                 |
| sceGsSetDefLoadImage             | sdk/libgraph/graph015.c                              | sdk      | –               |
| sceGsExecLoadImage               | sdk/libgraph/graph017.c                              | sdk      | –               |
| sceGsSyncPath                    | sdk/libgraph/graph012.c                              | sdk      | –               |
| flPS2ReleaseSystemMemory         | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| mflRelease                       | sf33rd/AcrSDK/common/memfound.c                      | sf33rd   | ✅               |
| plmemRelease                     | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| plmemDeleteBlockList             | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| flPS2InitRenderBuff              | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| sceGsResetGraph                  | sdk/libgraph/graph001.c                              | sdk      | –               |
| sceGsGetGParam                   | sdk/libgraph/graph001.c                              | sdk      | –               |
| GsPutIMR                         | sdk/libkernl/klib.c                                  | sdk      | –               |
| SetGsCrt                         | sdk/libkernl/klib.c                                  | sdk      | –               |
| flPS2GetStaticVramArea           | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2DeleteAllVramList           | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2InitRenderState             | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flInitPhaseStarted               | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| flPS2SendRenderState_ALPHA       | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flPS2GetSystemTmpBuff            | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| flPS2DmaAddQueue2                | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flPS2SendRenderState_TEST        | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flPS2SendRenderState_ZBUF        | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flPS2SendRenderState_SCISSOR     | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flPS2SendRenderState_FOGCOL      | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flPS2SendRenderState_TEX1        | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flInitPhaseFinished              | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| flPS2DmaAddEndTag                | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| sceGsSyncVCallback               | sdk/libgraph/graph019.c                              | sdk      | –               |
| flPS2VSyncCallback               | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| flmwVSyncCallback                | sf33rd/AcrSDK/MiddleWare/PS2/acrmw.c                 | sf33rd   | ✅               |
| flAdxControll                    | sf33rd/AcrSDK/MiddleWare/PS2/ADX/flADX.c             | sf33rd   | ✅               |
| ADXPS2_ExecVint                  | cri/libadxe/adx_mps2.c                               | cri      |                 |
| SVM_ExecSvrVint                  | cri/libadxe/svm.c                                    | cri      |                 |
| SVM_ExecSvrFunc                  | cri/libadxe/svm.c                                    | cri      | ✅               |
| flPS2SwapDBuff                   | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| sceDmaSend                       | sdk/libdma/libdma.c                                  | sdk      | –               |
| CheckAddress                     | sdk/libdma/libdma.c                                  | sdk      | –               |
| WaitDma                          | sdk/libdma/libdma.c                                  | sdk      | –               |
| sceDmaSync                       | sdk/libdma/libdma.c                                  | sdk      | –               |
| flPADInitialize                  | sf33rd/AcrSDK/common/mlPAD.c                         | sf33rd   | ✅               |
| tarPADInit                       | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| PADDeviceInit                    | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| sceDbcInit                       | sdk/libdbc/libdbc.c                                  | sdk      | –               |
| sceDbcGetModVersion              | sdk/libdbc/libdbc.c                                  | sdk      | –               |
| DPRINT                           | sdk/libdbc/libdbc.c                                  | sdk      | –               |
| sceDbcSetWorkAddr                | sdk/libdbc/libdbc.c                                  | sdk      | –               |
| scePad2Init                      | sdk/libpad2/libpad2.c                                | sdk      | –               |
| ps2PADWorkClear                  | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| flpad_ram_clear                  | sf33rd/AcrSDK/common/mlPAD.c                         | sf33rd   | ✅               |
| PADPortOpen                      | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| scePad2CreateSocket              | sdk/libpad2/libpad2.c                                | sdk      | –               |
| sceDbcCreateSocket               | sdk/libdbc/libdbc.c                                  | sdk      | –               |
| scePad2InitDmaDBuff              | sdk/libpad2/libpad2.c                                | sdk      | –               |
| flPADWorkClear                   | sf33rd/AcrSDK/common/mlPAD.c                         | sf33rd   | ✅               |
| flPADConfigSet                   | sf33rd/AcrSDK/common/mlPAD.c                         | sf33rd   | ✅               |
| flPADConfigSetACRtoXX            | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| flPS2DebugInit                   | sf33rd/AcrSDK/ps2/flps2debug.c                       | sf33rd   | ✅               |
| flSetDebugMode                   | sf33rd/AcrSDK/ps2/flps2debug.c                       | sf33rd   | ✅               |
| flCreateTextureFromFile          | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| flCreateTextureFromTim2          | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| flFileLength                     | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| ADXM_Lock                        | cri/libadxe/adx_mps2.c                               | cri      | ✅               |
| SVM_Lock                         | cri/libadxe/svm.c                                    | cri      | ✅               |
| svm_lock                         | cri/libadxe/svm.c                                    | cri      | ✅               |
| sceOpen                          | sdk/libkernl/filestub.c                              | sdk      | –               |
| _sceFsWaitS                      | sdk/libkernl/filestub.c                              | sdk      | –               |
| _sceFsSemInit                    | sdk/libkernl/filestub.c                              | sdk      | –               |
| sceFsInit                        | sdk/libkernl/filestub.c                              | sdk      | –               |
| _sceFsIobSemaMK                  | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| _fs_version                      | sdk/libkernl/filestub.c                              | sdk      | –               |
| new_iob                          | sdk/libkernl/filestub.c                              | sdk      | –               |
| _sceFsSigSema                    | sdk/libkernl/filestub.c                              | sdk      | –               |
| _sceFs_Rcv_Intr                  | sdk/libkernl/filestub.c                              | sdk      | –               |
| sceLseek                         | sdk/libkernl/filestub.c                              | sdk      | –               |
| get_iob                          | sdk/libkernl/filestub.c                              | sdk      | –               |
| sceClose                         | sdk/libkernl/filestub.c                              | sdk      | –               |
| ADXM_Unlock                      | cri/libadxe/adx_mps2.c                               | cri      | ✅               |
| SVM_Unlock                       | cri/libadxe/svm.c                                    | cri      | ✅               |
| svm_unlock                       | cri/libadxe/svm.c                                    | cri      | ✅               |
| mflTemporaryUse                  | sf33rd/AcrSDK/common/memfound.c                      | sf33rd   | ✅               |
| plmemTemporaryUse                | sf33rd/AcrSDK/common/memmgr.c                        | sf33rd   | ✅               |
| flFileRead                       | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| fstat                            | sdk/libkernl/glue.c                                  | sdk      | –               |
| isatty                           | sdk/libkernl/glue.c                                  | sdk      | –               |
| write                            | sdk/libkernl/glue.c                                  | sdk      | –               |
| sceTtyInit                       | sdk/libkernl/tty.c                                   | sdk      | –               |
| sceDeci2Open                     | sdk/libkernl/deci2.c                                 | sdk      | –               |
| Deci2Call                        | sdk/libkernl/klib.c                                  | sdk      | –               |
| sceRead                          | sdk/libkernl/filestub.c                              | sdk      | –               |
| flCreateTextureFromTim2_mem      | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| flPS2GetTextureHandle            | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| plTIM2GetMipmapTextureNum        | sf33rd/AcrSDK/common/pltim2.c                        | sf33rd   | ✅               |
| CheckTIM2FileHeader              | sf33rd/AcrSDK/common/pltim2.c                        | sf33rd   | ✅               |
| GetTim2PictureHead               | sf33rd/AcrSDK/common/pltim2.c                        | sf33rd   | ✅               |
| InputTim2AlignRegulation         | sf33rd/AcrSDK/common/pltim2.c                        | sf33rd   | ✅               |
| plTIM2SetContextFromImage        | sf33rd/AcrSDK/common/pltim2.c                        | sf33rd   | ✅               |
| flPS2GetTextureInfoFromContext   | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2GetTextureBuffWidth         | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2GetTextureVramBlock         | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2GetTextureSize              | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| plTIM2GetPixelAddressFromImage   | sf33rd/AcrSDK/common/pltim2.c                        | sf33rd   | ✅               |
| GetTim2PictureData               | sf33rd/AcrSDK/common/pltim2.c                        | sf33rd   | ✅               |
| flMemcpy                         | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| flPS2CreateTextureHandle         | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2GetPaletteHandle            | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| plTIM2SetPaletteContextFromImage | sf33rd/AcrSDK/common/pltim2.c                        | sf33rd   | ✅               |
| flPS2GetPaletteInfoFromContext   | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2GetPaletteVramBlock         | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| plTIM2GetPaletteAddressFromImage | sf33rd/AcrSDK/common/pltim2.c                        | sf33rd   | ✅               |
| GetTim2ClutData                  | sf33rd/AcrSDK/common/pltim2.c                        | sf33rd   | ✅               |
| flPS2ConvertAlpha                | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| flPS2CreatePaletteHandle         | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPrintColor                     | sf33rd/AcrSDK/ps2/flps2debug.c                       | sf33rd   | ✅               |
| flPS2DebugStrClear               | sf33rd/AcrSDK/ps2/flps2debug.c                       | sf33rd   | ✅               |
| sceGsSyncV                       | sdk/libgraph/graph011.c                              | sdk      | –               |
| VSync2                           | sdk/libkernl/glue.c                                  | sdk      | –               |
| SetVSyncFlag                     | sdk/libkernl/klib.c                                  | sdk      | –               |
| flSetRenderState                 | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flPS2SetClearColor               | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| ppgWorkInitializeApprication     | sf33rd/Source/Common/PPGWork.c                       | sf33rd   |                 |
| distributeScratchPadAddress      | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| njdp2d_init                      | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| njUserInit                       | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| appViewSetItems                  | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| appViewMatrix                    | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| flmatMakeViewport                | sf33rd/AcrSDK/ps2/flps2math.c                        | sf33rd   | ✅               |
| flmatInit                        | sf33rd/AcrSDK/ps2/flps2math.c                        | sf33rd   | ✅               |
| flPS2MakeClipViewport            | sf33rd/AcrSDK/ps2/flps2math.c                        | sf33rd   | ✅               |
| mmSystemInitialize               | sf33rd/Source/Common/MemMan.c                        | sf33rd   | ✅               |
| flGetFrame                       | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| fmsGetFrame                      | sf33rd/AcrSDK/common/fbms.c                          | sf33rd   | ✅               |
| seqsGetUseMemorySize             | sf33rd/Source/Game/MTRANS.c                          | sf33rd   |                 |
| mppMalloc                        | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| flAllocMemory                    | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| seqsInitialize                   | sf33rd/Source/Game/MTRANS.c                          | sf33rd   |                 |
| ppg_Initialize                   | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| mmHeapInitialize                 | sf33rd/Source/Common/MemMan.c                        | sf33rd   | ✅               |
| mmRoundUp                        | sf33rd/Source/Common/MemMan.c                        | sf33rd   | ✅               |
| mmRoundOff                       | sf33rd/Source/Common/MemMan.c                        | sf33rd   | ✅               |
| zlib_Initialize                  | sf33rd/Source/Compress/zlibApp.c                     | sf33rd   | ✅               |
| flGetSpace                       | sf33rd/AcrSDK/ps2/flps2etc.c                         | sf33rd   | ✅               |
| fmsCalcSpace                     | sf33rd/AcrSDK/common/fbms.c                          | sf33rd   | ✅               |
| Init_ram_control_work            | sf33rd/Source/Game/RAMCNT.c                          | sf33rd   | ✅               |
| Setup_Disp_Size                  | sf33rd/Source/Game/SYS_sub2.c                        | sf33rd   | ✅               |
| setup_pos_remake_key             | sf33rd/Source/Game/SYS_sub2.c                        | sf33rd   | ✅               |
| Init_sound_system                | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| flAdxInitialize                  | sf33rd/AcrSDK/MiddleWare/PS2/ADX/flADX.c             | sf33rd   | ✅               |
| ADXPS2_SetupDvdFs                | cri/libadxe/adx_sudv.c                               | cri      |                 |
| cvFsEntryErrFunc                 | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| cvFsAddDev                       | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| addDevice                        | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| toUpperStr                       | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| dvCiGetInterface                 | cri/libadxe/dvci.c                                   | cri      | ✅               |
| dvCiSetRootDir                   | cri/libadxe/dvci_sub.c                               | cri      |                 |
| getDevice                        | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| dvCiEntryErrFunc                 | cri/libadxe/dvci.c                                   | cri      | ✅               |
| cvFsSetDefDev                    | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| isExistDev                       | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| dvCiSetRdMode                    | cri/libadxe/dvci_sub.c                               | cri      |                 |
| ADXPS2_LoadFcacheDvd             | cri/libadxe/adx_sudv.c                               | cri      | ✅               |
| dvCiLoadFcache                   | cri/libadxe/dvci_sub.c                               | cri      | ✅               |
| load_flist                       | cri/libadxe/dvci_sub.c                               | cri      | ✅               |
| dvci_conv_fname                  | cri/libadxe/dvci_sub.c                               | cri      | ✅               |
| dvci_to_large_to_yen             | cri/libadxe/dvci.c                                   | cri      | ✅               |
| SRD_SetHistory                   | cri/libadxe/cri_srd.c                                | cri      | ✅               |
| sceCdSync                        | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| dvCiCdSearchFile                 | cri/libadxe/dvci.c                                   | cri      | ✅               |
| sceCdLayerSearchFile             | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| sceCdRead                        | sdk/libcdvd/cdvd005.c                                | sdk      | –               |
| sceCdNcmdDiskReady               | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| _sceCd_ncmd_prechk               | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| _sceCd_cd_read_intr              | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| _sceCd_cd_callback               | sdk/libcdvd/cdvd000.c                                | sdk      | –               |
| analysis_flist_003DC6A0          | cri/libadxe/dvci_sub.c                               | cri      |                 |
| search_fstate                    | cri/libadxe/dvci_sub.c                               | cri      | ✅               |
| scePrintf                        | sdk/libkernl/kprintf2.c                              | sdk      | –               |
| _printf                          | sdk/libkernl/kprintf2.c                              | sdk      | –               |
| deci2Putchar                     | sdk/libkernl/kprintf2.c                              | sdk      | –               |
| kputs                            | sdk/libkernl/deci2.c                                 | sdk      | –               |
| ADXPS2_SetupThrd                 | cri/libadxe/adx_mps2.c                               | cri      |                 |
| ADXM_SetupThrd                   | cri/libadxe/adx_mps2.c                               | cri      |                 |
| SVM_Init                         | cri/libadxe/svm.c                                    | cri      | ✅               |
| svm_reset_variable               | cri/libadxe/svm.c                                    | cri      | ✅               |
| SVM_SetCbLock                    | cri/libadxe/svm.c                                    | cri      | ✅               |
| SVM_SetCbUnlock                  | cri/libadxe/svm.c                                    | cri      | ✅               |
| adxm_SetupSafeThrd               | cri/libadxe/adx_mps2.c                               | cri      |                 |
| adxm_SuspendThread               | cri/libadxe/adx_mps2.c                               | cri      |                 |
| SuspendThread                    | sdk/libkernl/klib.c                                  | sdk      | –               |
| adxm_SetupVsyncThrd              | cri/libadxe/adx_mps2.c                               | cri      |                 |
| adxm_SetupFsThrd                 | cri/libadxe/adx_mps2.c                               | cri      |                 |
| adxm_SetupMwIdleThrd             | cri/libadxe/adx_mps2.c                               | cri      |                 |
| adxm_vsync_proc                  | cri/libadxe/adx_mps2.c                               | cri      |                 |
| adxm_IsSetupThrdEx               | cri/libadxe/adx_mps2.c                               | cri      |                 |
| ADXPS2_WakeupMainThrd            | cri/libadxe/adx_mps2.c                               | cri      |                 |
| SVM_ExecSvrVsync                 | cri/libadxe/svm.c                                    | cri      |                 |
| adxm_SleepThread                 | cri/libadxe/adx_mps2.c                               | cri      |                 |
| SleepThread                      | sdk/libkernl/klib.c                                  | sdk      | –               |
| adxm_fs_proc                     | cri/libadxe/adx_mps2.c                               | cri      |                 |
| SVM_ExecSvrFs                    | cri/libadxe/svm.c                                    | cri      |                 |
| SVM_SetCbBdr                     | cri/libadxe/svm.c                                    | cri      |                 |
| _adxm_lock                       | cri/libadxe/adx_mps2.c                               | cri      |                 |
| adxm_ResumeThread                | cri/libadxe/adx_mps2.c                               | cri      |                 |
| ResumeThread                     | sdk/libkernl/klib.c                                  | sdk      | –               |
| _adxm_unlock                     | cri/libadxe/adx_mps2.c                               | cri      |                 |
| ADXT_Init                        | cri/libadxe/adx_inis.c                               | cri      | ✅               |
| ADXCRS_Init                      | cri/libadxe/adx_crs.c                                | cri      | ✅               |
| ADXCRS_Lock                      | cri/libadxe/adx_crs.c                                | cri      | ✅               |
| SJUNI_Init                       | cri/libadxe/sj_uni.c                                 | cri      | ✅               |
| SJRBF_Init                       | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| SJCRS_Lock                       | cri/libadxe/sj_crs.c                                 | cri      | ✅               |
| SJCRS_Unlock                     | cri/libadxe/sj_crs.c                                 | cri      | ✅               |
| SJMEM_Init                       | cri/libadxe/sj_mem.c                                 | cri      | ✅               |
| ADXERR_Init                      | cri/libadxe/adx_errs.c                               | cri      | ✅               |
| ADXSTM_Init                      | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSJD_Init                      | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXB_Init                        | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| ADXPD_Init                       | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| SKG_Init                         | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| ADXF_Init                        | cri/libadxe/adx_fini.c                               | cri      | ✅               |
| ADXRNA_Init                      | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_Init                      | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| SJRMT_Init                       | cri/libadxe/sjr_clt.c                                | cri      | ✅               |
| DTX_Init                         | cri/libadxe/dtx.c                                    | cri      | ✅               |
| adxm_safe_proc                   | cri/libadxe/adx_mps2.c                               | cri      |                 |
| adxm_safe_trap                   | cri/libadxe/adx_mps2.c                               | cri      |                 |
| SJX_Init                         | cri/libadxe/sjx.c                                    | cri      | ✅               |
| sceSifAllocIopHeap               | sdk/libkernl/iopheap.c                               | sdk      | –               |
| DTX_Create                       | cri/libadxe/dtx.c                                    | cri      | ✅               |
| dtx_create_rmt                   | cri/libadxe/dtx.c                                    | cri      | ✅               |
| SyncDCache                       | sdk/libkernl/cache.c                                 | sdk      | –               |
| _sceSDC                          | sdk/libkernl/cache.c                                 | sdk      | –               |
| InvalidDCache                    | sdk/libkernl/cache.c                                 | sdk      | –               |
| _sceIDC                          | sdk/libkernl/cache.c                                 | sdk      | –               |
| DTX_SetRcvCbf                    | cri/libadxe/dtx.c                                    | cri      | ✅               |
| DTX_SetSndCbf                    | cri/libadxe/dtx.c                                    | cri      | ✅               |
| DTX_CallUrpc                     | cri/libadxe/dtx.c                                    | cri      | ✅               |
| PS2RNA_InitIopSnd                | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| ps2rna_init_psj                  | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| SJUNI_CreateRmt                  | cri/libadxe/sjr_clt.c                                | cri      | ✅               |
| SJUNI_Create                     | cri/libadxe/sj_uni.c                                 | cri      | ✅               |
| SJUNI_Reset                      | cri/libadxe/sj_uni.c                                 | cri      | ✅               |
| SJUNI_PutChunk                   | cri/libadxe/sj_uni.c                                 | cri      | ✅               |
| SJX_Create                       | cri/libadxe/sjx.c                                    | cri      | ✅               |
| LSC_Init                         | cri/libadxe/lsc_ini.c                                | cri      | ✅               |
| LSC_LockCrs                      | cri/libadxe/lsc_crs.c                                | cri      | ✅               |
| lsc_EntrySvrInt                  | cri/libadxe/lsc_ini.c                                | cri      | ✅               |
| LSC_EntryErrFunc                 | cri/libadxe/lsc_err.c                                | cri      | ✅               |
| LSC_UnlockCrs                    | cri/libadxe/lsc_crs.c                                | cri      | ✅               |
| ADXRNA_EntryErrFunc              | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| ADXM_IsSetupThrd                 | cri/libadxe/adx_mps2.c                               | cri      | ✅               |
| SVM_SetCbSvrId                   | cri/libadxe/svm.c                                    | cri      | ✅               |
| SVM_SetCbSvr                     | cri/libadxe/svm.c                                    | cri      | ✅               |
| ADXT_SetDefSvrFreq               | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| ADXCRS_Unlock                    | cri/libadxe/adx_crs.c                                | cri      | ✅               |
| ADXT_Create                      | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| SJRBF_Create                     | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| SJRBF_Reset                      | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| ADXSTM_Create                    | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTMF_CreateCvfsRt             | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTMF_SetupHandleMember        | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| SJRBF_GetNumData                 | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| ADXSJD_Create                    | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| SJRBF_GetBufPtr                  | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| SJRBF_GetBufSize                 | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| SJRBF_GetXtrSize                 | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| ADXB_Create                      | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| ADXPD_Create                     | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| ADX_GetCoefficient               | cri/libadxe/adx_dcd.c                                | cri      |                 |
| ADXB_EntryGetWrFunc              | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| adxsjd_clear                     | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXRNA_Create                    | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_Create                    | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| ps2rna_get_psj                   | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| DTR_Create                       | cri/libadxe/dtr.c                                    | cri      | ✅               |
| LSC_Create                       | cri/libadxe/lsc.c                                    | cri      | ✅               |
| lsc_Alloc                        | cri/libadxe/lsc.c                                    | cri      | ✅               |
| LSC_SetStmHndl                   | cri/libadxe/lsc.c                                    | cri      | ✅               |
| ADXT_SetLnkSw                    | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| ADXSJD_SetLnkSw                  | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| cseInitSndDrv                    | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.c         | sf33rd   |                 |
| flSifRpcInit                     | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/eflSifRpc.c   | sf33rd   |                 |
| DelayThread                      | sdk/libkernl/thread.c                                | sdk      | –               |
| TimerUSec2BusClock               | sdk/libkernl/timer.c                                 | sdk      | –               |
| SetTimerAlarm                    | sdk/libkernl/timeralarm.c                            | sdk      | –               |
| AllocTimerCounter                | sdk/libkernl/timer.c                                 | sdk      | –               |
| iAllocTimerCounter               | sdk/libkernl/timer.c                                 | sdk      | –               |
| SetTimerHandler                  | sdk/libkernl/timer.c                                 | sdk      | –               |
| iSetTimerHandler                 | sdk/libkernl/timer.c                                 | sdk      | –               |
| iGetTimerSystemTime              | sdk/libkernl/timer.c                                 | sdk      | –               |
| StartTimerCounter                | sdk/libkernl/timer.c                                 | sdk      | –               |
| iStartTimerCounter               | sdk/libkernl/timer.c                                 | sdk      | –               |
| InsertAlarm                      | sdk/libkernl/timer.c                                 | sdk      | –               |
| UnlinkAlarm                      | sdk/libkernl/timer.c                                 | sdk      | –               |
| AlarmHandler                     | sdk/libkernl/timeralarm.c                            | sdk      | –               |
| _DelayThreadHandler              | sdk/libkernl/thread.c                                | sdk      | –               |
| mlRpcQueueInit                   | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlRpcQueue.c | sf33rd   |                 |
| mlSeInitSndDrv                   | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv.c   | sf33rd   |                 |
| flSifRpcSend                     | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/eflSifRpc.c   | sf33rd   |                 |
| mlTsbInit                        | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB.c      | sf33rd   |                 |
| mlTsbInitEchoWork                | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB.c      | sf33rd   |                 |
| Init_bgm_work                    | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| work_init_zero                   | sf33rd/Source/Game/EFFECT.c                          | sf33rd   | ✅               |
| Setup_Directory_Record_Data      | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| ADXF_LoadPartitionNw             | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXF_LoadPtNwEx                  | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| adxf_LoadPtBothNw                | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| adxf_ChkPrmPt                    | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXF_Open                        | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| adxf_SetCmdHstry                 | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| adxf_CreateAdxFs                 | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| adxf_AllocAdxFs                  | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXSTMF_CreateCvfs               | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| adxf_SetFileInfoEx               | cri/libadxe/adx_fs.c                                 | cri      |                 |
| ADXSTM_BindFile                  | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTM_BindFileNw                | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXT_ExecFsSvr                   | cri/libadxe/adx_fsvr.c                               | cri      | ✅               |
| ADXSTM_ExecServer                | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| SVM_TestAndSet                   | cri/libadxe/svm.c                                    | cri      | ✅               |
| ADXSTMF_ExecHndl                 | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| cvFsOpen                         | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| getDevName                       | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| allocCvFsHn                      | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| variousProc                      | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| getDefDev                        | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| addDevName                       | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| isNeedDevName                    | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| dvCiOptFn1                       | cri/libadxe/dvci.c                                   | cri      |                 |
| dvCiOpen                         | cri/libadxe/dvci.c                                   | cri      | ✅               |
| dvci_alloc                       | cri/libadxe/dvci.c                                   | cri      | ✅               |
| dvci_get_fstate                  | cri/libadxe/dvci_sub.c                               | cri      | ✅               |
| get_fp_from_fname                | cri/libadxe/dvci_sub.c                               | cri      | ✅               |
| dvci_stricmp                     | cri/libadxe/dvci_sub.c                               | cri      | ✅               |
| dvci_charicmp                    | cri/libadxe/dvci_sub.c                               | cri      | ✅               |
| conv_cmp_003DC578                | cri/libadxe/dvci_sub.c                               | cri      | ✅               |
| cvFsSeek                         | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| dvCiSeek                         | cri/libadxe/dvci.c                                   | cri      | ✅               |
| cvFsTell                         | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| dvCiTell                         | cri/libadxe/dvci.c                                   | cri      | ✅               |
| ADXSTM_Seek                      | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| cvFsExecServer                   | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| dvCiExecServer                   | cri/libadxe/dvci.c                                   | cri      | ✅               |
| dvCiExecHndl                     | cri/libadxe/dvci.c                                   | cri      | ✅               |
| SRD_ExecServer                   | cri/libadxe/cri_srd.c                                | cri      | ✅               |
| ADXF_ExecServer                  | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| adxf_ExecOne                     | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXSTM_GetStat                   | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTM_GetFileLen                | cri/libadxe/adx_stmc.c                               | cri      |                 |
| ADXSTM_GetFileSct                | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXF_ReadNw                      | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXF_ReadNw32                    | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| adxf_read_sj32                   | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXSTM_SetEos                    | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTM_SetSj                     | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTM_SetReqRdSize              | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTM_SetPause                  | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTM_Start2                    | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| adxstm_start_sub                 | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXF_GetPtStat                   | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXF_GetPtStatEx                 | cri/libadxe/adx_fs.c                                 | cri      |                 |
| ADXF_GetStat                     | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| adxm_iWakeupThread               | cri/libadxe/adx_mps2.c                               | cri      |                 |
| iReferThreadStatus               | sdk/libkernl/klib.c                                  | sdk      | –               |
| iWakeupThread                    | sdk/libkernl/thread.c                                | sdk      | –               |
| _iWakeupThread                   | sdk/libkernl/klib.c                                  | sdk      | –               |
| adxt_exec_tsvr                   | cri/libadxe/adx_inis.c                               | cri      | ✅               |
| ADXT_ExecServer                  | cri/libadxe/adx_tlk.c                                | cri      |                 |
| ADXSJD_ExecServer                | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXSJD_ExecHndl                  | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXT_ExecHndl                    | cri/libadxe/adx_tsvr.c                               | cri      |                 |
| ADXT_ExecRdCompChk               | cri/libadxe/adx_tsvr.c                               | cri      |                 |
| ADXT_GetStat                     | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| ADXT_ExecRdErrChk                | cri/libadxe/adx_tsvr.c                               | cri      |                 |
| LSC_GetStat                      | cri/libadxe/lsc.c                                    | cri      | ✅               |
| ADXRNA_ExecServer                | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_ExecServer                | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| RNACRS_Lock                      | cri/libadxe/rna_crs.c                                | cri      |                 |
| PS2RNA_ExecHndl                  | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| RNACRS_Unlock                    | cri/libadxe/rna_crs.c                                | cri      |                 |
| DTR_ExecServer                   | cri/libadxe/dtr.c                                    | cri      |                 |
| DTR_ExecHndl                     | cri/libadxe/dtr.c                                    | cri      |                 |
| DTX_ExecServer                   | cri/libadxe/dtx.c                                    | cri      | ✅               |
| DTX_ExecHndl                     | cri/libadxe/dtx.c                                    | cri      | ✅               |
| sjx_sndcbf                       | cri/libadxe/sjx.c                                    | cri      | ✅               |
| SJUNI_GetChunk                   | cri/libadxe/sj_uni.c                                 | cri      | ✅               |
| ps2rna_sndcbf                    | cri/libadxe/ps2_rna.c                                | cri      |                 |
| SJX_ExecServer                   | cri/libadxe/sjx.c                                    | cri      |                 |
| adxt_exec_fssvr                  | cri/libadxe/adx_inis.c                               | cri      | ✅               |
| adxstmf_stat_exec                | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| cvFsGetStat                      | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| dvCiGetStat                      | cri/libadxe/dvci.c                                   | cri      | ✅               |
| SJRBF_GetChunk                   | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| cvFsReqRd                        | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| dvCiReqRd                        | cri/libadxe/dvci.c                                   | cri      | ✅               |
| SRD_Create                       | cri/libadxe/cri_srd.c                                | cri      |                 |
| SVM_LockVar                      | cri/libadxe/svm.c                                    | cri      |                 |
| srd_reset_obj                    | cri/libadxe/cri_srd.c                                | cri      |                 |
| SVM_UnlockVar                    | cri/libadxe/svm.c                                    | cri      |                 |
| SRD_ReqRdDvd                     | cri/libadxe/cri_srd.c                                | cri      |                 |
| SRD_GetStat                      | cri/libadxe/cri_srd.c                                | cri      |                 |
| srd_exec_dvd                     | cri/libadxe/cri_srd.c                                | cri      | ✅               |
| ADXM_ExecMain                    | cri/libadxe/adx_mps2.c                               | cri      | ✅               |
| SVM_ExecSvrMain                  | cri/libadxe/svm.c                                    | cri      | ✅               |
| adxt_exec_main_thrd              | cri/libadxe/adx_inis.c                               | cri      | ✅               |
| LSC_ExecServer                   | cri/libadxe/lsc.c                                    | cri      | ✅               |
| lsc_ExecHndl                     | cri/libadxe/lsc_svr.c                                | cri      |                 |
| srd_check_dvd_error              | cri/libadxe/cri_srd.c                                | cri      | ✅               |
| sceCdGetError                    | sdk/libcdvd/cdvd015.c                                | sdk      | –               |
| ADXSTM_Tell                      | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| sjx_rcvcbf                       | cri/libadxe/sjx.c                                    | cri      | ✅               |
| ps2rna_rcvcbf                    | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| SRD_Destroy                      | cri/libadxe/cri_srd.c                                | cri      |                 |
| SJ_SplitChunk                    | cri/libadxe/sj_utl.c                                 | cri      | ✅               |
| SJRBF_PutChunk                   | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| SJRBF_UngetChunk                 | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| adxf_CloseSjStm                  | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| SJRBF_Destroy                    | cri/libadxe/sj_rbf.c                                 | cri      | ✅               |
| ADXF_CALC_BYTE2SCT               | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXSTM_Stop                      | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTM_StopNw                    | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| adxf_CloseLdptnwHn               | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXF_Close                       | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXSTM_ReleaseFile               | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTM_ReleaseFileNw             | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| cvFsClose                        | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| dvCiClose                        | cri/libadxe/dvci.c                                   | cri      |                 |
| dvci_free                        | cri/libadxe/dvci.c                                   | cri      | ✅               |
| releaseCvFsHn                    | cri/libadxe/cri_cvfs.c                               | cri      | ✅               |
| ADXSTM_Destroy                   | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| sndInitialLoad                   | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| cseMemMapInit                    | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| mlMemMapInit                     | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlMemMap.c   | sf33rd   |                 |
| flSpuMapInit                     | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/eflSpuMap.c   | sf33rd   |                 |
| flSpuMapChgPage                  | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/eflSpuMap.c   | sf33rd   |                 |
| cseMemMapSetPhdAddr              | sf33rd/Source/Game/color3rd.c                        | sf33rd   |                 |
| mlMemMapSetPhdAddr               | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlMemMap.c   | sf33rd   |                 |
| cseTsbSetBankAddr                | sf33rd/Source/Game/color3rd.c                        | sf33rd   |                 |
| mlTsbSetBankAddr                 | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB.c      | sf33rd   |                 |
| load_any_color                   | sf33rd/Source/Game/color3rd.c                        | sf33rd   |                 |
| load_it_use_any_key              | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| load_it_use_any_key2             | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| fsGetFileSize                    | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| fsCalSectorSize                  | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| Pull_ramcnt_key                  | sf33rd/Source/Game/RAMCNT.c                          | sf33rd   | ✅               |
| mmAlloc                          | sf33rd/Source/Common/MemMan.c                        | sf33rd   | ✅               |
| mmAllocSub                       | sf33rd/Source/Common/MemMan.c                        | sf33rd   | ✅               |
| Get_ramcnt_address               | sf33rd/Source/Game/RAMCNT.c                          | sf33rd   | ✅               |
| load_it_use_this_key             | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| fsOpen                           | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| ADXF_OpenAfs                     | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| adxf_SetAfsFileInfo              | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXF_GetFnameRangeEx             | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| adxf_ChkPrmGfr                   | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| ADXF_GetFnameFromPt              | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| fsFileReadSync                   | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| fsRequestFileRead                | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| fsCheckFileReaded                | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| fsUpdateDiskDriveError           | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| sceCdGetDiskType                 | sdk/libcdvd/cdvd014.c                                | sdk      | –               |
| waitVsyncDummy                   | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| cseExecServer                    | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.c         | sf33rd   |                 |
| mlTsbExecServer                  | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB.c      | sf33rd   |                 |
| mlTsbMoveEchoWork                | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB.c      | sf33rd   |                 |
| mlRpcQueueSend                   | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlRpcQueue.c | sf33rd   |                 |
| fsClose                          | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| Set_size_data_ramcnt_key         | sf33rd/Source/Game/RAMCNT.c                          | sf33rd   | ✅               |
| init_trans_color_ram             | sf33rd/Source/Game/color3rd.c                        | sf33rd   |                 |
| Get_size_data_ramcnt_key         | sf33rd/Source/Game/RAMCNT.c                          | sf33rd   | ✅               |
| cseSendBd2SpuWithId              | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.c         | sf33rd   |                 |
| mlMemMapGetBankAddr              | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlMemMap.c   | sf33rd   |                 |
| flSpuMapGetBankAddr              | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/eflSpuMap.c   | sf33rd   |                 |
| mlRpcQueueSetData                | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlRpcQueue.c | sf33rd   |                 |
| sndCheckVTransStatus             | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| cseCheckVTransStatus             | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.c         | sf33rd   |                 |
| mlRpcQueueGetNumVtransReq        | sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlRpcQueue.c | sf33rd   |                 |
| _request_rdata                   | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| _sceRpcGetFPacket2               | sdk/libkernl/sifrpc.c                                | sdk      | –               |
| isceSifSendCmd                   | sdk/libkernl/sifcmd.c                                | sdk      | –               |
| isceSifSetDma                    | sdk/libkernl/klib.c                                  | sdk      | –               |
| Push_ramcnt_key                  | sf33rd/Source/Game/RAMCNT.c                          | sf33rd   | ✅               |
| Push_ramcnt_key_original_2       | sf33rd/Source/Game/RAMCNT.c                          | sf33rd   | ✅               |
| mmFree                           | sf33rd/Source/Common/MemMan.c                        | sf33rd   | ✅               |
| cpInitTask                       | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| cpReadyTask                      | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| palCreateGhost                   | sf33rd/Source/Game/color3rd.c                        | sf33rd   |                 |
| ppgSetupPalChunkDir              | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgSetupContextFromPPL           | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgMallocF                       | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgChangeDataEndian              | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| flCreatePaletteHandle            | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2ConvertTextureFromContext   | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2ConvertContext              | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2GetVramFreeArea             | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2SearchVramSpace             | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2AddVramList                 | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2PullVramWork                | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2ChainVramWork               | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2VramTrans                   | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2VIF1CalcLoadImageSize       | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flPS2GetVramTransAdrs            | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2VIF1MakeLoadImage           | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flPS2DmaAddCntTag                | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flPS2DmaAddRefeTag               | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flPS2VIF1CalcEndLoadImageSize    | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flPS2VIF1MakeEndLoadImage        | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flPS2VIF1CodeAddDirectHL         | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| ppgMakeConvTableTexDC            | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| appSetupBasePriority             | sf33rd/Source/Game/MTRANS.c                          | sf33rd   |                 |
| MemcardInit                      | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| sceMcInit                        | sdk/libmc/libmc.c                                    | sdk      | –               |
| sceMcSync                        | sdk/libmc/libmc.c                                    | sdk      | –               |
| initRenderState                  | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| setBlendMode                     | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| setBlendSource                   | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| setBlendOperation                | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| setFilterMode                    | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| flAdjustScreen                   | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| setBackGroundColor               | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| appSetupTempPriority             | sf33rd/Source/Game/MTRANS.c                          | sf33rd   |                 |
| flPADGetALL                      | sf33rd/AcrSDK/common/mlPAD.c                         | sf33rd   | ✅               |
| tarPADRead                       | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| PADRead_for_PS2                  | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| PADReadSub                       | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| scePad2GetState                  | sdk/libpad2/libpad2.c                                | sdk      | –               |
| scePad2LinkDriver                | sdk/libpad2/libpad2.c                                | sdk      | –               |
| sceDbcGetDepNumber               | sdk/libdbc/libdbc.c                                  | sdk      | –               |
| scePad2CheckDma                  | sdk/libpad2/libpad2.c                                | sdk      | –               |
| scePad2GetSide                   | sdk/libpad2/libpad2.c                                | sdk      | –               |
| scePad2GetSide2                  | sdk/libpad2/libpad2.c                                | sdk      | –               |
| scePad2GetButtonProfile          | sdk/libpad2/libpad2.c                                | sdk      | –               |
| sceDbcReceiveData                | sdk/libdbc/libdbc.c                                  | sdk      | –               |
| scePad2SetButtonOrder            | sdk/libpad2/libpad2.c                                | sdk      | –               |
| sceVibGetProfile                 | sdk/libvib/libvib.c                                  | sdk      | –               |
| update_pad_stick_dir             | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| lever_analog_to_digital          | sf33rd/AcrSDK/ps2/ps2PAD.c                           | sf33rd   | ✅               |
| flupdate_pad_button_data         | sf33rd/AcrSDK/common/mlPAD.c                         | sf33rd   | ✅               |
| flupdate_pad_on_cnt              | sf33rd/AcrSDK/common/mlPAD.c                         | sf33rd   | ✅               |
| flPADACRConf                     | sf33rd/AcrSDK/common/mlPAD.c                         | sf33rd   | ✅               |
| flupdate_pad_stick_dir           | sf33rd/AcrSDK/common/mlPAD.c                         | sf33rd   | ✅               |
| keyConvert                       | sf33rd/Source/Game/IOConv.c                          | sf33rd   | ✅               |
| flPADSetRepeatSw                 | sf33rd/AcrSDK/common/mlPAD.c                         | sf33rd   | ✅               |
| appCopyKeyData                   | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| render_start                     | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| flBeginRender                    | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flGetSystemTime                  | sf33rd/AcrSDK/ps2/flps2debug.c                       | sf33rd   | ✅               |
| njUserMain                       | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| Check_Replay_Status              | sf33rd/Source/Game/SYS_sub.c                         | sf33rd   |                 |
| cpLoopTask                       | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| disp_ramcnt_free_area            | sf33rd/Source/Game/RAMCNT.c                          | sf33rd   | ✅               |
| MaskScreenEdge                   | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| appViewGetItems                  | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| seqsBeforeProcess                | sf33rd/Source/Game/MTRANS.c                          | sf33rd   |                 |
| njdp2d_draw                      | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| ps2SeqsRenderQuadInit_B          | sf33rd/Source/PS2/ps2Quad.c                          | sf33rd   | ✅               |
| setZ_Operation                   | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| ps2SeqsRenderQuadEnd             | sf33rd/Source/PS2/ps2Quad.c                          | sf33rd   | ✅               |
| seqsAfterProcess                 | sf33rd/Source/Game/MTRANS.c                          | sf33rd   |                 |
| CP3toPS2Draw                     | sf33rd/Source/PS2/ps2Quad.c                          | sf33rd   | ✅               |
| KnjFlush                         | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| KnjUseCheck                      | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| render_end                       | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| flEndRender                      | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| disp_effect_work                 | sf33rd/Source/Game/EFFECT.c                          | sf33rd   | ✅               |
| flFlip                           | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| flPS2DispSystemInfo              | sf33rd/AcrSDK/ps2/flps2debug.c                       | sf33rd   | ✅               |
| flPS2LoadCheckFlush              | sf33rd/AcrSDK/ps2/flps2debug.c                       | sf33rd   | ✅               |
| flPS2DebugStrDisp                | sf33rd/AcrSDK/ps2/flps2debug.c                       | sf33rd   | ✅               |
| flReloadTexture                  | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2ReloadTexture               | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2SetTextureRegister          | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flPS2DmaWait                     | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flmwFlip                         | sf33rd/AcrSDK/MiddleWare/PS2/acrmw.c                 | sf33rd   | ✅               |
| flmwFlipSub                      | sf33rd/AcrSDK/MiddleWare/PS2/acrmw.c                 | sf33rd   | ✅               |
| iFlushCache                      | sdk/libkernl/klib.c                                  | sdk      | –               |
| flPS2CheckDbChangeFlag           | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| flPS2DmaSend                     | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flPS2DrawPreparation             | sf33rd/AcrSDK/ps2/foundaps2.c                        | sf33rd   | ✅               |
| flPS2_Mem_move16_16A             | sf33rd/AcrSDK/ps2/flps2asm.c                         | sf33rd   |                 |
| Scrn_Renew                       | sf33rd/Source/Game/bg.c                              | sf33rd   | ✅               |
| Irl_Family                       | sf33rd/Source/Game/bg.c                              | sf33rd   | ✅               |
| Irl_Scrn                         | sf33rd/Source/Game/bg.c                              | sf33rd   | ✅               |
| BGM_Server                       | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| scePad2Read                      | sdk/libpad2/libpad2.c                                | sdk      | –               |
| flPS2DmaInterrupt                | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| Init_Task                        | sf33rd/Source/Game/init3rd.c                         | sf33rd   | ✅               |
| Init_Task_1st                    | sf33rd/Source/Game/init3rd.c                         | sf33rd   | ✅               |
| init_texcash_1st                 | sf33rd/Source/Game/texcash.c                         | sf33rd   |                 |
| Init_texgrplds_work              | sf33rd/Source/Game/texgroup.c                        | sf33rd   | ✅               |
| Init_load_on_memory_data         | sf33rd/Source/Game/aboutspr.c                        | sf33rd   | ✅               |
| copy_char_base_data              | sf33rd/Source/Game/CHARID.c                          | sf33rd   |                 |
| palConvSrcToRam                  | sf33rd/Source/Game/color3rd.c                        | sf33rd   |                 |
| palUpdateGhostCP3                | sf33rd/Source/Game/color3rd.c                        | sf33rd   |                 |
| flLockPalette                    | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2LockTexture                 | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| palConvRowTim2CI8Clut            | sf33rd/Source/Game/color3rd.c                        | sf33rd   | ✅               |
| flUnlockPalette                  | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2UnlockTexture               | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| reservMemKeySelObj               | sf33rd/Source/Game/texgroup.c                        | sf33rd   | ✅               |
| load_any_texture_patnum          | sf33rd/Source/Game/texgroup.c                        | sf33rd   | ✅               |
| load_any_texture_grpnum          | sf33rd/Source/Game/texgroup.c                        | sf33rd   | ✅               |
| Pause_Family_On                  | sf33rd/Source/Game/bg.c                              | sf33rd   |                 |
| njUnitMatrix                     | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| sceVu0UnitMatrix                 | sdk/libvu0/libvu0.c                                  | sdk      | –               |
| njScale                          | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| njTranslate                      | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| njGetMatrix                      | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| Bg_TexInit                       | sf33rd/Source/Game/bg.c                              | sf33rd   |                 |
| palGetChunkGhostCP3              | sf33rd/Source/Game/color3rd.c                        | sf33rd   | ✅               |
| Scrscreen_Init                   | sf33rd/Source/Game/sc_sub.c                          | sf33rd   |                 |
| ppgSetupCurrentDataList          | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgSetupPalChunk                 | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgPullDecBuff                   | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgMallocR                       | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgDecompress                    | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| zlib_Decompress                  | sf33rd/Source/Compress/zlibApp.c                     | sf33rd   | ✅               |
| inflateInit_                     | sf33rd/Source/Compress/zlib/inflate.c                | sf33rd   | –               |
| inflateInit2_                    | sf33rd/Source/Compress/zlib/inflate.c                | sf33rd   | –               |
| zlib_Malloc                      | sf33rd/Source/Compress/zlibApp.c                     | sf33rd   | ✅               |
| inflate_blocks_new               | sf33rd/Source/Compress/zlib/infblock.c               | sf33rd   | –               |
| inflate_blocks_reset             | sf33rd/Source/Compress/zlib/infblock.c               | sf33rd   | –               |
| adler32                          | sf33rd/Source/Compress/zlib/adler32.c                | sf33rd   | –               |
| inflateReset                     | sf33rd/Source/Compress/zlib/inflate.c                | sf33rd   | –               |
| inflate                          | sf33rd/Source/Compress/zlib/inflate.c                | sf33rd   | –               |
| inflate_blocks                   | sf33rd/Source/Compress/zlib/infblock.c               | sf33rd   | –               |
| inflate_trees_fixed              | sf33rd/Source/Compress/zlib/inftrees.c               | sf33rd   | –               |
| inflate_codes_new                | sf33rd/Source/Compress/zlib/infcodes.c               | sf33rd   | –               |
| inflate_codes                    | sf33rd/Source/Compress/zlib/infcodes.c               | sf33rd   | –               |
| inflate_fast                     | sf33rd/Source/Compress/zlib/inffast.c                | sf33rd   | –               |
| inflate_flush                    | sf33rd/Source/Compress/zlib/infutil.c                | sf33rd   | –               |
| inflate_codes_free               | sf33rd/Source/Compress/zlib/infcodes.c               | sf33rd   | –               |
| zlib_Free                        | sf33rd/Source/Compress/zlibApp.c                     | sf33rd   | ✅               |
| inflateEnd                       | sf33rd/Source/Compress/zlib/inflate.c                | sf33rd   | –               |
| inflate_blocks_free              | sf33rd/Source/Compress/zlib/infblock.c               | sf33rd   | –               |
| ppgPushDecBuff                   | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgFree                          | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| inflate_trees_bits               | sf33rd/Source/Compress/zlib/inftrees.c               | sf33rd   | –               |
| huft_build                       | sf33rd/Source/Compress/zlib/inftrees.c               | sf33rd   | –               |
| inflate_trees_dynamic            | sf33rd/Source/Compress/zlib/inftrees.c               | sf33rd   | –               |
| ppgSetupTexChunk_1st             | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgSetupTexChunk_2nd             | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgSetupTexChunk_3rd             | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgSetupContextFromPPG           | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| flCreateTextureHandle            | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| ppgSourceDataReleased            | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgTexSrcDataReleased            | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgCheckTextureDataBe            | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgPalSrcDataReleased            | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgCheckPaletteDataBe            | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| Sa_frame_Clear                   | sf33rd/Source/Game/sc_sub.c                          | sf33rd   |                 |
| effect_work_init                 | sf33rd/Source/Game/EFFECT.c                          | sf33rd   | ✅               |
| init_pulpul_work                 | sf33rd/Source/Game/PulPul.c                          | sf33rd   | ✅               |
| init_pulpul_work2                | sf33rd/Source/Game/PulPul.c                          | sf33rd   | ✅               |
| init_pulpul_round2               | sf33rd/Source/Game/PulPul.c                          | sf33rd   | ✅               |
| Init_Load_Request_Queue_1st      | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| Game_Data_Init                   | sf33rd/Source/Game/SYS_sub.c                         | sf33rd   |                 |
| Setup_Default_Game_Option        | sf33rd/Source/Game/SYS_sub.c                         | sf33rd   |                 |
| Ranking_Init                     | sf33rd/Source/Game/RANKING.c                         | sf33rd   |                 |
| Copy_Save_w                      | sf33rd/Source/Game/SYS_sub.c                         | sf33rd   |                 |
| Copy_Check_w                     | sf33rd/Source/Game/SYS_sub.c                         | sf33rd   |                 |
| Setup_Difficult_V                | sf33rd/Source/Game/init3rd.c                         | sf33rd   | ✅               |
| Setup_Limit_Time                 | sf33rd/Source/Game/SYS_sub.c                         | sf33rd   |                 |
| pulpul_stop                      | sf33rd/Source/Game/PulPul.c                          | sf33rd   | ✅               |
| pulpul_stop2                     | sf33rd/Source/Game/PulPul.c                          | sf33rd   | ✅               |
| Warning_Init                     | sf33rd/Source/Game/DEMO00.c                          | sf33rd   | ✅               |
| mmDebWriteTag                    | sf33rd/Source/Common/MemMan.c                        | sf33rd   | ✅               |
| purge_texture_group              | sf33rd/Source/Game/texgroup.c                        | sf33rd   | ✅               |
| CP3toPS2DrawOff                  | sf33rd/Source/PS2/ps2Quad.c                          | sf33rd   | ✅               |
| Init_Task_Aload                  | sf33rd/Source/Game/init3rd.c                         | sf33rd   | ✅               |
| SaveInit                         | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| McActInit                        | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| load_data                        | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| ADXF_GetFsizeSct                 | cri/libadxe/adx_fs.c                                 | cri      | ✅               |
| SaveMove                         | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| save_sw_get                      | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| save_move_init                   | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| load_busy_ck                     | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| McActMain                        | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| mc_act_stop                      | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| save_msg_trans                   | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| Reset_Task                       | sf33rd/Source/Game/Reset.c                           | sf33rd   | ✅               |
| Check_Reset_IO                   | sf33rd/Source/Game/Reset.c                           | sf33rd   | ✅               |
| Reset_Init                       | sf33rd/Source/Game/Reset.c                           | sf33rd   | ✅               |
| Reset_Move                       | sf33rd/Source/Game/Reset.c                           | sf33rd   | ✅               |
| Check_Reset                      | sf33rd/Source/Game/Reset.c                           | sf33rd   | ✅               |
| KnjInit                          | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| make_env_pkt                     | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| make_pal_pkt                     | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| make_img_pkt                     | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| McActAvailSet                    | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| save_move_aload                  | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| auto_load_init                   | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| auto_load_load                   | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| mc_msg_set                       | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| aload_buf_adrs                   | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| McActSave0Set                    | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| McActResult                      | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| mc_act_save0                     | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| mc_check_card                    | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| mc_sync                          | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| sceMcGetInfo                     | sdk/libmc/libmc.c                                    | sdk      | –               |
| mc_act_return                    | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| GetMemCardMsg                    | sf33rd/Source/PS2/mc/msgsub.c                        | sf33rd   |                 |
| KnjSetSize                       | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| KnjSetColor                      | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| FormStrDisp                      | sf33rd/Source/PS2/mc/msgsub.c                        | sf33rd   |                 |
| KnjLocate                        | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| str_tag_get                      | sf33rd/Source/PS2/mc/msgsub.c                        | sf33rd   |                 |
| str_str_get                      | sf33rd/Source/PS2/mc/msgsub.c                        | sf33rd   |                 |
| KnjCheckCode                     | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| utf82unicode                     | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| unicode2index                    | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| is_unicode_han                   | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| KnjPuts                          | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| unicode_puts                     | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| get_uni_adrs                     | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| make_fnt_pkt                     | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| make_fbg_pkt                     | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| str_tag_check                    | sf33rd/Source/PS2/mc/msgsub.c                        | sf33rd   |                 |
| KnjSetRgb                        | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| mceGetInfoApdx                   | sdk/libmc/libmc.c                                    | sdk      | –               |
| McActStopSet                     | sf33rd/Source/PS2/mc/mcsub.c                         | sf33rd   | ✅               |
| auto_load_exit                   | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| save_move_exit                   | sf33rd/Source/PS2/mc/savesub.c                       | sf33rd   | ✅               |
| KnjFinish                        | sf33rd/Source/PS2/mc/knjsub.c                        | sf33rd   |                 |
| Init_Task_2nd                    | sf33rd/Source/Game/init3rd.c                         | sf33rd   | ✅               |
| Warning                          | sf33rd/Source/Game/DEMO00.c                          | sf33rd   | ✅               |
| setTexAdrsMode                   | sf33rd/Source/Game/AcrUtil.c                         | sf33rd   | ✅               |
| FadeInit                         | sf33rd/Source/Game/sc_sub.c                          | sf33rd   | ✅               |
| TexRelease                       | sf33rd/Source/Game/op_sub.c                          | sf33rd   | ✅               |
| ppgReleaseTextureHandle          | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| flReleaseTextureHandle           | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2DmaTerminate                | sf33rd/AcrSDK/ps2/flps2dma.c                         | sf33rd   |                 |
| flPS2DeleteVramList              | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| ppgReleasePaletteHandle          | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| flReleasePaletteHandle           | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| flPS2PushVramWork                | sf33rd/AcrSDK/ps2/flps2vram.c                        | sf33rd   | ✅               |
| CP3toPS2DrawOn                   | sf33rd/Source/PS2/ps2Quad.c                          | sf33rd   | ✅               |
| Init_Task_End                    | sf33rd/Source/Game/init3rd.c                         | sf33rd   | ✅               |
| cpExitTask                       | sf33rd/Source/Game/main.c                            | sf33rd   | ✅               |
| Check_SoftReset                  | sf33rd/Source/Game/Reset.c                           | sf33rd   | ✅               |
| Entry_Task                       | sf33rd/Source/Game/Entry.c                           | sf33rd   | ✅               |
| nowSoftReset                     | sf33rd/Source/Game/Reset.c                           | sf33rd   | ✅               |
| Entry_00                         | sf33rd/Source/Game/Entry.c                           | sf33rd   | ✅               |
| Game_Task                        | sf33rd/Source/Game/Game.c                            | sf33rd   | ✅               |
| init_color_trans_req             | sf33rd/Source/Game/color3rd.c                        | sf33rd   |                 |
| init_texcash_before_process      | sf33rd/Source/Game/texcash.c                         | sf33rd   |                 |
| Loop_Demo                        | sf33rd/Source/Game/Game.c                            | sf33rd   | ✅               |
| Ck_Coin                          | sf33rd/Source/Game/Game.c                            | sf33rd   | ✅               |
| texture_cash_update              | sf33rd/Source/Game/texcash.c                         | sf33rd   |                 |
| disp_texcash_free_area           | sf33rd/Source/Game/texcash.c                         | sf33rd   |                 |
| move_pulpul_work                 | sf33rd/Source/Game/PulPul.c                          | sf33rd   | ✅               |
| move_pulpul                      | sf33rd/Source/Game/PulPul.c                          | sf33rd   | ✅               |
| chkVibUnit                       | sf33rd/Source/Game/PulPul.c                          | sf33rd   | ✅               |
| Check_Off_Vib                    | sf33rd/Source/Game/SYS_sub.c                         | sf33rd   |                 |
| Check_LDREQ_Queue                | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| disp_ldreq_status                | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| Check_Check_Screen               | sf33rd/Source/Game/debug/Debug.c                     | sf33rd   |                 |
| Check_Pos_BG                     | sf33rd/Source/Game/debug/Debug.c                     | sf33rd   |                 |
| Disp_Sound_Code                  | sf33rd/Source/Game/SE.c                              | sf33rd   | ✅               |
| Debug_Task                       | sf33rd/Source/Game/debug/Debug.c                     | sf33rd   |                 |
| Debug_Init                       | sf33rd/Source/Game/debug/Debug.c                     | sf33rd   |                 |
| Disp_Free_work                   | sf33rd/Source/Game/debug/Debug.c                     | sf33rd   |                 |
| Disp_Random                      | sf33rd/Source/Game/debug/Debug.c                     | sf33rd   |                 |
| Basic_Sub                        | sf33rd/Source/Game/SYS_sub.c                         | sf33rd   |                 |
| move_effect_work                 | sf33rd/Source/Game/EFFECT.c                          | sf33rd   | ✅               |
| CAPCOM_Logo                      | sf33rd/Source/Game/DEMO00.c                          | sf33rd   | ✅               |
| checkAdxFileLoaded               | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| ppgSetupCmpChunk                 | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| checkSelObjFileLoaded            | sf33rd/Source/Game/texgroup.c                        | sf33rd   | ✅               |
| Clear_texcash_work               | sf33rd/Source/Game/texcash.c                         | sf33rd   |                 |
| _clear_texcash_work              | sf33rd/Source/Game/texcash.c                         | sf33rd   |                 |
| Debug_1st                        | sf33rd/Source/Game/debug/Debug.c                     | sf33rd   |                 |
| Standby_BGM                      | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| remake_sound_code_for_DC         | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| Store_Sound_Code                 | sf33rd/Source/Game/SE.c                              | sf33rd   |                 |
| sound_request_for_dc             | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   |                 |
| CAPLOGO_Init                     | sf33rd/Source/Game/DEMO00.c                          | sf33rd   | ✅               |
| Push_LDREQ_Queue_Direct          | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| Push_LDREQ_Queue                 | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| q_ldreq_color_data               | sf33rd/Source/Game/color3rd.c                        | sf33rd   |                 |
| fsCheckCommandExecuting          | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| ADXT_Stop                        | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| ADXT_StopWithoutLsc              | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| ADXRNA_SetTransSw                | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_SetTransSw                | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| DTR_Stop                         | cri/libadxe/dtr.c                                    | cri      | ✅               |
| ADXRNA_SetPlaySw                 | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_SetPlaySw                 | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| PS2RNA_SetDiscardSw              | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| ADXSJD_Stop                      | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXB_Stop                        | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| ADXPD_Stop                       | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| bgm_seamless_clear               | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| bgm_volume_setup                 | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| ADXT_SetOutVol                   | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| ADXSJD_GetDefOutVol              | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXB_GetAinfLen                  | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| ADXRNA_SetOutVol                 | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_SetOutVol                 | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| ADXT_Pause                       | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| bgm_play_request                 | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| ADXT_StartAfs                    | cri/libadxe/adx_tlk2.c                               | cri      | ✅               |
| Check_LDREQ_Clear                | sf33rd/Source/Game/GD3rd.c                           | sf33rd   | ✅               |
| adxt_stat_decinfo                | cri/libadxe/adx_tsvr.c                               | cri      |                 |
| adxt_start_stm                   | cri/libadxe/adx_tlk.c                                | cri      |                 |
| ADXSTM_SetBufSize                | cri/libadxe/adx_stmc.c                               | cri      |                 |
| ADXSTM_EntryEosFunc              | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| ADXSTM_Start                     | cri/libadxe/adx_stmc.c                               | cri      | ✅               |
| adxt_start_sj                    | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| ADXSJD_SetInSj                   | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXB_SetAhxInSj                  | cri/libadxe/adx_bahx.c                               | cri      | ✅               |
| ADXB_SetAc3InSj                  | cri/libadxe/adx_bahx.c                               | cri      | ✅               |
| ADXSJD_Start                     | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXSJD_GetStat                   | cri/libadxe/adx_sjd.c                                | cri      |                 |
| adxsjd_decode_prep               | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXB_DecodeHeader                | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXB_DecodeHeaderAdx             | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADX_DecodeInfo                   | cri/libadxe/adx_dcd.c                                | cri      |                 |
| ADX_DecodeInfoExVer              | cri/libadxe/adx_dcd.c                                | cri      |                 |
| adxb_get_key                     | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXPD_SetExtPrm                  | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| ADX_DecodeInfoExADPCM2           | cri/libadxe/adx_dcd.c                                | cri      |                 |
| ADX_DecodeInfoExIdly             | cri/libadxe/adx_dcd.c                                | cri      |                 |
| ADXPD_SetCoef                    | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| ADXPD_SetDly                     | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| ADX_DecodeInfoExLoop             | cri/libadxe/adx_dcd.c                                | cri      |                 |
| ADX_DecodeInfoAinf               | cri/libadxe/adx_dcd.c                                | cri      |                 |
| ADXB_GetFormat                   | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXSJD_GetNumChan                | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXB_GetNumChan                  | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| ADXSJD_GetSfreq                  | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXB_GetSfreq                    | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| ADXSJD_GetNumLoop                | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXB_GetNumLoop                  | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXSJD_GetBlkSmpl                | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXB_GetBlkSmpl                  | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXSJD_SetMaxDecSmpl             | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXB_SetAhxDecSmpl               | cri/libadxe/adx_bahx.c                               | cri      |                 |
| ADXB_SetAc3DecSmpl               | cri/libadxe/adx_bahx.c                               | cri      |                 |
| ADXSJD_GetTotalNumSmpl           | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXB_GetTotalNumSmpl             | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| ADXSJD_SetTrapNumSmpl            | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXSJD_SetTrapDtLen              | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXSJD_SetTrapCnt                | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXSJD_EntryTrapFunc             | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXSJD_GetOutBps                 | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXB_GetOutBps                   | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| ADXRNA_SetBitPerSmpl             | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_SetBitPerSmpl             | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| ADXRNA_SetSfreq                  | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_SetSfreq                  | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| ADXRNA_SetNumChan                | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_SetNumChan                | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| ADXRNA_SetTotalNumSmpl           | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| ADXT_GetTranspose                | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| adxt_set_outpan                  | cri/libadxe/adx_tsvr.c                               | cri      |                 |
| ADXSJD_GetDefPan                 | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXRNA_SetOutPan                 | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_SetOutPan                 | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| ADXSJD_GetFormat                 | cri/libadxe/adx_sjd.c                                | cri      |                 |
| DTR_GetStat                      | cri/libadxe/dtr.c                                    | cri      |                 |
| SJUNI_GetNumData                 | cri/libadxe/sj_uni.c                                 | cri      | ✅               |
| DTR_Start                        | cri/libadxe/dtr.c                                    | cri      |                 |
| SJUNI_UngetChunk                 | cri/libadxe/sj_uni.c                                 | cri      | ✅               |
| adxsjd_decode_exec               | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXB_GetStat                     | cri/libadxe/adx_bsc.c                                | cri      |                 |
| adxsjd_decexec_start             | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXB_EntryData                   | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXB_Start                       | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXB_ExecHndl                    | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXB_ExecOneAdx                  | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXPD_GetStat                    | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| adxsjd_get_wr                    | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXB_GetPcmBuf                   | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXB_EvokeDecode                 | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXB_EvokeExpandSte              | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXPD_EntrySte                   | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| ADXPD_Start                      | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| ADXPD_ExecHndl                   | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| ADX_DecodeSte4                   | cri/libadxe/adx_dcd5.c                               | cri      |                 |
| ADX_DecodeSte4AsSte              | cri/libadxe/adx_dcd5.c                               | cri      |                 |
| ADXB_EndDecode                   | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXPD_GetNumBlk                  | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| ADXPD_Reset                      | cri/libadxe/adx_xpnd.c                               | cri      |                 |
| adxb_DefAddWr                    | cri/libadxe/adx_bsc.c                                | cri      | ✅               |
| adxsjd_decexec_end               | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXB_GetDecDtLen                 | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXB_GetDecNumSmpl               | cri/libadxe/adx_bsc.c                                | cri      |                 |
| ADXB_Reset                       | cri/libadxe/adx_bsc.c                                | cri      |                 |
| adxt_stat_prep                   | cri/libadxe/adx_tsvr.c                               | cri      |                 |
| ADXRNA_GetNumData                | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_GetNumData                | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| ADXRNA_GetNumRoom                | cri/libadxe/adx_rnap.c                               | cri      | ✅               |
| PS2RNA_GetNumRoom                | cri/libadxe/ps2_rna.c                                | cri      | ✅               |
| sceSifDmaStat                    | sdk/libkernl/klib.c                                  | sdk      | –               |
| Go_BGM                           | sf33rd/Source/Game/Sound3rd.c                        | sf33rd   | ✅               |
| ADXT_GetTime                     | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| ADXT_GetTimeSfreq2               | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| ADXSJD_GetDecNumSmpl             | cri/libadxe/adx_sjd.c                                | cri      | ✅               |
| ADXT_GetNumSmplObuf              | cri/libadxe/adx_tlk.c                                | cri      | ✅               |
| CAPLOGO_Move                     | sf33rd/Source/Game/DEMO00.c                          | sf33rd   | ✅               |
| njSetPaletteBankNumG             | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| ppgSetupCurrentPaletteNumber     | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| Put_char                         | sf33rd/Source/Game/DEMO00.c                          | sf33rd   | ✅               |
| njDrawTexture                    | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| ppgWriteQuadWithST_B             | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| ppgWriteQuadOnly                 | sf33rd/Source/Common/PPGFile.c                       | sf33rd   | ✅               |
| flPS2SendTextureRegister         | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flPS2psAddQueue                  | sf33rd/AcrSDK/ps2/flps2ps.c                          | sf33rd   | ✅               |
| ps2SeqsRenderQuadInit_A          | sf33rd/Source/PS2/ps2Quad.c                          | sf33rd   | ✅               |
| ps2SeqsRenderQuad_A              | sf33rd/Source/PS2/ps2Quad.c                          | sf33rd   | ✅               |
| ps2QuadTexture                   | sf33rd/Source/PS2/ps2Quad.c                          | sf33rd   | ✅               |
| flPS2ConvColor                   | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flPS2ConvScreenFZ                | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| adxt_stat_playing                | cri/libadxe/adx_tsvr.c                               | cri      |                 |
| ADXB_CopyExtraBufSte             | cri/libadxe/adx_bsc.c                                | cri      |                 |
| memcpy2                          | cri/libadxe/adx_bsc.c                                | cri      |                 |
| q_ldreq_texture_group            | sf33rd/Source/Game/texgroup.c                        | sf33rd   | ✅               |
| FadeIn                           | sf33rd/Source/Game/sc_sub.c                          | sf33rd   | ✅               |
| njColorBlendingMode              | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| njDrawPolygon2D                  | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| njdp2d_sort                      | sf33rd/Source/Game/DC_Ghost.c                        | sf33rd   | ✅               |
| ps2SeqsRenderQuad_B              | sf33rd/Source/PS2/ps2Quad.c                          | sf33rd   | ✅               |
| ps2QuadSolid                     | sf33rd/Source/PS2/ps2Quad.c                          | sf33rd   | ✅               |
| flPS2ConvScreenFX                | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| flPS2ConvScreenFY                | sf33rd/AcrSDK/ps2/flps2render.c                      | sf33rd   | ✅               |
| ADXSJD_TermSupply                | cri/libadxe/adx_sjd.c                                | cri      |                 |
| ADXB_AhxTermSupply               | cri/libadxe/adx_bahx.c                               | cri      |                 |
| ADXB_Ac3TermSupply               | cri/libadxe/adx_bahx.c                               | cri      |                 |
