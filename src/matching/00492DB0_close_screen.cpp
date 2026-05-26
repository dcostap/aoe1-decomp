// TRIBE_Credits_Screen::close_screen
// VA: 00492DB0

class TPanelSystem {
public:
    void* panel(char* name);
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

class RGE_Base_Game {
public:
    char gap_0000[0xA00];
    int save_paused;
    int singlePlayerGame();
    void set_paused(int a, int b);
};

class TRIBE_Screen_Main_Menu {
public:
    char gap[0x4B0];
    TRIBE_Screen_Main_Menu();
};

class TRIBE_Credits_Screen {
public:
    void close_screen();
};

#define panel_system (*(TPanelSystem*)0x62E870)
#define rge_base_game (*(RGE_Base_Game**)0x62C574)

void TRIBE_Credits_Screen::close_screen()
{
    if (panel_system.panel((char*)0x5842CC)) {
        if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system.setCurrentPanel((char*)0x5842CC, 0);
    } else {
        new TRIBE_Screen_Main_Menu();
        panel_system.setCurrentPanel((char*)0x5842E8, 0);
    }
    panel_system.destroyPanel((char*)0x5842BC);
}
