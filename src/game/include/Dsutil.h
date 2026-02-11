#pragma once
#include "common.h"

// WAV file header structure used by Dsutil
// Standard 44-byte WAV file header layout.
// Field names match decomp naming, NOT actual WAV spec names.
struct _tag_wavheader {
    char szRIFF[4];                 // +0x00  "RIFF"
    unsigned long dwRIFFLen;        // +0x04  RIFF chunk size
    char szWAVE[4];                 // +0x08  "WAVE"
    char szFMT[4];                  // +0x0C  "fmt "
    unsigned long dwFormatLength;   // +0x10  format chunk size (16 for PCM)
    unsigned long fmtTagChannels;   // +0x14  wFormatTag(lo16) + nChannels(hi16)
    unsigned long nSamplesPerSec;   // +0x18  actual samples per second
    unsigned long nAvgBytesPerSec;  // +0x1C  actual avg bytes/sec
    unsigned long blkAlignBPS;      // +0x20  nBlockAlign(lo16) + wBitsPerSample(hi16)
    char szDATA[4];                 // +0x24  "data"
    unsigned long dwDataSize;       // +0x28  data chunk size
};

// SndObj functions
void* SndObjCreate(IDirectSound* pDS, void* pRes, int nConcurrent);
void SndObjDestroy(void* pSO);
IDirectSoundBuffer* SndObjGetFreeBuffer(void* pSO);
int SndObjPlay(void* pSO, DWORD dwFlags);
int SndObjStop(void* pSO);

// DirectSound buffer helpers
IDirectSoundBuffer* DSLoadSoundBuffer(IDirectSound* pDS, void* pRes);
int DSReloadSoundBuffer(IDirectSoundBuffer* pDSB, void* pRes);
int DSGetWaveResource(HMODULE hModule, void* pRes, tWAVEFORMATEX** ppWaveHeader, unsigned char** ppbData, unsigned long* pdwDataSize);
int DSFillSoundBuffer(IDirectSoundBuffer* pDSB, unsigned char* pbData, unsigned long dwDataSize);
int DSParseWaveResource(void* pvRes, tWAVEFORMATEX** ppWaveHeader, unsigned char** ppbData, unsigned long* pdwDataSize);

// Wave file I/O
int WaveOpenFile(char* pszFileName, void** phmmioIn, tWAVEFORMATEX** ppwfxInfo, MMCKINFO* pckInRiff);
int WaveStartDataRead(void** phmmioIn, MMCKINFO* pckIn, MMCKINFO* pckInRiff);
int WaveReadFile(HMMIO hmmioIn, unsigned long cbRead, unsigned char* pbDest, MMCKINFO* pckIn, unsigned long* pcbActualRead);
int WaveCloseReadFile(HMMIO* phmmio, tWAVEFORMATEX** ppwfx);
int WaveCreateFile(char* pszFileName, HMMIO* phmmioOut, tWAVEFORMATEX* pwfxDest, MMCKINFO* pckOut, MMCKINFO* pckOutRIFF);
void WaveStartDataWrite(HMMIO* phmmioOut, MMCKINFO* pckOut, MMIOINFO* pmmioinfoOut);
void WaveWriteFile(HMMIO hmmioOut, unsigned long cbWrite, unsigned char* pbSrc, MMCKINFO* pckOut, unsigned long* pcbActualWrite, MMIOINFO* pmmioinfoOut);
int WaveCloseWriteFile(HMMIO* phmmioOut, MMCKINFO* pckOut, MMCKINFO* pckOutRIFF, MMIOINFO* pmmioinfoOut, unsigned long cSamples);
int WaveCopyUselessChunks(HMMIO* phmmioIn, MMCKINFO* pckIn, MMCKINFO* pckInRiff);
int WaveLoadFile(char* pszFileName, unsigned long* pcbWaveSize, unsigned long* pcbHeaderSize, unsigned char** ppbWaveData, tWAVEFORMATEX** ppWaveHeader);
void WaveSaveFile(char* pszFileName, unsigned long cbWaveSize, unsigned long cSamples, unsigned char* pbWaveData, tWAVEFORMATEX* pwfx);
int riffCopyChunk(HMMIO hmmioSrc, HMMIO hmmioDst, MMCKINFO* pckIn);

// DirectSound streaming
void ds_stream_init(void* main_wnd, IDirectSound* lpDS, IDirectSoundBuffer* lpBuffer);
void ds_stream_exit();
int ds_stream_file(char* filename, int loop, long volume);
int ds_stream_volume(long volume);
void ds_stream_pause();
int ds_stream_resume();
int ds_stream_stop();
int ds_stream_messages(void* hwnd, unsigned int msg, unsigned int wParam, long lParam);
void CALLBACK ds_stream_time_func(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

void ShowErrMsg();
