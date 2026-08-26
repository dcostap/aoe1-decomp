// VA: 0043E5C0 TribeDiplomacyDialog::check_wood
// PDB: dlg_dip.cpp lines 777-805 (136 bytes, 51 asm lines)
// Default flags. No inline asm/hacks.
// BINARY NOTE: PDB names this protected __thiscall method and bounds it to
// 0043E5C0-0043E647. Its symbol is ?check_wood@TribeDiplomacyDialog@@IAEHXZ.
// BINARY NOTE: Check prog_mode before get_player. Reload each button after
// set_disabled before the virtual call. Keep this fault order and receiver.
// BINARY NOTE: Keep result live through the button loop for final publication.

#ifndef DLG_DIP_SHARED_CONTEXT
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef int PositionMode;
typedef int RedrawMode;

class TDrawArea;
class TPanel;

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;

    class RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    char gap_00[0x50];
    float* attributes;
};

// Narrow standalone surface models the inherited TPanel slot at +0x14 as
// set_active. The other declarations preserve the observed slot order.
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long,
                                  long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);

    char gap_04[0x7C];
    int active;
    char gap_84[0x22C];
    int disabled;

    void set_disabled(int is_disabled);
};

class TribeDiplomacyDialog {
protected:
    char gap_00[0x534];
    TButtonPanel* woodTributeButtons[8];
    char gap_554[0x614 - 0x554];
    float woodTotal;
    char gap_618[0x6B0 - 0x618];
    int curPlayerRow;
    int tributeFlag;

    int check_wood();
};
#endif

int TribeDiplomacyDialog::check_wood()
{
    register int result;
    RGE_Base_Game* game = (RGE_Base_Game*)rge_base_game;

    if (game->prog_mode == 5) {
        result = 1;
    } else {
        RGE_Player* player = game->get_player();
        float diff = player->attributes[1] - this->woodTotal;
        if (diff > 0.0f) {
            result = 0;
        } else {
            result = 1;
        }
    }

    int i = 0;
#ifdef DLG_DIP_SHARED_CONTEXT
    TButtonPanel** pp = this->woodTributeButton;
#else
    TButtonPanel** pp = this->woodTributeButtons;
#endif
    do {
        TButtonPanel* btn = *pp;
        if (btn != 0) {
#ifdef DLG_DIP_SHARED_CONTEXT
            if (i == this->cur_player_row) {
#else
            if (i == this->curPlayerRow) {
#endif
                btn->set_disabled(1);
            } else {
                btn->set_disabled(result);
            }

            btn = *pp;
#ifdef DLG_DIP_SHARED_CONTEXT
            if (this->tribute_flag != 0) {
                btn->set_fn(1);
            } else {
                btn->set_fn(0);
            }
#else
            if (this->tributeFlag != 0) {
                btn->set_active(1);
            } else {
                btn->set_active(0);
            }
#endif
        }
        ++i;
        ++pp;
    } while (i < 8);

    return result;
}
