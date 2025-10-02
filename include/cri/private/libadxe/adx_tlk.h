#ifndef ADX_TLK_H
#define ADX_TLK_H

#include <cri/cri_adxt.h>
#include <cri/cri_xpts.h>

void ADXT_SetDefSvrFreq(Sint32 freq);
void adxt_start_sj(ADXT adxt, SJ sj);
void adxt_start_stm(ADXT adxt, const Char8* fname, void* dir, s32 arg3, Sint32 file_sct);

#endif
