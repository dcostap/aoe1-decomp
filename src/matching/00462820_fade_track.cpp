#include "../../include/music_context.h"

int TMusic_System::fade_track(void) {
    unsigned char playing_track = this->playing_track;

    this->loop = 0;
    this->start_track = 0;
    this->end_track = 0;
    this->file_name[0] = 0;
    this->fading_track = 0;
    if (playing_track != 0) {
        this->start_fade();
    }
    return 1;
}
