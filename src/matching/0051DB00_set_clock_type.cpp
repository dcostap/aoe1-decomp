// first pass with the tpnl_tim local layout fixed the main field offsets and most of the body shape
// remaining mismatch is now the top-of-function register/save basin: VC5 still chooses ebx for the first arg instead of the original esi/edi-only shape
// next lead: probe the source family around the early equality gate and the final visible-flag push so VC5 stops saving ebx
class PlayerCivInfo {
public:
    char gap_00[0x26];
    short civ_id;
};

class PlayerLike {
public:
    char gap_00[0x4A];
    short player_id_value;
    char gap_4C[0xBC];
    PlayerCivInfo* civ_info;
};

class WorldLike {
public:
    char gap_00[0x40];
    PlayerLike** players;
};

class TRIBE_Panel_Time {
public:
    char gap_00[0x3C];
    TRIBE_Panel_Time* parent_panel;
    char gap_44[0xB0];
    void* font;
    int field_F8;
    int field_FC;
    int field_100;
    char gap_104[0x4];
    int field_108;
    char gap_10C[0x8];
    WorldLike* world;
    PlayerLike* player;

    virtual void vf00();
    virtual void* vf04(unsigned int);
    virtual void vf08();
    virtual int vf0C();
    virtual void vf10();
    virtual void set_visible(int);
    virtual void vf18();
    virtual void vf1C();
    virtual long set_redraw(int);
    virtual long handle_idle();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void startup();

    void set_clock_type(int clock_type, int player_id);
};

void TRIBE_Panel_Time::set_clock_type(int clock_type, int player_id) {
    if (this->field_100 == clock_type) {
        if (this->player == 0) {
            return;
        }
        if (this->player->player_id_value == player_id) {
            return;
        }
    }

    this->field_100 = clock_type;

    if (player_id > 0) {
        this->player = this->world->players[player_id];
    } else {
        this->player = 0;
    }

    if (this->player != 0) {
        switch (this->player->civ_info->civ_id) {
        case 0:
            this->field_F8 = 0x00FF0000;
            this->field_FC = 0x00B3B3B3;
            break;
        case 1:
            this->field_F8 = 0x002139C6;
            this->field_FC = 0;
            break;
        case 2:
            this->field_F8 = 0x0000FFFF;
            this->field_FC = 0;
            break;
        case 3:
            this->field_F8 = 0x004F73A3;
            this->field_FC = 0;
            break;
        case 4:
            this->field_F8 = 0x000F77F3;
            this->field_FC = 0;
            break;
        case 5:
            this->field_F8 = 0x0000C700;
            this->field_FC = 0;
            break;
        case 6:
            this->field_F8 = 0x007B90A2;
            this->field_FC = 0;
            break;
        case 7:
            this->field_F8 = 0x00ADAD00;
            this->field_FC = 0;
            break;
        default:
            this->field_F8 = 0x00FFFFFF;
            this->field_FC = 0;
            break;
        }
    } else {
        this->field_F8 = 0x00FFFFFF;
        this->field_FC = 0;
    }

    if (clock_type == 1 || clock_type == 2) {
        this->field_108 = 1;
    } else {
        this->field_108 = 2;
    }

    if (clock_type == 0) {
        this->set_visible(0);
    } else {
        this->set_visible(1);
    }
    this->set_redraw(1);
    this->parent_panel->set_redraw(1);
    this->startup();
}
