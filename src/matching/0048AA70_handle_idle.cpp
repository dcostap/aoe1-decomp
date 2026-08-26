#include "..\..\include\rpnl_tim_context.h"

long RGE_Panel_Time::handle_idle() {
    this->TPanel::handle_idle();

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
