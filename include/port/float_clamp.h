#ifndef FLOAT_CLAMP_H
#define FLOAT_CLAMP_H
#include "common.h"

#if !defined(TARGET_PS2)
uint64_t float_to_uint64_clamped(float f);
#endif

#endif
