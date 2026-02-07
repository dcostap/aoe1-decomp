#include "../include/TDropDownPanel.h"
#include "../include/TDropDownButtonPanel.h"
#include "../include/TTextPanel.h"
#include "../include/TListPanel.h"
#include "../include/TButtonPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TDrawArea.h"
#include "../include/ui_core.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"

// Constructor - from decomp/asm at 0x00473ED0
TDropDownPanel::TDropDownPanel() : TPanel() {
    this->val_panel = nullptr;
    this->btn_panel = nullptr;
    this->list_panel = nullptr;
    this->scbar_panel = nullptr;
    this->mode = ModeNone;
    this->val_num = 0;
    this->list_is_above = 0;
    this->draw_style = DrawStyleNormal;
    // ASM: MOV byte ptr [ESI + 0xee], 0x6  -- this is panel_type in TPanel at offset 0xee
    this->panel_type = 6;
    this->draw_val_rect = 1;
}

// Destructor - from decomp at 0x00473F50
TDropDownPanel::~TDropDownPanel() {
    delete_panel((TPanel**)&this->btn_panel);
    delete_panel((TPanel**)&this->list_panel);
    delete_panel((TPanel**)&this->scbar_panel);
    delete_panel((TPanel**)&this->val_panel);
}

// Setup - from decomp at 0x00473FD0
// Decomp param mapping (1-indexed from decomp, this_ is implicit):
//   param_1=draw_area, param_2=parent, param_3=font, param_4=font_wid, param_5=font_hgt,
//   param_6=fill_back(int), param_7=back_color(uchar), param_8=have_outline(int), param_9=outline_color(uchar),
//   param_10=x, param_11=y, param_12=wid, param_13=hgt, param_14=bevel_type(short),
//   param_15=initial_line(short), param_16=btn_wid(long), param_17=btn_hgt(long),
//   param_18=back_pic_name(char*), param_19=list_wid(long), param_20=list_hgt(long),
//   param_21=string_list(char**), param_22=sorted(short), param_23=scbar_wid(long),
//   param_24-27=pic1-4, param_28=scbar_arrow_hgt, param_29=scbar_tab_hgt
long TDropDownPanel::setup(TDrawArea* draw_area, TPanel* parent, void* font, long font_wid, long font_hgt,
                          int fill_back, uchar back_color, int have_outline, uchar outline_color,
                          long x, long y, long wid, long hgt, short bevel_type,
                          short initial_line_param, long btn_wid_param, long btn_hgt_param, char* back_pic_name,
                          long list_wid_param, long list_hgt_param, char** string_list, short sorted,
                          long scbar_wid_param, char* pic1, char* pic2, char* pic3, char* pic4,
                          long scbar_arrow_hgt_param, long scbar_tab_hgt_param) {
    // From decomp:
    //   this->val_num = param_15 (initial line index)
    //   this->btn_wid = param_16
    //   this->btn_hgt = param_17
    //   this->list_wid = param_19
    //   this->list_hgt = param_20
    //   this->scbar_wid = param_23 (scbar_wid_param)
    //   this->scbar_arrow_hgt = param_28 (scbar_arrow_hgt_param)
    //   this->scbar_tab_hgt = param_29 (scbar_tab_hgt_param)
    //   this->val_wid = (param_12 - param_16) - 1  = (wid - btn_wid_param) - 1
    //   this->val_hgt = param_13 (hgt)
    //   this->outline_color = (uint)param_9 (outline_color)
    //   this->font_hgt = param_5 (font_hgt)
    this->val_num = initial_line_param;
    this->btn_wid = btn_wid_param;
    this->btn_hgt = btn_hgt_param;
    this->list_wid = list_wid_param;
    this->list_hgt = list_hgt_param;
    this->scbar_wid = scbar_wid_param;
    this->scbar_arrow_hgt = scbar_arrow_hgt_param;
    this->scbar_tab_hgt = scbar_tab_hgt_param;
    this->val_wid = (wid - this->btn_wid) - 1;
    this->val_hgt = hgt;
    this->outline_color = (int)(unsigned int)outline_color;
    this->font_hgt = font_hgt;

    if (this->val_num < 0) {
        this->val_num = 0;
    }

    // Setup base panel
    if (!TPanel::setup(draw_area, parent, x, y, wid, hgt, '\0')) {
        return 0;
    }

    // Create value text panel
    this->val_panel = new TTextPanel();
    if (!this->val_panel) return 0;

    // From decomp: val_panel setup uses string_list[val_num] as initial text.
    char* initial_text = (char*)"";
    if (string_list != nullptr) {
        initial_text = string_list[(int)this->val_num];
        if (!initial_text) {
            initial_text = (char*)"";
        }
    }

    if (!this->val_panel->setup(draw_area, this, 0, 0, this->val_wid, this->val_hgt,
                                font, font_wid, font_hgt, nullptr, fill_back, back_color,
                                have_outline, outline_color, bevel_type,
                                initial_text)) {
        return 0;
    }
    this->val_panel->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignLeft);

    // Create button panel - decomp shows TDropDownButtonPanel (size 0x2BC), not plain TButtonPanel
    TDropDownButtonPanel* dbp = new TDropDownButtonPanel(this);
    this->btn_panel = (TButtonPanel*)dbp;
    if (!this->btn_panel) return 0;

    // From decomp: DrawBevelPicture=6, NotifyAction=1
    if (!this->btn_panel->setup(draw_area, this, 0, 0, this->btn_wid, this->btn_hgt,
                                TButtonPanel::DrawBevelPicture, nullptr,
                                TButtonPanel::NotifyAction, 0)) {
        return 0;
    }

    // Create list panel
    this->list_panel = new TListPanel();
    if (!this->list_panel) return 0;

    // From decomp: list_panel setup passes string_list and sorted
    if (!this->list_panel->setup(draw_area, this, 0, 0, this->list_wid, this->list_hgt,
                                 font, font_wid, font_hgt, nullptr, fill_back, back_color,
                                 have_outline, outline_color, bevel_type,
                                 string_list, sorted)) {
        return 0;
    }
    this->list_panel->set_auto_track(1);
    this->list_panel->set_active(0);
    // From decomp: setCurrentLineNumber on list_panel with val_num
    ((TTextPanel*)this->list_panel)->setCurrentLineNumber((int)this->val_num);

    // Create scrollbar panel
    this->scbar_panel = new TScrollBarPanel();
    if (!this->scbar_panel) return 0;

    // From decomp: scbar setup uses render_area (this->_padding_ at offset 0x20 = render_area)
    // and passes sorted as back_frame param
    if (!this->scbar_panel->setup(this->render_area, this, 0, 0, this->scbar_wid, this->list_hgt,
                                  pic1, pic2, pic3, pic4,
                                  this->scbar_arrow_hgt, this->scbar_tab_hgt,
                                  (TPanel*)this->list_panel, (int)sorted, TScrollBarPanel::Vertical)) {
        return 0;
    }

    // From decomp: set_scrollbar on list_panel, then deactivate scbar
    ((TTextPanel*)this->list_panel)->set_scrollbar(this->scbar_panel, 0);
    this->scbar_panel->set_active(0);

    // From decomp: set_mode(this, ModeValue) -- mode is already ModeNone from constructor
    this->set_mode(ModeValue);

    (void)back_pic_name;
    return 1;
}

static long dropdown_calc_list_hgt(TDropDownPanel* self, int use_draw_lines) {
    if (!self || !self->list_panel) {
        return 0;
    }

    // Source-of-truth (`Pnl_drop.cpp.decomp` @ set_mode):
    // list height uses list spacer_size and border_size, not bevel_type.
    const int spacer = ((TTextPanel*)self->list_panel)->spacer_size;
    const int border = ((TTextPanel*)self->list_panel)->border_size;
    int lines = use_draw_lines ? ((TTextPanel*)self->list_panel)->numberDrawLines()
                               : ((TTextPanel*)self->list_panel)->numberLines();
    if (lines < 0) {
        lines = 0;
    }

    if (spacer == 0) {
        return lines * (self->font_hgt + 2) + border * 2;
    }
    return lines * (self->font_hgt + 1 + spacer * 2) + border * 2;
}

// set_mode - from decomp at 0x00474880.
void TDropDownPanel::set_mode(TDropDownPanel::DropdownMode param_1) {
    if (param_1 == this->mode) {
        return;
    }

    long parent_x = 0;
    long parent_y = 0;
    int parent_w = 0;
    int parent_h = 0;
    if (this->parent_panel) {
        parent_x = this->parent_panel->xPosition();
        parent_y = this->parent_panel->yPosition();
        parent_w = (int)this->parent_panel->width();
        parent_h = (int)this->parent_panel->height();
    } else if (this->render_area) {
        parent_w = this->render_area->Width;
        parent_h = this->render_area->Height;
    }

    const DropdownMode save_mode = this->mode;
    this->mode = ModeNone;

    if (param_1 == ModeValue) {
        if (save_mode == ModeList && this->parent_panel && this->parent_panel->parent_panel) {
            if (this->pnl_x < parent_x || this->pnl_y < parent_y ||
                (this->pnl_x + this->pnl_wid - 1) > (parent_x + parent_w - 1) ||
                (this->pnl_y + this->pnl_hgt - 1) > (parent_y + parent_h - 1)) {
                this->parent_panel->parent_panel->set_redraw(RedrawFull);
            }
        }

        if (this->list_panel) {
            this->list_panel->set_active(0);
        }
        if (this->scbar_panel) {
            this->scbar_panel->set_active(0);
        }

        if (this->draw_style == DrawStyleLeftButton) {
            this->btn_panel->set_positioning((PositionMode)7, 0, 0, 1, 0,
                this->btn_wid, this->btn_wid, this->btn_hgt, this->btn_hgt,
                nullptr, nullptr, nullptr, nullptr);
            this->val_panel->set_positioning((PositionMode)7, 1, 0, 0, 0,
                this->val_wid, this->val_wid, this->val_hgt, this->val_hgt,
                (TPanel*)this->btn_panel, nullptr, nullptr, nullptr);
        } else {
            this->val_panel->set_positioning((PositionMode)7, 0, 0, 1, 0,
                this->val_wid, this->val_wid, this->val_hgt, this->val_hgt,
                nullptr, nullptr, nullptr, nullptr);
            this->btn_panel->set_positioning((PositionMode)7, 1, 0, 0, 0,
                this->btn_wid, this->btn_wid, this->btn_hgt, this->btn_hgt,
                (TPanel*)this->val_panel, nullptr, nullptr, nullptr);
        }

        const int closed_w = (int)(this->val_wid + 1 + this->btn_wid);
        const int closed_h = (int)this->val_hgt;
        this->clip_to_parent = 1;
        if (this->list_is_above == 0) {
            this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - parent_y, closed_w, closed_h);
        } else {
            this->set_fixed_position(this->pnl_x - parent_x,
                (this->pnl_y + this->pnl_hgt) - closed_h - parent_y,
                closed_w, closed_h);
            this->list_is_above = 0;
        }

        if (this->parent_panel) {
            this->parent_panel->set_redraw(Redraw);
        } else {
            this->set_redraw(Redraw);
        }

        this->set_curr_child((TPanel*)this->val_panel);

        if (save_mode == ModeList) {
            if (panel_system) {
                const int restored = panel_system->restorePreviousModalPanel();
                if (!restored) {
                    panel_system->setModalPanel(nullptr);
                }
            }
            if (this->parent_panel) {
                this->parent_panel->action(this, 2, 0, 0);
            }
        }
    } else if (param_1 == ModeList) {
        if (!this->list_panel || !this->val_panel || !this->btn_panel || !this->scbar_panel) {
            this->mode = param_1;
            return;
        }

        this->list_panel->set_active(1);
        this->list_hgt = dropdown_calc_list_hgt(this, 0);
        this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);

        const int num_lines = this->list_panel->numberLines();
        const int draw_lines = this->list_panel->numberDrawLines();
        this->scbar_panel->set_active((draw_lines < num_lines) ? 1 : 0);

        if (this->draw_style == DrawStyleLeftButton) {
            this->btn_panel->set_positioning((PositionMode)7, 0, 0, 1, 0,
                this->btn_wid, this->btn_wid, this->btn_hgt, this->btn_hgt,
                nullptr, nullptr, nullptr, nullptr);
            this->val_panel->set_positioning((PositionMode)7, 1, 0, 0, 0,
                this->val_wid, this->val_wid, this->val_hgt, this->val_hgt,
                (TPanel*)this->btn_panel, nullptr, nullptr, nullptr);
        } else {
            this->val_panel->set_positioning((PositionMode)7, 0, 0, 1, 0,
                this->val_wid, this->val_wid, this->val_hgt, this->val_hgt,
                nullptr, nullptr, nullptr, nullptr);
            this->btn_panel->set_positioning((PositionMode)7, 1, 0, 0, 0,
                this->btn_wid, this->btn_wid, this->btn_hgt, this->btn_hgt,
                (TPanel*)this->val_panel, nullptr, nullptr, nullptr);
        }

        this->scbar_panel->set_positioning((PositionMode)10, 1, 1, 0, 0,
            this->scbar_wid, this->scbar_wid, 0, 0,
            nullptr, (TPanel*)this->val_panel, nullptr, nullptr);
        this->list_panel->set_positioning((PositionMode)8, 0, 1, 1, 0,
            0, 0, 0, 0,
            nullptr, (TPanel*)this->val_panel, (TPanel*)this->scbar_panel, nullptr);

        const int calc_wid = (int)this->list_wid;
        int calc_hgt = (int)(this->list_hgt + 1 + this->val_hgt);
        this->clip_to_parent = 0;
        this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - parent_y, calc_wid, calc_hgt);

        const int render_h = this->render_area ? this->render_area->Height : parent_h;
        const long list_bottom = this->list_panel->yPosition() + this->list_panel->height();
        if ((render_h - 4) < list_bottom) {
            const int overflow = (int)(list_bottom + (4 - render_h));
            const int space_above = (int)(this->list_panel->height() + (4 - this->pnl_y));

            if (space_above < overflow) {
                if (space_above > 0) {
                    this->list_hgt -= space_above;
                    if (this->list_hgt < 0) {
                        this->list_hgt = 0;
                    }
                    this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                    this->list_hgt = dropdown_calc_list_hgt(this, 1);
                    calc_hgt = (int)(this->list_hgt + 1 + this->val_hgt);
                    if (this->scbar_panel->active == 0) {
                        this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                        if (this->list_panel->numberDrawLines() < this->list_panel->numberLines()) {
                            this->scbar_panel->set_active(1);
                        }
                    }
                }

                if (this->draw_style == DrawStyleLeftButton) {
                    this->btn_panel->set_positioning((PositionMode)8, 0, 0, 1, 0,
                        this->btn_wid, this->btn_wid, this->btn_hgt, this->btn_hgt,
                        nullptr, nullptr, nullptr, nullptr);
                    this->val_panel->set_positioning((PositionMode)8, 1, 0, 0, 0,
                        this->val_wid, this->val_wid, this->val_hgt, this->val_hgt,
                        (TPanel*)this->btn_panel, nullptr, nullptr, nullptr);
                } else {
                    this->val_panel->set_positioning((PositionMode)8, 0, 0, 1, 0,
                        this->val_wid, this->val_wid, this->val_hgt, this->val_hgt,
                        nullptr, nullptr, nullptr, nullptr);
                    this->btn_panel->set_positioning((PositionMode)8, 1, 0, 0, 0,
                        this->btn_wid, this->btn_wid, this->btn_hgt, this->btn_hgt,
                        (TPanel*)this->val_panel, nullptr, nullptr, nullptr);
                }

                this->scbar_panel->set_positioning((PositionMode)9, 1, 1, 0, 0,
                    this->scbar_wid, this->scbar_wid, 0, 0,
                    nullptr, nullptr, nullptr, (TPanel*)this->val_panel);
                this->list_panel->set_positioning((PositionMode)7, 0, 1, 1, 0,
                    0, 0, 0, 0,
                    nullptr, nullptr, (TPanel*)this->scbar_panel, (TPanel*)this->val_panel);

                this->set_fixed_position(this->pnl_x - parent_x,
                    (this->pnl_y + ((int)this->val_hgt - calc_hgt)) - parent_y,
                    calc_wid, calc_hgt);
                this->list_is_above = 1;
            } else {
                this->list_hgt -= overflow;
                if (this->list_hgt < 0) {
                    this->list_hgt = 0;
                }
                this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                this->list_hgt = dropdown_calc_list_hgt(this, 1);

                if (this->scbar_panel->active == 0) {
                    this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                    if (this->list_panel->numberDrawLines() < this->list_panel->numberLines()) {
                        this->scbar_panel->set_active(1);
                    }
                    this->list_panel->set_positioning((PositionMode)8, 0, 1, 1, 0,
                        0, 0, 0, 0,
                        nullptr, (TPanel*)this->val_panel, (TPanel*)this->scbar_panel, nullptr);
                }

                this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - parent_y,
                    calc_wid, (int)(this->list_hgt + 1 + this->val_hgt));
            }
        }

        this->set_redraw(Redraw);
        this->set_z_order('\x01', 0);
        this->set_curr_child((TPanel*)this->list_panel);
        if (panel_system) {
            panel_system->setModalPanel(this);
        }
        if (this->parent_panel) {
            this->parent_panel->action(this, 1, 0, 0);
        }
    }

    this->mode = param_1;
}

void TDropDownPanel::set_draw_style(TDropDownPanel::DrawStyle style) {
    // From decomp at 0x00474600
    this->draw_style = style;
    if (this->val_panel != nullptr) {
        DropdownMode saved = this->mode;
        this->mode = ModeNone;
        this->set_mode(saved);
    }
}

void TDropDownPanel::set_draw_val_rect(int draw) {
    // From decomp at 0x00474630
    this->draw_val_rect = draw;
    if (this->val_panel != nullptr) {
        this->val_panel->set_outline(draw, (uchar)this->outline_color);
        this->set_redraw(RedrawFull);
    }
}

void TDropDownPanel::empty_list() {
    if (this->list_panel) {
        this->list_panel->empty_list();
    }
}

int TDropDownPanel::append_line(char* text, long id) {
    if (this->list_panel) {
        return this->list_panel->append_line(text, id);
    }
    return 0;
}

int TDropDownPanel::append_line(long str_id, long id) {
    if (this->list_panel) {
        return this->list_panel->append_line(str_id, id);
    }
    return 0;
}

void TDropDownPanel::set_line(long line_num) {
    this->val_num = (short)line_num;
    if (this->list_panel) {
        this->list_panel->set_line(line_num);
        if (this->val_panel) {
            char* text = ((TTextPanel*)this->list_panel)->get_text((int)(short)line_num);
            this->val_panel->set_text(text);
        }
    }
}

long TDropDownPanel::get_id() {
    if (this->list_panel) {
        return this->list_panel->get_id();
    }
    return 0;
}

void TDropDownPanel::set_val_text_color(unsigned long c1, unsigned long c2) {
    if (this->val_panel) {
        this->val_panel->set_text_color(c1, c2);
    }
}

void TDropDownPanel::set_bevel_info(int bevel_type, int c1, int c2, int c3, int c4, int c5, int c6) {
    // val_panel: bevel mapping 1->1, 2->5, 3->6, 4->7, default->0
    if (this->val_panel) {
        int val_bevel;
        switch (bevel_type) {
        case 1: val_bevel = 1; break;
        case 2: val_bevel = 5; break;
        case 3: val_bevel = 6; break;
        case 4: val_bevel = 7; break;
        default: val_bevel = 0; break;
        }
        this->val_panel->set_bevel_info(val_bevel, c1, c2, c3, c4, c5, c6);
    }

    // list_panel: bevel mapping 1->1, 2->2, 3->3, 4->4, default->0
    if (this->list_panel) {
        int list_bevel;
        switch (bevel_type) {
        case 1: list_bevel = 1; break;
        case 2: list_bevel = 2; break;
        case 3: list_bevel = 3; break;
        case 4: list_bevel = 4; break;
        default: list_bevel = 0; break;
        }
        ((TTextPanel*)this->list_panel)->set_bevel_info(list_bevel, c1, c2, c3, c4, c5, c6);
    }

    // scbar_panel: same mapping as list
    if (this->scbar_panel) {
        int scbar_bevel;
        switch (bevel_type) {
        case 1: scbar_bevel = 1; break;
        case 2: scbar_bevel = 2; break;
        case 3: scbar_bevel = 3; break;
        case 4: scbar_bevel = 4; break;
        default: scbar_bevel = 0; break;
        }
        this->scbar_panel->set_bevel_info(scbar_bevel,
            (unsigned char)c1, (unsigned char)c2, (unsigned char)c3,
            (unsigned char)c4, (unsigned char)c5, (unsigned char)c6);
    }

    // btn_panel: same mapping as list
    if (this->btn_panel) {
        int btn_bevel;
        switch (bevel_type) {
        case 1: btn_bevel = 1; break;
        case 2: btn_bevel = 2; break;
        case 3: btn_bevel = 3; break;
        case 4: btn_bevel = 4; break;
        default: btn_bevel = 0; break;
        }
        this->btn_panel->set_bevel_info(btn_bevel, c1, c2, c3, c4, c5, c6);
    }
}

void TDropDownPanel::set_buttons(TShape* button_pics, int pic_id, int highlight_id,
                               int w, int h, int offset) {
    // btn_panel: set_picture with the button pic
    if (this->btn_panel) {
        if (button_pics) {
            this->btn_panel->set_picture(0, button_pics, (short)pic_id);
        } else {
            this->btn_panel->set_picture(0, nullptr, (short)-1);
        }
    }
    // scbar_panel: set_buttons with scroll arrow pics
    if (this->scbar_panel) {
        this->scbar_panel->set_buttons(button_pics, highlight_id, w, h, offset);
    }
}

// Action handler - from decomp at 0x004744A0
long TDropDownPanel::action(TPanel* p, long a, ulong p3, ulong p4) {
    if ((TButtonPanel*)p == this->btn_panel) {
        // Button click: open dropdown if in value mode
        if (a == 2 && this->mode == ModeValue) {
            this->set_mode(ModeList);
        }
    }
    else if ((TListPanel*)p == this->list_panel && (a == 3 || a == 2)) {
        // List selection
        this->val_num = (short)p3;
        // Copy selected text from list to val_panel
        char* text = ((TTextPanel*)this->list_panel)->get_text((int)(short)p3);
        this->val_panel->set_text(text);
        // Close dropdown
        this->set_mode(ModeValue);
        // Notify parent of selection: action(this, 0, 0, 0)
        if (this->parent_panel != nullptr) {
            this->parent_panel->action(this, 0, 0, 0);
        }
    }

    return TPanel::action(p, a, p3, p4);
}

// handle_key_down - from decomp at 0x00474450
long TDropDownPanel::handle_key_down(long k, short s, int p1, int p2, int p3) {
    if (this->parent_panel && (k == 0x28 || k == 0x26) && this->mode == ModeValue) {
        this->set_mode(ModeList);
        return 1;
    }
    return TPanel::handle_key_down(k, s, p1, p2, p3);
}

// handle_mouse_down - from decomp at 0x00474350
long TDropDownPanel::handle_mouse_down(uchar b, long x, long y, int p1, int p2) {
    // Set this as current child of parent
    if (this->parent_panel) {
        this->parent_panel->set_curr_child(this);
    }

    if (this->mode == ModeList) {
        int in_list = this->list_panel ? this->list_panel->is_inside(x, y) : 0;
        int in_scbar = 0;
        if (this->scbar_panel) {
            in_scbar = this->scbar_panel->is_inside(x, y);
        }

        if (!in_list && !in_scbar) {
            // Click outside list/scrollbar: close dropdown
            this->set_mode(ModeValue);
            set_line(this->val_num);
            return 1;
        }
    }

    return TPanel::handle_mouse_down(b, x, y, p1, p2);
}

// draw - from ASM at 0x00474340: JMP TPanel::draw
// The original just delegates to TPanel::draw. No custom rendering.
void TDropDownPanel::draw() {
    TPanel::draw();
}

// set_rect - from decomp at 0x00474550
void TDropDownPanel::set_rect(long x, long y, long w, long h) {
    TPanel::set_rect(x, y, w, h);

    if (this->mode == ModeValue) {
        this->val_wid = (this->pnl_wid - this->btn_wid) - 1;
        this->val_hgt = this->pnl_hgt;
        this->mode = ModeNone;
        this->set_mode(ModeValue);
    }
    else if (this->mode == ModeList) {
        this->list_wid = this->pnl_wid;
        this->list_hgt = (this->pnl_hgt - this->val_hgt) - 1;
        this->set_mode(ModeValue);
        this->set_mode(ModeList);
    }
}

long TDropDownPanel::setup(TDrawArea* a, TPanel* p, long x, long y, long w, long h, uchar c) {
    return TPanel::setup(a, p, x, y, w, h, c);
}

void TDropDownPanel::set_rect(tagRECT r) { TPanel::set_rect(r); }

void TDropDownPanel::set_color(uchar c) { TPanel::set_color(c); }
void TDropDownPanel::set_active(int a) { TPanel::set_active(a); }
void TDropDownPanel::set_positioning(PositionMode m, long p1, long p2, long p3, long p4, long p5, long p6, long p7, long p8, TPanel* r1, TPanel* r2, TPanel* r3, TPanel* r4) {
    TPanel::set_positioning(m, p1, p2, p3, p4, p5, p6, p7, p8, r1, r2, r3, r4);
}
void TDropDownPanel::set_fixed_position(long x, long y, long w, long h) { TPanel::set_fixed_position(x, y, w, h); }
void TDropDownPanel::set_redraw(RedrawMode m) { TPanel::set_redraw(m); }
void TDropDownPanel::set_overlapped_redraw(RedrawMode m) { TPanel::set_overlapped_redraw(m); }
void TDropDownPanel::draw_setup(int p) { TPanel::draw_setup(p); }
void TDropDownPanel::draw_finish() { TPanel::draw_finish(); }
void TDropDownPanel::draw_rect(tagRECT* r) { TPanel::draw_rect(r); }
void TDropDownPanel::draw_offset(long x, long y, tagRECT* r) { TPanel::draw_offset(x, y, r); }
void TDropDownPanel::draw_rect2(tagRECT* r) { TPanel::draw_rect2(r); }
void TDropDownPanel::draw_offset2(long x, long y, tagRECT* r) { TPanel::draw_offset2(x, y, r); }
void TDropDownPanel::paint() { TPanel::paint(); }
long TDropDownPanel::wnd_proc(void* h, uint m, uint w, long l) { return TPanel::wnd_proc(h, m, w, l); }
long TDropDownPanel::handle_idle() { return TPanel::handle_idle(); }
long TDropDownPanel::handle_size(long w, long h) { return TPanel::handle_size(w, h); }
long TDropDownPanel::handle_paint() { return TPanel::handle_paint(); }
long TDropDownPanel::handle_char(long p1, short p2) { return TPanel::handle_char(p1, p2); }
long TDropDownPanel::handle_command(uint c, long p) { return TPanel::handle_command(c, p); }
long TDropDownPanel::handle_user_command(uint c, long p) { return TPanel::handle_user_command(c, p); }
long TDropDownPanel::handle_timer_command(uint c, long p) { return TPanel::handle_timer_command(c, p); }
long TDropDownPanel::handle_scroll(long p1, long p2) { return TPanel::handle_scroll(p1, p2); }
long TDropDownPanel::handle_mouse_move(long x, long y, int p1, int p2) { return TPanel::handle_mouse_move(x, y, p1, p2); }
long TDropDownPanel::handle_mouse_up(uchar b, long x, long y, int p1, int p2) { return TPanel::handle_mouse_up(b, x, y, p1, p2); }
long TDropDownPanel::handle_mouse_dbl_click(uchar b, long x, long y, int p1, int p2) { return TPanel::handle_mouse_dbl_click(b, x, y, p1, p2); }
long TDropDownPanel::mouse_move_action(long x, long y, int p1, int p2) { return TPanel::mouse_move_action(x, y, p1, p2); }
long TDropDownPanel::mouse_left_down_action(long x, long y, int p1, int p2) { return TPanel::mouse_left_down_action(x, y, p1, p2); }
long TDropDownPanel::mouse_left_hold_action(long x, long y, int p1, int p2) { return TPanel::mouse_left_hold_action(x, y, p1, p2); }
long TDropDownPanel::mouse_left_move_action(long x, long y, int p1, int p2) { return TPanel::mouse_left_move_action(x, y, p1, p2); }
long TDropDownPanel::mouse_left_up_action(long x, long y, int p1, int p2) { return TPanel::mouse_left_up_action(x, y, p1, p2); }
long TDropDownPanel::mouse_left_dbl_click_action(long x, long y, int p1, int p2) { return TPanel::mouse_left_dbl_click_action(x, y, p1, p2); }
long TDropDownPanel::mouse_right_down_action(long x, long y, int p1, int p2) { return TPanel::mouse_right_down_action(x, y, p1, p2); }
long TDropDownPanel::mouse_right_hold_action(long x, long y, int p1, int p2) { return TPanel::mouse_right_hold_action(x, y, p1, p2); }
long TDropDownPanel::mouse_right_move_action(long x, long y, int p1, int p2) { return TPanel::mouse_right_move_action(x, y, p1, p2); }
long TDropDownPanel::mouse_right_up_action(long x, long y, int p1, int p2) { return TPanel::mouse_right_up_action(x, y, p1, p2); }
long TDropDownPanel::mouse_right_dbl_click_action(long x, long y, int p1, int p2) { return TPanel::mouse_right_dbl_click_action(x, y, p1, p2); }
long TDropDownPanel::key_down_action(long k, short s, int p1, int p2, int p3) { return TPanel::key_down_action(k, s, p1, p2, p3); }
long TDropDownPanel::char_action(long p1, short p2) { return TPanel::char_action(p1, p2); }
void TDropDownPanel::get_true_render_rect(tagRECT* r) { TPanel::get_true_render_rect(r); }
int TDropDownPanel::is_inside(long x, long y) { return TPanel::is_inside(x, y); }
void TDropDownPanel::set_focus(int f) { TPanel::set_focus(f); }
void TDropDownPanel::set_tab_order() { TPanel::set_tab_order(); }
void TDropDownPanel::set_tab_order(TPanel** p, short s) { TPanel::set_tab_order(p, s); }
uchar TDropDownPanel::get_help_info(char** p1, long* p2, long p3, long p4) { return TPanel::get_help_info(p1, p2, p3, p4); }
void TDropDownPanel::stop_sound_system() { TPanel::stop_sound_system(); }
int TDropDownPanel::restart_sound_system() { return TPanel::restart_sound_system(); }
void TDropDownPanel::take_snapshot() { TPanel::take_snapshot(); }
void TDropDownPanel::handle_reactivate() { TPanel::handle_reactivate(); }
