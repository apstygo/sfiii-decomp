#ifndef BG_H
#define BG_H

#include "types.h"

void Bg_TexInit();       // Range: 0x16BA90 -> 0x16BB34
void Pause_Family_On();  // Range: 0x170290 -> 0x170320
void Bg_On_R(u32 s_prm); // Range: 0x170B00 -> 0x170B2C
void Scrn_Renew();       // Range: 0x170BE0 -> 0x170BF0
void Irl_Family();       // Range: 0x170BF0 -> 0x170CD0
void Irl_Scrn();         // Range: 0x170CD0 -> 0x170E9C

#endif
