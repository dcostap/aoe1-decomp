#ifndef AOE1_RPNL_TIM_CONTEXT_H
class RGE_Game_World {
public:
    char gap_00[4];
    unsigned long world_time;
    char gap_08[0x0C];
    unsigned long old_time;
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
};

extern RGE_Base_Game* rge_base_game;

class RGE_Panel_Time {
public:
    char gap_04[0x3C];
    RGE_Panel_Time* parent_panel;
    char gap_44[0xB4];
    unsigned long game_time;
    unsigned long last_game_time;
    int old_time;
    unsigned long real_time;

    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual long set_redraw(int);
    virtual long handle_idle();
};

class TPanel {
public:
    long handle_idle();
};
#endif

long RGE_Panel_Time::handle_idle() {
#ifdef AOE1_RPNL_TIM_CONTEXT_H
    this->TPanel::handle_idle();
#else
    ((TPanel*)this)->handle_idle();
#endif

    this->game_time = rge_base_game->world->world_time / 1000;

    unsigned long old_time = rge_base_game->world->old_time / 1000;
    if ((int)old_time > 0) {
        if (this->old_time == -1) {
            this->old_time = old_time;
            this->real_time = 0;
        } else {
            this->real_time = old_time - this->old_time;
        }
    }

    if (this->game_time != this->last_game_time) {
        this->set_redraw(1);
        if (this->parent_panel != 0) {
            this->parent_panel->set_redraw(1);
        }
        this->last_game_time = this->game_time;
    }

    return 0;
}
