#include "../include/Pnl_inp.h"

extern "C" short __cdecl __mbslen(const char*);
extern "C" int __cdecl _mbslen(const char*);
extern "C" int __cdecl __mbscmp(const char*, const char*);
extern "C" char* __cdecl __mbschr(const char*, unsigned int);
extern "C" char* __cdecl __mbscpy(char*, const char*);
extern "C" void* __cdecl _mbsncpy(void*, void*, int);
extern "C" void* __cdecl _mbsninc(void*, int);
extern "C" void* __cdecl _mbsinc(void*);
extern "C" void* __cdecl _mbsdec(void*, void*);
extern "C" int __cdecl __ismbcspace(unsigned int);
extern void operator delete(void*);
extern char pnl_inp_draw[];

TInputPanel::TInputPanel() : TTextPanel(), caret_color(0),
                             caret_interval(GetCaretBlinkTime()),
                             caret_last_time(0), draw_caret(1),
                             overLengthSound(0), input_buffer(0),
                             input_buffer1(0), input_buffer2(0),
                             input_len(0), max_len(0), insert_mode(1),
                             input_pos(0)
{
    this->handle_mouse_input = 1;
    this->bevel_type = 1;
    this->panel_type = 7;
    this->horz_align = TTextPanel::AlignHorizontalScroll;
}

TInputPanel::~TInputPanel()
{
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

long TInputPanel::setup(TDrawArea* da, TPanel* parent, long p3, long p4,
                        long p5, long p6, void* p7, long p8, long p9,
                        char* p10, int p11, unsigned char p12, int p13,
                        unsigned char p14, unsigned char p15,
                        short maxChars, TDigital* digital,
                        char* text, FormatType format)
{
    long setupMax = (format == FormatMultiLine) ? 0 : maxChars;
    if (TTextPanel::setup(da, parent, p3, p4, p5, p6, p7, p8, p9, p10,
                          p11, p12, p13, p14, setupMax, (char*)0) == 0) {
        return 0;
    }
    this->caret_color = p15;
    this->format_type = format;
    if (this->have_focus != 0) {
        this->draw_caret = 1;
        this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 89);
    }
    if (maxChars != 0)
        this->overLengthSound = digital;
    else
        this->overLengthSound = 0;
    if (this->format_type == FormatMultiLine) {
        this->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignLeft);
        this->set_word_wrap(1);
    } else {
        this->set_alignment(TTextPanel::AlignCenter,
                            TTextPanel::AlignHorizontalScroll);
    }
    this->input_buffer1 = (char*)calloc((unsigned int)((int)maxChars + (int)maxChars + 1), 1);
    if (this->input_buffer1 == 0) return 0;
    this->input_buffer2 = (char*)calloc((unsigned int)((int)maxChars + (int)maxChars + 1), 1);
    if (this->input_buffer2 == 0) return 0;
    this->input_buffer = this->input_buffer1;
    this->set_text(text);
    this->max_len = maxChars;
    this->reformat();
    return 1;
}

void TInputPanel::set_focus(int focus)
{
    TPanel::set_focus(focus);
    if (this->have_focus != 0) {
        this->draw_caret = 1;
        this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 137);
    }
}

void TInputPanel::set_format(FormatType format)
{
    this->format_type = format;
}

long TInputPanel::handle_idle()
{
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

long TInputPanel::char_action(long ch, short count)
{
    short i;
    if (ch == 8 || ch == 9 || ch == 10 || ch == 13 || ch == 27 || ch < 0x1B)
        return 1;
    if (count == 0) count = 1;
    i = 0;
    if (count <= 0) return 1;
    while (i < count) {
        switch (this->format_type) {
        case FormatPercent:
            if (__mbslen(this->get_text()) < 2 && ch >= '0' && ch <= '9') break;
            if (__mbslen(this->get_text()) != 2 || ch != '0' ||
                __mbscmp("10", this->get_text()) != 0) {
                if (this->overLengthSound != 0) this->overLengthSound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case FormatNumber:
        case FormatInteger:
        case FormatUnsignedInt:
            if (ch >= '0' && ch <= '9') break;
            if (ch == '-' && this->input_buffer[0] == 0 && this->format_type != FormatUnsignedInt) break;
            if (ch == '.' && __mbschr(this->input_buffer, ch) != 0 && this->format_type == FormatNumber) break;
            if (this->overLengthSound != 0) this->overLengthSound->play();
            else MessageBeep(0xFFFFFFFF);
            return 1;
        case FormatFile:
        case FormatFileNoExt:
            if (ch == '.') {
                if (this->format_type == FormatFile && __mbschr(this->input_buffer, ch) == 0) break;
            }
            if (ch == '.' || ch == '\\' || ch == ':' || ch == '/' || ch == '"' || ch == '*' || ch == '?' || ch == '>' || ch == '<' || ch == '|') {
                if (this->overLengthSound != 0) this->overLengthSound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case FormatPath:
            if ((ch == ':' && this->input_len != 1) || ch == '/' || ch == '"' || ch == '*' || ch == '?' || ch == '>' || ch == '<' || ch == '|') {
                if (this->overLengthSound != 0) this->overLengthSound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case FormatSingleLine:
        case FormatMultiLine:
            break;
        }
        if (this->insert_character(ch) == 0) return 1;
        ++i;
    }
    return 1;
}

long TInputPanel::key_down_action(long key, short, int, int param4, int param5)
{
    short len;
    short col;
    short line;

    switch (key) {
    case 0x25:
        if (this->num_lines < 1) return 1;
        col = this->cur_col;
        if (col > 0) {
            col--;
            this->cur_col = col;
            this->calc_input_pos();
            this->set_redraw(TPanel::RedrawNormal);
            return 1;
        } else {
            col = this->cur_line;
            if (col <= 0) return 1;
            col--;
            this->cur_line = col;
            col = __mbslen(this->get_text(this->cur_line));
        }
        this->cur_col = col;
        this->calc_input_pos();
        this->set_redraw(TPanel::RedrawNormal);
        return 1;

    case 0x27:
        if (this->num_lines < 1) return 1;
        col = this->cur_col;
        len = __mbslen(this->get_text(this->cur_line));
        if (col < len) {
            this->cur_col = col + 1;
            this->calc_input_pos();
            this->set_redraw(TPanel::RedrawNormal);
        } else {
            if (this->cur_line >= this->num_lines - 1) return 1;
            this->cur_line++;
            this->cur_col = 0;
            this->calc_input_pos();
            this->set_redraw(TPanel::RedrawNormal);
        }
        return 1;

    case 0x26:
        if (this->num_lines < 1) return 1;
        if (this->cur_line > 0) {
            this->cur_line--;
            if (this->cur_col > __mbslen(this->get_text(this->cur_line)))
                this->cur_col = __mbslen(this->get_text(this->cur_line));
            this->calc_input_pos();
            this->set_redraw(TPanel::RedrawNormal);
            return 1;
        }
        break;

    case 0x28:
        if (this->num_lines < 1) return 1;
        if (this->cur_line >= this->num_lines - 1) return 1;
        this->cur_line++;
        line = this->cur_line;
        goto page_update;

    case 0x24:
        if (this->num_lines < 1) return 1;
        if (param4 != 0) {
            if (this->cur_col == 0 && this->cur_line == 0) break;
            this->cur_col = 0;
            this->cur_line = 0;
            this->calc_input_pos();
            this->set_redraw(TPanel::RedrawNormal);
            return 1;
        }
        if (this->cur_col == 0) break;
        this->cur_col = 0;
        this->set_redraw(TPanel::RedrawNormal);
        this->calc_input_pos();
        return 1;

    case 0x23:
        if (this->num_lines < 1) return 1;
        if (param4 != 0) {
            if (this->cur_line == this->num_lines - 1) {
                len = __mbslen(this->get_text(this->cur_line));
                if (this->cur_col == len) break;
            }
            this->cur_line = this->num_lines - 1;
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        } else {
            len = __mbslen(this->get_text(this->cur_line));
            if (this->cur_col == len) break;
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        }
        this->set_redraw(TPanel::RedrawNormal);
        this->calc_input_pos();
        return 1;

    case 0x21:
        if (this->num_lines < 1) return 1;
        if (this->cur_line <= 0) return 1;
        line = this->cur_line;
        if (line < this->top_line || line > this->bot_line) line = this->top_line;
        if (line == this->top_line) {
            this->scroll(5, 0, 1);
            line = this->top_line;
        }
        goto page_update;

    case 0x22:
        if (this->num_lines < 1) return 1;
        if (this->cur_line >= this->num_lines - 1) return 1;
        line = this->cur_line;
        if (line < this->top_line || line > this->bot_line) line = this->bot_line;
        if (line == this->bot_line) {
            this->scroll(4, 0, 1);
            line = this->bot_line;
        }
page_update:
        this->cur_line = line;
        len = __mbslen(this->get_text(this->cur_line));
        if (this->cur_col > len)
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        this->calc_input_pos();
        this->set_redraw(TPanel::RedrawNormal);
        return 1;

    case 0x2E:
        this->delete_character();
        return 1;

    case 0x2D:
        if (param5 != 0) goto paste_action;
        if (param4 != 0) return 1;
        this->insert_mode = (this->insert_mode == 0);
        return 1;

    case 8:
        this->backspace_character();
        return 1;

    case 0x0D:
        if (this->format_type == FormatMultiLine) {
            this->insert_character(10);
            return 1;
        }
        if (this->parent_panel != 0)
            this->parent_panel->action(this, 0, 0, 0);
        return 1;

    case 0x1B:
        if (this->parent_panel != 0)
            this->parent_panel->action(this, 1, 0, 0);
        return 1;

    case 0x56:
        if (param4 == 0) return 0;
paste_action:
        this->paste();
        return 1;

    default:
        return 0;
    }
    return 1;
}

void TInputPanel::draw()
{
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

void TInputPanel::set_text(char* param_1)
{
    char* buf = this->input_buffer;
    if (buf != 0) {
        if (param_1 == 0) *buf = 0;
        else __mbscpy(buf, param_1);
        short len = __mbslen(this->input_buffer);
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

void TInputPanel::set_text(char**, short)
{
}

char* TInputPanel::get_input_buffer()
{
    return this->input_buffer;
}

int TInputPanel::append_character(long value)
{
    this->input_pos = this->input_len;
    return this->insert_character(value);
}

int TInputPanel::insert_character(long ch)
{
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
        _mbsncpy(dst_buffer, src_buffer, this->input_pos);
        src_buffer = (char*)_mbsninc(src_buffer, this->input_pos);
        dst_buffer = (char*)_mbsninc(dst_buffer, this->input_pos);
    }
    _mbsncpy(dst_buffer, &ch, 1);
    dst_buffer = (char*)_mbsinc(dst_buffer);
    _mbsncpy(dst_buffer, src_buffer, this->input_len - this->input_pos + 1);
    this->input_len++;
    this->input_pos++;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 655);
    return 1;
}

int TInputPanel::delete_character()
{
    short deleted_len;
    int bVar1;
    unsigned char* pcVar2;
    unsigned char* pcVar3;
    unsigned char* pcVar4;
    int move_back_one;
    if (this->input_pos >= this->input_len) return 0;
    pcVar3 = (unsigned char*)this->input_buffer1;
    bVar1 = 0;
    if (this->input_buffer == (char*)pcVar3) {
        pcVar4 = pcVar3;
        pcVar3 = (unsigned char*)this->input_buffer2;
    } else {
        pcVar4 = (unsigned char*)this->input_buffer2;
    }
    this->input_buffer = (char*)pcVar3;
    *pcVar3 = 0;
    pcVar2 = pcVar4;
    move_back_one = (int)pcVar3;
    if (this->input_pos > 0) {
        _mbsncpy(pcVar3, pcVar4, (int)this->input_pos);
        pcVar2 = (unsigned char*)_mbsninc(pcVar4, (int)this->input_pos);
        move_back_one = (int)_mbsninc(pcVar3, (int)this->input_pos);
    }
    if (*pcVar2 == '\r') {
        pcVar3 = (unsigned char*)_mbsinc(pcVar2);
        deleted_len = 1;
        if (*pcVar3 == '\n') {
            pcVar3 = (unsigned char*)_mbsinc(pcVar3);
            deleted_len = 2;
        }
    } else {
        if ((*pcVar2 == '\n') && (pcVar2 > pcVar4)) {
            pcVar4 = (unsigned char*)_mbsdec(pcVar4, pcVar2);
            if (*pcVar4 == '\r') {
                move_back_one = (int)_mbsdec(pcVar3, (unsigned char*)move_back_one);
                pcVar3 = (unsigned char*)_mbsninc(pcVar4, 2);
                deleted_len = 2;
                bVar1 = 1;
                goto do_copy;
            }
            pcVar3 = (unsigned char*)_mbsninc(pcVar4, 2);
        } else {
            pcVar3 = (unsigned char*)_mbsinc(pcVar2);
        }
        deleted_len = 1;
    }
do_copy:
    _mbsncpy((unsigned char*)move_back_one, pcVar3,
             ((int)this->input_len - (int)this->input_pos) + 1);
    if (bVar1) --this->input_pos;
    this->input_len -= deleted_len;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 758);
    return 1;
}

int TInputPanel::backspace_character()
{
    if (this->input_pos > 0) {
        this->input_pos = this->input_pos - 1;
        return this->delete_character();
    }
    return 0;
}

int TInputPanel::paste()
{
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
    if (!IsClipboardFormatAvailable(1)) return 0;
    if (!OpenClipboard(this->render_area->Wnd)) return 0;
    data_handle = GetClipboardData(1);
    if (data_handle != 0) {
        locked = (char*)GlobalLock(data_handle);
        if (locked != 0) {
            len = _mbslen(locked);
            if (len > 0xfff) len = 0xfff;
            for (int i = 0; i < 0x1000; ++i) new_str[i] = 0;
            _mbsncpy(new_str, locked, len);
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
    _mbsncpy(new_cur, old_str, (int)this->input_pos);
    old_tail = (char*)_mbsninc(old_str, (int)this->input_pos);
    dst_tail = new_cur;
    dst_tail = (char*)_mbsninc(dst_tail, (int)this->input_pos);
    _mbsncpy(dst_tail, new_str, len);
    dst_tail = (char*)_mbsninc(dst_tail, len);
    _mbsncpy(dst_tail, old_tail, ((int)this->input_len - (int)this->input_pos) + 1);
    this->input_len += (short)len;
    this->input_pos += (short)len;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 866);
    return 1;
}

void TInputPanel::reformat()
{
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

void TInputPanel::calc_input_pos()
{
    TTextPanel::TextNode* node;
    short i;
    short len;
    node = this->list;
    this->input_pos = 0;
    for (i = 0; node != 0 && i < this->cur_line; i++) {
        len = __mbslen(node->text);
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

void TInputPanel::calc_cur_line_col()
{
    TTextPanel::TextNode* node;
    short offset;
    short len;
    node = this->list;
    this->cur_line = 0;
    this->cur_col = 0;
    offset = 0;
    while (node != 0 && this->cur_line != this->num_lines - 1) {
        len = __mbslen(node->text);
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

int TInputPanel::is_blank()
{
    char* p = this->currentLine();
    if (p == 0) goto blank;
    if (*p == 0) goto blank;
    while (1) {
        if (*p == '\0') goto blank;
        if (__ismbcspace((unsigned char)*p) == 0) return 0;
        p = (char*)_mbsinc(p);
    }
blank:
    return 1;
}

char* TInputPanel::get_trimmed_str(char* dst, int maxlen)
{
    char temp_str[256];
    unsigned char* base;
    unsigned char* p;
    unsigned char* cur;
    memset(temp_str, 0, sizeof(temp_str));
    strcpy(temp_str, this->currentLine());
    memset(dst, 0, maxlen);
    base = (unsigned char*)dst;
    p = base;
    cur = (unsigned char*)temp_str;
    while (__ismbcspace(*cur & 0xFF)) cur = (unsigned char*)_mbsinc(cur);
    while (*cur) {
        _mbsncpy(p, cur, 1);
        p = (unsigned char*)_mbsinc(p);
        cur = (unsigned char*)_mbsinc(cur);
    }
    while (1) {
        *p = 0;
        if (p == base) break;
        p = (unsigned char*)_mbsdec(base, p);
        if (__ismbcspace(*p)) continue;
        break;
    }
    return (char*)base;
}
