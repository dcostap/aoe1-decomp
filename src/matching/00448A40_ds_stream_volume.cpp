struct IDirectSoundBuffer;

struct IDirectSoundBufferVtbl {
    void* vf00;
    void* vf04;
    void* vf08;
    void* vf0C;
    void* vf10;
    void* vf14;
    void* vf18;
    void* vf1C;
    void* vf20;
    void* vf24;
    void* vf28;
    void* vf2C;
    void* vf30;
    void* vf34;
    void* vf38;
    int (__stdcall *SetVolume)(IDirectSoundBuffer* self, int volume);
};

struct IDirectSoundBuffer {
    IDirectSoundBufferVtbl* lpVtbl;
};

extern IDirectSoundBuffer* _lpDSBStreamBuffer;

int __cdecl ds_stream_volume(int volume) {
    IDirectSoundBuffer* stream;
    int result;

    stream = _lpDSBStreamBuffer;
    if (stream == 0) {
        return 0;
    }
    result = stream->lpVtbl->SetVolume(stream, volume);
    return result == 0;
}
