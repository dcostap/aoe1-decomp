#include "../../include/music_context.h"

int TMusic_System::stop_track(void) {
    this->loop = 0;
    this->start_track = 0;
    this->end_track = 0;
    this->file_name[0] = 0;
    this->fading_track = 0;
    return this->stop_playing();
}
