#ifndef SOUNDDRV_CANONICAL_TU
class IDirectSoundBuffer {
public:
    int __stdcall SetVolume(long value);
};

class TDigital {
public:
    TDigital* owner;
    unsigned char loaded;
    char gap_05[0x1B];
    long volume;
    char gap_24[0x10];
    IDirectSoundBuffer* sound_buffer;
    void set_volume(long value);
};
#endif

void TDigital::set_volume(long volume) {
    TDigital* p = this->owner;
    this->volume = volume;
    if (!p) p = this;
    if (!p->loaded) return;
    p->sound_buffer->SetVolume(volume);
}
