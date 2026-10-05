#include "../include/dsutil.h"
#include <stddef.h>

#define DS_STREAM_STOP_MESSAGE 0x500
#define DS_STREAM_PROGRESS_MESSAGE 0x502
#define DS_STREAM_TIMER_PERIOD 50
#define DS_STREAM_TIMER_RESOLUTION 10

typedef struct SNDOBJ SNDOBJ;
struct SNDOBJ {
    unsigned char* pbWaveData;
    unsigned long cbWaveSize;
    int iAlloc;
    int iCurrent;
    LPDIRECTSOUNDBUFFER Buffers[1];
};

static const char DS_WAVE_RESOURCE_TYPE[] = "WAV";

extern int __cdecl DSGetWaveResource(void*, const char*, void*, void*, void*);
extern int __cdecl DSFillSoundBuffer(LPDIRECTSOUNDBUFFER, void*, int);
extern LPDIRECTSOUNDBUFFER __cdecl DSLoadSoundBuffer(LPDIRECTSOUND, const char*);
extern void __cdecl SndObjDestroy(void*);
extern LPDIRECTSOUNDBUFFER __cdecl SndObjGetFreeBuffer(SNDOBJ*);
extern int __cdecl ds_stream_stop(void);

extern int __cdecl WaveOpenFile(char*, HMMIO*, LPWAVEFORMATEX*, MMCKINFO*);
extern int __cdecl WaveCloseReadFile(HMMIO*, HGLOBAL*);
extern int __cdecl WaveStartDataRead(HMMIO*, MMCKINFO*, MMCKINFO*);
extern int __cdecl WaveReadFile(HMMIO, UINT, BYTE*, MMCKINFO*, UINT*);
extern MMRESULT __cdecl WaveStartDataWrite(void*, MMCKINFO*, MMIOINFO*);
extern int __cdecl WaveCreateFile(char*, HMMIO*, WAVEFORMATEX*, MMCKINFO*, MMCKINFO*);
extern int __cdecl WaveWriteFile(HMMIO, unsigned int, unsigned char*, MMCKINFO*, unsigned int*, MMIOINFO*);
extern int __cdecl WaveCloseWriteFile(HMMIO*, MMCKINFO*, MMCKINFO*, MMIOINFO*, DWORD);
extern int __cdecl riffCopyChunk(HMMIO, HMMIO, MMCKINFO*);

extern void __stdcall ds_stream_time_func(unsigned int, unsigned int, unsigned long, unsigned long, unsigned long);

void __cdecl ShowErrMsg(void) {
}

LPDIRECTSOUNDBUFFER __cdecl DSLoadSoundBuffer(LPDIRECTSOUND pDS, const char* lpName) {
    LPDIRECTSOUNDBUFFER pDSB = 0;
    DSBUFFERDESC dsBD = { 0 };
    void* pbWaveData;

    if (DSGetWaveResource(0, lpName, &dsBD.lpwfxFormat, &pbWaveData, (void*) &dsBD.dwBufferBytes) != 0) {
        dsBD.dwSize = sizeof(dsBD);
        dsBD.dwFlags = DSBCAPS_STATIC | DSBCAPS_CTRLDEFAULT;
        if (IDirectSound_CreateSoundBuffer(pDS, &dsBD, &pDSB, 0) >= 0) {
            if (DSFillSoundBuffer(pDSB, pbWaveData, dsBD.dwBufferBytes) == 0) {
                IDirectSoundBuffer_Release(pDSB);
                return 0;
            }
        } else {
            return 0;
        }
    }
    return pDSB;
}

int __cdecl DSReloadSoundBuffer(LPDIRECTSOUNDBUFFER pDSB, int lpName, void* cbWaveSize) {
    int result = 0;
    int pbWaveData;

    (void) cbWaveSize;
    if (DSGetWaveResource(0, (const char*) lpName, 0, (void*) &pbWaveData, (void*) &lpName) != 0) {
        if (IDirectSoundBuffer_Restore(pDSB) >= 0) {
            if (DSFillSoundBuffer(pDSB, (void*) pbWaveData, lpName) != 0) {
                result = 1;
            }
        }
    }
    return result;
}

int __cdecl DSGetWaveResource(
    void* hModule, const char* lpName, void* ppWaveHeader, void* ppbWaveData, void* pcbWaveSize
) {
    void* resource;

    resource = FindResourceA((HMODULE) hModule, lpName, DS_WAVE_RESOURCE_TYPE);
    if (resource != 0) {
        resource = LoadResource((HMODULE) hModule, (HRSRC) resource);
        if (resource != 0) {
            resource = LockResource((HGLOBAL) resource);
            if (resource != 0) {
                if (DSParseWaveResource(resource, ppWaveHeader, ppbWaveData, pcbWaveSize) != 0) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

SNDOBJ* __cdecl SndObjCreate(LPDIRECTSOUND pDS, const char* lpName, int iConcurrent) {
    unsigned char* pbData;
    unsigned long cbData;
    void* pWaveHeader;
    SNDOBJ* obj;
    int i;
    LPDIRECTSOUNDBUFFER* buf;

    obj = 0;
    if (DSGetWaveResource(0, lpName, &pWaveHeader, &pbData, &cbData) != 0) {
        i = 1;
        if (iConcurrent < i) {
            iConcurrent = i;
        }
        obj =
            (SNDOBJ*) LocalAlloc(LMEM_ZEROINIT, offsetof(SNDOBJ, Buffers) + iConcurrent * sizeof(LPDIRECTSOUNDBUFFER));
        if (obj != 0) {
            obj->iAlloc = iConcurrent;
            obj->pbWaveData = pbData;
            obj->cbWaveSize = cbData;
            obj->Buffers[0] = DSLoadSoundBuffer(pDS, lpName);
            if (i < obj->iAlloc) {
                buf = &obj->Buffers[1];
                while (1) {
                    if (pDS->lpVtbl->DuplicateSoundBuffer(pDS, obj->Buffers[0], buf) < 0) {
                        *buf = DSLoadSoundBuffer(pDS, lpName);
                        if (*buf == 0) {
                            goto destroy_obj;
                        }
                    }
                    i++;
                    buf++;
                    if (i < obj->iAlloc) {
                        continue;
                    }
                    return obj;
                }

            destroy_obj:
                SndObjDestroy(obj);
                obj = 0;
            }
        }
    }

    return obj;
}

void __cdecl SndObjDestroy(void* pSO) {
    if (pSO != 0) {
        int i = 0;
        if (*(int*) ((char*) pSO + 8) > 0) {
            do {
                LPDIRECTSOUNDBUFFER buffer =
                    *(LPDIRECTSOUNDBUFFER*) ((char*) pSO + offsetof(SNDOBJ, Buffers) + i * sizeof(LPDIRECTSOUNDBUFFER));
                if (buffer != 0) {
                    IDirectSoundBuffer_Release(buffer);
                    *(LPDIRECTSOUNDBUFFER*) ((char*) pSO + offsetof(SNDOBJ, Buffers)
                                             + i * sizeof(LPDIRECTSOUNDBUFFER)) = 0;
                }
                ++i;
            } while (i < *(int*) ((char*) pSO + 8));
        }
        LocalFree((HLOCAL) pSO);
    }
}

LPDIRECTSOUNDBUFFER __cdecl SndObjGetFreeBuffer(SNDOBJ* pSO) {
    LPDIRECTSOUNDBUFFER buf;
    DWORD dwStatus;
    int hr;

    if (pSO == 0)
        return 0;

    buf = pSO->Buffers[pSO->iCurrent];
    if (buf != 0) {
        hr = IDirectSoundBuffer_GetStatus(buf, &dwStatus);
        if (hr < 0) {
            dwStatus = 0;
        }
        if ((dwStatus & 1) == 1) {
            if (pSO->iAlloc > 1) {
                pSO->iCurrent++;
                if (pSO->iCurrent >= pSO->iAlloc) {
                    pSO->iCurrent = 0;
                }
                buf = pSO->Buffers[pSO->iCurrent];
                hr = IDirectSoundBuffer_GetStatus(buf, &dwStatus);
                if (hr >= 0 && (dwStatus & 1) == 1) {
                    IDirectSoundBuffer_Stop(buf);
                    IDirectSoundBuffer_SetCurrentPosition(buf, 0);
                }
            } else {
                buf = 0;
            }
        }

        if (buf != 0 && (dwStatus & 2) != 0) {
            hr = IDirectSoundBuffer_Restore(buf);
            if (hr < 0 || DSFillSoundBuffer(buf, pSO->pbWaveData, pSO->cbWaveSize) == 0) {
                buf = 0;
            }
        }
    }

    return buf;
}

unsigned int __cdecl SndObjPlay(SNDOBJ* pSO, unsigned long dwPlayFlags) {
    unsigned int result;
    LPDIRECTSOUNDBUFFER buffer;
    int hr;

    result = 0;
    if (pSO == 0) {
        return result;
    }
    if (((dwPlayFlags & 1) == 0) || (pSO->iAlloc == 1)) {
        buffer = SndObjGetFreeBuffer(pSO);
        if (buffer != 0) {
            hr = IDirectSoundBuffer_Play(buffer, 0, 0, dwPlayFlags);
            result = (unsigned int) (hr >= 0);
        }
    }
    return result;
}

int __cdecl SndObjStop(SNDOBJ* pSO) {
    int i;

    if (pSO == 0) {
        return 0;
    }

    i = 0;
    if (pSO->iAlloc > 0) {
        do {
            IDirectSoundBuffer_Stop(pSO->Buffers[i]);
            IDirectSoundBuffer_SetCurrentPosition(pSO->Buffers[i], 0);
            ++i;
        } while (i < pSO->iAlloc);
    }
    return 1;
}

int __cdecl DSFillSoundBuffer(LPDIRECTSOUNDBUFFER pDSB, void* pbWaveData, int cbWaveSize) {
    int hr;
    void* pMem1;
    int dwSize1;
    void* pMem2;
    int dwSize2;

    if (!pDSB || !pbWaveData || !cbWaveSize)
        return 0;

    hr = IDirectSoundBuffer_Lock(pDSB, 0, cbWaveSize, &pMem1, (DWORD*) &dwSize1, &pMem2, (DWORD*) &dwSize2, 0);
    if (hr < 0)
        return 0;

    memcpy(pMem1, pbWaveData, dwSize1);
    if (dwSize2)
        memcpy((char*) pMem2, (char*) pbWaveData + dwSize1, dwSize2);

    IDirectSoundBuffer_Unlock(pDSB, pMem1, dwSize1, pMem2, dwSize2);
    return 1;
}

int __cdecl DSParseWaveResource(void* pvRes, void** ppWaveHeader, BYTE** ppbData, DWORD* pdwDataSize) {
    DWORD* pdw;
    DWORD dwRiff;
    DWORD dwLength;
    DWORD dwType;
    DWORD* pdwEnd;

    if (ppWaveHeader) {
        *ppWaveHeader = 0;
    }
    if (ppbData) {
        *ppbData = 0;
    }
    if (pdwDataSize) {
        *pdwDataSize = 0;
    }

    pdw = (DWORD*) pvRes;
    dwRiff = *pdw++;
    dwLength = *pdw++;
    dwType = *pdw++;

    if (dwRiff != FOURCC_RIFF) {
        return 0;
    }
    if (dwType != mmioFOURCC('W', 'A', 'V', 'E')) {
        return 0;
    }

    pdwEnd = (DWORD*) ((BYTE*) pdw + dwLength - 4);

    while (pdw < pdwEnd) {
        dwType = *pdw++;
        dwLength = *pdw++;

        switch (dwType) {
            case mmioFOURCC('d', 'a', 't', 'a'):
                if ((ppbData && !*ppbData) || (pdwDataSize && !*pdwDataSize)) {
                    if (ppbData) {
                        *ppbData = (BYTE*) pdw;
                    }
                    if (pdwDataSize) {
                        *pdwDataSize = dwLength;
                    }

                    if (!ppWaveHeader || *ppWaveHeader) {
                        return 1;
                    }
                }
                break;

            case mmioFOURCC('f', 'm', 't', ' '):
                if (ppWaveHeader && !*ppWaveHeader) {
                    if (dwLength < 0x0e) {
                        return 0;
                    }
                    *ppWaveHeader = pdw;

                    if ((!ppbData || *ppbData) && (!pdwDataSize || *pdwDataSize)) {
                        return 1;
                    }
                }
                break;
        }

        pdw = (DWORD*) ((BYTE*) pdw + ((dwLength + 1) & ~1));
    }

    return 0;
}

#pragma function(memcpy)
int __cdecl WaveOpenFile(char* pszFileName, HMMIO* phmmioIn, LPWAVEFORMATEX* ppwfxInfo, MMCKINFO* pckInRIFF) {
    HMMIO hmmioIn;
    MMCKINFO ckIn;
    PCMWAVEFORMAT pcmWaveFormat;
    WORD cbExtraAlloc;
    int err;

    *ppwfxInfo = 0;
    err = 0;
    hmmioIn = 0;

    if ((hmmioIn = mmioOpenA(pszFileName, 0, MMIO_ALLOCBUF)) == 0) {
        err = 0xE100;
        goto error;
    }

    if ((err = mmioDescend(hmmioIn, (LPMMCKINFO) pckInRIFF, 0, 0)) != 0) {
        goto error;
    }

    if (pckInRIFF->ckid != mmioFOURCC('R', 'I', 'F', 'F') || pckInRIFF->fccType != mmioFOURCC('W', 'A', 'V', 'E')) {
        err = 0xE101;
        goto error;
    }

    ckIn.ckid = mmioFOURCC('f', 'm', 't', ' ');
    if ((err = mmioDescend(hmmioIn, (LPMMCKINFO) &ckIn, (LPMMCKINFO) pckInRIFF, MMIO_FINDCHUNK)) != 0) {
        goto error;
    }

    if (ckIn.cksize < sizeof(pcmWaveFormat)) {
        err = 0xE101;
        goto error;
    }

    if (mmioRead(hmmioIn, (char*) &pcmWaveFormat, sizeof(pcmWaveFormat)) != sizeof(pcmWaveFormat)) {
        err = 0xE102;
        goto error;
    }

    if (pcmWaveFormat.wf.wFormatTag == WAVE_FORMAT_PCM) {
        cbExtraAlloc = 0;
    } else {
        if (mmioRead(hmmioIn, (char*) &cbExtraAlloc, sizeof(cbExtraAlloc)) != sizeof(cbExtraAlloc)) {
            err = 0xE102;
            goto error;
        }
    }

    if ((*ppwfxInfo = GlobalAlloc(0, (DWORD) cbExtraAlloc + 18)) == 0) {
        err = 0xE000;
        goto error;
    }

    memcpy(*ppwfxInfo, &pcmWaveFormat, sizeof(pcmWaveFormat));
    (*ppwfxInfo)->cbSize = cbExtraAlloc;

    if (cbExtraAlloc != 0) {
        if (mmioRead(hmmioIn, (char*) &(*ppwfxInfo)->cbSize + sizeof(cbExtraAlloc), cbExtraAlloc) != cbExtraAlloc) {
            err = 0xE101;
            goto error;
        }
    }

    if ((err = mmioAscend(hmmioIn, (LPMMCKINFO) &ckIn, 0)) != 0) {
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

int __cdecl WaveStartDataRead(HMMIO* phmmioIn, MMCKINFO* pckIn, MMCKINFO* pckInRIFF) {
    if (mmioSeek(*phmmioIn, pckInRIFF->dwDataOffset + 4, 0) == -1) {
        return 1;
    }

    pckIn->ckid = mmioFOURCC('d', 'a', 't', 'a');
    return mmioDescend(*phmmioIn, (LPMMCKINFO) pckIn, (LPMMCKINFO) pckInRIFF, MMIO_FINDCHUNK);
}

int __cdecl WaveReadFile(HMMIO hmmioIn, UINT cbRead, BYTE* pbDest, MMCKINFO* pckIn, UINT* cbActualRead) {
    MMIOINFO mmioinfoIn;
    int nError = 0;
    UINT cT;
    UINT cbDataIn;
    UINT cbDataToCopy;

    if ((nError = (mmioGetInfo(hmmioIn, (LPMMIOINFO) &mmioinfoIn, 0) != 0))) {
        goto error;
    }

    cbDataIn = cbRead;
    if (cbDataIn > pckIn->cksize) {
        cbDataIn = pckIn->cksize;
    }

    pckIn->cksize -= cbDataIn;

    for (cT = 0; cT < cbDataIn;) {
        if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead) {
            if ((nError = mmioAdvance(hmmioIn, (LPMMIOINFO) &mmioinfoIn, 0)) != 0) {
                goto error;
            }
            if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead) {
                nError = 0xE103;
                goto error;
            }
        }

        cbDataToCopy = mmioinfoIn.pchEndRead - mmioinfoIn.pchNext;
        if (cbDataIn - cT < cbDataToCopy) {
            memcpy((cbDataToCopy = cbDataIn - cT, (BYTE*) pbDest + cT), (BYTE*) mmioinfoIn.pchNext, cbDataIn - cT);
        } else {
            memcpy((BYTE*) pbDest + cT, (BYTE*) mmioinfoIn.pchNext, cbDataToCopy);
        }
        cT += cbDataToCopy;
        mmioinfoIn.pchNext += cbDataToCopy;
    }

    if ((nError = mmioSetInfo(hmmioIn, (LPMMIOINFO) &mmioinfoIn, 0)) != 0) {
        goto error;
    }

    *cbActualRead = cbDataIn;
    goto done;

error:
    *cbActualRead = 0;
done:
    return nError;
}

int __cdecl WaveCloseReadFile(HMMIO* phmmio, HGLOBAL* ppwfxSrc) {
    if (*ppwfxSrc != 0) {
        GlobalFree(*ppwfxSrc);
        *ppwfxSrc = 0;
    }
    if (*phmmio != 0) {
        mmioClose(*phmmio, 0);
        *phmmio = 0;
    }
    return 0;
}

int __cdecl WaveCreateFile(
    char* pszFileName, HMMIO* phmmioOut, WAVEFORMATEX* pwfxDest, MMCKINFO* pckOut, MMCKINFO* pckOutRIFF
) {
    int err;
    DWORD dwFactChunk;
    MMCKINFO ckOut1;

    dwFactChunk = (DWORD) -1;
    err = 0;

    *phmmioOut = mmioOpenA(pszFileName, 0, MMIO_ALLOCBUF | MMIO_CREATE | MMIO_READWRITE);
    if (*phmmioOut == 0) {
        err = 0xE104;
        goto done;
    }

    pckOutRIFF->fccType = mmioFOURCC('W', 'A', 'V', 'E');
    pckOutRIFF->cksize = 0;
    if ((err = mmioCreateChunk(*phmmioOut, (LPMMCKINFO) pckOutRIFF, MMIO_CREATERIFF)) != 0) {
        goto done;
    }

    pckOut->ckid = mmioFOURCC('f', 'm', 't', ' ');
    pckOut->cksize = 16;
    if ((err = mmioCreateChunk(*phmmioOut, (LPMMCKINFO) pckOut, 0)) != 0) {
        goto done;
    }

    if (pwfxDest->wFormatTag == WAVE_FORMAT_PCM) {
        if (mmioWrite(*phmmioOut, (const char*) pwfxDest, 16) != 16) {
            err = 0xE104;
            goto done;
        }
    } else {
        if ((UINT) mmioWrite(*phmmioOut, (const char*) pwfxDest, 18 + pwfxDest->cbSize) != (18 + pwfxDest->cbSize)) {
            goto fail;
        }
    }

    if ((err = mmioAscend(*phmmioOut, (LPMMCKINFO) pckOut, 0)) != 0) {
        goto done;
    }

    ckOut1.ckid = mmioFOURCC('f', 'a', 'c', 't');
    ckOut1.cksize = 0;
    if ((err = mmioCreateChunk(*phmmioOut, (LPMMCKINFO) &ckOut1, 0)) != 0) {
        goto done;
    }

    if (mmioWrite(*phmmioOut, (const char*) &dwFactChunk, sizeof(dwFactChunk)) != sizeof(dwFactChunk)) {
        goto fail;
    }

    if ((err = mmioAscend(*phmmioOut, (LPMMCKINFO) &ckOut1, 0)) == 0) {
        goto done;
    }

fail:
    err = 0xE104;

done:
    return err;
}

MMRESULT __cdecl WaveStartDataWrite(void* phmmioOut, MMCKINFO* pckOut, MMIOINFO* pmmioinfoOut) {
    MMRESULT result;

    pckOut->ckid = mmioFOURCC('d', 'a', 't', 'a');
    pckOut->cksize = 0;
    result = mmioCreateChunk(*(HMMIO*) phmmioOut, (LPMMCKINFO) pckOut, 0);
    if (result != 0) {
        return result;
    }
    return mmioGetInfo(*(HMMIO*) phmmioOut, (LPMMIOINFO) pmmioinfoOut, 0);
}

int __cdecl WaveWriteFile(
    HMMIO hmmioOut, unsigned int cbWrite, unsigned char* pbSrc, MMCKINFO* pckOut, unsigned int* pdwWritten,
    MMIOINFO* pmmioinfoOut
) {
    MMRESULT result = 0;
    unsigned int i;
    *pdwWritten = result;
    i = 0;
    if (cbWrite <= 0)
        return;
    do {
        if (pmmioinfoOut->pchNext == pmmioinfoOut->pchEndWrite) {
            pmmioinfoOut->dwFlags = pmmioinfoOut->dwFlags | MMIO_DIRTY;
            result = mmioAdvance(hmmioOut, pmmioinfoOut, MMIO_WRITE);
            if (result != 0) {
                return result;
            }
        }
        *pmmioinfoOut->pchNext++ = pbSrc[i];
        (*pdwWritten)++;
        i = i + 1;
    } while (i < cbWrite);
    return result;
}

int __cdecl WaveCloseWriteFile(
    HMMIO* phmmioOut, MMCKINFO* pckOut, MMCKINFO* pckOutRIFF, MMIOINFO* pmmioinfoOut, DWORD cSamples
) {
    int result;

    if (*phmmioOut == 0) {
        return 0;
    }

    pmmioinfoOut->dwFlags |= MMIO_DIRTY;
    result = mmioSetInfo(*phmmioOut, (LPMMIOINFO) pmmioinfoOut, 0);
    if (result == 0) {
        result = mmioAscend(*phmmioOut, (LPMMCKINFO) pckOut, 0);
        if (result == 0) {
            result = mmioAscend(*phmmioOut, (LPMMCKINFO) pckOutRIFF, 0);
            if (result == 0) {
                mmioSeek(*phmmioOut, 0, 0);
                result = mmioDescend(*phmmioOut, (LPMMCKINFO) pckOutRIFF, 0, 0);
                if (result == 0) {
                    pckOut->ckid = mmioFOURCC('f', 'a', 'c', 't');
                    if ((result = mmioDescend(*phmmioOut, (LPMMCKINFO) pckOut, (LPMMCKINFO) pckOutRIFF, MMIO_FINDCHUNK))
                        == 0) {
                        mmioWrite(*phmmioOut, (const char*) &cSamples, sizeof(DWORD));
                        mmioAscend(*phmmioOut, (LPMMCKINFO) pckOut, result);
                        result = mmioAscend(*phmmioOut, (LPMMCKINFO) pckOutRIFF, 0);
                    } else {
                        return 1;
                    }
                }
            }
        }
    }

    if (*phmmioOut != 0) {
        mmioClose(*phmmioOut, 0);
        *phmmioOut = 0;
    }
    return result;
}

int __cdecl WaveCopyUselessChunks(HMMIO* phmmioIn, MMCKINFO* pckIn, MMCKINFO* pckInRiff, HMMIO* phmmioOut) {
    int result;

    if (mmioSeek(*phmmioIn, pckInRiff->dwDataOffset + 4, 0) == -1) {
        result = 0xE102;
    } else {
        result = 0;
        while (mmioDescend(*phmmioIn, (LPMMCKINFO) pckIn, (LPMMCKINFO) pckInRiff, 0) == 0) {
            DWORD ckEnd = pckIn->cksize;
            DWORD parentEnd = pckInRiff->cksize;
            ckEnd += pckIn->dwDataOffset;
            parentEnd += pckInRiff->dwDataOffset;
            if (ckEnd > parentEnd) {
                break;
            }
            if (pckIn->ckid != mmioFOURCC('P', 'A', 'D', ' ')) {
                if (pckIn->ckid == mmioFOURCC('D', 'I', 'S', 'P') || pckIn->ckid == mmioFOURCC('p', 'l', 's', 't')) {
                    riffCopyChunk(*phmmioIn, *phmmioOut, pckIn);
                }
            }
            mmioAscend(*phmmioIn, (LPMMCKINFO) pckIn, 0);
        }
    }

    mmioSeek(*phmmioIn, pckInRiff->dwDataOffset + 4, 0);
    return result;
}

#define CLEANUP_DATA() do { \
    GlobalUnlock(GlobalHandle(data)); \
    GlobalFree(GlobalHandle(data)); \
} while (0)

int __cdecl riffCopyChunk(HMMIO hmmioSrc, HMMIO hmmioDst, MMCKINFO* pckIn) {
    MMCKINFO ck;
    char* data;

    data = (char*) GlobalLock(GlobalAlloc(GHND, pckIn->cksize));
    if (data == 0) {
        return 0;
    }

    ck.ckid = pckIn->ckid;
    ck.cksize = pckIn->cksize;
    if (mmioCreateChunk(hmmioDst, (LPMMCKINFO) &ck, 0) != 0) {
        goto fail;
    }
    if (mmioRead(hmmioSrc, data, pckIn->cksize) != (LONG) pckIn->cksize) {
        goto fail;
    }
    if (mmioWrite(hmmioDst, data, pckIn->cksize) != pckIn->cksize) {
        goto fail;
    }
    if (mmioAscend(hmmioDst, (LPMMCKINFO) &ck, 0) != 0) {
        goto fail;
    }

    CLEANUP_DATA();
    return 1;

fail:
    CLEANUP_DATA();
    return 0;
}

int __cdecl WaveLoadFile(
    char* pszFileName, DWORD* cbSize, DWORD* pcSamples, void** ppwfxInfo, unsigned char** ppbData
) {
    HMMIO hmmio;
    MMCKINFO ckInRiff;
    MMCKINFO ckIn;
    int err;
    DWORD cbActualRead;

    (void) pcSamples;
    *ppbData = 0;
    *ppwfxInfo = 0;
    *cbSize = 0;

    err = WaveOpenFile(pszFileName, &hmmio, (LPWAVEFORMATEX*) ppwfxInfo, &ckInRiff);
    if (err != 0) {
        goto error;
    }

    err = WaveStartDataRead(&hmmio, &ckIn, &ckInRiff);
    if (err != 0) {
        goto error;
    }

    *ppbData = (unsigned char*) GlobalAlloc(0, ckIn.cksize);
    if (*ppbData == 0) {
        err = 0xE000;
        goto error;
    }

    err = WaveReadFile(hmmio, ckIn.cksize, *ppbData, &ckIn, &cbActualRead);
    if (err != 0) {
        goto error;
    }

    *cbSize = cbActualRead;
    goto done;

error:
    if (*ppbData != 0) {
        GlobalFree(*ppbData);
        *ppbData = 0;
    }
    if (*ppwfxInfo != 0) {
        GlobalFree(*ppwfxInfo);
        *ppwfxInfo = 0;
    }

done:
    if (hmmio != 0) {
        mmioClose(hmmio, 0);
    }
    return err;
}

void __cdecl WaveSaveFile(void* pszFileName, void* cbSize, void* cSamples, void* pwfxDest, void* pbData) {
    struct WaveSaveLocals {
        void* cbActualWrite;
        char ckOut[0x14];
        char ckOutRIFF[0x14];
        char pad[4];
        char mmioinfoOut[0x48];
    } l;

    if (WaveCreateFile(
            (char*) pszFileName, (HMMIO*) &l.cbActualWrite, (WAVEFORMATEX*) pwfxDest, (MMCKINFO*) (l.ckOut + 4),
            (MMCKINFO*) (l.ckOutRIFF + 4)
        )
        == 0) {
        if (WaveStartDataWrite(&l.cbActualWrite, (MMCKINFO*) (l.ckOut + 4), (MMIOINFO*) l.mmioinfoOut) == 0) {
            if (WaveWriteFile(
                    (HMMIO) l.cbActualWrite, (unsigned int) cbSize, (unsigned char*) pbData, (MMCKINFO*) (l.ckOut + 4),
                    (unsigned int*) l.ckOut, (MMIOINFO*) l.mmioinfoOut
                )
                == 0) {
                WaveCloseWriteFile(
                    (HMMIO*) &l.cbActualWrite, (MMCKINFO*) (l.ckOut + 4), (MMCKINFO*) (l.ckOutRIFF + 4),
                    (MMIOINFO*) l.mmioinfoOut, (DWORD) (unsigned long) cSamples
                );
            }
        }
    }
}

void __cdecl ds_stream_init(void* hWnd, LPDIRECTSOUND lpd, LPDIRECTSOUNDBUFFER lpb) {
    _uLastPercent = 100;
    _lpDSBStreamBuffer = 0;
    _bFileOpen = 0;
    _bPlaying = 0;
    _bTimerInstalled = 0;
    _uTimerID = 0;
    _main_wnd = (HWND) hWnd;
    _lpBuffer = lpb;
    _lpDS = lpd;
    _ds_ready = 1;
}

void __cdecl ds_stream_exit(void) {
    if (_ds_ready != 0) {
        if ((_bFileOpen != 0) || (_bPlaying != 0) || (_bTimerInstalled != 0)) {
            ds_stream_stop();
        }
        _ds_ready = 0;
    }
}

int __cdecl ds_stream_file(char* szName, int bLoop, long Volume) {
    int result;
    unsigned int dwLen1;
    unsigned char* lpWrite1;
    unsigned int uChkErr;
    unsigned char* lpWrite2;
    unsigned int dwLen2;
    DSBUFFERDESC dsbd;

    if (_bFileOpen != 0) {
        ds_stream_stop();
    } else if (_bPlaying != 0) {
        ds_stream_stop();
    } else if (_bTimerInstalled != 0) {
        ds_stream_stop();
    }

    _stream_paused = 0;
    result = WaveOpenFile(szName, &ds_wave_file, (LPWAVEFORMATEX*) &_wiWave, &ds_wave_riff_chunk);
    if (result != 0) {
        return 0;
    }

    if (*(short*) _wiWave != 1) {
        WaveCloseReadFile(&ds_wave_file, (HGLOBAL*) &_wiWave);
        return 0;
    }

    result = WaveStartDataRead(&ds_wave_file, &ds_wave_data_chunk, &ds_wave_riff_chunk);
    if (result != 0) {
        WaveCloseReadFile(&ds_wave_file, (HGLOBAL*) &_wiWave);
        return 0;
    }

    ds_chunk_size = ((((LPWAVEFORMATEX) _wiWave)->nAvgBytesPerSec * 120) / 100) / 6;
    ds_buffer_size = ds_chunk_size * 6;
    memset(&dsbd, 0, sizeof(dsbd));

    dsbd.dwSize = sizeof(dsbd);
    dsbd.dwFlags = DSBCAPS_CTRLDEFAULT;
    dsbd.dwBufferBytes = ds_buffer_size;
    dsbd.lpwfxFormat = (void*) _wiWave;
    result =
        IDirectSound_CreateSoundBuffer((LPDIRECTSOUND) _lpDS, &dsbd, (LPLPDIRECTSOUNDBUFFER) &_lpDSBStreamBuffer, 0);
    if (result != 0) {
        return 0;
    }

    ds_stream_buffer = _lpDSBStreamBuffer;
    ds_stream_at_end = 0;
    ds_silence_chunks = 0;
    result = IDirectSoundBuffer_Lock(
        (LPDIRECTSOUNDBUFFER) _lpDSBStreamBuffer, 0, ds_buffer_size, (void**) &lpWrite1, &dwLen1, (void**) &lpWrite2,
        &dwLen2, 0
    );
    if (result != 0) {
        return 0;
    }

    if (dwLen1 != 0) {
        WaveReadFile(ds_wave_file, dwLen1, lpWrite1, &ds_wave_data_chunk, &uChkErr);
        if (uChkErr < dwLen1) {
            if (ds_stream_loop != 0) {
                unsigned char* lpWriteCursor = lpWrite1;
                do {
                    lpWriteCursor += uChkErr;
                    dwLen1 -= uChkErr;
                    WaveStartDataRead(&ds_wave_file, &ds_wave_data_chunk, &ds_wave_riff_chunk);
                    WaveReadFile(ds_wave_file, dwLen1, lpWriteCursor, &ds_wave_data_chunk, &uChkErr);
                } while (uChkErr < dwLen1);
            } else {
                ds_silence_chunks = uChkErr / ds_chunk_size;
                ds_stream_at_end = 1;
                memset(
                    (unsigned char*) lpWrite1 + uChkErr, ((((LPWAVEFORMATEX) _wiWave)->wBitsPerSample != 8) - 1) & 0x80,
                    dwLen1 - uChkErr
                );
            }
        }
    }

    IDirectSoundBuffer_Unlock((LPDIRECTSOUNDBUFFER) _lpDSBStreamBuffer, lpWrite1, dwLen1, lpWrite2, 0);

    ds_stream_position = 0;
    ds_last_play_cursor = 0;
    ds_write_cursor = 0;
    ds_stream_stop_requested = 0;
    ds_stream_loop = bLoop & 0xFF;
    _bFileOpen = 1;
    SendMessageA((HWND) _main_wnd, DS_STREAM_PROGRESS_MESSAGE, 0, 0);

    IDirectSoundBuffer_SetCurrentPosition((LPDIRECTSOUNDBUFFER) _lpDSBStreamBuffer, 0);
    IDirectSoundBuffer_SetVolume((LPDIRECTSOUNDBUFFER) _lpDSBStreamBuffer, Volume);
    IDirectSoundBuffer_Play((LPDIRECTSOUNDBUFFER) _lpDSBStreamBuffer, 0, 0, 1);

    if (timeBeginPeriod(DS_STREAM_TIMER_PERIOD) != 0) {
        IDirectSoundBuffer_Stop((LPDIRECTSOUNDBUFFER) _lpDSBStreamBuffer);
        _bTimerInstalled = 0;
        _bPlaying = 0;
        return 0;
    }

    _uTimerID = timeSetEvent(DS_STREAM_TIMER_PERIOD, DS_STREAM_TIMER_RESOLUTION, ds_stream_time_func, 0, 1);
    if (_uTimerID != 0) {
        _bTimerInstalled = 1;
    }
    _bPlaying = 1;
    return 1;
}

int __cdecl ds_stream_volume(int val) {
    LPDIRECTSOUNDBUFFER stream;
    int result;

    stream = (LPDIRECTSOUNDBUFFER) _lpDSBStreamBuffer;
    if (stream == 0) {
        return 0;
    }
    result = IDirectSoundBuffer_SetVolume(stream, val);
    return result == 0;
}

int __cdecl ds_stream_pause(void) {
    _stream_paused = 1;
    return 1;
}

int __cdecl ds_stream_resume(void) {
    _stream_paused = 0;
    return 1;
}

int __cdecl ds_stream_stop(void) {
    ds_stream_stop_requested = 1;
    if (_bTimerInstalled != 0) {
        _bTimerInstalled = 0;
        timeKillEvent(_uTimerID);
        timeEndPeriod(DS_STREAM_TIMER_PERIOD);
    }

    if (_bPlaying != 0) {
        _bPlaying = 0;
        if (_lpDSBStreamBuffer != 0) {
            IDirectSoundBuffer_Stop((LPDIRECTSOUNDBUFFER) _lpDSBStreamBuffer);
        }
    }

    if (_bFileOpen != 0) {
        if (_wiWave != 0) {
            WaveCloseReadFile(&ds_wave_file, (HGLOBAL*) &_wiWave);
            _wiWave = 0;
        }
        if (_lpDSBStreamBuffer != 0) {
            IDirectSoundBuffer_Release((LPDIRECTSOUNDBUFFER) _lpDSBStreamBuffer);
            _lpDSBStreamBuffer = 0;
            ds_stream_buffer = 0;
        }
        _bFileOpen = 0;
    }
    return 1;
}

int __cdecl ds_stream_messages(int hWnd, int wMsg) {
    (void) hWnd;
    switch (wMsg) {
        case DS_STREAM_STOP_MESSAGE:
            ds_stream_stop();
            break;
        case DS_STREAM_PROGRESS_MESSAGE: {
            unsigned long a = ds_stream_position;
            unsigned long b = ds_wave_riff_chunk.cksize;
            if (a > b) {
                ds_stream_position = a - b;
                a = a - b;
            }
            {
                unsigned long temp = a * 100 / b;
                double d = (double) temp;
                long percent = (long) d;
                if (percent != ds_last_percent) {
                    ds_last_percent = percent;
                }
            }
            break;
        }
    }
    return 0;
}

void __stdcall ds_stream_time_func(
    unsigned int uTimerID, unsigned int uMsg, unsigned long dwUser, unsigned long dw1, unsigned long dw2
) {
    static int bInTimer;
    unsigned long dwPlay;
    unsigned long dwWrite;
    unsigned char* lpWrite1;
    unsigned long dwLen1;
    unsigned char* lpWrite2;
    unsigned long dwLen2;
    unsigned int uChkErr;
    unsigned long playDistance;
    unsigned char* lpWriteCursor;
    LPDIRECTSOUNDBUFFER stream;

    if (bInTimer != 0 || _stream_paused != 0) {
        return;
    }

    bInTimer = 1;
    if (ds_stream_stop_requested != 0 || ds_stream_buffer == 0) {
        goto done;
    }

    stream = ds_stream_buffer;
    IDirectSoundBuffer_GetCurrentPosition(stream, &dwPlay, &dwWrite);

    if (ds_write_cursor < dwPlay && dwPlay < ds_write_cursor + ds_chunk_size) {
        goto done;
    }

    if (ds_stream_at_end != 0 && ds_silence_chunks == 0) {
        if (ds_stream_stop_requested == 0) {
            ds_stream_stop_requested = 1;
            PostMessageA(_main_wnd, DS_STREAM_STOP_MESSAGE, 0, 0);
        }
        bInTimer = 0;
        return;
    }

    if (dwPlay < ds_last_play_cursor) {
        playDistance = ds_buffer_size + dwPlay - ds_last_play_cursor;
    } else {
        playDistance = dwPlay - ds_last_play_cursor;
    }
    ds_last_play_cursor = dwPlay;
    ds_stream_position += playDistance;
    PostMessageA(_main_wnd, DS_STREAM_PROGRESS_MESSAGE, 0, 0);

    if (ds_stream_at_end != 0 && ds_silence_chunks != 0) {
        --ds_silence_chunks;
        if ((int) ds_silence_chunks < 2 || ds_stream_buffer == 0) {
            goto done;
        }

        stream = ds_stream_buffer;
        if (IDirectSoundBuffer_Lock(
                stream, ds_write_cursor, ds_chunk_size, (void**) &lpWrite1, &dwLen1, (void**) &lpWrite2, &dwLen2, 0
            )
            != 0) {
            goto done;
        }

        if (_wiWave != 0 && lpWrite1 != 0) {
            if (_wiWave->wBitsPerSample == 8) {
                memset(lpWrite1, 0x80, dwLen1);
            } else if (_wiWave->wBitsPerSample == 16) {
                memset(lpWrite1, 0, dwLen1);
            }
        }

        IDirectSoundBuffer_Unlock(ds_stream_buffer, lpWrite1, dwLen1, lpWrite2, dwLen2);
    } else {
        if (ds_stream_buffer == 0) {
            goto done;
        }

        stream = ds_stream_buffer;
        if (IDirectSoundBuffer_Lock(
                stream, ds_write_cursor, ds_chunk_size, (void**) &lpWrite1, &dwLen1, (void**) &lpWrite2, &dwLen2, 0
            )
            != 0) {
            goto done;
        }

        if (dwLen1 != 0 && ds_stream_stop_requested == 0) {
            WaveReadFile(ds_wave_file, dwLen1, lpWrite1, &ds_wave_data_chunk, &uChkErr);
            if (uChkErr < dwLen1) {
                if (ds_stream_loop == 0) {
                    if (_wiWave != 0 && lpWrite1 != 0) {
                        if (_wiWave->wBitsPerSample == 8) {
                            memset(lpWrite1 + uChkErr, 0x80, dwLen1 - uChkErr);
                        } else if (_wiWave->wBitsPerSample == 16) {
                            memset(lpWrite1 + uChkErr, 0, dwLen1 - uChkErr);
                        }
                    }

                    ds_stream_at_end = 1;
                    if (dwPlay > ds_write_cursor) {
                        ds_silence_chunks = (ds_write_cursor + ds_buffer_size - dwPlay) / ds_chunk_size;
                    } else {
                        ds_silence_chunks = (ds_write_cursor - dwPlay) / ds_chunk_size;
                    }
                } else if (lpWrite1 != 0) {
                    lpWriteCursor = lpWrite1;
                    do {
                        dwLen1 -= uChkErr;
                        lpWriteCursor += uChkErr;
                        WaveStartDataRead(&ds_wave_file, &ds_wave_data_chunk, &ds_wave_riff_chunk);
                        WaveReadFile(ds_wave_file, dwLen1, lpWriteCursor, &ds_wave_data_chunk, &uChkErr);
                    } while (uChkErr < dwLen1);
                }
            }
        } else if (dwLen1 != 0 && ds_stream_stop_requested != 0 && _wiWave != 0 && lpWrite1 != 0) {
            memset(lpWrite1, ((_wiWave->wBitsPerSample != 8) - 1) & 0x80, dwLen1);
        }

        if (dwLen2 != 0) {
            if (ds_stream_stop_requested == 0) {
                WaveReadFile(ds_wave_file, dwLen2, lpWrite2, &ds_wave_data_chunk, &uChkErr);
                if (uChkErr < dwLen2) {
                    if (ds_stream_loop == 0) {
                        if (_wiWave != 0 && lpWrite2 != 0) {
                            if (_wiWave->wBitsPerSample == 8) {
                                memset(lpWrite2 + uChkErr, 0x80, dwLen2 - uChkErr);
                            } else if (_wiWave->wBitsPerSample == 16) {
                                memset(lpWrite2 + uChkErr, 0, dwLen2 - uChkErr);
                            }
                        }

                        ds_stream_at_end = 1;
                        if (dwPlay > ds_write_cursor) {
                            ds_silence_chunks = (ds_write_cursor + ds_buffer_size - dwPlay) / ds_chunk_size;
                        } else {
                            ds_silence_chunks = (ds_write_cursor - dwPlay) / ds_chunk_size;
                        }
                    } else if (lpWrite2 != 0) {
                        lpWriteCursor = lpWrite2;
                        do {
                            dwLen2 -= uChkErr;
                            lpWriteCursor += uChkErr;
                            WaveStartDataRead(&ds_wave_file, &ds_wave_data_chunk, &ds_wave_riff_chunk);
                            WaveReadFile(ds_wave_file, dwLen2, lpWriteCursor, &ds_wave_data_chunk, &uChkErr);
                        } while (uChkErr < dwLen2);
                    }
                }
            } else if (ds_stream_stop_requested != 0 && _wiWave != 0 && lpWrite2 != 0) {
                memset(lpWrite2, ((_wiWave->wBitsPerSample != 8) - 1) & 0x80, dwLen2);
            }
        }

        if (ds_stream_buffer != 0) {
            IDirectSoundBuffer_Unlock(ds_stream_buffer, lpWrite1, dwLen1, lpWrite2, dwLen2);
        }
    }

    ds_write_cursor += ds_chunk_size;
    if (ds_write_cursor >= ds_buffer_size) {
        ds_write_cursor -= ds_buffer_size;
    }

done:
    bInTimer = 0;
}
