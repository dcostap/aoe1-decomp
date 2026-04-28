// 0043E6E0 TribeDiplomacyDialog::check_stone
// Size: 136 bytes

extern void* rge_base_game;

class RGE_Base_Game {
public:
    void* get_player();
    char gap_00[0x1B0];
    int prog_mode;              // +0x1B0
};

class TButtonPanel {
public:
    virtual ~TButtonPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void slot5(int a); // slot 5 (0x14/4)
    void set_disabled(int val);
};

class Player {
public:
    char gap_00[0x50];
    float attr[2];               // actually attr array, index 2 is at +0x08 from attrs pointer
};

class TribeDiplomacyDialog {
public:
    char gap_00[0x574];
    void* stoneTributeButton[8]; // +0x574 (array of 8 void*)
    char gap_594[0x88];
    float stoneTotal;            // +0x61C
    char gap_620[0x90];
    int cur_player_row;          // +0x6B0
    int tribute_flag;            // +0x6B4

    int check_stone();
};

int TribeDiplomacyDialog::check_stone() {
    int result;
    int i;
    TButtonPanel** ppButton;
    RGE_Base_Game* base_game;
    Player* player;
    float* attr;

    base_game = *(RGE_Base_Game**)0x62C574;
    if (base_game->prog_mode == 5) {
        result = 1;
    } else {
        player = (Player*)base_game->get_player();
        attr = *(float**)((char*)player + 0x50);
        if (attr[2] - this->stoneTotal > 0.0f) {
            result = 0;
        } else {
            result = 1;
        }
    }

    i = 0;
    ppButton = (TButtonPanel**)this->stoneTributeButton;
    do {
        if (*ppButton != 0) {
            if (i == this->cur_player_row) {
                (*ppButton)->set_disabled(1);
            } else {
                (*ppButton)->set_disabled(result);
            }

            if (this->tribute_flag != 0) {
                (*ppButton)->slot5(1);
            } else {
                (*ppButton)->slot5(0);
            }
        }
        i++;
        ppButton++;
    } while (i < 8);

    return result;
}
