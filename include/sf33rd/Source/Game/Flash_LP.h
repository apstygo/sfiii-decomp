#ifndef FLASH_LP_H
#define FLASH_LP_H

#include "structs.h"
#include "types.h"

extern u8 Lamp_Flash_Data[][2] = {{0x07, 0x6f}, {0x1e, 0x03}}; // size: 0x4, address: 0x51FC30 //Exclusive

void Flash_Lamp();

#endif
