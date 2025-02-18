#ifndef __eestruct__
#define __eestruct__

typedef struct {
    unsigned long long FBP : 9;
    unsigned long long pad09 : 7;
    unsigned long long FBW : 6;
    unsigned long long pad22 : 2;
    unsigned long long PSM : 6;
    unsigned long long pad30 : 2;
    unsigned long long FBMSK : 32;
} sceGsFrame;

typedef struct {
    unsigned long long ZBP : 9;
    unsigned long long pad09 : 15;
    unsigned long long PSM : 4;
    unsigned long long pad28 : 4;
    unsigned long long ZMSK : 1;
    unsigned long long pad33 : 31;
} sceGsZbuf;

typedef struct {
    unsigned long long OFX : 16;
    unsigned long long pad16 : 16;
    unsigned long long OFY : 16;
    unsigned long long pad48 : 16;
} sceGsXyoffset;

typedef struct {
    unsigned long long SCAX0 : 11;
    unsigned long long pad11 : 5;
    unsigned long long SCAX1 : 11;
    unsigned long long pad27 : 5;
    unsigned long long SCAY0 : 11;
    unsigned long long pad43 : 5;
    unsigned long long SCAY1 : 11;
    unsigned long long pad59 : 5;
} sceGsScissor;

typedef struct {
    unsigned long long AC : 1;
    unsigned long long pad01 : 63;
} sceGsPrmodecont;

typedef struct {
    unsigned long long CLAMP : 1;
    unsigned long long pad01 : 63;
} sceGsColclamp;

typedef struct {
    unsigned long long DTHE : 1;
    unsigned long long pad01 : 63;
} sceGsDthe;

typedef struct {
    unsigned long long ATE : 1;
    unsigned long long ATST : 3;
    unsigned long long AREF : 8;
    unsigned long long AFAIL : 2;
    unsigned long long DATE : 1;
    unsigned long long DATM : 1;
    unsigned long long ZTE : 1;
    unsigned long long ZTST : 2;
    unsigned long long pad19 : 45;
} sceGsTest;

typedef struct {
    unsigned long long PRIM : 3;
    unsigned long long IIP : 1;
    unsigned long long TME : 1;
    unsigned long long FGE : 1;
    unsigned long long ABE : 1;
    unsigned long long AA1 : 1;
    unsigned long long FST : 1;
    unsigned long long CTXT : 1;
    unsigned long long FIX : 1;
    unsigned long long pad11 : 53;
} sceGsPrim;

typedef struct {
    unsigned int R : 8;
    unsigned int G : 8;
    unsigned int B : 8;
    unsigned int A : 8;
    float Q;
} sceGsRgbaq;

typedef struct {
    unsigned long long X : 16;
    unsigned long long Y : 16;
    unsigned long long Z : 32;
} sceGsXyz;

typedef struct {
    unsigned long long SBP : 14;
    unsigned long long pad14 : 2;
    unsigned long long SBW : 6;
    unsigned long long pad22 : 2;
    unsigned long long SPSM : 6;
    unsigned long long pad30 : 2;
    unsigned long long DBP : 14;
    unsigned long long pad46 : 2;
    unsigned long long DBW : 6;
    unsigned long long pad54 : 2;
    unsigned long long DPSM : 6;
    unsigned long long pad62 : 2;
} sceGsBitbltbuf;

typedef struct {
    unsigned long long SSAX : 11;
    unsigned long long pad11 : 5;
    unsigned long long SSAY : 11;
    unsigned long long pad27 : 5;
    unsigned long long DSAX : 11;
    unsigned long long pad43 : 5;
    unsigned long long DSAY : 11;
    unsigned long long DIR : 2;
    unsigned long long pad61 : 3;
} sceGsTrxpos;

typedef struct {
    unsigned long long RRW : 12;
    unsigned long long pad12 : 20;
    unsigned long long RRH : 12;
    unsigned long long pad44 : 20;
} sceGsTrxreg;

typedef struct {
    unsigned long long XDR : 2;
    unsigned long long pad02 : 62;
} sceGsTrxdir;

/*-vif1--------------------------------------------------*/

#define SCE_VIF1_SET_CODE(immediate, num, cmd, irq)                                                                    \
    ((u_int)(immediate) | ((u_int)(num) << 16) | ((u_int)(cmd) << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_NOP(irq) ((u_int)(irq) << 31)

#define SCE_VIF1_SET_STCYCL(wl, cl, irq) ((u_int)(cl) | ((u_int)(wl) << 8) | ((u_int)0x01 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_OFFSET(offset, irq) ((u_int)(offset) | ((u_int)0x02 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_BASE(base, irq) ((u_int)(base) | ((u_int)0x03 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_ITOP(itop, irq) ((u_int)(itop) | ((u_int)0x04 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_STMOD(stmod, irq) ((u_int)(stmod) | ((u_int)0x05 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_MSKPATH3(msk, irq) ((u_int)(msk) | ((u_int)0x06 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_MARK(mark, irq) ((u_int)(mark) | ((u_int)0x07 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_FLUSHE(irq) (((u_int)0x10 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_FLUSH(irq) (((u_int)0x11 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_FLUSHA(irq) (((u_int)0x13 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_MSCAL(vuaddr, irq) ((u_int)(vuaddr) | ((u_int)0x14 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_MSCNT(irq) (((u_int)0x17 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_MSCALF(vuaddr, irq) ((u_int)(vuaddr) | ((u_int)0x15 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_STMASK(irq) (((u_int)0x20 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_STROW(irq) (((u_int)0x30 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_STCOL(irq) (((u_int)0x31 << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_MPG(vuaddr, num, irq)                                                                             \
    ((u_int)(vuaddr) | ((u_int)(num) << 16) | ((u_int)(0x4a) << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_DIRECT(count, irq) ((u_int)(count) | ((u_int)(0x50) << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_DIRECTHL(count, irq) ((u_int)(count) | ((u_int)(0x51) << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_UNPACK(vuaddr, num, cmd, irq)                                                                     \
    ((u_int)(vuaddr) | ((u_int)(num) << 16) | ((u_int)(0x60 | (cmd)) << 24) | ((u_int)(irq) << 31))

#define SCE_VIF1_SET_UNPACKR(vuaddr, num, cmd, irq)                                                                    \
    ((u_int)((vuaddr) | 0x8000) | ((u_int)(num) << 16) | ((u_int)(0x60 | (cmd)) << 24) | ((u_int)(irq) << 31))

/*-gif--------------------------------------------------*/

/* Utility for making giftag */
typedef struct {
    unsigned long long NLOOP : 15;
    unsigned long long EOP : 1;
    unsigned long long pad16 : 16;
    unsigned long long id : 14;
    unsigned long long PRE : 1;
    unsigned long long PRIM : 11;
    unsigned long long FLG : 2;
    unsigned long long NREG : 4;
    unsigned long long REGS0 : 4;
    unsigned long long REGS1 : 4;
    unsigned long long REGS2 : 4;
    unsigned long long REGS3 : 4;
    unsigned long long REGS4 : 4;
    unsigned long long REGS5 : 4;
    unsigned long long REGS6 : 4;
    unsigned long long REGS7 : 4;
    unsigned long long REGS8 : 4;
    unsigned long long REGS9 : 4;
    unsigned long long REGS10 : 4;
    unsigned long long REGS11 : 4;
    unsigned long long REGS12 : 4;
    unsigned long long REGS13 : 4;
    unsigned long long REGS14 : 4;
    unsigned long long REGS15 : 4;
} sceGifTag;

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg)                                                              \
    ((u_long)(nloop) | ((u_long)(eop) << 15) | ((u_long)(pre) << 46) | ((u_long)(prim) << 47) |                        \
     ((u_long)(flg) << 58) | ((u_long)(nreg) << 60))

#define SCE_GIF_CLEAR_TAG(tp) (*(u_long128 *)(tp) = (u_long128)0)

#define SCE_GIF_PACKED 0
#define SCE_GIF_REGLIST 1
#define SCE_GIF_IMAGE 2
#define SCE_GIF_PACKED_AD 0x0e

/* Macros for making bit pattern of GS registers */

#define SCE_GS_SET_ALPHA_1 SCE_GS_SET_ALPHA
#define SCE_GS_SET_ALPHA_2 SCE_GS_SET_ALPHA
#define SCE_GS_SET_ALPHA(a, b, c, d, fix)                                                                              \
    ((u_long)(a) | ((u_long)(b) << 2) | ((u_long)(c) << 4) | ((u_long)(d) << 6) | ((u_long)(fix) << 32))

#define SCE_GS_SET_BITBLTBUF(sbp, sbw, spsm, dbp, dbw, dpsm)                                                           \
    ((u_long)(sbp) | ((u_long)(sbw) << 16) | ((u_long)(spsm) << 24) | ((u_long)(dbp) << 32) | ((u_long)(dbw) << 48) |  \
     ((u_long)(dpsm) << 56))

#define SCE_GS_SET_CLAMP_1 SCE_GS_SET_CLAMP
#define SCE_GS_SET_CLAMP_2 SCE_GS_SET_CLAMP
#define SCE_GS_SET_CLAMP(wms, wmt, minu, maxu, minv, maxv)                                                             \
    ((u_long)(wms) | ((u_long)(wmt) << 2) | ((u_long)(minu) << 4) | ((u_long)(maxu) << 14) | ((u_long)(minv) << 24) |  \
     ((u_long)(maxv) << 34))

#define SCE_GS_SET_COLCLAMP(clamp) ((u_long)(clamp))

#define SCE_GS_SET_DIMX(                                                                                               \
    dm00, dm01, dm02, dm03, dm10, dm11, dm12, dm13, dm20, dm21, dm22, dm23, dm30, dm31, dm32, dm33)                    \
    ((u_long)(dm00) | ((u_long)(dm01) << 4) | ((u_long)(dm02) << 8) | ((u_long)(dm03) << 12) |                         \
     ((u_long)(dm10) << 16) | ((u_long)(dm11) << 20) | ((u_long)(dm12) << 24) | ((u_long)(dm13) << 28) |               \
     ((u_long)(dm20) << 32) | ((u_long)(dm21) << 36) | ((u_long)(dm22) << 40) | ((u_long)(dm23) << 44) |               \
     ((u_long)(dm30) << 48) | ((u_long)(dm31) << 52) | ((u_long)(dm32) << 56) | ((u_long)(dm33) << 60))

#define SCE_GS_SET_DTHE(dthe) ((u_long)(dthe))

#define SCE_GS_SET_FBA_1 SCE_GS_SET_FBA
#define SCE_GS_SET_FBA_2 SCE_GS_SET_FBA
#define SCE_GS_SET_FBA(fba) ((u_long)(fba))

#define SCE_GS_SET_FOG(f) ((u_long)(f) << 56)

#define SCE_GS_SET_FOGCOL(fcr, fcg, fcb) ((u_long)(fcr) | ((u_long)(fcg) << 8) | ((u_long)(fcb) << 16))

#define SCE_GS_SET_FRAME_1 SCE_GS_SET_FRAME
#define SCE_GS_SET_FRAME_2 SCE_GS_SET_FRAME
#define SCE_GS_SET_FRAME(fbp, fbw, psm, fbmask)                                                                        \
    ((u_long)(fbp) | ((u_long)(fbw) << 16) | ((u_long)(psm) << 24) | ((u_long)(fbmask) << 32))

#define SCE_GS_SET_LABEL(id, idmsk) ((u_long)(id) | ((u_long)(idmsk) << 32))

#define SCE_GS_SET_MIPTBP1_1 SCE_GS_SET_MIPTBP1
#define SCE_GS_SET_MIPTBP1_2 SCE_GS_SET_MIPTBP1
#define SCE_GS_SET_MIPTBP1(tbp1, tbw1, tbp2, tbw2, tbp3, tbw3)                                                         \
    ((u_long)(tbp1) | ((u_long)(tbw1) << 14) | ((u_long)(tbp2) << 20) | ((u_long)(tbw2) << 34) |                       \
     ((u_long)(tbp3) << 40) | ((u_long)(tbw3) << 54))

#define SCE_GS_SET_MIPTBP2_1 SCE_GS_SET_MIPTBP2
#define SCE_GS_SET_MIPTBP2_2 SCE_GS_SET_MIPTBP2
#define SCE_GS_SET_MIPTBP2(tbp4, tbw4, tbp5, tbw5, tbp6, tbw6)                                                         \
    ((u_long)(tbp4) | ((u_long)(tbw4) << 14) | ((u_long)(tbp5) << 20) | ((u_long)(tbw5) << 34) |                       \
     ((u_long)(tbp6) << 40) | ((u_long)(tbw6) << 54))

#define SCE_GS_SET_PABE(pabe) ((u_long)(pabe))

#define SCE_GS_SET_PRIM(prim, iip, tme, fge, abe, aa1, fst, ctxt, fix)                                                 \
    ((u_long)(prim) | ((u_long)(iip) << 3) | ((u_long)(tme) << 4) | ((u_long)(fge) << 5) | ((u_long)(abe) << 6) |      \
     ((u_long)(aa1) << 7) | ((u_long)(fst) << 8) | ((u_long)(ctxt) << 9) | ((u_long)(fix) << 10))

#define SCE_GS_SET_PRMODE(iip, tme, fge, abe, aa1, fst, ctxt, fix)                                                     \
    (((u_long)(iip) << 3) | ((u_long)(tme) << 4) | ((u_long)(fge) << 5) | ((u_long)(abe) << 6) |                       \
     ((u_long)(aa1) << 7) | ((u_long)(fst) << 8) | ((u_long)(ctxt) << 9) | ((u_long)(fix) << 10))

#define SCE_GS_SET_PRMODECONT(ac) ((u_long)(ac))

#define SCE_GS_SET_RGBAQ(r, g, b, a, q)                                                                                \
    ((u_long)(r) | ((u_long)(g) << 8) | ((u_long)(b) << 16) | ((u_long)(a) << 24) | ((u_long)(q) << 32))

#define SCE_GS_SET_SCANMSK(msk) ((u_long)(msk))

#define SCE_GS_SET_SCISSOR_1 SCE_GS_SET_SCISSOR
#define SCE_GS_SET_SCISSOR_2 SCE_GS_SET_SCISSOR
#define SCE_GS_SET_SCISSOR(scax0, scax1, scay0, scay1)                                                                 \
    ((u_long)(scax0) | ((u_long)(scax1) << 16) | ((u_long)(scay0) << 32) | ((u_long)(scay1) << 48))

#define SCE_GS_SET_SIGNAL(id, idmsk) ((u_long)(id) | ((u_long)(idmsk) << 32))

#define SCE_GS_SET_ST(s, t) ((u_long)(s) | ((u_long)(t) << 32))

/* datm bit is unavailable on GS Rev.1 */
#define SCE_GS_SET_TEST_1 SCE_GS_SET_TEST
#define SCE_GS_SET_TEST_2 SCE_GS_SET_TEST
#define SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst)                                                 \
    ((u_long)(ate) | ((u_long)(atst) << 1) | ((u_long)(aref) << 4) | ((u_long)(afail) << 12) |                         \
     ((u_long)(date) << 14) | ((u_long)(datm) << 15) | ((u_long)(zte) << 16) | ((u_long)(ztst) << 17))

#define SCE_GS_SET_TEX0_1 SCE_GS_SET_TEX0
#define SCE_GS_SET_TEX0_2 SCE_GS_SET_TEX0
#define SCE_GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld)                                     \
    ((u_long)(tbp) | ((u_long)(tbw) << 14) | ((u_long)(psm) << 20) | ((u_long)(tw) << 26) | ((u_long)(th) << 30) |     \
     ((u_long)(tcc) << 34) | ((u_long)(tfx) << 35) | ((u_long)(cbp) << 37) | ((u_long)(cpsm) << 51) |                  \
     ((u_long)(csm) << 55) | ((u_long)(csa) << 56) | ((u_long)(cld) << 61))

#define SCE_GS_SET_TEX1_1 SCE_GS_SET_TEX1
#define SCE_GS_SET_TEX1_2 SCE_GS_SET_TEX1
#define SCE_GS_SET_TEX1(lcm, mxl, mmag, mmin, mtba, l, k)                                                              \
    ((u_long)(lcm) | ((u_long)(mxl) << 2) | ((u_long)(mmag) << 5) | ((u_long)(mmin) << 6) | ((u_long)(mtba) << 9) |    \
     ((u_long)(l) << 19) | ((u_long)(k) << 32))

#define SCE_GS_SET_TEX2_1 SCE_GS_SET_TEX2
#define SCE_GS_SET_TEX2_2 SCE_GS_SET_TEX2
#define SCE_GS_SET_TEX2(psm, cbp, cpsm, csm, csa, cld)                                                                 \
    (((u_long)(psm) << 20) | ((u_long)(cbp) << 37) | ((u_long)(cpsm) << 51) | ((u_long)(csm) << 55) |                  \
     ((u_long)(csa) << 56) | ((u_long)(cld) << 61))

#define SCE_GS_SET_TEXA(ta0, aem, ta1) ((u_long)(ta0) | ((u_long)(aem) << 15) | ((u_long)(ta1) << 32))

#define SCE_GS_SET_TEXCLUT(cbw, cou, cov) ((u_long)(cbw) | ((u_long)(cou) << 6) | ((u_long)(cov) << 12))

#define SCE_GS_SET_TRXDIR(xdr) ((u_long)(xdr))

#define SCE_GS_SET_TRXPOS(ssax, ssay, dsax, dsay, dir)                                                                 \
    ((u_long)(ssax) | ((u_long)(ssay) << 16) | ((u_long)(dsax) << 32) | ((u_long)(dsay) << 48) | ((u_long)(dir) << 59))

#define SCE_GS_SET_TRXREG(rrw, rrh) ((u_long)(rrw) | ((u_long)(rrh) << 32))

#define SCE_GS_SET_UV(u, v) ((u_long)(u) | ((u_long)(v) << 16))

#define SCE_GS_SET_XYOFFSET_1 SCE_GS_SET_XYOFFSET
#define SCE_GS_SET_XYOFFSET_2 SCE_GS_SET_XYOFFSET
#define SCE_GS_SET_XYOFFSET(ofx, ofy) ((u_long)(ofx) | ((u_long)(ofy) << 32))

#define SCE_GS_SET_XYZ3 SCE_GS_SET_XYZ
#define SCE_GS_SET_XYZ2 SCE_GS_SET_XYZ
#define SCE_GS_SET_XYZ(x, y, z) ((u_long)(x) | ((u_long)(y) << 16) | ((u_long)(z) << 32))

#define SCE_GS_SET_XYZF3 SCE_GS_SET_XYZF
#define SCE_GS_SET_XYZF2 SCE_GS_SET_XYZF
#define SCE_GS_SET_XYZF(x, y, z, f) ((u_long)(x) | ((u_long)(y) << 16) | ((u_long)(z) << 32) | ((u_long)(f) << 56))

#define SCE_GS_SET_ZBUF_1 SCE_GS_SET_ZBUF
#define SCE_GS_SET_ZBUF_2 SCE_GS_SET_ZBUF
#define SCE_GS_SET_ZBUF(zbp, psm, zmsk) ((u_long)(zbp) | ((u_long)(psm) << 24) | ((u_long)(zmsk) << 32))

#define SCE_GS_SET_PMODE(en1, en2, crtmd, mmod, amod, slbg, alp)                                                       \
    ((u_long)(en1) | ((u_long)(en2) << 1) | ((u_long)(crtmd) << 2) | ((u_long)(mmod) << 5) | ((u_long)(amod) << 6) |   \
     ((u_long)(slbg) << 7) | ((u_long)(alp) << 8))

#define SCE_GS_SET_DISPLAY1 SCE_GS_SET_DISPLAY
#define SCE_GS_SET_DISPLAY2 SCE_GS_SET_DISPLAY
#define SCE_GS_SET_DISPLAY SCE_GS_SET_DISPLAY_INTERLACE

/* #define GS_PAL_MODE */

// #ifdef GS_PAL_MODE

/* PAL, NOINTERLACE */
// #define SCE_GS_SET_DISPLAY_NOINTERLACE(dx, dy, magh, magv, dw, dh)                                                     \
//     ((u_long)(0x290 + (dx)) | ((u_long)(36 + (dy)) << 12) | ((u_long)(magh) << 23) | ((u_long)(magv) << 27) |          \
//      ((u_long)(dw) << 32) | ((u_long)(dh) << 44))

// /* PAL, INTERLACE */
// #define SCE_GS_SET_DISPLAY_INTERLACE(dx, dy, magh, magv, dw, dh) \
//     ((u_long)(0x290 + (dx)) | ((u_long)(72 + (dy)) << 12) | ((u_long)(magh) << 23) | ((u_long)(magv) << 27) | \
//      ((u_long)(dw) << 32) | ((u_long)(dh) << 44))

// #else

// /* NTSC, NOINTERLACE */
// #define SCE_GS_SET_DISPLAY_NOINTERLACE(dx, dy, magh, magv, dw, dh) \
//     ((u_long)(0x27c + (dx)) | ((u_long)(25 + (dy)) << 12) | ((u_long)(magh) << 23) | ((u_long)(magv) << 27) | \
//      ((u_long)(dw) << 32) | ((u_long)(dh) << 44))

// /* NTSC, INTERLACE */
// #define SCE_GS_SET_DISPLAY_INTERLACE(dx, dy, magh, magv, dw, dh) \
//     ((u_long)(0x27c + (dx)) | ((u_long)(50 + (dy)) << 12) | ((u_long)(magh) << 23) | ((u_long)(magv) << 27) | \
//      ((u_long)(dw) << 32) | ((u_long)(dh) << 44))

// #endif /* GS_PAL_MODE */

// They must've used this modified version of the SCE macro

/* NTSC, INTERLACE */
#define SCE_GS_SET_DISPLAY_INTERLACE(dx, dy, magh, magv, dw, dh)                                                       \
    ((u_long)(dx) | ((u_long)(dy) << 12) | ((u_long)(magh) << 23) | ((u_long)(magv) << 27) | ((u_long)(dw) << 32) |    \
     ((u_long)(dh) << 44))

#define SCE_GS_SET_DISPFB1 SCE_GS_SET_DISPFB
#define SCE_GS_SET_DISPFB2 SCE_GS_SET_DISPFB
#define SCE_GS_SET_DISPFB(fbp, fbw, psm, dbx, dby)                                                                     \
    ((u_long)(fbp) | ((u_long)(fbw) << 9) | ((u_long)(psm) << 15) | ((u_long)(dbx) << 32) | ((u_long)(dby) << 43))

#define SCE_GS_SET_SMODE2(intr, ffmd, dpms) ((u_long)(intr) | ((u_long)(ffmd) << 1) | ((u_long)(dpms) << 2))

#define SCE_GS_SET_EXTBUF(exbp, exbw, fbin, wffmd, emoda, emodc, wdx, wdy)                                             \
    ((u_long)(exbp) | ((u_long)(exbw) << 14) | ((u_long)(fbin) << 20) | ((u_long)(wffmd) << 22) |                      \
     ((u_long)(emoda) << 23) | ((u_long)(emodc) << 25) | ((u_long)(wdx) << 32) | ((u_long)(wdy) << 43))

#define SCE_GS_SET_EXTDATA(sx, sy, smph, smpv, ww, wh)                                                                 \
    ((u_long)(sx) | ((u_long)(sy) << 12) | ((u_long)(smph) << 23) | ((u_long)(smpv) << 27) | ((u_long)(ww) << 32) |    \
     ((u_long)(wh) << 44))

#define SCE_GS_SET_EXTWRITE(write) ((u_long)(write))

#define SCE_GS_SET_BGCOLOR(r, g, b) ((u_long)(r) | ((u_long)(g) << 8) | ((u_long)(b) << 16))

/* GS registers address */
/*-- vertex info. reg--*/
#define SCE_GS_PRIM 0x00
#define SCE_GS_RGBAQ 0x01
#define SCE_GS_ST 0x02
#define SCE_GS_UV 0x03
#define SCE_GS_XYZF2 0x04
#define SCE_GS_XYZ2 0x05
#define SCE_GS_FOG 0x0a
#define SCE_GS_XYZF3 0x0c
#define SCE_GS_XYZ3 0x0d
#define SCE_GS_XYOFFSET_1 0x18
#define SCE_GS_XYOFFSET_2 0x19
#define SCE_GS_PRMODECONT 0x1a

/*-- drawing attribute reg. --*/
#define SCE_GS_PRMODE 0x1b
#define SCE_GS_TEX0_1 0x06
#define SCE_GS_TEX0_2 0x07
#define SCE_GS_TEX1_1 0x14
#define SCE_GS_TEX1_2 0x15
#define SCE_GS_TEX2_1 0x16
#define SCE_GS_TEX2_2 0x17
#define SCE_GS_TEXCLUT 0x1c
#define SCE_GS_SCANMSK 0x22
#define SCE_GS_MIPTBP1_1 0x34
#define SCE_GS_MIPTBP1_2 0x35
#define SCE_GS_MIPTBP2_1 0x36
#define SCE_GS_MIPTBP2_2 0x37
#define SCE_GS_CLAMP_1 0x08
#define SCE_GS_CLAMP_2 0x09
#define SCE_GS_TEXA 0x3b
#define SCE_GS_FOGCOL 0x3d
#define SCE_GS_TEXFLUSH 0x3f

/*-- pixel operation reg. --*/
#define SCE_GS_SCISSOR_1 0x40
#define SCE_GS_SCISSOR_2 0x41
#define SCE_GS_ALPHA_1 0x42
#define SCE_GS_ALPHA_2 0x43
#define SCE_GS_DIMX 0x44
#define SCE_GS_DTHE 0x45
#define SCE_GS_COLCLAMP 0x46
#define SCE_GS_TEST_1 0x47
#define SCE_GS_TEST_2 0x48
#define SCE_GS_PABE 0x49
#define SCE_GS_FBA_1 0x4a
#define SCE_GS_FBA_2 0x4b

/*-- buffer reg. --*/
#define SCE_GS_FRAME_1 0x4c
#define SCE_GS_FRAME_2 0x4d
#define SCE_GS_ZBUF_1 0x4e
#define SCE_GS_ZBUF_2 0x4f

/*-- inter-buffer transfer reg. --*/
#define SCE_GS_BITBLTBUF 0x50
#define SCE_GS_TRXPOS 0x51
#define SCE_GS_TRXREG 0x52
#define SCE_GS_TRXDIR 0x53
#define SCE_GS_HWREG 0x54

/*-- other reg. --*/
#define SCE_GS_SIGNAL 0x60
#define SCE_GS_FINISH 0x61
#define SCE_GS_LABEL 0x62
#define SCE_GS_NOP 0x7f

#endif
