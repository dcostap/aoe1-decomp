// BINARY NOTE: PDB-qualified owner is TRIBE_Panel_Time::set_clock_type(int,int)
// in tpnl_tim.cpp lines 153-199. The original body is 0051DB00-0051DC3E.
// The natural typed panel/player/world model preserves the early equality
// fault order, canonical fields, seven-color switch, clock format, and four
// ordered virtual calls. The reduced source is an exact byte match.
#ifndef TPNL_TIM_SHARED_CONTEXT
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

    virtual void setup();
    virtual void set_color();
    virtual void set_active();
    virtual void set_positioning();
    virtual void set_fixed_position();
    virtual void set_visible(int);
    virtual void draw_setup();
    virtual void draw_finish();
    virtual long set_redraw(int);
    virtual long handle_idle();
    virtual void draw();
    virtual void draw_rect();
    virtual void draw_offset();
    virtual void draw_rect2();
    virtual void draw_offset2();
    virtual void paint();
    virtual void wnd_proc();
    virtual void handle_size();
    virtual void handle_paint();
    virtual void startup();

    void set_clock_type(int clock_type, int player_id);
};
#else
#include "../../include/tpnl_tim_context.h"
#endif

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
#ifdef TPNL_TIM_SHARED_CONTEXT
        this->set_active(0);
#else
        this->set_visible(0);
#endif
    } else {
#ifdef TPNL_TIM_SHARED_CONTEXT
        this->set_active(1);
#else
        this->set_visible(1);
#endif
    }
    this->set_redraw(1);
    this->parent_panel->set_redraw(1);
    this->startup();
}
