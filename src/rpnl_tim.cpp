
#include "../include/rpnl_tim.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/world.h"
#include "../include/player.h"
#include "../include/color.h"

#include <stdio.h>
#include <string.h>

RGE_Panel_Time::RGE_Panel_Time(TDrawArea* draw_area_in, TPanel* parent_in,
                               void* font_in)
    : TPanel() {
    font = font_in;
    handle_mouse_input = 0;
    game_time = 0;
    last_game_time = 0;
    old_time = -1;
    if (!setup(draw_area_in, parent_in, 0, 0, 0, 0, 0)) {
        error_code = 1;
    }
}

void RGE_Panel_Time::draw() {
    if (render_area == 0 || visible == 0 || active == 0)
        return;

    draw_setup(0);
    display_changed_count++;

    HGDIOBJ old_font;
    if (render_area->GetDc("rpnl_tim::draw") != 0) {
        SelectClipRgn(render_area->DrawDc, (HRGN)clip_rgn);
        old_font = SelectObject(render_area->DrawDc, (HGDIOBJ)font);

        if (rge_base_game->get_paused()) {
            SetBkColor(render_area->DrawDc, 0xFFFFFF);
            SetBkMode(render_area->DrawDc, OPAQUE);
            SetTextColor(render_area->DrawDc, 0xFF);
            {
                char str[100];
                sprintf(str, "Paused");
                TextOutA(render_area->DrawDc, render_rect.left,
                         render_rect.top - 2, str, strlen(str));
            }
        } else {
            SetBkMode(render_area->DrawDc, TRANSPARENT);
            SetTextColor(render_area->DrawDc, 0xFFFFFF);

            int seconds = game_time;
            int minutes = 0;
            int hours = 0;

            if (seconds > 59) {
                minutes = seconds / 60;
                seconds = seconds - minutes * 60;
                if (minutes > 59) {
                    hours = minutes / 60;
                    minutes = minutes - hours * 60;
                }
            }

            {
                char str[100];
                sprintf(str, "%02ld:%02ld:%02ld (%3.1f)", hours, minutes, seconds,
                        (double)rge_base_game->world->game_speed);
                TextOutA(render_area->DrawDc, render_rect.left,
                         render_rect.top - 2, str, strlen(str));
            }

            int player_index = 1;
            int player_num = rge_base_game->world->player_num;

            if (player_num > 1) {
                int y_offset = 13;

                do {
                    long countdown_timer;
                    rge_base_game->get_countdown_timer(player_index, countdown_timer);

                    if (countdown_timer >= 0) {
                        PALETTEENTRY paletteColor;
                        unsigned char map_color =
                            rge_base_game->world->players[player_index]->color_table->map_color;
                        HPALETTE palette = (HPALETTE)rge_base_game->draw_system->Pal;

                        GetPaletteEntries(palette, map_color, 1, &paletteColor);

                        COLORREF text_color =
                            (((paletteColor.peBlue & 0xFF) << 8 |
                              (paletteColor.peGreen & 0xFF)) << 8 |
                             (paletteColor.peRed & 0xFF));

                        SetTextColor(render_area->DrawDc, text_color);

                        {
                            char str[100];
                            sprintf(str, get_string(0x2C24), countdown_timer);
                            TextOutA(render_area->DrawDc, render_rect.left,
                                     y_offset + render_rect.top, str, strlen(str));
                        }
                        y_offset += 13;
                    }
                    player_index++;
                } while (player_index < player_num);
            }
        }

        SelectObject(render_area->DrawDc, old_font);
        SelectClipRgn(render_area->DrawDc, 0);
        render_area->ReleaseDc("rpnl_tim::draw");
    }

    draw_finish();
}

long RGE_Panel_Time::handle_idle() {
    TPanel::handle_idle();

    game_time = rge_base_game->world->world_time / 1000;

    unsigned long current_old_time = rge_base_game->world->old_time / 1000;
    if ((int)current_old_time > 0) {
        if (old_time == -1) {
            old_time = current_old_time;
            real_time = 0;
        } else {
            real_time = current_old_time - old_time;
        }
    }

    if (game_time != last_game_time) {
        set_redraw(TPanel::RedrawNormal);
        if (parent_panel != 0) {
            parent_panel->set_redraw(TPanel::RedrawNormal);
        }
        last_game_time = game_time;
    }

    return 0;
}

RGE_Panel_Time::~RGE_Panel_Time() {}
