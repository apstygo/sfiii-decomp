#ifndef _CRI_ADXF_H_INCLUDED
#define _CRI_ADXF_H_INCLUDED
/****************************************************************************/
/*																			*/
/*			$title$ �`�c�w�t�@�C���V�X�e�� ���C�u����						*/
/*				ADXF (ADX File System) Library */
/*																			*/
/*				1998.7.3		written by S.Hosaka
 */
/*																			*/
/****************************************************************************/

/****************************************************************************/
/*      �C���N���[�h�t�@�C�� */
/*      Include file */
/****************************************************************************/

#include "cri/ee/cri_xpt.h"
#include "sj.h"

/****************************************************************************/
/*		�萔�}�N��
 */
/*		MACRO CONSTANT
 */
/****************************************************************************/

/*	Version number of ADX File System	*/
#define ADXF_VER "6.33"

/*	�t�@�C�����̕�����				*/
/*	Maximum number of file name strings	*/
#define ADXF_FNAME_MAX (256)

/*	�ő�p�[�e�B�V������				*/
/*	Maximum number of partition			*/
#define ADXF_PART_MAX (256)

/*	�ő�t�@�C����						*/
/*	Maximum number of file				*/
#define ADXF_FILE_MAX (65536)

/*	ADXF�n���h���I�u�W�F�N�g�̌�		*/
/*	Maximum number of ADXF handle		*/
#define ADXF_OBJ_MAX (16)

/*	�n���h���̏��						*/
/*	Status of handle					*/
#define ADXF_STAT_STOP (1)    /*	��~��						*/
                              /*	During standstill			*/
#define ADXF_STAT_READING (2) /*	�f�[�^�ǂݍ��ݒ�			*/
                              /*	During data read-in			*/
#define ADXF_STAT_READEND (3) /*	�f�[�^�ǂݍ��ݏI��			*/
                              /*	Data read-in end			*/
#define ADXF_STAT_ERROR (4)   /*	�ǂݍ��݃G���[����			*/
                              /*	Read-in error outbreak state*/

/*	�V�[�N�^�C�v						*/
/*	Type of seek						*/
#define ADXF_SEEK_SET (0) /*	�t�@�C���̐擪				*/
                          /*	The beginning of file		*/
#define ADXF_SEEK_CUR (1) /*	���݂̈ʒu					*/
                          /*	The current position		*/
#define ADXF_SEEK_END (2) /*	�t�@�C���̏I�[				*/
                          /*	The end of file				*/

/*	�G���[�R�[�h						*/
/*	Error code							*/
#define ADXF_ERR_OK (0)        /*	����I��					*/
                               /*	Successful					*/
#define ADXF_ERR_FATAL (-1)    /*	�O���̃G���[				*/
                               /*	Fatal error					*/
#define ADXF_ERR_INTERNAL (-2) /*	�����̃G���[				*/
                               /*	Internal error				*/
#define ADXF_ERR_PRM (-3)      /*	�s���ȃp�����[�^			*/
                               /*	Illegal parameter			*/
#define ADXF_ERR_AFS_FILE (-4) /*	�s����AFS�t�@�C��			*/
                               /*	Illegal AFS file			*/
#define ADXF_ERR_FSIZE (-5)    /*	�t�@�C���T�C�Y���擾		*/
                               /*	Cannot get file size yet	*/

/*	����l								*/
/*	Default value						*/
#define ADXF_DEF_SCT_SIZE (2048) /*	CD-ROM�̃Z�N�^�T�C�Y		*/
                                 /*	Sector size in CD-ROM		*/
#ifdef __EE__
#define ADXF_DEF_DMA_ALIGN (64) /*	DMA�̃A���C�����g			*/
                                /*	Alignment of DMA transfer	*/
#define ADXF_DEF_ALIGN_CALC (0xFFFFFFC0)

#else

#define ADXF_DEF_DMA_ALIGN (32) /*	DMA�̃A���C�����g			*/
/*	Alignment of DMA transfer	*/
#define ADXF_DEF_ALIGN_CALC (0xFFFFFFE0)
#endif

#define ADXF_DEF_REQ_RD_SCT (512) /*	���[�h���N�G�X�g�T�C�Y		*/
                                  /*	read request size			*/

/*	�f�o�b�O�p	*/
/*	for Debug	*/
// #define	ADXF_CMD_HSTRY_MAX		(256)		/*	�R�}���h�����̌�
// */
#define ADXF_CMD_HSTRY_MAX (16) /*	�R�}���h�����̌�			*/
                                /*	Number of command history	*/

#define ADXF_CMD_OPEN (1)      /*	ADXF_Open					*/
#define ADXF_CMD_OPEN_AFS (2)  /*	ADXF_OpenAfs				*/
#define ADXF_CMD_CLOSE (3)     /*	ADXF_Close					*/
#define ADXF_CMD_READ_NW32 (4) /*	ADXF_ReadNw32				*/
#define ADXF_CMD_STOP (5)      /*	ADXF_Stop					*/
#define ADXF_CMD_SEEK (6)      /*	ADXF_Seek					*/
#define ADXF_CMD_STOP_NW (7)   /*	ADXF_StopNw					*/

#define ADXF_CMD_NUM_MAX (16)

/****************************************************************************/
/*		�񋓒萔
 */
/*		Enumarate Constants
 */
/****************************************************************************/

/****************************************************************************/
/*		�����}�N��
 */
/*		Process MACRO
 */
/****************************************************************************/

/*	�p�[�e�B�V�������ɕK�v�ȗ̈�̌v�Z						*/
/*	Calculation of necessary area for partition information		*/
//	"6"�́Aadxf_ptinfo�̃����o�[��(adxf_ptinfo+size+nfile+nentry+type+rev+curdir+ofst)
#define ADXF_PTIF_CMN_SZ ((6 * sizeof(Sint32)) + (ADXF_FNAME_MAX * sizeof(Sint8)))

#define ADXF_CALC_PTINFO_REAL_SIZE(n) (ADXF_PTIF_CMN_SZ + (((n) + 1) * sizeof(Sint16)))

#define ADXF_CALC_PTINFO_SIZE(n) ((ADXF_CALC_PTINFO_REAL_SIZE(n) + sizeof(Sint16)) / 4 * 4)

#define ADXF_CALC_ADD_PTINFO_SIZE(n) (ADXF_PTIF_CMN_SZ + ((n) * (2 * sizeof(Sint16) + sizeof(Sint32))))

/*	���[�h�p�[�e�B�V�����p�e���|�����o�b�t�@�̃T�C�Y�v�Z	*/
/*	Calculation of temporary buffer size for load-partition	*/
#define ADXF_CALC_TMPBUF_SIZE(n) ((((n + 1) * 8) + (ADXF_DEF_SCT_SIZE - 1)) / ADXF_DEF_SCT_SIZE * ADXF_DEF_SCT_SIZE)

/****************************************************************************/
/*		�f�[�^�^
 */
/*      Data type declaration */
/****************************************************************************/

#ifndef ADXSTM_DEFINED
#define ADXSTM_DEFINED
typedef void *ADXSTM;
#endif

/*	ADXF�n���h��		*/
/*	ADXF handle			*/
#ifndef ADXF_DEFINED
#define ADXF_DEFINED
typedef struct _adx_fs {
    Sint8 used;       /* offset 0x0, size 0x1 */ /*	�g�p�����ۂ�						*/
    Sint8 stat;       /* offset 0x1, size 0x1 */ /*	�n���h���̏��						*/
    Sint8 sjflag;     /* offset 0x2, size 0x1 */ /*	�O������ݒ肳�ꂽSJ���ۂ�			*/
    Sint8 stopnw_flg; /* offset 0x3, size 0x1 */ /*	��~�v���t���O						*/
    ADXSTM stm;       /* offset 0x4, size 0x4 */ /*	ADXSTM�n���h��						*/
    SJ sj;            /* offset 0x8, size 0x4 */ /*	�X�g���[���W���C���g				*/
    Sint32 fnsct;     /* offset 0xC, size 0x4 */ /*	�t�@�C���T�C�Y(�Z�N�^)				*/
    Sint32 fsize;     /* offset 0x10, size 0x4 */ /*	�t�@�C���T�C�Y(�o�C�g)				*/
    Sint32 skpos;     /* offset 0x14, size 0x4 */ /*	�A�N�Z�X�|�C���^�̈ʒu				*/
    Sint32 rdstpos;   /* offset 0x18, size 0x4 */ /*	�ǂݍ��݊J�n�ʒu					*/
    Sint32 rqsct;     /* offset 0x1C, size 0x4 */ /*	�ǂݍ��ݗv���f�[�^��(�Z�N�^)		*/
    Sint32 rdsct;     /* offset 0x20, size 0x4 */ /*	�ǂݍ��񂾃f�[�^��(�Z�N�^)			*/
    Sint8 *buf;       /* offset 0x24, size 0x4 */ /*	�o�b�t�@�̃A�h���X(�o�C�g)			*/
    Sint32 bsize;     /* offset 0x28, size 0x4 */ /*	�o�b�t�@�̃T�C�Y(�o�C�g)			*/
    Sint32 rqrdsct;   /* offset 0x2C, size 0x4 */ /*	���ۂɓǂݍ��ݗv��������(�Z�N�^)	*/
    /*	ADXSTM_OpenRange -> ADXSTM_OpenFileRange(1999.8.19)	*/
    Sint32 ofst;      /* offset 0x30, size 0x4 */ /*	�ǂݍ��݃t�@�C���ւ̃I�t�Z�b�g		*/
                 //	Sint8	fname[ADXF_FNAME_MAX];	/*	�t�@�C����							*/
    void *dir;             /* offset 0x34, size 0x4 */ 
    const Char8* unk38;    /* offset 0x38, size 0x4 */ 
    Sint32 unk3C;          /* offset 0x3C, size 0x4 */ 
    Sint32 unk40;          /* offset 0x40, size 0x4 */ 
} ADX_FS;
typedef ADX_FS *ADXF;
#endif

/*	�p�[�e�B�V�������		*/
/*	Partition information	*/
#ifndef ADXF_PTINFO_DEFINED
#define ADXF_PTINFO_DEFINED
typedef struct _adxf_ptinfo {
    /* 0x000 */ struct _adxf_ptinfo *next;   /*	���̃p�[�e�B�V����(NULL:�I���W�i��)	*/
    /* 0x004 */ Sint32 size;                 /*	�p�[�e�B�V�������̈�T�C�Y		*/
    /* 0x008 */ Sint32 nfile;                /*	�p�[�e�B�V�������̃t�@�C����		*/
    /* 0x00C */ Uint16 nentry;               /*	�p�[�e�B�V�������̓o�^�t�@�C����	*/
    /* 0x00E */ Sint8 type;                  /*	�I���W�i�����ǋL���̃t���O			*/
    /* 0x00F */ Sint8 rev;                   /*	�\��̈�							*/
    /* 0x010 */ Sint8 fname[ADXF_FNAME_MAX]; /*	AFS�t�@�C����			*/
    /* 0x110 */ void *curdir;                /*	�J�����g�f�B���N�g��(NULL:�w��Ȃ�)	*/
    /* 0x114 */ Sint32 ofst;                 /*	����qAFS�t�@�C���p					*/
    /* 0x118 */ Sint32 top;                  /*	�t�@�C�����̐擪					*/
} ADXF_PTINFO; /* 0x11C */
#endif

/*	�ǋL�t�@�C���̏��				*/
/*	Information of postscript file	*/
#ifndef ADXF_ADD_DEFINED
#define ADXF_ADD_DEFINED
typedef struct _adxf_add_info {
    Uint16 flid;  /*	�t�@�C��ID							*/
    Uint16 fnsct; /*	�t�@�C���T�C�Y						*/
    Sint32 ofst;  /*	�I�t�Z�b�g							*/
} ADXF_ADD_INFO;
#endif

#ifndef ADXF_CMD_HSTRY_DEFINED
#define ADXF_CMD_HSTRY_DEFINED
typedef struct _adxf_cmd_hstry {
    Uint8 cmdid;   /*	�R�}���h(�֐�)ID					*/
    Uint8 fg;      /*	�֐��̓�������o�����������t���O	*/
    Uint16 ncall;  /*	�R�}���h�̌Ăяo����				*/
    Sint32 prm[3]; /*	�R�}���h�p�����[�^					*/
} ADXF_CMD_HSTRY;
#endif

/****************************************************************************/
/*		�ϐ��錾
 */
/*		Variable Declaration */
/****************************************************************************/

/****************************************************************************/
/*		�֐��̐錾
 */
/*      Function Declaration */
/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*==========================================================================
                ���C�u�����̏������ƏI������
                Initialize and Finalize of Library
  ==========================================================================*/

/*  ���C�u�����̏�����
 * [���@��] void ADXF_Init( void );
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ���C�u����������������B
 *  Initialization of library
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Initializes library.
 */
void ADXF_Init(void);

/* ���C�u�����̏I������
 * [���@��] void ADXF_Finish(void);
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ���C�u�����̏I������������B
 *  Termination of library
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Finalizes library.
 */
void ADXF_Finish(void);

/*  �������A�^�p�[�e�B�V�����̃��[�h
 * [���@��] Sint32 ADXF_LoadPartitionNw(Sint32 ptid, Sint8 *fname,
 * 													void *dir, void
 **ptinfo); [���@��] ptid	:�p�[�e�B�V����ID fname	:AFS�t�@�C���̖��O dir		:�f�B���N�g�����
 *(GDFS:GDFS_DIRREC) ptinfo	:�p�[�e�B�V�������ǂݍ��ݗ̈� [�o�@��] �Ȃ� [�֐��l] �G���[�R�[�h [�@�@�\]
 *AFS�t�@�C����ǂݍ���ŁA�p�[�e�B�V����ID�ɐݒ肷��B Load of the partition(No wait) [Inputs  ] ptid   :Partition ID fname
 *:Name of AFS file dir	 :Directory information (GDFS:GDFS_DIRREC) ptinfo :Area of partition information [Outputs ] None
 * [Return  ] Error code
 * [Function] Loads AFS file and sets partition ID.
 */
Sint32 ADXF_LoadPartitionNw(Sint32 ptid, Char8 *fname, void *dir, void *ptinfo);

/*  �������A�^�p�[�e�B�V�����̃��[�h(����qAFS�t�@�C��)
 * [���@��] Sint32 ADXF_LoadPartitionFromPtNw(Sint32 set_ptid, Sint32 rd_ptid,
 *											Sint32 rd_flid, void *ptinfo);
 * [���@��] set_ptid
 *:���[�h����AFS�t�@�C���ɑ΂��Đݒ肷��p�[�e�B�V����ID rd_ptid
 *:�ǂݍ���AFS�t�@�C���̃p�[�e�B�V����ID rd_flid		:�ǂݍ���AFS�t�@�C���̃t�@�C��ID ptinfo
 *:�p�[�e�B�V�������ǂݍ��ݗ̈� [�o�@��] �Ȃ� [�֐��l] �G���[�R�[�h [�@�@�\]
 *AFS�t�@�C������AFS�t�@�C����ǂݍ���ŁA�p�[�e�B�V����ID�ɐݒ肷��B Load of the partition(No wait)(nested AFS file) [Inputs  ]
 *set_ptid   :Partition ID for loading and setting rd_ptid 	 :Partition ID reading AFS file rd_flid	 :File ID
 *reading AFS file ptinfo :Area of partition information [Outputs ] None [Return  ] Error code [Function] Loads AFS file
 *in AFS file and sets partition ID.
 */
Sint32 ADXF_LoadPartitionFromAfsNw(Sint32 set_ptid, Sint32 rd_ptid, Sint32 rd_flid, void *ptinfo);

/*  �������A�^�p�[�e�B�V�����̃��[�h(�ǂݍ��݃o�b�t�@���w�肷��)
 * [���@��] Sint32 ADXF_LoadPtNwEx(Sint32 ptid, Char8 *fname, void *dir, void *ptinfo,
 *									void *tmpbuf, Sint32 tbsize);
 * [���@��] ptid	:�p�[�e�B�V����ID
 *			fname	:AFS�t�@�C���̖��O
 *			dir		:�f�B���N�g����� (GDFS:GDFS_DIRREC)
 *			ptinfo	:�p�[�e�B�V�������ǂݍ��ݗ̈�
 *			tmpbuf	:AFS�t�@�C���w�b�_�ǂݍ��݃o�b�t�@
 *			tbsize	:AFS�t�@�C���w�b�_�ǂݍ��݃o�b�t�@�T�C�Y
 * [�o�@��] �Ȃ�
 * [�֐��l] �G���[�R�[�h
 * [�@�@�\] AFS�t�@�C����ǂݍ���ŁA�p�[�e�B�V����ID�ɐݒ肷��B
 *  Load of the partition(No wait)(specify reading buffer)
 * [Inputs  ] ptid		:Partition ID
 *			  fname		:Name of AFS file
 *            dir	 	:Directory information (GDFS:GDFS_DIRREC)
 *            ptinfo	:Area of partition information
 *			  tmpbuf	:Buffer reading AFS file
 *			  tbsize	:Size of buffer reading AFS file
 * [Outputs ] None
 * [Return  ] Error code
 * [Function] Loads AFS file and sets partition ID.
 */
Sint32 ADXF_LoadPtNwEx(Sint32 ptid, Char8 *fname, void *dir, void *ptinfo, void *tmpbuf, Sint32 tbsize);

/*  �������A�^�p�[�e�B�V�����̃��[�h(����qAFS�t�@�C��)(�ǂݍ��݃o�b�t�@���w�肷��ꍇ)
 * [���@��] Sint32 ADXF_LoadPtFromPtNwEx(Sint32 set_ptid, Sint32 rd_ptid, Sint32 rd_flid,
 *										void *ptinfo, void *tmpbuf, Sint32
 *tbsize); [���@��] set_ptid
 *:���[�h����AFS�t�@�C���ɑ΂��Đݒ肷��p�[�e�B�V����ID rd_ptid
 *:�ǂݍ���AFS�t�@�C���̃p�[�e�B�V����ID rd_flid		:�ǂݍ���AFS�t�@�C���̃t�@�C��ID ptinfo
 *:�p�[�e�B�V�������ǂݍ��ݗ̈� tmpbuf		:AFS�t�@�C���w�b�_�ǂݍ��݃o�b�t�@ tbsize
 *:AFS�t�@�C���w�b�_�ǂݍ��݃o�b�t�@�T�C�Y [�o�@��] �Ȃ� [�֐��l] �G���[�R�[�h [�@�@�\]
 *AFS�t�@�C������ǂݍ���ŁA�p�[�e�B�V����ID�ɐݒ肷��B Load of the partition(No wait)(nested AFS file)(specify reading buffer)
 * [Inputs  ] set_ptid	:Partition ID for loading and setting
 *			  rd_ptid	:Partition ID reading AFS file
 *            rd_flid	:File ID reading AFS file
 *            ptinfo	:Area of partition information
 *			  tmpbuf	:Buffer reading AFS file
 *			  tbsize	:Size of buffer reading AFS file
 * [Outputs ] None
 * [Return  ] Error code
 * [Function] Loads AFS file and sets partition ID.
 */
Sint32 ADXF_LoadPtFromAfsNwEx(Sint32 set_ptid, Sint32 rd_ptid, Sint32 rd_flid, void *ptinfo, void *tmpbuf,
                              Sint32 tbsize);

/*  �p�[�e�B�V�������̓ǂݍ��ݏ�Ԃ̎擾
 * [���@��] Sint32 ADXF_GetPtStat(Sint32 ptid);
 * [���@��] ptid	:�p�[�e�B�V����ID
 * [�o�@��] �Ȃ�
 * [�֐��l] �p�[�e�B�V�������̓ǂݍ��ݏ��
 * [�@�@�\] AFS�t�@�C������ǂݍ���ŁA�p�[�e�B�V����ID�ɐݒ肷��B
 *  Get partition loading state
 * [Inputs  ] ptid   :Partition ID
 * [Outputs ] None
 * [Return  ] Partition loading state
 * [Function] Gets partition loading state.
 */
Sint32 ADXF_GetPtStat(Sint32 ptid);
Sint32 ADXF_GetPtStatEx(Sint32 ptid);

/*  �p�[�e�B�V�������ǂݍ��݂̒��~
 * [���@��] void ADXF_StopPtLd(void);
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �p�[�e�B�V�������̓ǂݍ��݂𒆎~����B
 *  Stop to load partition information
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Stops to load partition information.
 */
void ADXF_StopPtLd(void);

/*  �p�[�e�B�V�������T�C�Y�̎擾
 * [���@��] Sint32 ADXF_GetPtinfoSize(Sint32 ptid);
 * [���@��] ptid	:�p�[�e�B�V����ID
 * [�o�@��] �Ȃ�
 * [�֐��l] �p�[�e�B�V�������T�C�Y(�P�ʁF�o�C�g)
 * [�@�@�\] �p�[�e�B�V�������̈�̃T�C�Y���擾����B
 *  Get size of partition information
 * [Inputs  ] ptid   :Partition ID
 * [Outputs ] None
 * [Return  ] Size of the partition information(byte)
 * [Function] Gets size of the partition information.
 */
Sint32 ADXF_GetPtinfoSize(Sint32 ptid);

/*==========================================================================
                �t�@�C���̓ǂݍ���
                Read file
  ==========================================================================*/

/*	�t�@�C���̃I�[�v��(ISO9660�̃t�@�C��)
 * [���@��] ADXF ADXF_Open(Sint8 *fname, void *atr);
 * [���@��] fname	: �t�@�C����
 *			atr		: �t�@�C���̑���
 * [�o�@��] �Ȃ�
 * [�֐��l] ADXF�n���h���A�G���[�̏ꍇNULL
 * [�@�@�\] �w��̃t�@�C�����I�[�v�����AADXF�n���h����Ԃ��B
 *  Open file(ISO9660 format)
 * [Inputs  ] fname  : File name
 *			  atr    : File attribute
 * [Outputs ] None
 * [Return  ] ADXF handle
 *			  (If the operation was unsuccessful, this function returns NULL.)
 * [Function] Opens a file of ISO9660 format.
 */
ADXF ADXF_Open(Char8 *fname, void *atr);

/*	�t�@�C���̃I�[�v��(AFS�t�H�[�}�b�g)
 * [���@��] ADXF ADXF_OpenAfs(Sint32 ptid, Sint32 flid);
 * [���@��] ptid	: �p�[�e�B�V����ID
 *			flid	: �t�@�C��ID
 * [�o�@��] �Ȃ�
 * [�֐��l] ADXF�n���h���A�G���[�̏ꍇNULL
 * [�@�@�\] �p�[�e�B�V����ID�ƃt�@�C��ID�Ŏw�肳�ꂽAFS�t�@�C�����I�[�v�����A
 *			ADXF�n���h����Ԃ��B
 *  Open file(AFS format)
 * [Inputs  ] ptid   : Partition ID
 *			  flid   : File ID
 * [Outputs ] None
 * [Return  ] ADXF handle
 *			  (If the operation was unsuccessful, this function returns NULL.)
 * [Function] Opens a file of AFS format.
 */
ADXF ADXF_OpenAfs(Sint32 ptid, Sint32 flid);

/* �t�@�C���̃N���[�Y
 * [���@��] void ADXF_Close(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �w�肳�ꂽADXF�n���h���̃t�@�C�����N���[�Y����B
 *  Close file
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Closes a file of specific ADXF handle.
 */
void ADXF_Close(ADXF adxf);

/* �S�Ẵt�@�C���N���[�Y
 * [���@��] void ADXF_CloseAll(void);
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ADXF�n���h���̃t�@�C����S�ăN���[�Y����B
 *  Close file
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Closes all file of ADXF handle.
 */
void ADXF_CloseAll(void);

/*  SJ�ւ̃f�[�^�ǂݍ��݊J�n
 * [���@��] void ADXF_ReadSj(ADXF adxf, Sint32 nsct, SJ sj);
 * [���@��] adxf	: ADXF�n���h��
 *			nsct	: �ǂݍ��݃f�[�^�̗�(�P�ʁF�Z�N�^)
 *			SJ		: �X�g���[���W���C���g
 * [�o�@��] �Ȃ�
 * [�֐��l] �ǂݍ��݃f�[�^��(�P�ʁF�Z�N�^)
 * [�@�@�\]
 *�X�g���[���W���C���g�Ƀf�[�^�ǂݍ��݂̃��N�G�X�g�𔭍s����B
 *			�X�g���[���W���C���g�̃o�b�t�@�T�C�Y�́A�Z�N�^�̐����{�łȂ����
 *			�Ȃ�Ȃ��B
 *			�X�g���[���W���C���g���烆�[�U���f�[�^��ǂݏo���ƁA�����I�ɃX�g���[
 *			���W���C���g�Ƀf�[�^���ǂݍ��܂��B
 *			���N�G�X�g�����A�N�Z�X���삪��������ƁA�A�N�Z�X�|�C���^��
 *			nsct�Z�N�^�i�ށB
 *  Read-in start to Stream Joint
 * [Inputs  ] adxf   : ADXF handle
 *			  nsct   : Number of read-in sectors to request
 *			  SJ     : Stream Joint
 * [Outputs ] None
 * [Return  ] Number of sectors to read
 * [Function] Requests data read-in to Stream Joint.
 *			  Buffer size of Stream Joint must be multiples of integer.
 *			  If you read data from Stream Joint, data are read into Stream
 *			  Joint automatically.
 *			  The access pointer moves 'nsct' sector minute when the request
 *			  was completed.
 */
Sint32 ADXF_ReadSj(ADXF adxf, Sint32 nsct, SJ sj);

/* �f�[�^�̓ǂݍ��݊J�n
 * [���@��] void ADXF_ReadNw(ADXF adxf, Sint32 nsct, void *buf);
 * [���@��] adxf	: ADXF�n���h��
 *			nsct	: �ǂݍ��݃f�[�^�̗�(�P�ʁF�Z�N�^)
 *			buf		: �ǂݍ��ݗ̈�
 * [�o�@��] �Ȃ�
 * [�֐��l] �ǂݍ��݃f�[�^��(�P�ʁF�Z�N�^)
 * [�@�@�\] �f�[�^�ǂݍ��݂̃��N�G�X�g�𔭍s����B
 *			���N�G�X�g�����A�N�Z�X���삪��������ƁA�A�N�Z�X�|�C���^��
 *			nsct�Z�N�^�i�ށB
 *  Read-in start
 * [Inputs  ] adxf   : ADXF handle
 *			  nsct   : Number of read-in sectors to request
 *			  buf    : Pointer to buffer into which the data is read
 * [Outputs ] None
 * [Return  ] Number of sectors to read
 * [Function] Requests data read-in to Stream Joint.
 *			  The access pointer moves 'nsct' sector minute when the request
 *			  was completed.
 */
Sint32 ADXF_ReadNw(ADXF adxf, Sint32 nsct, void *buf);

/* �f�[�^�̓ǂݍ��ݒ��~
 * [���@��] Sint32 ADXF_Stop(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] ���~�������_�ł̃A�N�Z�X�|�C���^�̈ʒu
 * [�@�@�\] �f�[�^�̓ǂݍ��݂𒆎~����B
 *  Read-in stop
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] The location of access pointer when you stop to read
 * [Function] Stops to read data.
 */
Sint32 ADXF_Stop(ADXF adxf);

/* �f�[�^�̓ǂݍ��ݒ��~ (�������A)
 * [���@��] Sint32 ADXF_Stop(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] ���~�����N�G�X�g���_�ł̃A�N�Z�X�|�C���^�̈ʒu
 * [�@�@�\] �f�[�^�̓ǂݍ��݂𒆎~�����N�G�X�g����B
 *			��Ԃ͂����ɂ͕ς炸�A�ǂݍ��݂��~�����Ƃ���STOP�ɕω�����
 *  Read-in stop
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] The location of access pointer when you request to stop
 * [Function] Request to Stop.
 */
Sint32 ADXF_StopNw(ADXF adxf);

/* �T�[�o�֐�
 * [���@��] void ADXF_ExecServer(void);
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ������Ԃ��X�V����B
 *  Server function
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Update the inside status of library.
 */
void ADXF_ExecServer(void);

/*==========================================================================
                �A�N�Z�X�|�C���^�̐���
                Control access pointer
  ==========================================================================*/

/*  �A�N�Z�X�|�C���^�̈ړ�
 * [���@��] Sint32 ADXF_Seek(ADXF adxf, Sint32 pos, Sint32 type);
 * [���@��] adxf	: ADXF�n���h��
 *			pos		: �A�N�Z�X�|�C���^�̈ړ���(�P�ʁF�Z�N�^)
 *			type	: �ړ��(�V�[�N�^�C�v�FADXF_SEEK_�`)
 * [�o�@��] �Ȃ�
 * [�֐��l] �A�N�Z�X�|�C���^�̈ʒu�A���̒l�̓G���[�R�[�h
 * [�@�@�\] �A�N�Z�X�|�C���^��type����pos�Z�N�^���ꂽ�ʒu�Ɉړ�������B
 *  Move access pointer
 * [Inputs  ] adxf   : ADXF handle
 *			  pos    : Offset relative to 'type'
 *			  type   : Specified the origin for the offset
 * [Outputs ] None
 * [Return  ] Location containing new seek pointer
 * [Function] Changes the seek pointer to a new location relative to the
 *			  beginning of the file, to the end of the file, or to the current
 *			  seek pointer.
 */
Sint32 ADXF_Seek(ADXF adxf, Sint32 pos, Sint32 type);

/*  �A�N�Z�X�|�C���^�̎擾
 * [���@��] Sint32 ADXF_Tell(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �A�N�Z�X�|�C���^�̈ʒu
 * [�@�@�\] �A�N�Z�X�|�C���^�̈ʒu���擾����B
 *  Get the access pointer
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] Access pointer
 * [Function] Gets the access pointer.
 */
Sint32 ADXF_Tell(ADXF adxf);

/*==========================================================================
                ���̎擾
                Get information
  ==========================================================================*/

/*  �t�@�C���T�C�Y�̎擾
 * [���@��] Sint32 ADXF_GetFsizeSct(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �t�@�C���T�C�Y(�P�ʁF�Z�N�^)
 * [�@�@�\] �w�肳�ꂽ�t�@�C���̃T�C�Y���Z�N�^�P�ʂŎ擾����B
 *  Get file size
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] File size(sector)
 * [Function] Obtains the size of the specified file.
 */
Sint32 ADXF_GetFsizeSct(ADXF adxf);

/*  �t�@�C���T�C�Y�̎擾
 * [���@��] Sint32 ADXF_GetFsizeByte(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �t�@�C���T�C�Y(�P�ʁF�o�C�g)
 * [�@�@�\] �w�肳�ꂽ�t�@�C���̃T�C�Y���o�C�g�P�ʂŎ擾����B
 *  Get file size
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] File size(byte)
 * [Function] Obtains the size of the specified file.
 */
Sint32 ADXF_GetFsizeByte(ADXF adxf);

/*  �ǂݍ��ݗv�����̎擾
 * [���@��] Sint32 ADXF_GetNumReqSct(ADXF adxf, Sint32 *seekpos);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] seekpos	: �ǂݍ��݈ʒu
 * [�֐��l] �v�������ǂݍ��݃f�[�^��(�P�ʁF�Z�N�^)
 * [�@�@�\] �v�������ǂݍ��݈ʒu�ƃf�[�^�ʂ��擾����B
 *  Get request information
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] seekpos: location of start to read
 * [Return  ] Request data size(sector)
 * [Function] Obtains read-in start position and the read-in size that
 *			  demanded.
 */
Sint32 ADXF_GetNumReqSct(ADXF adxf, Sint32 *seekpos);

/*  ���ۂɓǂݍ��񂾃Z�N�^���̎擾
 * [���@��] Sint32 ADXF_GetNumReadSct(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �ǂݍ��񂾃f�[�^��(�P�ʁF�Z�N�^)
 * [�@�@�\] ���ۂɓǂݍ��񂾃f�[�^�ʂ��擾����B
 *  Get the number of sectors read
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] Size of read data(sector)
 * [Function] Obtains the size of data that read actually.
 */
Sint32 ADXF_GetNumReadSct(ADXF adxf);

/*  �n���h���̏�Ԃ̎擾
 * [���@��] Sint32 ADXF_GetStat(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] ADXF�n���h���̓������(��ԁFADXF_STAT_�`)
 * [�@�@�\] ADXF�n���h���̓�����Ԃ��擾����B
 *  Get status of handle
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] Status of handle
 * [Function] Gets status of handle.
 */
Sint32 ADXF_GetStat(ADXF adxf);

Sint32 ADXF_GetFnameRange(Sint32 ptid, Sint32 flid, Char8 *fname, Sint32 *ofst, Sint32 *fnsct);

Sint32 ADXF_GetFnameRangeEx(Sint32 ptid, Sint32 flid, Char8 *fname, void **dir, Sint32 *ofst, Sint32 *fnsct);

/*�@���[�h���N�G�X�g�̃T�C�Y�̐ݒ�
 * [���@��] void ADXF_SetReqRdSct(ADXF adxf, Sint32 nsct);
 * [���@��] adxf    ; ADXF�n���h��
 *			nsct    ; �Z�N�^��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ���ɓǂݍ��ރT�C�Y��ݒ肵�܂��B
 *  Set size of read request
 * [Inputs  ] adxf   : ADXF handle
 *			  nsct   : size(sector)
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets size of read request(one time).
 */
void ADXF_SetReqRdSct(ADXF adxf, Sint32 nsct);

/*	�t�@�C���ǂݍ��݃X�e�[�^�X�̎擾
 * [���@��] Sint32 ADXT_GetStatRead(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] 1=�ǂݍ��ݒ��A0=�ǂݍ��ݒ�~��
 * [�@�@�\] �ǂݍ��ݏ�Ԃ��擾����
 *  Get status of data reading
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] 1=Data reading in progress,  0=Data reading stopped
 * [Function] Gets status of data reading
 */
Sint32 ADXF_GetStatRead(ADXF adxf);

/*==========================================================================
                ROFS�p
                for ROFS
  ==========================================================================*/

/* �ő啶���� */
#define ADXF_ROFS_VOLNAME_LEN (8)                         /* �{�����[�����̕����� */
#define ADXF_ROFS_VOLNAME_SIZ (ADXF_ROFS_VOLNAME_LEN + 1) /* ������T�C�Y */
#define ADXF_ROFS_FNAME_LEN (31)                          /* �t�@�C�����̕����� */
#define ADXF_ROFS_FNAME_SIZ (ADXF_ROFS_FNAME_LEN + 1)     /* ������T�C�Y */
#define ADXF_ROFS_DIRNAME_LEN (31)                        /* �f�B���N�g�����̕����� */
#define ADXF_RPFS_DIRNAME_SIZ (ADXF_ROFS_DIRNAME_LEN + 1) /* ������T�C�Y */

/* ���C�u������Ɨ̈�T�C�Y */
#define ADXF_CALC_LIBWORK_SIZ(max_open, max_volume, max_dirent)                                                        \
    (sizeof(ADXF_ROFS_WK) + ((max_open) + 1) * sizeof(ADXF_ROFS_OBJ) +                                                 \
     (ADXF_CALC_DIRREC_SIZ(max_dirent) + sizeof(ADXF_ROFS_VOL)) * ((max_volume) + 1))

/* �f�B���N�g�����R�[�h�̈�T�C�Y */
#define ADXF_CALC_DIRREC_SIZ(n_dirent)                                                                                 \
    (sizeof(ADXF_ROFS_DIRREC) - sizeof(ADXF_ROFS_DIRRECENT) + (n_dirent) * sizeof(ADXF_ROFS_DIRRECENT))

/* ���[�N�̈� */
typedef struct ADXF_ROFS_STWK ADXF_ROFS_WK;

/* �v���~�e�B�u�֐� */
typedef struct ADXF_ROFS_PFSIFTBL ADXF_ROFS_PFSTBL;

/* �f�o�C�X�R���g���[���֐� */
typedef struct ADXF_ROFS_DEVIFTBLE ADXF_ROFS_DEVTBL;

/* ���C�u�����C���^�[�t�F�[�X */
typedef struct ADXF_ROFS_LIBIFTBLE ADXF_ROFS_LIFTBL;

/* �f�B���N�g�����R�[�h�G���g�� */
typedef struct {
    Sint32 fad;                       /* fad */
    Sint32 fsize;                     /* file size */
    Uint8 flag;                       /* file attribute */
    Uint8 sid;                        /* filename search id */
    Char8 fname[ADXF_ROFS_FNAME_SIZ]; /* filename */
    Uint8 pad[6];
} ADXF_ROFS_DIRRECENT; /* 48 bytes */

/* �f�B���N�g�����R�[�h */
typedef struct {
    Sint32 dir_num;                     /* number of record */
    Sint32 max_ent;                     /* max entry of directory record */
    Sint32 dir_fad;                     /* fad of directory record */
    Char8 volname[ADXF_ROFS_FNAME_SIZ]; /* volume name */
    Sint32 pad;                         /* padding */
    ADXF_ROFS_DIRRECENT dirrec_tbl[1];  /* record table */
} ADXF_ROFS_DIRREC;
typedef ADXF_ROFS_DIRREC *ADXF_ROFS_DIRRECBUF;

/* �{�����[���Ǘ��\���� */
typedef struct {
    Char8 volname[ADXF_ROFS_VOLNAME_SIZ]; /* �{�����[���� */
    void *img_hn;                         /* �C���[�W�t�@�C���̃t�@�C���n���h�� */
    Sint32 zisb;                          /* ZONE0�C���[�W�f�[�^�J�n�ʒu */
    Sint32 ptbl_cba;                      /* cba of path table */
    Sint32 ptbl_size;                     /* size of path table */
    ADXF_ROFS_DIRRECBUF curdir;           /* current directory handle */
} ADXF_ROFS_VOL;

/* ROFS File Handle */
typedef struct {
    ADXF_ROFS_WK *wk;   /* pointer of lib work */
    Sint32 fid;         /* file id */
    Sint32 fad;         /* fad */
    Sint32 ofs;         /* offset */
    Sint32 fsize;       /* file size */
    Sint32 fsctsize;    /* sctor size of the file */
    ADXF_ROFS_VOL *vol; /* image file volume */
    Sint32 rsize;       /* reading size */
    Sint32 trns_seg;    /* �]���σu���b�N�P�� */
    Sint32 trns_ofs;    /* �]���σo�C�g�P�� */
    Sint32 trns_unit;   /* �]���P��(�u���b�N) */
    Uint8 *rdadr;       /* �ǂݍ��݃A�h���X */
    Sint16 used;        /* used flag */
    Sint16 act;         /* handle act */
    Sint16 stat;        /* handle status(ADXF_Stat) */
    Sint16 err;         /* error status */
} ADXF_ROFS_OBJ;
typedef ADXF_ROFS_OBJ *ADXF_ROFS;

/* ROFS Work Area */
struct ADXF_ROFS_STWK {
    Bool f_init;     /* �������t���O */
    Sint32 max_open; /* max open files */
    Sint32 max_volume;
    Sint32 max_dirent;
    Uint32 exec_server_cnt;                          /* counter */
    ADXF_ROFS syshdl;                                /* handle for system command */
    ADXF_ROFS hndtbl;                                /* handle */
    ADXF_ROFS_VOL *vollist;                          /* �{�����[����񃊃X�g */
    ADXF_ROFS_VOL *curvol;                           /* �J�����g�{�����[����� */
    ADXF_ROFS_DIRRECBUF dirbuf;                      /* �f�B���N�g�����R�[�h�̊J�n�ʒu */
    ADXF_ROFS_PFSTBL *pfs;                           /* �v���~�e�B�u�֐� */
    ADXF_ROFS_DEVTBL *dev;                           /* �f�o�C�X�R���g���[���֐� */
    ADXF_ROFS_LIFTBL *liftbl;                        /* ���C�u�����C���^�[�t�F�[�X */
    void (*g_errcb)(void *, Char8 *, Sint32);        /* error callback */
    void *g_errcb_1st;                               /* error callback 1st arg. */
    Uint32 sctbuf[(ADXF_DEF_SCT_SIZE * 2 + 64) / 4]; /* sector buffer */
    ADXF_ROFS_OBJ hndlist[1];                        /* handle table */
}; /* 64 + 4160 + handles */

/* ROFS�Z�b�g�A�b�v�\����  */
#ifndef ADXF_SPRM_ROFS_DEFINED
#define ADXF_SPRM_ROFS_DEFINED
typedef struct {
    Sint32 max_open;   /* �����ɃI�[�v���ł���ő�t�@�C���� */
    Sint32 max_volume; /* �����ɓo�^�ł���ő�{�����[���� */
    Sint32 max_dirent; /* �f�B���N�g���Ɋi�[����ő�t�@�C���� */
    void *rofs_work;   /* ���C�u������Ɨ̈�̐擪�A�h���X */
} ADXF_SPRM_ROFS;
#endif

/* ROFS�̃Z�b�g�A�b�v	*/
/* Setup ROFS			*/
void ADXF_SetupRofs(void *sprmr);

/* ROFS�̃V���b�g�_�E�� */
/* Shutdown ROFS		*/
void ADXF_ShutdownRofs(void);

/* ROFS�{�����[���̒ǉ�		*/
/* Addition of ROFS volume  */
Sint32 ADXF_AddRofsVol(Char8 *volname, Char8 *imgname);

/* ROFS�{�����[���̍폜 */
/* Delete ROFS volume	*/
void ADXF_DelRofsVol(Char8 *volname);

/* ROFS�{�����[�����ł��邩�ۂ� */
/* Check ROFS volume name		*/
Bool ADXF_IsRofsVol(Char8 *volname);

/* �f�t�H���g�f�o�C�X�̐ݒ� */
/* Setting default device	*/
void ADXF_SetDefDev(Char8 *volname);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _CRI_ADXF_H_INCLUDED */
