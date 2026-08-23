// 004625C0 TMusic_System::pause_play
// Source: music.cpp lines 732-775
// Size: 175 bytes
// Attempt log:
// Probe 1: natural C++ with bad local layout/order compiled too small.
// Probe 2: fixed binary offsets and source order (paused check, set paused before auto_paused).

#include "../../include/music_context.h"

int TMusic_System::pause_play()
{
    if (this->device_open == 0 || this->playing_track == 0) {
        return 0;
    }

    if (this->paused != 0) {
        this->auto_paused = 0;
        return 1;
    }

    int was_auto = this->auto_paused;
    this->paused = 1;
    if (was_auto != 0) {
        this->auto_paused = 0;
        return 1;
    }

    switch (this->music_type) {
    case 1:
        mciSendCommandA(this->device_id, 0x809, 2, 0);
        break;
    case 2:
        mciSendCommandA(this->device_id, 0x809, 2, 0);
        return 1;
    case 3:
        if (this->sound_system != 0) {
            this->sound_system->pause_stream();
            return 1;
        }
        break;
    }
    return 1;
}
