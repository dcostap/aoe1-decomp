#ifndef SOUNDDRV_CANONICAL_TU
struct IDirectSoundBuffer_vtbl_pan {
    char gap_00[0x40];
    int (__stdcall *SetPan)(void* thisptr, int pan);
};

struct IDirectSoundBuffer_pan {
    IDirectSoundBuffer_vtbl_pan* vtbl;
};

class TDigital_pan {
public:
    void set_pan(int pan);
    int dsound_driver;
    TDigital_pan* parent;
    unsigned char loaded;
    char gap_09[0x1B];
    int pan_field;
    char gap_28[0x0C];
    IDirectSoundBuffer_pan* buffer;
};

void TDigital_pan::set_pan(int pan) {
    TDigital_pan* p = this->parent;
    this->pan_field = pan;
    if (!p) p = this;
    if (!p->loaded) return;
    p->buffer->vtbl->SetPan(p->buffer, pan);
}
#else
void TDigital::set_pan(long pan) {
    TDigital* p = this->owner;
    this->pan = pan;
    if (!p) p = this;
    if (!p->loaded) return;
    p->sound_buffer->SetPan(pan);
}
#endif
