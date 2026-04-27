// _WaveCreateFile — real pass
// VA: 00448080
#include <windows.h>

struct MMCKINFOEXT {
    int ckid;
    int cksize;
    int fccType;
    int dwDataOffset;
    int dwFlags;
};

extern int (__stdcall* _mmioOpenA)(char* filename, void* pmmioinfo, int flags);
extern int (__stdcall* _mmioCreateChunk)(int mmio, MMCKINFOEXT* ck, int flags);
extern int (__stdcall* _mmioWrite)(int mmio, void* p, int size);
extern int (__stdcall* _mmioAscend)(int mmio, MMCKINFOEXT* ck, int unused);

int __cdecl _WaveCreateFile(char* filename, int* phmmio, MMCKINFOEXT* riffCK, MMCKINFOEXT* fmtCK, void* wf)
{
    *phmmio = (*_mmioOpenA)(filename, 0, 0x11002);
    if (!*phmmio) return 0xE104;
    
    // Write "WAVE" RIFF chunk
    riffCK->fccType = 'EVAW';  // "WAVE" little-endian
    riffCK->cksize = 0;
    if ((*_mmioCreateChunk)(*phmmio, riffCK, 0x20)) return 0xE104;
    
    // Write "fmt " chunk
    fmtCK->ckid = ' tmf';  // "fmt " little-endian
    fmtCK->cksize = 16;
    if ((*_mmioCreateChunk)(*phmmio, fmtCK, 0)) return 0xE104;
    
    // Write WAVEFORMATEX (format-dependent size)
    int fmtSize;
    if (*(short*)wf == 1) {
        // PCM: write 16 bytes
        if ((*_mmioWrite)(*phmmio, wf, 16) != 16) return 0xE104;
    } else {
        // Non-PCM: write wf->cbSize + 18 bytes
        fmtSize = *(unsigned short*)((char*)wf + 16) + 18;
        if ((*_mmioWrite)(*phmmio, wf, fmtSize) != fmtSize) return 0xE104;
    }
    
    // Ascend from "fmt " chunk
    if ((*_mmioAscend)(*phmmio, fmtCK, 0)) return 0xE104;
    
    // Write "fact" chunk
    int factData = 0;
    MMCKINFOEXT factCK;
    factCK.ckid = 'tcaf';  // "fact" little-endian
    if ((*_mmioCreateChunk)(*phmmio, &factCK, 0)) return 0xE104;
    
    // Write 4 bytes of fact data
    if ((*_mmioWrite)(*phmmio, &factData, 4) != 4) return 0xE104;
    
    // Ascend from "fact" chunk
    if ((*_mmioAscend)(*phmmio, &factCK, 0)) return 0xE104;
    
    return 0;  // success
}
