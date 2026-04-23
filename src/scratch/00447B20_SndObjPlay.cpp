// tried a direct wrapper-style spelling first; keeping the logic as a free function
// tried direct COM Play slot spelling; mismatch stayed at the entry prolog/register basin
// tried moving the flag read later and fixing the vtable slot; EBX still saved too early

struct IDirectSoundBufferVtbl;

struct IDirectSoundBuffer {
    IDirectSoundBufferVtbl* lpVtbl;
};

struct IDirectSoundBufferVtbl {
    void* reserved0;
    void* reserved1;
    void* reserved2;
    void* reserved3;
    void* reserved4;
    void* reserved5;
    void* reserved6;
    void* reserved7;
    void* reserved8;
    void* reserved9;
    void* reserved10;
    void* reserved11;
    int (__stdcall *Play)(IDirectSoundBuffer* this_, unsigned long, unsigned long, unsigned long);
};

struct SNDOBJ {
    unsigned char* pbWaveData;
    unsigned long cbWaveSize;
    int iAlloc;
    int iCurrent;
    IDirectSoundBuffer* Buffers[1];
};

extern IDirectSoundBuffer* SndObjGetFreeBuffer(SNDOBJ* sndobj);

unsigned int SndObjPlay(SNDOBJ* sndobj, unsigned long flags) {
    unsigned int result = 0;

    if (sndobj == 0) {
        return result;
    }

    if (((flags & 1) != 0) && (sndobj->iAlloc != 1)) {
        return result;
    }

    {
        IDirectSoundBuffer* buffer = SndObjGetFreeBuffer(sndobj);
        if (buffer != 0) {
            int ok = buffer->lpVtbl->Play(buffer, 0, 0, flags);
            result = (unsigned int)(ok >= 0);
        }
    }

    return result;
}
