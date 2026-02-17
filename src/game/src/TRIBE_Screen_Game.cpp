#include "../include/TRIBE_Screen_Game.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Diamond_Map.h"
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
#include "../include/TRIBE_Panel_Button.h"
#include "../include/TRIBE_Panel_Inven.h"
#include "../include/TRIBE_Panel_Object.h"
#include "../include/TRIBE_Panel_Pop.h"
#include "../include/TRIBE_Panel_Time.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_World.h"
#include "../include/custom_debug.h"
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

TRIBE_Screen_Game::TRIBE_Screen_Game()
    : GameViewPanel((rge_base_game != nullptr && rge_base_game->world != nullptr) ? rge_base_game->world->map : nullptr) {
    // Partial parity milestone:
    // constructor now executes panel/resource setup path, but map/main view rendering still
    // runs through GameViewPanel until TRIBE_Main_View/TRIBE_Diamond_Map_View are restored.
    memset(&this->runtime, 0, sizeof(this->runtime));
    memset(this->shim_padding, 0, sizeof(this->shim_padding));
    if (rge_base_game == nullptr) {
        this->error_code = 1;
        return;
    }

    if (!this->setup(rge_base_game->draw_area, (char*)0, -1, 0)) {
        this->error_code = 1;
        return;
    }

    this->world_map = (rge_base_game->world != nullptr) ? rge_base_game->world->map : nullptr;
    this->runtime.world = (TRIBE_World*)rge_base_game->world;
    // TODO: STUB: restore real TRIBE_Main_View / TRIBE_Diamond_Map_View path.
    this->runtime.main_view = this;
    this->runtime.map_view = nullptr;
    this->runtime.chat_line = 0;
    this->runtime.last_item = 0;

    if (rge_base_game->prog_palette != nullptr) {
        void* panel_pal = rge_base_game->prog_palette;
        if (panel_system != nullptr && rge_base_game->prog_info != nullptr) {
            void* acquired = panel_system->get_palette(rge_base_game->prog_info->pal_file, 50500);
            if (acquired != nullptr) {
                panel_pal = acquired;
            }
        }

        this->palette = panel_pal;
        if (rge_base_game->draw_system != nullptr) {
            rge_base_game->draw_system->SetPalette(rge_base_game->prog_palette);
        }
    }

    long screen_w = (rge_base_game->prog_info != nullptr) ? rge_base_game->prog_info->main_wid : 0x280;
    long screen_h = (rge_base_game->prog_info != nullptr) ? rge_base_game->prog_info->main_hgt : 0x1e0;
    this->set_ideal_size(screen_w, screen_h);

    if (this->world_map != nullptr && this->world_map->map_width > 0 && this->world_map->map_height > 0) {
        long world_pixel_w = (this->world_map->map_width + this->world_map->map_height) * 32;
        long world_pixel_h = (this->world_map->map_width + this->world_map->map_height) * 16;
        this->cam_x = (world_pixel_w - screen_w) / 2;
        this->cam_y = (world_pixel_h - screen_h) / 2;
        if (this->cam_x < 0) {
            this->cam_x = 0;
        }
        if (this->cam_y < 0) {
            this->cam_y = 0;
        }
    }

    // Constructor parity milestone:
    // keep fallback view ownership (main_view=this) until TRIBE_Main_View/TRIBE_Diamond_Map_View
    // object path is wired, but continue with full panel/resource setup below.
    this->runtime.main_view = this;

    // Constructor resource parity (partial): load button art assets up front.
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

    // Constructor resource parity (partial): create panel objects that scr_game owns/destructs.
    RGE_Font* font11 = rge_base_game->get_font(0x0B);
    RGE_Font* font7 = rge_base_game->get_font(7);
    TDigital* button_sound = rge_base_game->get_sound(1);
    TRIBE_Player* player = nullptr;
    if (this->runtime.world != nullptr && this->runtime.world->players != nullptr) {
        int curr = (int)this->runtime.world->curr_player;
        if (curr >= 0) {
            player = (TRIBE_Player*)this->runtime.world->players[curr];
        }
    }

    if (font11 != nullptr) {
        this->runtime.inven_panel = new TRIBE_Panel_Inven(this->render_area, this, font11->font, player);
        if (this->runtime.inven_panel != nullptr && this->runtime.inven_panel->error_code != 0) {
            delete_panel_safe((TPanel*&)this->runtime.inven_panel);
        }
    }

    if (font7 != nullptr) {
        this->runtime.object_panel = new TRIBE_Panel_Object(
            this->render_area,
            this,
            font7->font,
            font7->font_wid,
            font7->font_hgt,
            this->runtime.button_unit_pic,
            this->runtime.button_bldg_pics,
            player);
        if (this->runtime.object_panel != nullptr && this->runtime.object_panel->error_code != 0) {
            delete_panel_safe((TPanel*&)this->runtime.object_panel);
        }
    }

    this->runtime.time_panel = new TRIBE_Panel_Time(this->render_area, this);
    if (this->runtime.time_panel != nullptr && this->runtime.time_panel->error_code != 0) {
        delete_panel_safe((TPanel*&)this->runtime.time_panel);
    }
    this->runtime.pop_panel = new TRIBE_Panel_Pop(this->render_area, this);
    if (this->runtime.pop_panel != nullptr && this->runtime.pop_panel->error_code != 0) {
        delete_panel_safe((TPanel*&)this->runtime.pop_panel);
    }

    for (int i = 0; i < 10; ++i) {
        this->runtime.countdown_clock[i] = new TRIBE_Panel_Time(this->render_area, this);
        if (this->runtime.countdown_clock[i] != nullptr && this->runtime.countdown_clock[i]->error_code != 0) {
            delete_panel_safe((TPanel*&)this->runtime.countdown_clock[i]);
        }
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

    // TODO: STUB: scr_game log panel block is crashing in partial constructor parity state.
    // Defer log_text/log_scrollbar creation until full screen/view parity is restored.
    this->runtime.log_text = nullptr;
    this->runtime.log_scrollbar = nullptr;

    this->runtime.tool_box = nullptr;
    const int has_real_view_path = (this->runtime.main_view != this) && (this->runtime.main_view != nullptr) && (this->runtime.map_view != nullptr);
    if (font7 != nullptr && has_real_view_path) {
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

    if (this->runtime.main_view != nullptr && this->runtime.main_view != this) {
        this->set_curr_child(this->runtime.main_view);
    }
    // TODO: STUB: final activation/startup block from scr_game ctor is still parity-incomplete.
    // Keep construction deterministic and avoid touching panel runtime startup until
    // real TRIBE_Main_View/TRIBE_Diamond_Map_View + update loop parity is in place.
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

    if (this->runtime.main_view != this) {
        delete_panel_safe(this->runtime.main_view);
    } else {
        this->runtime.main_view = nullptr;
    }
    delete_panel_safe(this->runtime.map_view);
}

void TRIBE_Screen_Game::handle_game_update() {
    // TODO: STUB: restore full scr_game.cpp @ 0x00496800 timing/update parity.
    if (rge_base_game != nullptr && rge_base_game->world != nullptr) {
        this->world_map = rge_base_game->world->map;
        this->runtime.world = (TRIBE_World*)rge_base_game->world;
    }

    if (this->runtime.chat_line < 0 || this->runtime.chat_line > 7) {
        this->runtime.chat_line = 0;
    }

    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Screen_Game::game_mode_changed(int new_mode, int old_mode) {
    // Source of truth intent: scr_game.cpp.decomp @ 0x00498A10.
    if (this->runtime.tool_box != nullptr) {
        this->runtime.tool_box->game_mode_changed(new_mode, old_mode);
    }

    if (new_mode != old_mode || this->runtime.last_item != 0) {
        this->reset_buttons();
    }
}

void TRIBE_Screen_Game::player_changed(int old_player, int new_player) {
    // TODO: STUB: restore full scr_game.cpp @ 0x00498A50 player-changed parity once object/inventory panels are real.
    this->game_mode_changed(rge_base_game != nullptr ? rge_base_game->game_mode : 0, rge_base_game != nullptr ? rge_base_game->game_mode : 0);
    this->reset_buttons();
    this->reset_clocks();
    (void)old_player;
    (void)new_player;
}

void TRIBE_Screen_Game::handle_pause() {
    // Source of truth intent: scr_game.cpp.decomp @ 0x004972A0.
    if (this->runtime.pause_text != nullptr) {
        this->runtime.pause_text->set_text(0x2329); // "GAME PAUSED"
        if (this->runtime.pause_text->active == 0) {
            this->runtime.pause_text->set_active(1);
            this->runtime.pause_text->set_redraw(TPanel::Redraw);
        }
    }
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Screen_Game::handle_resume() {
    // Source of truth intent: scr_game.cpp.decomp @ 0x004972F0.
    if (this->runtime.pause_text != nullptr && this->runtime.pause_text->active != 0) {
        this->runtime.pause_text->set_active(0);
        this->runtime.pause_text->set_redraw(TPanel::Redraw);
    }
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Screen_Game::handleChatReceived(int from_player) {
    // TODO: STUB: restore full chat-panel/message-panel flow from scr_game.cpp @ 0x00497330.
    char fallback[96];
    fallback[0] = '\0';

    const char* latest = nullptr;
    if (chat != nullptr) {
        TChat* chat_system = (TChat*)chat;
        int msg_index = chat_system->CurrentMsgNo - 1;
        if (msg_index < 0) {
            msg_index = 0;
        }
        if (msg_index > 50) {
            msg_index = 50;
        }
        latest = chat_system->Chat[msg_index];
    }

    if (latest == nullptr || latest[0] == '\0') {
        _snprintf(fallback, sizeof(fallback), "Player %d sent a chat message.", from_player);
        fallback[sizeof(fallback) - 1] = '\0';
        latest = fallback;
    }

    this->display_system_message((char*)latest);
}

void TRIBE_Screen_Game::display_system_message(char* text) {
    // TODO: STUB: restore full message-panel ring behavior from scr_game.cpp @ 0x004973F0.
    if (text == nullptr || text[0] == '\0') {
        return;
    }

    if (this->runtime.log_text != nullptr) {
        this->runtime.log_text->append_line(text, 0);
    }

    this->runtime.chat_line++;
    if (this->runtime.chat_line > 7) {
        this->runtime.chat_line = 0;
    }
}

void TRIBE_Screen_Game::setup_buttons() {
    // TODO: STUB: restore full scr_game.cpp @ 0x004996C0 command-button parity.
    if (this->runtime.last_item < 0) {
        this->runtime.last_item = 0;
    }
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Screen_Game::reset_clocks() {
    // TODO: STUB: restore full scr_game.cpp @ 0x0049ADA0 clock panel parity.
    this->set_redraw(TPanel::Redraw);
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

    if (panel_system == nullptr || param_1 == nullptr) {
        return;
    }

    TPanel* dialog = panel_system->modalPanelValue;
    if (dialog == nullptr) {
        return;
    }

    if (rects_overlap(param_1->clip_rect, dialog->clip_rect) != 0) {
        dialog->set_redraw(param_3);
    }
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
