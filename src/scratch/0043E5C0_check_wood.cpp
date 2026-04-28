// TribeDiplomacyDialog::check_wood
// VA: 0043E5C0
// dlg_dip.cpp:777-805
// 136 bytes, not matched (parked)
// Same VC5 stack-slot-for-boolean issue as check_food (sibling function).
// Field layout same as check_food but with wood button at +0x534,
// woodTotal at +0x614, and attributes[1] instead of attributes[0].
// 2 source forms tried. 0 relocations.

#include "../../include/game_globals.h"

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
    class RGE_Player* get_player(void);
};

class RGE_Player {
public:
    char gap_00[0x50];
    float* attributes;
};

class TButtonPanel {
public:
    void set_disabled(int disabled);
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void show(int visible);
};

extern RGE_Base_Game* rge_base_game;

class TribeDiplomacyDialog {
public:
    char gap_00[0x534];
    TButtonPanel* woodTributeButton[8]; // +0x534
    char gap_554[0x610 - 0x554];
    float foodTotal;                    // +0x610
    float woodTotal;                    // +0x614
    char gap_618[0x6B0 - 0x618];
    int cur_player_row;                // +0x6B0
    int tribute_flag;                  // +0x6B4

    int check_wood(void);
};

int TribeDiplomacyDialog::check_wood(void) {
    int hasWood;

    if (rge_base_game->prog_mode == 5) {
        hasWood = 1;
    } else {
        RGE_Player* player = rge_base_game->get_player();
        if (player->attributes[1] - this->woodTotal <= 0.0f) {
            hasWood = 1;
        } else {
            hasWood = 0;
        }
    }

    for (int i = 0; i < 8; i++) {
        TButtonPanel* btn = this->woodTributeButton[i];
        if (btn != 0) {
            if (i == this->cur_player_row) {
                btn->set_disabled(1);
            } else {
                btn->set_disabled(hasWood);
            }

            if (this->tribute_flag != 0) {
                btn->show(1);
            } else {
                btn->show(0);
            }
        }
    }

    return hasWood;
}
