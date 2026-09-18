#include "../include/pnl_drop.h"
#include "../include/Pnl_scbr.h"

extern char s_592A40[];

TDropDownPanel::TDropDownPanel() : TPanel() {
    this->val_panel = 0;
    this->btn_panel = 0;
    this->list_panel = 0;
    this->scbar_panel = 0;
    this->mode = ModeNone;
    this->val_num = 0;
    this->list_is_above = 0;
    this->draw_style = DrawStyleDefault;
    this->panel_type = 6;
    this->draw_val_rect = 1;
}

TDropDownPanel::~TDropDownPanel() {
    this->delete_panel((TPanel**)&this->btn_panel);
    this->delete_panel((TPanel**)&this->list_panel);
    this->delete_panel((TPanel**)&this->scbar_panel);
    this->delete_panel((TPanel**)&this->val_panel);
}

long TDropDownPanel::setup(TDrawArea* render_area_in, TPanel* parent_panel_in, void* font_in,
                           long font_wid_in, long font_hgt_in, int fill_back_in,
                           unsigned char back_color_in, int outline_in,
                           unsigned char outline_color_in, long x_in, long y_in,
                           long wid_in, long hgt_in, short val_len_in, short val_num_in,
                           long btn_wid_in, long btn_hgt_in, char* btn_pic_in,
                           long list_wid_in, long list_hgt_in, char** list_in,
                           short list_num_lines_in, long scbar_wid_in,
                           char* scbar_back_pic_in, char* scbar_up_pic_in,
                           char* scbar_down_pic_in, char* scbar_tab_pic_in,
                           long scbar_arrow_hgt_in, long scbar_tab_hgt_in) {
    long result;

    this->val_num = val_num_in;
    this->val_wid = wid_in - btn_wid_in - 1;
    this->val_hgt = hgt_in;
    this->btn_wid = btn_wid_in;
    this->btn_hgt = btn_hgt_in;
    this->list_wid = list_wid_in;
    this->list_hgt = list_hgt_in;
    this->scbar_wid = scbar_wid_in;
    this->scbar_arrow_hgt = scbar_arrow_hgt_in;
    this->scbar_tab_hgt = scbar_tab_hgt_in;
    this->font_hgt = font_hgt_in;
    this->outline_color = outline_color_in;

    TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);

    this->val_panel = new TTextPanel;
    result = (long)this->val_panel;
    if (result != 0 && (result = this->val_panel->setup(render_area_in, this, 0, 0, this->val_wid, this->val_hgt,
                                                        font_in, font_wid_in, font_hgt_in, (char*)0,
                                                        fill_back_in, back_color_in, outline_in, outline_color_in, val_len_in,
                                                        list_in[(short)this->val_num])) != 0) {
        this->val_panel->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignLeft);

        this->btn_panel = new TDropDownButtonPanel(this);
        result = (long)this->btn_panel;
        if (result != 0 && (result = this->btn_panel->setup(render_area_in, this, 0, 0, this->btn_wid, this->btn_hgt,
                                                            TButtonPanel::DrawBevelPicture, (TDigital*)0,
                                                            TButtonPanel::NotifyAction, 0)) != 0) {
            this->list_panel = new TListPanel;
            result = (long)this->list_panel;
            if (result != 0 && (result = this->list_panel->setup(render_area_in, this, 0, 0, this->list_wid, this->list_hgt,
                                                                 font_in, font_wid_in, font_hgt_in, (char*)0,
                                                                 fill_back_in, back_color_in, outline_in,
                                                                 outline_color_in, val_len_in, list_in, list_num_lines_in)) != 0) {
                this->list_panel->set_auto_track(1);
                this->list_panel->set_active(0);
                ((TTextPanel*)this->list_panel)->setCurrentLineNumber(this->val_num);

                this->scbar_panel = new TScrollBarPanel;
                result = (long)this->scbar_panel;
                if (result != 0 &&
                    (result = this->scbar_panel->setup(this->render_area, this, 0, 0, this->scbar_wid, this->list_hgt,
                                                       s_592A40, s_592A40, s_592A40, s_592A40,
                                                       this->scbar_arrow_hgt, this->scbar_tab_hgt,
                                                       this->list_panel, list_num_lines_in,
                                                       TScrollBarPanel::Vertical)) != 0) {
                    TScrollBarPanel* scrollbar = this->scbar_panel;
                    this->list_panel->set_scrollbar(scrollbar, 0);
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

long TDropDownPanel::handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key) {
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

    return TPanel::handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
}

long TDropDownPanel::handle_mouse_move(long x, long y, int ctrl_key, int shift_key) {
    return TPanel::handle_mouse_move(x, y, ctrl_key, shift_key);
}

long TDropDownPanel::handle_mouse_up(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key) {
    return TPanel::handle_mouse_up(mouse_button_in, x, y, ctrl_key, shift_key);
}

long TDropDownPanel::handle_key_down(long key, short count, int alt_key, int ctrl_key, int shift_key) {
    if (this->have_focus != 0 && (key == 0x28 || key == 0x26) && this->mode == 1) {
        this->set_mode(ModeList);
        return 1;
    }
    return TPanel::handle_key_down(key, count, alt_key, ctrl_key, shift_key);
}

long TDropDownPanel::action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2) {
    if (from_panel == this->btn_panel) {
        if (action_in == 2) {
            if (this->mode == 1) {
                this->set_mode((DropdownMode)action_in);
            }
        }
    } else if (from_panel == (TPanel*)this->list_panel) {
        if (action_in == 3 || action_in == 2) {
            this->val_num = (short)action_val1;
            this->val_panel->set_text(this->list_panel->get_text((long)(short)action_val1));
            this->set_mode(ModeValue);
            if (this->parent_panel) {
                this->parent_panel->action(this, 0, 0, 0);
            }
        }
    }

    return TPanel::action(from_panel, action_in, action_val1, action_val2);
}

void TDropDownPanel::set_rect(long x_in, long y_in, long wid_in, long hgt_in) {
    TPanel::set_rect(x_in, y_in, wid_in, hgt_in);

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

void TDropDownPanel::set_val_text_color(unsigned long text_color1_in, unsigned long text_color2_in) {
    if (this->val_panel != 0) {
        this->val_panel->set_text_color(text_color1_in, text_color2_in);
    }
}

void TDropDownPanel::set_draw_style(TDropDownPanel::DrawStyle draw_style_in) {
    this->draw_style = draw_style_in;
    if (this->val_panel) {
        DropdownMode old_mode = this->mode;
        this->mode = ModeNone;
        this->set_mode(old_mode);
    }
}

void TDropDownPanel::set_draw_val_rect(int draw_val_rect_in) {
    this->draw_val_rect = draw_val_rect_in;
    if (this->val_panel != 0) {
        this->val_panel->set_outline(draw_val_rect_in, this->outline_color);
        this->set_redraw(TPanel::RedrawNormal);
    }
}

void TDropDownPanel::set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6) {
    if (this->val_panel != 0) {
        int mapped;
        switch (bevel_type_in) {
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
        switch (bevel_type_in) {
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
        switch (bevel_type_in) {
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
        switch (bevel_type_in) {
        case 1: mapped = 1; break;
        case 2: mapped = 2; break;
        case 3: mapped = 3; break;
        case 4: mapped = 4; break;
        default: mapped = 0; break;
        }
        this->btn_panel->set_bevel_info(mapped, c1, c2, c3, c4, c5, c6);
    }
}

void TDropDownPanel::set_buttons(TShape* button_shape_in, int btn_frame_in, int scbar_back_frame_in, int scbar_up_frame_in, int scbar_down_frame_in, int scbar_tab_frame_in) {
    if (this->btn_panel != 0) {
        if (button_shape_in != 0) {
            this->btn_panel->set_picture(0, button_shape_in, (short)btn_frame_in);
        } else {
            this->btn_panel->set_picture(0, 0, -1);
        }
    }
    if (this->scbar_panel != 0) {
        this->scbar_panel->set_buttons(button_shape_in, scbar_back_frame_in, scbar_up_frame_in, scbar_down_frame_in, scbar_tab_frame_in);
    }
}

void TDropDownPanel::set_mode(TDropDownPanel::DropdownMode mode_in) {
    if (mode_in == this->mode) {
        return;
    }

    long parent_x;
    long parent_y;
    long parent_wid;
    long parent_hgt;
    if (this->parent_panel != 0) {
        parent_x = this->parent_panel->xPosition();
        parent_y = this->parent_panel->yPosition();
        parent_wid = this->parent_panel->width();
        parent_hgt = this->parent_panel->height();
    } else {
        parent_x = 0;
        parent_y = 0;
        parent_wid = this->render_area->Width;
        parent_hgt = this->render_area->Height;
    }

    DropdownMode save_mode = this->mode;
    this->mode = ModeNone;

    if (mode_in == ModeValue) {
        if (save_mode == ModeList && this->parent_panel != 0 && this->parent_panel->parent_panel != 0 &&
            (this->clip_rect.left < parent_x || this->clip_rect.top < parent_y ||
             this->clip_rect.right > parent_x + parent_wid - 1 || this->clip_rect.bottom > parent_y + parent_hgt - 1)) {
            this->parent_panel->parent_panel->set_redraw(TPanel::RedrawImmediate);
        }

        this->list_panel->set_active(0);
        this->scbar_panel->set_active(0);

        if (this->draw_style == DrawStyleLeftButton) {
            this->btn_panel->set_positioning(TPanel::PositionLeftTop, 0, 0, 1, 0,
                                             this->btn_wid, this->btn_wid, this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
            this->val_panel->set_positioning(TPanel::PositionLeftTop, 1, 0, 0, 0,
                                             this->val_wid, this->val_wid, this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
        } else {
            this->val_panel->set_positioning(TPanel::PositionLeftTop, 0, 0, 1, 0,
                                             this->val_wid, this->val_wid, this->val_hgt, this->val_hgt, 0, 0, 0, 0);
            this->btn_panel->set_positioning(TPanel::PositionLeftTop, 1, 0, 0, 0,
                                             this->btn_wid, this->btn_wid, this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
        }

        this->clip_to_parent = 1;
        if (this->list_is_above != 0) {
            this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y + this->pnl_hgt - this->val_hgt - parent_y,
                                     this->val_wid + this->btn_wid + 1, this->val_hgt);
            this->list_is_above = 0;
        } else {
            this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - parent_y,
                                     this->val_wid + this->btn_wid + 1, this->val_hgt);
        }

        if (this->parent_panel != 0) {
            this->parent_panel->set_redraw(TPanel::RedrawNormal);
        } else {
            this->set_redraw(TPanel::RedrawNormal);
        }
        this->set_curr_child(this->val_panel);

        if (save_mode == ModeList) {
            if (panel_system.restorePreviousModalPanel() == 0) {
                panel_system.setModalPanel(0);
            }
            if (this->parent_panel != 0) {
                this->parent_panel->action(this, 2, 0, 0);
            }
        }
    } else if (mode_in == ModeList) {
        this->list_panel->set_active(1);

        if (this->list_panel->spacer_size == 0) {
            this->list_hgt =
                this->list_panel->numberLines() * (this->font_hgt + 2) +
                this->list_panel->border_size * 2;
        } else {
            this->list_hgt =
                this->list_panel->numberLines() *
                    (this->font_hgt + this->list_panel->spacer_size * 2 + 1) +
                this->list_panel->border_size * 2;
        }
        this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);

        int num_lines = this->list_panel->numberLines();
        int num_draw_lines = this->list_panel->numberDrawLines();
        if (num_draw_lines < num_lines) {
            this->scbar_panel->set_active(1);
        } else {
            this->scbar_panel->set_active(0);
        }

        if (this->draw_style == DrawStyleLeftButton) {
            this->btn_panel->set_positioning(TPanel::PositionLeftTop, 0, 0, 1, 0,
                                             this->btn_wid, this->btn_wid, this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
            this->val_panel->set_positioning(TPanel::PositionLeftTop, 1, 0, 0, 0,
                                             this->val_wid, this->val_wid, this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
        } else {
            this->val_panel->set_positioning(TPanel::PositionLeftTop, 0, 0, 1, 0,
                                             this->val_wid, this->val_wid, this->val_hgt, this->val_hgt, 0, 0, 0, 0);
            this->btn_panel->set_positioning(TPanel::PositionLeftTop, 1, 0, 0, 0,
                                             this->btn_wid, this->btn_wid, this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
        }

        this->scbar_panel->set_positioning(TPanel::PositionRightBottom, 1, 1, 0, 0, this->scbar_wid, this->scbar_wid, 0, 0,
                                           0, this->val_panel, 0, 0);
        this->list_panel->set_positioning(TPanel::PositionLeftBottom, 0, 1, 1, 0,
                                          0, 0, 0, 0, 0, this->val_panel, this->scbar_panel, 0);

        long total_hgt = this->list_hgt + this->val_hgt + 1;
        this->clip_to_parent = 0;
        this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - parent_y, this->list_wid, total_hgt);

        long list_bottom = this->list_panel->yPosition() +
                           this->list_panel->height();
        if (list_bottom > this->render_area->Height - 4) {
            long amount_below = this->list_panel->yPosition() +
                                this->list_panel->height() + 4 -
                                this->render_area->Height;
            long amount_above = this->list_panel->height() + 4 - this->pnl_y;

            if (amount_above < amount_below) {
                if (amount_above > 0) {
                    this->list_hgt -= amount_above;
                    this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);

                    if (this->list_panel->spacer_size == 0) {
                        this->list_hgt =
                            this->list_panel->numberDrawLines() *
                                (this->font_hgt + 2) +
                            this->list_panel->border_size * 2;
                    } else {
                        this->list_hgt =
                            this->list_panel->numberDrawLines() *
                                (this->font_hgt +
                                 this->list_panel->spacer_size * 2 + 1) +
                            this->list_panel->border_size * 2;
                    }
                    total_hgt = this->list_hgt + this->val_hgt + 1;

                    if (this->scbar_panel->active == 0) {
                        this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                        num_lines = this->list_panel->numberLines();
                        num_draw_lines = this->list_panel->numberDrawLines();
                        if (num_draw_lines < num_lines) {
                            this->scbar_panel->set_active(1);
                        }
                    }
                }

                if (this->draw_style == DrawStyleLeftButton) {
                    this->btn_panel->set_positioning(TPanel::PositionLeftBottom, 0, 0, 1, 0, this->btn_wid, this->btn_wid,
                                                     this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
                    this->val_panel->set_positioning(TPanel::PositionLeftBottom, 1, 0, 0, 0, this->val_wid, this->val_wid,
                                                     this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
                } else {
                    this->val_panel->set_positioning(TPanel::PositionLeftBottom, 0, 0, 1, 0, this->val_wid, this->val_wid,
                                                     this->val_hgt, this->val_hgt, 0, 0, 0, 0);
                    this->btn_panel->set_positioning(TPanel::PositionLeftBottom, 1, 0, 0, 0, this->btn_wid, this->btn_wid,
                                                     this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
                }

                this->scbar_panel->set_positioning(TPanel::PositionRightTop, 1, 1, 0, 0,
                                                   this->scbar_wid, this->scbar_wid, 0, 0, 0, 0, 0, this->val_panel);
                this->list_panel->set_positioning(TPanel::PositionLeftTop, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, this->scbar_panel,
                                                  this->val_panel);
                this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y + this->val_hgt - total_hgt - parent_y,
                                         this->list_wid, total_hgt);
                this->list_is_above = 1;
            } else {
                this->list_hgt -= amount_below;
                this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);

                if (this->list_panel->spacer_size == 0) {
                    this->list_hgt =
                        this->list_panel->numberDrawLines() *
                            (this->font_hgt + 2) +
                        this->list_panel->border_size * 2;
                } else {
                    this->list_hgt =
                        this->list_panel->numberDrawLines() *
                            (this->font_hgt +
                             this->list_panel->spacer_size * 2 + 1) +
                        this->list_panel->border_size * 2;
                }
                total_hgt = this->list_hgt + this->val_hgt + 1;

                if (this->scbar_panel->active == 0) {
                    this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                    num_lines = this->list_panel->numberLines();
                    num_draw_lines = this->list_panel->numberDrawLines();
                    if (num_draw_lines < num_lines) {
                        this->scbar_panel->set_active(1);
                    }
                    this->list_panel->set_positioning(TPanel::PositionLeftBottom, 0, 1, 1, 0,
                                                      0, 0, 0, 0, 0, this->val_panel, this->scbar_panel, 0);
                }

                this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - parent_y, this->list_wid, total_hgt);
            }
        }

        this->set_redraw(TPanel::RedrawNormal);
        this->set_z_order(1, 0);
        this->set_curr_child(this->list_panel);
        panel_system.setModalPanel(this);
        if (this->parent_panel != 0) {
            this->parent_panel->action(this, 1, 0, 0);
        }
    }

    this->mode = mode_in;
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

void TDropDownPanel::setCurrentLineNumber(int line_num_in) {
    this->set_line(line_num_in);
}

void TDropDownPanel::setCurrentLineId(int id_in) {
    if (this->list_panel) {
        this->list_panel->set_line_by_id(id_in);
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

void TDropDownPanel::set_tab_order(TPanel* prev_panel, TPanel* next_panel) {
    TPanel::set_tab_order(prev_panel, next_panel);
    if (this->val_panel != 0) {
        this->val_panel->set_tab_order((TPanel*)0, (TPanel*)0);
    }
}

void TDropDownPanel::set_sorted(int sorted_in) {
    if (this->list_panel) {
        this->list_panel->sorted = sorted_in;
    }
}

int TDropDownPanel::get_sorted() {
    if (this->list_panel) {
        return this->list_panel->sorted;
    }
    return 0;
}

void TDropDownPanel::set_line(long line_in) {
    this->val_num = (short)line_in;
    if (this->list_panel != 0) {
        this->list_panel->set_line(line_in);
        if (this->val_panel != 0) {
            this->val_panel->set_text(this->list_panel->get_text(line_in));
        }
    }
}

int TDropDownPanel::append_line(char* text_in, long id_in) {
    if (this->list_panel) {
        return this->list_panel->append_line(text_in, id_in);
    }
    return 0;
}

int TDropDownPanel::append_line(long string_id_in, long id_in) {
    if (this->list_panel) {
        return this->list_panel->append_line(string_id_in, id_in);
    }
    return 0;
}

int TDropDownPanel::insert_line(long line_in, char* text_in, long id_in) {
    if (this->list_panel) {
        return this->list_panel->insert_line(line_in, text_in, id_in);
    }
    return 0;
}

int TDropDownPanel::insert_line(long line_in, long string_id_in, long id_in) {
    if (this->list_panel) {
        return this->list_panel->insert_line(line_in, string_id_in, id_in);
    }
    return 0;
}

int TDropDownPanel::delete_line(long line_in) {
    if (this->list_panel) {
        return this->list_panel->delete_line(line_in);
    }
    return 0;
}

long TDropDownPanel::get_line() {
    if (this->list_panel) {
        return this->list_panel->get_line();
    }
    return 0;
}

long TDropDownPanel::get_line(long id_in) {
    if (this->list_panel) {
        return this->list_panel->get_line(id_in);
    }
    return 0;
}

long TDropDownPanel::get_line(char* text_in) {
    if (this->list_panel) {
        return this->list_panel->get_line(text_in);
    }
    return 0;
}

char* TDropDownPanel::get_text() {
    if (this->list_panel) {
        return this->list_panel->get_text();
    }
    return 0;
}

char* TDropDownPanel::get_text(long line_in) {
    if (this->list_panel) {
        return this->list_panel->get_text(line_in);
    }
    return 0;
}

long TDropDownPanel::get_id() {
    if (this->list_panel) {
        return this->list_panel->get_id();
    }
    return 0;
}

long TDropDownPanel::get_id(long line_in) {
    if (this->list_panel) {
        return this->list_panel->get_id(line_in);
    }
    return 0;
}

void TDropDownPanel::empty_list() {
    if (this->list_panel) {
        this->list_panel->empty_list();
    }
}

TDropDownButtonPanel::TDropDownButtonPanel(TDropDownPanel* drop_down_panel_in) : TButtonPanel() {
    this->drop_down_panel = drop_down_panel_in;
}

long TDropDownButtonPanel::handle_mouse_move(long x, long y, int ctrl_key, int shift_key) {
    if (this->mouse_captured != 0) {
        if (this->drop_down_panel->list_panel->is_inside(x, y) != 0) {
            this->handle_mouse_up(1, x, y, ctrl_key, shift_key);
            return this->drop_down_panel->list_panel->handle_mouse_down(1, x, y, ctrl_key, shift_key);
        }

        if (this->drop_down_panel->scbar_panel->is_inside(x, y) != 0) {
            this->handle_mouse_up(1, x, y, ctrl_key, shift_key);
            long list_hit_x = this->drop_down_panel->list_panel->width();
            list_hit_x += this->drop_down_panel->list_panel->xPosition() - 1;
            return this->drop_down_panel->list_panel->handle_mouse_down(1, list_hit_x, y, ctrl_key, shift_key);
        }
    }

    return TPanel::handle_mouse_move(x, y, ctrl_key, shift_key);
}
