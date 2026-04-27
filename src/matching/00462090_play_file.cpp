// 00462090 TMusic_System::play_file
// Source: music.cpp lines 471-489
// Size: 161 bytes
//
// Attempt log:
// Probe 1: natural C++

#include "..\..\include\game_globals.h"
#include <string.h>

class TMusic_System {
public:
    char _gap_00[0x104];
    unsigned char music_type;           // +0x104
    char _gap_105[0x23];                // +0x105 to +0x127
    unsigned char playing_track;        // +0x128
    char file_name[261];                // +0x129
    char _pad_22E[2];                   // +0x22E
    int start_track;                    // +0x230
    int end_track;                      // +0x234
    int make_cur_track;                 // +0x238
    unsigned long set_pos;              // +0x23C
    int loop;                           // +0x240
    char _gap_244[0x20];                // +0x244 to +0x263
    int fade_out;                       // +0x264
    unsigned long fade_time;            // +0x268

    int play_file(const char* name, int loop, unsigned long pos);
    int play(int a, int b, const char* c, int d, unsigned long e);
    void start_fade();
};

int TMusic_System::play_file(const char* name, int loop_val, unsigned long pos)
{
    if (this->music_type == 1)
        return 0;

    strcpy(this->file_name, name);

    this->start_track = 0;
    this->end_track = 0;
    this->make_cur_track = 0;
    this->set_pos = pos;
    this->loop = loop_val;

    if (this->playing_track && this->fade_out && this->fade_time > 0UL) {
        start_fade();
        return 1;
    }

    return play(0, 0, file_name, 0, pos);
}
