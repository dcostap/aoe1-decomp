#include <windows.h>

#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char ready;
    unsigned char mute;
    unsigned char pad_02[2];
    void* main_wnd;
    void* direct_sound;
    void* primary_buffer;
    long dsrval;
    long start_volume;
    long volume;
    char path[260];
    int mixer_open;
    void* mixer_handle;

    void set_volume(long param_1, int param_2);
    void close_mixer(void);
};
#endif

void TSound_Driver::close_mixer(void) {
    if (this->mixer_open != 0) {
        if (this->start_volume != 1) {
            this->set_volume(this->start_volume, 0);
            this->start_volume = 1;
        }
        if (this->mixer_handle != 0) {
            mixerClose(this->mixer_handle);
            this->mixer_handle = 0;
        }
        this->mixer_open = 0;
    }
}
