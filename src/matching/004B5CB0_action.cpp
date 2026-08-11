// VA: 004B5CB0 TribeGameSettingsScreen::action
// PDB source: scr_set.cpp
// Attempt log:
// - Canonical ownership is the named panel fields at +0x494, +0x4A4, +0x4AC,
//   +0x4F0, +0x504, +0x544, +0x548, +0x54C, and +0x550; the ordered call set
//   is the scr_set.cpp action path shown by the original assembly.
// - Prior natural nested-guard candidate matched all 13 calls and 105
//   instructions but remained 2 bytes larger with a cmp/cmp dropdown dispatch
//   instead of the oracle's sub/dec dispatch.
// - A switch on the original get_id() value supplies the oracle's sub eax,7 /
//   dec eax sequence.  Placing its default and the scenario fill path on one
//   explicit late activation tail, with an explicit fall-through to `def` for
//   unmatched events, reproduces the original shared block topology.
// - A first late-label probe omitted the fall-through `goto def` and added an
//   extra activation/call; the retained typed switch plus guarded fall-through
//   is exact under the default VC5 flags.
// - Probe 020: MATCH, 329 bytes, 105 instructions, 13 calls, 0 differing bytes.

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
        switch (this->victoryTypeDrop->get_id()) {
        case 7:
            this->timeDrop->set_line(3);
            break;
        case 8:
            this->scoreDrop->set_line(7);
            break;
        default:
            goto activate_and_return;
        }
        this->activatePanels();
        return 1;
    }

    if (param_1 == this->scenarioList) {
        if (param_2 == 3)
            return 1;
        if (param_2 == 1) {
            this->fillMissionText();
            goto activate_and_return;
        }
    }

    goto def;

activate_and_return:
    this->activatePanels();
    return 1;

def:
    return this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
