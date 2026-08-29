#include "../include/dsutil.h"

typedef struct SNDOBJ SNDOBJ;
struct SNDOBJ {
    unsigned char* pbWaveData;
    unsigned long cbWaveSize;
    int iAlloc;
    int iCurrent;
    LPDIRECTSOUNDBUFFER Buffers[1];
};

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
extern int __cdecl WaveWriteFile(HMMIO, unsigned int, const unsigned char*, unsigned int, unsigned int*, MMIOINFO*);
extern int __cdecl WaveCloseWriteFile(HMMIO*, MMCKINFO*, MMCKINFO*, MMIOINFO*, DWORD);
extern int __cdecl riffCopyChunk(HMMIO, HMMIO, MMCKINFO*);

extern void __stdcall ds_stream_time_func(unsigned int, unsigned int, unsigned long, unsigned long, unsigned long);

void __cdecl ShowErrMsg(void)
{
}

LPDIRECTSOUNDBUFFER __cdecl DSLoadSoundBuffer(LPDIRECTSOUND ds, const char* name)
{
    LPDIRECTSOUNDBUFFER pDSB = 0;
    DSBUFFERDESC dsBD = {0};
    void* pbWaveData;

    if (DSGetWaveResource(0, name, &dsBD.lpwfxFormat, &pbWaveData,
                          (void*)&dsBD.dwBufferBytes) != 0) {
        dsBD.dwSize = sizeof(dsBD);
        dsBD.dwFlags = 0xe2;
        if (IDirectSound_CreateSoundBuffer(ds, &dsBD, &pDSB, 0) >= 0) {
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

int __cdecl DSReloadSoundBuffer(LPDIRECTSOUNDBUFFER buffer, int param2,
                                void* param3)
{
    int result = 0;
    int local_4;

    (void)param3;
    if (DSGetWaveResource(0, (const char*)param2, 0, (void*)&local_4,
                          (void*)&param2) != 0) {
        if (IDirectSoundBuffer_Restore(buffer) >= 0) {
            if (DSFillSoundBuffer(buffer, (void*)local_4, param2) != 0) {
                result = 1;
            }
        }
    }
    return result;
}

int __cdecl DSGetWaveResource(void* hModule, const char* lpName, void* out1,
                              void* out2, void* out3)
{
    void* resource;

    resource = FindResourceA((HMODULE)hModule, lpName, (LPCSTR)0x570428);
    if (resource != 0) {
        resource = LoadResource((HMODULE)hModule, (HRSRC)resource);
        if (resource != 0) {
            resource = LockResource((HGLOBAL)resource);
            if (resource != 0) {
                if (DSParseWaveResource(resource, out1, out2, out3) != 0) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

SNDOBJ* __cdecl SndObjCreate(LPDIRECTSOUND pDS, const char* lpName,
                             int count)
{
    unsigned char* pbData;
    unsigned long cbData;
    void* pWaveHeader;
    SNDOBJ* obj;
    int i;
    LPDIRECTSOUNDBUFFER* buf;

    obj = 0;
    if (DSGetWaveResource(0, lpName, &pWaveHeader, &pbData, &cbData) != 0) {
        i = 1;
        if (count < i) {
            count = i;
        }
        obj = (SNDOBJ*)LocalAlloc(0x40, count * 4 + 0x10);
        if (obj != 0) {
            obj->iAlloc = count;
            obj->pbWaveData = pbData;
            obj->cbWaveSize = cbData;
            obj->Buffers[0] = DSLoadSoundBuffer(pDS, lpName);
            if (i < obj->iAlloc) {
                buf = &obj->Buffers[1];
                while (1) {
                    if (pDS->lpVtbl->DuplicateSoundBuffer(
                            pDS, obj->Buffers[0], buf) < 0) {
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

void __cdecl SndObjDestroy(void* obj)
{
    if (obj != 0) {
        int i = 0;
        if (*(int*)((char*)obj + 8) > 0) {
            do {
                LPDIRECTSOUNDBUFFER buffer = *(LPDIRECTSOUNDBUFFER*)
                    ((char*)obj + 0x10 + i * 4);
                if (buffer != 0) {
                    IDirectSoundBuffer_Release(buffer);
                    *(LPDIRECTSOUNDBUFFER*)((char*)obj + 0x10 + i * 4) = 0;
                }
                ++i;
            } while (i < *(int*)((char*)obj + 8));
        }
        LocalFree((HLOCAL)obj);
    }
}

LPDIRECTSOUNDBUFFER __cdecl SndObjGetFreeBuffer(SNDOBJ* obj)
{
    LPDIRECTSOUNDBUFFER buf;
    DWORD status;
    int hr;

    if (obj == 0) return 0;

    buf = obj->Buffers[obj->iCurrent];
    if (buf != 0) {
        hr = IDirectSoundBuffer_GetStatus(buf, &status);
        if (hr < 0) {
            status = 0;
        }
        if ((status & 1) == 1) {
            if (obj->iAlloc > 1) {
                obj->iCurrent++;
                if (obj->iCurrent >= obj->iAlloc) {
                    obj->iCurrent = 0;
                }
                buf = obj->Buffers[obj->iCurrent];
                hr = IDirectSoundBuffer_GetStatus(buf, &status);
                if (hr >= 0 && (status & 1) == 1) {
                    IDirectSoundBuffer_Stop(buf);
                    IDirectSoundBuffer_SetCurrentPosition(buf, 0);
                }
            } else {
                buf = 0;
            }
        }

        if (buf != 0 && (status & 2) != 0) {
            hr = IDirectSoundBuffer_Restore(buf);
            if (hr < 0 || DSFillSoundBuffer(buf, obj->pbWaveData,
                                            obj->cbWaveSize) == 0) {
                buf = 0;
            }
        }
    }

    return buf;
}

unsigned int __cdecl SndObjPlay(SNDOBJ* sndobj, unsigned long flags)
{
    unsigned int result;
    LPDIRECTSOUNDBUFFER buffer;
    int hr;

    result = 0;
    if (sndobj == 0) {
        return result;
    }
    if (((flags & 1) == 0) || (sndobj->iAlloc == 1)) {
        buffer = SndObjGetFreeBuffer(sndobj);
        if (buffer != 0) {
            hr = IDirectSoundBuffer_Play(buffer, 0, 0, flags);
            result = (unsigned int)(hr >= 0);
        }
    }
    return result;
}

int __cdecl SndObjStop(SNDOBJ* obj)
{
    if (obj == 0) {
        return 0;
    }

    {
        int i = 0;
        if (obj->iAlloc > 0) {
            do {
                LPDIRECTSOUNDBUFFER buf = obj->Buffers[i];
                IDirectSoundBuffer_Stop(buf);
                IDirectSoundBuffer_SetCurrentPosition(buf, 0);
                ++i;
            } while (i < obj->iAlloc);
        }
        return 1;
    }
}

int __cdecl DSFillSoundBuffer(LPDIRECTSOUNDBUFFER dsb, void* data,
                              int size)
{
    int hr;
    void* ptr1;
    int size1;
    void* ptr2;
    int size2;

    if (!dsb || !data || !size)
        return 0;

    hr = IDirectSoundBuffer_Lock(dsb, 0, size, &ptr1, (DWORD*)&size1,
                                 &ptr2, (DWORD*)&size2, 0);
    if (hr < 0)
        return 0;

    memcpy(ptr1, data, size1);
    if (size2)
        memcpy((char*)ptr2, (char*)data + size1, size2);

    IDirectSoundBuffer_Unlock(dsb, ptr1, size1, ptr2, size2);
    return 1;
}

int __cdecl DSParseWaveResource(void* pvRes, void** ppWaveHeader,
                                BYTE** ppbData, DWORD* pdwDataSize)
{
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

    pdw = (DWORD*)pvRes;
    dwRiff = *pdw++;
    dwLength = *pdw++;
    dwType = *pdw++;

    if (dwRiff != 0x46464952) {
        return 0;
    }
    if (dwType != 0x45564157) {
        return 0;
    }

    pdwEnd = (DWORD*)((BYTE*)pdw + dwLength - 4);

    while (pdw < pdwEnd) {
        dwType = *pdw++;
        dwLength = *pdw++;

        switch (dwType) {
        case 0x61746164:
            if ((ppbData && !*ppbData) || (pdwDataSize && !*pdwDataSize)) {
                if (ppbData) {
                    *ppbData = (BYTE*)pdw;
                }
                if (pdwDataSize) {
                    *pdwDataSize = dwLength;
                }

                if (!ppWaveHeader || *ppWaveHeader) {
                    return 1;
                }
            }
            break;

        case 0x20746D66:
            if (ppWaveHeader && !*ppWaveHeader) {
                if (dwLength < 0x0e) {
                    return 0;
                }
                *ppWaveHeader = pdw;

                if ((!ppbData || *ppbData) &&
                    (!pdwDataSize || *pdwDataSize)) {
                    return 1;
                }
            }
            break;
        }

        pdw = (DWORD*)((BYTE*)pdw + ((dwLength + 1) & ~1));
    }

    return 0;
}

#pragma function(memcpy)
int __cdecl WaveOpenFile(char* pszFileName, HMMIO* phmmioIn,
                         LPWAVEFORMATEX* ppwfxInfo,
                         MMCKINFO* pckInRIFF)
{
    HMMIO hmmioIn;
    MMCKINFO ckIn;
    PCMWAVEFORMAT pcmWaveFormat;
    WORD cbExtraAlloc;
    int err;

    *ppwfxInfo = 0;
    err = 0;
    hmmioIn = 0;

    if ((hmmioIn = mmioOpenA(pszFileName, 0, 0x10000)) == 0) {
        err = 0xE100;
        goto error;
    }

    if ((err = mmioDescend(hmmioIn, (LPMMCKINFO)pckInRIFF, 0, 0)) != 0) {
        goto error;
    }

    if (pckInRIFF->ckid != mmioFOURCC('R', 'I', 'F', 'F') ||
        pckInRIFF->fccType != mmioFOURCC('W', 'A', 'V', 'E')) {
        err = 0xE101;
        goto error;
    }

    ckIn.ckid = mmioFOURCC('f', 'm', 't', ' ');
    if ((err = mmioDescend(hmmioIn, (LPMMCKINFO)&ckIn,
                           (LPMMCKINFO)pckInRIFF, 0x10)) != 0) {
        goto error;
    }

    if (ckIn.cksize < sizeof(pcmWaveFormat)) {
        err = 0xE101;
        goto error;
    }

    if (mmioRead(hmmioIn, (char*)&pcmWaveFormat, sizeof(pcmWaveFormat)) !=
        sizeof(pcmWaveFormat)) {
        err = 0xE102;
        goto error;
    }

    if (pcmWaveFormat.wf.wFormatTag == WAVE_FORMAT_PCM) {
        cbExtraAlloc = 0;
    } else {
        if (mmioRead(hmmioIn, (char*)&cbExtraAlloc, sizeof(cbExtraAlloc)) !=
            sizeof(cbExtraAlloc)) {
            err = 0xE102;
            goto error;
        }
    }

    if ((*ppwfxInfo = GlobalAlloc(0, (DWORD)cbExtraAlloc + 18)) == 0) {
        err = 0xE000;
        goto error;
    }

    memcpy(*ppwfxInfo, &pcmWaveFormat, sizeof(pcmWaveFormat));
    (*ppwfxInfo)->cbSize = cbExtraAlloc;

    if (cbExtraAlloc != 0) {
        if (mmioRead(hmmioIn,
                    (char*)&(*ppwfxInfo)->cbSize + sizeof(cbExtraAlloc),
                    cbExtraAlloc) != cbExtraAlloc) {
            err = 0xE101;
            goto error;
        }
    }

    if ((err = mmioAscend(hmmioIn, (LPMMCKINFO)&ckIn, 0)) != 0) {
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

int __cdecl WaveStartDataRead(HMMIO* handle_ptr, MMCKINFO* buffer,
                              MMCKINFO* wave_info)
{
    if (mmioSeek(*handle_ptr, wave_info->dwDataOffset + 4, 0) == -1) {
        return 1;
    }

    buffer->ckid = 0x61746164;
    return mmioDescend(*handle_ptr, (LPMMCKINFO)buffer,
                       (LPMMCKINFO)wave_info, 0x10);
}

int __cdecl WaveReadFile(HMMIO hmmio, UINT cbRead, BYTE* pbDest,
                         MMCKINFO* pckIn, UINT* cbActualRead)
{
    MMIOINFO mmioinfoIn;
    int nError = 0;
    UINT cT;
    UINT cbDataIn;
    UINT cbDataToCopy;

    if ((nError = (mmioGetInfo(hmmio, (LPMMIOINFO)&mmioinfoIn, 0) != 0))) {
        goto error;
    }

    cbDataIn = cbRead;
    if (cbDataIn > pckIn->cksize) {
        cbDataIn = pckIn->cksize;
    }

    pckIn->cksize -= cbDataIn;

    for (cT = 0; cT < cbDataIn;) {
        if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead) {
            if ((nError = mmioAdvance(hmmio, (LPMMIOINFO)&mmioinfoIn, 0)) != 0) {
                goto error;
            }
            if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead) {
                nError = 0xE103;
                goto error;
            }
        }

        cbDataToCopy = mmioinfoIn.pchEndRead - mmioinfoIn.pchNext;
        if (cbDataIn - cT < cbDataToCopy) {
            memcpy((cbDataToCopy = cbDataIn - cT, (BYTE*)pbDest + cT),
                   (BYTE*)mmioinfoIn.pchNext, cbDataIn - cT);
        } else {
            memcpy((BYTE*)pbDest + cT, (BYTE*)mmioinfoIn.pchNext,
                   cbDataToCopy);
        }
        cT += cbDataToCopy;
        mmioinfoIn.pchNext += cbDataToCopy;
    }

    if ((nError = mmioSetInfo(hmmio, (LPMMIOINFO)&mmioinfoIn, 0)) != 0) {
        goto error;
    }

    *cbActualRead = cbDataIn;
    goto done;

error:
    *cbActualRead = 0;
done:
    return nError;
}

int __cdecl WaveCloseReadFile(HMMIO* hmmio, HGLOBAL* pwav)
{
    if (*pwav != 0) {
        GlobalFree(*pwav);
        *pwav = 0;
    }
    if (*hmmio != 0) {
        mmioClose(*hmmio, 0);
        *hmmio = 0;
    }
    return 0;
}

int __cdecl WaveCreateFile(char* pszFileName, HMMIO* phmmioOut,
                           WAVEFORMATEX* pwfxDest,
                           MMCKINFO* pckOut,
                           MMCKINFO* pckOutRIFF)
{
    int err;
    DWORD dwFactChunk;
    MMCKINFO ckOut1;

    dwFactChunk = (DWORD)-1;
    err = 0;

    *phmmioOut = mmioOpenA(pszFileName, 0, 0x11002);
    if (*phmmioOut == 0) {
        err = 0xE104;
        goto done;
    }

    pckOutRIFF->fccType = 0x45564157;
    pckOutRIFF->cksize = 0;
    if ((err = mmioCreateChunk(*phmmioOut, (LPMMCKINFO)pckOutRIFF, 0x20)) != 0) {
        goto done;
    }

    pckOut->ckid = 0x20746D66;
    pckOut->cksize = 16;
    if ((err = mmioCreateChunk(*phmmioOut, (LPMMCKINFO)pckOut, 0)) != 0) {
        goto done;
    }

    if (pwfxDest->wFormatTag == 1) {
        if (mmioWrite(*phmmioOut, (const char*)pwfxDest, 16) != 16) {
            err = 0xE104;
            goto done;
        }
    } else {
        if ((UINT)mmioWrite(*phmmioOut, (const char*)pwfxDest,
                            18 + pwfxDest->cbSize) !=
            (18 + pwfxDest->cbSize)) {
            goto fail;
        }
    }

    if ((err = mmioAscend(*phmmioOut, (LPMMCKINFO)pckOut, 0)) != 0) {
        goto done;
    }

    ckOut1.ckid = 0x74636166;
    ckOut1.cksize = 0;
    if ((err = mmioCreateChunk(*phmmioOut, (LPMMCKINFO)&ckOut1, 0)) != 0) {
        goto done;
    }

    if (mmioWrite(*phmmioOut, (const char*)&dwFactChunk, sizeof(dwFactChunk)) !=
        sizeof(dwFactChunk)) {
        goto fail;
    }

    if ((err = mmioAscend(*phmmioOut, (LPMMCKINFO)&ckOut1, 0)) == 0) {
        goto done;
    }

fail:
    err = 0xE104;

done:
    return err;
}

MMRESULT __cdecl WaveStartDataWrite(void* hmmioPtr, MMCKINFO* ckOut,
                                    MMIOINFO* mmioinfoOut)
{
    MMRESULT result;

    ckOut->ckid = 0x61746164;
    ckOut->cksize = 0;
    result = mmioCreateChunk(*(HMMIO*)hmmioPtr, (LPMMCKINFO)ckOut, 0);
    if (result != 0) {
        return result;
    }
    return mmioGetInfo(*(HMMIO*)hmmioPtr, (LPMMIOINFO)mmioinfoOut, 0);
}

int __cdecl WaveWriteFile(HMMIO hmmio, unsigned int cBytes,
                          const unsigned char* lpSrc, unsigned int pad,
                          unsigned int* pdwWritten, MMIOINFO* lpmmio)
{
    unsigned int i = 0;
    (void)pad;
    *pdwWritten = 0;
    if (cBytes <= 0) return;
    do {
        if (lpmmio->pchNext == lpmmio->pchEndWrite) {
            lpmmio->dwFlags = lpmmio->dwFlags | 0x10000000;
            if (mmioAdvance(hmmio, (LPMMIOINFO)lpmmio, 1) != 0) {
                return;
            }
        }
        *lpmmio->pchNext = lpSrc[i];
        lpmmio->pchNext = lpmmio->pchNext + 1;
        i = i + 1;
        *pdwWritten = *pdwWritten + 1;
    } while (i < cBytes);
}

int __cdecl WaveCloseWriteFile(HMMIO* phmmioOut, MMCKINFO* pckOut,
                               MMCKINFO* pckOutRIFF,
                               MMIOINFO* pmmioinfoOut, DWORD cSamples)
{
    int result;

    if (*phmmioOut == 0) {
        return 0;
    }

    pmmioinfoOut->dwFlags |= 0x10000000;
    result = mmioSetInfo(*phmmioOut, (LPMMIOINFO)pmmioinfoOut, 0);
    if (result == 0) {
        result = mmioAscend(*phmmioOut, (LPMMCKINFO)pckOut, 0);
        if (result == 0) {
            result = mmioAscend(*phmmioOut, (LPMMCKINFO)pckOutRIFF, 0);
            if (result == 0) {
                mmioSeek(*phmmioOut, 0, 0);
                result = mmioDescend(*phmmioOut, (LPMMCKINFO)pckOutRIFF, 0, 0);
                if (result == 0) {
                    pckOut->ckid = 0x74636166;
                    if (mmioDescend(*phmmioOut, (LPMMCKINFO)pckOut,
                                    (LPMMCKINFO)pckOutRIFF, 0x10) == 0) {
                        mmioWrite(*phmmioOut, (const char*)&cSamples,
                                  sizeof(DWORD));
                        mmioAscend(*phmmioOut, (LPMMCKINFO)pckOut, result);
                        result = mmioAscend(*phmmioOut,
                                            (LPMMCKINFO)pckOutRIFF, 0);
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

int __cdecl WaveCopyUselessChunks(HMMIO* hmmio, MMCKINFO* ck,
                                  MMCKINFO* parent, HMMIO* src)
{
    int result;

    if (mmioSeek(*hmmio, parent->dwDataOffset + 4, 0) == -1) {
        result = 0xE102;
    } else {
        result = 0;
        while (mmioDescend(*hmmio, (LPMMCKINFO)ck,
                           (LPMMCKINFO)parent, 0) == 0) {
            if (ck->dwDataOffset + ck->cksize >
                parent->cksize + parent->dwDataOffset) {
                break;
            }
            if (ck->ckid != 0x20444150) {
                if (ck->ckid == 0x50534944 || ck->ckid == 0x74736c70) {
                    riffCopyChunk(*hmmio, *src, ck);
                }
            }
            mmioAscend(*hmmio, (LPMMCKINFO)ck, 0);
        }
    }

    mmioSeek(*hmmio, parent->dwDataOffset + 4, 0);
    return result;
}

#define CLEANUP_DATA() do { \
    GlobalUnlock(GlobalHandle(data)); \
    GlobalFree(GlobalHandle(data)); \
} while (0)

int __cdecl riffCopyChunk(HMMIO hmmioSrc, HMMIO hmmioDst,
                          MMCKINFO* pckIn)
{
    MMCKINFO ck;
    char* data;

    data = (char*)GlobalLock(GlobalAlloc(0x42, pckIn->cksize));
    if (data == 0) {
        return 0;
    }

    ck.ckid = pckIn->ckid;
    ck.cksize = pckIn->cksize;
    if (mmioCreateChunk(hmmioDst, (LPMMCKINFO)&ck, 0) != 0) {
        goto fail;
    }
    if (mmioRead(hmmioSrc, data, pckIn->cksize) !=
        (LONG)pckIn->cksize) {
        goto fail;
    }
    if (mmioWrite(hmmioDst, data, pckIn->cksize) != pckIn->cksize) {
        goto fail;
    }
    if (mmioAscend(hmmioDst, (LPMMCKINFO)&ck, 0) != 0) {
        goto fail;
    }

    CLEANUP_DATA();
    return 1;

fail:
    CLEANUP_DATA();
    return 0;
}

int __cdecl WaveLoadFile(char* pszFileName, DWORD* pcbWaveSize,
                         DWORD* pcbHeaderSize, void** ppWaveHeader,
                         unsigned char** ppbWaveData)
{
    HMMIO hmmio;
    MMCKINFO ckInRiff;
    MMCKINFO ckIn;
    int err;
    DWORD cbActualRead;

    (void)pcbHeaderSize;
    *ppbWaveData = 0;
    *ppWaveHeader = 0;
    *pcbWaveSize = 0;

    err = WaveOpenFile(pszFileName, &hmmio, (LPWAVEFORMATEX*)ppWaveHeader,
                       &ckInRiff);
    if (err != 0) {
        goto error;
    }

    err = WaveStartDataRead(&hmmio, &ckIn, &ckInRiff);
    if (err != 0) {
        goto error;
    }

    *ppbWaveData = (unsigned char*)GlobalAlloc(0, ckIn.cksize);
    if (*ppbWaveData == 0) {
        err = 0xE000;
        goto error;
    }

    err = WaveReadFile(hmmio, ckIn.cksize, *ppbWaveData, &ckIn,
                       &cbActualRead);
    if (err != 0) {
        goto error;
    }

    *pcbWaveSize = cbActualRead;
    goto done;

error:
    if (*ppbWaveData != 0) {
        GlobalFree(*ppbWaveData);
        *ppbWaveData = 0;
    }
    if (*ppWaveHeader != 0) {
        GlobalFree(*ppWaveHeader);
        *ppWaveHeader = 0;
    }

done:
    if (hmmio != 0) {
        mmioClose(hmmio, 0);
    }
    return err;
}

void __cdecl WaveSaveFile(void* param_1, void* param_2, void* param_3,
                          void* param_4, void* param_5)
{
    struct WaveSaveLocals {
        void* cbActualWrite;
        char ckOut[0x14];
        char ckOutRIFF[0x14];
        char pad[4];
        char mmioinfoOut[0x48];
    } l;

    if (WaveCreateFile((char*)param_1, (HMMIO*)&l.cbActualWrite,
                       (WAVEFORMATEX*)param_4,
                       (MMCKINFO*)(l.ckOut + 4),
                       (MMCKINFO*)(l.ckOutRIFF + 4)) == 0) {
        if (WaveStartDataWrite(&l.cbActualWrite,
                               (MMCKINFO*)(l.ckOut + 4),
                               (MMIOINFO*)l.mmioinfoOut) == 0) {
            if (WaveWriteFile((HMMIO)l.cbActualWrite, (unsigned int)param_2,
                              (const unsigned char*)param_5,
                              (unsigned int)(l.ckOut + 4),
                              (unsigned int*)l.ckOut,
                              (MMIOINFO*)l.mmioinfoOut) == 0) {
                WaveCloseWriteFile((HMMIO*)&l.cbActualWrite,
                                   (MMCKINFO*)(l.ckOut + 4),
                                   (MMCKINFO*)(l.ckOutRIFF + 4),
                                   (MMIOINFO*)l.mmioinfoOut,
                                   (DWORD)(unsigned long)param_3);
            }
        }
    }
}

void __cdecl ds_stream_init(unsigned int main_wnd, unsigned int lpDS,
                            unsigned int lpBuffer)
{
    _uLastPercent = 100;
    _lpDSBStreamBuffer = 0;
    _bFileOpen = 0;
    _bPlaying = 0;
    _bTimerInstalled = 0;
    _uTimerID = 0;
    _main_wnd = (HWND)main_wnd;
    _lpBuffer = lpBuffer;
    _lpDS = (void*)lpDS;
    _ds_ready = 1;
}

void __cdecl ds_stream_exit(void)
{
    if (_ds_ready != 0) {
        if ((_bFileOpen != 0) || (_bPlaying != 0) ||
            (_bTimerInstalled != 0)) {
            ds_stream_stop();
        }
        _ds_ready = 0;
    }
}

int __cdecl ds_stream_file(char* filename, int param_2, long param_3)
{
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
    result = WaveOpenFile(filename, &ds_wave_file,
                          (LPWAVEFORMATEX*)&_wiWave, &ds_wave_riff_chunk);
    if (result != 0) {
        return 0;
    }

    if (*(short*)_wiWave != 1) {
        WaveCloseReadFile(&ds_wave_file, (HGLOBAL*)&_wiWave);
        return 0;
    }

    result = WaveStartDataRead(&ds_wave_file, &ds_wave_data_chunk,
                               &ds_wave_riff_chunk);
    if (result != 0) {
        WaveCloseReadFile(&ds_wave_file, (HGLOBAL*)&_wiWave);
        return 0;
    }

    ds_chunk_size = ((((LPWAVEFORMATEX)_wiWave)->nAvgBytesPerSec * 120) / 100) / 6;
    ds_buffer_size = ds_chunk_size * 6;
    memset(&dsbd, 0, sizeof(dsbd));

    dsbd.dwSize = 20;
    dsbd.dwFlags = 0xE0;
    dsbd.dwBufferBytes = ds_buffer_size;
    dsbd.lpwfxFormat = (void*)_wiWave;
    result = IDirectSound_CreateSoundBuffer((LPDIRECTSOUND)_lpDS, &dsbd,
        (LPLPDIRECTSOUNDBUFFER)&_lpDSBStreamBuffer, 0);
    if (result != 0) {
        return 0;
    }

    ds_stream_buffer = _lpDSBStreamBuffer;
    ds_stream_at_end = 0;
    ds_silence_chunks = 0;
    result = IDirectSoundBuffer_Lock((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer,
        0, ds_buffer_size, (void**)&lpWrite1, &dwLen1,
        (void**)&lpWrite2, &dwLen2, 0);
    if (result != 0) {
        return 0;
    }

    if (dwLen1 != 0) {
        WaveReadFile(ds_wave_file, dwLen1, lpWrite1, &ds_wave_data_chunk,
                     &uChkErr);
        if (uChkErr < dwLen1) {
            if (ds_stream_loop != 0) {
                unsigned char* lpWriteCursor = lpWrite1;
                do {
                    lpWriteCursor += uChkErr;
                    dwLen1 -= uChkErr;
                    WaveStartDataRead(&ds_wave_file, &ds_wave_data_chunk,
                                      &ds_wave_riff_chunk);
                    WaveReadFile(ds_wave_file, dwLen1, lpWriteCursor,
                                 &ds_wave_data_chunk, &uChkErr);
                } while (uChkErr < dwLen1);
            } else {
                ds_silence_chunks = uChkErr / ds_chunk_size;
                ds_stream_at_end = 1;
                memset((unsigned char*)lpWrite1 + uChkErr,
                    ((((LPWAVEFORMATEX)_wiWave)->wBitsPerSample != 8) - 1) & 0x80,
                    dwLen1 - uChkErr);
            }
        }
    }

    IDirectSoundBuffer_Unlock((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer,
        lpWrite1, dwLen1, lpWrite2, 0);

    ds_stream_position = 0;
    ds_last_play_cursor = 0;
    ds_write_cursor = 0;
    ds_stream_stop_requested = 0;
    ds_stream_loop = param_2 & 0xff;
    _bFileOpen = 1;
    SendMessageA((HWND)_main_wnd, 0x502, 0, 0);

    IDirectSoundBuffer_SetCurrentPosition((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer, 0);
    IDirectSoundBuffer_SetVolume((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer, param_3);
    IDirectSoundBuffer_Play((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer, 0, 0, 1);

    if (timeBeginPeriod(0x32) != 0) {
        IDirectSoundBuffer_Stop((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer);
        _bTimerInstalled = 0;
        _bPlaying = 0;
        return 0;
    }

    _uTimerID = timeSetEvent(0x32, 10, ds_stream_time_func, 0, 1);
    if (_uTimerID != 0) {
        _bTimerInstalled = 1;
    }
    _bPlaying = 1;
    return 1;
}

int __cdecl ds_stream_volume(int volume)
{
    LPDIRECTSOUNDBUFFER stream;
    int result;

    stream = (LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer;
    if (stream == 0) {
        return 0;
    }
    result = IDirectSoundBuffer_SetVolume(stream, volume);
    return result == 0;
}

void __cdecl ds_stream_pause(void)
{
    _stream_paused = 1;
}

int __cdecl ds_stream_resume(void)
{
    _stream_paused = 0;
    return 1;
}

int __cdecl ds_stream_stop(void)
{
    ds_stream_stop_requested = 1;
    if (_bTimerInstalled != 0) {
        _bTimerInstalled = 0;
        timeKillEvent(_uTimerID);
        timeEndPeriod(0x32);
    }

    if (_bPlaying != 0) {
        _bPlaying = 0;
        if (_lpDSBStreamBuffer != 0) {
            IDirectSoundBuffer_Stop((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer);
        }
    }

    if (_bFileOpen != 0) {
        if (_wiWave != 0) {
            WaveCloseReadFile(&ds_wave_file, (HGLOBAL*)&_wiWave);
            _wiWave = 0;
        }
        if (_lpDSBStreamBuffer != 0) {
            IDirectSoundBuffer_Release((LPDIRECTSOUNDBUFFER)_lpDSBStreamBuffer);
            _lpDSBStreamBuffer = 0;
            ds_stream_buffer = 0;
        }
        _bFileOpen = 0;
    }
    return 1;
}

int __cdecl ds_stream_messages(int a1, int a2)
{
    (void)a1;
    switch (a2) {
    case 0x500:
        ds_stream_stop();
        break;
    case 0x502: {
        unsigned long a = ds_stream_position;
        unsigned long b = ds_buffer_bytes;
        if (a > b) {
            ds_stream_position = a - b;
            a = a - b;
        }
        {
            unsigned long temp = a * 100 / b;
            double d = (double)temp;
            long percent = (long)d;
            if (percent != ds_last_percent) {
                ds_last_percent = percent;
            }
        }
        break;
    }
    }
    return 0;
}

void __stdcall ds_stream_time_func(unsigned int timer_id, unsigned int message,
    unsigned long user, unsigned long first, unsigned long second)
{
    DWORD dwLen1;
    DWORD dwLen2;
    unsigned char* lpWrite1;
    DWORD uChkErr;
    unsigned char* lpWrite2;
    DWORD dwPlay;
    DWORD dwWrite;
    DWORD local_4;

    (void)timer_id;
    (void)message;
    (void)user;
    (void)first;
    (void)second;
    if (ds_stream_callback_active != 0) return;
    if (_stream_paused != 0) return;
    ds_stream_callback_active = 1;
    if (ds_stream_stop_requested != 0) {
        ds_stream_callback_active = 0;
        return;
    }
    if (ds_stream_buffer == (void*)0) {
        ds_stream_callback_active = 0;
        return;
    }

    IDirectSoundBuffer_GetCurrentPosition((LPDIRECTSOUNDBUFFER)ds_stream_buffer,
        &local_4, &dwWrite);
    if (ds_write_cursor < dwWrite) {
        DWORD t = ds_write_cursor + ds_chunk_size;
        if (t > dwWrite) goto done;
    }

    if (ds_stream_at_end && ds_silence_chunks == 0) {
        if (ds_stream_stop_requested != 0) goto done;
        ds_stream_stop_requested = 1;
        PostMessageA((HWND)_main_wnd, 0x500, 0, 0);
        ds_stream_callback_active = 0;
        return;
    }

    {
        DWORD diff;
        if (dwWrite < ds_last_play_cursor) diff = ds_buffer_size + dwWrite;
        else diff = dwWrite;
        diff -= ds_last_play_cursor;
        ds_last_play_cursor = dwWrite;
        ds_stream_position += diff;
        PostMessageA((HWND)_main_wnd, 0x502, 0, 0);
    }

    if (ds_stream_at_end && ds_silence_chunks) {
        --ds_silence_chunks;
        if (ds_silence_chunks <= 1) goto done;
        if (ds_stream_buffer == (void*)0) goto done;
        if (IDirectSoundBuffer_Lock((LPDIRECTSOUNDBUFFER)ds_stream_buffer,
            ds_write_cursor, ds_chunk_size, (void**)&lpWrite1, &dwLen1,
            (void**)&lpWrite2, &dwLen2, 0)) goto done;
        if (lpWrite1 && _wiWave != 0 &&
            ((LPWAVEFORMATEX)_wiWave)->wBitsPerSample == 8)
            memset(lpWrite1, 0x80, dwLen1);
        else if (lpWrite1 && _wiWave != 0 &&
                 ((LPWAVEFORMATEX)_wiWave)->wBitsPerSample == 16)
            memset(lpWrite1, 0, dwLen1);
        IDirectSoundBuffer_Unlock((LPDIRECTSOUNDBUFFER)ds_stream_buffer,
            lpWrite1, dwLen1, lpWrite2, dwLen2);
        ds_write_cursor += ds_chunk_size;
        if (ds_write_cursor < ds_buffer_size) goto done;
        goto wrap_play;
    }

    if (ds_stream_buffer == (void*)0) goto done;
    if (IDirectSoundBuffer_Lock((LPDIRECTSOUNDBUFFER)ds_stream_buffer,
        ds_write_cursor, ds_chunk_size, (void**)&lpWrite1, &dwLen1,
        (void**)&lpWrite2, &dwLen2, 0)) goto done;

    if (dwLen1 == 0 || ds_stream_stop_requested != 0) {
        if (dwLen1 != 0 && ds_stream_stop_requested != 0) {
            if (lpWrite1 && _wiWave != 0 &&
                ((LPWAVEFORMATEX)_wiWave)->wBitsPerSample == 8)
                memset(lpWrite1, 0x80, dwLen1);
            else if (lpWrite1 && _wiWave != 0 &&
                     ((LPWAVEFORMATEX)_wiWave)->wBitsPerSample == 16)
                memset(lpWrite1, 0, dwLen1);
        }
    } else {
        WaveReadFile(ds_wave_file, dwLen1, lpWrite1, &ds_wave_data_chunk,
                     &uChkErr);
        if (uChkErr < dwLen1) {
            if (ds_stream_loop == 0) {
                if (lpWrite1 && _wiWave != 0 &&
                    ((LPWAVEFORMATEX)_wiWave)->wBitsPerSample == 8)
                    memset(lpWrite1 + uChkErr, 0x80, dwLen1 - uChkErr);
                else if (lpWrite1 && _wiWave != 0 &&
                         ((LPWAVEFORMATEX)_wiWave)->wBitsPerSample == 16)
                    memset(lpWrite1 + uChkErr, 0, dwLen1 - uChkErr);
                if (ds_write_cursor <= dwLen2)
                    ds_silence_chunks = (ds_buffer_size + ds_write_cursor - dwLen2) / ds_chunk_size;
                else
                    ds_silence_chunks = (ds_write_cursor - dwLen2) / ds_chunk_size;
                ds_stream_at_end = 1;
            } else if (lpWrite1) {
                unsigned char* retryWrite1 = lpWrite1;
                do {
                    retryWrite1 += uChkErr;
                    dwLen1 -= uChkErr;
                    WaveStartDataRead(&ds_wave_file, &ds_wave_data_chunk,
                                      &ds_wave_riff_chunk);
                    WaveReadFile(ds_wave_file, dwLen1, retryWrite1,
                        &ds_wave_data_chunk, &uChkErr);
                } while (uChkErr < dwLen1);
            }
        }
    }

    if (dwLen2 != 0 && ds_stream_stop_requested == 0) {
        WaveReadFile(ds_wave_file, dwLen2, lpWrite2, &ds_wave_data_chunk,
                     &uChkErr);
        if (uChkErr < dwLen2) {
            if (ds_stream_loop == 0) {
                if (lpWrite2 && _wiWave != 0 &&
                    ((LPWAVEFORMATEX)_wiWave)->wBitsPerSample == 8)
                    memset(lpWrite2 + uChkErr, 0x80, dwLen2 - uChkErr);
                else if (lpWrite2 && _wiWave != 0 &&
                         ((LPWAVEFORMATEX)_wiWave)->wBitsPerSample == 16)
                    memset(lpWrite2 + uChkErr, 0, dwLen2 - uChkErr);
                if (ds_write_cursor <= dwLen2)
                    ds_silence_chunks = (ds_buffer_size + ds_write_cursor - dwLen2) / ds_chunk_size;
                else
                    ds_silence_chunks = (ds_write_cursor - dwLen2) / ds_chunk_size;
                ds_stream_at_end = 1;
            } else if (lpWrite2) {
                unsigned char* retryWrite2 = lpWrite2;
                do {
                    retryWrite2 += uChkErr;
                    dwLen2 -= uChkErr;
                    WaveStartDataRead(&ds_wave_file, &ds_wave_data_chunk,
                                      &ds_wave_riff_chunk);
                    WaveReadFile(ds_wave_file, dwLen2, retryWrite2,
                        &ds_wave_data_chunk, &uChkErr);
                } while (uChkErr < dwLen2);
            }
        }
    } else if (dwLen2 != 0 && ds_stream_stop_requested != 0) {
        if (lpWrite2 && _wiWave != 0 &&
            ((LPWAVEFORMATEX)_wiWave)->wBitsPerSample == 8)
            memset(lpWrite2, 0x80, dwLen2);
        else if (lpWrite2 && _wiWave != 0 &&
                 ((LPWAVEFORMATEX)_wiWave)->wBitsPerSample == 16)
            memset(lpWrite2, 0, dwLen2);
    }

    if (ds_stream_buffer) IDirectSoundBuffer_Unlock(
        (LPDIRECTSOUNDBUFFER)ds_stream_buffer, lpWrite1, dwLen1,
        lpWrite2, dwLen2);
    ds_write_cursor += ds_chunk_size;
    if (ds_write_cursor < ds_buffer_size) goto done;

wrap_play:
    ds_write_cursor -= ds_buffer_size;

done:
    ds_stream_callback_active = 0;
}
