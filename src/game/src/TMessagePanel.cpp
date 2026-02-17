#include "../include/TMessagePanel.h"

#include <string.h>
#include <windows.h>

static void tmessagepanel_init_fields(TMessagePanel* panel, void* font, long font_wid, long font_hgt) {
    panel->types = nullptr;
    panel->text[0] = '\0';
    panel->showing_message = 0;
    panel->start_time = 0;
    panel->duration = 8000;
    panel->font = font;
    panel->font_width = font_wid;
    panel->font_height = font_hgt;
    panel->index_color = 0;
    panel->font_color1 = 0xFFFFFF;
    panel->font_color2 = 0;
    panel->horz_just = 0;
    panel->vert_just = 0;
    panel->word_wrap = 0;
    panel->image_clip_region = nullptr;
    panel->ImageBuffer = nullptr;
    panel->Icon = nullptr;
    panel->IconIndex = 0;
    panel->IconX = 0;
    panel->IconY = 0;
    panel->IconWidth = 0;
    panel->IconHeight = 0;
    panel->IconFrame1 = 0;
    panel->IconFrame2 = 0;
}

TMessagePanel::TMessagePanel() : TPanel() {
    // TODO: STUB: Minimal constructor until full pnl_msg.cpp parity is restored.
    tmessagepanel_init_fields(this, nullptr, 0, 0);
    this->set_active(0);
}

TMessagePanel::TMessagePanel(void* param_1, long param_2, long param_3) : TPanel() {
    // TODO: STUB: Minimal constructor parity for scr_game message panel creation path.
    tmessagepanel_init_fields(this, param_1, param_2, param_3);
    this->set_active(0);
}

TMessagePanel::~TMessagePanel() {
    // TODO: STUB: Full image-buffer/region lifecycle parity from pnl_msg.cpp is pending.
    if (this->image_clip_region != nullptr) {
        DeleteObject((HGDIOBJ)this->image_clip_region);
        this->image_clip_region = nullptr;
    }
    if (this->ImageBuffer != nullptr) {
        delete this->ImageBuffer;
        this->ImageBuffer = nullptr;
    }
}

void TMessagePanel::set_rect(tagRECT param_1) { TPanel::set_rect(param_1); }
void TMessagePanel::set_rect(long param_1, long param_2, long param_3, long param_4) { TPanel::set_rect(param_1, param_2, param_3, param_4); }
void TMessagePanel::draw_setup(int param_1) { TPanel::draw_setup(param_1); }
void TMessagePanel::draw_finish() { TPanel::draw_finish(); }
void TMessagePanel::draw() { TPanel::draw(); }
void TMessagePanel::draw_rect(tagRECT* param_1) { TPanel::draw_rect(param_1); }
long TMessagePanel::handle_idle() {
    if (this->showing_message != 0) {
        unsigned long now = GetTickCount();
        if (this->duration != 0 && now - this->start_time >= this->duration) {
            this->remove_message();
        }
    }
    return TPanel::handle_idle();
}

void TMessagePanel::handle_mouse_down(int param_1, int param_2, int param_3, int param_4, int param_5) {
    (void)TPanel::handle_mouse_down((uchar)param_1, param_2, param_3, param_4, param_5);
}

void TMessagePanel::handle_mouse_move(int param_1, int param_2, int param_3, int param_4, int param_5) {
    (void)param_5;
    (void)TPanel::handle_mouse_move(param_1, param_2, param_3, param_4);
}

void TMessagePanel::handle_mouse_up(int param_1, int param_2, int param_3, int param_4, int param_5) {
    (void)TPanel::handle_mouse_up((uchar)param_1, param_2, param_3, param_4, param_5);
}

void TMessagePanel::handle_key_down(int param_1, int param_2, int param_3, int param_4, int param_5) {
    (void)TPanel::handle_key_down(param_1, (short)param_2, param_3, param_4, param_5);
}

void TMessagePanel::handle_key_up(int param_1, int param_2, int param_3, int param_4, int param_5) {
    // TODO: STUB: key-up handling parity not yet implemented in pnl_msg path.
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
}

void TMessagePanel::handle_char(int param_1, int param_2, int param_3, int param_4, int param_5) {
    (void)param_3;
    (void)param_4;
    (void)param_5;
    (void)TPanel::handle_char(param_1, (short)param_2);
}

void TMessagePanel::handle_scroll(int param_1, int param_2, int param_3, int param_4, int param_5) {
    (void)param_3;
    (void)param_4;
    (void)param_5;
    (void)TPanel::handle_scroll(param_1, param_2);
}

int TMessagePanel::is_inside(int param_1, int param_2) { return TPanel::is_inside(param_1, param_2); }
void TMessagePanel::set_active(int param_1) { TPanel::set_active(param_1); }

void TMessagePanel::set_visible(int param_1) {
    this->visible = param_1;
    this->set_redraw(TPanel::Redraw);
}

void TMessagePanel::set_redraw(RedrawMode param_1) { TPanel::set_redraw(param_1); }
void TMessagePanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TPanel::set_overlapped_redraw(param_1, param_2, param_3); }

void TMessagePanel::add_panel(TPanel* param_1) {
    // TODO: STUB: dedicated child-panel handling parity pending.
    (void)param_1;
}

void TMessagePanel::remove_panel(TPanel* param_1) {
    // TODO: STUB: dedicated child-panel handling parity pending.
    (void)param_1;
}

void TMessagePanel::remove_all_panels() {
    // TODO: STUB: dedicated child-panel handling parity pending.
}

void TMessagePanel::set_message(char* param_1) {
    if (param_1 == nullptr) {
        this->clear_message();
        return;
    }

    strncpy(this->text, param_1, sizeof(this->text));
    this->text[sizeof(this->text) - 1] = '\0';
    this->showing_message = 1;
    this->start_time = GetTickCount();
    this->set_active(1);
    this->set_redraw(TPanel::Redraw);
}

void TMessagePanel::set_message(int param_1) {
    char* s = this->get_string(param_1);
    this->set_message(s);
}

void TMessagePanel::clear_message() {
    this->text[0] = '\0';
    this->showing_message = 0;
    this->set_active(0);
    this->set_redraw(TPanel::Redraw);
}

void TMessagePanel::set_time(unsigned long param_1) { this->duration = param_1; }
void TMessagePanel::set_color(unsigned long param_1, unsigned long param_2) { this->font_color1 = param_1; this->font_color2 = param_2; }
void TMessagePanel::set_style(int param_1) { this->index_color = param_1; }
void TMessagePanel::set_alignment(int param_1, int param_2) { this->horz_just = param_1; this->vert_just = param_2; }
void TMessagePanel::set_wrap(int param_1) { this->word_wrap = param_1; }
void TMessagePanel::set_icon(int param_1) { this->IconIndex = param_1; }

void TMessagePanel::handle_move_outside(int param_1, int param_2, int param_3, int param_4, int param_5) {
    // TODO: STUB: outside-hover behavior parity is pending.
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
}

void TMessagePanel::handle_reactivate() {
    // TODO: STUB: reactivation behavior parity is pending.
}

void TMessagePanel::set_font(void* param_1, long param_2, long param_3) {
    this->font = param_1;
    this->font_width = param_2;
    this->font_height = param_3;
    this->set_redraw(TPanel::Redraw);
}

void TMessagePanel::set_justification(int param_1, int param_2, int param_3) {
    this->set_alignment(param_1, param_2);
    this->set_wrap(param_3);
}

void TMessagePanel::remove_message() {
    this->clear_message();
}
