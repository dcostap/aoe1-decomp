
#include "../include/scr_game.h"
#include "../include/program_mode.h"
#include "../include/game_globals.h"
#include "../include/resource_ids.h"
#include "../include/dsutil.h"
#include <new.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char s_Game_Screen[] = "Game Screen";
static char s_Help_Dialog[] = "Help Dialog";
static char s_Send_Quick_Message_Dialog[] = "Send Quick Message Dialog";
static char s_scr_game_cpp[] = "C:\\msdev\\work\\age1_x1\\scr_game.cpp";
char s_Save_Game_Screen[] = "Save Game Screen";
char s_btnbldg_d_shp[] = "btnbldg%d.shp";
char s_btnunit_shp[] = "btnunit.shp";

static char s_scr_game_draw[] = "scr_game::draw";
static char s_scr_game_draw2[] = "scr_game::draw2";
static char s_scr_game_draw3[] = "scr_game::draw3";
static char s_dlg6_format[] = "dlg6_%d";
static char s_btn6_format[] = "btn6_%d";
static char s_button_border_a_format[] = "btnbrda%d.shp";
static char s_button_other_format[] = "btnoth%d.shp";
static char s_button_border_b_format[] = "btnbrdb%d.shp";
static char s_button_border_c_format[] = "btnbrdc%d.shp";
static char s_game_a_format[] = "gamea%d.shp";
static char s_game_b_format[] = "gameb%d.shp";
static char s_game_c_format[] = "gamec%d.shp";

TRIBE_Screen_Game::TRIBE_Screen_Game()
    : TScreenPanel(s_Game_Screen) {
    displayPathingFlags = 0;
    allow_user_commands = (do_fixed_update == 0);
    die_die_die = 0;

    int i;
    this->game_screen_pic = 0;
    this->button_border1_pic = 0;
    this->button_other_pic = 0;
    this->button_border2_pic = 0;
    this->button_border3_pic = 0;
    this->button_cmd_pic = 0;
    this->button_tech_pic = 0;
    this->button_unit_pic = 0;
    this->more_cancel_pic = 0;
    for (i = 0; i < 5; i++) {
        this->button_bldg_pics[i] = 0;
    }
    this->main_view = 0;
    this->map_view = 0;
    this->inven_panel = 0;
    this->object_panel = 0;
    this->age_panel = 0;
    this->fps_panel = 0;
    for (i = 0; i < 8; ++i) {
        this->score_panel[i] = 0;
    }
    this->log_text = 0;
    this->log_scrollbar = 0;
    for (i = 0; i < 17; ++i) {
        this->button_panel[i] = 0;
    }
    this->text_line_panel = 0;
    this->quit_message_panel = 0;
    this->time_panel = 0;
    this->pop_panel = 0;
    for (i = 0; i < 10; ++i) {
        this->countdown_clock[i] = 0;
    }
    this->message_panel = 0;
    this->message_panel2 = 0;
    this->message_panel3 = 0;
    this->message_panel4 = 0;
    this->message_panel5 = 0;
    this->message_panel6 = 0;
    for (i = 0; i < 8; ++i) {
        this->chat_panel[i] = 0;
    }
    this->tool_box = 0;
    this->help_mode = 0;
    this->cheat_code_entry = 0;
    this->cheat_code_entry_str[0] = 0;

    this->world = static_cast<TRIBE_World*>(rge_base_game->world);
    this->update_interval = rge_base_game->prog_info->update_interval;
    this->last_update_time = debug_timeGetTime(s_scr_game_cpp, 278);
    this->map_redraw_interval = 0x14d;
    this->last_map_redraw_time = debug_timeGetTime(s_scr_game_cpp, 281);
    this->game_obj = 0;
    this->tech_list = 0;
    this->make_list = 0;
    this->bldg_list = 0;
    this->trade_list = 0;
    this->item_cnt = 0;
    this->start_item = 0;
    this->last_item = -1;
    this->terrain_sound_interval = 0;
    this->last_terrain_sound_time = 0;
    this->terrain_sound = 0;
    this->terrain_playing = 0;
    this->terrain_sound_start_time = 0;
    this->anim_pal = 1;
    this->anim_pal_interval = 0;
    this->last_anim_pal_time = 0;
    this->last_anim_pal_index = 0;
    this->last_anim_pal_index2 = 0;
    this->last_anim_pal_index3 = 0;
    this->mouse_last_x = -1;
    this->mouse_last_y = -1;
    this->save_age = 0;
    this->save_culture = -1;
    this->save_screen_width = 0;
    this->game_over_time = 0;
    this->showing_game_over = 0;
    this->chat_line = 0;
    this->view_interval = 100;
    this->last_view_time = debug_timeGetTime(s_scr_game_cpp, 322);
    this->player_quit = 0;

    this->view_town_center_hotkey = *this->get_string(STRING_ID_HOTKEY_VIEW_TOWN_CENTER);
    this->work_hotkey = 0;
    this->move_hotkey = *this->get_string(STRING_ID_HOTKEY_MOVE);
    this->attack_hotkey = 0;
    this->ungroup_hotkey = *this->get_string(STRING_ID_HOTKEY_UNGROUP);
    this->watch_hotkey = 0x41;
    for (i = 0; i < 8; i++) {
        this->select_building_hotkey[i] = *this->get_string(i + STRING_ID_HOTKEY_SELECT_BUILDING_BASE);
    }
    this->reset_after_update = 1;
    this->score_interval = 3000;
    this->last_score_time = debug_timeGetTime(s_scr_game_cpp, 340);
    this->watch_mode = 0;
    this->game_ended = 0;
    this->game_over_sound = 0;
    this->last_game_speed_change = 0;
    this->last_pause_change = 0;

    if (!this->setup(rge_base_game->draw_area, "scr6", 0xc388, 1)) {
        this->error_code = 1;
        return;
    }

    char str[512];

    this->button_unit_pic = new TShape(s_btnunit_shp, 0xc62a);
    if (this->button_unit_pic == 0 || !(this->button_unit_pic)->is_loaded()) {
        this->error_code = 1;
        return;
    }

    this->button_tech_pic = new TShape("btntech.shp", 0xc629);
    if (this->button_tech_pic == 0 || !this->button_tech_pic->is_loaded()) {
        this->error_code = 1;
        return;
    }

    this->button_cmd_pic = new TShape("btncmd.shp", 0xc621);
    if (this->button_cmd_pic == 0 || !this->button_cmd_pic->is_loaded()) {
        this->error_code = 1;
        return;
    }

    for (i = 0; i < 5; i++) {
        sprintf(str, s_btnbldg_d_shp, i);
        if (i < 4) {
            this->button_bldg_pics[i] = new TShape(str, i + 0xc610);
        }
        else {
            this->button_bldg_pics[i] = new TShape(str, 0xcf0d);
        }
        if (this->button_bldg_pics[i] == 0 || !(this->button_bldg_pics[i])->is_loaded()) {
            this->error_code = 1;
            return;
        }
    }

    TRIBE_Main_View* main_tmp = new TRIBE_Main_View;
    this->main_view = main_tmp;
    if (main_tmp == 0 || main_tmp->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->main_view->setup(this->render_area, this, 0, 0, 0, 0, 0, 1, "bordline")) {
        this->error_code = 1;
        return;
    }
    this->main_view->set_world(this->world);
    this->main_view->set_player(rge_base_game->get_player());

    this->map_view = new TRIBE_Diamond_Map_View;
    if (this->map_view == 0 || this->map_view->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->map_view->setup(this->render_area, this, 0, 0, 0, 0, 0, 0, rge_base_game->map_save_area)) {
        this->error_code = 1;
        return;
    }
    this->map_view->set_help_info(STRING_ID_HELP_DIAMOND_MAP, -1);
    this->map_view->set_world(this->world);
    this->map_view->set_bitmap("map.bmp", 0xc4e1);
    this->map_view->set_player(rge_base_game->get_player());
    TRIBE_Main_View* main_view_for_map = this->main_view;
    this->map_view->main_view = main_view_for_map;

    RGE_Font* font = rge_base_game->get_font(RGE_FONT_STANDARD);
    this->inven_panel = new TRIBE_Panel_Inven(this->render_area, this, font->font,
                                              static_cast<TRIBE_Player*>(rge_base_game->get_player()));
    if (this->inven_panel == 0 || this->inven_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    this->inven_panel->set_help_info(STRING_ID_HELP_INVENTORY, -1);

    font = rge_base_game->get_font(RGE_FONT_ARIAL_10_NORMAL);
    this->object_panel = new TRIBE_Panel_Object(this->render_area, this, font->font, font->font_wid, font->font_hgt,
                                                this->button_unit_pic, this->button_bldg_pics, static_cast<TRIBE_Player*>(rge_base_game->get_player()));
    if (this->object_panel == 0 || this->object_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    this->object_panel->set_help_info(STRING_ID_HELP_OBJECT_PANEL, STRING_ID_HELP_OBJECT_PANEL_MORE);

    font = rge_base_game->get_font(RGE_FONT_STANDARD);
    TDigital* sound = rge_base_game->get_sound(1);
    for (i = 0; i < 0x11; i++) {
        this->button_panel[i] = new TRIBE_Panel_Button(this->render_area, this, sound, font->font, font->font_wid, font->font_hgt, (i < 0x0c) ? this->button_border1_pic : this->button_border2_pic);
        if (this->button_panel[i] == 0 || (this->button_panel[i])->error_code != 0) {
            this->error_code = 1;
            return;
        }
        this->button_panel[i]->set_text_color(0, 0, 0xffffff);
        this->button_panel[i]->set_sound_number(1);
    }

    this->button_panel[12]->set_id(0, 0x0d, 0);
    this->button_panel[12]->set_help_info(STRING_ID_HELP_GAME_CHAT, -1);
    this->button_panel[13]->set_id(0, 0x0e, 0);
    this->button_panel[13]->set_help_info(STRING_ID_HELP_GAME_DIPLOMACY, -1);
    this->button_panel[14]->set_id(0, 0x0f, 0);
    this->button_panel[14]->set_help_info(STRING_ID_HELP_GAME_MENU, -1);
    this->button_panel[15]->set_id(0, 0x15, 0);
    this->button_panel[15]->set_help_info(STRING_ID_HELP_GAME_HELP, -1);
    this->button_panel[16]->set_id(0, 0x18, 0);
    this->button_panel[16]->set_help_info(STRING_ID_HELP_GAME_SCORE, -1);

    for (i = 12; i < 15; ++i) {
        this->button_panel[i]->setDrawType(TButtonPanel::DrawText);
        this->button_panel[i]->tribe_button_type = 3;
        this->button_panel[i]->set_text(0, rge_base_game->get_string2(RGE_STRING_TYPE_COMMAND,
                                                                      this->button_panel[i]->get_id(), 0, str, 512));
        this->button_panel[i]->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3,
                                              this->bevel_color4, this->bevel_color5, this->bevel_color6);
    }
    if (rge_base_game->singlePlayerGame() == 1) {
        this->button_panel[12]->set_active(0);
    }
    this->button_panel[15]->setDrawType(TButtonPanel::DrawText);
    this->button_panel[15]->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    this->button_panel[15]->tribe_button_type = 3;
    this->button_panel[15]->set_text(0, STRING_ID_BUTTON_HELP);
    this->button_panel[16]->setDrawType(TButtonPanel::DrawText);
    this->button_panel[16]->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    this->button_panel[16]->tribe_button_type = 3;
    this->button_panel[16]->set_text(0, STRING_ID_SCORE_BUTTON_SHORTCUT);
    this->get_string(STRING_ID_SCORE_BUTTON_MESSAGE, str, 512);
    this->button_panel[16]->set_text_msg(str);

    {
    font = rge_base_game->get_font(RGE_FONT_STANDARD);
    this->text_line_panel = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    if (this->text_line_panel == 0 || this->text_line_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!(this->text_line_panel)->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->text_line_panel->set_justification(TMessagePanel::LeftJust, TMessagePanel::BottomJust, 1);
    this->main_view->message_panel = this->text_line_panel;

    this->create_text(this->main_view, &this->quit_message_panel, STRING_ID_GAME_OVER_MESSAGE, 0, 0,
                      600, 60, RGE_FONT_STANDARD, 1, 1, 0);
    if (this->quit_message_panel != 0) {
        this->quit_message_panel->set_text_color(0xffffff, 0);
        this->quit_message_panel->set_active(0);
    }
    this->create_text(this->main_view, &this->pause_text, STRING_ID_GAME_PAUSED, 0, 0, 600, 60, RGE_FONT_COPPERPLATE_21_BOLD, 1, 1, 0);
    if (this->pause_text != 0) {
        this->pause_text->set_text_color(0xffffff, 0);
        this->pause_text->set_active(0);
    }
    }

    {
    TRIBE_Panel_Time* time_panel = new TRIBE_Panel_Time(this->render_area, this->main_view);
    this->time_panel = time_panel;
    if (time_panel == 0 || time_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    time_panel->set_active(0);

    TRIBE_Panel_Pop* pop_panel = new TRIBE_Panel_Pop(this->render_area, this->main_view);
    this->pop_panel = pop_panel;
    if (pop_panel == 0 || pop_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    pop_panel->set_active(0);

    for (i = 0; i < 10; i++) {
        TRIBE_Panel_Time* clock = new TRIBE_Panel_Time(this->render_area, this->main_view);
        this->countdown_clock[i] = clock;
        if (clock == 0 || clock->error_code != 0) {
            this->error_code = 1;
            return;
        }
        clock->set_active(0);
    }
    }

    rge_base_game->get_sound(1);
    font = rge_base_game->get_font(RGE_FONT_STANDARD);
    this->message_panel = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    this->message_panel2 = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    this->message_panel3 = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    this->message_panel4 = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    this->message_panel5 = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    this->message_panel6 = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    TMessagePanel* message_panel = this->message_panel;
    TMessagePanel* message_check;
    if (message_panel == 0 || message_panel->error_code != 0 ||
        (message_check = this->message_panel2) == 0 || message_check->error_code != 0 ||
        (message_check = this->message_panel3) == 0 || message_check->error_code != 0 ||
        (message_check = this->message_panel4) == 0 || this->message_panel5 == 0 || this->message_panel6 == 0 ||
        message_check->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!(this->message_panel)->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0) ||
        !(this->message_panel2)->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0) ||
        !(this->message_panel3)->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0) ||
        !(this->message_panel4)->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0) ||
        !(this->message_panel5)->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0) ||
        !(this->message_panel6)->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }

    font = rge_base_game->get_font(RGE_FONT_STANDARD);
    for (i = 0; i < 8; i++) {
        TMessagePanel* chat = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
        this->chat_panel[i] = chat;
        if (chat == 0 || chat->error_code != 0 || !chat->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0)) {
            this->error_code = 1;
            return;
        }
    }

    {
    char* initial_text = 0;
    font = rge_base_game->get_font(RGE_FONT_STANDARD);
    this->age_panel = new TTextPanel;
    if (this->age_panel == 0 || this->age_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->age_panel->setup(this->render_area, this, 0, 0, 0, 0, font->font, font->font_wid, font->font_hgt,
                                0, 0, 0, 0, 0, 0, initial_text)) {
        this->error_code = 1;
        return;
    }
    this->age_panel->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
    this->age_panel->set_help_info(STRING_ID_HELP_AGE, -1);
    if (do_color_log) {
        this->age_panel->set_active(0);
    }

    font = rge_base_game->get_font(RGE_FONT_ARIAL_10_NORMAL_ALT);
    this->fps_panel = new TTextPanel;
    if (this->fps_panel == 0 || this->fps_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->fps_panel->setup(this->render_area, this, 0, 0, 0, 0, font->font, font->font_wid, font->font_hgt,
                                0, 1, 0, 0, 0, 0, initial_text)) {
        this->error_code = 1;
        return;
    }
    this->fps_panel->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignLeft);
    if (rge_base_game->do_show_timings != 0) {
        this->fps_panel->set_active(1);
        this->inven_panel->set_active(0);
        if (do_color_log == 0) {
            this->age_panel->set_active(0);
        }
    }
    else {
        this->fps_panel->set_active(0);
        this->inven_panel->set_active(1);
        if (do_color_log == 0) {
            this->age_panel->set_active(1);
        }
    }
    }

    font = rge_base_game->get_font(RGE_FONT_STANDARD);
    int num_game_players = 0;
    if (rge_base_game->multiplayerGame()) {
        for (i = 1; i < 9; i++) {
            if (comm->GetPlayerHumanity(i) == ME_HUMAN || comm->GetPlayerHumanity(i) == ME_COMPUTER) {
                num_game_players++;
            }
        }
        if (num_game_players == 0) num_game_players = 1;
    }
    else {
        num_game_players = this->world->player_num - 1;
    }
    for (i = 0; i < num_game_players; i++) {
        TMessagePanel* score = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
        this->score_panel[i] = score;
        if (!score->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0) || this->score_panel[i] == 0 || this->score_panel[i]->error_code != 0) {
            this->error_code = 1;
            return;
        }
    }

    {
    if (!this->create_text(this, &this->log_text, s_empty_string, 10, 300, 400, 96, RGE_FONT_ARIAL_10_NORMAL, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->log_text->set_back_pic(0);
    this->log_text->set_fill_back(1, 0);
    this->log_text->set_style(TTextPanel::NormalStyle);
    this->log_text->set_text_color(0xffffff, 0);
    if (!this->create_auto_scrollbar(&this->log_scrollbar, this->log_text, 20)) {
        this->error_code = 1;
        return;
    }
    this->log_scrollbar->set_bevel_info(1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff);
    this->log_text->empty_list();
    this->log_text->set_active(0);
    }

    font = rge_base_game->get_font(RGE_FONT_ARIAL_10_NORMAL);
    TDigital* tool_sound = rge_base_game->get_sound(1);
    {
    RGE_Panel_Tool_Box* tool_box = new RGE_Panel_Tool_Box(this->render_area, this, 0, 0, 0, 0, font->font, font->font_wid, font->font_hgt, tool_sound, this, this->main_view, this->map_view);
    this->tool_box = tool_box;
    if (tool_box == 0 || tool_box->error_code != 0) {
        this->error_code = 1;
        return;
    }
    tool_box->set_active(0);
    }
    for (i = 0; i < 0x11; i++) {
        (this->button_panel[i])->set_z_order(1, 0);
    }
    this->handle_size(this->pnl_wid, this->pnl_hgt);
    this->set_curr_child(this->main_view);
    this->player_changed(rge_base_game->get_player()->id, rge_base_game->get_player()->id);

    this->terrain_sound_interval = 20000;
    this->last_terrain_sound_time = debug_timeGetTime(s_scr_game_cpp, 825);
    this->anim_pal_interval = 200;
    this->last_anim_pal_time = debug_timeGetTime(s_scr_game_cpp, 831);
    this->last_anim_pal_index = 0;
    this->last_anim_pal_index2 = 0;
    this->last_anim_pal_index3 = 0;
    this->anim_pal_table[0].red = 0x17;
    this->anim_pal_table[0].green = 0x27;
    this->anim_pal_table[0].blue = 0x7C;
    this->anim_pal_table[1].red = 0x27;
    this->anim_pal_table[1].green = 0x3F;
    this->anim_pal_table[1].blue = 0x90;
    this->anim_pal_table[2].red = 0x3F;
    this->anim_pal_table[2].green = 0x5F;
    this->anim_pal_table[2].blue = 0x9F;
    this->anim_pal_table[3].red = 0x57;
    this->anim_pal_table[3].green = 0x7B;
    this->anim_pal_table[3].blue = 0xB4;
    this->anim_pal_table[4].red = 0x3F;
    this->anim_pal_table[4].green = 0x5F;
    this->anim_pal_table[4].blue = 0xA0;
    this->anim_pal_table[5].red = 0x27;
    this->anim_pal_table[5].green = 0x3F;
    this->anim_pal_table[5].blue = 0x91;
    this->anim_pal_table[6].red = 0x17;
    this->anim_pal_table[6].green = 0x27;
    this->anim_pal_table[6].blue = 0x7B;

    this->time_panel->startup();
    this->time_panel->set_clock_type(0, 0);
    for (i = 0; i < 10; i++) {
        this->countdown_clock[i]->startup();
        this->countdown_clock[i]->set_clock_type(0, 0);
    }
    this->reset_clocks();
    this->pop_panel->startup();
    this->command_score(static_cast<unsigned int>(this->world->score_displayed));

    confirmed_close = 0;
    if (rge_base_game->check_prog_argument("PAUSE")) {
        start_paused = 1;
        rge_base_game->set_prog_mode(ProgModeGameTempPaused);
        rge_base_game->world->temp_pause = 1;
    }
}


TRIBE_Screen_Game::~TRIBE_Screen_Game() {
    panel_system.destroyPanel("Config Dialog");

    if (this->game_over_sound != 0) {
        if (this->game_over_sound->is_playing() != 0) {
            this->game_over_sound->stop();
        }
        TDigital* sound = this->game_over_sound;
        if (sound != 0) {
            delete sound;
        }
        this->game_over_sound = 0;
    }

    if (this->terrain_sound != 0) {
        if (this->terrain_playing != 0) {
            this->terrain_playing = 0;
            this->terrain_sound->stop();
        }
        this->terrain_sound = 0;
    }

    if (this->game_screen_pic != 0) {
        delete this->game_screen_pic;
        this->game_screen_pic = 0;
    }
    if (this->button_border1_pic != 0) {
        delete this->button_border1_pic;
        this->button_border1_pic = 0;
    }
    if (this->button_other_pic != 0) {
        delete this->button_other_pic;
        this->button_other_pic = 0;
    }
    if (this->button_border2_pic != 0) {
        delete this->button_border2_pic;
        this->button_border2_pic = 0;
    }
    if (this->button_border3_pic != 0) {
        delete this->button_border3_pic;
        this->button_border3_pic = 0;
    }
    if (this->button_cmd_pic != 0) {
        delete this->button_cmd_pic;
        this->button_cmd_pic = 0;
    }
    if (this->button_tech_pic != 0) {
        delete this->button_tech_pic;
        this->button_tech_pic = 0;
    }
    if (this->button_unit_pic != 0) {
        delete this->button_unit_pic;
        this->button_unit_pic = 0;
    }

    int i;
    for (i = 0; i < 5; i++) {
        if (this->button_bldg_pics[i] != 0) {
            delete this->button_bldg_pics[i];
            this->button_bldg_pics[i] = 0;
        }
    }

    if (this->tech_list != 0) {
        free(this->tech_list);
        this->tech_list = 0;
    }
    if (this->make_list != 0) {
        free(this->make_list);
        this->make_list = 0;
    }
    if (this->bldg_list != 0) {
        free(this->bldg_list);
        this->bldg_list = 0;
    }
    if (this->trade_list != 0) {
        free(this->trade_list);
        this->trade_list = 0;
    }

    for (i = 0; i < 8; i++) {
        if (this->chat_panel[i] != 0) {
            delete this->chat_panel[i];
            this->chat_panel[i] = 0;
        }
    }
    for (i = 0; i < 17; i++) {
        if (this->button_panel[i] != 0) {
            delete this->button_panel[i];
            this->button_panel[i] = 0;
        }
    }

    if (this->age_panel != 0) {
        delete this->age_panel;
        this->age_panel = 0;
    }
    if (this->fps_panel != 0) {
        delete this->fps_panel;
        this->fps_panel = 0;
    }
    for (i = 0; i < 8; i++) {
        if (this->score_panel[i] != 0) {
            delete this->score_panel[i];
            this->score_panel[i] = 0;
        }
    }

    if (this->log_text != 0) {
        delete this->log_text;
        this->log_text = 0;
    }
    if (this->log_scrollbar != 0) {
        delete this->log_scrollbar;
        this->log_scrollbar = 0;
    }
    if (this->inven_panel != 0) {
        delete this->inven_panel;
        this->inven_panel = 0;
    }
    if (this->object_panel != 0) {
        delete this->object_panel;
        this->object_panel = 0;
    }
    if (this->quit_message_panel != 0) {
        delete this->quit_message_panel;
        this->quit_message_panel = 0;
    }
    if (this->text_line_panel != 0) {
        delete this->text_line_panel;
        this->text_line_panel = 0;
    }
    if (this->time_panel != 0) {
        delete this->time_panel;
        this->time_panel = 0;
    }
    if (this->pop_panel != 0) {
        delete this->pop_panel;
        this->pop_panel = 0;
    }
    for (i = 0; i < 10; i++) {
        if (this->countdown_clock[i] != 0) {
            delete this->countdown_clock[i];
            this->countdown_clock[i] = 0;
        }
    }
    if (this->message_panel6 != 0) {
        delete this->message_panel6;
        this->message_panel6 = 0;
    }
    if (this->message_panel5 != 0) {
        delete this->message_panel5;
        this->message_panel5 = 0;
    }
    if (this->message_panel4 != 0) {
        delete this->message_panel4;
        this->message_panel4 = 0;
    }
    if (this->message_panel3 != 0) {
        delete this->message_panel3;
        this->message_panel3 = 0;
    }
    if (this->message_panel2 != 0) {
        delete this->message_panel2;
        this->message_panel2 = 0;
    }
    if (this->message_panel != 0) {
        delete this->message_panel;
        this->message_panel = 0;
    }
    if (this->tool_box != 0) {
        delete this->tool_box;
        this->tool_box = 0;
    }
    if (this->pause_text != 0) {
        delete this->pause_text;
        this->pause_text = 0;
    }
    if (this->main_view != 0) {
        delete this->main_view;
        this->main_view = 0;
    }
    if (this->map_view != 0) {
        delete this->map_view;
        this->map_view = 0;
    }
}

void TRIBE_Screen_Game::set_redraw(TPanel::RedrawMode redraw_mode) {
    this->TPanel::set_redraw(redraw_mode);
}

void TRIBE_Screen_Game::set_overlapped_redraw(TPanel* redraw_panel, TPanel* calling_panel, TPanel::RedrawMode redraw_mode) {
    TPanel* dialog = panel_system.modalPanel();
    if (dialog != 0) {
        tagRECT this_rect = redraw_panel->clip_rect;
        tagRECT other_rect = dialog->clip_rect;

        if (((((other_rect.left >= this_rect.left) && (other_rect.left <= this_rect.right)) ||
                ((other_rect.right >= this_rect.left) && (other_rect.right <= this_rect.right)) ||
                ((this_rect.left > other_rect.left) && (other_rect.right > this_rect.right))) && (
                ((other_rect.top >= this_rect.top) && (other_rect.top <= this_rect.bottom)) ||
                ((other_rect.bottom >= this_rect.top) && (other_rect.bottom <= this_rect.bottom)) ||
                ((other_rect.top < this_rect.top) && (other_rect.bottom > this_rect.bottom)))) || ((
                ((this_rect.left >= other_rect.left) && (this_rect.left <= other_rect.right)) ||
                ((this_rect.right >= other_rect.left) && (this_rect.right <= other_rect.right)) ||
                ((this_rect.left < other_rect.left) && (this_rect.right > other_rect.right))) && (
                ((this_rect.top >= other_rect.top) && (this_rect.top <= other_rect.bottom)) ||
                ((this_rect.bottom >= other_rect.top) && (this_rect.bottom <= other_rect.bottom)) ||
                ((this_rect.top < other_rect.top) && (this_rect.bottom > other_rect.bottom))))) {
            dialog->set_redraw(redraw_mode);
        }
    }
}

void TRIBE_Screen_Game::set_map_buttons_redraw(TPanel::RedrawMode redraw_mode) {
    if (this->pnl_wid < 800) {
        this->button_panel[5]->set_redraw(redraw_mode);
        this->button_panel[11]->set_redraw(redraw_mode);
    }
    this->button_panel[15]->set_redraw(redraw_mode);
    this->button_panel[16]->set_redraw(redraw_mode);
}

long TRIBE_Screen_Game::handle_size(long win_wid, long win_hgt) {
    TPanel::handle_size(win_wid, win_hgt);

    if (this->main_view == 0) {
        return 0;
    }

    int save_score_active[8];
    long panel_y;
    long panel_x;

    this->log_text->set_active(0);
    this->text_line_panel->set_active(1);
    this->message_panel->set_active(1);
    this->message_panel2->set_active(1);
    this->message_panel3->set_active(1);
    this->message_panel4->set_active(1);
    this->message_panel5->set_active(1);
    this->message_panel6->set_active(1);

    int* saved_score = save_score_active;
    for (int score_active_index = 0; score_active_index < 8; ++score_active_index) {
        TPanel* panel = this->score_panel[score_active_index];
        if (panel != 0) {
            *saved_score = panel->active;
            panel->set_active(1);
        }
        ++saved_score;
    }

    short final_frame;

    if (this->pnl_wid >= 1024 && this->pnl_hgt >= 768) {
        this->pop_panel->set_positioning(TPanel::PositionLeftTop, 432, 4, 4, 4, 160, 160, 20, 20, 0, 0, 0, 0);

        if (this->tool_box->active != 0) {
            this->tool_box->set_fixed_position(0, 20, 1024, 30);
            this->main_view->set_fixed_position(0, 50, 1024, 592);
        } else {
            this->main_view->set_fixed_position(0, 20, 1024, 622);
        }

        this->map_view->set_fixed_position(795, 648, 220, 114);
        this->age_panel->set_fixed_position(270, 2, 492, 16);
        this->fps_panel->set_fixed_position(2, 2, 280, 16);
        this->inven_panel->set_fixed_position(0, 0, 270, 20);
        this->object_panel->set_fixed_position(5, 649, 127, 114);

        panel_y = 650;
        for (int panel_row = 0; panel_row < 2; ++panel_row) {
            panel_x = 136;
            int button_index = panel_row * 6;
            for (int panel_column = 0; panel_column < 6; ++panel_column) {
                this->button_panel[button_index]->set_fixed_position(panel_x, panel_y, 54, 54);
                this->button_panel[button_index]->tribe_button_type = 0;
                ++button_index;
                panel_x += 54;
            }
            panel_y += 58;
        }

        this->button_panel[12]->set_fixed_position(772, 0, 72, 19);
        this->button_panel[13]->set_fixed_position(844, 0, 108, 19);
        this->button_panel[14]->set_fixed_position(952, 0, 72, 19);
        this->button_panel[15]->set_fixed_position(989, 732, 30, 30);
        this->button_panel[15]->tribe_button_type = 3;
        this->button_panel[16]->set_fixed_position(989, 650, 30, 30);
        this->button_panel[16]->tribe_button_type = 3;

        this->more_cancel_pic = this->button_cmd_pic;
        this->more_frame = 0xB;
        final_frame = 0xA;
    } else {
        if (this->pnl_wid >= 800 && this->pnl_hgt >= 600) {
        this->pop_panel->set_positioning(TPanel::PositionLeftTop, 320, 4, 4, 4, 160, 160, 20, 20, 0, 0, 0, 0);

        if (this->tool_box->active != 0) {
            this->tool_box->set_fixed_position(0, 20, 800, 30);
            this->main_view->set_fixed_position(0, 50, 800, 424);
        } else {
            this->main_view->set_fixed_position(0, 20, 800, 454);
        }

        this->map_view->set_fixed_position(571, 480, 220, 114);
        this->age_panel->set_fixed_position(270, 2, 268, 16);
        this->fps_panel->set_fixed_position(2, 2, 280, 16);
        this->inven_panel->set_fixed_position(0, 0, 270, 20);
        this->object_panel->set_fixed_position(5, 481, 127, 114);

        panel_y = 482;
        for (int panel_row = 0; panel_row < 2; ++panel_row) {
            panel_x = 136;
            int button_index = panel_row * 6;
            for (int panel_column = 0; panel_column < 6; ++panel_column) {
                this->button_panel[button_index]->set_fixed_position(panel_x, panel_y, 54, 54);
                this->button_panel[button_index]->tribe_button_type = 0;
                ++button_index;
                panel_x += 54;
            }
            panel_y += 58;
        }

        this->button_panel[12]->set_fixed_position(548, 0, 72, 19);
        this->button_panel[13]->set_fixed_position(620, 0, 108, 19);
        this->button_panel[14]->set_fixed_position(728, 0, 72, 19);
        this->button_panel[15]->set_fixed_position(765, 564, 30, 30);
        this->button_panel[15]->tribe_button_type = 3;
        this->button_panel[16]->set_fixed_position(765, 482, 30, 30);
        this->button_panel[16]->tribe_button_type = 3;

        this->more_cancel_pic = this->button_cmd_pic;
        this->more_frame = 0xB;
        final_frame = 0xA;
        } else {
        this->pop_panel->set_positioning(TPanel::PositionLeftTop, 240, 4, 4, 4, 160, 160, 20, 20, 0, 0, 0, 0);

        if (this->tool_box->active != 0) {
            this->tool_box->set_fixed_position(0, 20, 640, 30);
            this->main_view->set_fixed_position(0, 50, 640, 304);
        } else {
            this->main_view->set_fixed_position(0, 20, 640, 334);
        }

        this->map_view->set_fixed_position(411, 362, 220, 114);
        this->age_panel->set_fixed_position(270, 2, 106, 16);
        this->fps_panel->set_fixed_position(2, 2, 280, 16);
        this->inven_panel->set_fixed_position(0, 0, 270, 20);
        this->object_panel->set_fixed_position(5, 361, 127, 114);

        panel_y = 362;
        for (int panel_row = 0; panel_row < 2; ++panel_row) {
            panel_x = 136;
            int button_index = panel_row * 6;
            for (int panel_column = 0; panel_column < 6; ++panel_column) {
                this->button_panel[button_index]->set_fixed_position(panel_x, panel_y, 54, 54);
                this->button_panel[button_index]->tribe_button_type = 0;
                ++button_index;
                panel_x += 54;
            }
            panel_y += 58;
        }

        this->button_panel[5]->set_fixed_position(406, 362, 102, 53);
        this->button_panel[5]->tribe_button_type = 2;
        this->button_panel[11]->set_fixed_position(406, 443, 102, 53);
        this->button_panel[11]->tribe_button_type = 2;
        this->button_panel[12]->set_fixed_position(388, 0, 72, 19);
        this->button_panel[13]->set_fixed_position(460, 0, 108, 19);
        this->button_panel[14]->set_fixed_position(568, 0, 72, 19);
        this->button_panel[15]->set_fixed_position(605, 444, 30, 30);
        this->button_panel[15]->tribe_button_type = 3;
        this->button_panel[16]->set_fixed_position(605, 362, 30, 30);
        this->button_panel[16]->tribe_button_type = 3;

        this->more_cancel_pic = this->button_other_pic;
        this->more_frame = 0;
            final_frame = 2;
        }
    }

    this->cancel_frame = final_frame;
    this->unselect_frame = final_frame;

    this->pause_text->set_positioning(TPanel::PositionCentered, 4, 4, 4, 4, 600, 600, 60, 60, 0, 0, 0, 0);
    this->time_panel->set_positioning(TPanel::PositionLeftTop, 4, 4, 4, 4, 120, 120, 20, 20, 0, 0, 0, 0);

    int clock_y = 4;
    TRIBE_Panel_Time** clock_panel = this->countdown_clock;
    for (int clock_index = 0; clock_index < 10; ++clock_index) {
        (*clock_panel)->set_positioning(TPanel::PositionRightTop, 4, clock_y, 4, 4, 170, 170, 20, 20, 0, 0, 0, 0);
        ++clock_panel;
        clock_y += 20;
    }

    if (this->world->score_displayed != 0) {
        this->text_line_panel->set_positioning(TPanel::PositionLeftBottom, 4, 0, 184, 4, 0, 0, 34, 34, 0, 0, 0, 0);
    } else {
        this->text_line_panel->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 4, 0, 0, 34, 34, 0, 0, 0, 0);
    }

    int half_width = (this->main_view->width() - 500) / 2;
    this->quit_message_panel->set_positioning(TPanel::PositionLeftTop, half_width, 8, half_width, 8, 0, 0, 20, 20,
                                              0, 0, 0, 0);

    this->message_panel->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0, 0, 0, 20, 20,
                                         0, 0, 0, this->text_line_panel);
    this->message_panel2->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0, 0, 0, 20, 20,
                                          0, 0, 0, this->message_panel);
    this->message_panel3->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0, 0, 0, 20, 20,
                                          0, 0, 0, this->message_panel2);
    this->message_panel4->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0, 0, 0, 20, 20,
                                          0, 0, 0, this->message_panel3);
    this->message_panel5->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0, 0, 0, 20, 20,
                                          0, 0, 0, this->message_panel4);
    this->message_panel6->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0, 0, 0, 20, 20,
                                          0, 0, 0, this->message_panel5);

    int chat_y = 34;
    TMessagePanel** chat_panel = this->chat_panel;
    for (int chat_index = 0; chat_index < 8; ++chat_index) {
        (*chat_panel)->set_fixed_position(4, chat_y, 620, 20);
        ++chat_panel;
        chat_y += 20;
    }

    short score_index = 7;
    do {
        if (this->score_panel[score_index] != 0) {
            this->score_panel[score_index]->set_positioning(TPanel::PositionRightBottom, 4, 0, 4, score_index == 7 ? 4 : 0,
                                                            200, 200, 20, 20, 0, 0, 0, score_index == 7 ? 0 : this->score_panel[score_index + 1]);
        }
        --score_index;
    } while (score_index >= 0);

    this->text_line_panel->set_active(0);
    this->message_panel->set_active(0);
    this->message_panel2->set_active(0);
    this->message_panel3->set_active(0);
    this->message_panel4->set_active(0);
    this->message_panel5->set_active(0);
    this->message_panel6->set_active(0);

    for (int score_restore_index = 0; score_restore_index < 8; ++score_restore_index) {
        if (this->score_panel[score_restore_index] != 0) {
            this->score_panel[score_restore_index]->set_active(save_score_active[score_restore_index]);
        }
    }

    this->player_changed(static_cast<short>(rge_base_game->get_player()->id),
                         static_cast<short>(rge_base_game->get_player()->id));
    return 0;
}


long TRIBE_Screen_Game::handle_paint() {
    if (this->render_area == 0) {
        return 0;
    }
    if (this->visible == 0) {
        return 0;
    }
    if (this->active == 0) {
        return 0;
    }
    if (rge_base_game->prog_active == 0) {
        return 0;
    }
    if (IsIconic(this->render_area->Wnd) != 0) {
        return 0;
    }

    unsigned long first_time =
        debug_timeGetTime(s_scr_game_cpp, 1450);

    int draw_all_children;
    if (this->need_redraw == 2 || this->main_view->get_focus() != 0 ||
        this->curr_child == panel_system.panel(s_Send_Quick_Message_Dialog)) {
        draw_all_children = 1;
    } else {
        TPanel* help_dialog = panel_system.panel(s_Help_Dialog);
        draw_all_children = 0;
        if (this->curr_child == help_dialog) {
            draw_all_children = 1;
        }
    }

    if (this->need_redraw != 0) {
        if (draw_all_children) {
            for (PanelNode* node = this->first_child_node; node != 0; node = node->next_node) {
                node->panel->set_redraw(static_cast<TPanel::RedrawMode>(this->need_redraw));
            }

            TPanel* panel = this->parent_panel;
            if (panel != 0 && panel->overlapping_children != 0) {
                panel->set_overlapped_redraw(this, this, static_cast<TPanel::RedrawMode>(this->need_redraw));
            }
            this->draw();
        }
        this->need_redraw = 0;
        this->just_drawn = 1;
    }

    unsigned long other_time =
        debug_timeGetTime(s_scr_game_cpp, 1474) - first_time;

    for (PanelNode* node = this->first_child_node; node != 0; node = node->next_node) {
        unsigned long child_start =
            debug_timeGetTime(s_scr_game_cpp, 1481);
        TPanel* panel = node->panel;

        if (draw_all_children || panel == this->curr_child) {
            panel->handle_paint();
        }

        unsigned long child_end =
            debug_timeGetTime(s_scr_game_cpp, 1488);
        unsigned long elapsed = child_end - child_start;
        if (panel != this->main_view && panel != this->map_view) {
            other_time += elapsed;
        }
    }

    rge_base_game->add_to_timing(0x11, other_time);
    this->just_drawn = 0;
    return 0;
}

long TRIBE_Screen_Game::handle_idle() {
    long result;

    color_log(0x5F, 0x5F, 5);

    if (rge_base_game->input_enabled == 0) {
        color_log(0x5F, 0x4C, 5);
        rge_base_game->enable_input();
    }

    color_log(0x5F, 0x16, 5);
    int mode = rge_base_game->prog_mode;

    if (mode == ProgModeGame || mode == ProgModeGameTempPaused || mode == ProgModeGameOver) {
        if (panel_system.currentPanel() == this && this->main_view->get_focus() != 0) {
            color_log(0x5F, 0x45, 5);
            this->handle_anim_pal();
        }
    }

    if (mode == ProgModeGame || mode == ProgModeGameTempPaused) {
        color_log(0x5F, 0x32, 5);
        this->handle_terrain_sound();
        color_log(0x5F, 0xBA, 5);
        this->handle_mouse_pointing_at();
    }

    color_log(0x5F, 0x24, 5);
    result = TPanel::handle_idle();
    color_log(0x5F, 0x5F, 5);
    return result;
}

void TRIBE_Screen_Game::handle_game_update() {
    int update_counter = 0;

    color_log(0x24, 0x24, 5);

    unsigned long calc_game_time = debug_timeGetTime(s_scr_game_cpp, 1599);
    if (calc_game_time - this->last_update_time < this->update_interval) {
        color_log(0x24, 0x5f, 5);
        return;
    }

    int mode = rge_base_game->prog_mode;
    if (static_cast<unsigned char>(mode) != ProgModeGameTempPaused) {
        color_log(0x24, 0x32, 5);

        int num_updates;
        if (rge_base_game->multiplayerGame()) {
            unsigned long single_time = rge_base_game->get_last_single_time(2);
            single_time += rge_base_game->get_last_single_time(3);
            unsigned long average_time;

            if (rge_base_game->get_last_world_update_count() != 0) {
                unsigned long world_update_count = rge_base_game->get_last_world_update_count();
                average_time = rge_base_game->get_last_time(1) / world_update_count;
                if (average_time == 0) {
                    average_time = 1;
                }
            } else {
                average_time = 1;
            }

            int player = comm->WhoAmI();
            unsigned long player_time = comm->Speed->PlayerAvgFramesMsec[player];
            if (multi_updates != 0 && player_time >= 0x43 && player_time <= 0x7d && static_cast<float>(average_time) /
                static_cast<long>(single_time) <= 2.0f) {
                num_updates = 2;
            } else {
                num_updates = 1;
            }

            rge_base_game->set_last_single_time(2, 0);
            rge_base_game->set_last_single_time(3, 0);
        } else {
            num_updates = 1;
        }

        for (int update = 0; update < num_updates; ++update) {
            color_log(0x24, 0x4c, 5);
            color_log(0x24, 0x24, 1);

            unsigned long update_start = debug_timeGetTime(s_scr_game_cpp, 1682);
            unsigned char game_state;

            if (start_paused != 0) {
                game_state = 0;
                rge_base_game->set_prog_mode(ProgModeGameTempPaused);
            } else if (this->game_ended != 0) {
                game_state = 1;
            } else {
                game_state = this->world->update();
                if (out_of_sync2 != 0) {
                    return;
                }

                if (game_state == 1) {
                    this->game_ended = 1;
                    this->main_view->end_scroll_view();
                    this->main_view->set_selection_area(-1, -1, -1, -1);
                    rge_base_game->set_game_mode(0, 0);
                    this->command_unselect();
                    if (rge_base_game->multiplayerGame()) {
                        this->world->send_zone_score_info();
                    }
                }
            }

            if (out_of_sync2 != 0) {
                return;
            }

            calc_game_time = debug_timeGetTime(s_scr_game_cpp, 1723);
            this->last_update_time = calc_game_time;
            if (this->world->world_time_delta != 0) {
                rge_base_game->add_to_timing(1, calc_game_time - update_start);
                rge_base_game->increment_world_update_count();
            }

            color_log(0x24, 0xba, 1);

            if (this->reset_after_update != 0) {
                this->reset_clocks();
                this->reset_after_update = 0;
            }
            if (this->watch_mode != 0) {
                this->command_view_selected();
            }

            if (this->game_obj != rge_base_game->get_player()->selected_obj ||
                this->sel_count != rge_base_game->get_player()->sel_count) {
                this->object_panel->set_object(rge_base_game->get_player()->selected_obj);
                this->object_changed();
            }

            color_log(0x24, 0x54, 5);

            if (start_paused == 0 && (game_state == 1 || this->world->players[this->world->curr_player]->game_status == 2 || this->player_quit == 1)) {
                if (static_cast<unsigned char>(mode) != ProgModeGameOver) {
                    color_log(0x24, 0x45, 5);
                    this->command_cancel();
                    this->command_unselect();
                    this->text_line_panel->remove_message();
                    this->message_panel->remove_message();
                    this->message_panel2->remove_message();
                    this->message_panel3->remove_message();
                    this->message_panel4->remove_message();
                    this->message_panel5->remove_message();
                    this->message_panel6->remove_message();
                    rge_base_game->set_prog_mode(ProgModeGameOver);

                    if (panel_system.mouseOwner() != 0) {
                        panel_system.mouseOwner()->release_mouse();
                    }
                    panel_system.setCurrentPanel(s_Game_Screen, 0);
                    this->set_curr_child(this->main_view);
                    static_cast<TRIBE_Game*>(rge_base_game)->close_game_screens(0);

                    this->pause_text->set_active(1);
                    if (rge_base_game->get_player()->game_status == 1) {
                        this->pause_text->set_text(STRING_ID_VICTORY_MESSAGE);
                    } else {
                        this->pause_text->set_text(STRING_ID_DEFEAT_MESSAGE);
                    }
                    this->main_view->set_redraw(TPanel::RedrawNormal);

                    if (rge_base_game->prog_info->use_sound != 0 && rge_base_game->sound_system != 0) {
                        if (this->game_over_sound != 0) {
                            delete this->game_over_sound;
                        }

                        if (rge_base_game->get_player()->game_status == 1) {
                            this->game_over_sound = new TDigital(rge_base_game->sound_system, "won.wav", 0xc490);
                        } else {
                            this->game_over_sound = new TDigital(rge_base_game->sound_system, "lost.wav", 0xc491);
                        }

                        if (this->game_over_sound != 0) {
                            this->game_over_sound->load(0, -1);
                            this->game_over_sound->play();
                        }
                    }

                    this->game_over_time = debug_timeGetTime(s_scr_game_cpp, 1836);
                    this->showing_game_over = 1;
                } else if (this->showing_game_over != 0) {
                    if (debug_timeGetTime(s_scr_game_cpp, 1844) - this->game_over_time > 5000) {
                        color_log(0x24, 0x16, 5);
                        this->showing_game_over = 0;

                        if (!rge_base_game->multiplayerGame()) {
                            this->main_view->end_scroll_view();
                            this->main_view->set_selection_area(-1, -1, -1, -1);
                            rge_base_game->set_game_mode(0, 0);
                            this->command_unselect();
                            static_cast<TRIBE_Game*>(rge_base_game)->do_game_over();
                            color_log(0x24, 0x5f, 5);
                            return;
                        }

                        if (!rge_base_game->get_paused()) {
                            this->pause_text->set_active(0);
                        }
                        rge_base_game->set_map_visible(1);
                        rge_base_game->set_map_fog(0);
                        this->main_view->set_redraw(TPanel::RedrawImmediate);
                        this->map_view->set_redraw(TPanel::RedrawImmediate);
                        this->quit_message_panel->set_active(1);
                        this->pop_panel->set_active(0);
                    }
                } else {
                    int player_index = 1;
                    while (player_index < this->world->player_num) {
                        if (this->world->players[player_index]->game_status == 0) {
                            break;
                        }
                        ++player_index;
                    }
                }
            }

            if (this->world->world_time_delta != 0) {
                unsigned long auto_exit_time = static_cast<TRIBE_Game*>(rge_base_game)->auto_exit_time;
                if (auto_exit_time != 0 && this->world->world_time >= auto_exit_time) {
                    rge_base_game->close();
                    color_log(0x24, 0x5f, 5);
                    return;
                }
            }

            update_counter += this->world->world_time_delta;
        }
    }

    if (panel_system.currentPanel() == this) {
        color_log(0x16, 0x4c, 5);
        calc_game_time = debug_timeGetTime(s_scr_game_cpp, 1948);

        if (update_counter != 0) {
            if (static_cast<long>(rge_base_game->get_player()->attributes[6]) != this->save_age) {
                this->age_changed();
            }

            if (this->score_panel[0] != 0 && this->score_panel[0]->active != 0 &&
                calc_game_time - this->last_score_time >= this->score_interval) {
                this->reset_score_display();
                this->last_score_time = debug_timeGetTime(s_scr_game_cpp, 1960);
            }
        }

        if (this->main_view->get_focus() != 0 || this->curr_child == panel_system.panel(s_Send_Quick_Message_Dialog) ||
            this->curr_child == panel_system.panel(s_Help_Dialog)) {
            color_log(0x16, 0x54, 5);

            if (update_counter != 0 || calc_game_time - this->last_view_time >= this->view_interval) {
                this->main_view->set_redraw(TPanel::RedrawNormal);
                this->last_view_time = calc_game_time;
            }
            if (update_counter != 0 && calc_game_time - this->last_map_redraw_time >= this->map_redraw_interval) {
                this->map_view->set_redraw(TPanel::RedrawNormal);
                this->last_map_redraw_time = calc_game_time;
            }

            color_log(0x16, 0x24, 5);
            if (this->main_view->need_redraw != 0) {
                rge_base_game->draw_window();
            }
        }
    }

    color_log(0x24, 0x5f, 5);
}

long TRIBE_Screen_Game::wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    if (msg == WM_SYSKEYDOWN && wParam == VK_F10 && this->have_focus != 0 && this->curr_child == this->main_view) {
        this->command_menu();
        return 1;
    }

    if (msg == WM_KEYUP && this->have_focus != 0 && this->main_view->get_focus() != 0) {
        if (wParam == 0x72 || wParam == 0x13) {
            short (__stdcall *get_key_state)(int) = GetKeyState;
            int alt = get_key_state(VK_MENU) < 0;
            int ctrl = get_key_state(VK_CONTROL) < 0;
            int shift = get_key_state(VK_SHIFT) < 0;
            if (alt == 0 && ctrl == 0 && shift == 0) {
                this->command_pause();
            }
        }
    } else if (msg == WM_CLOSE) {
        if (confirmed_close == 0) {
            confirmed_close = 1;
            int mode = rge_base_game->prog_mode;
            if (mode == ProgModeGameOver || mode == ProgModeGame ||
                mode == ProgModeGameTempPaused || mode == ProgModeScenarioEditor) {
                if (IsIconic(this->render_area->Wnd) == 0) {
                    this->popupYesNoDialog(STRING_ID_CONFIRM_QUIT_GAME, "CloseProgramDialog", TEASY_POPUP_WIDTH, 100);
                    return 1;
                }
            }
        }
    } else if (msg == WM_MBUTTONUP) {
        static_cast<TRIBE_Game*>(rge_base_game)->goto_notification_loc();
    }

    return TPanel::wnd_proc(hwnd, msg, wParam, lParam);
}

long TRIBE_Screen_Game::handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key) {
    message_panel->remove_message();
    message_panel2->remove_message();
    message_panel3->remove_message();
    message_panel4->remove_message();
    message_panel5->remove_message();
    message_panel6->remove_message();
    return TEasy_Panel::handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
}

long TRIBE_Screen_Game::handle_user_command(unsigned int wParam, long lParam) {
    return TPanel::handle_user_command(wParam, lParam);
}

void TRIBE_Screen_Game::handle_pause(void) {
    this->pause_text->set_text(STRING_ID_GAME_PAUSED);
    if (this->pause_text->active == 0) {
        this->pause_text->set_active(1);
        this->pause_text->set_redraw(TPanel::RedrawNormal);
    }
    this->main_view->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Screen_Game::handle_resume(void) {
    if (this->pause_text->active != 0) {
        this->pause_text->set_active(0);
        this->pause_text->set_redraw(TPanel::RedrawNormal);
        this->main_view->set_redraw(TPanel::RedrawNormal);
    }
}

void TRIBE_Screen_Game::handleChatReceived(int line_no) {
    char chat_msg[256];

    strcpy(chat_msg, chat->GetChatMsg(line_no));
    L->Log("$$$ RECEIVED CHAT @%u: %s", this->world->world_time, chat_msg);
    this->chat_panel[this->chat_line]->show_message(
        TMessagePanel::ChatMessage, chat_msg, TMessagePanel::WhiteColor, 0, 0, 0, 0);

    this->chat_line++;
    if (this->chat_line >= 8) {
        this->chat_line = 0;
    }
}

void TRIBE_Screen_Game::display_system_message(char* msg) {
    this->chat_panel[this->chat_line]->show_message(TMessagePanel::ChatMessage, msg, TMessagePanel::WhiteColor, 0, 0, 0, 0);
    this->chat_line++;
    if (this->chat_line >= 8) {
        this->chat_line = 0;
    }
}

long TRIBE_Screen_Game::key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key) {
    int game_over;
    long result;
    char str[512];

    if (panel_system.modalPanel() != 0) {
        return 0;
    }

    RGE_Panel_Tool_Box* tool_box = this->tool_box;
    if (tool_box->active != 0 && tool_box->key_down_action(key, count, alt_key, ctrl_key, shift_key) != 0) {
        return 1;
    }

    game_over = (rge_base_game->prog_mode == ProgModeGameOver);

    if (ctrl_key != 0 && shift_key != 0 && alt_key != 0) {
        if (game_over == 0) {
            if ((key <= 0x7A) && (key >= 0x61)) {
                key -= 0x20;
            } else if (((key > 0x5A) || (key < 0x41)) && ((key < 0x30) || (key > 0x39))) {
                key = 0;
            }

            if (key != 0) {
                if (this->cheat_code_entry == 0x32) {
                    this->cheat_code_entry_str[0x32] = static_cast<char>(key);
                    memcpy(this->cheat_code_entry_str, this->cheat_code_entry_str + 1, 51);
                } else {
                    this->cheat_code_entry_str[this->cheat_code_entry] = static_cast<char>(key);
                    this->cheat_code_entry++;
                    this->cheat_code_entry_str[this->cheat_code_entry] = 0;
                }

                if (rge_base_game->processCheatCode(this->world->curr_player, this->cheat_code_entry_str) != 0) {
                    this->cheat_code_entry = 0;
                    this->cheat_code_entry_str[0] = 0;
                    return 1;
                }
            }
        }
        return 1;
    }

    if (rge_base_game->gameDeveloperMode() != 0 && comm->IsHost() != 0) {
        if (ctrl_key != 0 && shift_key != 0 && key >= 0x32 && key <= 0x38) {
            comm->Kick(key - 0x30);
            return 1;
        }
    }
    if (ctrl_key != 0 && key >= 0x30 && key <= 0x39) {
        key -= 0x30;
        this->command_group_by_number(static_cast<int>(key));
        return 1;
    }

    if (shift_key != 0) {
        switch (key) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
            key -= 0x30;
            this->command_select_group(static_cast<int>(key), 0);
            return 1;
        case 0x70:
            this->setup_popup_help();
            return 1;
        case 0x71:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(0);
            }
            return 1;
        case 0x72:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(1);
            }
            return 1;
        case 0x73:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(2);
            }
            return 1;
        case 0x74:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(3);
            }
            return 1;
        case 0x75:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(4);
            }
            return 1;
        case 0x76:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(5);
            }
            return 1;
        case 9:
            this->command_tab_selected(0);
            return 1;
        default:
            break;
        }
    }

    // Ctrl and Alt 0x49 use different game fields.
    if (alt_key != 0) {
        switch (key) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
            key -= 0x30;
            this->command_select_group(static_cast<int>(key), 1);
            this->command_view_selected();
            return 1;
        case 0x49:
            if (rge_base_game->gameDeveloperMode() != 0) {
                rge_base_game->display_selected_ids =
                    (rge_base_game->display_selected_ids == 0);
            }
            return 1;
        case 0x50:
            if (rge_base_game->gameDeveloperMode() != 0) {
                MapPathsDisplay = (MapPathsDisplay == 0);
            }
            return 1;
        case 0x53:
            if (rge_base_game->gameDeveloperMode() != 0) {
                view_debug_spans = (view_debug_spans == 0);
            }
            return 1;
        case 0x43:
            if (rge_base_game->gameDeveloperMode() != 0) {
                view_debug_redraw_all = 1;
            }
            return 1;
        case 0x4F:
            if (rge_base_game->gameDeveloperMode() != 0) {
                view_debug_ObstructionMap = (view_debug_ObstructionMap == 0);
            }
            return 1;
        case 0x41:
            if (rge_base_game->gameDeveloperMode() != 0) {
                view_debug_Objects = (view_debug_Objects == 0);
            }
            return 1;
        case 0x58:
            if (rge_base_game->gameDeveloperMode() != 0) {
                view_debug_palette = (view_debug_palette == 0);
            }
            return 1;
        default:
            return 0;
        }
    }

    result = 1;
    if (ctrl_key == 0) {
        if (rge_base_game->get_paused() == 0 && rge_base_game->game_mode == 6 && rge_base_game->sub_game_mode == 1) {
            for (int i = 0; i < this->item_cnt; ++i) {
                RGE_Master_Static_Object* master =
                    rge_base_game->get_player()->master_objects[
                        this->bldg_list[i].id];
                if (key == *this->get_string(master->hotkey_id)) {
                    TDigital* sound = rge_base_game->get_sound(1);
                    if (sound != 0) {
                        sound->play();
                    }
                    this->command_building(this->bldg_list[i].id);
                    return 1;
                }
            }
        }
    }

    if (ctrl_key != 0) {
        int i = 0;
        long* hotkey = this->select_building_hotkey;
        while (i < 8) {
            if (key == *hotkey) {
                this->command_select_building(i);
                return result;
            }
            ++i;
            ++hotkey;
        }
    }

    if (this->view_town_center_hotkey != 0 && key == this->view_town_center_hotkey) {
        this->command_select_building(0);
        return 0;
    }

    if (ctrl_key != 0) {
        if (rge_base_game->gameDeveloperMode() == 0) {
            return 0;
        }

        switch (key) {
        case 0x70:
            this->command_player(1);
            return result;
        case 0x71:
            this->command_player(2);
            return result;
        case 0x72:
            this->command_player(3);
            return result;
        case 0x73:
            this->command_player(4);
            return result;
        case 0x74:
            this->command_player(5);
            return result;
        case 0x75:
            this->command_player(6);
            return result;
        case 0x76:
            this->command_player(7);
            return result;
        case 0x77:
            this->command_player(8);
            return result;
        case 0x78:
            this->command_player(0);
            return result;
        case 0x20:
            this->command_view_selected();
            break;
        case 0x45:
            new TribeSaveGameScreen(TribeSaveGameScreen::SaveGame, 0, 0);
            panel_system.setCurrentPanel(s_Save_Game_Screen, 0);
            break;
        case 0x46:
            if (allow_user_commands != 0) {
                this->command_add_attribute(0);
            }
            break;
        case 0x47:
            if (allow_user_commands != 0) {
                this->command_add_attribute(3);
            }
            break;
        case 0x49:
            static_cast<TRIBE_Game*>(rge_base_game)->show_object_id =
                (static_cast<TRIBE_Game*>(rge_base_game)->show_object_id == 0);
            this->object_panel->set_redraw(static_cast<TPanel::RedrawMode>(result));
            return 0;
        case 0x4A:
            comm->TXDebugPing();
            break;
        case 0x4D: {
            sprintf(str, "Writing out memory info (%d)...", ++memory_dump_sequence);
            TRIBE_Game* game = static_cast<TRIBE_Game*>(rge_base_game);
            game->show_status_message(str, 0, -1);
            sprintf(str, "c:\\mem%d.txt", memory_dump_sequence);
            rge_base_game->dump_memory_usage(str);
            static_cast<TRIBE_Game*>(rge_base_game)->close_status_message();
            break;
        }
        case 0x4E:
            if (rge_base_game->multiplayerGame() == 0) {
                static_cast<TRIBE_Game*>(rge_base_game)->restart_game();
            }
            break;
        case 0x4F:
            if (rge_base_game->outline_type != 3) {
                rge_base_game->outline_type = 3;
                return result;
            }
            rge_base_game->outline_type = 2;
            return result;
        case 0x51:
            if (allow_user_commands != 0) {
                this->command_quick_build();
            }
            break;
        case 0x52:
            ++View_Grid_Mode;
            if (rge_base_game->gameDeveloperMode() != 0) {
                if (View_Grid_Mode > 4) {
                    View_Grid_Mode = 0;
                }
            } else if (View_Grid_Mode > result) {
                View_Grid_Mode = 0;
            }
            this->main_view->set_redraw(TPanel::RedrawImmediate);
            return 0;
        case 0x53:
            if (allow_user_commands != 0) {
                this->command_add_attribute(2);
            }
            break;
        case 0x54:
            this->command_tool_box();
            break;
        case 0x55:
            if (rge_base_game->gameDeveloperMode() != 0 && rge_base_game->check_prog_argument("ALLOWCTRLU") != 0) {
                L->Log("*** !!! %%% USER PRESSED CTRL-U TO FORCE OUT OF SYNC %%% !!! ***");
                displayPathingFlags = (displayPathingFlags == 0);
            }
            break;
        case 0x56:
            new TribeSaveGameScreen(TribeSaveGameScreen::SaveScenario, 0, 0);
            panel_system.setCurrentPanel(s_Save_Game_Screen, 0);
            break;
        case 0x57:
            if (allow_user_commands != 0) {
                this->command_add_attribute(1);
            }
            break;
        case 0x58:
            if (allow_user_commands != 0) {
                rge_base_game->get_player()->kickAI(result);
            }
            break;
        case 0x59:
            if (allow_user_commands != 0) {
                rge_base_game->get_player()->kickAI(2);
            }
            break;
        case 0x5A:
            if (allow_user_commands != 0) {
                rge_base_game->get_player()->kickAI(3);
            }
            break;
        default:
            break;
        }
    } else {
        if (rge_base_game->game_mode != 6 || rge_base_game->sub_game_mode != 1) {
            // a matched work key returns; a miss reaches the next switch.
            if (this->work_hotkey != 0 && key == this->work_hotkey && game_over == 0) {
                if (allow_user_commands != 0) {
                    this->command_work();
                }
                return 0;
            } else if (this->move_hotkey != 0 && key == this->move_hotkey && game_over == 0) {
                if (allow_user_commands != 0) {
                    this->command_move();
                }
                return 0;
            } else if (this->attack_hotkey != 0 && key == this->attack_hotkey && game_over == 0) {
                if (allow_user_commands != 0) {
                    this->command_attack();
                }
                return 0;
            } else if (this->ungroup_hotkey != 0 && key == this->ungroup_hotkey) {
                this->command_ungroup();
                return 0;
            }
        }

        // this switch is after the work-key fall-through blocks.
        switch (key) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
            key = key + (-0x30);
            this->command_select_group(static_cast<int>(key), result);
            break;
        case 9:
            this->command_tab_selected(result);
            return result;
        case 0x73:
            this->command_score(this->world->score_displayed == 0);
            break;
        case 0x74:
            this->command_fps();
            break;
        case 0x75:
            if (rge_base_game->gameDeveloperMode() != 0) {
                this->command_visibility();
            }
            break;
        case 0x76:
            if (rge_base_game->gameDeveloperMode() != 0) {
                this->command_fog_of_war();
            }
            break;
        case 0x77:
            if (rge_base_game->gameDeveloperMode() != 0) {
                this->command_comm_info();
            }
            break;
        case 0x78:
            if (rge_base_game->gameDeveloperMode() != 0) {
                this->command_ai_info();
            }
            break;
        case 0x7A:
            if (this->time_panel->get_clock_type() == 0) {
                this->time_panel->set_clock_type(2, 0);
                this->pop_panel->set_active(result);
            } else {
                this->time_panel->set_clock_type(0, 0);
                this->pop_panel->set_active(0);
            }
                this->reset_clocks();
                this->main_view->set_redraw(static_cast<TPanel::RedrawMode>(result));
                return 0;
        case 0x20:
            this->command_view_selected();
            break;
        case 0x0D:
            this->command_quick_chat();
            break;
        case 0x24:
            static_cast<TRIBE_Game*>(rge_base_game)->goto_notification_loc();
            break;
        case 0x2E:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_cancel_building();
            }
            break;
        default:
            break;
        }

        return 0;
    }

    return 0;
}

long TRIBE_Screen_Game::char_action(long key, short count) {
    static_cast<void>(count);
    switch (key) {
    case 0x2B:
    case 0x3D:
        if (allow_user_commands != 0) {
            this->command_game_speed(1);
        }
        return 0;
    case 0x2D:
        if (allow_user_commands != 0) {
            this->command_game_speed(0);
        }
        return 0;
    default:
        return 0;
    }
}

long TRIBE_Screen_Game::action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2) {
    RGE_Panel_Tool_Box* tool_box;
    RGE_Base_Game* cleanup_game;

    if (from_panel == 0) {
        goto null_base_action;
    }

    tool_box = this->tool_box;
    if (from_panel != tool_box && tool_box->active != 0 &&
        tool_box->action(from_panel, action_in, action_val1, action_val2) != 0) {
        return 1;
    }

    if (action_in == 1 || action_in == 4) {
        for (int i = 0; i < 17; ++i) {
            if (from_panel == this->button_panel[i]) {
                this->do_button_action(action_val1, action_val2, action_in == 4);
                return 1;
            }
        }
    }

    if (from_panel == this->object_panel && action_in == 1) {
        this->object_changed();
        return 1;
    }

    if (from_panel->panelName() == 0) {
        goto named_base_action;
    }

    if (strcmp(from_panel->panelName(), "RestartDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("RestartDialog");
        cleanup_game = rge_base_game;
        if (action_in != 0) {
            goto pause_loaded;
        }
        static_cast<TRIBE_Game*>(cleanup_game)->restart_game();
        return 1;
    } else if (strcmp(from_panel->panelName(), "QuitGameDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("QuitGameDialog");
        if (action_in == 0) {
            static_cast<TRIBE_Game*>(rge_base_game)->do_game_over();
            return 1;
        }
        goto clear_cleanup;
    } else if (strcmp(from_panel->panelName(), "CloseProgramDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("CloseProgramDialog");
        if (action_in == 0) {
            rge_base_game->close();
            return 1;
        }
        goto clear_cleanup;
    } else if (strcmp(from_panel->panelName(), "ResignDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("ResignDialog");
        if (action_in == 0) {
            this->player_quit = 1;
            RGE_Player* player = rge_base_game->get_player();
            player->command_resign(comm->WhoAmI(), action_in);
            return 1;
        }
        goto pause_cleanup;
    } else if (strcmp(from_panel->panelName(), "QuitAndLoadDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("QuitAndLoadDialog");
        if (action_in == 0) {
            new TribeLoadSavedGameScreen();
            panel_system.setCurrentPanel("Load Saved Game Screen", 0);
            return 1;
        }
        goto pause_cleanup;
    } else {
        goto named_base_action;
    }

pause_cleanup:
    cleanup_game = rge_base_game;
pause_loaded:
    if (cleanup_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
        rge_base_game->set_paused(0, 0);
    }
    goto finish;

clear_cleanup:
    confirmed_close = 0;
    if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
        rge_base_game->set_paused(0, 0);
        return 1;
    }

finish:

    return 1;

null_base_action:
    return TEasy_Panel::action(from_panel, action_in, action_val1, action_val2);

named_base_action:
    return TEasy_Panel::action(from_panel, action_in, action_val1, action_val2);
}

void TRIBE_Screen_Game::do_button_action(int action_in, int action2_in, int right_btn) {
    if (allow_user_commands != 0) {
        switch (action_in) {
        case 1:
            this->command_work();
            return;
        case 2:
            this->command_move();
            return;
        case 3:
            this->command_build();
            return;
        case 4:
            this->command_trade();
            return;
        case 5:
            this->command_stop();
            return;
        case 6:
            this->command_unselect();
            return;
        case 7:
            this->command_unload();
            return;
        case 8:
            this->command_group();
            return;
        case 9:
            this->command_ungroup();
            return;
        case 0xB:
            this->command_cancel();
            return;
        case 0xC:
            this->command_more();
            return;
        case 0xD:
            this->command_chat();
            return;
        case 0xE:
            this->command_diplomacy();
            return;
        case 0xF:
            this->command_menu();
            return;
        case 0x10:
            this->command_trade_with(action2_in);
            return;
        case 0x11:
            this->command_research(action2_in);
            return;
        case 0x12:
            this->command_train(action2_in, right_btn ? -1 : 1);
            return;
        case 0x13:
            this->command_building(action2_in);
            return;
        case 0x14:
            this->command_cancel_building();
            return;
        case 0x15:
            this->setup_popup_help();
            return;
        case 0x16:
            this->command_stand_ground();
            return;
        case 0x17:
            this->command_attack_ground();
            return;
        case 0x18:
            this->command_score(this->world->score_displayed == 0);
            return;
        case 0x19:
            this->command_trade_attribute(0);
            return;
        case 0x1A:
            this->command_trade_attribute(1);
            return;
        case 0x1B:
            this->command_trade_attribute(2);
            return;
        case 0x1C:
            this->command_heal();
            return;
        case 0x1D:
            this->command_convert();
            return;
        case 0x1E:
            this->command_attack();
            return;
        case 0x1F:
            this->command_repair();
            return;
        case 0x20:
            this->command_train(action2_in, 1);
            return;
        case 0x21:
            this->command_train(action2_in, -1);
            return;
        default:
            return;
        }
    }

    switch (action_in) {
    case 6:
        this->command_unselect();
        return;
    case 8:
        this->command_group();
        return;
    case 9:
        this->command_ungroup();
        return;
    case 0xB:
        this->command_cancel();
        return;
    case 0xC:
        this->command_more();
        return;
    case 0xD:
        this->command_chat();
        return;
    case 0xE:
        this->command_diplomacy();
        return;
    case 0xF:
        this->command_menu();
        return;
    case 0x15:
        this->setup_popup_help();
        return;
    case 0x18:
        this->command_score(this->world->score_displayed == 0);
        return;
    default:
        return;
    }
}

void TRIBE_Screen_Game::game_mode_changed(int old_mode, int new_mode) {
    if (this->tool_box != 0) {
        this->tool_box->game_mode_changed(old_mode, new_mode);
    }
    if (this->button_panel[0] != 0) {
        this->reset_buttons();
    }
}

void TRIBE_Screen_Game::player_changed(int old_player_id, int new_player_id) {
    char str[512];
    RGE_Player* player = rge_base_game->get_player();

    this->main_view->set_player(player);
    this->map_view->set_player(player);
    this->inven_panel->set_player(static_cast<TRIBE_Player*>(player));
    this->object_panel->set_player(static_cast<TRIBE_Player*>(player));

    this->game_mode_changed(rge_base_game->game_mode, rge_base_game->game_mode);
    this->object_changed();
    this->age_changed();

    if (player->id != 0) {
        if (player->culture != this->save_culture || this->pnl_wid != this->save_screen_width) {
            int culture = player->culture;
            this->save_culture = player->culture;
            this->save_screen_width = this->pnl_wid;

            if (culture >= 5) {
                culture = 0;
            }

            sprintf(str, s_dlg6_format, culture);

            if (culture == 4) {
                this->set_info_file(str, 0xCF08);
                this->set_popup_info_file(str, 0xCF08);
            } else {
                this->set_info_file(str, culture + 0xC356);
                this->set_popup_info_file(str, culture + 0xC356);
            }

            sprintf(str, s_btn6_format, culture);

            if (culture == 4) {
                this->set_button_pics(str, 0xCF0C);
            } else {
                this->set_button_pics(str, culture + 0xC5AD);
            }

            switch (culture) {
            case 0:
                this->set_bevel_colors(0x7E, 0x6D, 0x6F, 0x6F, 0xEE, 0x38);
                break;
            case 1:
                this->set_bevel_colors(0x72, 0x73, 0x74, 0x74, 0xB7, 0xB8);
                break;
            case 2:
                this->set_bevel_colors(0xB9, 0x77, 0x78, 0x78, 0x78, 0x79);
                break;
            case 3:
                this->set_bevel_colors(0x8A, 0xED, 0xEE, 0xEE, 0x38, 0x95);
                break;
            case 4:
                this->set_bevel_colors(0x73, 0x74, 0x75, 0x75, 0x76, 0x77);
                break;
            }

            this->button_panel[12]->set_bevel_info(3, this->bevel_color1,
                                                   this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            this->button_panel[13]->set_bevel_info(3, this->bevel_color1,
                                                   this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            this->button_panel[14]->set_bevel_info(3, this->bevel_color1,
                                                   this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            this->button_panel[15]->set_bevel_info(4, this->bevel_color1,
                                                   this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            this->button_panel[16]->set_bevel_info(4, this->bevel_color1,
                                                   this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);

            if (this->button_border1_pic != 0) {
                delete this->button_border1_pic;
            }
            sprintf(str, s_button_border_a_format, culture);
            if (culture == 4) {
                this->button_border1_pic = new TShape(str, 0xCF0E);
            } else {
                this->button_border1_pic = new TShape(str, culture + 0xC619);
            }

            if (this->button_other_pic != 0) {
                delete this->button_other_pic;
            }
            sprintf(str, s_button_other_format, culture);
            if (culture == 4) {
                this->button_other_pic = new TShape(str, 0xCF11);
            } else {
                this->button_other_pic = new TShape(str, culture + 0xC625);
            }

            if (this->button_border2_pic != 0) {
                delete this->button_border2_pic;
            }
            sprintf(str, s_button_border_b_format, culture);
            if (culture == 4) {
                this->button_border2_pic = new TShape(str, 0xCF0F);
            } else {
                this->button_border2_pic = new TShape(str, culture + 0xC61D);
            }

            if (this->button_border3_pic != 0) {
                delete this->button_border3_pic;
            }
            sprintf(str, s_button_border_c_format, culture);
            if (culture == 4) {
                this->button_border3_pic = new TShape(str, 0xCF10);
            } else {
                this->button_border3_pic = new TShape(str, culture + 0xC63B);
            }

            if (this->game_screen_pic != 0) {
                delete this->game_screen_pic;
            }

            int game_pic_id;
            if (this->pnl_wid >= 1024 && this->pnl_hgt >= 768) {
                sprintf(str, s_game_c_format, culture);
                if (culture == 4) {
                    game_pic_id = 0xCF14;
                } else {
                    game_pic_id = culture + 0xC635;
                }
            } else if (this->pnl_wid >= 800 && this->pnl_hgt >= 600) {
                sprintf(str, s_game_b_format, culture);
                if (culture == 4) {
                    game_pic_id = 0xCF13;
                } else {
                    game_pic_id = culture + 0xC631;
                }
            } else {
                sprintf(str, s_game_a_format, culture);
                if (culture == 4) {
                    game_pic_id = 0xCF12;
                } else {
                    game_pic_id = culture + 0xC62D;
                }
            }
            this->game_screen_pic = new TShape(str, game_pic_id);

            for (int i = 0; i < 0x11; ++i) {
                this->button_panel[i]->border_pic =
                    (i < 0x0C) ? this->button_border1_pic : this->button_border2_pic;
            }

            if (this->pnl_wid >= 800 && this->pnl_hgt >= 600) {
                this->more_cancel_pic = this->button_cmd_pic;
            } else {
                this->more_cancel_pic = this->button_other_pic;
            }

            this->button_panel[5]->set_picture(0, this->more_cancel_pic, this->more_frame);
            if (this->button_panel[11]->get_id() == 6) {
                this->button_panel[11]->set_picture(0, this->more_cancel_pic, this->unselect_frame);
            } else {
                this->button_panel[11]->set_picture(0, this->more_cancel_pic, this->cancel_frame);
            }

            if (culture == 2 || culture == 3 || culture == 4) {
                this->inven_panel->set_text_color(0xFFFFFF, 0);
                this->age_panel->set_text_color(0xFFFFFF, 0);
                this->button_panel[12]->set_text_color(0, 0xFFFFFF, 0);
                this->button_panel[13]->set_text_color(0, 0xFFFFFF, 0);
                this->button_panel[14]->set_text_color(0, 0xFFFFFF, 0);
                this->button_panel[15]->set_text_color(0, 0xFFFFFF, 0);
                this->button_panel[16]->set_text_color(0, 0xFFFFFF, 0);
            } else {
                this->inven_panel->set_text_color(0, 0xFFFFFF);
                this->age_panel->set_text_color(0, 0xFFFFFF);
                this->button_panel[12]->set_text_color(0, 0, 0xFFFFFF);
                this->button_panel[13]->set_text_color(0, 0, 0xFFFFFF);
                this->button_panel[14]->set_text_color(0, 0, 0xFFFFFF);
                this->button_panel[15]->set_text_color(0, 0, 0xFFFFFF);
                this->button_panel[16]->set_text_color(0, 0, 0xFFFFFF);
            }
        }
    }

    this->setup_buttons();
    this->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Screen_Game::object_changed(void) {
    int changed = this->game_obj != rge_base_game->get_player()->selected_obj;
    this->game_obj = rge_base_game->get_player()->selected_obj;
    this->sel_count = rge_base_game->get_player()->sel_count;

    if (changed != 0) {
        if (rge_base_game->game_mode == 0x15) {
            this->main_view->end_scroll_view();
            this->main_view->set_selection_area(-1, -1, -1, -1);
        }

        int mode = rge_base_game->game_mode;
        if (static_cast<char>(mode) != 1 && static_cast<char>(mode) != 0x12 && static_cast<char>(mode) != 0x0E &&
            static_cast<char>(mode) != 2 && static_cast<char>(mode) != 3 && static_cast<char>(mode) != 8 &&
            static_cast<char>(mode) != 9 && static_cast<char>(mode) != 0x0A) {
            rge_base_game->set_game_mode(0, 0);
        }
    }

    this->reset_buttons();
}

void TRIBE_Screen_Game::age_changed() {
    char str[512];

    if (this->age_panel != 0) {
        RGE_Player* player = rge_base_game->get_player();
        this->save_age = player->attributes[6];
        rge_base_game->get_string2(RGE_STRING_TYPE_AGE, this->save_age, 0, str, 512);
        this->age_panel->set_text(str);
        this->age_panel->set_redraw(TPanel::RedrawNormal);

        switch (this->save_age) {
        case 1:
            this->age_panel->set_help_info(STRING_ID_HELP_AGE_STONE, -1);
            break;
        case 2:
            this->age_panel->set_help_info(STRING_ID_HELP_AGE_TOOL, -1);
            break;
        case 3:
            this->age_panel->set_help_info(STRING_ID_HELP_AGE_BRONZE, -1);
            break;
        case 4:
            this->age_panel->set_help_info(STRING_ID_HELP_AGE_IRON, -1);
            break;
        }
    }
}

void TRIBE_Screen_Game::show_timings(char* str1, char* str2) {
    char* current = this->fps_panel->get_text();
    if (current == 0 || strcmp(current, str2) != 0) {
        this->fps_panel->set_text(str2);
    }
}

void TRIBE_Screen_Game::show_comm(char* str, char* str2, char* str3, char* str4, char* str5, char* str6) {
    message_panel->show_message(TMessagePanel::DebugMessage, str, TMessagePanel::DebugColor, 0, 0, 0, 0);
    message_panel2->show_message(TMessagePanel::DebugMessage, str2, TMessagePanel::DebugColor, 0, 0, 0, 0);
    message_panel3->show_message(TMessagePanel::DebugMessage, str3, TMessagePanel::DebugColor, 0, 0, 0, 0);
    message_panel4->show_message(TMessagePanel::DebugMessage, str4, TMessagePanel::DebugColor, 0, 0, 0, 0);
    message_panel5->show_message(TMessagePanel::DebugMessage, str5, TMessagePanel::DebugColor, 0, 0, 0, 0);
    message_panel6->show_message(TMessagePanel::DebugMessage, str6, TMessagePanel::DebugColor, 0, 0, 0, 0);
}

void TRIBE_Screen_Game::show_ai(char* str, char* str2, char* str3, char* str4, char* str5, char* str6) {
    this->message_panel->show_message(TMessagePanel::DebugMessage, str, TMessagePanel::DebugColor, 0, 0, 0, 0);
    this->message_panel2->show_message(TMessagePanel::DebugMessage, str2, TMessagePanel::DebugColor, 0, 0, 0, 0);
    this->message_panel3->show_message(TMessagePanel::DebugMessage, str3, TMessagePanel::DebugColor, 0, 0, 0, 0);
    this->message_panel4->show_message(TMessagePanel::DebugMessage, str4, TMessagePanel::DebugColor, 0, 0, 0, 0);
    this->message_panel5->show_message(TMessagePanel::DebugMessage, str5, TMessagePanel::DebugColor, 0, 0, 0, 0);
    this->message_panel6->show_message(TMessagePanel::DebugMessage, str6, TMessagePanel::DebugColor, 0, 0, 0, 0);
}

void TRIBE_Screen_Game::show_message(TMessagePanel::MessageType message_type, char* str, unsigned char font_color_in, unsigned char back_color_in) {
    this->message_panel->show_message(message_type, str, font_color_in, back_color_in, 0, 0, 0);
}

void TRIBE_Screen_Game::reset_buttons() {
    this->start_item = 0;
    this->setup_buttons();
}

void TRIBE_Screen_Game::setup_buttons() {
    char name[512];
    char msg_str[512];
    TRIBE_Player* player;
    int culture;

    this->item_cnt = 0;
    this->last_item = -1;

    for (int button_index = 0; button_index < 12; ++button_index) {
        this->button_panel[button_index]->in_use = 0;
    }

    this->mouse_last_x = -1;
    this->mouse_last_y = -1;

    if (this->game_obj != 0) {
        TShape* final_pic;
        short final_frame;
        long final_type;
        bool set_final_button = false;
        player = static_cast<TRIBE_Player*>(rge_base_game->get_player());
    culture = player->culture;
    if (culture > 5) {
        culture = 0;
    }
    if ((rge_base_game->game_mode == 6) && (rge_base_game->sub_game_mode == 1)) {
        short building_count;
        short tc_num = -1;
        short range_num = -1;
        int any_more = 0;

        player->interface_item_avail(&this->bldg_list, &this->item_cnt, 0x76);
        building_count = this->item_cnt;

        for (short building_index = 0; building_index < building_count; ++building_index) {
            if (this->bldg_list[building_index].id == 0x6D) {
                tc_num = building_index;
            }
            if (this->bldg_list[building_index].id == 0x57) {
                range_num = building_index;
            }
        }

        for (short item_index = 0; item_index < this->item_cnt; ++item_index) {
            short item_id = this->bldg_list[item_index].id;
            RGE_Master_Static_Object* base_master =
                player->master_objects[item_id];
            TRIBE_Master_Building_Object* master =
                static_cast<TRIBE_Master_Building_Object*>(base_master);
            unsigned char btn_loc =
                static_cast<TRIBE_Master_Combat_Object*>(base_master)
                    ->button_location;

            if ((item_index == tc_num) && (range_num == -1)) {
                btn_loc = 6;
            }

            if (this->start_item == 0) {
                if (btn_loc > 10) {
                    any_more = 1;
                    continue;
                }
            } else if (btn_loc < 11) {
                any_more = 1;
                continue;
            }

            rge_base_game->get_string(master->string_id, name + 4, 512);
            this->calc_text_msg(msg_str + 4, &this->bldg_list[item_index], 0x13, master->string_id2);
            short button = this->calc_button_loc(btn_loc);
            Item_Avail* item = &this->bldg_list[item_index];
            this->set_button(this->button_bldg_pics[culture], button,
                             static_cast<short>(master->building_facet + item->pict), 0x13, item->id,
                             master->string_id2 + 100000, item->help_page_id, master->hotkey_id,
                             player->color_table->table, name + 4, msg_str + 4, 0);
        }

        if (any_more != 0) {
            this->set_button(this->more_cancel_pic, 5, this->more_frame, 0x0C, 0, 0x1D4D7, -1, 0, 0, 0, 0, 0);
        }

        final_pic = this->more_cancel_pic;
        final_frame = this->cancel_frame;
        final_type = 0x0B;
        set_final_button = 1;
    } else if ((rge_base_game->game_mode == 0) && (rge_base_game->prog_mode != ProgModeGameOver)) {
        if (this->game_obj->owner == player) {
            unsigned char level = player->unit_level_selected();
            int continue_setup = 1;

            if (level == 3) {
                this->set_button(this->button_cmd_pic, 0, 2, 3, 0, 0x1D4DF, -1, 0, 0, 0, 0, 0);
                this->set_button(this->button_cmd_pic, 1, 0, 0x1F, 0, 0x1D4F6, -1, 0, 0, 0, 0, 0);
                if (this->any_selected_have_action()) {
                    this->set_button(this->button_cmd_pic, 2, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                }

                if (player->sel_count > 1) {
                    this->set_button(this->button_cmd_pic, 6, 7, 8, 0, 0x1D4E1, -1, 0, 0, 0, 0, 0);
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, STRING_ID_HELP_UNGROUP_BUTTON, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
                final_pic = this->more_cancel_pic;
                final_frame = this->unselect_frame;
                final_type = 6;
                set_final_button = 1;
                continue_setup = 0;
            } else if (level == 9) {
                if (this->any_selected_have_action()) {
                    this->set_button(this->button_cmd_pic, 0, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                }
                if (player->sel_count > 1) {
                    this->set_button(this->button_cmd_pic, 6, 7, 8, 0, 0x1D4E1, -1, 0, 0, 0, 0, 0);
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
                final_pic = this->more_cancel_pic;
                final_frame = this->unselect_frame;
                final_type = 6;
                set_final_button = 1;
                continue_setup = 0;
            } else if (level == 4) {
                short selected = 0;
                int movable = 1;
                short i = 0;

                while ((selected < this->sel_count) && (i < 25)) {
                    RGE_Static_Object* object = player->sel_list[i];
                    if (object != 0) {
                        RGE_Master_Combat_Object* master =
                            static_cast<RGE_Master_Combat_Object*>(object->master_obj);
                        //! This UI gate also tests blast radius == 0 instead of blast level.
                        if ((master->missile_id == -1) || (master->area_effect_range == g_no_area_effect_range)) {
                            movable = 0;
                            break;
                        }
                        ++selected;
                    }
                    ++i;
                }

                this->set_button(this->button_cmd_pic, 0, 4, 0x16, 0, 0x1D4EA, -1, 0, 0, 0, 0, 0);
                short command_index = 1;
                if (movable) {
                    this->set_button(this->button_cmd_pic, 1, 0x0C, 0x17, 0, 0x1D4EB, -1, 0, 0, 0, 0, 0);
                    command_index = 2;
                }
                if (this->any_selected_have_action()) {
                    this->set_button(this->button_cmd_pic, command_index, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                }

                if (player->sel_count > 1) {
                    this->set_button(this->button_cmd_pic, 6, 7, 8, 0, 0x1D4E1, -1, 0, 0, 0, 0, 0);
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
                final_pic = this->more_cancel_pic;
                final_frame = this->unselect_frame;
                final_type = 6;
                set_final_button = 1;
                continue_setup = 0;
            } else if (level == 6) {
                this->set_button(this->button_cmd_pic, 0, 0x0D, 0x1C, 0, 0x1D4F1, -1, 0, 0, 0, 0, 0);
                this->set_button(this->button_cmd_pic, 1, 0x0E, 0x1D, 0, 0x1D4F2, -1, 0, 0, 0, 0, 0);
                if (this->any_selected_have_action()) {
                    this->set_button(this->button_cmd_pic, 2, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                }

                if (player->sel_count > 1) {
                    this->set_button(this->button_cmd_pic, 6, 7, 8, 0, 0x1D4E1, -1, 0, 0, 0, 0, 0);
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, STRING_ID_HELP_UNGROUP_BUTTON, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
                final_pic = this->more_cancel_pic;
                final_frame = this->unselect_frame;
                final_type = 6;
                set_final_button = 1;
                continue_setup = 0;
            } else if (level == 7) {
                short selected = 0;
                int found = 0;
                short i = 0;

                while ((selected < player->sel_count) && (i < 25)) {
                    RGE_Static_Object* object = player->sel_list[i];
                    if (object != 0) {
                        ++selected;
                        if (object->objects->number_of_objects > 0) {
                            this->set_button(this->button_cmd_pic, 0, 5, 7, 0, 0x1D4E9, -1, 0, 0, 0, 0, 0);
                            found = 1;
                            break;
                        }
                    }
                    ++i;
                }

                if (this->any_selected_have_action()) {
                    this->set_button(this->button_cmd_pic, found, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                }
                if (player->sel_count > 1) {
                    this->set_button(this->button_cmd_pic, 6, 7, 8, 0, 0x1D4E1, -1, 0, 0, 0, 0, 0);
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
                final_pic = this->more_cancel_pic;
                final_frame = this->unselect_frame;
                final_type = 6;
                set_final_button = 1;
                continue_setup = 0;
            } else if (level == 5) {
                this->set_button(this->button_tech_pic, 1, 0x57, 0x19, 0, 0x1A25C, 0x265AF, 0, 0, 0, 0, 0);
                this->set_button(this->button_tech_pic, 2, 0x56, 0x1A, 0, 0x1A25D, 0x265AF, 0, 0, 0, 0, 0);
                this->set_button(this->button_tech_pic, 3, 0x58, 0x1B, 0, 0x1A25E, 0x265AF, 0, 0, 0, 0, 0);
                if (this->any_selected_have_action()) {
                    this->set_button(this->button_cmd_pic, 0, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                }
                if (player->sel_count > 1) {
                    this->set_button(this->button_cmd_pic, 6, 7, 8, 0, 0x1D4E1, -1, 0, 0, 0, 0, 0);
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
                final_pic = this->more_cancel_pic;
                final_frame = this->unselect_frame;
                final_type = 6;
                set_final_button = 1;
                continue_setup = 0;
            } else if ((level == 2) && (this->game_obj->master_obj->master_type == 'P')) {
                TRIBE_Building_Object* building =
                    static_cast<TRIBE_Building_Object*>(this->game_obj);
                short work_type;
                short work_target;
                short progress;

                building->work_status(work_type, work_target, progress, name + 4, 0x200);
                if (progress == 100) {
                    work_type = 0;
                }

                unsigned char object_state = building->object_state;
                if (object_state < RGE_OBJECT_STATE_ACTIVE) {
                    this->set_button(this->button_cmd_pic, 0, 3, 0x14, 0, 0x1D4E5, -1, 0, 0, 0, 0, 0);
                    final_pic = this->more_cancel_pic;
                    final_frame = this->unselect_frame;
                    final_type = 6;
                    set_final_button = 1;
                    continue_setup = 0;
                } else if (object_state > RGE_OBJECT_STATE_ACTIVE) {
                    final_pic = this->more_cancel_pic;
                    final_frame = this->unselect_frame;
                    final_type = 6;
                    set_final_button = 1;
                    continue_setup = 0;
                } else if ((object_state == RGE_OBJECT_STATE_ACTIVE) && ((work_type == 0x67) || ((work_type == 0x66) &&
                             (production_queues_is_use == 0)))) {
                    this->set_button(this->button_cmd_pic, 0, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                    final_pic = this->more_cancel_pic;
                    final_frame = this->unselect_frame;
                    final_type = 6;
                    set_final_button = 1;
                    continue_setup = 0;
                } else if ((object_state == RGE_OBJECT_STATE_ACTIVE) && ((work_type != 0x66) || (production_queues_is_use != 0))) {
                    short tech_cnt;
                    short make_cnt;
                    player->interface_tech_avail(&this->tech_list, &tech_cnt, this->game_obj->master_obj->id);
                    player->interface_item_avail(&this->make_list, &make_cnt, this->game_obj->master_obj->id);
                    this->item_cnt = make_cnt + tech_cnt;

                    bool queue_active =
                        (production_queues_is_use != 0) &&
                        (building->production_queue_count > 0);
                    if (queue_active) {
                        this->set_button(this->button_cmd_pic, 6, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                    }

                    for (short make_index = 0; make_index < make_cnt; ++make_index) {
                        short item_id = this->make_list[make_index].id;
                        RGE_Master_Static_Object* base_master =
                            player->master_objects[item_id];
                        TRIBE_Master_Combat_Object* master =
                            static_cast<TRIBE_Master_Combat_Object*>(base_master);
                        int queued = 0;

                        if (queue_active) {
                            short queue_count =
                                building->production_queue_count;
                            if (queue_count > 0) {
                                Production_Queue_Record* queue =
                                    building->production_queue;
                                do {
                                    if (queue->master_id == master->id) {
                                        queued += queue->unit_count;
                                    }
                                    ++queue;
                                    --queue_count;
                                } while (queue_count != 0);
                            }
                        }

                        if ((!queue_active) || (queued > 0)) {
                            rge_base_game->get_string(master->string_id, name + 4, 512);
                            this->calc_text_msg(msg_str + 4, &this->make_list[make_index], 0x12, master->string_id2);
                            //! @bug Slot writes run with no collision check, and two location ranges map to one slot.
                            //! When a player owns both fire galley and catapult trireme, one icon overwrites the other.
                            //! The overwritten warship loses its button and cannot be trained (All techs games).
                            short button = this->calc_button_loc(master->button_location);
                            Item_Avail* item = &this->make_list[make_index];
                            this->set_button(this->button_unit_pic, button, item->pict, 0x12, item->id,
                                             master->string_id2 + 100000, item->help_page_id, master->hotkey_id,
                                             player->color_table->table, name + 4, msg_str + 4, 0);
                            if ((!queue_active) || (queued < 1)) {
                                this->button_panel[button]->set_display_garrison(0);
                            } else {
                                this->button_panel[button]->set_display_garrison(1);
                                this->button_panel[button]->set_garrison_number(queued);
                            }
                        }
                    }

                    int make_disabled = 0;
                    if (queue_active) {
                        continue_setup = 0;
                    } else {
                        if ((building->master_obj->id == 0x6D) && (tech_cnt == 0) &&
                            (static_cast<int>(rge_base_game->get_player()->attributes[6]) < 4)) {
                            short tech_id =
                                static_cast<short>(static_cast<int>(rge_base_game->get_player()->attributes[6]) + 100);
                            if (player->tech_tree->get_tech_state(tech_id) != -1) {
                                if (this->tech_list != 0) {
                                    free(this->tech_list);
                                }
                                this->tech_list = static_cast<Item_Avail*>(calloc(1, sizeof(Item_Avail)));
                                if (this->tech_list != 0) {
                                    tech_cnt = 1;
                                    make_disabled = 1;
                                    short inv_1;
                                    short inv_amt_1;
                                    short inv_2;
                                    short inv_amt_2;
                                    short inv_3;
                                    short inv_amt_3;
                                    player->tech_tree->tech_cost(tech_id, inv_1, inv_amt_1, inv_2,
                                                                 inv_amt_2, inv_3, inv_amt_3);
                                    Tech_Tree* tech =
                                        &this->world->tech->tech_tree[tech_id];
                                    this->tech_list->id = tech_id;
                                    this->tech_list->name = tech->name;
                                    this->tech_list->pict = tech->icon;
                                    this->tech_list->inventory_item_1 = inv_1;
                                    this->tech_list->inventory_cost_1 = static_cast<float>(inv_amt_1);
                                    this->tech_list->inventory_item_2 = inv_2;
                                    this->tech_list->inventory_cost_2 = static_cast<float>(inv_amt_2);
                                    this->tech_list->inventory_item_3 = inv_3;
                                    this->tech_list->inventory_cost_3 = static_cast<float>(inv_amt_3);
                                    this->tech_list->help_string_id =
                                        player->tech_tree->get_help_message(tech_id);
                                    this->tech_list->help_page_id =
                                        player->tech_tree->get_help_page(tech_id);
                                }
                            }
                        }

                        for (int tech_index = 0; tech_index < tech_cnt; ++tech_index) {
                            short item_id = this->tech_list[tech_index].id;
                            short string_id =
                                player->tech_tree->get_string_id(item_id);
                            rge_base_game->get_string(string_id, name + 4, 512);
                            short string_id2 =
                                player->tech_tree->get_string_id2(this->tech_list[tech_index].id);
                            this->calc_text_msg(msg_str + 4, &this->tech_list[tech_index], 0x11, string_id2);
                            unsigned char btn_loc =
                                player->tech_tree->get_button_location(this->tech_list[tech_index].id);
                            short button = this->calc_button_loc(btn_loc);
                            Item_Avail* item = &this->tech_list[tech_index];
                            unsigned char* color_table =
                                player->color_table->table;
                            long hotkey =
                                player->tech_tree->get_hotkey(item->id);
                            this->set_button(this->button_tech_pic, button, item->pict, 0x11, item->id,
                                             item->help_string_id, item->help_page_id, hotkey, color_table,
                                             name + 4, msg_str + 4, make_disabled);
                        }

                        if ((make_cnt == 0) && (tech_cnt == 0)) {
                            if (player->sel_count > 1) {
                                this->set_button(this->button_cmd_pic, 6, 7, 8, 0, 0x1D4E1, -1, 0, 0, 0, 0, 0);
                                this->set_button(this->button_cmd_pic, 7, 8, 9, 0, STRING_ID_HELP_UNGROUP_BUTTON, -1, 0,
                                                 0, 0, 0, 0);
                            } else if (this->game_obj->selected_group != 0) {
                                this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                            }
                        }
                        final_pic = this->more_cancel_pic;
                        final_frame = this->unselect_frame;
                        final_type = 6;
                        set_final_button = 1;
                        continue_setup = 0;
                    }
                }

            }

            if (continue_setup != 0) {
                bool special_selection =
                    (level == 0) && (player->sel_count > 1);
                bool all_moveable_units = true;
                bool have_action = false;
                if (special_selection) {
                    short selected = 0;
                    for (short j = 0; (j < 25) && (selected < player->sel_count); ++j) {
                        RGE_Action_Object* object =
                            static_cast<RGE_Action_Object*>(player->sel_list[j]);
                        if (object != 0) {
                            unsigned char object_level = object->master_obj->unit_level;
                            if ((object_level != 3) && (object_level != 9) && (object_level != 4) && (object_level != 5) &&
                                (object_level != 6) && (object_level != 7) && (object_level != 8)) {
                                all_moveable_units = false;
                                break;
                            }
                            if (!have_action) {
                                have_action = object->have_action() != 0;
                            }
                            ++selected;
                        }
                    }
                }

                int group;
                bool special_known = special_selection && all_moveable_units;
                if (special_known) {
                    group = player->is_group_selected(4);
                    if (group != 0) {
                        this->set_button(this->button_cmd_pic, 0, 2, 3, 0, 0x1D4DF, -1, 0, 0, 0, 0, 0);
                    }
                    if (have_action) {
                        this->set_button(this->button_cmd_pic, group != 0, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                    }
                } else {
                    group = player->is_group_selected(4);
                    if (group != 0) {
                        this->set_button(this->button_cmd_pic, 0, 2, 3, 0, 0x1D4DF, -1, 0, 0, 0, 0, 0);
                    }
                    if (this->any_selected_have_action()) {
                        this->set_button(this->button_cmd_pic, group != 0, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                    }
                }
                if (player->sel_count > 1) {
                    this->set_button(this->button_cmd_pic, 6, 7, 8, 0, 0x1D4E1, -1, 0, 0, 0, 0, 0);
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, special_known ? 0x1D4E3 : STRING_ID_HELP_UNGROUP_BUTTON,
                                     -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
                final_pic = this->more_cancel_pic;
                final_frame = this->unselect_frame;
                final_type = special_known ? 6 : 0x0B;
                set_final_button = 1;
            }
        } else {
            final_pic = this->more_cancel_pic;
            final_frame = this->unselect_frame;
            final_type = 6;
            set_final_button = 1;
        }

    } else {
        final_pic = this->more_cancel_pic;
        final_frame = this->cancel_frame;
        final_type = 0x0B;
        set_final_button = 1;
    }

    if (set_final_button) {
        this->set_button(final_pic, 0x0B, final_frame, final_type, 0, 0x1D4D9, -1, 0, 0, 0, 0, 0);
    }
}
    this->disable_unused_buttons();
}

// Managed pass 2026-08-17 notes:
void TRIBE_Screen_Game::disable_unused_buttons(void) {
    TRIBE_Panel_Button** button = this->button_panel;
    int button_count = 12;
    do {
        if ((*button)->in_use == 0) {
            (*button)->set_active(0);
            (*button)->set_id(0, 0, -1);
            (*button)->set_help_info(-1, -1);
        } else {
            (*button)->set_active(1);
        }
        ++button;
    } while (--button_count != 0);
}

char* TRIBE_Screen_Game::calc_text_msg(char* msg_str, Item_Avail* item, long button_action_id, long message_string_id) {
    char command_str[512];
    char cost_str3[512];
    char cost_str[512];
    char cost_str1[512];
    char cost_str2[512];
    char inven_str[512];

    rge_base_game->get_string(message_string_id, command_str, 512);
    cost_str1[0] = 0;

    if (item != 0) {
        if (item->inventory_item_1 == -1 || item->inventory_item_1 > 3) {
            cost_str2[0] = 0;
        } else {
            rge_base_game->get_string2(RGE_STRING_TYPE_INVENTORY, item->inventory_item_1, 0, cost_str3, 512);
            sprintf(cost_str2, "%s: %d", cost_str3, static_cast<int>(item->inventory_cost_1));
        }

        if (item->inventory_item_2 == -1 || item->inventory_item_2 > 3) {
            inven_str[0] = 0;
        } else {
            rge_base_game->get_string2(RGE_STRING_TYPE_INVENTORY, item->inventory_item_2, 0, cost_str3, 512);
            sprintf(inven_str, "  %s: %d", cost_str3, static_cast<int>(item->inventory_cost_2));
        }

        if (item->inventory_item_3 == -1 || item->inventory_item_3 > 3) {
            cost_str[0] = 0;
        } else {
            rge_base_game->get_string2(RGE_STRING_TYPE_INVENTORY, item->inventory_item_3, 0, cost_str3, 512);
            sprintf(cost_str, "  %s: %d", cost_str3, static_cast<int>(item->inventory_cost_3));
        }

        if (cost_str2[0] != 0 || inven_str[0] != 0 || cost_str[0] != 0) {
            sprintf(cost_str1, "(%s%s%s)", cost_str2, inven_str, cost_str);
        }
    }

    if (command_str[0] != 0 && cost_str1[0] != 0) {
        sprintf(msg_str, "%s %s", command_str, cost_str1);
    } else if (command_str[0] != 0) {
        sprintf(msg_str, "%s", command_str);
    } else {
        msg_str[0] = 0;
    }
    return msg_str;
}

short TRIBE_Screen_Game::calc_button_loc(unsigned char button_loc) {
    if (button_loc >= 1 && button_loc <= 5) {
        return button_loc - 1;
    }
    if (button_loc >= 6 && button_loc <= 10) {
        return button_loc;
    }
    if (button_loc >= 11 && button_loc <= 15) {
        return button_loc - 0xB;
    }
    if (button_loc >= 16 && button_loc <= 20) {
        return button_loc - 0xA;
    }
    return 0;
}

void TRIBE_Screen_Game::set_button(
    TShape* buttons, short button, short pic_index,
    long id, long id2, long help_string_id, long help_page_id,
    long hotkey, unsigned char* color_table,
    char* text2, char* text_msg, int make_disabled) {
    char text1[512];
    TRIBE_Panel_Button* button_panel = this->button_panel[button];

    button_panel->in_use = 1;
    if (button_panel->disabled != make_disabled) {
        button_panel->set_disabled(make_disabled);
    }

    if (button_panel->get_id() != id || button_panel->get_id2() != id2) {
        button_panel->reset();
        button_panel->set_display_garrison(0);
        rge_base_game->get_string2(RGE_STRING_TYPE_COMMAND, id, id2, text1, 512);
        button_panel->set_picture(0, buttons, pic_index);
        button_panel->set_id(0, id, id2);
        button_panel->color_table = color_table;
        button_panel->set_text(0, text1, text2);
        button_panel->set_help_info(help_string_id, help_page_id);

        if (text_msg != 0) {
            button_panel->set_text_msg(text_msg);
        } else {
            button_panel->set_text_msg(text1);
        }

        if (id == 0x11) {
            button_panel->border_frame = 2;
        } else {
            button_panel->border_frame = 0;
        }

        switch (id) {
        case 3:
            hotkey = STRING_ID_HOTKEY_BUILD;
            break;
        case 5:
            hotkey = STRING_ID_HOTKEY_STOP;
            break;
        case 8:
            hotkey = STRING_ID_HOTKEY_GROUP;
            break;
        case 9:
            hotkey = STRING_ID_HOTKEY_UNGROUP;
            break;
        case 0x0C:
            hotkey = STRING_ID_HOTKEY_MORE;
            break;
        case 0x16:
            hotkey = STRING_ID_HOTKEY_STAND_GROUND;
            break;
        case 0x17:
            hotkey = STRING_ID_HOTKEY_ATTACK_GROUND;
            break;
        case 0x1C:
            hotkey = STRING_ID_HOTKEY_HEAL;
            break;
        case 0x1D:
            hotkey = STRING_ID_HOTKEY_CONVERT;
            break;
        case 1:
            hotkey = STRING_ID_HOTKEY_WORK;
            break;
        case 2:
            hotkey = STRING_ID_HOTKEY_MOVE;
            break;
        case 0x1E:
            hotkey = STRING_ID_HOTKEY_ATTACK;
            break;
        case 0x1F:
            hotkey = STRING_ID_HOTKEY_REPAIR;
            break;
        case 7:
            hotkey = STRING_ID_HOTKEY_UNLOAD;
            break;
        }

        if (hotkey != 0) {
            hotkey = static_cast<int>(*this->get_string(hotkey));
        }
        if (id == 6 || id == 0x0B) {
            hotkey = 0x1B;
        }

        button_panel->hotkey = hotkey;
        button_panel->hotkey_shift = 0;
        button_panel->set_active(1);
    }
}

void TRIBE_Screen_Game::reset_clocks() {
    if (this->world->victory_type == 2) {
        this->countdown_clock[0]->set_clock_type(3, 0);
        return;
    }

    if (this->world->victory_type != 0) {
        return;
    }

    int player_id = 1;
    int clock_count = 0;

    if (player_id < this->world->player_num) {
        TRIBE_Panel_Time** clock = this->countdown_clock;
        do {
            long countdown_timer;
            rge_base_game->get_countdown_timer(player_id, countdown_timer);
            if (countdown_timer > 0) {
                ++clock_count;
                (*clock++)->set_clock_type(4, player_id);
                if (clock_count > 9) {
                    break;
                }
            }

            if (static_cast<TRIBE_Player*>(this->world->players[player_id]) ->artifact_held_time != -1.0f) {
                int found = 0;
                if (static_cast<TRIBE_Player*>(this->world->players[player_id]) ->allied_victory != 0) {
                    int other_player = 1;
                    for (; other_player < player_id; ++other_player) {
                        if (static_cast<TRIBE_Player*>(this->world->players[player_id]) ->relation(other_player) == 0 &&
                            this->world->players[other_player] ->relation(player_id) == 0 &&
                            this->world->players[other_player] ->allied_victory != 0) {
                            found = 1;
                            break;
                        }
                    }
                }

                if (found == 0) {
                    ++clock_count;
                    (*clock++)->set_clock_type(5, player_id);
                    if (clock_count > 9) {
                        break;
                    }
                }
            }

            if (static_cast<TRIBE_Player*>(this->world->players[player_id]) ->ruin_held_time != -1.0f) {
                int found = 0;
                if (static_cast<TRIBE_Player*>(this->world->players[player_id]) ->allied_victory != 0) {
                    int other_player = 1;
                    for (; other_player < player_id; ++other_player) {
                        if (static_cast<TRIBE_Player*>(this->world->players[player_id]) ->relation(other_player) == 0 &&
                            this->world->players[other_player] ->relation(player_id) == 0 &&
                            this->world->players[other_player] ->allied_victory != 0) {
                            found = 1;
                            break;
                        }
                    }
                }

                if (found == 0) {
                    ++clock_count;
                    (*clock++)->set_clock_type(6, player_id);
                    if (clock_count > 9) {
                        break;
                    }
                }
            }

            ++player_id;
        } while (player_id < this->world->player_num);
    }

    if (clock_count < 10) {
        TRIBE_Panel_Time** clock = &this->countdown_clock[clock_count];
        int remaining = 10 - clock_count;
        do {
            (*clock++)->set_clock_type(0, 0);
            --remaining;
        } while (remaining != 0);
    }
}

int scr_game_score_compare(const void* arg1, const void* arg2) {
    const PLAYER_SCORE* a = static_cast<const PLAYER_SCORE*>(arg2);
    const PLAYER_SCORE* b = static_cast<const PLAYER_SCORE*>(arg1);

    score_compare_left = a;
    score_compare_right = b;

    if (a->team_score > b->team_score) return 1;
    if (a->team_score < b->team_score) return -1;
    if (a->team_id > b->team_id) return 1;
    if (a->team_id < b->team_id) return -1;
    if (a->player_score > b->player_score) return 1;
    if (a->player_score < b->player_score) return -1;
    if (a->player_id > b->player_id) return 1;
    return (a->player_id >= b->player_id) - 1;
}

void TRIBE_Screen_Game::reset_score_display() {
    int player_count;
    int low_fps_player;
    int team_count;
    int team;
    int player_num;
    int icon_num2;
    TShape* icon2;
    TShape* icon1;
    PLAYER_SCORE player_score[9];
    char str[512];

    for (int i = 0; i < 9; ++i) {
        player_score[i].comm_id = 0;
        player_score[i].player_id = 0;
        player_score[i].team_id = 0;
        player_score[i].player_score = 0;
        player_score[i].team_score = 0;
    }

    player_count = 0;
    player_num = 1;
    if (player_num <= rge_base_game->numberPlayers()) {
        do {
            int player_id = rge_base_game->playerID(player_num);
            int score_index = player_num - 1;

            if (player_id != 0 && player_id < this->world->player_num) {
                if (player_score[score_index].team_id == 0) {
                    ++player_count;
                    player_score[score_index].team_id = player_count;
                }

                player_score[score_index].comm_id = player_num;
                player_score[score_index].player_id = player_id;
                long points = this->world->players[player_id]
                                  ->victory_conditions->get_victory_points();
                player_score[score_index].player_score = points;
                player_score[score_index].team_score = points;
                team_count = 1;

                if (this->world->players[player_id]->allied_victory != 0) {
                    int allied_player_num = 1;
                    if (allied_player_num <= rge_base_game->numberPlayers()) {
                        team = 0;
                        do {
                            if (allied_player_num != player_num) {
                                int allied_player_id =
                                    rge_base_game->playerID(allied_player_num);
                                if (allied_player_id != 0 && allied_player_id < this->world->player_num &&
                                    this->world->players[player_id]->relation(allied_player_id) == 0 &&
                                    this->world->players[allied_player_id]->relation(player_id) == 0 &&
                                    this->world->players[allied_player_id] ->allied_victory != 0) {
                                    int allied_score_index = allied_player_num - 1;
                                    if (player_score[allied_score_index].team_id == 0) {
                                        player_score[allied_score_index].team_id =
                                            player_score[score_index].team_id;
                                    }
                                    player_score[score_index].team_score +=
                                        this->world->players[allied_player_id]
                                            ->victory_conditions->get_victory_points();
                                    ++team_count;
                                }
                            }

                            team += sizeof(PLAYER_SCORE);
                            ++allied_player_num;
                        } while (allied_player_num <= rge_base_game->numberPlayers());
                    }
                }

                player_score[score_index].team_score /= team_count;
            }

            ++player_num;
        } while (player_num <= rge_base_game->numberPlayers());
    }

    qsort(player_score, rge_base_game->numberPlayers(), sizeof(PLAYER_SCORE), scr_game_score_compare);
    low_fps_player = 0;

    if (rge_base_game->multiplayerGame() != 0) {
        unsigned int best_speed = 0x0B;
        for (int score_index = 0; score_index < 8; ++score_index) {
            if (player_score[score_index].player_id != 0 &&
                comm->GetPlayerHumanity(player_score[score_index].comm_id) == ME_HUMAN) {
                unsigned long speed = comm->Speed->PlayerAvgFramesMsec[
                    player_score[score_index].comm_id];
                if (speed < 1000) {
                    if (speed < 10) {
                        speed = 100;
                    } else {
                        speed = 1000 / speed;
                    }
                } else {
                    speed = 1;
                }
                if (speed < best_speed) {
                    low_fps_player = player_score[score_index].comm_id;
                    best_speed = speed;
                }
            }
        }
    }

    PLAYER_SCORE* score = player_score;
    TMessagePanel** score_panel = this->score_panel;
    for (icon_num2 = 0; icon_num2 < 8; ++icon_num2, ++score, ++score_panel) {
        if (*score_panel == 0) {
            return;
        }

        if (score->player_id == 0) {
            (*score_panel)->set_active(0);
            continue;
        }

        sprintf(str, "%s: %d/%d", comm->GetPlayerName(score->comm_id), score->player_score, score->team_score);

        RGE_Player* player = this->world->players[score->player_id];
        unsigned long font_color1;
        unsigned long font_color2;
        switch (player->color_table->id) {
        case 0:
            font_color1 = 0xFF0000;
            font_color2 = 0xB3B3B3;
            break;
        case 1:
            font_color1 = 0x2139C6;
            font_color2 = 0;
            break;
        case 2:
            font_color1 = 0xFFFF;
            font_color2 = 0;
            break;
        case 3:
            font_color1 = 0x4F73A3;
            font_color2 = 0;
            break;
        case 4:
            font_color1 = 0x0F77F3;
            font_color2 = 0;
            break;
        case 5:
            font_color1 = 0xC700;
            font_color2 = 0;
            break;
        case 6:
            font_color1 = 0x7B90A2;
            font_color2 = 0;
            break;
        case 7:
            font_color1 = 0xADAD00;
            font_color2 = 0;
            break;
        default:
            font_color1 = 0xFFFFFF;
            font_color2 = 0;
            break;
        }

        int special_font = 0;
        if (player->game_status == 2) {
            special_font = 1;
        } else if (rge_base_game->multiplayerGame() != 0) {
            int humanity = comm->GetPlayerHumanity(score->comm_id);
            if (humanity != ME_HUMAN && humanity != ME_COMPUTER) {
                special_font = 1;
            }
        }
        RGE_Font* font = rge_base_game->get_font(special_font != 0 ? RGE_FONT_STRIKEOUT : RGE_FONT_STANDARD);

        icon1 = 0;
        int icon_frame1 = 0;
        icon2 = 0;
        int icon_frame2 = 0;
        if (rge_base_game->multiplayerGame() != 0 && comm->GetPlayerHumanity(score->comm_id) == ME_HUMAN) {
            unsigned long latency =
                comm->Speed->GetPlayerLatency(score->comm_id);
            if (score->comm_id == low_fps_player) {
                icon2 = this->button_pics;
                icon_frame2 = 0x11;
            }
            if (latency > 299) {
                icon1 = this->button_pics;
                icon_frame1 = 0x14;
                if (latency < 0x3E9) {
                    icon_frame1 = 0x13;
                }
            }
        }

        (*score_panel)->show_message2(TMessagePanel::RightInfoMessage, str, font_color1, font_color2,
                                      font->font, font->font_wid, font->font_hgt, icon1, icon_frame1, icon2, icon_frame2);
    }
}

void TRIBE_Screen_Game::draw() {
    if (do_color_log) {
        tagRECT* r = &this->clip_rect;
        tagRECT save_clip_rect = *r;
        this->draw_setup(0);
        if (this->inven_panel) {
            if (this->render_area->Lock(s_scr_game_draw, 1)) {
                TPanel* panel = this->inven_panel;
                tagRECT panel_rect = panel->render_rect;
                this->render_area->FillRect(panel_rect.left, panel_rect.top, panel_rect.right, panel_rect.bottom, 0x74);
                this->render_area->Unlock(s_scr_game_draw);
                if (this->clip_rect.top < panel_rect.bottom)
                    this->clip_rect.top = panel_rect.bottom;
                this->render_area->SetClipRect(r);
            }
        }
        if (this->game_screen_pic) {
            if (this->render_area->Lock(s_scr_game_draw2, 1)) {
                if (this->pnl_wid >= 1024 && this->pnl_hgt >= 768) {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 642, 1, 0, 0);
                } else if (this->pnl_wid >= 800 && this->pnl_hgt >= 600) {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 474, 1, 0, 0);
                } else {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 354, 1, 0, 0);
                }
                this->render_area->Unlock(s_scr_game_draw2);
            }
        }
        this->draw_finish();
        *r = save_clip_rect;
        this->render_area->SetClipRect(r);
    } else {
        int flag;
        if (this->need_redraw != 2 && this->game_screen_pic) flag = 0;
        else flag = 1;
        this->draw_setup(flag);
        if (this->game_screen_pic) {
            if (this->render_area->Lock(s_scr_game_draw3, 1)) {
                if (this->pnl_wid >= 1024 && this->pnl_hgt >= 768) {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 642, 1, 0, 0);
                } else if (this->pnl_wid >= 800 && this->pnl_hgt >= 600) {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 474, 1, 0, 0);
                } else {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 354, 1, 0, 0);
                }
                this->render_area->Unlock(s_scr_game_draw3);
            }
        }
        this->draw_finish();
    }
}


void TRIBE_Screen_Game::handle_anim_pal() {
    unsigned long time;
    PALETTEENTRY pal_entries[7];

    time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_game.cpp", 4587);
    if (time - this->last_anim_pal_time >= this->anim_pal_interval) {
        short index = this->last_anim_pal_index;

        for (int i = 0; i < 7; ++i) {
            pal_entries[i].peRed = this->anim_pal_table[index].red;
            pal_entries[i].peGreen = this->anim_pal_table[index].green;
            pal_entries[i].peBlue = this->anim_pal_table[index].blue;
            pal_entries[i].peFlags = 0;

            ++index;
            if (index == 7) {
                index = 0;
            }
        }

        if (this->last_anim_pal_index == 0) {
            this->last_anim_pal_index = 6;
        } else {
            --this->last_anim_pal_index;
        }

        this->render_area->DrawSystem->ModifyPalette(248, 7, pal_entries);
        this->last_anim_pal_time = time;
    }
}

void TRIBE_Screen_Game::handle_terrain_sound() {
    color_log(0x54, 0x16, 4);

    if (rge_base_game->prog_info->use_sound != 0 && rge_base_game->sound_system != 0 && disable_terrain_sounds == 0) {
        unsigned long now =
            debug_timeGetTime(s_scr_game_cpp, 4637);

        if (this->terrain_playing != 0) {
            if (now - this->last_terrain_sound_time < 1000)
                return;

            this->last_terrain_sound_time = now;

            if (_bPlaying != 0) {
                if (now - this->terrain_sound_start_time < 6000) {
                    color_log(0x54, 0x5F, 4);
                    return;
                }
                rge_base_game->sound_system->stop_stream();
            }

            this->terrain_playing = 0;
            color_log(0x54, 0x5F, 4);
            return;
        }

        if (now - this->last_terrain_sound_time < this->terrain_sound_interval)
            return;

        TRIBE_World* world = this->world;
        this->last_terrain_sound_time = now;

        RGE_Map* map = world->map;
        short terrain_count = map->num_terrain;
        short best_index = -1;
        short best_drawn = 0;
        short index = 0;
        for (; index < terrain_count; ++index) {
            RGE_Tile_Set* terrain = &map->terrain_types[index];
            if (terrain->loaded != 0 && terrain->drawn > best_drawn && terrain->sound != 0) {
                best_index = index;
                best_drawn = terrain->drawn;
            }
        }

        if (best_index != -1) {
            char* file_name =
                map->terrain_types[best_index].sound->get_file_name();
            if (file_name != 0) {
                color_log(0x54, 0x4C, 4);
                debug_timeGetTime(s_scr_game_cpp, 4699);
                rge_base_game->sound_system->stop_stream();
                rge_base_game->sound_system->stream_file(file_name, 0, 0);
                color_log(0x54, 0x32, 4);
                this->terrain_playing = 1;
                this->terrain_sound_start_time =
                    debug_timeGetTime(s_scr_game_cpp, 4706);
            }
        } else {
            color_log(0x54, 0x5F, 4);
            return;
        }
    }

    color_log(0x54, 0x5F, 4);
    return;
}

void TRIBE_Screen_Game::handle_mouse_pointing_at() {
    void* window = rge_base_game->prog_window;
    if (GetForegroundWindow() != window) {
        return;
    }
    if (this->main_view->get_focus() == 0) {
        return;
    }
    if (panel_system.modalPanel() != 0) {
        return;
    }

    tagPOINT point;
    rge_base_game->get_mouse_pos(point);
    if (point.x == this->mouse_last_x && point.y == this->mouse_last_y) {
        return;
    }

    this->mouse_last_x = point.x;
    this->mouse_last_y = point.y;

    if (this->main_view->UC_ObjectTouched == 0) {
        this->text_line_panel->remove_message();
    }

    if (point.x < 0 || point.x >= this->pnl_wid || point.y < 0 || point.y > this->pnl_hgt) {
        return;
    }

    short row;
    short col;
    RGE_Tile* tile;
    if (this->map_view->pick_tile(point.x, point.y, &row, &col, &tile) != 0) {
        return;
    }

    short found = -1;
    short i = 0;
    while (i < 0x11) {
        TRIBE_Panel_Button** slot = &this->button_panel[i];
        if ((*slot)->active != 0 && (*slot)->get_id() != -1 && (*slot)->hit_button(point.x, point.y) != 0) {
            found = i;
            break;
        }
        ++i;
    }

    if (found != -1) {
        this->text_line_panel->show_message(TMessagePanel::InfoMessage, this->button_panel[found]->text_msg,
                                            TMessagePanel::WhiteColor, 0, 0, 0, 0);
    }
}

void TRIBE_Screen_Game::command_add_attribute(int attr_id) {
    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->allowCheatCodes() != 0) {
            RGE_Player* player = rge_base_game->get_player();
            player->command_add_attribute(attr_id, 1000.0f);
        }
    }
}

void TRIBE_Screen_Game::command_ai_info() {
    message_panel->remove_message();
    message_panel2->remove_message();
    message_panel3->remove_message();
    message_panel4->remove_message();
    message_panel5->remove_message();
    message_panel6->remove_message();

    if (rge_base_game->do_show_ai != 0) {
        rge_base_game->do_show_ai = 0;
        return;
    }
    {
        RGE_Base_Game* g = rge_base_game;
        g->do_show_timings = 0;
    }
    {
        RGE_Base_Game* g = rge_base_game;
        g->do_show_comm = 0;
    }
    {
        RGE_Base_Game* g = rge_base_game;
        g->do_show_ai = 1;
    }
}

void TRIBE_Screen_Game::command_attack(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }
    this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(STRING_ID_MESSAGE_ATTACK), TMessagePanel::NormalColor, 0, 0, 0, 0);
    // This command uses the set_game_mode virtual slot.
    rge_base_game->set_game_mode(0x67, 0);
}

void TRIBE_Screen_Game::command_build(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->set_game_mode(6, 1);
        // The original clears the inherited start item.
        this->start_item = 0;
        this->setup_buttons();
    }
}

void TRIBE_Screen_Game::command_building(int id) {
    short attr;
    char msg[512];

    if (rge_base_game->get_paused() == 0) {
        if (static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->check_obj_cost(static_cast<short>(id), &attr, 1.0f, 0)) {
            RGE_Base_Game* game = rge_base_game;
            game->master_obj_id = id;
            TRIBE_Player* player =
                static_cast<TRIBE_Player*>(rge_base_game->get_player());
            RGE_Master_Static_Object* object = player->master_objects[id];
            TRIBE_Master_Building_Object* building =
                static_cast<TRIBE_Master_Building_Object*>(object);
            if (building->building_connect_flag) {
                rge_base_game->set_game_mode(0x15, 0);
                return;
            }
            rge_base_game->set_game_mode(7, 0);
            return;
        } else {
            rge_base_game->get_string2(RGE_STRING_TYPE_ATTRIBUTE, 1, static_cast<int>(attr), msg, sizeof(msg));
            // This palette index has no verified name for this error path.
            this->message_panel->show_message(TMessagePanel::BadMessage, msg, 0x56, 0, 0, 0, 0);
        }
    }
}

void TRIBE_Screen_Game::command_cancel() {
    if (this->help_mode) {
        this->clear_popup_help();
        return;
    }

    if (rge_base_game->get_paused()) {
        return;
    }

    if (rge_base_game->game_mode != 0) {
        if (rge_base_game->game_mode == 0x15) {
            this->main_view->end_scroll_view();
            this->main_view->set_selection_area(-1, -1, -1, -1);
        }
        rge_base_game->set_game_mode(0, 0);
    } else {
        this->command_unselect();
    }
}

void TRIBE_Screen_Game::command_cancel_building() {
    if (rge_base_game->get_paused() == 0) {
        static_cast<TRIBE_Player*>(rge_base_game->get_player())
            ->command_building_cancel();
    }
}

void TRIBE_Screen_Game::command_chat() {
    if (rge_base_game->singlePlayerGame()) {
        command_quick_chat();
        return;
    }
    if (game_ended == 0 && rge_base_game->prog_mode == ProgModeGameOver) {
        message_panel->show_message(
            TMessagePanel::BadMessage, get_string(STRING_ID_ERROR_CHAT_AFTER_DEFEAT), TMessagePanel::NormalColor, 0, 0, 0, 0);
        return;
    }
    new TribeSendMessageDialog(this);
}

void TRIBE_Screen_Game::command_quick_chat() {
    if (game_ended == 0 && rge_base_game->prog_mode == ProgModeGameOver) {
        message_panel->show_message(
            TMessagePanel::BadMessage, get_string(STRING_ID_ERROR_CHAT_AFTER_DEFEAT), TMessagePanel::NormalColor, 0, 0, 0, 0);
        return;
    }

    new TribeSendQuickMessageDialog(this, TribeSendQuickMessageDialog::AsChat);
}

void TRIBE_Screen_Game::command_comm_info() {
    rge_base_game->do_show_timings = 0;
    this->fps_panel->set_active(0);
    this->inven_panel->set_active(1);
    this->message_panel->remove_message();
    this->message_panel2->remove_message();
    this->message_panel3->remove_message();
    this->message_panel4->remove_message();
    this->message_panel5->remove_message();
    this->message_panel6->remove_message();
    if (rge_base_game->do_show_comm != 0) {
        rge_base_game->do_show_comm = 0;
    }
    else {
        RGE_Base_Game* game;
        rge_base_game->do_show_timings = 0;
        game = rge_base_game;
        game->do_show_ai = 0;
        game = rge_base_game;
        game->do_show_comm = 1;
    }
}

void TRIBE_Screen_Game::command_convert(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }
    this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(STRING_ID_MESSAGE_CONVERT), TMessagePanel::NormalColor, 0, 0, 0, 0);
    // This command uses the set_game_mode virtual slot.
    rge_base_game->set_game_mode(0x65, 0);
}

void TRIBE_Screen_Game::command_diplomacy() {
    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->singlePlayerGame() == 1) {
            rge_base_game->set_paused(1, 1);
        }
        TribeDiplomacyDialog* dialog = new TribeDiplomacyDialog(this);
    }
}

void TRIBE_Screen_Game::command_fog_of_war() {
    if (rge_base_game->allowCheatCodes()) {
        rge_base_game->set_map_fog(this->world->map->fog_flag == 0);
        this->main_view->set_redraw(TPanel::RedrawImmediate);
    }
}

void TRIBE_Screen_Game::command_fps() {
    RGE_Base_Game* game = rge_base_game;
    if (game->do_show_timings != 0) {
        if (show_timing_max == 0) {
            show_timing_max = 1;
            return;
        }
        game->do_show_timings = 0;
        this->fps_panel->set_active(0);
        this->inven_panel->set_active(1);
    } else {
        show_timing_max = 0;
        game->do_show_timings = 1;
        this->fps_panel->set_active(1);
        this->inven_panel->set_active(0);
    }
}

//! Game speed follows the fixed ladder 1, 1.5, 2 here; the options dialog offers the same three.
//! Only developer mode adds 4, 8, 16. The engine accepts any float speed below this input layer.
//! A non-ladder speed makes every ladder comparison fail, so the + and - keys then do nothing.
void TRIBE_Screen_Game::command_game_speed(int increase_speed) {
    float new_speed;
    float cur_speed;

    unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_game.cpp", 5118);
    if (t - this->last_game_speed_change < 1000) {
        if (rge_base_game->singlePlayerGame() == 0) {
            return;
        }
    }

    this->last_game_speed_change = t;
    if (rge_base_game->prog_mode != ProgModeGameOver) {
        new_speed = 0.0f;
        cur_speed = this->world->game_speed;

        if (increase_speed != 0) {
            if (cur_speed == 1.0f) {
                new_speed = 1.5f;
            } else if (cur_speed == 1.5f) {
                new_speed = 2.0f;
            } else {
                if (rge_base_game->singlePlayerGame() != 0 && rge_base_game->gameDeveloperMode() != 0) {
                    if (cur_speed == 2.0f) {
                        new_speed = 4.0f;
                    } else if (cur_speed == 4.0f) {
                        new_speed = 8.0f;
                    } else if (cur_speed == 8.0f) {
                        new_speed = 16.0f;
                    }
                }
            }
        } else {
            if (cur_speed == 16.0f) {
                new_speed = 8.0f;
            } else if (cur_speed == 8.0f) {
                new_speed = 4.0f;
            } else if (cur_speed == 4.0f) {
                new_speed = 2.0f;
            } else if (cur_speed == 2.0f) {
                new_speed = 1.5f;
            } else if (cur_speed == 1.5f) {
                new_speed = 1.0f;
            }
        }

        if (new_speed != 0.0f) {
            if (rge_base_game->multiplayerGame() != 0) {
                char message[256];
                const char* text = this->get_string(STRING_ID_GAME_SPEED_CHANGED);
                sprintf(message, text);
                comm->SendChatMsgAll(message);
            }

            static_cast<TRIBE_Command*>(this->world->commands)
                ->command_game_speed(new_speed);
            if (rge_base_game->singlePlayerGame() != 0) {
                rge_base_game->set_game_speed(new_speed);
            }
        }
    }
}

void TRIBE_Screen_Game::command_group(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->get_player()->group_objects(-1);
    }
}

void TRIBE_Screen_Game::command_group_by_number(int id) {
    if (rge_base_game->get_paused() == 0) {
        if (id == 0) {
            id = 10;
        }
        (rge_base_game->get_player())->group_objects(id);
    }
}

void TRIBE_Screen_Game::command_heal(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }

    this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(STRING_ID_MESSAGE_HEAL), TMessagePanel::NormalColor, 0, 0, 0, 0);
        rge_base_game->set_game_mode(0x66, 0);
}

void TRIBE_Screen_Game::command_repair(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }
    this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(STRING_ID_MESSAGE_REPAIR), TMessagePanel::NormalColor, 0, 0, 0, 0);
    // This command uses the set_game_mode virtual slot.
    rge_base_game->set_game_mode(0x68, 0);
}

void TRIBE_Screen_Game::command_score(int show) {
    this->world->score_displayed = static_cast<unsigned char>(show);
    int score_count = 8;
    TMessagePanel** score_panel = this->score_panel;
    do {
        TMessagePanel* b = *score_panel;
        if (b != 0) {
            b->set_active(show);
        }
        ++score_panel;
        --score_count;
    } while (score_count != 0);

    if (show != 0) {
        this->reset_score_display();
    }

    if (this->world->score_displayed != 0) {
        this->text_line_panel->set_positioning(TPanel::PositionLeftBottom, 4, 0, 184, 4, 0, 0, 34, 34, 0, 0, 0, 0);
    } else {
        this->text_line_panel->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 4, 0, 0, 34, 34, 0, 0, 0, 0);
    }
    this->main_view->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Screen_Game::command_select_group(int id, int unsel_prior) {
    if (rge_base_game->get_paused()) {
        return;
    }
    if (unsel_prior != 0) {
        rge_base_game->get_player()->unselect_object();
    }
    if (id == 0) {
        id = 10;
    }
    rge_base_game->get_player()->select_group(id);
    this->main_view->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Screen_Game::command_menu() {
    if (rge_base_game->prog_mode == ProgModeGameTempPaused) {
        static_cast<TRIBE_Command*>(this->world->commands)->do_commands();
    }
    if (rge_base_game->singlePlayerGame() == 1) {
        rge_base_game->set_paused(1, 1);
    }
    new TribeMenuDialog(this);
}

void TRIBE_Screen_Game::command_more() {
    if (rge_base_game->get_paused())
        return;

    if (rge_base_game->game_mode == 6 && rge_base_game->sub_game_mode == 1) {
        this->start_item = (this->start_item != 0) ? 0 : 10;
        this->setup_buttons();
        return;
    }

    if (this->last_item < this->item_cnt - 1) {
        this->start_item = this->last_item + 1;
        this->setup_buttons();
        return;
    }

    this->start_item = 0;
    this->setup_buttons();
}

void TRIBE_Screen_Game::command_move() {
    RGE_Static_Object** list;
    short list_num;

    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->get_player()->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
            free(list);
                // This palette index has no verified name for this error path.
                this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(STRING_ID_MESSAGE_MOVE),
                                                  TMessagePanel::NormalColor, 0, 0, 0, 0);
            rge_base_game->set_game_mode(4, 0);
        }
    }
}

void TRIBE_Screen_Game::command_outline() {
    RGE_Base_Game* game;
    unsigned char outline_type;

    game = rge_base_game;
    outline_type = game->outline_type;
    switch (outline_type) {
    case 0:
    case 3:
        outline_type = 2;
        break;
    case 2:
        outline_type = 1;
        break;
    case 1:
        outline_type = 0;
        break;
    }
    game->outline_type = outline_type;
}

void TRIBE_Screen_Game::command_pause() {
    char msg[256];
    unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_game.cpp", 5362);

    if (t - last_pause_change < 1000) {
        if (rge_base_game->singlePlayerGame() == 0) {
            return;
        }
    }

    last_pause_change = t;

    if (rge_base_game->prog_mode != ProgModeGameOver) {
        if (rge_base_game->multiplayerGame() != 0) {
            const char* s = get_string(STRING_ID_MESSAGE_GAME_PAUSED);
            sprintf(msg, s);
            comm->SendChatMsgAll(msg);
        }
        rge_base_game->request_pause();
    }
}

void TRIBE_Screen_Game::command_player(int id) {
    if (!rge_base_game->allowCheatCodes()) {
        return;
    }

    rge_base_game->get_player()->unselect_object();
    this->main_view->set_redraw(TPanel::RedrawNormal);

    if (rge_base_game->game_mode == 6 && rge_base_game->sub_game_mode == 1) {
        rge_base_game->set_game_mode(0, 0);
    }

    rge_base_game->set_player(static_cast<short>(id));
}

void TRIBE_Screen_Game::command_quick_build(void) {
    if (rge_base_game->allowCheatCodes() != 0) {
        static_cast<TRIBE_Command*>(this->world->commands)
            ->command_quick_build(rge_base_game->quick_build == 0);
    }
}

void TRIBE_Screen_Game::command_quit() {
    comm->SendIResignMsg();
    comm->GameOver();
    static_cast<TRIBE_Game*>(rge_base_game)->do_game_over();
}

void TRIBE_Screen_Game::command_research(int id) {
    short attr;
    char msg[512];

    if (rge_base_game->get_paused() == 0) {
        if (static_cast<TRIBE_Player*>(rge_base_game->get_player()) ->check_tech_cost(static_cast<short>(id), &attr)) {
            static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->command_building_make_tech(static_cast<short>(id));
            return;
        }
        rge_base_game->get_string2(RGE_STRING_TYPE_ATTRIBUTE, 1, static_cast<int>(attr), msg, 512);
        // This palette index has no verified name for this error path.
        this->message_panel->show_message(TMessagePanel::BadMessage, msg, 0x56, 0, 0, 0, 0);
    }
}

void TRIBE_Screen_Game::command_save_game() {
    if (rge_base_game->prog_mode == ProgModeGameTempPaused) {
        static_cast<TRIBE_Command*>(this->world->commands)->do_commands();
    }
    new TribeSaveGameScreen(TribeSaveGameScreen::SaveGame, 0, 0);
    panel_system.setCurrentPanel(s_Save_Game_Screen, 0);
}

void TRIBE_Screen_Game::command_save_scenario() {
    if (rge_base_game->prog_mode == ProgModeGameTempPaused) {
        static_cast<TRIBE_Command*>(this->world->commands)->do_commands();
    }
    new TribeSaveGameScreen(TribeSaveGameScreen::SaveScenario, 0, 0);
    panel_system.setCurrentPanel(s_Save_Game_Screen, 0);
}

void TRIBE_Screen_Game::command_select_building(int id) {
    int object_id;

    if (rge_base_game->get_paused() == 0) {
        switch (id) {
        case 0:
            object_id = 0x6D;
            break;
        case 1:
            object_id = 0x0C;
            break;
        case 2:
            object_id = 0x2D;
            break;
        case 3:
            object_id = 0x57;
            break;
        case 4:
            object_id = 0x31;
            break;
        case 5:
            object_id = 0x65;
            break;
        case 6:
            object_id = 0x68;
            break;
        case 7:
            object_id = 0;
            break;
        default:
            return;
        }

        RGE_Static_Object* selected = rge_base_game->get_player()->selected_obj;
        RGE_Static_Object* obj;
        if (selected == 0 || rge_base_game->get_player()->selected_obj->master_obj->id != object_id) {
            obj = static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->find_obj(static_cast<short>(object_id), 0);
        } else {
            obj = static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->find_obj(static_cast<short>(object_id), rge_base_game->get_player()->selected_obj);
        }
        if (obj != 0) {
            rge_base_game->get_player()->unselect_object();
            rge_base_game->get_player()->select_object(obj);
            rge_base_game->get_player()->set_view_loc(obj->world_x, obj->world_y);
            rge_base_game->get_player()->set_map_loc(static_cast<short>(static_cast<int>(obj->world_x)),
                                                     static_cast<short>(static_cast<int>(obj->world_y)));
            this->main_view->set_redraw(TPanel::RedrawNormal);
        }
    }
}

void TRIBE_Screen_Game::command_stop(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->get_player()->command_stop();
    }
}

void TRIBE_Screen_Game::command_tool_box() {
    if (rge_base_game->multiplayerGame() == 0) {
        RGE_Panel_Tool_Box* tb = this->tool_box;
        if (tb->active != 0) tb->set_active(0); else tb->set_active(1);
        this->handle_size(this->pnl_wid, this->pnl_hgt);
        rge_base_game->set_game_mode(0, 0);
        this->set_redraw(TPanel::RedrawNormal);
    }
}

void TRIBE_Screen_Game::command_trade() {}

void TRIBE_Screen_Game::command_trade_with(int id) {}

void TRIBE_Screen_Game::command_train(int id, short train_count) {
    short attr;
    char msg[512];

    if (rge_base_game->get_paused() == 0) {
        if (production_queues_is_use) {
            static_cast<TRIBE_Command*>(this->world->commands)
                ->command_queue(this->game_obj, id, train_count);
            return;
        }
        if (static_cast<TRIBE_Player*>(rge_base_game->get_player())
            ->check_obj_cost(static_cast<short>(id), &attr, 1.0f, 0)) {
            RGE_Base_Game* game = rge_base_game;
            game->master_obj_id = static_cast<short>(id);
            static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->command_building_make_obj(static_cast<short>(id));
            return;
        }
        rge_base_game->get_string2(RGE_STRING_TYPE_ATTRIBUTE, 1, static_cast<int>(attr), msg, 512);
        // This palette index has no verified name for this error path.
        this->message_panel->show_message(TMessagePanel::BadMessage, msg, 0x56, 0, 0, 0, 0);
    }
}

void TRIBE_Screen_Game::command_ungroup(void) {
    if (rge_base_game->get_paused() == 0) {
        (rge_base_game->get_player())->ungroup_objects();
        this->main_view->set_redraw(TPanel::RedrawNormal);
    }
}

void TRIBE_Screen_Game::command_unload(void) {
    if (!rge_base_game->get_paused()) {
        this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(STRING_ID_MESSAGE_UNLOAD),
                                          TMessagePanel::NormalColor, 0, 0, 0, 0);
        rge_base_game->set_game_mode(0x69, 0);
    }
}

void TRIBE_Screen_Game::command_unselect(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->get_player()->unselect_object();
        rge_base_game->get_player()->unselect_area();
        this->main_view->set_redraw(TPanel::RedrawNormal);
    }
}

void TRIBE_Screen_Game::command_view_selected() {
    if (rge_base_game->get_paused()) return;

    RGE_Static_Object* selected = rge_base_game->get_player()->selected_obj;
    if (selected == 0) return;

    rge_base_game->get_player()->set_view_loc(selected->world_x, selected->world_y);
    rge_base_game->get_player()->set_map_loc(static_cast<short>(static_cast<int>(selected->world_x)),
                                             static_cast<short>(static_cast<int>(selected->world_y)));
}

void TRIBE_Screen_Game::command_view_tribe() {
    if (rge_base_game->get_paused() == 0) {
        RGE_Static_Object* obj =
            static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->find_obj(0x6d, 0);
        if (obj != 0) {
            rge_base_game->get_player()->unselect_object();
            rge_base_game->get_player()->select_object(obj);
            rge_base_game->get_player()->set_view_loc(obj->world_x, obj->world_y);
            rge_base_game->get_player()->set_map_loc(static_cast<short>(static_cast<int>(obj->world_x)),
                                                     static_cast<short>(static_cast<int>(obj->world_y)));
            main_view->set_redraw(TPanel::RedrawNormal);
        }
    }
}

void TRIBE_Screen_Game::command_visibility() {
    if (!rge_base_game->allowCheatCodes())
        return;

    rge_base_game->set_map_visible(this->world->map->map_visible_flag == 0);
    this->main_view->set_redraw(TPanel::RedrawImmediate);
    this->map_view->set_redraw(TPanel::RedrawImmediate);
}

void TRIBE_Screen_Game::command_work() {
    RGE_Static_Object** list;
    short list_num;

    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->get_player()->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
            free(list);
            this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(STRING_ID_MESSAGE_WORK),
                                              TMessagePanel::NormalColor, 0, 0, 0, 0);
            rge_base_game->set_game_mode(5, 0);
        }
    }
}

void TRIBE_Screen_Game::command_formation(int formationID) {
    if (rge_base_game->get_paused() == 0) {
        (rge_base_game->get_player())->command_formation(formationID);
    }
}

void TRIBE_Screen_Game::command_stand_ground(void) {
    if (rge_base_game->get_paused() == 0) {
        (rge_base_game->get_player())->command_stand_ground();
    }
}

void TRIBE_Screen_Game::command_attack_ground(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }
    this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(STRING_ID_MESSAGE_ATTACK_GROUND), TMessagePanel::NormalColor, 0, 0, 0, 0);
    // This command uses the set_game_mode virtual slot.
    rge_base_game->set_game_mode(0x64, 0);
}

void TRIBE_Screen_Game::command_trade_attribute(long attribute) {
    if (rge_base_game->get_paused() == 0) {
        static_cast<TRIBE_Player*>(rge_base_game->get_player())
            ->command_trade_attribute(attribute);
    }
}

void TRIBE_Screen_Game::command_tab_selected(int forward) {
    RGE_Player* player = rge_base_game->get_player();
    int found = 0;
    RGE_Static_Object* candidate = 0;
    int paused = rge_base_game->get_paused();

    if (paused == 0) {
        short selected_count = player->sel_count;
        if (selected_count >= 2) {
            short slot;
            short count;
            if (forward != 0) {
                slot = 0;
                count = 0;
                while (slot < 25) {
                    if (count >= selected_count) {
                        break;
                    }
                    RGE_Static_Object* current = player->sel_list[slot];
                    if (current != 0) {
                        if (current == player->selected_obj) {
                            found = true;
                        } else {
                            if (found) {
                                candidate = player->sel_list[slot];
                                break;
                            }
                            if (candidate == 0) {
                                candidate = current;
                            }
                        }
                        ++count;
                    }
                    ++slot;
                }
            } else {
                slot = 0;
                count = 0;
                while (slot < 25) {
                    if (count >= selected_count) {
                        break;
                    }
                    RGE_Static_Object* current = player->sel_list[slot];
                    if (current != 0) {
                        if (current == player->selected_obj) {
                            if (candidate != 0) {
                                break;
                            }
                        } else {
                            candidate = current;
                        }
                        ++count;
                    }
                    ++slot;
                }
            }

            if (candidate != 0) {
                player->selected_obj = candidate;
            }
        }
    }
}

int TRIBE_Screen_Game::any_selected_have_action() {
    TRIBE_Player* player = static_cast<TRIBE_Player*>(rge_base_game->get_player());
    int slot = 0;
    int index = 0;
    while (slot < 25) {
        if (index >= player->sel_count) {
            return 0;
        }
        RGE_Action_Object* object =
            static_cast<RGE_Action_Object*>(player->sel_list[slot]);
        if (object != 0) {
            unsigned char type = object->master_obj->master_type;
            if (type >= 0x28 && type <= 0x50 && object->have_action() != 0) {
                return 1;
            }
            ++index;
        }
        ++slot;
    }
    return 0;
}

void TRIBE_Screen_Game::set_focus(int have_focus_in) {
    TScreenPanel::set_focus(have_focus_in);
    if (this->have_focus != 0) {
        rge_base_game->set_windows_mouse(0);
    } else {
        rge_base_game->set_windows_mouse(1);
    }
}

void TRIBE_Screen_Game::stop_sound_system(void) {
    TDigital* sound_system = this->game_over_sound;

    if (sound_system != 0) {
        delete sound_system;
        this->game_over_sound = 0;
    }
    TPanel::stop_sound_system();
}

int TRIBE_Screen_Game::restart_sound_system() { return TPanel::restart_sound_system(); }

void TRIBE_Screen_Game::add_log(char* text) {}
