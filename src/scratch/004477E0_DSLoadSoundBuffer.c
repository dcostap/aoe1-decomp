/* VA: 004477E0 _DSLoadSoundBuffer */
/* Dsutil.c lines 72-97, 170 bytes */

int __cdecl _DSLoadSoundBufferFromMemory(void* ds, void** buf, void* data, int size, int flags);

int __cdecl _DSFillSoundBuffer(void* buf, void* data, int size);

int __cdecl _DSLoadSoundBuffer(void* ds, void** buf, void* data, int size) {
    void* wave = 0;
    void* extra = 0;
    int wsize = 0;
    int esize = 0;
    int rc = _DSLoadSoundBufferFromMemory(ds, buf, data, size, 0);
    if (rc) return 0;
    return _DSFillSoundBuffer(*buf, data, size);
}
