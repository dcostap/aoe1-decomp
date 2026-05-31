/* VA: 00448400 riffCopyChunk */
/* Dsutil.c lines 1191-1227, 208 bytes */
/*
 * Attempt log:
 * - Absolute IAT macros give exact 208-byte size and keep the prologue/import call shape close.
 * - Current blocker: first mismatch offset 34. Original uses short `jne` into the allocated body
 *   with an immediate null-return epilogue; VC5 keeps merging the null return with the later
 *   failure tail as a near `je`, causing large positional drift (edit diff about 26.9%).
 * - Tried guard/tail/register/pragma/flag variant labs and a natural positive-body rewrite;
 *   the rewrite regressed to mismatch at offset 6, so the best absolute-IAT baseline is kept.
 */

typedef unsigned int UINT;
typedef unsigned int DWORD;
typedef long LONG;
typedef void* HGLOBAL;
typedef void* HMMIO;

typedef struct MMCKINFO_LOCAL {
    DWORD ckid;
    DWORD cksize;
    DWORD fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
} MMCKINFO_LOCAL;

typedef HGLOBAL (__stdcall *GLOBALALLOC)(UINT flags, DWORD bytes);
typedef void* (__stdcall *GLOBALLOCK)(HGLOBAL hMem);
typedef HGLOBAL (__stdcall *GLOBALHANDLE)(const void* pMem);
typedef int (__stdcall *GLOBALUNLOCK)(HGLOBAL hMem);
typedef HGLOBAL (__stdcall *GLOBALFREE)(HGLOBAL hMem);
typedef int (__stdcall *MMIOCREATECHUNK)(HMMIO hmmio, MMCKINFO_LOCAL* ck, UINT flags);
typedef LONG (__stdcall *MMIOREAD)(HMMIO hmmio, char* pch, LONG cch);
typedef LONG (__stdcall *MMIOWRITE)(HMMIO hmmio, const char* pch, LONG cch);
typedef int (__stdcall *MMIOASCEND)(HMMIO hmmio, MMCKINFO_LOCAL* ck, UINT flags);

#define GlobalAlloc_abs (*(GLOBALALLOC*)0x88A668)
#define GlobalLock_abs (*(GLOBALLOCK*)0x88A698)
#define GlobalHandle_abs (*(GLOBALHANDLE*)0x88A68C)
#define GlobalUnlock_abs (*(GLOBALUNLOCK*)0x88A690)
#define GlobalFree_abs (*(GLOBALFREE*)0x88A69C)
#define mmioCreateChunk_abs (*(MMIOCREATECHUNK*)0x88A944)
#define mmioRead_abs (*(MMIOREAD*)0x88A930)
#define mmioWrite_abs (*(MMIOWRITE*)0x88A948)
#define mmioAscend_abs (*(MMIOASCEND*)0x88A934)

int __cdecl riffCopyChunk(HMMIO hmmioSrc, HMMIO hmmioDst, MMCKINFO_LOCAL* pckIn)
{
    MMCKINFO_LOCAL ck;
    char* data;
    LONG size;

    data = (char*)GlobalLock_abs(GlobalAlloc_abs(0x42, pckIn->cksize));
    if (data == 0) {
        goto alloc_failed;
    }
    goto allocated;
alloc_failed:
    return 0;
allocated:
    {
        ck.ckid = pckIn->ckid;
        ck.cksize = pckIn->cksize;

        if (mmioCreateChunk_abs(hmmioDst, &ck, 0) == 0) {
            size = pckIn->cksize;
            if (mmioRead_abs(hmmioSrc, data, size) == size) {
                if (mmioWrite_abs(hmmioDst, data, size) == pckIn->cksize) {
                    if (mmioAscend_abs(hmmioDst, &ck, 0) == 0) {
                        goto success;
                    }
                }
            }
        }

        GlobalUnlock_abs(GlobalHandle_abs(data));
        GlobalFree_abs(GlobalHandle_abs(data));
        return 0;

success:
        GlobalUnlock_abs(GlobalHandle_abs(data));
        GlobalFree_abs(GlobalHandle_abs(data));
        return 1;
    }
}

