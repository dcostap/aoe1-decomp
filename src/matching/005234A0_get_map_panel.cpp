#include "../../include/tribegam_context.h"

#if 0
class TPanel;
class TRIBE_Screen_Game;
class TPanelSystem;

extern TPanelSystem panel_system;

class TRIBE_Game {
public:
    char gap_0000[0x1B0];
    int game_mode;
    char gap_01B4[0xC24 - 0x1B4];
    TRIBE_Screen_Game* game_screen;

    TPanel* get_map_panel(void);
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x4BC];
    TPanel* map_view;
};

class TPanelSystem {
public:
    TPanel* panel(char* name);
};
#endif

TPanel* TRIBE_Game::get_map_panel(void) {
    if (this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 5) {
        if (this->game_screen != 0) {
            return this->game_screen->map_view;
        }
    }

    if (this->prog_mode == 7) {
        TPanel* p = panel_system.panel((char*)"Scenario Editor Screen");
        if (p != 0) {
            return *(TPanel**)((char*)p + 0x4CC);
        }
    }

    return 0;
}
