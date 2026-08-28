#include "../include/Pnl_scbr.h"

extern "C" unsigned long __cdecl debug_timeGetTime(const char*, int);

TScrollBarPanel::TScrollBarPanel()
    : TPanel(),
      list_panel(0),
      list_len(0),
      one_step(0),
      page_step(0),
      list_num(0),
      button_pics(0),
      back_frame(0),
      up_frame(0),
      down_frame(0),
      tab_frame(0),
      arrowSize(0),
      tabSize(0),
      tab_y(0),
      tab_min_y(0),
      tab_max_y(0),
      tab_mouse_y(0),
      tab_x(0),
      tab_min_x(0),
      tab_max_x(0),
      tab_mouse_x(0),
      item_down(0),
      item_is_down(0),
      item_x(0),
      item_y(0),
      item_mode(0),
      item_last_time(0),
      item_hold_interval(100),
      item_down_interval(250),
      orientationValue(Vertical),
      bevel_type(1),
      bevel_color1(0),
      bevel_color2(0),
      bevel_color3(0),
      bevel_color4(0),
      bevel_color5(0),
      bevel_color6(0)
{
    this->panel_type = 5;
    this->mouse_move_tolerance = 0;
    SetRect(&this->up_rect, 0, 0, 0, 0);
    SetRect(&this->down_rect, 0, 0, 0, 0);
    SetRect(&this->tab_rect, 0, 0, 0, 0);
    SetRect(&this->top_rect, 0, 0, 0, 0);
    SetRect(&this->bottom_rect, 0, 0, 0, 0);
}

TScrollBarPanel::~TScrollBarPanel() {
}

long TScrollBarPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6,
                            char* param_7, char* param_8, char* param_9, char* param_10,
                            long param_11, long param_12, TPanel* param_13, long param_14,
                            TScrollBarPanel::Orientation param_15) {
    long result;

    this->orientationValue = param_15;
    this->arrowSize = param_11;
    this->tabSize = param_12;
    this->list_panel = param_13;
    this->list_len = param_14;
    result = this->TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0);
    result = 1;
    return result;
}

#include <new.h>

void TScrollBarPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    TPanel::set_rect(param_1, param_2, param_3, param_4);

    if (this->orientationValue == Horizontal) {
        const long base_top = this->pnl_y + 2;
        const long track_bottom = this->pnl_y + this->pnl_hgt - 5;

        this->up_rect.left = this->pnl_x + 2;
        this->up_rect.top = base_top;
        this->up_rect.right = (this->pnl_x + 2) + this->pnl_hgt - 5;
        this->up_rect.bottom = track_bottom;

        const long down_left = (this->pnl_x + this->pnl_wid - this->pnl_hgt) + 2;
        this->down_rect.left = down_left;
        this->down_rect.top = base_top;
        this->down_rect.right = down_left + this->pnl_hgt - 5;
        this->down_rect.bottom = track_bottom;

        this->tab_rect.top = base_top;
        this->tab_rect.bottom = track_bottom;
        this->top_rect.top = base_top;
        this->top_rect.bottom = track_bottom;
        this->bottom_rect.top = base_top;
        this->bottom_rect.bottom = track_bottom;

        this->tab_min_x = this->up_rect.right + 1;
        this->tab_max_x = (down_left - this->pnl_hgt) + 4;
        this->tab_x = this->tab_min_x;
    } else {
        const long base_left = this->pnl_x + 2;
        const long track_right = this->pnl_x + this->pnl_wid - 5;

        this->up_rect.left = base_left;
        this->up_rect.top = this->pnl_y + 2;
        this->up_rect.right = track_right;
        this->up_rect.bottom = (this->pnl_y + 2) + this->pnl_wid - 5;

        const long down_top = (this->pnl_y + this->pnl_hgt - this->pnl_wid) + 2;
        this->down_rect.left = base_left;
        this->down_rect.top = down_top;
        this->down_rect.right = track_right;
        this->down_rect.bottom = down_top + this->pnl_wid - 5;

        this->tab_rect.left = base_left;
        this->top_rect.left = base_left;
        this->bottom_rect.left = base_left;
        this->tab_rect.right = track_right;
        this->top_rect.right = track_right;
        this->bottom_rect.right = track_right;

        this->tab_max_y = (down_top - this->pnl_wid) + 4;
        this->tab_min_y = this->up_rect.bottom + 1;
        this->tab_y = this->tab_min_y;
    }

    this->calc_item_rects();
}

void TScrollBarPanel::calc_item_rects()
{
    int x, w, r, dl;

    if (this->orientationValue == 1) {
        x = this->tab_x;
        w = this->pnl_hgt;
        r = this->up_rect.right;
        this->tab_rect.left = x;
        w = w + x - 5;
        x--;
        this->tab_rect.right = w;
        this->top_rect.right = x;
        dl = this->down_rect.left;
        r++;
        w++;
        dl--;
        this->top_rect.left = r;
        this->bottom_rect.left = w;
        this->bottom_rect.right = dl;
    } else {
        x = this->tab_y;
        w = this->pnl_wid;
        r = this->up_rect.bottom;
        this->tab_rect.top = x;
        w = w + x - 5;
        x--;
        this->tab_rect.bottom = w;
        this->top_rect.bottom = x;
        dl = this->down_rect.top;
        r++;
        w++;
        dl--;
        this->top_rect.top = r;
        this->bottom_rect.top = w;
        this->bottom_rect.bottom = dl;
    }
}

void TScrollBarPanel::set_tab_pos(long pos) {
    this->list_num = (int)pos;

    if (this->orientationValue == 1) {
        if (this->list_len > 0) {
            int half = this->tabSize / 2;
            this->tab_x = ((half + this->tab_max_x - this->tab_min_x) * (int)pos) / this->list_len + this->tab_min_x;
        }

        if (this->tab_x < this->tab_min_x) {
            this->tab_x = this->tab_min_x;
        } else if (this->tab_x > this->tab_max_x) {
            this->tab_x = this->tab_max_x;
        }
    } else {
        if (this->list_len > 0) {
            if ((int)pos == this->list_len - 1) {
                this->tab_y = this->tab_max_y;
            } else {
                int half = this->tabSize / 2;
                this->tab_y = ((half + this->tab_max_y - this->tab_min_y) * (int)pos) / this->list_len + this->tab_min_y;
            }
        }

        if (this->tab_y < this->tab_min_y) {
            this->tab_y = this->tab_min_y;
        } else if (this->tab_y > this->tab_max_y) {
            this->tab_y = this->tab_max_y;
        }
    }

    this->calc_item_rects();
    this->set_redraw(TPanel::RedrawNormal);
}

void TScrollBarPanel::set_list_len(long len, long position) {
    this->list_len = len;
    this->set_tab_pos(position);
}

void TScrollBarPanel::set_buttons(TShape* button_pics, int back_frame, int up_frame, int down_frame, int tab_frame) {
    this->button_pics = button_pics;
    this->back_frame = back_frame;
    this->up_frame = up_frame;
    this->down_frame = down_frame;
    this->tab_frame = tab_frame;
}

void TScrollBarPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6) {
    bevel_type = type;
    bevel_color1 = (unsigned char)c1;
    bevel_color2 = (unsigned char)c2;
    bevel_color3 = (unsigned char)c3;
    bevel_color4 = (unsigned char)c4;
    bevel_color5 = (unsigned char)c5;
    bevel_color6 = (unsigned char)c6;
}

long TScrollBarPanel::handle_idle() {
    switch (this->item_mode) {
    case 2: {
        if (this->item_is_down == 0) return 0;
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 306);
        if (now - this->item_last_time < this->item_hold_interval) return 0;
        this->item_last_time = now;
        switch (this->item_down) {
        case 1:
            this->scroll(ActionUp, 0); return 0;
        case 2:
            this->scroll(ActionDown, 0); return 0;
        case 3:
            if (!this->is_inside_rect(this->item_x, this->item_y, &this->top_rect)) {
                this->item_is_down = 0; this->item_mode = 0;
                this->set_redraw(TPanel::RedrawNormal);
                return 0;
            }
            this->scroll(ActionPrior, 0); return 0;
        case 4:
            this->scroll(ActionPrior, 0); return 0;
        case 5:
            if (!this->is_inside_rect(this->item_x, this->item_y, &this->bottom_rect)) {
                this->item_is_down = 0; this->item_mode = 0;
                this->set_redraw(TPanel::RedrawNormal);
                return 0;
            }
            this->scroll(ActionNext, 0); return 0;
        }
        break;
    }
    case 1: {
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 296);
        if (now - this->item_last_time >= this->item_down_interval) {
            this->item_mode = 2;
            this->item_last_time = now - this->item_hold_interval;
        }
        break;
    }
    }
    return 0;
}

long TScrollBarPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4)
{
    TPanel* p;

    this->capture_mouse();

    if (this->is_inside_rect(param_1, param_2, &this->up_rect)) {
        this->item_down = 1;
        this->item_is_down = 1;
        this->scroll(ActionUp, 0);
    } else if (this->is_inside_rect(param_1, param_2, &this->down_rect)) {
        this->item_down = 2;
        this->item_is_down = 1;
        this->scroll(ActionDown, 0);
    } else if (this->is_inside_rect(param_1, param_2, &this->tab_rect)) {
        this->item_down = 3;
        if (this->orientationValue == 1) {
            this->tab_mouse_x = param_1 - this->tab_x;
        } else {
            this->tab_mouse_y = param_2 - this->tab_y;
        }
    } else if (this->is_inside_rect(param_1, param_2, &this->top_rect)) {
        this->item_down = 4;
        this->item_is_down = 1;
        this->scroll(ActionPrior, 0);
    } else if (this->is_inside_rect(param_1, param_2, &this->bottom_rect)) {
        this->item_down = 5;
        this->item_is_down = 1;
        this->scroll(ActionNext, 0);
    } else {
        this->item_down = 0;
    }

    if (this->item_down) {
        p = this->list_panel;
        if (p && p->tab_stop && p->parent_panel) {
            p->parent_panel->set_curr_child(p);
        }
        this->item_x = param_1;
        this->item_y = param_2;
        this->item_mode = 1;
        this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 0x185);
        this->set_redraw(TPanel::RedrawNormal);
    }

    return 0;
}

long TScrollBarPanel::mouse_left_move_action(long x, long y, int key, int flags)
{
    int delta;
    long value;

    switch (this->item_down) {
    case 1:
        if (this->is_inside_rect(x, y, &this->up_rect)) {
            if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 0x19A);
                this->scroll(ActionUp, 0);
                this->set_redraw(TPanel::RedrawNormal);
            }
        } else if (this->item_is_down != 0) {
            this->item_is_down = 0;
            this->item_mode = 0;
            this->set_redraw(TPanel::RedrawNormal);
        }
        break;

    case 2:
        if (this->is_inside_rect(x, y, &this->down_rect)) {
            if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 0x1AD);
                this->scroll(ActionDown, 0);
                this->set_redraw(TPanel::RedrawNormal);
            }
        } else if (this->item_is_down != 0) {
            this->item_is_down = 0;
            this->item_mode = 0;
            this->set_redraw(TPanel::RedrawNormal);
        }
        break;

    case 4:
        if (this->is_inside_rect(x, y, &this->top_rect)) {
            if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 0x1C0);
                this->scroll(ActionPrior, 0);
                this->set_redraw(TPanel::RedrawNormal);
            }
        } else if (this->item_is_down != 0) {
            this->item_is_down = 0;
            this->item_mode = 0;
            this->set_redraw(TPanel::RedrawNormal);
        }
        break;

    case 5:
        if (this->is_inside_rect(x, y, &this->bottom_rect)) {
            if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 0x1D3);
                this->scroll(ActionNext, 0);
                this->set_redraw(TPanel::RedrawNormal);
            }
        } else if (this->item_is_down != 0) {
            this->item_is_down = 0;
            this->item_mode = 0;
            this->set_redraw(TPanel::RedrawNormal);
        }
        break;

    case 3:
        if (this->orientationValue == 1) {
            delta = x - this->item_x;
            if (delta > 0) {
                if ((this->tab_x == this->tab_min_x) &&
                    (x < this->tab_mouse_x + this->tab_x)) {
                    delta = 0;
                }
            }
            if (this->tab_x == this->tab_max_x) {
                if ((delta < 0) && (x >= this->tab_mouse_x + this->tab_x)) {
                    delta = 0;
                }
            }
            if (delta != 0) {
                this->tab_x += delta;
                if (this->tab_x < this->tab_min_x) {
                    this->tab_x = this->tab_min_x;
                } else if (this->tab_x > this->tab_max_x) {
                    this->tab_x = this->tab_max_x;
                }
                this->calc_item_rects();
                this->set_redraw(TPanel::RedrawNormal);
                if (this->tab_min_x == this->tab_max_x) {
                    value = 0;
                } else {
                    value = ((this->tab_x - this->tab_min_x) * this->list_len) /
                            (this->tab_max_x - this->tab_min_x);
                    if (value < 0) {
                        value = 0;
                    } else {
                        long max_value = this->list_len - 1;
                        if (value > max_value) {
                            value = max_value;
                        }
                    }
                }
                this->scroll(ActionPosition, value);
            }
        } else {
            delta = y;
            delta -= this->item_y;
            if (delta > 0) {
                if ((this->tab_y == this->tab_min_y) &&
                    (y < this->tab_mouse_y + this->tab_y)) {
                    delta = 0;
                }
            }
            if (this->tab_y == this->tab_max_y) {
                if ((delta < 0) && (y >= this->tab_mouse_y + this->tab_y)) {
                    delta = 0;
                }
            }
            if (delta != 0) {
                this->tab_y += delta;
                if (this->tab_y < this->tab_min_y) {
                    this->tab_y = this->tab_min_y;
                } else if (this->tab_y > this->tab_max_y) {
                    this->tab_y = this->tab_max_y;
                }
                this->calc_item_rects();
                    this->set_redraw(TPanel::RedrawNormal);
                if (this->tab_min_y == this->tab_max_y) {
                    value = 0;
                } else {
                    value = ((this->tab_y - this->tab_min_y) * this->list_len) /
                            (this->tab_max_y - this->tab_min_y);
                    if (value < 0) {
                        value = 0;
                    } else {
                        long max_value = this->list_len - 1;
                        if (value > max_value) {
                            value = max_value;
                        }
                    }
                }
                this->scroll(ActionPosition, value);
            }
        }
        break;
    }

    if (this->item_down != 0) {
        this->item_x = x;
        this->item_y = y;
    }
    return 0;
}

long TScrollBarPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    if (this->parent_panel != 0) {
        this->parent_panel->action(this, 5, this->list_num, 0);
    }
    this->release_mouse();
    this->item_down = 0;
    this->item_mode = 0;
    this->item_is_down = 0;
    this->set_redraw(TPanel::RedrawNormal);
    return 0;
}

void TScrollBarPanel::scroll(TScrollBarPanel::ActionType action, long param) {
    if (this->list_panel != 0) {
        this->list_panel->action(this, action, param, 0);
        return;
    }

    long val = this->list_num;

    switch (action) {
    case 0:
        val -= this->one_step;
        break;
    case 1:
        val += this->one_step;
        break;
    case 2:
        val -= this->page_step;
        break;
    case 3:
        val += this->page_step;
        break;
    case 4:
        val = param;
        break;
    default:
        return;
    }

    if (val < 0) {
        val = 0;
    } else {
        int max = this->list_len - 1;
        if (val > max)
            val = max;
    }

    if (val != this->list_num) {
        set_tab_pos(val);
        if (this->parent_panel != 0) {
            this->parent_panel->action(this, ActionPosition, val, 0);
        }
    }
}

void TScrollBarPanel::draw()
{
    if (this->parent_panel != 0) {
        this->parent_panel->draw_rect2(&this->clip_rect);
    }

    this->draw_setup(0);

    if (this->render_area->Lock("pnl_scbr::draw", 1)) {
        this->draw_back_pic();
        this->draw_border(0, 1, &this->render_rect);

        if (this->up_rect.top != this->up_rect.bottom && this->up_rect.left != this->up_rect.right) {
            this->draw_button_pic(this->up_frame, this->item_down == 1 && this->item_is_down, &this->up_rect);
            this->draw_border(1, this->item_down == 1 && this->item_is_down, &this->up_rect);
        }

        if (this->down_rect.top != this->down_rect.bottom && this->down_rect.left != this->down_rect.right) {
            this->draw_button_pic(this->down_frame, this->item_down == 2 && this->item_is_down, &this->down_rect);
            this->draw_border(1, this->item_down == 2 && this->item_is_down, &this->down_rect);
        }

        this->draw_button_pic(this->tab_frame, 0, &this->tab_rect);
        this->draw_border(1, 0, &this->tab_rect);

        this->render_area->Unlock("pnl_scbr::draw");
    }

    this->draw_finish();
}

void TScrollBarPanel::draw_border(int x, int y, tagRECT* rect) {
    draw_border(x, y, rect->left, rect->top, rect->right, rect->bottom);
}

void TScrollBarPanel::draw_border(int raised, int flag, long left, long top, long right, long bottom)
{
    if (left != right && top != bottom) {
        if (flag != 0) {
            switch (this->bevel_type) {
            case 1:
                if (raised != 0) {
                    this->render_area->DrawRect(left + 1, top + 1, right, bottom, 0xff);
                } else {
                    this->render_area->DrawRect(left, top, right - 1, bottom, 0xff);
                }
                return;
            case 2:
                this->render_area->DrawBevel(left, top, right, bottom, this->bevel_color6, this->bevel_color1);
                return;
            case 3:
                this->render_area->DrawBevel2(left, top, right, bottom, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1);
                return;
            case 4:
                this->render_area->DrawBevel3(left, top, right, bottom, this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
                return;
            }
        } else {
            switch (this->bevel_type) {
            case 1:
                if (raised != 0) {
                    this->render_area->DrawVertLine(right, top + 1, bottom - top, 0);
                    this->render_area->DrawHorzLine(left + 1, top, right - left, 0);
                    this->render_area->DrawRect(left, top, right - 1, top - 1, 0xff);
                } else {
                    this->render_area->DrawRect(left, top, right - 1, bottom, 0);
                }
                return;
            case 2:
                this->render_area->DrawBevel(left, top, right, bottom, this->bevel_color1, this->bevel_color6);
                return;
            case 3:
                this->render_area->DrawBevel2(left, top, right, bottom, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6);
                return;
            case 4:
                this->render_area->DrawBevel3(left, top, right, bottom, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                return;
            }
        }
    }
}

void TScrollBarPanel::draw_back_pic() {
    if (this->button_pics != 0 && this->back_frame != -1) {
        long x_min, y_max, pic_hgt, y_min;
        this->button_pics->shape_minmax(y_max, pic_hgt, x_min, y_min, this->back_frame);

        int row_step = (x_min - y_max) + 1;
        int col_step = (y_min - pic_hgt) + 1;
        int outer = 0;

        if (this->pnl_hgt >= 0) {
            do {
                int inner = 0;
                if (this->pnl_wid >= 0) {
                    do {
                        this->button_pics->shape_draw(
                            this->render_area,
                            this->pnl_x + inner,
                            this->pnl_y + outer,
                            this->back_frame, 0, 0);
                        inner += row_step;
                    } while (inner <= this->pnl_wid);
                }
                outer += col_step;
            } while (outer <= this->pnl_hgt);
        }
    }
}

#include <new.h>

void TScrollBarPanel::draw_button_pic(int param_1, int param_2, tagRECT* param_3)
{
    long x_min;
    long y_max;
    short x;
    short y;
    long y_min;
    long x_max;

    if (this->button_pics != 0 && param_1 != -1) {
        this->render_area->SetClipRect(param_3);

        this->button_pics->shape_minmax(y_max, x_max, x_min, y_min,
                                        param_1);

        x = (short)((param_3->right - param_3->left + 1) / 2) -
            (short)((x_min + (1 - y_max)) / 2);
        x -= (short)y_max;
        x += (short)param_3->left;
        y = (short)((param_3->bottom - param_3->top + 1) / 2) -
            (short)((y_min - x_max + 1) / 2) -
            (short)x_max + (short)param_3->top;

        if (param_2 != 0) {
            ++x;
            --y;
        }

        this->button_pics->shape_draw(this->render_area, x, y,
                                      param_1 + (param_2 != 0), 0, 0);
    } else {
        this->parent_panel->draw_rect2(param_3);
    }
}
