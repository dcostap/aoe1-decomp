// 004481A0 _WaveStartDataWrite
// PDB: Dsutil.c:906-929, 55 bytes
// FLAGS: default
//
// Fixed: removed spurious `unsigned long unused` first param — the original
// takes 3 params (void* hmmioPtr, _MMCKINFO* ckOut, _MMIOINFO* mmioinfoOut).
// The extra 4-byte param shifted all stack offsets by 8/0x8.
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

MMRESULT __cdecl _WaveStartDataWrite(void* hmmioPtr, _MMCKINFO* ckOut, _MMIOINFO* mmioinfoOut) {
    MMRESULT result;

    ckOut->ckid = 0x61746164;
    ckOut->cksize = 0;
    result = mmioCreateChunk(*(void**)hmmioPtr, ckOut, 0);
    if (result != 0) {
        return result;
    }
    return mmioGetInfo(*(void**)hmmioPtr, mmioinfoOut, 0);
}
