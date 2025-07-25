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

#include <fcntl.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// libcdvd

int sceCdBreak(void) {
    not_implemented(__func__);
}

int sceCdGetDiskType(void) {
    return SCECdPS2DVD;
}

int sceCdGetError(void) {
    return SCECdErNO;
}

int sceCdInit(int init_mode) {
    not_implemented(__func__);
}

int sceCdMmode(int media) {
    not_implemented(__func__);
}

#define AFS_LENGTH 642492416
#define AFS_START_LSN 0x100
#define AFS_SECTOR_COUNT ((AFS_LENGTH + 2047) / 2048)
#define AFS_END_LSN (AFS_START_LSN + AFS_SECTOR_COUNT)

static const char flist_path[] = "\\THIRD\\0FLIST.DIR;1";
static const char afs_path[] = "\\THIRD\\SF33RD.AFS;1";

int sceCdRead(u_int lsn, u_int sectors, void *buf, sceCdRMode *mode) {
    if (lsn == -1) {
        // No need to actually read a file or write to the buffer
        // because we are handling flist read and we don't
        // need to read from buf
        return 1;
    } else if ((lsn >= AFS_START_LSN) && (lsn < AFS_END_LSN)) {
        const int file_offset = (lsn - AFS_START_LSN) * 2048;
        const int fd = open("rom/THIRD/SF33RD.AFS", O_RDONLY);
        lseek(fd, file_offset, SEEK_SET);
        read(fd, buf, sectors * 2048);
        close(fd);
    } else {
        fatal_error("Can't handle lsn %u", lsn);
    }

    return 1;
}

int sceCdSync(int mode) {
    // printf("[SDK] sceCdSync(mode: %d)\n", mode);
    return 0;
}

int sceCdLayerSearchFile(sceCdlFILE *fp, const char *name, int layer) {
    if (strncmp(name, flist_path, strlen(flist_path)) == 0) {
        fp->size = 12;
        fp->lsn = -1; // Set a wacky lsn on purpose to recognize it in sceCdRead
    } else if (strncmp(name, afs_path, strlen(afs_path)) == 0) {
        fp->size = AFS_LENGTH;
        fp->lsn = AFS_START_LSN; // Set a wacky lsn on purpose to recognize it in sceCdRead
    } else {
        fatal_error("Can't handle filename %s", name);
    }

    return 1;
}

// sifdev

static bool starts_with(const char *prefix, const char *str) {
    return strncmp(prefix, str, strlen(prefix)) == 0;
}

static void convert_filename(char *dest, const char *src) {
    const char device_name[] = "cdrom0:";

    if (starts_with(device_name, src)) {
        // Skip device name
        src += strlen(device_name);
    } else {
        fatal_error("Can't handle filename: %s.", src);
    }

    // FIXME: Figure out a way to package resources with the executable
    //        instead of relying on relative paths
    strcpy(dest, "rom");
    strcat(dest, src);

    for (; *dest; dest++) {
        // Convert \ to /
        if (*dest == '\\') {
            *dest = '/';
        }

        // Remove ;1 from the end
        if (*dest == ';') {
            *dest = '\0';
            break;
        }
    }
}

int sceOpen(const char *filename, int flag, ...) {
    // Convert SCE flags to Unix flags
    int _flag = 0;

    switch (flag & 0xF) {
    case SCE_RDONLY:
        _flag = O_RDONLY;
        break;

    case SCE_WRONLY:
        _flag = O_WRONLY;
        break;

    case SCE_RDWR:
        _flag = O_RDWR;
        break;
    }

    if (flag & SCE_APPEND) {
        _flag |= O_APPEND;
    }

    if (flag & SCE_CREAT) {
        _flag |= O_CREAT;
    }

    if (flag & SCE_TRUNC) {
        _flag |= O_TRUNC;
    }

    // Convert filenames
    // Example: cdrom0:\THIRD\IOP\FONT8_8.TM2;1 -> rom/THIRD/IOP/FONT8_8.TM2
    char converted_filename[2048];
    memset(converted_filename, 0, sizeof(converted_filename));
    convert_filename(converted_filename, filename);

    return open(converted_filename, _flag, 0644);
}

int sceClose(int fd) {
    return close(fd);
}

int sceRead(int fd, void *buf, int nbyte) {
    return read(fd, buf, nbyte);
}

int sceWrite(int fd, const void *buf, int nbyte) {
    return write(fd, buf, nbyte);
}

int sceLseek(int fd, int offset, int whence) {
    return lseek(fd, offset, whence);
}

long sceLseek64(int fd, long offset, int whence) {
    not_implemented(__func__);
}

int sceFsReset(void) {
    not_implemented(__func__);
}

int sceIoctl(int fd, int req, void *) {
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

int sceSifCheckStatRpc(sceSifRpcData *) {
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
    // printf("[SDK] sceDmaSend(d: %X, tag: %X)\n", d, tag);
}

int sceDmaSync(sceDmaChan *d, int mode, int timeout) {
    // printf("[SDK] sceDmaSync(d: %X, mode: %d, timeout: %d)\n", d, mode, timeout);
    return 0;
}

// libgraph

int sceGsExecLoadImage(sceGsLoadImage *lp, unsigned int *srcaddr) {
    not_implemented(__func__);
}

void sceGsResetGraph(short mode, short inter, short omode, short ffmode) {
    // printf("[SDK] sceGsResetGraph(mode: %d, inter: %d, omode: %d, ffmode: %d)\n", mode, inter, omode, ffmode);
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
    fatal_error("sceGsSyncV should never be called in ports");
}

int *sceGsSyncVCallback(int (*func)(int)) {
    return NULL;
}

// eekernel

void scePrintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    vprintf(fmt, args);

    va_end(args);
}

// libvu0

void sceVpu0Reset() {
    not_implemented(__func__);
}

void sceVu0UnitMatrix(sceVu0FMATRIX m) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] = (i == j);
        }
    }
}

// libdbc

int sceDbcInit() {
    // Do nothing
    return 1;
}

void sceDbcEnd() {
    not_implemented(__func__);
}

// eekernel

void FlushCache(int operation) {
    // printf("[SDK] FlushCache called (operation: %d)\n", operation);
}

void iFlushCache(int operation) {
    // printf("[SDK] iFlushCache called (operation: %d)\n", operation);
}

void InvalidDCache(void *begin, void *end) {
    // printf("[SDK] InvalidDCache called (begin: %0X, end: %0X)\n", begin, end);
}

void SyncDCache(void *, void *) {
    not_implemented(__func__);
}

int EnableIntc(int) {
    not_implemented(__func__);
}

int iEnableIntc(int) {
    not_implemented(__func__);
}

int iDisableIntc(int) {
    not_implemented(__func__);
}

int EnableDmac(int) {
    not_implemented(__func__);
}

int AddIntcHandler(int, int (*)(int), int) {
    not_implemented(__func__);
}

int AddDmacHandler(int, int (*)(int), int) {
    not_implemented(__func__);
}

void ExitHandler() {
    not_implemented(__func__);
}

// libdma

void sceDmaRecvN(sceDmaChan *d, void *addr, int size) {
    not_implemented(__func__);
}

#endif
