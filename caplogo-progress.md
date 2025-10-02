# Caplogo progress

This file shows progress towards porting the very first thing you see on screen – the Capcom logo.

Notes:
- Functions appear in the order that the game first calls them in.
- There's no need to decompile SDK and zlib functions.

| Module   | Progress   |
|----------|------------|
| sf33rd   | 100%       |
| cri      | 92.91%     |

| Function                | File                   |
|-------------------------|------------------------|
| dvCiSetRootDir          | cri/libadxe/dvci_sub.c |
| analysis_flist_003DC6A0 | cri/libadxe/dvci_sub.c |
| dvCiOptFn1              | cri/libadxe/dvci.c     |
| ADXF_GetPtStatEx        | cri/libadxe/adx_fs.c   |
| lsc_ExecHndl            | cri/libadxe/lsc_svr.c  |
| adxsjd_decexec_start    | cri/libadxe/adx_sjd.c  |
| ADX_DecodeSte4          | cri/libadxe/adx_dcd5.c |
| ADX_DecodeSte4AsSte     | cri/libadxe/adx_dcd5.c |
