struct IDirectSoundBuffer_vtbl_sv {
    char gap_00[0x3C];
    int (__stdcall *SetVolume)(void* thisptr, int volume);
};

struct IDirectSoundBuffer_sv {
    IDirectSoundBuffer_vtbl_sv* vtbl;
};

class TDigital_sv {
public:
    void set_volume(int volume);
    int dsound_driver;
    TDigital_sv* parent;
    unsigned char loaded;
    char gap_09[0x13];
    int volume_field;
    char gap_20[0x14];
    IDirectSoundBuffer_sv* buffer;
};

void TDigital_sv::set_volume(int volume) {
    TDigital_sv* p = this->parent;
    this->volume_field = volume;
    if (!p) p = this;
    if (!p->loaded) return;
    p->buffer->vtbl->SetVolume(p->buffer, volume);
}
