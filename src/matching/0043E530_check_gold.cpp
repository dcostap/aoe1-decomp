// 0043E530 check_gold (136 bytes) — MATCHED
// PDB: dlg_dip.cpp (TribeDiplomacyDialog::check_gold)

class TButtonPanel {
public:
    virtual void _virt0();
    virtual void _virt1();
    virtual void _virt2();
    virtual void _virt3();
    virtual void _virt4();
    virtual void set_fn(int enabled);

    void set_disabled(int enabled);
};

class RGE_Player;

class RGE_Base_Game {
public:
    char gap_1B0[0x1B0];
    int prog_mode;

    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

extern float DAT_0056f884;

class TribeDiplomacyDialog {
public:
    char gap_514[0x514];
    TButtonPanel* goldTributeButton[8];
    char gap_534[0xE4];
    float goldTotal;
    char gap_61C[0x94];
    int cur_player_row;
    int tribute_flag;

    int check_gold();
};

int TribeDiplomacyDialog::check_gold()
{
    int i;
    int gold_ok;
    TButtonPanel** ppBtn;
    TButtonPanel* btn;

    if (rge_base_game->prog_mode != 5) {
        RGE_Player* player = rge_base_game->get_player();
        float pg = *(float*)(*(char**)((char*)player + 0x50) + 0x0C);
        if ((pg - this->goldTotal) <= 0.0f) {
            gold_ok = 1;
        } else {
            gold_ok = 0;
        }
    } else {
        gold_ok = 1;
    }

    for (i = 0; i < 8; i++) {
        btn = this->goldTributeButton[i];
        if (btn) {
            if (i == this->cur_player_row) {
                btn->set_disabled(1);
            } else {
                btn->set_disabled(gold_ok);
            }
            btn = this->goldTributeButton[i];
            if (this->tribute_flag) {
                btn->set_fn(1);
            } else {
                btn->set_fn(0);
            }
        }
    }

    return gold_ok;
}
