// VA: 0043B400 TribeAboutDialog::action
// dlg_abt.cpp lines 174-200

// attempt 1: natural C++ — vf14 at wrong vtable slot, missing push 0
// attempt 2: removed vf14 decl, direct slot 5 call with push 0 -> slot fixed
// attempt 3: EH handler addr reloc prevents size match (320 vs 325)
// Remaining: instruction scheduling differs (param load before/after push esi),
// register allocation cascade (200+ diff bytes after crude reloc masking).
// EH prologue present — needs /GX. Deep codegen basin. Left in scratch.

class TPanelSystem;
class TRIBE_Credits_Screen;

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
    virtual long vf04();
    virtual long vf08();
    virtual long vf0C();
    virtual long vf10();
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x39C];
    virtual ~TEasy_Panel();
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

extern TPanelSystem* panel_system;  // 62E870h

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

long TribeAboutDialog::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    if (param_2 != 1)
        return TEasy_Panel::action(param_1, param_2, param_3, param_4);

    if (param_1 == this->close_button) {
        TPanel* game_screen = panel_system->panel("Game Screen");
        if (game_screen) {
            if (rge_base_game->singlePlayerGame() == 1) {
                if (!rge_base_game->field_A00) {
                    rge_base_game->set_paused(0, 0);
                }
            }
            panel_system->setCurrentPanel("Game Screen", 0);
            ((void (__stdcall *)(int))(*(void***)this)[5])(0);
        }
        panel_system->destroyPanel("About Dialog");
        return 1;
    }

    if (param_1 == this->credits_button) {
        TRIBE_Credits_Screen* credits = new TRIBE_Credits_Screen();
        panel_system->setCurrentPanel("Credits Screen", 0);
        panel_system->destroyPanel("About Dialog");
        return 1;
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
