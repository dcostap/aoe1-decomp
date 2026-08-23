// tried the straightforward fade-start form; VC5 still wants the exact field order and imported-timer call basin
// remaining gap is field-name/order shaping around the timer stores
extern unsigned long debug_timeGetTime(char* file, int line);
#include "../../include/music_context.h"

void TMusic_System::start_fade(void) {
    if (this->fading_track == 0) {
        this->fade_volume = this->volume;
        this->last_fade_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 0x38C);
        this->fading_track = 1;
    }
}
