// VA: 00462B40 after_end_track (228B)
// music.cpp
// Attempt log:
// probe 1: natural switch, stacked case 2/3 -> 3 play calls vs orig 4 (stacked cases share one body).
// probe 2: separate case 2 and case 3 blocks (original duplicates the body).

#include "..\..\include\game_globals.h"
#include "../../include/music_context.h"

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
