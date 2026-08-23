// 00461F60 TMusic_System::set_volume
// Source: music.cpp lines 393-448
// Size: 172 bytes
// Attempt log:
// Probe 1: natural C++ placeholder was 160B too small and had bad sound_system offset.
// Probe 2: fixed +0x108 sound_system and real stream-volume call, but explicit __int64
// division expansion saved `this` in ESI and emitted helper calls. MATCH came from spelling
// the mixer computation naturally as `(range * (vol + 10000)) / 10000`; VC5 lowers the
// unsigned divide to the original magic `mul 0xD1B71759; shr edx,0x0D` while keeping `this`
// in ECX and using ESI only for the mixer minimum.

#include "../../include/music_context.h"

extern "C" int (__stdcall *mixerSetControlDetails_ptr)(void*, void*, unsigned long);

void TMusic_System::set_volume(long vol, int save_flag)
{
    if (vol < -10000) {
        vol = -10000;
    } else if (vol > 0) {
        vol = 0;
    }

    if (save_flag) {
        this->volume = vol;
    }

    if (this->device_open == 0) {
        return;
    }

    switch (this->music_type) {
    case 1:
        if (this->mixer_open == 0) {
            return;
        }
        break;
    case 2:
        if (this->mixer_open == 0) {
            return;
        }
        break;
    case 3:
        if (this->sound_system == 0) {
            return;
        }
        this->sound_system->set_stream_volume(vol);
        return;
    default:
        return;
    }

    unsigned int delta = this->mixer_volume_control.Bounds.dwMaximum -
                         this->mixer_volume_control.Bounds.dwMinimum;
    vol += 10000;
    delta = (delta * vol) / 10000;
    this->mixer_volume_value.dwValue = delta;
    mixerSetControlDetails_ptr(this->mixer_handle,
                               &this->mixer_volume_details, 0);
}
