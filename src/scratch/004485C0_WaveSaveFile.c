/* VA: 004485C0 _WaveSaveFile */
/* Dsutil.c lines 1327-1360, 158 bytes */

extern int __cdecl _WaveWriteFile(void*, void*, void*, int);
extern int __cdecl _WaveInitFileHeader(void*, void*, void*);
extern int __cdecl _WaveWriteSamples(void*, void*, void*, void*, int);

int __cdecl _WaveSaveFile(void* hmmio, void* wave, void* fmt, void* data, int size) {
    if (_WaveWriteFile(hmmio, wave, fmt, size)) return 1;
    if (_WaveInitFileHeader(hmmio, wave, fmt)) return 1;
    if (_WaveWriteSamples(hmmio, wave, fmt, data, size)) return 1;
    return 0;
}
