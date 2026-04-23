class TPanel {
public:
    char gap_00[0x4C8];
    TPanel* previousPanelValue;
};

class TPanelSystem {
public:
    TPanel* panel(char* panel_name);
};

extern TPanelSystem panel_system;

class TRIBE_Screen_Game;

class TRIBE_Game {
public:
    char gap_00[0x1B0];
    int modeValue;
    char gap_1B4[0xC24 - 0x1B4];
    TRIBE_Screen_Game* game_screen;

    TPanel* get_view_panel();
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x4B8];
    TPanel* main_view;
};

TPanel* TRIBE_Game::get_view_panel()
{
    if (this->modeValue == 4 || this->modeValue == 6 || this->modeValue == 5) {
        if (this->game_screen != 0)
            return this->game_screen->main_view;
    }

    if (this->modeValue == 7) {
        TPanel* panel = panel_system.panel("Scenario Editor Screen");
        if (panel != 0)
            return panel->previousPanelValue;
    }

    return 0;
}
