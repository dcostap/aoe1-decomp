/* VA: 00447D50 _WaveOpenFile */
/* Dsutil.c lines 496-619, 414 bytes */
/*
 * Context gate: PDB source Dsutil.c, C function, lines 496-619. The address
 * sequence and MMIO call anchors match the neighboring Dsutil.c functions.
 *
 * Exact-finish: the required source shape uses period WinMM declarations,
 * the named six-field PCM record, and #pragma function(memcpy). The pragma
 * preserves the shipped direct CRT call under /Oi-. A canonical PCMWAVEFORMAT
 * declaration changed the later WaveCopyUselessChunks owner, so it was walked
 * back. Raw FOURCC constants, a local WAVEFORMATEX overlay, an explicit
 * GlobalAlloc cast, and a duplicate HMMIO typedef were also tested and
 * removed or replaced without changing the exact result.
 */
#include <windows.h>
#include <mmsystem.h>

typedef struct DSUTIL_WAVEOPEN_PCM {
    WORD wFormatTag;
    WORD nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
    WORD wBitsPerSample;
} DSUTIL_WAVEOPEN_PCM;
/* Force the period CRT entry instead of VC5's aggregate-copy intrinsic. */
#pragma function(memcpy)
int __cdecl WaveOpenFile(char* pszFileName, HMMIO* phmmioIn, LPWAVEFORMATEX* ppwfxInfo, MMCKINFO* pckInRIFF)
{
    HMMIO hmmioIn;
    MMCKINFO ckIn;
    DSUTIL_WAVEOPEN_PCM pcmWaveFormat;
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

    if (pckInRIFF->ckid != mmioFOURCC('R', 'I', 'F', 'F') ||
        pckInRIFF->fccType != mmioFOURCC('W', 'A', 'V', 'E')) {
        err = 0xE101;
        goto error;
    }

    ckIn.ckid = mmioFOURCC('f', 'm', 't', ' ');
    if ((err = mmioDescend(hmmioIn, &ckIn, pckInRIFF, 0x10)) != 0) {
        goto error;
    }

    if (ckIn.cksize < sizeof(pcmWaveFormat)) {
        err = 0xE101;
        goto error;
    }

    if (mmioRead(hmmioIn, (char*)&pcmWaveFormat, sizeof(pcmWaveFormat)) != sizeof(pcmWaveFormat)) {
        err = 0xE102;
        goto error;
    }

    if (pcmWaveFormat.wFormatTag == WAVE_FORMAT_PCM) {
        cbExtraAlloc = 0;
    } else {
        if (mmioRead(hmmioIn, (char*)&cbExtraAlloc, sizeof(cbExtraAlloc)) != sizeof(cbExtraAlloc)) {
            err = 0xE102;
            goto error;
        }
    }

    if ((*ppwfxInfo = GlobalAlloc(0,
        (DWORD)cbExtraAlloc + 18)) == 0) {
        err = 0xE000;
        goto error;
    }

    memcpy(*ppwfxInfo, &pcmWaveFormat, sizeof(pcmWaveFormat));
    (*ppwfxInfo)->cbSize = cbExtraAlloc;

    if (cbExtraAlloc != 0) {
        if (mmioRead(hmmioIn, (char*)&(*ppwfxInfo)->cbSize + sizeof(cbExtraAlloc), cbExtraAlloc) != cbExtraAlloc) {
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
