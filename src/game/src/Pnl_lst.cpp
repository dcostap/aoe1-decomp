#include "../include/TListPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TDrawArea.h"
#include "../include/debug_helpers.h"

#include <windows.h>
#include <ctype.h>

namespace {

static int list_line_height(const TListPanel* self) {
    if (!self) {
        return 1;
    }
    if (self->spacer_size == 0) {
        return (self->text_hgt > 0) ? self->text_hgt : 1;
    }
    const int h = self->text_hgt - 1 + (self->spacer_size * 2);
    return (h > 0) ? h : 1;
}

static short list_item_at(TListPanel* self, long x, long y) {
    (void)x;
    if (!self) {
        return 0;
    }

    const int line_h = list_line_height(self);
    const int rel_y = (int)(y - self->pnl_y - self->border_size - self->spacer_size);
    if (rel_y < 0) {
        return self->top_line;
    }
    return (short)(self->top_line + (rel_y / line_h));
}

static void list_calc_line_pos(TListPanel* self, HDC hdc, short draw_index, short line_index, tagRECT* out_rect) {
    if (!self || !out_rect) {
        return;
    }

    SIZE full_sz;
    full_sz.cx = 0;
    full_sz.cy = 0;

    char* text = self->get_text(line_index);
    if (text && text[0] != '\0') {
        GetTextExtentPoint32A(hdc, text, (int)strlen(text), &full_sz);
    }

    int text_w_with_pad = full_sz.cx;
    if (self->horz_align != TTextPanel::AlignCenter && self->horz_align != TTextPanel::AlignWordwrap) {
        text_w_with_pad += 5;
    }

    int x = self->pnl_x + self->border_size;
    if (self->horz_align == TTextPanel::AlignRight) {
        x = (((self->pnl_x + self->pnl_wid) - self->border_size) - text_w_with_pad) - 7;
    } else if (self->horz_align == TTextPanel::AlignCenter || self->horz_align == TTextPanel::AlignWordwrap) {
        x = (self->pnl_x + (self->pnl_wid / 2)) - (text_w_with_pad / 2);
    }

    const int line_h = list_line_height(self);
    int y = self->pnl_y + self->border_size;
    if (self->vert_align == TTextPanel::AlignTop) {
        y = self->pnl_y + self->border_size + draw_index * line_h + self->spacer_size;
    } else if (self->vert_align == TTextPanel::AlignBottom) {
        y = (((self->pnl_y + self->pnl_hgt) - (((int)self->num_lines - (int)draw_index) * line_h)) - self->border_size) - self->spacer_size - 1;
    } else {
        y = ((int)draw_index * line_h - ((int)self->num_lines * line_h) / 2) + self->pnl_y + (self->pnl_hgt / 2) + self->spacer_size;
    }

    out_rect->left = x;
    out_rect->top = y;
    out_rect->right = x + text_w_with_pad - 1;
    out_rect->bottom = y + self->text_hgt;
}

static void list_draw_line(TListPanel* self, HDC hdc, short draw_index, short line_index, unsigned long c_main, unsigned long c_shadow) {
    if (!self) {
        return;
    }

    char* text = self->get_text(line_index);
    if (!text || text[0] == '\0') {
        return;
    }

    tagRECT line_rect;
    list_calc_line_pos(self, hdc, draw_index, line_index, &line_rect);

    int x = line_rect.left;
    if (self->horz_align != TTextPanel::AlignCenter && self->horz_align != TTextPanel::AlignWordwrap) {
        x += 5;
    }
    const int y = line_rect.top;
    const int text_len = (int)strlen(text);

    if (self->text_style == TTextPanel::NormalStyle) {
        SetTextColor(hdc, (COLORREF)c_main);
        TextOutA(hdc, x, y, text, text_len);
        return;
    }

    if (self->text_style == TTextPanel::BeveledStyle) {
        SetTextColor(hdc, (COLORREF)c_main);
        TextOutA(hdc, x - 1, y + 1, text, text_len);
        SetTextColor(hdc, (COLORREF)c_shadow);
        TextOutA(hdc, x, y, text, text_len);
        return;
    }

    SetTextColor(hdc, (COLORREF)c_shadow);
    TextOutA(hdc, x - 1, y + 1, text, text_len);
    SetTextColor(hdc, (COLORREF)c_main);
    TextOutA(hdc, x, y, text, text_len);
}

static void list_scroll_cur_line(TListPanel* self, uchar mode, short line, int update_scrollbar) {
    if (!self || self->num_lines <= 0) {
        return;
    }

    const short old_line = self->cur_line;
    short new_line = self->cur_line;
    short visible_top = self->top_line;
    short visible_bottom = self->bot_line;
    const short max_line = (short)(self->num_lines - 1);

    switch (mode) {
    case 1:
        self->cur_line = line;
        if (line < 0) {
            self->cur_line = 0;
        } else if (line > max_line) {
            self->cur_line = max_line;
        }

        new_line = self->cur_line;
        if (new_line < visible_top) {
            self->scroll(1, new_line, update_scrollbar);
        } else if (visible_bottom < new_line) {
            self->scroll(0, (short)(new_line - visible_bottom), update_scrollbar);
        }
        break;

    case 2:
        if (old_line < visible_top || visible_bottom < old_line) {
            visible_bottom = self->bot_line;
            self->cur_line = visible_bottom;
        }

        new_line = self->cur_line;
        if (visible_bottom <= new_line) {
            if (new_line < max_line) {
                self->cur_line = (short)(new_line + 1);
                self->scroll(2, 0, update_scrollbar);
            }
            break;
        }

        self->cur_line = (short)(new_line + 1);
        break;

    case 3:
        visible_top = self->top_line;
        if (old_line < visible_top || self->bot_line < old_line) {
            self->cur_line = visible_top;
        }

        new_line = self->cur_line;
        if (new_line <= visible_top) {
            if (new_line > 0) {
                self->cur_line = (short)(new_line - 1);
                self->scroll(3, 0, update_scrollbar);
            }
            break;
        }

        self->cur_line = (short)(new_line - 1);
        break;

    case 4:
        if (old_line < self->top_line || self->bot_line < old_line) {
            visible_bottom = self->bot_line;
            self->cur_line = visible_bottom;
        }

        if (self->cur_line == visible_bottom) {
            self->scroll(4, 0, update_scrollbar);
            self->cur_line = self->bot_line;
            break;
        }

        self->cur_line = visible_bottom;
        break;

    case 5:
        visible_top = self->top_line;
        if (old_line < visible_top || self->bot_line < old_line) {
            self->cur_line = visible_top;
        }

        if (self->cur_line == visible_top) {
            self->scroll(5, 0, update_scrollbar);
            self->cur_line = self->top_line;
            break;
        }

        self->cur_line = visible_top;
        break;

    case 6:
        self->scroll(6, 0, update_scrollbar);
        self->cur_line = self->top_line;
        break;

    case 7:
        self->scroll(7, 0, update_scrollbar);
        self->cur_line = self->bot_line;
        break;

    default:
        break;
    }

    self->set_redraw(TPanel::RedrawMode::Redraw);

    if (self->cur_line != old_line && self->parent_panel &&
        self->cur_line >= 0 && self->cur_line < self->num_lines) {
        self->parent_panel->action(self, 1, (ulong)self->cur_line, 0);
    }
}

static void list_draw_highlight_bar(TListPanel* self) {
    if (!self || !self->drawHighlightBar || !self->render_area) {
        return;
    }
    if (self->cur_line < self->top_line || self->cur_line > self->bot_line) {
        return;
    }

    HDC hdc = (HDC)self->render_area->GetDc((char*)"pnl_lst::draw_highlight_bar");
    if (!hdc) {
        return;
    }

    tagRECT line_rect;
    list_calc_line_pos(self, hdc, (short)(self->cur_line - self->top_line), self->cur_line, &line_rect);
    self->render_area->ReleaseDc((char*)"pnl_lst::draw_highlight_bar");

    if (!self->render_area->Lock((char*)"pnl_lst::draw_highlight_bar", 1)) {
        return;
    }

    const long x1 = self->pnl_x + self->border_size;
    const long y1 = line_rect.top - self->spacer_size;
    const long x2 = (self->pnl_x + self->pnl_wid - self->border_size) - 1;
    const long y2 = line_rect.bottom + self->spacer_size - 1;

    switch (self->bevel_type) {
    case 0:
    case 1:
        self->render_area->DrawRect(x1, y1, x2, y2, 0xff);
        break;
    case 2:
        self->render_area->DrawBevel(x1, y1, x2, y2, self->bevel_color1, self->bevel_color6);
        break;
    case 3:
        self->render_area->DrawBevel2(x1, y1, x2, y2, self->bevel_color1, self->bevel_color2, self->bevel_color5, self->bevel_color6);
        break;
    case 4:
        self->render_area->DrawBevel3(x1, y1, x2, y2, self->bevel_color1, self->bevel_color2, self->bevel_color3, self->bevel_color4, self->bevel_color5, self->bevel_color6);
        break;
    case 5:
        self->render_area->DrawBevel(x1, y1, x2, y2, self->bevel_color6, self->bevel_color1);
        break;
    case 6:
        self->render_area->DrawBevel2(x1, y1, x2, y2, self->bevel_color6, self->bevel_color5, self->bevel_color2, self->bevel_color1);
        break;
    case 7:
        self->render_area->DrawBevel3(x1, y1, x2, y2, self->bevel_color6, self->bevel_color5, self->bevel_color4, self->bevel_color3, self->bevel_color2, self->bevel_color1);
        break;
    default:
        break;
    }

    self->render_area->Unlock((char*)"pnl_lst::draw_highlight_bar");
}

} // namespace

TListPanel::TListPanel() : TTextPanel() {
    auto_track = 0;
    mouse_scroll_last_time = 0;
    mouse_scroll_up = 0;
    mouse_scroll_down = 0;
    drawHighlightBar = 1;
    panel_type = 4;
    bevel_type = 1;
    mouse_scroll_interval = 50;
    tab_stop = 1;
    border_size = 1;
    spacer_size = 1;
}

TListPanel::~TListPanel() {
}

void TListPanel::set_auto_track(int track) {
    auto_track = track;
}

long TListPanel::setup(TDrawArea* draw_area, TPanel* parent, long x, long y, long wid, long hgt,
                       void* font, long font_wid, long font_hgt, void* back_pic, int fill_back,
                       unsigned char back_color, int have_outline, unsigned char outline_color,
                       int word_wrap, char** string_list, short sorted) {
    if (!TTextPanel::setup(draw_area, parent, x, y, wid, hgt, font, font_wid, font_hgt,
                           (char*)back_pic, fill_back, back_color, have_outline, outline_color,
                           (short)word_wrap, string_list, sorted)) {
        return 0;
    }

    return 1;
}

void TListPanel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    switch (param_1) {
    case 3:
    case 6:
        spacer_size = 2;
        break;
    case 4:
    case 7:
        spacer_size = 3;
        break;
    default:
        spacer_size = 1;
        break;
    }

    TTextPanel::set_bevel_info(param_1, param_2, param_3, param_4, param_5, param_6, param_7);

    if (spacer_size == 0) {
        spacer_size = 1;
        // Source-of-truth (`Pnl_lst.cpp.decomp`) calls `calc_draw_info(this, 1)` here.
        // `set_font` is our non-virtual helper that already runs `calc_draw_info` and redraw.
        this->set_font(this->font, this->font_wid, this->font_hgt);
    }
}

long TListPanel::handle_idle() {
    TPanel::handle_idle();

    if (!mouse_scroll_up && !mouse_scroll_down) {
        return 0;
    }

    const unsigned long now = debug_timeGetTime((char*)"C:/msdev/work/age1_x1/Pnl_lst.cpp", 0x6c);
    if ((now - mouse_scroll_last_time) < mouse_scroll_interval) {
        return 0;
    }

    mouse_scroll_last_time = now;
    if (mouse_scroll_up) {
        const short visible_top = top_line;
        if (cur_line != visible_top) {
            list_scroll_cur_line(this, 1, visible_top, 1);
        }
        list_scroll_cur_line(this, 3, 0, 1);
    } else {
        const short visible_bottom = bot_line;
        if (cur_line != visible_bottom) {
            list_scroll_cur_line(this, 1, visible_bottom, 1);
        }
        list_scroll_cur_line(this, 2, 0, 1);
    }
    return 0;
}

long TListPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) {
    (void)param_3;
    (void)param_4;

    if (!auto_track || !is_inside(param_1, param_2)) {
        return 0;
    }

    const short item = list_item_at(this, param_1, param_2);
    if (item >= top_line && item <= bot_line) {
        list_scroll_cur_line(this, 1, item, 1);
    }
    return 1;
}

long TListPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    (void)param_3;
    (void)param_4;
    capture_mouse();
    list_scroll_cur_line(this, 1, list_item_at(this, param_1, param_2), 1);
    return 1;
}

long TListPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    (void)param_3;
    (void)param_4;

    const long y1 = pnl_y;
    const long y2 = pnl_y + pnl_hgt - 1;

    if (param_2 >= y1 && param_2 <= y2) {
        mouse_scroll_up = 0;
        mouse_scroll_down = 0;
        list_scroll_cur_line(this, 1, list_item_at(this, param_1, param_2), 1);
        return 1;
    }

    const unsigned long now = debug_timeGetTime((char*)"C:/msdev/work/age1_x1/Pnl_lst.cpp", 0xb1);
    if (param_2 < y1) {
        mouse_scroll_down = 0;
        if (!mouse_scroll_up) {
            mouse_scroll_up = 1;
            mouse_scroll_last_time = now - mouse_scroll_interval;
        }
        return 1;
    }

    mouse_scroll_up = 0;
    if (!mouse_scroll_down) {
        mouse_scroll_down = 1;
        mouse_scroll_last_time = now - mouse_scroll_interval;
    }
    return 1;
}

long TListPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;

    release_mouse();
    mouse_scroll_up = 0;
    mouse_scroll_down = 0;

    if (parent_panel && cur_line >= 0 && cur_line < num_lines) {
        parent_panel->action(this, 2, (ulong)cur_line, 0);
    }
    return 1;
}

long TListPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    (void)param_3;
    (void)param_4;
    list_scroll_cur_line(this, 1, list_item_at(this, param_1, param_2), 1);

    if (parent_panel && cur_line >= 0 && cur_line < num_lines) {
        parent_panel->action(this, 3, (ulong)cur_line, 0);
    }
    return 1;
}

long TListPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;

    switch (param_1) {
    case 0x21:
        list_scroll_cur_line(this, 5, 0, 1);
        return 1;
    case 0x22:
        list_scroll_cur_line(this, 4, 0, 1);
        return 1;
    case 0x23:
        list_scroll_cur_line(this, 7, 0, 1);
        return 1;
    case 0x24:
        list_scroll_cur_line(this, 6, 0, 1);
        return 1;
    case 0x26:
        list_scroll_cur_line(this, 3, 0, 1);
        return 1;
    case 0x28:
        list_scroll_cur_line(this, 2, 0, 1);
        return 1;
    case 0x0d:
        if (parent_panel && cur_line >= 0 && cur_line < num_lines) {
            parent_panel->action(this, 3, (ulong)cur_line, 0);
        }
        return 1;
    default:
        return 0;
    }
}

long TListPanel::char_action(long param_1, short param_2) {
    (void)param_2;
    const int want = toupper((int)param_1);
    if (num_lines <= 0) {
        return 0;
    }

    int start = (int)cur_line + 1;
    for (int i = start; i < num_lines; ++i) {
        char* text = get_text(i);
        if (text && text[0] != '\0' && toupper((unsigned char)text[0]) == want) {
            list_scroll_cur_line(this, 1, (short)i, 1);
            return 1;
        }
    }

    for (int i = 0; i < start && i < num_lines; ++i) {
        char* text = get_text(i);
        if (text && text[0] != '\0' && toupper((unsigned char)text[0]) == want) {
            list_scroll_cur_line(this, 1, (short)i, 1);
            return 1;
        }
    }

    return 0;
}

long TListPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    return TTextPanel::action(param_1, param_2, param_3, param_4);
}

void TListPanel::draw() {
    if (!render_area || !active || !visible) {
        return;
    }

    const int saved_focus = have_focus;
    const int saved_mouse_captured = mouse_captured;
    have_focus = 0;
    mouse_captured = 0;
    TTextPanel::draw();
    have_focus = saved_focus;
    mouse_captured = saved_mouse_captured;

    list_draw_highlight_bar(this);

    if (!drawHighlightBar || !(saved_focus || saved_mouse_captured) ||
        cur_line < top_line || cur_line > bot_line) {
        return;
    }

    HDC hdc = (HDC)render_area->GetDc((char*)"pnl_lst::draw_selected_line");
    if (!hdc) {
        return;
    }

    if (clip_rgn) {
        SelectClipRgn(hdc, (HRGN)clip_rgn);
    }
    HGDIOBJ old_font = font ? SelectObject(hdc, (HGDIOBJ)font) : nullptr;
    SetBkMode(hdc, TRANSPARENT);
    list_draw_line(this, hdc, (short)(cur_line - top_line), cur_line, highlightTextColor1, highlightTextColor2);
    if (old_font) {
        SelectObject(hdc, old_font);
    }
    SelectClipRgn(hdc, 0);
    render_area->ReleaseDc((char*)"pnl_lst::draw_selected_line");
}

void TListPanel::set_focus(int param_1) {
    TPanel::set_focus(param_1);
    if (parent_panel && cur_line >= 0 && cur_line < num_lines) {
        parent_panel->action(this, 1, (ulong)cur_line, 0);
    }
}

// Virtual method stubs
long TListPanel::setup(TDrawArea* a, TPanel* p, long x, long y, long w, long h, uchar c) {
    return TTextPanel::setup(a, p, x, y, w, h, c);
}

void TListPanel::set_rect(tagRECT r) { TTextPanel::set_rect(r); }
void TListPanel::set_rect(long x, long y, long w, long h) { TTextPanel::set_rect(x, y, w, h); }
void TListPanel::set_color(uchar c) { TTextPanel::set_color(c); }
void TListPanel::set_active(int a) { TTextPanel::set_active(a); }
void TListPanel::set_positioning(PositionMode m, long p1, long p2, long p3, long p4, long p5, long p6, long p7, long p8, TPanel* t1, TPanel* t2, TPanel* t3, TPanel* t4) {
    TTextPanel::set_positioning(m, p1, p2, p3, p4, p5, p6, p7, p8, t1, t2, t3, t4);
}
void TListPanel::set_fixed_position(long x, long y, long w, long h) { TTextPanel::set_fixed_position(x, y, w, h); }
void TListPanel::set_redraw(RedrawMode m) { TTextPanel::set_redraw(m); }
void TListPanel::set_overlapped_redraw(TPanel* p1, TPanel* p2, RedrawMode m) { TTextPanel::set_overlapped_redraw(p1, p2, m); }
void TListPanel::draw_setup(int p) { TTextPanel::draw_setup(p); }
void TListPanel::draw_finish() { TTextPanel::draw_finish(); }
void TListPanel::draw_rect(tagRECT* r) { TTextPanel::draw_rect(r); }
void TListPanel::draw_offset(long x, long y, tagRECT* r) { TTextPanel::draw_offset(x, y, r); }
void TListPanel::draw_rect2(tagRECT* r) { TTextPanel::draw_rect2(r); }
void TListPanel::draw_offset2(long x, long y, tagRECT* r) { TTextPanel::draw_offset2(x, y, r); }
void TListPanel::paint() { TTextPanel::paint(); }
long TListPanel::wnd_proc(void* h, uint m, uint w, long l) { return TTextPanel::wnd_proc(h, m, w, l); }
long TListPanel::handle_size(long w, long h) { return TTextPanel::handle_size(w, h); }
long TListPanel::handle_paint() { return TTextPanel::handle_paint(); }
long TListPanel::handle_key_down(long k, short s, int p1, int p2, int p3) { return key_down_action(k, s, p1, p2, p3); }
long TListPanel::handle_char(long p1, short p2) { return char_action(p1, p2); }
long TListPanel::handle_command(uint c, long p) { return TTextPanel::handle_command(c, p); }
long TListPanel::handle_user_command(uint c, long p) { return TTextPanel::handle_user_command(c, p); }
long TListPanel::handle_timer_command(uint c, long p) { return TTextPanel::handle_timer_command(c, p); }
long TListPanel::handle_scroll(long p1, long p2) { return TTextPanel::handle_scroll(p1, p2); }
long TListPanel::handle_mouse_down(uchar b, long x, long y, int p1, int p2) { return TPanel::handle_mouse_down(b, x, y, p1, p2); }
long TListPanel::handle_mouse_move(long x, long y, int p1, int p2) { return TPanel::handle_mouse_move(x, y, p1, p2); }
long TListPanel::handle_mouse_up(uchar b, long x, long y, int p1, int p2) { return TPanel::handle_mouse_up(b, x, y, p1, p2); }
long TListPanel::handle_mouse_dbl_click(uchar b, long x, long y, int p1, int p2) {
    if (b == 1) {
        return mouse_left_dbl_click_action(x, y, p1, p2);
    }
    return mouse_right_dbl_click_action(x, y, p1, p2);
}
long TListPanel::mouse_left_hold_action(long x, long y, int p1, int p2) { return TTextPanel::mouse_left_hold_action(x, y, p1, p2); }
long TListPanel::mouse_right_down_action(long x, long y, int p1, int p2) { return TTextPanel::mouse_right_down_action(x, y, p1, p2); }
long TListPanel::mouse_right_hold_action(long x, long y, int p1, int p2) { return TTextPanel::mouse_right_hold_action(x, y, p1, p2); }
long TListPanel::mouse_right_move_action(long x, long y, int p1, int p2) { return TTextPanel::mouse_right_move_action(x, y, p1, p2); }
long TListPanel::mouse_right_up_action(long x, long y, int p1, int p2) { return TTextPanel::mouse_right_up_action(x, y, p1, p2); }
long TListPanel::mouse_right_dbl_click_action(long x, long y, int p1, int p2) { return TTextPanel::mouse_right_dbl_click_action(x, y, p1, p2); }
void TListPanel::get_true_render_rect(tagRECT* r) { TTextPanel::get_true_render_rect(r); }
int TListPanel::is_inside(long x, long y) { return TTextPanel::is_inside(x, y); }
void TListPanel::set_tab_order(TPanel* p1, TPanel* p2) { TTextPanel::set_tab_order(p1, p2); }
void TListPanel::set_tab_order(TPanel** p, short s) { TTextPanel::set_tab_order(p, s); }
uchar TListPanel::get_help_info(char** p1, long* p2, long p3, long p4) { return TTextPanel::get_help_info(p1, p2, p3, p4); }
void TListPanel::stop_sound_system() { TTextPanel::stop_sound_system(); }
int TListPanel::restart_sound_system() { return TTextPanel::restart_sound_system(); }
void TListPanel::take_snapshot() { TTextPanel::take_snapshot(); }
void TListPanel::handle_reactivate() { TTextPanel::handle_reactivate(); }
void TListPanel::set_text(char** p, short s) { TTextPanel::set_text(p, s); }
void TListPanel::set_text(long l) { TTextPanel::set_text(l); }
void TListPanel::set_text(char* s) { TTextPanel::set_text(s); }
