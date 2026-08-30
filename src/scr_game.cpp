
#include "../include/scr_game.h"
#include "../include/game_globals.h"
#include <new.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    : TScreenPanel(s_Game_Screen)
{
    displayPathingFlags = 0;
    allow_user_commands = (do_fixed_update == 0);
    die_die_die = 0;

    register int i;
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
    this->last_update_time = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x116);
    this->map_redraw_interval = 0x14d;
    this->last_map_redraw_time = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x119);
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
    this->last_view_time = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x142);
    this->player_quit = 0;

    this->save_age = *this->get_string(0x103f);
    this->save_culture = 0;
    this->save_screen_width = *this->get_string(0x104a);
    this->game_over_time = 0;
    this->showing_game_over = *this->get_string(0x103a);
    this->chat_line = 0x41;
    for (i = 0; i < 8; i++) {
        this->select_building_hotkey[i] = *this->get_string(i + 0x1040);
    }
    this->reset_after_update = 1;
    this->score_interval = 3000;
    this->last_score_time = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x154);
    this->watch_mode = 0;
    this->game_ended = 0;
    this->game_over_sound = 0;

    if (!this->setup(rge_base_game->draw_area, s_scr6, 0xc388, 1)) {
        this->error_code = 1;
        return;
    }

    char str[512];

    this->button_unit_pic = new TShape(s_btnunit_shp, 0xc62a);
    if (this->button_unit_pic == 0 || !(this->button_unit_pic)->is_loaded()) {
        this->error_code = 1;
        return;
    }

    this->button_tech_pic = new TShape(s_btntech_shp, 0xc629);
    if (this->button_tech_pic == 0 || !this->button_tech_pic->is_loaded()) {
        this->error_code = 1;
        return;
    }

    this->button_cmd_pic = new TShape(s_btncmd_shp, 0xc621);
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
    if (!this->main_view->setup(this->render_area, this, 0, 0, 0, 0, 0, 1, s_bordline)) {
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
    this->map_view->set_help_info(0x4e33, -1);
    this->map_view->set_world(this->world);
    this->map_view->set_bitmap(s_map_bmp, 0xc4e1);
    this->map_view->set_player(rge_base_game->get_player());
    TRIBE_Main_View* main_view_for_map = this->main_view;
    this->map_view->main_view = main_view_for_map;

    RGE_Font* font = rge_base_game->get_font(0xb);
    {
    TRIBE_Panel_Inven* inven = new TRIBE_Panel_Inven(
        this->render_area, this, font->font,
        static_cast<TRIBE_Player*>(rge_base_game->get_player()));
    this->inven_panel = inven;
    if (inven == 0 || inven->error_code != 0) {
        this->error_code = 1;
        return;
    }
    inven->set_help_info(0x4e25, -1);
    }

    font = rge_base_game->get_font(7);
    {
    TRIBE_Panel_Object* object_panel = new TRIBE_Panel_Object(
        this->render_area, this, font->font, font->font_wid, font->font_hgt,
        this->button_unit_pic, this->button_bldg_pics,
        static_cast<TRIBE_Player*>(rge_base_game->get_player()));
    this->object_panel = object_panel;
    if (object_panel == 0 || object_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    object_panel->set_help_info(0x19bb8, 0x265ac);
    }

    font = rge_base_game->get_font(0xb);
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
    this->button_panel[12]->set_help_info(0x1d4cf, -1);
    this->button_panel[13]->set_id(0, 0x0e, 0);
    this->button_panel[13]->set_help_info(0x1d4d1, -1);
    this->button_panel[14]->set_id(0, 0x0f, 0);
    this->button_panel[14]->set_help_info(0x1d4cd, -1);
    this->button_panel[15]->set_id(0, 0x15, 0);
    this->button_panel[15]->set_help_info(0x1d4db, -1);
    this->button_panel[16]->set_id(0, 0x18, 0);
    this->button_panel[16]->set_help_info(0x1d4dc, -1);

    for (i = 12; i < 15; ++i) {
        TRIBE_Panel_Button* button = this->button_panel[i];
        button->setDrawType(TButtonPanel::DrawPicture);
        button->tribe_button_type = 3;
        button->set_text(0, rge_base_game->get_string2(0x66, button->get_id(),
                                                        0, str, 0x200));
        button->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                               this->bevel_color3, this->bevel_color4,
                               this->bevel_color5, this->bevel_color6);
    }
    if (rge_base_game->singlePlayerGame() == 1) {
        this->button_panel[12]->set_active(0);
    }
    this->button_panel[15]->setDrawType(TButtonPanel::DrawPicture);
    this->button_panel[15]->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    this->button_panel[15]->tribe_button_type = 3;
    this->button_panel[15]->set_text(0, 0x0FA9L);
    this->button_panel[16]->setDrawType(TButtonPanel::DrawPicture);
    this->button_panel[16]->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    this->button_panel[16]->tribe_button_type = 3;
    this->button_panel[16]->set_text(0, 0x1023L);
    this->get_string(0x1024, str, 0x200);
    this->button_panel[16]->set_text_msg(str);

    {
    font = rge_base_game->get_font(0xb);
    this->text_line_panel = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    if (this->text_line_panel == 0 || this->text_line_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!(this->text_line_panel)->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->text_line_panel->set_justification(TMessagePanel::LeftJust,
                                             TMessagePanel::BottomJust, 1);
    this->main_view->message_panel = this->text_line_panel;

    this->create_text(this->main_view, &this->quit_message_panel, 0x232e, 0, 0,
                      600, 0x3c, 0x0b, 1, 1, 0);
    if (this->quit_message_panel != 0) {
        this->quit_message_panel->set_text_color(0xffffff, 0);
        this->quit_message_panel->set_active(0);
    }
    this->create_text(this->main_view, &this->pause_text, 0x2329, 0, 0, 600,
                      0x3c, 1, 1, 1, 0);
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
    font = rge_base_game->get_font(0xb);
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
        (message_check = this->message_panel4) == 0 ||
        this->message_panel5 == 0 ||
        this->message_panel6 == 0 ||
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

    font = rge_base_game->get_font(0xb);
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
    font = rge_base_game->get_font(0xb);
    this->age_panel = new TTextPanel;
    if (this->age_panel == 0 || this->age_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->age_panel->setup(this->render_area, this, 0, 0, 0, 0,
                                font->font, font->font_wid, font->font_hgt,
                                0, 0, 0, 0, 0, 0, initial_text)) {
        this->error_code = 1;
        return;
    }
    this->age_panel->set_alignment(TTextPanel::AlignCenter,
                                   TTextPanel::AlignCenter);
    this->age_panel->set_help_info(0x4e35, -1);
    if (do_color_log) {
        this->age_panel->set_active(0);
    }

    font = rge_base_game->get_font(10);
    this->fps_panel = new TTextPanel;
    if (this->fps_panel == 0 || this->fps_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->fps_panel->setup(this->render_area, this, 0, 0, 0, 0,
                                font->font, font->font_wid, font->font_hgt,
                                0, 1, 0, 0, 0, 0, initial_text)) {
        this->error_code = 1;
        return;
    }
    this->fps_panel->set_alignment(TTextPanel::AlignCenter,
                                   TTextPanel::AlignLeft);
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

    font = rge_base_game->get_font(0xb);
    int num_game_players = 0;
    if (rge_base_game->multiplayerGame()) {
        for (i = 1; i < 9; i++) {
            if (comm->GetPlayerHumanity(i) == 2 || comm->GetPlayerHumanity(i) == 4) {
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
    if (!this->create_text(this, &this->log_text, s_, 10, 300, 400, 0x60, 7, 0, 0,
                           0)) {
        this->error_code = 1;
        return;
    }
    this->log_text->set_back_pic(0);
    this->log_text->set_fill_back(1, 0);
    this->log_text->set_style(TTextPanel::NormalStyle);
    this->log_text->set_text_color(0xffffff, 0);
    if (!this->create_auto_scrollbar(&this->log_scrollbar, this->log_text, 0x14)) {
        this->error_code = 1;
        return;
    }
    this->log_scrollbar->set_bevel_info(1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff);
    this->log_text->empty_list();
    this->log_text->set_active(0);
    }

    font = rge_base_game->get_font(7);
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
    this->player_changed(rge_base_game->get_player()->id,
                         rge_base_game->get_player()->id);

    this->terrain_sound_interval = 20000;
    this->last_terrain_sound_time = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x339);
    this->anim_pal_interval = 200;
    this->last_anim_pal_time = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x33f);
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
    if (rge_base_game->check_prog_argument(s_PAUSE)) {
        start_paused = 1;
        rge_base_game->set_prog_mode(6);
        rge_base_game->world->temp_pause = 1;
    }
}


TRIBE_Screen_Game::~TRIBE_Screen_Game() {
    panel_system.destroyPanel(s_Game_Screen);

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

void TRIBE_Screen_Game::set_redraw(TPanel::RedrawMode p) {
    this->TPanel::set_redraw(p);
}

void TRIBE_Screen_Game::set_overlapped_redraw(
    TPanel* param_1, TPanel* param_2, TPanel::RedrawMode param_3)
{
    TPanel* dialog = panel_system.modalPanel();
    if (dialog != 0) {
        tagRECT this_rect = param_1->clip_rect;
        tagRECT other_rect = dialog->clip_rect;

        if ((
            (
                ((other_rect.left >= this_rect.left) &&
                 (other_rect.left <= this_rect.right)) ||
                ((other_rect.right >= this_rect.left) &&
                 (other_rect.right <= this_rect.right)) ||
                ((this_rect.left > other_rect.left) &&
                 (other_rect.right > this_rect.right))
            ) &&
            (
                ((other_rect.top >= this_rect.top) &&
                 (other_rect.top <= this_rect.bottom)) ||
                ((other_rect.bottom >= this_rect.top) &&
                 (other_rect.bottom <= this_rect.bottom)) ||
                ((other_rect.top < this_rect.top) &&
                 (other_rect.bottom > this_rect.bottom))
            )
        ) ||
        (
            (
                ((this_rect.left >= other_rect.left) &&
                 (this_rect.left <= other_rect.right)) ||
                ((this_rect.right >= other_rect.left) &&
                 (this_rect.right <= other_rect.right)) ||
                ((this_rect.left < other_rect.left) &&
                 (this_rect.right > other_rect.right))
            ) &&
            (
                ((this_rect.top >= other_rect.top) &&
                 (this_rect.top <= other_rect.bottom)) ||
                ((this_rect.bottom >= other_rect.top) &&
                 (this_rect.bottom <= other_rect.bottom)) ||
                ((this_rect.top < other_rect.top) &&
                 (this_rect.bottom > other_rect.bottom))
            )
        )) {
            dialog->set_redraw(param_3);
        }
    }
}

void TRIBE_Screen_Game::set_map_buttons_redraw(TPanel::RedrawMode mode) {
    if (this->pnl_wid < 0x320) {
        this->button_panel[5]->set_redraw(mode);
        this->button_panel[11]->set_redraw(mode);
    }
    this->button_panel[15]->set_redraw(mode);
    this->button_panel[16]->set_redraw(mode);
}

long TRIBE_Screen_Game::handle_size(long width, long height) {
    TPanel::handle_size(width, height);

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

    for (int score_active_index = 0; score_active_index < 8; ++score_active_index) {
        TPanel* panel = this->score_panel[score_active_index];
        if (panel != 0) {
            save_score_active[score_active_index] = panel->active;
            panel->set_active(1);
        }
    }

    short final_frame;

    if (this->pnl_wid >= 0x400 && this->pnl_hgt >= 0x300) {
        this->pop_panel->set_positioning(TPanel::PositionLeftTop, 0x1B0, 4, 4, 4,
                                         0xA0, 0xA0, 0x14, 0x14,
                                         0, 0, 0, 0);

        if (this->tool_box->active != 0) {
            this->tool_box->set_fixed_position(0, 0x14, 0x400, 0x1E);
            this->main_view->set_fixed_position(0, 0x32, 0x400, 0x250);
        } else {
            this->main_view->set_fixed_position(0, 0x14, 0x400, 0x26E);
        }

        this->map_view->set_fixed_position(0x31B, 0x288, 0xDC, 0x72);
        this->age_panel->set_fixed_position(0x10E, 2, 0x1EC, 0x10);
        this->fps_panel->set_fixed_position(2, 2, 0x118, 0x10);
        this->inven_panel->set_fixed_position(0, 0, 0x10E, 0x14);
        this->object_panel->set_fixed_position(5, 0x289, 0x7F, 0x72);

        panel_y = 0x28A;
        for (int panel_row = 0; panel_row < 2; ++panel_row) {
            panel_x = 0x88;
            for (int panel_column = 0; panel_column < 6; ++panel_column) {
                int button_index = panel_row * 6 + panel_column;
                this->button_panel[button_index]->set_fixed_position(panel_x, panel_y, 0x36, 0x36);
                this->button_panel[button_index]->tribe_button_type = 0;
                panel_x += 0x36;
            }
            panel_y += 0x3A;
        }

        this->button_panel[12]->set_fixed_position(0x304, 0, 0x48, 0x13);
        this->button_panel[13]->set_fixed_position(0x34C, 0, 0x6C, 0x13);
        this->button_panel[14]->set_fixed_position(0x3B8, 0, 0x48, 0x13);
        this->button_panel[15]->set_fixed_position(0x3DD, 0x2DC, 0x1E, 0x1E);
        this->button_panel[15]->tribe_button_type = 3;
        this->button_panel[16]->set_fixed_position(0x3DD, 0x28A, 0x1E, 0x1E);
        this->button_panel[16]->tribe_button_type = 3;

        this->more_cancel_pic = this->button_cmd_pic;
        this->more_frame = 0xB;
        final_frame = 0xA;
    } else {
        if (this->pnl_wid >= 0x320 && this->pnl_hgt >= 0x258) {
        this->pop_panel->set_positioning(TPanel::PositionLeftTop, 0x140, 4, 4, 4,
                                         0xA0, 0xA0, 0x14, 0x14,
                                         0, 0, 0, 0);

        if (this->tool_box->active != 0) {
            this->tool_box->set_fixed_position(0, 0x14, 0x320, 0x1E);
            this->main_view->set_fixed_position(0, 0x32, 0x320, 0x1A8);
        } else {
            this->main_view->set_fixed_position(0, 0x14, 0x320, 0x1C6);
        }

        this->map_view->set_fixed_position(0x23B, 0x1E0, 0xDC, 0x72);
        this->age_panel->set_fixed_position(0x10E, 2, 0x10C, 0x10);
        this->fps_panel->set_fixed_position(2, 2, 0x118, 0x10);
        this->inven_panel->set_fixed_position(0, 0, 0x10E, 0x14);
        this->object_panel->set_fixed_position(5, 0x1E1, 0x7F, 0x72);

        panel_y = 0x1E2;
        for (int panel_row = 0; panel_row < 2; ++panel_row) {
            panel_x = 0x88;
            for (int panel_column = 0; panel_column < 6; ++panel_column) {
                int button_index = panel_row * 6 + panel_column;
                this->button_panel[button_index]->set_fixed_position(panel_x, panel_y, 0x36, 0x36);
                this->button_panel[button_index]->tribe_button_type = 0;
                panel_x += 0x36;
            }
            panel_y += 0x3A;
        }

        this->button_panel[12]->set_fixed_position(0x224, 0, 0x48, 0x13);
        this->button_panel[13]->set_fixed_position(0x26C, 0, 0x6C, 0x13);
        this->button_panel[14]->set_fixed_position(0x2D8, 0, 0x48, 0x13);
        this->button_panel[15]->set_fixed_position(0x2FD, 0x234, 0x1E, 0x1E);
        this->button_panel[15]->tribe_button_type = 3;
        this->button_panel[16]->set_fixed_position(0x2FD, 0x1E2, 0x1E, 0x1E);
        this->button_panel[16]->tribe_button_type = 3;

        this->more_cancel_pic = this->button_cmd_pic;
        this->more_frame = 0;
        final_frame = 2;
        } else {
        this->pop_panel->set_positioning(TPanel::PositionLeftTop, 0xF0, 4, 4, 4,
                                         0xA0, 0xA0, 0x14, 0x14,
                                         0, 0, 0, 0);

        if (this->tool_box->active != 0) {
            this->tool_box->set_fixed_position(0, 0x14, 0x280, 0x1E);
            this->main_view->set_fixed_position(0, 0x32, 0x280, 0x130);
        } else {
            this->main_view->set_fixed_position(0, 0x14, 0x280, 0x14E);
        }

        this->map_view->set_fixed_position(0x19B, 0x16A, 0xDC, 0x72);
        this->age_panel->set_fixed_position(0x10E, 2, 0x6A, 0x10);
        this->fps_panel->set_fixed_position(2, 2, 0x118, 0x10);
        this->inven_panel->set_fixed_position(0, 0, 0x10E, 0x14);
        this->object_panel->set_fixed_position(5, 0x169, 0x7F, 0x72);

        panel_y = 0x16A;
        for (int panel_row = 0; panel_row < 2; ++panel_row) {
            panel_x = 0x88;
            for (int panel_column = 0; panel_column < 6; ++panel_column) {
                int button_index = panel_row * 6 + panel_column;
                this->button_panel[button_index]->set_fixed_position(panel_x, panel_y, 0x36, 0x36);
                this->button_panel[button_index]->tribe_button_type = 0;
                panel_x += 0x36;
            }
            panel_y += 0x3A;
        }

        this->button_panel[5]->set_fixed_position(0x196, 0x16A, 0x66, 0x35);
        this->button_panel[5]->tribe_button_type = 2;
        this->button_panel[11]->set_fixed_position(0x196, 0x1BB, 0x66, 0x35);
        this->button_panel[11]->tribe_button_type = 2;
        this->button_panel[12]->set_fixed_position(0x184, 0, 0x48, 0x13);
        this->button_panel[13]->set_fixed_position(0x1CC, 0, 0x6C, 0x13);
        this->button_panel[14]->set_fixed_position(0x238, 0, 0x48, 0x13);
        this->button_panel[15]->set_fixed_position(0x25D, 0x1BC, 0x1E, 0x1E);
        this->button_panel[15]->tribe_button_type = 3;
        this->button_panel[16]->set_fixed_position(0x25D, 0x16A, 0x1E, 0x1E);
        this->button_panel[16]->tribe_button_type = 3;

        this->more_cancel_pic = this->button_cmd_pic;
        this->more_frame = 0;
            final_frame = 2;
        }
    }

    this->cancel_frame = final_frame;
    this->unselect_frame = final_frame;

    this->pause_text->set_positioning(TPanel::PositionCentered, 4, 4, 4, 4,
                                      0x258, 0x258, 0x3C, 0x3C,
                                      0, 0, 0, 0);
    this->time_panel->set_positioning(TPanel::PositionLeftTop, 4, 4, 4, 4,
                                      0x78, 0x78, 0x14, 0x14,
                                      0, 0, 0, 0);

    int clock_y = 4;
    for (int clock_index = 0; clock_index < 10; ++clock_index) {
        this->countdown_clock[clock_index]->set_positioning(
            TPanel::PositionRightTop, 4, clock_y, 4, 4, 0xAA, 0xAA, 0x14, 0x14,
            0, 0, 0, 0);
        clock_y += 0x14;
    }

    if (this->world->countdown_victory != 0) {
        this->text_line_panel->set_positioning(TPanel::PositionLeftBottom, 4, 0, 0xB8, 4,
                                               0, 0, 0x22, 0x22,
                                               0, 0, 0, 0);
    } else {
        this->text_line_panel->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 4,
                                               0, 0, 0x22, 0x22,
                                               0, 0, 0, 0);
    }

    int half_width = (this->main_view->width() - 500) / 2;
    this->quit_message_panel->set_positioning(TPanel::PositionLeftTop, half_width, 8,
                                              half_width, 8,
                                              0, 0, 0x14, 0x14,
                                              0, 0, 0, 0);

    this->message_panel->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->text_line_panel);
    this->message_panel2->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->message_panel);
    this->message_panel3->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->message_panel2);
    this->message_panel4->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->message_panel3);
    this->message_panel5->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->message_panel4);
    this->message_panel6->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 0,
                                            0, 0, 0x14, 0x14,
                                            0, 0, 0, this->message_panel5);

    int chat_y = 0x22;
    for (int chat_index = 0; chat_index < 8; ++chat_index) {
        this->chat_panel[chat_index]->set_fixed_position(4, chat_y, 0x26C, 0x14);
        chat_y += 0x14;
    }

    short score_index = 7;
    do {
        TPanel* score = this->score_panel[static_cast<int>(score_index)];
        if (score != 0) {
            TPanel* next_score = 0;
            if (score_index != 7) {
                next_score = this->score_panel[static_cast<int>(score_index) + 1];
            }
            score->set_positioning(TPanel::PositionRightBottom, 4, 0, 4,
                                   score_index != 7 ? 4 : 0,
                                   200, 200, 0x14, 0x14,
                                   0, 0, 0, next_score);
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
            this->score_panel[score_restore_index]->set_active(
                save_score_active[score_restore_index]);
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
        debug_timeGetTime(s_scr_game_cpp, 0x5AA);

    int draw_all_children;
    if (this->need_redraw == 2 ||
        this->main_view->get_focus() != 0 ||
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
            for (PanelNode* node = this->first_child_node;
                 node != 0;
                 node = node->next_node) {
                node->panel->set_redraw(
                    static_cast<TPanel::RedrawMode>(this->need_redraw));
            }

            TPanel* panel = this->parent_panel;
            if (panel != 0 && panel->overlapping_children != 0) {
                panel->set_overlapped_redraw(
                    this, this, static_cast<TPanel::RedrawMode>(this->need_redraw));
            }
            this->draw();
        }
        this->need_redraw = 0;
        this->just_drawn = 1;
    }

    unsigned long other_time =
        debug_timeGetTime(s_scr_game_cpp, 0x5C2) - first_time;

    for (PanelNode* node = this->first_child_node;
         node != 0;
         node = node->next_node) {
        unsigned long child_start =
            debug_timeGetTime(s_scr_game_cpp, 0x5C9);
        TPanel* panel = node->panel;

        if (draw_all_children || panel == this->curr_child) {
            panel->handle_paint();
        }

        unsigned long child_end =
            debug_timeGetTime(s_scr_game_cpp, 0x5D0);
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

    if (mode == 4 || mode == 6 || mode == 5) {
        if (panel_system.currentPanel() == this &&
            this->main_view->get_focus() != 0) {
            color_log(0x5F, 0x45, 5);
            this->handle_anim_pal();
        }
    }

    if (mode == 4 || mode == 6) {
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

void TRIBE_Screen_Game::handle_game_update(void)
{
    unsigned long t;
    unsigned long now;
    unsigned char update_flag;
    int mode;
    int calc_game_time;
    unsigned long update_counter;
    int loop_i;
    int i;

    update_counter = 0;
    color_log(0x24, 0x24, 5);

    t = debug_timeGetTime(s_scr_game_cpp, 0x63F);
    if (t - this->last_update_time >= this->update_interval) {
        mode = rge_base_game->prog_mode;
        if (static_cast<char>(mode) != 6) {
            color_log(0x24, 0x32, 5);
            if (rge_base_game->multiplayerGame()) {
        unsigned long st2 = rge_base_game->get_last_single_time(2);
        unsigned long sum = st2 + rge_base_game->get_last_single_time(3);
        unsigned long per;

        if (rge_base_game->get_last_world_update_count() == 0) {
            per = 1;
        } else {
            unsigned long wc2 = rge_base_game->get_last_world_update_count();
            unsigned long lt = rge_base_game->get_last_time(1);
            per = lt / wc2;
            if (per == 0) {
                per = 1;
            }
        }
        {
            int who = comm->WhoAmI();
            unsigned long avg = comm->Speed->GetPlayerAvgFramesMsec(who);
            calc_game_time = 2;
            if (multi_updates == 0 || avg < 0x43 || avg > 0x7D ||
                static_cast<float>(per) / static_cast<float>(static_cast<int>(sum)) > 2.0f) {
                calc_game_time = 1;
            }
        }
        rge_base_game->set_last_single_time(2, 0);
        rge_base_game->set_last_single_time(3, 0);
    } else {
        calc_game_time = 1;
    }

    loop_i = 0;
    if (calc_game_time > 0) {
        do {
            unsigned char update_flag;
            color_log(0x24, 0x4C, 5);
            color_log(0x24, 0x24, 1);
            now = debug_timeGetTime(s_scr_game_cpp, 0x692);
            if (start_paused) {
                update_flag = 0;
                rge_base_game->set_prog_mode(6);
            } else if (this->game_ended == 0) {
                update_flag = this->world->update();
                if (out_of_sync2) {
                    return;
                }
                if (update_flag == 1) {
                    this->game_ended = 1;
                    this->main_view->end_scroll_view();
                    this->main_view->set_selection_area(-1, -1, -1, -1);
                    rge_base_game->set_game_mode(0, 0);
                    this->command_unselect();
                    if (rge_base_game->multiplayerGame()) {
                        this->world->send_zone_score_info();
                    }
                }
            } else {
                update_flag = 1;
            }
            if (out_of_sync2) {
                return;
            }

            this->last_update_time = debug_timeGetTime(s_scr_game_cpp, 0x6BB);
            if (this->world->world_time_delta != 0) {
                rge_base_game->add_to_timing(1, this->last_update_time - now);
                rge_base_game->increment_world_update_count();
            }
            color_log(0x24, 0xBA, 1);

            if (this->reset_after_update != 0) {
                this->reset_clocks();
                this->reset_after_update = 0;
            }
            if (this->watch_mode != 0) {
                this->command_view_selected();
            }
            {
                RGE_Player* p = rge_base_game->get_player();
                if (this->game_obj != p->selected_obj ||
                    this->sel_count != rge_base_game->get_player()->sel_count) {
                    this->object_panel->set_object(
                        rge_base_game->get_player()->selected_obj);
                    this->object_changed();
                }
            }
            color_log(0x24, 0x54, 5);
            if (start_paused == 0 &&
                (update_flag == 1 ||
                 this->world->players[this->world->curr_player]->game_status == 2 ||
                 this->player_quit == 1)) {
                if (static_cast<char>(mode) != 5) {
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
                    rge_base_game->set_prog_mode(5);
                    if (panel_system.mouseOwner() != 0) {
                        panel_system.mouseOwner()->release_mouse();
                    }
                    panel_system.setCurrentPanel(s_Game_Screen, 0);
                    this->set_curr_child(this->main_view);
                    static_cast<TRIBE_Game*>(rge_base_game)
                        ->close_game_screens(0);
                    this->pause_text->set_active(1);
                    {
                        RGE_Player* p = rge_base_game->get_player();
                        if (p->game_status == 1) {
                            this->pause_text->set_text(static_cast<long>(0x232C));
                        } else {
                            this->pause_text->set_text(static_cast<long>(0x232D));
                        }
                    }
                    this->main_view->set_redraw(TPanel::RedrawNormal);
                    if (rge_base_game->prog_info->use_sound != 0 &&
                        rge_base_game->sound_system != 0) {
                        TDigital* old = this->game_over_sound;
                        if (old != 0) {
                            delete old;
                        }
                        {
                            RGE_Player* p = rge_base_game->get_player();
                            if (p->game_status == 1) {
                                this->game_over_sound =
                                    new TDigital(rge_base_game->sound_system,
                                                 s_won_wav, 0xC490);
                            } else {
                                this->game_over_sound =
                                    new TDigital(rge_base_game->sound_system,
                                                 s_lost_wav, 0xC491);
                            }
                        }
                        if (this->game_over_sound != 0) {
                            this->game_over_sound->load(0, -1);
                            this->game_over_sound->play();
                        }
                    }
                    this->game_over_time = debug_timeGetTime(s_scr_game_cpp, 0x72C);
                    this->showing_game_over = 1;
                } else {
                    if (this->showing_game_over != 0) {
                        if (debug_timeGetTime(s_scr_game_cpp, 0x734) -
                                               this->game_over_time > 5000) {
                            color_log(0x24, 0x16, 5);
                            this->showing_game_over = 0;
                        if (rge_base_game->multiplayerGame()) {
                            if (rge_base_game->get_paused() == 0) {
                                this->pause_text->set_active(0);
                            }
                            rge_base_game->set_map_visible(1);
                            rge_base_game->set_map_fog(0);
                            this->main_view->set_redraw(TPanel::RedrawImmediate);
                            this->map_view->set_redraw(TPanel::RedrawImmediate);
                            this->quit_message_panel->set_active(1);
                            this->pop_panel->set_active(0);
                        } else {
                            this->main_view->end_scroll_view();
                            this->main_view->set_selection_area(-1, -1, -1, -1);
                            rge_base_game->set_game_mode(0, 0);
                            this->command_unselect();
                            static_cast<TRIBE_Game*>(rge_base_game)->do_game_over();
                            color_log(0x24, 0x5F, 5);
                            return;
                        }
                        }
                    } else {
                        for (i = 1; i < this->world->player_num; i++) {
                            update_flag =
                                this->world->players[i]->game_status;
                            if (update_flag == 0) {
                                break;
                            }
                        }
                    }
                }
            }
            if (this->world->world_time_delta != 0 &&
                static_cast<TRIBE_Game*>(rge_base_game)->auto_exit_time != 0 &&
                static_cast<unsigned long>(this->world->world_time) >=
                    static_cast<unsigned long>(static_cast<TRIBE_Game*>(rge_base_game)->auto_exit_time)) {
                rge_base_game->close();
                color_log(0x24, 0x5F, 5);
                return;
            }
            update_counter += this->world->world_time_delta;
            loop_i++;
        } while (loop_i < calc_game_time);
    }
        }
    }

    if (panel_system.currentPanel() == this) {
        color_log(0x16, 0x4C, 5);
        now = debug_timeGetTime(s_scr_game_cpp, 0x79C);
        if (update_counter > 0) {
            RGE_Player* p = rge_base_game->get_player();
            if (static_cast<int>(p->attributes[6]) != this->save_age) {
                this->age_changed();
            }
            if (this->score_panel[0] != 0 &&
                this->score_panel[0]->active != 0 &&
                now - this->last_score_time >= this->score_interval) {
                this->reset_score_display();
                this->last_score_time = debug_timeGetTime(s_scr_game_cpp, 0x7A8);
            }
        }
        if (this->main_view->get_focus() != 0 ||
            this->curr_child == panel_system.panel(s_Send_Quick_Message_Dialog) ||
            this->curr_child == panel_system.panel(s_Help_Dialog)) {
            color_log(0x16, 0x54, 5);
            if (update_counter > 0 ||
                now - this->last_view_time >= this->view_interval) {
                this->main_view->set_redraw(TPanel::RedrawNormal);
                this->last_view_time = now;
            }
            if (update_counter > 0 &&
                now - this->last_map_redraw_time >= this->map_redraw_interval) {
                this->map_view->set_redraw(TPanel::RedrawNormal);
                this->last_map_redraw_time = now;
            }
            color_log(0x16, 0x24, 5);
            if (this->main_view->need_redraw != 0) {
                rge_base_game->draw_window();
            }
        }
    }

    color_log(0x24, 0x5F, 5);
    return;
}

long TRIBE_Screen_Game::wnd_proc(void* window, unsigned int message,
                                 unsigned int wparam, long lparam) {
    if (message == 0x104 && wparam == 0x79 &&
        this->have_focus != 0 && this->curr_child == this->main_view) {
        this->command_menu();
        return 1;
    }

    if (message == 0x101 && this->have_focus != 0 &&
        this->main_view->get_focus() != 0) {
        if (wparam == 0x72 || wparam == 0x13) {
            short (__stdcall *get_key_state)(int) = GetKeyState;
            int alt = get_key_state(0x12) < 0;
            int ctrl = get_key_state(0x11) < 0;
            int shift = get_key_state(0x10) < 0;
            if (alt == 0 && ctrl == 0 && shift == 0) {
                this->command_pause();
            }
        }
    } else if (message == 0x10) {
        if (confirmed_close == 0) {
            confirmed_close = 1;
            int mode = rge_base_game->prog_mode;
            if (mode == 5 || mode == 4 || mode == 6 || mode == 7) {
                if (IsIconic(this->render_area->Wnd) == 0) {
                    this->popupYesNoDialog(0xC1D, close_confirmation_text,
                                           0x1C2, 100);
                    return 1;
                }
            }
        }
    } else if (message == 0x208) {
        static_cast<TRIBE_Game*>(rge_base_game)->goto_notification_loc();
    }

    return TPanel::wnd_proc(window, message, wparam, lparam);
}

long TRIBE_Screen_Game::handle_mouse_down(unsigned char param1, long param2, long param3, int param4, int param5) {
    message_panel->remove_message();
    message_panel2->remove_message();
    message_panel3->remove_message();
    message_panel4->remove_message();
    message_panel5->remove_message();
    message_panel6->remove_message();
    return TEasy_Panel::handle_mouse_down(param1, param2, param3, param4, param5);
}

long TRIBE_Screen_Game::handle_user_command(unsigned int command, long value) {
    return TPanel::handle_user_command(command, value);
}

void TRIBE_Screen_Game::handle_pause(void) {
    this->pause_text->set_text(0x2329);
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

void TRIBE_Screen_Game::handleChatReceived(int chatIndex)
{
    char chat_msg[256];

    strcpy(chat_msg, chat->GetChatMsg(chatIndex));
    L->Log("$$$ RECEIVED CHAT @%u: %s", this->world->world_time, chat_msg);
    this->chat_panel[this->chat_line]->show_message(
        TMessagePanel::ChatMessage, chat_msg, 0xff, 0, 0, 0, 0);

    this->chat_line++;
    if (this->chat_line >= 8) {
        this->chat_line = 0;
    }
}

void TRIBE_Screen_Game::display_system_message(char* text) {
    this->chat_panel[this->chat_line]->show_message(
        TMessagePanel::ChatMessage, text, 0xFF, 0, 0, 0, 0);
    this->chat_line++;
    if (this->chat_line >= 8) {
        this->chat_line = 0;
    }
}

long TRIBE_Screen_Game::key_down_action(long param_1, short param_2,
                                        int param_3, int param_4, int param_5)
{
    int game_over;
    long result;
    char str[512];

    if (panel_system.modalPanel() != 0) {
        return 0;
    }

    RGE_Panel_Tool_Box* tool_box = this->tool_box;
    if (tool_box->active != 0 &&
        tool_box->key_down_action(param_1, param_2, param_3, param_4, param_5) != 0) {
        return 1;
    }

    game_over = (rge_base_game->prog_mode == 5);

    if (param_4 != 0 && param_5 != 0 && param_3 != 0) {
        if (game_over == 0) {
            if ((param_1 <= 0x7A) && (param_1 >= 0x61)) {
                param_1 -= 0x20;
            } else if (((param_1 > 0x5A) || (param_1 < 0x41)) &&
                       ((param_1 < 0x30) || (param_1 > 0x39))) {
                param_1 = 0;
            }

            if (param_1 != 0) {
                if (this->cheat_code_entry == 0x32) {
                    this->cheat_code_entry_str[0x32] = static_cast<char>(param_1);
                    memcpy(this->cheat_code_entry_str, this->cheat_code_entry_str + 1, 0x33);
                } else {
                    this->cheat_code_entry_str[this->cheat_code_entry] = static_cast<char>(param_1);
                    this->cheat_code_entry++;
                    this->cheat_code_entry_str[this->cheat_code_entry] = 0;
                }

                if (rge_base_game->processCheatCode(this->world->curr_player,
                                                     this->cheat_code_entry_str) != 0) {
                    this->cheat_code_entry = 0;
                    this->cheat_code_entry_str[0] = 0;
                    return 1;
                }
            }
        }
        return 1;
    }

    if (rge_base_game->gameDeveloperMode() != 0 && comm->IsHost() != 0) {
        if (param_4 != 0 && param_5 != 0 &&
            param_1 >= 0x32 && param_1 <= 0x38) {
            comm->Kick(param_1 - 0x30);
            return 1;
        }
    }
    if (param_4 != 0 && param_1 >= 0x30 && param_1 <= 0x39) {
        param_1 -= 0x30;
        this->command_group_by_number(static_cast<int>(param_1));
        return 1;
    }

    if (param_5 != 0) {
        switch (param_1) {
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
            param_1 -= 0x30;
            this->command_select_group(static_cast<int>(param_1), 0);
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
    if (param_3 != 0) {
        switch (param_1) {
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
            param_1 -= 0x30;
            this->command_select_group(static_cast<int>(param_1), 1);
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
    if (param_4 == 0) {
        if (rge_base_game->get_paused() == 0 &&
            rge_base_game->game_mode == 6 &&
            rge_base_game->sub_game_mode == 1) {
            for (int i = 0; i < this->item_cnt; ++i) {
                RGE_Master_Static_Object* master =
                    rge_base_game->get_player()->master_objects[
                        this->bldg_list[i].id];
                if (param_1 == *this->get_string(master->hotkey_id)) {
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

    if (param_4 != 0) {
        int i = 0;
        long* hotkey = this->select_building_hotkey;
        while (i < 8) {
            if (param_1 == *hotkey) {
                this->command_select_building(i);
                return result;
            }
            ++i;
            ++hotkey;
        }
    }

    if (this->view_town_center_hotkey != 0 &&
        param_1 == this->view_town_center_hotkey) {
        this->command_select_building(0);
        return 0;
    }

    if (param_4 != 0) {
        if (rge_base_game->gameDeveloperMode() == 0) {
            return 0;
        }

        switch (param_1) {
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
            panel_system.setCurrentPanel(Save_Game_Screen, 0);
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
            sprintf(str, s_Writing_out_memory_info, ++memory_dump_sequence);
            TRIBE_Game* game = static_cast<TRIBE_Game*>(rge_base_game);
            game->show_status_message(str, 0, -1);
            sprintf(str, s_memory_filename, memory_dump_sequence);
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
            if (rge_base_game->gameDeveloperMode() != 0 &&
                rge_base_game->check_prog_argument(s_ALLOWCTRLU) != 0) {
                L->Log(s_force_ctrl_u);
                displayPathingFlags = (displayPathingFlags == 0);
            }
            break;
        case 0x56:
            new TribeSaveGameScreen(TribeSaveGameScreen::SaveScenario, 0, 0);
            panel_system.setCurrentPanel(Save_Game_Screen, 0);
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
        if (rge_base_game->game_mode != 6 ||
            rge_base_game->sub_game_mode != 1) {
            // a matched work key returns; a miss reaches the next switch.
            if (this->work_hotkey != 0 && param_1 == this->work_hotkey &&
                game_over == 0) {
                if (allow_user_commands != 0) {
                    this->command_work();
                }
                return 0;
            } else if (this->move_hotkey != 0 && param_1 == this->move_hotkey &&
                       game_over == 0) {
                if (allow_user_commands != 0) {
                    this->command_move();
                }
                return 0;
            } else if (this->attack_hotkey != 0 && param_1 == this->attack_hotkey &&
                       game_over == 0) {
                if (allow_user_commands != 0) {
                    this->command_attack();
                }
                return 0;
            } else if (this->ungroup_hotkey != 0 && param_1 == this->ungroup_hotkey) {
                this->command_ungroup();
                return 0;
            }
        }

        // this switch is after the work-key fall-through blocks.
        switch (param_1) {
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
            param_1 = param_1 + (-0x30);
            this->command_select_group(static_cast<int>(param_1), result);
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

long TRIBE_Screen_Game::char_action(long action, short param_2) {
    static_cast<void>(param_2);
    switch (action) {
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

long TRIBE_Screen_Game::action(TPanel* panel, long id,
                               unsigned long p3, unsigned long p4)
{
    if (panel == 0) {
        return TEasy_Panel::action(panel, id, p3, p4);
    }

    RGE_Panel_Tool_Box* tool_box = this->tool_box;
    if (panel != tool_box && tool_box->active != 0 &&
        tool_box->action(panel, id, p3, p4) != 0) {
        return 1;
    }

        if (id == 1 || id == 4) {
            for (int i = 0; i < 17; ++i) {
                if (panel == this->button_panel[i]) {
                    this->do_button_action(p3, p4, id == 4);
                    return 1;
                }
            }
        }

        if (panel == this->object_panel && id == 1) {
            this->object_changed();
            return 1;
        }

    if (panel->panelName() == 0)
        return TEasy_Panel::action(panel, id, p3, p4);

    if (strcmp(panel->panelName(), "RestartDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("RestartDialog");
        if (id != 0) {
            if (rge_base_game->singlePlayerGame() == 1 &&
                rge_base_game->save_paused == 0) {
                rge_base_game->set_paused(0, 0);
            }
            return 1;
        }
        static_cast<TRIBE_Game*>(rge_base_game)->restart_game();
        return 1;
    } else if (strcmp(panel->panelName(), "QuitGameDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("QuitGameDialog");
        if (id == 0) {
            static_cast<TRIBE_Game*>(rge_base_game)->do_game_over();
            return 1;
        }
        confirmed_close = 0;
        if (rge_base_game->singlePlayerGame() == 1 &&
            rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        return 1;
    } else if (strcmp(panel->panelName(), "CloseProgramDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("CloseProgramDialog");
        if (id == 0) {
            rge_base_game->close();
            return 1;
        }
        confirmed_close = 0;
        if (rge_base_game->singlePlayerGame() == 1 &&
            rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        return 1;
    } else if (strcmp(panel->panelName(), "ResignDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("ResignDialog");
        if (id == 0) {
            this->player_quit = 1;
            RGE_Player* player = rge_base_game->get_player();
            player->command_resign(comm->WhoAmI(), id);
            return 1;
        }
        if (rge_base_game->singlePlayerGame() == 1 &&
            rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        return 1;
    } else if (strcmp(panel->panelName(), "QuitAndLoadDialog") == 0) {
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("QuitAndLoadDialog");
        if (id == 0) {
            new TribeLoadSavedGameScreen();
            panel_system.setCurrentPanel("Load Saved Game Screen", 0);
            return 1;
        }
        if (rge_base_game->singlePlayerGame() == 1 &&
            rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        return 1;
    }

    return TEasy_Panel::action(panel, id, p3, p4);
}

void TRIBE_Screen_Game::do_button_action(int action, int value, int flag) {
    if (allow_user_commands != 0) {
        switch (action) {
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
            this->command_trade_with(value);
            return;
        case 0x11:
            this->command_research(value);
            return;
        case 0x12:
            this->command_train(value, flag ? -1 : 1);
            return;
        case 0x13:
            this->command_building(value);
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
            this->command_train(value, 1);
            return;
        case 0x21:
            this->command_train(value, -1);
            return;
        default:
            return;
        }
    }

    switch (action) {
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

void TRIBE_Screen_Game::game_mode_changed(int a, int b) {
    if (this->tool_box != 0) {
        this->tool_box->game_mode_changed(a, b);
    }
    if (this->button_panel[0] != 0) {
        this->reset_buttons();
    }
}

void TRIBE_Screen_Game::player_changed(int old_player, int new_player) {
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
                this->bevel_color2, this->bevel_color3, this->bevel_color4,
                this->bevel_color5, this->bevel_color6);
            this->button_panel[13]->set_bevel_info(3, this->bevel_color1,
                this->bevel_color2, this->bevel_color3, this->bevel_color4,
                this->bevel_color5, this->bevel_color6);
            this->button_panel[14]->set_bevel_info(3, this->bevel_color1,
                this->bevel_color2, this->bevel_color3, this->bevel_color4,
                this->bevel_color5, this->bevel_color6);
            this->button_panel[15]->set_bevel_info(4, this->bevel_color1,
                this->bevel_color2, this->bevel_color3, this->bevel_color4,
                this->bevel_color5, this->bevel_color6);
            this->button_panel[16]->set_bevel_info(4, this->bevel_color1,
                this->bevel_color2, this->bevel_color3, this->bevel_color4,
                this->bevel_color5, this->bevel_color6);

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
            if (this->pnl_wid >= 0x400 && this->pnl_hgt >= 0x300) {
                sprintf(str, s_game_c_format, culture);
                if (culture == 4) {
                    game_pic_id = 0xCF14;
                } else {
                    game_pic_id = culture + 0xC635;
                }
            } else if (this->pnl_wid >= 0x320 && this->pnl_hgt >= 0x258) {
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

            if (this->pnl_wid >= 0x320 && this->pnl_hgt >= 0x258) {
                this->more_cancel_pic = this->button_cmd_pic;
            } else {
                this->more_cancel_pic = this->button_other_pic;
            }

            this->button_panel[5]->set_picture(0, this->more_cancel_pic,
                                                this->more_frame);
            if (this->button_panel[11]->get_id() == 6) {
                this->button_panel[11]->set_picture(0, this->more_cancel_pic,
                                                    this->unselect_frame);
            } else {
                this->button_panel[11]->set_picture(0, this->more_cancel_pic,
                                                    this->cancel_frame);
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
        if (static_cast<char>(mode) != 1 &&
            static_cast<char>(mode) != 0x12 &&
            static_cast<char>(mode) != 0x0E &&
            static_cast<char>(mode) != 2 &&
            static_cast<char>(mode) != 3 &&
            static_cast<char>(mode) != 8 &&
            static_cast<char>(mode) != 9 &&
            static_cast<char>(mode) != 0x0A) {
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
        rge_base_game->get_string2(0x65, this->save_age, 0, str, 0x200);
        this->age_panel->set_text(str);
        this->age_panel->set_redraw(TPanel::RedrawNormal);

        switch (this->save_age) {
        case 1:
            this->age_panel->set_help_info(0x1069, -1);
            break;
        case 2:
            this->age_panel->set_help_info(0x106A, -1);
            break;
        case 3:
            this->age_panel->set_help_info(0x106B, -1);
            break;
        case 4:
            this->age_panel->set_help_info(0x106C, -1);
            break;
        }
    }
}

void TRIBE_Screen_Game::show_timings(char* param_1, char* param_2) {
    char* current = this->fps_panel->get_text();
    if (current == 0 || strcmp(current, param_2) != 0) {
        this->fps_panel->set_text(param_2);
    }
}

void TRIBE_Screen_Game::show_comm(char* p1, char* p2, char* p3, char* p4, char* p5, char* p6) {
    message_panel->show_message(TMessagePanel::DebugMessage, p1, 0x56, 0, 0, 0, 0);
    message_panel2->show_message(TMessagePanel::DebugMessage, p2, 0x56, 0, 0, 0, 0);
    message_panel3->show_message(TMessagePanel::DebugMessage, p3, 0x56, 0, 0, 0, 0);
    message_panel4->show_message(TMessagePanel::DebugMessage, p4, 0x56, 0, 0, 0, 0);
    message_panel5->show_message(TMessagePanel::DebugMessage, p5, 0x56, 0, 0, 0, 0);
    message_panel6->show_message(TMessagePanel::DebugMessage, p6, 0x56, 0, 0, 0, 0);
}

void TRIBE_Screen_Game::show_ai(char* a1, char* a2, char* a3, char* a4, char* a5, char* a6)
{
    this->message_panel->show_message(TMessagePanel::DebugMessage, a1, 0x56, 0, 0, 0, 0);
    this->message_panel2->show_message(TMessagePanel::DebugMessage, a2, 0x56, 0, 0, 0, 0);
    this->message_panel3->show_message(TMessagePanel::DebugMessage, a3, 0x56, 0, 0, 0, 0);
    this->message_panel4->show_message(TMessagePanel::DebugMessage, a4, 0x56, 0, 0, 0, 0);
    this->message_panel5->show_message(TMessagePanel::DebugMessage, a5, 0x56, 0, 0, 0, 0);
    this->message_panel6->show_message(TMessagePanel::DebugMessage, a6, 0x56, 0, 0, 0, 0);
}

void TRIBE_Screen_Game::show_message(TMessagePanel::MessageType type,
                                     char* text, unsigned char a3,
                                     unsigned char a4) {
    this->message_panel->show_message(type, text, a3, a4, 0, 0, 0);
}

void TRIBE_Screen_Game::reset_buttons() {
    this->start_item = 0;
    this->setup_buttons();
}

void TRIBE_Screen_Game::setup_buttons()
{
    char name[512];
    char msg_str[512];
    int culture;
    TShape* final_pic;
    short final_frame;
    long final_type;
    TRIBE_Player* player;
    int set_final_button = 0;

    this->item_cnt = 0;
    this->last_item = -1;

    for (int i0 = 0; i0 < 12; ++i0) {
        this->button_panel[i0]->in_use = 0;
    }

    this->mouse_last_x = -1;
    this->mouse_last_y = -1;

    if (this->game_obj != 0) {
        player = static_cast<TRIBE_Player*>(rge_base_game->get_player());
    culture = player->culture;
    if (culture > 5) {
        culture = 0;
    }
    if ((rge_base_game->game_mode == 6) &&
        (rge_base_game->sub_game_mode == 1)) {
        short building_count;
        short inv_2 = -1;
        short tech_count = -1;

        player->interface_item_avail(&this->bldg_list,
                                     &this->item_cnt, 0x76);
        building_count = this->item_cnt;

        for (short i1 = 0; i1 < building_count; ++i1) {
            if (this->bldg_list[i1].id == 0x6D) {
                inv_2 = i1;
            }
            if (this->bldg_list[i1].id == 0x57) {
                tech_count = i1;
            }
        }

        for (short i2 = 0; i2 < building_count; ++i2) {
            Item_Avail* item = &this->bldg_list[i2];
            RGE_Master_Static_Object* base_master =
                player->master_objects[item->id];
            TRIBE_Master_Building_Object* master =
                static_cast<TRIBE_Master_Building_Object*>(base_master);
            unsigned char button_location =
                static_cast<TRIBE_Master_Combat_Object*>(base_master)
                    ->button_location;

            if ((i2 == inv_2) && (tech_count == -1)) {
                button_location = 6;
            }

            if (this->start_item == 0) {
                if (button_location > 10) {
                    this->start_item = 1;
                    continue;
                }
            } else if (button_location < 11) {
                this->start_item = 1;
                continue;
            }

            rge_base_game->get_string(master->string_id, name + 4, 0x200);
            this->calc_text_msg(msg_str + 4, item, 0x13,
                                master->string_id2);
            short index = this->calc_button_loc(button_location);
            this->set_button(this->button_bldg_pics[culture], index,
                             static_cast<short>(master->building_facet + item->pict),
                             0x13, item->id,
                             master->string_id2 + 100000,
                             item->help_page_id, master->hotkey_id,
                             player->color_table->table, name + 4,
                             msg_str + 4, 0);
        }

        if (this->start_item != 0) {
            this->set_button(this->more_cancel_pic, 5, this->more_frame,
                             0x0C, 0, 0x1D4D7, -1, 0,
                             0, 0, 0, 0);
        }

        final_pic = this->more_cancel_pic;
        final_frame = this->cancel_frame;
        final_type = 0x0B;
        set_final_button = 1;
    } else if ((rge_base_game->game_mode == 0) &&
               (rge_base_game->prog_mode != 5)) {
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
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, 0x4E43, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
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
            } else if (level == 4) {
                short selected = 0;
                int movable = 1;
                short i = 0;

                while ((selected < player->sel_count) && (i < 25)) {
                    RGE_Static_Object* object = player->sel_list[i];
                    if (object != 0) {
                        RGE_Master_Combat_Object* master =
                            static_cast<RGE_Master_Combat_Object*>(
                                object->master_obj);
                        if ((master->missile_id == -1) ||
                            (master->area_effect_range == 0.0f)) {
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
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, 0x4E43, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
            } else if (level == 6) {
                this->set_button(this->button_cmd_pic, 0, 0x0D, 0x1C, 0, 0x1D4F1, -1, 0, 0, 0, 0, 0);
                this->set_button(this->button_cmd_pic, 1, 0x0E, 0x1D, 0, 0x1D4F2, -1, 0, 0, 0, 0, 0);
                if (this->any_selected_have_action()) {
                    this->set_button(this->button_cmd_pic, 2, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                }

                if (player->sel_count > 1) {
                    this->set_button(this->button_cmd_pic, 6, 7, 8, 0, 0x1D4E1, -1, 0, 0, 0, 0, 0);
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, 0x4E43, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
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
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, 0x4E43, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
            } else if (level == 5) {
                this->set_button(this->button_tech_pic, 1, 0x57, 0x19,
                                 0, 0x1A25C, 0x265AF, 0,
                                 0, 0, 0, 0);
                this->set_button(this->button_tech_pic, 2, 0x56, 0x1A,
                                 0, 0x1A25D, 0x265AF, 0,
                                 0, 0, 0, 0);
                this->set_button(this->button_tech_pic, 3, 0x58, 0x1B,
                                 0, 0x1A25E, 0x265AF, 0,
                                 0, 0, 0, 0);
                if (this->any_selected_have_action()) {
                    this->set_button(this->button_cmd_pic, 0, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                }
                if (player->sel_count > 1) {
                    this->set_button(this->button_cmd_pic, 6, 7, 8, 0, 0x1D4E1, -1, 0, 0, 0, 0, 0);
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
            } else if (level == 2) {
                TRIBE_Building_Object* building =
                    static_cast<TRIBE_Building_Object*>(this->game_obj);
                short work_type;
                short work_target;
                short progress;

                building->work_status(work_type, work_target, progress,
                                      name + 4, 0x200);
                if (progress == 100) {
                    work_type = 0;
                }

                unsigned char object_state = building->object_state;
                if (object_state < 2) {
                    this->set_button(this->button_cmd_pic, 0, 3, 0x14, 0, 0x1D4E5, -1, 0, 0, 0, 0, 0);
                    final_pic = this->more_cancel_pic;
                    final_frame = this->unselect_frame;
                    final_type = 6;
                    set_final_button = 1;
                    continue_setup = 0;
                } else if ((object_state == 2) && (work_type == 0x67)) {
                    this->set_button(this->button_cmd_pic, 0, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                    final_pic = this->more_cancel_pic;
                    final_frame = this->unselect_frame;
                    final_type = 6;
                    set_final_button = 1;
                    continue_setup = 0;
                } else if ((object_state == 2) &&
                           ((work_type != 0x66) ||
                            (production_queues_is_use != 0))) {
                    short tech_count_local;
                    short make_count;
                    player->interface_tech_avail(&this->tech_list,
                                                 &tech_count_local,
                                                 building->master_obj->id);
                    player->interface_item_avail(&this->make_list,
                                                 &make_count,
                                                 building->master_obj->id);
                    this->start_item = make_count + tech_count_local;

                    bool show_queue =
                        (production_queues_is_use != 0) &&
                        (building->production_queue_count > 0);
                    if (show_queue) {
                        this->set_button(this->button_cmd_pic, 6, 3, 5, 0, 0x1D4DD, -1, 0, 0, 0, 0, 0);
                    }

                    for (short i3 = 0; i3 < make_count; ++i3) {
                        Item_Avail* item = &this->make_list[i3];
                        RGE_Master_Static_Object* base_master =
                            player->master_objects[item->id];
                        TRIBE_Master_Combat_Object* master =
                            static_cast<TRIBE_Master_Combat_Object*>(base_master);
                        int queued = 0;

                        if (show_queue) {
                            for (short queue_index = 0;
                                 queue_index < building->production_queue_count;
                                 ++queue_index) {
                                Production_Queue_Record& queue =
                                    building->production_queue[queue_index];
                                if (queue.master_id == master->id) {
                                    queued += queue.unit_count;
                                }
                            }
                        }

                        if ((!show_queue) || (queued > 0)) {
                            rge_base_game->get_string(master->string_id,
                                                      name + 4, 0x200);
                            this->calc_text_msg(msg_str + 4, item, 0x12,
                                                master->string_id2);
                            short index = this->calc_button_loc(
                                master->button_location);
                            this->set_button(this->button_unit_pic, index,
                                             item->pict, 0x12, item->id,
                                             master->string_id2 + 100000,
                                             item->help_page_id,
                                             master->hotkey_id,
                                             player->color_table->table,
                                             name + 4, msg_str + 4, 0);
                            if ((!show_queue) || (queued < 1)) {
                                this->button_panel[index]->set_display_garrison(0);
                            } else {
                                this->button_panel[index]->set_display_garrison(1);
                                this->button_panel[index]->set_garrison_number(queued);
                            }
                        }
                    }

                    int tech_disabled = 0;
                    if (show_queue) {
                        continue_setup = 0;
                    } else {
                        if ((building->master_obj->id == 0x6D) &&
                            (tech_count_local == 0) &&
                            (static_cast<int>(rge_base_game->get_player()->attributes[6]) < 4)) {
                            short tech_id =
                                static_cast<short>(
                                    static_cast<int>(rge_base_game->get_player()->attributes[6]) + 100);
                            if (player->tech_tree->get_tech_state(tech_id) != -1) {
                                if (this->tech_list != 0) {
                                    free(this->tech_list);
                                }
                                this->tech_list = static_cast<Item_Avail*>(
                                    calloc(1, sizeof(Item_Avail)));
                                if (this->tech_list != 0) {
                                    tech_count_local = 1;
                                    tech_disabled = 1;
                                    short inv_1;
                                    short amt_1;
                                    short inv_2;
                                    short amt_2;
                                    short inv_3;
                                    short amt_3;
                                    player->tech_tree->tech_cost(
                                        tech_id, &inv_1, &amt_1, &inv_2,
                                        &amt_2, &inv_3, &amt_3);
                                    Tech_Tree* tech =
                                        &this->world->tech->tech_tree[tech_id];
                                    this->tech_list->id = tech_id;
                                    this->tech_list->name = tech->name;
                                    this->tech_list->pict = tech->icon;
                                    this->tech_list->inventory_item_1 = inv_1;
                                    this->tech_list->inventory_cost_1 = static_cast<float>(amt_1);
                                    this->tech_list->inventory_item_2 = inv_2;
                                    this->tech_list->inventory_cost_2 = static_cast<float>(amt_2);
                                    this->tech_list->inventory_item_3 = inv_3;
                                    this->tech_list->inventory_cost_3 = static_cast<float>(amt_3);
                                    this->tech_list->help_string_id =
                                        player->tech_tree->get_help_message(tech_id);
                                    this->tech_list->help_page_id =
                                        player->tech_tree->get_help_page(tech_id);
                                }
                            }
                        }

                        for (int i4 = 0; i4 < tech_count_local; ++i4) {
                            Item_Avail* item = &this->tech_list[i4];
                            short string_id =
                                player->tech_tree->get_string_id(item->id);
                            rge_base_game->get_string(string_id, name + 4,
                                                      0x200);
                            short string_id2 =
                                player->tech_tree->get_string_id2(item->id);
                            this->calc_text_msg(msg_str + 4, item, 0x11,
                                                string_id2);
                            unsigned char button_location =
                                player->tech_tree->get_button_location(item->id);
                            short index = this->calc_button_loc(button_location);
                            this->set_button(this->button_tech_pic, index,
                                             item->pict, 0x11, item->id,
                                             item->help_string_id,
                                             item->help_page_id,
                                             player->tech_tree->get_hotkey(item->id),
                                             player->color_table->table,
                                             name + 4, msg_str + 4,
                                             tech_disabled);
                        }

                        if ((make_count != 0) || (tech_count_local != 0)) {
                            final_pic = this->more_cancel_pic;
                            final_frame = this->unselect_frame;
                            final_type = 6;
                            set_final_button = 1;
                            continue_setup = 0;
                        }
                    }
                }

            }

            if (continue_setup != 0) {
                bool special_selection =
                    (level == 0) && (player->sel_count > 1);
                bool all_known = true;
                bool have_action = false;
                if (special_selection) {
                    short selected = 0;
                    for (short i5 = 0;
                         (i5 < 25) && (selected < player->sel_count); ++i5) {
                        RGE_Action_Object* object =
                            static_cast<RGE_Action_Object*>(player->sel_list[i5]);
                        if (object != 0) {
                            unsigned char object_level = object->master_obj->unit_level;
                            if ((object_level != 3) &&
                                (object_level != 9) &&
                                (object_level != 4) &&
                                (object_level != 5) &&
                                (object_level != 6) &&
                                (object_level != 7) &&
                                (object_level != 8)) {
                                all_known = false;
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
                if (special_selection && all_known) {
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
                    this->set_button(this->button_cmd_pic, 7, 8, 9, 0, 0x4E43, -1, 0, 0, 0, 0, 0);
                } else if (this->game_obj->selected_group != 0) {
                    this->set_button(this->button_cmd_pic, 6, 8, 9, 0, 0x1D4E3, -1, 0, 0, 0, 0, 0);
                }
                final_pic = this->more_cancel_pic;
                final_frame = this->unselect_frame;
                final_type = 6;
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

    }

    if (set_final_button != 0) {
        this->set_button(final_pic, 0x0B, final_frame, final_type, 0,
                         0x1D4D9, -1, 0, 0, 0, 0, 0);
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

char* TRIBE_Screen_Game::calc_text_msg(char* text, Item_Avail* item,
                                       long unused, long command_id) {
    char command_str[512];
    char str[512];
    char cost_str[512];
    char cost_str1[512];
    char cost_str2[512];
    char inven_str[512];

    rge_base_game->get_string(command_id, command_str, 0x200);
    cost_str1[0] = 0;

    if (item != 0) {
        if (item->inventory_item_1 == -1 || item->inventory_item_1 > 3) {
            cost_str2[0] = 0;
        } else {
            rge_base_game->get_string2(0x64, item->inventory_item_1, 0,
                                       str, 0x200);
            sprintf(cost_str2, "%s: %d", str,
                    static_cast<int>(item->inventory_cost_1));
        }

        if (item->inventory_item_2 == -1 || item->inventory_item_2 > 3) {
            inven_str[0] = 0;
        } else {
            rge_base_game->get_string2(0x64, item->inventory_item_2, 0,
                                       str, 0x200);
            sprintf(inven_str, "  %s: %d", str,
                    static_cast<int>(item->inventory_cost_2));
        }

        if (item->inventory_item_3 == -1 || item->inventory_item_3 > 3) {
            cost_str[0] = 0;
        } else {
            rge_base_game->get_string2(0x64, item->inventory_item_3, 0,
                                       str, 0x200);
            sprintf(cost_str, "  %s: %d", str,
                    static_cast<int>(item->inventory_cost_3));
        }

        if (cost_str2[0] != 0 || inven_str[0] != 0 || cost_str[0] != 0) {
            sprintf(cost_str1, "(%s%s%s)", cost_str2, inven_str, cost_str);
        }
    }

    if (command_str[0] != 0 && cost_str1[0] != 0) {
        sprintf(text, "%s %s", command_str, cost_str1);
    } else if (command_str[0] != 0) {
        sprintf(text, "%s", command_str);
    } else {
        text[0] = 0;
    }
    return text;
}

short TRIBE_Screen_Game::calc_button_loc(unsigned char param_1) {
    if (param_1 >= 1 && param_1 <= 5) {
        return param_1 - 1;
    }
    if (param_1 >= 6 && param_1 <= 10) {
        return param_1;
    }
    if (param_1 >= 11 && param_1 <= 15) {
        return param_1 - 0xB;
    }
    if (param_1 >= 16 && param_1 <= 20) {
        return param_1 - 0xA;
    }
    return 0;
}

void TRIBE_Screen_Game::set_button(
    TShape* picture, short index, short frame,
    long id, long id2, long string_id, long help_page_id,
    long hotkey_id, unsigned char* color_table,
    char* name, char* text, int disabled_value) {
    char text1[512];
    TRIBE_Panel_Button* button = this->button_panel[index];

    button->in_use = 1;
    if (button->disabled != disabled_value) {
        button->set_disabled(disabled_value);
    }

    if (button->get_id() != id || button->get_id2() != id2) {
        button->reset();
        button->set_display_garrison(0);
        rge_base_game->get_string2(0x66, id, id2, text1, 0x200);
        button->set_picture(0, picture, frame);
        button->set_id(0, id, id2);
        button->color_table = color_table;
        button->set_text(0, text1, name);
        button->set_help_info(string_id, help_page_id);

        if (text != 0) {
            button->set_text_msg(text);
        } else {
            button->set_text_msg(text1);
        }

        if (id == 0x11) {
            button->border_frame = 2;
        } else {
            button->border_frame = 0;
        }

        switch (id) {
        case 3:
            hotkey_id = 0x1037;
            break;
        case 5:
            hotkey_id = 0x1038;
            break;
        case 8:
            hotkey_id = 0x1039;
            break;
        case 9:
            hotkey_id = 0x103A;
            break;
        case 0x0C:
            hotkey_id = 0x103B;
            break;
        case 0x16:
            hotkey_id = 0x103D;
            break;
        case 0x17:
            hotkey_id = 0x103E;
            break;
        case 0x1C:
            hotkey_id = 0x1048;
            break;
        case 0x1D:
            hotkey_id = 0x1049;
            break;
        case 1:
            hotkey_id = 0x104B;
            break;
        case 2:
            hotkey_id = 0x104A;
            break;
        case 0x1E:
            hotkey_id = 0x104C;
            break;
        case 0x1F:
            hotkey_id = 0x104D;
            break;
        case 7:
            hotkey_id = 0x104E;
            break;
        }

        if (hotkey_id != 0) {
            hotkey_id = static_cast<int>(*this->get_string(hotkey_id));
        }
        if (id == 6 || id == 0x0B) {
            hotkey_id = 0x1B;
        }

        button->hotkey = hotkey_id;
        button->hotkey_shift = 0;
        button->set_active(1);
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
        do {
            TRIBE_Player* player = static_cast<TRIBE_Player*>(
                this->world->players[player_id]);
            long countdown_timer;
            rge_base_game->get_countdown_timer(player_id, countdown_timer);
            if (countdown_timer > 0) {
                this->countdown_clock[clock_count]->set_clock_type(4, player_id);
                ++clock_count;
                if (clock_count > 9) {
                    break;
                }
            }

            if (player->artifact_held_time != -1.0f) {
                int countdown = 0;
                if (player->allied_victory != 0) {
                    int other_player = 1;
                    if (player_id > 1) {
                        do {
                            RGE_Player* other =
                                this->world->players[other_player];
                            if (player->relation(other_player) == 0 &&
                                other->relation(player_id) == 0 &&
                                other->allied_victory != 0) {
                                countdown = 1;
                                break;
                            }
                            ++other_player;
                        } while (other_player < player_id);
                    }
                }

                if (countdown == 0) {
                    this->countdown_clock[clock_count]->set_clock_type(5, player_id);
                    ++clock_count;
                    if (clock_count > 9) {
                        break;
                    }
                }
            }

            if (player->ruin_held_time != -1.0f) {
                int countdown = 0;
                if (player->allied_victory != 0) {
                    int other_player = 1;
                    if (player_id > 1) {
                        do {
                            RGE_Player* other =
                                this->world->players[other_player];
                            if (player->relation(other_player) == 0 &&
                                other->relation(player_id) == 0 &&
                                other->allied_victory != 0) {
                                countdown = 1;
                                break;
                            }
                            ++other_player;
                        } while (other_player < player_id);
                    }
                }

                if (countdown == 0) {
                    this->countdown_clock[clock_count]->set_clock_type(6, player_id);
                    ++clock_count;
                    if (clock_count > 9) {
                        break;
                    }
                }
            }

            ++player_id;
        } while (player_id < this->world->player_num);
    }

    if (clock_count < 10) {
        for (; clock_count < 10; ++clock_count) {
            this->countdown_clock[clock_count]->set_clock_type(0, 0);
        }
    }
}

int scr_game_score_compare(const void* param_b, const void* param_a) {
    const PLAYER_SCORE* a = static_cast<const PLAYER_SCORE*>(param_a);
    const PLAYER_SCORE* b = static_cast<const PLAYER_SCORE*>(param_b);

    if (a->team_score > b->team_score) return 1;
    if (a->team_score < b->team_score) return -1;
    if (a->team_id > b->team_id) return 1;
    if (a->team_id < b->team_id) return -1;
    if (a->player_score > b->player_score) return 1;
    if (a->player_score < b->player_score) return -1;
    if (a->player_id > b->player_id) return 1;
    return (a->player_id >= b->player_id) - 1;
}

void TRIBE_Screen_Game::reset_score_display()
{
    int i;
    int j;
    int local_2d4;
    int team;
    int icon_num2;
    int low_fps_player;
    TShape* icon1;
    int icon_frame1;
    TShape* icon2;
    int icon_frame2;
    PLAYER_SCORE player_score[9];
    char str[512];

    for (i = 0; i < 9; ++i) {
        player_score[i].comm_id = 0;
        player_score[i].player_id = 0;
        player_score[i].team_id = 0;
        player_score[i].player_score = 0;
        player_score[i].team_score = 0;
    }

    i = 0;
    for (icon_num2 = 1; icon_num2 <= rge_base_game->numberPlayers(); ++icon_num2) {
        PLAYER_SCORE& score = player_score[icon_num2 - 1];
        int player_id = rge_base_game->playerID(icon_num2);
        if (player_id != 0 && player_id < this->world->player_num) {
            if (score.team_id == 0) {
                ++i;
                score.team_id = i;
            }
            score.comm_id = icon_num2;
            score.player_id = player_id;
            score.player_score =
                this->world->players[player_id]->victory_conditions->get_victory_points();
            score.team_score = score.player_score;
            local_2d4 = 1;

            if (this->world->players[player_id]->allied_victory != 0) {
                for (int team_player = 1;
                     team_player <= rge_base_game->numberPlayers(); ++team_player) {
                    if (team_player != icon_num2) {
                        PLAYER_SCORE& team_score = player_score[team_player - 1];
                        int player_id2 = rge_base_game->playerID(team_player);
                        if (player_id2 != 0 && player_id2 < this->world->player_num &&
                            this->world->players[player_id]->relation(player_id2) == 0 &&
                            this->world->players[player_id2]->relation(player_id) == 0 &&
                            this->world->players[player_id2]->allied_victory != 0) {
                            if (team_score.team_id == 0) {
                                team_score.team_id = score.team_id;
                            }
                            score.team_score +=
                                this->world->players[player_id2]->victory_conditions->get_victory_points();
                            ++local_2d4;
                        }
                    }
                }
            }
            score.team_score /= local_2d4;
        }
    }

    qsort(player_score, rge_base_game->numberPlayers(), sizeof(PLAYER_SCORE),
          scr_game_score_compare);
    low_fps_player = 0;
    if (rge_base_game->multiplayerGame() != 0) {
        int low_fps = 11;
        for (j = 0; j < 8; ++j) {
            PLAYER_SCORE& score = player_score[j];
            if (score.player_id != 0 && comm->GetPlayerHumanity(score.comm_id) == 2) {
                unsigned long average =
                    comm->Speed->GetPlayerAvgFramesMsec(score.comm_id);
                int frame_rate;
                if (average > 999) {
                    frame_rate = 1;
                } else if (average < 10) {
                    frame_rate = 100;
                } else {
                    frame_rate = 1000 / average;
                }
                if (frame_rate < low_fps) {
                    low_fps_player = score.comm_id;
                    low_fps = frame_rate;
                }
            }
        }
    }

    icon_num2 = 0;
    for (; icon_num2 < 8; ++icon_num2) {
        PLAYER_SCORE* p = &player_score[icon_num2];
        TMessagePanel* panel = this->score_panel[icon_num2];
        if (panel == 0) {
            return;
        }
        if (p->player_id == 0) {
            panel->visible = 0;
        } else {
            sprintf(str + 4, "%s: %d/%d", comm->GetPlayerName(p->comm_id),
                    p->player_score, p->team_score);

            RGE_Player* player = this->world->players[p->player_id];
            int font_color;
            int back_color;
            switch (player->color_table->id) {
            case 0:
                font_color = 0xFF0000;
                back_color = 0xB3B3B3;
                break;
            case 1: font_color = 0x2139C6; break;
            case 2: font_color = 0xFFFF; break;
            case 3: font_color = 0x4F73A3; break;
            case 4: font_color = 0x0F77F3; break;
            case 5: font_color = 0xC700; break;
            case 6: font_color = 0x7B90A2; break;
            case 7: font_color = 0xADAD00; break;
            default: font_color = 0xFFFFFF; break;
            }

            int dimmed = 0;
            if (player->game_status == 2) {
                dimmed = 1;
            } else if (rge_base_game->multiplayerGame() != 0) {
                int humanity = comm->GetPlayerHumanity(p->comm_id);
                if (humanity != 2 && humanity != 4) {
                    dimmed = 1;
                }
            }
            RGE_Font* font = rge_base_game->get_font(dimmed != 0 ? 8 : 11);

            icon1 = 0;
            icon_frame1 = 0;
            icon2 = 0;
            icon_frame2 = 0;
            if (rge_base_game->multiplayerGame() != 0 &&
                comm->GetPlayerHumanity(p->comm_id) == 2) {
                unsigned long latency = comm->Speed->GetPlayerLatency(p->comm_id);
                if (p->comm_id == low_fps_player) {
                    icon2 = this->button_pics;
                    icon_frame2 = 17;
                }
                if (latency >= 300) {
                    icon1 = this->button_pics;
                    icon_frame1 = 20;
                    if (latency <= 1000) {
                        icon_frame1 = 19;
                    }
                }
            }

            panel->show_message2(TMessagePanel::RightInfoMessage, str + 4, font_color, back_color,
                                 font->font, font->font_wid, font->font_hgt,
                                 icon1, icon_frame1, icon2, icon_frame2);
        }
    }
}

void TRIBE_Screen_Game::draw()
{
    if (byte_62C584) {
        tagRECT* r = &this->clip_rect;
        tagRECT old = *r;
        this->draw_setup(0);
        if (this->inven_panel) {
            if (this->render_area->Lock(s_scr_game_draw, 1)) {
                TPanel* panel = this->inven_panel;
                tagRECT panel_rect = panel->render_rect;
                this->render_area->FillRect(panel_rect.left, panel_rect.top,
                                     panel_rect.right, panel_rect.bottom, 0x74);
                this->render_area->Unlock(s_scr_game_draw);
                if (this->clip_rect.top < panel_rect.bottom)
                    this->clip_rect.top = panel_rect.bottom;
                this->render_area->SetClipRect(r);
            }
        }
        if (this->game_screen_pic) {
            if (this->render_area->Lock(s_scr_game_draw2, 1)) {
                if (this->pnl_wid >= 0x400 && this->pnl_hgt >= 0x300) {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0x282, 1, 0, 0);
                } else if (this->pnl_wid >= 0x320 && this->pnl_hgt >= 0x258) {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0x1da, 1, 0, 0);
                } else {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0x162, 1, 0, 0);
                }
                this->render_area->Unlock(s_scr_game_draw2);
            }
        }
        this->draw_finish();
        *r = old;
        this->render_area->SetClipRect(r);
    } else {
        int flag;
        if (this->need_redraw != 2 && this->game_screen_pic) flag = 0;
        else flag = 1;
        this->draw_setup(flag);
        if (this->game_screen_pic) {
            if (this->render_area->Lock(s_scr_game_draw3, 1)) {
                if (this->pnl_wid >= 0x400 && this->pnl_hgt >= 0x300) {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0x282, 1, 0, 0);
                } else if (this->pnl_wid >= 0x320 && this->pnl_hgt >= 0x258) {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0x1da, 1, 0, 0);
                } else {
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0, 0, 0, 0);
                    this->game_screen_pic->shape_draw(this->render_area, 0, 0x162, 1, 0, 0);
                }
                this->render_area->Unlock(s_scr_game_draw3);
            }
        }
        this->draw_finish();
    }
}


void TRIBE_Screen_Game::handle_anim_pal()
{
    unsigned long time;
    PALETTEENTRY pal_entries[7];

    time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x11EB);
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

        this->render_area->DrawSystem->ModifyPalette(0xF8, 7, pal_entries);
        this->last_anim_pal_time = time;
    }
}

void TRIBE_Screen_Game::handle_terrain_sound() {
    color_log(0x54, 0x16, 4);

    if (rge_base_game->prog_info->use_sound != 0 &&
        rge_base_game->sound_system != 0 &&
        disable_terrain_sounds == 0) {
        unsigned long now =
            debug_timeGetTime(s_scr_game_cpp, 0x121D);

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

        if (now - this->last_terrain_sound_time <
            this->terrain_sound_interval)
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
            if (terrain->loaded != 0 &&
                terrain->drawn > best_drawn &&
                terrain->sound != 0) {
                best_index = index;
                best_drawn = terrain->drawn;
            }
        }

        if (best_index != -1) {
            char* file_name =
                map->terrain_types[best_index].sound->get_file_name();
            if (file_name != 0) {
                color_log(0x54, 0x4C, 4);
                debug_timeGetTime(s_scr_game_cpp, 0x125B);
                rge_base_game->sound_system->stop_stream();
                rge_base_game->sound_system->stream_file(file_name, 0, 0);
                color_log(0x54, 0x32, 4);
                this->terrain_playing = 1;
                this->terrain_sound_start_time =
                    debug_timeGetTime(s_scr_game_cpp, 0x1262);
            } else {
                color_log(0x54, 0x5F, 4);
                return;
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

    if (this->text_line_panel->showing_message == 0) {
        this->text_line_panel->remove_message();
    }

    if (point.x < 0 || point.x >= this->pnl_wid ||
        point.y < 0 || point.y > this->pnl_hgt) {
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
        TRIBE_Panel_Button* button = this->button_panel[i];
        if (button->active != 0 && button->get_id() != -1 &&
            button->hit_button(point.x, point.y) != 0) {
            found = i;
            break;
        }
        ++i;
    }

    if (found != -1) {
        this->text_line_panel->show_message(
            TMessagePanel::InfoMessage, this->button_panel[found]->text_msg,
            0xFF, 0, 0, 0, 0);
    }
}

void TRIBE_Screen_Game::command_add_attribute(int value) {
    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->allowCheatCodes() != 0) {
            RGE_Player* player = rge_base_game->get_player();
            player->command_add_attribute(value, 1000.0f);
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
    this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(0xBE2), 0x32, 0, 0, 0, 0);
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

void TRIBE_Screen_Game::command_building(int obj_id) {
    short attr;
    char msg[512];

    int paused = rge_base_game->get_paused();
    if (paused == 0) {
        if (static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->check_obj_cost(obj_id, &attr, 1.0f, paused)) {
            RGE_Base_Game* game = rge_base_game;
            game->master_obj_id = obj_id;
            TRIBE_Player* player =
                static_cast<TRIBE_Player*>(rge_base_game->get_player());
            RGE_Master_Static_Object* object = player->master_objects[obj_id];
            TRIBE_Master_Building_Object* building =
                static_cast<TRIBE_Master_Building_Object*>(object);
            if (building->building_connect_flag) {
                rge_base_game->set_game_mode(0x15, 0);
                return;
            }
            rge_base_game->set_game_mode(7, 0);
            return;
        } else {
            rge_base_game->get_string2(0x67, 1, static_cast<int>(attr), msg, 0x200);
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
    if (game_ended == 0 && rge_base_game->prog_mode == 5) {
        message_panel->show_message(
            TMessagePanel::BadMessage, get_string(0xBFE), 0x32,
            0, 0, 0, 0);
        return;
    }
    new TribeSendMessageDialog(this);
}

void TRIBE_Screen_Game::command_quick_chat() {
    if (game_ended == 0 && rge_base_game->prog_mode == 5) {
        message_panel->show_message(
            TMessagePanel::BadMessage, get_string(0xBFE), 0x32,
            0, 0, 0, 0);
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
    this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(0xBE4), 0x32, 0, 0, 0, 0);
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

void TRIBE_Screen_Game::command_game_speed(int param_1) {
    float cur_speed;
    float old_speed;

    unsigned long t = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x13FE);
    if (t - this->last_game_speed_change < 1000) {
        if (rge_base_game->singlePlayerGame() == 0) {
            return;
        }
    }

    this->last_game_speed_change = t;
    if (rge_base_game->prog_mode != 5) {
        cur_speed = 0.0f;
        old_speed = this->world->game_speed;

        if (param_1 != 0) {
            if (old_speed == 1.0f) {
                cur_speed = 1.5f;
            } else if (old_speed == 1.5f) {
                cur_speed = 2.0f;
            } else {
                if (rge_base_game->singlePlayerGame() != 0 &&
                    rge_base_game->gameDeveloperMode() != 0) {
                    if (old_speed == 2.0f) {
                        cur_speed = 4.0f;
                    } else if (old_speed == 4.0f) {
                        cur_speed = 8.0f;
                    } else if (old_speed == 8.0f) {
                        cur_speed = 16.0f;
                    }
                }
            }
        } else {
            if (old_speed == 16.0f) {
                cur_speed = 8.0f;
            } else if (old_speed == 8.0f) {
                cur_speed = 4.0f;
            } else if (old_speed == 4.0f) {
                cur_speed = 2.0f;
            } else if (old_speed == 2.0f) {
                cur_speed = 1.5f;
            } else if (old_speed == 1.5f) {
                cur_speed = 1.0f;
            }
        }

        if (cur_speed != 0.0f) {
            if (rge_base_game->multiplayerGame() != 0) {
                char message[256];
                const char* text = this->get_string(0xBF3);
                sprintf(message, text);
                comm->SendChatMsgAll(message);
            }

            static_cast<TRIBE_Command*>(this->world->commands)
                ->command_game_speed(cur_speed);
            if (rge_base_game->singlePlayerGame() != 0) {
                rge_base_game->set_game_speed(cur_speed);
            }
        }
    }
}

void TRIBE_Screen_Game::command_group(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->get_player()->group_objects(-1);
    }
}

void TRIBE_Screen_Game::command_group_by_number(int group) {
    if (rge_base_game->get_paused() == 0) {
        if (group == 0) {
            group = 10;
        }
        (rge_base_game->get_player())->group_objects(group);
    }
}

void TRIBE_Screen_Game::command_heal(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }

    this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(0xBE3), 0x32, 0, 0, 0, 0);
        rge_base_game->set_game_mode(0x66, 0);
}

void TRIBE_Screen_Game::command_repair(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }
    this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(0xBEC), 0x32, 0, 0, 0, 0);
    // This command uses the set_game_mode virtual slot.
    rge_base_game->set_game_mode(0x68, 0);
}

void TRIBE_Screen_Game::command_score(int a1)
{
    this->world->score_displayed = static_cast<unsigned char>(a1);
    int score_count = 8;
    TMessagePanel** score_panel = this->score_panel;
    do {
        TMessagePanel* b = *score_panel;
        if (b != 0) {
            b->set_active(a1);
        }
        ++score_panel;
        --score_count;
    } while (score_count != 0);

    if (a1 != 0) {
        this->reset_score_display();
    }

    if (this->world->score_displayed != 0) {
        this->text_line_panel->set_positioning(TPanel::PositionLeftBottom, 4, 0, 0xB8, 4, 0, 0, 0x22, 0x22,
                                               0, 0, 0, 0);
    } else {
        this->text_line_panel->set_positioning(TPanel::PositionLeftBottom, 4, 0, 4, 4, 0, 0, 0x22, 0x22,
                                               0, 0, 0, 0);
    }
    this->main_view->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Screen_Game::command_select_group(int group, int unselect) {
    if (rge_base_game->get_paused()) {
        return;
    }
    if (unselect != 0) {
        rge_base_game->get_player()->unselect_object();
    }
    if (group == 0) {
        group = 10;
    }
    rge_base_game->get_player()->select_group(group);
    this->main_view->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Screen_Game::command_menu() {
    if (rge_base_game->prog_mode == 6) {
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
        this->last_item = (this->last_item != 0) ? 0 : 10;
        this->setup_buttons();
        return;
    }

    if (this->last_item < this->start_item - 1) {
        this->last_item = this->last_item + 1;
        this->setup_buttons();
        return;
    }

    this->last_item = 0;
    this->setup_buttons();
}

void TRIBE_Screen_Game::command_move() {
    RGE_Static_Object** list;
    short list_num;

    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->get_player()->get_selected_objects_to_command(
                &list, &list_num, -1, -1, -1, -1)) {
            free(list);
            this->message_panel->show_message(
                TMessagePanel::BadMessage, this->get_string(0xBE0),
                0x32, 0, 0, 0, 0);
            rge_base_game->set_game_mode(4, 0);
        }
    }
}

void TRIBE_Screen_Game::command_outline() {
    RGE_Base_Game* game;
    unsigned char t;

    game = rge_base_game;
    t = game->outline_type;
    switch (t) {
    case 0:
    case 3:
        t = 2;
        break;
    case 2:
        t = 1;
        break;
    case 1:
        t = 0;
        break;
    }
    game->outline_type = t;
}

void TRIBE_Screen_Game::command_pause() {
    char msg[256];
    unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x14F2);

    if (t - last_pause_change < 1000) {
        if (rge_base_game->singlePlayerGame() == 0) {
            return;
        }
    }

    last_pause_change = t;

    if (rge_base_game->prog_mode != 5) {
        if (rge_base_game->multiplayerGame() != 0) {
            const char* s = get_string(0xBF4);
            sprintf(msg, s);
            comm->SendChatMsgAll(msg);
        }
        rge_base_game->request_pause();
    }
}

void TRIBE_Screen_Game::command_player(int param_1) {
    if (!rge_base_game->allowCheatCodes()) {
        return;
    }

    rge_base_game->get_player()->unselect_object();
    this->main_view->set_redraw(TPanel::RedrawNormal);

    if (rge_base_game->game_mode == 6 && rge_base_game->sub_game_mode == 1) {
        rge_base_game->set_game_mode(0, 0);
    }

    rge_base_game->set_player(static_cast<short>(param_1));
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

void TRIBE_Screen_Game::command_research(int tech_id) {
    short attr;
    char msg[512];

    if (rge_base_game->get_paused() == 0) {
        if (static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->check_tech_cost(static_cast<short>(tech_id), &attr)) {
            static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->command_building_make_tech(static_cast<short>(tech_id));
            return;
        }
        rge_base_game->get_string2(0x67, 1, static_cast<int>(attr), msg, 0x200);
        this->message_panel->show_message(TMessagePanel::BadMessage, msg,
                                          0x56, 0, 0, 0, 0);
    }
}

void TRIBE_Screen_Game::command_save_game() {
    if (rge_base_game->prog_mode == 6) {
        static_cast<TRIBE_Command*>(this->world->commands)->do_commands();
    }
    new TribeSaveGameScreen(TribeSaveGameScreen::SaveGame, 0, 0);
    panel_system.setCurrentPanel(Save_Game_Screen, 0);
}

void TRIBE_Screen_Game::command_save_scenario() {
    if (rge_base_game->prog_mode == 6) {
        static_cast<TRIBE_Command*>(this->world->commands)->do_commands();
    }
    new TribeSaveGameScreen(TribeSaveGameScreen::SaveScenario, 0, 0);
    panel_system.setCurrentPanel(s_Save_Game_Screen, 0);
}

void TRIBE_Screen_Game::command_select_building(int value) {
    int object_id;

    if (rge_base_game->get_paused() == 0) {
        switch (value) {
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
        if (selected == 0 ||
            rge_base_game->get_player()->selected_obj->master_obj->id !=
                object_id) {
            obj = static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->find_obj(static_cast<short>(object_id), 0);
        } else {
            obj = static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->find_obj(static_cast<short>(object_id),
                           rge_base_game->get_player()->selected_obj);
        }
        if (obj != 0) {
            rge_base_game->get_player()->unselect_object();
            rge_base_game->get_player()->select_object(obj);
            rge_base_game->get_player()->set_view_loc(obj->world_x, obj->world_y);
            rge_base_game->get_player()->set_map_loc(
                static_cast<short>(static_cast<int>(obj->world_x)),
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

void TRIBE_Screen_Game::command_trade_with(int p0) {}

void TRIBE_Screen_Game::command_train(int player_id, short train_id) {
    short attr;
    char msg[512];

    if (rge_base_game->get_paused() == 0) {
        if (production_queues_is_use) {
            static_cast<TRIBE_Command*>(this->world->commands)
                ->command_queue(this->game_obj, player_id, train_id);
            return;
        }
        if (static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->check_obj_cost(static_cast<short>(player_id), &attr, 1.0f, 0)) {
            RGE_Base_Game* game = rge_base_game;
            game->master_obj_id = static_cast<short>(player_id);
            static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->command_building_make_obj(static_cast<short>(player_id));
            return;
        }
        rge_base_game->get_string2(0x67, 1, static_cast<int>(attr), msg, 0x200);
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
        this->message_panel->show_message(TMessagePanel::BadMessage,
                                          this->get_string(0xBED),
                                          0x32, 0, 0, 0, 0);
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

    rge_base_game->get_player()->set_view_loc(
        selected->world_x, selected->world_y);
    rge_base_game->get_player()->set_map_loc(
        static_cast<short>(static_cast<int>(selected->world_x)),
        static_cast<short>(static_cast<int>(selected->world_y)));
}

void TRIBE_Screen_Game::command_view_tribe()
{
    if (rge_base_game->get_paused() == 0) {
        RGE_Static_Object* obj =
            static_cast<TRIBE_Player*>(rge_base_game->get_player())
                ->find_obj(0x6d, 0);
        if (obj != 0) {
            rge_base_game->get_player()->unselect_object();
            rge_base_game->get_player()->select_object(obj);
            rge_base_game->get_player()->set_view_loc(obj->world_x, obj->world_y);
            rge_base_game->get_player()->set_map_loc(
                static_cast<short>(static_cast<int>(obj->world_x)),
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
        if (rge_base_game->get_player()->get_selected_objects_to_command(
                &list, &list_num, -1, -1, -1, -1)) {
            free(list);
            this->message_panel->show_message(
                TMessagePanel::BadMessage, this->get_string(0xBE1),
                0x32, 0, 0, 0, 0);
            rge_base_game->set_game_mode(5, 0);
        }
    }
}

void TRIBE_Screen_Game::command_formation(int value) {
    if (rge_base_game->get_paused() == 0) {
        (rge_base_game->get_player())->command_formation(value);
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
    this->message_panel->show_message(TMessagePanel::BadMessage, this->get_string(0xBE5), 0x32, 0, 0, 0, 0);
    // This command uses the set_game_mode virtual slot.
    rge_base_game->set_game_mode(0x64, 0);
}

void TRIBE_Screen_Game::command_trade_attribute(long value) {
    if (rge_base_game->get_paused() == 0) {
        static_cast<TRIBE_Player*>(rge_base_game->get_player())
            ->command_trade_attribute(value);
    }
}

void TRIBE_Screen_Game::command_tab_selected(int value) {
    RGE_Player* player = rge_base_game->get_player();
    int found = 0;
    RGE_Static_Object* candidate = 0;
    int paused = rge_base_game->get_paused();

    if (paused == 0) {
        short selected_count = player->sel_count;
        if (selected_count >= 2) {
            short slot;
            short count;
            if (value != 0) {
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
    TRIBE_Player* player = static_cast<TRIBE_Player*>(
        rge_base_game->get_player());
    int slot = 0;
    int index = 0;
    while (slot < 25) {
        if (index >= player->sel_count) {
            return 0;
        }
        RGE_Action_Object* object =
            static_cast<RGE_Action_Object*>(player->sel_list[slot]);
        if (object != 0) {
            unsigned char type = object->master_obj->unit_level;
            if (type >= 0x28 && type <= 0x50 &&
                object->have_action() != 0) {
                return 1;
            }
            ++index;
        }
        ++slot;
    }
    return 0;
}

void TRIBE_Screen_Game::set_focus(int value) {
    TScreenPanel::set_focus(value);
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

void TRIBE_Screen_Game::add_log(char* p0) {}
