#ifndef ADX_FINI_H
#define ADX_FINI_H

#include <cri/cri_adxf.h>
#include <cri/cri_xpts.h>

extern ADX_FS adxf_obj[ADXF_OBJ_MAX];
extern ADXF_PTINFO* adxf_ptinfo[ADXF_PART_MAX];
extern Sint32 adxf_ocbi_fg;
extern ADXF_CMD_HSTRY adxf_cmd_hstry[ADXF_CMD_HSTRY_MAX];
extern Sint16 adxf_cmd_ncall[ADXF_CMD_NUM_MAX];
extern Sint32 adxf_hstry_no;
extern ADXF adxf_ldptnw_hn;
extern Sint32 adxf_ldptnw_ptid;
extern Sint32 adxf_flno;

#endif
