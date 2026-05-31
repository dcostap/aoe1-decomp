/* VA: 00447F40 _WaveReadFile */
/* Dsutil.c lines 680-745, 242 bytes */
/* attempt 2026-05-31: implemented natural MMIO read loop from packet/source shape; first 33 bytes match but default memcpy is inlined and register allocation differs (cbRead/bytesRead/pointers in esi/ebx/edi instead of original ebx/edi/ebp), 57.85% positional. A memcpy2 call probe made body 240B (<242) and still wrong register coloring, rolled back to exact-size natural source. */

typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef unsigned int MMRESULT;

typedef struct _MMCKINFO {
    DWORD ckid;
    DWORD cksize;
    DWORD fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
} MMCKINFO;

typedef struct _MMIOINFO {
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
} MMIOINFO;

__declspec(dllimport) MMRESULT __stdcall mmioGetInfo(void* hmmio, MMIOINFO* info, UINT flags);
__declspec(dllimport) MMRESULT __stdcall mmioAdvance(void* hmmio, MMIOINFO* info, UINT flags);
__declspec(dllimport) MMRESULT __stdcall mmioSetInfo(void* hmmio, MMIOINFO* info, UINT flags);
void* __cdecl memcpy(void* dst, const void* src, unsigned int count);

MMRESULT __cdecl _WaveReadFile(void* hmmio, UINT cbRead, BYTE* pbDest, MMCKINFO* pckIn, UINT* cbActualRead)
{
    MMIOINFO mmioinfoIn;
    MMRESULT result;
    UINT cbDataIn;
    UINT cbDataToCopy;
    UINT cbBytesRead;
    BYTE* pbDestCur;
    char* pchNext;
    char* pchEndRead;

    result = (mmioGetInfo(hmmio, &mmioinfoIn, 0) != 0);
    if (result == 0) {
        if (cbRead > pckIn->cksize) {
            cbRead = pckIn->cksize;
        }
        pckIn->cksize -= cbRead;

        cbBytesRead = 0;
        if (cbRead != 0) {
            pbDestCur = pbDest;
            pchNext = mmioinfoIn.pchNext;
            do {
                pchEndRead = mmioinfoIn.pchEndRead;
                if (pchNext == pchEndRead) {
                    result = mmioAdvance(hmmio, &mmioinfoIn, 0);
                    if (result != 0) {
                        goto error;
                    }
                    pchNext = mmioinfoIn.pchNext;
                    pchEndRead = mmioinfoIn.pchEndRead;
                    if (pchNext == pchEndRead) {
                        result = 0xE103;
                        goto error;
                    }
                }

                cbDataIn = pchEndRead - pchNext;
                cbDataToCopy = cbRead - cbBytesRead;
                if (cbDataToCopy < cbDataIn) {
                    cbDataIn = cbDataToCopy;
                }
                memcpy(pbDestCur + cbBytesRead, pchNext, cbDataIn);
                cbBytesRead += cbDataIn;
                pchNext += cbDataIn;
                mmioinfoIn.pchNext = pchNext;
            } while (cbBytesRead < cbRead);
        }

        result = mmioSetInfo(hmmio, &mmioinfoIn, 0);
        if (result == 0) {
            *cbActualRead = cbRead;
            return result;
        }
    }

error:
    *cbActualRead = 0;
    return result;
}
