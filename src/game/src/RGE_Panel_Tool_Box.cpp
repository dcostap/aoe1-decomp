#include "../include/RGE_Panel_Tool_Box.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Dialog_List.h"
#include "../include/RGE_Diamond_Map.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Active_Sprite_List.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_View.h"
#include "../include/TButtonPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TScreenPanel.h"
#include "../include/globals.h"

#include <string.h>

static char s_Object_List_Dialog[] = "Object List Dialog";
static char s_Terrain_List_Dialog[] = "Terrain List Dialog";

static char s_Game[] = "Game";
static char s_Obj[] = "Obj";
static char s_Move[] = "Move";
static char s_Del[] = "Del";
static char s_Terr[] = "Terr";
static char s_Elev[] = "Elev";
static char s_Cmd[] = "Cmd";

static char s_lt_Game_gt[] = "<Game>";
static char s_lt_Obj_gt[] = "<Obj>";
static char s_lt_Move_gt[] = "<Move>";
static char s_lt_Del_gt[] = "<Del>";
static char s_lt_Terr_gt[] = "<Terr>";
static char s_lt_Elev_gt[] = "<Elev>";
static char s_lt_Cmd_gt[] = "<Cmd>";

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
    // Fully verified. Source of truth: rpnl_tbx.cpp.decomp @ 0x004898D0
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
    }
    if (this->view == nullptr) {
        this->error_code = 1;
        return;
    }

    this->game_mode_button = new TButtonPanel();
    if (this->game_mode_button == nullptr) { this->error_code = 1; return; }
    this->game_mode_button->setup(this->render_area, this, 0, 0, 0x32, 0x1E, TButtonPanel::DrawTextA, param_10, TButtonPanel::NotifyAction, 0);
    this->game_mode_button->set_text_info(s_Game, param_7, param_8, param_9, -1, -1);
    this->game_mode_button->set_text(1, s_lt_Game_gt);

    this->object_mode_button = new TButtonPanel();
    if (this->object_mode_button == nullptr) { this->error_code = 1; return; }
    this->object_mode_button->setup(this->render_area, this, 0x34, 0, 0x32, 0x1E, TButtonPanel::DrawTextA, param_10, TButtonPanel::NotifyAction, 0);
    this->object_mode_button->set_text_info(s_Obj, param_7, param_8, param_9, -1, -1);
    this->object_mode_button->set_text(1, s_lt_Obj_gt);

    this->move_mode_button = new TButtonPanel();
    if (this->move_mode_button == nullptr) { this->error_code = 1; return; }
    this->move_mode_button->setup(this->render_area, this, 0x68, 0, 0x32, 0x1E, TButtonPanel::DrawTextA, param_10, TButtonPanel::NotifyAction, 0);
    this->move_mode_button->set_text_info(s_Move, param_7, param_8, param_9, -1, -1);
    this->move_mode_button->set_text(1, s_lt_Move_gt);

    this->delete_mode_button = new TButtonPanel();
    if (this->delete_mode_button == nullptr) { this->error_code = 1; return; }
    this->delete_mode_button->setup(this->render_area, this, 0x9C, 0, 0x32, 0x1E, TButtonPanel::DrawTextA, param_10, TButtonPanel::NotifyAction, 0);
    this->delete_mode_button->set_text_info(s_Del, param_7, param_8, param_9, -1, -1);
    this->delete_mode_button->set_text(1, s_lt_Del_gt);

    this->terrain_mode_button = new TButtonPanel();
    if (this->terrain_mode_button == nullptr) { this->error_code = 1; return; }
    this->terrain_mode_button->setup(this->render_area, this, 0xD0, 0, 0x32, 0x1E, TButtonPanel::DrawTextA, param_10, TButtonPanel::NotifyAction, 0);
    this->terrain_mode_button->set_text_info(s_Terr, param_7, param_8, param_9, -1, -1);
    this->terrain_mode_button->set_text(1, s_lt_Terr_gt);
    this->terrain_mode_button->set_active(0);

    this->elevation_mode_button = new TButtonPanel();
    if (this->elevation_mode_button == nullptr) { this->error_code = 1; return; }
    this->elevation_mode_button->setup(this->render_area, this, 0x104, 0, 0x32, 0x1E, TButtonPanel::DrawTextA, param_10, TButtonPanel::NotifyAction, 0);
    this->elevation_mode_button->set_text_info(s_Elev, param_7, param_8, param_9, -1, -1);
    this->elevation_mode_button->set_text(1, s_lt_Elev_gt);
    this->elevation_mode_button->set_active(0);

    TButtonPanel* mode_buttons[6];
    mode_buttons[0] = this->game_mode_button;
    mode_buttons[1] = this->object_mode_button;
    mode_buttons[2] = this->move_mode_button;
    mode_buttons[3] = this->delete_mode_button;
    mode_buttons[4] = this->terrain_mode_button;
    mode_buttons[5] = this->elevation_mode_button;
    this->game_mode_button->set_radio_info(mode_buttons, 6);
    this->object_mode_button->set_radio_info(mode_buttons, 6);
    this->move_mode_button->set_radio_info(mode_buttons, 6);
    this->delete_mode_button->set_radio_info(mode_buttons, 6);
    this->terrain_mode_button->set_radio_info(mode_buttons, 6);
    this->elevation_mode_button->set_radio_info(mode_buttons, 6);

    this->command_button = new TButtonPanel();
    if (this->command_button == nullptr) { this->error_code = 1; return; }
    this->command_button->setup(this->render_area, this, 0x13A, 0, 0x32, 0x1E, TButtonPanel::DrawTextA, param_10, TButtonPanel::NotifyAction, 0);
    this->command_button->set_text_info(s_Cmd, param_7, param_8, param_9, -1, -1);
    this->command_button->set_text(1, s_lt_Cmd_gt);
    this->command_button->set_state_info(2);

    this->game_mode_changed(rge_base_game->game_mode, rge_base_game->game_mode);
}

RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box() {
    // Fully verified. Source of truth: rpnl_tbx.cpp.decomp @ 0x00489E90
    if (this->game_mode_button != nullptr) { delete this->game_mode_button; }
    if (this->object_mode_button != nullptr) { delete this->object_mode_button; }
    if (this->move_mode_button != nullptr) { delete this->move_mode_button; }
    if (this->delete_mode_button != nullptr) { delete this->delete_mode_button; }
    if (this->terrain_mode_button != nullptr) { delete this->terrain_mode_button; }
    if (this->elevation_mode_button != nullptr) { delete this->elevation_mode_button; }
    if (this->command_button != nullptr) { delete this->command_button; }

    this->game_mode_button = nullptr;
    this->object_mode_button = nullptr;
    this->move_mode_button = nullptr;
    this->delete_mode_button = nullptr;
    this->terrain_mode_button = nullptr;
    this->elevation_mode_button = nullptr;
    this->command_button = nullptr;
}

long RGE_Panel_Tool_Box::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Fully verified. Source of truth: rpnl_tbx.cpp.decomp @ 0x00489F50
    (void)param_3;
    (void)param_4;

    if (param_1 == nullptr) {
        return 0;
    }

    if (((TButtonPanel*)param_1 == this->game_mode_button) && (param_2 == 1)) {
        rge_base_game->set_game_mode(0, 0);
        return 1;
    }

    if (((TButtonPanel*)param_1 == this->object_mode_button) && (param_2 == 1)) {
        this->dialog = (TPanel*)new RGE_Dialog_List(s_Object_List_Dialog);
        if (this->dialog != nullptr) {
            char* title = this->get_string(0x232A); // "Select Object"
            const long popup_id = this->screen_panel->get_popup_info_id();
            char* popup_file = this->screen_panel->get_popup_info_file();
            const int ok = ((RGE_Dialog_List*)this->dialog)->setup(this->screen_panel, popup_file, popup_id, 1, title);
            if (ok == 0) {
                delete this->dialog;
                this->dialog = nullptr;
                return 1;
            }
        }
        return 1;
    }

    if (((TButtonPanel*)param_1 == this->move_mode_button) && (param_2 == 1)) {
        rge_base_game->set_game_mode(0x12, 0);
        return 1;
    }
    if (((TButtonPanel*)param_1 == this->delete_mode_button) && (param_2 == 1)) {
        rge_base_game->set_game_mode(0x0E, 0);
        return 1;
    }
    if (((TButtonPanel*)param_1 == this->elevation_mode_button) && (param_2 == 1)) {
        rge_base_game->set_game_mode(3, 0);
        return 1;
    }
    if (((TButtonPanel*)param_1 == this->command_button) && (param_2 == 1)) {
        if (rge_base_game->prog_mode == 4) {
            rge_base_game->set_prog_mode(6);
            rge_base_game->world->temp_pause = 1;
            return 1;
        }
        rge_base_game->set_prog_mode(4);
        return 1;
    }

    TPanel** pp_dialog = &this->dialog;
    if (param_1 == this->dialog) {
        const char* dlg_name = this->dialog->panelName();
        if (strcmp(dlg_name, s_Object_List_Dialog) == 0) {
            if (param_2 == 1) {
                const short id = ((TListDialog*)*pp_dialog)->get_list_id();
                rge_base_game->master_obj_id = id;
                rge_base_game->delete_dialog(pp_dialog);
                rge_base_game->set_game_mode(1, 0);
                RGE_Player* player = rge_base_game->get_player();
                player->unselect_object();
                return 1;
            }
        } else if (strcmp(dlg_name, s_Terrain_List_Dialog) == 0) {
            if (param_2 == 1) {
                const short id = ((TListDialog*)*pp_dialog)->get_list_id();
                rge_base_game->terrain_id = id;
                rge_base_game->delete_dialog(pp_dialog);
                rge_base_game->set_game_mode(2, 0);
                return 1;
            }
        }

        if (param_2 == 2) {
            rge_base_game->delete_dialog(pp_dialog);
            this->game_mode_changed(rge_base_game->game_mode, rge_base_game->game_mode);
        }
        return 1;
    }

    return 0;
}

long RGE_Panel_Tool_Box::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: rpnl_tbx.cpp.decomp @ 0x0048A320
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;

    if (rge_base_game->get_paused() != 0) {
        return 0;
    }
    const int prog_mode = rge_base_game->prog_mode;
    if (((prog_mode != 4) && (prog_mode != 6)) && (prog_mode != 7)) {
        return 0;
    }

    if (param_1 == 0x21) {
        if (rge_base_game->game_mode != 3) {
            return 0;
        }
        long col1 = 0, row1 = 0, col2 = 0, row2 = 0;
        this->view->get_selection_area(&col1, &row1, &col2, &row2, 1);
        rge_base_game->world->map->set_elev((short)col1, (short)row1, (short)col2, (short)row2, '\0', 1, '\x01');
        rge_base_game->world->map->clean_elevation(col1, row1, col2, row2, '\b');
        this->view->set_redraw(TPanel::RedrawMode::RedrawFull);
        if (this->map != nullptr) {
            this->map->set_redraw(TPanel::RedrawMode::RedrawFull);
        }
        return 1;
    }

    if (param_1 == 0x22) {
        if (rge_base_game->game_mode != 3) {
            return 0;
        }
        long col1 = 0, row1 = 0, col2 = 0, row2 = 0;
        this->view->get_selection_area(&col1, &row1, &col2, &row2, 1);
        rge_base_game->world->map->set_elev((short)col1, (short)row1, (short)col2, (short)row2, '\0', -1, '\x01');
        rge_base_game->world->map->clean_elevation(col1, row1, col2, row2, '\b');
        this->view->set_redraw(TPanel::RedrawMode::RedrawFull);
        if (this->map != nullptr) {
            this->map->set_redraw(TPanel::RedrawMode::RedrawFull);
        }
        return 1;
    }

    if (param_1 != 0x2E) {
        return 0;
    }
    if (rge_base_game->game_mode != 0x12) {
        return 0;
    }

    RGE_Player* player = rge_base_game->get_player();
    RGE_Static_Object* obj = player->selected_obj;
    if (obj == nullptr) {
        return 1;
    }

    uchar lowest = 0;
    if (obj->sprite_list == nullptr) {
        if (obj->sprite == nullptr) {
            lowest = '\x14';
        } else {
            lowest = obj->sprite->get_lowest_draw_level();
        }
    } else {
        lowest = obj->sprite_list->get_lowest_draw_level();
    }

    obj->destroy_obj();
    if (lowest != '\0') {
        return 1;
    }

    this->view->set_redraw(TPanel::RedrawMode::RedrawFull);
    return 1;
}

void RGE_Panel_Tool_Box::game_mode_changed(int param_1, int param_2) {
    // Fully verified. Source of truth: rpnl_tbx.cpp.decomp @ 0x0048A520
    if ((param_1 == 1) || (param_1 == 0x12)) {
        RGE_Player* player = rge_base_game->get_player();
        player->unselect_object();
    } else if ((param_1 == 2) || (param_1 == 3)) {
        this->view->set_selection_area(-1, -1, -1, -1);
    }

    switch (param_2) {
    case 1:
        this->object_mode_button->set_radio_button();
        return;
    case 2:
        this->terrain_mode_button->set_radio_button();
        break;
    case 3:
        this->elevation_mode_button->set_radio_button();
        break;
    case 0x0E:
        this->delete_mode_button->set_radio_button();
        return;
    case 0x12:
        this->move_mode_button->set_radio_button();
        return;
    default:
        this->game_mode_button->set_radio_button();
        return;
    }

    RGE_Player* player = rge_base_game->get_player();
    player->unselect_object();
}

void RGE_Panel_Tool_Box::draw() {
    if (this->render_area != nullptr) {
        this->draw_setup(0);
        this->render_area->Clear(&this->clip_rect, 0);
        this->draw_finish();
    }
}
