// PDB source module: C:\msdev\work\age1_x1\rpnl_tbx.cpp.
// Definitions follow the PDB source lines and address order.

#include "../include/rpnl_tbx.h"

#include "../include/asp_list.h"
#include "../include/basegame.h"
#include "../include/diam_map.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/sprite.h"
#include "../include/stat_obj.h"
#include "../include/view.h"
#include "../include/world.h"

#include <string.h>

static char text_game[] = "Game";
static char text_game_label[] = "<Game>";
static char text_object[] = "Obj";
static char text_object_label[] = "<Obj>";
static char text_move[] = "Move";
static char text_move_label[] = "<Move>";
static char text_delete[] = "Del";
static char text_delete_label[] = "<Del>";
static char text_terrain[] = "Terr";
static char text_terrain_label[] = "<Terr>";
static char text_elevation[] = "Elev";
static char text_elevation_label[] = "<Elev>";
static char text_command[] = "Cmd";
static char text_command_label[] = "<Cmd>";

// PDB: rpnl_tbx.cpp:39-161.
RGE_Panel_Tool_Box::RGE_Panel_Tool_Box(
    TDrawArea* draw_area,
    TPanel* parent,
    long x,
    long y,
    long width,
    long height,
    void* font,
    long font_width,
    long font_height,
    TDigital* sound,
    TScreenPanel* screen_panel_value,
    RGE_View* view_value,
    RGE_Diamond_Map* map_value)
    : TPanel()
{
    this->screen_panel = screen_panel_value;
    this->view = view_value;
    this->map = map_value;
    this->game_mode_button = 0;
    this->object_mode_button = 0;
    this->delete_mode_button = 0;
    this->move_mode_button = 0;
    this->terrain_mode_button = 0;
    this->elevation_mode_button = 0;
    this->command_button = 0;
    this->dialog = 0;

    if (TPanel::setup(draw_area, parent, x, y, width, height, 0) == 0) {
        this->error_code = 1;
    }
    if (this->view == 0) {
        this->error_code = 1;
    }
    else {
        this->game_mode_button = new TButtonPanel;
        if (this->game_mode_button == 0) {
            this->error_code = 1;
        }
        else {
            this->game_mode_button->setup(
                this->render_area, this, 0, 0, 0x32, 0x1E,
                TButtonPanel::DrawPicture, sound,
                TButtonPanel::NotifyAction, 0);
            this->game_mode_button->set_text_info(
                text_game, font, font_width, font_height, -1, -1);
            this->game_mode_button->set_text(1, text_game_label);

            this->object_mode_button = new TButtonPanel;
            if (this->object_mode_button == 0) {
                this->error_code = 1;
            }
            else {
                this->object_mode_button->setup(
                    this->render_area, this, 0x34, 0, 0x32, 0x1E,
                    TButtonPanel::DrawPicture, sound,
                    TButtonPanel::NotifyAction, 0);
                this->object_mode_button->set_text_info(
                    text_object, font, font_width, font_height, -1, -1);
                this->object_mode_button->set_text(1, text_object_label);

                this->move_mode_button = new TButtonPanel;
                if (this->move_mode_button == 0) {
                    this->error_code = 1;
                }
                else {
                    this->move_mode_button->setup(
                        this->render_area, this, 0x68, 0, 0x32, 0x1E,
                        TButtonPanel::DrawPicture, sound,
                        TButtonPanel::NotifyAction, 0);
                    this->move_mode_button->set_text_info(
                        text_move, font, font_width, font_height, -1, -1);
                    this->move_mode_button->set_text(1, text_move_label);

                    this->delete_mode_button = new TButtonPanel;
                    if (this->delete_mode_button == 0) {
                        this->error_code = 1;
                    }
                    else {
                        this->delete_mode_button->setup(
                            this->render_area, this, 0x9C, 0, 0x32, 0x1E,
                            TButtonPanel::DrawPicture, sound,
                            TButtonPanel::NotifyAction, 0);
                        this->delete_mode_button->set_text_info(
                            text_delete, font, font_width, font_height, -1, -1);
                        this->delete_mode_button->set_text(1, text_delete_label);

                        this->terrain_mode_button = new TButtonPanel;
                        if (this->terrain_mode_button == 0) {
                            this->error_code = 1;
                        }
                        else {
                            this->terrain_mode_button->setup(
                                this->render_area, this, 0xD0, 0, 0x32, 0x1E,
                                TButtonPanel::DrawPicture, sound,
                                TButtonPanel::NotifyAction, 0);
                            this->terrain_mode_button->set_text_info(
                                text_terrain, font, font_width, font_height,
                                -1, -1);
                            this->terrain_mode_button->set_text(
                                1, text_terrain_label);
                            this->terrain_mode_button->set_active(0);

                            this->elevation_mode_button = new TButtonPanel;
                            if (this->elevation_mode_button == 0) {
                                this->error_code = 1;
                            }
                            else {
                                this->elevation_mode_button->setup(
                                    this->render_area, this, 0x104, 0, 0x32,
                                    0x1E, TButtonPanel::DrawPicture, sound,
                                    TButtonPanel::NotifyAction, 0);
                                this->elevation_mode_button->set_text_info(
                                    text_elevation, font, font_width,
                                    font_height, -1, -1);
                                this->elevation_mode_button->set_text(
                                    1, text_elevation_label);
                                this->elevation_mode_button->set_active(0);

                                TButtonPanel* mode_buttons[6] = {
                                    this->game_mode_button,
                                    this->object_mode_button,
                                    this->move_mode_button,
                                    this->delete_mode_button,
                                    this->terrain_mode_button,
                                    this->elevation_mode_button
                                };
                                this->game_mode_button->set_radio_info(
                                    mode_buttons, 6);
                                this->object_mode_button->set_radio_info(
                                    mode_buttons, 6);
                                this->move_mode_button->set_radio_info(
                                    mode_buttons, 6);
                                this->delete_mode_button->set_radio_info(
                                    mode_buttons, 6);
                                this->terrain_mode_button->set_radio_info(
                                    mode_buttons, 6);
                                this->elevation_mode_button->set_radio_info(
                                    mode_buttons, 6);

                                this->command_button = new TButtonPanel;
                                if (this->command_button == 0) {
                                    this->error_code = 1;
                                }
                                else {
                                    this->command_button->setup(
                                        this->render_area, this, 0x13A, 0,
                                        0x32, 0x1E, TButtonPanel::DrawPicture,
                                        sound, TButtonPanel::NotifyAction, 0);
                                    this->command_button->set_text_info(
                                        text_command, font, font_width,
                                        font_height, -1, -1);
                                    this->command_button->set_text(
                                        1, text_command_label);
                                    this->command_button->set_state_info(2);
                                    RGE_Base_Game* base_game = rge_base_game;
                                    this->game_mode_changed(
                                        base_game->game_mode,
                                        base_game->game_mode);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// PDB: rpnl_tbx.cpp:166-174.
RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box()
{
    delete this->game_mode_button;
    delete this->object_mode_button;
    delete this->move_mode_button;
    delete this->delete_mode_button;
    delete this->terrain_mode_button;
    delete this->elevation_mode_button;
    delete this->command_button;
}

// PDB: rpnl_tbx.cpp:180-306.
long RGE_Panel_Tool_Box::action(TPanel* panel, long code,
                                unsigned long param_3, unsigned long param_4)
{
    if (panel != 0) {
        if ((panel == this->game_mode_button) && (code == 1)) {
            rge_base_game->set_game_mode(0, 0);
            return 1;
        }

        if ((panel == this->object_mode_button) && (code == 1)) {
            this->dialog = new RGE_Dialog_List("Object List Dialog");
            if (this->dialog != 0) {
                if (((RGE_Dialog_List*)this->dialog)->setup(
                        this->screen_panel,
                        this->screen_panel->get_popup_info_file(),
                        this->screen_panel->get_popup_info_id(),
                        1, this->get_string(0x232A)) == 0) {
                    delete this->dialog;
                    this->dialog = 0;
                }
            }
            return 1;
        }
        else {
            if ((panel == this->move_mode_button) && (code == 1)) {
                rge_base_game->set_game_mode(0x12, 0);
                return 1;
            }
            if ((panel == this->delete_mode_button) && (code == 1)) {
                rge_base_game->set_game_mode(0x0E, 0);
                return 1;
            }
            if ((panel == this->elevation_mode_button) && (code == 1)) {
                rge_base_game->set_game_mode(3, 0);
                return 1;
            }
            if ((panel == this->command_button) && (code == 1)) {
                if (rge_base_game->prog_mode == 4) {
                    rge_base_game->set_prog_mode(6);
                    rge_base_game->world->temp_pause = 1;
                }
                else {
                    rge_base_game->set_prog_mode(4);
                    return 1;
                }
            }
            else {
                if (panel != this->dialog) {
                    return 0;
                }

                if (strcmp(this->dialog->panelName(), "Object List Dialog") == 0) {
                    if (code == 1) {
                        rge_base_game->master_obj_id =
                            ((RGE_Dialog_List*)this->dialog)->get_list_id();
                        rge_base_game->delete_dialog(&this->dialog);
                        rge_base_game->set_game_mode(1, 0);
                        rge_base_game->get_player()->unselect_object();
                        return 1;
                    }
                    if (code == 2) {
                        rge_base_game->delete_dialog(&this->dialog);
                        this->game_mode_changed(rge_base_game->game_mode,
                                                rge_base_game->game_mode);
                        return 1;
                    }
                }
                else if (strcmp(this->dialog->panelName(),
                                "Terrain List Dialog") == 0) {
                    if (code == 1) {
                        rge_base_game->terrain_id =
                            ((RGE_Dialog_List*)this->dialog)->get_list_id();
                        rge_base_game->delete_dialog(&this->dialog);
                        rge_base_game->set_game_mode(2, 0);
                        return 1;
                    }
                    if (code == 2) {
                        rge_base_game->delete_dialog(&this->dialog);
                        this->game_mode_changed(rge_base_game->game_mode,
                                                rge_base_game->game_mode);
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}

// PDB: rpnl_tbx.cpp:312-372.
// ACCEPTED DRIFT: This body has a reviewed ESI/EDI role exchange only.
long RGE_Panel_Tool_Box::key_down_action(long key, short ch, int a3, int a4,
                                         int a5)
{
    long local_4;
    long x1;
    long y1;
    long x2;

    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->prog_mode != 4 &&
            rge_base_game->prog_mode != 6 &&
            rge_base_game->prog_mode != 7) {
            return 0;
        }

        switch (key) {
        case 0x2E: {
            if (rge_base_game->game_mode != 0x12) {
                return 0;
            }
            RGE_Player* player = rge_base_game->get_player();
            RGE_Static_Object* object = player->selected_obj;
            if (object != 0) {
                unsigned char draw_level;
                if (object->sprite_list != 0) {
                    draw_level = object->sprite_list->get_lowest_draw_level();
                }
                else if (object->sprite != 0) {
                    draw_level = object->sprite->get_lowest_draw_level();
                }
                else {
                    draw_level = 0x14;
                }

                object->destroy_obj();
                if (draw_level == 0) {
                    this->view->set_redraw(TPanel::RedrawImmediate);
                }
            }
            return 1;
        }

        case 0x21:
            if (rge_base_game->game_mode != 3) {
                return 0;
            }

            this->view->get_selection_area(local_4, x1, y1, x2, 1);
            rge_base_game->world->map->set_elev(
                (short)local_4, (short)x1, (short)y1, (short)x2, 0, 1, 1);
            rge_base_game->world->map->clean_elevation(local_4, x1, y1, x2, 8);
            break;

        case 0x22:
            if (rge_base_game->game_mode != 3) {
                return 0;
            }

            this->view->get_selection_area(local_4, x1, y1, x2, 1);
            rge_base_game->world->map->set_elev(
                (short)local_4, (short)x1, (short)y1, (short)x2, 0, -1, 1);
            rge_base_game->world->map->clean_elevation(local_4, x1, y1, x2, 8);
            break;

        default:
            return 0;
        }

        this->view->set_redraw(TPanel::RedrawImmediate);
        if (this->map != 0) {
            this->map->set_redraw(TPanel::RedrawImmediate);
        }
        return 1;
    }

    return 0;
}

// PDB: rpnl_tbx.cpp:380-422.
void RGE_Panel_Tool_Box::game_mode_changed(int mode, int new_mode)
{
    TButtonPanel* button;

    switch (mode) {
    case 1:
    case 0x12:
        rge_base_game->get_player()->unselect_object();
        break;
    case 2:
    case 3:
        this->view->set_selection_area(-1, -1, -1, -1);
        break;
    }

    switch (new_mode) {
    case 1:
        this->object_mode_button->set_radio_button();
        return;
    case 0x12:
        this->move_mode_button->set_radio_button();
        return;
    case 0xE:
        this->delete_mode_button->set_radio_button();
        return;
    case 2:
        button = this->terrain_mode_button;
        break;
    case 3:
        button = this->elevation_mode_button;
        break;
    default:
        this->game_mode_button->set_radio_button();
        return;
    }

    button->set_radio_button();
    rge_base_game->get_player()->unselect_object();
}

// PDB: rpnl_tbx.cpp:428-437.
void RGE_Panel_Tool_Box::draw()
{
    if (this->render_area != 0 && this->visible != 0 &&
        this->active != 0) {
        this->draw_setup(0);
        this->render_area->Clear(&this->clip_rect, 0);
        this->draw_finish();
    }
}
