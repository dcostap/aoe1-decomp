// VA: 00492970 ~TRIBE_Credits_Screen
// PDB donor: scr_cred.cpp lines 173-206
// Baseline: natural /GX virtual destructor with the binary-proven owned shape
// array, scroll-text panel, inherited reset field, and music cleanup.
// Flags: default /O2 /Oy removes the observed EH registration and is 45 bytes
// short; retain the target-specific /GX response file.

#include <new.h>
#include "../../include/scr_cred_context.h"

TRIBE_Credits_Screen::~TRIBE_Credits_Screen()
{
    for (int i = 0; i < 7; i++) {
        if (this->back_pics[i] != 0) {
            delete this->back_pics[i];
            this->back_pics[i] = 0;
        }
    }

    this->field_204 = 0;

    if (this->text_panel != 0) {
        delete this->text_panel;
        this->text_panel = 0;
    }

    TMusic_System* music = rge_base_game->music_system;
    if (music != 0 && music->music_type == 1 && music->track_count == 0xF) {
        music->play_tracks(5, 0xE, 1, 0, 0);
    }
}
