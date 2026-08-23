// VA: 00462A10 handle_messages (295B)
// music.cpp
// Baseline reconstruction: period-plausible message dispatch using the
// canonical TMusic_System fields recovered from exact music.cpp siblings.
// Attempt log:
// Probe 1: natural nested equality dispatch matched size/CFG but placed the
// timer handler inline (215 differing bytes).
// Probe 2: inverted the timer equality arm so the 0x1c path falls through
// and the timer handler is late (136 differing bytes).
// Probe 3: reversed the wParam branches so VC5 leaves the pause arm late
// after the resume checks (90 differing bytes).
// Probe 4: inverted the 0x3b9 equality arm so the 0x500 path is inline;
// exact match.
// Main-agent audit confirmed the non-polymorphic TMusic_System field surface
// against exact same-TU donors; emitted code remains exact.

#include "../../include/music_context.h"

unsigned int TMusic_System::handle_messages(void* param_1,
                                            unsigned int param_2,
                                            unsigned int param_3,
    long param_4)
{
    if (param_2 <= 0x113) {
        if (param_2 != 0x113) {
            if (param_2 == 0x1c) {
                if (param_3 != 0) {
                    if (this->inactivated != 0 && this->auto_paused != 0) {
                        this->resume_play();
                        this->auto_paused = 0;
                        this->inactivated = 0;
                    }
                } else if (this->inactivated == 0) {
                    this->pause_play();
                    this->auto_paused = 1;
                    this->inactivated = 1;
                }
            }
        } else if (this->fading_track != 0) {
            this->do_fade();
        }
    } else if (param_2 != 0x3b9) {
        if (param_2 == 0x500 && this->music_type == 3 && this->paused == 0) {
            this->playing_track = 0;
            this->after_end_track();
        }
    } else {
        unsigned char type = this->music_type;
        if (type == 1 || type == 2) {
            if (this->notify_waiting > 0) {
                --this->notify_waiting;
            }
            if (this->notify_waiting == 0 && this->paused == 0) {
                if (type == 1) {
                    this->playing_track = 0;
                }
                this->after_end_track();
            }
        }
    }

    return 0;
}
