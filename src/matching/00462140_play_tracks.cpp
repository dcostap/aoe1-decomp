// VA: 00462140 play_tracks (183B)
// music.cpp
// Attempt log:
// try 1: natural sibling of play_track/play_file with correct return/signature and call surface; 4-byte cmp operand drift.
// try 2: spell upper-bound checks with parameter on the left to match original cmp register order.

#include "../../include/music_context.h"

int TMusic_System::play_tracks(int from, int to, int loop_val, int make_cur, unsigned long pos)
{
    int count;

    this->loop = loop_val;
    count = this->track_count;
    this->file_name[0] = 0;
    this->start_track = from;
    this->end_track = to;
    this->make_cur_track = make_cur;
    this->set_pos = pos;

    if (count == 0)
        return count;

    if (from > count)
        this->start_track = count;

    from = this->start_track;
    if (to < from) {
        this->end_track = from;
    } else if (to > count) {
        this->end_track = count;
    }

    if (this->playing_track && this->fade_out && this->fade_time > 0UL) {
        this->start_fade();
        return 1;
    }

    return this->play(from, this->end_track, 0, make_cur, pos);
}
