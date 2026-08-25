// VA: 0043B400 TribeAboutDialog::action
// dlg_abt.cpp lines 174-200

// Attempt log:
// - Baseline: named button ownership and typed virtual set_active(0); /GX is
//   required for the binary-observed new-expression EH frame.
// - Independent close/credits guards reproduce the natural behavior but VC5
//   tail-merges the two destroyPanel sites (309 rebuilt vs 325 original).
// - An outer guard with the shared cleanup shape improved the diagnostic to
//   289 bytes / 250 differing bytes, but PDB lines 186 and 194 prove two
//   source destroyPanel sites; that codegen winner was not retained as source.
// - Canonical TPanel/TEasy/TScreen hierarchy and polymorphic credits layout
//   were tested; it did not resolve the cleanup-site merge. /O1 was rejected.
// - The prior scratch state restored readable separate guards. Its remaining
//   gap was the VC5 source/control-flow basin around duplicated destroyPanel
//   and EH handler placement; no inline asm, manual vtable, or volatility.
// - Fresh ABI probe: panel_system is a proven global TPanelSystem object, not a
//   pointer. The original loads ECX with 62E870h directly and has 11 calls.
// - Fresh control-flow probe: wrap both button arms in a positive param2 == 1
//   guard. This restores the original fallthrough layout and matches 325 bytes.

#ifndef DLG_ABT_CANONICAL_TU
class TPanelSystem;
class TRIBE_Credits_Screen;
class TDrawArea;

class RGE_Base_Game {
public:
    int singlePlayerGame();
    void set_paused(int a, int b);
    char gap_000[0xA00];
    int field_A00;
};

extern RGE_Base_Game* rge_base_game;  // 62C574h

class TPanel {
public:
    char _gap_04[0x1C];
    void* render_area;
    char _gap_24[0x1C];
    void* parent_panel;
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x14];
    void* clip_rgn;
    char render_rect[16];
    char _gap_9C[0x44];
    int display_changed_count;
    char _gap_E4[0x10];

    virtual ~TPanel();
    void delete_panel(TPanel** panel_ptr);
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int active);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x39C];
    virtual ~TEasy_Panel();
    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
};

class TPanelSystem {
public:
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int flag);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;  // 62E870h

class TribeAboutDialog : public TDialogPanel {
public:
    TPanel* title_text;       // +0x490
    TPanel* version_text;     // +0x494
    TPanel* ms_copy_text1;    // +0x498
    TPanel* ms_copy_text2;    // +0x49C
    TPanel* ens_copy_text;    // +0x4A0
    TPanel* genie_copy_text;  // +0x4A4
    TPanel* pid_label_text;   // +0x4A8
    TPanel* pid_text;         // +0x4AC
    TPanel* warning_text;     // +0x4B0
    TPanel* bg_display;       // +0x4B4
    TPanel* credits_button;   // +0x4B8
    TPanel* close_button;     // +0x4BC
    TPanel* background;       // +0x4C0

    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

class TRIBE_Credits_Screen {
public:
    char gap_000[0x8B8];   // sizeof = 0x8B8 for operator_new
    TRIBE_Credits_Screen();
};
#else
class TPanelSystem {
public:
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int flag);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    int singlePlayerGame();
    void set_paused(int a, int b);
    char gap_000[0xA00];
    int field_A00;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Credits_Screen {
public:
    char gap_000[0x8B8];
    TRIBE_Credits_Screen();
};
#endif

long TribeAboutDialog::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    if (param_2 == 1) {
        if (param_1 == this->close_button) {
            TPanel* game_screen = panel_system.panel("Game Screen");
            if (game_screen) {
                if (rge_base_game->singlePlayerGame() == 1) {
                    if (!rge_base_game->field_A00) {
                        rge_base_game->set_paused(0, 0);
                    }
                }
                panel_system.setCurrentPanel("Game Screen", 0);
                this->set_active(0);
            }
            panel_system.destroyPanel("About Dialog");
            return 1;
        }

        if (param_1 == this->credits_button) {
            TRIBE_Credits_Screen* credits = new TRIBE_Credits_Screen();
            panel_system.setCurrentPanel("Credits Screen", 0);
            panel_system.destroyPanel("About Dialog");
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
