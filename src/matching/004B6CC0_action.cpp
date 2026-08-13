// VA: 004B6CC0 action
// PDB source: Scr_sing.cpp
// Attempt log:
// baseline: typed button dispatch, game settings, panel transitions, and people-list ownership.
// removed fallback dialog panel transitions; the original returns after construction.
// modeled get_people_list as the donor-proven RGE_Game_Info member with a long reference output.
// separate cleanup and name-screen result checks retain the original redundant test and block shape.
// shardB4-B6CC0 exact: typed rge_base_game plus a cached player_game_info local mirrors
// the exact Scr_sing-family donor call setup and reaches the original 1138 bytes.

#include <stdlib.h>

class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    virtual void d00(); virtual void d04();
    virtual void d08(); virtual void d0C(); virtual void d10();
    virtual void addRef(int val);
    virtual void setMargins(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13);
    virtual void d1C(); virtual void d20(); virtual void d24();
    virtual void d28(); virtual void d2C(); virtual void d30();
    virtual void d34(); virtual void d38(); virtual void d3C();
    virtual void d40(); virtual void d44(); virtual void d48();
    virtual void d4C();
    char pad_TPanel[0x40];
};

class TEasy_Panel : public TPanel {
public:
    long action(TPanel* panel, long code, unsigned long a3, unsigned long a4);
    char pad_TEasy[0x434];
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class RGE_Game_Info;

class RGE_Base_Game {
public:
    char gap_00[0x04];
    RGE_Game_Info* player_game_info;
    char gap_08[0x44];
    void setCampaignGame(int val);
    void setSavedGame(int val);
    void setScenarioGame(int val);
    void setDeathMatch(unsigned char val);
    void setQuickStartGame(unsigned char val);
    void disable_input();
    void close();
};

class RGE_Game_Info {
public:
    long get_people_list(char*** list, long& count);
};

class TPanelSystem {
public:
    int setCurrentPanel(const char* name, int val);
    int destroyPanel(const char* name);
};

extern TPanelSystem panel_system;

class TribeSPMenuScreen;

class TribeMPSetupScreen : public TScreenPanel {
public:
    TribeMPSetupScreen();
    char gap[0x890 - 0x478];
};

class TribeSelectScenarioScreen : public TScreenPanel {
public:
    TribeSelectScenarioScreen();
    char gap[0x4D8 - 0x478];
};

class TribeLoadSavedGameScreen : public TScreenPanel {
public:
    TribeLoadSavedGameScreen();
    char gap[0x494 - 0x478];
};

class TRIBE_Screen_Name : public TScreenPanel {
public:
    TRIBE_Screen_Name();
    char gap[0x4A0 - 0x478];
};

class TRIBE_Dialog_Name : public TScreenPanel {
public:
    TRIBE_Dialog_Name(TribeSPMenuScreen* parent);
    char gap[0x4A4 - 0x478];
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    TRIBE_Screen_Main_Menu();
    char gap[0x4B0 - 0x478];
};

class TribeSPMenuScreen : public TScreenPanel {
public:
    TPanel* title;
    TPanel* button[7];
    TPanel* close_button;
    virtual long handle_idle();
    virtual long action(TPanel* panel, long code, unsigned long a3, unsigned long a4);
};

long TribeSPMenuScreen::action(TPanel* panel, long code, unsigned long a3, unsigned long a4) {
    if (panel && code == 1) {
        if (panel == button[0]) {
            ((RGE_Base_Game*)rge_base_game)->setCampaignGame(0);
            ((RGE_Base_Game*)rge_base_game)->setSavedGame(0);
            ((RGE_Base_Game*)rge_base_game)->setScenarioGame(0);
            ((RGE_Base_Game*)rge_base_game)->setDeathMatch(0);
            ((RGE_Base_Game*)rge_base_game)->setQuickStartGame(0);
            ((RGE_Base_Game*)rge_base_game)->disable_input();
            new TribeMPSetupScreen();
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            panel_system.destroyPanel("Single Player Menu");
            return 1;
        }
        if (panel == button[2]) {
            ((RGE_Base_Game*)rge_base_game)->setCampaignGame(0);
            ((RGE_Base_Game*)rge_base_game)->setSavedGame(0);
            ((RGE_Base_Game*)rge_base_game)->setScenarioGame(0);
            ((RGE_Base_Game*)rge_base_game)->setDeathMatch(1);
            ((RGE_Base_Game*)rge_base_game)->setQuickStartGame(0);
            ((RGE_Base_Game*)rge_base_game)->disable_input();
            new TribeMPSetupScreen();
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            panel_system.destroyPanel("Single Player Menu");
            return 1;
        }
        if (panel == button[3]) {
            ((RGE_Base_Game*)rge_base_game)->setCampaignGame(0);
            ((RGE_Base_Game*)rge_base_game)->setSavedGame(0);
            ((RGE_Base_Game*)rge_base_game)->setScenarioGame(1);
            ((RGE_Base_Game*)rge_base_game)->setDeathMatch(0);
            ((RGE_Base_Game*)rge_base_game)->setQuickStartGame(0);
            ((RGE_Base_Game*)rge_base_game)->disable_input();
            new TribeSelectScenarioScreen();
            panel_system.setCurrentPanel("Select Scenario Screen", 0);
            panel_system.destroyPanel("Single Player Menu");
            return 1;
        }
        if (panel == button[4]) {
            ((RGE_Base_Game*)rge_base_game)->disable_input();
            new TribeLoadSavedGameScreen();
            panel_system.setCurrentPanel("Load Saved Game Screen", 0);
            panel_system.destroyPanel("Single Player Menu");
            return 1;
        }
        if (panel == button[1]) {
            ((RGE_Base_Game*)rge_base_game)->disable_input();

            RGE_Game_Info* info = rge_base_game->player_game_info;
            char** list = 0;
            long count;
            long result = info->get_people_list(&list, count);

            if (result > 0) {
                for (int i = 0; i < result; i++) {
                    free(list[i]);
                }
                free(list);
            }

            if (result > 0) {
                new TRIBE_Screen_Name();
                panel_system.setCurrentPanel("Name Selection Screen", 0);
                panel_system.destroyPanel("Single Player Menu");
                return 1;
            }

            new TRIBE_Dialog_Name(this);
            return 1;
        }
        if (panel == button[5]) {
            ((RGE_Base_Game*)rge_base_game)->disable_input();
            new TRIBE_Screen_Main_Menu();
            panel_system.setCurrentPanel("Main Menu", 0);
            panel_system.destroyPanel("Single Player Menu");
            return 1;
        }
        if (panel == close_button) {
            ((RGE_Base_Game*)rge_base_game)->close();
            return 1;
        }
    }
    return TEasy_Panel::action(panel, code, a3, a4);
}
