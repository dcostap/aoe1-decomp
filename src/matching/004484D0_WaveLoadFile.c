/* VA: 004484D0 _WaveLoadFile */
/* Dsutil.c lines 1251-1310, 229 bytes */

typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef struct DSUTIL_WAVELOAD_MMCKINFO {
    DWORD ckid;
    DWORD cksize;
    DWORD fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
} DSUTIL_WAVELOAD_MMCKINFO;

__declspec(dllimport) HGLOBAL __stdcall GlobalAlloc(UINT flags, DWORD bytes);
__declspec(dllimport) HGLOBAL __stdcall GlobalFree(HGLOBAL hMem);
__declspec(dllimport) int __stdcall mmioClose(HMMIO hmmio, UINT flags);

int __cdecl _WaveOpenFile(char* pszFileName, HMMIO* phmmioIn, void** ppWaveHeader, DSUTIL_WAVELOAD_MMCKINFO* pckInRIFF);
int __cdecl _WaveStartDataRead(HMMIO* phmmioIn, DSUTIL_WAVELOAD_MMCKINFO* pckIn, DSUTIL_WAVELOAD_MMCKINFO* pckInRIFF);
int __cdecl _WaveReadFile(HMMIO hmmioIn, DWORD cbRead, unsigned char* pbDest, DSUTIL_WAVELOAD_MMCKINFO* pckIn, DWORD* pcbActualRead);

int __cdecl _WaveLoadFile(char* pszFileName, DWORD* pcbWaveSize, DWORD* pcbHeaderSize, void** ppWaveHeader, unsigned char** ppbWaveData)
{
    HMMIO hmmio;
    DSUTIL_WAVELOAD_MMCKINFO ckInRiff;
    DSUTIL_WAVELOAD_MMCKINFO ckIn;
    int err;
    DWORD cbActualRead;

    *ppbWaveData = 0;
    *ppWaveHeader = 0;
    *pcbWaveSize = 0;

    err = _WaveOpenFile(pszFileName, &hmmio, ppWaveHeader, &ckInRiff);
    if (err != 0) {
        goto error;
    }

    err = _WaveStartDataRead(&hmmio, &ckIn, &ckInRiff);
    if (err != 0) {
        goto error;
    }

    *ppbWaveData = (unsigned char*)GlobalAlloc(0, ckIn.cksize);
    if (*ppbWaveData == 0) {
        err = 0xE000;
        goto error;
    }

    err = _WaveReadFile(hmmio, ckIn.cksize, *ppbWaveData, &ckIn, &cbActualRead);
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
