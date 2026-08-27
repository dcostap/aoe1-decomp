#include "../include/pnl_drop.h"

TDropDownPanel::TDropDownPanel() : TPanel() {
    this->val_panel = 0;
    this->btn_panel = 0;
    this->list_panel = 0;
    this->scbar_panel = 0;
    this->mode = 0;
    this->val_num = 0;
    this->list_is_above = 0;
    this->draw_style = 0;
    this->panel_type = 6;
    this->draw_val_rect = 1;
}

TDropDownPanel::~TDropDownPanel() {
    this->delete_panel((TPanel**)&this->btn_panel);
    this->delete_panel((TPanel**)&this->list_panel);
    this->delete_panel((TPanel**)&this->scbar_panel);
    this->delete_panel((TPanel**)&this->val_panel);
}

long TDropDownPanel::setup(TDrawArea* area, TPanel* parent, void* p3, long p4, long p5, int p6, unsigned char p7,
                           int p8, unsigned char outline, long left, long top, long panel_width, long panel_height,
                           short p14, short p15, long btn_wid_param, long btn_hgt_param, char* p18,
                           long list_wid_param, long list_hgt_param, char** vals, short p22,
                           long scbar_wid_param, char* p24, char* p25, char* p26, char* p27,
                           long scbar_arrow_hgt_param, long scbar_tab_hgt_param) {
    long result;

    this->val_num = p15;
    this->btn_wid = btn_wid_param;
    this->val_wid = panel_width - btn_wid_param - 1;
    this->btn_hgt = btn_hgt_param;
    this->list_wid = list_wid_param;
    this->list_hgt = list_hgt_param;
    this->scbar_wid = scbar_wid_param;
    this->scbar_arrow_hgt = scbar_arrow_hgt_param;
    this->scbar_tab_hgt = scbar_tab_hgt_param;
    this->val_hgt = panel_height;
    this->font_hgt = p5;
    this->outline_color = outline;

    TPanel::setup(area, parent, left, top, panel_width, panel_height, 0);

    this->val_panel = new TTextPanel;
    result = (long)this->val_panel;
    if (result != 0 &&
        (result = this->val_panel->setup(area, this, 0, 0, this->val_wid, this->val_hgt,
                                         p3, p4, p5, (char*)0, p6, p7, p8, outline, p14,
                                         vals[(short)this->val_num])) != 0) {
        this->val_panel->set_alignment(0, 1);

        this->btn_panel = new TDropDownButtonPanel(this);
        result = (long)this->btn_panel;
        if (result != 0 &&
            (result = this->btn_panel->setup(area, this, 0, 0, this->btn_wid, this->btn_hgt,
                                             TButtonPanel::DrawBevelPicture, (TDigital*)0,
                                             TButtonPanel::NotifyAction, 0)) != 0) {
            this->list_panel = new TListPanel;
            result = (long)this->list_panel;
            if (result != 0 &&
                (result = this->list_panel->setup(area, this, 0, 0, this->list_wid, this->list_hgt,
                                                  p3, p4, p5, (char*)0, p6, p7, p8, outline, p14,
                                                  vals, p22)) != 0) {
                this->list_panel->set_auto_track(1);
                this->list_panel->set_active(0);
                ((TTextPanel*)this->list_panel)->setCurrentLineNumber(this->val_num);

                this->scbar_panel = new TScrollBarPanel;
                result = (long)this->scbar_panel;
                if (result != 0 &&
                    (result = this->scbar_panel->setup(this->render_area, this, 0, 0, this->scbar_wid, this->list_hgt,
                                                       s_, s_, s_, s_,
                                                       this->scbar_arrow_hgt, this->scbar_tab_hgt,
                                                       this->list_panel, (int)p22,
                                                       TScrollBarPanel::Vertical)) != 0) {
                    this->list_panel->set_scrollbar(this->scbar_panel, 0);
                    this->scbar_panel->set_active(0);
                    this->set_mode(ModeValue);
                    result = 1;
                }
            }
        }
    }
    return result;
}

void TDropDownPanel::draw() {
    TPanel::draw();
}

long TDropDownPanel::handle_mouse_down(unsigned char buttons, long x, long y, int param4, int param5) {
    if (this->tab_stop && this->parent_panel) {
        this->parent_panel->set_curr_child(this);
    }

    if (this->mode == 2) {
        long list_hit = this->list_panel->is_inside(x, y);
        long scbar_hit;
        if (this->scbar_panel) {
            scbar_hit = this->scbar_panel->is_inside(x, y);
        } else {
            scbar_hit = 0;
        }
        if (!list_hit && !scbar_hit) {
            this->set_mode(ModeValue);
            this->set_line(this->val_num);
            return 1;
        }
    }

    return TPanel::handle_mouse_down(buttons, x, y, param4, param5);
}

long TDropDownPanel::handle_mouse_move(long a, long b, int c, int d) {
    return TPanel::handle_mouse_move(a, b, c, d);
}

long TDropDownPanel::handle_mouse_up(unsigned char p1, long p2, long p3, int p4, int p5) {
    return TPanel::handle_mouse_up(p1, p2, p3, p4, p5);
}

long TDropDownPanel::handle_key_down(long key, short ch, int a3, int a4, int a5) {
    if (this->have_focus != 0 && (key == 0x28 || key == 0x26) && this->mode == 1) {
        this->set_mode(ModeList);
        return 1;
    }
    return TPanel::handle_key_down(key, ch, a3, a4, a5);
}

long TDropDownPanel::action(TPanel* panel, long action_code, unsigned long line, unsigned long param4) {
    if (panel == this->btn_panel) {
        if (action_code == 2) {
            if (this->mode == 1) {
                this->set_mode((DropdownMode)action_code);
            }
        }
    } else if (panel == (TPanel*)this->list_panel) {
        if (action_code == 3 || action_code == 2) {
            this->val_num = (short)line;
            this->val_panel->set_text(this->list_panel->get_text((long)(short)line));
            this->set_mode(ModeValue);
            if (this->parent_panel) {
                this->parent_panel->action(this, 0, 0, 0);
            }
        }
    }

    return TPanel::action(panel, action_code, line, param4);
}

void TDropDownPanel::set_rect(long p1, long p2, long p3, long p4) {
    TPanel::set_rect(p1, p2, p3, p4);

    if (this->mode == 1) {
        this->val_wid = (this->pnl_wid - this->btn_wid) - 1;
        this->val_hgt = this->pnl_hgt;
        this->set_mode(ModeNone);
        this->set_mode(ModeValue);
        return;
    }

    if (this->mode == 2) {
        this->list_wid = this->pnl_wid;
        this->list_hgt = (this->pnl_hgt - this->val_hgt) - 1;
        this->set_mode(ModeValue);
        this->set_mode(ModeList);
    }
}

void TDropDownPanel::set_val_text_color(unsigned long fg, unsigned long bg) {
    if (this->val_panel != 0) {
        this->val_panel->set_text_color(fg, bg);
    }
}

void TDropDownPanel::set_draw_style(TDropDownPanel::DrawStyle param_1) {
    this->draw_style = param_1;
    if (this->val_panel) {
        int old_mode = this->mode;
        this->mode = 0;
        this->set_mode((DropdownMode)old_mode);
    }
}

void TDropDownPanel::set_draw_val_rect(int value) {
    this->draw_val_rect = value;
    if (this->val_panel != 0) {
        this->val_panel->set_outline(value, this->outline_color);
        this->set_redraw(1);
    }
}

void TDropDownPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6) {
    if (this->val_panel != 0) {
        int mapped;
        switch (type) {
        case 1: mapped = 1; break;
        case 2: mapped = 5; break;
        case 3: mapped = 6; break;
        case 4: mapped = 7; break;
        default: mapped = 0; break;
        }
        this->val_panel->set_bevel_info(mapped, c1, c2, c3, c4, c5, c6);
    }

    if (this->list_panel != 0) {
        int mapped;
        switch (type) {
        case 1: mapped = 1; break;
        case 2: mapped = 2; break;
        case 3: mapped = 3; break;
        case 4: mapped = 4; break;
        default: mapped = 0; break;
        }
        this->list_panel->set_bevel_info(mapped, c1, c2, c3, c4, c5, c6);
    }

    if (this->scbar_panel != 0) {
        int mapped;
        switch (type) {
        case 1: mapped = 1; break;
        case 2: mapped = 2; break;
        case 3: mapped = 3; break;
        case 4: mapped = 4; break;
        default: mapped = 0; break;
        }
        this->scbar_panel->set_bevel_info(mapped, c1, c2, c3, c4, c5, c6);
    }

    if (this->btn_panel != 0) {
        int mapped;
        switch (type) {
        case 1: mapped = 1; break;
        case 2: mapped = 2; break;
        case 3: mapped = 3; break;
        case 4: mapped = 4; break;
        default: mapped = 0; break;
        }
        this->btn_panel->set_bevel_info(mapped, c1, c2, c3, c4, c5, c6);
    }
}

void TDropDownPanel::set_buttons(TShape* shape, int p2, int p3, int p4, int p5, int p6) {
    if (this->btn_panel != 0) {
        if (shape != 0) {
            this->btn_panel->set_picture(0, shape, (short)p2);
        } else {
            this->btn_panel->set_picture(0, 0, -1);
        }
    }
    if (this->scbar_panel != 0) {
        this->scbar_panel->set_buttons(shape, p3, p4, p5, p6);
    }
}

void TDropDownPanel::set_mode(TDropDownPanel::DropdownMode mode) {
    if (mode == this->mode) {
        return;
    }

    long parent_x = 0;
    long parent_y = 0;
    long parent_w = 0;
    long parent_h = 0;
    DropdownMode old_mode;
    if (this->parent_panel) {
        parent_x = this->parent_panel->xPosition();
        parent_y = this->parent_panel->yPosition();
        parent_w = this->parent_panel->width();
        parent_h = this->parent_panel->height();
    } else {
        parent_x = 0;
        parent_y = 0;
        parent_w = this->render_area->Width;
        parent_h = this->render_area->Height;
    }

    old_mode = (DropdownMode)this->mode;
    this->mode = (DropdownMode)ModeNone;

    if (mode == ModeValue) {
        if (old_mode == ModeList && this->parent_panel != 0 && this->parent_panel->parent_panel != 0) {
            if (this->clip_rect.left < parent_x || this->clip_rect.top < parent_y ||
                this->clip_rect.right > parent_w + parent_x - 1 ||
                this->clip_rect.bottom > parent_h + parent_y - 1) {
                this->parent_panel->parent_panel->set_redraw(2);
            }
        }
        this->list_panel->set_active(0);
        this->scbar_panel->set_active(0);
        if (this->draw_style == 1) {
            this->btn_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
            this->val_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
        } else {
            this->val_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, 0, 0, 0, 0);
            this->btn_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
        }
        this->clip_to_parent = 1;
        long value_wid = this->val_wid + this->btn_wid + 1;
        long value_hgt = this->val_hgt;
        if (this->list_is_above) {
            this->set_fixed_position(this->pnl_x - parent_x,
                                     this->pnl_y + this->pnl_hgt - this->val_hgt - old_mode,
                                     value_wid, value_hgt);
            this->list_is_above = 0;
        } else {
            this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - old_mode,
                                     value_wid, value_hgt);
        }
        if (this->parent_panel) {
            this->parent_panel->set_redraw(1);
        } else {
            this->set_redraw(1);
        }
        this->set_curr_child(this->val_panel);
        if (old_mode == ModeList) {
            if (panel_system.restorePreviousModalPanel() == 0) {
                panel_system.setModalPanel(0);
            }
            if (this->parent_panel) {
                this->parent_panel->action(this, 2, 0, 0);
                this->mode = mode;
                return;
            }
        }
    } else if (mode == ModeList) {
        this->list_panel->set_active(1);
        int spacer_size = this->list_panel->spacer_size;
        if (spacer_size == 0) {
            int border_size = this->list_panel->border_size;
            this->list_hgt = this->list_panel->numberLines() * (this->font_hgt + 2) +
                             border_size * 2;
        } else {
            int border_size = this->list_panel->border_size;
            this->list_hgt = this->list_panel->numberLines() * (this->font_hgt + 1 +
                             spacer_size * 2) + border_size * 2;
        }
        this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
        int number_lines = this->list_panel->numberLines();
        if (number_lines > this->list_panel->numberDrawLines()) {
            this->scbar_panel->set_active(1);
        } else {
            this->scbar_panel->set_active(0);
        }
        if (this->draw_style == 1) {
            this->btn_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
            this->val_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
        } else {
            this->val_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, 0, 0, 0, 0);
            this->btn_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
        }
        this->scbar_panel->set_positioning(PositionRightBottom, 1, 1, 0, 0, this->scbar_wid, this->scbar_wid,
                                           0, 0, 0, this->val_panel, 0, 0);
        this->list_panel->set_positioning(PositionLeftBottom, 0, 1, 1, 0, 0, 0, 0, 0, 0,
                                          this->val_panel, this->scbar_panel, 0);
        this->clip_to_parent = 0;
        long calc_wid = this->list_wid;
        this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - parent_y,
                                 calc_wid, this->list_hgt + this->val_hgt + 1);
        if (this->list_panel->yPosition() + this->list_panel->height() >
            this->render_area->Height - 4) {
            long overflow = this->list_panel->yPosition() + this->list_panel->height() +
                            4 - this->render_area->Height;
            long above = this->list_panel->height() + 4 - this->pnl_y;
            if (above < overflow) {
                if (above > 0) {
                    this->list_hgt -= above;
                    this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                    int spacer_size = this->list_panel->spacer_size;
                    if (spacer_size == 0) {
                        int border_size = this->list_panel->border_size;
                        this->list_hgt = this->list_panel->numberDrawLines() * (this->font_hgt + 2) +
                                         border_size * 2;
                    } else {
                        int border_size = this->list_panel->border_size;
                        this->list_hgt = this->list_panel->numberDrawLines() *
                                         (this->font_hgt + 1 + spacer_size * 2) +
                                         border_size * 2;
                    }
                    if (this->scbar_panel->active == 0) {
                        this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                        int number_lines = this->list_panel->numberLines();
                        if (number_lines > this->list_panel->numberDrawLines()) {
                            this->scbar_panel->set_active(1);
                        }
                    }
                }
                if (this->draw_style == 1) {
                    this->btn_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->btn_wid, this->btn_wid,
                                                     this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
                    this->val_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->val_wid, this->val_wid,
                                                     this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
                } else {
                    this->val_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->val_wid, this->val_wid,
                                                     this->val_hgt, this->val_hgt, 0, 0, 0, 0);
                    this->btn_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->btn_wid, this->btn_wid,
                                                     this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
                }
                this->scbar_panel->set_positioning(PositionRightTop, 1, 1, 0, 0, this->scbar_wid, this->scbar_wid,
                                                   0, 0, 0, 0, 0, this->val_panel);
                this->list_panel->set_positioning(PositionLeftTop, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
                                                  this->scbar_panel, this->val_panel);
                this->set_fixed_position(this->pnl_x - parent_x,
                                         this->pnl_y - parent_y - this->list_hgt - 1,
                                         calc_wid, this->list_hgt + this->val_hgt + 1);
                this->list_is_above = 1;
            } else {
                this->list_hgt -= overflow;
                this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                int spacer_size = this->list_panel->spacer_size;
                if (spacer_size == 0) {
                    int border_size = this->list_panel->border_size;
                    this->list_hgt = this->list_panel->numberDrawLines() * (this->font_hgt + 2) +
                                     border_size * 2;
                } else {
                    int border_size = this->list_panel->border_size;
                    this->list_hgt = this->list_panel->numberDrawLines() *
                                     (this->font_hgt + 1 + spacer_size * 2) +
                                     border_size * 2;
                }
                if (this->scbar_panel->active == 0) {
                    this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                    int number_lines = this->list_panel->numberLines();
                    if (number_lines > this->list_panel->numberDrawLines()) {
                        this->scbar_panel->set_active(1);
                    }
                    this->list_panel->set_positioning(PositionLeftBottom, 0, 1, 1, 0, 0, 0, 0, 0, 0,
                                                      this->val_panel, this->scbar_panel, 0);
                }
                this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - parent_y,
                                         calc_wid, this->list_hgt + this->val_hgt + 1);
            }
        }
        this->set_redraw(1);
        this->set_z_order(1, 0);
        this->set_curr_child(this->list_panel);
        panel_system.setModalPanel(this);
        if (this->parent_panel) {
            this->parent_panel->action(this, 1, 0, 0);
        }
    }

    this->mode = mode;
}

int TDropDownPanel::numberLines() {
    if (this->list_panel) {
        return this->list_panel->numberLines();
    }
    return 0;
}

int TDropDownPanel::currentLineNumber() {
    if (this->list_panel) {
        return this->list_panel->currentLineNumber();
    }
    return 0;
}

void TDropDownPanel::setCurrentLineNumber(int p) {
    this->set_line(p);
}

void TDropDownPanel::setCurrentLineId(int id) {
    if (this->list_panel) {
        this->list_panel->set_line_by_id(id);
        long line = this->list_panel->get_line();
        this->val_num = (short)line;
        if (this->val_panel) {
            this->val_panel->set_text(this->list_panel->get_text((long)(short)line));
        }
    }
}

char* TDropDownPanel::currentLine() {
    if (this->list_panel) {
        return this->list_panel->currentLine();
    }
    return 0;
}

void TDropDownPanel::set_tab_order(TPanel* a, TPanel* b) {
    TPanel::set_tab_order(a, b);
    if (this->val_panel != 0) {
        this->val_panel->set_tab_order((TPanel**)0, (short)0);
    }
}

void TDropDownPanel::set_sorted(int val) {
    if (this->list_panel) {
        this->list_panel->sorted = val;
    }
}

int TDropDownPanel::get_sorted() {
    if (this->list_panel) {
        return this->list_panel->sorted;
    }
    return 0;
}

void TDropDownPanel::set_line(long line) {
    this->val_num = (short)line;
    if (this->list_panel != 0) {
        this->list_panel->set_line(line);
        if (this->val_panel != 0) {
            this->val_panel->set_text(this->list_panel->get_text(line));
        }
    }
}

int TDropDownPanel::append_line(char* param_1, long param_2) {
    if (this->list_panel) {
        return this->list_panel->append_line(param_1, param_2);
    }
    return 0;
}

int TDropDownPanel::append_line(long param_1, long param_2) {
    if (this->list_panel) {
        return this->list_panel->append_line(param_1, param_2);
    }
    return 0;
}

int TDropDownPanel::insert_line(long param_1, char* param_2, long param_3) {
    if (this->list_panel) {
        return this->list_panel->insert_line(param_1, param_2, param_3);
    }
    return 0;
}

int TDropDownPanel::insert_line(long param_1, long param_2, long param_3) {
    if (this->list_panel) {
        return this->list_panel->insert_line(param_1, param_2, param_3);
    }
    return 0;
}

int TDropDownPanel::delete_line(long param) {
    if (this->list_panel) {
        return this->list_panel->delete_line(param);
    }
    return 0;
}

long TDropDownPanel::get_line() {
    if (this->list_panel) {
        return this->list_panel->get_line();
    }
    return 0;
}

long TDropDownPanel::get_line(long param) {
    if (this->list_panel) {
        return this->list_panel->get_line(param);
    }
    return 0;
}

long TDropDownPanel::get_line(char* param) {
    if (this->list_panel) {
        return this->list_panel->get_line(param);
    }
    return 0;
}

char* TDropDownPanel::get_text() {
    if (this->list_panel) {
        return this->list_panel->get_text();
    }
    return 0;
}

char* TDropDownPanel::get_text(long param) {
    if (this->list_panel) {
        return this->list_panel->get_text(param);
    }
    return 0;
}

long TDropDownPanel::get_id() {
    if (this->list_panel) {
        return this->list_panel->get_id();
    }
    return 0;
}

long TDropDownPanel::get_id(long param) {
    if (this->list_panel) {
        return this->list_panel->get_id(param);
    }
    return 0;
}

void TDropDownPanel::empty_list() {
    if (this->list_panel) {
        this->list_panel->empty_list();
    }
}

TDropDownButtonPanel::TDropDownButtonPanel(TDropDownPanel* panel) : TButtonPanel() {
    this->drop_down_panel = panel;
}

long TDropDownButtonPanel::handle_mouse_move(long x, long y, int ctrl_key, int shift_key) {
    if (this->mouse_captured != 0) {
        if (this->drop_down_panel->list_panel->is_inside(x, y) != 0) {
            this->handle_mouse_up(1, x, y, ctrl_key, shift_key);
            return this->drop_down_panel->list_panel->handle_mouse_down(1, x, y, ctrl_key, shift_key);
        }

        if (this->drop_down_panel->scbar_panel->is_inside(x, y) != 0) {
            this->handle_mouse_up(1, x, y, ctrl_key, shift_key);
            long list_width = this->drop_down_panel->list_panel->width();
            long list_x = this->drop_down_panel->list_panel->xPosition();
            return this->drop_down_panel->list_panel->handle_mouse_down(
                1, list_width + list_x - 1, y, ctrl_key, shift_key);
        }
    }

    return TPanel::handle_mouse_move(x, y, ctrl_key, shift_key);
}
