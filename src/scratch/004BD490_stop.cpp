#ifndef SOUNDDRV_CANONICAL_TU
struct IDirectSoundBuffer_vtbl_st {
    char gap_00[0x48];
    int (__stdcall *Stop)(void* thisptr);
};

struct IDirectSoundBuffer_st {
    IDirectSoundBuffer_vtbl_st* vtbl;
};

class TDigital_stop {
public:
    void stop(void);
    int dsound_driver;
    TDigital_stop* parent;
    unsigned char loaded;
    char gap_09[0x23];
    int field_2C;
    int field_30;
    IDirectSoundBuffer_st* buffer;
};

void TDigital_stop::stop(void) {
    TDigital_stop* p = this;
    while (p->parent)
        p = p->parent;
    if (!p->dsound_driver) return;
    if (!*(unsigned char*)p->dsound_driver) return;
    if (!p->loaded) return;
    if (!p->buffer) return;
    p->buffer->vtbl->Stop(p->buffer);
}
#else
void TDigital::stop(void) {
    TDigital* p = this;
    while (p->owner != 0)
        p = p->owner;
    if (p->sound_system == 0) return;
    if (p->sound_system->ready == 0) return;
    if (p->loaded == 0) return;
    if (p->sound_buffer == 0) return;
    p->sound_buffer->Stop();
}
#endif
