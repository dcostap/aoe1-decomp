#include "../include/TInputPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TDigital.h"
#include "../include/debug_helpers.h"

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <mbstring.h>
#include <mbctype.h>

static const char* kPnlInpSourcePath = "C:/msdev/work/age1_x1/Pnl_inp.cpp";

TInputPanel::TInputPanel() : TTextPanel() {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00476C10
    this->caret_color = 0;
    this->caret_interval = (unsigned long)GetCaretBlinkTime();
    this->caret_last_time = 0;
    this->draw_caret = 1;
    this->overLengthSound = nullptr;
    this->format_type = FormatAny;
    this->input_buffer = nullptr;
    this->input_buffer1 = nullptr;
    this->input_buffer2 = nullptr;
    this->input_len = 0;
    this->max_len = 0;
    this->insert_mode = 1;
    this->input_pos = 0;

    // ASM sets panel_type=7 and color=5 in the constructor.
    this->panel_type = 7;
    this->color = 5;
}

TInputPanel::~TInputPanel() {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00476CF0
    if (this->input_buffer1) {
        free(this->input_buffer1);
        this->input_buffer1 = nullptr;
    }
    if (this->input_buffer2) {
        free(this->input_buffer2);
        this->input_buffer2 = nullptr;
    }
    this->input_buffer = nullptr;
}

long TInputPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TTextPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

long TInputPanel::setup(TDrawArea* area, TPanel* parent, long x, long y, long w, long h,
                        void* font, long font_wid, long font_hgt, char* back_pic_name,
                        int fill_back, uchar back_color, int outline, uchar outline_color,
                        uchar caret_color_in, short max_len_in, TDigital* over_len_sound,
                        char* initial_text, TInputPanel::FormatType format) {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00476D80
    short fixed_len = max_len_in;
    if (format == FormatMultiLine) {
        fixed_len = 0;
    }

    if (!TTextPanel::setup(area, parent, x, y, w, h, font, font_wid, font_hgt, back_pic_name,
                           fill_back, back_color, outline, outline_color, fixed_len, (char*)nullptr)) {
        return 0;
    }

    this->caret_color = caret_color_in;
    this->format_type = format;
    if (this->have_focus) {
        this->draw_caret = 1;
        this->caret_last_time = debug_timeGetTime(kPnlInpSourcePath, 0x59);
    }

    this->overLengthSound = (max_len_in == 0) ? nullptr : over_len_sound;

    if (this->format_type == FormatMultiLine) {
        this->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignLeft);
        this->set_word_wrap(1);
    } else {
        this->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignHorizontalScroll);
    }

    const int buf_bytes = (int)max_len_in * 2 + 1;
    this->input_buffer1 = (char*)calloc((size_t)buf_bytes, 1);
    if (!this->input_buffer1) {
        return 0;
    }
    this->input_buffer2 = (char*)calloc((size_t)buf_bytes, 1);
    if (!this->input_buffer2) {
        return 0;
    }

    this->input_buffer = this->input_buffer1;
    this->max_len = max_len_in;
    this->set_text(initial_text);
    this->reformat();
    return 1;
}

void TInputPanel::set_rect(tagRECT param_1) { TTextPanel::set_rect(param_1); }
void TInputPanel::set_rect(long param_1, long param_2, long param_3, long param_4) { TTextPanel::set_rect(param_1, param_2, param_3, param_4); }
void TInputPanel::set_color(uchar param_1) { TTextPanel::set_color(param_1); }
void TInputPanel::set_active(int param_1) { TTextPanel::set_active(param_1); }
void TInputPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TTextPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void TInputPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TTextPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TInputPanel::set_redraw(RedrawMode param_1) { TTextPanel::set_redraw(param_1); }
void TInputPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TTextPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TInputPanel::draw_setup(int param_1) { TTextPanel::draw_setup(param_1); }
void TInputPanel::draw_finish() { TTextPanel::draw_finish(); }
void TInputPanel::draw_rect(tagRECT* param_1) { TTextPanel::draw_rect(param_1); }
void TInputPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TTextPanel::draw_offset(param_1, param_2, param_3); }
void TInputPanel::draw_rect2(tagRECT* param_1) { TTextPanel::draw_rect2(param_1); }
void TInputPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TTextPanel::draw_offset2(param_1, param_2, param_3); }
void TInputPanel::paint() { TTextPanel::paint(); }
long TInputPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TTextPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TInputPanel::handle_size(long param_1, long param_2) { return TTextPanel::handle_size(param_1, param_2); }
long TInputPanel::handle_paint() { return TTextPanel::handle_paint(); }
long TInputPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TTextPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TInputPanel::handle_char(long param_1, short param_2) { return TTextPanel::handle_char(param_1, param_2); }
long TInputPanel::handle_command(uint param_1, long param_2) { return TTextPanel::handle_command(param_1, param_2); }
long TInputPanel::handle_user_command(uint param_1, long param_2) { return TTextPanel::handle_user_command(param_1, param_2); }
long TInputPanel::handle_timer_command(uint param_1, long param_2) { return TTextPanel::handle_timer_command(param_1, param_2); }
long TInputPanel::handle_scroll(long param_1, long param_2) { return TTextPanel::handle_scroll(param_1, param_2); }
long TInputPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TTextPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TInputPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TInputPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TTextPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TInputPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TTextPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TInputPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TInputPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TInputPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TInputPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TInputPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TInputPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TInputPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TInputPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TInputPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TInputPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TInputPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TTextPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TInputPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TTextPanel::action(param_1, param_2, param_3, param_4); }
void TInputPanel::get_true_render_rect(tagRECT* param_1) { TTextPanel::get_true_render_rect(param_1); }
int TInputPanel::is_inside(long param_1, long param_2) { return TTextPanel::is_inside(param_1, param_2); }
void TInputPanel::set_tab_order(TPanel* param_1, TPanel* param_2) { TTextPanel::set_tab_order(param_1, param_2); }
void TInputPanel::set_tab_order(TPanel** param_1, short param_2) { TTextPanel::set_tab_order(param_1, param_2); }
uchar TInputPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TTextPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TInputPanel::stop_sound_system() { TTextPanel::stop_sound_system(); }
int TInputPanel::restart_sound_system() { return TTextPanel::restart_sound_system(); }
void TInputPanel::take_snapshot() { TTextPanel::take_snapshot(); }
void TInputPanel::handle_reactivate() { TTextPanel::handle_reactivate(); }
void TInputPanel::set_text(long param_1) { TTextPanel::set_text(param_1); }
void TInputPanel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) { TTextPanel::set_bevel_info(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }

void TInputPanel::set_focus(int focused) {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00476EE0
    TPanel::set_focus(focused);
    if (this->have_focus) {
        this->draw_caret = 1;
        this->caret_last_time = debug_timeGetTime(kPnlInpSourcePath, 0x89);
    }
}

void TInputPanel::set_format(TInputPanel::FormatType format) {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00476F20
    this->format_type = format;
}

long TInputPanel::handle_idle() {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00476F30
    if (this->have_focus) {
        const ulong now = debug_timeGetTime(kPnlInpSourcePath, 0x9E);
        if (this->caret_interval <= now - this->caret_last_time) {
            this->draw_caret = (this->draw_caret == 0) ? 1 : 0;
            this->set_redraw(TPanel::RedrawMode::Redraw);
            this->caret_last_time = debug_timeGetTime(kPnlInpSourcePath, 0xA3);
        }
    }
    return TPanel::handle_idle();
}

void TInputPanel::draw() {
    // Fully verified. Source of truth: pnl_inp.cpp.asm @ 0x004777C0
    TTextPanel::draw();

    if (!this->render_area) return;
    if (!this->visible) return;
    if (!this->active) return;
    if (!this->have_focus) return;
    if (this->draw_caret == 0) return;
    if (this->cur_line < this->top_line || this->cur_line > this->bot_line) return;

    tagRECT line_rect{};
    long cursor_x_offset = 0;

    this->draw_setup(0);

    HDC hdc = (HDC)this->render_area->GetDc((char*)"pnl_inp::draw");
    if (hdc) {
        const HGDIOBJ old_font = SelectObject(hdc, (HGDIOBJ)this->font);
        this->calc_line_pos(hdc, (short)(this->cur_line - this->top_line), this->cur_line, &line_rect, &cursor_x_offset);
        SelectObject(hdc, old_font);
        this->render_area->ReleaseDc((char*)"pnl_inp::draw");

        uchar* bits = this->render_area->Lock((char*)"pnl_inp::draw", 1);
        if (bits) {
            const long x = cursor_x_offset + line_rect.left;
            const long len = (line_rect.bottom - line_rect.top) + 1;
            if (x < this->render_rect.right) {
                this->render_area->DrawVertLine(x, line_rect.top, len, this->caret_color);
                this->render_area->DrawVertLine(x + 1, line_rect.top, len, this->caret_color);
            }
            this->render_area->Unlock((char*)"pnl_inp::draw");
        }
    }

    this->draw_finish();
}

void TInputPanel::set_text(char* s) {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00477910
    if (!this->input_buffer) {
        return;
    }

    if (!s) {
        this->input_buffer[0] = '\0';
    } else {
        _mbscpy((unsigned char*)this->input_buffer, (const unsigned char*)s);
    }

    this->input_len = (short)_mbslen((const unsigned char*)this->input_buffer);
    this->input_pos = 0;
    this->cur_line = 0;
    this->cur_col = 0;

    if (this->format_type != FormatMultiLine && this->input_len > 0) {
        this->input_pos = this->input_len;
        this->cur_col = this->input_len;
    }
    this->reformat();
}

void TInputPanel::set_text(char** /*param_1*/, short /*param_2*/) {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00477990
}

char* TInputPanel::get_input_buffer() {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x004779A0
    return this->input_buffer;
}

int TInputPanel::append_character(long ch) {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x004779B0
    this->input_pos = this->input_len;
    return this->insert_character(ch);
}

int TInputPanel::insert_character(long ch) {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x004779D0
    if (this->input_len >= this->max_len) {
        if (this->overLengthSound) {
            this->overLengthSound->play();
            return 0;
        }
        MessageBeep((UINT)-1);
        return 0;
    }

    char* src = this->input_buffer;
    char* dst = (this->input_buffer == this->input_buffer1) ? this->input_buffer2 : this->input_buffer1;
    this->input_buffer = dst;
    dst[0] = '\0';

    if (this->input_pos > 0) {
        _mbsncpy((unsigned char*)dst, (const unsigned char*)src, (size_t)this->input_pos);
        src = (char*)_mbsninc((const unsigned char*)src, (size_t)this->input_pos);
        dst = (char*)_mbsninc((const unsigned char*)dst, (size_t)this->input_pos);
    }

    char ch_buf[2];
    ch_buf[0] = (char)ch;
    ch_buf[1] = '\0';
    _mbsncpy((unsigned char*)dst, (const unsigned char*)ch_buf, 1);
    unsigned char* after = _mbsinc((unsigned char*)dst);
    _mbsncpy(after, (const unsigned char*)src, (size_t)((int)this->input_len - (int)this->input_pos) + 1);

    this->input_len = (short)(this->input_len + 1);
    this->input_pos = (short)(this->input_pos + 1);
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime(kPnlInpSourcePath, 0x28F);
    return 1;
}

int TInputPanel::delete_character() {
    // Fully verified. Source of truth: pnl_inp.cpp.asm @ 0x00477AF0
    if (this->input_len <= this->input_pos) {
        return 0;
    }

    const char* src_buf = (this->input_buffer == this->input_buffer1) ? this->input_buffer1 : this->input_buffer2;
    char* dst_buf = (this->input_buffer == this->input_buffer1) ? this->input_buffer2 : this->input_buffer1;

    this->input_buffer = dst_buf;
    dst_buf[0] = '\0';

    unsigned char* cur_src = (unsigned char*)src_buf;
    unsigned char* cur_dest = (unsigned char*)dst_buf;
    unsigned char* after_src = (unsigned char*)src_buf;
    short remove_chars = 1;
    int move_back_one = 0;

    if (0 < this->input_pos) {
        _mbsncpy(cur_dest, cur_src, (int)this->input_pos);
        after_src = _mbsninc(cur_src, (int)this->input_pos);
        cur_dest = _mbsninc(cur_dest, (int)this->input_pos);
    } else {
        after_src = cur_src;
    }

    if (*after_src == '\r') {
        unsigned char* p = _mbsinc(after_src);
        remove_chars = 1;
        if (*p == '\n') {
            p = _mbsinc(p);
            remove_chars = 2;
        }
        after_src = p;
    } else {
        if ((*after_src == '\n') && ((const unsigned char*)src_buf < after_src)) {
            unsigned char* prev = _mbsdec((unsigned char*)src_buf, after_src);
            if (*prev == '\r') {
                cur_dest = _mbsdec((unsigned char*)dst_buf, cur_dest);
                after_src = _mbsninc(prev, 2);
                remove_chars = 2;
                move_back_one = 1;
                goto LAB_00477C15;
            }
            after_src = _mbsninc(prev, 2);
        } else {
            after_src = _mbsinc(after_src);
        }
        remove_chars = 1;
    }

LAB_00477C15:
    _mbsncpy(cur_dest, after_src, ((int)this->input_len - (int)this->input_pos) + 1);
    if (move_back_one) this->input_pos = (short)(this->input_pos - 1);
    this->input_len = (short)(this->input_len - remove_chars);
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime(kPnlInpSourcePath, 0x2F6);
    return 1;
}

int TInputPanel::backspace_character() {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00477C90
    if (this->input_pos > 0) {
        this->input_pos = (short)(this->input_pos - 1);
        return this->delete_character();
    }
    return 0;
}

int TInputPanel::paste() {
    // Fully verified. Source of truth: pnl_inp.cpp.asm @ 0x00477CB0
    if (!IsClipboardFormatAvailable(CF_TEXT)) {
        return 0;
    }
    HWND hwnd = (HWND)this->render_area->Wnd;
    if (!OpenClipboard(hwnd)) {
        return 0;
    }

    char clip_buf[4096];
    memset(clip_buf, 0, sizeof(clip_buf));

    HGLOBAL data = (HGLOBAL)GetClipboardData(CF_TEXT);
    int clip_len = 0;
    if (data) {
        const char* locked = (const char*)GlobalLock(data);
        if (locked) {
            clip_len = (int)_mbslen((const unsigned char*)locked);
            if (clip_len > 0xFFF) clip_len = 0xFFF;
            _mbsncpy((unsigned char*)(clip_buf + 4), (const unsigned char*)locked, (size_t)clip_len);
            GlobalUnlock(data);
        }
    }
    CloseClipboard();

    if (this->max_len <= (short)(clip_len + this->input_len)) {
        if (this->overLengthSound) {
            this->overLengthSound->play();
            return 0;
        }
        MessageBeep((UINT)-1);
        return 0;
    }

    char* src = this->input_buffer;
    char* dst = (this->input_buffer == this->input_buffer1) ? this->input_buffer2 : this->input_buffer1;
    this->input_buffer = dst;
    dst[0] = '\0';

    _mbsncpy((unsigned char*)dst, (const unsigned char*)src, (size_t)this->input_pos);
    unsigned char* src_tail = _mbsninc((unsigned char*)src, (size_t)this->input_pos);
    unsigned char* dst_tail = _mbsninc((unsigned char*)dst, (size_t)this->input_pos);

    _mbsncpy(dst_tail, (unsigned char*)(clip_buf + 4), (size_t)clip_len);
    dst_tail = _mbsninc(dst_tail, (size_t)clip_len);
    _mbsncpy(dst_tail, src_tail, (size_t)((int)this->input_len - (int)this->input_pos) + 1);

    this->input_len = (short)(this->input_len + clip_len);
    this->input_pos = (short)(this->input_pos + clip_len);
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime(kPnlInpSourcePath, 0x362);
    return 1;
}

void TInputPanel::reformat() {
    // Fully verified. Source of truth: pnl_inp.cpp.asm @ 0x00477E90
    const short old_top = this->top_line;
    const short old_cur = this->cur_line;

    TTextPanel::set_text(this->input_buffer);

    const short num_lines = this->num_lines;
    if (num_lines <= old_cur) {
        this->cur_line = (short)(num_lines - 1);
    } else {
        this->cur_line = old_cur;
    }
    if (num_lines <= old_top) {
        this->top_line = (short)(num_lines - 1);
    }

    this->scroll(1, old_top, 1);
    this->set_redraw(TPanel::RedrawMode::Redraw);
}

void TInputPanel::calc_input_pos() {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00477EF0
    this->input_pos = 0;

    TTextPanel::TextNode* n = this->list;
    for (short i = 0; n && i < this->cur_line; ++i) {
        this->input_pos = (short)(this->input_pos + (short)_mbslen((const unsigned char*)n->text));
        n = n->next;
    }

    this->input_pos = (short)(this->input_pos + this->cur_col);
    if (this->cur_col > 0 && this->input_pos > 0 && this->input_buffer[this->input_pos - 1] == '\n') {
        this->input_pos = (short)(this->input_pos - 1);
        this->cur_col = (short)(this->cur_col - 1);
    }
    if (this->cur_col > 0 && this->input_pos > 0 && this->input_buffer[this->input_pos - 1] == '\r') {
        this->input_pos = (short)(this->input_pos - 1);
        this->cur_col = (short)(this->cur_col - 1);
    }

    while (this->cur_line < this->top_line) {
        this->scroll(3, 1, 1);
    }
    while (this->cur_line > this->bot_line) {
        this->scroll(2, 1, 1);
    }
}

void TInputPanel::calc_cur_line_col() {
    // Fully verified. Source of truth: pnl_inp.cpp.asm @ 0x00478010
    this->cur_line = 0;
    this->cur_col = 0;

    int scanned = 0;
    TTextPanel::TextNode* n = this->list;
    while (n && (this->cur_line != (short)(this->num_lines - 1))) {
        const int len = (int)_mbslen((const unsigned char*)n->text);
        if (scanned + len > (int)this->input_pos) break;
        scanned += len;
        this->cur_line = (short)(this->cur_line + 1);
        n = n->next;
    }

    this->cur_col = (short)((int)this->input_pos - scanned);
    if (this->cur_col > 0 && this->input_pos > 0 && this->input_buffer[this->input_pos - 1] == '\n') {
        this->cur_col = (short)(this->cur_col - 1);
        this->input_pos = (short)(this->input_pos - 1);
    }
    if (this->cur_col > 0 && this->input_pos > 0 && this->input_buffer[this->input_pos - 1] == '\r') {
        this->cur_col = (short)(this->cur_col - 1);
        this->input_pos = (short)(this->input_pos - 1);
    }

    while (this->cur_line < this->top_line) {
        this->scroll(3, 1, 1);
    }
    while (this->cur_line > this->bot_line) {
        this->scroll(2, 1, 1);
    }
}

int TInputPanel::is_blank() {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00478150
    char* s = this->currentLine();
    if (s && *s) {
        for (; *s; s = (char*)_mbsinc((unsigned char*)s)) {
            if (_ismbcspace((unsigned char)*s) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

char* TInputPanel::get_trimmed_str(char* out, int out_len) {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x004781A0
    if (!out || out_len <= 0) {
        return out;
    }
    memset(out, 0, (size_t)out_len);

    char temp[256];
    memset(temp, 0, sizeof(temp));

    const char* cur = this->currentLine();
    if (!cur) cur = "";
    strncpy(temp + 4, cur, sizeof(temp) - 5);

    unsigned char* s = (unsigned char*)(temp + 4);
    while (*s && _ismbcspace(*s) != 0) {
        s = _mbsinc(s);
    }

    unsigned char* d = (unsigned char*)out;
    while (*s) {
        _mbsncpy(d, s, 1);
        d = _mbsinc(d);
        s = _mbsinc(s);
    }

    while (d != (unsigned char*)out) {
        *d = '\0';
        unsigned char* prev = _mbsdec((unsigned char*)out, d);
        if (!prev || _ismbcspace(*prev) == 0) {
            break;
        }
        d = prev;
    }
    return out;
}

long TInputPanel::char_action(long key, short repeat) {
    // Fully verified. Source of truth: pnl_inp.cpp.decomp @ 0x00476FA0
    if (key != 8 && key != 9 && key != 10 && key != 0x0D && key != 0x1B && key > 0x1A) {
        if (repeat == 0) repeat = 1;

        for (short i = 0; i < repeat; ++i) {
            const FormatType fmt = this->format_type;
            switch (fmt) {
            case FormatNumber:
            case FormatInteger:
            case FormatUnsignedInt:
                if (((key < '0' || key > '9') &&
                     ((key != '-' || (this->input_buffer && this->input_buffer[0] != '\0') || fmt == FormatUnsignedInt))) &&
                    ((key != '.' || (fmt != FormatNumber) || (_mbschr((unsigned char*)this->input_buffer, '.') != nullptr)))) {
                    if (this->overLengthSound) {
                        this->overLengthSound->play();
                        return 1;
                    }
                    MessageBeep((UINT)-1);
                    return 1;
                }
                break;
            case FormatFile:
            case FormatFileNoExt:
                if (key == '.') {
                    if (fmt != FormatFile || _mbschr((unsigned char*)this->input_buffer, '.') != nullptr) {
                        if (this->overLengthSound) {
                            this->overLengthSound->play();
                            return 1;
                        }
                        MessageBeep((UINT)-1);
                        return 1;
                    }
                } else if (key == '\\' || key == ':' || key == '/' || key == '"' || key == '*' || key == '?' ||
                           key == '>' || key == '<' || key == '|') {
                    if (this->overLengthSound) {
                        this->overLengthSound->play();
                        return 1;
                    }
                    MessageBeep((UINT)-1);
                    return 1;
                }
                break;
            case FormatPath:
                if ((key == ':' && this->input_len != 1) || key == '/' || key == '"' || key == '*' || key == '?' ||
                    key == '>' || key == '<' || key == '|') {
                    if (this->overLengthSound) {
                        this->overLengthSound->play();
                        return 1;
                    }
                    MessageBeep((UINT)-1);
                    return 1;
                }
                break;
            case FormatPercent: {
                const uint len = (uint)_mbslen((unsigned char*)this->get_text((long)this->cur_line));
                if (len > 1 || key < '0' || key > '9') {
                    if (len == 2 && key == '0' && _mbscmp((unsigned char*)"10", (unsigned char*)this->get_text((long)this->cur_line)) == 0) {
                        break;
                    }
                    if (this->overLengthSound) {
                        this->overLengthSound->play();
                        return 1;
                    }
                    MessageBeep((UINT)-1);
                    return 1;
                }
                break;
            }
            default:
                break;
            }

            if (this->insert_character(key) == 0) {
                return 1;
            }
        }
    }
    return 1;
}

long TInputPanel::key_down_action(long key, short /*param_2*/, int alt, int ctrl, int shift) {
    // Fully verified. Source of truth: pnl_inp.cpp.asm @ 0x00477220
    (void)alt;

    short sVar1;
    short sVar3;
    char* pcVar4;

    switch (key) {
    case VK_BACK:
        this->backspace_character();
        return 1;
    default:
        return 0;
    case VK_RETURN:
        if (this->format_type == FormatMultiLine) {
            this->insert_character(10);
            return 1;
        }
        if (this->parent_panel) {
            this->parent_panel->action(this, 0, 0, 0);
            return 1;
        }
        break;
    case VK_ESCAPE:
        if (this->parent_panel) {
            this->parent_panel->action(this, 1, 0, 0);
            return 1;
        }
        break;
    case VK_PRIOR: // Page Up
        if (this->num_lines < 1) return 1;
        sVar1 = this->cur_line;
        if (sVar1 < 1) return 1;
        sVar3 = this->top_line;
        if ((sVar1 < sVar3) || (this->bot_line < sVar1)) {
            this->cur_line = sVar3;
        }
        if (this->cur_line == sVar3) {
            this->scroll(5, 0, 1);
            sVar3 = this->top_line;
        }
        goto LAB_004775F9;
    case VK_NEXT: // Page Down
        sVar3 = this->num_lines;
        if (sVar3 < 1) return 1;
        sVar1 = this->cur_line;
        if ((int)(sVar3 - 1) <= (int)sVar1) return 1;
        if ((sVar1 < this->top_line) || (this->bot_line < sVar1)) {
            sVar3 = this->bot_line;
            this->cur_line = sVar3;
        } else {
            sVar3 = this->bot_line;
        }
        if (this->cur_line == sVar3) {
            this->scroll(4, 0, 1);
            sVar3 = this->bot_line;
        }
        goto LAB_004775F9;
    case VK_END:
        sVar3 = this->num_lines;
        if (sVar3 < 1) return 1;
        if (ctrl == 0) {
            pcVar4 = this->get_text((long)this->cur_line);
            sVar3 = (short)_mbslen((const unsigned char*)pcVar4);
            if (this->cur_col == sVar3) return 1;
            sVar3 = this->cur_line;
        } else {
            const int iVar5 = (int)this->cur_line;
            if (iVar5 == (int)sVar3 - 1) {
                pcVar4 = this->get_text((long)iVar5);
                sVar3 = (short)_mbslen((const unsigned char*)pcVar4);
                if (this->cur_col == sVar3) return 1;
            }
            sVar3 = (short)(this->num_lines - 1);
            this->cur_line = sVar3;
        }
        pcVar4 = this->get_text((long)sVar3);
        this->cur_col = (short)_mbslen((const unsigned char*)pcVar4);
        goto LAB_0047750F;
    case VK_HOME:
        if (this->num_lines < 1) return 1;
        if (ctrl == 0) {
            if (this->cur_col != 0) {
                this->cur_col = 0;
                goto LAB_0047750F;
            }
        } else if ((this->cur_col != 0) || (this->cur_line != 0)) {
            this->cur_col = 0;
            this->cur_line = 0;
            this->calc_input_pos();
            this->set_redraw(TPanel::RedrawMode::Redraw);
            return 1;
        }
        break;
    case VK_LEFT:
        if (this->num_lines < 1) return 1;
        sVar3 = this->cur_col;
        if (sVar3 < 1) {
            sVar3 = this->cur_line;
            if (sVar3 < 1) return 1;
            sVar3 = (short)(sVar3 - 1);
            this->cur_line = sVar3;
            goto LAB_00477625;
        }
        sVar3 = (short)(sVar3 - 1);
        goto LAB_00477635;
    case VK_UP:
        if (this->num_lines < 1) return 1;
        sVar3 = this->cur_line;
        if (0 < sVar3) {
            sVar3 = (short)(sVar3 - 1);
            this->cur_line = sVar3;
            pcVar4 = this->get_text((long)sVar3);
            sVar3 = (short)_mbslen((const unsigned char*)pcVar4);
            if (sVar3 < this->cur_col) {
                pcVar4 = this->get_text((long)this->cur_line);
                this->cur_col = (short)_mbslen((const unsigned char*)pcVar4);
            }
            goto LAB_0047763C;
        }
        break;
    case VK_RIGHT:
        if (this->num_lines < 1) return 1;
        sVar3 = this->cur_col;
        pcVar4 = this->get_text((long)this->cur_line);
        sVar1 = (short)_mbslen((const unsigned char*)pcVar4);
        if (sVar3 < sVar1) {
            this->cur_col = (short)(sVar3 + 1);
            goto LAB_0047763C;
        }
        sVar3 = this->cur_line;
        if ((int)sVar3 < (int)this->num_lines - 1) {
            this->cur_col = 0;
            this->cur_line = (short)(sVar3 + 1);
            goto LAB_0047763C;
        }
        break;
    case VK_DOWN:
        sVar3 = this->num_lines;
        if (sVar3 < 1) return 1;
        sVar1 = this->cur_line;
        if ((int)(sVar3 - 1) <= (int)sVar1) return 1;
        sVar1 = (short)(sVar1 + 1);
        this->cur_line = sVar1;
        pcVar4 = this->get_text((long)sVar1);
        sVar3 = (short)_mbslen((const unsigned char*)pcVar4);
        if (this->cur_col <= sVar3) goto LAB_0047763C;
        goto LAB_0047761D;
    case VK_INSERT:
        if (shift == 0) {
            if (ctrl != 0) return 1;
            this->insert_mode = (this->insert_mode == 0);
            return 1;
        }
        goto LAB_00477711;
    case VK_DELETE:
        this->delete_character();
        return 1;
    case 'V':
        if (ctrl == 0) return 0;

LAB_00477711:
        this->paste();
    }

    return 1;

LAB_0047750F:
    this->set_redraw(TPanel::RedrawMode::Redraw);
    this->calc_input_pos();
    return 1;

LAB_004775F9:
    this->cur_line = sVar3;
    pcVar4 = this->get_text((long)sVar3);
    sVar3 = (short)_mbslen((const unsigned char*)pcVar4);
    if (sVar3 < this->cur_col) goto LAB_0047761D;
    goto LAB_0047763C;

LAB_0047761D:
    sVar3 = this->cur_line;

LAB_00477625:
    pcVar4 = this->get_text((long)sVar3);
    sVar3 = (short)_mbslen((const unsigned char*)pcVar4);

LAB_00477635:
    this->cur_col = sVar3;

LAB_0047763C:
    this->calc_input_pos();
    this->set_redraw(TPanel::RedrawMode::Redraw);
    return 1;
}

