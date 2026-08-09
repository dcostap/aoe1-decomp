// VA: 004B5CB0 TribeGameSettingsScreen::action
// PDB source: scr_set.cpp
// Attempt log:
// - 8 attempts: goto def pattern fixed shared handler, switch matched sub/dec dispatch
// - Remaining diff: ~18% edit / 28% positional
// - Switch generates sub eax,7; je; dec eax; je (correct dispatch form)
// - But default handler placed BEFORE case8 handler (fall-through to default)
//   vs original: jne to default AFTER case handler block (2-byte offset cascade)
// - Also: first okButton check loads into ecx for register-to-register cmp
//   instead of original's direct memory cmp. CancelButton/help_button are correct (memory form).
// - Left in scratch: structural VC5 codegen barrier for default/case block placement
// - SA60574_action baseline: typed switch retained an extra activatePanels call
//   and the same default-before-case8 layout.
// - SA60574_action nested positive guards (id!=7, then id==8) restored the
//   original 13-call topology, 105 instructions, and 95.24% exact-block
//   coverage; final size is +2 bytes and 114 positional-diff bytes.
// - Final bounded evidence: the remaining hunk is the dropdown dispatch
//   spelling (oracle sub eax,7 / dec eax / jne default; rebuilt cmp eax,7 /
//   cmp eax,8) plus the resulting two-byte block span. Switch label/order,
//   goto-to-late-label, arithmetic-normalized dispatch, and alternate guard
//   orders either duplicated code or produced no improvement; restored the
//   natural nested-guard candidate.

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(void*);
    virtual void draw_offset(long, long, void*);
    virtual void draw_rect2(void*);
    virtual void draw_offset2(long, long, void*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    char gap_04[0xF0];
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    void setup_popup_help();
    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    void activatePanels();
};

class TDropDownPanel : public TPanel {
public:
    char gap_F4[0x398];
    long get_id();
    void set_line(long val);
};

class TribeMPSetupScreen : public TPanel {};

class TribeGameSettingsScreen : public TEasy_Panel {
public:
    char gap_478[0x1C];
    TDropDownPanel* victoryTypeDrop;   // +0x494
    char gap_498[0x0C];
    TDropDownPanel* scoreDrop;         // +0x4A4
    char gap_4A8[0x04];
    TDropDownPanel* timeDrop;          // +0x4AC
    char gap_4B0[0x40];
    TPanel* scenarioList;              // +0x4F0
    char gap_4F4[0x10];
    int scenariosLoaded;               // +0x504
    char gap_508[0x3C];
    TPanel* okButton;                  // +0x544
    TPanel* cancelButton;              // +0x548
    TPanel* help_button;               // +0x54C
    TribeMPSetupScreen* chat_scr;      // +0x550
    char gap_554[0x0C];

    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    void sendSettings();
    void getSettings();
    void fillMissionText();
};

long TribeGameSettingsScreen::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    if (param_1 == 0)
        goto def;

    if (this->scenariosLoaded == 0)
        goto def;

    if (param_1 == this->okButton && param_2 == 1) {
        ((TPanel*)this)->set_curr_child(this->scenarioList);
        this->sendSettings();
        this->chat_scr->action(this, 1, 0, 0);
        return 1;
    }

    if (param_1 == this->cancelButton && param_2 == 1) {
        ((TPanel*)this)->set_curr_child(this->scenarioList);
        this->getSettings();
        this->chat_scr->action(this, 0, 0, 0);
        return 1;
    }

    if (param_1 == this->help_button && param_2 == 1) {
        ((TEasy_Panel*)this)->setup_popup_help();
        return 1;
    }

    if (param_1 == (TPanel*)this->victoryTypeDrop && param_2 == 0) {
        long id = this->victoryTypeDrop->get_id();
        if (id != 7) {
            if (id == 8) {
                this->scoreDrop->set_line(7);
            } else {
                this->activatePanels();
                return 1;
            }
        } else {
            this->timeDrop->set_line(3);
        }
        this->activatePanels();
        return 1;
    }

    if (param_1 == this->scenarioList) {
        if (param_2 == 3)
            return 1;
        if (param_2 == 1) {
            this->fillMissionText();
            this->activatePanels();
            return 1;
        }
    }

def:
    return this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
