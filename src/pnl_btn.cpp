// Recovered direct owner module for C:\msdev\work\age1_x1\Pnl_btn.cpp.
#include "../include/pnl_btn.h"
#include "../include/game_globals.h"
#include "../include/Shape.h"
#include "../include/sounddrv.h"
// 00471EC0_TButtonPanel.cpp
#include <string.h>

static char s_pnl_btn_draw[] = "pnl_btn::draw";
static char s_pnl_btn_draw2[] = "pnl_btn::draw2";

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
      sound_number(-1) {
    // The compiler emits the derived vptr as part of normal construction.
    ((TPanel*)this)->panel_type = 3;

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

long TButtonPanel::setup(TDrawArea* render_area_in, TPanel* parent_panel_in,
                         long x_in, long y_in, long wid_in, long hgt_in,
                         TButtonPanel::DrawType drawTypeIn, TDigital* sound_in,
                         TButtonPanel::NotifyType notifyTypeIn, long id_in) {
    TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in,
                  0);
    this->drawTypeValue = drawTypeIn;
    this->notifyTypeValue = notifyTypeIn;
    this->set_sound(sound_in);
    this->set_id(0, id_in, 0);
    return 1;
}

// 00472110_buttonType.cpp
TButtonPanel::ButtonType TButtonPanel::buttonType() const { return this->buttonTypeValue; }

// 00472120_drawType.cpp
TButtonPanel::DrawType TButtonPanel::drawType() const { return this->drawTypeValue; }

// 00472130_notifyType.cpp
TButtonPanel::NotifyType TButtonPanel::notifyType() const { return this->notifyTypeValue; }

// 00472140_setDrawType.cpp
void TButtonPanel::setDrawType(TButtonPanel::DrawType drawTypeIn) { this->drawTypeValue = drawTypeIn; }

// 00472150_setButtonType.cpp
void TButtonPanel::setButtonType(TButtonPanel::ButtonType buttonTypeIn) { this->buttonTypeValue = buttonTypeIn; }

// 00472160_set_picture_info.cpp
void TButtonPanel::set_picture_info(TShape* pic_in, short pic_index_in, long pic_x_in, long pic_y_in, int all_hot_in, int auto_pic_pos_in) {
    pic_x = pic_x_in;
    pic_y = pic_y_in;
    all_hot = all_hot_in;
    auto_pic_pos = auto_pic_pos_in;
    set_picture(0, pic_in, pic_index_in);
}

// 004721A0_set_text_info.cpp
void TButtonPanel::set_text_info(char* text_in, void* font_in, long font_wid_in, long font_hgt_in, long text_x_in, long text_y_in) {
    set_text_pos(text_x_in, text_y_in);
    set_text(0, text_in);
    set_font(font_in, font_wid_in, font_hgt_in);
}

// 004721E0_set_text_info.cpp
void TButtonPanel::set_text_info(long string_id_in, void* font_in, long font_wid_in, long font_hgt_in, long text_x_in, long text_y_in) {
    set_text_pos(text_x_in, text_y_in);
    set_text(0, string_id_in);
    set_font(font_in, font_wid_in, font_hgt_in);
}

// 00472220_set_text_pos.cpp
void TButtonPanel::set_text_pos(long text_x_in, long text_y_in) {
    this->text_x = text_x_in;
    this->text_y = text_y_in;
    this->set_redraw(TPanel::RedrawNormal);
}

// 00472240_set_radio_info.cpp

#include <stdlib.h>

void TButtonPanel::set_radio_info(TButtonPanel** buttons_in, short button_count_in) {
    TButtonPanel** old_radio = this->radio_buttons;
    this->buttonTypeValue = TButtonPanel::Radio;
    if (old_radio != 0) {
        free(old_radio);
        this->radio_buttons = 0;
    }
    if (button_count_in != 0) {
        this->num_radio_buttons = button_count_in;
        this->radio_buttons = (TButtonPanel**)calloc(button_count_in, sizeof(TButtonPanel*));
        if (button_count_in > 0) {
            int index = 0;
            int remaining = button_count_in;
            do {
                this->radio_buttons[index] = buttons_in[index];
                ++index;
                --remaining;
            } while (remaining != 0);
        }
    }
}

// 004722C0_set_state_info.cpp
void TButtonPanel::set_state_info(short num_states_in) {
    buttonTypeValue = TButtonPanel::State;
    num_states = num_states_in;
}

// 004722E0_set_id.cpp
void TButtonPanel::set_id(short state_in, long id_in, long id2_in) {
    this->id[state_in] = id_in;
    this->id2[state_in] = id2_in;
}

// 00472300_set_picture.cpp
void TButtonPanel::set_picture(short state_in, TShape* pic_in, short pic_index_in) {
    this->pic[state_in] = pic_in;
    this->pic_index[state_in] = pic_index_in;
    this->set_redraw(TPanel::RedrawNormal);
}

// 00472330_set_text.cpp

#include <string.h>

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);


void TButtonPanel::set_text(short state_in, char* text_in) {
    if (text1[state_in] != 0) {
        free(text1[state_in]);
        text1[state_in] = 0;
    }
    if (text2[state_in] != 0) {
        free(text2[state_in]);
        text2[state_in] = 0;
    }
    if (text_in != 0 && *text_in != 0) {
        char* newline = strchr(text_in, 10);
        short length;

        if (newline != 0) {
            length = (short)(newline - text_in);
        } else {
            length = (short)strlen(text_in);
        }
        text1[state_in] = (char*)calloc(length + 1, 1);
        if (text1[state_in] != 0) {
            strncpy(text1[state_in], text_in, length);
            text1[state_in][length] = 0;
            if (newline != 0) {
                newline++;
                text2[state_in] = (char*)calloc(strlen(newline) + 1, 1);
                if (text2[state_in] != 0) {
                    strcpy(text2[state_in], newline);
                }
            }
        }
    }
    set_redraw(TPanel::RedrawNormal);
}

// 00472440_set_text.cpp

#include <string.h>



void TButtonPanel::set_text(short state_in, char* text1_in, char* text2_in) {
    if (text1[state_in] != 0) {
        free(text1[state_in]);
        text1[state_in] = 0;
    }
    if (text2[state_in] != 0) {
        free(text2[state_in]);
        text2[state_in] = 0;
    }
    if (text1_in != 0 && *text1_in != 0) {
        text1[state_in] = (char*)calloc(strlen(text1_in) + 1, 1);
        if (text1[state_in] != 0) {
            strcpy(text1[state_in], text1_in);
            if (text2_in != 0 && *text2_in != 0) {
                text2[state_in] = (char*)calloc(strlen(text2_in) + 1, 1);
                if (text2[state_in] != 0) {
                    strcpy(text2[state_in], text2_in);
                }
            }
        }
    }
    set_redraw(TPanel::RedrawNormal);
}

// 00472540_set_text.cpp
void TButtonPanel::set_text(short state_in, long string_id_in) {
    char str[256];

    get_string(string_id_in, str, 256);
    set_text(state_in, str);
}

// 00472580_set_text.cpp
void TButtonPanel::set_text(short state_in, long string_id1_in, long string_id2_in) {
    char str2[256];
    char str1[256];

    get_string(string_id1_in, str1, 256);
    get_string(string_id2_in, str2, 256);
    set_text(state_in, str1, str2);
}

// 004725F0_set_font.cpp
void TButtonPanel::set_font(void* font_in, long font_wid_in, long font_hgt_in) {
    this->font = font_in;
    this->font_wid = font_wid_in;
    this->font_hgt = font_hgt_in;
    this->set_redraw(TPanel::RedrawNormal);
}

// 00472620_set_text_color.cpp
void TButtonPanel::set_text_color(int state, unsigned long text_color1_in, unsigned long text_color2_in) {
    if (state >= 0 && state <= 8) {
        text_color1[state] = text_color1_in;
        text_color2[state] = text_color2_in;
        set_redraw(TPanel::RedrawNormal);
    }
}

// 00472650_set_highlight_text_color.cpp
void TButtonPanel::set_highlight_text_color(int state, unsigned long text_color1_in, unsigned long text_color2_in) {
    if (state >= 0 && state <= 8) {
        highlight_text_color1[state] = text_color1_in;
        highlight_text_color2[state] = text_color2_in;
        set_redraw(TPanel::RedrawNormal);
    }
}

// 00472680_set_sound.cpp
void TButtonPanel::set_sound(TDigital* sound_in) { this->sound = sound_in; }

// 00472690_set_radio_button.cpp
void TButtonPanel::set_radio_button(void) {
    int i;

    for (i = 0; i < num_radio_buttons; i++) {
        radio_buttons[i]->is_down = 0;
        radio_buttons[i]->set_state(0);
    }
    if (drawTypeValue == TButtonPanel::DrawText || drawTypeValue == TButtonPanel::DrawFillAndText) {
        is_down = 1;
    }
    set_state(1);
}

// 00472700_set_state.cpp
void TButtonPanel::set_state(short state_in) {
    this->cur_state = state_in;
    this->set_redraw(TPanel::RedrawNormal);
}

// 00472720_set_state_by_id.cpp
void TButtonPanel::set_state_by_id(long id_in) {
    int i;

    for (i = 0; i < num_states; i++) {
        if (id[i] == id_in) {
            cur_state = (short)i;
            set_redraw(TPanel::RedrawNormal);
            return;
        }
    }
}

// 00472760_set_bevel_info.cpp
void TButtonPanel::set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6) {
    bevel_type = bevel_type_in;
    bevel_color1 = (unsigned char)c1;
    bevel_color2 = (unsigned char)c2;
    bevel_color3 = (unsigned char)c3;
    bevel_color4 = (unsigned char)c4;
    bevel_color5 = (unsigned char)c5;
    bevel_color6 = (unsigned char)c6;
}

// 004727B0_set_disabled.cpp
// The shipped setter changes handle_mouse_input, not active.
void TButtonPanel::set_disabled(int val) {
    disabled = val;
    set_redraw(TPanel::RedrawNormal);
    if (disabled != 0) {
        handle_mouse_input = 0;
        return;
    }
    handle_mouse_input = 1;
}

// 004727F0_set_rect.cpp
void TButtonPanel::set_rect(long x_in, long y_in, long wid_in, long hgt_in) {
    TPanel::set_rect(x_in, y_in, wid_in, hgt_in);
}

// 00472810_get_state.cpp
int TButtonPanel::get_state() {
    return cur_state;
}

// 00472820_get_id.cpp
long TButtonPanel::get_id() {
    return id[cur_state];
}

// 00472830_get_id2.cpp
long TButtonPanel::get_id2() {
    return id2[cur_state];
}

// 00472840_get_text.cpp
int TButtonPanel::get_text(short state_in, char** text1_in, char** text2_in) {
    if (state_in == -1) {
        state_in = cur_state;
    }
    *text1_in = text1[state_in];
    *text2_in = text2[state_in];
    return *text1_in != 0;
}

// 00472880_get_text_color.cpp
void TButtonPanel::get_text_color(short state_in, unsigned long* color1, unsigned long* color2) {
    if (state_in == -1) {
        state_in = cur_state;
    }
    *color1 = text_color1[state_in];
    *color2 = text_color2[state_in];
}

// 004728C0_draw.cpp
// The panel and button layouts, virtual slots, and bevel branch

#include <string.h>


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

    if (render_area == 0 || visible == 0 || active == 0 || drawTypeValue == DrawClear) {
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

    if (drawTypeValue == DrawPicture || drawTypeValue == DrawPictureAndText || drawTypeValue == DrawBevelPicture) {
        if (render_area->Lock(s_pnl_btn_draw, 1) != 0) {
            if (pic[cur_state] != 0) {
                if (auto_pic_pos != 0) {
                    pic[cur_state]->shape_minmax(x_min, y_min, x_max, y_max, pic_index[cur_state]);
                    pic_x = (short)(pnl_wid / 2 - (x_max - x_min + 1) / 2 - x_min);
                    pic_y = (short)(pnl_hgt / 2 - (y_max - y_min + 1) / 2 - y_min);
                }

                x = pic_x + pnl_x;
                y = pic_y + pnl_y;
                if ((draw_reverse == 0 && is_down != 0) || (draw_reverse != 0 && is_down == 0)) {
                    ++x;
                    --y;
                }
                pic[cur_state]->shape_draw(render_area, x, y, pic_index[cur_state], 0, 0);
            }
            render_area->Unlock(s_pnl_btn_draw);
        }
    }

    if (drawTypeValue == DrawText || drawTypeValue == DrawPictureAndText || drawTypeValue == DrawFillAndText) {
        void* dc = render_area->GetDc(s_pnl_btn_draw);
        if (dc != 0) {
            SelectClipRgn(dc, clip_rgn);
            old_font = SelectObject(dc, font);
            SetBkMode(dc, TRANSPARENT);

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

                if ((draw_reverse == 0 && is_down != 0) || (draw_reverse != 0 && is_down == 0)) {
                    ++text_x_pos;
                    --text_y_pos;
                }

                if (have_focus == 0) {
                    SetTextColor(dc, text_color2[cur_state]);
                    TextOutA(dc, text_x_pos - 1, text_y_pos + 1, text, text_length);
                    SetTextColor(dc, text_color1[cur_state]);
                    TextOutA(dc, text_x_pos, text_y_pos, text, text_length);
                } else {
                    SetTextColor(dc, highlight_text_color2[cur_state]);
                    TextOutA(dc, text_x_pos - 1, text_y_pos + 1, text, text_length);
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

                    if ((draw_reverse == 0 && is_down != 0) || (draw_reverse != 0 && is_down == 0)) {
                        ++text_x_pos;
                        --text_y_pos;
                    }

                    if (have_focus == 0) {
                        SetTextColor(dc, text_color2[cur_state]);
                        TextOutA(dc, text_x_pos - 1, text_y_pos + 1, text, text_length);
                        SetTextColor(dc, text_color1[cur_state]);
                        TextOutA(dc, text_x_pos, text_y_pos, text, text_length);
                    } else {
                        SetTextColor(dc, highlight_text_color2[cur_state]);
                        TextOutA(dc, text_x_pos - 1, text_y_pos + 1, text, text_length);
                        SetTextColor(dc, highlight_text_color1[cur_state]);
                        TextOutA(dc, text_x_pos, text_y_pos, text, text_length);
                    }
                }
            }

            SelectObject(dc, old_font);
            SelectClipRgn(dc, 0);
            render_area->ReleaseDc(s_pnl_btn_draw);
        }
    }

    if (drawTypeValue == DrawText || drawTypeValue == DrawPictureAndText || drawTypeValue == DrawFillAndText ||
        drawTypeValue == DrawBevelPicture) {
        if (render_area->Lock(s_pnl_btn_draw2, 1) != 0) {
            if (disabled != 0) {
                render_area->DrawRect(pnl_x, pnl_y, pnl_x + pnl_wid - 1, pnl_y + pnl_hgt - 1, bevel_color6);
                render_area->DrawRect(pnl_x + 1, pnl_y + 1, pnl_x + pnl_wid - 2, pnl_y + pnl_hgt - 2, bevel_color1);
            } else if ((draw_reverse == 0 && is_down == 0) || (draw_reverse != 0 && is_down != 0)) {
                switch (bevel_type) {
                case 1:
                    render_area->DrawVertLine(pnl_x + pnl_wid - 1, pnl_y + 1, pnl_hgt - 1, 0);
                    render_area->DrawHorzLine(pnl_x + 1, pnl_y + pnl_hgt - 1, pnl_wid - 1, 0);
                    render_area->DrawRect(pnl_x, pnl_y, pnl_x + pnl_wid - 2, pnl_y + pnl_hgt - 2, 0xFF);
                    break;
                case 2:
                    render_area->DrawBevel(pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                                           pnl_y + pnl_hgt - 1, bevel_color1, bevel_color6);
                    break;
                case 3:
                    render_area->DrawBevel2(pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                                            pnl_y + pnl_hgt - 1, bevel_color1, bevel_color2, bevel_color5, bevel_color6);
                    break;
                case 4:
                    render_area->DrawBevel3(pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                                            pnl_y + pnl_hgt - 1, bevel_color1, bevel_color2, bevel_color3, bevel_color4, bevel_color5,
                                            bevel_color6);
                    break;
                }
            } else {
                switch (bevel_type) {
                case 1:
                    render_area->DrawRect(pnl_x + 1, pnl_y + 1, pnl_x + pnl_wid - 2, pnl_y + pnl_hgt - 2, 0xFF);
                    break;
                case 2:
                    render_area->DrawBevel(pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                                           pnl_y + pnl_hgt - 1, bevel_color6, bevel_color1);
                    break;
                case 3:
                    render_area->DrawBevel21(pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                                             pnl_y + pnl_hgt - 1, bevel_color6, bevel_color5, bevel_color2, bevel_color1);
                    break;
                case 4:
                    render_area->DrawBevel32(pnl_x, pnl_y, pnl_x + pnl_wid - 1,
                                             pnl_y + pnl_hgt - 1, bevel_color6, bevel_color5, bevel_color4, bevel_color3, bevel_color2,
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
long TButtonPanel::handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key) {
    if (active == 0) {
        return 0;
    }
    if (mouse_captured != 0) {
        return 0;
    }
    if (hit_button(x, y) == 0) {
        return 0;
    }
    return TPanel::handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
}

// 00473180_mouse_left_dbl_click_action.cpp
long TButtonPanel::mouse_left_dbl_click_action(long x, long y, int ctrl_key, int shift_key) {
    return 0;
}

// 00473190_mouse_left_down_action.cpp
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

long TButtonPanel::mouse_left_down_action(long x, long y, int ctrl_key, int shift_key) {
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
    button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 882);
    set_redraw(TPanel::RedrawNormal);
    if (parent_panel != 0) {
        parent_panel->action(this, 2, id[cur_state], id2[cur_state]);
    }
    return 1;
}

// 00473240_mouse_left_move_action.cpp

long TButtonPanel::mouse_left_move_action(long x, long y, int ctrl_key, int shift_key) {
    int new_state = (this->is_inside(x, y) != 0);
    if (this->is_down != new_state) {
        this->is_down = new_state;
        if (new_state != 0) {
            this->button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 905);
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


long TButtonPanel::mouse_left_up_action(long x, long y, int ctrl_key, int shift_key) {
    release_mouse();
    if (is_down != 0) {
        if (buttonTypeValue != TButtonPanel::Radio) {
            is_down = 0;
        }
        set_redraw(TPanel::RedrawNormal);
        SendMessageA(render_area->Wnd, WM_PAINT, 0, 0);
        do_action();
        return 1;
    }
    if (buttonTypeValue == TButtonPanel::Radio && cur_state == 1) {
        is_down = 1;
        set_redraw(TPanel::RedrawNormal);
    }
    return 1;
}

// 00473390_mouse_right_dbl_click_action.cpp
long TButtonPanel::mouse_right_dbl_click_action(long x, long y, int ctrl_key, int shift_key) {
    return 0;
}

// 004733A0_mouse_right_down_action.cpp

long TButtonPanel::mouse_right_down_action(long x, long y, int ctrl_key, int shift_key) {
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
    button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 972);
    set_redraw(TPanel::RedrawNormal);
    if (parent_panel != 0) {
        parent_panel->action(this, 5, id[cur_state], id2[cur_state]);
    }
    return 1;
}

// 00473450_mouse_right_move_action.cpp

long TButtonPanel::mouse_right_move_action(long x, long y, int ctrl_key, int shift_key) {
    int new_is_down = (this->is_inside(x, y) != 0);

    if (this->is_down != new_is_down) {
        this->is_down = new_is_down;
        if (new_is_down != 0) {
            this->button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 995);
        }
        this->set_redraw(TPanel::RedrawNormal);
        if (this->is_down != 0) {
            if (this->parent_panel != 0) {
                this->parent_panel->action(this, 5, this->id[this->cur_state], this->id2[this->cur_state]);
            }
            return 1;
        } else if (this->parent_panel != 0) {
            this->parent_panel->action(this, 6, this->id[this->cur_state], this->id2[this->cur_state]);
        }
    }

    return 1;
}

// 00473520_mouse_right_up_action.cpp


long TButtonPanel::mouse_right_up_action(long x, long y, int ctrl_key, int shift_key) {
    release_mouse();
    if (is_down != 0) {
        if (buttonTypeValue != TButtonPanel::Radio) {
            is_down = 0;
        }
        set_redraw(TPanel::RedrawNormal);
        SendMessageA(render_area->Wnd, WM_PAINT, 0, 0);
        do_right_action(shift_key);
        return 1;
    }
    if (buttonTypeValue == TButtonPanel::Radio && cur_state == 1) {
        is_down = 1;
        set_redraw(TPanel::RedrawNormal);
    }
    return 1;
}

// 004735B0_handle_key_down.cpp


long TButtonPanel::handle_key_down(long key, short count, int alt_key, int ctrl_key, int shift_key) {
    if (active != 0 && disabled == 0 && alt_key == 0 && ctrl_key == 0 && hotkey != 0 && key == hotkey && key_down == 0 &&
        (hotkey_shift == 0 || shift_key == hotkey_shift)) {
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
        button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 1057);
        set_redraw(TPanel::RedrawNormal);
        if (parent_panel != 0) {
            parent_panel->action(this, 2, id[cur_state], id2[cur_state]);
        }
        return 1;
    }
    return TPanel::handle_key_down(key, count, alt_key, ctrl_key, shift_key);
}

// 004736F0_key_down_action.cpp


long TButtonPanel::key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key) {
    TPanel* child;

    if (key_down != 0) {
        return 0;
    }

    switch (key) {
    case VK_DOWN:
        if (alt_key == 0 && ctrl_key == 0 && tab_stop != 0 && parent_panel != 0) {
            child = tab_next_panel;
            if (child != 0) {
                parent_panel->set_curr_child(child);
            }
        }
        return 1;

    case VK_UP:
        if (alt_key == 0 && ctrl_key == 0 && tab_stop != 0 && parent_panel != 0) {
            child = tab_prev_panel;
            if (child != 0) {
                parent_panel->set_curr_child(child);
            }
        }
        return 1;

    case VK_RETURN:
    case VK_SPACE:
        if (disabled != 0 || alt_key != 0 || ctrl_key != 0) {
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
        button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 1099);
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




long TButtonPanel::wnd_proc(void* hwnd, unsigned msg, unsigned wParam, long lParam) {
    if (msg == WM_KEYUP && this->key_down != 0 && wParam == this->key_down) {
        int buttonType = this->buttonTypeValue;
        this->key_down = 0;
        if (buttonType != TButtonPanel::Radio) {
            this->is_down = 0;
        }
        this->set_redraw(TPanel::RedrawNormal);
        SendMessageA(this->render_area->Wnd, WM_PAINT, 0, 0);
        this->do_action();
        return 1;
    }
    return TPanel::wnd_proc(hwnd, msg, wParam, lParam);
}

// 00473920_char_action.cpp
long TButtonPanel::char_action(long key, short count) { return 0; }

// 00473930_hit_button.cpp

#include <stdlib.h>

int TButtonPanel::hit_button(long x, long y) {
    int hit = this->is_inside(x, y);
    if (hit == 0) {
        return 0;
    }
    if (this->all_hot != 0) {
        return 1;
    }
    if (this->pic[this->cur_state] != 0) {
        long shape_index = this->pic_index[this->cur_state];
        long shape_y = (y - this->pic_y) - this->pnl_y;
        long shape_x = (x - this->pic_x) - this->pnl_x;
        return this->pic[this->cur_state]->shape_check(shape_x, shape_y, shape_index)
                   ? 1
                   : 0;
    }
    return 1;
}

// 004739B0_do_action.cpp
// Pnl_btn.cpp

extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

void TButtonPanel::do_action(void) {
    if (this->buttonTypeValue == TButtonPanel::State) {
        if ((int)this->cur_state == this->num_states - 1) {
            this->set_state(0);
        } else {
            this->set_state(this->cur_state + 1);
        }
    } else if (this->buttonTypeValue == TButtonPanel::Radio) {
        this->set_radio_button();
    }

    if (this->parent_panel != 0) {
        this->parent_panel->action(this, 3, this->id[this->cur_state], this->id2[this->cur_state]);
    }

    if (this->notifyTypeValue == TButtonPanel::NotifyAction) {
        if (this->parent_panel != 0) {
            this->parent_panel->action(this, 1, this->id[this->cur_state], this->id2[this->cur_state]);
            return;
        }
    } else if (this->id[this->cur_state] != 0 || this->id2[this->cur_state] != 0) {
        SendMessageA(this->render_area->Wnd, WM_COMMAND, this->id[this->cur_state], this->id2[this->cur_state]);
    }
}

// 00473AA0_do_right_action.cpp
// Pnl_btn.cpp

void TButtonPanel::do_right_action(int shift_key) {
    if (this->buttonTypeValue == TButtonPanel::State) {
        if ((int)this->cur_state == this->num_states - 1) {
            this->set_state(0);
        } else {
            this->set_state(this->cur_state + 1);
        }
    } else if (this->buttonTypeValue == TButtonPanel::Radio) {
        this->set_radio_button();
    }

    short state = this->cur_state;
    long id_value = this->id[state];
    long id2_value = this->id2[state];

    if (this->parent_panel != 0) {
        this->parent_panel->action(this, 6, id_value, id2_value);
    }

    if (this->notifyTypeValue == TButtonPanel::NotifyAction) {
        if (this->parent_panel != 0) {
            this->parent_panel->action(this, 4, id_value, id2_value);
            return;
        }
    } else if (this->id[this->cur_state] != 0 || this->id2[this->cur_state] != 0) {
        SendMessageA(this->render_area->Wnd, WM_COMMAND, id_value, id2_value);
    }
}

// 00473B80_reset.cpp
void TButtonPanel::reset(void) {
    release_mouse();
    if (is_down != 0) {
        if (buttonTypeValue != TButtonPanel::Radio) {
            is_down = 0;
        }
        set_redraw(TPanel::RedrawNormal);
    }
}

// 00473BB0_set_sound_number.cpp
void TButtonPanel::set_sound_number(int sound_number_in) { this->sound_number = sound_number_in; }

// 00473BC0_stop_sound_system.cpp
void TButtonPanel::stop_sound_system(void) {
    if (this->sound != 0) {
        this->sound = 0;
    }
}

// 00473BE0_restart_sound_system.cpp

int TButtonPanel::restart_sound_system(void) {
    if (this->sound_number != -1) {
        this->sound = rge_base_game->get_sound(this->sound_number);
    }
    return 1;
}
