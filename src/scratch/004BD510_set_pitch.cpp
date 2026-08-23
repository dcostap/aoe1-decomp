struct IDirectSoundBuffer_vtbl_sp {
    char gap_00[0x44];
    int (__stdcall *SetFrequency)(void* thisptr, int freq);
};

struct IDirectSoundBuffer_sp {
    IDirectSoundBuffer_vtbl_sp* vtbl;
};

class TDigital_sp {
public:
    void set_pitch(int freq);
    int dsound_driver;
    TDigital_sp* parent;
    unsigned char loaded;
    char gap_09[0x17];
    int pitch_field;
    char gap_24[0x10];
    IDirectSoundBuffer_sp* buffer;
};

void TDigital_sp::set_pitch(int freq) {
    TDigital_sp* p = this->parent;
    this->pitch_field = freq;
    if (!p) p = this;
    if (!p->loaded) return;
    p->buffer->vtbl->SetFrequency(p->buffer, freq);
}
