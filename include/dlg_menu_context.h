#ifndef AOE1_DLG_MENU_CONTEXT_H
#define AOE1_DLG_MENU_CONTEXT_H

// Authentic source module: C:\\msdev\\work\\age1_x1\\dlg_menu.cpp.
// This surface joins the three PDB owners in source-line order while keeping
// the proven panel, dialog, and menu object layouts.

#include "game_globals.h"

class TDrawArea;
class TButtonPanel;
class TPicture;
class RGE_World;
class RGE_Scenario;

class TPanel {
public:
    char _gap_04[0x1C];
    TDrawArea* render_area;
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
    TDrawArea* renderArea();
    char* get_string(int id);
    virtual long action(TPanel* panel, long id, unsigned long param3,
                        unsigned long param4);
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** buttons, int count);
    void delete_panel(TPanel** panel);
};

typedef char dlg_menu_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x39C];

    virtual ~TEasy_Panel();
    long get_popup_info_id();
    char* get_popup_info_file();
    int create_button(TPanel* parent, TButtonPanel** button_ptr, long lang_id,
                      long param5, long y_offset, long y_pos, long width,
                      long height, long param10, long param11, long type);
    void popupYesNoDialog(long lang_id, long title_id, long param3,
                          long param4);
    long action(TPanel* panel, long id, unsigned long param3,
                unsigned long param4);
};

typedef char dlg_menu_teasy_size_check[(sizeof(TEasy_Panel) == 0x490) ? 1 : -1];

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
    int setup(TDrawArea* area, TPanel* parent, long width, long height,
              char* str, long id, int param);
};

class TButtonPanel : public TPanel {
public:
    char _gap_F4[0x1A4];
    int hotkey;
    int hotkey_shift;
};

typedef char dlg_menu_tbutton_size_check[(sizeof(TButtonPanel) == 0x2A0) ? 1 : -1];

class TribeMenuDialog : public TDialogPanel {
public:
    TButtonPanel* button[11];

    TribeMenuDialog(TScreenPanel* parent);
    virtual ~TribeMenuDialog();
    virtual long action(TPanel* panel, long id, unsigned long param3,
                        unsigned long param4);
};

typedef char dlg_menu_dialog_size_check[(sizeof(TribeMenuDialog) == 0x4BC) ? 1 : -1];

class RGE_Player {
public:
    char _gap_00[0x80];
    unsigned char game_status;
};

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

class RGE_Base_Game {
public:
    char _gap_00[0x10];
    HWND prog_window;
    char _gap_14[0x3E0];
    RGE_World* world;
    char _gap_3F8[0x608];
    int save_paused;

    int multiplayerGame();
    RGE_Player* get_player();
    int singlePlayerGame();
    void set_paused(int param1, int param2);
};

extern RGE_Base_Game* rge_base_game;
extern int confirmed_close;

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

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

class TRIBE_Mission_Screen {
public:
    char _gap_00[0x49C];
    TRIBE_Mission_Screen(char* info_file, unsigned char game_flag,
                         TPicture* vc_back_bmp);
};

#endif
