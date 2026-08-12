// 0043F720 TribeMenuDialog::action
// Source: dlg_menu.cpp lines 159-326
//
// Attempt log:
// Probe 1: full decomp with EH prolog, /GX needed. 1349 bytes, 12-way switch.
// Probe 2: typed new expressions and the direct panel_system object restored
// the constructor call set and reduced the size gap to 25 bytes.
// Probe 3: passing get_string and the mission picture as constructor arguments
// preserved allocation-before-argument evaluation and improved block order.
// Probe 4: a direct TEasy_Panel fallback aligned the complete call set.
// Probe 5: nested panel and id guards were codegen-neutral.
// Probe 6: a natural final else fallback broke the exact body; rolled back.
// Probe 8: the final unknown-action goto restored the common return and exact
// size. This matches the observed final conditional branch and base fallback.
// Probe 9: modeled save_paused at RGE_Base_Game +0xA00.
// Probe 10: typed world/scenario ownership moved mission-picture lookup after
// allocation and produced an exact match.
// Final: exact 1349-byte match. FLAGS: config/flags/0043F720_action.rsp (/GX).

#include "..\..\include\game_globals.h"
class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};
extern TPanelSystem panel_system;

class TDrawArea;

class TPanel {
public:
    char _gap_04[0x1C];
    void* render_area;
    char _gap_24[0x1C];
    TPanel* parent_panel;
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char _gap_9C[0x44];
    int display_changed_count;
    char _gap_E4[0x10];

    virtual ~TPanel();
    char* get_string(int id);
    virtual long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x39C];
    virtual ~TEasy_Panel();
    long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
    void popupYesNoDialog(long lang_id, long title_id, long param3, long param4);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
};

class TribeSaveGameScreen {
public:
    char _gap_00[0x6A4];
    TribeSaveGameScreen(int mode, char* name, int quit_after_save);
};

class TribeConfigDialog {
public:
    char _gap_00[0x564];
    TribeConfigDialog(int mode, TScreenPanel* parent);
};

class TribeAchievementsScreen {
public:
    char _gap_00[0x5F8];
    TribeAchievementsScreen(char* title, int end_game_flag);
};

class TribeAboutDialog {
public:
    char _gap_00[0x4C4];
    TribeAboutDialog(TScreenPanel* parent);
};

class TPicture;

class TRIBE_Mission_Screen {
public:
    char _gap_00[0x49C];
    TRIBE_Mission_Screen(char* info_file, unsigned char game_flag, TPicture* vc_back_bmp);
};

class TribeMenuDialog : public TDialogPanel {
public:
    char* button[11];

    TribeMenuDialog(TScreenPanel* parent);
    virtual ~TribeMenuDialog();
    virtual long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
};

class RGE_Scenario;

class TPicture;

class RGE_Scenario {
public:
    char _gap_00[0x198C];
    TPicture* mission_picture;
};

class RGE_World {
public:
    char _gap_00[0x5C];
    RGE_Scenario* scenario;
};

class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;

extern int confirmed_close;

class RGE_Base_Game {
public:
    char _gap_00[0x10];
    HWND prog_window;
    char _gap_14[0x3E0];
    RGE_World* world;
    char _gap_3F8[0x608];
    int save_paused;

    int multiplayerGame();
    int singlePlayerGame();
    void set_paused(int param1, int param2);
};

long TribeMenuDialog::action(TPanel* panel, long id, unsigned long param3, unsigned long param4)
{
    if (panel != 0) {
      if (id == 1) {
      if (param3 == 1) {
        TribeSaveGameScreen* obj = new TribeSaveGameScreen(0, 0, 0);
        panel_system.setCurrentPanel("Save Game Screen", 0);
        panel_system.destroyPanel("Menu Dialog");
        return 1;
      }

      if (param3 == 2) {
        TribeSaveGameScreen* obj = new TribeSaveGameScreen(1, 0, 0);
        panel_system.setCurrentPanel("Save Game Screen", 0);
        return 1;
      }

      if (param3 == 3) {
        TScreenPanel* ep = (TScreenPanel*)this->parent_panel;
        panel_system.destroyPanel("Menu Dialog");
        panel_system.setCurrentPanel("Game Screen", 0);
        ep->popupYesNoDialog(0xC1C, 0x5843A4, 0x1C2, 100);
        return 1;
      }

      if (param3 == 8) {
        if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system.destroyPanel("Menu Dialog");
        panel_system.setCurrentPanel("Game Screen", 0);
        WinHelpA(rge_base_game->prog_window, "empires.hlp", 3, 0);
        return 1;
      }

      if (param3 == 4) {
        confirmed_close = 1;
        TScreenPanel* ep = (TScreenPanel*)this->parent_panel;
        panel_system.destroyPanel("Menu Dialog");
        panel_system.setCurrentPanel("Game Screen", 0);
        ep->popupYesNoDialog(0xC1D, 0x584394, 0x1C2, 100);
        return 1;
      }

      if (param3 == 5) {
        TScreenPanel* ep = (TScreenPanel*)this->parent_panel;
        panel_system.destroyPanel("Menu Dialog");
        panel_system.setCurrentPanel("Game Screen", 0);
        TribeConfigDialog* obj = new TribeConfigDialog(0, ep);
        return 1;
      }

      if (param3 == 7) {
        TribeAchievementsScreen* obj = new TribeAchievementsScreen(this->get_string(0x269E), 0);
        panel_system.setCurrentPanel("Achievements Screen", 0);
        panel_system.destroyPanel("Menu Dialog");
        return 1;
      }

      if (param3 == 10) {
        TScreenPanel* ep = (TScreenPanel*)this->parent_panel;
        panel_system.destroyPanel("Menu Dialog");
        panel_system.setCurrentPanel("Game Screen", 0);
        TribeAboutDialog* obj = new TribeAboutDialog(ep);
        return 1;
      }

      if (param3 == 11) {
        TScreenPanel* ep = (TScreenPanel*)this->parent_panel;
        panel_system.destroyPanel("Menu Dialog");
        panel_system.setCurrentPanel("Game Screen", 0);
        ep->popupYesNoDialog(0xC1E, 0x584370, 0x1C2, 100);
        return 1;
      }

      if (param3 == 9) {
        TRIBE_Mission_Screen* obj = new TRIBE_Mission_Screen(
            0, 1, rge_base_game->world->scenario->mission_picture);
        panel_system.setCurrentPanel("Mission Dialog", 0);
        panel_system.destroyPanel("Menu Dialog");
        return 1;
      }

      if (param3 == 6) {
        if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("Menu Dialog");
        return 1;
      }

      if (param3 == 12) {
        TScreenPanel* ep = (TScreenPanel*)this->parent_panel;
        panel_system.destroyPanel("Menu Dialog");
        panel_system.setCurrentPanel("Game Screen", 0);
        ep->popupYesNoDialog(0xC1F, 0x584350, 0x1C2, 100);
      } else {
        goto default_handler;
      }

        return 1;
      }
    }

default_handler:
    return TEasy_Panel::action(panel, id, param3, param4);
}
