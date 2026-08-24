/* VA: 00448400 riffCopyChunk */
/* Dsutil.c lines 1191-1227, 208 bytes */
/* Match note: use direct member-size expressions for the read/write checks; this makes VC5 keep
 * the size in EBX and copy it through ECX for the mmioRead argument.  The cleanup helper caches
 * GlobalHandle through a void* local so the dead pckIn/ESI register is reused for the thunk. */

typedef unsigned int UINT;
typedef unsigned int DWORD;
typedef long LONG;
typedef struct DSUTIL_RIFFCOPY_MMCKINFO {
    DWORD ckid;
    DWORD cksize;
    DWORD fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
} DSUTIL_RIFFCOPY_MMCKINFO;

typedef HGLOBAL (__stdcall *GLOBALALLOC)(UINT flags, DWORD bytes);
typedef void* (__stdcall *GLOBALLOCK)(HGLOBAL hMem);
typedef HGLOBAL (__stdcall *DSUTIL_GLOBALHANDLE)(const void* pMem);
typedef int (__stdcall *GLOBALUNLOCK)(HGLOBAL hMem);
typedef HGLOBAL (__stdcall *GLOBALFREE)(HGLOBAL hMem);
typedef int (__stdcall *MMIOCREATECHUNK)(HMMIO hmmio, DSUTIL_RIFFCOPY_MMCKINFO* ck, UINT flags);
typedef LONG (__stdcall *MMIOREAD)(HMMIO hmmio, char* pch, LONG cch);
typedef LONG (__stdcall *MMIOWRITE)(HMMIO hmmio, const char* pch, LONG cch);
typedef int (__stdcall *MMIOASCEND)(HMMIO hmmio, DSUTIL_RIFFCOPY_MMCKINFO* ck, UINT flags);

#define GlobalAlloc_abs (*(GLOBALALLOC*)0x88A668)
#define GlobalLock_abs (*(GLOBALLOCK*)0x88A698)
#define GlobalHandle_abs (*(DSUTIL_GLOBALHANDLE*)0x88A68C)
#define GlobalUnlock_abs (*(GLOBALUNLOCK*)0x88A690)
#define GlobalFree_abs (*(GLOBALFREE*)0x88A69C)
#define mmioCreateChunk_abs (*(MMIOCREATECHUNK*)0x88A944)
#define mmioRead_abs (*(MMIOREAD*)0x88A930)
#define mmioWrite_abs (*(MMIOWRITE*)0x88A948)
#define mmioAscend_abs (*(MMIOASCEND*)0x88A934)

#define CLEANUP_DATA() do { \
    void* handle_func = (void*)GlobalHandle_abs; \
    GlobalUnlock_abs(((DSUTIL_GLOBALHANDLE)handle_func)(data)); \
    GlobalFree_abs(((DSUTIL_GLOBALHANDLE)handle_func)(data)); \
} while (0)

int __cdecl riffCopyChunk(HMMIO hmmioSrc, HMMIO hmmioDst, DSUTIL_RIFFCOPY_MMCKINFO* pckIn)
{
    DSUTIL_RIFFCOPY_MMCKINFO ck;
    char* data;

    data = (char*)GlobalLock_abs(GlobalAlloc_abs(0x42, pckIn->cksize));
    if (data == 0) {
        return 0;
    }

    ck.ckid = pckIn->ckid;
    ck.cksize = pckIn->cksize;
    if (mmioCreateChunk_abs(hmmioDst, &ck, 0) != 0) {
        goto fail;
    }
    if (mmioRead_abs(hmmioSrc, data, pckIn->cksize) != (LONG)pckIn->cksize) {
        goto fail;
    }
    if (mmioWrite_abs(hmmioDst, data, pckIn->cksize) != pckIn->cksize) {
        goto fail;
    }
    if (mmioAscend_abs(hmmioDst, &ck, 0) != 0) {
        goto fail;
    }

    CLEANUP_DATA();
    return 1;

fail:
    CLEANUP_DATA();
    return 0;
}
