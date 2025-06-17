# CRI decompilation progress

If you don't see a function in this list it doesn't need to be decompiled.

### adx_amp ✅

- [x] ADXAMP_Destroy
- [x] ADXAMP_Start
- [x] ADXAMP_Stop

### adx_bahx ✅

- [x] ADXB_SetAc3InSj
- [x] ADXB_SetAc3DecSmpl
- [x] ADXB_Ac3TermSupply
- [x] ADXB_SetAhxInSj
- [x] ADXB_SetAhxDecSmpl
- [x] ADXB_AhxTermSupply

### adx_bsc

- [x] SKG_Init
- [x] ADXB_Init
- [x] adxb_DefAddWr
- [x] ADXB_Create
- [x] ADXB_Destroy
- [ ] ADXB_DecodeHeaderAdx
- [ ] ADXB_DecodeHeader
- [x] ADXB_EntryGetWrFunc
- [ ] ADXB_GetPcmBuf
- [ ] ADXB_GetFormat
- [x] ADXB_GetSfreq
- [x] ADXB_GetNumChan
- [x] ADXB_GetOutBps
- [ ] ADXB_GetBlkSmpl
- [x] ADXB_GetTotalNumSmpl
- [ ] ADXB_GetNumLoop
- [x] ADXB_GetAinfLen
- [x] ADXB_GetDefOutVol
- [ ] adxb_get_key
- [ ] ADXB_GetStat
- [ ] ADXB_EntryData
- [ ] ADXB_Start
- [x] ADXB_Stop
- [ ] ADXB_Reset
- [ ] ADXB_GetDecDtLen
- [ ] ADXB_GetDecNumSmpl
- [ ] ADXB_EvokeExpandSte
- [ ] ADXB_EvokeDecode
- [ ] memcpy2
- [ ] ADXB_CopyExtraBufSte
- [ ] ADXB_EndDecode
- [ ] ADXB_ExecOneAdx
- [ ] ADXB_ExecHndl

### adx_crs ✅

- [x] ADXCRS_Init
- [x] ADXCRS_Lock
- [x] ADXCRS_Unlock

### adx_dcd

- [ ] ADX_GetCoefficient
- [ ] ADX_DecodeInfo
- [ ] ADX_DecodeInfoExADPCM2
- [ ] ADX_DecodeInfoExVer
- [ ] ADX_DecodeInfoExIdly
- [ ] ADX_DecodeInfoExLoop
- [ ] ADX_DecodeInfoAinf

### adx_dcd3 ✅

- [x] ADX_SetDecodeSteAsMonoSw

### adx_dcd5

- [ ] ADX_DecodeSte4AsSte
- [ ] ADX_DecodeSte4

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

### adx_fs

- [x] ADXF_CALC_BYTE2SCT
- [x] adxf_SetCmdHstry
- [x] adxf_ChkPrmPt
- [x] ADXF_LoadPartitionNw
- [x] ADXF_LoadPtNwEx
- [x] adxf_LoadPtBothNw
- [x] adxf_CloseLdptnwHn
- [x] ADXF_GetPtStat
- [ ] ADXF_GetPtStatEx
- [x] adxf_AllocAdxFs
- [x] adxf_CreateAdxFs
- [ ] adxf_SetFileInfoEx
- [x] ADXF_Open
- [x] adxf_SetAfsFileInfo
- [x] ADXF_OpenAfs
- [x] adxf_CloseSjStm
- [x] ADXF_Close
- [x] ADXF_CloseAll
- [x] adxf_read_sj32
- [x] ADXF_ReadNw32
- [x] ADXF_ReadNw
- [x] ADXF_Stop
- [x] ADXF_StopNw
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

- [x] adxt_exec_main_thrd
- [x] adxt_exec_tsvr
- [x] adxt_exec_fssvr
- [x] ADXT_Init
- [x] ADXT_Finish

### adx_lsc ✅

- [x] ADXT_EntryAfs
- [x] ADXT_StartSeamless
- [x] ADXT_GetNumFiles
- [x] ADXT_ResetEntry

### adx_mps2

- [ ] _adxm_lock
- [ ] _adxm_unlock
- [ ] adxm_safe_trap
- [ ] adxm_safe_proc
- [ ] adxm_vsync_proc
- [ ] adxm_fs_proc
- [ ] adxm_iWakeupThread
- [ ] adxm_SleepThread
- [ ] adxm_ResumeThread
- [ ] adxm_SuspendThread
- [ ] adxm_SetupSafeThrd
- [ ] adxm_SetupVsyncThrd
- [ ] adxm_SetupFsThrd
- [ ] adxm_SetupMwIdleThrd
- [ ] adxm_IsSetupThrdEx
- [x] ADXM_IsSetupThrd
- [ ] ADXM_SetupThrd
- [x] adxm_ShutdownPreProcedure
- [x] ADXM_ShutdownThrd
- [x] adxm_ShutdownMwIdleThrd
- [x] adxm_ShutdownVsyncThrd
- [x] adxm_ShutdownFsThrd
- [x] adxm_ShutdownSafeThrd
- [x] ADXM_Lock
- [x] ADXM_Unlock
- [ ] ADXPS2_ExecVint
- [x] ADXM_ExecMain
- [ ] ADXPS2_WakeupMainThrd
- [ ] ADXPS2_SetupThrd

### adx_rnap ✅

- [x] ADXPS2_SetupVoice
- [x] ADXRNA_Init
- [x] ADXRNA_Finish
- [x] ADXRNA_EntryErrFunc
- [x] ADXRNA_Create
- [x] ADXRNA_Destroy
- [x] ADXRNA_SetTransSw
- [x] ADXRNA_SetPlaySw
- [x] ADXRNA_GetNumData
- [x] ADXRNA_GetNumRoom
- [x] ADXRNA_ExecServer
- [x] ADXRNA_SetNumChan
- [x] ADXRNA_SetSfreq
- [x] ADXRNA_SetOutVol
- [x] ADXRNA_SetOutPan
- [x] ADXRNA_SetBitPerSmpl
- [x] ADXRNA_SetTotalNumSmpl

### adx_sjd

- [x] ADXSJD_Init
- [x] ADXSJD_Finish
- [x] adxsjd_clear
- [x] ADXSJD_Create
- [x] ADXSJD_Destroy
- [ ] ADXSJD_GetStat
- [x] ADXSJD_SetInSj
- [ ] ADXSJD_SetMaxDecSmpl
- [ ] ADXSJD_TermSupply
- [x] ADXSJD_Start
- [x] ADXSJD_Stop
- [ ] adxsjd_decode_prep
- [x] adxsjd_get_wr
- [ ] adxsjd_decexec_start
- [ ] adxsjd_decexec_end
- [ ] adxsjd_decode_exec
- [ ] ADXSJD_ExecHndl
- [ ] ADXSJD_ExecServer
- [x] ADXSJD_GetDecNumSmpl
- [x] ADXSJD_SetLnkSw
- [ ] ADXSJD_EntryTrapFunc
- [ ] ADXSJD_SetTrapNumSmpl
- [ ] ADXSJD_SetTrapCnt
- [ ] ADXSJD_SetTrapDtLen
- [ ] ADXSJD_GetFormat
- [x] ADXSJD_GetSfreq
- [ ] ADXSJD_GetNumChan
- [x] ADXSJD_GetOutBps
- [ ] ADXSJD_GetBlkSmpl
- [x] ADXSJD_GetTotalNumSmpl
- [ ] ADXSJD_GetNumLoop
- [x] ADXSJD_GetDefOutVol
- [ ] ADXSJD_GetDefPan

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
- [x] ADXSTM_Start
- [x] ADXSTM_Start2
- [x] ADXSTM_StopNw
- [x] ADXSTM_Stop
- [x] ADXSTM_EntryEosFunc
- [x] ADXSTM_SetEos
- [x] adxstm_sj_internal_error
- [x] adxstmf_stat_exec
- [x] ADXSTMF_ExecHndl
- [x] ADXSTM_ExecServer
- [x] ADXSTM_SetBufSize
- [x] ADXSTM_SetReqRdSize
- [x] ADXSTM_GetFileLen
- [x] ADXSTM_GetFileSct
- [x] ADXSTM_SetPause
- [x] ADXSTM_SetSj
- [x] ADXSTM_OpenCvfs

### adx_sudv ✅

- [x] adxps2_err_dvd
- [x] ADXPS2_SetupDvdFs
- [x] ADXPS2_LoadFcacheDvd

### adx_suht

- [ ] ADXPS2_SetupHostFs
- [ ] ADXPS2_LoadFcacheHost

### adx_tlk ✅

- [x] ADXT_Create
- [x] adxt_detach_ahx
- [x] adxt_detach_ac3
- [x] adxt_detach_pl2
- [x] ADXT_Destroy
- [x] adxt_start_sj
- [x] adxt_start_stm
- [x] ADXT_StopWithoutLsc
- [x] ADXT_Stop
- [x] ADXT_GetStat
- [x] ADXT_GetTimeSfreq2
- [x] adxt_time_adjust_trap
- [x] ADXT_GetTime
- [x] ADXT_SetOutVol
- [x] ADXT_SetDefSvrFreq
- [x] ADXT_GetNumSmplObuf
- [x] ADXT_ExecServer
- [x] ADXT_Pause
- [x] ADXT_GetStatPause
- [x] ADXT_GetTranspose
- [x] ADXT_SetLnkSw
- [x] ADXT_SetOutputMono

### adx_tlk2 ✅

- [x] ADXT_StartAfs
- [x] ADXT_StartMem
- [x] ADXT_StartMem2

### adx_tsvr

- [ ] adxt_set_outpan
- [ ] adxt_stat_decinfo
- [ ] adxt_stat_prep
- [ ] adxt_stat_playing
- [ ] ADXT_ExecRdErrChk
- [ ] ADXT_ExecRdCompChk
- [ ] ADXT_ExecHndl

### adx_xpnd

- [ ] ADXPD_Init
- [ ] ADXPD_Create
- [ ] ADXPD_SetCoef
- [ ] ADXPD_SetDly
- [ ] ADXPD_SetExtPrm
- [ ] ADXPD_Destroy
- [ ] ADXPD_GetStat
- [ ] ADXPD_EntrySte
- [ ] ADXPD_Start
- [ ] ADXPD_Stop
- [ ] ADXPD_Reset
- [ ] ADXPD_GetNumBlk
- [ ] ADXPD_ExecHndl

### cri_cvfs ✅

- [x] cvFsCallUsrErrFn
- [x] cvFsError
- [x] cvFsAddDev
- [x] addDevice
- [x] getDevice
- [x] toUpperStr
- [x] cvFsSetDefDev
- [x] isExistDev
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
- [x] cvFsEntryErrFunc
- [x] isNeedDevName
- [x] addDevName

### cri_srd

- [x] srd_reset_obj
- [ ] SRD_Create
- [x] SRD_Destroy
- [x] SRD_ReqRdDvd
- [x] SRD_GetStat
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

- [x] DTR_ExecHndl
- [x] DTR_GetStat
- [x] DTR_ExecServer
- [x] DTR_Create
- [x] DTR_Destroy
- [x] DTR_Start
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

- [x] dvCiGetInterface
- [x] dvci_call_errfn
- [x] dvCiCdSearchFile
- [x] dvCiExecHndl
- [x] dvCiExecServer
- [x] dvCiEntryErrFunc
- [x] dvci_to_large_to_yen
- [x] dvCiIsExistFile
- [x] dvCiGetFileSize
- [x] dvci_alloc
- [x] dvci_free
- [x] dvCiOpen
- [x] dvCiClose
- [x] dvCiSeek
- [x] dvCiTell
- [x] dvCiReqRd
- [x] dvCiStopTr
- [x] dvCiGetStat
- [x] dvCiGetSctLen
- [x] dvCiGetNumTr
- [x] dvci_getnumtr_upper
- [x] dvci_getnumtr_lower
- [ ] dvci_filesize_upper
- [ ] dvci_filesize_lower
- [ ] dvCiOptFn1

### dvci_sub

- [x] dvci_conv_fname
- [x] conv_cmp_003DC578
- [x] dvci_charicmp
- [x] dvci_stricmp
- [ ] analysis_flist_003DC6A0
- [x] load_flist
- [x] search_fstate
- [x] get_fp_from_fname
- [x] dvci_init_flist
- [x] dvci_get_fstate
- [x] dvCiLoadFcache
- [x] dvCiSetRdMode
- [ ] dvCiSetRootDir

### htci_sub ✅

- [x] htci_is_inc_colon
- [x] htci_is_bgn_host
- [x] htci_conv_fname
- [x] htci_load_flist

### lsc ✅

- [x] lsc_Alloc
- [x] LSC_Create
- [x] LSC_Destroy
- [x] LSC_SetStmHndl
- [x] LSC_EntryFileRange
- [x] LSC_ResetEntry
- [x] LSC_Start
- [x] LSC_Stop
- [x] LSC_ExecServer
- [x] LSC_GetStat
- [x] LSC_GetNumStm
- [x] LSC_SetFlowLimit

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

### lsc_svr

- [ ] lsc_ExecHndl

### ps2_rna

- [x] PS2RNA_SetupVoice
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
- [x] PS2RNA_GetNumRoom
- [x] PS2RNA_ExecHndl
- [x] PS2RNA_ExecServer
- [x] PS2RNA_SetNumChan
- [x] PS2RNA_SetSfreq
- [x] PS2RNA_SetOutVol
- [x] PS2RNA_SetOutPan
- [x] PS2RNA_SetBitPerSmpl

### rna_crs ✅

- [x] RNACRS_Lock
- [x] RNACRS_Unlock

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
- [x] SJX_ExecServer
- [x] SJX_Init
- [x] SJX_Finish
- [x] SJX_Create
- [x] SJX_Destroy

### svm ✅

- [x] svm_lock
- [x] svm_unlock
- [x] SVM_Lock
- [x] SVM_Unlock
- [x] SVM_LockVar
- [x] SVM_LockRsc
- [x] SVM_UnlockVar
- [x] SVM_UnlockRsc
- [x] SVM_CallErr
- [x] SVM_CallErr1
- [x] SVM_SetCbSvr
- [x] SVM_DelCbSvr
- [x] SVM_SetCbSvrId
- [x] SVM_SetCbBdr
- [x] SVM_SetCbLock
- [x] SVM_SetCbUnlock
- [x] SVM_ExecSvrFunc
- [x] SVM_ExecSvrVint
- [x] SVM_ExecSvrVsync
- [x] SVM_ExecSvrFs
- [x] SVM_ExecSvrMain
- [x] svm_reset_variable
- [x] SVM_Init
- [x] SVM_Finish
- [x] SVM_TestAndSet
