// protected: TribeDiplomacyDialog::check_food
// VA: 0043E650
// dlg_dip.cpp:811-840
//
// BINARY NOTE: PDB and Ghidra qualify this member as protected __thiscall.
// The owning body is 0043E650-0043E6D6 and the symbol is
// ?check_food@TribeDiplomacyDialog@@IAEHXZ. Do not use the byte-identical
// public QAEH symbol.
//
// Recovery notes:
// - The exact body needs `register int hasFood` and a `TButtonPanel**` loop.
// - `set_disabled` is non-virtual. It precedes five virtual slots, so `show`
//   remains at vtable offset 0x14. The loop reloads each receiver after the
//   direct call.
// - The protected access is required. A public walkback kept all 135 bytes,
//   but emitted QAEH instead of the PDB symbol IA EH.
// - The exact source preserves the prog-mode guard, player read, ordered calls,
//   virtual receiver reloads, loop cleanup, and final result publication.
// Result: MATCH with `python tools/check_function.py --va 0043E650`.

#ifndef DLG_DIP_SHARED_CONTEXT
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
protected:
    char gap_00[0x554];
    TButtonPanel* foodTributeButton[8];
    char gap_574[0x610 - 0x574];
    float foodTotal;
    char gap_614[0x6B0 - 0x614];
    int cur_player_row;
    int tribute_flag;

    int check_food();
};
#endif

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
