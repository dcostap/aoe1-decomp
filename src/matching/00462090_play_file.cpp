// 00462090 TMusic_System::play_file
// Source: music.cpp lines 471-489
// Size: 161 bytes
//
// Attempt log:
// Probe 1: natural C++

#include "..\..\include\game_globals.h"
#include <string.h>
#include "../../include/music_context.h"

int TMusic_System::play_file(char* name, int loop_val, unsigned long pos)
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
