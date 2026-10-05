#include "../include/Pnl_scbr.h"

extern unsigned long __cdecl debug_timeGetTime(char*, int);

TScrollBarPanel::TScrollBarPanel() :
    TPanel(), list_panel(0), list_len(0), one_step(0), page_step(0), list_num(0), button_pics(0), back_frame(0),
    up_frame(0), down_frame(0), tab_frame(0), arrowSize(0), tabSize(0), tab_y(0), tab_min_y(0), tab_max_y(0),
    tab_mouse_y(0), tab_x(0), tab_min_x(0), tab_max_x(0), tab_mouse_x(0), item_down(0), item_is_down(0), item_x(0),
    item_y(0), item_mode(0), item_last_time(0), item_hold_interval(100), item_down_interval(250),
    orientationValue(Vertical), bevel_type(1), bevel_color1(0), bevel_color2(0), bevel_color3(0), bevel_color4(0),
    bevel_color5(0), bevel_color6(0) {
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

long TScrollBarPanel::setup(
    TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in,
    char* back_pic_in, char* up_pic_in, char* down_pic_in, char* tab_pic_in, long arrowSizeIn, long tabSizeIn,
    TPanel* list_panel_in, long list_len_in, TScrollBarPanel::Orientation orientation
) {
    long result;

    this->orientationValue = orientation;
    this->arrowSize = arrowSizeIn;
    this->tabSize = tabSizeIn;
    this->list_panel = list_panel_in;
    this->list_len = list_len_in;
    result = this->TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
    result = 1;
    return result;
}

#include <new.h>

void TScrollBarPanel::set_rect(long x_in, long y_in, long wid_in, long hgt_in) {
    TPanel::set_rect(x_in, y_in, wid_in, hgt_in);

    if (this->orientationValue == Horizontal) {
        const int base_top = this->pnl_y + 2;
        const int track_bottom = this->pnl_y + this->pnl_hgt - 5;

        this->up_rect.top = base_top;
        this->down_rect.top = base_top;

        this->up_rect.left = this->pnl_x + 2;
        this->up_rect.bottom = track_bottom;

        this->down_rect.left = (this->pnl_wid + this->pnl_x - this->pnl_hgt) + 2;
        this->up_rect.right = this->up_rect.left + this->pnl_hgt - 5;
        this->down_rect.bottom = track_bottom;
        this->down_rect.right = this->down_rect.left + this->pnl_hgt - 5;

        this->tab_rect.top = base_top;
        this->tab_rect.bottom = track_bottom;
        this->top_rect.top = base_top;
        this->top_rect.bottom = track_bottom;
        this->bottom_rect.top = base_top;
        this->bottom_rect.bottom = track_bottom;

        this->tab_min_x = this->up_rect.right + 1;
        this->tab_max_x = (this->down_rect.left - this->pnl_hgt) + 4;
        this->tab_x = this->tab_min_x;
    } else {
        this->up_rect.left = this->pnl_x + 2;
        this->up_rect.top = this->pnl_y + 2;
        this->up_rect.right = this->up_rect.left + this->pnl_wid - 5;
        this->up_rect.bottom = this->up_rect.top + this->pnl_wid - 5;

        this->down_rect.left = this->up_rect.left;
        this->down_rect.top = (this->pnl_hgt + this->pnl_y - this->pnl_wid) + 2;
        this->down_rect.right = this->up_rect.right;
        this->down_rect.bottom = this->down_rect.top + this->pnl_wid - 5;

        this->tab_rect.left = this->up_rect.left;
        this->top_rect.left = this->up_rect.left;
        this->bottom_rect.left = this->up_rect.left;
        const long tab_min = this->up_rect.bottom + 1;
        this->tab_max_y = (this->down_rect.top - this->pnl_wid) + 4;
        this->tab_rect.right = this->up_rect.right;
        this->top_rect.right = this->up_rect.right;
        this->bottom_rect.right = this->up_rect.right;

        this->tab_min_y = tab_min;
        this->tab_y = tab_min;
    }

    this->calc_item_rects();
}

void TScrollBarPanel::calc_item_rects() {
    int x, w, r, dl;
    tagRECT& tab = this->tab_rect;
    tagRECT& top = this->top_rect;
    tagRECT& bottom = this->bottom_rect;

    if (this->orientationValue == 1) {
        x = this->tab_x;
        w = this->pnl_hgt;
        r = this->up_rect.right;
        int top_left = r + 1;
        tab.left = x;
        w = w + x - 5;
        x--;
        tab.right = w;
        top.right = x;
        dl = this->down_rect.left;
        top.left = top_left;
        bottom.left = w + 1;
        bottom.right = dl - 1;
    } else {
        x = this->tab_y;
        w = this->pnl_wid;
        r = this->up_rect.bottom;
        int top_top = r + 1;
        tab.top = x;
        w = w + x - 5;
        x--;
        tab.bottom = w;
        top.bottom = x;
        dl = this->down_rect.top;
        top.top = top_top;
        bottom.top = w + 1;
        bottom.bottom = dl - 1;
    }
}

void TScrollBarPanel::set_tab_pos(long list_num_in) {
    this->list_num = list_num_in;

    if (this->orientationValue == Horizontal) {
        if (this->list_len > 0) {
            this->tab_x = ((this->tabSize / 2 + this->tab_max_x - this->tab_min_x) * list_num_in) / this->list_len
                          + this->tab_min_x;
        }

        if (this->tab_x < this->tab_min_x) {
            this->tab_x = this->tab_min_x;
        } else if (this->tab_x > this->tab_max_x) {
            this->tab_x = this->tab_max_x;
        }
    } else {
        if (this->list_len > 0) {
            if (list_num_in == this->list_len - 1) {
                this->tab_y = this->tab_max_y;
            } else {
                this->tab_y = ((this->tabSize / 2 + this->tab_max_y - this->tab_min_y) * list_num_in) / this->list_len
                              + this->tab_min_y;
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

void TScrollBarPanel::set_list_len(long list_len_in, long list_num_in) {
    this->list_len = list_len_in;
    this->set_tab_pos(list_num_in);
}

void TScrollBarPanel::set_buttons(
    TShape* button_pics_in, int back_frame_in, int up_frame_in, int down_frame_in, int tab_frame_in
) {
    this->button_pics = button_pics_in;
    this->back_frame = back_frame_in;
    this->up_frame = up_frame_in;
    this->down_frame = down_frame_in;
    this->tab_frame = tab_frame_in;
}

void TScrollBarPanel::set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6) {
    bevel_type = bevel_type_in;
    bevel_color1 = (unsigned char) c1;
    bevel_color2 = (unsigned char) c2;
    bevel_color3 = (unsigned char) c3;
    bevel_color4 = (unsigned char) c4;
    bevel_color5 = (unsigned char) c5;
    bevel_color6 = (unsigned char) c6;
}

long TScrollBarPanel::handle_idle() {
    switch (this->item_mode) {
        case 2: {
            if (this->item_is_down == 0)
                return 0;
            unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 306);
            if (now - this->item_last_time < this->item_hold_interval)
                return 0;
            this->item_last_time = now;
            switch (this->item_down) {
                case 1:
                    this->scroll(ActionUp, 0);
                    return 0;
                case 2:
                    this->scroll(ActionDown, 0);
                    return 0;
                case 3:
                    if (!this->is_inside_rect(this->item_x, this->item_y, &this->top_rect)) {
                        this->item_is_down = 0;
                        this->item_mode = 0;
                        this->set_redraw(TPanel::RedrawNormal);
                        return 0;
                    }
                    this->scroll(ActionPrior, 0);
                    return 0;
                case 4:
                    this->scroll(ActionPrior, 0);
                    return 0;
                case 5:
                    if (!this->is_inside_rect(this->item_x, this->item_y, &this->bottom_rect)) {
                        this->item_is_down = 0;
                        this->item_mode = 0;
                        this->set_redraw(TPanel::RedrawNormal);
                        return 0;
                    }
                    this->scroll(ActionNext, 0);
                    return 0;
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

long TScrollBarPanel::mouse_left_down_action(long x, long y, int ctrl_key, int shift_key) {
    TPanel* p;

    this->capture_mouse();

    if (this->is_inside_rect(x, y, &this->up_rect)) {
        this->item_down = 1;
        this->item_is_down = 1;
        this->scroll(ActionUp, 0);
    } else if (this->is_inside_rect(x, y, &this->down_rect)) {
        this->item_down = 2;
        this->item_is_down = 1;
        this->scroll(ActionDown, 0);
    } else if (this->is_inside_rect(x, y, &this->tab_rect)) {
        this->item_down = 3;
        if (this->orientationValue == 1) {
            this->tab_mouse_x = x - this->tab_x;
        } else {
            this->tab_mouse_y = y - this->tab_y;
        }
    } else if (this->is_inside_rect(x, y, &this->top_rect)) {
        this->item_down = 4;
        this->item_is_down = 1;
        this->scroll(ActionPrior, 0);
    } else if (this->is_inside_rect(x, y, &this->bottom_rect)) {
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
        this->item_x = x;
        this->item_y = y;
        this->item_mode = 1;
        this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 389);
        this->set_redraw(TPanel::RedrawNormal);
    }

    return 0;
}

long TScrollBarPanel::mouse_left_move_action(long x, long y, int ctrl_key, int shift_key) {
    long delta;
    long position;

    switch (this->item_down) {
        case 1:
            if (this->is_inside_rect(x, y, &this->up_rect) == 0) {
                if (this->item_is_down != 0) {
                    this->item_is_down = 0;
                    this->item_mode = 0;
                    this->set_redraw(TPanel::RedrawNormal);
                }
            } else if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 410);
                this->scroll(ActionUp, 0);
                this->set_redraw(TPanel::RedrawNormal);
            }
            break;

        case 2:
            if (this->is_inside_rect(x, y, &this->down_rect) == 0) {
                if (this->item_is_down != 0) {
                    this->item_is_down = 0;
                    this->item_mode = 0;
                    this->set_redraw(TPanel::RedrawNormal);
                }
            } else if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 429);
                this->scroll(ActionDown, 0);
                this->set_redraw(TPanel::RedrawNormal);
            }
            break;

        case 3:
            if (this->orientationValue == Horizontal) {
                delta = x - this->item_x;
                if (this->tab_x == this->tab_min_x && delta > 0 && x < this->tab_mouse_x + this->tab_x) {
                    delta = 0;
                } else if (this->tab_x == this->tab_max_x && delta < 0 && this->tab_mouse_x + this->tab_x <= x) {
                    delta = 0;
                }

                if (delta == 0) {
                    break;
                }

                this->tab_x += delta;
                if (this->tab_x < this->tab_min_x) {
                    this->tab_x = this->tab_min_x;
                } else if (this->tab_x > this->tab_max_x) {
                    this->tab_x = this->tab_max_x;
                }

                this->calc_item_rects();
                this->set_redraw(TPanel::RedrawNormal);

                if (this->tab_min_x == this->tab_max_x) {
                    position = 0;
                } else {
                    position = ((this->tab_x - this->tab_min_x) * this->list_len) / (this->tab_max_x - this->tab_min_x);
                    if (position < 0) {
                        position = 0;
                    } else if (position > this->list_len - 1) {
                        position = this->list_len - 1;
                    }
                }
            } else {
                delta = y - this->item_y;
                if (this->tab_y == this->tab_min_y && delta > 0 && y < this->tab_mouse_y + this->tab_y) {
                    delta = 0;
                } else if (this->tab_y == this->tab_max_y && delta < 0 && this->tab_mouse_y + this->tab_y <= y) {
                    delta = 0;
                }

                if (delta == 0) {
                    break;
                }

                this->tab_y += delta;
                if (this->tab_y < this->tab_min_y) {
                    this->tab_y = this->tab_min_y;
                } else if (this->tab_y > this->tab_max_y) {
                    this->tab_y = this->tab_max_y;
                }

                this->calc_item_rects();
                this->set_redraw(TPanel::RedrawNormal);

                if (this->tab_min_y == this->tab_max_y) {
                    position = 0;
                } else {
                    position = ((this->tab_y - this->tab_min_y) * this->list_len) / (this->tab_max_y - this->tab_min_y);
                    if (position < 0) {
                        position = 0;
                    } else if (position > this->list_len - 1) {
                        position = this->list_len - 1;
                    }
                }
            }
            this->scroll(ActionPosition, position);
            break;

        case 4:
            if (this->is_inside_rect(x, y, &this->top_rect) == 0) {
                if (this->item_is_down != 0) {
                    this->item_is_down = 0;
                    this->item_mode = 0;
                    this->set_redraw(TPanel::RedrawNormal);
                }
            } else if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 448);
                this->scroll(ActionPrior, 0);
                this->set_redraw(TPanel::RedrawNormal);
            }
            break;

        case 5:
            if (this->is_inside_rect(x, y, &this->bottom_rect) == 0) {
                if (this->item_is_down != 0) {
                    this->item_is_down = 0;
                    this->item_mode = 0;
                    this->set_redraw(TPanel::RedrawNormal);
                }
            } else if (this->item_is_down == 0) {
                this->item_is_down = 1;
                this->item_mode = 2;
                this->item_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 467);
                this->scroll(ActionNext, 0);
                this->set_redraw(TPanel::RedrawNormal);
            }
            break;
    }

    if (this->item_down != 0) {
        this->item_x = x;
        this->item_y = y;
    }

    return 0;
}

long TScrollBarPanel::mouse_left_up_action(long x, long y, int ctrl_key, int shift_key) {
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

void TScrollBarPanel::scroll(TScrollBarPanel::ActionType action, long val) {
    if (this->list_panel != 0) {
        this->list_panel->action(this, action, val, 0);
        return;
    }

    long new_position = this->list_num;

    switch (action) {
        case 0:
            new_position -= this->one_step;
            break;
        case 1:
            new_position += this->one_step;
            break;
        case 2:
            new_position -= this->page_step;
            break;
        case 3:
            new_position += this->page_step;
            break;
        case 4:
            new_position = val;
            break;
        default:
            return;
    }

    if (new_position < 0) {
        new_position = 0;
    } else {
        int max = this->list_len - 1;
        if (new_position > max)
            new_position = max;
    }

    if (new_position != this->list_num) {
        set_tab_pos(new_position);
        if (this->parent_panel != 0) {
            this->parent_panel->action(this, ActionPosition, new_position, 0);
        }
    }
}

void TScrollBarPanel::draw() {
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

void TScrollBarPanel::draw_border(int button, int down, tagRECT* rect) {
    draw_border(button, down, rect->left, rect->top, rect->right, rect->bottom);
}

void TScrollBarPanel::draw_border(int button, int down, long x1, long y1, long x2, long y2) {
    if (x1 != x2 && y1 != y2) {
        if (down != 0) {
            switch (this->bevel_type) {
                case 1:
                    if (button != 0) {
                        this->render_area->DrawRect(x1 + 1, y1 + 1, x2, y2, 0xff);
                    } else {
                        this->render_area->DrawRect(x1, y1, x2 - 1, y2, 0xff);
                    }
                    return;
                case 2:
                    this->render_area->DrawBevel(x1, y1, x2, y2, this->bevel_color6, this->bevel_color1);
                    return;
                case 3:
                    this->render_area->DrawBevel2(
                        x1, y1, x2, y2, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1
                    );
                    return;
                case 4:
                    this->render_area->DrawBevel3(
                        x1, y1, x2, y2, this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3,
                        this->bevel_color2, this->bevel_color1
                    );
                    return;
            }
        } else {
            switch (this->bevel_type) {
                case 1:
                    if (button != 0) {
                        this->render_area->DrawVertLine(x2, y1 + 1, y2 - y1, 0);
                        this->render_area->DrawHorzLine(x1 + 1, y1, x2 - x1, 0);
                        this->render_area->DrawRect(x1, y1, x2 - 1, y1 - 1, 0xff);
                    } else {
                        this->render_area->DrawRect(x1, y1, x2 - 1, y2, 0);
                    }
                    return;
                case 2:
                    this->render_area->DrawBevel(x1, y1, x2, y2, this->bevel_color1, this->bevel_color6);
                    return;
                case 3:
                    this->render_area->DrawBevel2(
                        x1, y1, x2, y2, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6
                    );
                    return;
                case 4:
                    this->render_area->DrawBevel3(
                        x1, y1, x2, y2, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4,
                        this->bevel_color5, this->bevel_color6
                    );
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
                            this->render_area, this->pnl_x + inner, this->pnl_y + outer, this->back_frame, 0, 0
                        );
                        inner += row_step;
                    } while (inner <= this->pnl_wid);
                }
                outer += col_step;
            } while (outer <= this->pnl_hgt);
        }
    }
}

#include <new.h>

void TScrollBarPanel::draw_button_pic(int frame, int down, tagRECT* rect) {
    long x_min;
    long y_max;
    short x;
    short y;
    long y_min;
    long x_max;

    if (this->button_pics != 0 && frame != -1) {
        this->render_area->SetClipRect(rect);

        this->button_pics->shape_minmax(y_max, x_max, x_min, y_min, frame);

        x = (short) ((rect->right - rect->left + 1) / 2) - (short) ((x_min + (1 - y_max)) / 2);
        x -= (short) y_max;
        x += (short) rect->left;
        y = (short) ((rect->bottom - rect->top + 1) / 2) - (short) ((y_min - x_max + 1) / 2) - (short) x_max
            + (short) rect->top;

        if (down != 0) {
            ++x;
            --y;
        }

        this->button_pics->shape_draw(this->render_area, x, y, frame + (down != 0), 0, 0);
    } else {
        this->parent_panel->draw_rect2(rect);
    }
}
