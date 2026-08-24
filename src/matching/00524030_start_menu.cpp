// VA: 00524030 TRIBE_Game::start_menu (274 bytes)
// PDB source: tribegam.cpp, lines 1601-1636
// Attempt log:
// - Baseline reconstruction: natural TRIBE_Screen_Main_Menu allocation/error
//   cleanup, TPanelSystem member call, TRIBE_Game virtual set_prog_mode, and
//   TMusic_System member calls with the proven field ownership/layout.

#include <new.h>

#include "../../include/tribegam_context.h"

class TTextPanel;
class TButtonPanel;
class TPicturePanel;

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    TTextPanel* title1; // +0x478
    TTextPanel* title2; // +0x47C
    TButtonPanel* button[7]; // +0x480
    TTextPanel* ms_title_text; // +0x49C
    TTextPanel* ms_copy_text1; // +0x4A0
    TTextPanel* ms_copy_text2; // +0x4A4
    TTextPanel* warning_text; // +0x4A8
    TPicturePanel* circle_p_pic; // +0x4AC

    TRIBE_Screen_Main_Menu();
};

extern TPanelSystem panel_system;

int TRIBE_Game::start_menu()
{
    TRIBE_Screen_Main_Menu* screen;

    if (this->video_setup)
        this->shutdown_video_system();

    screen = new TRIBE_Screen_Main_Menu;
    if (screen == 0)
        return 0;

    if (screen->error_code) {
        delete screen;
        return 0;
    }

    panel_system.setCurrentPanel("Main Menu", 0);
    this->set_prog_mode(2);

    TMusic_System* music = this->music_system;
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
