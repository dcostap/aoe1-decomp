/* VA: 004485C0 _WaveSaveFile */
/* Dsutil.c lines 1327-1360, 158 bytes */

extern int __cdecl _WaveCreateFile(void* param_1, void* cbActualWrite, void* param_4, void* ckOut, void* ckOutRIFF);
extern int __cdecl _WaveStartDataWrite(void* cbActualWrite, void* ckOut, void* mmioinfoOut);
extern int __cdecl _WaveWriteFile(void* cbActualWrite, void* param_2, void* param_5, void* ckOutCksize, void* ckOut, void* mmioinfoOut);
extern int __cdecl _WaveCloseWriteFile(void* cbActualWrite, void* ckOut, void* ckOutRIFF, void* mmioinfoOut, void* param_3);

struct WaveSaveLocals {
    void* cbActualWrite;
    char ckOut[0x14];
    char ckOutRIFF[0x14];
    char pad[4];
    char mmioinfoOut[0x48];
};

void __cdecl _WaveSaveFile(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5)
{
    struct WaveSaveLocals l;

    if (_WaveCreateFile(param_1, &l.cbActualWrite, param_4, l.ckOut + 4, l.ckOutRIFF + 4) == 0) {
        if (_WaveStartDataWrite(&l.cbActualWrite, l.ckOut + 4, l.mmioinfoOut) == 0) {
            if (_WaveWriteFile(l.cbActualWrite, param_2, param_5, l.ckOut + 4, l.ckOut, l.mmioinfoOut) == 0) {
                _WaveCloseWriteFile(&l.cbActualWrite, l.ckOut + 4, l.ckOutRIFF + 4, l.mmioinfoOut, param_3);
            }
        }
    }
}
