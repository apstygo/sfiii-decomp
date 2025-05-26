#ifndef OBJTEST_H
#define OBJTEST_H

#include "structs.h"
#include "types.h"

#define OT_PULREQ_MAX 51
#define OT_PULPARA_MAX 53
#define OT_PULREQ_XX_MAX 32

extern PPWORK_SUB_SUB ot_pulreq_xx[OT_PULREQ_XX_MAX];
extern PULREQ ot_pulreq[OT_PULREQ_MAX];
extern PULPARA ot_pulpara[OT_PULPARA_MAX];

void ot_make_curr_vib_data();

#endif
