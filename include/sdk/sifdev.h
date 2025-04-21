#ifndef _SIFDEV_H_DEFS
#define _SIFDEV_H_DEFS

/* Flag for sceOpen() */
#define SCE_RDONLY 0x0001
#define SCE_WRONLY 0x0002
#define SCE_RDWR 0x0003
#define SCE_NBLOCK 0x0010 /* Non-Blocking I/O */
#define SCE_APPEND 0x0100 /* append (writes guaranteed at the end) */
#define SCE_CREAT 0x0200  /* open with file create */
#define SCE_TRUNC 0x0400  /* open with truncation */
#define SCE_EXCL 0x0800   /* exclusive create */
#define SCE_NOBUF 0x4000  /* no device buffer and console interrupt */
#define SCE_NOWAIT 0x8000 /* asyncronous i/o */

int sceOpen(const char *filename, int flag, ...);
int sceClose(int fd);
int sceRead(int fd, void *buf, int nbyte);
int sceWrite(int fd, const void *buf, int nbyte);
int sceLseek(int fd, int offset, int where);

int sceSifInitIopHeap();
int sceSifRebootIop(const char *img);
int sceSifSyncIop();

int sceSifLoadModule(const char *filename, int args, const char *argp);

int sceFsReset();

#endif
