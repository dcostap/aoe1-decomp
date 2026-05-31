/* VA: 00448250 _WaveCloseWriteFile */
/* Dsutil.c lines 1007-1076, 228 bytes */
/*
 * Attempt log:
 * - Built natural MMIO close/write-fact path with absolute IAT macros; exact 228-byte size.
 * - Reworked missing fact chunk path to branch to cleanup/close and return success; improved to
 *   edit diff 9 bytes, positional 25.8772%, first mismatch 52.
 * - Best remaining drift: after mmioWrite, original emits `push edi; mov edi,[88A934h]`
 *   before two mmioAscend calls; VC5 source variants either cache the pointer before the push
 *   (`mov edi,[IAT]; push 0`, one byte longer) or use direct IAT calls without the cached pointer.
 * - Tried focused variant labs for fact-branch shape, cached/direct/dllimport/extern import surfaces,
 *   register/flag argument expressions, and assignment position; no exact match yet.
 */

typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef long LONG;
typedef void* HMMIO;

typedef struct MMCKINFO_LOCAL {
    DWORD ckid;
    DWORD cksize;
    DWORD fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
} MMCKINFO_LOCAL;

typedef struct MMIOINFO_LOCAL {
    DWORD dwFlags;
    DWORD fccIOProc;
    LONG (__stdcall *pIOProc)(char*, UINT, LONG, LONG);
    UINT wErrorRet;
    void* htask;
    LONG cchBuffer;
    char* pchBuffer;
    char* pchNext;
    char* pchEndRead;
    char* pchEndWrite;
    LONG lBufOffset;
    LONG lDiskOffset;
    DWORD adwInfo[3];
    DWORD dwReserved1;
    DWORD dwReserved2;
    HMMIO hmmio;
} MMIOINFO_LOCAL;

typedef int (__stdcall *MMIOSETINFO)(HMMIO, MMIOINFO_LOCAL*, UINT);
typedef LONG (__stdcall *MMIOSEEK)(HMMIO, LONG, int);
typedef int (__stdcall *MMIODESCEND)(HMMIO, MMCKINFO_LOCAL*, const MMCKINFO_LOCAL*, UINT);
typedef int (__stdcall *MMIOASCEND)(HMMIO, MMCKINFO_LOCAL*, UINT);
typedef LONG (__stdcall *MMIOWRITE)(HMMIO, const char*, LONG);
typedef int (__stdcall *MMIOCLOSE)(HMMIO, UINT);

#define mmioSetInfo_abs (*(MMIOSETINFO*)0x88A924)
#define mmioSeek_abs (*(MMIOSEEK*)0x88A928)
#define mmioDescend_abs (*(MMIODESCEND*)0x88A92C)
#define mmioAscend_abs (*(MMIOASCEND*)0x88A934)
#define mmioWrite_abs (*(MMIOWRITE*)0x88A948)
#define mmioClose_abs (*(MMIOCLOSE*)0x88A94C)

int __cdecl _WaveCloseWriteFile(HMMIO* phmmioOut, MMCKINFO_LOCAL* pckOut, MMCKINFO_LOCAL* pckOutRIFF, MMIOINFO_LOCAL* pmmioinfoOut, DWORD cSamples)
{
    int result;
    MMIOASCEND ascend;

    if (*phmmioOut == 0) {
        return 0;
    }

    pmmioinfoOut->dwFlags |= 0x10000000;
    result = mmioSetInfo_abs(*phmmioOut, pmmioinfoOut, 0);
    if (result == 0) {
        result = mmioAscend_abs(*phmmioOut, pckOut, 0);
        if (result == 0) {
            result = mmioAscend_abs(*phmmioOut, pckOutRIFF, 0);
            if (result == 0) {
                mmioSeek_abs(*phmmioOut, 0, 0);
                result = mmioDescend_abs(*phmmioOut, pckOutRIFF, 0, 0);
                if (result == 0) {
                    pckOut->ckid = 0x74636166;
                    if (mmioDescend_abs(*phmmioOut, pckOut, pckOutRIFF, 0x10) == 0) {
                        goto have_fact;
                    }
                    goto no_fact;
have_fact:
                    mmioWrite_abs(*phmmioOut, (const char*)&cSamples, 4);
                    result = (ascend = mmioAscend_abs)(*phmmioOut, pckOut, result);
                    result = ascend(*phmmioOut, pckOutRIFF, 0);
                }
            }
        }
    }

    if (*phmmioOut != 0) {
        mmioClose_abs(*phmmioOut, 0);
        *phmmioOut = 0;
    }
    return result;

no_fact:
    return 1;
}
