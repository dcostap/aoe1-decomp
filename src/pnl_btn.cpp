// Recovered direct owner module for C:\msdev\work\age1_x1\Pnl_btn.cpp.
#include "../include/pnl_btn.h"
#include "../include/Shape.h"
#include "../include/sounddrv.h"
// 00471EC0_TButtonPanel.cpp
#include <string.h>

TButtonPanel::TButtonPanel()
    : buttonTypeValue(Normal),
      drawTypeValue(DrawClear),
      notifyTypeValue(NotifyAction),
      sound(0),
      auto_pic_pos(1),
      pic_x(0),
      pic_y(0),
      all_hot(1),
      draw_reverse(0),
      text_x(-1),
      text_y(-1),
      font(0),
      font_wid(0),
      font_hgt(0),
      num_states(1),
      cur_state(0),
      is_down(0),
      radio_buttons(0),
      num_radio_buttons(0),
      button_down_time(0),
      hotkey(0),
      hotkey_shift(0),
      bevel_type(1),
      bevel_color1(0),
      bevel_color2(0),
      bevel_color3(0),
      bevel_color4(0),
      bevel_color5(0),
      bevel_color6(0),
      key_down(0),
      disabled(0),
      sound_number(-1)
{
    // The compiler emits the derived vptr as part of normal construction.
    ((TPanel*)this)->panel_type = 3;

    // Array initialization loop (9 iterations)
    for (int i = 0; i < 9; i++) {
        id[i] = 0;
        id2[i] = 0;
        pic[i] = 0;
        pic_index[i] = -1;
        text1[i] = 0;
        text2[i] = 0;
        text_color1[i] = 0xFFFFFF;
        text_color2[i] = 0;
        highlight_text_color1[i] = 0xFFFF;
        highlight_text_color2[i] = 0;
    }
}

// 00472030_TButtonPanel.cpp
extern "C" void __cdecl free(void* ptr);

TButtonPanel::~TButtonPanel() {
    int i;

    for (i = 0; i < 9; i++) {
        if (text1[i] != 0) {
            free(text1[i]);
            text1[i] = 0;
        }
        if (text2[i] != 0) {
            free(text2[i]);
            text2[i] = 0;
        }
    }
    if (radio_buttons != 0) {
        free(radio_buttons);
        radio_buttons = 0;
    }
}

// 004720A0_setup.cpp

long TButtonPanel::setup(
    TDrawArea* draw_area,
    TPanel* parent,
    long x,
    long y,
    long width,
    long height,
    TButtonPanel::DrawType draw_type,
    TDigital* sound,
    TButtonPanel::NotifyType notify_type,
    long button_id
) {
    TPanel::setup(draw_area, parent, x, y, width, height, 0);
    this->drawTypeValue = draw_type;
    this->notifyTypeValue = notify_type;
    this->set_sound(sound);
    this->set_id(0, button_id, 0);
    return 1;
}

// 00472110_buttonType.cpp
TButtonPanel::ButtonType TButtonPanel::buttonType() const { return this->buttonTypeValue; }

// 00472120_drawType.cpp
TButtonPanel::DrawType TButtonPanel::drawType() const { return this->drawTypeValue; }

// 00472130_notifyType.cpp
TButtonPanel::NotifyType TButtonPanel::notifyType() const { return this->notifyTypeValue; }

// 00472140_setDrawType.cpp
void TButtonPanel::setDrawType(TButtonPanel::DrawType v) { this->drawTypeValue = v; }

// 00472150_setButtonType.cpp
void TButtonPanel::setButtonType(TButtonPanel::ButtonType v) { this->buttonTypeValue = v; }

// 00472160_set_picture_info.cpp
void TButtonPanel::set_picture_info(TShape* shape, short index, long x, long y, int all_hot_value, int auto_pic_pos_value) {
    pic_x = x;
    pic_y = y;
    all_hot = all_hot_value;
    auto_pic_pos = auto_pic_pos_value;
    set_picture(0, shape, index);
}

// 004721A0_set_text_info.cpp
void TButtonPanel::set_text_info(char* text, void* font, long width, long height, long x, long y) {
    set_text_pos(x, y);
    set_text(0, text);
    set_font(font, width, height);
}

// 004721E0_set_text_info.cpp
void TButtonPanel::set_text_info(long string_id, void* font, long width, long height, long x, long y) {
    set_text_pos(x, y);
    set_text(0, string_id);
    set_font(font, width, height);
}

// 00472220_set_text_pos.cpp
void TButtonPanel::set_text_pos(long a, long b) {
    this->text_x = a;
    this->text_y = b;
    this->set_redraw(TPanel::RedrawNormal);
}

// 00472240_set_radio_info.cpp

#include <stdlib.h>

void TButtonPanel::set_radio_info(TButtonPanel** buttons, short count) {
    TButtonPanel** old_radio = this->radio_buttons;
    this->buttonTypeValue = TButtonPanel::Radio;
    if (old_radio != 0) {
        free(old_radio);
        this->radio_buttons = 0;
    }
    if (count != 0) {
        int cnt = (int)(short)count;
        this->num_radio_buttons = count;
        this->radio_buttons = (TButtonPanel**)calloc(
            cnt, sizeof(TButtonPanel*));
        if (count > 0) {
            int index = 0;
            int remaining = cnt;
            do {
                this->radio_buttons[index] = buttons[index];
                ++index;
                --remaining;
            } while (remaining != 0);
        }
    }
}

// 004722C0_set_state_info.cpp
void TButtonPanel::set_state_info(short param) {
    buttonTypeValue = TButtonPanel::State;
    num_states = param;
}

// 004722E0_set_id.cpp
void TButtonPanel::set_id(short param_1, long param_2, long param_3) {
    this->id[param_1] = param_2;
    this->id2[param_1] = param_3;
}

// 00472300_set_picture.cpp
void TButtonPanel::set_picture(short param_1, TShape* param_2, short param_3) {
    this->pic[param_1] = param_2;
    this->pic_index[param_1] = param_3;
    this->set_redraw(TPanel::RedrawNormal);
}

// 00472330_set_text.cpp

#include <string.h>

extern "C" void __cdecl free(void* ptr);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);


void TButtonPanel::set_text(short state, char* text) {
    if (text1[state] != 0) {
        free(text1[state]);
        text1[state] = 0;
    }
    if (text2[state] != 0) {
        free(text2[state]);
        text2[state] = 0;
    }
    if (text != 0 && *text != 0) {
        char* newline = strchr(text, 10);
        short length;

        if (newline != 0) {
            length = (short)(newline - text);
        } else {
            length = (short)strlen(text);
        }
        text1[state] = (char*)calloc(length + 1, 1);
        if (text1[state] != 0) {
            strncpy(text1[state], text, length);
            text1[state][length] = 0;
            if (newline != 0) {
                newline++;
                text2[state] = (char*)calloc(strlen(newline) + 1, 1);
                if (text2[state] != 0) {
                    strcpy(text2[state], newline);
                }
            }
        }
    }
    set_redraw(TPanel::RedrawNormal);
}

// 00472440_set_text.cpp

#include <string.h>

extern "C" void __cdecl free(void* ptr);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);


void TButtonPanel::set_text(short state, char* text1_arg, char* text2_arg) {
    if (text1[state] != 0) {
        free(text1[state]);
        text1[state] = 0;
    }
    if (text2[state] != 0) {
        free(text2[state]);
        text2[state] = 0;
    }
    if (text1_arg != 0 && *text1_arg != 0) {
        text1[state] = (char*)calloc(strlen(text1_arg) + 1, 1);
        if (text1[state] != 0) {
            strcpy(text1[state], text1_arg);
            if (text2_arg != 0 && *text2_arg != 0) {
                text2[state] = (char*)calloc(strlen(text2_arg) + 1, 1);
                if (text2[state] != 0) {
                    strcpy(text2[state], text2_arg);
                }
            }
        }
    }
        set_redraw(TPanel::RedrawNormal);
}

// 00472540_set_text.cpp
void TButtonPanel::set_text(short state, long string_id) {
    char str[256];

    get_string(string_id, str, 0x100);
    set_text(state, str);
}

// 00472580_set_text.cpp
void TButtonPanel::set_text(short state, long string_id1, long string_id2) {
    char str2[256];
    char str1[256];

    get_string(string_id1, str1, 0x100);
    get_string(string_id2, str2, 0x100);
    set_text(state, str1, str2);
}

// 004725F0_set_font.cpp
void TButtonPanel::set_font(void* param_1, long param_2, long param_3) {
    this->font = param_1;
    this->font_wid = param_2;
    this->font_hgt = param_3;
    this->set_redraw(TPanel::RedrawNormal);
}

// 00472620_set_text_color.cpp
void TButtonPanel::set_text_color(int state, unsigned long color1, unsigned long color2) {
    if (state >= 0 && state <= 8) {
        text_color1[state] = color1;
        text_color2[state] = color2;
        set_redraw(TPanel::RedrawNormal);
    }
}

// 00472650_set_highlight_text_color.cpp
void TButtonPanel::set_highlight_text_color(int state, unsigned long color1, unsigned long color2) {
    if (state >= 0 && state <= 8) {
        highlight_text_color1[state] = color1;
        highlight_text_color2[state] = color2;
        set_redraw(TPanel::RedrawNormal);
    }
}

// 00472680_set_sound.cpp
void TButtonPanel::set_sound(TDigital* v) { this->sound = v; }

// 00472690_set_radio_button.cpp
void TButtonPanel::set_radio_button(void) {
    int i;

    for (i = 0; i < num_radio_buttons; i++) {
        radio_buttons[i]->is_down = 0;
        radio_buttons[i]->set_state(0);
    }
    if (drawTypeValue == 3 || drawTypeValue == 5) {
        is_down = 1;
    }
    set_state(1);
}

// 00472700_set_state.cpp
void TButtonPanel::set_state(short param_1) {
    this->cur_state = param_1;
    this->set_redraw(TPanel::RedrawNormal);
}

// 00472720_set_state_by_id.cpp
void TButtonPanel::set_state_by_id(long target_id) {
    int i;

    for (i = 0; i < num_states; i++) {
        if (id[i] == target_id) {
            cur_state = (short)i;
            set_redraw(TPanel::RedrawNormal);
            return;
        }
    }
}

// 00472760_set_bevel_info.cpp
void TButtonPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6) {
    bevel_type = type;
    bevel_color1 = (unsigned char)c1;
    bevel_color2 = (unsigned char)c2;
    bevel_color3 = (unsigned char)c3;
    bevel_color4 = (unsigned char)c4;
    bevel_color5 = (unsigned char)c5;
    bevel_color6 = (unsigned char)c6;
}

// 004727B0_set_disabled.cpp
// The shipped setter changes handle_mouse_input, not active.
void TButtonPanel::set_disabled(int is_disabled) {
    disabled = is_disabled;
        set_redraw(TPanel::RedrawNormal);
    if (disabled != 0) {
        handle_mouse_input = 0;
        return;
    }
    handle_mouse_input = 1;
}

// 004727F0_set_rect.cpp
void TButtonPanel::set_rect(long a, long b, long c, long d) {
    TPanel::set_rect(a, b, c, d);
}

// 00472810_get_state.cpp
// get_state (00472810, 8 bytes, Pnl_btn.cpp)
// returns this->cur_state


int TButtonPanel::get_state() {
    return cur_state;
}

// 00472820_get_id.cpp
// get_id (00472820, 15 bytes, Pnl_btn.cpp)
// returns this->id[this->cur_state]


long TButtonPanel::get_id() {
    return id[cur_state];
}

// 00472830_get_id2.cpp
// get_id2 (00472830, 15 bytes, Pnl_btn.cpp)
// returns this->id2[this->cur_state]


long TButtonPanel::get_id2() {
    return id2[cur_state];
}

// 00472840_get_text.cpp
int TButtonPanel::get_text(short state, char** out_text1, char** out_text2) {
    if (state == -1) {
        state = cur_state;
    }
    *out_text1 = text1[state];
    *out_text2 = text2[state];
    return *out_text1 != 0;
}

// 00472880_get_text_color.cpp
void TButtonPanel::get_text_color(short state, unsigned long* color1, unsigned long* color2) {
    if (state == -1) {
        state = cur_state;
    }
    *color1 = text_color1[state];
    *color2 = text_color2[state];
}

// 004728C0_draw.cpp
// __thiscall this, returns void
// The panel and button layouts, virtual slots, and bevel branch

#include <string.h>

extern char s_pnl_btn_draw[];    // "pnl_btn::draw" @ 0x5852F8
extern char s_pnl_btn_draw2[];   // "pnl_btn::draw2" @ 0x5852E8

extern "C" {
__declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* object);
__declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* rgn);
__declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode);
__declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color);
__declspec(dllimport) int __stdcall TextOutA(void* hdc, int x, int y, const char* s, int len);
}



void TButtonPanel::draw() {
    long x;
    long y;
    long calc_x;
    long x_min;
    long x_max;
    long y_min;
    long y_max;
    void* old_font;
    SIZE text_size;
    short text_length;
    char* text;

    if (render_area == 0 || visible == 0 || active == 0 ||
        drawTypeValue == DrawClear) {
        need_redraw = 0;
        return;
    }

    if (drawTypeValue == DrawFillAndText) {
        render_area->Clear(&clip_rect, color);
    } else if (parent_panel != 0) {
        if (bevel_type >= 2 && bevel_type <= 4) {
            parent_panel->draw_rect2(&clip_rect);
        } else if (parent_panel->just_drawn == 0) {
            parent_panel->draw_rect(&clip_rect);
        }
    }

    draw_setup(0);

    if (drawTypeValue == DrawPicture ||
        drawTypeValue == DrawPictureAndText ||
        drawTypeValue == DrawBevelPicture) {
        if (render_area->Lock(s_pnl_btn_draw, 1) != 0) {
            if (pic[cur_state] != 0) {
                if (auto_pic_pos != 0) {
                    pic[cur_state]->shape_minmax(
                        x_min, y_min, x_max, y_max, pic_index[cur_state]);
                    pic_x = (short)(pnl_wid / 2 -
                                    (x_max - x_min + 1) / 2 - x_min);
                    pic_y = (short)(pnl_hgt / 2 -
                                    (y_max - y_min + 1) / 2 - y_min);
                }

                x = pic_x + pnl_x;
                y = pic_y + pnl_y;
                if ((draw_reverse == 0 && is_down != 0) ||
                    (draw_reverse != 0 && is_down == 0)) {
                    ++x;
                    --y;
                }
                pic[cur_state]->shape_draw(
                    render_area, x, y, pic_index[cur_state], 0, 0);
            }
            render_area->Unlock(s_pnl_btn_draw);
        }
    }

    if (drawTypeValue == DrawText ||
        drawTypeValue == DrawPictureAndText ||
        drawTypeValue == DrawFillAndText) {
        void* dc = render_area->GetDc(s_pnl_btn_draw);
        if (dc != 0) {
            SelectClipRgn(dc, clip_rgn);
            old_font = SelectObject(dc, font);
            SetBkMode(dc, 1);

            calc_x = text_x;
            if (calc_x == -1) {
                calc_x = pnl_wid / 2;
            }
            y = text_y;
            if (y == -1) {
                y = pnl_hgt / 2;
            }

            text = text1[cur_state];
            if (text == 0) {
                text = text1[0];
            }
            if (text != 0) {
                text_length = (short)strlen(text);
                GetTextExtentPoint32A(dc, text, text_length, &text_size);
                long text_x_pos = calc_x - text_size.cx / 2 + pnl_x;
                long text_y_pos;
                if (text2[cur_state] != 0) {
                    text_y_pos = y - font_hgt + pnl_y;
                } else {
                    text_y_pos = y - font_hgt / 2 + pnl_y;
                }

                if ((draw_reverse == 0 && is_down != 0) ||
                    (draw_reverse != 0 && is_down == 0)) {
                    ++text_x_pos;
                    --text_y_pos;
                }

                if (have_focus == 0) {
                    SetTextColor(dc, text_color2[cur_state]);
                    TextOutA(dc, text_x_pos - 1, text_y_pos + 1, text,
                             text_length);
                    SetTextColor(dc, text_color1[cur_state]);
                    TextOutA(dc, text_x_pos, text_y_pos, text, text_length);
                } else {
                    SetTextColor(dc, highlight_text_color2[cur_state]);
                    TextOutA(dc, text_x_pos - 1, text_y_pos + 1, text,
                             text_length);
                    SetTextColor(dc, highlight_text_color1[cur_state]);
                    TextOutA(dc, text_x_pos, text_y_pos, text, text_length);
                }

                text = text2[cur_state];
                if (text == 0) {
                    text = text2[0];
                }
                if (text != 0) {
                    text_length = (short)strlen(text);
                    GetTextExtentPoint32A(dc, text, text_length, &text_size);
                    text_x_pos = calc_x - text_size.cx / 2 + pnl_x;
                    text_y_pos = y + pnl_y;

                    if ((draw_reverse == 0 && is_down != 0) ||
                        (draw_reverse != 0 && is_down == 0)) {
                        ++text_x_pos;
                        --text_y_pos;
                    }

                    if (have_focus == 0) {
                        SetTextColor(dc, text_color2[cur_state]);
                        TextOutA(dc, text_x_pos - 1, text_y_pos + 1, text,
                                 text_length);
                        SetTextColor(dc, text_color1[cur_state]);
                        TextOutA(dc, text_x_pos, text_y_pos, text,
                                 text_length);
                    } else {
                        SetTextColor(dc, highlight_text_color2[cur_state]);
                        TextOutA(dc, text_x_pos - 1, text_y_pos + 1, text,
                                 text_length);
                        SetTextColor(dc, highlight_text_color1[cur_state]);
                        TextOutA(dc, text_x_pos, text_y_pos, text,
                                 text_length);
                    }
                }
            }

            SelectObject(dc, old_font);
            SelectClipRgn(dc, 0);
            render_area->ReleaseDc(s_pnl_btn_draw);
        }
    }

    if (drawTypeValue == DrawText ||
        drawTypeValue == DrawPictureAndText ||
        drawTypeValue == DrawFillAndText ||
        drawTypeValue == DrawBevelPicture) {
        if (render_area->Lock(s_pnl_btn_draw2, 1) != 0) {
            if (disabled != 0) {
                render_area->DrawRect(
                    pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                    pnl_y + pnl_hgt - 1, bevel_color6);
                render_area->DrawRect(
                    pnl_x + 1, pnl_y + 1, pnl_x + pnl_wid - 2,
                    pnl_y + pnl_hgt - 2, bevel_color1);
            } else if ((draw_reverse == 0 && is_down == 0) ||
                       (draw_reverse != 0 && is_down != 0)) {
                switch (bevel_type) {
                case 1:
                    render_area->DrawVertLine(
                        pnl_x + pnl_wid - 1, pnl_y + 1, pnl_hgt - 1, 0);
                    render_area->DrawHorzLine(
                        pnl_x + 1, pnl_y + pnl_hgt - 1, pnl_wid - 1, 0);
                    render_area->DrawRect(
                        pnl_x, pnl_y, pnl_x + pnl_wid - 2,
                        pnl_y + pnl_hgt - 2, 0xFF);
                    break;
                case 2:
                    render_area->DrawBevel(
                        pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                        pnl_y + pnl_hgt - 1, bevel_color1, bevel_color6);
                    break;
                case 3:
                    render_area->DrawBevel2(
                        pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                        pnl_y + pnl_hgt - 1, bevel_color1, bevel_color2,
                        bevel_color5, bevel_color6);
                    break;
                case 4:
                    render_area->DrawBevel3(
                        pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                        pnl_y + pnl_hgt - 1, bevel_color1, bevel_color2,
                        bevel_color3, bevel_color4, bevel_color5,
                        bevel_color6);
                    break;
                }
            } else {
                switch (bevel_type) {
                case 1:
                    render_area->DrawRect(
                        pnl_x + 1, pnl_y + 1, pnl_x + pnl_wid - 2,
                        pnl_y + pnl_hgt - 2, 0xFF);
                    break;
                case 2:
                    render_area->DrawBevel(
                        pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                        pnl_y + pnl_hgt - 1, bevel_color6, bevel_color1);
                    break;
                case 3:
                    render_area->DrawBevel21(
                        pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                        pnl_y + pnl_hgt - 1, bevel_color6, bevel_color5,
                        bevel_color2, bevel_color1);
                    break;
                case 4:
                    render_area->DrawBevel32(
                        pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                        pnl_y + pnl_hgt - 1, bevel_color6, bevel_color5,
                        bevel_color4, bevel_color3, bevel_color2,
                        bevel_color1);
                    break;
                }
            }
            render_area->Unlock(s_pnl_btn_draw2);
        }
    }

    draw_finish();
}

// 00473120_handle_mouse_down.cpp
// The input gate checks active and mouse_captured, then uses the
// virtual hit_button test before dispatching to TPanel::handle_mouse_down.
long TButtonPanel::handle_mouse_down(unsigned char button, long x, long y, int ctrl, int shift) {
    if (active == 0) {
        return 0;
    }
    if (mouse_captured != 0) {
        return 0;
    }
    if (hit_button(x, y) == 0) {
        return 0;
    }
    return TPanel::handle_mouse_down(button, x, y, ctrl, shift);
}

// 00473180_mouse_left_dbl_click_action.cpp
long TButtonPanel::mouse_left_dbl_click_action(long p0, long p1, int p2, int p3) { return 0; }

// 00473190_mouse_left_down_action.cpp
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

long TButtonPanel::mouse_left_down_action(long x, long y, int ctrl, int shift) {
    if (disabled != 0) {
        return 0;
    }
    if (sound != 0) {
        if (sound->is_playing() != 0) {
            sound->stop();
        }
        sound->play();
    }
    capture_mouse();
    is_down = 1;
    button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x372);
    set_redraw(TPanel::RedrawNormal);
    if (parent_panel != 0) {
        parent_panel->action(this, 2, id[cur_state], id2[cur_state]);
    }
    return 1;
}

// 00473240_mouse_left_move_action.cpp
// Pnl_btn.cpp lines 893-920

extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

long TButtonPanel::mouse_left_move_action(long x, long y, int ctrl, int shift) {
    int new_state = (this->is_inside(x, y) != 0);
    if (this->is_down != new_state) {
        this->is_down = new_state;
        if (new_state != 0) {
            this->button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x389);
        }
        this->set_redraw(TPanel::RedrawNormal);
        TPanel* target = this->parent_panel;
        if (this->is_down != 0) {
            if (target != 0) {
                target->action(this, 2, this->id[this->cur_state], this->id2[this->cur_state]);
                return 1;
            }
        } else if (target != 0) {
            target->action(this, 3, this->id[this->cur_state], this->id2[this->cur_state]);
        }
    }
    return 1;
}

// 00473310_mouse_left_up_action.cpp
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);


long TButtonPanel::mouse_left_up_action(long x, long y, int ctrl, int shift) {
    release_mouse();
    if (is_down != 0) {
        if (buttonTypeValue != 2) {
            is_down = 0;
        }
        set_redraw(TPanel::RedrawNormal);
        SendMessageA(render_area->Wnd, 0x0F, 0, 0);
        do_action();
        return 1;
    }
    if (buttonTypeValue == 2 && cur_state == 1) {
        is_down = 1;
        set_redraw(TPanel::RedrawNormal);
    }
    return 1;
}

// 00473390_mouse_right_dbl_click_action.cpp
long TButtonPanel::mouse_right_dbl_click_action(long p0, long p1, int p2, int p3) { return 0; }

// 004733A0_mouse_right_down_action.cpp
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

long TButtonPanel::mouse_right_down_action(long x, long y, int ctrl, int shift) {
    if (disabled != 0) {
        return 0;
    }
    if (sound != 0) {
        if (sound->is_playing() != 0) {
            sound->stop();
        }
        sound->play();
    }
    capture_mouse();
    is_down = 1;
    button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x3CC);
    set_redraw(TPanel::RedrawNormal);
    if (parent_panel != 0) {
        parent_panel->action(this, 5, id[cur_state], id2[cur_state]);
    }
    return 1;
}

// 00473450_mouse_right_move_action.cpp
// Pnl_btn.cpp

extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

long TButtonPanel::mouse_right_move_action(long x, long y, int ctrl, int shift) {
    int new_is_down = (this->is_inside(x, y) != 0);

    if (this->is_down != new_is_down) {
        this->is_down = new_is_down;
        if (new_is_down != 0) {
            this->button_down_time = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x3E3);
        }
        this->set_redraw(TPanel::RedrawNormal);
        if (this->is_down != 0) {
            if (this->parent_panel != 0) {
                this->parent_panel->action(
                    this, 5, this->id[this->cur_state], this->id2[this->cur_state]);
            }
            return 1;
        } else if (this->parent_panel != 0) {
            this->parent_panel->action(
                this, 6, this->id[this->cur_state], this->id2[this->cur_state]);
        }
    }

    return 1;
}

// 00473520_mouse_right_up_action.cpp
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);


long TButtonPanel::mouse_right_up_action(long x, long y, int ctrl, int shift) {
    release_mouse();
    if (is_down != 0) {
        if (buttonTypeValue != 2) {
            is_down = 0;
        }
        set_redraw(TPanel::RedrawNormal);
        SendMessageA(render_area->Wnd, 0x0F, 0, 0);
        do_right_action(shift);
        return 1;
    }
    if (buttonTypeValue == 2 && cur_state == 1) {
        is_down = 1;
        set_redraw(TPanel::RedrawNormal);
    }
    return 1;
}

// 004735B0_handle_key_down.cpp

extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

long TButtonPanel::handle_key_down(long key, short ch, int a3, int a4, int a5) {
    if (active != 0 && disabled == 0 && a3 == 0 && a4 == 0 &&
        hotkey != 0 && key == hotkey && key_down == 0 &&
        (hotkey_shift == 0 || a5 == hotkey_shift)) {
        if (tab_stop != 0 && parent_panel != 0 && have_focus == 0) {
            parent_panel->set_curr_child(this);
        }
        if (sound != 0) {
            if (sound->is_playing() != 0) {
                sound->stop();
            }
            sound->play();
        }
        key_down = key;
        is_down = 1;
        button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x421);
        set_redraw(TPanel::RedrawNormal);
        if (parent_panel != 0) {
            parent_panel->action(this, 2, id[cur_state], id2[cur_state]);
        }
        return 1;
    }
    return TPanel::handle_key_down(key, ch, a3, a4, a5);
}

// 004736F0_key_down_action.cpp

extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

long TButtonPanel::key_down_action(long key, short ch, int a3, int a4, int a5) {
    TPanel* child;

    if (key_down != 0) {
        return 0;
    }

    switch (key) {
    case 0x28:
        if (a3 == 0 && a4 == 0 && tab_stop != 0 && parent_panel != 0) {
            child = tab_next_panel;
            if (child != 0) {
                parent_panel->set_curr_child(child);
            }
        }
        return 1;

    case 0x26:
        if (a3 == 0 && a4 == 0 && tab_stop != 0 && parent_panel != 0) {
            child = tab_prev_panel;
            if (child != 0) {
                parent_panel->set_curr_child(child);
            }
        }
        return 1;

    case 0x0D:
    case 0x20:
        if (disabled != 0 || a3 != 0 || a4 != 0) {
            break;
        }
        if (sound != 0) {
            if (sound->is_playing() != 0) {
                sound->stop();
            }
            sound->play();
        }
        key_down = key;
        is_down = 1;
        button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x44B);
        set_redraw(TPanel::RedrawNormal);
        if (parent_panel != 0) {
            parent_panel->action(this, 2, id[cur_state], id2[cur_state]);
        }
        return 1;

    default:
        break;
    }
    return 0;
}

// 00473890_wnd_proc.cpp

extern "C" __declspec(dllimport) long __stdcall SendMessageA(void* hwnd, unsigned msg, unsigned wparam, long lparam);




long TButtonPanel::wnd_proc(void* hwnd, unsigned msg, unsigned wp, long lp) {
    if (msg == 0x101 && this->key_down != 0 && wp == this->key_down) {
        int buttonType = this->buttonTypeValue;
        this->key_down = 0;
        if (buttonType != 2) {
            this->is_down = 0;
        }
        this->set_redraw(TPanel::RedrawNormal);
        SendMessageA(this->render_area->Wnd, 0x0F, 0, 0);
        this->do_action();
        return 1;
    }
    return TPanel::wnd_proc(hwnd, msg, wp, lp);
}

// 00473920_char_action.cpp
long TButtonPanel::char_action(long p0, short p1) { return 0; }

// 00473930_hit_button.cpp

#include <stdlib.h>

int TButtonPanel::hit_button(long param_1, long param_2) {
    int hit = this->is_inside(param_1, param_2);
    if (hit == 0) {
        return 0;
    }
    if (this->all_hot != 0) {
        return 1;
    }
    if (this->pic[this->cur_state] != 0) {
        int idx = this->pic_index[this->cur_state];
        int y = (param_2 - this->pic_y) - this->pnl_y;
        int x = (param_1 - this->pic_x) - this->pnl_x;
        return this->pic[this->cur_state]->shape_check(x, y, idx) ? 1 : 0;
    }
    return 1;
}

// 004739B0_do_action.cpp
// Pnl_btn.cpp

extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

void TButtonPanel::do_action(void) {
    if (this->buttonTypeValue == 3) {
        if ((int)this->cur_state == this->num_states - 1) {
            this->set_state(0);
        } else {
            this->set_state(this->cur_state + 1);
        }
    } else if (this->buttonTypeValue == 2) {
        this->set_radio_button();
    }

    if (this->parent_panel != 0) {
        this->parent_panel->action(this, 3, this->id[this->cur_state],
                                   this->id2[this->cur_state]);
    }

    if (this->notifyTypeValue == 1) {
        if (this->parent_panel != 0) {
            this->parent_panel->action(this, 1, this->id[this->cur_state],
                                       this->id2[this->cur_state]);
            return;
        }
    } else if (this->id[this->cur_state] != 0 ||
               this->id2[this->cur_state] != 0) {
        SendMessageA(this->render_area->Wnd, 0x111,
                     this->id[this->cur_state], this->id2[this->cur_state]);
    }
}

// 00473AA0_do_right_action.cpp
// Pnl_btn.cpp

extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

void TButtonPanel::do_right_action(int ctrl) {
    if (this->buttonTypeValue == 3) {
        if ((int)this->cur_state == this->num_states - 1) {
            this->set_state(0);
        } else {
            this->set_state(this->cur_state + 1);
        }
    } else if (this->buttonTypeValue == 2) {
        this->set_radio_button();
    }

    short state = this->cur_state;
    long id_value = this->id[state];
    long id2_value = this->id2[state];

    if (this->parent_panel != 0) {
        this->parent_panel->action(this, 6, id_value, id2_value);
    }

    if (this->notifyTypeValue == 1) {
        if (this->parent_panel != 0) {
            this->parent_panel->action(this, 4, id_value, id2_value);
            return;
        }
    } else if (this->id[this->cur_state] != 0 ||
               this->id2[this->cur_state] != 0) {
        SendMessageA(this->render_area->Wnd, 0x111, id_value, id2_value);
    }
}

// 00473B80_reset.cpp
void TButtonPanel::reset(void) {
    release_mouse();
    if (is_down != 0) {
        if (buttonTypeValue != 2) {
            is_down = 0;
        }
        set_redraw(TPanel::RedrawNormal);
    }
}

// 00473BB0_set_sound_number.cpp
void TButtonPanel::set_sound_number(int v) { this->sound_number = v; }

// 00473BC0_stop_sound_system.cpp
void TButtonPanel::stop_sound_system(void) {
    if (this->sound != 0) {
        this->sound = 0;
    }
}

// 00473BE0_restart_sound_system.cpp
extern RGE_Base_Game* rge_base_game;

int TButtonPanel::restart_sound_system(void) {
    if (this->sound_number != -1) {
        this->sound = rge_base_game->get_sound(this->sound_number);
    }
    return 1;
}
