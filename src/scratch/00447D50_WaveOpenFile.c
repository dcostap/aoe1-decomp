/* VA: 00447D50 _WaveOpenFile */
/* Dsutil.c lines 496-619, 414 bytes */
typedef unsigned int UINT; typedef unsigned long DWORD; typedef long LONG; typedef unsigned short WORD;
typedef struct DSUTIL_WAVEOPEN_MMCKINFO { DWORD ckid; DWORD cksize; DWORD fccType; DWORD dwDataOffset; DWORD dwFlags; } DSUTIL_WAVEOPEN_MMCKINFO;
typedef struct PCMWAVEFORMAT_LOCAL { WORD wFormatTag; WORD nChannels; DWORD nSamplesPerSec; DWORD nAvgBytesPerSec; WORD nBlockAlign; WORD wBitsPerSample; } PCMWAVEFORMAT_LOCAL;
typedef struct WAVEFORMATEX_LOCAL { WORD wFormatTag; WORD nChannels; DWORD nSamplesPerSec; DWORD nAvgBytesPerSec; WORD nBlockAlign; WORD wBitsPerSample; WORD cbSize; } WAVEFORMATEX_LOCAL;
/* Alias avoids VC5 treating the CRT copy as an intrinsic; original emits a direct call. */
void* __cdecl memcpy2(void*, const void*, UINT);
int __cdecl WaveOpenFile(char* pszFileName, HMMIO* phmmioIn, void** ppwfxInfo, DSUTIL_WAVEOPEN_MMCKINFO* pckInRIFF)
{
    HMMIO hmmioIn;
    DSUTIL_WAVEOPEN_MMCKINFO ckIn;
    PCMWAVEFORMAT_LOCAL pcmWaveFormat;
    WORD cbExtraAlloc;
    int err;

    *ppwfxInfo = 0;
    err = 0;
    hmmioIn = 0;

    if ((hmmioIn = mmioOpenA(pszFileName, 0, 0x10000)) == 0) {
        err = 0xE100;
        goto error;
    }

    if ((err = mmioDescend(hmmioIn, pckInRIFF, 0, 0)) != 0) {
        goto error;
    }

    if (pckInRIFF->ckid != 0x46464952 || pckInRIFF->fccType != 0x45564157) {
        err = 0xE101;
        goto error;
    }

    ckIn.ckid = 0x20746D66;
    if ((err = mmioDescend(hmmioIn, &ckIn, pckInRIFF, 0x10)) != 0) {
        goto error;
    }

    if (ckIn.cksize < sizeof(PCMWAVEFORMAT_LOCAL)) {
        err = 0xE101;
        goto error;
    }

    if (mmioRead(hmmioIn, (char*)&pcmWaveFormat, sizeof(PCMWAVEFORMAT_LOCAL)) != sizeof(PCMWAVEFORMAT_LOCAL)) {
        err = 0xE102;
        goto error;
    }

    if (pcmWaveFormat.wFormatTag == 1) {
        cbExtraAlloc = 0;
    } else {
        if (mmioRead(hmmioIn, (char*)&cbExtraAlloc, sizeof(cbExtraAlloc)) != sizeof(cbExtraAlloc)) {
            err = 0xE102;
            goto error;
        }
    }

    if ((*ppwfxInfo = GlobalAlloc(0, (DWORD)cbExtraAlloc + 18)) == 0) {
        err = 0xE000;
        goto error;
    }

    memcpy2(*ppwfxInfo, &pcmWaveFormat, sizeof(PCMWAVEFORMAT_LOCAL));
    ((WAVEFORMATEX_LOCAL*)*ppwfxInfo)->cbSize = cbExtraAlloc;

    if (cbExtraAlloc != 0) {
        if (mmioRead(hmmioIn, (char*)&((WAVEFORMATEX_LOCAL*)*ppwfxInfo)->cbSize + sizeof(cbExtraAlloc), cbExtraAlloc) != cbExtraAlloc) {
            err = 0xE101;
            goto error;
        }
    }

    if ((err = mmioAscend(hmmioIn, &ckIn, 0)) != 0) {
        goto error;
    }
    goto tempcleanup;

error:
    if (*ppwfxInfo != 0) {
        GlobalFree(*ppwfxInfo);
        *ppwfxInfo = 0;
    }
    if (hmmioIn != 0) {
        mmioClose(hmmioIn, 0);
        hmmioIn = 0;
    }

tempcleanup:
    *phmmioIn = hmmioIn;
    return err;
}
