#ifndef FLASH_LP_H
#define FLASH_LP_H

#include "structs.h"
#include "types.h"


extern const u8 Lamp_Flash_Data[2][2]; // size: 0x4, address: 0x51FC30

void Flash_Lamp();

#endif
