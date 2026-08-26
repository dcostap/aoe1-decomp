/* VA: 00448080 _WaveCreateFile */
/* Dsutil.c lines 793-895, 287 bytes */

typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef long LONG;
typedef struct DSUTIL_WAVECREATE_MMCKINFO {
    DWORD ckid;
    DWORD cksize;
    DWORD fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
} DSUTIL_WAVECREATE_MMCKINFO;

typedef struct DSUTIL_WAVECREATE_WAVEFORMATEX {
    unsigned short wFormatTag;
    unsigned short nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
} DSUTIL_WAVECREATE_WAVEFORMATEX;

int __cdecl WaveCreateFile(char* pszFileName, HMMIO* phmmioOut, DSUTIL_WAVECREATE_WAVEFORMATEX* pwfxDest, DSUTIL_WAVECREATE_MMCKINFO* pckOut, DSUTIL_WAVECREATE_MMCKINFO* pckOutRIFF)
{
    int err;
    DWORD dwFactChunk;
    DSUTIL_WAVECREATE_MMCKINFO ckOut1;

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
