// VA: 0049D6E0 TRIBE_Screen_Info::close_screen
// scr_info.cpp lines 118-189

// Baseline reconstruction: model the source panel name and the nine ordered
// screen transitions.  Numeric addresses preserve the original data objects.

#include <string.h>

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x18];
    char* panel_name; // +0x1C
    char gap_20[0x458];
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

class RGE_Base_Game {
public:
    void disable_input();
    void close();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int start_menu();
};

class TribeSPMenuScreen {
public:
    char gap[0x49C];
    TribeSPMenuScreen();
};

class TRIBE_Screen_Info : public TPanel {
public:
    char gap_478[0x0C];
    TRIBE_Screen_Info(char* name, char* resource, long id, unsigned long timer);
    void close_screen();
};

class TRIBE_Screen_Main_Menu {
public:
    char gap[0x4B0];
    TRIBE_Screen_Main_Menu();
};

extern TPanelSystem panel_system;
extern TRIBE_Game* rge_base_game;

void TRIBE_Screen_Info::close_screen()
{
    if (strcmp(this->panel_name, (char*)0x58664C) == 0) {
        rge_base_game->disable_input();
        new TribeSPMenuScreen;
        panel_system.setCurrentPanel((char*)0x586638, 0);
        panel_system.destroyPanel((char*)0x58664C);
        return;
    }

    if (strcmp(this->panel_name, (char*)0x58662C) == 0) {
        rge_base_game->disable_input();
        new TribeSPMenuScreen;
        panel_system.setCurrentPanel((char*)0x586638, 0);
        panel_system.destroyPanel((char*)0x58662C);
        return;
    }

    if (strcmp(this->panel_name, (char*)0x586620) == 0) {
        new TRIBE_Screen_Info((char*)0x586608, (char*)0x586614, 0xC392, 2000);
        panel_system.setCurrentPanel((char*)0x586608, 0);
        return;
    }

    if (strcmp(this->panel_name, (char*)0x586608) == 0) {
        if (rge_base_game->start_menu() == 0) {
            rge_base_game->close();
        }
        return;
    }

    if (strcmp(this->panel_name, (char*)0x5865F4) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info((char*)0x5865DC, (char*)0x5865E8, 0xC394, 0);
        panel_system.setCurrentPanel((char*)0x5865DC, 0);
        panel_system.destroyPanel((char*)0x5865F4);
        return;
    }

    if (strcmp(this->panel_name, (char*)0x5865DC) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info((char*)0x5865C4, (char*)0x5865D0, 0xC395, 0);
        panel_system.setCurrentPanel((char*)0x5865C4, 0);
        panel_system.destroyPanel((char*)0x5865DC);
        return;
    }

    if (strcmp(this->panel_name, (char*)0x5865C4) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info((char*)0x5865AC, (char*)0x5865B8, 0xC396, 0);
        panel_system.setCurrentPanel((char*)0x5865AC, 0);
        panel_system.destroyPanel((char*)0x5865C4);
        return;
    }

    if (strcmp(this->panel_name, (char*)0x5865AC) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Main_Menu;
        panel_system.setCurrentPanel((char*)0x5842E8, 0);
        panel_system.destroyPanel((char*)0x5865AC);
        return;
    }

    if (strcmp(this->panel_name, (char*)0x58659C) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info((char*)0x586588, (char*)0x586594, 0xC393, 0);
        panel_system.setCurrentPanel((char*)0x586588, 0);
        panel_system.destroyPanel((char*)0x58659C);
        return;
    }

    if (strcmp(this->panel_name, (char*)0x586588) == 0) {
        rge_base_game->disable_input();
        new TRIBE_Screen_Info((char*)0x586570, (char*)0x58657C, 0xC38F, 0);
        panel_system.setCurrentPanel((char*)0x586570, 0);
        panel_system.destroyPanel((char*)0x586588);
        return;
    }

    rge_base_game->close();
}
