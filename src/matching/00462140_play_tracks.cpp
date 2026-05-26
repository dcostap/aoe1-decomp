// VA: 00462140 play_tracks (183B)
// music.cpp
// Attempt log:
// try 1: natural sibling of play_track/play_file with correct return/signature and call surface; 4-byte cmp operand drift.
// try 2: spell upper-bound checks with parameter on the left to match original cmp register order.

class TMusic_System {
public:
    char _gap_00[0x128];
    unsigned char playing_track;        // +0x128
    char file_name[261];                // +0x129
    char _pad_22E[2];                   // +0x22E
    int start_track;                    // +0x230
    int end_track;                      // +0x234
    int make_cur_track;                 // +0x238
    unsigned long set_pos;              // +0x23C
    int loop;                           // +0x240
    int current_track;                  // +0x244
    int track_count;                    // +0x248
    int notify_waiting;                 // +0x24C
    long start_volume;                  // +0x250
    long volume;                        // +0x254
    int paused;                         // +0x258
    int auto_paused;                    // +0x25C
    int inactivated;                    // +0x260
    int fade_out;                       // +0x264
    unsigned long fade_time;            // +0x268

    int play_tracks(int from, int to, int loop_val, int make_cur, unsigned long pos);
    int play(int from, int to, const char* name, int make_cur, unsigned long pos);
    void start_fade();
};

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
