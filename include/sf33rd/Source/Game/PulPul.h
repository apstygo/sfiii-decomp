#ifndef PULPUL_H
#define PULPUL_H

#include "structs.h"
#include "types.h"

#define PULREQ_MAX 51
#define PULPARA_MAX 54

extern const u16 comm_quay_pulpul[11];
extern const s16 pp_dm_shock[8];
extern const s16 pp_guard_shock[8];
extern const s16 pp_hit_shock[8];
extern const s8 dokidoki_ix_change_table[18];
extern const PPWORK_SUB_SUB pulreq_00[1];
extern const PPWORK_SUB_SUB pulreq_01[3];
extern const PPWORK_SUB_SUB pulreq_02[3];
extern const PPWORK_SUB_SUB pulreq_03[1];
extern const PPWORK_SUB_SUB pulreq_04[1];
extern const PPWORK_SUB_SUB pulreq_05[1];
extern const PPWORK_SUB_SUB pulreq_06[1];
extern const PPWORK_SUB_SUB pulreq_07[1];
extern const PPWORK_SUB_SUB pulreq_08[1];
extern const PPWORK_SUB_SUB pulreq_09[1];
extern const PPWORK_SUB_SUB pulreq_10[1];
extern const PPWORK_SUB_SUB pulreq_11[1];
extern const PPWORK_SUB_SUB pulreq_20[3];
extern const PPWORK_SUB_SUB pulreq_21[3];
extern const PPWORK_SUB_SUB pulreq_22[3];
extern const PPWORK_SUB_SUB pulreq_23[3];
extern const PPWORK_SUB_SUB pulreq_24[3];
extern const PPWORK_SUB_SUB pulreq_25[3];
extern const PPWORK_SUB_SUB pulreq_26[3];
extern const PPWORK_SUB_SUB pulreq_27[3];
extern const PPWORK_SUB_SUB pulreq_28[3];
extern const PPWORK_SUB_SUB pulreq_29[3];
extern const PPWORK_SUB_SUB pulreq_30[3];
extern const PPWORK_SUB_SUB pulreq_31[3];
extern const PPWORK_SUB_SUB pulreq_32[3];
extern const PPWORK_SUB_SUB pulreq_33[3];
extern const PPWORK_SUB_SUB pulreq_34[3];
extern const PPWORK_SUB_SUB pulreq_35[3];
extern const PPWORK_SUB_SUB pulreq_36[3];
extern const PPWORK_SUB_SUB pulreq_37[3];
extern const PPWORK_SUB_SUB pulreq_38[3];
extern const PPWORK_SUB_SUB pulreq_39[3];
extern const PPWORK_SUB_SUB pulreq_40[3];
extern const PPWORK_SUB_SUB pulreq_41[4];
extern const PPWORK_SUB_SUB pulreq_42[3];
extern const PPWORK_SUB_SUB pulreq_43[3];
extern const PPWORK_SUB_SUB pulreq_44[3];
extern const PPWORK_SUB_SUB pulreq_xx[6];
extern const PPWORK_SUB_SUB pulreq_x2[7];


extern s16 vib_req[2][2];
extern u8 pulpul_scene;
extern PPWORK ppwork[2]; // size: 0x68, address: 0x579610
extern PULREQ pulreq[PULREQ_MAX];
extern PULPARA pulpara[PULPARA_MAX];

void init_pulpul_work();
void pulpul_stop();
void pulpul_stop2(s16 ix);
void pp_vib_on(s16 id);
void pp_operator_check_flag(u8 fl);
void move_pulpul_work();
void pp_screen_quake(s16 ix);
void init_pulpul_work2(s16 ix);
void init_pulpul_round2(s16 ix);
void pulpul_request(s16 id, s16 ix);
void pulpul_req_copy(s16 id, PULREQ* adr);
void pulpul_request_again();
s32 chkVibUnit(s32 port);
void move_pulpul(PPWORK* wk);
s32 pulpul_pdVibMxStart(PPWORK* wk, s32 arg1, s32 arg2, PULPARA* param);
s32 vibParamTrans(s32 id, PULPARA* prm);
void pp_pulpara_remake_at_init();
void pp_pulpara_remake_at_init2();
void pp_pulpara_remake_at_hit();
void pp_pulpara_remake_at();
void pp_pulpara_remake_dm_all(WORK* wk);
void pp_pulpara_guard(WORK* wk);
void pp_pulpara_hit(WORK* wk);
void pp_pulpara_blocking(WORK* wk);
void pp_pulpara_catch(WORK* wk);
void pp_pulpara_caught(WORK* wk);
void pp_pulpara_remake_nm_move();
void pp_pulpara_shungokusatsu(WORK* wk);

#endif
