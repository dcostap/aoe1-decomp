// 00462010 TMusic_System::play_track
// Source: music.cpp lines 452-467
// Size: 113 bytes
//
// Attempt log:
// Probe 1: 113/113B, 8.85% diff — offset shift from struct alignment
// Probe 2: explicit raw-offset accesses

#include "..\..\include\game_globals.h"

class TMusic_System {
public:
    char _gap_00[0x128];
    unsigned char playing_track;    // +0x128
    char _gap_129[0x107];           // +0x129 to +0x22F (file_name[261] + pad[2])
    int start_track;                // +0x230
    int end_track;                  // +0x234
    int make_cur_track;             // +0x238
    unsigned long set_pos;          // +0x23C
    int loop;                       // +0x240
    char _gap_244[0x20];            // +0x244 to +0x263
    int fade_out;                   // +0x264
    unsigned long fade_time;        // +0x268

    int play_track(int a, int b, unsigned long c);
    int play(int a, int b, int c, int d, unsigned long e);
    void start_fade();
};

int TMusic_System::play_track(int param_1, int param_2, unsigned long param_3)
{
    int was_playing = this->playing_track;
    this->_gap_129[0] = 0;  // file_name[0] = 0
    this->start_track = param_1;
    this->end_track = param_1;
    this->make_cur_track = 0;
    this->set_pos = param_3;
    this->loop = param_2;

    if (was_playing && this->fade_out && this->fade_time > 0UL) {
        start_fade();
        return 1;
    }

    return play(param_1, param_1, 0, 0, param_3);
}
