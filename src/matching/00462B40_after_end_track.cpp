// VA: 00462B40 after_end_track (228B)
// music.cpp
// Attempt log:
// probe 1: natural switch, stacked case 2/3 -> 3 play calls vs orig 4 (stacked cases share one body).
// probe 2: separate case 2 and case 3 blocks (original duplicates the body).

#include "..\..\include\game_globals.h"

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
    int fading_track;                   // +0x26C

    int play(int a, int b, const char* c, int d, unsigned long e);
    void after_end_track();
};

void TMusic_System::after_end_track() {
    switch (this->music_type) {
    case 1:
        if (this->fading_track == 0 && this->loop != 0) {
            this->play(this->start_track, this->end_track, 0, 0, 0);
        }
        break;
    case 2:
        if (this->fading_track != 0) {
            break;
        }
        if (this->file_name[0] == 0 && this->current_track < this->end_track) {
            this->play(this->current_track + 1, this->current_track + 1, 0, 0, 0);
            break;
        }
        if (this->loop != 0) {
            if (this->file_name[0] != 0) {
                this->play(0, 0, this->file_name, 0, 0);
            } else {
                this->play(this->start_track, this->end_track, 0, 0, 0);
            }
        }
        break;
    case 3:
        if (this->fading_track != 0) {
            break;
        }
        if (this->file_name[0] == 0 && this->current_track < this->end_track) {
            this->play(this->current_track + 1, this->current_track + 1, 0, 0, 0);
            break;
        }
        if (this->loop != 0) {
            if (this->file_name[0] != 0) {
                this->play(0, 0, this->file_name, 0, 0);
            } else {
                this->play(this->start_track, this->end_track, 0, 0, 0);
            }
        }
        break;
    }
}
