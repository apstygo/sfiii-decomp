#ifndef ACRUTIL_H
#define ACRUTIL_H

#include "structs.h"
#include "types.h"

void appViewSetItems(VPRM *prm);
void appViewGetItems(VPRM *prm);
void appViewMatrix();
void render_start();
void render_end();
void initRenderState(s32 flag);
void setZ_Operation(s32 flag);
void setBlendMode(s32 ope, s32 src, s32 dst);
void setBlendOperation(s32 ope);
void setBlendSource(s32 src, s32 dst);
void setFilterMode(s32 mode);
void setTexAdrsMode(s32 mode);
void setBackGroundColor(u32 color);

#endif
