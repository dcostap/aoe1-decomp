#include "../include/Pnl_txt.h"
#include <new.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char s_pnl_txt__draw[];
extern char s_pnl_txt__get_text_rect[];
extern "C" short __cdecl __mbslen(const char* text);
extern "C" unsigned char* __cdecl __mbsinc(const unsigned char* text);
extern "C" unsigned char* __cdecl __mbsdec(const unsigned char* start,
                                               const unsigned char* current);
extern "C" unsigned char* __cdecl __mbsninc(const unsigned char* text,
                                               int count);
extern "C" unsigned char* __cdecl __mbscat(unsigned char* dst,
                                               const unsigned char* src);
extern "C" int __cdecl __ismbcspace(int ch);
extern "C" char* __cdecl __mbschr(const char* text, unsigned int ch);
extern "C" char* __cdecl _mbschr(const char* text, unsigned int ch);
extern "C" unsigned char* __cdecl __mbsncpy(unsigned char* dst,
                                               const unsigned char* src,
                                               int count);
extern "C" __declspec(dllimport) int __stdcall CompareStringA(
    unsigned long locale, unsigned long flags, const char* string1,
    int length1, const char* string2, int length2);
extern char DAT_0086B250;
extern unsigned char DAT_0086b24c;
typedef void* (__stdcall *SelectObjectFn)(void* hdc, void* obj);

struct DrawLineRect {
    TTextPanel* receiver;
    RECT rect;
};

// PDB: Pnl_txt.cpp:73-78.
TTextPanel::TTextPanel()
    : list(0),
      num_lines(0),
      draw_lines(0),
      top_line(0),
      bot_line(0),
      cur_line(0),
      cur_col(0),
      font(0),
      font_wid(0),
      font_hgt(0),
      vert_align(0),
      horz_align(0),
      word_wrap(0),
      text_style(2),
      text_color1(0xFFFFFF),
      text_color2(0),
      highlight_text_color1(0xFFFF),
      highlight_text_color2(0),
      scbar_panel(0),
      auto_scbar(0),
      fixed_len(0),
      text_wid(0),
      text_hgt(0),
      back_pic(0),
      back_pic_wid(0),
      back_pic_hgt(0),
      fill_back(0),
      back_color(0xFF),
      outline(0),
      outline_color(0),
      sorted(0),
      second_column_pos(0),
      full_width(0),
      scbar_width(0),
      scbar_active(0),
      bevel_type(0),
      bevel_color1(0),
      bevel_color2(0),
      bevel_color3(0),
      bevel_color4(0),
      bevel_color5(0),
      bevel_color6(0),
      clip_rgn2(0),
      border_size(0),
      spacer_size(0)
{
    this->handle_mouse_input = 0;
    this->panel_type = 1;
}

// PDB: Pnl_txt.cpp:84-92.
TTextPanel::~TTextPanel()
{
    this->free_text();
    if (this->clip_rgn2 != 0) {
        DeleteObject(this->clip_rgn2);
        this->clip_rgn2 = 0;
    }
    // No explicit TPanel::~TPanel() call — VC5 auto-generates it.
    // An explicit call creates a duplicate call before eh_state = -1.
}

// PDB: Pnl_txt.cpp:102-120.
long TTextPanel::setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h,
                       void* font, long font_arg2, long font_arg3, char* back_pic,
                       int fill, unsigned char backColor, int outlineValue, unsigned char outlineColor,
                       short fixedLenValue, char* text)
{
    TPanel::setup(draw, parent, x, y, w, h, 0);
    fill_back = fill;
    back_color = (unsigned char)backColor;
    outline = outlineValue;
    outline_color = outlineColor;
    fixed_len = fixedLenValue;
    if (outlineValue != 0) {
        bevel_type = 1;
    }
    set_text(text);
    set_font(font, font_arg2, font_arg3);
    set_alignment(AlignCenter, AlignCenter);
    set_back_pic(back_pic);
    return 1;
}

// PDB: Pnl_txt.cpp:130-151.
long TTextPanel::setup(TDrawArea* draw, TPanel* parent, long x, long y, long w,
                       long h, void* font, long font_width, long font_height,
                       char* back_picture, int fill, unsigned char backColor,
                       int outlineValue, unsigned char outlineColor,
                       short fixedLen, long text_id)
{
    char str[0x1000];

    TPanel::setup(draw, parent, x, y, w, h, 0);
    fill_back = fill;
    back_color = backColor;
    outline = outlineValue;
    outline_color = outlineColor;
    fixed_len = fixedLen;
    if (outlineValue != 0) {
        bevel_type = 1;
    }
    set_font(font, font_width, font_height);
    set_alignment(AlignCenter, AlignCenter);
    set_back_pic(back_picture);
    TPanel::get_string(text_id, str, 0x1000);
    set_text(str);
    return 1;
}

// PDB: Pnl_txt.cpp:161-179.
long TTextPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4,
                       long param_5, long param_6, void* param_7, long param_8,
                       long param_9, char* param_10, int param_11, unsigned char param_12,
                       int param_13, unsigned char param_14, short param_15,
                       char** param_16, short param_17)
{
    TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0);
    this->fill_back = param_11;
    this->back_color = param_12;
    this->outline = param_13;
    this->outline_color = param_14;
    this->fixed_len = param_15;
    if (param_13 != 0) {
        this->bevel_type = 1;
    }
    this->set_text(param_16, param_17);
    this->set_font(param_7, param_8, param_9);
    this->set_alignment(AlignTop, AlignLeft);
    this->set_back_pic(param_10);
    return 1;
}

// PDB: Pnl_txt.cpp:185-231.
void TTextPanel::set_rect(long left, long top, long width, long height) {
    int x;
    int y;
    tagRECT clip_rect2;

    TPanel::set_rect(left, top, width, height);
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
            x + this->full_width - this->scbar_width,
            y,
            this->scbar_width,
            this->pnl_hgt);
    }

    this->calc_draw_info(1);

    if (this->second_column_pos != 0) {
        if (this->clip_rgn2 != 0) {
            DeleteObject(this->clip_rgn2);
            this->clip_rgn2 = 0;
        }

        if (this->visible != 0) {
            clip_rect2 = this->clip_rect;
            clip_rect2.right = this->render_rect.left +
                               this->second_column_pos - 10;
            if (clip_rect2.right > this->clip_rect.right) {
                clip_rect2.right = this->clip_rect.right;
            }
            this->clip_rgn2 = CreateRectRgn(
                clip_rect2.left,
                clip_rect2.top,
                clip_rect2.right,
                clip_rect2.bottom);
        }
    }
}

// PDB: Pnl_txt.cpp:237-246.
void TTextPanel::set_scrollbar(TScrollBarPanel* panel, int auto_scbar_value) {
    this->scbar_panel = panel;
    this->auto_scbar = auto_scbar_value;
    if (panel != 0) {
        this->scbar_width = panel->width();
        this->set_rect(this->pnl_x, this->pnl_y, this->pnl_wid, this->pnl_hgt);
    }
}

// PDB: Pnl_txt.cpp:254-262.
TTextPanel::CharType TTextPanel::char_type(unsigned char* text) {
    if (text != 0 && *text != 0) {
        if (IsDBCSLeadByte(*text) != 0) {
            return DoubleByteChar;
        }

        if (*text >= 0xA1 && *text <= 0xDF) {
            return SingleByteKanaChar;
        }
    }

    return SingleByteChar;
}

// PDB: Pnl_txt.cpp:268-314.
void TTextPanel::set_text(char* text) {
    char temp_text[256];

    free_text();
    if (text == 0) {
        if (fixed_len != 0) {
            append_line("", 0);
            return;
        }
    } else {
        if (*text == '\0') {
            append_line("", 0);
            return;
        }
        if (word_wrap == 0 && horz_align != 6) {   // 6 == AlignWordwrap
            while (true) {
                char* nl = _mbschr(text, '\n');
                if (nl == 0) {
                    break;
                }
                int len = nl - text;
                strncpy(temp_text, text, (short)len);
                temp_text[(short)len] = '\0';
                append_line(temp_text, 0);
                text = nl + 1;
            }
            append_line(text, 0);
            return;
        }
        word_wrap_append(text);
    }
}

// PDB: Pnl_txt.cpp:320-560.
int TTextPanel::word_wrap_append(char* text)
{
    short text_len;
    short chars;
    short last_chars;
    int found_break;
    int found_return;
    void* dc;
    int found_space;
    unsigned char* last_char;
    long max_wid;
    unsigned char* next_char;
    SIZE text_size;
    int found_linefeed;
    int found_char_break;
    int japanese;
    void* old_font;
    TEXTMETRICA tm;
    char temp_text[256];

    if (text == 0) {
        return 1;
    }
    if (*text == '\0') {
        return 1;
    }

    if (this->auto_scbar != 0) {
        max_wid = this->full_width - this->scbar_width;
    } else {
        max_wid = this->pnl_wid;
    }
    max_wid -= 10;

    dc = this->render_area->GetDc((char*)0x58547c);
    if (dc == 0) {
        return 0;
    }

    old_font = SelectObject((HDC)dc, (HGDIOBJ)this->font);
    GetTextMetricsA((HDC)dc, &tm);
    japanese = (tm.tmCharSet == 0x80);

    for (;;) {
    next_line:
        text_len = __mbslen(text);
        found_break = 0;
        found_linefeed = 0;
        found_char_break = 0;
        found_space = 0;
        found_return = 0;
        next_char = (unsigned char*)text;

        if (*text == '\n') {
            found_linefeed = 1;
            chars = 0;
            goto emit_line;
        }

        chars = 1;
        next_char = (unsigned char*)text;
        GetTextExtentPoint32A((HDC)dc, text,
                              (int)(short)(__mbsinc(
                                  (const unsigned char*)text) -
                                           (unsigned char*)text),
                              &text_size);
        last_char = 0;

        while (chars <= text_len) {
            if (text_size.cx >= max_wid) {
                break;
            }
            if (*next_char == '\n') {
            --chars;
            found_linefeed = 1;
            if (last_char != 0 && *last_char == '\r') {
                found_space = 1;
                --chars;
            }
                break;
            }
            if (*next_char == '\r') {
                found_return = 1;
            }

            last_char = next_char;
            next_char = __mbsinc(next_char);
            ++chars;
            GetTextExtentPoint32A(
                (HDC)dc, text,
                (int)(short)(__mbsinc(next_char) - (unsigned char*)text),
                &text_size);
        }

    emit_line:
        if (!found_linefeed) {
            GetTextExtentPoint32A((HDC)dc, text, (int)(short)strlen(text),
                              &text_size);
            if (text_size.cx <= max_wid) {
                goto append_all;
            }

            chars = 1;
            next_char = (unsigned char*)text;
            last_chars = chars;
            while (chars < text_len) {
                next_char = __mbsinc(next_char);
                GetTextExtentPoint32A(
                    (HDC)dc, text,
                    (int)(short)(next_char - (unsigned char*)text),
                    &text_size);
                if (text_size.cx > max_wid) {
                    break;
                }
                last_chars = chars - 1;
                next_char = __mbsinc(next_char);
                ++chars;
            }

            while (chars > 1) {
                unsigned char* old_next = next_char;
                next_char = __mbsdec((const unsigned char*)text, next_char);
                --chars;

                if (japanese) {
                    CharType first = this->char_type(next_char);
                    CharType second = this->char_type(old_next);
                    if (first == SingleByteChar && second == SingleByteChar &&
                        __ismbcspace(*next_char) != 0) {
                        found_char_break = 1;
                        break;
                    }
                    if ((first == DoubleByteChar && second == DoubleByteChar) ||
                        (first == SingleByteKanaChar && second == SingleByteKanaChar) ||
                        (first == SingleByteChar && second == DoubleByteChar) ||
                        (first == DoubleByteChar && second == SingleByteChar) ||
                        (first == SingleByteChar && second == SingleByteKanaChar) ||
                        (first == SingleByteKanaChar && second == SingleByteChar)) {
                        found_break = 1;
                        break;
                    }
                } else if (__ismbcspace(*next_char) != 0) {
                    found_char_break = 1;
                    break;
                }
            }
        }

        if (!found_break && !found_char_break) {
            chars = last_chars;
            found_break = 1;
        }
        if (!found_linefeed && !found_char_break && !found_break) {
            goto append_all;
        }

        memset(temp_text, 0, 0x100);
        __mbsncpy((unsigned char*)temp_text + 4,
                  (const unsigned char*)text, chars);
        if (found_space) {
            __mbscat((unsigned char*)temp_text + 4,
                     (const unsigned char*)0x580460);
        }
        if (found_linefeed) {
            __mbscat((unsigned char*)temp_text + 4,
                     (const unsigned char*)0x580460);
        }
        if (found_return) {
            unsigned char* p = (unsigned char*)temp_text + 4;
            while (*p != 0) {
                if (*p == '\r') {
                    *p = ' ';
                }
                p = __mbsinc(p);
            }
        }
        this->append_line(temp_text + 4, 0);
        text = (char*)__mbsninc((const unsigned char*)text, chars);
        if (found_space) {
            text = (char*)__mbsinc((const unsigned char*)text);
        }
        if (found_linefeed) {
            text = (char*)__mbsinc((const unsigned char*)text);
        }
        goto next_line;

    append_all:
        this->append_line(text, 0);
        SelectObject((HDC)dc, (HGDIOBJ)old_font);
        this->render_area->ReleaseDc((char*)0x58547c);
        return 1;
    }
}

// PDB: Pnl_txt.cpp:566-570.
void TTextPanel::set_text(long id) {
    char buffer[0x1000];
    this->get_string(id, buffer, 0x1000);
    this->set_text(buffer);
}

// PDB: Pnl_txt.cpp:576-592.
void TTextPanel::set_text(char** texts, short count) {
    free_text();
    if (count == 0) {
        if (fixed_len != 0) {
            append_line("", 0);
        }
    }
    else if (count > 0) {
        int i = count;
        do {
            append_line(texts[0], 0);
            texts++;
            i--;
        } while (i != 0);
    }
}

// PDB: Pnl_txt.cpp:598-604.
void TTextPanel::set_font(void* param_1, long param_2, long param_3) {
    this->font = param_1;
    this->font_wid = param_2;
    this->font_hgt = param_3;
    this->calc_draw_info(1);
    this->set_redraw(1);
}

// PDB: Pnl_txt.cpp:610-614.
void TTextPanel::set_alignment(TTextPanel::Alignment a, TTextPanel::Alignment b) {
    this->vert_align = a;
    this->horz_align = b;
    this->set_redraw(1);
}

// PDB: Pnl_txt.cpp:620-623.
void TTextPanel::set_word_wrap(int value) {
    this->word_wrap = value;
    this->set_redraw(1);
}

// PDB: Pnl_txt.cpp:629-632.
void TTextPanel::set_style(TTextPanel::Style value) {
    this->text_style = value;
    this->set_redraw(1);
}

// PDB: Pnl_txt.cpp:638-642.
void TTextPanel::set_text_color(unsigned long a, unsigned long b) {
    this->text_color1 = a;
    this->text_color2 = b;
    this->set_redraw(1);
}

// PDB: Pnl_txt.cpp:648-652.
void TTextPanel::set_highlight_text_color(unsigned long a, unsigned long b) {
    this->highlight_text_color1 = a;
    this->highlight_text_color2 = b;
    this->set_redraw(1);
}

// PDB: Pnl_txt.cpp:658-661.
void TTextPanel::set_fill_back(int a, unsigned char b) {
    this->fill_back = a;
    this->back_color = b;
}

// PDB: Pnl_txt.cpp:667-685.
void TTextPanel::set_back_pic(char* name) {
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

    if (name == 0 || *name == '\0') {
        return;
    }

    this->back_pic = new TShape(name, -1);
    this->back_pic->shape_minmax(&x_max, &x_min, &y_max, &y_min, 0);
    this->back_pic_wid = (short)(y_max - x_max + 1);
    this->back_pic_hgt = (short)(y_min - x_min + 1);
}

// PDB: Pnl_txt.cpp:691-699.
void TTextPanel::set_outline(int outline, unsigned char color) {
    this->outline = outline;
    if (outline != 0) {
        this->bevel_type = 1;
    } else {
        this->bevel_type = 0;
    }
    this->outline_color = color;
    this->set_redraw(1);
}

// PDB: Pnl_txt.cpp:705-738.
void TTextPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6)
{
    bevel_type = type, bevel_color1 = (unsigned char)c1;
    bevel_color2 = (unsigned char)c2;
    bevel_color3 = (unsigned char)c3;
    bevel_color4 = (unsigned char)c4;
    bevel_color5 = (unsigned char)c5;
    bevel_color6 = (unsigned char)c6;

    switch (type) {
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

// PDB: Pnl_txt.cpp:744-747.
void TTextPanel::set_spacer_size(int size) {
    spacer_size = size;
    calc_draw_info(1);
}

// PDB: Pnl_txt.cpp:753-763.
void TTextPanel::set_active(int active) {
    TPanel::set_active(active);
    if (this->auto_scbar != 0 && this->scbar_panel != 0) {
        if (this->active != 0) {
            this->scbar_panel->set_active(this->scbar_active);
        }
        else {
            this->scbar_panel->set_active(0);
        }
    }
}

// PDB: Pnl_txt.cpp:769-833.
void TTextPanel::calc_draw_info(int recalc_scrollbar)
{
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
        this->draw_lines = (short)(available_height / line_height);
    }

    if (this->draw_lines < 1) {
        this->draw_lines = 1;
    }

    number_lines = this->num_lines;
    if (this->top_line >= number_lines) {
        this->top_line = number_lines - 1;
    }

    visible_lines = this->draw_lines;
    if ((int)number_lines - (int)this->top_line < (int)visible_lines) {
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
        if (recalc_scrollbar != 0) {
            this->scbar_panel->set_list_len(
                (int)number_lines - (int)visible_lines + 1,
                (int)this->top_line);
        }

        if (this->auto_scbar != 0) {
            if (this->num_lines > this->draw_lines) {
                if (this->scbar_active == 0) {
                    TPanel::set_rect(this->pnl_x, this->pnl_y,
                                     this->full_width - this->scbar_width,
                                     this->pnl_hgt);
                    this->scbar_active = 1;
                    if (this->active != 0) {
                        this->scbar_panel->set_active(1);
                        this->text_wid = this->pnl_wid;
                        return;
                    }
                }
            } else if (this->scbar_active != 0) {
                TPanel::set_rect(this->pnl_x, this->pnl_y,
                                 this->full_width, this->pnl_hgt);
                this->scbar_active = 0;
                if (this->active != 0) {
                    this->scbar_panel->set_active(0);
                }
            }
        }
    }

    this->text_wid = this->pnl_wid;
}

// PDB: Pnl_txt.cpp:839-878.
void TTextPanel::scroll(unsigned char scroll_type, short amount, int param_3)
{
    switch (scroll_type) {
    case 0:
        this->top_line += amount;
        break;
    case 1:
        this->top_line = amount;
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

    this->calc_draw_info(param_3);
    this->set_redraw(1);
}

// PDB: Pnl_txt.cpp:884-921.
long TTextPanel::key_down_action(long param_1, short param_2, int param_3,
                                 int param_4, int param_5)
{
    switch (param_1) {
    case 0x28:
        this->scroll(2, 0, 1);
        if (this->parent_panel != 0 && this->tab_stop != 0) {
            this->parent_panel->key_down_action(param_1, param_2, param_3,
                                                 param_4, param_5);
            return 1;
        }
        return 1;
    case 0x26:
        this->scroll(3, 0, 1);
        if (this->parent_panel != 0 && this->tab_stop != 0) {
            this->parent_panel->key_down_action(param_1, param_2, param_3,
                                                 param_4, param_5);
            return 1;
        }
        return 1;
    case 0x22:
        this->scroll(4, 0, 1);
        if (this->parent_panel != 0 && this->tab_stop != 0) {
            this->parent_panel->key_down_action(param_1, param_2, param_3,
                                                 param_4, param_5);
        }
        return 1;
    case 0x21:
        this->scroll(5, 0, 1);
        if (this->parent_panel != 0 && this->tab_stop != 0) {
            this->parent_panel->key_down_action(param_1, param_2, param_3,
                                                 param_4, param_5);
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

// PDB: Pnl_txt.cpp:927-955.
long TTextPanel::action(TPanel* panel, long msg, unsigned long p1, unsigned long p2)
{
    if (this->scbar_panel && panel == this->scbar_panel) {
        switch (msg) {
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
            this->scroll(1, p1, 0);
            return 1;
        }
    }
    return TPanel::action(panel, msg, p1, p2);
}

// PDB: Pnl_txt.cpp:961-1000.
void TTextPanel::draw()
{
    short line;
    short line_index = 0;
    HDC dc;
    void* old_font;

    this->need_redraw = 0;
    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        return;
    }

    this->draw_background();
    this->draw_setup(0);

    dc = this->render_area->GetDc(s_pnl_txt__draw);
    if (dc != 0) {
        SelectClipRgn(dc, this->clip_rgn);
        old_font = SelectObject(dc, this->font);
        SetBkMode(dc, 1);

        line = this->top_line;
        while (line <= this->bot_line) {
            if ((this->tab_stop != 0 && this->have_focus != 0) ||
                this->mouse_captured != 0) {
                this->draw_line(dc, line_index, line,
                                this->highlight_text_color1,
                                this->highlight_text_color2);
            } else {
                this->draw_line(dc, line_index, line,
                                this->text_color1, this->text_color2);
            }
            ++line;
            ++line_index;
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc(s_pnl_txt__draw);
    }

    this->draw_border();
    this->draw_finish();
}

// PDB: Pnl_txt.cpp:1006-1089.
void TTextPanel::draw_background()
{
    short pic_cols;
    short pic_rows = 0;

    if (this->back_pic != 0) {
        if (this->render_area->Lock("pnl_txt::draw_background", 1) == 0) {
            return;
        }

        if (this->back_pic_wid >= this->pnl_wid) {
            pic_cols = 1;
        } else {
            pic_cols = (short)(this->pnl_wid / this->back_pic_wid);
            if ((short)pic_cols * this->back_pic_wid < this->pnl_wid) {
                pic_cols++;
            }
        }

        if (this->back_pic_hgt >= this->pnl_hgt) {
            pic_rows = (short)(this->pnl_hgt / this->back_pic_hgt);
            if ((short)pic_rows * this->back_pic_hgt < this->pnl_hgt) {
                pic_rows++;
            }
        }

        if (pic_rows > 0) {
            int row = 0;
            int row_count = pic_rows;
            do {
                if (pic_cols > 0) {
                    int col = 0;
                    int col_count = (short)pic_cols;
                    do {
                        int draw_y = row * this->back_pic_hgt + this->pnl_y;
                        int draw_x = col * this->back_pic_wid + this->pnl_x;
                        this->back_pic->shape_draw(
                            this->render_area,
                            draw_x, draw_y,
                            0, 0, 0);
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
            this->pnl_x, this->pnl_y,
            this->pnl_x + this->pnl_wid - 1,
            this->pnl_y + this->pnl_hgt - 1,
            this->back_color);
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

// PDB: Pnl_txt.cpp:1095-1133.
void TTextPanel::draw_border()
{
    if (this->bevel_type != 0) {
        if (this->render_area->Lock("pnl_txt::draw_border", 1) != 0) {
            switch (this->bevel_type) {
            case 1:
                this->render_area->DrawRect(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->outline_color);
                break;
            case 2:
                this->render_area->DrawBevel(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color6, this->bevel_color1);
                break;
            case 3:
                this->render_area->DrawBevel2(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color6, this->bevel_color5,
                    this->bevel_color2, this->bevel_color1);
                break;
            case 4:
                this->render_area->DrawBevel3(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color6, this->bevel_color5,
                    this->bevel_color4, this->bevel_color3,
                    this->bevel_color2, this->bevel_color1);
                break;
            case 5:
                this->render_area->DrawBevel(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color1, this->bevel_color6);
                break;
            case 6:
                this->render_area->DrawBevel2(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color5, this->bevel_color6);
                break;
            case 7:
                this->render_area->DrawBevel3(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color3, this->bevel_color4,
                    this->bevel_color5, this->bevel_color6);
                break;
            }
        }
        this->render_area->Unlock("pnl_txt::draw_border");
    }
}

// PDB: Pnl_txt.cpp:1139-1229.
void TTextPanel::draw_line(void* dc, short line_index, short line,
                           unsigned long color1, unsigned long color2)
{
    char* text;
    char* text2;
    short text_len;
    short text2_len;
    DrawLineRect line_rect;
    TTextPanel* panel;

    line_rect.receiver = this;
    text_len = 0;
    text2_len = 0;
    text = this->get_text((long)line);
    text2 = this->get_text2((long)line);

    if (text == 0 && text2 == 0) {
        return;
    }

    if (text != 0) {
        text_len = (short)strlen(text);
    }

    if (text2 != 0) {
        text2_len = (short)strlen(text2);
    }

    this->calc_line_pos(dc, line_index, line, &line_rect.rect, 0);

    long text_x = line_rect.rect.left;
    if (this->horz_align != 0 && this->horz_align != 6) {
        text_x += 5;
    }
    long second_text_x = this->second_column_pos + text_x;
    long text_y = line_rect.rect.top;

    if (this->clip_rgn2 != 0) {
        SelectClipRgn(dc, this->clip_rgn2);
    }

    switch (this->text_style) {
    case 0:
        SetTextColor(dc, color1);
        if (text != 0) {
            TextOutA(dc, text_x, text_y, text, (int)text_len);
        }
        break;
    case 1:
        SetTextColor(dc, color1);
        if (text != 0) {
            TextOutA(dc, text_x - 1, text_y + 1,
                     text, (int)text_len);
        }
        SetTextColor(dc, color2);
        if (text != 0) {
            TextOutA(dc, text_x, text_y, text, (int)text_len);
        }
        break;
    case 2:
        SetTextColor(dc, color2);
        if (text != 0) {
            TextOutA(dc, text_x - 1, text_y + 1,
                     text, (int)text_len);
        }
        SetTextColor(dc, color1);
        if (text != 0) {
            TextOutA(dc, text_x, text_y, text, (int)text_len);
        }
        break;
    default:
        break;
    }

    if (text2 == 0) {
        return;
    }

    panel = line_rect.receiver;
    if (panel->clip_rgn2 != 0) {
        SelectClipRgn(dc, panel->clip_rgn);
    }

    switch (panel->text_style) {
    case 0:
        SetTextColor(dc, color1);
        TextOutA(dc, second_text_x, text_y,
                 text2, (int)text2_len);
        return;
    case 1:
        SetTextColor(dc, color1);
        TextOutA(dc, second_text_x - 1, text_y + 1,
                 text2, (int)text2_len);
        SetTextColor(dc, color2);
        TextOutA(dc, second_text_x, text_y,
                 text2, (int)text2_len);
        return;
    case 2:
        SetTextColor(dc, color2);
        TextOutA(dc, second_text_x - 1, text_y + 1,
                 text2, (int)text2_len);
        SetTextColor(dc, color1);
        TextOutA(dc, second_text_x, text_y,
                 text2, (int)text2_len);
        return;
    default:
        return;
    }
}

// PDB: Pnl_txt.cpp:1235-1346.
void TTextPanel::calc_line_pos(void* dc, short line, short current,
                               RECT* rect, long* out)
{
    char* text = this->get_text((long)current);
    long col_offset;
    SIZE text_size;
    char temp_text2[256];
    short byte_len;

    if (text != 0) {
        if (this->cur_col == 0) {
            col_offset = 0;
        } else {
            short text_len = __mbslen(text);
            if (this->cur_col > text_len) {
                byte_len = (short)strlen(text);
                GetTextExtentPoint32A(dc, text, byte_len, &text_size);
            } else {
                memset(temp_text2, 0, 0x100);
                __mbsncpy((unsigned char*)temp_text2,
                          (const unsigned char*)text,
                          (unsigned int)this->cur_col);
                byte_len = (short)strlen(temp_text2);
                GetTextExtentPoint32A(dc, text, byte_len, &text_size);
            }
            col_offset = text_size.cx;
        }

        // This call is present in the original line-measurement path even
        // though the following byte-length expression supplies the count.
        __mbslen(text);
        byte_len = (short)strlen(text);
        GetTextExtentPoint32A(dc, text, byte_len, &text_size);
    } else {
        col_offset = 0;
        text_size.cx = 0;
    }

    long horizontal = this->horz_align;
    if (horizontal != 0 && horizontal != 6) {
        col_offset += 5;
    }

    long x;
    switch (horizontal) {
    case 1:
        x = this->pnl_x + this->border_size;
        break;
    case 2:
        x = this->pnl_x + this->pnl_wid - this->border_size
            - text_size.cx - 7;
        break;
    case 5:
        x = this->pnl_x + this->border_size;
        if (col_offset + 1 >= this->pnl_wid) {
            x += this->pnl_wid - col_offset - 2;
        }
        break;
    default:
        x = this->pnl_x + this->pnl_wid / 2 - text_size.cx / 2;
        break;
    }

    long row_size = this->spacer_size;
    if (row_size == 0) {
        row_size = this->text_hgt;
    } else {
        row_size = this->text_hgt + row_size * 2 - 1;
    }

    long y;
    switch (this->vert_align) {
    case 3:
        y = line * row_size + this->pnl_y + this->border_size
            + this->spacer_size;
        break;
    case 4:
        y = this->pnl_y - (this->num_lines - line) * row_size;
        y += this->pnl_hgt - this->border_size - this->spacer_size - 1;
        break;
    default:
        y = line * row_size - (this->num_lines * row_size) / 2
            + this->pnl_y + this->pnl_hgt / 2;
        break;
    }

    rect->left = x;
    rect->top = y;
    rect->right = x - 1 + text_size.cx;
    rect->bottom = y + this->text_hgt;
    if (out != 0) {
        *out = col_offset;
    }
}

// PDB: Pnl_txt.cpp:1352-1356.
long TTextPanel::mouse_left_down_action(long x, long y, int buttons, int keys) {
    if (this->parent_panel != 0) {
        this->parent_panel->action(this, 1, 0, 0);
    }
    return 0;
}

// PDB: Pnl_txt.cpp:1361-1363.
int TTextPanel::numberLines() const {
    return num_lines;
}

// PDB: Pnl_txt.cpp:1368-1370.
int TTextPanel::numberDrawLines() const {
    return draw_lines;
}

// PDB: Pnl_txt.cpp:1375-1377.
int TTextPanel::currentLineNumber() const {
    return cur_line;
}

// PDB: Pnl_txt.cpp:1382-1384.
void TTextPanel::setCurrentLineNumber(int p) { this->set_line(p); }

// PDB: Pnl_txt.cpp:1389-1389.
char* TTextPanel::currentLine() { return this->get_text(); }

// PDB: Pnl_txt.cpp:1399-1402.
void TTextPanel::set_line(long line) {
    cur_line = (short)line;
    calc_draw_info(1);
}

// PDB: Pnl_txt.cpp:1408-1418.
void TTextPanel::set_line_by_id(long id) {
    int index = 0;
    void** node = (void**)this->list;

    if (node == 0)
        return;

    while (node) {
        if ((long)node[2] == id) {
            this->set_line(index);
            return;
        }
        node = (void**)node[3];
        index++;
    }
}

// PDB: Pnl_txt.cpp:1424-1426.
int TTextPanel::append_line(char* text, long value) {
    return insert_line((int)num_lines, text, value);
}

// PDB: Pnl_txt.cpp:1432-1434.
int TTextPanel::append_line(char* text1, char* text2, long value) {
    return insert_line((int)num_lines, text1, text2, value);
}

// PDB: Pnl_txt.cpp:1440-1442.
int TTextPanel::append_line(long a1, long a2) {
    return insert_line((int)num_lines, a1, a2);
}

// PDB: Pnl_txt.cpp:1448-1450.
int TTextPanel::append_line(long a1, long a2, long a3) {
    return insert_line((int)num_lines, a1, a2, a3);
}

// PDB: Pnl_txt.cpp:1456-1458.
int TTextPanel::insert_line(long line, char* text1, long value) {
    return insert_line(line, text1, 0, value);
}

// PDB: Pnl_txt.cpp:1464-1582.
int TTextPanel::insert_line(long line, char* text, char* text2, long value)
{
    int i;
    TextNode* previous;
    TextNode* node = (TextNode*)calloc(1, sizeof(TextNode));
    if (node == 0) {
        return 0;
    }

    if (this->fixed_len != 0) {
        node->text = (char*)calloc((int)this->fixed_len + 1, 1);
    } else if (text == 0) {
        node->text = (char*)calloc(1, 1);
    } else {
        node->text = (char*)calloc(strlen(text) + 1, 1);
    }

    if (node->text == 0) {
        free(node);
        return 0;
    }

    if (text2 != 0) {
        node->text2 = (char*)calloc(strlen(text2) + 1, 1);
        if (node->text2 == 0) {
            free(node->text);
            free(node);
            return 0;
        }
    }

    if (text == 0) {
        node->text[0] = '\0';
    } else if (this->fixed_len != 0) {
        strncpy(node->text, text, (int)this->fixed_len);
        node->text[(short)this->fixed_len] = '\0';
    } else {
        strcpy(node->text, text);
    }

    if (text2 != 0) {
        strcpy(node->text2, text2);
    }

    node->id = value;
    i = 0;
    node->next_node = 0;

    TextNode* list_node = this->list;
    if (list_node == 0) {
        this->list = node;
    } else if (this->sorted != 0) {
        TextNode* current = list_node;
        previous = 0;
        while (current != 0) {
            int result = CompareStringA(0x400, 1,
                                        node->text, -1,
                                        current->text, -1);
            if (result == 1) {
                node->next_node = current;
                if (previous != 0) {
                    previous->next_node = node;
                } else {
                    this->list = node;
                }
                break;
            }
            previous = current;
            current = current->next_node;
        }
        if (current == 0) {
            previous->next_node = node;
        }
    } else {
        if (line == 0) {
            node->next_node = list_node;
            this->list = node;
        } else if (line < this->num_lines) {
            --line;
            while (i != line) {
                list_node = list_node->next_node;
                i++;
            }
            node->next_node = list_node->next_node;
            list_node->next_node = node;
        } else {
            while (list_node->next_node != 0) {
                list_node = list_node->next_node;
            }
            list_node->next_node = node;
        }
    }

    this->num_lines++;
    this->calc_draw_info(1);
    this->set_redraw(1);
    return 1;
}

// PDB: Pnl_txt.cpp:1588-1592.
int TTextPanel::insert_line(long line, long text, long value)
{
    char str[256];

    get_string((int)text, str, 0x100);
    return insert_line(line, str, value);
}

// PDB: Pnl_txt.cpp:1598-1606.
int TTextPanel::insert_line(long param_1, long param_2, long param_3, long param_4) {
    char str1[256];
    char str2[256];

    this->get_string(param_2, str1, 0x100);
    this->get_string(param_3, str2, 0x100);
    return this->insert_line(param_1, str1, str2, param_4);
}

// PDB: Pnl_txt.cpp:1612-1628.
int TTextPanel::change_line(long param_1, char* param_2, char* param_3, long param_4) {
    int iVar1;
    int iVar2;

    iVar1 = this->sorted;
    this->sorted = 0;
    iVar2 = insert_line(param_1, param_2, param_3, param_4);
    if (iVar2 == 0) {
        this->sorted = iVar1;
        return 0;
    }

    delete_line(param_1 + 1);
    this->sorted = iVar1;
    return 1;
}

// PDB: Pnl_txt.cpp:1634-1650.
int TTextPanel::change_line(long a1, long a2, long a3, long a4) {
    int saved_sorted = this->sorted;
    this->sorted = 0;

    if (insert_line(a1, a2, a3, a4) == 0) {
        this->sorted = saved_sorted;
        return 0;
    }

    delete_line(a1 + 1);
    this->sorted = saved_sorted;
    return 1;
}

// PDB: Pnl_txt.cpp:1656-1710.
int TTextPanel::delete_line(long line)
{
    if (line >= 0 && line <= this->num_lines - 1) {
        TextNode* deleted;

        if (line == 0) {
            deleted = this->list;
            this->list = deleted->next_node;
        } else {
            TextNode* node = this->list;
            int i = 0;
            --line;
            while (true) {
                if (i == line) {
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
            this->set_redraw(1);
            return 1;
        }
    }
    return 0;
}

// PDB: Pnl_txt.cpp:1716-1721.
long TTextPanel::get_line() {
    if (num_lines == 0) {
        return -1;
    }
    return cur_line;
}

// PDB: Pnl_txt.cpp:1727-1740.
long TTextPanel::get_line(long index) {
    TextNode* node = this->list;
    int i = 0;
    while (node != 0) {
        if (node->id == index) {
            return i;
        }
        node = node->next_node;
        ++i;
    }
    return -1;
}

// PDB: Pnl_txt.cpp:1746-1760.
long TTextPanel::get_line(char* s) {
    TextNode* node = this->list;
    long i = 0;
    while (node != 0) {
        if (strcmp(node->text, s) == 0) return i;
        node = node->next_node;
        ++i;
    }
    return -1;
}

// PDB: Pnl_txt.cpp:1766-1768.
char* TTextPanel::get_text() {
    return this->get_text(this->cur_line);
}

// PDB: Pnl_txt.cpp:1774-1790.
char* TTextPanel::get_text(long index) {
    TextNode* node = this->list;
    long i = 0;
    if (node == 0) {
        DAT_0086B250 = 0;
        return &DAT_0086B250;
    }
    while (node != 0) {
        if (index == i) {
            return node->text;
        }
        node = node->next_node;
        i++;
    }
    DAT_0086B250 = 0;
    return &DAT_0086B250;
}

// PDB: Pnl_txt.cpp:1796-1798.
char* TTextPanel::get_text2() {
    return this->get_text2(this->cur_line);
}

// PDB: Pnl_txt.cpp:1804-1820.
char* TTextPanel::get_text2(long index) {
    long i;
    TextNode* node;

    i = 0;
    node = this->list;
    if (node == 0) {
        DAT_0086b24c = 0;
        return (char*)&DAT_0086b24c;
    }
    while (node != 0) {
        if (i == index) return node->text2;
        node = node->next_node;
        i++;
    }
    DAT_0086b24c = 0;
    return (char*)&DAT_0086b24c;
}

// PDB: Pnl_txt.cpp:1826-1828.
long TTextPanel::get_id() {
    return this->get_id(this->cur_line);
}

// PDB: Pnl_txt.cpp:1834-1848.
long TTextPanel::get_id(long index) {
    long count = 0;
    long target = index;
    TextNode* node = this->list;

    if (node == 0) return -1;

    while (node != 0) {
        if (count == target) {
            return node->id;
        }
        node = node->next_node;
        count++;
    }
    return -1;
}

// PDB: Pnl_txt.cpp:1854-1854.
void TTextPanel::empty_list() { this->free_text(); }

// PDB: Pnl_txt.cpp:1862-1886.
void TTextPanel::free_text(void) {
    TextNode* node = this->list;
    if (node != 0) {
        do {
            if (node->text != 0) {
                free(node->text);
            }
            if (node->text2 != 0) {
                free(node->text2);
            }
            TextNode* old = node;
            node = node->next_node;
            free(old);
        } while (node != 0);
        this->list = 0;
    }
    this->num_lines = 0;
    this->calc_draw_info(1);
    this->set_redraw(1);
}

// PDB: Pnl_txt.cpp:1892-1895.
void TTextPanel::set_second_column_pos(long value) {
    this->second_column_pos = value;
    this->set_redraw(1);
}

// PDB: Pnl_txt.cpp:1901-1916.
int TTextPanel::get_text_rect(RECT* rect) {
    void* dc = this->render_area->GetDc(s_pnl_txt__get_text_rect);
    if (dc != 0) {
        SelectObjectFn select_object = SelectObject;
        void* old_font = select_object(dc, this->font);
        this->calc_line_pos(dc, 0, 0, rect, 0);
        select_object(dc, old_font);
        this->render_area->ReleaseDc(s_pnl_txt__get_text_rect);
        return 1;
    }
    return 0;
}
