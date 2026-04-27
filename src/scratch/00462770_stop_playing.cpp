// 00462770 TMusic_System::stop_playing
// Source: music.cpp lines 791-835
// Size: 165 bytes
//
// Attempt log:
// Probe 1: natural C++

#include "..\..\include\game_globals.h"

class TMusic_System {
public:
    char _gap_00[0x104];
    unsigned char music_type;           // +0x104
    char _gap_105[0x13];
    void* sound_system;                 // +0x108 (TSound_Driver*)
    char _gap_10C[8];
    int device_open;                    // +0x114
    unsigned int device_id;             // +0x118
    char _gap_11C[0x10C];               // +0x11C to +0x227
    unsigned char playing_track;        // +0x128
    char _gap_129[0x137];               // +0x129 to +0x25F
    int auto_paused;                    // +0x25C
    char _gap_260[0x1];
    int fade_out;                       // +0x264
    char _gap_268[0x4];
    int fading_track;                   // +0x26C

    int stop_playing();
};

int TMusic_System::stop_playing()
{
    if (!this->device_open || !this->playing_track)
        return 1;

    this->fading_track = -1;

    // Set playing_track to 0
    // MCI stop depending on music type
    switch (this->music_type) {
    case 3:
        break; // CD stop
    case 2:
    case 1:
        break; // MCI stop
    }

    // Reset state
    this->auto_paused = 0;
    return 1;
}
