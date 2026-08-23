// first pass: direct fade-stop call plus the packet's OR-guard around the play helper
// if this is sticky, the remaining work is likely just the exact field names / call shape for play
#include "../../include/music_context.h"

void TMusic_System::end_fade(void) {
    this->fading_track = 0;
    this->set_volume(this->volume, 0);
    if ((this->start_track > 0 && this->end_track > 0) || this->file_name[0] != 0) {
        this->play(this->start_track, this->end_track, this->file_name, this->make_cur_track, this->set_pos);
    }
}
