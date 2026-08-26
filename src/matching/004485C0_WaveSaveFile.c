/* VA: 004485C0 _WaveSaveFile */
/* Dsutil.c lines 1327-1360, 158 bytes */

extern int __cdecl WaveCreateFile(void* param_1, void* cbActualWrite, void* param_4, void* ckOut, void* ckOutRIFF);
extern int __cdecl WaveStartDataWrite(void* cbActualWrite, void* ckOut, void* mmioinfoOut);
extern int __cdecl WaveWriteFile(HMMIO hmmio, unsigned int cBytes, const unsigned char* lpSrc, unsigned int pad, unsigned int* pdwWritten, struct DSUTIL_WAVEWRITE_MMIOINFO* lpmmio);
extern int __cdecl WaveCloseWriteFile(void* cbActualWrite, void* ckOut, void* ckOutRIFF, void* mmioinfoOut, void* param_3);

struct WaveSaveLocals {
    void* cbActualWrite;
    char ckOut[0x14];
    char ckOutRIFF[0x14];
    char pad[4];
    char mmioinfoOut[0x48];
};

void __cdecl WaveSaveFile(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5)
{
    struct WaveSaveLocals l;

    if (WaveCreateFile(param_1, &l.cbActualWrite, param_4, l.ckOut + 4, l.ckOutRIFF + 4) == 0) {
        if (WaveStartDataWrite(&l.cbActualWrite, l.ckOut + 4, l.mmioinfoOut) == 0) {
            if (WaveWriteFile(l.cbActualWrite, param_2, param_5, l.ckOut + 4, l.ckOut, l.mmioinfoOut) == 0) {
                WaveCloseWriteFile(&l.cbActualWrite, l.ckOut + 4, l.ckOutRIFF + 4, l.mmioinfoOut, param_3);
            }
        }
    }
}
