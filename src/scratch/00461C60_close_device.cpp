// 00461C60 TMusic_System::close_device
// Source: music.cpp lines 306-350
// Size: 190 bytes

#include "..\..\include\game_globals.h"

class TMusic_System {
public:
    char _gap_00[0x108];
    void* sound_system;
    char _gap_10C[8];
    int device_open;
    unsigned int device_id;
    char _gap_11C[0x6C];
    unsigned char playing_track;
    char _gap_129[0x8F];
    int auto_paused;
    char _gap_25C[0x14];
    int mixer_open;
    void* mixer_handle;

    void close_device();
};

void TMusic_System::close_device()
{
    // Close MCI device, reset state
}
