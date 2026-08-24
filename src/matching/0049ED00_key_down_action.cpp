// VA: 0049ED00 TRIBE_Screen_Main_Menu::key_down_action (250B)
// Scr_main.cpp lines 231-258
// EH-framed virtual function
// FLAGS: /GX (EH)
// Attempt log:
// - The initial goto-shaped dispatch kept the credits block in the wrong
//   position; nested/reversed if forms also merged the success cleanup tails.
// - Exact source shape: a positive param_4 guard around a switch, with
//   explicit per-case returns and the invalid return after the switch.

#include <windows.h>
#include "../../include/scr_main_context.h"

#if 0
class TPanel {
public:
    char __gap[0x1C];
    void* render_area;
    char __gap2[0x1C];
    void* parent_panel;
    char __gap3[0x28];
    int active;
    int visible;
    char __gap4[0x14];
    void* clip_rgn;
    RECT render_rect;
    char __gap5[0x44];
    int display_changed_count;
    char __gap6[0x10];

    virtual ~TPanel();
};

class TEasy_Panel : public TPanel {
public:
    char __gap7[0x384];
    virtual ~TEasy_Panel();
    void popupOKDialog(long string_id, char* text, int value1, int value2);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TRIBE_Credits_Screen : public TScreenPanel {
public:
    char data[0x8B8 - sizeof(TScreenPanel)];
    TRIBE_Credits_Screen();
    virtual ~TRIBE_Credits_Screen();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x1BC];
    int field_1C0;
    int gameDeveloperMode();
    int load_db_files();
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    TPanel* title1;
    TPanel* title2;
    TPanel* button[7];
    TPanel* ms_title_text;
    TPanel* ms_copy_text1;
    TPanel* ms_copy_text2;
    TPanel* warning_text;
    TPanel* circle_p_pic;

    virtual ~TRIBE_Screen_Main_Menu();
    virtual long handle_idle();
    virtual long key_down_action(long key, short param_2, int param_3, int param_4, int param_5);
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};
#endif

long TRIBE_Screen_Main_Menu::key_down_action(long key, short param_2, int param_3, int param_4, int param_5) {
    if (param_4 != 0) {
        switch (key) {
    case 0x4C:
        {
            if (rge_base_game->gameDeveloperMode() != 0) {
                if (rge_base_game->load_db_files() == 0) {
                    TEasy_Panel::popupOKDialog(0x7D7, 0, 0x1C2, 100);
                }
            }
            return 1;
        }

    case 0x43:
        new TRIBE_Credits_Screen();
        panel_system.setCurrentPanel("Credits Screen", 0);
        panel_system.destroyPanel("Main Menu");
        return 1;
        }
    }
    return 0;
}
