#include "../include/RGE_Panel_Tool_Box.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Diamond_Map.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_View.h"
#include "../include/TButtonPanel.h"
#include "../include/TDrawArea.h"
#include "../include/globals.h"

static RGE_Player* toolbox_active_player() {
    if (rge_base_game == nullptr || rge_base_game->world == nullptr || rge_base_game->world->players == nullptr) {
        return nullptr;
    }

    int idx = (int)rge_base_game->world->curr_player;
    if (idx < 0 || idx >= rge_base_game->world->player_num) {
        idx = rge_base_game->world->player_turn;
    }
    if (idx < 0 || idx >= rge_base_game->world->player_num) {
        return nullptr;
    }
    return rge_base_game->world->players[idx];
}

RGE_Panel_Tool_Box::RGE_Panel_Tool_Box(
    TDrawArea* param_1,
    TPanel* param_2,
    long param_3,
    long param_4,
    long param_5,
    long param_6,
    void* param_7,
    long param_8,
    long param_9,
    TDigital* param_10,
    TScreenPanel* param_11,
    RGE_View* param_12,
    RGE_Diamond_Map* param_13)
    : TPanel() {
    // TODO: STUB: Partial transliteration of rpnl_tbx.cpp constructor.
    this->screen_panel = param_11;
    this->view = param_12;
    this->map = param_13;
    this->game_mode_button = nullptr;
    this->object_mode_button = nullptr;
    this->delete_mode_button = nullptr;
    this->move_mode_button = nullptr;
    this->terrain_mode_button = nullptr;
    this->elevation_mode_button = nullptr;
    this->command_button = nullptr;
    this->dialog = nullptr;

    if (this->setup(param_1, param_2, param_3, param_4, param_5, param_6, 0) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->view == nullptr) {
        this->error_code = 1;
        return;
    }

    auto mk_mode_btn = [&](TButtonPanel*& dst, long x, const char* label, int id) -> int {
        dst = new TButtonPanel();
        if (dst == nullptr) {
            return 0;
        }
        if (dst->setup(param_1, this, x, 0, 0x32, 0x1E, TButtonPanel::DrawTextA, param_10, TButtonPanel::NotifyAction, id) == 0 ||
            dst->error_code != 0) {
            delete dst;
            dst = nullptr;
            return 0;
        }
        dst->set_font(param_7, param_8, param_9);
        dst->set_text(1, (char*)label);
        dst->set_text(0, (char*)label);
        return 1;
    };

    if (!mk_mode_btn(this->game_mode_button, 0x00, "<Game>", 0)) { this->error_code = 1; return; }
    if (!mk_mode_btn(this->object_mode_button, 0x34, "<Obj>", 0)) { this->error_code = 1; return; }
    if (!mk_mode_btn(this->move_mode_button, 0x68, "<Move>", 0)) { this->error_code = 1; return; }
    if (!mk_mode_btn(this->delete_mode_button, 0x9C, "<Del>", 0)) { this->error_code = 1; return; }
    if (!mk_mode_btn(this->terrain_mode_button, 0xD0, "<Terr>", 0)) { this->error_code = 1; return; }
    this->terrain_mode_button->set_active(0);
    if (!mk_mode_btn(this->elevation_mode_button, 0x104, "<Elev>", 0)) { this->error_code = 1; return; }
    this->elevation_mode_button->set_active(0);
    if (!mk_mode_btn(this->command_button, 0x13A, "<Cmd>", 0)) { this->error_code = 1; return; }
    this->command_button->set_state_info(2);

    this->game_mode_changed(rge_base_game != nullptr ? rge_base_game->game_mode : 0, rge_base_game != nullptr ? rge_base_game->game_mode : 0);
}

RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box() {
    delete this->game_mode_button; this->game_mode_button = nullptr;
    delete this->object_mode_button; this->object_mode_button = nullptr;
    delete this->move_mode_button; this->move_mode_button = nullptr;
    delete this->delete_mode_button; this->delete_mode_button = nullptr;
    delete this->terrain_mode_button; this->terrain_mode_button = nullptr;
    delete this->elevation_mode_button; this->elevation_mode_button = nullptr;
    delete this->command_button; this->command_button = nullptr;
}

long RGE_Panel_Tool_Box::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    (void)param_3;
    (void)param_4;

    // TODO: STUB: Partial action parity from rpnl_tbx.cpp.
    if (param_1 == nullptr || param_2 != 1 || rge_base_game == nullptr) {
        return 0;
    }

    if ((TButtonPanel*)param_1 == this->game_mode_button) {
        rge_base_game->set_game_mode(0, 0);
        return 1;
    }
    if ((TButtonPanel*)param_1 == this->move_mode_button) {
        rge_base_game->set_game_mode(0x12, 0);
        return 1;
    }
    if ((TButtonPanel*)param_1 == this->delete_mode_button) {
        rge_base_game->set_game_mode(0x0E, 0);
        return 1;
    }
    if ((TButtonPanel*)param_1 == this->terrain_mode_button) {
        rge_base_game->set_game_mode(2, 0);
        return 1;
    }
    if ((TButtonPanel*)param_1 == this->elevation_mode_button) {
        rge_base_game->set_game_mode(3, 0);
        return 1;
    }
    if ((TButtonPanel*)param_1 == this->object_mode_button) {
        rge_base_game->set_game_mode(1, 0);
        return 1;
    }
    if ((TButtonPanel*)param_1 == this->command_button) {
        if (rge_base_game->prog_mode == 4) {
            rge_base_game->set_prog_mode(6);
            if (rge_base_game->world != nullptr) {
                rge_base_game->world->temp_pause = 1;
            }
        } else {
            rge_base_game->set_prog_mode(4);
        }
        return 1;
    }

    return 1;
}

long RGE_Panel_Tool_Box::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
    // TODO: STUB: key-down terrain/elevation editor parity pending.
    return 0;
}

void RGE_Panel_Tool_Box::game_mode_changed(int param_1, int param_2) {
    if (param_1 == 1 || param_1 == 0x12) {
        RGE_Player* p = toolbox_active_player();
        if (p != nullptr) {
            p->unselect_object();
        }
    } else if (param_1 == 2 || param_1 == 3) {
        if (this->view != nullptr) {
            this->view->sel_col1 = -1;
            this->view->sel_row1 = -1;
            this->view->sel_col2 = -1;
            this->view->sel_row2 = -1;
        }
    }

    if (this->game_mode_button) this->game_mode_button->set_state(0);
    if (this->object_mode_button) this->object_mode_button->set_state(0);
    if (this->move_mode_button) this->move_mode_button->set_state(0);
    if (this->delete_mode_button) this->delete_mode_button->set_state(0);
    if (this->terrain_mode_button) this->terrain_mode_button->set_state(0);
    if (this->elevation_mode_button) this->elevation_mode_button->set_state(0);

    switch (param_2) {
    case 1:
        if (this->object_mode_button) this->object_mode_button->set_radio_button();
        return;
    case 2:
        if (this->terrain_mode_button) this->terrain_mode_button->set_radio_button();
        break;
    case 3:
        if (this->elevation_mode_button) this->elevation_mode_button->set_radio_button();
        break;
    case 0x0E:
        if (this->delete_mode_button) this->delete_mode_button->set_radio_button();
        return;
    case 0x12:
        if (this->move_mode_button) this->move_mode_button->set_radio_button();
        return;
    default:
        if (this->game_mode_button) this->game_mode_button->set_radio_button();
        return;
    }

    RGE_Player* p = toolbox_active_player();
    if (p != nullptr) {
        p->unselect_object();
    }
}

void RGE_Panel_Tool_Box::draw() {
    if (this->render_area != nullptr) {
        this->draw_setup(0);
        this->render_area->Clear(&this->clip_rect, 0);
        this->draw_finish();
    }
}
