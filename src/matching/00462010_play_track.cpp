// 00462010 TMusic_System::play_track
// Source: music.cpp lines 452-467
// Size: 113 bytes
//
// Attempt log:
// Probe 1: 113/113B, 8.85% diff — offset shift from struct alignment
// Probe 2: explicit raw-offset accesses

#include "..\..\include\game_globals.h"
#include "../../include/music_context.h"

int TMusic_System::play_track(int param_1, int param_2, unsigned long param_3)
{
    int was_playing = this->playing_track;
    this->file_name[0] = 0;
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
