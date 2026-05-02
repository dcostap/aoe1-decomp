extern "C" int __cdecl _SndObjGetFreeBuffer(void* sndobj);

struct IDirectSoundBufferVtbl {
    void* fn00;
    void* fn04;
    void* fn08;
    void* fn0C;
    void* fn10;
    void* fn14;
    void* fn18;
    void* fn1C;
    void* fn20;
    void* fn24;
    void* fn28;
    void* fn2C;
    int (__stdcall *Play)(void* self, unsigned long, unsigned long, unsigned long);
};

struct IDirectSoundBuffer {
    IDirectSoundBufferVtbl* lpVtbl;
};

struct SNDOBJ {
    unsigned char* pbWaveData;
    unsigned long cbWaveSize;
    int iAlloc;
    int iCurrent;
    IDirectSoundBuffer* Buffers[1];
};

extern "C" unsigned int __cdecl _SndObjPlay(SNDOBJ* sndobj, unsigned long flags) {
    unsigned int result;
    IDirectSoundBuffer* buffer;
    int hr;

    result = 0;
    if (sndobj == 0) {
        return result;
    }
    if (((flags & 1) == 0) || (sndobj->iAlloc == 1)) {
        buffer = (IDirectSoundBuffer*)_SndObjGetFreeBuffer(sndobj);
        if (buffer != 0) {
            hr = buffer->lpVtbl->Play(buffer, 0, 0, flags);
            result = (unsigned int)(hr >= 0);
        }
    }
    return result;
}
