#ifndef _LIBGRAPH_H
#define _LIBGRAPH_H

#include <eeregs.h>
#include <eestruct.h>

#define SCE_GS_NOINTERLACE (0)
#define SCE_GS_INTERLACE (1)
#define SCE_GS_FIELD (0)
#define SCE_GS_FRAME (1)
#define SCE_GS_NTSC (0x2)
#define SCE_GS_PAL (0x3)
#define SCE_GS_VESA1A (0x1a) /* System Use */
#define SCE_GS_VESA1B (0x1b) /* System Use */
#define SCE_GS_VESA1C (0x1c) /* System Use */
#define SCE_GS_VESA1D (0x1d) /* System Use */
#define SCE_GS_VESA2A (0x2a) /* System Use */
#define SCE_GS_VESA2B (0x2b) /* System Use */
#define SCE_GS_VESA2C (0x2c) /* System Use */
#define SCE_GS_VESA2D (0x2d) /* System Use */
#define SCE_GS_VESA2E (0x2e) /* System Use */
#define SCE_GS_VESA3B (0x3b) /* System Use */
#define SCE_GS_VESA3C (0x3c) /* System Use */
#define SCE_GS_VESA3D (0x3d) /* System Use */
#define SCE_GS_VESA3E (0x3e) /* System Use */
#define SCE_GS_VESA4A (0x4a) /* System Use */
#define SCE_GS_VESA4B (0x4b) /* System Use */
#define SCE_GS_DTV480P (0x50)
#define SCE_GS_PSMCT32 (0)
#define SCE_GS_PSMCT24 (1)
#define SCE_GS_PSMCT16 (2)
#define SCE_GS_PSMCT16S (10)
#define SCE_GS_PSMT8 (19)
#define SCE_GS_PSMT4 (20)
#define SCE_GS_PSMT8H (27)
#define SCE_GS_PSMT4HL (36)
#define SCE_GS_PSMT4HH (44)
#define SCE_GS_PSMZ32 (48)
#define SCE_GS_PSMZ24 (49)
#define SCE_GS_PSMZ16 (50)
#define SCE_GS_PSMZ16S (58)
#define SCE_GS_ZNOUSE (0)
#define SCE_GS_ZALWAYS (1)
#define SCE_GS_ZGEQUAL (2)
#define SCE_GS_ZGREATER (3)
#define SCE_GS_NOCLEAR (0)
#define SCE_GS_CLEAR (1)
#define SCE_GS_MODULATE (0)
#define SCE_GS_DECAL (1)
#define SCE_GS_HILIGHT (2)
#define SCE_GS_GHLIGHT2 SCE_GS_HIGHLIGHT2
#define SCE_GS_HIGHLIGHT2 (3)
#define SCE_GS_NEAREST (0)
#define SCE_GS_LINEAR (1)
#define SCE_GS_NEAREST_MIPMAP_NEAREST (2)
#define SCE_GS_NEAREST_MIPMAP_LINEAR SCE_GS_NEAREST_MIPMAP_LENEAR
#define SCE_GS_NEAREST_MIPMAP_LENEAR (3)
#define SCE_GS_LINEAR_MIPMAP_NEAREST (4)
#define SCE_GS_LINEAR_MIPMAP_LINEAR (5)
#define SCE_GS_PRIM_POINT (0)
#define SCE_GS_PRIM_LINE (1)
#define SCE_GS_PRIM_LINESTRIP (2)
#define SCE_GS_PRIM_TRI (3)
#define SCE_GS_PRIM_TRISTRIP (4)
#define SCE_GS_PRIM_TRIFAN (5)
#define SCE_GS_PRIM_SPRITE (6)
#define SCE_GS_PRIM_IIP (1 << 3)
#define SCE_GS_PRIM_TME (1 << 4)
#define SCE_GS_PRIM_FGE (1 << 5)
#define SCE_GS_PRIM_ABE (1 << 6)
#define SCE_GS_PRIM_AA1 (1 << 7)
#define SCE_GS_PRIM_FST (1 << 8)
#define SCE_GS_PRIM_CTXT1 (0)
#define SCE_GS_PRIM_CTXT2 (1 << 9)
#define SCE_GS_PRIM_FIX (1 << 10)

#define SCE_GS_FALSE (0)
#define SCE_GS_TRUE (1)

typedef struct {
    tGS_PMODE pmode;
    tGS_SMODE2 smode2;
    tGS_DISPFB2 dispfb;
    tGS_DISPLAY2 display;
    tGS_BGCOLOR bgcolor;
} sceGsDispEnv;

typedef struct {
    sceGsFrame frame1;
    unsigned long frame1addr;
    sceGsZbuf zbuf1;
    long zbuf1addr;
    sceGsXyoffset xyoffset1;
    long xyoffset1addr;
    sceGsScissor scissor1;
    long scissor1addr;
    sceGsPrmodecont prmodecont;
    long prmodecontaddr;
    sceGsColclamp colclamp;
    long colclampaddr;
    sceGsDthe dthe;
    long dtheaddr;
    sceGsTest test1;
    long test1addr;
} sceGsDrawEnv1;

typedef struct {
    sceGsFrame frame2;
    unsigned long frame2addr;
    sceGsZbuf zbuf2;
    long zbuf2addr;
    sceGsXyoffset xyoffset2;
    long xyoffset2addr;
    sceGsScissor scissor2;
    long scissor2addr;
    sceGsPrmodecont prmodecont;
    long prmodecontaddr;
    sceGsColclamp colclamp;
    long colclampaddr;
    sceGsDthe dthe;
    long dtheaddr;
    sceGsTest test2;
    long test2addr;
} sceGsDrawEnv2;

typedef struct {
    sceGsTest testa;
    long testaaddr;
    sceGsPrim prim;
    long primaddr;
    sceGsRgbaq rgbaq;
    long rgbaqaddr;
    sceGsXyz xyz2a;
    long xyz2aaddr;
    sceGsXyz xyz2b;
    long xyz2baddr;
    sceGsTest testb;
    long testbaddr;
} sceGsClear;

typedef struct {
    sceGsDispEnv disp[2];
    sceGifTag giftag0;
    sceGsDrawEnv1 draw01;
    sceGsDrawEnv2 draw02;
    sceGsClear clear0;
    sceGifTag giftag1;
    sceGsDrawEnv1 draw11;
    sceGsDrawEnv2 draw12;
    sceGsClear clear1;
} sceGsDBuffDc;

typedef struct {
    sceGifTag giftag0;
    sceGsBitbltbuf bitbltbuf;
    long bitbltbufaddr;
    sceGsTrxpos trxpos;
    long trxposaddr;
    sceGsTrxreg trxreg;
    long trxregaddr;
    sceGsTrxdir trxdir;
    long trxdiraddr;
    sceGifTag giftag1;
} sceGsLoadImage;

int sceGsSyncV(int mode);
int *sceGsSyncVCallback(int (*func)(int));
void sceGsResetPath();
void sceGsResetGraph(short mode, short inter, short omode, short ffmode);
int sceGsSyncPath(int mode, unsigned short timeout);
int sceGsSetDefLoadImage(sceGsLoadImage *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h);
int sceGsExecLoadImage(sceGsLoadImage *lp, unsigned int *srcaddr); // The address should be u_int128

#endif
