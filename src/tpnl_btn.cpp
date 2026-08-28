// PDB source module: C:\msdev\work\age1_x1\tpnl_btn.cpp.
// Definitions follow PDB source lines 50 through 334.

#include "../include/scr_game.h"
#include "../include/tpnl_btn.h"

#include <stdio.h>
#include <string.h>

static char s_tpnl_btn_draw[] = "tpnl_btn::draw";
static char s_tpnl_btn_draw2[] = "tpnl_btn::draw2";
static char s_tpnl_btn_draw3[] = "tpnl_btn::draw3";

extern "C" void __cdecl _ASMSet_Shadowing(int, int, int, int);
extern "C" void __cdecl _ASMSet_Color_Xform(int);

TRIBE_Panel_Button::TRIBE_Panel_Button(
    TDrawArea* draw_area, TPanel* parent, TDigital* sound, void* font,
    long font_width, long font_height, TShape* border)
{
    tribe_button_type = 0;
    color_table = 0;
    border_frame = 0;
    text_msg[0] = 0;
    in_use = 0;
    display_garrison = 0;
    garrsion_number = 0;
    border_pic = border;

    if (setup(draw_area, parent, 0, 0, 0, 0, TButtonPanel::DrawClear, sound,
              TButtonPanel::NotifyAction, -1) == 0) {
        error_code = 1;
    } else {
        set_font(font, font_width, font_height);
    }
}

void TRIBE_Panel_Button::set_text_msg(char* text)
{
    if (text == 0) {
        text_msg[0] = 0;
        return;
    }

    strncpy(text_msg, text, sizeof(text_msg));
    text_msg[sizeof(text_msg) - 1] = 0;
}

int TRIBE_Panel_Button::is_inside(long x, long y)
{
    if (!TPanel::is_inside(x, y))
        return 0;

    if (tribe_button_type == 2 || tribe_button_type == 3) {
        TRIBE_Screen_Game* screen =
            static_cast<TRIBE_Screen_Game*>(parent_panel);
        TRIBE_Diamond_Map_View* map_view = screen->map_view;
        if (map_view != 0 && map_view->is_inside(x, y))
            return 0;
    }

    return 1;
}

void TRIBE_Panel_Button::draw()
{
    HGDIOBJ old_font;
    long calc_y;
    long y;
    short frame;
    long x;
    char* text;
    SIZE text_size;
    short text_length;

    if (tribe_button_type == 3) {
        TButtonPanel::draw();
        return;
    }

    if (render_area == 0 || visible == 0 || active == 0) {
        need_redraw = 0;
        return;
    }

    draw_setup(0);
    parent_panel->draw_rect(&clip_rect);

    int border_drawn = 1;
    if ((tribe_button_type == 0 || tribe_button_type == 1) && border_pic != 0) {
        if (render_area->Lock(s_tpnl_btn_draw, 1) != 0) {
            border_drawn = 0;
            long border_facet = (is_down != 0);
            border_facet += border_frame;
            border_pic->shape_draw(render_area, pnl_x, pnl_y, border_facet, 0,
                                   0);
            render_area->Unlock(s_tpnl_btn_draw);
        }
    }

    if (border_drawn)
        parent_panel->draw_rect(&clip_rect);

    if ((tribe_button_type == 1 || tribe_button_type == 3) && text1[0] != 0) {
        HDC dc = static_cast<HDC>(render_area->GetDc(s_tpnl_btn_draw));
        if (dc != 0) {
            SelectClipRgn(dc, clip_rgn);
            old_font = SelectObject(dc, static_cast<HGDIOBJ>(font));
            SetBkMode(dc, 1);

            int center_x = pnl_wid / 2;
            calc_y = pnl_hgt / 2;

            if (text1[cur_state] != 0)
                text = text1[cur_state];
            else
                text = text1[0];

            if (text != 0) {
                text_length = static_cast<short>(strlen(text));
                GetTextExtentPoint32A(dc, text, text_length, &text_size);

                x = center_x - text_size.cx / 2 + pnl_x;
                if (text2[cur_state] != 0)
                    y = calc_y - font_hgt + pnl_y;
                else
                    y = calc_y - font_hgt / 2 + pnl_y;

                if ((draw_reverse == 0 && is_down != 0) ||
                    (draw_reverse != 0 && is_down == 0)) {
                    x++;
                    y++;
                }

                SetTextColor(dc, text_color2[cur_state]);
                TextOutA(dc, x - 1, y + 1, text, text_length);
                SetTextColor(dc, text_color1[cur_state]);
                TextOutA(dc, x, y, text, text_length);

                if (text2[cur_state] != 0)
                    text = text2[cur_state];
                else
                    text = text2[0];

                if (text != 0) {
                    short second_length = static_cast<short>(strlen(text));
                    GetTextExtentPoint32A(dc, text, second_length, &text_size);

                    x = center_x - text_size.cx / 2 + pnl_x;
                    y = calc_y + pnl_y;

                    if ((draw_reverse == 0 && is_down != 0) ||
                        (draw_reverse != 0 && is_down == 0)) {
                        x++;
                        y++;
                    }

                    SetTextColor(dc, text_color2[cur_state]);
                    TextOutA(dc, x - 1, y + 1, text, second_length);
                    SetTextColor(dc, text_color1[cur_state]);
                    TextOutA(dc, x, y, text, second_length);
                }
            }

            SelectObject(dc, old_font);
            SelectClipRgn(dc, 0);
            render_area->ReleaseDc(s_tpnl_btn_draw);
        }
    } else if (pic[0] != 0 && pic_index[0] >= 0) {
        if (render_area->Lock(s_tpnl_btn_draw3, 1) != 0) {
            frame = pic_index[0];

            if (tribe_button_type == 0) {
                x = pnl_x;
                y = pnl_y;
                if (!is_down) {
                    render_area->SetClipRect(clip_rect.left + 2,
                                             clip_rect.top + 2,
                                             clip_rect.right - 2,
                                             clip_rect.bottom - 2);
                    x += 2;
                    y += 2;
                } else {
                    render_area->SetClipRect(clip_rect.left + 3,
                                             clip_rect.top + 3,
                                             clip_rect.right - 2,
                                             clip_rect.bottom - 3);
                    x += 3;
                    y += 3;
                }
            } else if (tribe_button_type == 1) {
                x = pnl_x + 1;
                y = pnl_y + 1;
                render_area->SetClipRect(clip_rect.left + 1, clip_rect.top + 1,
                                         clip_rect.right - 1,
                                         clip_rect.bottom - 1);
                if (is_down) {
                    x++;
                    y++;
                }
            } else {
                x = pnl_x;
                y = pnl_y;
                if (is_down)
                    frame++;
            }

            if (disabled) {
                fog_next_shape = 1;
                _ASMSet_Shadowing(0xFF00FF, 0, 0x00FF00FF, 0);
            }

            if (color_table != 0) {
                _ASMSet_Color_Xform(
                    (rge_base_game->get_player()->color_table->id + 1) * 0x10);
                pic[0]->shape_draw(render_area, x, y, frame, 1, color_table);
            } else {
                pic[0]->shape_draw(render_area, x, y, frame, 0, 0);
            }

            if (disabled)
                fog_next_shape = 0;
            render_area->Unlock(s_tpnl_btn_draw3);
        }
    }

    if (display_garrison && garrsion_number > 0) {
        HDC dc = static_cast<HDC>(render_area->GetDc(s_tpnl_btn_draw2));
        if (dc != 0) {
            char message[10];
            sprintf(message, "%d", garrsion_number);

            SelectClipRgn(render_area->DrawDc, clip_rgn);
            SetBkMode(render_area->DrawDc, 1);
            SetTextColor(render_area->DrawDc, 0xCCCCCC);
            TextOutA(render_area->DrawDc, pnl_x + 3 + (is_down != 0),
                     pnl_y + 2 + (is_down != 0), message,
                     static_cast<int>(strlen(message)));
            SelectClipRgn(render_area->DrawDc, 0);
            render_area->ReleaseDc(s_tpnl_btn_draw2);
        }
    }

    draw_finish();
}

void TRIBE_Panel_Button::set_display_garrison(int value)
{
    display_garrison = value;
    set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Panel_Button::set_garrison_number(int value)
{
    garrsion_number = value;
    set_redraw(TPanel::RedrawNormal);
}

int TRIBE_Panel_Button::get_garrison_number()
{
    return garrsion_number;
}
