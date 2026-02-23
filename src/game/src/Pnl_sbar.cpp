#include "../include/TScrollBarPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TShape.h"
#include "../include/TTextPanel.h"
#include "../include/debug_helpers.h"

#include <windows.h>

namespace {

static int sbar_rect_valid(const tagRECT& r) {
    return (r.left != r.right) && (r.top != r.bottom);
}

static int sbar_is_inside_rect(const tagRECT& r, long x, long y) {
    return (x >= r.left && x <= r.right && y >= r.top && y <= r.bottom) ? 1 : 0;
}

static void sbar_calc_item_rects(TScrollBarPanel* self) {
    if (!self) {
        return;
    }

    if (self->orientationValue == TScrollBarPanel::Horizontal) {
        self->tab_rect.left = self->tab_x;
        self->tab_rect.right = self->tab_x + self->tabSize - 5;

        self->top_rect.left = self->up_rect.right + 1;
        self->top_rect.right = self->tab_x - 1;

        self->bottom_rect.left = self->tab_rect.right + 1;
        self->bottom_rect.right = self->down_rect.left - 1;
        return;
    }

    self->tab_rect.top = self->tab_y;
    self->tab_rect.bottom = self->tab_y + self->tabSize - 5;

    self->top_rect.top = self->up_rect.bottom + 1;
    self->top_rect.bottom = self->tab_y - 1;

    self->bottom_rect.top = self->tab_rect.bottom + 1;
    self->bottom_rect.bottom = self->down_rect.top - 1;
}

static void sbar_draw_border(TScrollBarPanel* self, int border_type, int reverse, long left, long top, long right, long bottom) {
    if (!self || !self->render_area) {
        return;
    }
    if (left == right || top == bottom) {
        return;
    }

    if (reverse == 0) {
        switch (self->bevel_type) {
        case 1:
            if (border_type != 0) {
                self->render_area->DrawVertLine(right, top + 1, bottom - top, 0);
                self->render_area->DrawHorzLine(left + 1, top, right - left, 0);
                self->render_area->DrawRect(left, top, right - 1, bottom - 1, 0xff);
            } else {
                self->render_area->DrawRect(left, top, right - 1, bottom, 0);
            }
            return;
        case 2:
            self->render_area->DrawBevel(left, top, right, bottom, self->bevel_color1, self->bevel_color6);
            return;
        case 3:
            self->render_area->DrawBevel2(left, top, right, bottom,
                self->bevel_color1, self->bevel_color2, self->bevel_color5, self->bevel_color6);
            return;
        case 4:
            self->render_area->DrawBevel3(left, top, right, bottom,
                self->bevel_color1, self->bevel_color2, self->bevel_color3,
                self->bevel_color4, self->bevel_color5, self->bevel_color6);
            return;
        default:
            return;
        }
    }

    switch (self->bevel_type) {
    case 1:
        if (border_type != 0) {
            self->render_area->DrawRect(left + 1, top + 1, right, bottom, 0xff);
        } else {
            self->render_area->DrawRect(left, top, right - 1, bottom, 0xff);
        }
        return;
    case 2:
        self->render_area->DrawBevel(left, top, right, bottom, self->bevel_color6, self->bevel_color1);
        return;
    case 3:
        self->render_area->DrawBevel2(left, top, right, bottom,
            self->bevel_color6, self->bevel_color5, self->bevel_color2, self->bevel_color1);
        return;
    case 4:
        self->render_area->DrawBevel3(left, top, right, bottom,
            self->bevel_color6, self->bevel_color5, self->bevel_color4,
            self->bevel_color3, self->bevel_color2, self->bevel_color1);
        return;
    default:
        return;
    }
}

static void sbar_draw_border(TScrollBarPanel* self, int border_type, int reverse, const tagRECT& r) {
    sbar_draw_border(self, border_type, reverse, r.left, r.top, r.right, r.bottom);
}

static void sbar_draw_back_pic(TScrollBarPanel* self) {
    if (!self || !self->button_pics || self->back_frame == -1) {
        return;
    }

    long x_min = 0;
    long y_min = 0;
    long x_max = 0;
    long y_max = 0;
    self->button_pics->shape_minmax(&x_min, &y_min, &x_max, &y_max, self->back_frame);

    const int pic_w = (int)((x_max - x_min) + 1);
    const int pic_h = (int)((y_max - y_min) + 1);
    if (pic_w <= 0 || pic_h <= 0) {
        return;
    }

    for (int y = 0; y <= self->pnl_hgt; y += pic_h) {
        for (int x = 0; x <= self->pnl_wid; x += pic_w) {
            self->button_pics->shape_draw(self->render_area,
                self->pnl_x + x,
                self->pnl_y + y,
                self->back_frame,
                0,
                (uchar*)0);
        }
    }
}

static void sbar_draw_button_pic(TScrollBarPanel* self, int frame, int pressed, const tagRECT& r) {
    if (!self) {
        return;
    }

    if (self->button_pics && frame != -1) {
        self->render_area->SetClipRect((tagRECT*)&r);

        long x_min = 0;
        long y_min = 0;
        long x_max = 0;
        long y_max = 0;
        self->button_pics->shape_minmax(&x_min, &y_min, &x_max, &y_max, frame);

        const int shape_w = (int)((x_max - x_min) + 1);
        const int shape_h = (int)((y_max - y_min) + 1);
        short draw_x = (short)(r.left + (((r.right - r.left + 1) - shape_w) / 2) - x_min);
        short draw_y = (short)(r.top + (((r.bottom - r.top + 1) - shape_h) / 2) - y_min);

        if (pressed) {
            ++draw_x;
            --draw_y;
        }

        self->button_pics->shape_draw(self->render_area,
            (int)draw_x,
            (int)draw_y,
            frame + (pressed ? 1 : 0),
            0,
            (uchar*)0);
        return;
    }

    if (self->parent_panel) {
        self->parent_panel->draw_rect2((tagRECT*)&r);
    }
}

} // namespace

void TScrollBarPanel::calc_item_rects() {
    sbar_calc_item_rects(this);
}

void TScrollBarPanel::draw_back_pic() {
    sbar_draw_back_pic(this);
}

void TScrollBarPanel::draw_button_pic(int frame, int pressed, tagRECT* r) {
    if (!r) {
        return;
    }
    sbar_draw_button_pic(this, frame, pressed, *r);
}

void TScrollBarPanel::draw_border(int border_type, int reverse, tagRECT* r) {
    if (!r) {
        return;
    }
    sbar_draw_border(this, border_type, reverse, *r);
}

TScrollBarPanel::TScrollBarPanel() : TPanel() {
    list_panel = nullptr;
    list_len = 0;
    one_step = 0;
    page_step = 0;
    list_num = 0;
    button_pics = nullptr;
    back_frame = 0;
    up_frame = 0;
    down_frame = 0;
    tab_frame = 0;
    arrowSize = 0;
    tabSize = 0;
    tab_y = 0;
    tab_min_y = 0;
    tab_max_y = 0;
    tab_mouse_y = 0;
    tab_x = 0;
    tab_min_x = 0;
    tab_max_x = 0;
    tab_mouse_x = 0;
    item_down = 0;
    item_is_down = 0;
    item_x = 0;
    item_y = 0;
    item_mode = 0;
    item_last_time = 0;
    item_hold_interval = 100;
    item_down_interval = 250;
    SetRect(&up_rect, 0, 0, 0, 0);
    SetRect(&down_rect, 0, 0, 0, 0);
    SetRect(&tab_rect, 0, 0, 0, 0);
    SetRect(&top_rect, 0, 0, 0, 0);
    SetRect(&bottom_rect, 0, 0, 0, 0);
    orientationValue = Vertical;
    bevel_type = 1;
    bevel_color1 = 0;
    bevel_color2 = 0;
    bevel_color3 = 0;
    bevel_color4 = 0;
    bevel_color5 = 0;
    bevel_color6 = 0;
    panel_type = 5;
}

TScrollBarPanel::~TScrollBarPanel() {
}

long TScrollBarPanel::setup(TDrawArea* a, TPanel* p, long x, long y, long w, long h, uchar c) {
    return TPanel::setup(a, p, x, y, w, h, c);
}

long TScrollBarPanel::setup(TDrawArea* draw_area, TPanel* parent, long x, long y, long wid, long hgt,
                          char* pic1, char* pic2, char* pic3, char* pic4,
                          long arrow_hgt, long tab_hgt, TPanel* list, int list_len_value,
                          Orientation orientation) {
    (void)pic1;
    (void)pic2;
    (void)pic3;
    (void)pic4;

    orientationValue = orientation;
    arrowSize = arrow_hgt;
    tabSize = tab_hgt;
    list_panel = list;
    list_len = list_len_value;

    TPanel::setup(draw_area, parent, x, y, wid, hgt, '\0');
    return 1;
}

void TScrollBarPanel::set_rect(tagRECT r) {
    set_rect(r.left, r.top, (r.right - r.left) + 1, (r.bottom - r.top) + 1);
}

void TScrollBarPanel::set_rect(long x, long y, long w, long h) {
    TPanel::set_rect(x, y, w, h);

    if (orientationValue == Horizontal) {
        const long base_top = pnl_y + 2;
        const long track_bottom = pnl_y + pnl_hgt - 5;

        up_rect.left = pnl_x + 2;
        up_rect.top = base_top;
        up_rect.right = (pnl_x + 2) + pnl_hgt - 5;
        up_rect.bottom = track_bottom;

        const long down_left = (pnl_x + pnl_wid - pnl_hgt) + 2;
        down_rect.left = down_left;
        down_rect.top = base_top;
        down_rect.right = down_left + pnl_hgt - 5;
        down_rect.bottom = track_bottom;

        tab_rect.top = base_top;
        tab_rect.bottom = track_bottom;
        top_rect.top = base_top;
        top_rect.bottom = track_bottom;
        bottom_rect.top = base_top;
        bottom_rect.bottom = track_bottom;

        tab_min_x = up_rect.right + 1;
        tab_max_x = (down_left - pnl_hgt) + 4;
        tab_x = tab_min_x;
        sbar_calc_item_rects(this);
        return;
    }

    const long base_left = pnl_x + 2;
    const long track_right = pnl_x + pnl_wid - 5;

    up_rect.left = base_left;
    up_rect.top = pnl_y + 2;
    up_rect.right = track_right;
    up_rect.bottom = (pnl_y + 2) + pnl_wid - 5;

    const long down_top = (pnl_y + pnl_hgt - pnl_wid) + 2;
    down_rect.left = base_left;
    down_rect.top = down_top;
    down_rect.right = track_right;
    down_rect.bottom = down_top + pnl_wid - 5;

    tab_rect.left = base_left;
    top_rect.left = base_left;
    bottom_rect.left = base_left;
    tab_rect.right = track_right;
    top_rect.right = track_right;
    bottom_rect.right = track_right;

    tab_max_y = (down_top - pnl_wid) + 4;
    tab_min_y = up_rect.bottom + 1;
    tab_y = tab_min_y;
    sbar_calc_item_rects(this);
}

void TScrollBarPanel::set_color(uchar c) { TPanel::set_color(c); }
void TScrollBarPanel::set_active(int a) { TPanel::set_active(a); }
void TScrollBarPanel::set_positioning(PositionMode m, long p1, long p2, long p3, long p4, long p5, long p6, long p7, long p8, TPanel* r1, TPanel* r2, TPanel* r3, TPanel* r4) {
    TPanel::set_positioning(m, p1, p2, p3, p4, p5, p6, p7, p8, r1, r2, r3, r4);
}
void TScrollBarPanel::set_fixed_position(long x, long y, long w, long h) { TPanel::set_fixed_position(x, y, w, h); }
void TScrollBarPanel::set_redraw(RedrawMode m) { TPanel::set_redraw(m); }
void TScrollBarPanel::set_overlapped_redraw(TPanel* p1, TPanel* p2, RedrawMode m) { TPanel::set_overlapped_redraw(p1, p2, m); }
void TScrollBarPanel::draw_setup(int p) { TPanel::draw_setup(p); }
void TScrollBarPanel::draw_finish() { TPanel::draw_finish(); }

void TScrollBarPanel::set_tab_pos(long list_index) {
    list_num = list_index;

    if (orientationValue == Horizontal) {
        if (list_len > 0) {
            tab_x = ((((tabSize / 2) + tab_max_x) - tab_min_x) * list_index) / list_len + tab_min_x;
        }
        if (tab_x < tab_min_x) {
            tab_x = tab_min_x;
        } else if (tab_x > tab_max_x) {
            tab_x = tab_max_x;
        }
    } else {
        if (list_len > 0) {
            if (list_index == list_len - 1) {
                tab_y = tab_max_y;
            } else {
                tab_y = ((((tabSize / 2) + tab_max_y) - tab_min_y) * list_index) / list_len + tab_min_y;
            }
        }
        if (tab_y < tab_min_y) {
            tab_y = tab_min_y;
        } else if (tab_y > tab_max_y) {
            tab_y = tab_max_y;
        }
    }

    sbar_calc_item_rects(this);
    set_redraw(TPanel::RedrawMode::Redraw);
}

void TScrollBarPanel::set_list_len(long list_len_value, long list_index) {
    list_len = list_len_value;
    set_tab_pos(list_index);
}

void TScrollBarPanel::set_buttons(TShape* pics, int back, int up, int down, int tab) {
    button_pics = pics;
    back_frame = back;
    up_frame = up;
    down_frame = down;
    tab_frame = tab;
}

void TScrollBarPanel::set_bevel_info(int type, unsigned char c1, unsigned char c2,
                                     unsigned char c3, unsigned char c4,
                                     unsigned char c5, unsigned char c6) {
    bevel_type = type;
    bevel_color1 = c1;
    bevel_color2 = c2;
    bevel_color3 = c3;
    bevel_color4 = c4;
    bevel_color5 = c5;
    bevel_color6 = c6;
}

long TScrollBarPanel::handle_idle() {
    unsigned long now;

    if (item_mode == 1) {
        now = debug_timeGetTime((char*)"C:/msdev/work/age1_x1/Pnl_scbr.cpp", 0x128);
        if ((now - item_last_time) >= item_down_interval) {
            item_mode = 2;
            item_last_time = now - item_hold_interval;
        }
    } else if (item_mode == 2 && item_is_down != 0) {
        now = debug_timeGetTime((char*)"C:/msdev/work/age1_x1/Pnl_scbr.cpp", 0x132);
        if ((now - item_last_time) >= item_hold_interval) {
            item_last_time = now;
            switch (item_down) {
            case 1:
                scroll(ActionUp, 0);
                return 0;
            case 2:
                scroll(ActionDown, 0);
                return 0;
            case 4:
                if (!sbar_is_inside_rect(top_rect, item_x, item_y)) {
                    item_is_down = 0;
                    item_mode = 0;
                    set_redraw(TPanel::RedrawMode::Redraw);
                    return 0;
                }
                scroll(ActionPrior, 0);
                return 0;
            case 5:
                if (!sbar_is_inside_rect(bottom_rect, item_x, item_y)) {
                    item_is_down = 0;
                    item_mode = 0;
                    set_redraw(TPanel::RedrawMode::Redraw);
                    return 0;
                }
                scroll(ActionNext, 0);
                return 0;
            default:
                break;
            }
        }
    }

    return 0;
}

long TScrollBarPanel::handle_size(long w, long h) { return TPanel::handle_size(w, h); }
long TScrollBarPanel::handle_paint() { return TPanel::handle_paint(); }
long TScrollBarPanel::handle_key_down(long k, short s, int p1, int p2, int p3) { return TPanel::handle_key_down(k, s, p1, p2, p3); }
long TScrollBarPanel::handle_char(long p1, short p2) { return TPanel::handle_char(p1, p2); }
long TScrollBarPanel::handle_command(uint c, long p) { return TPanel::handle_command(c, p); }
long TScrollBarPanel::handle_user_command(uint c, long p) { return TPanel::handle_user_command(c, p); }
long TScrollBarPanel::handle_timer_command(uint c, long p) { return TPanel::handle_timer_command(c, p); }
long TScrollBarPanel::handle_scroll(long p1, long p2) { return TPanel::handle_scroll(p1, p2); }
long TScrollBarPanel::handle_mouse_down(uchar b, long x, long y, int p1, int p2) { return TPanel::handle_mouse_down(b, x, y, p1, p2); }
long TScrollBarPanel::handle_mouse_move(long x, long y, int p1, int p2) { return TPanel::handle_mouse_move(x, y, p1, p2); }
long TScrollBarPanel::handle_mouse_up(uchar b, long x, long y, int p1, int p2) { return TPanel::handle_mouse_up(b, x, y, p1, p2); }
long TScrollBarPanel::handle_mouse_dbl_click(uchar b, long x, long y, int p1, int p2) { return TPanel::handle_mouse_dbl_click(b, x, y, p1, p2); }
long TScrollBarPanel::mouse_move_action(long x, long y, int p1, int p2) { return TPanel::mouse_move_action(x, y, p1, p2); }

long TScrollBarPanel::mouse_left_down_action(long x, long y, int p1, int p2) {
    (void)p1;
    (void)p2;

    capture_mouse();

    if (sbar_is_inside_rect(up_rect, x, y)) {
        item_down = 1;
        item_is_down = 1;
        scroll(ActionUp, 0);
    } else if (sbar_is_inside_rect(down_rect, x, y)) {
        item_down = 2;
        item_is_down = 1;
        scroll(ActionDown, 0);
    } else if (sbar_is_inside_rect(tab_rect, x, y)) {
        item_down = 3;
        if (orientationValue == Horizontal) {
            tab_mouse_x = x - tab_x;
        } else {
            tab_mouse_y = y - tab_y;
        }
    } else if (sbar_is_inside_rect(top_rect, x, y)) {
        item_down = 4;
        item_is_down = 1;
        scroll(ActionPrior, 0);
    } else if (sbar_is_inside_rect(bottom_rect, x, y)) {
        item_down = 5;
        item_is_down = 1;
        scroll(ActionNext, 0);
    } else {
        item_down = 0;
    }

    if (item_down != 0) {
        if (list_panel && list_panel->tab_stop && list_panel->parent_panel) {
            list_panel->parent_panel->set_curr_child(list_panel);
        }
        item_x = x;
        item_y = y;
        item_mode = 1;
        item_last_time = debug_timeGetTime((char*)"C:/msdev/work/age1_x1/Pnl_scbr.cpp", 0x185);
        set_redraw(TPanel::RedrawMode::Redraw);
    }

    return 0;
}

long TScrollBarPanel::mouse_left_hold_action(long x, long y, int p1, int p2) {
    return TPanel::mouse_left_hold_action(x, y, p1, p2);
}

long TScrollBarPanel::mouse_left_move_action(long x, long y, int p1, int p2) {
    (void)p1;
    (void)p2;

    switch (item_down) {
    case 1:
        if (!sbar_is_inside_rect(up_rect, x, y)) {
            if (item_is_down) {
                item_is_down = 0;
                item_mode = 0;
                set_redraw(TPanel::RedrawMode::Redraw);
            }
            break;
        }
        if (!item_is_down) {
            item_is_down = 1;
            item_mode = 2;
            item_last_time = debug_timeGetTime((char*)"C:/msdev/work/age1_x1/Pnl_scbr.cpp", 0x19a);
            scroll(ActionUp, 0);
            set_redraw(TPanel::RedrawMode::Redraw);
        }
        break;

    case 2:
        if (!sbar_is_inside_rect(down_rect, x, y)) {
            if (item_is_down) {
                item_is_down = 0;
                item_mode = 0;
                set_redraw(TPanel::RedrawMode::Redraw);
            }
            break;
        }
        if (!item_is_down) {
            item_is_down = 1;
            item_mode = 2;
            item_last_time = debug_timeGetTime((char*)"C:/msdev/work/age1_x1/Pnl_scbr.cpp", 0x1ad);
            scroll(ActionDown, 0);
            set_redraw(TPanel::RedrawMode::Redraw);
        }
        break;

    case 3:
        if (orientationValue == Horizontal) {
            int delta = (int)(x - item_x);
            if (((tab_x == tab_min_x) && (delta > 0) && (x < tab_mouse_x + tab_x)) ||
                ((tab_x == tab_max_x) && (delta < 0) && (tab_mouse_x + tab_x <= x))) {
                delta = 0;
            }
            if (delta == 0) {
                break;
            }

            tab_x += delta;
            if (tab_x < tab_min_x) {
                tab_x = tab_min_x;
            } else if (tab_x > tab_max_x) {
                tab_x = tab_max_x;
            }

            sbar_calc_item_rects(this);
            set_redraw(TPanel::RedrawMode::Redraw);

            long pos = 0;
            if (tab_min_x != tab_max_x) {
                pos = ((tab_x - tab_min_x) * list_len) / (tab_max_x - tab_min_x);
                if (pos < 0) {
                    pos = 0;
                } else if (pos > list_len - 1) {
                    pos = list_len - 1;
                }
            }
            scroll(ActionPosition, pos);
        } else {
            int delta = (int)(y - item_y);
            if (((tab_y == tab_min_y) && (delta > 0) && (y < tab_mouse_y + tab_y)) ||
                ((tab_y == tab_max_y) && (delta < 0) && (tab_mouse_y + tab_y <= y))) {
                delta = 0;
            }
            if (delta == 0) {
                break;
            }

            tab_y += delta;
            if (tab_y < tab_min_y) {
                tab_y = tab_min_y;
            } else if (tab_y > tab_max_y) {
                tab_y = tab_max_y;
            }

            sbar_calc_item_rects(this);
            set_redraw(TPanel::RedrawMode::Redraw);

            long pos = 0;
            if (tab_min_y != tab_max_y) {
                pos = ((tab_y - tab_min_y) * list_len) / (tab_max_y - tab_min_y);
                if (pos < 0) {
                    pos = 0;
                } else if (pos > list_len - 1) {
                    pos = list_len - 1;
                }
            }
            scroll(ActionPosition, pos);
        }
        break;

    case 4:
        if (!sbar_is_inside_rect(top_rect, x, y)) {
            if (item_is_down) {
                item_is_down = 0;
                item_mode = 0;
                set_redraw(TPanel::RedrawMode::Redraw);
            }
            break;
        }
        if (!item_is_down) {
            item_is_down = 1;
            item_mode = 2;
            item_last_time = debug_timeGetTime((char*)"C:/msdev/work/age1_x1/Pnl_scbr.cpp", 0x1c0);
            scroll(ActionPrior, 0);
            set_redraw(TPanel::RedrawMode::Redraw);
        }
        break;

    case 5:
        if (!sbar_is_inside_rect(bottom_rect, x, y)) {
            if (item_is_down) {
                item_is_down = 0;
                item_mode = 0;
                set_redraw(TPanel::RedrawMode::Redraw);
            }
            break;
        }
        if (!item_is_down) {
            item_is_down = 1;
            item_mode = 2;
            item_last_time = debug_timeGetTime((char*)"C:/msdev/work/age1_x1/Pnl_scbr.cpp", 0x1d3);
            scroll(ActionNext, 0);
            set_redraw(TPanel::RedrawMode::Redraw);
        }
        break;

    default:
        break;
    }

    if (item_down != 0) {
        item_x = x;
        item_y = y;
    }

    return 0;
}

long TScrollBarPanel::mouse_left_up_action(long x, long y, int p1, int p2) {
    (void)x;
    (void)y;
    (void)p1;
    (void)p2;

    if (parent_panel) {
        parent_panel->action(this, 5, (ulong)list_num, 0);
    }

    release_mouse();
    item_down = 0;
    item_mode = 0;
    item_is_down = 0;
    set_redraw(TPanel::RedrawMode::Redraw);
    return 0;
}

long TScrollBarPanel::mouse_left_dbl_click_action(long x, long y, int p1, int p2) { return TPanel::mouse_left_dbl_click_action(x, y, p1, p2); }
long TScrollBarPanel::mouse_right_down_action(long x, long y, int p1, int p2) { return TPanel::mouse_right_down_action(x, y, p1, p2); }
long TScrollBarPanel::mouse_right_hold_action(long x, long y, int p1, int p2) { return TPanel::mouse_right_hold_action(x, y, p1, p2); }
long TScrollBarPanel::mouse_right_move_action(long x, long y, int p1, int p2) { return TPanel::mouse_right_move_action(x, y, p1, p2); }
long TScrollBarPanel::mouse_right_up_action(long x, long y, int p1, int p2) { return TPanel::mouse_right_up_action(x, y, p1, p2); }
long TScrollBarPanel::mouse_right_dbl_click_action(long x, long y, int p1, int p2) { return TPanel::mouse_right_dbl_click_action(x, y, p1, p2); }
long TScrollBarPanel::key_down_action(long k, short s, int p1, int p2, int p3) { return TPanel::key_down_action(k, s, p1, p2, p3); }
long TScrollBarPanel::char_action(long p1, short p2) { return TPanel::char_action(p1, p2); }
long TScrollBarPanel::action(TPanel* p, long a, ulong p3, ulong p4) { return TPanel::action(p, a, p3, p4); }
void TScrollBarPanel::get_true_render_rect(tagRECT* r) { TPanel::get_true_render_rect(r); }
int TScrollBarPanel::is_inside(long x, long y) { return TPanel::is_inside(x, y); }
void TScrollBarPanel::set_focus(int f) { TPanel::set_focus(f); }
void TScrollBarPanel::set_tab_order(TPanel* p1, TPanel* p2) { TPanel::set_tab_order(p1, p2); }
void TScrollBarPanel::set_tab_order(TPanel** p, short s) { TPanel::set_tab_order(p, s); }
uchar TScrollBarPanel::get_help_info(char** p1, long* p2, long p3, long p4) { return TPanel::get_help_info(p1, p2, p3, p4); }
void TScrollBarPanel::stop_sound_system() { TPanel::stop_sound_system(); }
int TScrollBarPanel::restart_sound_system() { return TPanel::restart_sound_system(); }
void TScrollBarPanel::take_snapshot() { TPanel::take_snapshot(); }
void TScrollBarPanel::handle_reactivate() { TPanel::handle_reactivate(); }

void TScrollBarPanel::scroll(ActionType action, long value) {
    if (list_panel) {
        list_panel->action(this, (long)action, (ulong)value, 0);
        return;
    }

    const long old_pos = list_num;
    long new_pos = value;

    switch (action) {
    case ActionUp:
        new_pos = old_pos - one_step;
        break;
    case ActionDown:
        new_pos = old_pos + one_step;
        break;
    case ActionPrior:
        new_pos = old_pos - page_step;
        break;
    case ActionNext:
        new_pos = old_pos + page_step;
        break;
    case ActionPosition:
        break;
    default:
        return;
    }

    if (new_pos < 0) {
        new_pos = 0;
    } else if (new_pos > list_len - 1) {
        new_pos = list_len - 1;
    }

    if (new_pos != old_pos) {
        set_tab_pos(new_pos);
        if (parent_panel) {
            parent_panel->action(this, 4, (ulong)new_pos, 0);
        }
    }
}

void TScrollBarPanel::draw() {
    if (!render_area || !visible || !active) {
        return;
    }

    if (parent_panel) {
        parent_panel->draw_rect2(&clip_rect);
    }

    draw_setup(0);
    if (render_area->Lock((char*)"pnl_scbr::draw", 1)) {
        sbar_draw_back_pic(this);
        sbar_draw_border(this, 0, 1, clip_rect);

        if (sbar_rect_valid(up_rect)) {
            const int pressed = (item_down == 1 && item_is_down != 0) ? 1 : 0;
            sbar_draw_button_pic(this, up_frame, pressed, up_rect);
            sbar_draw_border(this, 1, pressed, up_rect);
        }

        if (sbar_rect_valid(down_rect)) {
            const int pressed = (item_down == 2 && item_is_down != 0) ? 1 : 0;
            sbar_draw_button_pic(this, down_frame, pressed, down_rect);
            sbar_draw_border(this, 1, pressed, down_rect);
        }

        sbar_draw_button_pic(this, tab_frame, 0, tab_rect);
        sbar_draw_border(this, 1, 0, tab_rect);

        render_area->Unlock((char*)"pnl_scbr::draw");
    }
    draw_finish();
}

void TScrollBarPanel::draw_rect(tagRECT* r) { TPanel::draw_rect(r); }
void TScrollBarPanel::draw_offset(long x, long y, tagRECT* r) { TPanel::draw_offset(x, y, r); }
void TScrollBarPanel::draw_rect2(tagRECT* r) { TPanel::draw_rect2(r); }
void TScrollBarPanel::draw_offset2(long x, long y, tagRECT* r) { TPanel::draw_offset2(x, y, r); }
void TScrollBarPanel::paint() { TPanel::paint(); }
long TScrollBarPanel::wnd_proc(void* h, uint m, uint w, long l) { return TPanel::wnd_proc(h, m, w, l); }
