#include "../include/pnl_lst.h"

extern "C" int __cdecl toupper(int c);

TListPanel::TListPanel() : drawHighlightBar(1) {
    field_C0 = 0;
    mouse_scroll_last_time = 0;
    mouse_scroll_up = 0;
    mouse_scroll_down = 0;
    auto_track = 0;
    field_EE = 4;
    field_170 = 1;
    mouse_scroll_interval = 0x32;
    field_80 = 1;
    spacer_size = 1;
    border_size = 1;
}

TListPanel::~TListPanel() {
}

void TListPanel::set_auto_track(int v) {
    this->auto_track = v;
}

void TListPanel::set_bevel_info(int param_1, int param_2, int param_3,
                                int param_4, int param_5, int param_6,
                                int param_7) {
    switch (param_1) {
    case 3:
    case 6:
        this->spacer_size = 2;
        break;
    case 4:
    case 7:
        this->spacer_size = 3;
        break;
    case 1:
    case 2:
    case 5:
        this->spacer_size = 1;
        break;
    default:
        this->spacer_size = 1;
        break;
    }

    TTextPanel::set_bevel_info(param_1, param_2, param_3, param_4,
                               param_5, param_6, param_7);
    if (this->border_size == 0) {
        this->border_size = 1;
        ((TTextPanel*)this)->calc_draw_info(1);
    }
}

long TListPanel::handle_idle() {
    TPanel::handle_idle();
    if (this->mouse_scroll_up == 0 && this->mouse_scroll_down == 0)
        return 0;

    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 0x6C);
    if (now - this->mouse_scroll_last_time < (unsigned long)this->mouse_scroll_interval)
        return 0;

    this->mouse_scroll_last_time = now;

    if (this->mouse_scroll_up != 0) {
        if (this->cur_line != this->top_line)
            this->scroll_cur_line(1, this->top_line, 1);
        this->scroll_cur_line(3, 0, 1);
        return 0;
    }

    if (this->cur_line != this->bot_line)
        this->scroll_cur_line(1, this->bot_line, 1);
    this->scroll_cur_line(2, 0, 1);
    return 0;
}

long TListPanel::mouse_move_action(long param_1, long param_2, int, int) {
    if (this->auto_track == 0) {
        return 0;
    }

    if (this->is_inside(param_1, param_2) == 0) {
        return 0;
    }

    short item = this->item_at(param_1, param_2);
    if (item < this->item_min) {
        return 1;
    }
    if (item > this->item_max) {
        return 1;
    }
    this->goto_item(param_1, param_2);

    return 1;
}

long TListPanel::mouse_left_down_action(long p1, long p2, int p3, int p4) {
    capture_mouse();
    goto_item(p1, p2);
    return 1;
}

long TListPanel::mouse_left_move_action(long param_1, long param_2, int param_3,
                                        int param_4) {
    if (param_2 >= this->pnl_y) {
        if (param_2 < this->pnl_y + this->pnl_hgt) {
            this->mouse_scroll_up = 0;
            this->mouse_scroll_down = 0;
            this->goto_item(param_1, param_2);
            return 1;
        }
    }

    if (param_2 < this->pnl_y) {
        this->mouse_scroll_down = 0;
        if (this->mouse_scroll_up != 0)
            return 1;
        this->mouse_scroll_up = 1;
        this->mouse_scroll_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 0xB1) - this->mouse_scroll_interval;
        return 1;
    } else {
        if (param_2 > this->pnl_y + this->pnl_hgt - 1) {
            this->mouse_scroll_up = 0;
            if (this->mouse_scroll_down != 0)
                return 1;
            this->mouse_scroll_down = 1;
            this->mouse_scroll_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 0xBA) - this->mouse_scroll_interval;
            return 1;
        } else {
            this->mouse_scroll_up = 0;
            this->mouse_scroll_down = 0;
            return 1;
        }
    }
}

long TListPanel::mouse_left_up_action(long param_1, long param_2, int param_3,
                                      int param_4) {
    release_mouse();
    this->mouse_scroll_up = 0;
    this->mouse_scroll_down = 0;
    if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 2, this->cur_line, 0);
    }
    return 1;
}

long TListPanel::mouse_left_dbl_click_action(long param_1, long param_2,
                                             int param_3, int param_4) {
    this->goto_item(param_1, param_2);
    if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 3, this->cur_line, 0);
    }
    return 1;
}

short TListPanel::item_at(long, long param_2) {
    int rowsize = this->spacer_size;
    if (rowsize == 0) {
        rowsize = this->text_hgt;
    } else {
        rowsize = this->text_hgt + rowsize + rowsize - 1;
    }

    return (short)((((param_2 - this->border_size) - this->pnl_y) - this->spacer_size) / rowsize) + this->top_line;
}

void TListPanel::goto_item(long p1, long p2) {
    scroll_cur_line(1, item_at(p1, p2), 1);
}

long TListPanel::key_down_action(long vk, short param_2, int param_3, int param_4,
                                 int param_5) {
    switch (vk) {
    case 0x28:
        this->scroll_cur_line(2, 0, 1);
        return 1;
    case 0x26:
        this->scroll_cur_line(3, 0, 1);
        return 1;
    case 0x23:
        this->scroll_cur_line(4, 0, 1);
        return 1;
    case 0x24:
        this->scroll_cur_line(5, 0, 1);
        return 1;
    case 0x21:
        this->scroll_cur_line(6, 0, 1);
        return 1;
    case 0x22:
        this->scroll_cur_line(7, 0, 1);
        return 1;
    case 0x0D:
        if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
            this->parent_panel->action(this, 3, this->cur_line, 0);
        }
        return 1;
    }
    return 0;
}

long TListPanel::char_action(long param_1, short param_2) {
    int ch = toupper((int)param_1);
    TextNode* node = this->list;
    int i = 0;

    while (node != 0) {
        if (i > (int)(short)this->cur_line) {
            if (toupper((int)*node->text) == ch)
                goto found;
        }
        i++;
        node = node->next;
    }

    if ((int)(short)this->cur_line > 0) {
        node = this->list;
        i = 0;
        while (node != 0) {
            if (toupper((int)*node->text) == ch)
                goto found;
            i++;
            if (i >= (int)(short)this->cur_line)
                return 0;
            node = node->next;
        }
    }

    return 0;

found:
    this->scroll_cur_line(1, (short)i, 1);
    return 1;
}

long TListPanel::action(TPanel* panel, long value, unsigned long index,
                        unsigned long zero) {
    return TTextPanel::action(panel, value, index, zero);
}

void TListPanel::scroll_cur_line(unsigned char action, short line, int flag) {
    short old_cur = this->cur_line;

    switch (action) {
    case 1: {
        short new_cur = line;
        this->cur_line = new_cur;
        if (new_cur < 0) {
            this->cur_line = 0;
        } else if (new_cur > this->num_lines - 1) {
            this->cur_line = this->num_lines - 1;
        }
        if (this->cur_line < this->top_line) {
            this->scroll(1, this->cur_line, flag);
        } else if (this->cur_line > this->bot_line) {
            this->scroll(0, this->cur_line - this->bot_line, flag);
        }
        break;
    }
    case 2: {
        short cur = this->cur_line;
        if (cur < this->top_line || cur > this->bot_line) {
            this->cur_line = this->bot_line;
        }
        cur = this->cur_line;
        if (cur < this->bot_line) {
            cur++;
            this->cur_line = cur;
        } else if (cur < this->num_lines - 1) {
            cur++;
            this->cur_line = cur;
            this->scroll(2, 0, flag);
        }
        break;
    }
    case 3: {
        short cur = this->cur_line;
        if (cur < this->top_line || cur > this->bot_line) {
            this->cur_line = this->top_line;
        }
        cur = this->cur_line;
        if (cur > this->top_line) {
            cur--;
            this->cur_line = cur;
        } else if (cur > 0) {
            cur--;
            this->cur_line = cur;
            this->scroll(3, 0, flag);
        }
        break;
    }
    case 4: {
        short cur = this->cur_line;
        if (cur < this->top_line || cur > this->bot_line) {
            this->cur_line = this->bot_line;
        }
        if (this->cur_line == this->bot_line) {
            this->scroll(4, 0, flag);
            this->cur_line = this->bot_line;
        } else {
            this->cur_line = this->bot_line;
        }
        break;
    }
    case 5: {
        short cur = this->cur_line;
        if (cur < this->top_line || cur > this->bot_line) {
            this->cur_line = this->top_line;
        }
        if (this->cur_line == this->top_line) {
            this->scroll(5, 0, flag);
            this->cur_line = this->top_line;
        } else {
            this->cur_line = this->top_line;
        }
        break;
    }
    case 6:
        this->scroll(6, 0, flag);
        this->cur_line = this->top_line;
        break;
    case 7:
        this->scroll(7, 0, flag);
        this->cur_line = this->bot_line;
        break;
    }

    this->set_redraw(1);

    if (this->cur_line != old_cur) {
        if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
            this->parent_panel->action(this, 1, this->cur_line, 0);
        }
    }
}

void TListPanel::draw() {
    this->need_redraw = 0;
    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        return;
    }

    this->draw_background();
    this->draw_setup(0);

    void* dc = this->render_area->GetDc(s_pnl_lst__draw);
    if (dc != 0) {
        SelectClipRgn(dc, this->clip_rgn);
        void* old_font = SelectObject(dc, this->font);
        SetBkMode(dc, 1);

        for (short line = this->top_line, line_index = 0;
             line <= this->bot_line; ++line, ++line_index) {
            if (this->drawHighlightBar != 0 &&
                (this->have_focus != 0 || this->mouse_captured != 0) &&
                line_index + this->top_line == this->cur_line) {
                this->draw_line(dc, line_index, line,
                                this->highlightTextColor1,
                                this->highlightTextColor2);
            } else {
                this->draw_line(dc, line_index, line,
                                this->text_color1, this->text_color2);
            }
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc(s_pnl_lst__draw);
    }

    this->draw_border();
    this->draw_highlight_bar();
    this->draw_finish();
}

void TListPanel::draw_highlight_bar() {
    if (this->drawHighlightBar == 0)
        return;

    if (this->cur_line < this->top_line)
        return;
    if (this->cur_line > this->bot_line)
        return;

    void* dc = this->render_area->GetDc(s_pnl_lst__draw_highlight_bar);
    if (dc != 0) {
        tagRECT rect;
        this->calc_line_pos(dc, this->cur_line - this->top_line, this->cur_line,
                            &rect, 0);
        this->render_area->ReleaseDc(s_pnl_lst__draw_highlight_bar);

        if (this->render_area->Lock(s_pnl_lst__draw_highlight_bar, 1) != 0) {
            long left = this->pnl_x + this->border_size;
            long right = this->pnl_x + this->pnl_wid - this->border_size - 1;
            long top = rect.top - this->spacer_size;
            long bottom = rect.bottom + this->spacer_size;

            switch (this->bevel_type) {
            case 0:
            case 1:
                this->render_area->DrawRect(left, top, right, bottom, 0xFF);
                break;
            case 5:
                this->render_area->DrawBevel(
                    left, top, right, bottom,
                    this->bevel_color6, this->bevel_color1);
                break;
            case 6:
                this->render_area->DrawBevel2(
                    left, top, right, bottom,
                    this->bevel_color6, this->bevel_color5,
                    this->bevel_color2, this->bevel_color1);
                break;
            case 7:
                this->render_area->DrawBevel3(
                    left, top, right, bottom,
                    this->bevel_color6, this->bevel_color5,
                    this->bevel_color4, this->bevel_color3,
                    this->bevel_color2, this->bevel_color1);
                break;
            case 2:
                this->render_area->DrawBevel(
                    left, top, right, bottom,
                    this->bevel_color1, this->bevel_color6);
                break;
            case 3:
                this->render_area->DrawBevel2(
                    left, top, right, bottom,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color5, this->bevel_color6);
                break;
            case 4:
                this->render_area->DrawBevel3(
                    left, top, right, bottom,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color3, this->bevel_color4,
                    this->bevel_color5, this->bevel_color6);
                break;
            }
        }
    }

    this->render_area->Unlock(s_pnl_lst__draw_highlight_bar);
}

void TListPanel::setDrawHighlightBar(int v) {
    this->drawHighlightBar = v;
}

void TListPanel::set_focus(int focus) {
    TPanel::set_focus(focus);
    if (this->have_focus != 0 && this->parent_panel != 0 &&
        this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 1, this->cur_line, 0);
    }
}
