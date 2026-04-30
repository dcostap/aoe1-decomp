// TDigital::play

struct IDirectSoundBuffer_vtbl {
    char gap_00[0x24];
    int (__stdcall *GetStatus)(void* thisptr, unsigned long* status);
    char gap_28[8];
    int (__stdcall *Play)(void* thisptr, unsigned long a, unsigned long b, int flags);
    int (__stdcall *SetCurrentPosition)(void* thisptr, unsigned long pos);
    char gap_38[4];
    int (__stdcall *SetVolume)(void* thisptr, long volume);
    int (__stdcall *SetPan)(void* thisptr, long pan);
    int (__stdcall *SetFrequency)(void* thisptr, unsigned long freq);
};

struct IDirectSoundBuffer {
    IDirectSoundBuffer_vtbl* vtbl;
};

class TDigital {
public:
    int sound_system;
    TDigital* owner;
    unsigned char loaded;
    unsigned char failed;
    char sound_file[13];
    unsigned char pad_17;
    long resource_id;
    long volume;
    unsigned long pitch;
    long pan;
    int loop;
    unsigned char* wave_data;
    void* wave_info;
    IDirectSoundBuffer* sound_buffer;

    int load(char* name, long param);
    int play();
};

int TDigital::play() {
    unsigned long status;
    int loop_flag;
    int hr;
    TDigital* target = this->owner;
    unsigned char* drv;
    TDigital* original = this;

    if (target == 0) {
        target = this;
    }

    drv = (unsigned char*)target->sound_system;

    if (drv == 0) goto done;
    if (drv[0] == 0) goto done;
    if (drv[1] != 0) goto done;

    if (target->loaded == 0) {
        int result = target->load(original->sound_file, -1);
        if (result == 0) return 0;
    }

    if (target->sound_buffer == 0) {
        target->failed = 1;
        return 0;
    }

    target->sound_buffer->vtbl->GetStatus(target->sound_buffer, &status);

    loop_flag = (target->loop != 0);
    target->sound_buffer->vtbl->SetVolume(target->sound_buffer, original->volume);
    target->sound_buffer->vtbl->SetFrequency(target->sound_buffer, original->pitch);
    target->sound_buffer->vtbl->SetPan(target->sound_buffer, original->pan);
    target->sound_buffer->vtbl->SetCurrentPosition(target->sound_buffer, 0);

    hr = target->sound_buffer->vtbl->Play(target->sound_buffer, 0, 0, loop_flag);

    if (hr == 0x88780096) {
        int result = target->load(0, -1);
        if (result == 0) return 0;

        target->sound_buffer->vtbl->SetVolume(target->sound_buffer, original->volume);
        target->sound_buffer->vtbl->SetFrequency(target->sound_buffer, original->pitch);
        target->sound_buffer->vtbl->SetPan(target->sound_buffer, original->pan);
        target->sound_buffer->vtbl->SetCurrentPosition(target->sound_buffer, 0);
        target->sound_buffer->vtbl->Play(target->sound_buffer, 0, 0, loop_flag);
    }

done:
    return 1;
}
