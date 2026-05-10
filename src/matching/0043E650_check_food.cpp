// TribeDiplomacyDialog::check_food
// VA: 0043E650
// dlg_dip.cpp:811-840
//
// Attempt log:
// - Prior parked source used an ordinary `int hasFood`; VC5 put it in a stack slot and used EBP for `this`, causing
//   broad frame/register drift.
// - SpruceGlow MATCH: declare `register int hasFood` and iterate with a `TButtonPanel**` pointer. Also declare
//   `set_disabled` as the non-virtual member before the virtual slots so the direct call keeps `ecx = *pp`, while
//   `show` remains virtual at vtable offset 0x14.
// Result: MATCH locally with `python tools/check_function.py --va 0043E650`.

class RGE_Player {
public:
    char gap_00[0x50];
    float* attributes;
};

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;

    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

class TButtonPanel {
public:
    void set_disabled(int disabled);
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void show(int visible);
};

class TribeDiplomacyDialog {
public:
    char gap_00[0x554];
    TButtonPanel* foodTributeButton[8];
    char gap_574[0x610 - 0x574];
    float foodTotal;
    char gap_614[0x6B0 - 0x614];
    int cur_player_row;
    int tribute_flag;

    int check_food();
};

int TribeDiplomacyDialog::check_food() {
    register int hasFood;

    if (rge_base_game->prog_mode == 5 || (*rge_base_game->get_player()->attributes - this->foodTotal <= 0.0f)) {
        hasFood = 1;
    }
    else {
        hasFood = 0;
    }

    int i = 0;
    TButtonPanel** pp = this->foodTributeButton;
    do {
        if (*pp) {
            if (i == this->cur_player_row) {
                (*pp)->set_disabled(1);
            }
            else {
                (*pp)->set_disabled(hasFood);
            }

            if (this->tribute_flag) {
                (*pp)->show(1);
            }
            else {
                (*pp)->show(0);
            }
        }
        ++i;
        ++pp;
    } while (i < 8);

    return hasFood;
}
