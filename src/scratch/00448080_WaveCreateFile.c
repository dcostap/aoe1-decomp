/* VA: 00448080 _WaveCreateFile (287B) */
/* Dsutil.c lines 793-895 */
/* C89 */
/* Creates a WAV file using WINMM mmio* APIs */

typedef struct {
    unsigned long ckid;
    unsigned long cksize;
    unsigned long fccType;
} MMCKINFO;

typedef struct {
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
} WAVEFORMAT;

typedef void* HMMIO;

extern void* __cdecl mmioOpenA(void* name, void* p, unsigned long flags);
extern long __cdecl mmioCreateChunk(void* hmmio, MMCKINFO* ck, long flags);
extern long __cdecl mmioWrite(void* hmmio, void* p, long cb);
extern long __cdecl mmioAscend(void* hmmio, MMCKINFO* ck, long flags);

long __cdecl _WaveCreateFile(const char* szName, HMMIO* phmmio,
    WAVEFORMAT* pFormat, MMCKINFO* mmckinfoParent)
{
    HMMIO hmmio;
    unsigned long* pFccType;
    
    hmmio = mmioOpenA((void*)szName, 0, 0x11002);
    *phmmio = hmmio;
    if (hmmio == 0) {
        return 0xE104;
    }
    
    pFccType = (unsigned long*)((char*)mmckinfoParent + 8);
    *pFccType = 0x45564157;
    *((unsigned long*)((char*)mmckinfoParent + 4)) = 0;
    if (mmioCreateChunk(hmmio, (MMCKINFO*)pFormat, 0x20) != 0) {
        return 0xE104;
    }
    
    mmckinfoParent->ckid = 0x20746D66;
    mmckinfoParent->cksize = 0x10;
    if (mmioCreateChunk(hmmio, mmckinfoParent, 0) != 0) {
        return 0xE104;
    }
    
    return 0;
}
