// first pass: walk to the owner-chain tail, stop if not loaded, then release/free the tail resources
extern "C" void __cdecl free(void* block);

#ifndef SOUNDDRV_CANONICAL_TU
struct IDirectSoundBuffer_vtbl {
    char gap_00[8];
    int (__stdcall *Release)(void* thisptr);
};

struct IDirectSoundBuffer {
    IDirectSoundBuffer_vtbl* vtbl;
};

class TDigital {
public:
    int field_00;
    TDigital* owner;
    unsigned char loaded;
    unsigned char failed;
    char gap_0A[0x22];
    unsigned char* wave_data;
    void* wave_info;
    IDirectSoundBuffer* sound_buffer;

    void stop();
    void unload();
};
#endif

void TDigital::unload() {
    TDigital* p = this;

    while (p->owner != 0) {
        p = p->owner;
    }

    if (p->loaded == 0) {
        goto done;
    }

    p->stop();

    if (p->sound_buffer != 0) {
#ifdef SOUNDDRV_CANONICAL_TU
        p->sound_buffer->Release();
#else
        p->sound_buffer->vtbl->Release(p->sound_buffer);
#endif
        p->sound_buffer = 0;
    }

    if (p->wave_data != 0) {
        free(p->wave_data);
        p->wave_data = 0;
    }

    if (p->wave_info != 0) {
        free(p->wave_info);
        p->wave_info = 0;
    }

    p->loaded = 0;

done:
    p->failed = 0;
}
