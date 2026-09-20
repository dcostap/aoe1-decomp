#include "../include/pnl_lst.h"

static char s_pnl_lst__draw[] = "pnl_lst::draw";
static char s_pnl_lst__draw_highlight_bar[] = "pnl_lst::draw_highlight_bar";

extern "C" int __cdecl toupper(int c);
extern unsigned long __cdecl debug_timeGetTime(char*, int);

TListPanel::TListPanel() : drawHighlightBar(1) {
    mouse_move_tolerance = 0;
    mouse_scroll_last_time = 0;
    mouse_scroll_up = 0;
    mouse_scroll_down = 0;
    auto_track = 0;
    panel_type = 4;
    bevel_type = 1;
    mouse_scroll_interval = 0x32;
    handle_mouse_input = 1;
    spacer_size = 1;
    border_size = 1;
}

TListPanel::~TListPanel() {
}

void TListPanel::set_auto_track(int auto_track_in) {
    this->auto_track = auto_track_in;
}

void TListPanel::set_bevel_info(int bevel_type_in, int c1, int c2, int c3,
                                int c4, int c5, int c6) {
    switch (bevel_type_in) {
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

    TTextPanel::set_bevel_info(bevel_type_in, c1, c2, c3, c4, c5, c6);
    if (this->border_size == 0) {
        this->border_size = 1;
        ((TTextPanel*)this)->calc_draw_info(1);
    }
}

long TListPanel::handle_idle() {
    TPanel::handle_idle();
    if (this->mouse_scroll_up == 0 && this->mouse_scroll_down == 0)
        return 0;

    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 108);
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

long TListPanel::mouse_move_action(long x, long y, int ctrl_key, int shift_key) {
    if (this->auto_track == 0) {
        return 0;
    }

    if (this->is_inside(x, y) == 0) {
        return 0;
    }

    short item = this->item_at(x, y);
    if (item < this->top_line) {
        return 1;
    }
    if (item > this->bot_line) {
        return 1;
    }
    this->goto_item(x, y);

    return 1;
}

long TListPanel::mouse_left_down_action(long x, long y, int ctrl_key, int shift_key) {
    capture_mouse();
    goto_item(x, y);
    return 1;
}

long TListPanel::mouse_left_move_action(long x, long y, int ctrl_key, int shift_key) {
    if (y >= this->pnl_y) {
        if (y < this->pnl_y + this->pnl_hgt) {
            this->mouse_scroll_up = 0;
            this->mouse_scroll_down = 0;
            this->goto_item(x, y);
            return 1;
        }
    }

    if (y < this->pnl_y) {
        this->mouse_scroll_down = 0;
        if (this->mouse_scroll_up != 0)
            return 1;
        this->mouse_scroll_up = 1;
        this->mouse_scroll_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 177) - this->mouse_scroll_interval;
        return 1;
    } else {
        if (y > this->pnl_y + this->pnl_hgt - 1) {
            this->mouse_scroll_up = 0;
            if (this->mouse_scroll_down != 0)
                return 1;
            this->mouse_scroll_down = 1;
            this->mouse_scroll_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 186) - this->mouse_scroll_interval;
            return 1;
        } else {
            this->mouse_scroll_up = 0;
            this->mouse_scroll_down = 0;
            return 1;
        }
    }
}

long TListPanel::mouse_left_up_action(long x, long y, int ctrl_key, int shift_key) {
    release_mouse();
    this->mouse_scroll_up = 0;
    this->mouse_scroll_down = 0;
    if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 2, this->cur_line, 0);
    }
    return 1;
}

long TListPanel::mouse_left_dbl_click_action(long x, long y, int ctrl_key, int shift_key) {
    this->goto_item(x, y);
    if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 3, this->cur_line, 0);
    }
    return 1;
}

short TListPanel::item_at(long x, long y) {
    int rowsize = this->spacer_size;
    if (rowsize == 0) {
        rowsize = this->text_hgt;
    } else {
        rowsize = this->text_hgt + rowsize + rowsize - 1;
    }

    return (short)((((y - this->border_size) - this->pnl_y) - this->spacer_size) / rowsize) + this->top_line;
}

void TListPanel::goto_item(long x, long y) {
    scroll_cur_line(1, item_at(x, y), 1);
}

long TListPanel::key_down_action(long key, short count, int alt_key, int ctrl_key,
                                 int shift_key) {
    switch (key) {
    case 0x28:
        this->scroll_cur_line(2, 0, 1);
        return 1;
    case 0x26:
        this->scroll_cur_line(3, 0, 1);
        return 1;
    case 0x22:
        this->scroll_cur_line(4, 0, 1);
        return 1;
    case 0x21:
        this->scroll_cur_line(5, 0, 1);
        return 1;
    case 0x24:
        this->scroll_cur_line(6, 0, 1);
        return 1;
    case 0x23:
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

long TListPanel::char_action(long key, short count) {
    int ch = toupper((int)key);
    TTextPanel::TextNode* node = this->list;
    int i = 0;

    while (node != 0) {
        if (i > (int)(short)this->cur_line) {
            if (toupper((int)*node->text) == ch)
                goto found;
        }
        i++;
        node = node->next_node;
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
            node = node->next_node;
        }
    }

    return 0;

found:
    this->scroll_cur_line(1, (short)i, 1);
    return 1;
}

long TListPanel::action(TPanel* from_panel, long action_in, unsigned long action_val1,
                        unsigned long action_val2) {
    return TTextPanel::action(from_panel, action_in, action_val1, action_val2);
}

void TListPanel::scroll_cur_line(unsigned char scroll_type, short scroll_val, int update_scrollbar) {
    short old_cur = this->cur_line;

    switch (scroll_type) {
    case 1: {
        short new_cur = scroll_val;
        this->cur_line = new_cur;
        if (new_cur < 0) {
            this->cur_line = 0;
        } else if (new_cur > this->num_lines - 1) {
            this->cur_line = this->num_lines - 1;
        }
        if (this->cur_line < this->top_line) {
            this->scroll(1, this->cur_line, update_scrollbar);
        } else if (this->cur_line > this->bot_line) {
            this->scroll(0, this->cur_line - this->bot_line, update_scrollbar);
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
            this->scroll(2, 0, update_scrollbar);
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
            this->scroll(3, 0, update_scrollbar);
        }
        break;
    }
    case 4: {
        short cur = this->cur_line;
        if (cur < this->top_line || cur > this->bot_line) {
            this->cur_line = this->bot_line;
        }
        if (this->cur_line == this->bot_line) {
            this->scroll(4, 0, update_scrollbar);
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
            this->scroll(5, 0, update_scrollbar);
            this->cur_line = this->top_line;
        } else {
            this->cur_line = this->top_line;
        }
        break;
    }
    case 6:
        this->scroll(6, 0, update_scrollbar);
        this->cur_line = this->top_line;
        break;
    case 7:
        this->scroll(7, 0, update_scrollbar);
        this->cur_line = this->bot_line;
        break;
    }

    this->set_redraw(TPanel::RedrawNormal);

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
        SetBkMode(dc, TRANSPARENT);

        for (short line = this->top_line, line_index = 0; line <= this->bot_line; ++line, ++line_index) {
            if (this->drawHighlightBar != 0 && (this->have_focus != 0 || this->mouse_captured != 0) &&
                line_index + this->top_line == this->cur_line) {
                this->draw_line(dc, line_index, line, this->highlightTextColor1, this->highlightTextColor2);
            } else {
                this->draw_line(dc, line_index, line, this->text_color1, this->text_color2);
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
        tagRECT r;
        this->calc_line_pos(dc, this->cur_line - this->top_line, this->cur_line, &r, 0);
        this->render_area->ReleaseDc(s_pnl_lst__draw_highlight_bar);

        if (this->render_area->Lock(s_pnl_lst__draw_highlight_bar, 1) != 0) {
            long x = this->pnl_x;
            long wid = this->pnl_wid;
            long border = this->border_size;
            long left = x + border;
            long right = x + wid - border - 1;
            long top = r.top - this->spacer_size;
            long bottom = r.bottom + this->spacer_size;

            switch (this->bevel_type) {
            case 0:
            case 1:
                this->render_area->DrawRect(left, top, right, bottom, 0xFF);
                break;
            case 5:
                this->render_area->DrawBevel(left, top, right, bottom, this->bevel_color6, this->bevel_color1);
                break;
            case 6:
                this->render_area->DrawBevel2(left, top, right, bottom, this->bevel_color6, this->bevel_color5,
                                              this->bevel_color2, this->bevel_color1);
                break;
            case 7:
                this->render_area->DrawBevel3(left, top, right, bottom, this->bevel_color6, this->bevel_color5,
                                              this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
                break;
            case 2:
                this->render_area->DrawBevel(left, top, right, bottom, this->bevel_color1, this->bevel_color6);
                break;
            case 3:
                this->render_area->DrawBevel2(left, top, right, bottom, this->bevel_color1, this->bevel_color2,
                                              this->bevel_color5, this->bevel_color6);
                break;
            case 4:
                this->render_area->DrawBevel3(left, top, right, bottom, this->bevel_color1, this->bevel_color2,
                                              this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                break;
            }
        }
    }

    this->render_area->Unlock(s_pnl_lst__draw_highlight_bar);
}

void TListPanel::setDrawHighlightBar(int v) {
    this->drawHighlightBar = v;
}

void TListPanel::set_focus(int have_focus_in) {
    TPanel::set_focus(have_focus_in);
    if (this->have_focus != 0 && this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 1, this->cur_line, 0);
    }
}
