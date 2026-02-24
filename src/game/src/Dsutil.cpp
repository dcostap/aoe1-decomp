// Decompiled: Dsutil.cpp
// SourceMap: C:/msdev/work/age1_x1/Dsutil.c
// NOTE: Originally a C file, not C++. All functions are free (non-member).

#include "../include/Dsutil.h"
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <timeapi.h>

// ============================================================================
// Streaming globals
// ============================================================================
static int          _ds_ready = 0;
static void*        _main_wnd = nullptr;
static IDirectSound* _lpDS = nullptr;
static IDirectSoundBuffer* _lpBuffer = nullptr;     // primary buffer reference
static IDirectSoundBuffer* _lpDSBStreamBuffer = nullptr;
static int          _bFileOpen = 0;
static int          _bPlaying = 0;
static int          _bTimerInstalled = 0;
static UINT         _uTimerID = 0;
static int          _uLastPercent = 100;
static int          _stream_paused = 0;

// Wave file state for streaming
static HMMIO        _hmmioIn = nullptr;
static tWAVEFORMATEX* _wiWave = nullptr;
static MMCKINFO     _ckIn;      // data chunk info
static MMCKINFO     _ckInRiff;  // riff chunk info

// Streaming buffer state
static IDirectSoundBuffer* _lpDSBStream2 = nullptr; // alias for _lpDSBStreamBuffer used in timer
static unsigned long _dwStreamBufSize = 0;   // total stream buffer size
static unsigned long _dwChunkSize = 0;       // size of one chunk
static unsigned long _dwWriteOffset = 0;     // current write cursor in stream buffer  
static unsigned long _dwPlayOffset = 0;      // last known play cursor
static unsigned long _dwBytesPlayed = 0;     // total bytes played
static int          _bEndOfFile = 0;         // reached end of wav
static int          _dwEndChunks = 0;        // chunks remaining after EOF
static int          _bLooping = 0;           // loop flag
static int          _bStopping = 0;          // stop request

// ============================================================================
// Offset: 0x004477D0
void ShowErrMsg() {
    // Empty in original
}

// ============================================================================
// Offset: 0x00447C60
int DSParseWaveResource(void* pvRes, tWAVEFORMATEX** ppWaveHeader, unsigned char** ppbData, unsigned long* pdwDataSize) {
    int* pRes = (int*)pvRes;

    if (ppWaveHeader != nullptr) *ppWaveHeader = nullptr;
    if (ppbData != nullptr) *ppbData = nullptr;
    if (pdwDataSize != nullptr) *pdwDataSize = 0;

    // Check RIFF header
    if (pRes[0] != 0x46464952 || pRes[2] != 0x45564157) { // 'RIFF', 'WAVE'
        return 0;
    }

    int* pEnd = (int*)((char*)(pRes + 3) + pRes[1] - 4);
    int* pCur = pRes + 3;

    while (pCur < pEnd) {
        unsigned long chunkId = *(unsigned long*)pCur;
        unsigned long chunkSize = *((unsigned long*)pCur + 1);
        unsigned char* chunkData = (unsigned char*)(pCur + 2);

        if (chunkId == 0x20746d66) { // 'fmt '
            if (ppWaveHeader != nullptr && *ppWaveHeader == nullptr) {
                if (chunkSize < 0x0E) return 0;
                *ppWaveHeader = (tWAVEFORMATEX*)chunkData;
                if ((ppbData == nullptr || *ppbData != nullptr) &&
                    (pdwDataSize == nullptr)) {
                    return 1;
                }
                if (pdwDataSize != nullptr && *pdwDataSize != 0) return 1;
            }
        } else if (chunkId == 0x61746164) { // 'data'
            if ((ppbData != nullptr && *ppbData == nullptr) ||
                (pdwDataSize != nullptr && *pdwDataSize == 0)) {
                if (ppbData != nullptr) *ppbData = chunkData;
                if (pdwDataSize != nullptr) *pdwDataSize = chunkSize;
                if (ppWaveHeader == nullptr) return 1;
                if (*ppWaveHeader != nullptr) return 1;
            }
        }

        pCur = (int*)((char*)chunkData + ((chunkSize + 1) & ~1));
    }

    return 0;
}

// ============================================================================
// Offset: 0x00447BC0
int DSFillSoundBuffer(IDirectSoundBuffer* pDSB, unsigned char* pbData, unsigned long dwDataSize) {
    void* pMem1 = nullptr;
    void* pMem2 = nullptr;
    unsigned long dwLen1 = 0;
    unsigned long dwLen2 = 0;

    if (pDSB == nullptr || pbData == nullptr || dwDataSize == 0) return 0;

    HRESULT hr = pDSB->Lock(0, dwDataSize, &pMem1, &dwLen1, &pMem2, &dwLen2, 0);
    if (SUCCEEDED(hr)) {
        memcpy(pMem1, pbData, dwLen1);
        if (pMem2 != nullptr) {
            memcpy(pMem2, pbData + dwLen1, dwLen2);
        }
        pDSB->Unlock(pMem1, dwLen1, pMem2, dwLen2);
        return 1;
    }
    return 0;
}

// ============================================================================
// Offset: 0x004478F0
int DSGetWaveResource(HMODULE hModule, void* pRes, tWAVEFORMATEX** ppWaveHeader, unsigned char** ppbData, unsigned long* pdwDataSize) {
    HRSRC hRsrc = FindResourceA(hModule, (LPCSTR)pRes, "WAVE");
    if (hRsrc != nullptr) {
        HGLOBAL hGlobal = LoadResource(hModule, hRsrc);
        if (hGlobal != nullptr) {
            void* pvRes = LockResource(hGlobal);
            if (pvRes != nullptr) {
                int result = DSParseWaveResource(pvRes, ppWaveHeader, ppbData, pdwDataSize);
                if (result != 0) return 1;
            }
        }
    }
    return 0;
}

// ============================================================================
// Offset: 0x004477E0
IDirectSoundBuffer* DSLoadSoundBuffer(IDirectSound* pDS, void* pRes) {
    DSBUFFERDESC dsBD;
    tWAVEFORMATEX* pwfx = nullptr;
    unsigned char* pbData = nullptr;
    unsigned long dwDataSize = 0;
    IDirectSoundBuffer* pDSB = nullptr;

    memset(&dsBD, 0, sizeof(dsBD));

    if (!DSGetWaveResource(nullptr, pRes, &pwfx, &pbData, &dwDataSize)) {
        return nullptr;
    }

    dsBD.dwSize = sizeof(DSBUFFERDESC);
    dsBD.dwFlags = DSBCAPS_STATIC | DSBCAPS_CTRLVOLUME;
    dsBD.dwBufferBytes = dwDataSize;
    dsBD.lpwfxFormat = pwfx;

    HRESULT hr = pDS->CreateSoundBuffer(&dsBD, &pDSB, nullptr);
    if (FAILED(hr)) {
        return nullptr;
    }

    if (!DSFillSoundBuffer(pDSB, pbData, dwDataSize)) {
        pDSB->Release();
        return nullptr;
    }

    return pDSB;
}

// ============================================================================
// Offset: 0x00447890
int DSReloadSoundBuffer(IDirectSoundBuffer* pDSB, void* pRes) {
    tWAVEFORMATEX* pwfx = nullptr;
    unsigned char* pbData = nullptr;
    unsigned long dwDataSize = 0;

    if (!DSGetWaveResource(nullptr, pRes, &pwfx, &pbData, &dwDataSize)) {
        return 0;
    }

    HRESULT hr = pDSB->Restore();
    if (SUCCEEDED(hr)) {
        if (DSFillSoundBuffer(pDSB, pbData, dwDataSize)) {
            return 1;
        }
    }
    return 0;
}

// ============================================================================
// Offset: 0x00447950
// SndObj layout: [pbData(4), cbData(4), nBufs(4), curBuf(4), pDSB[nBufs]...]
void* SndObjCreate(IDirectSound* pDS, void* pRes, int nConcurrent) {
    tWAVEFORMATEX* pwfx = nullptr;
    unsigned char* pbData = nullptr;
    unsigned long dwDataSize = 0;

    if (!DSGetWaveResource(nullptr, pRes, &pwfx, &pbData, &dwDataSize)) {
        return nullptr;
    }

    if (nConcurrent < 1) nConcurrent = 1;

    unsigned long* pSO = (unsigned long*)LocalAlloc(LPTR, nConcurrent * 4 + 0x10);
    if (pSO == nullptr) return nullptr;

    pSO[0] = (unsigned long)pbData;
    pSO[1] = dwDataSize;
    pSO[2] = nConcurrent;
    pSO[3] = 0; // current buffer index

    IDirectSoundBuffer* pDSB = DSLoadSoundBuffer(pDS, pRes);
    pSO[4] = (unsigned long)pDSB;

    for (int i = 1; i < nConcurrent; i++) {
        IDirectSoundBuffer* pDup = nullptr;
        HRESULT hr = pDS->DuplicateSoundBuffer(pDSB, &pDup);
        if (FAILED(hr)) {
            pDup = DSLoadSoundBuffer(pDS, pRes);
            if (pDup == nullptr) {
                SndObjDestroy(pSO);
                return nullptr;
            }
        }
        pSO[4 + i] = (unsigned long)pDup;
    }

    return pSO;
}

// ============================================================================
// Offset: 0x00447A20
void SndObjDestroy(void* pSO) {
    if (pSO == nullptr) return;
    unsigned long* p = (unsigned long*)pSO;
    int nBufs = (int)p[2];
    for (int i = 0; i < nBufs; i++) {
        IDirectSoundBuffer* pDSB = (IDirectSoundBuffer*)p[4 + i];
        if (pDSB != nullptr) {
            pDSB->Release();
            p[4 + i] = 0;
        }
    }
    LocalFree(pSO);
}

// ============================================================================
// Offset: 0x00447A60
IDirectSoundBuffer* SndObjGetFreeBuffer(void* pSO) {
    if (pSO == nullptr) return nullptr;
    unsigned long* p = (unsigned long*)pSO;

    int curBuf = (int)p[3];
    IDirectSoundBuffer* pDSB = (IDirectSoundBuffer*)p[curBuf + 4];
    if (pDSB == nullptr) return nullptr;

    DWORD dwStatus = 0;
    HRESULT hr = pDSB->GetStatus(&dwStatus);

    if (SUCCEEDED(hr) && (dwStatus & DSBSTATUS_PLAYING)) {
        int nBufs = (int)p[2];
        if (nBufs < 2) return nullptr;

        p[3] = curBuf + 1;
        if ((int)p[3] >= nBufs) p[3] = 0;

        pDSB = (IDirectSoundBuffer*)p[p[3] + 4];
        hr = pDSB->GetStatus(&dwStatus);
        if (SUCCEEDED(hr) && (dwStatus & DSBSTATUS_PLAYING)) {
            pDSB->Stop();
            pDSB->SetCurrentPosition(0);
        }
    }

    if (pDSB != nullptr && (dwStatus & DSBSTATUS_BUFFERLOST)) {
        hr = pDSB->Restore();
        if (SUCCEEDED(hr)) {
            if (DSFillSoundBuffer(pDSB, (unsigned char*)p[0], p[1])) {
                return pDSB;
            }
        }
        return nullptr;
    }

    return pDSB;
}

// ============================================================================
// Offset: 0x00447B20
int SndObjPlay(void* pSO, DWORD dwFlags) {
    if (pSO == nullptr) return 0;
    unsigned long* p = (unsigned long*)pSO;

    // If looping requested and only 1 buffer, just play with that flag
    if ((dwFlags & DSBPLAY_LOOPING) == 0 || p[2] == 1) {
        IDirectSoundBuffer* pDSB = SndObjGetFreeBuffer(pSO);
        if (pDSB != nullptr) {
            HRESULT hr = pDSB->Play(0, 0, dwFlags);
            return SUCCEEDED(hr) ? 1 : 0;
        }
    }
    return 0;
}

// ============================================================================
// Offset: 0x00447B70
int SndObjStop(void* pSO) {
    if (pSO == nullptr) return 0;
    unsigned long* p = (unsigned long*)pSO;
    int nBufs = (int)p[2];
    for (int i = 0; i < nBufs; i++) {
        IDirectSoundBuffer* pDSB = (IDirectSoundBuffer*)p[4 + i];
        if (pDSB != nullptr) {
            pDSB->Stop();
            pDSB->SetCurrentPosition(0);
        }
    }
    return 1;
}

// ============================================================================
// Wave File I/O functions
// ============================================================================

// Offset: 0x00447D50
int WaveOpenFile(char* pszFileName, void** phmmioIn, tWAVEFORMATEX** ppwfxInfo, MMCKINFO* pckInRiff) {
    HMMIO hmmio;
    MMCKINFO ckIn;
    PCMWAVEFORMAT pcmWaveFormat;

    *ppwfxInfo = nullptr;

    hmmio = mmioOpenA(pszFileName, nullptr, MMIO_READ | MMIO_ALLOCBUF);
    if (hmmio == nullptr) return 0xE100;

    MMRESULT mr = mmioDescend(hmmio, pckInRiff, nullptr, 0);
    if (mr != 0) goto error;

    if (pckInRiff->ckid != FOURCC_RIFF || pckInRiff->fccType != mmioFOURCC('W','A','V','E')) {
        mr = 0xE101;
        goto error;
    }

    ckIn.ckid = mmioFOURCC('f','m','t',' ');
    mr = mmioDescend(hmmio, &ckIn, pckInRiff, MMIO_FINDCHUNK);
    if (mr != 0) goto error;

    if (ckIn.cksize < sizeof(PCMWAVEFORMAT)) {
        mr = 0xE101;
        goto error;
    }

    if (mmioRead(hmmio, (HPSTR)&pcmWaveFormat, sizeof(PCMWAVEFORMAT)) != sizeof(PCMWAVEFORMAT)) {
        mr = 0xE102;
        goto error;
    }

    WORD cbExtraBytes = 0;
    if (pcmWaveFormat.wf.wFormatTag != WAVE_FORMAT_PCM) {
        if (mmioRead(hmmio, (HPSTR)&cbExtraBytes, sizeof(WORD)) != sizeof(WORD)) {
            mr = 0xE102;
            goto error;
        }
    }

    *ppwfxInfo = (tWAVEFORMATEX*)GlobalAlloc(GPTR, sizeof(tWAVEFORMATEX) + cbExtraBytes);
    if (*ppwfxInfo == nullptr) {
        mr = 0xE000;
        goto error;
    }

    memcpy(*ppwfxInfo, &pcmWaveFormat, sizeof(PCMWAVEFORMAT));
    (*ppwfxInfo)->cbSize = cbExtraBytes;

    if (cbExtraBytes != 0) {
        if (mmioRead(hmmio, (HPSTR)(((char*)*ppwfxInfo) + sizeof(WAVEFORMATEX)), cbExtraBytes) != cbExtraBytes) {
            mr = 0xE102;
            goto error;
        }
    }

    mr = mmioAscend(hmmio, &ckIn, 0);
    if (mr != 0) goto error;

    *(HMMIO*)phmmioIn = hmmio;
    return 0;

error:
    if (*ppwfxInfo != nullptr) {
        GlobalFree(*ppwfxInfo);
        *ppwfxInfo = nullptr;
    }
    if (hmmio != nullptr) {
        mmioClose(hmmio, 0);
    }
    *(HMMIO*)phmmioIn = nullptr;
    return mr;
}

// ============================================================================
// Offset: 0x00447EF0
int WaveStartDataRead(void** phmmioIn, MMCKINFO* pckIn, MMCKINFO* pckInRiff) {
    HMMIO hmmio = *(HMMIO*)phmmioIn;
    int seekResult = mmioSeek(hmmio, pckInRiff->dwDataOffset + 4, SEEK_SET);
    if (seekResult == -1) return 1;

    pckIn->ckid = mmioFOURCC('d','a','t','a');
    MMRESULT mr = mmioDescend(hmmio, pckIn, pckInRiff, MMIO_FINDCHUNK);
    return mr;
}

// ============================================================================
// Offset: 0x00447F40
int WaveReadFile(HMMIO hmmioIn, unsigned long cbRead, unsigned char* pbDest, MMCKINFO* pckIn, unsigned long* pcbActualRead) {
    MMIOINFO mmioinfoIn;

    *pcbActualRead = 0;

    if (mmioGetInfo(hmmioIn, &mmioinfoIn, 0) != 0) {
        return 1;
    }

    unsigned long cbDataIn = pckIn->cksize;
    if (cbDataIn < cbRead) cbRead = cbDataIn;
    pckIn->cksize -= cbRead;

    unsigned long cbActual = 0;
    while (cbActual < cbRead) {
        if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead) {
            if (mmioAdvance(hmmioIn, &mmioinfoIn, MMIO_READ) != 0) {
                *pcbActualRead = 0;
                return 0xE103;
            }
            if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead) {
                *pcbActualRead = 0;
                return 0xE103;
            }
        }

        unsigned long cbToCopy = (unsigned long)(mmioinfoIn.pchEndRead - mmioinfoIn.pchNext);
        if (cbRead - cbActual < cbToCopy) cbToCopy = cbRead - cbActual;

        memcpy(pbDest + cbActual, mmioinfoIn.pchNext, cbToCopy);
        cbActual += cbToCopy;
        mmioinfoIn.pchNext += cbToCopy;
    }

    if (mmioSetInfo(hmmioIn, &mmioinfoIn, 0) != 0) {
        *pcbActualRead = 0;
        return 1;
    }

    *pcbActualRead = cbRead;
    return 0;
}

// ============================================================================
// Offset: 0x00448040
int WaveCloseReadFile(HMMIO* phmmio, tWAVEFORMATEX** ppwfx) {
    if (*ppwfx != nullptr) {
        GlobalFree(*ppwfx);
        *ppwfx = nullptr;
    }
    if (*phmmio != nullptr) {
        mmioClose(*phmmio, 0);
        *phmmio = nullptr;
    }
    return 0;
}

// ============================================================================
// Offset: 0x00448080
int WaveCreateFile(char* pszFileName, HMMIO* phmmioOut, tWAVEFORMATEX* pwfxDest, MMCKINFO* pckOut, MMCKINFO* pckOutRIFF) {
    // Fully verified. Source of truth: dsutil.cpp.asm @ 0x00448080
    *phmmioOut = mmioOpenA(pszFileName, nullptr, MMIO_WRITE | MMIO_CREATE | MMIO_ALLOCBUF);
    if (*phmmioOut == nullptr) {
        return 0xE104; // ERROR_CANNOT_WRITE
    }

    pckOutRIFF->cksize = 0;
    pckOutRIFF->fccType = mmioFOURCC('W','A','V','E');
    int mmr = mmioCreateChunk(*phmmioOut, pckOutRIFF, MMIO_CREATERIFF);
    if (mmr != 0) {
        return mmr;
    }

    pckOut->ckid = mmioFOURCC('f','m','t',' ');
    pckOut->cksize = 0x10;
    mmr = mmioCreateChunk(*phmmioOut, pckOut, 0);
    if (mmr != 0) {
        return mmr;
    }

    if (pwfxDest->wFormatTag == 1) {
        int wrote = mmioWrite(*phmmioOut, (HPSTR)pwfxDest, 0x10);
        if (wrote != 0x10) {
            return 0xE104;
        }
    } else {
        unsigned int cb = (unsigned int)(unsigned short)pwfxDest->cbSize + 0x12;
        int wrote = mmioWrite(*phmmioOut, (HPSTR)pwfxDest, (int)cb);
        if (wrote != (int)cb) {
            return 0xE104;
        }
    }

    mmr = mmioAscend(*phmmioOut, pckOut, 0);
    if (mmr != 0) {
        return mmr;
    }

    MMCKINFO ckFact;
    ckFact.ckid = mmioFOURCC('f','a','c','t');
    ckFact.cksize = 0;
    mmr = mmioCreateChunk(*phmmioOut, &ckFact, 0);
    if (mmr != 0) {
        return mmr;
    }

    DWORD dwFactChunk;
    int wroteFact = mmioWrite(*phmmioOut, (HPSTR)&dwFactChunk, sizeof(DWORD));
    if (wroteFact != sizeof(DWORD)) {
        return 0xE104;
    }

    if (mmioAscend(*phmmioOut, &ckFact, 0) != 0) {
        return 0xE104;
    }

    return 0;
}

// ============================================================================
// Offset: 0x004481A0
void WaveStartDataWrite(HMMIO* phmmioOut, MMCKINFO* pckOut, MMIOINFO* pmmioinfoOut) {
    pckOut->ckid = mmioFOURCC('d','a','t','a');
    pckOut->cksize = 0;
    int result = mmioCreateChunk(*phmmioOut, pckOut, 0);
    if (result == 0) {
        mmioGetInfo(*phmmioOut, pmmioinfoOut, 0);
    }
}

// ============================================================================
// Offset: 0x004481E0
void WaveWriteFile(HMMIO hmmioOut, unsigned long cbWrite, unsigned char* pbSrc, MMCKINFO* pckOut, unsigned long* pcbActualWrite, MMIOINFO* pmmioinfoOut) {
    *pcbActualWrite = 0;
    unsigned long cbWritten = 0;
    while (cbWritten < cbWrite) {
        if (pmmioinfoOut->pchNext == pmmioinfoOut->pchEndWrite) {
            pmmioinfoOut->dwFlags |= MMIO_DIRTY;
            if (mmioAdvance(hmmioOut, pmmioinfoOut, MMIO_WRITE) != 0) {
                return;
            }
        }
        *(pmmioinfoOut->pchNext) = pbSrc[cbWritten];
        pmmioinfoOut->pchNext++;
        cbWritten++;
        *pcbActualWrite = *pcbActualWrite + 1;
    }
}

// ============================================================================
// Offset: 0x00448250
int WaveCloseWriteFile(HMMIO* phmmioOut, MMCKINFO* pckOut, MMCKINFO* pckOutRIFF, MMIOINFO* pmmioinfoOut, unsigned long cSamples) {
    if (*phmmioOut == nullptr) return 0;

    pmmioinfoOut->dwFlags |= MMIO_DIRTY;
    if (mmioSetInfo(*phmmioOut, pmmioinfoOut, 0) != 0) goto cleanup;
    if (mmioAscend(*phmmioOut, pckOut, 0) != 0) goto cleanup;
    if (mmioAscend(*phmmioOut, pckOutRIFF, 0) != 0) goto cleanup;

    mmioSeek(*phmmioOut, 0, SEEK_SET);
    if (mmioDescend(*phmmioOut, pckOutRIFF, nullptr, 0) != 0) goto cleanup;

    {
        MMCKINFO ckFact;
        ckFact.ckid = mmioFOURCC('f','a','c','t');
        if (mmioDescend(*phmmioOut, &ckFact, pckOutRIFF, MMIO_FINDCHUNK) != 0) {
            goto cleanup_ok;
        }
        mmioWrite(*phmmioOut, (HPSTR)&cSamples, sizeof(DWORD));
        mmioAscend(*phmmioOut, &ckFact, 0);
        mmioAscend(*phmmioOut, pckOutRIFF, 0);
    }

cleanup_ok:
    if (*phmmioOut != nullptr) {
        mmioClose(*phmmioOut, 0);
        *phmmioOut = nullptr;
    }
    return 0;

cleanup:
    if (*phmmioOut != nullptr) {
        mmioClose(*phmmioOut, 0);
        *phmmioOut = nullptr;
    }
    return 1;
}

// ============================================================================
// Offset: 0x00448340
int WaveCopyUselessChunks(HMMIO* phmmioIn, MMCKINFO* pckIn, MMCKINFO* pckInRiff) {
    int seekResult = mmioSeek(*phmmioIn, pckInRiff->dwDataOffset + 4, SEEK_SET);
    if (seekResult == -1) return 0xE102;

    MMCKINFO ck;
    int result = mmioDescend(*phmmioIn, &ck, pckInRiff, 0);
    while (result == 0 && (ck.dwDataOffset + ck.cksize) <= (pckInRiff->cksize + pckInRiff->dwDataOffset)) {
        if (ck.ckid != mmioFOURCC(' ','P','A','D') &&
            (ck.ckid == mmioFOURCC('D','I','S','P') || ck.ckid == mmioFOURCC('p','l','s','t'))) {
            riffCopyChunk(*phmmioIn, *phmmioIn, &ck);
        }
        mmioAscend(*phmmioIn, &ck, 0);
        result = mmioDescend(*phmmioIn, &ck, pckInRiff, 0);
    }

    mmioSeek(*phmmioIn, pckInRiff->dwDataOffset + 4, SEEK_SET);
    return 0;
}

// ============================================================================
// Offset: 0x00448400
int riffCopyChunk(HMMIO hmmioSrc, HMMIO hmmioDst, MMCKINFO* pckIn) {
    MMCKINFO ckOut;
    void* pBuf;
    HGLOBAL hBuf;

    ckOut.ckid = pckIn->ckid;
    ckOut.cksize = pckIn->cksize;

    hBuf = GlobalAlloc(GMEM_MOVEABLE, 0x42);
    pBuf = GlobalLock(hBuf);
    if (pBuf == nullptr) return 0;

    if (mmioCreateChunk(hmmioDst, &ckOut, 0) != 0) goto fail;

    {
        int cbRead = (int)pckIn->cksize;
        int actual = mmioRead(hmmioSrc, (HPSTR)pBuf, cbRead);
        if (actual != cbRead) goto fail;
        int written = mmioWrite(hmmioDst, (HPSTR)pBuf, cbRead);
        if (written != cbRead) goto fail;
        if (mmioAscend(hmmioDst, &ckOut, 0) != 0) goto fail;
    }

    {
        HGLOBAL h = GlobalHandle(pBuf);
        GlobalUnlock(h);
        h = GlobalHandle(pBuf);
        GlobalFree(h);
    }
    return 1;

fail:
    {
        HGLOBAL h = GlobalHandle(pBuf);
        GlobalUnlock(h);
        h = GlobalHandle(pBuf);
        GlobalFree(h);
    }
    return 0;
}

// ============================================================================
// Offset: 0x004484D0
int WaveLoadFile(char* pszFileName, unsigned long* pcbWaveSize, unsigned long* pcbHeaderSize, unsigned char** ppbWaveData, tWAVEFORMATEX** ppWaveHeader) {
    HMMIO hmmio = nullptr;
    MMCKINFO ckIn;
    MMCKINFO ckInRiff;

    *ppbWaveData = nullptr;
    *ppWaveHeader = nullptr;
    *pcbWaveSize = 0;

    int err = WaveOpenFile(pszFileName, (void**)&hmmio, ppWaveHeader, &ckInRiff);
    if (err != 0) goto error;

    err = WaveStartDataRead((void**)&hmmio, &ckIn, &ckInRiff);
    if (err != 0) goto error;

    *ppbWaveData = (unsigned char*)GlobalAlloc(GPTR, ckIn.cksize);
    if (*ppbWaveData == nullptr) {
        err = 0xE000;
        goto error;
    }

    {
        unsigned long cbActualRead = 0;
        err = WaveReadFile(hmmio, ckIn.cksize, *ppbWaveData, &ckIn, &cbActualRead);
        if (err != 0) goto error;
        *pcbWaveSize = cbActualRead;
    }

    if (hmmio != nullptr) {
        mmioClose(hmmio, 0);
    }
    return 0;

error:
    if (*ppbWaveData != nullptr) {
        GlobalFree(*ppbWaveData);
        *ppbWaveData = nullptr;
    }
    if (*ppWaveHeader != nullptr) {
        GlobalFree(*ppWaveHeader);
        *ppWaveHeader = nullptr;
    }
    if (hmmio != nullptr) {
        mmioClose(hmmio, 0);
    }
    return err;
}

// ============================================================================
// Offset: 0x004485C0
void WaveSaveFile(char* pszFileName, unsigned long cbWaveSize, unsigned long cSamples, unsigned char* pbWaveData, tWAVEFORMATEX* pwfx) {
    HMMIO hmmioOut = nullptr;
    MMCKINFO ckOut;
    MMCKINFO ckOutRIFF;
    MMIOINFO mmioinfoOut;

    int err = WaveCreateFile(pszFileName, &hmmioOut, pwfx, &ckOut, &ckOutRIFF);
    if (err != 0) return;

    memset(&mmioinfoOut, 0, sizeof(mmioinfoOut));
    WaveStartDataWrite(&hmmioOut, &ckOut, &mmioinfoOut);

    unsigned long cbActualWrite = 0;
    WaveWriteFile(hmmioOut, cbWaveSize, pbWaveData, &ckOut, &cbActualWrite, &mmioinfoOut);

    WaveCloseWriteFile(&hmmioOut, &ckOut, &ckOutRIFF, &mmioinfoOut, cSamples);
}

// ============================================================================
// DirectSound Streaming
// ============================================================================

// Offset: 0x00448660
void ds_stream_init(void* main_wnd, IDirectSound* lpDS, IDirectSoundBuffer* lpBuffer) {
    _uLastPercent = 100;
    _lpDSBStreamBuffer = nullptr;
    _bFileOpen = 0;
    _bPlaying = 0;
    _bTimerInstalled = 0;
    _uTimerID = 0;
    _main_wnd = main_wnd;
    _lpBuffer = lpBuffer;
    _lpDS = lpDS;
    _ds_ready = 1;
}

// ============================================================================
// Offset: 0x004486B0
void ds_stream_exit() {
    if (_ds_ready != 0) {
        if (_bFileOpen != 0 || _bPlaying != 0 || _bTimerInstalled != 0) {
            ds_stream_stop();
        }
        _ds_ready = 0;
    }
}

// ============================================================================
// Offset: 0x004486F0
int ds_stream_file(char* filename, int loop, long volume) {
    DSBUFFERDESC dsbd;
    HRESULT hr;

    if (_bFileOpen != 0 || _bPlaying != 0 || _bTimerInstalled != 0) {
        ds_stream_stop();
    }

    _stream_paused = 0;

    // Open the wave file
    int err = WaveOpenFile(filename, (void**)&_hmmioIn, &_wiWave, &_ckInRiff);
    if (err != 0) return 0;

    // Only support PCM format
    if (_wiWave->wFormatTag != WAVE_FORMAT_PCM) {
        WaveCloseReadFile(&_hmmioIn, &_wiWave);
        return 0;
    }

    err = WaveStartDataRead((void**)&_hmmioIn, &_ckIn, &_ckInRiff);
    if (err != 0) {
        WaveCloseReadFile(&_hmmioIn, &_wiWave);
        return 0;
    }

    // Calculate buffer sizes: chunk = nAvgBytesPerSec * 120 / 600, buffer = chunk * 6
    _dwChunkSize = (_wiWave->nAvgBytesPerSec * 120) / 600;
    _dwStreamBufSize = _dwChunkSize * 6;

    // Create streaming buffer
    memset(&dsbd, 0, sizeof(dsbd));
    dsbd.dwSize = sizeof(DSBUFFERDESC);
    dsbd.dwFlags = DSBCAPS_STATIC | DSBCAPS_CTRLVOLUME;
    dsbd.dwBufferBytes = _dwStreamBufSize;
    dsbd.lpwfxFormat = _wiWave;

    hr = _lpDS->CreateSoundBuffer(&dsbd, &_lpDSBStreamBuffer, nullptr);
    if (FAILED(hr)) return 0;

    _lpDSBStream2 = _lpDSBStreamBuffer;
    _bEndOfFile = 0;
    _dwEndChunks = 0;
    _bLooping = loop;

    // Lock and fill the initial buffer
    void* lpWrite1 = nullptr;
    void* lpWrite2 = nullptr;
    unsigned long dwLen1 = 0;
    unsigned long dwLen2 = 0;

    hr = _lpDSBStreamBuffer->Lock(0, _dwStreamBufSize, &lpWrite1, &dwLen1, &lpWrite2, &dwLen2, 0);
    if (FAILED(hr)) {
        WaveCloseReadFile(&_hmmioIn, &_wiWave);
        return 0;
    }

    // Fill the buffer
    unsigned long cbActualRead = 0;
    WaveReadFile(_hmmioIn, dwLen1, (unsigned char*)lpWrite1, &_ckIn, &cbActualRead);

    if (cbActualRead < dwLen1) {
        if (!loop) {
            // Not looping: fill remainder with silence, mark end
            _dwEndChunks = cbActualRead / _dwChunkSize;
            _bEndOfFile = 1;
            unsigned char silence = (_wiWave->wBitsPerSample == 8) ? 0x80 : 0;
            memset((unsigned char*)lpWrite1 + cbActualRead, silence, dwLen1 - cbActualRead);
        } else {
            // Looping: re-read from start
            while (cbActualRead < dwLen1) {
                unsigned long remaining = dwLen1 - cbActualRead;
                WaveStartDataRead((void**)&_hmmioIn, &_ckIn, &_ckInRiff);
                unsigned long cbRead2 = 0;
                WaveReadFile(_hmmioIn, remaining, (unsigned char*)lpWrite1 + cbActualRead, &_ckIn, &cbRead2);
                cbActualRead += cbRead2;
            }
        }
    }

    _lpDSBStreamBuffer->Unlock(lpWrite1, dwLen1, lpWrite2, 0);

    _dwWriteOffset = 0;
    _dwPlayOffset = 0;
    _dwBytesPlayed = 0;
    _bStopping = 0;
    _bFileOpen = 1;

    SendMessageA((HWND)_main_wnd, 0x502, 0, 0);

    _lpDSBStreamBuffer->SetCurrentPosition(0);
    _lpDSBStreamBuffer->SetVolume(volume);
    _lpDSBStreamBuffer->Play(0, 0, DSBPLAY_LOOPING);

    MMRESULT mmr = timeBeginPeriod(50);
    if (mmr == TIMERR_NOERROR) {
        _uTimerID = timeSetEvent(50, 10, ds_stream_time_func, 0, TIME_PERIODIC);
        if (_uTimerID != 0) {
            _bTimerInstalled = 1;
        }
        _bPlaying = 1;
        return 1;
    }

    _lpDSBStreamBuffer->Stop();
    _bTimerInstalled = 0;
    _bPlaying = 0;
    return 0;
}

// ============================================================================
// Offset: 0x00448A40
int ds_stream_volume(long volume) {
    if (_lpDSBStreamBuffer == nullptr) return 0;
    HRESULT hr = _lpDSBStreamBuffer->SetVolume(volume);
    return (hr == DS_OK) ? 1 : 0;
}

// ============================================================================
// Offset: 0x00448A60
void ds_stream_pause() {
    _stream_paused = 1;
}

// ============================================================================
// Offset: 0x00448A70
int ds_stream_resume() {
    _stream_paused = 0;
    return 1;
}

// ============================================================================
// Offset: 0x00448A80
int ds_stream_stop() {
    _bStopping = 1;

    if (_bTimerInstalled != 0) {
        _bTimerInstalled = 0;
        timeKillEvent(_uTimerID);
        timeEndPeriod(50);
    }

    if (_bPlaying != 0) {
        _bPlaying = 0;
        if (_lpDSBStreamBuffer != nullptr) {
            _lpDSBStreamBuffer->Stop();
        }
    }

    if (_bFileOpen != 0) {
        if (_wiWave != nullptr) {
            WaveCloseReadFile(&_hmmioIn, &_wiWave);
            _wiWave = nullptr;
        }
        if (_lpDSBStreamBuffer != nullptr) {
            _lpDSBStreamBuffer->Release();
            _lpDSBStreamBuffer = nullptr;
            _lpDSBStream2 = nullptr;
        }
        _bFileOpen = 0;
    }

    return 1;
}

// ============================================================================
// Offset: 0x00448B30
int ds_stream_messages(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    if (msg == 0x500) {
        ds_stream_stop();
    } else if (msg == 0x502) {
        // Progress message — compute percentage
        // Simplified: just return 0
    }
    return 0;
}

// ============================================================================
// Offset: 0x00448BA0
// Timer callback for streaming — fills next chunk of audio data
static volatile int _timer_guard = 0;

void CALLBACK ds_stream_time_func(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2) {
    if (_timer_guard != 0) return;
    if (_stream_paused != 0) return;

    _timer_guard = 1;

    if (_bStopping != 0) {
        _timer_guard = 0;
        return;
    }

    if (_lpDSBStream2 == nullptr) {
        _timer_guard = 0;
        return;
    }

    // Get current play position
    DWORD dwPlay = 0, dwWrite = 0;
    _lpDSBStream2->GetCurrentPosition(&dwPlay, &dwWrite);

    // If play cursor is still in the same chunk we wrote, skip
    if (dwPlay >= _dwWriteOffset && dwPlay < _dwWriteOffset + _dwChunkSize) {
        _timer_guard = 0;
        return;
    }

    // End-of-file countdown
    if (_bEndOfFile != 0 && _dwEndChunks == 0) {
        if (_bStopping != 0) {
            _timer_guard = 0;
            return;
        }
        _bStopping = 1;
        PostMessageA((HWND)_main_wnd, 0x500, 0, 0);
        _timer_guard = 0;
        return;
    }

    // Track bytes played for progress
    DWORD dwPlayAdj = dwPlay;
    if (dwPlay < _dwPlayOffset) {
        dwPlayAdj = _dwStreamBufSize + dwPlay;
    }
    _dwBytesPlayed += (dwPlayAdj - _dwPlayOffset);
    _dwPlayOffset = dwPlay;

    PostMessageA((HWND)_main_wnd, 0x502, 0, 0);

    if (_bEndOfFile != 0 && _dwEndChunks > 0) {
        // Count down end chunks, fill silence
        _dwEndChunks--;
        if (_dwEndChunks >= 2) {
            // Fill chunk with silence
            void* lpWrite1 = nullptr;
            void* lpWrite2 = nullptr;
            unsigned long dwLen1 = 0, dwLen2 = 0;

            HRESULT hr = _lpDSBStream2->Lock(_dwWriteOffset, _dwChunkSize, &lpWrite1, &dwLen1, &lpWrite2, &dwLen2, 0);
            if (FAILED(hr)) {
                _timer_guard = 0;
                return;
            }

            unsigned char silence = (_wiWave != nullptr && _wiWave->wBitsPerSample == 8) ? 0x80 : 0;
            if (lpWrite1 != nullptr) memset(lpWrite1, silence, dwLen1);

            _lpDSBStream2->Unlock(lpWrite1, dwLen1, lpWrite2, dwLen2);
        }

        _dwWriteOffset += _dwChunkSize;
        if (_dwWriteOffset >= _dwStreamBufSize) {
            _dwWriteOffset -= _dwStreamBufSize;
        }
        _timer_guard = 0;
        return;
    }

    // Normal streaming: fill next chunk
    if (_lpDSBStream2 == nullptr) {
        _timer_guard = 0;
        return;
    }

    void* lpWrite1 = nullptr;
    void* lpWrite2 = nullptr;
    unsigned long dwLen1 = 0, dwLen2 = 0;

    HRESULT hr = _lpDSBStream2->Lock(_dwWriteOffset, _dwChunkSize, &lpWrite1, &dwLen1, &lpWrite2, &dwLen2, 0);
    if (FAILED(hr)) {
        _timer_guard = 0;
        return;
    }

    if (_bStopping != 0 || lpWrite1 == nullptr) {
        // Fill with silence if stopping
        if (lpWrite1 != nullptr && _wiWave != nullptr) {
            unsigned char silence = (_wiWave->wBitsPerSample == 8) ? 0x80 : 0;
            memset(lpWrite1, silence, dwLen1);
        }
    } else {
        unsigned long cbActualRead = 0;
        WaveReadFile(_hmmioIn, dwLen1, (unsigned char*)lpWrite1, &_ckIn, &cbActualRead);

        if (cbActualRead < dwLen1) {
            if (!_bLooping) {
                // End of file, not looping
                if (_wiWave != nullptr && lpWrite1 != nullptr) {
                    unsigned char silence = (_wiWave->wBitsPerSample == 8) ? 0x80 : 0;
                    memset((unsigned char*)lpWrite1 + cbActualRead, silence, dwLen1 - cbActualRead);
                }
                _bEndOfFile = 1;
                // Calculate how many chunks remain
                if (_dwWriteOffset < dwPlay) {
                    _dwEndChunks = (_dwWriteOffset + _dwStreamBufSize - dwPlay) / _dwChunkSize;
                } else {
                    _dwEndChunks = (_dwWriteOffset - dwPlay) / _dwChunkSize;
                }
            } else {
                // Looping: restart from beginning
                while (cbActualRead < dwLen1) {
                    unsigned long remaining = dwLen1 - cbActualRead;
                    WaveStartDataRead((void**)&_hmmioIn, &_ckIn, &_ckInRiff);
                    unsigned long cbRead2 = 0;
                    WaveReadFile(_hmmioIn, remaining, (unsigned char*)lpWrite1 + cbActualRead, &_ckIn, &cbRead2);
                    cbActualRead += cbRead2;
                }
            }
        }
    }

    // Fill second part if wrapped
    if (lpWrite2 != nullptr && dwLen2 > 0) {
        if (_bStopping != 0) {
            if (_wiWave != nullptr) {
                unsigned char silence = (_wiWave->wBitsPerSample == 8) ? 0x80 : 0;
                memset(lpWrite2, silence, dwLen2);
            }
        } else {
            unsigned long cbActualRead2 = 0;
            WaveReadFile(_hmmioIn, dwLen2, (unsigned char*)lpWrite2, &_ckIn, &cbActualRead2);
            if (cbActualRead2 < dwLen2) {
                if (!_bLooping) {
                    if (_wiWave != nullptr) {
                        unsigned char silence = (_wiWave->wBitsPerSample == 8) ? 0x80 : 0;
                        memset((unsigned char*)lpWrite2 + cbActualRead2, silence, dwLen2 - cbActualRead2);
                    }
                    _bEndOfFile = 1;
                    if (_dwWriteOffset < dwPlay) {
                        _dwEndChunks = (_dwWriteOffset + _dwStreamBufSize - dwPlay) / _dwChunkSize;
                    } else {
                        _dwEndChunks = (_dwWriteOffset - dwPlay) / _dwChunkSize;
                    }
                } else {
                    while (cbActualRead2 < dwLen2) {
                        unsigned long remaining = dwLen2 - cbActualRead2;
                        WaveStartDataRead((void**)&_hmmioIn, &_ckIn, &_ckInRiff);
                        unsigned long cbRead2 = 0;
                        WaveReadFile(_hmmioIn, remaining, (unsigned char*)lpWrite2 + cbActualRead2, &_ckIn, &cbRead2);
                        cbActualRead2 += cbRead2;
                    }
                }
            }
        }
    }

    if (_lpDSBStream2 != nullptr) {
        _lpDSBStream2->Unlock(lpWrite1, dwLen1, lpWrite2, dwLen2);
    }

    _dwWriteOffset += _dwChunkSize;
    if (_dwWriteOffset >= _dwStreamBufSize) {
        _dwWriteOffset -= _dwStreamBufSize;
    }

    _timer_guard = 0;
}
