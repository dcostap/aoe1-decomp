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
 * - Probe 1: natural direct macro calls, 3rd arg of first final mmioAscend = `result` (binary pushes
 *   edi holding the RIFF-descend result), if/else instead of goto. -> diff 59, push edi OK but direct
 *   call [88A934h] (no cached pointer).
 * - Probe 2: same body with __declspec(dllimport) declarations -> VC5 cached mmioAscend in a register
 *   for ALL four calls (diff 160); import unresolved in this build env. REVERTED.
 * - Baseline for final-block lab: macro + direct calls + result as 3rd arg (diff 59, shape 98.06%).
 * - Probe 4 (lab, 11 final-block shapes): all local-cache forms (assign-expr, separate stmt, late decl,
 *   discarded/assigned first result, 3rd arg result/0) collapse to ONE family: `mov edi,[88A934h];
 *   push 0; push ebp; push edx; call edi` (8 bytes vs original 7-byte `push edi; mov edi,[88A934h]`);
 *   direct-macro forms stay direct calls. No exact basin found.
 * - Key open lead (from prior worker's assignpos lab, 20260531_145344 V000000): assigning the ascend
 *   local BEFORE mmioWrite made VC5 emit the original's push-then-load ORDER
 *   (`push edi; mov edi,[esp+18h]; push ebp; push edx; call edi`) but it loaded the local from a reused
 *   dead parameter slot ([esp+18h]) instead of rematerializing [88A934h] (diff 58, size 240). A future
 *   worker should try to make that slot load come from [88A934h] directly (e.g., register local, or a
 *   form where the store is eliminated and the load is rematerialized) while keeping push-then-load order.
 *   Note the original loads [88A934h] into edi AFTER pushing edi, reusing the just-pushed register;
 *   every local-cache variant emits the load BEFORE the pushes and folds the 3rd arg to push 0.
 * - Probe 15: kept direct IAT views for the guarded early ascends, but used the SDK import declaration
 *   for the adjacent post-write ascend pair; this reproduces the original push-then-load order exactly.
 *   -> exact 228 bytes, 10/10 calls, 0.0000% diff.
 */

typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef long LONG;
typedef struct DSUTIL_WAVECLOSEWRITE_MMCKINFO {
    DWORD ckid;
    DWORD cksize;
    DWORD fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
} DSUTIL_WAVECLOSEWRITE_MMCKINFO;

typedef struct DSUTIL_WAVECLOSEWRITE_MMIOINFO {
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
} DSUTIL_WAVECLOSEWRITE_MMIOINFO;

typedef int (__stdcall *MMIOSETINFO)(HMMIO, DSUTIL_WAVECLOSEWRITE_MMIOINFO*, UINT);
typedef LONG (__stdcall *MMIOSEEK)(HMMIO, LONG, int);
typedef int (__stdcall *MMIODESCEND)(HMMIO, DSUTIL_WAVECLOSEWRITE_MMCKINFO*, const DSUTIL_WAVECLOSEWRITE_MMCKINFO*, UINT);
typedef int (__stdcall *MMIOASCEND)(HMMIO, DSUTIL_WAVECLOSEWRITE_MMCKINFO*, UINT);
typedef LONG (__stdcall *MMIOWRITE)(HMMIO, const char*, LONG);
typedef int (__stdcall *MMIOCLOSE)(HMMIO, UINT);

#define mmioSetInfo_abs (*(MMIOSETINFO*)0x88A924)
#define mmioSeek_abs (*(MMIOSEEK*)0x88A928)
#define mmioDescend_abs (*(MMIODESCEND*)0x88A92C)
#define mmioAscend_abs (*(MMIOASCEND*)0x88A934)
#define mmioWrite_abs (*(MMIOWRITE*)0x88A948)
#define mmioClose_abs (*(MMIOCLOSE*)0x88A94C)

int __cdecl WaveCloseWriteFile(HMMIO* phmmioOut, DSUTIL_WAVECLOSEWRITE_MMCKINFO* pckOut, DSUTIL_WAVECLOSEWRITE_MMCKINFO* pckOutRIFF, DSUTIL_WAVECLOSEWRITE_MMIOINFO* pmmioinfoOut, DWORD cSamples)
{
    int result;

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
                        mmioWrite_abs(*phmmioOut, (const char*)&cSamples, sizeof(DWORD));
                        mmioAscend(*phmmioOut, pckOut, result);
                        result = mmioAscend(*phmmioOut, pckOutRIFF, 0);
                    } else {
                        return 1;
                    }
                }
            }
        }
    }

    if (*phmmioOut != 0) {
        mmioClose_abs(*phmmioOut, 0);
        *phmmioOut = 0;
    }
    return result;
}
