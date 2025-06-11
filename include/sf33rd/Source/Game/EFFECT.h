#ifndef EFFECT_H
#define EFFECT_H

#include "structs.h"
#include "types.h"

#define EFFECT_MAX 128

extern s16 exec_tm[8];           // size: 0x10, address: 0x578F80
extern u32 frw[EFFECT_MAX][448]; // size: 0x38000, address: 0x5A9CA0
extern s16 head_ix[8];           // size: 0x10, address: 0x578FA0
extern s16 tail_ix[8];           // size: 0x10, address: 0x578F90
extern s16 frwctr_min;           // size: 0x2, address: 0x578FB0
extern s16 frwctr;               // size: 0x2, address: 0x578FB4
extern s16 frwque[EFFECT_MAX];   // size: 0x100, address: 0x5A9BA0

void move_effect_work(s16 index);
void disp_effect_work();
void effect_work_init();
void effect_work_quick_init();
void effect_work_kill_mod_plcol();
void push_effect_work(WORK *wkhd);
s16 pull_effect_work(s16 index);
void work_init_zero(s32 *adrs_int, s32 xx);
void effect_work_list_init(s16 lix, s16 iid);
s16 search_effect_index(s16 index, s16 flag, s16 tid);
void effect_work_kill(s16 index, s16 kill_id);
void write_my_shell_ix(WORK *wk, s16 ix);
s32 erase_my_shell_ix(WORK *wk, s16 ix);
s32 get_my_shell_ix(WORK *wk, s16 ix, WORK **tmw);
s32 get_vs_shell_adrs(WORK *wk, s16 id, s16 ix, WORK_Other **tmw);
void clear_my_shell_ix(WORK *wk);
void setup_shell_hit_stop(WORK *wk, s16 tm, s16 fl);
s32 shell_live_check(PLW *wk, s16 wix);
s32 clear_caution_flag(PLW *wk, u8 /* unused */);
s32 set_caution_flag(PLW *wk, u8 /* unused */);
s32 setup_status_flag(WORK *wk, u8 data);
s32 reset_extra_bg_flag(WORK *wk, u8 /* unused */);
s32 flip_my_rl_flag(WORK *wk, u8 /* unused */);
s32 setup_meoshi_hit_flag(WORK *wk, u8 data);
s32 exec_char_asxy(WORK *wk, u8 data);
s32 setup_my_clear_level(WORK *wk, u8 data);
s32 setup_my_bright_level(WORK *wk, u8 data);
s32 setup_free_program(s32 /* unused */, s32 /* unused */);
s32 setup_bg_quake_x(s32 /* unused */, u8 data);
s32 setup_bg_quake_y(s32 /* unused */, u8 data);
s32 setup_exdm_ix(PLW *wk, u8 data);
s32 setup_dmv_use_flag(PLW *wk, u8 data);
s32 setup_disp_flag(WORK *wk, u8 data);
s32 setup_command_number(PLW *wk, u8 data);
u8 old_my_char_check(u8 num, u8 flag);
void setup_shadow_of_the_Effy(WORK *wk);
void set_init_A4_flag();

#endif
