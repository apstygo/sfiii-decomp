#include "common.h"
#include "sf33rd/Source/Game/Flash_LP.h"
#include "sf33rd/Source/Game/workuser.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/SysDir.h"
#include "sf33rd/Source/Game/sc_data.h"

void Flash_Lamp(void) {
    unsigned char ix; // r16 (s0)
    unsigned char ix2p; // r19 (s3)
    unsigned char mark; // r18 (s2)
    unsigned char color; // r17 (s1)

    if (Mode_Type == 3 || Mode_Type == 4) {
        return;
    }

    if (omop_cockpit == 0) {
        return;
    }

    if (!Game_pause) {
        switch (Lamp_No) {
        case 0:
            Lamp_No = 1;
            Lamp_Index = 1;
            Lamp_Timer = 1;
        case 1:
            if (--Lamp_Timer == 0) {
                if (++Lamp_Index > 1) {
                    Lamp_Index = 0;
                }
                Lamp_Color = Lamp_Flash_Data[Lamp_Index][0];
                Lamp_Timer = Lamp_Flash_Data[Lamp_Index][1];
            }
        break;
        }
    }

    for (ix = 0; ix <= save_w[Present_Mode].Battle_Number[Play_Type]; ix++) {
        mark = flash_win_type[0][ix];
        if (flash_win_type[0][ix] == 0) {
            color = 7;
        }
        else {
            color = Lamp_Color;
        }
        if (flash_win_type[0][ix] == sync_win_type[0][ix] ) {
            scfont_sqput(vmark_tbl[ix],4,color,0,mark * 2,26,2,1,2);
        }
        mark = flash_win_type[1][ix];
        ix2p = ix + 4;
        {
            if (flash_win_type[1][ix] == 0) {
                color = 7;
            }
            else {
                color = Lamp_Color;
            }
        }
        if (flash_win_type[1][ix] == sync_win_type[1][ix]) {
            scfont_sqput(vmark_tbl[ix2p],4,color,0,mark * 2,26,2,1,2);
        } 
    }
}

//INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Flash_LP", Lamp_Flash_Data);
