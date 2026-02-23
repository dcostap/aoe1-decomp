#include "../include/ui_core.h"
#include "../include/TShape.h"
#include "../include/TDrawArea.h"
#include "../include/TDigital.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Font.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"
#include <stdlib.h>

static unsigned long button_time_ms() {
    return (unsigned long)GetTickCount();
}

static void button_notify_parent(TButtonPanel* btn, long code) {
    if (!btn || !btn->parent_panel) return;
    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("button_notify_parent btn=%p code=%ld parent=%p id=%ld id2=%ld",
        btn, code, btn->parent_panel, btn->id[btn->cur_state], btn->id2[btn->cur_state]);
    CUSTOM_DEBUG_END
    btn->parent_panel->action(btn, code, (ulong)btn->id[btn->cur_state], (ulong)btn->id2[btn->cur_state]);
}

static void button_send_command(TButtonPanel* btn, short state) {
    if (!btn || !btn->render_area || !btn->render_area->Wnd) return;
    if (state < 0 || state >= 9) return;

    const long id = btn->id[state];
    const long id2 = btn->id2[state];
    if (id != 0 || id2 != 0) {
        SendMessageA((HWND)btn->render_area->Wnd, WM_COMMAND, (WPARAM)id, (LPARAM)id2);
    }
}

// Constructor
TButtonPanel::TButtonPanel() : TPanel("Button") {
    memset((unsigned char*)this + sizeof(TPanel), 0, sizeof(TButtonPanel) - sizeof(TPanel));

    // Defaults verified against `src/game/src/Pnl_btn.cpp.decomp` / `.asm` (immutable references).
    this->buttonTypeValue = TButtonPanel::Normal;
    this->drawTypeValue = TButtonPanel::DrawClear;
    this->notifyTypeValue = TButtonPanel::NotifyAction;
    this->auto_pic_pos = 1;
    this->all_hot = 1;
    this->text_x = -1;
    this->text_y = -1;
    this->num_states = 1;
    this->bevel_type = 1;
    this->sound_number = -1;
    this->sound = nullptr;
    this->pic_x = 0;
    this->pic_y = 0;
    this->draw_reverse = 0;
    this->font = nullptr;
    this->font_wid = 0;
    this->font_hgt = 0;
    this->cur_state = 0;
    this->is_down = 0;
    this->radio_buttons = nullptr;
    this->num_radio_buttons = 0;
    this->button_down_time = 0;
    this->hotkey = 0;
    this->hotkey_shift = 0;
    this->bevel_color1 = 0;
    this->bevel_color2 = 0;
    this->bevel_color3 = 0;
    this->bevel_color4 = 0;
    this->bevel_color5 = 0;
    this->bevel_color6 = 0;
    this->key_down = 0;
    this->disabled = 0;

    for (int i = 0; i < 9; ++i) {
        this->id[i] = 0;
        this->id2[i] = 0;
        this->pic[i] = nullptr;
        this->pic_index[i] = -1;
        this->text1[i] = nullptr;
        this->text2[i] = nullptr;
        this->text_color1[i] = 0x00FFFFFF;
        this->text_color2[i] = 0;
        this->highlight_text_color1[i] = 0x0000FFFF;
        this->highlight_text_color2[i] = 0;
    }
}

// Destructor
TButtonPanel::~TButtonPanel() {
    for (int i = 0; i < 9; ++i) {
        if (this->text1[i]) {
            free(this->text1[i]);
            this->text1[i] = nullptr;
        }
        if (this->text2[i]) {
            free(this->text2[i]);
            this->text2[i] = nullptr;
        }
    }

    if (this->radio_buttons) {
        free(this->radio_buttons);
        this->radio_buttons = nullptr;
    }
}

// Virtual Implementations
long TButtonPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, TButtonPanel::DrawType param_7, TDigital* param_8, TButtonPanel::NotifyType param_9, long param_10) {
    TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0);

    this->drawTypeValue = param_7;
    this->notifyTypeValue = param_9;
    this->set_sound(param_8);
    this->set_id(0, param_10, 0);
    return 1;
}
void TButtonPanel::set_rect(tagRECT param_1) { TPanel::set_rect(param_1); }
void TButtonPanel::set_rect(long param_1, long param_2, long param_3, long param_4) { TPanel::set_rect(param_1, param_2, param_3, param_4); }
void TButtonPanel::set_color(uchar param_1) { TPanel::set_color(param_1); }
void TButtonPanel::set_active(int param_1) { TPanel::set_active(param_1); }
void TButtonPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void TButtonPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TButtonPanel::set_redraw(TPanel::RedrawMode param_1) { TPanel::set_redraw(param_1); }
void TButtonPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, TPanel::RedrawMode param_3) {
    TPanel::set_overlapped_redraw(param_1, param_2, param_3);
}
void TButtonPanel::draw_setup(int param_1) { TPanel::draw_setup(param_1); }
void TButtonPanel::draw_finish() { TPanel::draw_finish(); }
void TButtonPanel::draw_rect(tagRECT* param_1) { TPanel::draw_rect(param_1); }
void TButtonPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset(param_1, param_2, param_3); }
void TButtonPanel::draw_rect2(tagRECT* param_1) { TPanel::draw_rect2(param_1); }
void TButtonPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset2(param_1, param_2, param_3); }
void TButtonPanel::paint() {}
// TButtonPanel inherited stubs (removed to use TPanel base or new overrides)
long TButtonPanel::handle_paint() { return 0; }
long TButtonPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TButtonPanel::handle_char(long param_1, short param_2) { return 0; }
long TButtonPanel::handle_user_command(uint param_1, long param_2) { return 0; }
long TButtonPanel::handle_timer_command(uint param_1, long param_2) { return 0; }
long TButtonPanel::handle_scroll(long param_1, long param_2) { return 0; }
// ASM: TButtonPanel does NOT override handle_mouse_dbl_click — inherit TPanel's default
// which includes is_inside check and fallback to handle_mouse_down.
long TButtonPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5);
}
long TButtonPanel::handle_mouse_move(long x, long y, int wparam, int param_4) {
    if (!this->active) return 0;

    if (!this->mouse_captured) {
        return TPanel::handle_mouse_move(x, y, wparam, param_4);
    }

    if (this->mouse_down_button == 1) {
        return this->mouse_left_move_action(x, y, wparam, param_4);
    }
    if (this->mouse_down_button == 2) {
        return this->mouse_right_move_action(x, y, wparam, param_4);
    }

    return this->mouse_move_action(x, y, wparam, param_4);
}
long TButtonPanel::mouse_move_action(long x, long y, int wparam, int param_4) {
    // Original TButtonPanel does NOT override mouse_move_action (not in Pnl_btn.cpp.asm).
    // Hover focus is NOT set here; captured-path tracking is in mouse_left_move_action.
    (void)x; (void)y; (void)wparam; (void)param_4;
    return 0;
}
long TButtonPanel::mouse_left_move_action(long x, long y, int wparam, int param_4) {
    (void)wparam;
    (void)param_4;

    const int down_now = this->hit_button(x, y) ? 1 : 0;
    if (this->is_down != down_now) {
        this->is_down = down_now;
        if (down_now) {
            this->button_down_time = button_time_ms();
            this->set_focus(1);
            button_notify_parent(this, 2);
        } else {
            this->set_focus(0);
            button_notify_parent(this, 3);
        }
        this->set_redraw(TPanel::RedrawMode::Redraw);
    }

    return 1;
}
long TButtonPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;

    if (!this->active || !this->visible) return 0;
    if (this->disabled != 0) return 0;

    this->capture_mouse();
    this->is_down = 1;
    this->button_down_time = button_time_ms();
    this->set_focus(1);
    this->set_redraw(TPanel::RedrawMode::Redraw);
    button_notify_parent(this, 5);
    return 1;
}
long TButtonPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_right_move_action(long x, long y, int param_3, int param_4) {
    (void)param_3;
    (void)param_4;

    const int down_now = this->hit_button(x, y) ? 1 : 0;
    if (this->is_down != down_now) {
        this->is_down = down_now;
        if (down_now) {
            this->button_down_time = button_time_ms();
            this->set_focus(1);
            button_notify_parent(this, 5);
        } else {
            this->set_focus(0);
            button_notify_parent(this, 6);
        }
        this->set_redraw(TPanel::RedrawMode::Redraw);
    }
    return 1;
}
long TButtonPanel::mouse_right_up_action(long x, long y, int param_3, int param_4) {
    (void)param_3;
    (void)param_4;

    this->release_mouse();

    if (this->is_down != 0) {
        if (this->buttonTypeValue != TButtonPanel::Radio) {
            this->is_down = 0;
        }
        this->set_focus(this->hit_button(x, y) ? 1 : 0);
        this->set_redraw(TPanel::RedrawMode::Redraw);
        if (this->render_area && this->render_area->Wnd) {
            SendMessageA((HWND)this->render_area->Wnd, WM_PAINT, 0, 0);
        }
        this->do_right_action(param_3);
        return 1;
    }

    if (this->buttonTypeValue == TButtonPanel::Radio && this->cur_state == 1) {
        this->is_down = 1;
        this->set_redraw(TPanel::RedrawMode::Redraw);
    }
    return 1;
}
long TButtonPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TButtonPanel::char_action(long param_1, short param_2) { return 0; }
long TButtonPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return 0; }
void TButtonPanel::get_true_render_rect(tagRECT* param_1) {}
int TButtonPanel::is_inside(long param_1, long param_2) { return TPanel::is_inside(param_1, param_2); }
void TButtonPanel::set_focus(int focused) {
    const int want = focused ? 1 : 0;
    if (this->have_focus == want) return;

    this->have_focus = want;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}
void TButtonPanel::set_tab_order(TPanel* param_1, TPanel* param_2) { TPanel::set_tab_order(param_1, param_2); }
void TButtonPanel::set_tab_order(TPanel** param_1, short param_2) {}
uchar TButtonPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return 0; }
void TButtonPanel::stop_sound_system() {
    if (this->sound != nullptr) {
        this->sound = nullptr;
    }
}
int TButtonPanel::restart_sound_system() {
    if (this->sound_number != -1) {
        this->sound = (rge_base_game != nullptr) ? rge_base_game->get_sound(this->sound_number) : nullptr;
    }
    return 1;
}
void TButtonPanel::take_snapshot() {}
void TButtonPanel::handle_reactivate() {}
void TButtonPanel::set_state(short param_1) {
    this->cur_state = param_1;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TButtonPanel::set_text_pos(long x, long y) {
    // Fully verified. Source of truth: pnl_btn.cpp.decomp @ 0x00472220
    this->text_x = x;
    this->text_y = y;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TButtonPanel::set_text_info(char* text, void* font, long wid, long hgt, long x, long y) {
    // Fully verified. Source of truth: pnl_btn.cpp.decomp @ 0x004721A0
    this->set_text_pos(x, y);
    this->set_text(0, text);
    this->set_font(font, wid, hgt);
}

void TButtonPanel::set_text_info(long resid, void* font, long wid, long hgt, long x, long y) {
    // Fully verified. Source of truth: pnl_btn.cpp.decomp @ 0x004721E0
    this->set_text_pos(x, y);
    this->set_text(0, resid);
    this->set_font(font, wid, hgt);
}

// Decomp @ Pnl_btn.cpp: returns (int)this->cur_state
int TButtonPanel::get_state() {
    return (int)this->cur_state;
}
int TButtonPanel::hit_button(long x, long y) {
    if (!this->is_inside(x, y)) return 0;
    if (this->all_hot != 0) return 1;

    if (this->cur_state >= 0 && this->cur_state < 9) {
        TShape* shp = this->pic[this->cur_state];
        if (shp) {
            long local_x = (x - this->pic_x) - this->pnl_x;
            long local_y = (y - this->pic_y) - this->pnl_y;
            return shp->shape_check(local_x, local_y, (long)this->pic_index[this->cur_state]) ? 1 : 0;
        }
    }

    return 1;
}
void TButtonPanel::set_sound_number(int num) { this->sound_number = num; }
void TButtonPanel::set_id(long val) {
    for (int i = 0; i < 9; ++i) this->id[i] = val;
}
void TButtonPanel::set_id(short state, long id, long id2) {
    if (state < 0 || state >= 9) return;
    this->id[state] = id;
    this->id2[state] = id2;
}
void TButtonPanel::set_sound(TDigital* s) { this->sound = s; }

void TButtonPanel::set_radio_info(TButtonPanel** buttons, short count) {
    // Fully verified. Source of truth: pnl_btn.cpp.decomp @ 0x00472240
    this->buttonTypeValue = TButtonPanel::Radio;

    if (this->radio_buttons != nullptr) {
        free(this->radio_buttons);
        this->radio_buttons = nullptr;
    }

    this->num_radio_buttons = 0;
    if (count == 0) {
        return;
    }

    this->num_radio_buttons = count;
    this->radio_buttons = (TButtonPanel**)calloc((int)count, 4);
    if (this->radio_buttons == nullptr) {
        this->num_radio_buttons = 0;
        return;
    }

    for (int i = 0; i < (int)count; ++i) {
        this->radio_buttons[i] = buttons[i];
    }
}

void TButtonPanel::set_radio_button() {
    // Best-effort match for `TButtonPanel::set_radio_button` in `Pnl_btn.cpp.asm`.
    for (int i = 0; i < this->num_radio_buttons; ++i) {
        if (!this->radio_buttons || !this->radio_buttons[i]) continue;
        this->radio_buttons[i]->is_down = 0;
        this->radio_buttons[i]->set_state(0);
    }

    if (this->drawTypeValue == TButtonPanel::DrawTextA || this->drawTypeValue == TButtonPanel::DrawFillAndText) {
        this->is_down = 1;
    }

    this->set_state(1);
}

void TButtonPanel::do_action() {
    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("TButtonPanel::do_action this=%p parent=%p notify=%d btnType=%d id=%ld id2=%ld",
        this, this->parent_panel, (int)this->notifyTypeValue, (int)this->buttonTypeValue,
        this->id[this->cur_state], this->id2[this->cur_state]);
    CUSTOM_DEBUG_END
    if (this->buttonTypeValue == TButtonPanel::State) {
        if (this->cur_state == (short)(this->num_states - 1)) {
            this->set_state(0);
        } else {
            this->set_state((short)(this->cur_state + 1));
        }
    } else if (this->buttonTypeValue == TButtonPanel::Radio) {
        this->set_radio_button();
    }

    // ASM @ 0x004739B0: decomp says action code 3 here but that's wrong.
    // TDropDownPanel::action ASM @ 004744ba checks CMP EBP,0x2 for btn_panel click.
    // List panel sends 2=click, 3=dblclick. Pattern: 1=notify, 2=click, 3=dblclick.
    if (this->parent_panel) {
        this->parent_panel->action(this, 2, (ulong)this->id[this->cur_state], (ulong)this->id2[this->cur_state]);
    }

    if (this->notifyTypeValue == TButtonPanel::NotifyAction) {
        if (this->parent_panel) {
            this->parent_panel->action(this, 1, (ulong)this->id[this->cur_state], (ulong)this->id2[this->cur_state]);
        }
        return;
    }

    button_send_command(this, this->cur_state);
}

void TButtonPanel::do_right_action(int param_1) {
    (void)param_1;

    if (this->buttonTypeValue == TButtonPanel::State) {
        if (this->cur_state == (short)(this->num_states - 1)) {
            this->set_state(0);
        } else {
            this->set_state((short)(this->cur_state + 1));
        }
    } else if (this->buttonTypeValue == TButtonPanel::Radio) {
        this->set_radio_button();
    }

    // ASM: decomp says 6 but correct right-click code is 5. Pattern mirrors left: 5=rclick, 6=rdblclick.
    if (this->parent_panel) {
        this->parent_panel->action(this, 5, (ulong)this->id[this->cur_state], (ulong)this->id2[this->cur_state]);
    }

    if (this->notifyTypeValue == TButtonPanel::NotifyAction) {
        if (this->parent_panel) {
            this->parent_panel->action(this, 4, (ulong)this->id[this->cur_state], (ulong)this->id2[this->cur_state]);
        }
        return;
    }

    button_send_command(this, this->cur_state);
}

void TButtonPanel::set_font(void* font, long wid, long hgt) {
    this->font = font;
    if (wid != -1) this->font_wid = wid;
    if (hgt != -1) this->font_hgt = hgt;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

// Non-Virtuals
void TButtonPanel::set_text(short state, char* text) {
    if (state < 0) state = this->cur_state;
    if (state >= 9) return;

    if (this->text1[state]) {
        free(this->text1[state]);
        this->text1[state] = nullptr;
    }
    if (this->text2[state]) {
        free(this->text2[state]);
        this->text2[state] = nullptr;
    }

    if (!text || text[0] == '\0') {
        this->set_redraw(TPanel::RedrawMode::Redraw);
        return;
    }

    char* newline = strchr(text, '\n');
    if (newline) {
        size_t len1 = newline - text;
        this->text1[state] = (char*)calloc(1, len1 + 1);
        if (this->text1[state]) {
            strncpy(this->text1[state], text, len1);
            this->text1[state][len1] = '\0';
            // Language strings sometimes use "\r\n". Strip the '\r' for accurate rendering.
            size_t tlen = strlen(this->text1[state]);
            if (tlen > 0 && this->text1[state][tlen - 1] == '\r') {
                this->text1[state][tlen - 1] = '\0';
            }
        }

        char* s2 = newline + 1;
        size_t len2 = strlen(s2);
        this->text2[state] = (char*)calloc(1, len2 + 1);
        if (this->text2[state]) {
            strcpy(this->text2[state], s2);
            size_t tlen = strlen(this->text2[state]);
            if (tlen > 0 && this->text2[state][tlen - 1] == '\r') {
                this->text2[state][tlen - 1] = '\0';
            }
        }
    } else {
        size_t len = strlen(text);
        this->text1[state] = (char*)calloc(1, len + 1);
        if (this->text1[state]) {
            strcpy(this->text1[state], text);
            size_t tlen = strlen(this->text1[state]);
            if (tlen > 0 && this->text1[state][tlen - 1] == '\r') {
                this->text1[state][tlen - 1] = '\0';
            }
        }
    }

    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TButtonPanel::set_text(short state, long resid) {
    char str[256];
    if (this->get_string(resid, str, 256)) {
        this->set_text(state, str);
    }
}

void TButtonPanel::set_text(long resid) {
    this->set_text(this->cur_state, resid);
}

void TButtonPanel::set_text(short state, long resid1, long resid2) {
    char str1[256], str2[256];
    if (this->get_string(resid1, str1, 256) && this->get_string(resid2, str2, 256)) {
        this->set_text(state, str1, str2);
    }
}

void TButtonPanel::set_text(short state, char* text1, char* text2) {
    if (state < 0) state = this->cur_state;
    if (state >= 9) return;

    if (this->text1[state]) free(this->text1[state]);
    if (this->text2[state]) free(this->text2[state]);
    this->text1[state] = nullptr;
    this->text2[state] = nullptr;

    if (text1 && text1[0] != '\0') {
        this->text1[state] = (char*)calloc(1, strlen(text1) + 1);
        if (this->text1[state]) {
            strcpy(this->text1[state], text1);
            size_t tlen = strlen(this->text1[state]);
            if (tlen > 0 && this->text1[state][tlen - 1] == '\r') {
                this->text1[state][tlen - 1] = '\0';
            }
        }
    }
    if (text2 && text2[0] != '\0') {
        this->text2[state] = (char*)calloc(1, strlen(text2) + 1);
        if (this->text2[state]) {
            strcpy(this->text2[state], text2);
            size_t tlen = strlen(this->text2[state]);
            if (tlen > 0 && this->text2[state][tlen - 1] == '\r') {
                this->text2[state][tlen - 1] = '\0';
            }
        }
    }

    this->set_redraw(TPanel::RedrawMode::Redraw);
}

long TButtonPanel::mouse_left_down_action(long x, long y, int wparam, int param_4) {
    (void)x;
    (void)y;
    (void)wparam;
    (void)param_4;

    if (!this->active || !this->visible) return 0;
    if (this->disabled != 0) return 0;

    // Decomp @ 0x00473190: play sound if set
    if (this->sound) { if (this->sound->is_playing()) this->sound->stop(); this->sound->play(); }

    // Decomp @ 0x00473190: TPanel::capture_mouse
    this->capture_mouse();
    this->is_down = 1;
    this->button_down_time = button_time_ms();
    this->set_redraw(TPanel::RedrawMode::Redraw);
    button_notify_parent(this, 2);
    return 1;
}

long TButtonPanel::mouse_left_up_action(long x, long y, int wparam, int param_4) {
    (void)wparam;
    (void)param_4;

    // Decomp @ 0x00473310: TPanel::release_mouse
    this->release_mouse();

    if (this->is_down != 0) {
        if (this->buttonTypeValue != TButtonPanel::Radio) {
            this->is_down = 0;
        }
        this->set_redraw(TPanel::RedrawMode::Redraw);
        if (this->render_area && this->render_area->Wnd) {
            SendMessageA((HWND)this->render_area->Wnd, WM_PAINT, 0, 0);
        }
        this->do_action();
        return 1;
    }

    if (this->buttonTypeValue == TButtonPanel::Radio && this->cur_state == 1) {
        this->is_down = 1;
        this->set_redraw(TPanel::RedrawMode::Redraw);
    }

    return 1;
}

void TButtonPanel::draw() {
    // Best-effort reimplementation based on immutable references:
    // - `src/game/src/Pnl_btn.cpp.asm`
    // - `src/game/src/Pnl_btn.cpp.decomp`
    //
    // TODO: The original draw path uses `TDrawArea::Lock` and span-based primitives. Our draw-area
    //       implementation is still incomplete, so bevel drawing below uses `FillRect`-based helpers.

    if (!this->visible || !this->active || !this->render_area || this->pnl_hgt <= 0 || this->pnl_wid <= 0 ||
        this->drawTypeValue == TButtonPanel::DrawClear) {
        // Source of truth: `Pnl_btn.cpp.asm` writes zero to `[this+0x38]` on early return.
        this->curr_child = nullptr;
        return;
    }

    // 1. Clear/Background restore (source of truth: `Pnl_btn.cpp.decomp`).
    //
    // Main-menu buttons (scr1) use a shaded background "plate" produced by asking the parent to
    // redraw the background clipped to this button, with `draw_rect2` (shadowed) for bevel types 2..4.
    if (this->drawTypeValue == TButtonPanel::DrawFillAndText) {
        // NOTE: The original clears using a per-panel fill byte; field mapping is not confirmed.
        this->render_area->Clear(&this->clip_rect, (int)this->color);
    } else if (this->parent_panel) {
        if (this->bevel_type >= 2 && this->bevel_type <= 4) {
            this->parent_panel->draw_rect2(&this->clip_rect);
        } else {
            // Only do the plain restore for non-overlapping parents (matches `Pnl_btn.cpp.decomp`).
            if (this->parent_panel->overlapping_children == 0) {
                this->parent_panel->draw_rect(&this->clip_rect);
            }
        }
    }

    this->draw_setup(0);

    const int draw_type = (int)this->drawTypeValue;
    const bool pressed = (this->draw_reverse == 0) ? (this->is_down != 0) : (this->is_down == 0);
    short state = this->cur_state;
    if (state < 0 || state >= 9) state = 0;

    // 2. Picture draw path (`Pnl_btn.cpp.decomp`): draw for DrawPicture / DrawPictureAndText / DrawBevelPicture.
    if (draw_type == (int)TButtonPanel::DrawPicture ||
        draw_type == (int)TButtonPanel::DrawPictureAndText ||
        draw_type == (int)TButtonPanel::DrawBevelPicture) {
        if (this->render_area->Lock((char*)"pnl_btn::draw", 1)) {
            TShape* shape = this->pic[state];
            if (shape) {
                if (this->auto_pic_pos != 0) {
                    long x_min = 0, y_min = 0, x_max = 0, y_max = 0;
                    if (shape->shape_minmax(&x_min, &y_min, &x_max, &y_max, (int)this->pic_index[state])) {
                        this->pic_x = ((this->pnl_wid / 2) - (((x_max - x_min) + 1) / 2)) - x_min;
                        this->pic_y = ((this->pnl_hgt / 2) - (((y_max - y_min) + 1) / 2)) - y_min;
                    }
                }

                long draw_x = this->pnl_x + this->pic_x;
                long draw_y = this->pnl_y + this->pic_y;
                if (pressed) {
                    draw_x++;
                    draw_y--;
                }
                shape->shape_draw(this->render_area, draw_x, draw_y, this->pic_index[state], 0, nullptr);
            }
            this->render_area->Unlock((char*)"pnl_btn::draw");
        }
    }

    // 3. GDI Text (source of truth: `Pnl_btn.cpp.decomp`).
    if (draw_type == (int)TButtonPanel::DrawTextA ||
        draw_type == (int)TButtonPanel::DrawPictureAndText ||
        draw_type == (int)TButtonPanel::DrawFillAndText) {
        HDC hdc = (HDC)this->render_area->GetDc("pnl_btn::draw");
        if (hdc) {
            if (this->clip_rgn) SelectClipRgn(hdc, (HRGN)this->clip_rgn);
            void* old_font = nullptr;
            if (this->font) old_font = SelectObject(hdc, (HGDIOBJ)this->font);
            SetBkMode(hdc, 1);

            char* line1 = this->text1[state] ? this->text1[state] : this->text1[0];
            char* line2_state = this->text2[state];
            char* line2 = line2_state ? line2_state : this->text2[0];

            if (line1 && line1[0] != '\0') {
                SIZE sz1;
                GetTextExtentPoint32A(hdc, line1, (int)strlen(line1), &sz1);

                long cx = (this->text_x == -1) ? (this->pnl_wid / 2) : this->text_x;
                long cy = (this->text_y == -1) ? (this->pnl_hgt / 2) : this->text_y;

                long tx = this->pnl_x + (cx - (sz1.cx / 2));
                long ty = this->pnl_y + (cy - (line2_state ? this->font_hgt : (this->font_hgt / 2)));

                if (pressed) {
                    tx++;
                    ty--;
                }

                const unsigned long shadow_c = (this->have_focus != 0) ? this->highlight_text_color2[state] : this->text_color2[state];
                const unsigned long main_c = (this->have_focus != 0) ? this->highlight_text_color1[state] : this->text_color1[state];

                SetTextColor(hdc, shadow_c);
                TextOutA(hdc, tx - 1, ty + 1, line1, (int)strlen(line1));
                SetTextColor(hdc, main_c);
                TextOutA(hdc, tx, ty, line1, (int)strlen(line1));

                if (line2 && line2[0] != '\0') {
                    SIZE sz2;
                    GetTextExtentPoint32A(hdc, line2, (int)strlen(line2), &sz2);
                    long tx2 = this->pnl_x + (cx - (sz2.cx / 2));
                    long ty2 = this->pnl_y + cy;
                    if (pressed) {
                        tx2++;
                        ty2--;
                    }

                    SetTextColor(hdc, shadow_c);
                    TextOutA(hdc, tx2 - 1, ty2 + 1, line2, (int)strlen(line2));
                    SetTextColor(hdc, main_c);
                    TextOutA(hdc, tx2, ty2, line2, (int)strlen(line2));
                }
            }

            if (old_font) SelectObject(hdc, (HGDIOBJ)old_font);
            SelectClipRgn(hdc, 0);
            this->render_area->ReleaseDc("pnl_btn::draw");
        }
    }

    // 4. Bevel.
    if (draw_type == (int)TButtonPanel::DrawTextA ||
        draw_type == (int)TButtonPanel::DrawPictureAndText ||
        draw_type == (int)TButtonPanel::DrawFillAndText ||
        draw_type == (int)TButtonPanel::DrawBevelPicture) {
        if (this->render_area->Lock((char*)"pnl_btn::draw2", 1)) {
            const long x1 = this->pnl_x;
            const long y1 = this->pnl_y;
            const long x2 = this->pnl_x + this->pnl_wid - 1;
            const long y2 = this->pnl_y + this->pnl_hgt - 1;

            if (x2 > x1 && y2 > y1) {
                if (this->disabled != 0) {
                    this->render_area->DrawRect(x1, y1, x2, y2, this->bevel_color6);
                    this->render_area->DrawRect(x1 + 1, y1 + 1, x2 - 1, y2 - 1, this->bevel_color1);
                } else {
                    const int down_for_bevel = pressed ? 1 : 0;
                    switch (this->bevel_type) {
                        case 2:
                            if (down_for_bevel) this->render_area->DrawBevel(x1, y1, x2, y2, this->bevel_color6, this->bevel_color1);
                            else this->render_area->DrawBevel(x1, y1, x2, y2, this->bevel_color1, this->bevel_color6);
                            break;
                        case 3:
                            if (down_for_bevel) this->render_area->DrawBevel21(x1, y1, x2, y2, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1);
                            else this->render_area->DrawBevel2(x1, y1, x2, y2, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6);
                            break;
                        case 4:
                            if (down_for_bevel) {
                                this->render_area->DrawBevel32(x1, y1, x2, y2,
                                    this->bevel_color6, this->bevel_color5, this->bevel_color4,
                                    this->bevel_color3, this->bevel_color2, this->bevel_color1);
                            } else {
                                this->render_area->DrawBevel3(x1, y1, x2, y2,
                                    this->bevel_color1, this->bevel_color2, this->bevel_color3,
                                    this->bevel_color4, this->bevel_color5, this->bevel_color6);
                            }
                            break;
                        case 1:
                        default:
                            if (down_for_bevel) {
                                this->render_area->DrawRect(x1 + 1, y1 + 1, x2 - 1, y2 - 1, 0xFF);
                            } else {
                                this->render_area->DrawVertLine(x2, y1 + 1, this->pnl_hgt - 1, 0);
                                this->render_area->DrawHorzLine(x1 + 1, y2, this->pnl_wid - 1, 0);
                                this->render_area->DrawRect(x1, y1, x2 - 1, y2 - 1, 0xFF);
                            }
                            break;
                    }
                }
            }
            this->render_area->Unlock((char*)"pnl_btn::draw2");
        }
    }

    this->draw_finish();
}

void TButtonPanel::set_state_info(int num_states) {
    // Source of truth: `src/game/src/Pnl_btn.cpp.decomp` (`set_state_info` @ 0x004722C0).
    // Original behavior is intentionally minimal:
    //   this->buttonTypeValue = State;
    //   this->num_states = param_1;
    // Keep this exact so state-cycling buttons (team/color/etc.) enter the State mode path in do_action().
    this->buttonTypeValue = TButtonPanel::State;
    this->num_states = (short)num_states;
}

// From decomp: sets a picture for a given button state
void TButtonPanel::set_picture(short state, TShape* pic_ptr, short pic_idx) {
    if (state < 0 || state >= 9) return;
    this->pic[state] = pic_ptr;
    this->pic_index[state] = pic_idx;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

// From decomp: sets bevel info on the button panel
void TButtonPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6) {
    this->bevel_type = type;
    this->bevel_color1 = (unsigned char)c1;
    this->bevel_color2 = (unsigned char)c2;
    this->bevel_color3 = (unsigned char)c3;
    this->bevel_color4 = (unsigned char)c4;
    this->bevel_color5 = (unsigned char)c5;
    this->bevel_color6 = (unsigned char)c6;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}
