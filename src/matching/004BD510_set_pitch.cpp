#ifndef SOUNDDRV_CANONICAL_TU
class IDirectSoundBuffer {
public:
    int __stdcall SetFrequency(unsigned long value);
};

class TDigital {
public:
    TDigital* owner;
    unsigned char loaded;
    char gap_05[0x1B];
    unsigned long pitch;
    char gap_24[0x10];
    IDirectSoundBuffer* sound_buffer;
    void set_pitch(unsigned long value);
};
#endif

void TDigital::set_pitch(unsigned long freq) {
    TDigital* p = this->owner;
    this->pitch = freq;
    if (!p) p = this;
    if (!p->loaded) return;
    p->sound_buffer->SetFrequency(freq);
}
