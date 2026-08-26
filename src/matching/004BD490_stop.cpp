#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char ready;
};

class IDirectSoundBuffer {
public:
    int __stdcall Stop(void);
};

class TDigital {
public:
    TSound_Driver* sound_system;
    TDigital* owner;
    unsigned char loaded;
    unsigned char failed;
    char sound_file[13];
    unsigned char gap_17;
    long resource_id;
    long volume;
    unsigned long pitch;
    long pan;
    int loop;
    unsigned char* wave_data;
    void* wave_info;
    IDirectSoundBuffer* sound_buffer;
    void stop(void);
};
#endif

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
