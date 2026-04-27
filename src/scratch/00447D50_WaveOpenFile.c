/* VA: 00447D50 _WaveOpenFile (414B) */
/* Dsutil.c lines 496-619 */
/* C89 */
/* Opens a WAV file using WINMM mmio* APIs */

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

extern void* mmioOpenA(void* name, void* p, unsigned long flags);
extern long mmioDescend(void* hmmio, MMCKINFO* ck, MMCKINFO* ckParent, long flags);
extern long mmioAscend(void* hmmio, MMCKINFO* ck, long flags);
extern long mmioRead(void* hmmio, void* p, long cb);
extern long mmioClose(void* hmmio, long flags);

long _WaveOpenFile(const char* szName, HMMIO* phmmio,
    WAVEFORMAT* pFormat, MMCKINFO* mmckinfoParent)
{
    HMMIO hmmio;
    MMCKINFO ckRiff;
    
    hmmio = mmioOpenA((void*)szName, 0, 0x11000);
    if (hmmio == 0) {
        return 0;
    }
    
    /* Descend into RIFF */
    ckRiff.fccType = 0x45564157;  /* 'WAVE' */
    if (mmioDescend(hmmio, &ckRiff, 0, 0x20) != 0) {
        mmioClose(hmmio, 0);
        return 0;
    }
    
    if (ckRiff.fccType != 0x45564157) {
        mmioClose(hmmio, 0);
        return 0;
    }
    
    return 0;
}
