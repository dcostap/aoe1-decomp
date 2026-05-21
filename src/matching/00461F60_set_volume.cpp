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

#include <windows.h>

class TSound_Driver {
public:
    int set_stream_volume(long volume);
};

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;           // +0x104
    char gap_105[3];
    TSound_Driver* sound_system;        // +0x108
    void* instance;                     // +0x10C
    char gap_110[4];
    int device_open;                    // +0x114
    char gap_118[0x13C];
    long volume;                        // +0x254
    char gap_258[0x20];
    int mixer_open;                     // +0x278
    void* mixer_handle;                 // +0x27C
    char gap_280[0x124];
    unsigned int mixer_min;             // +0x3A4
    unsigned int mixer_max;             // +0x3A8
    char gap_3AC[0x28];
    char mixer_details[0x18];           // +0x3D4
    unsigned int mixer_value;           // +0x3EC

    void set_volume(long vol, int save_flag);
};

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

    unsigned int delta = this->mixer_max - this->mixer_min;
    vol += 10000;
    delta = (delta * vol) / 10000;
    this->mixer_value = delta;
    mixerSetControlDetails_ptr(this->mixer_handle, &this->mixer_details, 0);
}
