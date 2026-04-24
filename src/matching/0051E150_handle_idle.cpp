extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" long __cdecl __ftol(void);

class RGE_Base_Game {
public:
    void get_countdown_timer(int player_id, long* out_value);
};

extern RGE_Base_Game* rge_base_game;

class WorldLike {
public:
    char gap_00[4];
    unsigned long world_time;
    char gap_08[0x110];
    float field_118;
};

class PlayerLike {
public:
    char gap_00[0x4A];
    short player_id_value;
    char gap_4C[0x7F4];
    float field_840;
    float field_844;
};

class TPanel {
public:
    long handle_idle();
};

class TRIBE_Panel_Time {
public:
    char gap_00[0x3C];
    TRIBE_Panel_Time* parent_panel;
    char gap_44[0xB0];
    void* font;
    int color1;
    int color2;
    int clock_type;
    char gap_104[0x4];
    int clock_format;
    char gap_10C[0x8];
    WorldLike* world;
    PlayerLike* player;
    unsigned long start_real_time;
    unsigned long current_display_value;
    unsigned long last_display_value;

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

};

long TRIBE_Panel_Time::handle_idle() {
    ((TPanel*)this)->handle_idle();

    switch (this->clock_type) {
    case 0:
        break;
    case 1:
        this->current_display_value = (debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_tim.cpp", 0x18A) - this->start_real_time) / 1000;
        break;
    case 2:
        this->current_display_value = this->world->world_time / 1000;
        break;
    case 3:
        this->current_display_value = (int)this->world->field_118;
        break;
    case 4:
        if (this->player != 0) {
            long countdown_timer;
            rge_base_game->get_countdown_timer(this->player->player_id_value, &countdown_timer);
            this->current_display_value = countdown_timer;
            break;
        }
        this->current_display_value = 0;
        break;
    case 5:
        if (this->player != 0 && this->player->field_844 != -1.0f) {
            this->current_display_value = (int)this->player->field_844;
            break;
        }
        this->current_display_value = 0;
        break;
    case 6:
        if (this->player != 0 && this->player->field_840 != -1.0f) {
            this->current_display_value = (int)this->player->field_840;
            break;
        }
        this->current_display_value = 0;
        break;
    }

    if (this->current_display_value != this->last_display_value) {
        this->set_redraw(1);
        this->parent_panel->set_redraw(1);
        this->last_display_value = this->current_display_value;
    }

    return 0;
}

