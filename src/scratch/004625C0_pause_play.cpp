// 004625C0 TMusic_System::pause_play
// Source: music.cpp lines 732-775
// Size: 175 bytes
//
// Attempt log:
// Probe 1: natural C++

#include "..\..\include\game_globals.h"

class TMusic_System {
public:
    char _gap_00[0x104];
    unsigned char music_type;           // +0x104
    char _gap_105[0xF];
    void* sound_system;                 // +0x108
    void* instance;                     // +0x10C
    char _gap_110[4];
    int device_open;                    // +0x114
    unsigned int device_id;             // +0x118
    char _gap_11C[0x6C];                // +0x11C to +0x187
    unsigned char playing_track;        // +0x128
    char _gap_129[0x12F];               // +0x129 to +0x257
    int paused;                         // +0x258
    int auto_paused;                    // +0x25C

    int pause_play();
};

extern int (__stdcall *g_mciSendCommand)(unsigned int device_id, unsigned int msg, unsigned long flags, void* param);

int TMusic_System::pause_play()
{
    if (!this->device_open || !this->playing_track)
        return 0;

    if (this->paused) {
        this->auto_paused = 0;
        return 1;
    }

    if (this->auto_paused) {
        this->paused = 1;
        this->auto_paused = 0;
        return 1;
    }

    this->paused = 1;

    switch (this->music_type) {
    case 3:
        if (this->sound_system)
            break; // call sound_system->pause
    case 2:
    case 1:
        g_mciSendCommand(this->device_id, 0x809, 2, 0);
        break;
    }
    return 1;
}
