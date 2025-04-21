/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 1998-2002 CRI-MW
 *
 * Library  : CRI Middleware Library
 * Module   : CRI Common Header
 * File     : cri_xpts.h
 * Date     : 2002-09-18
 * Version  : 1.10
 *
 ****************************************************************************/
#ifndef CRI_XPTS_H
#define CRI_XPTS_H

#ifndef SEGA_XPT_H

/*****************************************************************************
 * �萔�}�N��
 *****************************************************************************/

/* NULL �|�C���^�^ */
#ifndef NULL
#ifdef __cplusplus
#define NULL	(0)
#else
#define NULL	((void *)0)
#endif
#endif

/* �_���萔�P�i�U�A�^�j */
#ifndef FALSE
#define FALSE	(0)
#endif
#ifndef TRUE
#define TRUE	(1)
#endif

/* �_���萔�Q�i�X�C�b�`�j */
#ifndef OFF
#define OFF		(0)
#endif
#ifndef ON
#define ON		(1)
#endif
                                                                                                        
/* ���ʔ���̒萔�i�����A���s�j */
#ifndef OK
#define OK		(0)			/* ���� */
#endif
#ifndef NG
#define NG		(-1)		/* ���s */
#endif

/*****************************************************************************
 * ��{�f�[�^�^�錾
 *****************************************************************************/

/*****************************************************************************
 * Uint8 Sint8 Uint16 Sint16 �Ɋւ��Ă͋���
 *****************************************************************************/

#ifndef _TYPEDEF_Uint8
#define _TYPEDEF_Uint8
typedef unsigned char			Uint8;		/* �����Ȃ��P�o�C�g���� */
#endif

#ifndef _TYPEDEF_Sint8
#define _TYPEDEF_Sint8
typedef char				    Sint8;		/* �������P�o�C�g���� */
#endif

#ifndef _TYPEDEF_Uint16
#define _TYPEDEF_Uint16
typedef unsigned short			Uint16;		/* �����Ȃ��Q�o�C�g���� */
#endif

#ifndef _TYPEDEF_Sint16
#define _TYPEDEF_Sint16
typedef signed short			Sint16;		/* �������Q�o�C�g���� */
#endif

/*****************************************************************************
 * Uint32 Sint32 Uint64 Sint64 Uint128 Sint128 �Ɋւ��Ă͌X�ɐݒ�
 *****************************************************************************/

#ifdef XPT_TGT_EE

#ifndef _TYPEDEF_Uint32
#define _TYPEDEF_Uint32
typedef unsigned int			Uint32;		/* �����Ȃ��S�o�C�g���� */
#endif

#ifndef _TYPEDEF_Sint32
#define _TYPEDEF_Sint32
typedef signed int				Sint32;		/* �������S�o�C�g���� */
#endif

#ifndef _TYPEDEF_Uint64
#define _TYPEDEF_Uint64
typedef unsigned long			Uint64;		/* �����Ȃ��W�o�C�g���� */
#endif

#ifndef _TYPEDEF_Sint64
#define _TYPEDEF_Sint64
typedef signed long				Sint64;		/* �������W�o�C�g���� */
#endif

// #ifndef _TYPEDEF_Uint128
// #define _TYPEDEF_Uint128					/* �����Ȃ�16�o�C�g���� */
// typedef unsigned int			Uint128 __attribute__ ((mode (TI)));
// #endif

// #ifndef _TYPEDEF_Sint128
// #define _TYPEDEF_Sint128					/* ������16�o�C�g���� */
// typedef int						Sint128 __attribute__ ((mode (TI)));
// #endif

#endif	/* endif XPT_TGT_EE */

#ifdef XPT_TGT_IOP

#ifndef _TYPEDEF_Uint32
#define _TYPEDEF_Uint32
typedef unsigned int			Uint32;		/* �����Ȃ��S�o�C�g���� */
#endif

#ifndef _TYPEDEF_Sint32
#define _TYPEDEF_Sint32
typedef signed int				Sint32;		/* �������S�o�C�g���� */
#endif

#endif	/* endif XPT_TGT_IOP */

#if	1	/* �����ׂẴ^�[�Q�b�g */

#ifndef _TYPEDEF_Uint32
#define _TYPEDEF_Uint32
typedef unsigned long			Uint32;		/* �����Ȃ��S�o�C�g���� */
#endif

#ifndef _TYPEDEF_Sint32
#define _TYPEDEF_Sint32
typedef signed long				Sint32;		/* �������S�o�C�g���� */
#endif

#endif /* endif �����ׂẴ^�[�Q�b�g */

/*****************************************************************************
 * Float16 Float32 �Ɋւ��Ă͂قڋ��ʁiPowerPlant�g�p���̂ݗ�O�j
 *****************************************************************************/

#ifndef _TYPEDEF_Float16
#define _TYPEDEF_Float16
typedef signed short			Float16;	/* �Q�o�C�g���� */
#endif

/* Mac����PowerPlant�g�p����Float32��Float64��MacTypes.h�Œ�`�ς� */
#ifndef __MACTYPES__

#ifndef _TYPEDEF_Float32
#define _TYPEDEF_Float32
typedef float					Float32;	/* �S�o�C�g���� */
#endif

#ifndef _TYPEDEF_Float64
#define _TYPEDEF_Float64
typedef double					Float64;	/* �W�o�C�g���� */
#endif

#endif	/* endif __MACTYPES__ */

/*****************************************************************************
 * Fixed32 Bool Char8 �Ɋւ��Ă͋���
 *****************************************************************************/

#ifndef _TYPEDEF_Fixed32
#define _TYPEDEF_Fixed32
typedef signed long				Fixed32;	/* �Œ菬���_32�r�b�g */
#endif

#ifndef _TYPEDEF_Bool
#define _TYPEDEF_Bool
typedef Sint32					Bool;		/* �_���^�i�_���萔��l�ɂƂ�j */
#endif

#ifndef _TYPEDEF_Char8
#define _TYPEDEF_Char8
typedef char					Char8;		/* �����^ */
#endif


#endif
#endif	/* CRI_XPTS_H */

/* end of file */
