/* VA: 00448080 _WaveCreateFile */
/* Dsutil.c lines 793-895, 287 bytes */

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

typedef struct WAVEFORMATEX_LOCAL {
    unsigned short wFormatTag;
    unsigned short nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
} WAVEFORMATEX_LOCAL;

__declspec(dllimport) HMMIO __stdcall mmioOpenA(char* filename, void* mmioinfo, DWORD flags);
__declspec(dllimport) int __stdcall mmioCreateChunk(HMMIO hmmio, MMCKINFO_LOCAL* ck, UINT flags);
__declspec(dllimport) LONG __stdcall mmioWrite(HMMIO hmmio, const char* buffer, LONG bytes);
__declspec(dllimport) int __stdcall mmioAscend(HMMIO hmmio, MMCKINFO_LOCAL* ck, UINT flags);

int __cdecl _WaveCreateFile(char* pszFileName, HMMIO* phmmioOut, WAVEFORMATEX_LOCAL* pwfxDest, MMCKINFO_LOCAL* pckOut, MMCKINFO_LOCAL* pckOutRIFF)
{
    int err;
    DWORD dwFactChunk;
    MMCKINFO_LOCAL ckOut1;

    dwFactChunk = (DWORD)-1;
    err = 0;

    *phmmioOut = mmioOpenA(pszFileName, 0, 0x11002);
    if (*phmmioOut == 0) {
        err = 0xE104;
        goto done;
    }

    pckOutRIFF->fccType = 0x45564157;
    pckOutRIFF->cksize = 0;
    if ((err = mmioCreateChunk(*phmmioOut, pckOutRIFF, 0x20)) != 0) {
        goto done;
    }

    pckOut->ckid = 0x20746D66;
    pckOut->cksize = 16;
    if ((err = mmioCreateChunk(*phmmioOut, pckOut, 0)) != 0) {
        goto done;
    }

    if (pwfxDest->wFormatTag == 1) {
        if (mmioWrite(*phmmioOut, (const char*)pwfxDest, 16) != 16) {
            err = 0xE104;
            goto done;
        }
    } else {
        if ((UINT)mmioWrite(*phmmioOut, (const char*)pwfxDest, 18 + pwfxDest->cbSize) != (18 + pwfxDest->cbSize)) {
            goto fail;
        }
    }

    if ((err = mmioAscend(*phmmioOut, pckOut, 0)) != 0) {
        goto done;
    }

    ckOut1.ckid = 0x74636166;
    ckOut1.cksize = 0;
    if ((err = mmioCreateChunk(*phmmioOut, &ckOut1, 0)) != 0) {
        goto done;
    }

    if (mmioWrite(*phmmioOut, (const char*)&dwFactChunk, sizeof(dwFactChunk)) != sizeof(dwFactChunk)) {
        goto fail;
    }

    if ((err = mmioAscend(*phmmioOut, &ckOut1, 0)) == 0) {
        goto done;
    }

fail:
    err = 0xE104;

done:
    return err;
}
