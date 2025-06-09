// This file exists to make clang linker happy

#if !defined(TARGET_PS2)

#include "common.h"
#include "types.h"

#include <eekernel.h>
#include <libcdvd.h>
#include <libdma.h>
#include <libgraph.h>
#include <libmc.h>
#include <libpad2.h>
#include <libvu0.h>
#include <sif.h>
#include <sifrpc.h>

// libcdvd

int sceCdBreak(void) {
    not_implemented(__func__);
}

int sceCdGetDiskType(void) {
    not_implemented(__func__);
}

int sceCdGetError(void) {
    not_implemented(__func__);
}

int sceCdInit(int init_mode) {
    not_implemented(__func__);
}

int sceCdMmode(int media) {
    not_implemented(__func__);
}

int sceCdRead(u_int lbn, u_int sectors, void *buf, sceCdRMode *mode) {
    not_implemented(__func__);
}

int sceCdSync(int mode) {
    not_implemented(__func__);
}

int sceCdLayerSearchFile(sceCdlFILE *fp, const char *name, int layer) {
    not_implemented(__func__);
}

// sifdev

int sceRead(int fd, void *buf, int nbyte) {
    not_implemented(__func__);
}

int sceClose(int fd) {
    not_implemented(__func__);
}

int sceFsReset(void) {
    not_implemented(__func__);
}

int sceIoctl(int fd, int req, void *) {
    not_implemented(__func__);
}

int sceLseek(int fd, int offset, int where) {
    not_implemented(__func__);
}

long sceLseek64(int fd, long offset, int whence) {
    not_implemented(__func__);
}

int sceOpen(const char *filename, int flag, ...) {
    not_implemented(__func__);
}

int sceWrite(int fd, const void *buf, int nbyte) {
    not_implemented(__func__);
}

void *sceSifAllocIopHeap(unsigned int) {
    not_implemented(__func__);
}

int sceSifInitIopHeap(void) {
    not_implemented(__func__);
}

int sceSifFreeIopHeap(void *) {
    not_implemented(__func__);
}

int sceSifLoadModule(const char *filename, int args, const char *argp) {
    not_implemented(__func__);
}

int sceSifRebootIop(const char *img) {
    not_implemented(__func__);
}

int sceSifSyncIop(void) {
    not_implemented(__func__);
}

// sifrpc

void sceSifInitRpc(unsigned int mode) {
    not_implemented(__func__);
}

int sceSifBindRpc(sceSifClientData *, unsigned int, unsigned int) {
    not_implemented(__func__);
}

int sceSifCallRpc(sceSifClientData *, unsigned int, unsigned int, void *, int, void *, int, sceSifEndFunc, void *) {
    not_implemented(__func__);
}

// sif

int sceSifDmaStat(unsigned int id) {
    not_implemented(__func__);
}

unsigned int sceSifSetDma(sceSifDmaData *sdd, int len) {
    not_implemented(__func__);
}

// libdma

sceDmaChan *sceDmaGetChan(int id) {
    not_implemented(__func__);
}

int sceDmaReset(int mode) {
    not_implemented(__func__);
}

void sceDmaSend(sceDmaChan *d, void *tag) {
    not_implemented(__func__);
}

int sceDmaSync(sceDmaChan *d, int mode, int timeout) {
    not_implemented(__func__);
}

// libgraph

int sceGsExecLoadImage(sceGsLoadImage *lp, unsigned int *srcaddr) {
    not_implemented(__func__);
}

void sceGsResetGraph(short mode, short inter, short omode, short ffmode) {
    not_implemented(__func__);
}

void sceGsResetPath() {
    not_implemented(__func__);
}

int sceGsSetDefLoadImage(sceGsLoadImage *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h) {
    not_implemented(__func__);
}

int sceGsSyncPath(int mode, unsigned short timeout) {
    not_implemented(__func__);
}

int sceGsSyncV(int mode) {
    not_implemented(__func__);
}

int *sceGsSyncVCallback(int (*func)(int)) {
    not_implemented(__func__);
}

// libpad2

s32 scePad2Init(s32) {
    not_implemented(__func__);
}

s32 scePad2End(void) {
    not_implemented(__func__);
}

s32 scePad2GetButtonProfile(s32, scePad2ButtonProfile *) {
    not_implemented(__func__);
}

s32 scePad2GetState(s32) {
    not_implemented(__func__);
}

s32 scePad2Read(s32, scePad2ButtonState *) {
    not_implemented(__func__);
}

s32 scePad2CreateSocket(scePad2SocketParam *, void *) {
    not_implemented(__func__);
}

s32 scePad2DeleteSocket(s32) {
    not_implemented(__func__);
}

// eekernel

void scePrintf(const char *fmt, ...) {
    not_implemented(__func__);
}

// libvib

int sceVibGetProfile(int, unsigned char *) {
    not_implemented(__func__);
}

int sceVibSetActParam(int, int, unsigned char *, int, unsigned char *) {
    not_implemented(__func__);
}

// libvu0

void sceVpu0Reset() {
    not_implemented(__func__);
}

void sceVu0UnitMatrix(sceVu0FMATRIX m) {
    not_implemented(__func__);
}

// libdbc

int sceDbcInit() {
    not_implemented(__func__);
}

void sceDbcEnd() {
    not_implemented(__func__);
}

// libmc

int sceMcInit(void) {
    not_implemented(__func__);
}

int sceMcOpen(int, int, const char *, int) {
    not_implemented(__func__);
}

int sceMcClose(int) {
    not_implemented(__func__);
}

int sceMcRead(int, void *, int) {
    not_implemented(__func__);
}

int sceMcWrite(int, const void *, int) {
    not_implemented(__func__);
}

int sceMcMkdir(int, int, const char *) {
    not_implemented(__func__);
}

int sceMcDelete(int, int, const char *) {
    not_implemented(__func__);
}

int sceMcFormat(int, int) {
    not_implemented(__func__);
}

int sceMcUnformat(int, int) {
    not_implemented(__func__);
}

int sceMcGetDir(int, int, const char *, unsigned int, int, sceMcTblGetDir *) {
    not_implemented(__func__);
}

int sceMcGetInfo(int, int, int *, int *, int *) {
    not_implemented(__func__);
}

int sceMcSync(int, int *, int *) {
    not_implemented(__func__);
}

// eekernel

int ChangeThreadPriority(int, int) {
    not_implemented(__func__);
}

void FlushCache(int) {
    not_implemented(__func__);
}

void iFlushCache(int) {
    not_implemented(__func__);
}

void InvalidDCache(void *, void *) {
    not_implemented(__func__);
}

int ResumeThread(int) {
    not_implemented(__func__);
}

void SyncDCache(void *, void *) {
    not_implemented(__func__);
}

int WakeupThread(int) {
    not_implemented(__func__);
}

#endif
