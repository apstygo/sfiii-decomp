# CRI decompilation progress

If you don't see a function in this list it doesn't need to be decompiled.

### adx_amp ✅

- [x] ADXAMP_Destroy
- [x] ADXAMP_Start
- [x] ADXAMP_Stop

### adx_bahx ✅

- [x] ADXB_SetAc3InSj
- [x] ADXB_SetAhxInSj

### adx_bsc ✅

- [x] SKG_Init
- [x] ADXB_Init
- [x] ADXB_Create
- [x] ADXB_Destroy
- [x] ADXB_EntryGetWrFunc
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

### adx_dcd3

- [ ] ADX_SetDecodeSteAsMonoSw

### adx_errs ✅

- [x] ADXERR_Init
- [x] ADXERR_Finish
- [x] ADXERR_CallErrFunc1
- [x] ADXERR_CallErrFunc2
- [x] ADXERR_ItoA
- [x] ADXERR_ItoA2

### adx_fcch

- [ ] ADXF_Ocbi

### adx_fini

- [ ] ADXF_Init
- [ ] ADXF_Finish

### adx_fs

- [ ] adxf_SetCmdHstry
- [ ] adxf_AllocAdxFs
- [ ] adxf_CreateAdxFs
- [ ] adxf_SetAfsFileInfo
- [x] ADXF_OpenAfs
- [ ] adxf_CloseSjStm
- [ ] ADXF_Close
- [ ] ADXF_CloseAll
- [ ] adxf_read_sj32
- [ ] ADXF_ReadNw32
- [ ] ADXF_ReadNw
- [ ] ADXF_Stop
- [ ] adxf_ExecOne
- [ ] ADXF_ExecServer
- [ ] ADXF_GetFsizeSct
- [ ] ADXF_GetStat
- [ ] adxf_ChkPrmGfr
- [ ] ADXF_GetFnameRangeEx
- [ ] ADXF_GetFnameFromPt

### adx_fsvr

- [ ] ADXT_ExecFsSvr

### adx_inis

- [ ] ADXT_Init
- [ ] ADXT_Finish

### adx_lsc ✅

- [x] ADXT_EntryAfs
- [x] ADXT_StartSeamless
- [x] ADXT_GetNumFiles
- [x] ADXT_ResetEntry

### adx_mps2

- [ ] ADXM_IsSetupThrd
- [ ] adxm_ShutdownPreProcedure
- [ ] ADXM_ShutdownThrd
- [ ] adxm_ShutdownMwIdleThrd
- [ ] adxm_ShutdownVsyncThrd
- [ ] adxm_ShutdownFsThrd
- [ ] adxm_ShutdownSafeThrd
- [ ] ADXM_Lock
- [ ] ADXM_Unlock
- [ ] ADXM_ExecMain

### adx_rnap

- [ ] ADXRNA_Init
- [ ] ADXRNA_Finish
- [ ] ADXRNA_EntryErrFunc
- [ ] ADXRNA_Create
- [ ] ADXRNA_Destroy
- [ ] ADXRNA_SetTransSw
- [ ] ADXRNA_SetPlaySw
- [ ] ADXRNA_GetNumData
- [ ] ADXRNA_SetOutVol

### adx_sjd

- [ ] ADXSJD_Init
- [ ] ADXSJD_Finish
- [ ] adxsjd_clear
- [ ] ADXSJD_Create
- [ ] ADXSJD_Destroy
- [ ] ADXSJD_SetInSj
- [ ] ADXSJD_Start
- [ ] ADXSJD_Stop
- [ ] ADXSJD_GetDecNumSmpl
- [ ] ADXSJD_SetLnkSw
- [ ] ADXSJD_GetSfreq
- [ ] ADXSJD_GetOutBps
- [ ] ADXSJD_GetTotalNumSmpl
- [ ] ADXSJD_GetDefOutVol

### adx_stmc

- [ ] ADXSTM_Init
- [ ] ADXSTM_Finish
- [ ] ADXSTMF_SetupHandleMember
- [ ] ADXSTMF_CreateCvfsRt
- [ ] ADXSTMF_CreateCvfs
- [ ] ADXSTM_Create
- [ ] ADXSTM_Destroy
- [ ] ADXSTM_BindFileNw
- [ ] ADXSTM_BindFile
- [ ] ADXSTM_ReleaseFileNw
- [ ] ADXSTM_ReleaseFile
- [ ] ADXSTM_GetStat
- [ ] ADXSTM_Seek
- [ ] ADXSTM_Tell
- [ ] adxstm_start_sub
- [ ] ADXSTM_Start2
- [ ] ADXSTM_StopNw
- [ ] ADXSTM_Stop
- [ ] ADXSTM_EntryEosFunc
- [ ] ADXSTM_SetEos
- [ ] adxstm_sj_internal_error
- [ ] adxstmf_stat_exec
- [ ] ADXSTMF_ExecHndl
- [ ] ADXSTM_ExecServer
- [ ] ADXSTM_SetReqRdSize
- [ ] ADXSTM_GetFileSct
- [ ] ADXSTM_SetPause
- [ ] ADXSTM_SetSj
- [ ] ADXSTM_OpenCvfs

### adx_sudv

- [ ] ADXPS2_LoadFcacheDvd

### adx_tlk

- [ ] ADXT_Create
- [ ] adxt_detach_ahx
- [ ] adxt_detach_ac3
- [ ] adxt_detach_pl2
- [ ] ADXT_Destroy
- [ ] adxt_start_sj
- [ ] ADXT_StopWithoutLsc
- [ ] ADXT_Stop
- [ ] ADXT_GetStat
- [ ] ADXT_GetTimeSfreq2
- [ ] adxt_time_adjust_trap
- [ ] ADXT_GetTime
- [ ] ADXT_SetOutVol
- [ ] ADXT_SetDefSvrFreq
- [ ] ADXT_GetNumSmplObuf
- [ ] ADXT_Pause
- [ ] ADXT_GetStatPause
- [ ] ADXT_SetLnkSw
- [ ] ADXT_SetOutputMono

### adx_tlk2

- [ ] ADXT_StartAfs
- [ ] ADXT_StartMem
- [ ] ADXT_StartMem2

### adx_xpnd

- [ ] ADXPD_Init
- [ ] ADXPD_Create
- [ ] ADXPD_Destroy
- [ ] ADXPD_Stop

### cri_cvfs

- [ ] cvFsCallUsrErrFn
- [ ] cvFsError
- [ ] getDevice
- [ ] toUpperStr
- [ ] cvFsGetDefDev
- [ ] variousProc
- [ ] cvFsOpen
- [ ] allocCvFsHn
- [ ] releaseCvFsHn
- [ ] getDevName
- [ ] getDefDev
- [ ] cvFsClose
- [ ] cvFsTell
- [ ] cvFsSeek
- [ ] cvFsReqRd
- [ ] cvFsExecServer
- [ ] cvFsGetStat
- [ ] isNeedDevName
- [ ] addDevName

### cri_srd

- [ ] srd_wait
- [ ] srd_wait_hst
- [ ] srd_check_dvd_error
- [ ] srd_exec_dvd
- [ ] srd_exec_hst
- [ ] SRD_ExecServer
- [ ] SRD_SetHistory
- [ ] srd_sw_lock
- [ ] srd_sw_unlock
- [ ] SRD_SceLseek
- [ ] SRD_SceIoctl
- [ ] SRD_SceOpen
- [ ] SRD_SceClose
- [ ] SRD_SceRead

### dtr

- [ ] DTR_Create
- [ ] DTR_Destroy
- [ ] DTR_Stop

### dtx

- [ ] dtx_create_rmt
- [ ] dtx_destroy_rmt
- [ ] DTX_Create
- [ ] DTX_Destroy
- [ ] DTX_SetRcvCbf
- [ ] DTX_SetSndCbf
- [ ] DTX_ExecHndl
- [ ] DTX_Init
- [ ] DTX_Finish
- [ ] DTX_CallUrpc
- [ ] DTX_ExecServer

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

### lsc_crs

- [ ] LSC_LockCrs
- [ ] LSC_UnlockCrs

### lsc_err

- [ ] LSC_EntryErrFunc
- [ ] LSC_CallErrFunc

### lsc_ini

- [ ] lsc_EntrySvrInt
- [ ] lsc_DeleteSvrInt
- [ ] LSC_Init
- [ ] LSC_Finish

### ps2_rna

- [ ] ps2rna_init_psj
- [ ] ps2rna_finish_psj
- [ ] ps2rna_get_psj
- [ ] ps2rna_release_psj
- [ ] PS2RNA_Init
- [ ] PS2RNA_InitIopSnd
- [ ] PS2RNA_FinishIopSnd
- [ ] PS2RNA_Finish
- [ ] PS2RNA_Create
- [ ] PS2RNA_Destroy
- [ ] PS2RNA_SetTransSw
- [ ] PS2RNA_SetPlaySw
- [ ] PS2RNA_SetDiscardSw
- [ ] PS2RNA_GetNumData
- [ ] PS2RNA_SetOutVol

### sj_crs

- [ ] SJCRS_Lock
- [ ] SJCRS_Unlock

### sj_mem

- [ ] SJMEM_Init
- [ ] SJMEM_Finish
- [ ] SJMEM_Create
- [ ] SJMEM_Reset

### sj_rbf

- [ ] SJRBF_Init
- [ ] SJRBF_Finish
- [ ] SJRBF_Create
- [ ] SJRBF_Reset
- [ ] SJRBF_GetBufPtr
- [ ] SJRBF_GetBufSize
- [ ] SJRBF_GetXtrSize

### sj_uni

- [ ] SJUNI_Init
- [ ] SJUNI_Finish
- [ ] SJUNI_Create
- [ ] SJUNI_Reset

### sj_utl

- [ ] SJ_SplitChunk

### sjr_clt

- [ ] SJUNI_CreateRmt
- [ ] SJRMT_Destroy
- [ ] SJRMT_Init
- [ ] SJRMT_Finish

### sjx

- [ ] SJX_Init
- [ ] SJX_Finish
- [ ] SJX_Create
- [ ] SJX_Destroy

### svm

- [ ] svm_lock
- [ ] svm_unlock
- [ ] SVM_Lock
- [ ] SVM_Unlock
- [ ] SVM_LockRsc
- [ ] SVM_UnlockRsc
- [ ] SVM_CallErr
- [ ] SVM_CallErr1
- [ ] SVM_SetCbSvr
- [ ] SVM_DelCbSvr
- [ ] SVM_SetCbSvrId
- [ ] SVM_SetCbLock
- [ ] SVM_SetCbUnlock
- [ ] SVM_ExecSvrFunc
- [ ] SVM_ExecSvrMain
- [ ] svm_reset_variable
- [ ] SVM_Init
- [ ] SVM_Finish
- [ ] SVM_TestAndSet
