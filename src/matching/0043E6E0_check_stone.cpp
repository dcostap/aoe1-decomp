// protected: TribeDiplomacyDialog::check_stone
// VA: 0043E6E0; dlg_dip.cpp:846-874; body: 0043E6E0-0043E767
// PDB/Ghidra symbol: ?check_stone@TribeDiplomacyDialog@@IAEHXZ
// BINARY NOTE: Do not replace protected access with public access. The public
// QAEH symbol is byte-identical but is not the PDB-qualified owner.
// BINARY NOTE: Keep the prog-mode guard, resource check, ordered calls,
// receiver reloads, loop cleanup, and final result publication.
// EXACT FINISH: A public reversion kept the bytes but emitted QAEH. The
// protected source emits IAEHXZ and remains an exact match.

#ifndef DLG_DIP_SHARED_CONTEXT
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TPanel;

class RGE_Player;

class RGE_Base_Game {
public:
    RGE_Player* get_player();
    char gap_00[0x1B0];
    int prog_mode;              // +0x1B0
};

extern RGE_Base_Game* rge_base_game;

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
    void set_disabled(int val);
};

class RGE_Player {
public:
    char gap_00[0x50];
    float* attributes;
};

class TribeDiplomacyDialog {
protected:
    char gap_00[0x574];
    TButtonPanel* stoneTributeButton[8]; // +0x574
    char gap_594[0x88];
    float stoneTotal;            // +0x61C
    char gap_620[0x90];
    int cur_player_row;          // +0x6B0
    int tribute_flag;            // +0x6B4

    int check_stone();
};
#endif

int TribeDiplomacyDialog::check_stone() {
    int result;
    int i;
    TButtonPanel** ppButton;
    RGE_Player* player;

    if (rge_base_game->prog_mode == 5) {
        result = 1;
    } else {
        player = rge_base_game->get_player();
        if (player->attributes[2] - this->stoneTotal > 0.0f) {
            result = 0;
        } else {
            result = 1;
        }
    }

    i = 0;
    ppButton = this->stoneTributeButton;
    do {
        if (*ppButton != 0) {
            if (i == this->cur_player_row) {
                (*ppButton)->set_disabled(1);
            } else {
                (*ppButton)->set_disabled(result);
            }

            if (this->tribute_flag != 0) {
                (*ppButton)->set_active(1);
            } else {
                (*ppButton)->set_active(0);
            }
        }
        i++;
        ppButton++;
    } while (i < 8);

    return result;
}
