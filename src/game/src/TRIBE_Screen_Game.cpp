#include "../include/TRIBE_Screen_Game.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Diamond_Map.h"
#include "../include/TRIBE_Diamond_Map_View.h"
#include "../include/RGE_Font.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Panel_Tool_Box.h"
#include "../include/RGE_View.h"
#include "../include/TChat.h"
#include "../include/TDrawSystem.h"
#include "../include/TDigital.h"
#include "../include/TMessagePanel.h"
#include "../include/TShape.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TTextPanel.h"
#include "../include/TRIBE_Main_View.h"
#include "../include/TRIBE_Panel_Button.h"
#include "../include/TRIBE_Panel_Inven.h"
#include "../include/TRIBE_Panel_Object.h"
#include "../include/TRIBE_Panel_Pop.h"
#include "../include/TRIBE_Panel_Time.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_Game.h"
#include "../include/TRIBE_World.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/TCommunications_Handler.h"
#include "../include/RGE_Communications_Speed.h"
#include "../include/custom_debug.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int rects_overlap(const tagRECT& a, const tagRECT& b) {
    if (a.right < b.left || b.right < a.left) {
        return 0;
    }
    if (a.bottom < b.top || b.bottom < a.top) {
        return 0;
    }
    return 1;
}

struct SCR_GAME_PLAYER_SCORE {
    int player_id;
    int game_player_id;
    int team_id;
    int score;
    int average_score;
};

static int __cdecl scr_game_score_compare(const void* param_1, const void* param_2) {
    const SCR_GAME_PLAYER_SCORE* score1 = (const SCR_GAME_PLAYER_SCORE*)param_1;
    const SCR_GAME_PLAYER_SCORE* score2 = (const SCR_GAME_PLAYER_SCORE*)param_2;

    if (score1->average_score < score2->average_score) {
        return 1;
    }
    if (score2->average_score < score1->average_score) {
        return -1;
    }
    if (score1->team_id < score2->team_id) {
        return 1;
    }
    if (score2->team_id < score1->team_id) {
        return -1;
    }
    if (score1->score < score2->score) {
        return 1;
    }
    if (score2->score < score1->score) {
        return -1;
    }
    if (score1->game_player_id < score2->game_player_id) {
        return 1;
    }
    return (score1->game_player_id <= score2->game_player_id) ? 0 : -1;
}

static void scr_game_get_score_colors(short color_index, ulong* color1, ulong* color2) {
    if (color1 == nullptr || color2 == nullptr) {
        return;
    }

    *color2 = 0;
    switch (color_index) {
    case 0:
        *color1 = 0xFF0000;
        *color2 = 0xB3B3B3;
        return;
    case 1:
        *color1 = 0x2139C6;
        return;
    case 2:
        *color1 = 0xFFFF;
        return;
    case 3:
        *color1 = 0x4F73A3;
        return;
    case 4:
        *color1 = 0x0F77F3;
        return;
    case 5:
        *color1 = 0xC700;
        return;
    case 6:
        *color1 = 0x7B90A2;
        return;
    case 7:
        *color1 = 0xADAD00;
        return;
    default:
        *color1 = 0xFFFFFF;
        return;
    }
}

static TShape* load_shape_checked(const char* name, long id) {
    TShape* shape = new TShape((char*)name, id);
    if (shape == nullptr) {
        return nullptr;
    }

    if (shape->is_loaded() == 0) {
        delete shape;
        return nullptr;
    }

    return shape;
}

static void delete_shape_safe(TShape*& shape) {
    if (shape != nullptr) {
        delete shape;
        shape = nullptr;
    }
}

static void delete_panel_safe(TPanel*& panel) {
    if (panel != nullptr) {
        delete panel;
        panel = nullptr;
    }
}

static int& scr_game_field_i32(TRIBE_Screen_Game* self, size_t offset) {
    return *(int*)((unsigned char*)self + offset);
}

static ulong& scr_game_field_u32(TRIBE_Screen_Game* self, size_t offset) {
    return *(ulong*)((unsigned char*)self + offset);
}

static short& scr_game_field_i16(TRIBE_Screen_Game* self, size_t offset) {
    return *(short*)((unsigned char*)self + offset);
}

static void scr_game_set_info_file(TEasy_Panel* panel, const char* file_name, long info_id) {
    panel->info_id = info_id;
    if (file_name != nullptr) {
        strncpy(panel->info_file_name, file_name, sizeof(panel->info_file_name) - 1);
        panel->info_file_name[sizeof(panel->info_file_name) - 1] = '\0';
    } else {
        panel->info_file_name[0] = '\0';
    }
}

static void scr_game_set_popup_info_file(TEasy_Panel* panel, const char* file_name, long info_id) {
    panel->popup_info_id = info_id;
    if (file_name != nullptr) {
        strncpy(panel->popup_info_file_name, file_name, sizeof(panel->popup_info_file_name) - 1);
        panel->popup_info_file_name[sizeof(panel->popup_info_file_name) - 1] = '\0';
    } else {
        panel->popup_info_file_name[0] = '\0';
    }
}

static void scr_game_set_button_pics(TEasy_Panel* panel, const char* file_name, long pic_id) {
    delete_shape_safe(panel->button_pics);
    if (file_name != nullptr) {
        panel->button_pics = new TShape((char*)file_name, pic_id);
    }
}

static void scr_game_set_bevel_colors(TEasy_Panel* panel, uchar c1, uchar c2, uchar c3, uchar c4, uchar c5, uchar c6) {
    panel->bevel_color1 = c1;
    panel->bevel_color2 = c2;
    panel->bevel_color3 = c3;
    panel->bevel_color4 = c4;
    panel->bevel_color5 = c5;
    panel->bevel_color6 = c6;
}

static void scr_game_set_button_text_color(TRIBE_Panel_Button* button, ulong color1, ulong color2) {
    if (button == nullptr) {
        return;
    }
    button->text_color1[0] = color1;
    button->text_color2[0] = color2;
}

static void scr_game_reload_shape(TShape*& shape, const char* format, uint style, long style4_id, long base_id) {
    char file_name[64];
    _snprintf(file_name, sizeof(file_name), format, style);
    file_name[sizeof(file_name) - 1] = '\0';
    delete_shape_safe(shape);
    const long shape_id = (style == 4) ? style4_id : (base_id + (long)style);
    shape = new TShape(file_name, shape_id);
}

static TMessagePanel* create_message_panel_checked(
    TDrawArea* area,
    TPanel* parent,
    void* font,
    long font_wid,
    long font_hgt) {
    TMessagePanel* panel = new TMessagePanel(font, font_wid, font_hgt);
    if (panel == nullptr) {
        return nullptr;
    }

    if (panel->setup(area, parent, 0, 0, 0, 0, 0) == 0 || panel->error_code != 0) {
        delete panel;
        return nullptr;
    }

    return panel;
}

static int scr_game_get_player_age(RGE_Player* player) {
    if (player == nullptr) {
        return 0;
    }

    void* age_state = *(void**)((char*)player + 0x50);
    if (age_state == nullptr) {
        return 0;
    }

    return (int)(*(float*)((char*)age_state + 0x18));
}

TRIBE_Screen_Game::TRIBE_Screen_Game()
    : TScreenPanel((char*)"Game Screen") {
    // Parity-first: in-game rendering/input routes through TRIBE_Main_View/TRIBE_Diamond_Map_View.
    memset(&this->runtime, 0, sizeof(this->runtime));
    memset(this->shim_padding, 0, sizeof(this->shim_padding));
    if (rge_base_game == nullptr) {
        this->error_code = 1;
        return;
    }

    // Fully verified. Source of truth: scr_game.cpp.asm @ 0x004940BF..0x004940DC
    if (!this->setup(rge_base_game->draw_area, (char*)"scr6", 0xC388, 1)) {
        this->error_code = 1;
        return;
    }

    this->runtime.world = (TRIBE_World*)rge_base_game->world;
    this->runtime.main_view = nullptr;
    this->runtime.map_view = nullptr;
    this->runtime.chat_line = 0;
    this->runtime.last_item = 0;
    this->runtime.update_interval = (rge_base_game->prog_info != nullptr) ? rge_base_game->prog_info->update_interval : 0;
    this->runtime.last_update_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x116);
    this->runtime.map_redraw_interval = 0x14D;
    this->runtime.last_map_redraw_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x119);
    this->runtime.save_age = 0;
    this->runtime.view_interval = 100;
    this->runtime.last_view_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x142);
    this->runtime.reset_after_update = 1;
    this->runtime.score_interval = 3000;
    this->runtime.last_score_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x154);
    this->runtime.watch_mode = 0;

    if (rge_base_game->prog_palette != nullptr) {
        void* panel_pal = rge_base_game->prog_palette;
        if (panel_system != nullptr && rge_base_game->prog_info != nullptr) {
            void* acquired = panel_system->get_palette(rge_base_game->prog_info->pal_file, 50500);
            if (acquired != nullptr) {
                panel_pal = acquired;
            }
        }

        this->palette = panel_pal;
    }

    long screen_w = (rge_base_game->prog_info != nullptr) ? rge_base_game->prog_info->main_wid : 0x280;
    long screen_h = (rge_base_game->prog_info != nullptr) ? rge_base_game->prog_info->main_hgt : 0x1e0;
    this->set_ideal_size(screen_w, screen_h);

    // Main in-game view panel (original-style rendering pipeline).
    // Fully verified. Source of truth: scr_game.cpp.decomp @ 0x00494285..0x0049431E
    this->runtime.main_view = (TPanel*)new TRIBE_Main_View();
    if (this->runtime.main_view == nullptr ||
        ((RGE_View*)this->runtime.main_view)->setup(this->render_area, this, 0, 0, screen_w, screen_h, 0) == 0) {
        delete_panel_safe(this->runtime.main_view);
        this->runtime.main_view = nullptr;
        this->error_code = 1;
        return;
    }
    {
        RGE_View* main_view = (RGE_View*)this->runtime.main_view;
        main_view->world = (RGE_Game_World*)rge_base_game->world;
        main_view->player = (rge_base_game != nullptr) ? rge_base_game->get_player() : nullptr;
        main_view->map = (rge_base_game->world != nullptr) ? rge_base_game->world->map : nullptr;
        if (main_view->map != nullptr) {
            main_view->tile_wid = main_view->map->tile_width;
            main_view->tile_hgt = main_view->map->tile_height;
            main_view->tile_half_wid = main_view->map->tile_half_width;
            main_view->tile_half_hgt = main_view->map->tile_half_height;
            main_view->elev_hgt = main_view->map->elev_height;
        }
    }

    // Minimap (diamond map) panel.
    // Fully verified. Source of truth: scr_game.cpp.decomp @ 0x004942F0..0x004943F1
    {
        TRIBE_Diamond_Map_View* map_view = new TRIBE_Diamond_Map_View();
        this->runtime.map_view = (TPanel*)map_view;
        if (map_view == nullptr || map_view->error_code != 0 ||
            ((RGE_Diamond_Map*)map_view)->setup(this->render_area, this, 0, 0, 0, 0, 0, 0, rge_base_game->map_save_area) == 0) {
            delete_panel_safe(this->runtime.map_view);
            this->error_code = 1;
            return;
        }

        map_view->set_help_info(0x4E33, -1);
        ((RGE_Diamond_Map*)map_view)->set_world((RGE_Game_World*)rge_base_game->world);
        ((RGE_Diamond_Map*)map_view)->set_bitmap((char*)"map.bmp", 0xC4E1);
        ((RGE_Diamond_Map*)map_view)->set_player(rge_base_game->get_player());
        ((RGE_Diamond_Map*)map_view)->set_main_view((RGE_View*)this->runtime.main_view);
    }

    // NOTE: the view pipeline now owns main in-game render via runtime.main_view.

    // Fully verified. Source of truth: scr_game.cpp.asm @ 0x004940FC..0x0049427F
    this->runtime.button_unit_pic = load_shape_checked("btnunit.shp", 0xC62A);
    if (this->runtime.button_unit_pic == nullptr) {
        this->error_code = 1;
        return;
    }

    this->runtime.button_tech_pic = load_shape_checked("btntech.shp", 0xC629);
    if (this->runtime.button_tech_pic == nullptr) {
        this->error_code = 1;
        return;
    }

    this->runtime.button_cmd_pic = load_shape_checked("btncmd.shp", 0xC621);
    if (this->runtime.button_cmd_pic == nullptr) {
        this->error_code = 1;
        return;
    }

    for (int i = 0; i < 5; ++i) {
        char shp_name[64];
        _snprintf(shp_name, sizeof(shp_name), "btnbldg%d.shp", i);
        shp_name[sizeof(shp_name) - 1] = '\0';
        long res_id = (i < 4) ? (0xC610 + i) : 0xCF0D;
        this->runtime.button_bldg_pics[i] = load_shape_checked(shp_name, res_id);
        if (this->runtime.button_bldg_pics[i] == nullptr) {
            this->error_code = 1;
            return;
        }
    }

    // Fully verified. Source of truth: scr_game.cpp.decomp @ 0x0049437E..0x004946E7
    RGE_Font* font11 = rge_base_game->get_font(0x0B);
    RGE_Font* font7 = rge_base_game->get_font(7);
    TDigital* button_sound = rge_base_game->get_sound(1);
    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();

    if (font11 == nullptr || font7 == nullptr) {
        this->error_code = 1;
        return;
    }

    this->runtime.inven_panel = new TRIBE_Panel_Inven(this->render_area, this, font11->font, player);
    if (this->runtime.inven_panel == nullptr || this->runtime.inven_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    this->runtime.inven_panel->set_help_info(0x4E25, -1);

    this->runtime.object_panel = new TRIBE_Panel_Object(
        this->render_area,
        this,
        font7->font,
        font7->font_wid,
        font7->font_hgt,
        this->runtime.button_unit_pic,
        this->runtime.button_bldg_pics,
        player);
    if (this->runtime.object_panel == nullptr || this->runtime.object_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    this->runtime.object_panel->set_help_info(0x19BB8, 0x265AC);

    this->runtime.time_panel = new TRIBE_Panel_Time(this->render_area, this->runtime.main_view);
    if (this->runtime.time_panel == nullptr || this->runtime.time_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    this->runtime.time_panel->set_active(0);

    this->runtime.pop_panel = new TRIBE_Panel_Pop(this->render_area, this->runtime.main_view);
    if (this->runtime.pop_panel == nullptr || this->runtime.pop_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    this->runtime.pop_panel->set_active(0);

    for (int i = 0; i < 10; ++i) {
        this->runtime.countdown_clock[i] = new TRIBE_Panel_Time(this->render_area, this->runtime.main_view);
        if (this->runtime.countdown_clock[i] == nullptr || this->runtime.countdown_clock[i]->error_code != 0) {
            this->error_code = 1;
            return;
        }
        this->runtime.countdown_clock[i]->set_active(0);
    }

    if (font11 != nullptr) {
        for (int i = 0; i < 17; ++i) {
            TShape* border = (i < 0x0C) ? this->runtime.button_border1_pic : this->runtime.button_border2_pic;
            this->runtime.button_panel[i] = new TRIBE_Panel_Button(
                this->render_area,
                this,
                button_sound,
                font11->font,
                font11->font_wid,
                font11->font_hgt,
                border);
            if (this->runtime.button_panel[i] != nullptr && this->runtime.button_panel[i]->error_code == 0) {
                this->runtime.button_panel[i]->text_color1[0] = 0;
                this->runtime.button_panel[i]->text_color2[0] = 0xFFFFFF;
                this->runtime.button_panel[i]->set_sound_number(1);
            } else if (this->runtime.button_panel[i] != nullptr) {
                delete_panel_safe((TPanel*&)this->runtime.button_panel[i]);
            }
        }

        for (int i = 0; i < 17; ++i) {
            if (this->runtime.button_panel[i] == nullptr) {
                this->error_code = 1;
                return;
            }
        }
    } else {
        this->error_code = 1;
        return;
    }

    // Button ID/help/text setup parity for map/menu buttons.
    this->runtime.button_panel[12]->set_id(0, 0x0D, 0);
    this->runtime.button_panel[12]->set_help_info(0x1D4CF, -1);
    this->runtime.button_panel[13]->set_id(0, 0x0E, 0);
    this->runtime.button_panel[13]->set_help_info(0x1D4D1, -1);
    this->runtime.button_panel[14]->set_id(0, 0x0F, 0);
    this->runtime.button_panel[14]->set_help_info(0x1D4CD, -1);
    this->runtime.button_panel[15]->set_id(0, 0x15, 0);
    this->runtime.button_panel[15]->set_help_info(0x1D4DB, -1);
    this->runtime.button_panel[16]->set_id(0, 0x18, 0);
    this->runtime.button_panel[16]->set_help_info(0x1D4DC, -1);

    for (int i = 12; i <= 14; ++i) {
        this->runtime.button_panel[i]->drawTypeValue = TButtonPanel::DrawTextA;
        this->runtime.button_panel[i]->set_text(0, this->runtime.button_panel[i]->id[0]);
        this->runtime.button_panel[i]->set_bevel_info(
            3,
            (int)this->bevel_color1,
            (int)this->bevel_color2,
            (int)this->bevel_color3,
            (int)this->bevel_color4,
            (int)this->bevel_color5,
            (int)this->bevel_color6);
    }

    if (rge_base_game->singlePlayerGame() == 1) {
        this->runtime.button_panel[12]->set_active(0);
    }

    this->runtime.button_panel[15]->drawTypeValue = TButtonPanel::DrawTextA;
    this->runtime.button_panel[15]->set_bevel_info(
        4,
        (int)this->bevel_color1,
        (int)this->bevel_color2,
        (int)this->bevel_color3,
        (int)this->bevel_color4,
        (int)this->bevel_color5,
        (int)this->bevel_color6);
    this->runtime.button_panel[15]->set_text(0, 0xFA9);

    this->runtime.button_panel[16]->drawTypeValue = TButtonPanel::DrawTextA;
    this->runtime.button_panel[16]->set_bevel_info(
        4,
        (int)this->bevel_color1,
        (int)this->bevel_color2,
        (int)this->bevel_color3,
        (int)this->bevel_color4,
        (int)this->bevel_color5,
        (int)this->bevel_color6);
    this->runtime.button_panel[16]->set_text(0, 0x1023);
    {
        char score_msg[512];
        if (this->get_string(0x1024, score_msg, sizeof(score_msg)) != 0) {
            this->runtime.button_panel[16]->set_text_msg(score_msg);
        }
    }

    if (font11 != nullptr) {
        this->runtime.text_line_panel = create_message_panel_checked(
            this->render_area,
            this->runtime.main_view,
            font11->font,
            font11->font_wid,
            font11->font_hgt);
        if (this->runtime.text_line_panel == nullptr) {
            this->error_code = 1;
            return;
        }
        this->runtime.text_line_panel->set_justification(0, 2, 1);
        ((RGE_View*)this->runtime.main_view)->message_panel = this->runtime.text_line_panel;
    }

    if (this->create_text(
            this->runtime.main_view,
            &this->runtime.quit_message_panel,
            0x232E,
            0,
            0,
            600,
            0x3C,
            0x0B,
            1,
            1,
            0) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->runtime.quit_message_panel != nullptr) {
        this->runtime.quit_message_panel->set_text_color(0xFFFFFF, 0);
        this->runtime.quit_message_panel->set_active(0);
    }

    if (this->create_text(
            this->runtime.main_view,
            &this->runtime.pause_text,
            0x2329,
            0,
            0,
            600,
            0x3C,
            1,
            1,
            1,
            0) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->runtime.pause_text != nullptr) {
        this->runtime.pause_text->set_text_color(0xFFFFFF, 0);
        this->runtime.pause_text->set_active(0);
    }

    if (font11 != nullptr) {
        for (int i = 0; i < 6; ++i) {
            this->runtime.message_panel[i] = create_message_panel_checked(
                this->render_area,
                this->runtime.main_view,
                font11->font,
                font11->font_wid,
                font11->font_hgt);
            if (this->runtime.message_panel[i] == nullptr) {
                this->error_code = 1;
                return;
            }
            this->runtime.message_panel[i]->set_active(0);
        }

        for (int i = 0; i < 8; ++i) {
            this->runtime.chat_panel[i] = create_message_panel_checked(
                this->render_area,
                this->runtime.main_view,
                font11->font,
                font11->font_wid,
                font11->font_hgt);
            if (this->runtime.chat_panel[i] == nullptr) {
                this->error_code = 1;
                return;
            }
            this->runtime.chat_panel[i]->set_active(0);
        }
    }

    if (font11 != nullptr) {
        this->runtime.age_panel = new TTextPanel();
        if (this->runtime.age_panel == nullptr ||
            this->runtime.age_panel->setup(
                this->render_area,
                this,
                0,
                0,
                0,
                0,
                font11->font,
                font11->font_wid,
                font11->font_hgt,
                nullptr,
                0,
                0,
                0,
                0,
                0,
                nullptr) == 0) {
            this->error_code = 1;
            return;
        }
        this->runtime.age_panel->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
        this->runtime.age_panel->set_help_info(0x4E35, -1);
    }

    RGE_Font* font10 = rge_base_game->get_font(10);
    if (font10 != nullptr) {
        this->runtime.fps_panel = new TTextPanel();
        if (this->runtime.fps_panel == nullptr ||
            this->runtime.fps_panel->setup(
                this->render_area,
                this,
                0,
                0,
                0,
                0,
                font10->font,
                font10->font_wid,
                font10->font_hgt,
                nullptr,
                1,
                0,
                0,
                0,
                0,
                nullptr) == 0) {
            this->error_code = 1;
            return;
        }
        this->runtime.fps_panel->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignLeft);
        if (rge_base_game->do_show_timings == 0) {
            this->runtime.fps_panel->set_active(0);
            if (this->runtime.inven_panel != nullptr) {
                this->runtime.inven_panel->set_active(1);
            }
        } else {
            this->runtime.fps_panel->set_active(1);
            if (this->runtime.inven_panel != nullptr) {
                this->runtime.inven_panel->set_active(0);
            }
        }
    }

    int num_score_panels = 0;
    if (this->runtime.world != nullptr) {
        num_score_panels = (int)this->runtime.world->player_num - 1;
    }
    if (num_score_panels < 0) {
        num_score_panels = 0;
    }
    if (num_score_panels > 8) {
        num_score_panels = 8;
    }
    if (font11 != nullptr) {
        for (int i = 0; i < num_score_panels; ++i) {
            this->runtime.score_panel[i] = create_message_panel_checked(
                this->render_area,
                this->runtime.main_view,
                font11->font,
                font11->font_wid,
                font11->font_hgt);
            if (this->runtime.score_panel[i] == nullptr) {
                this->error_code = 1;
                return;
            }
            this->runtime.score_panel[i]->set_active(0);
        }
    }

    if (this->create_text(
            this,
            &this->runtime.log_text,
            (char*)"",
            10,
            300,
            400,
            0x60,
            7,
            0,
            0,
            0) == 0 ||
        this->runtime.log_text == nullptr) {
        this->error_code = 1;
        return;
    }
    this->runtime.log_text->set_back_pic(nullptr);
    this->runtime.log_text->set_fill_back(1, 0);
    this->runtime.log_text->text_style = TTextPanel::NormalStyle;
    this->runtime.log_text->set_text_color(0xFFFFFF, 0);

    if (this->create_auto_scrollbar(&this->runtime.log_scrollbar, this->runtime.log_text, 0x14) == 0) {
        this->error_code = 1;
        return;
    }
    this->runtime.log_scrollbar->set_bevel_info(1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    this->runtime.log_text->empty_list();
    this->runtime.log_text->set_active(0);

    this->runtime.tool_box = nullptr;
    const int has_real_view_path = (this->runtime.main_view != this) && (this->runtime.main_view != nullptr);
    if (font7 != nullptr && has_real_view_path && this->runtime.map_view != nullptr) {
        this->runtime.tool_box = new RGE_Panel_Tool_Box(
            this->render_area,
            this,
            0,
            0,
            0,
            0,
            font7->font,
            font7->font_wid,
            font7->font_hgt,
            button_sound,
            this,
            (RGE_View*)this->runtime.main_view,
            (RGE_Diamond_Map*)this->runtime.map_view);

        if (this->runtime.tool_box != nullptr) {
            if (this->runtime.tool_box->error_code != 0) {
                delete_panel_safe((TPanel*&)this->runtime.tool_box);
            } else {
                this->runtime.tool_box->set_active(0);
            }
        }
    }

    for (int i = 0; i < 17; ++i) {
        this->runtime.button_panel[i]->set_z_order(1, 0);
    }

    if (has_real_view_path) {
        this->handle_size(this->pnl_wid, this->pnl_hgt);

        if (this->runtime.main_view != nullptr && this->runtime.main_view != this) {
            this->set_curr_child(this->runtime.main_view);
        }

        if (this->runtime.world != nullptr && this->runtime.world->players != nullptr) {
            int curr_player = (int)this->runtime.world->curr_player;
            if (curr_player >= 0 && curr_player < this->runtime.world->player_num &&
                this->runtime.world->players[curr_player] != nullptr) {
                this->player_changed(curr_player, curr_player);
            }
        }

        if (this->runtime.time_panel != nullptr) {
            this->runtime.time_panel->startup();
            this->runtime.time_panel->set_clock_type(0, 0);
        }

        for (int i = 0; i < 10; ++i) {
            if (this->runtime.countdown_clock[i] != nullptr) {
                this->runtime.countdown_clock[i]->startup();
                this->runtime.countdown_clock[i]->set_clock_type(0, 0);
            }
        }

        this->reset_clocks();

        if (this->runtime.pop_panel != nullptr) {
            this->runtime.pop_panel->startup();
        }

    }

    // Constructor tail parity (scr_game.cpp @ 0x004953C7..0x00495420):
    // initialize terrain/animation timing state and apply current score-display mode.
    this->runtime.terrain_sound_interval = 20000;
    this->runtime.last_terrain_sound_time =
        debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x339);
    this->runtime.anim_pal_interval = 200;
    this->runtime.last_anim_pal_time =
        debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x33f);
    this->runtime.last_anim_pal_index2 = 0;
    this->runtime.last_anim_pal_index3 = 0;
    this->runtime.last_score_display = (this->runtime.world != nullptr) ? this->runtime.world->score_displayed : 0;
    this->command_score((this->runtime.world != nullptr) ? (int)this->runtime.world->score_displayed : 0);
    confirmed_close = 0;

    if (rge_base_game != nullptr && rge_base_game->check_prog_argument("PAUSE") != 0) {
        rge_base_game->set_prog_mode(6);
        if (rge_base_game->world != nullptr) {
            rge_base_game->world->temp_pause = 1;
        }
    }

    (void)player;
}

TRIBE_Screen_Game::~TRIBE_Screen_Game() {
    if (panel_system != nullptr) {
        panel_system->destroyPanel((char*)"Config Dialog");
    }

    if (this->runtime.game_over_sound != nullptr) {
        if (this->runtime.game_over_sound->is_playing() != 0) {
            this->runtime.game_over_sound->stop();
        }
        delete this->runtime.game_over_sound;
        this->runtime.game_over_sound = nullptr;
    }

    if (this->runtime.tech_list != nullptr) {
        free(this->runtime.tech_list);
        this->runtime.tech_list = nullptr;
    }
    if (this->runtime.make_list != nullptr) {
        free(this->runtime.make_list);
        this->runtime.make_list = nullptr;
    }
    if (this->runtime.bldg_list != nullptr) {
        free(this->runtime.bldg_list);
        this->runtime.bldg_list = nullptr;
    }
    if (this->runtime.trade_list != nullptr) {
        free(this->runtime.trade_list);
        this->runtime.trade_list = nullptr;
    }

    delete_shape_safe(this->runtime.game_screen_pic);
    delete_shape_safe(this->runtime.button_border1_pic);
    delete_shape_safe(this->runtime.button_other_pic);
    delete_shape_safe(this->runtime.button_border2_pic);
    delete_shape_safe(this->runtime.button_border3_pic);
    delete_shape_safe(this->runtime.button_cmd_pic);
    delete_shape_safe(this->runtime.button_tech_pic);
    delete_shape_safe(this->runtime.button_unit_pic);
    delete_shape_safe(this->runtime.more_cancel_pic);
    for (int i = 0; i < 5; ++i) {
        delete_shape_safe(this->runtime.button_bldg_pics[i]);
    }

    for (int i = 0; i < 8; ++i) {
        delete_panel_safe((TPanel*&)this->runtime.chat_panel[i]);
    }
    for (int i = 0; i < 17; ++i) {
        delete_panel_safe((TPanel*&)this->runtime.button_panel[i]);
    }
    for (int i = 0; i < 8; ++i) {
        delete_panel_safe((TPanel*&)this->runtime.score_panel[i]);
    }
    for (int i = 0; i < 10; ++i) {
        delete_panel_safe((TPanel*&)this->runtime.countdown_clock[i]);
    }
    for (int i = 0; i < 6; ++i) {
        delete_panel_safe((TPanel*&)this->runtime.message_panel[i]);
    }

    delete_panel_safe((TPanel*&)this->runtime.pause_text);
    delete_panel_safe((TPanel*&)this->runtime.age_panel);
    delete_panel_safe((TPanel*&)this->runtime.fps_panel);
    delete_panel_safe((TPanel*&)this->runtime.log_text);
    delete_panel_safe((TPanel*&)this->runtime.log_scrollbar);
    delete_panel_safe((TPanel*&)this->runtime.text_line_panel);
    delete_panel_safe((TPanel*&)this->runtime.quit_message_panel);
    delete_panel_safe((TPanel*&)this->runtime.inven_panel);
    delete_panel_safe((TPanel*&)this->runtime.object_panel);
    delete_panel_safe((TPanel*&)this->runtime.time_panel);
    delete_panel_safe((TPanel*&)this->runtime.pop_panel);
    delete_panel_safe((TPanel*&)this->runtime.tool_box);

    delete_panel_safe(this->runtime.main_view);
    delete_panel_safe(this->runtime.map_view);
}

void TRIBE_Screen_Game::handle_game_update() {
    // Source of truth: scr_game.cpp.decomp @ 0x00496800
    if (rge_base_game == nullptr) {
        return;
    }

    if (rge_base_game->world != nullptr) {
        this->runtime.world = (TRIBE_World*)rge_base_game->world;
    }

    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();
    auto command_unselect = [this]() {
        if (rge_base_game == nullptr || rge_base_game->get_paused() != 0) {
            return;
        }

        RGE_Player* unselect_player = rge_base_game->get_player();
        if (unselect_player != nullptr) {
            unselect_player->unselect_object();
            unselect_player->unselect_area();
        }
        if (this->runtime.main_view != nullptr) {
            this->runtime.main_view->set_redraw(TPanel::Redraw);
        }
    };
    auto command_cancel = [this, &command_unselect]() {
        if (rge_base_game == nullptr) {
            return;
        }

        if (this->help_mode != 0) {
            this->clear_popup_help();
            return;
        }

        if (rge_base_game->get_paused() != 0) {
            return;
        }

        if (rge_base_game->game_mode != 0) {
            if (rge_base_game->game_mode == 0x15 && this->runtime.main_view != nullptr) {
                ((RGE_View*)this->runtime.main_view)->set_selection_area(-1, -1, -1, -1);
            }
            rge_base_game->set_game_mode(0, 0);
            return;
        }

        command_unselect();
    };

    if (this->runtime.main_view != nullptr && this->runtime.main_view != this) {
        RGE_View* main_view = (RGE_View*)this->runtime.main_view;
        main_view->world = (RGE_Game_World*)rge_base_game->world;
        main_view->map = (rge_base_game->world != nullptr) ? rge_base_game->world->map : nullptr;
        main_view->player = player;
        if (main_view->map != nullptr) {
            main_view->tile_wid = main_view->map->tile_width;
            main_view->tile_hgt = main_view->map->tile_height;
            main_view->tile_half_wid = main_view->map->tile_half_width;
            main_view->tile_half_hgt = main_view->map->tile_half_height;
            main_view->elev_hgt = main_view->map->elev_height;
        }
    }

    int update_counter = 0;
    const ulong update_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x63F);
    if (update_time - this->runtime.last_update_time >= this->runtime.update_interval) {
        ulong calc_game_time = 1;
        if (rge_base_game->prog_mode != 6) {
            if (rge_base_game->multiplayerGame() != 0) {
                const ulong last_single_time2 = rge_base_game->timings[2].last_single_time;
                const ulong last_single_time3 = rge_base_game->timings[3].last_single_time;

                ulong avg_world_time = 1;
                const ulong world_update_count = rge_base_game->get_last_world_update_count();
                if (world_update_count != 0) {
                    avg_world_time = rge_base_game->timings[1].last_time / world_update_count;
                    if (avg_world_time == 0) {
                        avg_world_time = 1;
                    }
                }

                uint player_avg_msec = 0;
                TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;
                if (comm_handler != nullptr && comm_handler->Speed != nullptr) {
                    int who_am_i = comm_handler->WhoAmI();
                    if (who_am_i >= 0 && who_am_i < 9) {
                        player_avg_msec = comm_handler->Speed->PlayerAvgFramesMsec[who_am_i];
                    }
                }

                calc_game_time = 2;
                const int single_time_sum = (int)(last_single_time2 + last_single_time3);
                const int ratio_is_too_high =
                    (single_time_sum <= 0) || (((float)avg_world_time / (float)single_time_sum) > 2.0f);
                if (multi_updates == 0 || player_avg_msec < 0x43 || player_avg_msec > 0x7D || ratio_is_too_high) {
                    calc_game_time = 1;
                }

                rge_base_game->timings[2].last_single_time = 0;
                rge_base_game->timings[3].last_single_time = 0;
            }
        }

        for (int num_updates = 0; num_updates < (int)calc_game_time; ++num_updates) {
            const ulong world_step_start_time =
                debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x692);

            int world_state_ok = 0;
            int& game_over_state = scr_game_field_i32(this, 0x7B4);
            if (start_paused == 0) {
                if (game_over_state == 0) {
                    const int game_state = (this->runtime.world != nullptr) ? this->runtime.world->get_game_state() : 0;
                    if (out_of_sync2 != 0) {
                        return;
                    }

                    if (game_state == 1) {
                        game_over_state = 1;
                        if (this->runtime.main_view != nullptr) {
                            ((RGE_View*)this->runtime.main_view)->set_selection_area(-1, -1, -1, -1);
                        }
                        rge_base_game->set_game_mode(0, 0);
                        command_unselect();
                        if (rge_base_game->multiplayerGame() != 0 && this->runtime.world != nullptr) {
                            this->runtime.world->send_zone_score_info();
                        }
                    }
                    world_state_ok = game_state;
                } else {
                    world_state_ok = 1;
                }
            } else {
                rge_base_game->set_prog_mode(6);
            }

            if (out_of_sync2 != 0) {
                return;
            }

            const ulong world_step_end_time =
                debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x6BB);
            this->runtime.last_update_time = world_step_end_time;

            if (this->runtime.world != nullptr && this->runtime.world->world_time_delta != 0) {
                rge_base_game->add_to_timing(1, world_step_end_time - world_step_start_time);
                rge_base_game->increment_world_update_count();
                update_counter += (int)this->runtime.world->world_time_delta;
            }

            if (this->runtime.reset_after_update != 0) {
                this->reset_clocks();
                this->runtime.reset_after_update = 0;
            }

            if (scr_game_field_i32(this, 0x7B0) != 0) {
                if (rge_base_game->get_paused() == 0) {
                    RGE_Player* view_player = rge_base_game->get_player();
                    if (view_player != nullptr && view_player->selected_obj != nullptr) {
                        const float view_x = view_player->selected_obj->world_x;
                        const float view_y = view_player->selected_obj->world_y;
                        view_player->set_view_loc(view_x, view_y);
                        view_player->set_map_loc((short)view_x, (short)view_y);
                    }
                }
            }

            player = (TRIBE_Player*)rge_base_game->get_player();
            if (this->runtime.object_panel != nullptr &&
                player != nullptr &&
                (this->runtime.last_selected_obj != player->selected_obj ||
                 this->runtime.last_sel_count != player->sel_count)) {
                this->runtime.object_panel->set_object(player->selected_obj);
                this->object_changed();
            }

            int current_player_status = 0;
            if (this->runtime.world != nullptr && this->runtime.world->players != nullptr) {
                const int current_player = this->runtime.world->curr_player;
                if (current_player >= 0 && current_player < this->runtime.world->player_num) {
                    RGE_Player* status_player = this->runtime.world->players[current_player];
                    if (status_player != nullptr) {
                        current_player_status = status_player->game_status;
                    }
                }
            }

            if (start_paused == 0 &&
                (world_state_ok != 0 || current_player_status == 2 || this->runtime.watch_mode == 1)) {
                int& game_over_pending = scr_game_field_i32(this, 0x720);
                ulong& game_over_time = scr_game_field_u32(this, 0x71C);

                if (rge_base_game->prog_mode == 5) {
                    if (game_over_pending != 0) {
                        const ulong elapsed_time =
                            debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x734);
                        if (elapsed_time - game_over_time > 5000) {
                            game_over_pending = 0;
                            if (rge_base_game->multiplayerGame() == 0) {
                                if (this->runtime.main_view != nullptr) {
                                    ((RGE_View*)this->runtime.main_view)->set_selection_area(-1, -1, -1, -1);
                                }
                                rge_base_game->set_game_mode(0, 0);
                                command_unselect();
                                ((TRIBE_Game*)rge_base_game)->do_game_over();
                                return;
                            }

                            if (rge_base_game->get_paused() == 0 && this->runtime.pause_text != nullptr) {
                                this->runtime.pause_text->set_active(0);
                            }

                            rge_base_game->set_map_visible(1);
                            rge_base_game->set_map_fog(0);
                            if (this->runtime.main_view != nullptr) {
                                this->runtime.main_view->set_redraw(TPanel::RedrawFull);
                            }
                            if (this->runtime.map_view != nullptr) {
                                this->runtime.map_view->set_redraw(TPanel::RedrawFull);
                            }
                            if (this->runtime.quit_message_panel != nullptr) {
                                this->runtime.quit_message_panel->set_active(1);
                            }
                            if (this->runtime.pop_panel != nullptr) {
                                this->runtime.pop_panel->set_active(0);
                            }
                        }
                    }
                } else {
                    command_cancel();
                    command_unselect();

                    if (this->runtime.text_line_panel != nullptr) {
                        this->runtime.text_line_panel->remove_message();
                    }
                    for (int i = 0; i < 6; ++i) {
                        if (this->runtime.message_panel[i] != nullptr) {
                            this->runtime.message_panel[i]->remove_message();
                        }
                    }

                    rge_base_game->set_prog_mode(5);

                    if (panel_system != nullptr) {
                        if (panel_system->mouseOwnerValue != nullptr) {
                            panel_system->mouseOwnerValue->release_mouse();
                        }
                        panel_system->setCurrentPanel((char*)"Game Screen", 0);
                    }
                    if (this->runtime.main_view != nullptr) {
                        this->set_curr_child(this->runtime.main_view);
                    }
                    ((TRIBE_Game*)rge_base_game)->close_game_screens(0);

                    if (this->runtime.pause_text != nullptr) {
                        this->runtime.pause_text->set_active(1);
                        if (player != nullptr && player->game_status == 1) {
                            this->runtime.pause_text->set_text(0x232C);
                        } else {
                            this->runtime.pause_text->set_text(0x232D);
                        }
                    }
                    if (this->runtime.main_view != nullptr) {
                        this->runtime.main_view->set_redraw(TPanel::Redraw);
                    }

                    if (rge_base_game->prog_info != nullptr &&
                        rge_base_game->prog_info->use_sound != 0 &&
                        rge_base_game->sound_system != nullptr) {
                        if (this->runtime.game_over_sound != nullptr) {
                            delete this->runtime.game_over_sound;
                            this->runtime.game_over_sound = nullptr;
                        }

                        const int won_game = (player != nullptr && player->game_status == 1) ? 1 : 0;
                        this->runtime.game_over_sound = new TDigital(
                            rge_base_game->sound_system,
                            won_game != 0 ? (char*)"won.wav" : (char*)"lost.wav",
                            won_game != 0 ? 0xC490 : 0xC491);

                        if (this->runtime.game_over_sound != nullptr) {
                            this->runtime.game_over_sound->load(nullptr, -1);
                            this->runtime.game_over_sound->play();
                        }
                    }

                    game_over_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x72C);
                    game_over_pending = 1;
                }
            }
        }
    }

    if (panel_system != nullptr && panel_system->currentPanel() == this) {
        const ulong draw_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x79C);

        if (update_counter != 0 && player != nullptr) {
            const int current_age = scr_game_get_player_age((RGE_Player*)player);
            if (current_age != this->runtime.save_age) {
                this->age_changed();
            }

            if (this->runtime.score_panel[0] != nullptr &&
                this->runtime.score_panel[0]->active != 0 &&
                this->runtime.score_interval <= draw_time - this->runtime.last_score_time) {
                this->reset_score_display();
                this->runtime.last_score_time =
                    debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x7A8);
            }
        }

        int has_focus = 0;
        if (this->runtime.main_view != nullptr) {
            has_focus = this->runtime.main_view->have_focus;
        }

        TPanel* quick_message_dialog = panel_system->panel((char*)"Send Quick Message Dialog");
        TPanel* help_dialog = panel_system->panel((char*)"Help Dialog");
        if (has_focus != 0 || this->curr_child == quick_message_dialog || this->curr_child == help_dialog) {
            if (this->runtime.main_view != nullptr &&
                (update_counter != 0 || this->runtime.view_interval <= draw_time - this->runtime.last_view_time)) {
                this->runtime.main_view->set_redraw(TPanel::Redraw);
                this->runtime.last_view_time = draw_time;
            }

            if (update_counter != 0 &&
                this->runtime.map_view != nullptr &&
                this->runtime.map_redraw_interval <= draw_time - this->runtime.last_map_redraw_time) {
                this->runtime.map_view->set_redraw(TPanel::Redraw);
                this->runtime.last_map_redraw_time = draw_time;
            }

            if (this->runtime.main_view != nullptr &&
                this->runtime.main_view->need_redraw != TPanel::NoRedraw) {
                rge_base_game->draw_window();
            }
        }
    }
}

void TRIBE_Screen_Game::game_mode_changed(int new_mode, int old_mode) {
    // Fully verified. Source of truth: scr_game.cpp.decomp @ 0x00498A10
    if (this->runtime.tool_box != nullptr) {
        this->runtime.tool_box->game_mode_changed(new_mode, old_mode);
    }

    if (this->runtime.button_panel[0] != nullptr) {
        this->reset_buttons();
    }
}

void TRIBE_Screen_Game::player_changed(int old_player, int new_player) {
    // Source of truth: scr_game.cpp.decomp @ 0x00498A50
    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();

    RGE_View* main_view = (RGE_View*)this->runtime.main_view;
    main_view->player = (RGE_Player*)player;
    main_view->last_view_x = -9999.0f;
    main_view->last_view_y = -9999.0f;
    main_view->set_redraw(TPanel::RedrawFull);
    ((RGE_Diamond_Map*)this->runtime.map_view)->set_player((RGE_Player*)player);
    this->runtime.inven_panel->set_player(player);
    this->runtime.object_panel->set_player(player);

    this->game_mode_changed(rge_base_game->game_mode, rge_base_game->game_mode);
    this->object_changed();
    this->age_changed();

    if (player != nullptr && player->id != 0) {
        const int civ_raw = (int)player->culture;
        int& saved_civ = scr_game_field_i32(this, 0x714);
        int& saved_width = scr_game_field_i32(this, 0x718);
        if (saved_civ != civ_raw || saved_width != this->pnl_wid) {
            saved_civ = civ_raw;
            saved_width = this->pnl_wid;

            uint civ_style = (uint)civ_raw;
            if (civ_style > 4) {
                civ_style = 0;
            }

            char file_name[64];
            _snprintf(file_name, sizeof(file_name), "dlg6_%d", civ_style);
            file_name[sizeof(file_name) - 1] = '\0';
            const long info_id = (civ_style == 4) ? 0xCF08 : (0xC356 + (long)civ_style);
            scr_game_set_info_file(this, file_name, info_id);
            scr_game_set_popup_info_file(this, file_name, info_id);

            _snprintf(file_name, sizeof(file_name), "btn6_%d", civ_style);
            file_name[sizeof(file_name) - 1] = '\0';
            const long button_pic_id = (civ_style == 4) ? 0xCF0C : (0xC5AD + (long)civ_style);
            scr_game_set_button_pics(this, file_name, button_pic_id);

            switch (civ_style) {
            case 0:
                scr_game_set_bevel_colors(this, 0x7E, 0x6D, 0x6F, 0x6F, 0xEE, 0x38);
                break;
            case 1:
                scr_game_set_bevel_colors(this, 0x72, 0x73, 0x74, 0x74, 0xB7, 0xB8);
                break;
            case 2:
                scr_game_set_bevel_colors(this, 0xB9, 0x77, 0x78, 0x78, 0x78, 0x79);
                break;
            case 3:
                scr_game_set_bevel_colors(this, 0x8A, 0xED, 0xEE, 0xEE, 0x38, 0x95);
                break;
            case 4:
                scr_game_set_bevel_colors(this, 0x73, 0x74, 0x75, 0x75, 0x76, 0x77);
                break;
            default:
                break;
            }

            const int b1 = (int)this->bevel_color1;
            const int b2 = (int)this->bevel_color2;
            const int b3 = (int)this->bevel_color3;
            const int b4 = (int)this->bevel_color4;
            const int b5 = (int)this->bevel_color5;
            const int b6 = (int)this->bevel_color6;
            if (this->runtime.button_panel[12] != nullptr) this->runtime.button_panel[12]->set_bevel_info(3, b1, b2, b3, b4, b5, b6);
            if (this->runtime.button_panel[13] != nullptr) this->runtime.button_panel[13]->set_bevel_info(3, b1, b2, b3, b4, b5, b6);
            if (this->runtime.button_panel[14] != nullptr) this->runtime.button_panel[14]->set_bevel_info(3, b1, b2, b3, b4, b5, b6);
            if (this->runtime.button_panel[15] != nullptr) this->runtime.button_panel[15]->set_bevel_info(4, b1, b2, b3, b4, b5, b6);
            if (this->runtime.button_panel[16] != nullptr) this->runtime.button_panel[16]->set_bevel_info(4, b1, b2, b3, b4, b5, b6);

            scr_game_reload_shape(this->runtime.button_border1_pic, "btnbrda%d.shp", civ_style, 0xCF0E, 0xC619);
            scr_game_reload_shape(this->runtime.button_other_pic, "btnoth%d.shp", civ_style, 0xCF11, 0xC625);
            scr_game_reload_shape(this->runtime.button_border2_pic, "btnbrdb%d.shp", civ_style, 0xCF0F, 0xC61D);
            scr_game_reload_shape(this->runtime.button_border3_pic, "btnbrdc%d.shp", civ_style, 0xCF10, 0xC63B);

            if ((this->pnl_wid < 0x400) || (this->pnl_hgt < 0x300)) {
                if ((this->pnl_wid < 800) || (this->pnl_hgt < 600)) {
                    scr_game_reload_shape(this->runtime.game_screen_pic, "gamea%d.shp", civ_style, 0xCF12, 0xC62D);
                } else {
                    scr_game_reload_shape(this->runtime.game_screen_pic, "gameb%d.shp", civ_style, 0xCF13, 0xC631);
                }
            } else {
                scr_game_reload_shape(this->runtime.game_screen_pic, "gamec%d.shp", civ_style, 0xCF14, 0xC635);
            }

            for (int i = 0; i < 17; ++i) {
                if (this->runtime.button_panel[i] != nullptr) {
                    this->runtime.button_panel[i]->border_pic =
                        (i < 12) ? this->runtime.button_border1_pic : this->runtime.button_border2_pic;
                }
            }

            if ((this->pnl_wid < 800) || (this->pnl_hgt < 600)) {
                this->runtime.more_cancel_pic = this->runtime.button_other_pic;
            } else {
                this->runtime.more_cancel_pic = this->runtime.button_cmd_pic;
            }

            if (this->runtime.button_panel[5] != nullptr) {
                this->runtime.button_panel[5]->set_picture(
                    0,
                    this->runtime.more_cancel_pic,
                    scr_game_field_i16(this, 0x4B0));
            }

            if (this->runtime.button_panel[11] != nullptr) {
                const short frame =
                    (this->runtime.button_panel[11]->id[0] == 6)
                        ? scr_game_field_i16(this, 0x4B4)
                        : scr_game_field_i16(this, 0x4B2);
                this->runtime.button_panel[11]->set_picture(0, this->runtime.more_cancel_pic, frame);
            }

            const int dark_style = (civ_style == 2 || civ_style == 3 || civ_style == 4) ? 1 : 0;
            if (this->runtime.inven_panel != nullptr) {
                this->runtime.inven_panel->set_text_color(dark_style ? 0xFFFFFF : 0, dark_style ? 0 : 0xFFFFFF);
            }
            if (this->runtime.age_panel != nullptr) {
                this->runtime.age_panel->set_text_color(dark_style ? 0xFFFFFF : 0, dark_style ? 0 : 0xFFFFFF);
            }

            const ulong text_color1 = dark_style ? 0xFFFFFF : 0;
            const ulong text_color2 = dark_style ? 0 : 0xFFFFFF;
            scr_game_set_button_text_color(this->runtime.button_panel[12], text_color1, text_color2);
            scr_game_set_button_text_color(this->runtime.button_panel[13], text_color1, text_color2);
            scr_game_set_button_text_color(this->runtime.button_panel[14], text_color1, text_color2);
            scr_game_set_button_text_color(this->runtime.button_panel[15], text_color1, text_color2);
            scr_game_set_button_text_color(this->runtime.button_panel[16], text_color1, text_color2);
        }
    }

    this->setup_buttons();
    this->set_redraw(TPanel::Redraw);
    (void)old_player;
    (void)new_player;
}

void TRIBE_Screen_Game::object_changed() {
    // Fully verified. Source of truth: scr_game.cpp.decomp @ 0x004992E0
    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();
    RGE_Static_Object* previous_obj = this->runtime.last_selected_obj;
    RGE_Static_Object* selected_obj = player->selected_obj;

    this->runtime.last_selected_obj = selected_obj;
    this->runtime.last_sel_count = player->sel_count;

    if (previous_obj != selected_obj) {
        if (rge_base_game->game_mode == 0x15) {
            ((RGE_View*)this->runtime.main_view)->set_selection_area(-1, -1, -1, -1);
        }

        const char game_mode = (char)rge_base_game->game_mode;
        if (game_mode != 0x01 &&
            game_mode != 0x12 &&
            game_mode != 0x0E &&
            game_mode != 0x02 &&
            game_mode != 0x03 &&
            game_mode != 0x08 &&
            game_mode != 0x09 &&
            game_mode != 0x0A) {
            rge_base_game->set_game_mode(0, 0);
        }
    }

    this->reset_buttons();
}

void TRIBE_Screen_Game::age_changed() {
    // Fully verified. Source of truth: scr_game.cpp.decomp @ 0x004993B0
    if (this->runtime.age_panel == nullptr) {
        return;
    }

    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();
    this->runtime.save_age = scr_game_get_player_age((RGE_Player*)player);

    char age_text[512];
    age_text[0] = '\0';
    rge_base_game->get_string(0x65, this->runtime.save_age, age_text, sizeof(age_text));
    this->runtime.age_panel->set_text(age_text);
    this->runtime.age_panel->set_redraw(TPanel::Redraw);

    switch (this->runtime.save_age) {
    case 1:
        this->runtime.age_panel->set_help_info(0x1069, -1);
        break;
    case 2:
        this->runtime.age_panel->set_help_info(0x106A, -1);
        break;
    case 3:
        this->runtime.age_panel->set_help_info(0x106B, -1);
        break;
    case 4:
        this->runtime.age_panel->set_help_info(0x106C, -1);
        break;
    default:
        break;
    }
}

void TRIBE_Screen_Game::handle_pause() {
    // Fully verified. Source of truth: scr_game.cpp.decomp @ 0x004972A0
    if (this->runtime.pause_text != nullptr) {
        this->runtime.pause_text->set_text(0x2329); // "GAME PAUSED"
        if (this->runtime.pause_text->active == 0) {
            this->runtime.pause_text->set_active(1);
            this->runtime.pause_text->set_redraw(TPanel::Redraw);
        }
    }
    if (this->runtime.main_view != nullptr) {
        this->runtime.main_view->set_redraw(TPanel::Redraw);
    }
}

void TRIBE_Screen_Game::handle_resume() {
    // Fully verified. Source of truth: scr_game.cpp.decomp @ 0x004972F0
    if (this->runtime.pause_text != nullptr && this->runtime.pause_text->active != 0) {
        this->runtime.pause_text->set_active(0);
        this->runtime.pause_text->set_redraw(TPanel::Redraw);
        if (this->runtime.main_view != nullptr) {
            this->runtime.main_view->set_redraw(TPanel::Redraw);
        }
    }
}

void TRIBE_Screen_Game::handleChatReceived(int from_player) {
    char chat_msg[256];
    chat_msg[0] = '\0';

    const char* src = nullptr;
    if (chat != nullptr) {
        TChat* chat_system = (TChat*)chat;
        if (from_player >= 0 && from_player < 51) {
            src = chat_system->Chat[from_player];
        }
        if ((src == nullptr || src[0] == '\0') && chat_system->CurrentMsgNo >= 0 && chat_system->CurrentMsgNo < 51) {
            src = chat_system->Chat[chat_system->CurrentMsgNo];
        }
    }

    if (src == nullptr || src[0] == '\0') {
        _snprintf(chat_msg, sizeof(chat_msg), "Player %d sent a chat message.", from_player);
        chat_msg[sizeof(chat_msg) - 1] = '\0';
    } else {
        strncpy(chat_msg, src, sizeof(chat_msg) - 1);
        chat_msg[sizeof(chat_msg) - 1] = '\0';
    }

    if (this->runtime.chat_line < 0 || this->runtime.chat_line > 7) {
        this->runtime.chat_line = 0;
    }

    TMessagePanel* panel = this->runtime.chat_panel[this->runtime.chat_line];
    if (panel != nullptr) {
        panel->set_color(0xFF, 0);
        panel->set_time(0);
        panel->set_message(chat_msg);
        panel->set_redraw(TPanel::Redraw);
    }

    this->runtime.chat_line = this->runtime.chat_line + 1;
    if (this->runtime.chat_line > 7) {
        this->runtime.chat_line = 0;
    }
}

void TRIBE_Screen_Game::display_system_message(char* text) {
    if (text == nullptr || text[0] == '\0') {
        return;
    }

    if (this->runtime.chat_line < 0 || this->runtime.chat_line > 7) {
        this->runtime.chat_line = 0;
    }

    TMessagePanel* panel = this->runtime.chat_panel[this->runtime.chat_line];
    if (panel != nullptr) {
        panel->set_color(0xFF, 0);
        panel->set_time(0);
        panel->set_message(text);
        panel->set_redraw(TPanel::Redraw);
    }

    this->runtime.chat_line = this->runtime.chat_line + 1;
    if (this->runtime.chat_line > 7) {
        this->runtime.chat_line = 0;
    }
}

void TRIBE_Screen_Game::setup_buttons() {
    // Source-backed command-panel refresh slice. Source: scr_game.cpp.decomp @ 0x004996C0
    this->runtime.start_item = 0;
    this->runtime.current_item = -1;

    for (int i = 0; i < 12; ++i) {
        this->runtime.button_panel[i]->in_use = 0;
    }

    scr_game_field_i32(this, 0x708) = -1;
    scr_game_field_i32(this, 0x70C) = -1;

    if (this->runtime.last_selected_obj == nullptr) {
        this->set_redraw(TPanel::Redraw);
        return;
    }

    if (this->runtime.last_item < 0) {
        this->runtime.last_item = 0;
    }
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Screen_Game::command_score(int enabled) {
    const int show_score = (enabled != 0) ? 1 : 0;
    if (this->runtime.world != nullptr) {
        this->runtime.world->score_displayed = (unsigned char)show_score;
    }

    for (int i = 0; i < 8; ++i) {
        if (this->runtime.score_panel[i] != nullptr) {
            this->runtime.score_panel[i]->set_active(show_score);
        }
    }

    if (show_score != 0) {
        this->reset_score_display();
    }

    if (this->runtime.text_line_panel != nullptr) {
        if (this->runtime.world != nullptr && this->runtime.world->score_displayed != 0) {
            this->runtime.text_line_panel->set_positioning(
                TPanel::Fixed, 8, 4, 0, 0xB8, 4, 0, 0x22, 0x22, nullptr, nullptr, nullptr, nullptr);
        } else {
            this->runtime.text_line_panel->set_positioning(
                TPanel::Fixed, 8, 4, 0, 4, 4, 0, 0x22, 0x22, nullptr, nullptr, nullptr, nullptr);
        }
    }

    if (this->runtime.main_view != nullptr) {
        this->runtime.main_view->set_redraw(TPanel::Redraw);
    }
}

void TRIBE_Screen_Game::reset_score_display() {
    // Source of truth: scr_game.cpp.decomp @ 0x0049B080.
    if (rge_base_game == nullptr || this->runtime.world == nullptr) {
        return;
    }

    SCR_GAME_PLAYER_SCORE player_score[9];
    memset(player_score, 0, sizeof(player_score));

    int team_counter = 0;
    int player_count = rge_base_game->numberPlayers();
    if (player_count < 0) {
        player_count = 0;
    }
    if (player_count > 9) {
        player_count = 9;
    }

    for (int slot = 1; slot <= player_count; ++slot) {
        int game_player_id = rge_base_game->playerID(slot);
        if (game_player_id == 0) {
            continue;
        }
        if (this->runtime.world->players == nullptr || game_player_id >= this->runtime.world->player_num) {
            continue;
        }

        SCR_GAME_PLAYER_SCORE* score = &player_score[slot - 1];
        if (score->team_id == 0) {
            ++team_counter;
            score->team_id = team_counter;
        }

        score->player_id = slot;
        score->game_player_id = game_player_id;

        RGE_Player* player = this->runtime.world->players[game_player_id];
        if (player == nullptr || player->victory_conditions == nullptr) {
            continue;
        }

        long points = player->victory_conditions->get_victory_points();
        score->score = (int)points;
        score->average_score = (int)points;

        int alliance_count = 1;
        if (player->type != 0) {
            for (int ally_slot = 1; ally_slot <= player_count; ++ally_slot) {
                if (ally_slot == slot) {
                    continue;
                }

                int ally_id = rge_base_game->playerID(ally_slot);
                if (ally_id == 0 || ally_id >= this->runtime.world->player_num || this->runtime.world->players == nullptr) {
                    continue;
                }

                RGE_Player* ally = this->runtime.world->players[ally_id];
                if (ally == nullptr || ally->type == 0) {
                    continue;
                }

                if (player->relation(ally_id) == 0 && ally->relation(game_player_id) == 0) {
                    if (player_score[ally_slot - 1].team_id == 0) {
                        player_score[ally_slot - 1].team_id = score->team_id;
                    }
                    if (ally->victory_conditions != nullptr) {
                        score->average_score += (int)ally->victory_conditions->get_victory_points();
                        ++alliance_count;
                    }
                }
            }
        }

        score->average_score /= alliance_count;
    }

    qsort(player_score, player_count, sizeof(SCR_GAME_PLAYER_SCORE), scr_game_score_compare);

    TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;
    int low_fps_player = 0;
    if (rge_base_game->multiplayerGame() != 0 && comm_handler != nullptr && comm_handler->Speed != nullptr) {
        uint low_fps = 0x0B;
        for (int i = 0; i < 8; ++i) {
            SCR_GAME_PLAYER_SCORE* score = &player_score[i];
            if (score->game_player_id == 0) {
                continue;
            }

            if (comm_handler->GetPlayerHumanity((uint)score->player_id) == 2) {
                uint fps = comm_handler->Speed->PlayerAvgFramesMsec[score->player_id];
                if (fps < 1000) {
                    if (fps < 10) {
                        fps = 100;
                    } else {
                        fps = 1000 / fps;
                    }
                } else {
                    fps = 1;
                }

                if (fps < low_fps) {
                    low_fps = fps;
                    low_fps_player = score->player_id;
                }
            }
        }
    }

    char text[512];
    for (int i = 0; i < 8; ++i) {
        TMessagePanel* panel = this->runtime.score_panel[i];
        if (panel == nullptr) {
            return;
        }

        SCR_GAME_PLAYER_SCORE* score = &player_score[i];
        if (score->game_player_id == 0) {
            panel->set_active(0);
            continue;
        }

        char* player_name = nullptr;
        if (comm_handler != nullptr) {
            player_name = comm_handler->GetPlayerName((uint)score->player_id);
        }
        if (player_name == nullptr) {
            player_name = (char*)"";
        }

        _snprintf(text, sizeof(text), "%s: %d/%d", player_name, score->score, score->average_score);
        text[sizeof(text) - 1] = '\0';

        ulong color1 = 0xFFFFFF;
        ulong color2 = 0;
        RGE_Player* player = nullptr;
        if (this->runtime.world->players != nullptr && score->game_player_id < this->runtime.world->player_num) {
            player = this->runtime.world->players[score->game_player_id];
        }
        short color_index = -1;
        if (player != nullptr && player->color_table != nullptr) {
            color_index = player->color_table->id;
        }
        scr_game_get_score_colors(color_index, &color1, &color2);

        bool use_dim_font = false;
        if (player != nullptr && player->type == 2) {
            use_dim_font = true;
        } else if (rge_base_game->multiplayerGame() != 0 && comm_handler != nullptr) {
            int humanity = comm_handler->GetPlayerHumanity((uint)score->player_id);
            if (humanity != 2 && humanity != 4) {
                use_dim_font = true;
            }
        }

        int font_index = use_dim_font ? 8 : 11;
        RGE_Font* font = rge_base_game->get_font(font_index);
        void* font_obj = (font != nullptr) ? font->font : nullptr;
        long font_wid = (font != nullptr) ? font->font_wid : 0;
        long font_hgt = (font != nullptr) ? font->font_hgt : 0;

        TShape* icon1 = nullptr;
        TShape* icon2 = nullptr;
        int icon1_frame = 0;
        int icon2_frame = 0;
        if (rge_base_game->multiplayerGame() != 0 && comm_handler != nullptr && comm_handler->Speed != nullptr &&
            comm_handler->GetPlayerHumanity((uint)score->player_id) == 2) {
            ulong latency = comm_handler->Speed->ActualLatency[score->player_id];
            if (score->player_id == low_fps_player) {
                icon2 = this->runtime.button_other_pic;
                icon2_frame = 0x11;
            }
            if (latency > 299) {
                icon1 = this->runtime.button_other_pic;
                icon1_frame = 0x14;
                if (latency < 1001) {
                    icon1_frame = 0x13;
                }
            }
        }

        panel->show_message2(TMessagePanel::RightInfoMessage, text, color1, color2, font_obj, font_wid, font_hgt, icon1, icon1_frame, icon2, icon2_frame);
        panel->set_redraw(TPanel::Redraw);
    }
}

void TRIBE_Screen_Game::reset_clocks() {
    // Source of truth: scr_game.cpp.decomp @ 0x0049ADA0.
    if (this->runtime.world == nullptr) {
        return;
    }

    if (this->runtime.world->victory_type == 2) {
        if (this->runtime.countdown_clock[0] != nullptr) {
            this->runtime.countdown_clock[0]->set_clock_type(3, 0);
        }
        return;
    }

    if (this->runtime.world->victory_type != 0) {
        return;
    }

    int used = 0;
    for (int player_id = 1; player_id < this->runtime.world->player_num; ++player_id) {
        long countdown_value = 0;
        if (rge_base_game != nullptr && player_id >= 0 && player_id < 9) {
            countdown_value = rge_base_game->countdown_timer[player_id];
        }
        if (countdown_value > 0) {
            if (used < 10 && this->runtime.countdown_clock[used] != nullptr) {
                this->runtime.countdown_clock[used]->set_clock_type(4, player_id);
            }
            ++used;
            if (used > 9) {
                break;
            }
        }

        TRIBE_Player* p = (TRIBE_Player*)this->runtime.world->players[player_id];
        if (p != nullptr && p->artifact_held_time != -1.0f) {
            int allied_holding = 0;
            if (p->type != 0 && player_id > 1) {
                for (int other = 1; other < player_id; ++other) {
                    TRIBE_Player* other_p = (TRIBE_Player*)this->runtime.world->players[other];
                    if (other_p == nullptr || other_p->type == 0) {
                        continue;
                    }
                    if (p->relation(other) == 0 && other_p->relation(player_id) == 0) {
                        allied_holding = 1;
                        break;
                    }
                }
            }
            if (allied_holding == 0) {
                if (used < 10 && this->runtime.countdown_clock[used] != nullptr) {
                    this->runtime.countdown_clock[used]->set_clock_type(5, player_id);
                }
                ++used;
                if (used > 9) {
                    break;
                }
            }
        }

        if (p != nullptr && p->ruin_held_time != -1.0f) {
            int allied_holding = 0;
            if (p->type != 0 && player_id > 1) {
                for (int other = 1; other < player_id; ++other) {
                    TRIBE_Player* other_p = (TRIBE_Player*)this->runtime.world->players[other];
                    if (other_p == nullptr || other_p->type == 0) {
                        continue;
                    }
                    if (p->relation(other) == 0 && other_p->relation(player_id) == 0) {
                        allied_holding = 1;
                        break;
                    }
                }
            }
            if (allied_holding == 0) {
                if (used < 10 && this->runtime.countdown_clock[used] != nullptr) {
                    this->runtime.countdown_clock[used]->set_clock_type(6, player_id);
                }
                ++used;
                if (used > 9) {
                    break;
                }
            }
        }
    }

    for (int i = used; i < 10; ++i) {
        if (this->runtime.countdown_clock[i] != nullptr) {
            this->runtime.countdown_clock[i]->set_clock_type(0, 0);
        }
    }
}

void TRIBE_Screen_Game::reset_buttons() {
    this->runtime.last_item = 0;
    this->setup_buttons();
}

void TRIBE_Screen_Game::set_redraw(RedrawMode param_1) {
    TPanel::set_redraw(param_1);
}

void TRIBE_Screen_Game::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) {
    (void)param_2;
    TPanel* dialog = (panel_system != nullptr) ? panel_system->modalPanelValue : nullptr;
    if (dialog != nullptr && rects_overlap(param_1->clip_rect, dialog->clip_rect) != 0) {
        dialog->set_redraw(param_3);
    }
}

long TRIBE_Screen_Game::handle_size(long param_1, long param_2) {
    // Source of truth: scr_game.cpp.decomp @ 0x00495AE0.
    TPanel::handle_size(param_1, param_2);

    if (this->runtime.main_view == nullptr) {
        return 0;
    }

    auto set_rect_safe = [](TPanel* panel, long x, long y, long w, long h) {
        if (panel != nullptr) {
            panel->set_rect(x, y, w, h);
        }
    };

    const int toolbox_active =
        (this->runtime.tool_box != nullptr && ((TPanel*)this->runtime.tool_box)->active != 0) ? 1 : 0;

    int grid_start_y = 0;
    int b12_x = 0;
    int b13_x = 0;
    int b14_x = 0;
    int b15_x = 0;
    int b15_y = 0;
    int b16_x = 0;
    int b16_y = 0;

    if ((this->pnl_wid < 0x400) || (this->pnl_hgt < 0x300)) {
        if ((this->pnl_wid < 800) || (this->pnl_hgt < 600)) {
            // 640x480 layout
            if (toolbox_active == 0) {
                set_rect_safe(this->runtime.main_view, 0, 0x14, 0x280, 0x14e);
            } else {
                set_rect_safe((TPanel*)this->runtime.tool_box, 0, 0x14, 0x280, 0x1e);
                set_rect_safe(this->runtime.main_view, 0, 0x32, 0x280, 0x130);
            }

            set_rect_safe(this->runtime.map_view, 0x19b, 0x16a, 0xdc, 0x72);
            set_rect_safe((TPanel*)this->runtime.age_panel, 0x10e, 2, 0x6a, 0x10);
            set_rect_safe((TPanel*)this->runtime.fps_panel, 2, 2, 0x118, 0x10);
            set_rect_safe((TPanel*)this->runtime.inven_panel, 0, 0, 0x10e, 0x14);
            set_rect_safe((TPanel*)this->runtime.object_panel, 5, 0x169, 0x7f, 0x72);

            grid_start_y = 0x16a;
            b12_x = 0x224;
            b13_x = 0x26c;
            b14_x = 0x2d8;
            b15_x = 0x2fd;
            b15_y = 0x234;
            b16_x = 0x2fd;
            b16_y = 0x1e2;
        } else {
            // 800x600 layout
            if (toolbox_active == 0) {
                set_rect_safe(this->runtime.main_view, 0, 0x14, 800, 0x1c6);
            } else {
                set_rect_safe((TPanel*)this->runtime.tool_box, 0, 0x14, 800, 0x1e);
                set_rect_safe(this->runtime.main_view, 0, 0x32, 800, 0x1a8);
            }

            set_rect_safe(this->runtime.map_view, 0x23b, 0x1e0, 0xdc, 0x72);
            set_rect_safe((TPanel*)this->runtime.age_panel, 0x10e, 2, 0x10c, 0x10);
            set_rect_safe((TPanel*)this->runtime.fps_panel, 2, 2, 0x118, 0x10);
            set_rect_safe((TPanel*)this->runtime.inven_panel, 0, 0, 0x10e, 0x14);
            set_rect_safe((TPanel*)this->runtime.object_panel, 5, 0x1e1, 0x7f, 0x72);

            grid_start_y = 0x1e2;
            b12_x = 0x224;
            b13_x = 0x34c;
            b14_x = 0x3b8;
            b15_x = 0x3dd;
            b15_y = 0x2dc;
            b16_x = 0x3dd;
            b16_y = 0x28a;
        }
    } else {
        // 1024x768+ layout
        if (toolbox_active == 0) {
            set_rect_safe(this->runtime.main_view, 0, 0x14, 0x400, 0x26e);
        } else {
            set_rect_safe((TPanel*)this->runtime.tool_box, 0, 0x14, 0x400, 0x1e);
            set_rect_safe(this->runtime.main_view, 0, 0x32, 0x400, 0x250);
        }

        set_rect_safe(this->runtime.map_view, 0x31b, 0x288, 0xdc, 0x72);
        set_rect_safe((TPanel*)this->runtime.age_panel, 0x10e, 2, 0x1ec, 0x10);
        set_rect_safe((TPanel*)this->runtime.fps_panel, 2, 2, 0x118, 0x10);
        set_rect_safe((TPanel*)this->runtime.inven_panel, 0, 0, 0x10e, 0x14);
        set_rect_safe((TPanel*)this->runtime.object_panel, 5, 0x289, 0x7f, 0x72);

        grid_start_y = 0x28a;
        b12_x = 0x304;
        b13_x = 0x34c;
        b14_x = 0x3b8;
        b15_x = 0x3dd;
        b15_y = 0x2dc;
        b16_x = 0x3dd;
        b16_y = 0x28a;
    }

    // Main 2x6 command grid.
    int button_index = 0;
    int y = grid_start_y;
    for (int row = 0; row < 2; ++row) {
        int x = 0x88;
        for (int col = 0; col < 6; ++col) {
            set_rect_safe((TPanel*)this->runtime.button_panel[button_index], x, y, 0x36, 0x36);
            x += 0x36;
            button_index++;
        }
        y += 0x3a;
    }

    // Top map/action buttons (indices 12..16).
    set_rect_safe((TPanel*)this->runtime.button_panel[12], b12_x, 0, 0x48, 0x13);
    set_rect_safe((TPanel*)this->runtime.button_panel[13], b13_x, 0, 0x6c, 0x13);
    set_rect_safe((TPanel*)this->runtime.button_panel[14], b14_x, 0, 0x48, 0x13);
    set_rect_safe((TPanel*)this->runtime.button_panel[15], b15_x, b15_y, 0x1e, 0x1e);
    set_rect_safe((TPanel*)this->runtime.button_panel[16], b16_x, b16_y, 0x1e, 0x1e);

    CUSTOM_DEBUG_BEGIN
    static int s_scr_game_size_logs = 0;
    if (s_scr_game_size_logs < 8 && this->runtime.main_view != nullptr) {
        CUSTOM_DEBUG_LOG_FMT(
            "TRIBE_Screen_Game::handle_size wnd=%ldx%ld main=(%ld,%ld %ldx%ld) map=(%ld,%ld %ldx%ld) object=(%ld,%ld %ldx%ld)",
            this->pnl_wid,
            this->pnl_hgt,
            this->runtime.main_view->pnl_x,
            this->runtime.main_view->pnl_y,
            this->runtime.main_view->pnl_wid,
            this->runtime.main_view->pnl_hgt,
            (this->runtime.map_view != nullptr) ? this->runtime.map_view->pnl_x : -1L,
            (this->runtime.map_view != nullptr) ? this->runtime.map_view->pnl_y : -1L,
            (this->runtime.map_view != nullptr) ? this->runtime.map_view->pnl_wid : -1L,
            (this->runtime.map_view != nullptr) ? this->runtime.map_view->pnl_hgt : -1L,
            (this->runtime.object_panel != nullptr) ? this->runtime.object_panel->pnl_x : -1L,
            (this->runtime.object_panel != nullptr) ? this->runtime.object_panel->pnl_y : -1L,
            (this->runtime.object_panel != nullptr) ? this->runtime.object_panel->pnl_wid : -1L,
            (this->runtime.object_panel != nullptr) ? this->runtime.object_panel->pnl_hgt : -1L);
        s_scr_game_size_logs++;
    }
    CUSTOM_DEBUG_END

    return 1;
}

void TRIBE_Screen_Game::set_map_buttons_redraw(RedrawMode param_1) {
    if (this->width() < 800) {
        if (this->runtime.button_panel[5] != nullptr) {
            this->runtime.button_panel[5]->set_redraw(param_1);
        }
        if (this->runtime.button_panel[11] != nullptr) {
            this->runtime.button_panel[11]->set_redraw(param_1);
        }
    }

    if (this->runtime.button_panel[15] != nullptr) {
        this->runtime.button_panel[15]->set_redraw(param_1);
    }
    if (this->runtime.button_panel[16] != nullptr) {
        this->runtime.button_panel[16]->set_redraw(param_1);
    }
}

long TRIBE_Screen_Game::handle_user_command(uint param_1, long param_2) {
    return TPanel::handle_user_command(param_1, param_2);
}

void TRIBE_Screen_Game::set_focus(int param_1) {
    TScreenPanel::set_focus(param_1);
    if (rge_base_game != nullptr) {
        rge_base_game->windows_mouse = (this->have_focus != 0) ? 0 : 1;
    }
}

void TRIBE_Screen_Game::stop_sound_system() {
    if (this->runtime.game_over_sound != nullptr) {
        delete this->runtime.game_over_sound;
        this->runtime.game_over_sound = nullptr;
    }

    TPanel::stop_sound_system();
}

int TRIBE_Screen_Game::restart_sound_system() {
    int ok = 1;
    for (PanelNode* node = this->first_child_node; node != nullptr; node = node->next_node) {
        if (node->panel != nullptr && node->panel->restart_sound_system() == 0) {
            ok = 0;
        }
    }
    return ok;
}
