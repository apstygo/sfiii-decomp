#include "common.h"

const u8 Ex_Menu_Max_Data[4][8] = { 
    {
        0x05,
        0x06,
        0x06,
        0x03,
        0x01,
        0x01,
        0x00,
        0x00,
    },
    {
        0x02,
        0x02,
        0x0A,
        0x0A,
        0x10,
        0x10,
        0x03,
        0x00,
    },
    {
        0x04,
        0x04,
        0x03,
        0x03,
        0x00,
        0x00,
        0x00,
        0x00,
    },
    {
        0x01,
        0x01,
        0x01,
        0x01,
        0x01,
        0x01,
        0x00,
        0x00,
    } 
};

const u8 Ex_Account_Data[4] = { 0, 8, 16, 24 };
const u8 Ex_Page_Data[4] = { 7, 7, 4, 6 };

s8 *Ex_Letter_Data[4][7][17] = {
    {
        {
            "DECREASE",
            "NORMAL",
            "INCREASE",
            "RECOVER",
            "QUICK RECOVER",
            "NO DAMAGE",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "S/#;;;;;;/L",
            "S/##;;;;;/L",
            "S/###;;;;/L",
            "S/####;;;/L",
            "S/#####;;/L",
            "S/######;/L",
            "S/#######/L",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "S/#;;;;;;/L",
            "S/##;;;;;/L",
            "S/###;;;;/L",
            "S/####;;;/L",
            "S/#####;;/L",
            "S/######;/L",
            "S/#######/L",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "NORMAL",
            "AUTO GUARD",
            "SEMI-PARRYING",
            "AUTO PARRYING",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "OFF",
            "ON",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "OFF",
            "ON",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
    },
    {
        {
            "NORMAL",
            "INFINITY",
            "MAXIMUM",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "NORMAL",
            "INFINITY",
            "MAXIMUM",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "-2",
            "-1",
            "NORMAL",
            "+1",
            "+2",
            "+3",
            "+4",
            "+5",
            "+6",
            "+7",
            "+8",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "-2",
            "-1",
            "NORMAL",
            "+1",
            "+2",
            "+3",
            "+4",
            "+5",
            "+6",
            "+7",
            "+8",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "-8",
            "-7",
            "-6",
            "-5",
            "-4",
            "-3",
            "-2",
            "-1",
            "NORMAL",
            "+1",
            "+2",
            "+3",
            "+4",
            "+5",
            "+6",
            "+7",
            "+8",
        },
        {
            "-8",
            "-7",
            "-6",
            "-5",
            "-4",
            "-3",
            "-2",
            "-1",
            "NORMAL",
            "+1",
            "+2",
            "+3",
            "+4",
            "+5",
            "+6",
            "+7",
            "+8",
        },
        {
            "S/#;;;/L",
            "S/##;;/L",
            "S/###;/L",
            "S/####/L",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
    },
    {
        {
            "S/#;;;;/L",
            "S/##;;;/L",
            "S/###;;/L",
            "S/####;/L",
            "S/#####/L",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "S/#;;;;/L",
            "S/##;;;/L",
            "S/###;;/L",
            "S/####;/L",
            "S/#####/L",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "S/#;;;/L",
            "S/##;;/L",
            "S/###;/L",
            "S/####/L",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "S/#;;;/L",
            "S/##;;/L",
            "S/###;/L",
            "S/####/L",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
    },
    {
        {
            "OFF",
            "ON",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "OFF",
            "ON",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "OFF",
            "ON",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "OFF",
            "ON",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "OFF",
            "ON",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "OFF",
            "ON",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
        {
            "",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
    },
};

s8 *Ex_Title_Data[4][7] = {
    {
        "LIFE GAUGE TYPE/.............",
        "1P VITALITY/.................",
        "2P VITALITY/.................",
        "GUARD TYPE/..................",
        "RAPID FIRE/..................",
        "BONUS STAGE/.................",
        "DEFAULT SETTING",
    },
    {
        "1P S.A. GAUGE TYPE/..........",
        "2P S.A. GAUGE TYPE/..........",
        "1P S.A. GAUGE STOCKS/........",
        "2P S.A. GAUGE STOCKS/........",
        "1P S.A. GAUGE LENGTH/........",
        "2P S.A. GAUGE LENGTH/........",
        "S.A. GAUGE INCREASE SPEED/...",
    },
    {
        "1P STUN GAUGE LENGTH/........",
        "2P STUN GAUGE LENGTH/........",
        "STUN GAUGE INCREASE SPEED/...",
        "STUN GAUGE RECOVERY SPEED/...",
        NULL,
        NULL,
        NULL,
    },
    {
        "SCREEN TEXT DISPLAY/.........",
        "LIFE GAUGE DISPLAY/..........",
        "TIMER DISPLAY/...............",
        "STUN GAUGE DISPLAY/..........",
        "S.A.GAUGE DISPLAY/...........",
        "PRESS START DISPLAY/.........",
        NULL,
    },
};