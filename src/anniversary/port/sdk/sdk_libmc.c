#if defined(TARGET_SDL3)

#include "common.h"

#include <SDL3/SDL.h>
#include <libmc.h>

#include <errno.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#if defined(_WIN32) || defined(_WIN64)
#include <direct.h>
#include <dirent.h>
#define S_ISDIR(m) (((m)&S_IFMT) == S_IFDIR)
#define mkdir(path, mode) _mkdir(path)
#else
#include <unistd.h>
#include <dirent.h>
#ifndef O_BINARY
#define O_BINARY 0
#endif
#endif

typedef void (*OperationFinalizer)(int *result);

// Operation data structures
typedef struct GetInfoOperation { int *type, *free, *format; } GetInfoOperation;
typedef struct OpenOperation { int port, slot, mode; const char *name; } OpenOperation;
typedef struct CloseOperation { int fd; } CloseOperation;
typedef struct ReadOperation { int fd, nbyte; void *buf; } ReadOperation;
typedef struct WriteOperation { int fd, nbyte; const void *buf; } WriteOperation;
typedef struct MkdirOperation { int port, slot; const char *name; } MkdirOperation;
typedef struct GetDirOperation { int port, slot, maxent; const char *name; sceMcTblGetDir *table; } GetDirOperation;
typedef struct DeleteOperation { int port, slot; const char *name; } DeleteOperation;

// Static instances for pending operations
static GetInfoOperation get_info_operation = { 0 };
static OpenOperation open_operation = { 0 };
static CloseOperation close_operation = { 0 };
static ReadOperation read_operation = { 0 };
static WriteOperation write_operation = { 0 };
static MkdirOperation mkdir_operation = { 0 };
static GetDirOperation get_dir_operation = { 0 };
static DeleteOperation delete_operation = { 0 };
static int registered_operation = 0;

// Forward declarations for helpers
static char *get_full_path(int port, int slot, const char *name);
static void stat_to_sce_time(struct stat *st, sceMcStDateTime *sce_time);

// Finalizer functions
static void finalize_get_info(int *result) {
    *get_info_operation.type = sceMcTypePS2;
    *get_info_operation.free = 0x1F03;
    *get_info_operation.format = 1;
    *result = sceMcResSucceed;
}

static void finalize_open(int *result) {
    char *full_path = get_full_path(open_operation.port, open_operation.slot, open_operation.name);
    if (!full_path) { *result = -1; return; }
    int flags, acc = 0644;
    switch (open_operation.mode) {
        case 1: flags = O_RDONLY | O_BINARY; break;
        case 2: flags = O_WRONLY | O_TRUNC | O_BINARY; break;
        case 0x200: flags = O_WRONLY | O_CREAT | O_TRUNC | O_BINARY; break;
        default: free(full_path); *result = -1; return;
    }
    *result = open(full_path, flags, acc);
    free(full_path);
}

static void finalize_close(int *result) { *result = close(close_operation.fd); }
static void finalize_read(int *result) { *result = read(read_operation.fd, read_operation.buf, read_operation.nbyte); }
static void finalize_write(int *result) { *result = write(write_operation.fd, write_operation.buf, write_operation.nbyte); }

static void finalize_mkdir(int *result) {
    char *full_path = get_full_path(mkdir_operation.port, mkdir_operation.slot, mkdir_operation.name);
    if (!full_path) { *result = -1; return; }
    if (mkdir(full_path, 0755) == 0) {
        *result = sceMcResSucceed;
    } else {
        *result = (errno == EEXIST) ? sceMcResNoEntry : -1;
    }
    free(full_path);
}

static void finalize_get_dir(int *result) {
    char *wildcard = strrchr(get_dir_operation.name, '*');
    if (wildcard) {
        size_t base_len = wildcard - get_dir_operation.name - 1;
        char *dir_name = malloc(base_len + 1);
        strncpy(dir_name, get_dir_operation.name, base_len);
        dir_name[base_len] = '\0';
        char *dir_path = get_full_path(get_dir_operation.port, get_dir_operation.slot, dir_name);
        free(dir_name);
        if (!dir_path) { *result = -1; return; }
        DIR *dir = opendir(dir_path);
        if (!dir) { free(dir_path); *result = -1; return; }
        int i = 0;
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL && i < get_dir_operation.maxent) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
            char *full_entry_path = malloc(strlen(dir_path) + strlen(entry->d_name) + 2);
            sprintf(full_entry_path, "%s/%s", dir_path, entry->d_name);
            struct stat st;
            if (stat(full_entry_path, &st) == 0) {
                sceMcTblGetDir *dirent = &get_dir_operation.table[i];
                memset(dirent, 0, sizeof(sceMcTblGetDir));
                strncpy((char *)dirent->EntryName, entry->d_name, sizeof(dirent->EntryName) - 1);
                dirent->EntryName[sizeof(dirent->EntryName) - 1] = '\0';
                dirent->AttrFile = S_ISDIR(st.st_mode) ? sceMcFileAttrSubdir : (sceMcFileAttrReadable | sceMcFileAttrWriteable);
                dirent->FileSizeByte = st.st_size;
                stat_to_sce_time(&st, &dirent->_Modify);
                memcpy(&dirent->_Create, &dirent->_Modify, sizeof(sceMcStDateTime));
                i++;
            }
            free(full_entry_path);
        }
        closedir(dir);
        free(dir_path);
        *result = i;
    } else {
        char *full_path = get_full_path(get_dir_operation.port, get_dir_operation.slot, get_dir_operation.name);
        if (!full_path) { *result = -1; return; }
        struct stat st;
        if (stat(full_path, &st) != 0) { free(full_path); *result = -1; return; }
        free(full_path);
        sceMcTblGetDir *dirent = &get_dir_operation.table[0];
        memset(dirent, 0, sizeof(sceMcTblGetDir));
        const char *basename = strrchr(get_dir_operation.name, '/');
        basename = basename ? basename + 1 : get_dir_operation.name;
        strncpy((char *)dirent->EntryName, basename, sizeof(dirent->EntryName) - 1);
        dirent->EntryName[sizeof(dirent->EntryName) - 1] = '\0';
        dirent->AttrFile = S_ISDIR(st.st_mode) ? sceMcFileAttrSubdir : (sceMcFileAttrReadable | sceMcFileAttrWriteable);
        dirent->FileSizeByte = st.st_size;
        stat_to_sce_time(&st, &dirent->_Modify);
        memcpy(&dirent->_Create, &dirent->_Modify, sizeof(sceMcStDateTime));
        *result = 1;
    }
}

static void finalize_delete(int *result) {
    char *full_path = get_full_path(delete_operation.port, delete_operation.slot, delete_operation.name);
    if (!full_path) { *result = -1; return; }
    *result = remove(full_path);
    free(full_path);
}

static OperationFinalizer finalizers[] = {
    [sceMcFuncNoCardInfo] = finalize_get_info, [sceMcFuncNoOpen] = finalize_open,
    [sceMcFuncNoClose] = finalize_close, [sceMcFuncNoRead] = finalize_read,
    [sceMcFuncNoWrite] = finalize_write, [sceMcFuncNoMkdir] = finalize_mkdir,
    [sceMcFuncNoGetDir] = finalize_get_dir, [sceMcFuncNoDelete] = finalize_delete,
};

// Helper functions
static char *get_save_path(int port, int slot) {
    if (port != 0 || slot != 0) return NULL;
    char *path = SDL_GetPrefPath("capcom", "sf33rd");
    if (!path) return NULL;
    struct stat st;
    if (stat(path, &st) != 0 || !S_ISDIR(st.st_mode)) mkdir(path, 0755);
    return path;
}

static char *get_full_path(int port, int slot, const char *name) {
    char *base_path = get_save_path(port, slot);
    if (!base_path) return NULL;
    size_t full_path_len = strlen(base_path) + strlen(name) + 1;
    char *full_path = malloc(full_path_len);
    snprintf(full_path, full_path_len, "%s%s", base_path, name);
    SDL_free(base_path);
    return full_path;
}

static void stat_to_sce_time(struct stat *st, sceMcStDateTime *sce_time) {
    struct tm *tm_time = localtime(&st->st_mtime);
    sce_time->Sec = tm_time->tm_sec; sce_time->Min = tm_time->tm_min;
    sce_time->Hour = tm_time->tm_hour; sce_time->Day = tm_time->tm_mday;
    sce_time->Month = tm_time->tm_mon + 1; sce_time->Year = tm_time->tm_year + 1900;
}

// sceMc... API functions
int sceMcInit(void) { return sceMcIniSucceed; }

int sceMcSync(int mode, int *cmd, int *result) {
    if (registered_operation > 0 && finalizers[registered_operation]) {
        *cmd = registered_operation;
        finalizers[registered_operation](result);
        registered_operation = 0;
        return sceMcExecFinish;
    }
    return sceMcExecIdle;
}

int sceMcGetInfo(int port, int slot, int *type, int *free, int *format) {
    registered_operation = sceMcFuncNoCardInfo;
    get_info_operation.type = type; get_info_operation.free = free; get_info_operation.format = format;
    return 0;
}

int sceMcOpen(int port, int slot, const char *name, int mode) {
    registered_operation = sceMcFuncNoOpen;
    open_operation.port = port; open_operation.slot = slot; open_operation.name = name; open_operation.mode = mode;
    return 0;
}

int sceMcClose(int fd) {
    registered_operation = sceMcFuncNoClose;
    close_operation.fd = fd;
    return 0;
}

int sceMcRead(int fd, void *buf, int nbyte) {
    registered_operation = sceMcFuncNoRead;
    read_operation.fd = fd; read_operation.buf = buf; read_operation.nbyte = nbyte;
    return 0;
}

int sceMcWrite(int fd, const void *buf, int nbyte) {
    registered_operation = sceMcFuncNoWrite;
    write_operation.fd = fd; write_operation.buf = buf; write_operation.nbyte = nbyte;
    return 0;
}

int sceMcMkdir(int port, int slot, const char *name) {
    registered_operation = sceMcFuncNoMkdir;
    mkdir_operation.port = port; mkdir_operation.slot = slot; mkdir_operation.name = name;
    return 0;
}

int sceMcDelete(int port, int slot, const char *name) {
    registered_operation = sceMcFuncNoDelete;
    delete_operation.port = port; delete_operation.slot = slot; delete_operation.name = name;
    return 0;
}

int sceMcGetDir(int port, int slot, const char *name, unsigned int mode, int maxent, sceMcTblGetDir *table) {
    registered_operation = sceMcFuncNoGetDir;
    get_dir_operation.port = port; get_dir_operation.slot = slot; get_dir_operation.name = name;
    get_dir_operation.maxent = maxent; get_dir_operation.table = table;
    return 0;
}

int sceMcFormat(int port, int slot) { return sceMcResSucceed; }
int sceMcUnformat(int port, int slot) { return sceMcResSucceed; }

#else

#include "common.h"
#include <libmc.h>
#include <stdbool.h>

void sceMcInit(void) { not_implemented(__func__); }
int sceMcSync(int mode, int *cmd, int *result) { not_implemented(__func__); }
int sceMcGetInfo(int port, int slot, int *type, int *free, int *format) { not_implemented(__func__); }
int sceMcOpen(int, int, const char *, int) { not_implemented(__func__); }
int sceMcClose(int) { not_implemented(__func__); }
int sceMcRead(int, void *, int) { not_implemented(__func__); }
int sceMcWrite(int, const void *, int) { not_implemented(__func__); }
int sceMcMkdir(int, int, const char *) { not_implemented(__func__); }
int sceMcDelete(int, int, const char *) { not_implemented(__func__); }
int sceMcFormat(int, int) { not_implemented(__func__); }
int sceMcUnformat(int, int) { not_implemented(__func__); }
int sceMcGetDir(int port, int slot, const char *name, unsigned int mode, int maxent, sceMcTblGetDir *table) { not_implemented(__func__); }

#endif