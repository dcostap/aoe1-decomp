#include "../include/TButtonPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TShape.h"
#include "../include/TDigital.h"
#include "../include/custom_debug.h"

// Constructor
TButtonPanel::TButtonPanel() : TPanel("Button") {}

// Destructor
TButtonPanel::~TButtonPanel() {}

// Virtual Implementations
long TButtonPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, TButtonPanel::DrawType param_7, TDigital* param_8, TButtonPanel::NotifyType param_9, long param_10) {
    TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0);

    this->drawTypeValue = param_7;
    this->notifyTypeValue = param_9;
    this->set_sound(param_8);
    this->set_id(param_10);

    return 1;
}
void TButtonPanel::set_rect(tagRECT param_1) { TPanel::set_rect(param_1); }
void TButtonPanel::set_rect(long param_1, long param_2, long param_3, long param_4) { TPanel::set_rect(param_1, param_2, param_3, param_4); }
void TButtonPanel::set_color(uchar param_1) {}
void TButtonPanel::set_active(int param_1) {}
void TButtonPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {}
void TButtonPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) {}
void TButtonPanel::set_redraw(TPanel::RedrawMode param_1) {}
void TButtonPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, TPanel::RedrawMode param_3) {}
void TButtonPanel::draw_setup(int param_1) {}
void TButtonPanel::draw_finish() {}
void TButtonPanel::draw_rect(tagRECT* param_1) {}
void TButtonPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) {}
void TButtonPanel::draw_rect2(tagRECT* param_1) {}
void TButtonPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) {}
void TButtonPanel::paint() {}
long TButtonPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return 0; }
long TButtonPanel::handle_idle() { return 0; }
long TButtonPanel::handle_size(long param_1, long param_2) { return 0; }
long TButtonPanel::handle_paint() { return 0; }
long TButtonPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TButtonPanel::handle_char(long param_1, short param_2) { return 0; }
long TButtonPanel::handle_command(uint param_1, long param_2) { return 0; }
long TButtonPanel::handle_user_command(uint param_1, long param_2) { return 0; }
long TButtonPanel::handle_timer_command(uint param_1, long param_2) { return 0; }
long TButtonPanel::handle_scroll(long param_1, long param_2) { return 0; }
long TButtonPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TButtonPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TButtonPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TButtonPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TButtonPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TButtonPanel::char_action(long param_1, short param_2) { return 0; }
long TButtonPanel::action(long param_1, ulong param_2, ulong param_3) { return 0; }
void TButtonPanel::get_true_render_rect(tagRECT* param_1) {}
int TButtonPanel::is_inside(long param_1, long param_2) { return 0; }
void TButtonPanel::set_focus(int param_1) {}
void TButtonPanel::set_tab_order(TPanel* param_1, TPanel* param_2) {}
void TButtonPanel::set_tab_order(TPanel** param_1, short param_2) {}
uchar TButtonPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return 0; }
void TButtonPanel::stop_sound_system() {}
int TButtonPanel::restart_sound_system() { return 1; }
void TButtonPanel::take_snapshot() {}
void TButtonPanel::handle_reactivate() {}
void TButtonPanel::set_state(short param_1) {
    if (param_1 < 0 || param_1 >= this->num_states) return;
    this->cur_state = param_1;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}
int TButtonPanel::hit_button(long param_1, long param_2) { return 0; }
void TButtonPanel::set_sound_number(int num) { this->sound_number = num; }
void TButtonPanel::set_id(long val) {
    for (int i = 0; i < 9; ++i) this->id[i] = val;
}
void TButtonPanel::set_sound(TDigital* s) { this->sound = s; }

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
        }

        char* s2 = newline + 1;
        size_t len2 = strlen(s2);
        this->text2[state] = (char*)calloc(1, len2 + 1);
        if (this->text2[state]) {
            strcpy(this->text2[state], s2);
        }
    } else {
        size_t len = strlen(text);
        this->text1[state] = (char*)calloc(1, len + 1);
        if (this->text1[state]) {
            strcpy(this->text1[state], text);
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
        if (this->text1[state]) strcpy(this->text1[state], text1);
    }
    if (text2 && text2[0] != '\0') {
        this->text2[state] = (char*)calloc(1, strlen(text2) + 1);
        if (this->text2[state]) strcpy(this->text2[state], text2);
    }

    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TButtonPanel::draw() {
    // Debug log to confirm button draw attempt and state
    CUSTOM_DEBUG_LOG_FMT("TButtonPanel::draw: id=%ld, vis=%d, act=%d, area=%p, w=%ld, h=%ld", 
        this->id[0], this->visible, this->active, this->render_area, this->pnl_wid, this->pnl_hgt);

    if (!this->visible || !this->active) return;
    if (!this->render_area || this->pnl_hgt <= 0 || this->pnl_wid <= 0) return;
    
    if (this->drawTypeValue == (DrawType)1) return;

    // 1. Clear/Background
    if (this->drawTypeValue == (DrawType)5) {
        this->render_area->Clear(&this->render_rect, this->bevel_color1);
    } else if (this->parent_panel) {
        // Handle transparency or overlapped redraw (best effort)
        if (this->bevel_type >= 2 && this->bevel_type <= 4) {
            // bevel drawing stub
        } else if (this->bevel_type == 0) {
            // normal draw
        }
    }

    this->draw_setup(0);

    // 2. SLP Graphics
    int draw_type = (int)this->drawTypeValue;
    if (draw_type == 2 || draw_type == 4 || draw_type == 6) {
        if (this->render_area->Lock("pnl_btn::draw", 0)) {
            short state = this->cur_state;
            if (state >= 0 && state < 9 && this->pic[state]) {
                long x = this->pnl_x + this->pic_x;
                long y = this->pnl_y + this->pic_y;
                if (this->is_down) {
                    x++; y++;
                }
                this->pic[state]->shape_draw(this->render_area, x, y, this->pic_index[state], 0, 0, nullptr);
            }
            this->render_area->Unlock("pnl_btn::draw");
        }
    }

    // 3. GDI Text
    if (draw_type == 3 || draw_type == 4 || draw_type == 5) {
        HDC hdc = (HDC)this->render_area->GetDc("pnl_btn::draw");
        if (hdc) {
            SelectClipRgn(hdc, (HRGN)this->clip_rgn);
            SelectObject(hdc, (HGDIOBJ)this->font);
            SetBkMode(hdc, TRANSPARENT);

            short state = this->cur_state;
            if (state >= 0 && state < 9 && this->text1[state]) {
                SIZE sz;
                GetTextExtentPoint32A(hdc, this->text1[state], strlen(this->text1[state]), &sz);
                
                long tx = this->pnl_x + (this->text_x == -1 ? (this->pnl_wid - sz.cx) / 2 : this->text_x);
                long ty = this->pnl_y + (this->text_y == -1 ? (this->pnl_hgt - sz.cy) / 2 : this->text_y);
                
                if (this->is_down) {
                    tx++; ty++;
                }

                SetTextColor(hdc, this->text_color1[state]);
                TextOutA(hdc, tx, ty, this->text1[state], strlen(this->text1[state]));

                if (this->text2[state]) {
                    GetTextExtentPoint32A(hdc, this->text2[state], strlen(this->text2[state]), &sz);
                    long tx2 = this->pnl_x + (this->text_x == -1 ? (this->pnl_wid - sz.cx) / 2 : this->text_x);
                    long ty2 = ty + sz.cy; // Approximation of next line
                    if (this->is_down) {
                        tx2++; ty2++;
                    }
                    SetTextColor(hdc, this->text_color1[state]);
                    TextOutA(hdc, tx2, ty2, this->text2[state], strlen(this->text2[state]));
                }
            }
            this->render_area->ReleaseDc("pnl_btn::draw");
        }
    }

    this->draw_finish();
}
