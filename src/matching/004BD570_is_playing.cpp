#ifndef SOUNDDRV_CANONICAL_TU
class IDirectSoundBuffer;
typedef long (__stdcall *IDirectSoundBuffer_GetStatusFn)(IDirectSoundBuffer* self, unsigned long* status);

class TSound_Driver;

class TDigital {
public:
    TSound_Driver* sound_system;
    TDigital* owner;
    unsigned char loaded;
    unsigned char failed;
    char sound_file[13];
    unsigned char _pad_0[0x1];
    long resource_id;
    long volume;
    unsigned long pitch;
    long pan;
    int loop;
    unsigned char* wave_data;
    void* wave_info;
    IDirectSoundBuffer* sound_buffer;

    int is_playing();
};
#endif

int TDigital::is_playing() {
    TDigital* target = this->owner;
    unsigned long status;

    if (target == 0) {
        target = this;
    }
    if (this->sound_system != 0 && target->loaded != 0 && target->sound_buffer != 0) {
#ifdef SOUNDDRV_CANONICAL_TU
        if (target->sound_buffer->GetStatus(&status) == 0) {
#else
        if (((IDirectSoundBuffer_GetStatusFn)((*(void***)target->sound_buffer)[9]))(target->sound_buffer, &status) == 0) {
#endif
            if (status == 1 || status == 4) {
                return 1;
            }
        }
    }
    return 0;
}
