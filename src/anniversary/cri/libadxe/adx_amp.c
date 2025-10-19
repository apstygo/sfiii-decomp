#include "common.h"
#include <cri/private/libadxe/adx_amp.h>
#include <cri/private/libadxe/adx_crs.h>
#include <cri/sj.h>
#include <memory.h>

s32 adxsmp_init_cnt = 0;
ADXAMP_OBJ adxamp_obj[16] = { 0 };

void ADXAMP_Init() {
    if (adxsmp_init_cnt == 0) {
        memset(&adxamp_obj, 0, sizeof(adxamp_obj));
    }

    adxsmp_init_cnt += 1;
}

void ADXAMP_Finish() {
    if (--adxsmp_init_cnt == 0) {
        memset(&adxamp_obj, 0, sizeof(adxamp_obj));
    }
}

ADXAMP ADXAMP_Create(Sint32 arg0, SJ *arg1, SJ *arg2) {
    ADXAMP amp;
    Sint32 i, j;

    for (i = 0; i < 16; i++) {
        if (adxamp_obj[i].used == 0) {
            break;
        }
    }
    
    if (i == 0x10) {
        return NULL;
    }
    
    ADXCRS_Lock();
    
    amp = &adxamp_obj[i];
    amp->unk2 = arg0;

    for (j = 0; j < arg0; j++) {
        amp->unk4[j] = arg1[j];
        amp->ExtractNumSmpl[j] = 0;
        amp->unkC[j] = arg2[j];
    }
    
    amp->unk1 = 0;
    amp->unk1C = arg0;
    amp->Sfreq = 44100;
    amp->unk2C = 0;
    amp->FrmLen = 0.099999999f;
    amp->FrmPrd = 0.099999999f;
    amp->used = 1;
    ADXCRS_Unlock();
    return amp;
}

void ADXAMP_Destroy(ADXAMP amp) {
    if (amp != NULL) {
        ADXCRS_Lock();
        memset(amp, 0, sizeof(ADXAMP_OBJ));
        ADXCRS_Unlock();
    }
}

Sint8 ADXAMP_GetStat(ADXAMP amp) {
    return amp->unk1;
}

void ADXAMP_Start(ADXAMP amp) {
    s32 i;
    SJ sj;
    SJCK ck;

    for (i = 0; i < amp->unk2; i++) {
        amp->ExtractNumSmpl[i] = 0;
    }

    amp->unk2C = 0;

    for (i = 0; i < amp->unk2; i++) {
        sj = amp->unk4[i];
        SJ_Reset(sj);
        SJ_GetChunk(sj, 0, SJ_GetNumData(sj, 0), &ck);
        memset(ck.data, 0, ck.len);
        SJ_UngetChunk(sj, 0, &ck);
    }

    for (i = 0; i < amp->unk2; i++) {
        sj = amp->unkC[i];
        SJ_Reset(sj);
        SJ_GetChunk(sj, 0, SJ_GetNumData(sj, 0), &ck);
        memset(ck.data, 0, ck.len);
        SJ_UngetChunk(sj, 0, &ck);
    }

    amp->unk1 = 2;
}

void ADXAMP_Stop(ADXAMP amp) {
    amp->unk1 = 0;
}

void adxamp_extract(ADXAMP amp) {
    SJCK sp;
    SJCK sp10;
    int temp_f1;
    int temp_a0_4;
    int var_s3;
    s32 temp_s0;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s6;
    Sint32 i, j, k;

    temp_f1 = (f32) amp->Sfreq * amp->FrmLen;
    for (i = 0; i < amp->unk1C; i++) {
        temp_s0 = SJ_GetNumData(amp->unk4[i], 1) / 2 / temp_f1;
        temp_v1 = SJ_GetNumData(amp->unkC[i], 0) / 16;
        var_s6 = (temp_s0 < temp_v1) ? temp_s0 : temp_v1;
        
        for (k = 0; k < var_s6; k++) {
            var_s0 = 0;
            var_s3 = 0;
            while (var_s0 < temp_f1) {
                int len;
                short* p;
                
                SJ_GetChunk(amp->unk4[i], 1, (temp_f1 - var_s0) * 2, &sp);
                len = sp.len / 2;
                p = (short*)sp.data;
                for (j = 0; j < len; j++) {
                    temp_a0_4 = *p++;
                    if (temp_a0_4 < 0) {
                        temp_a0_4 = -temp_a0_4;
                    }
                    var_s3 = (var_s3 < temp_a0_4) ? temp_a0_4 : var_s3;
                }
                
                var_s0 += len;
                SJ_PutChunk(amp->unk4[i], 0, &sp);
            }
            
            SJ_GetChunk(amp->unkC[i], 0, 0x10, &sp10);
            if (sp10.len == 0) {
                while(1);
            }

            // TODO: ?
            ((int*)sp10.data)[0] = var_s3;
            ((int*)sp10.data)[1] = amp->ExtractNumSmpl[i];
            ((int*)sp10.data)[2] = amp->Sfreq;
            ((int*)sp10.data)[3] = temp_f1;
            SJ_PutChunk(amp->unkC[i], 1, &sp10);
            amp->ExtractNumSmpl[i] += temp_f1;
            amp->unk2C += 1;
        }
    }
    
    return;
}

void ADXAMP_ExecHndl(ADXAMP amp) {
    if (amp->unk1 == 2) {
        adxamp_extract(amp);
    }
}

void ADXAMP_ExecServer(void) {
    Sint32 i;
    
    for (i = 0; i < 16; i++) {
        if (adxamp_obj[i].used == 1) {
            ADXAMP_ExecHndl(&adxamp_obj[i]);
        }
    }
}

s32 ADXAMP_GetExtractNumSmpl(ADXAMP amp) {
    return amp->ExtractNumSmpl[0];
}

void ADXAMP_SetSfreq(ADXAMP amp, Sint32 sfreq) {
    amp->Sfreq = sfreq;
}

Sint32 ADXAMP_GetSfreq(ADXAMP amp) {
    return amp->Sfreq;
}

void ADXAMP_SetFrmLen(ADXAMP amp, Float32 frmLen) {
    amp->FrmLen = frmLen;
}

Float32 ADXAMP_GetFrmLen(ADXAMP amp) {
    return amp->FrmLen;
}

void ADXAMP_SetFrmPrd(ADXAMP amp, Float32 frmPrd) {
    amp->FrmPrd = frmPrd;
}

Float32 ADXAMP_GetFrmPrd(ADXAMP amp) {
    return amp->FrmPrd;
}
