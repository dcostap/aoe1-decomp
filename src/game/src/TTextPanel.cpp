#include "../include/TTextPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TShape.h"
#include "../include/TScrollBarPanel.h"
#include "../include/custom_debug.h"
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <mbstring.h>
#include <mbctype.h>

static void calc_draw_info(TTextPanel* this_, int update_scrollbar);

static void free_text_list(TTextPanel* this_) {
    if (!this_) return;
    TTextPanel::TextNode* node = this_->list;
    while (node) {
        TTextPanel::TextNode* next = node->next;
        if (node->text) free(node->text);
        if (node->text2) free(node->text2);
        free(node);
        node = next;
    }
    this_->list = nullptr;
    this_->num_lines = 0;
    calc_draw_info(this_, 1);
    this_->set_redraw(TPanel::RedrawMode::Redraw);
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

static TTextPanel::TextNode* get_line_node(TTextPanel* this_, int index) {
    if (!this_ || index < 0) {
        return nullptr;
    }

    TTextPanel::TextNode* n = this_->list;
    int i = 0;
    while (n && i < index) {
        n = n->next;
        ++i;
    }
    return n;
}

static TTextPanel::TextNode* get_tail(TTextPanel* this_) {
    TTextPanel::TextNode* n = this_->list;
    if (!n) return nullptr;
    while (n->next) n = n->next;
    return n;
}

static int append_text_line(TTextPanel* this_, const char* text, long id) {
    TTextPanel::TextNode* n = (TTextPanel::TextNode*)calloc(1, sizeof(TTextPanel::TextNode));
    if (!n) return 0;
    n->text = dup_cstr(text ? text : "");
    if (!n->text) {
        free(n);
        return 0;
    }
    n->id = id;
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

static const char* get_line_text2(const TTextPanel* this_, int index) {
    if (!this_ || index < 0) return nullptr;
    const TTextPanel::TextNode* n = this_->list;
    int i = 0;
    while (n && i < index) {
        n = n->next;
        i++;
    }
    return (n && n->text2) ? n->text2 : nullptr;
}

static void update_second_column_clip(TTextPanel* this_) {
    if (!this_) {
        return;
    }

    if (this_->clip_rgn2) {
        DeleteObject((HGDIOBJ)this_->clip_rgn2);
        this_->clip_rgn2 = nullptr;
    }

    if (this_->second_column_pos == 0 || this_->pnl_wid <= 0 || this_->pnl_hgt <= 0) {
        return;
    }

    long left = this_->pnl_x;
    long top = this_->pnl_y;
    long right = this_->pnl_x + this_->second_column_pos - 10;
    long max_right = this_->pnl_x + this_->pnl_wid;
    if (right > max_right) {
        right = max_right;
    }
    if (right < left) {
        right = left;
    }

    long bottom = this_->pnl_y + this_->pnl_hgt;
    this_->clip_rgn2 = (void*)CreateRectRgn((int)left, (int)top, (int)right, (int)bottom);
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

    if (this_->scbar_panel) {
        if (update_scrollbar) {
            this_->scbar_panel->set_list_len(((int)this_->num_lines - (int)this_->draw_lines) + 1, (int)this_->top_line);
        }

        if (this_->auto_scbar) {
            if (this_->draw_lines < this_->num_lines) {
                if (this_->scbar_active == 0) {
                    // NOTE: The original explicitly calls TPanel::set_rect here (non-virtual) to avoid recursion.
                    this_->TPanel::set_rect(this_->pnl_x, this_->pnl_y, this_->full_width - this_->scbar_width, this_->pnl_hgt);
                    this_->scbar_active = 1;
                    if (this_->active) {
                        this_->scbar_panel->set_active(1);
                        this_->text_wid = this_->pnl_wid;
                        return;
                    }
                }
            } else if (this_->scbar_active != 0) {
                this_->TPanel::set_rect(this_->pnl_x, this_->pnl_y, this_->full_width, this_->pnl_hgt);
                this_->scbar_active = 0;
                if (this_->active) {
                    this_->scbar_panel->set_active(0);
                }
            }
        }
    }

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
            const int mbs_len = (int)_mbslen((const unsigned char*)text);
            if (mbs_len < this_->cur_col) {
                col_sz = full_sz;
            } else {
                unsigned char temp_text2[256];
                memset(temp_text2, 0, sizeof(temp_text2));
                _mbsncpy(temp_text2 + 4, (const unsigned char*)text, (size_t)this_->cur_col);
                const int col_bytes = (int)strlen((const char*)(temp_text2 + 4));
                if (col_bytes > 0) {
                    // Truth uses the original string pointer with a substring byte length.
                    GetTextExtentPoint32A(hdc, text, col_bytes, &col_sz);
                }
            }
        }
    }

    const int text_width = full_sz.cx;
    const int col_offset = col_sz.cx;
    int col_offset_for_scroll = col_offset;
    if (this_->horz_align != TTextPanel::AlignCenter && this_->horz_align != TTextPanel::AlignWordwrap) {
        // Truth adds 5 to the scroll comparison value for non-center/non-wordwrap modes.
        col_offset_for_scroll += 5;
    }

    int x = this_->pnl_x + this_->border_size;
    if (this_->horz_align == TTextPanel::AlignRight) {
        x = (((this_->pnl_x + this_->pnl_wid) - this_->border_size) - text_width) - 7;
    } else if (this_->horz_align == TTextPanel::AlignHorizontalScroll) {
        x = this_->pnl_x + this_->border_size;
        if (this_->text_wid <= col_offset_for_scroll + 1) x += (this_->text_wid - col_offset_for_scroll) - 2;
    } else if (this_->horz_align == TTextPanel::AlignCenter || this_->horz_align == TTextPanel::AlignWordwrap) {
        x = (this_->pnl_x + (this_->pnl_wid / 2)) - (text_width / 2);
    }

    int y = this_->pnl_y + this_->border_size;
    int line_hgt = (this_->spacer_size == 0) ? (int)this_->text_hgt : (int)this_->text_hgt - 1 + this_->spacer_size * 2;
    if (line_hgt <= 0) line_hgt = 1;

    if (this_->vert_align == TTextPanel::AlignTop) {
        y = (int)this_->pnl_y + this_->border_size + ((int)draw_index * line_hgt) + this_->spacer_size;
    } else if (this_->vert_align == TTextPanel::AlignBottom) {
        y = (((this_->pnl_y + this_->pnl_hgt) - (((int)this_->num_lines - (int)draw_index) * line_hgt)) - this_->border_size) - this_->spacer_size - 1;
    } else {
        // NOTE: Matches pnl_txt.cpp.asm: center-vertical does not apply spacer_size as an additional offset.
        y = ((int)draw_index * line_hgt - ((int)this_->num_lines * line_hgt) / 2) + this_->pnl_y + (this_->pnl_hgt / 2);
    }

    line_rect->left = x;
    line_rect->top = y;
    line_rect->right = x + text_width - 1;
    line_rect->bottom = y + this_->text_hgt;
    if (col_offset_out) *col_offset_out = col_offset;
}

static void draw_line(TTextPanel* this_, HDC hdc, short draw_index, short line_index, unsigned long color_main, unsigned long color_shadow) {
    const char* text = get_line_text(this_, (int)line_index);
    const char* text2 = get_line_text2(this_, (int)line_index);
    if ((text == nullptr || text[0] == '\0') && (text2 == nullptr || text2[0] == '\0')) return;

    tagRECT line_rect;
    long col_offset = 0;
    calc_line_pos(this_, hdc, draw_index, line_index, &line_rect, &col_offset);

    int x = line_rect.left;
    if (this_->horz_align != TTextPanel::AlignCenter && this_->horz_align != TTextPanel::AlignWordwrap) {
        x += 5;
    }
    const int x2 = x + (int)this_->second_column_pos;
    const int y = line_rect.top;
    const int text_len = (text != nullptr) ? (int)strlen(text) : 0;
    const int text2_len = (text2 != nullptr) ? (int)strlen(text2) : 0;

    if (this_->clip_rgn2 != nullptr) {
        SelectClipRgn(hdc, (HRGN)this_->clip_rgn2);
    }

    if (this_->text_style == TTextPanel::NormalStyle) {
        SetTextColor(hdc, (COLORREF)color_main);
        if (text != nullptr) {
            TextOutA(hdc, x, y, text, text_len);
        }
    } else if (this_->text_style == TTextPanel::BeveledStyle) {
        SetTextColor(hdc, (COLORREF)color_main);
        if (text != nullptr) {
            TextOutA(hdc, x - 1, y + 1, text, text_len);
        }
        SetTextColor(hdc, (COLORREF)color_shadow);
        if (text != nullptr) {
            TextOutA(hdc, x, y, text, text_len);
        }
    } else if (this_->text_style == TTextPanel::ChiseledStyle) {
        SetTextColor(hdc, (COLORREF)color_shadow);
        if (text != nullptr) {
            TextOutA(hdc, x - 1, y + 1, text, text_len);
        }
        SetTextColor(hdc, (COLORREF)color_main);
        if (text != nullptr) {
            TextOutA(hdc, x, y, text, text_len);
        }
    } else {
        SetTextColor(hdc, (COLORREF)color_main);
        if (text != nullptr) {
            TextOutA(hdc, x, y, text, text_len);
        }
    }

    if (text2 != nullptr) {
        if (this_->clip_rgn2 != nullptr) {
            SelectClipRgn(hdc, (HRGN)this_->clip_rgn);
        }

        if (this_->text_style == TTextPanel::NormalStyle) {
            SetTextColor(hdc, (COLORREF)color_main);
            TextOutA(hdc, x2, y, text2, text2_len);
        } else if (this_->text_style == TTextPanel::BeveledStyle) {
            SetTextColor(hdc, (COLORREF)color_main);
            TextOutA(hdc, x2 - 1, y + 1, text2, text2_len);
            SetTextColor(hdc, (COLORREF)color_shadow);
            TextOutA(hdc, x2, y, text2, text2_len);
        } else if (this_->text_style == TTextPanel::ChiseledStyle) {
            SetTextColor(hdc, (COLORREF)color_shadow);
            TextOutA(hdc, x2 - 1, y + 1, text2, text2_len);
            SetTextColor(hdc, (COLORREF)color_main);
            TextOutA(hdc, x2, y, text2, text2_len);
        } else {
            SetTextColor(hdc, (COLORREF)color_main);
            TextOutA(hdc, x2, y, text2, text2_len);
        }
    }
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
                        0, 0, (uchar*)0);
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
    if (!TPanel::setup(area, parent, x, y, w, h, 0)) {
        return 0;
    }

    this->fill_back = fill_back;
    this->back_color = back_color;
    this->outline = outline;
    this->outline_color = outline_color;
    this->fixed_len = fixed_len;
    if (outline) this->bevel_type = 1;

    this->set_text(initial_text);
    this->set_font(font, font_wid, font_hgt);
    this->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
    this->set_back_pic(back_pic_name);
    return 1;
}

long TTextPanel::setup(TDrawArea* area, TPanel* parent, long x, long y, long w, long h, void* font, long font_wid, long font_hgt, char* back_pic_name, int fill_back, uchar back_color, int outline, uchar outline_color, short fixed_len, long text_resid) {
    if (!TPanel::setup(area, parent, x, y, w, h, 0)) {
        return 0;
    }

    this->fill_back = fill_back;
    this->back_color = back_color;
    this->outline = outline;
    this->outline_color = outline_color;
    this->fixed_len = fixed_len;
    if (outline) this->bevel_type = 1;

    this->set_font(font, font_wid, font_hgt);
    this->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
    this->set_back_pic(back_pic_name);

    char str[4096];
    str[0] = '\0';
    this->get_string((int)text_resid, str, sizeof(str));
    this->set_text(str);
    return 1;
}

long TTextPanel::setup(TDrawArea* area, TPanel* parent, long x, long y, long w, long h, void* font, long font_wid, long font_hgt, char* back_pic_name, int fill_back, uchar back_color, int outline, uchar outline_color, short fixed_len, char** text_list, short text_count) {
    if (!TPanel::setup(area, parent, x, y, w, h, 0)) {
        return 0;
    }

    this->fill_back = fill_back;
    this->back_color = back_color;
    this->outline = outline;
    this->outline_color = outline_color;
    this->fixed_len = fixed_len;
    if (outline) this->bevel_type = 1;

    this->set_text(text_list, text_count);
    this->set_font(font, font_wid, font_hgt);
    this->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignLeft);
    this->set_back_pic(back_pic_name);
    return 1;
}

void TTextPanel::set_font(void* font, long font_wid, long font_hgt) {
    this->font = font;
    this->font_wid = font_wid;
    this->font_hgt = font_hgt;
    calc_draw_info(this, 1);
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TTextPanel::set_fill_back(int fill_back, uchar back_color) {
    this->fill_back = fill_back;
    this->back_color = back_color;
}

void TTextPanel::set_back_pic(char* back_pic_name) {
    if (this->back_pic) {
        delete this->back_pic;
        this->back_pic = nullptr;
        this->back_pic_wid = 0;
        this->back_pic_hgt = 0;
    }

    if (back_pic_name && back_pic_name[0] != '\0') {
        this->back_pic = new TShape(back_pic_name, -1);
        if (this->back_pic) {
            long x_min = 0;
            long y_min = 0;
            long x_max = 0;
            long y_max = 0;
            this->back_pic->shape_minmax(&x_min, &y_min, &x_max, &y_max, 0);
            this->back_pic_wid = (short)((x_max - x_min) + 1);
            this->back_pic_hgt = (short)((y_max - y_min) + 1);
        }
    }
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

void TTextPanel::set_spacer_size(int size) {
    // Fully verified. Source of truth: pnl_txt.cpp.decomp @ 0x0047CE00
    this->spacer_size = size;
    calc_draw_info(this, 1);
}

void TTextPanel::set_rect(tagRECT param_1) {
    TPanel::set_rect(param_1);
    this->full_width = this->pnl_wid;

    if (this->auto_scbar && this->scbar_panel) {
        this->scbar_panel->set_active(0);
        this->scbar_active = 0;

        int rel_x = (int)this->pnl_x;
        int rel_y = (int)this->pnl_y;
        if (this->parent_panel) {
            rel_x -= (int)this->parent_panel->xPosition();
            rel_y -= (int)this->parent_panel->yPosition();
        }

        this->scbar_panel->set_fixed_position((rel_x + this->full_width) - this->scbar_width, rel_y, this->scbar_width, this->pnl_hgt);
    }

    calc_draw_info(this, 1);
    update_second_column_clip(this);
}

void TTextPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    TPanel::set_rect(param_1, param_2, param_3, param_4);
    this->full_width = this->pnl_wid;

    if (this->auto_scbar && this->scbar_panel) {
        this->scbar_panel->set_active(0);
        this->scbar_active = 0;

        int rel_x = (int)this->pnl_x;
        int rel_y = (int)this->pnl_y;
        if (this->parent_panel) {
            rel_x -= (int)this->parent_panel->xPosition();
            rel_y -= (int)this->parent_panel->yPosition();
        }

        this->scbar_panel->set_fixed_position((rel_x + this->full_width) - this->scbar_width, rel_y, this->scbar_width, this->pnl_hgt);
    }

    calc_draw_info(this, 1);
    update_second_column_clip(this);
}

void TTextPanel::set_color(uchar param_1) { TPanel::set_color(param_1); }
void TTextPanel::set_active(int param_1) {
    TPanel::set_active(param_1);
    if (this->auto_scbar != 0 && this->scbar_panel) {
        if (this->active != 0) {
            this->scbar_panel->set_active(this->scbar_active);
        } else {
            this->scbar_panel->set_active(0);
        }
    }
}
void TTextPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void TTextPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TTextPanel::set_redraw(RedrawMode param_1) { TPanel::set_redraw(param_1); }
void TTextPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TTextPanel::draw_setup(int param_1) { TPanel::draw_setup(param_1); }
void TTextPanel::draw_finish() { TPanel::draw_finish(); }

void TTextPanel::draw() {
    if (!this->render_area || !this->active || !this->visible) return;

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
            if ((this->tab_stop && this->have_focus) || this->mouse_captured) {
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
void TTextPanel::paint() { TPanel::paint(); }
long TTextPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TTextPanel::handle_idle() { return TPanel::handle_idle(); }
long TTextPanel::handle_size(long param_1, long param_2) { return TPanel::handle_size(param_1, param_2); }
long TTextPanel::handle_paint() { return TPanel::handle_paint(); }
long TTextPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TTextPanel::handle_char(long param_1, short param_2) { return TPanel::handle_char(param_1, param_2); }
long TTextPanel::handle_command(uint param_1, long param_2) { return TPanel::handle_command(param_1, param_2); }
long TTextPanel::handle_user_command(uint param_1, long param_2) { return TPanel::handle_user_command(param_1, param_2); }
long TTextPanel::handle_timer_command(uint param_1, long param_2) { return TPanel::handle_timer_command(param_1, param_2); }
long TTextPanel::handle_scroll(long param_1, long param_2) { return TPanel::handle_scroll(param_1, param_2); }
long TTextPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TTextPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TTextPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TTextPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TTextPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4;
    if (this->parent_panel) {
        this->parent_panel->action(this, 1, 0, 0);
    }
    return 0;
}
long TTextPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { (void)param_1; (void)param_2; (void)param_3; (void)param_4; return 0; }
long TTextPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    uchar scroll_cmd = 0;
    switch (param_1) {
    case VK_PRIOR:
        scroll_cmd = 5;
        break;
    case VK_NEXT:
        scroll_cmd = 4;
        break;
    case VK_END:
        this->scroll(7, 0, 1);
        return 1;
    case VK_HOME:
        this->scroll(6, 0, 1);
        return 1;
    case VK_UP:
        scroll_cmd = 3;
        break;
    case VK_DOWN:
        scroll_cmd = 2;
        break;
    default:
        return 0;
    }

    this->scroll(scroll_cmd, 0, 1);
    if (this->parent_panel && this->parent_panel->active) {
        this->parent_panel->key_down_action(param_1, param_2, param_3, param_4, param_5);
    }
    return 1;
}
long TTextPanel::char_action(long param_1, short param_2) { (void)param_1; (void)param_2; return 0; }
long TTextPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    (void)param_4;
    if (this->scbar_panel && param_1 == this->scbar_panel) {
        switch (param_2) {
        case 0:
            this->scroll(3, 0, 1);
            return 1;
        case 1:
            this->scroll(2, 0, 1);
            return 1;
        case 2:
            this->scroll(5, 0, 1);
            return 1;
        case 3:
            this->scroll(4, 0, 1);
            return 1;
        case 4:
            this->scroll(1, (short)param_3, 0);
            return 1;
        default:
            break;
        }
    }
    return TPanel::action(param_1, param_2, param_3, param_4);
}
void TTextPanel::get_true_render_rect(tagRECT* param_1) { (void)param_1; }
int TTextPanel::is_inside(long param_1, long param_2) { return TPanel::is_inside(param_1, param_2); }
void TTextPanel::set_focus(int param_1) { TPanel::set_focus(param_1); }
void TTextPanel::set_tab_order(TPanel* param_1, TPanel* param_2) { TPanel::set_tab_order(param_1, param_2); }
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
            this->append_line((char*)"", 0);
        }
    } else if (param_2 > 0 && param_1) {
        for (int i = 0; i < param_2; ++i) {
            this->append_line(param_1[i] ? param_1[i] : (char*)"", 0);
        }
    }
}

void TTextPanel::set_text(long param_1) {
    char str[4096];
    str[0] = '\0';
    this->get_string((int)param_1, str, sizeof(str));
    this->set_text(str);
}

void TTextPanel::set_text(char* param_1) {
    free_text_list(this);

    if (param_1 == nullptr) {
        if (this->fixed_len != 0) {
            this->append_line((char*)"", 0);
        }
        return;
    }
    if (param_1[0] == '\0') {
        this->append_line((char*)"", 0);
        return;
    }

    if (this->word_wrap == 0 && this->horz_align != TTextPanel::AlignWordwrap) {
        unsigned char temp_text[256];
        unsigned char* cur = (unsigned char*)param_1;
        while (true) {
            unsigned char* lf = (unsigned char*)_mbschr(cur, '\n');
            if (lf == nullptr) break;

            short copy_len = (short)(lf - cur);
            strncpy((char*)(temp_text + 4), (char*)cur, (int)copy_len);
            temp_text[(int)copy_len + 4] = '\0';
            this->append_line((char*)(temp_text + 4), 0);

            cur = lf + 1;
        }
        this->append_line((char*)cur, 0);
    } else {
        this->word_wrap_append(param_1);
    }
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

// List management methods (needed for TDropDownPanel / TListPanel)
void TTextPanel::empty_list() {
    free_text_list(this);
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

int TTextPanel::append_line(char* text, long id) {
    return this->insert_line((long)this->num_lines, text, id);
}

int TTextPanel::append_line(long str_id, long id) {
    char str[256];
    str[0] = '\0';
    this->get_string((int)str_id, str, sizeof(str));
    return append_line(str, id);
}

int TTextPanel::insert_line(long line_num, char* text, long id) {
    return this->insert_line(line_num, text, (char*)0, id);
}

int TTextPanel::insert_line(long line_num, char* text, char* text2, long id) {
    TTextPanel::TextNode* node = (TTextPanel::TextNode*)calloc(1, sizeof(TTextPanel::TextNode));
    if (node == nullptr) {
        return 0;
    }

    size_t text_bytes = 1;
    if (this->fixed_len == 0) {
        if (text != nullptr) {
            text_bytes = strlen(text) + 1;
        }
    } else {
        text_bytes = (size_t)this->fixed_len + 1;
    }

    node->text = (char*)calloc(text_bytes, 1);
    if (node->text == nullptr) {
        free(node);
        return 0;
    }

    if (text2 != nullptr) {
        node->text2 = (char*)calloc(strlen(text2) + 1, 1);
        if (node->text2 == nullptr) {
            free(node->text);
            free(node);
            return 0;
        }
    }

    if (text == nullptr) {
        node->text[0] = '\0';
    } else if (this->fixed_len == 0) {
        memcpy(node->text, text, strlen(text) + 1);
    } else {
        strncpy(node->text, text, this->fixed_len);
        node->text[this->fixed_len] = '\0';
    }

    if (text2 != nullptr) {
        memcpy(node->text2, text2, strlen(text2) + 1);
    }

    node->id = id;
    node->next = nullptr;

    if (this->list == nullptr) {
        this->list = node;
    } else if (this->sorted == 0) {
        if (line_num <= 0) {
            node->next = this->list;
            this->list = node;
        } else if (line_num < this->num_lines) {
            TTextPanel::TextNode* prev = this->list;
            for (int i = 0; i != (int)line_num - 1 && prev->next != nullptr; ++i) {
                prev = prev->next;
            }
            node->next = prev->next;
            prev->next = node;
        } else {
            TTextPanel::TextNode* tail = this->list;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = node;
        }
    } else {
        TTextPanel::TextNode* prev = nullptr;
        TTextPanel::TextNode* curr = this->list;
        while (curr != nullptr) {
            int cmp = CompareStringA(LOCALE_USER_DEFAULT, NORM_IGNORECASE, node->text, -1, curr->text, -1);
            if (cmp == 1) {
                node->next = curr;
                if (prev == nullptr) {
                    this->list = node;
                } else {
                    prev->next = node;
                }
                break;
            }

            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr && prev != nullptr) {
            prev->next = node;
        }
    }

    this->num_lines = (short)(this->num_lines + 1);
    calc_draw_info(this, 1);
    this->set_redraw(TPanel::RedrawMode::Redraw);
    return 1;
}

int TTextPanel::insert_line(long line_num, long str_id, long id) {
    char str[256];
    str[0] = '\0';
    this->get_string((int)str_id, str, sizeof(str));
    return this->insert_line(line_num, str, id);
}

int TTextPanel::insert_line(long line_num, long str1_id, long str2_id, long id) {
    char str1[256];
    char str2[256];
    str1[0] = '\0';
    str2[0] = '\0';
    this->get_string((int)str1_id, str1, sizeof(str1));
    this->get_string((int)str2_id, str2, sizeof(str2));
    return this->insert_line(line_num, str1, str2, id);
}

int TTextPanel::change_line(long line_num, char* text, char* text2, long id) {
    int sorted_prev = this->sorted;
    this->sorted = 0;
    int inserted = this->insert_line(line_num, text, text2, id);
    if (inserted == 0) {
        this->sorted = sorted_prev;
        return 0;
    }
    this->delete_line(line_num + 1);
    this->sorted = sorted_prev;
    return 1;
}

int TTextPanel::change_line(long line_num, long str1_id, long str2_id, long id) {
    int sorted_prev = this->sorted;
    this->sorted = 0;
    int inserted = this->insert_line(line_num, str1_id, str2_id, id);
    if (inserted == 0) {
        this->sorted = sorted_prev;
        return 0;
    }
    this->delete_line(line_num + 1);
    this->sorted = sorted_prev;
    return 1;
}

int TTextPanel::delete_line(long line_num) {
    if (line_num < 0 || line_num > (long)this->num_lines - 1) {
        return 0;
    }

    TTextPanel::TextNode* victim = nullptr;
    if (line_num == 0) {
        victim = this->list;
        if (victim != nullptr) {
            this->list = victim->next;
        }
    } else {
        TTextPanel::TextNode* prev = this->list;
        for (int i = 0; i != (int)line_num - 1 && prev != nullptr; ++i) {
            prev = prev->next;
        }
        if (prev != nullptr) {
            victim = prev->next;
            if (victim != nullptr) {
                prev->next = victim->next;
            }
        }
    }

    if (victim == nullptr) {
        return 0;
    }

    if (victim->text != nullptr) {
        free(victim->text);
    }
    if (victim->text2 != nullptr) {
        free(victim->text2);
    }
    free(victim);

    this->num_lines = (short)(this->num_lines - 1);
    if (this->num_lines == 0) {
        this->cur_line = 0;
    } else if (this->num_lines <= this->cur_line) {
        this->cur_line = (short)(this->num_lines - 1);
    }

    calc_draw_info(this, 1);
    this->set_redraw(TPanel::RedrawMode::Redraw);
    return 1;
}

void TTextPanel::set_line(long line_num) {
    // Source of truth: `Pnl_txt.cpp.decomp` (`TTextPanel::set_line`).
    this->cur_line = (short)line_num;
    calc_draw_info(this, 1);
}

long TTextPanel::get_line() {
    if (this->num_lines == 0) {
        return -1;
    }
    return this->cur_line;
}

long TTextPanel::get_line(long line_num) {
    // Source of truth: Pnl_txt.cpp.decomp
    // Returns line index for a given line id; returns -1 when no match.
    int i = 0;
    for (TTextPanel::TextNode* n = this->list; n; n = n->next, ++i) {
        if (n->id == line_num) {
            return i;
        }
    }
    return -1;
}

long TTextPanel::get_line(char* text) {
    int i = 0;
    for (TTextPanel::TextNode* n = this->list; n != nullptr; n = n->next, ++i) {
        if (n->text == nullptr || text == nullptr) {
            continue;
        }
        if (strcmp(n->text, text) == 0) {
            return i;
        }
    }
    return -1;
}

long TTextPanel::get_id() {
    return this->get_id((long)this->cur_line);
}

long TTextPanel::get_id(long line_num) {
    if (!this->list) {
        return -1;
    }
    TTextPanel::TextNode* n = get_line_node(this, (int)line_num);
    if (!n) {
        return -1;
    }
    return n->id;
}

char* TTextPanel::get_text(long line_num) {
    const char* text = get_line_text(this, (int)line_num);
    return (char*)text;
}

char* TTextPanel::get_text2(long line_num) {
    const char* text = get_line_text2(this, (int)line_num);
    return (char*)text;
}

void TTextPanel::set_second_column_pos(long pos) {
    this->second_column_pos = pos;
    update_second_column_clip(this);
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

// From decomp at 0x0047CCF0
void TTextPanel::set_outline(int param_1, uchar param_2) {
    this->outline = param_1;
    if (param_1) {
        this->outline_color = param_2;
    }
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

// From decomp at 0x0047C4D0
void TTextPanel::set_scrollbar(TScrollBarPanel* param_1, int param_2) {
    this->scbar_panel = param_1;
    this->auto_scbar = param_2;
    if (param_1) {
        this->scbar_width = param_1->width();
        this->set_rect(this->pnl_x, this->pnl_y, this->pnl_wid, this->pnl_hgt);
    }
}

// From decomp at 0x0047C520
TTextPanel::CharType TTextPanel::char_type(unsigned char* param_1) {
    if (param_1 != nullptr && *param_1 != '\0') {
        if (IsDBCSLeadByte(*param_1) != 0) {
            return TTextPanel::DoubleByteChar;
        }
        if (*param_1 > 0xA0 && *param_1 < 0xE0) {
            return TTextPanel::SingleByteKanaChar;
        }
    }
    return TTextPanel::SingleByteChar;
}

// From asm/decomp at 0x0047C640
int TTextPanel::word_wrap_append(char* param_1) {
    if (param_1 == nullptr || *param_1 == '\0') {
        return 1;
    }

    long max_wid = 0;
    if (this->auto_scbar == 0) {
        max_wid = this->pnl_wid;
    } else {
        max_wid = this->full_width - this->scbar_width;
    }
    max_wid = max_wid - 10;

    HDC dc = (HDC)this->render_area->GetDc((char*)"pnl_txt::word_wrap_append");
    if (!dc) {
        return 0;
    }

    HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);
    TEXTMETRICA tm;
    GetTextMetricsA(dc, &tm);
    int japanese = (tm.tmCharSet == SHIFTJIS_CHARSET);

    unsigned char* cur = (unsigned char*)param_1;
    while (cur != nullptr && *cur != '\0') {
        int found_break = 0;
        int found_return = 0;
        int found_space = 0;
        int found_linefeed = 0;
        int found_bad_return = 0;

        const int mbs_len = (int)_mbslen(cur);
        int break_chars = 0;

        // Scan for a newline before we exceed the max width.
        if (*cur == '\n') {
            found_linefeed = 1;
            break_chars = 0;
        } else {
            for (int i = 1; i <= mbs_len; ++i) {
                unsigned char* end = _mbsninc(cur, i);
                if (!end) break;

                // Detect newline (and CRLF) within the measured prefix.
                unsigned char* p = _mbsninc(cur, i - 1);
                if (p && *p == '\n') {
                    found_linefeed = 1;
                    break_chars = i - 1;
                    if (break_chars > 0) {
                        unsigned char* prev = _mbsdec(cur, p);
                        if (prev && *prev == '\r') {
                            found_return = 1;
                            break_chars = break_chars - 1;
                        }
                    }
                    break;
                }
                if (p && *p == '\r') {
                    found_bad_return = 1;
                }

                SIZE sz;
                GetTextExtentPoint32A(dc, (char*)cur, (int)(end - cur), &sz);
                if (sz.cx >= max_wid) {
                    break;
                }
            }
        }

        if (!found_linefeed) {
            SIZE full_sz;
            GetTextExtentPoint32A(dc, (char*)cur, (int)strlen((char*)cur), &full_sz);
            if (full_sz.cx <= max_wid) {
                this->append_line((char*)cur, 0);
                break;
            }

            // Determine the first char count that exceeds max_wid; keep a fallback break point.
            int fallback_break_chars = 1;
            for (int i = 1; i <= mbs_len; ++i) {
                unsigned char* end = _mbsninc(cur, i);
                if (!end) break;
                SIZE sz;
                GetTextExtentPoint32A(dc, (char*)cur, (int)(end - cur), &sz);
                if (sz.cx > max_wid) {
                    break_chars = i;
                    break;
                }
                fallback_break_chars = i - 1;
            }
            if (break_chars == 0) {
                break_chars = 1;
            }

            // Walk backward to find a break position (space, or Japanese type transition).
            unsigned char* next_char = _mbsninc(cur, break_chars);
            int scan_chars = break_chars;
            while (scan_chars >= 2 && next_char != nullptr) {
                unsigned char* old_next = next_char;
                unsigned char* last_char = _mbsdec(cur, old_next);
                if (!last_char) break;
                scan_chars = scan_chars - 1;

                if (!japanese) {
                    if (_ismbcspace(*last_char) != 0) {
                        found_space = 1;
                        break;
                    }
                } else {
                    const CharType t1 = this->char_type(last_char);
                    const CharType t2 = this->char_type(old_next);

                    if (t1 == SingleByteChar && t2 == SingleByteChar && _ismbcspace(*last_char) != 0) {
                        found_space = 1;
                        break;
                    }

                    if ((t1 == DoubleByteChar && t2 == DoubleByteChar) ||
                        (t1 == SingleByteKanaChar && t2 == SingleByteKanaChar) ||
                        (t1 == SingleByteChar && t2 == DoubleByteChar) ||
                        (t1 == DoubleByteChar && t2 == SingleByteChar) ||
                        (t1 == SingleByteChar && t2 == SingleByteKanaChar) ||
                        (t1 == SingleByteKanaChar && t2 == SingleByteChar)) {
                        found_break = 1;
                        break;
                    }
                }

                next_char = last_char;
            }

            if (found_space == 0 && found_break == 0) {
                found_break = 1;
                scan_chars = fallback_break_chars;
                if (scan_chars < 1) {
                    scan_chars = 1;
                }
            }

            break_chars = scan_chars;
        }

        unsigned char temp_text[256];
        memset(temp_text, 0, sizeof(temp_text));
        _mbsncpy(temp_text + 4, cur, (size_t)break_chars);
        if (found_return) {
            _mbscat(temp_text + 4, (unsigned char*)" ");
        }
        if (found_linefeed) {
            _mbscat(temp_text + 4, (unsigned char*)" ");
        }

        if (found_bad_return) {
            unsigned char* p = temp_text + 4;
            while (*p != '\0') {
                if (*p == '\r') {
                    *p = ' ';
                }
                p = _mbsinc(p);
            }
        }

        this->append_line((char*)(temp_text + 4), 0);

        cur = _mbsninc(cur, (size_t)break_chars);
        if (found_return) {
            cur = _mbsinc(cur);
        }
        if (found_linefeed) {
            cur = _mbsinc(cur);
        }
    }

    SelectObject(dc, old_font);
    this->render_area->ReleaseDc((char*)"pnl_txt::word_wrap_append");
    return 1;
}

// From decomp at 0x0047DC30
int TTextPanel::numberLines() {
    return (int)this->num_lines;
}

// From decomp at 0x0047DC40
int TTextPanel::numberDrawLines() {
    return (int)this->draw_lines;
}

// From decomp at 0x0047DC50
int TTextPanel::currentLineNumber() {
    return (int)this->cur_line;
}

// From decomp at 0x0047DC70
char* TTextPanel::currentLine() {
    return this->get_text((long)this->cur_line);
}

// From decomp at 0x0047DC60
void TTextPanel::setCurrentLineNumber(int param_1) {
    this->set_line((long)param_1);
}

void TTextPanel::scroll(uchar param_1, short param_2, int param_3) {
    // Source of truth: Pnl_txt.cpp.decomp @ TTextPanel::scroll
    switch (param_1) {
    case 0:
        this->top_line = this->top_line + param_2;
        break;
    case 1:
        this->top_line = param_2;
        break;
    case 2:
        this->top_line = this->top_line + 1;
        break;
    case 3:
        this->top_line = this->top_line - 1;
        break;
    case 4:
        this->top_line = this->top_line + this->draw_lines - 1;
        break;
    case 5:
        this->top_line = this->top_line + (1 - this->draw_lines);
        break;
    case 6:
        this->top_line = 0;
        break;
    case 7:
        this->top_line = this->num_lines - 1;
        break;
    default:
        break;
    }

    calc_draw_info(this, param_3);
    this->set_redraw(TPanel::RedrawMode::Redraw);
}
