#include "../include/pnl_lst.h"
#include "../include/Pnl_scbr.h"
#include "../include/Pnl_txt.h"
#include <new.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mbstring.h>

static char s_pnl_txt__draw[] = "pnl_txt::draw";
static char s_pnl_txt__get_text_rect[] = "pnl_txt::get_text_rect";
static char s_pnl_txt__word_wrap_append[] = "pnl_txt::word_wrap_append";

extern "C" __declspec(dllimport) int __stdcall CompareStringA(
    unsigned long locale, unsigned long flags, const char* string1, int length1, const char* string2, int length2
);

TTextPanel::TTextPanel() :
    list(0), num_lines(0), draw_lines(0), top_line(0), bot_line(0), cur_line(0), cur_col(0), font(0), font_wid(0),
    font_hgt(0), vert_align(AlignCenter), horz_align(AlignCenter), word_wrap(0), text_style(ChiseledStyle),
    text_color1(0xFFFFFF), text_color2(0), highlightTextColor1(0xFFFF), highlightTextColor2(0), scbar_panel(0),
    auto_scbar(0), fixed_len(0), text_wid(0), text_hgt(0), back_pic(0), back_pic_wid(0), back_pic_hgt(0), fill_back(0),
    back_color(0xFF), outline(0), outline_color(0), sorted(0), second_column_pos(0), full_width(0), scbar_width(0),
    scbar_active(0), bevel_type(0), bevel_color1(0), bevel_color2(0), bevel_color3(0), bevel_color4(0), bevel_color5(0),
    bevel_color6(0), clip_rgn2(0), border_size(0), spacer_size(0) {
    this->handle_mouse_input = 0;
    this->panel_type = 1;
}

TTextPanel::~TTextPanel() {
    this->free_text();
    if (this->clip_rgn2 != 0) {
        DeleteObject(this->clip_rgn2);
        this->clip_rgn2 = 0;
    }
}

long TTextPanel::setup(
    TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in, void* font_in,
    long font_wid_in, long font_hgt_in, char* back_pic_in, int fill_back_in, unsigned char back_color_in,
    int outline_in, unsigned char outline_color_in, short fixed_len_in, char* text_in
) {
    TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
    fill_back = fill_back_in;
    back_color = (unsigned char) back_color_in;
    outline = outline_in;
    outline_color = outline_color_in;
    fixed_len = fixed_len_in;
    if (outline_in != 0) {
        bevel_type = 1;
    }
    set_text(text_in);
    set_font(font_in, font_wid_in, font_hgt_in);
    set_alignment(AlignCenter, AlignCenter);
    set_back_pic(back_pic_in);
    return 1;
}

long TTextPanel::setup(
    TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in, void* font_in,
    long font_wid_in, long font_hgt_in, char* back_pic_in, int fill_back_in, unsigned char back_color_in,
    int outline_in, unsigned char outline_color_in, short fixed_len_in, long string_id_in
) {
    char str[0x1000];

    TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
    fill_back = fill_back_in;
    back_color = back_color_in;
    outline = outline_in;
    outline_color = outline_color_in;
    fixed_len = fixed_len_in;
    if (outline_in != 0) {
        bevel_type = 1;
    }
    set_font(font_in, font_wid_in, font_hgt_in);
    set_alignment(AlignCenter, AlignCenter);
    set_back_pic(back_pic_in);
    TPanel::get_string(string_id_in, str, 4096);
    set_text(str);
    return 1;
}

long TTextPanel::setup(
    TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in, void* font_in,
    long font_wid_in, long font_hgt_in, char* back_pic_in, int fill_back_in, unsigned char back_color_in,
    int outline_in, unsigned char outline_color_in, short fixed_len_in, char** text_in, short num_lines_in
) {
    TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
    this->fill_back = fill_back_in;
    this->back_color = back_color_in;
    this->outline = outline_in;
    this->outline_color = outline_color_in;
    this->fixed_len = fixed_len_in;
    if (outline_in != 0) {
        this->bevel_type = 1;
    }
    this->set_text(text_in, num_lines_in);
    this->set_font(font_in, font_wid_in, font_hgt_in);
    this->set_alignment(AlignTop, AlignLeft);
    this->set_back_pic(back_pic_in);
    return 1;
}

void TTextPanel::set_rect(long x_in, long y_in, long wid_in, long hgt_in) {
    int x;
    int y;
    tagRECT clip_rect2;

    TPanel::set_rect(x_in, y_in, wid_in, hgt_in);
    this->full_width = this->pnl_wid;

    if (this->auto_scbar != 0 && this->scbar_panel != 0) {
        this->scbar_panel->set_active(0);
        this->scbar_active = 0;

        if (this->parent_panel != 0) {
            x = this->pnl_x - this->parent_panel->xPosition();
            y = this->pnl_y - this->parent_panel->yPosition();
        } else {
            x = this->pnl_x;
            y = this->pnl_y;
        }

        this->scbar_panel->set_fixed_position(
            x + this->full_width - this->scbar_width, y, this->scbar_width, this->pnl_hgt
        );
    }

    this->calc_draw_info(1);

    if (this->second_column_pos != 0) {
        if (this->clip_rgn2 != 0) {
            DeleteObject(this->clip_rgn2);
            this->clip_rgn2 = 0;
        }

        if (this->visible != 0) {
            clip_rect2 = this->clip_rect;
            clip_rect2.right = this->render_rect.left + this->second_column_pos - 10;
            if (clip_rect2.right > this->clip_rect.right) {
                clip_rect2.right = this->clip_rect.right;
            }
            this->clip_rgn2 = CreateRectRgn(clip_rect2.left, clip_rect2.top, clip_rect2.right, clip_rect2.bottom);
        }
    }
}

void TTextPanel::set_scrollbar(TScrollBarPanel* scbar_panel_in, int auto_scbar_in) {
    this->scbar_panel = scbar_panel_in;
    this->auto_scbar = auto_scbar_in;
    if (scbar_panel_in != 0) {
        this->scbar_width = scbar_panel_in->width();
        this->set_rect(this->pnl_x, this->pnl_y, this->pnl_wid, this->pnl_hgt);
    }
}

TTextPanel::CharType TTextPanel::char_type(unsigned char* c) {
    if (c != 0 && *c != 0) {
        if (IsDBCSLeadByte(*c) != 0) {
            return DoubleByteChar;
        }

        if (*c >= 0xA1 && *c <= 0xDF) {
            return SingleByteKanaChar;
        }
    }

    return SingleByteChar;
}

void TTextPanel::set_text(char* text_in) {
    char temp_text[256];

    free_text();
    if (text_in == 0) {
        if (fixed_len != 0) {
            append_line("", 0);
            return;
        }
    } else {
        if (*text_in == '\0') {
            append_line("", 0);
            return;
        }
        if (word_wrap == 0 && horz_align != AlignWordwrap) {
            while (true) {
                char* nl = (char*) _mbschr((const unsigned char*) text_in, '\n');
                if (nl == 0) {
                    break;
                }
                int len = nl - text_in;
                strncpy(temp_text, text_in, (short) len);
                temp_text[(short) len] = '\0';
                append_line(temp_text, 0);
                text_in = nl + 1;
            }
            append_line(text_in, 0);
            return;
        }
        word_wrap_append(text_in);
    }
}

int TTextPanel::word_wrap_append(char* text_in) {
    char* text = text_in;
    short text_len;
    short chars;
    short len;
    short last_fit_len;
    int found_break;
    int found_return;
    void* dc;
    int found_space;
    unsigned char* last_char;
    long max_wid;
    unsigned char* next_char;
    SIZE text_size;
    int found_linefeed;
    int found_bad_return;
    int japanese;
    void* old_font;
    TEXTMETRICA tm;
    unsigned char temp_text[256];

    if (text == 0) {
        return 1;
    }
    if (*text == '\0') {
        return 1;
    }

    if (this->auto_scbar != 0) {
        max_wid = this->full_width - this->scbar_width - 10;
    } else {
        max_wid = this->pnl_wid - 10;
    }

    dc = this->render_area->GetDc(s_pnl_txt__word_wrap_append);
    if (dc == 0) {
        return 0;
    }

    old_font = SelectObject((HDC) dc, (HGDIOBJ) this->font);
    GetTextMetricsA((HDC) dc, &tm);
    japanese = (tm.tmCharSet == 0x80);

    for (;;) {
        chars = 0;
        text_len = _mbslen((const unsigned char*) text);
        found_return = 0;
        found_linefeed = 0;
        found_space = 0;
        found_break = 0;
        found_bad_return = 0;
        next_char = (unsigned char*) text;

        if (*text == '\n') {
            found_return = 1;
        } else {
            chars = 1;
            len = _mbsinc((const unsigned char*) text) - (unsigned char*) text;
            GetTextExtentPoint32A((HDC) dc, text, len, &text_size);
            last_char = 0;

            while (chars <= (short) text_len) {
                if (text_size.cx >= max_wid) {
                    break;
                }
                if (*next_char == '\n') {
                    --chars;
                    found_return = 1;
                    if (last_char != 0 && *last_char == '\r') {
                        found_linefeed = 1;
                        --chars;
                    }
                    break;
                }
                if (*next_char == '\r') {
                    found_bad_return = 1;
                }

                last_char = next_char;
                next_char = _mbsinc(next_char);
                ++chars;
                len = _mbsinc(next_char) - (unsigned char*) text;
                GetTextExtentPoint32A((HDC) dc, text, len, &text_size);
            }
        }

        if (!found_return) {
            len = strlen(text);
            chars = text_len;
            GetTextExtentPoint32A((HDC) dc, text, len, &text_size);
            if (text_size.cx <= max_wid) {
                break;
            }
        }

        if (!found_return) {
            chars = 1;
            next_char = (unsigned char*) text;
            last_fit_len = chars;
            while (chars < (short) text_len) {
                // Measure ahead. Advance the cursor only after a successful fit.
                len = _mbsinc(next_char) - (unsigned char*) text;
                GetTextExtentPoint32A((HDC) dc, text, len, &text_size);
                if (text_size.cx > max_wid) {
                    break;
                }
                last_fit_len = chars - 1;
                next_char = _mbsinc(next_char);
                ++chars;
            }

            while (chars > 1) {
                unsigned char* old_next = next_char;
                next_char = _mbsdec((const unsigned char*) text, next_char);
                --chars;

                if (japanese) {
                    CharType first = this->char_type(next_char);
                    CharType second = this->char_type(old_next);
                    if (first == SingleByteChar && second == SingleByteChar && _ismbcspace(*next_char) != 0) {
                        found_space = 1;
                        break;
                    }
                    if ((first == DoubleByteChar && second == DoubleByteChar)
                        || (first == SingleByteKanaChar && second == SingleByteKanaChar)
                        || (first == SingleByteChar && second == DoubleByteChar)
                        || (first == DoubleByteChar && second == SingleByteChar)
                        || (first == SingleByteChar && second == SingleByteKanaChar)
                        || (first == SingleByteKanaChar && second == SingleByteChar)) {
                        found_break = 1;
                        break;
                    }
                } else if (_ismbcspace(*next_char) != 0) {
                    found_space = 1;
                    break;
                }
            }
            if (!found_space && !found_break) {
                chars = last_fit_len;
                found_break = 1;
            }
        }
        if (!found_return && !found_space && !found_break) {
            break;
        }

        memset(temp_text, 0, 256);
        _mbsncpy(temp_text, (const unsigned char*) text, chars);
        if (found_linefeed) {
            _mbscat(temp_text, (const unsigned char*) " ");
        }
        if (found_return) {
            _mbscat(temp_text, (const unsigned char*) " ");
        }
        if (found_bad_return) {
            unsigned char* p = temp_text;
            while (*p != 0) {
                if (*p == '\r') {
                    *p = ' ';
                }
                p = _mbsinc(p);
            }
        }
        this->append_line((char*) temp_text, 0);
        text = (char*) _mbsninc((const unsigned char*) text, chars);
        if (found_linefeed) {
            text = (char*) _mbsinc((const unsigned char*) text);
        }
        if (found_return) {
            text = (char*) _mbsinc((const unsigned char*) text);
        }
    }
    this->append_line(text, 0);
    SelectObject((HDC) dc, (HGDIOBJ) old_font);
    this->render_area->ReleaseDc(s_pnl_txt__word_wrap_append);
    return 1;
}

void TTextPanel::set_text(long string_id_in) {
    char buffer[0x1000];
    this->get_string(string_id_in, buffer, 4096);
    this->set_text(buffer);
}

void TTextPanel::set_text(char** text_in, short num_lines_in) {
    free_text();
    if (num_lines_in == 0) {
        if (fixed_len != 0) {
            append_line("", 0);
        }
    } else if (num_lines_in > 0) {
        int i = num_lines_in;
        do {
            append_line(text_in[0], 0);
            text_in++;
            i--;
        } while (i != 0);
    }
}

void TTextPanel::set_font(void* font_in, long font_wid_in, long font_hgt_in) {
    this->font = font_in;
    this->font_wid = font_wid_in;
    this->font_hgt = font_hgt_in;
    this->calc_draw_info(1);
    this->set_redraw(TPanel::RedrawNormal);
}

void TTextPanel::set_alignment(TTextPanel::Alignment vert_align_in, TTextPanel::Alignment horz_align_in) {
    this->vert_align = vert_align_in;
    this->horz_align = horz_align_in;
    this->set_redraw(TPanel::RedrawNormal);
}

void TTextPanel::set_word_wrap(int word_wrap_in) {
    this->word_wrap = word_wrap_in;
    this->set_redraw(TPanel::RedrawNormal);
}

void TTextPanel::set_style(TTextPanel::Style text_style_in) {
    this->text_style = text_style_in;
    this->set_redraw(TPanel::RedrawNormal);
}

void TTextPanel::set_text_color(unsigned long text_color1_in, unsigned long text_color2_in) {
    this->text_color1 = text_color1_in;
    this->text_color2 = text_color2_in;
    this->set_redraw(TPanel::RedrawNormal);
}

void TTextPanel::set_highlight_text_color(unsigned long text_color1_in, unsigned long text_color2_in) {
    this->highlightTextColor1 = text_color1_in;
    this->highlightTextColor2 = text_color2_in;
    this->set_redraw(TPanel::RedrawNormal);
}

void TTextPanel::set_fill_back(int fill_back_in, unsigned char back_color_in) {
    this->fill_back = fill_back_in;
    this->back_color = back_color_in;
}

void TTextPanel::set_back_pic(char* back_pic_in) {
    long x_max;
    long x_min;
    long y_max;
    long y_min;

    if (this->back_pic != 0) {
        delete this->back_pic;
        this->back_pic = 0;
        this->back_pic_wid = 0;
        this->back_pic_hgt = 0;
    }

    if (back_pic_in == 0 || *back_pic_in == '\0') {
        return;
    }

    this->back_pic = new TShape(back_pic_in, -1);
    this->back_pic->shape_minmax(x_max, x_min, y_max, y_min, 0);
    this->back_pic_wid = (short) (y_max - x_max + 1);
    this->back_pic_hgt = (short) (y_min - x_min + 1);
}

void TTextPanel::set_outline(int outline_in, unsigned char outline_color_in) {
    this->outline = outline_in;
    if (outline_in != 0) {
        this->bevel_type = 1;
    } else {
        this->bevel_type = 0;
    }
    this->outline_color = outline_color_in;
    this->set_redraw(TPanel::RedrawNormal);
}

void TTextPanel::set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6) {
    bevel_type = bevel_type_in, bevel_color1 = (unsigned char) c1;
    bevel_color2 = (unsigned char) c2;
    bevel_color3 = (unsigned char) c3;
    bevel_color4 = (unsigned char) c4;
    bevel_color5 = (unsigned char) c5;
    bevel_color6 = (unsigned char) c6;

    switch (bevel_type_in) {
        case 1:
        case 2:
        case 5:
            border_size = 1;
            break;
        case 3:
        case 6:
            border_size = 2;
            break;
        case 4:
        case 7:
            border_size = 3;
            break;
        default:
            border_size = 0;
            break;
    }
    calc_draw_info(1);
}

void TTextPanel::set_spacer_size(int size_in) {
    spacer_size = size_in;
    calc_draw_info(1);
}

void TTextPanel::set_active(int activ_in) {
    TPanel::set_active(activ_in);
    if (this->auto_scbar != 0 && this->scbar_panel != 0) {
        if (this->active != 0) {
            this->scbar_panel->set_active(this->scbar_active);
        } else {
            this->scbar_panel->set_active(0);
        }
    }
}

void TTextPanel::calc_draw_info(int update_scbar) {
    short bottom_line;
    short number_lines;
    short visible_lines;
    int font_height;
    int available_height;
    int line_height;

    font_height = this->font_hgt;
    line_height = font_height + 2;
    this->text_hgt = line_height;

    if (font_height == 0) {
        this->draw_lines = 1;
    } else {
        if (this->spacer_size == 0) {
            available_height = this->pnl_hgt - this->border_size * 2;
        } else {
            available_height = this->pnl_hgt - this->border_size * 2;
            line_height += this->spacer_size * 2 - 1;
        }
        this->draw_lines = (short) (available_height / line_height);
    }

    if (this->draw_lines < 1) {
        this->draw_lines = 1;
    }

    number_lines = this->num_lines;
    if (this->top_line >= number_lines) {
        this->top_line = number_lines - 1;
    }

    visible_lines = this->draw_lines;
    if ((int) number_lines - (int) this->top_line < (int) visible_lines) {
        this->top_line = number_lines - visible_lines;
    }

    if (this->top_line < 0) {
        this->top_line = 0;
    }

    bottom_line = this->top_line - 1 + visible_lines;
    this->bot_line = bottom_line;
    if (bottom_line < 0) {
        this->bot_line = 0;
    }
    if (this->bot_line >= number_lines) {
        this->bot_line = number_lines - 1;
    }

    if (this->cur_line < 0) {
        this->cur_line = 0;
    }
    if (this->cur_line >= number_lines) {
        this->cur_line = number_lines - 1;
    }

    if (this->scbar_panel != 0) {
        if (update_scbar != 0) {
            this->scbar_panel->set_list_len((int) number_lines - (int) visible_lines + 1, (int) this->top_line);
        }

        if (this->auto_scbar != 0) {
            if (this->num_lines > this->draw_lines) {
                if (this->scbar_active == 0) {
                    TPanel::set_rect(this->pnl_x, this->pnl_y, this->full_width - this->scbar_width, this->pnl_hgt);
                    this->scbar_active = 1;
                    if (this->active != 0) {
                        this->scbar_panel->set_active(1);
                        this->text_wid = this->pnl_wid;
                        return;
                    }
                }
            } else if (this->scbar_active != 0) {
                TPanel::set_rect(this->pnl_x, this->pnl_y, this->full_width, this->pnl_hgt);
                this->scbar_active = 0;
                if (this->active != 0) {
                    this->scbar_panel->set_active(0);
                }
            }
        }
    }

    this->text_wid = this->pnl_wid;
}

void TTextPanel::scroll(unsigned char scroll_type, short scroll_val, int update_scbar) {
    switch (scroll_type) {
        case 0:
            this->top_line += scroll_val;
            break;
        case 1:
            this->top_line = scroll_val;
            break;
        case 2:
            this->top_line++;
            break;
        case 3:
            this->top_line--;
            break;
        case 4: {
            short dx = this->draw_lines;
            dx--;
            this->top_line += dx;
            break;
        }
        case 5: {
            short ax = 1;
            ax -= this->draw_lines;
            this->top_line += ax;
            break;
        }
        case 6:
            this->top_line = 0;
            break;
        case 7: {
            short cx = this->num_lines;
            cx--;
            this->top_line = cx;
            break;
        }
    }

    this->calc_draw_info(update_scbar);
    this->set_redraw(TPanel::RedrawNormal);
}

long TTextPanel::key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key) {
    switch (key) {
        case 0x28:
            this->scroll(2, 0, 1);
            if (this->parent_panel != 0 && this->tab_stop != 0) {
                this->parent_panel->key_down_action(key, count, alt_key, ctrl_key, shift_key);
                return 1;
            }
            return 1;
        case 0x26:
            this->scroll(3, 0, 1);
            if (this->parent_panel != 0 && this->tab_stop != 0) {
                this->parent_panel->key_down_action(key, count, alt_key, ctrl_key, shift_key);
                return 1;
            }
            return 1;
        case 0x22:
            this->scroll(4, 0, 1);
            if (this->parent_panel != 0 && this->tab_stop != 0) {
                this->parent_panel->key_down_action(key, count, alt_key, ctrl_key, shift_key);
            }
            return 1;
        case 0x21:
            this->scroll(5, 0, 1);
            if (this->parent_panel != 0 && this->tab_stop != 0) {
                this->parent_panel->key_down_action(key, count, alt_key, ctrl_key, shift_key);
            }
            return 1;
        case 0x24:
            this->scroll(6, 0, 1);
            return 1;
        case 0x23:
            this->scroll(7, 0, 1);
            return 1;
        default:
            return 0;
    }
}

long TTextPanel::action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2) {
    if (this->scbar_panel && from_panel == this->scbar_panel) {
        switch (action_in) {
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
                this->scroll(1, action_val1, 0);
                return 1;
        }
    }
    return TPanel::action(from_panel, action_in, action_val1, action_val2);
}

void TTextPanel::draw() {
    this->need_redraw = 0;
    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        return;
    }

    this->draw_background();
    this->draw_setup(0);

    void* dc = this->render_area->GetDc(s_pnl_txt__draw);
    if (dc != 0) {
        SelectClipRgn(dc, this->clip_rgn);
        void* old_font = SelectObject(dc, this->font);
        SetBkMode(dc, TRANSPARENT);

        for (short line = this->top_line, line_index = 0; line <= this->bot_line; ++line, ++line_index) {
            if ((this->tab_stop != 0 && this->have_focus != 0) || this->mouse_captured != 0) {
                this->draw_line(dc, line_index, line, this->highlightTextColor1, this->highlightTextColor2);
            } else {
                this->draw_line(dc, line_index, line, this->text_color1, this->text_color2);
            }
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc(s_pnl_txt__draw);
    }

    this->draw_border();
    this->draw_finish();
}

void TTextPanel::draw_background() {
    short pic_cols;
    short pic_rows = 0;

    if (this->back_pic != 0) {
        if (this->render_area->Lock("pnl_txt::draw_background", 1) == 0) {
            return;
        }

        if (this->back_pic_wid >= this->pnl_wid) {
            pic_cols = 1;
        } else {
            pic_cols = (short) (this->pnl_wid / this->back_pic_wid);
            if ((short) pic_cols * this->back_pic_wid < this->pnl_wid) {
                pic_cols++;
            }
        }

        if (this->back_pic_hgt >= this->pnl_hgt) {
            pic_rows = (short) (this->pnl_hgt / this->back_pic_hgt);
            if ((short) pic_rows * this->back_pic_hgt < this->pnl_hgt) {
                pic_rows++;
            }
        }

        if (pic_rows > 0) {
            int row = 0;
            int row_count = pic_rows;
            do {
                if (pic_cols > 0) {
                    int col = 0;
                    int col_count = (short) pic_cols;
                    do {
                        int draw_y = row * this->back_pic_hgt + this->pnl_y;
                        int draw_x = col * this->back_pic_wid + this->pnl_x;
                        this->back_pic->shape_draw(this->render_area, draw_x, draw_y, 0, 0, 0);
                        col++;
                        col_count--;
                    } while (col_count != 0);
                }
                row++;
                row_count--;
            } while (row_count != 0);
        }

        this->render_area->Unlock("pnl_txt::draw_background");
        return;
    }

    if (this->fill_back != 0) {
        if (this->render_area->Lock("pnl_txt::draw_background2", 1) == 0) {
            return;
        }
        this->render_area->FillRect(
            this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->back_color
        );
        this->render_area->Unlock("pnl_txt::draw_background2");
        return;
    }

    if (this->parent_panel != 0) {
        if (this->bevel_type >= 2 && this->bevel_type <= 7) {
            this->parent_panel->draw_rect2(&this->clip_rect);
            return;
        }
        if (this->parent_panel->just_drawn == 0) {
            this->parent_panel->draw_rect(&this->clip_rect);
        }
    }
}

void TTextPanel::draw_border() {
    if (this->bevel_type != 0) {
        if (this->render_area->Lock("pnl_txt::draw_border", 1) != 0) {
            switch (this->bevel_type) {
                case 1:
                    this->render_area->DrawRect(
                        this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->outline_color
                    );
                    break;
                case 2:
                    this->render_area->DrawBevel(
                        this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color6, this->bevel_color1
                    );
                    break;
                case 3:
                    this->render_area->DrawBevel2(
                        this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1
                    );
                    break;
                case 4:
                    this->render_area->DrawBevel3(
                        this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3,
                        this->bevel_color2, this->bevel_color1
                    );
                    break;
                case 5:
                    this->render_area->DrawBevel(
                        this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color1, this->bevel_color6
                    );
                    break;
                case 6:
                    this->render_area->DrawBevel2(
                        this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6
                    );
                    break;
                case 7:
                    this->render_area->DrawBevel3(
                        this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4,
                        this->bevel_color5, this->bevel_color6
                    );
                    break;
            }
        }
        this->render_area->Unlock("pnl_txt::draw_border");
    }
}

void TTextPanel::draw_line(void* dc, short draw_row, short text_line, unsigned long color1, unsigned long color2) {
    char* text;
    char* text2;
    short text_len;
    short text2_len;
    RECT line_rect;
    TTextPanel* panel = this;

    text_len = 0;
    text2_len = 0;
    text = this->get_text((long) text_line);
    text2 = this->get_text2((long) text_line);

    if (text == 0 && text2 == 0) {
        return;
    }

    if (text != 0) {
        text_len = (short) strlen(text);
    }

    if (text2 != 0) {
        text2_len = (short) strlen(text2);
    }

    this->calc_line_pos(dc, draw_row, text_line, &line_rect, 0);

    long text_x = line_rect.left;
    if (this->horz_align != 0 && this->horz_align != 6) {
        text_x += 5;
    }
    long second_text_x = this->second_column_pos + text_x;
    long text_y = line_rect.top;

    if (this->clip_rgn2 != 0) {
        SelectClipRgn(dc, this->clip_rgn2);
    }

    switch (this->text_style) {
        case 0:
            SetTextColor(dc, color1);
            if (text != 0) {
                TextOutA(dc, text_x, text_y, text, (int) text_len);
            }
            break;
        case 1:
            SetTextColor(dc, color1);
            if (text != 0) {
                TextOutA(dc, text_x - 1, text_y + 1, text, (int) text_len);
            }
            SetTextColor(dc, color2);
            if (text != 0) {
                TextOutA(dc, text_x, text_y, text, (int) text_len);
            }
            break;
        case 2:
            SetTextColor(dc, color2);
            if (text != 0) {
                TextOutA(dc, text_x - 1, text_y + 1, text, (int) text_len);
            }
            SetTextColor(dc, color1);
            if (text != 0) {
                TextOutA(dc, text_x, text_y, text, (int) text_len);
            }
            break;
        default:
            break;
    }

    if (text2 == 0) {
        return;
    }

    if (panel->clip_rgn2 != 0) {
        SelectClipRgn(dc, panel->clip_rgn);
    }

    switch (panel->text_style) {
        case 0:
            SetTextColor(dc, color1);
            TextOutA(dc, second_text_x, text_y, text2, (int) text2_len);
            return;
        case 1:
            SetTextColor(dc, color1);
            TextOutA(dc, second_text_x - 1, text_y + 1, text2, (int) text2_len);
            SetTextColor(dc, color2);
            TextOutA(dc, second_text_x, text_y, text2, (int) text2_len);
            return;
        case 2:
            SetTextColor(dc, color2);
            TextOutA(dc, second_text_x - 1, text_y + 1, text2, (int) text2_len);
            SetTextColor(dc, color1);
            TextOutA(dc, second_text_x, text_y, text2, (int) text2_len);
            return;
        default:
            return;
    }
}

void TTextPanel::calc_line_pos(void* dc, short draw_row, short text_line, tagRECT* line_rect, long* cursor_x_offset) {
    char* text;
    short text_len;
    short len;
    long col_offset;
    long text_width;
    long line_left;
    long line_top;
    long line_height;
    SIZE text_size;
    unsigned char temp_text2[256];

    text = this->get_text((long) text_line);
    if (text != 0) {
        if (this->cur_col == 0) {
            col_offset = 0;
        } else {
            text_len = (short) _mbslen((const unsigned char*) text);
            if (this->cur_col > text_len) {
                len = (short) strlen(text);
                GetTextExtentPoint32A((HDC) dc, text, len, &text_size);
            } else {
                memset(temp_text2, 0, sizeof(temp_text2));
                _mbsncpy(temp_text2, (const unsigned char*) text, this->cur_col);
                len = (short) strlen((const char*) temp_text2);
                GetTextExtentPoint32A((HDC) dc, text, len, &text_size);
            }
            col_offset = text_size.cx;
        }

        text_len = (short) _mbslen((const unsigned char*) text);
        len = (short) strlen(text);
        GetTextExtentPoint32A((HDC) dc, text, len, &text_size);
        text_width = text_size.cx;
    } else {
        col_offset = 0;
        text_width = 0;
    }

    if (this->horz_align != AlignCenter && this->horz_align != AlignWordwrap) {
        col_offset += 5;
    }

    switch (this->horz_align) {
        case AlignLeft:
            line_left = this->pnl_x + this->border_size;
            break;
        case AlignRight:
            line_left = this->pnl_x + this->pnl_wid - this->border_size - text_width - 7;
            break;
        case AlignHorizontalScroll:
            line_left = this->pnl_x + this->border_size;
            if (col_offset + 1 >= this->pnl_wid) {
                line_left += this->pnl_wid - col_offset - 2;
            }
            break;
        default:
            line_left = this->pnl_x - text_width / 2 + this->pnl_wid / 2;
            break;
    }

    if (this->spacer_size == 0) {
        line_height = this->text_hgt;
    } else {
        line_height = this->text_hgt + this->spacer_size * 2 - 1;
    }

    switch (this->vert_align) {
        case AlignTop:
            line_top = this->pnl_y + draw_row * line_height + this->border_size + this->spacer_size;
            break;
        case AlignBottom:
            line_top = this->pnl_y + this->pnl_hgt - (this->num_lines - draw_row) * line_height - this->border_size
                       - this->spacer_size - 1;
            break;
        default:
            line_top = this->pnl_y + draw_row * line_height - this->num_lines * line_height / 2 + this->pnl_hgt / 2;
            break;
    }

    line_rect->left = line_left;
    line_rect->top = line_top;
    line_rect->right = line_left + text_width - 1;
    line_rect->bottom = line_top + this->text_hgt;

    if (cursor_x_offset != 0) {
        *cursor_x_offset = col_offset;
    }
}

long TTextPanel::mouse_left_down_action(long x, long y, int ctrl_key, int shift_key) {
    if (this->parent_panel != 0) {
        this->parent_panel->action(this, 1, 0, 0);
    }
    return 0;
}

int TTextPanel::numberLines() const {
    return num_lines;
}

int TTextPanel::numberDrawLines() const {
    return draw_lines;
}

int TTextPanel::currentLineNumber() const {
    return cur_line;
}

void TTextPanel::setCurrentLineNumber(int v) {
    this->set_line(v);
}

char* TTextPanel::currentLine() {
    return this->get_text();
}

void TTextPanel::set_line(long line_in) {
    cur_line = (short) line_in;
    calc_draw_info(1);
}

void TTextPanel::set_line_by_id(long id_in) {
    int index = 0;
    void** node = (void**) this->list;

    if (node == 0)
        return;

    while (node) {
        if ((long) node[2] == id_in) {
            this->set_line(index);
            return;
        }
        node = (void**) node[3];
        index++;
    }
}

int TTextPanel::append_line(char* text_in, long id_in) {
    return insert_line((int) num_lines, text_in, id_in);
}

int TTextPanel::append_line(char* text_in, char* text2_in, long id_in) {
    return insert_line((int) num_lines, text_in, text2_in, id_in);
}

int TTextPanel::append_line(long string_id_in, long id_in) {
    return insert_line((int) num_lines, string_id_in, id_in);
}

int TTextPanel::append_line(long string_id_in, long string_id2_in, long id_in) {
    return insert_line((int) num_lines, string_id_in, string_id2_in, id_in);
}

int TTextPanel::insert_line(long line_in, char* text_in, long id_in) {
    return insert_line(line_in, text_in, 0, id_in);
}

int TTextPanel::insert_line(long line_in, char* text_in, char* text2_in, long id_in) {
    TextNode* new_node = (TextNode*) calloc(1, sizeof(TextNode));
    if (new_node == 0) {
        return 0;
    }

    if (this->fixed_len != 0) {
        new_node->text = (char*) calloc(this->fixed_len + 1, 1);
    } else if (text_in == 0) {
        new_node->text = (char*) calloc(1, 1);
    } else {
        new_node->text = (char*) calloc(strlen(text_in) + 1, 1);
    }

    if (new_node->text == 0) {
        free(new_node);
        return 0;
    }

    if (text2_in != 0) {
        new_node->text2 = (char*) calloc(strlen(text2_in) + 1, 1);
        if (new_node->text2 == 0) {
            free(new_node->text);
            free(new_node);
            return 0;
        }
    }

    if (text_in == 0) {
        new_node->text[0] = '\0';
    } else if (this->fixed_len != 0) {
        strncpy(new_node->text, text_in, this->fixed_len);
        new_node->text[this->fixed_len] = '\0';
    } else {
        strcpy(new_node->text, text_in);
    }

    if (text2_in != 0) {
        strcpy(new_node->text2, text2_in);
    }

    new_node->id = id_in;
    new_node->next_node = 0;

    TextNode* node = this->list;
    if (node == 0) {
        this->list = new_node;
    } else if (this->sorted != 0) {
        TextNode* previous = 0;
        while (node != 0) {
            if (CompareStringA(LOCALE_USER_DEFAULT, NORM_IGNORECASE, new_node->text, -1, node->text, -1) == 1) {
                new_node->next_node = node;
                if (previous == 0) {
                    this->list = new_node;
                } else {
                    previous->next_node = new_node;
                }
                break;
            }
            previous = node;
            node = node->next_node;
        }
        if (node == 0) {
            previous->next_node = new_node;
        }
    } else if (line_in == 0) {
        new_node->next_node = node;
        this->list = new_node;
    } else if (line_in >= this->num_lines) {
        while (node->next_node != 0) {
            node = node->next_node;
        }
        node->next_node = new_node;
    } else {
        int index = 0;
        --line_in;
        while (index != line_in) {
            node = node->next_node;
            ++index;
        }
        new_node->next_node = node->next_node;
        node->next_node = new_node;
    }

    ++this->num_lines;
    this->calc_draw_info(1);
    this->set_redraw(TPanel::RedrawNormal);
    return 1;
}

int TTextPanel::insert_line(long line_in, long string_id_in, long id_in) {
    char str[256];

    get_string((int) string_id_in, str, 256);
    return insert_line(line_in, str, id_in);
}

int TTextPanel::insert_line(long line_in, long string_id_in, long string_id2_in, long id_in) {
    char str1[256];
    char str2[256];

    this->get_string(string_id_in, str1, 256);
    this->get_string(string_id2_in, str2, 256);
    return this->insert_line(line_in, str1, str2, id_in);
}

int TTextPanel::change_line(long line_in, char* text_in, char* text2_in, long id_in) {
    int saved_sorted;
    int insert_result;

    saved_sorted = this->sorted;
    this->sorted = 0;
    insert_result = insert_line(line_in, text_in, text2_in, id_in);
    if (insert_result == 0) {
        this->sorted = saved_sorted;
        return 0;
    }

    delete_line(line_in + 1);
    this->sorted = saved_sorted;
    return 1;
}

int TTextPanel::change_line(long line_in, long string_id_in, long string_id2_in, long id_in) {
    int saved_sorted = this->sorted;
    this->sorted = 0;

    if (insert_line(line_in, string_id_in, string_id2_in, id_in) == 0) {
        this->sorted = saved_sorted;
        return 0;
    }

    delete_line(line_in + 1);
    this->sorted = saved_sorted;
    return 1;
}

int TTextPanel::delete_line(long line_in) {
    if (line_in >= 0 && line_in <= this->num_lines - 1) {
        TTextPanel::TextNode* deleted;

        if (line_in == 0) {
            deleted = this->list;
            this->list = deleted->next_node;
        } else {
            TTextPanel::TextNode* node = this->list;
            int i = 0;
            --line_in;
            while (true) {
                if (i == line_in) {
                    break;
                }
                node = node->next_node;
                ++i;
            }
            deleted = node->next_node;
            node->next_node = deleted->next_node;
        }

        if (deleted != 0) {
            if (deleted->text != 0) {
                free(deleted->text);
            }
            if (deleted->text2 != 0) {
                free(deleted->text2);
            }
            free(deleted);
            --this->num_lines;

            short count = this->num_lines;
            if (count == 0) {
                this->cur_line = 0;
            } else if (this->cur_line >= count) {
                this->cur_line = count - 1;
            }

            this->calc_draw_info(1);
            this->set_redraw(TPanel::RedrawNormal);
            return 1;
        }
    }
    return 0;
}

long TTextPanel::get_line() {
    if (num_lines == 0) {
        return -1;
    }
    return cur_line;
}

long TTextPanel::get_line(long id_in) {
    TTextPanel::TextNode* node = this->list;
    int i = 0;
    while (node != 0) {
        if (node->id == id_in) {
            return i;
        }
        node = node->next_node;
        ++i;
    }
    return -1;
}

long TTextPanel::get_line(char* text_in) {
    TTextPanel::TextNode* node = this->list;
    long i = 0;
    while (node != 0) {
        if (strcmp(node->text, text_in) == 0)
            return i;
        node = node->next_node;
        ++i;
    }
    return -1;
}

char* TTextPanel::get_text() {
    return this->get_text(this->cur_line);
}

char* TTextPanel::get_text(long line_in) {
    static char empty_text;
    long i;
    TTextPanel::TextNode* node;

    i = 0;
    node = this->list;
    if (node == 0) {
        empty_text = 0;
        return &empty_text;
    }
    while (node != 0) {
        if (i == line_in) {
            return node->text;
        }
        node = node->next_node;
        i++;
    }
    empty_text = 0;
    return &empty_text;
}

char* TTextPanel::get_text2() {
    return this->get_text2(this->cur_line);
}

char* TTextPanel::get_text2(long line_in) {
    static char empty_text;
    long i;
    TTextPanel::TextNode* node;

    i = 0;
    node = this->list;
    if (node == 0) {
        empty_text = 0;
        return &empty_text;
    }
    while (node != 0) {
        if (i == line_in)
            return node->text2;
        node = node->next_node;
        i++;
    }
    empty_text = 0;
    return &empty_text;
}

long TTextPanel::get_id() {
    return this->get_id(this->cur_line);
}

long TTextPanel::get_id(long line_in) {
    long count = 0;
    long target = line_in;
    TTextPanel::TextNode* node = this->list;

    if (node == 0)
        return -1;

    while (node != 0) {
        if (count == target) {
            return node->id;
        }
        node = node->next_node;
        count++;
    }
    return -1;
}

void TTextPanel::empty_list() {
    this->free_text();
}

void TTextPanel::free_text(void) {
    TTextPanel::TextNode* node = this->list;
    if (node != 0) {
        do {
            if (node->text != 0) {
                free(node->text);
            }
            if (node->text2 != 0) {
                free(node->text2);
            }
            TTextPanel::TextNode* old = node;
            node = node->next_node;
            free(old);
        } while (node != 0);
        this->list = 0;
    }
    this->num_lines = 0;
    this->calc_draw_info(1);
    this->set_redraw(TPanel::RedrawNormal);
}

void TTextPanel::set_second_column_pos(long val) {
    this->second_column_pos = val;
    this->set_redraw(TPanel::RedrawNormal);
}

int TTextPanel::get_text_rect(RECT* rect) {
    void* dc = this->render_area->GetDc(s_pnl_txt__get_text_rect);
    if (dc != 0) {
        void* old_font = SelectObject(dc, this->font);
        this->calc_line_pos(dc, 0, 0, rect, 0);
        SelectObject(dc, old_font);
        this->render_area->ReleaseDc(s_pnl_txt__get_text_rect);
        return 1;
    }
    return 0;
}
