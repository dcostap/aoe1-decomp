// TDigital::play

#ifndef SOUNDDRV_CANONICAL_TU
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
#endif

#ifdef SOUNDDRV_CANONICAL_TU
#define SOUNDDRV_GET_STATUS(buffer, status) ((buffer)->GetStatus(status))
#define SOUNDDRV_SET_VOLUME(buffer, value) ((buffer)->SetVolume(value))
#define SOUNDDRV_SET_FREQUENCY(buffer, value) ((buffer)->SetFrequency(value))
#define SOUNDDRV_SET_PAN(buffer, value) ((buffer)->SetPan(value))
#define SOUNDDRV_SET_POSITION(buffer, value) ((buffer)->SetCurrentPosition(value))
#define SOUNDDRV_PLAY(buffer, a, b, flags) ((buffer)->Play(a, b, flags))
#else
#define SOUNDDRV_GET_STATUS(buffer, status) ((buffer)->vtbl->GetStatus(buffer, status))
#define SOUNDDRV_SET_VOLUME(buffer, value) ((buffer)->vtbl->SetVolume(buffer, value))
#define SOUNDDRV_SET_FREQUENCY(buffer, value) ((buffer)->vtbl->SetFrequency(buffer, value))
#define SOUNDDRV_SET_PAN(buffer, value) ((buffer)->vtbl->SetPan(buffer, value))
#define SOUNDDRV_SET_POSITION(buffer, value) ((buffer)->vtbl->SetCurrentPosition(buffer, value))
#define SOUNDDRV_PLAY(buffer, a, b, flags) ((buffer)->vtbl->Play(buffer, a, b, flags))
#endif

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

    SOUNDDRV_GET_STATUS(target->sound_buffer, &status);

    loop_flag = (target->loop != 0);
    SOUNDDRV_SET_VOLUME(target->sound_buffer, original->volume);
    SOUNDDRV_SET_FREQUENCY(target->sound_buffer, original->pitch);
    SOUNDDRV_SET_PAN(target->sound_buffer, original->pan);
    SOUNDDRV_SET_POSITION(target->sound_buffer, 0);

    hr = SOUNDDRV_PLAY(target->sound_buffer, 0, 0, loop_flag);

    if (hr == 0x88780096) {
        int result = target->load(0, -1);
        if (result == 0) return 0;

        SOUNDDRV_SET_VOLUME(target->sound_buffer, original->volume);
        SOUNDDRV_SET_FREQUENCY(target->sound_buffer, original->pitch);
        SOUNDDRV_SET_PAN(target->sound_buffer, original->pan);
        SOUNDDRV_SET_POSITION(target->sound_buffer, 0);
        SOUNDDRV_PLAY(target->sound_buffer, 0, 0, loop_flag);
    }

done:
    return 1;
}
