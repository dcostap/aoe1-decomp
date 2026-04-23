// tried the direct chunk-write/MMIO-import shape; first mismatch moved to the stack-arg load order
// tried adding a dummy leading parameter to shift the entry offsets; first arg matched, but the handle/info loads still drifted
// leaving in scratch because the remaining gap is stack-argument ordering, not a behavior mismatch
typedef unsigned long MMRESULT;

struct _MMCKINFO {
    unsigned long ckid;
    unsigned long cksize;
    unsigned long fccType;
    unsigned long dwDataOffset;
    unsigned long dwFlags;
};

struct _MMIOINFO {
    unsigned long dwFlags;
    unsigned long fccIOProc;
    long (__stdcall *pIOProc)(char*, unsigned int, long, long);
    unsigned int wErrorRet;
    void* htask;
    long cchBuffer;
    char* pchBuffer;
    char* pchNext;
    char* pchEndRead;
    char* pchEndWrite;
    long lBufOffset;
    long lDiskOffset;
    unsigned long adwInfo[3];
    unsigned long dwReserved1;
    unsigned long dwReserved2;
    void* hmmio;
};

extern "C" __declspec(dllimport) MMRESULT __stdcall mmioCreateChunk(void* hmmio, void* ckInfo, unsigned long flags);
extern "C" __declspec(dllimport) MMRESULT __stdcall mmioGetInfo(void* hmmio, void* info, unsigned long flags);

MMRESULT __cdecl _WaveStartDataWrite(unsigned long unused, _MMCKINFO* ckOut, void* hmmioPtr, _MMIOINFO* mmioinfoOut) {
    MMRESULT result;

    ckOut->ckid = 0x61746164;
    ckOut->cksize = 0;
    result = mmioCreateChunk(*(void**)hmmioPtr, ckOut, 0);
    if (result != 0) {
        return result;
    }
    return mmioGetInfo(*(void**)hmmioPtr, mmioinfoOut, 0);
}
