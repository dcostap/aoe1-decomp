/* VA: 00447F40 _WaveReadFile */
/* Dsutil.c lines 680-745, 242 bytes */
/* attempt log:
 * baseline: natural named-cursor MMIO loop, default flags; 248B, missing the
 * binary-proven direct memcpy call.
 * /Oi- probe: restored direct memcpy and all four calls, but the extra locals
 * colored the total/read/destination cursors incorrectly (232B).
 * byte-at-a-time SDK-source probe: period-plausible but VC5 retained a scalar
 * loop, cached the mmioAdvance import, and missed memcpy (205B).
 * direct-field chunk probes: removed cursor aliases and recovered the original
 * EBX/EDI/EBP/ECX/ESI topology; best was 234B with 120 positional differences.
 * min-order and conditional-argument variants were nonproductive. A focused
 * 15-variant lab found three emitted groups, no size/frame/call-set eligible
 * candidate, and no exact match.
 * this session: branch-local assignment in the memcpy count reached 242B/16B
 * drift but swapped the next/remaining register roles; SDK headers did not
 * change the natural 234B basin. The exact source shape assigns the selected
 * length in the destination argument's comma expression, which preserves the
 * binary-proven selected-length state while VC5 evaluates the cdecl pushes.
 * exact: local MMIOINFO/MMCKINFO surface, /Oi- direct memcpy, and branch-local
 * selected-length update now match all 242 bytes; casts are period SDK-style.
 */

typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef unsigned int MMRESULT;

typedef struct DSUTIL_WAVE_READ_MMCKINFO {
    DWORD ckid;
    DWORD cksize;
    DWORD fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
} DSUTIL_WAVE_READ_MMCKINFO;

typedef struct DSUTIL_WAVE_READ_MMIOINFO {
    DWORD dwFlags;
    DWORD fccIOProc;
    long (__stdcall *pIOProc)(char*, UINT, long, long);
    UINT wErrorRet;
    void* htask;
    long cchBuffer;
    char* pchBuffer;
    char* pchNext;
    char* pchEndRead;
    char* pchEndWrite;
    long lBufOffset;
    long lDiskOffset;
    DWORD adwInfo[3];
    DWORD dwReserved1;
    DWORD dwReserved2;
    void* hmmio;
} DSUTIL_WAVE_READ_MMIOINFO;

int __cdecl _WaveReadFile(void* hmmio, UINT cbRead, BYTE* pbDest, DSUTIL_WAVE_READ_MMCKINFO* pckIn, UINT* cbActualRead)
{
    DSUTIL_WAVE_READ_MMIOINFO mmioinfoIn;
    int nError = 0;
    UINT cT;
    UINT cbDataIn;
    UINT cbDataToCopy;

    if ((nError = (mmioGetInfo(hmmio, &mmioinfoIn, 0) != 0))) {
        goto error;
    }

    cbDataIn = cbRead;
    if (cbDataIn > pckIn->cksize) {
        cbDataIn = pckIn->cksize;
    }

    pckIn->cksize -= cbDataIn;

    for (cT = 0; cT < cbDataIn;) {
        if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead) {
            if ((nError = mmioAdvance(hmmio, &mmioinfoIn, 0)) != 0) {
                goto error;
            }
            if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead) {
                nError = 0xE103;
                goto error;
            }
        }

        cbDataToCopy = mmioinfoIn.pchEndRead - mmioinfoIn.pchNext;
        if (cbDataIn - cT < cbDataToCopy) {
            memcpy((cbDataToCopy = cbDataIn - cT, (BYTE*)pbDest + cT),
                   (BYTE*)mmioinfoIn.pchNext, cbDataIn - cT);
        } else {
            memcpy((BYTE*)pbDest + cT, (BYTE*)mmioinfoIn.pchNext,
                   cbDataToCopy);
        }
        cT += cbDataToCopy;
        mmioinfoIn.pchNext += cbDataToCopy;
    }

    if ((nError = mmioSetInfo(hmmio, &mmioinfoIn, 0)) != 0) {
        goto error;
    }

    *cbActualRead = cbDataIn;
    goto done;

error:
    *cbActualRead = 0;
done:
    return nError;
}
