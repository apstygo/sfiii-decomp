#ifndef ADX_FINI_H
#define ADX_FINI_H

#include "types.h"
#include <cri/cri_adxf.h>

extern ADX_FS adxf_obj[ADXF_OBJ_MAX];
extern s32 adxf_ocbi_fg;
extern ADXF_CMD_HSTRY adxf_cmd_hstry[ADXF_CMD_HSTRY_MAX];
extern s16 adxf_cmd_ncall[ADXF_CMD_NUM_MAX];
extern s32 adxf_hstry_no;
extern ADXF adxf_ldptnw_hn;
extern s32 adxf_ldptnw_ptid;

#endif
