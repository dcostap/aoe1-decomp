// TribeDiplomacyDialog::check_food
// VA: 0043E650
// dlg_dip.cpp:811-840
// 135 bytes, not matched (parked)
// VC5 allocates stack slot for the conditional hasFood variable
// (push ecx + mov [esp+N],val pattern) while the original uses
// ebp directly (xor ebp,ebp / mov ebp,1). The stack variable adds
// ~25 bytes of codegen vs the register-based pattern.
// 5 source forms tried. 4 relocations.
// Attempt log:
// v0: int hasFood with separate if/else → 144 bytes + push ecx
// v1: correct field offsets → same size
// v2: goto-based control flow, no else → 160 bytes 
// v3: goto + ternary in loop → 160 bytes

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
    char gap_00[0x554];
    TButtonPanel* foodTributeButton[8];
    char gap_574[0x610 - 0x574];
    float foodTotal;
    char gap_614[0x6B0 - 0x614];
    int cur_player_row;
    int tribute_flag;

    int check_food(void);
};

int TribeDiplomacyDialog::check_food(void) {
    int hasFood;

    if (rge_base_game->prog_mode == 5) {
        hasFood = 1;
    } else {
        RGE_Player* player = rge_base_game->get_player();
        if (*player->attributes - this->foodTotal <= 0.0f) {
            hasFood = 1;
        } else {
            hasFood = 0;
        }
    }

    for (int i = 0; i < 8; i++) {
        TButtonPanel* btn = this->foodTributeButton[i];
        if (btn != 0) {
            if (i == this->cur_player_row) {
                btn->set_disabled(1);
            } else {
                btn->set_disabled(hasFood);
            }

            if (this->tribute_flag != 0) {
                btn->show(1);
            } else {
                btn->show(0);
            }
        }
    }

    return hasFood;
}
