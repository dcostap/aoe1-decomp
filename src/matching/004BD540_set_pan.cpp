#ifndef SOUNDDRV_CANONICAL_TU
class IDirectSoundBuffer {
public:
    int __stdcall SetPan(long value);
};

class TDigital {
public:
    TDigital* owner;
    unsigned char loaded;
    char gap_05[0x1B];
    long pan;
    char gap_24[0x10];
    IDirectSoundBuffer* sound_buffer;
    void set_pan(long value);
};
#endif

void TDigital::set_pan(long pan) {
    TDigital* p = this->owner;
    this->pan = pan;
    if (!p) p = this;
    if (!p->loaded) return;
    p->sound_buffer->SetPan(pan);
}
