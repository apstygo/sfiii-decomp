# CRI decompilation progress

If you don't see a function in this list it doesn't need to be decompiled.

### adx_amp ✅

- [x] ADXAMP_Destroy
- [x] ADXAMP_Start
- [x] ADXAMP_Stop

### adx_bahx ✅

- [x] ADXB_SetAc3InSj
- [x] ADXB_SetAhxInSj

### adx_bsc

- [x] SKG_Init
- [x] ADXB_Init
- [x] ADXB_Create
- [x] ADXB_Destroy
- [x] ADXB_EntryGetWrFunc
- [ ] ADXB_GetPcmBuf
- [x] ADXB_GetSfreq
- [x] ADXB_GetOutBps
- [x] ADXB_GetTotalNumSmpl
- [x] ADXB_GetAinfLen
- [x] ADXB_GetDefOutVol
- [x] ADXB_Stop

### adx_crs ✅

- [x] ADXCRS_Init
- [x] ADXCRS_Lock
- [x] ADXCRS_Unlock

### adx_dcd

- [ ] ADX_GetCoefficient

### adx_dcd3 ✅

- [x] ADX_SetDecodeSteAsMonoSw

### adx_errs ✅

- [x] ADXERR_Init
- [x] ADXERR_Finish
- [x] ADXERR_CallErrFunc1
- [x] ADXERR_CallErrFunc2
- [x] ADXERR_ItoA
- [x] ADXERR_ItoA2

### adx_fcch ✅

- [x] ADXF_Ocbi

### adx_fini ✅

- [x] ADXF_Init
- [x] ADXF_Finish

### adx_fs ✅

- [x] adxf_SetCmdHstry
- [x] adxf_AllocAdxFs
- [x] adxf_CreateAdxFs
- [x] adxf_SetAfsFileInfo
- [x] ADXF_OpenAfs
- [x] adxf_CloseSjStm
- [x] ADXF_Close
- [x] ADXF_CloseAll
- [x] adxf_read_sj32
- [x] ADXF_ReadNw32
- [x] ADXF_ReadNw
- [x] ADXF_Stop
- [x] adxf_ExecOne
- [x] ADXF_ExecServer
- [x] ADXF_GetFsizeSct
- [x] ADXF_GetStat
- [x] adxf_ChkPrmGfr
- [x] ADXF_GetFnameRangeEx
- [x] ADXF_GetFnameFromPt

### adx_fsvr ✅

- [x] ADXT_ExecFsSvr

### adx_inis ✅

- [x] ADXT_Init
- [x] ADXT_Finish

### adx_lsc ✅

- [x] ADXT_EntryAfs
- [x] ADXT_StartSeamless
- [x] ADXT_GetNumFiles
- [x] ADXT_ResetEntry

### adx_mps2 ✅

- [x] ADXM_IsSetupThrd
- [x] adxm_ShutdownPreProcedure
- [x] ADXM_ShutdownThrd
- [x] adxm_ShutdownMwIdleThrd
- [x] adxm_ShutdownVsyncThrd
- [x] adxm_ShutdownFsThrd
- [x] adxm_ShutdownSafeThrd
- [x] ADXM_Lock
- [x] ADXM_Unlock
- [x] ADXM_ExecMain

### adx_rnap ✅

- [x] ADXRNA_Init
- [x] ADXRNA_Finish
- [x] ADXRNA_EntryErrFunc
- [x] ADXRNA_Create
- [x] ADXRNA_Destroy
- [x] ADXRNA_SetTransSw
- [x] ADXRNA_SetPlaySw
- [x] ADXRNA_GetNumData
- [x] ADXRNA_SetOutVol

### adx_sjd ✅

- [x] ADXSJD_Init
- [x] ADXSJD_Finish
- [x] adxsjd_clear
- [x] ADXSJD_Create
- [x] ADXSJD_Destroy
- [x] ADXSJD_SetInSj
- [x] ADXSJD_Start
- [x] ADXSJD_Stop
- [x] adxsjd_get_wr
- [x] ADXSJD_GetDecNumSmpl
- [x] ADXSJD_SetLnkSw
- [x] ADXSJD_GetSfreq
- [x] ADXSJD_GetOutBps
- [x] ADXSJD_GetTotalNumSmpl
- [x] ADXSJD_GetDefOutVol

### adx_stmc ✅

- [x] ADXSTM_Init
- [x] ADXSTM_Finish
- [x] ADXSTMF_SetupHandleMember
- [x] ADXSTMF_CreateCvfsRt
- [x] ADXSTMF_CreateCvfs
- [x] ADXSTM_Create
- [x] ADXSTM_Destroy
- [x] ADXSTM_BindFileNw
- [x] ADXSTM_BindFile
- [x] ADXSTM_ReleaseFileNw
- [x] ADXSTM_ReleaseFile
- [x] ADXSTM_GetStat
- [x] ADXSTM_Seek
- [x] ADXSTM_Tell
- [x] adxstm_start_sub
- [x] ADXSTM_Start2
- [x] ADXSTM_StopNw
- [x] ADXSTM_Stop
- [x] ADXSTM_EntryEosFunc
- [x] ADXSTM_SetEos
- [x] adxstm_sj_internal_error
- [x] adxstmf_stat_exec
- [x] ADXSTMF_ExecHndl
- [x] ADXSTM_ExecServer
- [x] ADXSTM_SetReqRdSize
- [x] ADXSTM_GetFileSct
- [x] ADXSTM_SetPause
- [x] ADXSTM_SetSj
- [x] ADXSTM_OpenCvfs

### adx_sudv ✅

- [x] ADXPS2_LoadFcacheDvd

### adx_tlk ✅

- [x] ADXT_Create
- [x] adxt_detach_ahx
- [x] adxt_detach_ac3
- [x] adxt_detach_pl2
- [x] ADXT_Destroy
- [x] adxt_start_sj
- [x] ADXT_StopWithoutLsc
- [x] ADXT_Stop
- [x] ADXT_GetStat
- [x] ADXT_GetTimeSfreq2
- [x] adxt_time_adjust_trap
- [x] ADXT_GetTime
- [x] ADXT_SetOutVol
- [x] ADXT_SetDefSvrFreq
- [x] ADXT_GetNumSmplObuf
- [x] ADXT_Pause
- [x] ADXT_GetStatPause
- [x] ADXT_SetLnkSw
- [x] ADXT_SetOutputMono

### adx_tlk2 ✅

- [x] ADXT_StartAfs
- [x] ADXT_StartMem
- [x] ADXT_StartMem2

### adx_xpnd

- [ ] ADXPD_Init
- [ ] ADXPD_Create
- [ ] ADXPD_Destroy
- [ ] ADXPD_Stop

### cri_cvfs ✅

- [x] cvFsCallUsrErrFn
- [x] cvFsError
- [x] getDevice
- [x] toUpperStr
- [x] cvFsGetDefDev
- [x] variousProc
- [x] cvFsOpen
- [x] allocCvFsHn
- [x] releaseCvFsHn
- [x] getDevName
- [x] getDefDev
- [x] cvFsClose
- [x] cvFsTell
- [x] cvFsSeek
- [x] cvFsReqRd
- [x] cvFsExecServer
- [x] cvFsGetStat
- [x] isNeedDevName
- [x] addDevName

### cri_srd ✅

- [x] srd_wait
- [x] srd_wait_hst
- [x] srd_check_dvd_error
- [x] srd_exec_dvd
- [x] srd_exec_hst
- [x] SRD_ExecServer
- [x] SRD_SetHistory
- [x] srd_sw_lock
- [x] srd_sw_unlock
- [x] SRD_SceLseek
- [x] SRD_SceIoctl
- [x] SRD_SceOpen
- [x] SRD_SceClose
- [x] SRD_SceRead

### dtr ✅

- [x] DTR_Create
- [x] DTR_Destroy
- [x] DTR_Stop

### dtx ✅

- [x] dtx_create_rmt
- [x] dtx_destroy_rmt
- [x] dtx_def_rcvcbf
- [x] dtx_def_sndcbf
- [x] DTX_Create
- [x] DTX_Destroy
- [x] DTX_SetRcvCbf
- [x] DTX_SetSndCbf
- [x] DTX_ExecHndl
- [x] DTX_Init
- [x] DTX_Finish
- [x] DTX_CallUrpc
- [x] DTX_ExecServer

### dvci

- [ ] dvci_call_errfn
- [ ] dvCiCdSearchFile
- [ ] dvci_to_large_to_yen

### dvci_sub

- [ ] dvci_conv_fname
- [ ] analysis_flist_003DC6A0
- [ ] load_flist
- [ ] search_fstate
- [ ] dvci_init_flist
- [ ] dvCiLoadFcache

### htci_sub

- [ ] htci_is_inc_colon
- [ ] htci_is_bgn_host
- [ ] htci_conv_fname
- [ ] htci_load_flist

### lsc

- [ ] lsc_Alloc
- [ ] LSC_Create
- [ ] LSC_Destroy
- [ ] LSC_SetStmHndl
- [ ] LSC_EntryFileRange
- [ ] LSC_ResetEntry
- [ ] LSC_Start
- [ ] LSC_Stop
- [ ] LSC_GetNumStm
- [ ] LSC_SetFlowLimit

### lsc_crs ✅

- [x] LSC_LockCrs
- [x] LSC_UnlockCrs

### lsc_err ✅

- [x] LSC_EntryErrFunc
- [x] LSC_CallErrFunc

### lsc_ini ✅

- [x] lsc_EntrySvrInt
- [x] lsc_DeleteSvrInt
- [x] LSC_Init
- [x] LSC_Finish

### ps2_rna

- [x] ps2rna_init_psj
- [x] ps2rna_finish_psj
- [x] ps2rna_get_psj
- [x] ps2rna_release_psj
- [x] ps2rna_rcvcbf
- [ ] ps2rna_sndcbf
- [x] PS2RNA_Init
- [x] PS2RNA_InitIopSnd
- [x] PS2RNA_FinishIopSnd
- [x] PS2RNA_Finish
- [x] PS2RNA_Create
- [x] PS2RNA_Destroy
- [x] PS2RNA_SetTransSw
- [x] PS2RNA_SetPlaySw
- [x] PS2RNA_SetDiscardSw
- [x] PS2RNA_GetNumData
- [x] PS2RNA_SetOutVol

### sj_crs ✅

- [x] SJCRS_Lock
- [x] SJCRS_Unlock

### sj_mem ✅

- [x] SJMEM_Error
- [x] SJMEM_Init
- [x] SJMEM_Finish
- [x] SJMEM_Create
- [x] SJMEM_Destroy
- [x] SJMEM_GetUuid
- [x] SJMEM_EntryErrFunc
- [x] SJMEM_Reset
- [x] SJMEM_GetNumData
- [x] SJMEM_GetChunk
- [x] SJMEM_PutChunk
- [x] SJMEM_UngetChunk
- [x] SJMEM_IsGetChunk

### sj_rbf ✅

- [x] SJRBF_Error
- [x] SJRBF_Init
- [x] SJRBF_Finish
- [x] SJRBF_Create
- [x] SJRBF_Destroy
- [x] SJRBF_GetUuid
- [x] SJRBF_EntryErrFunc
- [x] SJRBF_Reset
- [x] SJRBF_GetNumData
- [x] SJRBF_GetChunk
- [x] SJRBF_PutChunk
- [x] SJRBF_UngetChunk
- [x] SJRBF_IsGetChunk
- [x] SJRBF_GetBufPtr
- [x] SJRBF_GetBufSize
- [x] SJRBF_GetXtrSize

### sj_uni ✅

- [x] SJUNI_Error
- [x] SJUNI_Init
- [x] SJUNI_Finish
- [x] SJUNI_Create
- [x] SJUNI_Destroy
- [x] SJUNI_GetUuid
- [x] SJUNI_EntryErrFunc
- [x] SJUNI_Reset
- [x] SJUNI_GetNumData
- [x] SJUNI_GetChunk
- [x] SJUNI_PutChunk
- [x] SJUNI_UngetChunk
- [x] SJUNI_IsGetChunk

### sj_utl ✅

- [x] SJ_SplitChunk

### sjr_clt ✅

- [x] SJUNI_CreateRmt
- [x] SJRMT_Destroy
- [x] SJRMT_Init
- [x] SJRMT_Finish

### sjx ✅

- [x] sjx_rcvcbf
- [x] sjx_sndcbf
- [x] SJX_Init
- [x] SJX_Finish
- [x] SJX_Create
- [x] SJX_Destroy

### svm ✅

- [x] svm_lock
- [x] svm_unlock
- [x] SVM_Lock
- [x] SVM_Unlock
- [x] SVM_LockRsc
- [x] SVM_UnlockRsc
- [x] SVM_CallErr
- [x] SVM_CallErr1
- [x] SVM_SetCbSvr
- [x] SVM_DelCbSvr
- [x] SVM_SetCbSvrId
- [x] SVM_SetCbLock
- [x] SVM_SetCbUnlock
- [x] SVM_ExecSvrFunc
- [x] SVM_ExecSvrMain
- [x] svm_reset_variable
- [x] SVM_Init
- [x] SVM_Finish
- [x] SVM_TestAndSet
