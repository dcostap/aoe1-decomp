#include "../include/Pnl_inp.h"

#include <mbstring.h>
extern void operator delete(void*);
extern char pnl_inp_draw[];

TInputPanel::TInputPanel() : TTextPanel(), caret_color(0),
                             caret_interval(GetCaretBlinkTime()),
                             caret_last_time(0), draw_caret(1),
                             overLengthSound(0), input_buffer(0),
                             input_buffer1(0), input_buffer2(0),
                             input_len(0), max_len(0), insert_mode(1),
                             input_pos(0) {
    this->handle_mouse_input = 1;
    this->bevel_type = 1;
    this->panel_type = 7;
    this->horz_align = TTextPanel::AlignHorizontalScroll;
}

TInputPanel::~TInputPanel() {
    if (this->input_buffer1 != 0) {
        delete this->input_buffer1;
        this->input_buffer1 = 0;
    }
    if (this->input_buffer2 != 0) {
        delete this->input_buffer2;
        this->input_buffer2 = 0;
    }
    this->input_buffer = 0;
    this->handle_mouse_input = 1;
}

long TInputPanel::setup(TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in,
                        long wid_in, long hgt_in, void* font_in, long font_wid_in, long font_hgt_in,
                        char* back_pic_in, int fill_back_in, unsigned char back_color_in, int outline_in,
                        unsigned char outline_color_in, unsigned char caret_color_in,
                        short max_len_in, TDigital* overLengthSoundIn,
                        char* text_in, FormatType format_type_in) {
    long setup_max = (format_type_in == FormatMultiLine) ? 0 : max_len_in;
    if (TTextPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, font_in, font_wid_in, font_hgt_in, back_pic_in,
                          fill_back_in, back_color_in, outline_in, outline_color_in, setup_max, (char*)0) == 0) {
        return 0;
    }
    this->caret_color = caret_color_in;
    this->format_type = format_type_in;
    if (this->have_focus != 0) {
        this->draw_caret = 1;
        this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 89);
    }
    if (max_len_in != 0)
        this->overLengthSound = overLengthSoundIn;
    else
        this->overLengthSound = 0;
    if (this->format_type == FormatMultiLine) {
        this->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignLeft);
        this->set_word_wrap(1);
    } else {
        this->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignHorizontalScroll);
    }
    this->input_buffer1 = (char*)calloc((unsigned int)((int)max_len_in + (int)max_len_in + 1), 1);
    if (this->input_buffer1 == 0) return 0;
    this->input_buffer2 = (char*)calloc((unsigned int)((int)max_len_in + (int)max_len_in + 1), 1);
    if (this->input_buffer2 == 0) return 0;
    this->input_buffer = this->input_buffer1;
    this->set_text(text_in);
    this->max_len = max_len_in;
    this->reformat();
    return 1;
}

void TInputPanel::set_focus(int have_focus_in) {
    TPanel::set_focus(have_focus_in);
    if (this->have_focus != 0) {
        this->draw_caret = 1;
        this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 137);
    }
}

void TInputPanel::set_format(FormatType format_type_in) {
    this->format_type = format_type_in;
}

long TInputPanel::handle_idle() {
    if (this->have_focus != 0) {
        unsigned long now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 158);
        if ((now - this->caret_last_time) >= this->caret_interval) {
            this->draw_caret = (this->draw_caret == 0) ? 1 : 0;
            this->set_redraw(TPanel::RedrawNormal);
            now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 163);
            this->caret_last_time = now;
        }
    }
    return TPanel::handle_idle();
}

long TInputPanel::char_action(long key, short count) {
    short i;
    if (key == 8 || key == 9 || key == 10 || key == 13 || key == 27 || key < 0x1B)
        return 1;
    if (count == 0) count = 1;
    i = 0;
    if (count <= 0) return 1;
    while (i < count) {
        switch (this->format_type) {
        case FormatPercent:
            if (_mbslen((const unsigned char*)this->get_text()) < 2 && key >= '0' && key <= '9') break;
            if (_mbslen((const unsigned char*)this->get_text()) != 2 || key != '0' ||
                _mbscmp((const unsigned char*)"10", (const unsigned char*)this->get_text()) != 0) {
                if (this->overLengthSound != 0) this->overLengthSound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case FormatNumber:
        case FormatInteger:
        case FormatUnsignedInt:
            if (key >= '0' && key <= '9') break;
            if (key == '-' && this->input_buffer[0] == 0 && this->format_type != FormatUnsignedInt) break;
            if (key == '.' && _mbschr((const unsigned char*)this->input_buffer, key) != 0 && this->format_type == FormatNumber) break;
            if (this->overLengthSound != 0) this->overLengthSound->play();
            else MessageBeep(0xFFFFFFFF);
            return 1;
        case FormatFile:
        case FormatFileNoExt:
            if (key == '.') {
                if (this->format_type == FormatFile && _mbschr((const unsigned char*)this->input_buffer, key) == 0) break;
            }
            if (key == '.' || key == '\\' || key == ':' || key == '/' || key == '"' || key == '*' || key == '?' || key == '>' || key == '<' || key == '|') {
                if (this->overLengthSound != 0) this->overLengthSound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case FormatPath:
            if ((key == ':' && this->input_len != 1) || key == '/' || key == '"' || key == '*' || key == '?' || key == '>' || key == '<' || key == '|') {
                if (this->overLengthSound != 0) this->overLengthSound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case FormatSingleLine:
        case FormatMultiLine:
            break;
        }
        if (this->insert_character(key) == 0) return 1;
        ++i;
    }
    return 1;
}

long TInputPanel::key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key) {
    short line_len;
    short column;

    switch (key) {
    case VK_LEFT:
        if (this->num_lines < 1) return 1;
        if (this->cur_col > 0) {
            this->cur_col--;
        } else {
            if (this->cur_line <= 0) break;
            this->cur_line--;
            this->cur_col = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        }
        this->calc_input_pos();
        this->set_redraw(TPanel::RedrawNormal);
        break;

    case VK_RIGHT:
        if (this->num_lines < 1) return 1;
        column = this->cur_col;
        line_len = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        if (column < line_len) {
            this->cur_col = column + 1;
        } else {
            if (this->cur_line >= this->num_lines - 1) break;
            this->cur_line++;
            this->cur_col = 0;
        }
        this->calc_input_pos();
        this->set_redraw(TPanel::RedrawNormal);
        break;

    case VK_UP:
        if (this->num_lines < 1) return 1;
        if (this->cur_line <= 0) break;
        this->cur_line--;
        line_len = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        if (this->cur_col > line_len) {
            this->cur_col = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        }
        this->calc_input_pos();
        this->set_redraw(TPanel::RedrawNormal);
        break;

    case VK_DOWN:
        if (this->num_lines < 1) return 1;
        if (this->cur_line >= this->num_lines - 1) break;
        this->cur_line++;
        line_len = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        if (this->cur_col > line_len) {
            this->cur_col = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        }
        this->calc_input_pos();
        this->set_redraw(TPanel::RedrawNormal);
        break;

    case VK_HOME:
        if (this->num_lines < 1) return 1;
        if (ctrl_key != 0) {
            if (this->cur_col == 0 && this->cur_line == 0) break;
            this->cur_col = 0;
            this->cur_line = 0;
            this->calc_input_pos();
            this->set_redraw(TPanel::RedrawNormal);
            break;
        }
        if (this->cur_col == 0) break;
        this->cur_col = 0;
        this->set_redraw(TPanel::RedrawNormal);
        this->calc_input_pos();
        break;

    case VK_END:
        if (this->num_lines < 1) return 1;
        if (ctrl_key != 0) {
            if (this->cur_line == this->num_lines - 1) {
                line_len = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
                if (this->cur_col == line_len) break;
            }
            this->cur_line = this->num_lines - 1;
        } else {
            line_len = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
            if (this->cur_col == line_len) break;
        }
        this->cur_col = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        this->set_redraw(TPanel::RedrawNormal);
        this->calc_input_pos();
        break;

    case VK_PRIOR:
        if (this->num_lines < 1) return 1;
        if (this->cur_line <= 0) break;
        if (this->cur_line < this->top_line || this->cur_line > this->bot_line) {
            this->cur_line = this->top_line;
        }
        if (this->cur_line == this->top_line) {
            this->scroll(5, 0, 1);
        }
        this->cur_line = this->top_line;
        line_len = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        if (this->cur_col > line_len) {
            this->cur_col = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        }
        this->calc_input_pos();
        this->set_redraw(TPanel::RedrawNormal);
        break;

    case VK_NEXT:
        if (this->num_lines < 1) return 1;
        if (this->cur_line >= this->num_lines - 1) break;
        if (this->cur_line < this->top_line || this->cur_line > this->bot_line) {
            this->cur_line = this->bot_line;
        }
        if (this->cur_line == this->bot_line) {
            this->scroll(4, 0, 1);
        }
        this->cur_line = this->bot_line;
        line_len = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        if (this->cur_col > line_len) {
            this->cur_col = (short)_mbslen((const unsigned char*)this->get_text(this->cur_line));
        }
        this->calc_input_pos();
        this->set_redraw(TPanel::RedrawNormal);
        break;

    case VK_DELETE:
        this->delete_character();
        break;

    case VK_INSERT:
        if (shift_key != 0) {
            this->paste();
        } else if (ctrl_key == 0) {
            this->insert_mode = (this->insert_mode == 0);
        }
        break;

    case VK_BACK:
        this->backspace_character();
        break;

    case VK_RETURN:
        if (this->format_type == FormatMultiLine) {
            this->insert_character(10);
        } else if (this->parent_panel != 0) {
            this->parent_panel->action(this, 0, 0, 0);
        }
        break;

    case VK_ESCAPE:
        if (this->parent_panel != 0) {
            this->parent_panel->action(this, 1, 0, 0);
        }
        break;

    case 0x56:
        if (ctrl_key == 0) return 0;
        this->paste();
        break;

    default:
        return 0;
    }

    return 1;
}

void TInputPanel::draw() {
    TTextPanel::draw();
    if (this->render_area == 0) return;
    if (this->visible == 0) return;
    if (this->active == 0) return;
    if (this->have_focus == 0) return;
    if (this->draw_caret == 0) return;
    if (this->cur_line < this->top_line) return;
    if (this->cur_line > this->bot_line) return;

    this->draw_setup(0);
    void* dc = this->render_area->GetDc(pnl_inp_draw);
    if (dc != 0) {
        void* (__stdcall *select_object)(void*, void*) = SelectObject;
        void* old_font = select_object(dc, this->font);
        tagRECT line_rect;
        long cursor_x_offset;
        short cur = this->cur_line;
        short diff = cur - this->top_line;
        this->calc_line_pos(dc, diff, cur, &line_rect, &cursor_x_offset);
        select_object(dc, old_font);
        this->render_area->ReleaseDc(pnl_inp_draw);
        unsigned char* locked = this->render_area->Lock(pnl_inp_draw, 1);
        if (locked != 0) {
            int x = cursor_x_offset + line_rect.left;
            int y = line_rect.top;
            int h = (line_rect.bottom - line_rect.top) + 1;
            if (x < this->render_rect.right) {
                this->render_area->DrawVertLine(x, y, h, this->caret_color);
                this->render_area->DrawVertLine(x + 1, y, h, this->caret_color);
            }
            this->render_area->Unlock(pnl_inp_draw);
        }
    }
    this->draw_finish();
}

void TInputPanel::set_text(char* text_in) {
    char* buf = this->input_buffer;
    if (buf != 0) {
        if (text_in == 0) *buf = 0;
        else _mbscpy((unsigned char*)buf, (const unsigned char*)text_in);
        short len = _mbslen((const unsigned char*)this->input_buffer);
        this->input_len = len;
        this->input_pos = 0;
        this->cur_line = 0;
        this->cur_col = 0;
        if (this->format_type != FormatMultiLine && len > 0) {
            this->input_pos = len;
            this->cur_col = len;
        }
        this->reformat();
    }
}

void TInputPanel::set_text(char** text_in, short num_lines_in) {
}

char* TInputPanel::get_input_buffer() {
    return this->input_buffer;
}

int TInputPanel::append_character(long c) {
    this->input_pos = this->input_len;
    return this->insert_character(c);
}

int TInputPanel::insert_character(long c) {
    if (this->input_len >= this->max_len) {
        if (this->overLengthSound != 0) this->overLengthSound->play();
        else MessageBeep(0xFFFFFFFF);
        return 0;
    }

    char* src_buffer;
    char* dst_buffer;
    if (this->input_buffer == this->input_buffer1) {
        src_buffer = this->input_buffer1;
        dst_buffer = this->input_buffer2;
    } else {
        src_buffer = this->input_buffer2;
        dst_buffer = this->input_buffer1;
    }
    this->input_buffer = dst_buffer;
    *dst_buffer = 0;
    if (this->input_pos > 0) {
        _mbsncpy((unsigned char*)dst_buffer, (const unsigned char*)src_buffer, this->input_pos);
        src_buffer = (char*)_mbsninc((const unsigned char*)src_buffer, this->input_pos);
        dst_buffer = (char*)_mbsninc((const unsigned char*)dst_buffer, this->input_pos);
    }
    _mbsncpy((unsigned char*)dst_buffer, (const unsigned char*)&c, 1);
    dst_buffer = (char*)_mbsinc((const unsigned char*)dst_buffer);
    _mbsncpy((unsigned char*)dst_buffer, (const unsigned char*)src_buffer, this->input_len - this->input_pos + 1);
    this->input_len++;
    this->input_pos++;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 655);
    return 1;
}

int TInputPanel::delete_character() {
    short deleted_len;
    unsigned char* delete_position;
    unsigned char* next_position;
    unsigned char* source_position;
    int move_back_one;
    unsigned char* cur_dest;
    if (this->input_pos >= this->input_len) return 0;
    next_position = (unsigned char*)this->input_buffer1;
    move_back_one = 0;
    if (this->input_buffer == (char*)next_position) {
        source_position = next_position;
        next_position = (unsigned char*)this->input_buffer2;
    } else {
        source_position = (unsigned char*)this->input_buffer2;
    }
    this->input_buffer = (char*)next_position;
    *next_position = 0;
    delete_position = source_position;
    cur_dest = next_position;
    if (this->input_pos > 0) {
        _mbsncpy(next_position, source_position, (int)this->input_pos);
        delete_position = (unsigned char*)_mbsninc(source_position, (int)this->input_pos);
        cur_dest = (unsigned char*)_mbsninc(next_position, (int)this->input_pos);
    }
    if (*delete_position == '\r') {
        next_position = (unsigned char*)_mbsinc(delete_position);
        deleted_len = 1;
        if (*next_position == '\n') {
            next_position = (unsigned char*)_mbsinc(next_position);
            deleted_len = 2;
        }
    } else {
        if ((*delete_position == '\n') && (delete_position > source_position)) {
            source_position = (unsigned char*)_mbsdec(source_position, delete_position);
            if (*source_position == '\r') {
                cur_dest = (unsigned char*)_mbsdec(next_position, cur_dest);
                next_position = (unsigned char*)_mbsninc(source_position, 2);
                deleted_len = 2;
                move_back_one = 1;
                goto do_copy;
            }
            next_position = (unsigned char*)_mbsninc(source_position, 2);
        } else {
            next_position = (unsigned char*)_mbsinc(delete_position);
        }
        deleted_len = 1;
    }
do_copy:
    _mbsncpy(cur_dest, next_position, ((int)this->input_len - (int)this->input_pos) + 1);
    if (move_back_one) --this->input_pos;
    this->input_len -= deleted_len;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 758);
    return 1;
}

int TInputPanel::backspace_character() {
    if (this->input_pos > 0) {
        this->input_pos = this->input_pos - 1;
        return this->delete_character();
    }
    return 0;
}

int TInputPanel::paste() {
    int len;
    HANDLE data_handle;
    char* locked;
    char* old_str;
    char* new_cur;
    char* old_tail;
    char* dst_tail;
    char new_str[0x1000];
    len = 0;
    new_str[0] = 0;
    if (!IsClipboardFormatAvailable(CF_TEXT)) return 0;
    if (!OpenClipboard(this->render_area->Wnd)) return 0;
    data_handle = GetClipboardData(CF_TEXT);
    if (data_handle != 0) {
        locked = (char*)GlobalLock(data_handle);
        if (locked != 0) {
            len = _mbslen((const unsigned char*)locked);
            if (len > 0xfff) len = 0xfff;
            for (int i = 0; i < 0x1000; ++i) new_str[i] = 0;
            _mbsncpy((unsigned char*)new_str, (const unsigned char*)locked, len);
            GlobalUnlock(data_handle);
        }
    }
    CloseClipboard();
    {
        int total_len;
        int max_len;
        total_len = len;
        total_len += this->input_len;
        max_len = this->max_len;
        if (total_len >= max_len) {
            if (this->overLengthSound != 0) {
                this->overLengthSound->play();
                return 0;
            }
            MessageBeep(0xffffffff);
            return 0;
        }
    }
    new_cur = this->input_buffer1;
    if (this->input_buffer == new_cur) {
        old_str = new_cur;
        new_cur = this->input_buffer2;
    } else {
        old_str = this->input_buffer2;
    }
    this->input_buffer = new_cur;
    *new_cur = 0;
    _mbsncpy((unsigned char*)new_cur, (const unsigned char*)old_str, (int)this->input_pos);
    old_tail = (char*)_mbsninc((const unsigned char*)old_str, (int)this->input_pos);
    dst_tail = new_cur;
    dst_tail = (char*)_mbsninc((const unsigned char*)dst_tail, (int)this->input_pos);
    _mbsncpy((unsigned char*)dst_tail, (const unsigned char*)new_str, len);
    dst_tail = (char*)_mbsninc((const unsigned char*)dst_tail, len);
    _mbsncpy((unsigned char*)dst_tail, (const unsigned char*)old_tail, ((int)this->input_len - (int)this->input_pos) + 1);
    this->input_len += (short)len;
    this->input_pos += (short)len;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 866);
    return 1;
}

void TInputPanel::reformat() {
    short top = this->top_line;
    short cur = this->cur_line;
    TTextPanel::set_text(this->input_buffer);
    short n = this->num_lines;
    if (cur >= n) cur = n - 1;
    this->cur_line = cur;
    if (top >= n) this->top_line = n - 1;
    this->scroll(1, top, 1);
    this->set_redraw(TPanel::RedrawNormal);
}

void TInputPanel::calc_input_pos() {
    TTextPanel::TextNode* node;
    short i;
    short len;
    node = this->list;
    this->input_pos = 0;
    for (i = 0; node != 0 && i < this->cur_line; i++) {
        len = _mbslen((const unsigned char*)node->text);
        this->input_pos = this->input_pos + len;
        node = node->next_node;
    }
    short col = this->cur_col;
    this->input_pos = this->input_pos + col;
    short pos = this->input_pos;
    if (col > 0 && pos > 0) {
        if (this->input_buffer[pos - 1] == '\n') {
            this->input_pos = pos - 1;
            this->cur_col = col - 1;
        }
    }
    short col2 = this->cur_col;
    if (col2 > 0) {
        short pos2 = this->input_pos;
        if (pos2 > 0 && this->input_buffer[pos2 - 1] == '\r') {
            this->input_pos = pos2 - 1;
            this->cur_col = col2 - 1;
        }
    }
    if (this->cur_line < this->top_line) {
        do { this->scroll(3, 1, 1); } while (this->cur_line < this->top_line);
    }
    if (this->cur_line > this->bot_line) {
        do { this->scroll(2, 1, 1); } while (this->cur_line > this->bot_line);
    }
}

void TInputPanel::calc_cur_line_col() {
    TTextPanel::TextNode* node;
    short offset;
    short len;
    node = this->list;
    this->cur_line = 0;
    this->cur_col = 0;
    offset = 0;
    while (node != 0 && this->cur_line != this->num_lines - 1) {
        len = _mbslen((const unsigned char*)node->text);
        if (offset + len > this->input_pos) break;
        offset += len;
        this->cur_line++;
        node = node->next_node;
    }
    this->cur_col = this->input_pos - offset;
    if (this->cur_col > 0 && this->input_pos > 0 && this->input_buffer[this->input_pos - 1] == '\n') {
        this->input_pos--;
        this->cur_col--;
    }
    if (this->cur_col > 0 && this->input_pos > 0 && this->input_buffer[this->input_pos - 1] == '\r') {
        this->input_pos--;
        this->cur_col--;
    }
    if (this->cur_line < this->top_line) {
        do { this->scroll(3, 1, 1); } while (this->cur_line < this->top_line);
    }
    if (this->cur_line > this->bot_line) {
        do { this->scroll(2, 1, 1); } while (this->cur_line > this->bot_line);
    }
}

int TInputPanel::is_blank() {
    char* p = this->currentLine();
    if (p == 0) goto blank;
    if (*p == 0) goto blank;
    while (1) {
        if (*p == '\0') goto blank;
        if (_ismbcspace((unsigned char)*p) == 0) return 0;
        p = (char*)_mbsinc((const unsigned char*)p);
    }
blank:
    return 1;
}

char* TInputPanel::get_trimmed_str(char* str, int str_len) {
    char temp_str[256];
    unsigned char* base;
    unsigned char* p;
    unsigned char* cur;
    memset(temp_str, 0, sizeof(temp_str));
    strcpy(temp_str, this->currentLine());
    memset(str, 0, str_len);
    base = (unsigned char*)str;
    p = base;
    cur = (unsigned char*)temp_str;
    while (_ismbcspace(*cur & 0xFF)) cur = (unsigned char*)_mbsinc(cur);
    while (*cur) {
        _mbsncpy(p, cur, 1);
        p = (unsigned char*)_mbsinc((const unsigned char*)p);
        cur = (unsigned char*)_mbsinc(cur);
    }
    while (1) {
        *p = 0;
        if (p == base) break;
        p = (unsigned char*)_mbsdec(base, p);
        if (_ismbcspace(*p)) continue;
        break;
    }
    return (char*)base;
}
