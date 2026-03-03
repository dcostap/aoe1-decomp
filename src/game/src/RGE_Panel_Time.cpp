#include "../include/RGE_Panel_Time.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/globals.h"

#include <cstdio>
#include <cstring>
#include <new>
#include <windows.h>

// TODO: MISSING_FUNC - RGE_Panel_Time::~RGE_Panel_Time not implemented as a class method in this TU (bucket has direct base-destructor thunk). [decomp: bucket_048A.decomp @ 0x0048A730]

// Fully verified. Source of truth: rpnl_tim.cpp.decomp @ 0x0048A680
RGE_Panel_Time* rpnl_tim_ctor_0048A680(RGE_Panel_Time* this_, TDrawArea* param_1, TPanel* param_2, void* param_3) {
    new (this_) TPanel();
    this_->font = param_3;
    this_->game_time = 0;
    this_->last_game_time = 0;
    this_->old_time = -1;
    this_->real_time = 0;

    if (this_->TPanel::setup(param_1, param_2, 0, 0, 0, 0, 0) == 0) {
        this_->error_code = 1;
    }
    return this_;
}

// Fully verified. Source of truth: rpnl_tim.cpp.decomp @ 0x0048A740
void rpnl_tim_draw_0048A740(RGE_Panel_Time* this_) {
    if (this_ == nullptr || this_->active == 0 || this_->visible == 0 || this_->render_area == nullptr) {
        return;
    }

    this_->draw_setup(0);
    this_->real_time = this_->real_time + 1;

    HDC dc = (HDC)this_->render_area->GetDc((char*)"rpnl_tim::draw");
    if (dc != nullptr) {
        SelectClipRgn(dc, (HRGN)this_->clip_rgn);
        HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this_->font);

        char str[100];
        if (rge_base_game != nullptr && rge_base_game->world != nullptr && rge_base_game->get_paused() == 0) {
            SetBkMode(dc, 1);
            SetTextColor(dc, 0x00FFFFFF);

            long seconds = this_->game_time;
            long minutes = 0;
            long hours = 0;
            if (seconds > 0x3B) {
                minutes = seconds / 0x3C;
                seconds = seconds % 0x3C;
                if (minutes > 0x3B) {
                    hours = minutes / 0x3C;
                    minutes = minutes % 0x3C;
                }
            }

            std::sprintf(str, "%02ld:%02ld:%02ld (%3.1f)", hours, minutes, seconds, (double)rge_base_game->world->game_speed);
            TextOutA(dc, this_->pnl_x, this_->pnl_y - 2, str, (int)std::strlen(str));

            int y_off = 0x0D;
            const int player_num = (int)rge_base_game->world->player_num;
            for (int i = 1; i < player_num; ++i) {
                long countdown_timer = -1;
                rge_base_game->get_countdown_timer(i, &countdown_timer);
                if (countdown_timer < 0) {
                    continue;
                }

                unsigned long player_color = 0x00FFFFFF;
                if (rge_base_game->draw_system != nullptr && rge_base_game->draw_system->Pal != nullptr &&
                    rge_base_game->world->players != nullptr && rge_base_game->world->players[i] != nullptr &&
                    rge_base_game->world->players[i]->color_table != nullptr) {
                    tagPALETTEENTRY palette_color;
                    GetPaletteEntries((HPALETTE)rge_base_game->draw_system->Pal,
                                      rge_base_game->world->players[i]->color_table->map_color, 1, &palette_color);
                    player_color = ((unsigned long)palette_color.peBlue << 16) |
                                   ((unsigned long)palette_color.peGreen << 8) |
                                   (unsigned long)palette_color.peRed;
                }
                SetTextColor(dc, player_color);

                const char* years_fmt = this_->get_string(0x2C24);
                if (years_fmt == nullptr) {
                    years_fmt = "%d Years";
                }
                std::sprintf(str, years_fmt, countdown_timer);
                TextOutA(dc, this_->pnl_x, this_->pnl_y + y_off, str, (int)std::strlen(str));
                y_off += 0x0D;
            }
        } else {
            SetBkColor(dc, 0x00FFFFFF);
            SetBkMode(dc, 2);
            SetTextColor(dc, 0x000000FF);
            std::sprintf(str, "%s", "Paused");
            TextOutA(dc, this_->pnl_x, this_->pnl_y - 2, str, (int)std::strlen(str));
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this_->render_area->ReleaseDc((char*)"rpnl_tim::draw");
    }

    this_->draw_finish();
}

// Fully verified. Source of truth: rpnl_tim.cpp.decomp @ 0x0048AA70
long rpnl_tim_handle_idle_0048AA70(RGE_Panel_Time* this_) {
    if (this_ == nullptr || rge_base_game == nullptr || rge_base_game->world == nullptr) {
        return 0;
    }

    this_->TPanel::handle_idle();

    this_->game_time = (long)(rge_base_game->world->world_time / 1000);
    const unsigned long world_old_time = rge_base_game->world->old_time / 1000;
    if (world_old_time != 0) {
        if (this_->old_time == -1) {
            this_->old_time = (long)world_old_time;
            this_->real_time = 0;
        } else {
            this_->real_time = (long)world_old_time - this_->old_time;
        }
    }

    if (this_->game_time != this_->last_game_time) {
        this_->set_redraw(TPanel::Redraw);
        if (this_->parent_panel != nullptr) {
            this_->parent_panel->set_redraw(TPanel::Redraw);
        }
        this_->last_game_time = this_->game_time;
    }
    return 0;
}

// TODO: MISSING_FUNC - RGE_Panel_Time::~RGE_Panel_Time not implemented [decomp: bucket_048A.decomp @ 0x0048A730]
