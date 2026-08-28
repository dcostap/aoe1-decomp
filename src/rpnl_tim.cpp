// PDB source module: C:\\msdev\\work\\age1_x1\\rpnl_tim.cpp.
// Definitions follow the original constructor, draw, and idle order.

#include "../include/rpnl_tim.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/world.h"
#include "../include/player.h"
#include "../include/color.h"

#include <stdio.h>
#include <string.h>

RGE_Panel_Time::RGE_Panel_Time(TDrawArea* draw_area, TPanel* parent,
                               void* font_arg)
    : TPanel()
{
    font = font_arg;
    handle_mouse_input = 0;
    game_time = 0;
    last_game_time = 0;
    old_time = -1;
    if (!setup(draw_area, parent, 0, 0, 0, 0, 0)) {
        error_code = 1;
    }
}

void RGE_Panel_Time::draw()
{
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
            SetBkMode(render_area->DrawDc, 2);
            SetTextColor(render_area->DrawDc, 0xFF);
            {
                char str[100];
                sprintf(str, "Paused");
                TextOutA(render_area->DrawDc, render_rect.left,
                         render_rect.top - 2, str, strlen(str));
            }
        } else {
            SetBkMode(render_area->DrawDc, 1);
            SetTextColor(render_area->DrawDc, 0xFFFFFF);

            int t = game_time;
            int m = 0;
            int h = 0;

            if (t > 59) {
                m = t / 60;
                t = t - m * 60;
                if (m > 59) {
                    h = m / 60;
                    m = m - h * 60;
                }
            }

            {
                char str[100];
                sprintf(str, "%02ld:%02ld:%02ld (%3.1f)", h, m, t,
                        (double)rge_base_game->world->game_speed);
                TextOutA(render_area->DrawDc, render_rect.left,
                         render_rect.top - 2, str, strlen(str));
            }

            int pi = 1;
            int pc = rge_base_game->world->player_num;

            if (pc > 1) {
                int yo = 13;

                do {
                    long ct;
                    rge_base_game->get_countdown_timer(pi, ct);

                    if (ct >= 0) {
                        PALETTEENTRY pe;
                        unsigned char map_color =
                            rge_base_game->world->players[pi]->color_table->map_color;
                        HPALETTE palette = (HPALETTE)rge_base_game->draw_system->Pal;

                        GetPaletteEntries(palette, map_color, 1, &pe);

                        COLORREF color = (((pe.peBlue & 0xFF) << 8 |
                                           (pe.peGreen & 0xFF)) << 8 |
                                          (pe.peRed & 0xFF));

                        SetTextColor(render_area->DrawDc, color);

                        {
                            char str[100];
                            sprintf(str, get_string(0x2C24), ct);
                            TextOutA(render_area->DrawDc, render_rect.left,
                                     yo + render_rect.top, str, strlen(str));
                        }
                        yo += 13;
                    }
                    pi++;
                } while (pi < pc);
            }
        }

        SelectObject(render_area->DrawDc, old_font);
        SelectClipRgn(render_area->DrawDc, 0);
        render_area->ReleaseDc("rpnl_tim::draw");
    }

    draw_finish();
}

long RGE_Panel_Time::handle_idle()
{
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

RGE_Panel_Time::~RGE_Panel_Time()
{
}
