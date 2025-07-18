#include "sf33rd/Source/Game/stun.h"
#include "common.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/SysDir.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/sc_sub.h"
#include "sf33rd/Source/Game/workuser.h"

SDAT sdat[2];

void stngauge_cont_init() {
    u8 i;

    for (i = 0; i < 2; i++) {
        sdat[i].cstn = 0;
        sdat[i].sflag = 0;
        sdat[i].osflag = 0;
        sdat[i].g_or_s = 0;
        sdat[i].stimer = 2;
        sdat[i].slen = (piyori_type[i].genkai / 8);
        sdat[i].proccess_dead = 0;

        if (omop_st_bar_disp[i]) {
            stun_base_put(i, sdat[i].slen);
        }
    }

    stun_gauge_waku_write(sdat->slen, sdat[1].slen);
}

void stngauge_cont_main() {
    u8 i;

    if (omop_cockpit != 0) {
        if (gauge_stop_flag[0] == 0) {
            stngauge_control(0);
        } else {
            stun_put(0, sdat->cstn);
        }

        if (gauge_stop_flag[1] == 0) {
            stngauge_control(1);
        } else {
            stun_put(1, sdat[1].cstn);
        }

        for (i = 0; i < 2; i++) {
            if (omop_st_bar_disp[i]) {
                stun_base_put(i, sdat[i].slen);
            }
        }

        stun_gauge_waku_write(sdat->slen, sdat[1].slen);
    }
}

void stngauge_control(u8 pl) {
    if (!sdat[pl].proccess_dead) {
        if (plw[pl].dead_flag) {
            sdat[pl].proccess_dead = 1;
            sdat[pl].cstn = 0;
            return;
        }

        if (((plw[pl].wu.routine_no[1] == 1) && (plw[pl].wu.routine_no[2] == 0x19) &&
             (plw[pl].wu.routine_no[3] != 0)) ||
            (plw[pl].py->flag == 1)) {
            sdat[pl].sflag = 1;

            if (sdat[pl].osflag == 0) {
                sdat[pl].cstn = piyori_type[pl].genkai;
            }

            if (!EXE_flag && !Game_pause) {
                sdat[pl].stimer--;
            }

            if (sdat[pl].g_or_s == 0) {
                if (No_Trans == 0) {
                    stun_mark_write(pl, sdat[pl].slen);
                    stun_put(pl, sdat[pl].cstn);
                }

                if (sdat[pl].stimer == 0) {
                    sdat[pl].g_or_s = 1;
                    sdat[pl].stimer = 2;
                }
            } else {
                if (No_Trans == 0) {
                    stun_put(pl, sdat[pl].cstn);
                }

                if (sdat[pl].stimer == 0) {
                    sdat[pl].g_or_s = 0;
                    sdat[pl].stimer = 2;
                }
            }

            sdat[pl].osflag = sdat[pl].sflag;
            return;
        }

        sdat[pl].sflag = 0;

        if (sdat[pl].osflag == 1) {
            sdat[pl].osflag = sdat[pl].sflag;
            sdat[pl].g_or_s = 0;
            sdat[pl].stimer = 2;
            sdat[pl].cstn = plw[pl].py->now.quantity.h;
            sdat[pl].osflag = sdat[pl].sflag;

            if (No_Trans == 0) {
                stun_put(pl, sdat[pl].cstn);
            }
            return;
        }

        if (sdat[pl].cstn != plw[pl].py->now.quantity.h) {
            sdat[pl].cstn = plw[pl].py->now.quantity.h;
        }

        if (No_Trans == 0) {
            stun_put(pl, sdat[pl].cstn);
        }
    }
}

void stngauge_work_clear() {
    sdat[0].cstn = 0;
    sdat[0].sflag = 0;
    sdat[0].osflag = 0;
    sdat[0].g_or_s = 0;
    sdat[0].stimer = 2;
    sdat[0].proccess_dead = 0;
    stun_put(0, 0);
    sdat[1].cstn = 0;
    sdat[1].sflag = 0;
    sdat[1].osflag = 0;
    sdat[1].g_or_s = 0;
    sdat[1].stimer = 2;
    sdat[1].proccess_dead = 0;
    stun_put(1, 0);
}
