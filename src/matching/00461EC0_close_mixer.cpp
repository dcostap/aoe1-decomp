#include "../../include/music_context.h"

void TMusic_System::close_mixer(void) {
    if (this->mixer_open != 0) {
        if (this->mixer_handle != 0) {
            mixerClose(this->mixer_handle);
            this->mixer_handle = 0;
        }
        this->mixer_open = 0;
    }
}
