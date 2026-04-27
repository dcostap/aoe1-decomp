// 00461F60 TMusic_System::set_volume
// Source: music.cpp lines 393-448
// Size: 172 bytes
//
// Attempt log:
// Probe 1: natural C++

#include "..\..\include\game_globals.h"

class TMusic_System {
public:
    char _gap_00[0x104];
    unsigned char music_type;           // +0x104
    char _gap_105[0xF];
    void* sound_system;                 // +0x108 (TSound_Driver*)
    void* instance;                     // +0x10C
    char _gap_110[4];
    int device_open;                    // +0x114
    char _gap_118[0x10C];               // +0x118 to +0x223
    char _gap_224[0x2C];                // +0x224 to +0x24F
    long start_volume;                  // +0x250
    long volume;                        // +0x254
    char _gap_258[0x1C];                // +0x258 to +0x273
    char _gap_274[4];                   // +0x274 to +0x277
    int mixer_open;                     // +0x278
    void* mixer_handle;                 // +0x27C
    char _gap_280[0x124];               // +0x280 to +0x3A3
    int mixer_val_3A4;                  // +0x3A4
    int mixer_val_3A8;                  // +0x3A8
    char _gap_3AC[0x28];                // +0x3AC to +0x3D3
    char mixer_details[0x18];           // +0x3D4
    unsigned int mixer_volume_value;    // +0x3EC

    void set_volume(long vol, int save_flag);
};

// extern function pointer for mixer API
extern int (__stdcall *g_mixerSetControlDetails)(void* hmxobj, void* pmxcd, unsigned long fdwDetails);

void TMusic_System::set_volume(long vol, int save_flag)
{
    // Clamp volume to [-10000, 0]
    if (vol < -10000)
        vol = -10000;
    else if (vol > 0)
        vol = 0;

    if (save_flag)
        this->volume = vol;

    if (!this->device_open)
        return;

    switch (this->music_type) {
    case 1: // WAV
        if (this->mixer_open) {
            // Mixer volume control
            unsigned int range = this->mixer_val_3A8 - this->mixer_val_3A4;
            vol += 0x2710; // Add 10000 to make positive
            range = (range * (unsigned int)vol) * 0xD1B71759 >> 0x2D;
            this->mixer_volume_value = range;
            g_mixerSetControlDetails(this->mixer_handle, &this->mixer_details, 0);
        }
        break;
    case 2:
        if (this->mixer_open) {
            // similar mixer code
            unsigned int range = this->mixer_val_3A8 - this->mixer_val_3A4;
            vol += 0x2710;
            range = (range * (unsigned int)vol) * 0xD1B71759 >> 0x2D;
            this->mixer_volume_value = range;
            g_mixerSetControlDetails(this->mixer_handle, &this->mixer_details, 0);
        }
        break;
    case 3: // CD
        if (this->sound_system)
            // Call CD volume set function
            break;
    }
}
