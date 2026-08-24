// VA: 00523F10 TRIBE_Game::start_campaign_menu (274 bytes)
// PDB: tribegam.cpp:1560-1596
// Baseline reconstruction: normal TRIBE_Game menu startup, typed screen
// construction/deletion, panel-system transition, and music selection.
// Attempt log:
// - Baseline used the canonical named TRIBE_Game/TMusic_System fields and a
//   natural new/delete screen lifecycle. It matched size, calls, CFG, and
//   frame, with only the three shifted TRIBE_Game offsets remaining.
// - Layout probe corrected the local inherited/base gap, placing
//   music_system/video_setup/started_menu_music at +0x64/+0xC00/+0xC1C;
//   this produced an exact 274-byte match under the default flags.

#include "../../include/tribegam_context.h"

class TRIBE_Screen_Campaign_Selection {
public:
    virtual ~TRIBE_Screen_Campaign_Selection();
    char gap_04[0xD4];
    int error_code;
    char gap_DC[0x3F0];

    TRIBE_Screen_Campaign_Selection();
};

int TRIBE_Game::start_campaign_menu()
{
    TRIBE_Screen_Campaign_Selection* screen;
    TMusic_System* music;

    if (this->video_setup != 0)
        this->shutdown_video_system();

    screen = new TRIBE_Screen_Campaign_Selection;
    if (screen == 0)
        return 0;

    if (screen->error_code != 0) {
        delete screen;
        return 0;
    }

    panel_system.setCurrentPanel("Campaign Selection Screen", 0);
    this->set_prog_mode(2);

    music = this->music_system;
    if (music != 0 && this->started_menu_music == 0) {
        if (music->music_type == 1) {
            music->play_track(2, 0, 0);
        } else if (music->music_type == 2) {
            music->play_file("open.mid", 0, 0);
        } else if (music->music_type == 3) {
            music->play_file("open.wav", 0, 0);
        }
        this->started_menu_music = 1;
    }

    return 1;
}
