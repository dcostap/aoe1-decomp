#include "../include/TTextPanel.h"
#include "../include/TDrawArea.h"
#include <windows.h>
#include <string.h>
#include <stdlib.h>

static void free_text_list(TTextPanel* this_) {
    if (!this_) return;
    TTextPanel::TextNode* node = this_->list;
    while (node) {
        TTextPanel::TextNode* next = node->next;
        if (node->text) free(node->text);
        free(node);
        node = next;
    }
    this_->list = nullptr;
    this_->num_lines = 0;
    this_->draw_lines = 0;
    this_->top_line = 0;
    this_->bot_line = 0;
    this_->cur_line = 0;
    this_->cur_col = 0;
}

static char* dup_cstr(const char* s) {
    if (!s) return nullptr;
    size_t len = strlen(s);
    char* out = (char*)calloc(1, len + 1);
    if (!out) return nullptr;
    memcpy(out, s, len);
    out[len] = '\0';
    return out;
}

TTextPanel::TTextPanel() : TPanel(nullptr) {
    // Defaults from `src/game/src/Pnl_txt.cpp.decomp` (immutable reference).
    this->back_color = 0xff;
    this->list = nullptr;
    this->num_lines = 0;
    this->draw_lines = 0;
    this->top_line = 0;
    this->bot_line = 0;
    this->cur_line = 0;
    this->cur_col = 0;
    this->font = nullptr;
    this->font_wid = 0;
    this->font_hgt = 0;
    this->vert_align = TTextPanel::AlignCenter;
    this->horz_align = TTextPanel::AlignCenter;
    this->word_wrap = 0;
    this->text_style = TTextPanel::ChiseledStyle;
    this->text_color1 = 0x00ffffff;
    this->text_color2 = 0;
    this->highlightTextColor1 = 0x0000ffff;
    this->highlightTextColor2 = 0;
    this->scbar_panel = nullptr;
    this->auto_scbar = 0;
    this->fixed_len = 0;
    this->text_wid = 0;
    this->text_hgt = 0;
    this->back_pic = nullptr;
    this->back_pic_wid = 0;
    this->back_pic_hgt = 0;
    this->fill_back = 0;
    this->outline = 0;
    this->outline_color = 0;
    this->sorted = 0;
    this->second_column_pos = 0;
    this->full_width = 0;
    this->scbar_width = 0;
    this->scbar_active = 0;
    this->bevel_type = 0;
    this->bevel_color1 = 0;
    this->bevel_color2 = 0;
    this->bevel_color3 = 0;
    this->bevel_color4 = 0;
    this->bevel_color5 = 0;
    this->bevel_color6 = 0;
    this->clip_rgn2 = nullptr;
    this->border_size = 0;
    this->spacer_size = 0;
}

TTextPanel::~TTextPanel() {
    free_text_list(this);
    if (this->clip_rgn2) {
        DeleteObject((HGDIOBJ)this->clip_rgn2);
        this->clip_rgn2 = nullptr;
    }
}

long TTextPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

long TTextPanel::setup(TDrawArea* area, TPanel* parent, long x, long y, long w, long h, void* font, long font_wid, long font_hgt, char* back_pic_name, int fill_back, uchar back_color, int outline, uchar outline_color, short fixed_len, char* initial_text) {
    (void)back_pic_name;
    if (!TPanel::setup(area, parent, x, y, w, h, 0)) return 0;
    this->font = font;
    this->font_wid = font_wid;
    this->font_hgt = font_hgt;
    this->fill_back = fill_back;
    this->back_color = back_color;
    this->outline = outline;
    this->outline_color = outline_color;
    this->fixed_len = fixed_len;
    if (initial_text) {
        this->set_text(initial_text);
    }
    return 1;
}

void TTextPanel::set_alignment(TTextPanel::Alignment vert, TTextPanel::Alignment horz) {
    this->vert_align = vert;
    this->horz_align = horz;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TTextPanel::set_word_wrap(int enable) {
    this->word_wrap = enable;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TTextPanel::set_text_color(unsigned long c1, unsigned long c2) {
    this->text_color1 = c1;
    this->text_color2 = c2;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TTextPanel::set_highlight_text_color(unsigned long c1, unsigned long c2) {
    this->highlightTextColor1 = c1;
    this->highlightTextColor2 = c2;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TTextPanel::set_rect(tagRECT param_1) { TPanel::set_rect(param_1); }
void TTextPanel::set_rect(long param_1, long param_2, long param_3, long param_4) { TPanel::set_rect(param_1, param_2, param_3, param_4); }
void TTextPanel::set_color(uchar param_1) { TPanel::set_color(param_1); }
void TTextPanel::set_active(int param_1) { TPanel::set_active(param_1); }
void TTextPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    (void)param_10; (void)param_11; (void)param_12; (void)param_13;
    TPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
void TTextPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TTextPanel::set_redraw(RedrawMode param_1) { TPanel::set_redraw(param_1); }
void TTextPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { (void)param_1; (void)param_2; TPanel::set_overlapped_redraw(param_3); }
void TTextPanel::draw_setup(int param_1) { TPanel::draw_setup(param_1); }
void TTextPanel::draw_finish() { TPanel::draw_finish(); }

void TTextPanel::draw() {
    if (!this->visible || !this->active) return;
    if (!this->render_area) return;

    const char* text = (this->list && this->list->text) ? this->list->text : nullptr;
    if (!text || text[0] == '\0') return;

    HDC hdc = (HDC)this->render_area->GetDc((char*)"pnl_txt::draw");
    if (!hdc) return;

    HGDIOBJ old_font = nullptr;
    if (this->font) old_font = SelectObject(hdc, (HGDIOBJ)this->font);
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, (COLORREF)this->text_color1);

    RECT r;
    r.left = this->pnl_x;
    r.top = this->pnl_y;
    r.right = this->pnl_x + this->pnl_wid;
    r.bottom = this->pnl_y + this->pnl_hgt;

    UINT flags = DT_NOPREFIX;
    if (this->word_wrap) flags |= DT_WORDBREAK;
    else flags |= DT_SINGLELINE;

    if (this->horz_align == TTextPanel::AlignCenter) flags |= DT_CENTER;
    else if (this->horz_align == TTextPanel::AlignRight) flags |= DT_RIGHT;
    else flags |= DT_LEFT;

    if (this->vert_align == TTextPanel::AlignCenter) flags |= DT_VCENTER;
    else if (this->vert_align == TTextPanel::AlignBottom) flags |= DT_BOTTOM;
    else flags |= DT_TOP;

    DrawTextA(hdc, text, -1, &r, flags);

    if (old_font) SelectObject(hdc, old_font);
    this->render_area->ReleaseDc((char*)"pnl_txt::draw");
}

void TTextPanel::draw_rect(tagRECT* param_1) { (void)param_1; }
void TTextPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) { (void)param_1; (void)param_2; (void)param_3; }
void TTextPanel::draw_rect2(tagRECT* param_1) { (void)param_1; }
void TTextPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { (void)param_1; (void)param_2; (void)param_3; }
void TTextPanel::paint() {}
long TTextPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TTextPanel::handle_idle() { return 0; }
long TTextPanel::handle_size(long param_1, long param_2) { (void)param_1; (void)param_2; return 0; }
long TTextPanel::handle_paint() { return 0; }
long TTextPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; return 0; }
long TTextPanel::handle_char(long param_1, short param_2) { (void)param_1; (void)param_2; return 0; }
long TTextPanel::handle_command(uint param_1, long param_2) { (void)param_1; (void)param_2; return 0; }
long TTextPanel::handle_user_command(uint param_1, long param_2) { (void)param_1; (void)param_2; return 0; }
long TTextPanel::handle_timer_command(uint param_1, long param_2) { (void)param_1; (void)param_2; return 0; }
long TTextPanel::handle_scroll(long param_1, long param_2) { (void)param_1; (void)param_2; return 0; }
long TTextPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; return 0; }
long TTextPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; return 0; }
long TTextPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; return 0; }
long TTextPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; return 0; }
long TTextPanel::char_action(long param_1, short param_2) { (void)param_1; (void)param_2; return 0; }
long TTextPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
void TTextPanel::get_true_render_rect(tagRECT* param_1) { (void)param_1; }
int TTextPanel::is_inside(long param_1, long param_2) { return TPanel::is_inside(param_1, param_2); }
void TTextPanel::set_focus(int param_1) { (void)param_1; }
void TTextPanel::set_tab_order(TPanel* param_1, TPanel* param_2) { (void)param_1; (void)param_2; }
void TTextPanel::set_tab_order(TPanel** param_1, short param_2) { (void)param_1; (void)param_2; }
uchar TTextPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
void TTextPanel::stop_sound_system() {}
int TTextPanel::restart_sound_system() { return 1; }
void TTextPanel::take_snapshot() {}
void TTextPanel::handle_reactivate() {}

void TTextPanel::set_text(char** param_1, short param_2) {
    (void)param_2;
    free_text_list(this);
    if (!param_1) return;
    // TODO: handle multi-line lists accurately (see `Pnl_txt.cpp.decomp`).
    if (param_1[0]) this->set_text(param_1[0]);
}

void TTextPanel::set_text(long param_1) {
    char buf[1024];
    buf[0] = '\0';
    if (this->get_string((int)param_1, buf, sizeof(buf)) && buf[0] != '\0') {
        this->set_text(buf);
    } else {
        this->set_text((char*)"");
    }
}

void TTextPanel::set_text(char* param_1) {
    free_text_list(this);
    if (!param_1) param_1 = (char*)"";
    TTextPanel::TextNode* node = (TTextPanel::TextNode*)calloc(1, sizeof(TTextPanel::TextNode));
    if (!node) return;
    node->text = dup_cstr(param_1);
    node->next = nullptr;
    this->list = node;
    this->num_lines = 1;
    this->draw_lines = 1;
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TTextPanel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    this->bevel_type = param_1;
    this->bevel_color1 = (unsigned char)param_2;
    this->bevel_color2 = (unsigned char)param_3;
    this->bevel_color3 = (unsigned char)param_4;
    this->bevel_color4 = (unsigned char)param_5;
    this->bevel_color5 = (unsigned char)param_6;
    this->bevel_color6 = (unsigned char)param_7;
}

int TTextPanel::get_text_rect(tagRECT* out_rect) {
    if (!out_rect || !this->render_area) return 0;
    const char* text = (this->list && this->list->text) ? this->list->text : nullptr;
    if (!text) return 0;

    HDC hdc = (HDC)this->render_area->GetDc((char*)"pnl_txt::get_text_rect");
    if (!hdc) return 0;

    HGDIOBJ old_font = nullptr;
    if (this->font) old_font = SelectObject(hdc, (HGDIOBJ)this->font);

    RECT r;
    r.left = 0;
    r.top = 0;
    r.right = this->pnl_wid;
    r.bottom = this->pnl_hgt;

    UINT flags = DT_NOPREFIX | DT_CALCRECT;
    if (this->word_wrap) flags |= DT_WORDBREAK;
    else flags |= DT_SINGLELINE;
    DrawTextA(hdc, text, -1, &r, flags);

    if (old_font) SelectObject(hdc, old_font);
    this->render_area->ReleaseDc((char*)"pnl_txt::get_text_rect");

    out_rect->left = r.left;
    out_rect->top = r.top;
    out_rect->right = r.right;
    out_rect->bottom = r.bottom;
    return 1;
}

