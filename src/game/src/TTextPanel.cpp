#include "../include/TTextPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TShape.h"
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
    const size_t len = strlen(s);
    char* out = (char*)calloc(1, len + 1);
    if (!out) return nullptr;
    memcpy(out, s, len);
    out[len] = '\0';
    return out;
}

static TTextPanel::TextNode* get_tail(TTextPanel* this_) {
    TTextPanel::TextNode* n = this_->list;
    if (!n) return nullptr;
    while (n->next) n = n->next;
    return n;
}

static int append_line(TTextPanel* this_, const char* text) {
    TTextPanel::TextNode* n = (TTextPanel::TextNode*)calloc(1, sizeof(TTextPanel::TextNode));
    if (!n) return 0;
    n->text = dup_cstr(text ? text : "");
    if (!n->text) {
        free(n);
        return 0;
    }
    n->next = nullptr;
    if (!this_->list) {
        this_->list = n;
    } else {
        TTextPanel::TextNode* tail = get_tail(this_);
        if (tail) tail->next = n;
    }
    this_->num_lines++;
    return 1;
}

static const char* get_line_text(const TTextPanel* this_, int index) {
    if (!this_ || index < 0) return nullptr;
    const TTextPanel::TextNode* n = this_->list;
    int i = 0;
    while (n && i < index) {
        n = n->next;
        i++;
    }
    return (n && n->text) ? n->text : nullptr;
}

static void calc_draw_info(TTextPanel* this_, int update_scrollbar) {
    (void)update_scrollbar;

    const int font_hgt = (int)this_->font_hgt;
    int line_hgt = font_hgt + 2;
    this_->text_hgt = line_hgt;

    if (font_hgt == 0) {
        this_->draw_lines = 1;
    } else {
        const int avail_h = (int)this_->pnl_hgt - (this_->border_size * 2);
        if (this_->spacer_size != 0) {
            line_hgt = font_hgt + 1 + (this_->spacer_size * 2);
        }
        if (line_hgt <= 0) line_hgt = 1;
        this_->draw_lines = (short)(avail_h / line_hgt);
    }

    if (this_->draw_lines < 1) this_->draw_lines = 1;

    const short num_lines = this_->num_lines;
    if (num_lines <= this_->top_line) this_->top_line = num_lines - 1;
    if ((int)num_lines - (int)this_->top_line < (int)this_->draw_lines) this_->top_line = num_lines - this_->draw_lines;
    if (this_->top_line < 0) this_->top_line = 0;

    this_->bot_line = this_->top_line + this_->draw_lines - 1;
    if (this_->bot_line < 0) this_->bot_line = 0;
    if (num_lines <= this_->bot_line) this_->bot_line = num_lines - 1;

    if (this_->cur_line < 0) this_->cur_line = 0;
    if (num_lines <= this_->cur_line) this_->cur_line = num_lines - 1;

    this_->text_wid = this_->pnl_wid;
}

static void calc_line_pos(TTextPanel* this_, HDC hdc, short draw_index, short line_index, tagRECT* line_rect, long* col_offset_out) {
    SIZE full_sz;
    SIZE col_sz;
    full_sz.cx = 0;
    full_sz.cy = 0;
    col_sz.cx = 0;
    col_sz.cy = 0;

    const char* text = get_line_text(this_, (int)line_index);
    if (text && text[0] != '\0') {
        const int text_len = (int)strlen(text);
        GetTextExtentPoint32A(hdc, text, text_len, &full_sz);
        if (this_->cur_col > 0) {
            int col_len = this_->cur_col;
            if (col_len > text_len) col_len = text_len;
            GetTextExtentPoint32A(hdc, text, col_len, &col_sz);
        }
    }

    const int text_width = full_sz.cx;
    int col_offset = col_sz.cx;
    int text_w_with_pad = text_width;
    if (this_->horz_align != TTextPanel::AlignCenter && this_->horz_align != TTextPanel::AlignWordwrap) {
        text_w_with_pad += 5;
    }

    int x = this_->pnl_x + this_->border_size;
    if (this_->horz_align == TTextPanel::AlignRight) {
        x = (((this_->pnl_x + this_->pnl_wid) - this_->border_size) - text_w_with_pad) - 7;
    } else if (this_->horz_align == TTextPanel::AlignHorizontalScroll) {
        x = this_->pnl_x + this_->border_size;
        if (this_->text_wid <= col_offset + 1) x += (this_->text_wid - col_offset) - 2;
    } else if (this_->horz_align == TTextPanel::AlignCenter || this_->horz_align == TTextPanel::AlignWordwrap) {
        x = (this_->pnl_x + (this_->pnl_wid / 2)) - (text_w_with_pad / 2);
    }
    x += col_offset;

    int y = this_->pnl_y + this_->border_size;
    int line_hgt = (this_->spacer_size == 0) ? (int)this_->text_hgt : (int)this_->text_hgt - 1 + this_->spacer_size * 2;
    if (line_hgt <= 0) line_hgt = 1;

    if (this_->vert_align == TTextPanel::AlignTop) {
        y = (int)this_->pnl_y + this_->border_size + ((int)draw_index * line_hgt) + this_->spacer_size;
    } else if (this_->vert_align == TTextPanel::AlignBottom) {
        y = (((this_->pnl_y + this_->pnl_hgt) - (((int)this_->num_lines - (int)draw_index) * line_hgt)) - this_->border_size) - this_->spacer_size - 1;
    } else {
        y = ((int)draw_index * line_hgt - ((int)this_->num_lines * line_hgt) / 2) + this_->pnl_y + (this_->pnl_hgt / 2) + this_->spacer_size;
    }

    line_rect->left = x;
    line_rect->top = y;
    line_rect->right = x + text_w_with_pad - 1;
    line_rect->bottom = y + this_->text_hgt;
    if (col_offset_out) *col_offset_out = col_offset;
}

static void draw_line(TTextPanel* this_, HDC hdc, short draw_index, short line_index, unsigned long color_main, unsigned long color_shadow) {
    const char* text = get_line_text(this_, (int)line_index);
    if (!text || text[0] == '\0') return;

    tagRECT line_rect;
    long col_offset = 0;
    calc_line_pos(this_, hdc, draw_index, line_index, &line_rect, &col_offset);

    int x = line_rect.left;
    if (this_->horz_align != TTextPanel::AlignCenter && this_->horz_align != TTextPanel::AlignWordwrap) {
        x += 5;
    }
    const int y = line_rect.top;
    const int text_len = (int)strlen(text);

    if (this_->text_style == TTextPanel::NormalStyle) {
        SetTextColor(hdc, (COLORREF)color_main);
        TextOutA(hdc, x, y, text, text_len);
        return;
    }

    if (this_->text_style == TTextPanel::BeveledStyle) {
        SetTextColor(hdc, (COLORREF)color_main);
        TextOutA(hdc, x - 1, y + 1, text, text_len);
        SetTextColor(hdc, (COLORREF)color_shadow);
        TextOutA(hdc, x, y, text, text_len);
        return;
    }

    if (this_->text_style == TTextPanel::ChiseledStyle) {
        SetTextColor(hdc, (COLORREF)color_shadow);
        TextOutA(hdc, x - 1, y + 1, text, text_len);
        SetTextColor(hdc, (COLORREF)color_main);
        TextOutA(hdc, x, y, text, text_len);
        return;
    }

    SetTextColor(hdc, (COLORREF)color_main);
    TextOutA(hdc, x, y, text, text_len);
}

static void draw_background(TTextPanel* this_) {
    if (!this_->render_area) return;

    if (this_->back_pic) {
        if (this_->render_area->Lock((char*)"pnl_txt::draw_background", 1)) {
            int cols = 1;
            int rows = 1;
            if (this_->back_pic_wid > 0) {
                cols = (int)this_->pnl_wid / (int)this_->back_pic_wid;
                if (cols * this_->back_pic_wid < this_->pnl_wid) cols++;
                if (cols < 1) cols = 1;
            }
            if (this_->back_pic_hgt > 0) {
                rows = (int)this_->pnl_hgt / (int)this_->back_pic_hgt;
                if (rows * this_->back_pic_hgt < this_->pnl_hgt) rows++;
                if (rows < 1) rows = 1;
            }
            for (int y = 0; y < rows; ++y) {
                for (int x = 0; x < cols; ++x) {
                    this_->back_pic->shape_draw(
                        this_->render_area,
                        this_->pnl_x + x * this_->back_pic_wid,
                        this_->pnl_y + y * this_->back_pic_hgt,
                        0, 0, 0, (uchar*)0);
                }
            }
            this_->render_area->Unlock((char*)"pnl_txt::draw_background");
        }
        return;
    }

    if (this_->fill_back) {
        if (this_->render_area->Lock((char*)"pnl_txt::draw_background2", 1)) {
            this_->render_area->FillRect(
                this_->pnl_x,
                this_->pnl_y,
                this_->pnl_x + this_->pnl_wid - 1,
                this_->pnl_y + this_->pnl_hgt - 1,
                this_->back_color);
            this_->render_area->Unlock((char*)"pnl_txt::draw_background2");
        }
        return;
    }

    if (this_->parent_panel) {
        if (this_->bevel_type > 1 && this_->bevel_type < 8) this_->parent_panel->draw_rect2(&this_->clip_rect);
        else if (this_->parent_panel->overlapping_children == 0) this_->parent_panel->draw_rect(&this_->clip_rect);
    }
}

static void draw_border(TTextPanel* this_) {
    if (!this_->render_area) return;
    if (this_->bevel_type == 0) return;
    if (!this_->render_area->Lock((char*)"pnl_txt::draw_border", 1)) return;

    const long x1 = this_->pnl_x;
    const long y1 = this_->pnl_y;
    const long x2 = this_->pnl_x + this_->pnl_wid - 1;
    const long y2 = this_->pnl_y + this_->pnl_hgt - 1;

    switch (this_->bevel_type) {
    case 1:
        this_->render_area->DrawRect(x1, y1, x2, y2, this_->outline_color);
        break;
    case 2:
        this_->render_area->DrawBevel(x1, y1, x2, y2, this_->bevel_color1, this_->bevel_color6);
        break;
    case 3:
        this_->render_area->DrawBevel2(x1, y1, x2, y2, this_->bevel_color1, this_->bevel_color2, this_->bevel_color5, this_->bevel_color6);
        break;
    case 4:
        this_->render_area->DrawBevel3(x1, y1, x2, y2, this_->bevel_color1, this_->bevel_color2, this_->bevel_color3, this_->bevel_color4, this_->bevel_color5, this_->bevel_color6);
        break;
    case 5:
        this_->render_area->DrawBevel(x1, y1, x2, y2, this_->bevel_color6, this_->bevel_color1);
        break;
    case 6:
        this_->render_area->DrawBevel2(x1, y1, x2, y2, this_->bevel_color6, this_->bevel_color5, this_->bevel_color2, this_->bevel_color1);
        break;
    case 7:
        this_->render_area->DrawBevel3(x1, y1, x2, y2, this_->bevel_color6, this_->bevel_color5, this_->bevel_color4, this_->bevel_color3, this_->bevel_color2, this_->bevel_color1);
        break;
    default:
        break;
    }

    this_->render_area->Unlock((char*)"pnl_txt::draw_border");
}

TTextPanel::TTextPanel() : TPanel(nullptr) {
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

    this->fill_back = fill_back;
    this->back_color = back_color;
    this->outline = outline;
    this->outline_color = outline_color;
    this->fixed_len = fixed_len;
    if (outline) this->bevel_type = 1;

    this->font = font;
    this->font_wid = font_wid;
    this->font_hgt = font_hgt;
    this->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
    this->set_text(initial_text);
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

void TTextPanel::set_rect(tagRECT param_1) {
    TPanel::set_rect(param_1);
    calc_draw_info(this, 1);
}

void TTextPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    TPanel::set_rect(param_1, param_2, param_3, param_4);
    calc_draw_info(this, 1);
}

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
    if (!this->render_area || !this->active || !this->visible) return;
    if (!this->list) return;

    draw_background(this);
    this->draw_setup(0);

    HDC hdc = (HDC)this->render_area->GetDc((char*)"pnl_txt::draw");
    if (hdc) {
        if (this->clip_rgn) SelectClipRgn(hdc, (HRGN)this->clip_rgn);
        HGDIOBJ old_font = this->font ? SelectObject(hdc, (HGDIOBJ)this->font) : nullptr;
        SetBkMode(hdc, TRANSPARENT);

        short draw_i = 0;
        for (short line_i = this->top_line; line_i <= this->bot_line; ++line_i) {
            unsigned long c_main = this->text_color1;
            unsigned long c_shadow = this->text_color2;
            if (this->have_focus) {
                c_main = this->highlightTextColor1;
                c_shadow = this->highlightTextColor2;
            }
            draw_line(this, hdc, draw_i, line_i, c_main, c_shadow);
            draw_i++;
        }

        if (old_font) SelectObject(hdc, old_font);
        SelectClipRgn(hdc, 0);
        this->render_area->ReleaseDc((char*)"pnl_txt::draw");
    }

    draw_border(this);
    this->draw_finish();
}

void TTextPanel::draw_rect(tagRECT* param_1) { TPanel::draw_rect(param_1); }
void TTextPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset(param_1, param_2, param_3); }
void TTextPanel::draw_rect2(tagRECT* param_1) { TPanel::draw_rect2(param_1); }
void TTextPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset2(param_1, param_2, param_3); }
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
    free_text_list(this);

    if (param_2 == 0) {
        if (this->fixed_len != 0) {
            append_line(this, "");
        }
    } else if (param_2 > 0 && param_1) {
        for (int i = 0; i < param_2; ++i) {
            append_line(this, param_1[i] ? param_1[i] : "");
        }
    }

    calc_draw_info(this, 1);
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TTextPanel::set_text(long param_1) {
    char str[4096];
    str[0] = '\0';
    this->get_string((int)param_1, str, sizeof(str));
    this->set_text(str);
}

void TTextPanel::set_text(char* param_1) {
    free_text_list(this);

    if (param_1 == nullptr || param_1[0] == '\0') {
        append_line(this, "");
        calc_draw_info(this, 1);
        this->set_redraw(TPanel::RedrawMode::Redraw);
        return;
    }

    if (this->word_wrap == 0 && this->horz_align != TTextPanel::AlignWordwrap) {
        const char* cur = param_1;
        while (cur && cur[0] != '\0') {
            const char* lf = strchr(cur, '\n');
            if (!lf) {
                append_line(this, cur);
                break;
            }

            size_t len = (size_t)(lf - cur);
            while (len > 0 && cur[len - 1] == '\r') len--;
            char* tmp = (char*)calloc(1, len + 1);
            if (!tmp) break;
            memcpy(tmp, cur, len);
            tmp[len] = '\0';
            append_line(this, tmp);
            free(tmp);
            cur = lf + 1;
        }
    } else {
        // TODO: proper word-wrap behavior (`Pnl_txt.cpp.decomp`: `word_wrap_append`).
        append_line(this, param_1);
    }

    if (this->num_lines == 0) append_line(this, "");
    calc_draw_info(this, 1);
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

    switch (param_1) {
    case 1:
    case 2:
    case 5:
        this->border_size = 1;
        break;
    case 3:
    case 6:
        this->border_size = 2;
        break;
    case 4:
    case 7:
        this->border_size = 3;
        break;
    default:
        this->border_size = 0;
        break;
    }

    calc_draw_info(this, 1);
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

int TTextPanel::get_text_rect(tagRECT* out_rect) {
    // Source of truth: `src/game/src/Pnl_txt.cpp.decomp` (`get_text_rect`).
    // It selects this->font, then delegates to `calc_line_pos(this, hdc, 0, 0, out_rect, 0)`.
    if (!out_rect || !this->render_area) return 0;

    HDC hdc = (HDC)this->render_area->GetDc((char*)"pnl_txt::get_text_rect");
    if (!hdc) return 0;

    HGDIOBJ old_font = SelectObject(hdc, (HGDIOBJ)this->font);
    calc_line_pos(this, hdc, 0, 0, out_rect, (long*)0);
    SelectObject(hdc, old_font);
    this->render_area->ReleaseDc((char*)"pnl_txt::get_text_rect");
    return 1;
}
