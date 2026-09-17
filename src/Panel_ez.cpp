#include "../include/panel_ez.h"
#include "../include/basegame.h"
#include "../include/drawarea.h"
#include "../include/Shape.h"
#include "../include/color.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_inp.h"
#include "../include/pnl_edit.h"
#include "../include/Pnl_scbr.h"
#include "../include/pnl_drop.h"
#include "../include/pnl_sld.h"
#include "../include/Mouseptr.h"
#include "../include/dlg_msg.h"
#include "../include/dlg_help.h"
#include <fcntl.h>
#include <io.h>
#include <new.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char s_space[] = " ";
static char s_X[] = "X";

extern "C" int __cdecl stricmp(const char* str1, const char* str2);

TEasy_Panel::TEasy_Panel(char* name)
    : TPanel(name) {
    init_vars();
}

long TEasy_Panel::setup(TDrawArea* render_area_in, TPanel* parent_in,
                        char* info_file_name_in, long resource_file_id,
                        int full_screen, long x_in, long y_in, long wid_in,
                        long hgt_in, int allow_shadow_area_in) {
    int own_mem = -1;
    int f1g;
    int f2r;
    int f2b;
    int back_pic_id_a1;
    int back_pic_id_a2;
    int t2g;
    int s2g;
    int background_pos_in;
    int f1r;
    int f1b;
    int button_pic_id;
    int bc6;
    int bc5;
    int bc4;
    int t1g;
    int s1g;
    int back_pic_id_c1;
    int popup_info_id;
    int bc3;
    int t2r;
    int t2b;
    int s2r;
    int s2b;
    int back_pic_id_c2;
    int cursor_id;
    int bc2;
    int resDataSize;
    int bc1;
    int f2g;
    int pal_id;
    int back_pic_id_b1;
    int t1r;
    int t1b;
    int s1r;
    int s1b;
    int back_pic_id_b2;
    int background_color1_in;
    int shad_amt;
    char temp_label[256];
    char info_file_name2[260];
    char background_pic_file_name_b1[260];
    char background_pic_file_name_c2[260];
    char background_pic_file_name_a2[260];
    char palette_file_name[260];
    char background_pic_file_name_b2[260];
    char cursor_file_name[260];
    char background_pic_file_name_c1[260];
    char button_pics_file_name[260];
    char background_pic_file_name_a1[260];
    char popup_info_file_name_in[260];
    unsigned char* info_data;

    this->allow_shadow_area = allow_shadow_area_in;
    this->set_info_file(info_file_name_in, resource_file_id);

    if (full_screen == 0) {
        if (wid_in > 0 && hgt_in > 0 && render_area_in != 0) {
            if (x_in == -1) {
                x_in = render_area_in->Width / 2 - wid_in / 2;
            }
            if (y_in == -1) {
                y_in = render_area_in->Height / 2 - hgt_in / 2;
            }
        }
    } else {
        x_in = 0;
        y_in = 0;
        if (render_area_in == 0) {
            wid_in = 0;
            hgt_in = 0;
        } else {
            wid_in = render_area_in->Width;
            hgt_in = render_area_in->Height;
        }
    }

    if (this->TPanel::setup(render_area_in, parent_in, x_in, y_in, wid_in, hgt_in, 0) == 0) {
        return 0;
    }

    this->set_ideal_size(wid_in, hgt_in);
    if (full_screen != 0) {
        this->set_positioning((TPanel::PositionMode)1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }

    info_data = 0;
    if (shape_file_first != 0 && this->info_file_name != 0 &&
        *this->info_file_name != 0) {
        if (strchr(this->info_file_name, '.') == 0) {
            sprintf(info_file_name2, "%s.sin", this->info_file_name);
        } else {
            sprintf(info_file_name2, "%s", this->info_file_name);
        }

        int file_handle = open(info_file_name2, _O_BINARY);
        if (file_handle != -1) {
            lseek(file_handle, 0, 2);
            resDataSize = tell(file_handle);
            info_data = (unsigned char*)malloc(resDataSize);
            if (info_data != 0) {
                lseek(file_handle, 0, 0);
                read(file_handle, info_data, resDataSize);
                own_mem = 1;
            }
            close(file_handle);
        }
    }

    if (info_data == 0) {
        if (this->info_id != -1) {
            info_data = RESFILE_load(RES_TYPE_BINARY, this->info_id, own_mem, resDataSize);
        }
        if (info_data == 0) {
            return 1;
        }
    }

    if (sscanf((char*)info_data, "%s %s %s %d %d   " "%s %s %s %d %d   " "%s %s %s %d %d   " "%s %s %d   " "%s %s %d   "
               "%s %s %d   " "%s %s %d   " "%s %s %d   " "%s %d   " "%s %d   " "%s %d %d %d %d %d %d   " "%s %d %d %d   "
               "%s %d %d %d   " "%s %d %d %d   " "%s %d %d %d   " "%s %d %d %d   " "%s %d %d %d",
               temp_label, background_pic_file_name_a1, background_pic_file_name_a2, &back_pic_id_a1,
               &back_pic_id_a2, temp_label, background_pic_file_name_b1, background_pic_file_name_b2,
               &back_pic_id_b1, &back_pic_id_b2, temp_label, background_pic_file_name_c1, background_pic_file_name_c2,
               &back_pic_id_c1, &back_pic_id_c2, temp_label, palette_file_name, &pal_id, temp_label, cursor_file_name,
               &cursor_id, temp_label, temp_label, &shad_amt, temp_label, button_pics_file_name, &button_pic_id, temp_label,
               popup_info_file_name_in, &popup_info_id, temp_label, &background_pos_in, temp_label, &background_color1_in,
               temp_label, &bc1, &bc2, &bc3, &bc4, &bc5, &bc6, temp_label, &t1r, &t1g, &t1b, temp_label, &t2r, &t2g,
               &t2b, temp_label, &f1r, &f1g, &f1b, temp_label, &f2r, &f2g, &f2b, temp_label, &s1r, &s1g, &s1b, temp_label,
               &s2r, &s2g, &s2b) != -1) {
        this->set_use_bevels(1);

        if (this->render_area->Width < 800 ||
            stricmp(background_pic_file_name_b1, "none") == 0) {
            this->set_background(background_pic_file_name_a1, back_pic_id_a1);
            this->set_background2(background_pic_file_name_a2, back_pic_id_a2);
        } else if (this->render_area->Width < 1024) {
            this->set_background(background_pic_file_name_b1, back_pic_id_b1);
            this->set_background2(background_pic_file_name_b2, back_pic_id_b2);
        } else {
            this->set_background(background_pic_file_name_c1, back_pic_id_c1);
            this->set_background2(background_pic_file_name_c2, back_pic_id_c2);
        }

        this->set_shadow_amount(shad_amt);
        this->set_palette(palette_file_name, pal_id);
        this->set_cursor(cursor_file_name, cursor_id);
        this->set_background_pos(background_pos_in);
        this->set_background_colors(background_color1_in, background_color1_in);
        this->set_bevel_colors(bc1, bc2, bc3, bc4, bc5, bc6);
        this->set_text_colors(((t1b & 0xFF) << 16) | ((t1g & 0xFF) << 8) | (t1r & 0xFF), ((t2b & 0xFF) << 16) |
                              ((t2g & 0xFF) << 8) | (t2r & 0xFF));
        this->set_focus_colors(((f1b & 0xFF) << 16) | ((f1g & 0xFF) << 8) | (f1r & 0xFF), ((f2b & 0xFF) << 16) |
                               ((f2g & 0xFF) << 8) | (f2r & 0xFF));
        this->set_state_colors(((s1b & 0xFF) << 16) | ((s1g & 0xFF) << 8) | (s1r & 0xFF), ((s2b & 0xFF) << 16) |
                               ((s2g & 0xFF) << 8) | (s2r & 0xFF));
        this->set_button_pics(button_pics_file_name, button_pic_id);
        this->set_popup_info_file(popup_info_file_name_in, popup_info_id);
    }

    if (own_mem == 1) {
        free(info_data);
    }
    return 1;
}

TEasy_Panel::TEasy_Panel()
    : TPanel() {
    init_vars();
}

void TEasy_Panel::init_vars() {
    this->ideal_width = 640;
    this->ideal_height = 480;
    this->info_file_name[0] = 0;
    this->info_id = -1;
    this->background_pic = 0;
    this->background_pic2 = 0;
    this->palette = 0;
    this->cursor_file[0] = 0;
    this->cursor_id = -1;
    this->background_pos = 0;
    this->use_bevels = 0;
    this->bevel_color1 = 0;
    this->bevel_color2 = 0;
    this->bevel_color3 = 0;
    this->bevel_color4 = 0;
    this->bevel_color5 = 0;
    this->bevel_color6 = 0;
    this->text_color1 = 0xFFFFFF;
    this->text_color2 = 0;
    this->focus_color1 = 0xFFFF;
    this->focus_color2 = 0;
    this->state_color1 = 0xFFFFFF;
    this->state_color2 = 0;
    this->popup_info_file_name[0] = 0;
    this->popup_info_id = -1;
    this->button_pics = 0;
    this->shadow_color_table = 0;
    this->background_color1 = 0;
    this->background_color2 = 0;
    this->enable_ime = 0;
    this->help_mode = 0;
    this->stock_brush = 0;
    this->brush = 0;
    this->brush_color = 0;
    this->shadow_amount = 0;
    this->shadow_area = 0;
    this->saved_mouse_mode = 0;
}

TEasy_Panel::~TEasy_Panel() {
    TPanel* self = this;

    prepare_for_close();
}

void TEasy_Panel::prepare_for_close() {
    if (this->shadow_area != 0) {
        delete this->shadow_area;
        this->shadow_area = 0;
    }

    if (this->brush != 0) {
        if (this->stock_brush == 0) {
            DeleteObject(this->brush);
        }
        this->brush = 0;
    }

    if (this->background_pic != 0) {
        delete this->background_pic;
        this->background_pic = 0;
    }

    if (this->background_pic2 != 0) {
        delete this->background_pic2;
        this->background_pic2 = 0;
    }

    if (this->palette != 0) {
        panel_system.release_palette(this->palette);
        this->palette = 0;
    }

    if (this->shadow_color_table != 0) {
        delete this->shadow_color_table;
        this->shadow_color_table = 0;
    }

    if (this->button_pics != 0) {
        delete this->button_pics;
        this->button_pics = 0;
    }
}

void TEasy_Panel::setup_shadow_area(int force_redraw) {
    TDrawArea* area = this->shadow_area;
    if ((area == 0 || force_redraw != 0) &&
        this->background_pic != 0 && this->shadow_color_table != 0) {
        unsigned long old_flags = this->render_area->DrawSystem->Flags;

        if (area == 0) {
            char area_name[256];
            TDrawSystem* draw_system = this->render_area->DrawSystem;
            draw_system->Flags &= 1;
            sprintf(area_name, "%s Shadow Panel", this->panel_name);
            this->shadow_area = new TDrawArea(area_name, 0);
        }

        if (this->shadow_area != 0) {
            long y_max;
            long x_min;
            long y_min;
            long x_max;

            this->background_pic->shape_minmax(x_min, y_min, x_max, y_max, 0);

            int width = x_max - x_min + 1;
            int height = y_max - y_min + 1;
            if (width > this->pnl_wid)
                width = this->pnl_wid;
            if (height > this->pnl_hgt)
                height = this->pnl_hgt;

            if (this->shadow_area->Init(this->render_area->DrawSystem, width, height, 0, 0)) {
                this->shadow_area->Clear(0, this->background_color1);
                if (this->shadow_area->Lock("panel_ez::setup_shadow_area", 1)) {
                    this->background_pic->shape_draw(this->shadow_area, 0, 0, 0, 0, 0);
                    this->shadow_area->SetShadowTable(this->shadow_color_table);
                    this->shadow_area->DrawShadowBox(0, 0, width - 1, height - 1);
                    this->shadow_area->Unlock("panel_ez::setup_shadow_area");
                }
            }
        }

        this->render_area->DrawSystem->Flags = old_flags;
    }
}

void TEasy_Panel::draw_setup(int clear) { this->TPanel::draw_setup(clear); }

void TEasy_Panel::draw() {
    if (this->need_restore != 0) {
        if (this->shadow_area != 0) {
            this->setup_shadow_area(1);
        }
        this->need_restore = 0;
    }
    if (this->draw_rect2_flag != 0) {
        this->draw_background(1);
    } else {
        this->draw_background(0);
    }
}

void TEasy_Panel::draw_background(int use_background2) {
    long y_max;
    long x_min;
    long y_min;
    long x_max;
    long pic_hgt;
    TShape* pic;

    this->draw_setup(0);

    if (use_background2 && this->shadow_area) {
        if (this->need_redraw == 2)
            this->render_area->Clear(&this->clip_rect, this->background_color2);

        int tile_w = this->shadow_area->Width;
        pic_hgt = this->shadow_area->Height;
        switch (this->background_pos) {
        case 0:
            this->shadow_area->Copy(this->render_area, this->pnl_x, this->pnl_y, 0, 0);
            break;
        case 1: {
            short yy = this->pnl_y + this->pnl_hgt / 2 - pic_hgt / 2;
            short xx = this->pnl_x + this->pnl_wid / 2 - tile_w / 2;
            this->shadow_area->Copy(this->render_area, (long)xx, (long)yy, 0, 0);
            break;
        }
        case 2: {
            long yy = 0;
            if (this->pnl_hgt >= 0) {
                do {
                    long xx = 0;
                    if (this->pnl_wid >= 0) {
                        do {
                            this->shadow_area->Copy(this->render_area, this->pnl_x + xx, this->pnl_y + yy, 0, 0);
                            xx += tile_w;
                        } while (xx <= this->pnl_wid);
                    }
                    yy += pic_hgt;
                } while (yy <= this->pnl_hgt);
            }
            break;
        }
        }
        goto bevels;
    }

    if (use_background2 && this->background_pic2)
        pic = this->background_pic2;
    else
        pic = this->background_pic;

    if (this->need_redraw == 2 || pic == 0) {
        if (use_background2)
            this->render_area->Clear(&this->clip_rect, this->background_color2);
        else
            this->render_area->Clear(&this->clip_rect, this->background_color1);
        if (pic == 0)
            goto bevels;
    }

    if (this->render_area->Lock("panel_ez::draw_background", 1)) {
        pic->shape_minmax(x_min, y_min, x_max, y_max, 0);
        long pic_w = x_max - x_min + 1;
        pic_hgt = y_max - y_min + 1;
        switch (this->background_pos) {
        case 1: {
            short yy = this->pnl_y + this->pnl_hgt / 2 - pic_hgt / 2;
            short xx = this->pnl_x + this->pnl_wid / 2 - pic_w / 2;
            pic->shape_draw(this->render_area, (long)xx, (long)yy, 0, 0, 0);
            if (use_background2 && this->shadow_color_table) {
                this->render_area->SetShadowTable(this->shadow_color_table);
                this->render_area->DrawShadowBox((long)xx, (long)yy, xx + pic_w - 1, yy + pic_hgt - 1);
            }
            break;
        }
        case 2: {
            long yy = 0;
            if (this->pnl_hgt >= 0) {
                do {
                    long xx = 0;
                    if (this->pnl_wid >= 0) {
                        do {
                            pic->shape_draw(this->render_area, this->pnl_x + xx, this->pnl_y + yy, 0, 0, 0);
                            xx += pic_w;
                        } while (xx <= this->pnl_wid);
                    }
                    yy += pic_hgt;
                } while (yy <= this->pnl_hgt);
            }
            if (use_background2 && this->shadow_color_table) {
                this->render_area->SetShadowTable(this->shadow_color_table);
                this->render_area->DrawShadowBox(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1);
            }
            break;
        }
        default:
            pic->shape_draw(this->render_area, this->pnl_x, this->pnl_y, 0, 0, 0);
            if (use_background2 && this->shadow_color_table) {
                this->render_area->SetShadowTable(this->shadow_color_table);
                this->render_area->DrawShadowBox(this->pnl_x, this->pnl_y, this->pnl_x + pic_w - 1, this->pnl_y + pic_hgt - 1);
            }
            break;
        }
        this->render_area->Unlock("panel_ez::draw_background");
    }

bevels:
    if (this->use_bevels) {
        if (this->render_area->Lock("panel_ez::draw_background2", 1)) {
            this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                                          this->bevel_color1, this->bevel_color2, this->bevel_color3,
                                          this->bevel_color4, this->bevel_color5, this->bevel_color6);
            this->render_area->Unlock("panel_ez::draw_background2");
        }
    }
    this->draw_finish();
}

long TEasy_Panel::handle_mouse_down(unsigned char mouse_button_in, long x, long y,
                                    int ctrl_key, int shift_key) {
    if (this->command_do_popup_help(mouse_button_in, x, y) != 0) {
        return 1;
    }
    return TPanel::handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
}

void TEasy_Panel::set_info_file(char* file_name, long resource_file_id) {
    if (file_name) {
        strcpy(this->info_file_name, file_name);
    } else {
        this->info_file_name[0] = '\0';
    }
    this->info_id = resource_file_id;
}

void TEasy_Panel::set_ideal_size(long width, long height) {
    this->ideal_width = width;
    this->ideal_height = height;
}

int TEasy_Panel::set_background(char* file_name, long resource_id) {
    char file_name2[260];

    TShape* old = this->background_pic;
    if (old != 0) {
        delete old;
        this->background_pic = 0;
    }

    if (file_name != 0 && *file_name != 0 && stricmp(file_name, "none") != 0) {
        if (strchr(file_name, '.') == 0) {
            sprintf(file_name2, "%s.shp", file_name);
        } else {
            sprintf(file_name2, "%s", file_name);
        }
        this->background_pic = new TShape(file_name2, resource_id);
    } else if (resource_id != -1) {
        this->background_pic = new TShape("", resource_id);
    }

    if (this->background_pic != 0 && this->background_pic->is_loaded() == 0) {
        TShape* shape = this->background_pic;
        if (shape != 0) {
            delete shape;
        }
        this->background_pic = 0;
    }
    return this->background_pic != 0;
}

int TEasy_Panel::set_background2(char* file_name, long resource_id) {
    char file_name2[260];

    TShape* old = this->background_pic2;
    if (old != 0) {
        delete old;
        this->background_pic2 = 0;
    }

    if (file_name != 0 && *file_name != 0 && stricmp(file_name, "none") != 0) {
        if (strchr(file_name, '.') == 0) {
            sprintf(file_name2, "%s.shp", file_name);
        } else {
            sprintf(file_name2, "%s", file_name);
        }
        this->background_pic2 = new TShape(file_name2, resource_id);
    } else if (resource_id != -1) {
        this->background_pic2 = new TShape("", resource_id);
    }

    if (this->background_pic2 != 0 && this->background_pic2->is_loaded() == 0) {
        TShape* shape = this->background_pic2;
        if (shape != 0) {
            delete shape;
        }
        this->background_pic2 = 0;
    }
    return this->background_pic2 != 0;
}

void TEasy_Panel::set_background_colors(unsigned char color1, unsigned char color2) {
    this->set_color(color1);
    background_color1 = color1;
    background_color2 = color2;
    this->brush = GetStockObject(BLACK_BRUSH);
    this->stock_brush = 1;
    brush_color = 0;
}

int TEasy_Panel::set_palette(char* file_name, long resource_file_id) {
    if (this->palette != 0) {
        panel_system.release_palette(this->palette);
        this->palette = 0;
    }

    if (this->shadow_color_table != 0) {
        delete this->shadow_color_table;
        this->shadow_color_table = 0;
    }

    if (resource_file_id == -1) {
        if (file_name != 0 && *file_name != '\0') {
            if (stricmp(file_name, "none") == 0) {
                return 1;
            }
        } else {
            return 1;
        }
    }

    void* p = panel_system.get_palette(file_name, resource_file_id);
    this->palette = p;
    if (p == 0 || this->shadow_amount <= 0) {
        return 0;
    }

    tagPALETTEENTRY palette_entries[256];
    if (GetPaletteEntries(p, 0, 256, palette_entries) != 0) {
            this->shadow_color_table = new RGE_Color_Table(this->render_area, this->shadow_amount, 0, palette_entries);
    }
    return 1;
}

int TEasy_Panel::set_cursor(char* file_name, long resource_id) {
    strcpy(this->cursor_file, file_name);
    this->cursor_id = resource_id;
    return 1;
}

void TEasy_Panel::set_use_bevels(int use_bevels_in) { this->use_bevels = use_bevels_in; }

void TEasy_Panel::set_background_pos(int background_pos_in) { this->background_pos = background_pos_in; }

void TEasy_Panel::set_bevel_colors(unsigned char c1, unsigned char c2, unsigned char c3,
                                   unsigned char c4, unsigned char c5, unsigned char c6) {
    this->bevel_color1 = c1;
    this->bevel_color2 = c2;
    this->bevel_color3 = c3;
    this->bevel_color4 = c4;
    this->bevel_color5 = c5;
    this->bevel_color6 = c6;
}

void TEasy_Panel::set_text_colors(unsigned long c1, unsigned long c2) {
    this->text_color1 = c1;
    this->text_color2 = c2;
}

void TEasy_Panel::set_focus_colors(unsigned long c1, unsigned long c2) {
    this->focus_color1 = c1;
    this->focus_color2 = c2;
}

void TEasy_Panel::set_state_colors(unsigned long c1, unsigned long c2) {
    this->state_color1 = c1;
    this->state_color2 = c2;
}

void TEasy_Panel::set_popup_info_file(char* file_name, long resource_file_id) {
    if (file_name) {
        strcpy(popup_info_file_name, file_name);
    } else {
        popup_info_file_name[0] = 0;
    }
    popup_info_id = resource_file_id;
}

void TEasy_Panel::set_button_pics(char* file_name, long resource_file_id) {
    char file_name2[260];

    TShape* old = this->button_pics;
    if (old != 0) {
        delete old;
        this->button_pics = 0;
    }

    if (file_name != 0 && *file_name != 0 && stricmp(file_name, "none") != 0) {
        if (strchr(file_name, '.') == 0) {
            sprintf(file_name2, "%s.shp", file_name);
        } else {
            sprintf(file_name2, "%s", file_name);
        }
        this->button_pics = new TShape(file_name2, resource_file_id);
    } else if (resource_file_id != -1) {
        this->button_pics = new TShape("", resource_file_id);
    }

    if (this->button_pics != 0 && this->button_pics->is_loaded() == 0) {
        TShape* shape = this->button_pics;
        if (shape != 0) {
            delete shape;
        }
        this->button_pics = 0;
    }
}

void TEasy_Panel::set_shadow_amount(long val) {
    PALETTEENTRY palette_entries[256];

    if (val == -1) {
        this->shadow_amount = 0;
    } else {
        this->shadow_amount = val;
    }

    if (this->shadow_color_table != 0) {
        delete this->shadow_color_table;
        this->shadow_color_table = 0;
    }

    if (this->palette != 0 && this->shadow_amount > 0) {
        if (GetPaletteEntries(this->palette, 0, 256, palette_entries)) {
            this->shadow_color_table = new RGE_Color_Table(this->render_area, this->shadow_amount, 0, palette_entries);
        }
    }

    if (this->have_focus != 0) {
        this->set_redraw(TPanel::RedrawImmediate);
    }
}

void TEasy_Panel::set_enable_ime(int enable_ime_in) {
    this->enable_ime = enable_ime_in;
    if (this->have_focus != 0) {
        if (enable_ime_in != 0) {
            panel_system.EnableIME();
            return;
        }
        panel_system.DisableIME();
    }
}

char* TEasy_Panel::get_info_file() { return this->info_file_name; }

long TEasy_Panel::get_info_id() { return this->info_id; }

TShape* TEasy_Panel::get_background() { return this->background_pic; }

TShape* TEasy_Panel::get_background2() { return this->background_pic2; }

void* TEasy_Panel::get_palette() { return this->palette; }

char* TEasy_Panel::get_cursor() { return this->cursor_file; }

int TEasy_Panel::get_use_bevels() { return this->use_bevels; }

int TEasy_Panel::get_background_pos() { return this->background_pos; }

void TEasy_Panel::get_bevel_colors(unsigned char& c1, unsigned char& c2, unsigned char& c3, unsigned char& c4, unsigned char& c5, unsigned char& c6) {
    c1 = this->bevel_color1;
    c2 = this->bevel_color2;
    c3 = this->bevel_color3;
    c4 = this->bevel_color4;
    c5 = this->bevel_color5;
    c6 = this->bevel_color6;
}

void TEasy_Panel::get_text_colors(unsigned long& c1, unsigned long& c2) {
    c1 = this->text_color1;
    c2 = this->text_color2;
}

void TEasy_Panel::get_focus_colors(unsigned long& c1, unsigned long& c2) {
    c1 = this->focus_color1;
    c2 = this->focus_color2;
}

long TEasy_Panel::get_shadow_amount() { return this->shadow_amount; }

void TEasy_Panel::get_state_colors(unsigned long& c1, unsigned long& c2) {
    c1 = this->state_color1;
    c2 = this->state_color2;
}

char* TEasy_Panel::get_popup_info_file() { return this->popup_info_file_name; }

long TEasy_Panel::get_popup_info_id() { return this->popup_info_id; }

TShape* TEasy_Panel::get_button_pics() { return this->button_pics; }

RGE_Color_Table* TEasy_Panel::get_shadow_color_table() { return this->shadow_color_table; }

int TEasy_Panel::get_enable_ime() { return this->enable_ime; }

int TEasy_Panel::create_button(TPanel* parent, TButtonPanel** button,
                               long text_id1, long text_id2, long x, long y,
                               long width, long height, long font_num,
                               long sound_num, long action_id) {
    char text2[120];
    char text1[120];

    this->get_string(text_id1, text1, 120);
    this->get_string(text_id2, text2, 120);
    return this->create_button(parent, button, text1, text2, x, y, width, height, font_num, sound_num, action_id);
}

int TEasy_Panel::create_button(TPanel* parent, TButtonPanel** button,
                               char* text1, char* text2, long x, long y,
                               long width, long height, long font_num,
                               long sound_num, long action_id) {
    TDigital* sound;
    long ideal_x;
    long sy;
    long sw;
    long sh;
    int i;

    sound = 0;
    ideal_x = (x * this->pnl_wid) / this->ideal_width;
    sy = (y * this->pnl_hgt) / this->ideal_height;
    sw = (width * this->pnl_wid) / this->ideal_width;
    sh = (height * this->pnl_hgt) / this->ideal_height;

    TButtonPanel* button_panel = new TButtonPanel;
    *button = button_panel;
    if (*button != 0 && (*button)->error_code == 0) {
        if (sound_num >= 0) {
            sound = rge_base_game->get_sound(sound_num);
        }

        if ((*button)->setup(this->render_area, parent, ideal_x, sy, sw, sh, TButtonPanel::DrawText, sound,
                             TButtonPanel::NotifyAction, action_id) != 0) {
            (*button)->set_sound_number(sound_num);
            RGE_Font* font;
            if (font_num >= 0) {
                font = rge_base_game->get_font(font_num);
            } else {
                font = rge_base_game->get_font(10);
            }
            (*button)->set_text_info(text1, font->font, font->font_wid, font->font_hgt, -1, -1);
            if (text2 != 0) {
                (*button)->set_text(1, text2);
            }
            if (this->use_bevels != 0) {
                (*button)->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            }
            i = 0;
            do {
                (*button)->set_text_color(i, this->text_color1, this->text_color2);
                (*button)->set_highlight_text_color(i, this->focus_color1, this->focus_color2);
                ++i;
            } while (i < 9);
            (*button)->set_text_color(1, this->state_color1, this->state_color2);
            (*button)->set_highlight_text_color(1, this->focus_color1, this->focus_color2);
            i = 1;
        } else {
            this->error_code = 1;
            i = 0;
        }
    } else {
        this->error_code = 1;
        i = 0;
    }
    return i;
}

int TEasy_Panel::create_check_box(TPanel* parent, TButtonPanel** button,
                                 long x, long y, long width, long height,
                                 long sound_num, long action_id) {
    TDigital* sound;
    long ideal_x;
    long sy;
    long sw;
    long sh;

    sound = 0;
    ideal_x = x * this->pnl_wid / this->ideal_width;
    sy = y * this->pnl_hgt / this->ideal_height;
    sw = width * this->pnl_wid / this->ideal_width;
    sh = height * this->pnl_hgt / this->ideal_height;
    TButtonPanel* button_panel = new TButtonPanel;
    *button = button_panel;
    if (button_panel != 0 && button_panel->error_code == 0) {
        if (sound_num >= 0) sound = rge_base_game->get_sound(sound_num);
        if ((*button)->setup(this->render_area, parent, ideal_x, sy, sw, sh, TButtonPanel::DrawBevelPicture, sound,
                             TButtonPanel::NotifyAction, action_id)) {
            (*button)->set_sound_number(sound_num);
            (*button)->set_state_info(2);
            if (this->button_pics) {
                (*button)->setDrawType(TButtonPanel::DrawBevelPicture);
                (*button)->set_picture(0, this->button_pics, 0);
                (*button)->set_picture(1, this->button_pics, 2);
            } else {
                RGE_Font* font = rge_base_game->get_font(0);
                (*button)->set_text_info(s_space, font->font, font->font_wid, font->font_hgt, -1, -1);
                (*button)->set_text(1, s_X);
                (*button)->setDrawType(TButtonPanel::DrawText);
            }
            if (this->use_bevels) {
                (*button)->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            }
            (*button)->set_text_color(0, this->text_color1, this->text_color2);
            (*button)->set_highlight_text_color(0, this->focus_color1, this->focus_color2);
            (*button)->set_text_color(1, this->state_color1, this->state_color2);
            (*button)->set_highlight_text_color(1, this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_radio_button(TPanel* parent, TButtonPanel** button,
                                     long x, long y, long width, long height,
                                     long sound_num, long action_id) {
    long ideal_x = x;
    TButtonPanel* button_panel;
    TDigital* sound;
    long sx;
    long sy;
    long sw;
    long sh;

    sound = 0;
    sx = (ideal_x * this->pnl_wid) / this->ideal_width;
    sy = (y * this->pnl_hgt) / this->ideal_height;
    sw = (width * this->pnl_wid) / this->ideal_width;
    sh = (height * this->pnl_hgt) / this->ideal_height;

    button_panel = new TButtonPanel;
    *button = button_panel;
    if (*button != 0 && (*button)->error_code == 0) {
        if (sound_num >= 0) {
            sound = rge_base_game->get_sound(sound_num);
        }

        if ((*button)->setup(this->render_area, parent, sx, sy, sw, sh, TButtonPanel::DrawPicture, sound,
                             TButtonPanel::NotifyAction, action_id)) {
            (*button)->set_sound_number(sound_num);

            if (this->button_pics != 0) {
                (*button)->setDrawType(TButtonPanel::DrawBevelPicture);
                (*button)->set_picture(0, this->button_pics, 4);
                (*button)->set_picture(1, this->button_pics, 6);
            } else {
                RGE_Font* font;
                (*button)->setDrawType(TButtonPanel::DrawText);
                font = rge_base_game->get_font(0);
                (*button)->set_text_info(s_space, font->font, font->font_wid, font->font_hgt, -1, -1);
                (*button)->set_text(1, s_X);
            }

            if (this->use_bevels != 0) {
                (*button)->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            }
            (*button)->set_text_color(0, this->text_color1, this->text_color2);
            (*button)->set_highlight_text_color(0, this->focus_color1, this->focus_color2);
            (*button)->set_text_color(1, this->state_color1, this->state_color2);
            (*button)->set_highlight_text_color(1, this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** text_panel,
                             int text_id, long x, long y, long width,
                             long height, long font_num, int horz_center,
                             int vert_center, int word_wrap) {
    char text[256];

    this->get_string(text_id, text, 256);
    return this->create_text(parent, text_panel, text, x, y, width, height, font_num, horz_center, vert_center, word_wrap);
}

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** text_panel,
                             char* text, long x, long y, long width,
                             long height, long font_num, int horz_center,
                             int vert_center, int word_wrap) {
    long ideal_x = (x * this->pnl_wid) / this->ideal_width;
    long ideal_y = (y * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (width * this->pnl_wid) / this->ideal_width;
    long ideal_h = (height * this->pnl_hgt) / this->ideal_height;

    *text_panel = new TTextPanel;
    if (*text_panel != 0 && (*text_panel)->error_code == 0) {
        RGE_Font* font;
        if (font_num >= 0) {
            font = rge_base_game->get_font(font_num);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*text_panel)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, font->font, font->font_wid,
                                 font->font_hgt, 0, 0, 0, 0, 0, 0, (char*)0) != 0) {
            if (horz_center != 0 && vert_center != 0) {
                (*text_panel)->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
            } else if (horz_center != 0) {
                (*text_panel)->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignCenter);
            } else if (vert_center != 0) {
                (*text_panel)->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignLeft);
            } else {
                (*text_panel)->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignLeft);
            }
            (*text_panel)->set_word_wrap(word_wrap);
            (*text_panel)->set_text(text);
            (*text_panel)->set_text_color(this->text_color1, this->text_color2);
            (*text_panel)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** text_panel,
                             char** text, long line_num, long x, long y,
                             long width, long height, long font_num,
                             int horz_center, int vert_center) {
    long ideal_x = (x * this->pnl_wid) / this->ideal_width;
    long ideal_y = (y * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (width * this->pnl_wid) / this->ideal_width;
    long ideal_h = (height * this->pnl_hgt) / this->ideal_height;

    TTextPanel* text_panel_instance = new TTextPanel;
    *text_panel = text_panel_instance;
    if (text_panel_instance != 0 && text_panel_instance->error_code == 0) {
        RGE_Font* font;
        if (font_num >= 0) {
            font = rge_base_game->get_font(font_num);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*text_panel)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, font->font, font->font_wid,
                                 font->font_hgt, 0, 0, 0, 0, 0, 0, (char*)0) != 0) {
            (*text_panel)->set_text(text, line_num);
            (*text_panel)->scroll(6, 0, 1);
            if (horz_center != 0 && vert_center != 0) {
                (*text_panel)->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
            } else if (horz_center != 0) {
                (*text_panel)->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignCenter);
            } else if (vert_center != 0) {
                (*text_panel)->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignLeft);
            } else {
                (*text_panel)->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignLeft);
            }
            (*text_panel)->set_text_color(this->text_color1, this->text_color2);
            (*text_panel)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_input(TPanel* parent, TInputPanel** input_panel,
                              char* value, short max_len,
                              TInputPanel::FormatType format_type, long x,
                              long y, long width, long height, long font_num) {
    long ideal_x = (x * this->pnl_wid) / this->ideal_width;
    long ideal_y = (y * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (width * this->pnl_wid) / this->ideal_width;
    long ideal_h = (height * this->pnl_hgt) / this->ideal_height;

    *input_panel = new TInputPanel;
    if (*input_panel != 0 && (*input_panel)->error_code == 0) {
        RGE_Font* font;
        if (font_num >= 0) {
            font = rge_base_game->get_font(font_num);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*input_panel)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h,
                                  font->font, font->font_wid, font->font_hgt, 0, 0, 0, 1, 0xff, 0xff, max_len, 0, value,
                                  format_type) != 0) {
            if (this->use_bevels != 0) {
                (*input_panel)->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                                               this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            }
            (*input_panel)->set_text_color(this->text_color1, this->text_color2);
            (*input_panel)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }

    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_edit(TPanel* parent, TEditPanel** edit_panel,
                             char* value, short max_len,
                             TEditPanel::FormatType format_type, long x,
                             long y, long width, long height, long font_num,
                             int enable_ime, int turn_ime_on) {
    int scaled_x = (x * this->pnl_wid) / this->ideal_width;
    int scaled_y = (this->pnl_hgt * y) / this->ideal_height;
    int scaled_width = (width * this->pnl_wid) / this->ideal_width;

    *edit_panel = new TEditPanel;
    if (*edit_panel != 0 && (*edit_panel)->error_code == 0) {
        RGE_Font* font;
        if (font_num >= 0) {
            font = rge_base_game->get_font(font_num);
        } else {
            font = rge_base_game->get_font(10);
        }

        int multiline = (format_type != 7) ? 1 : 0;

        if ((*edit_panel)->setup(this->render_area, parent, scaled_x, scaled_y,
                                 scaled_width, height, font->font, max_len, value, format_type, multiline)) {

            if (this->use_bevels) {
                (*edit_panel)->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                                              this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            }

            (*edit_panel)->set_text_color(this->text_color1, this->text_color2);
            (*edit_panel)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            (*edit_panel)->set_back_color(this->brush, this->brush_color, this->background_color1);
            (*edit_panel)->set_ime_info(enable_ime, turn_ime_on);

            return 1;
        }
    }

    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_drop_down(TPanel* parent, TDropDownPanel** drop_panel,
                                  long list_width, long list_height, long x,
                                  long y, long width, long height, long font_num) {
    long ideal_x = x * this->pnl_wid / this->ideal_width;
    long ideal_y = y * this->pnl_hgt / this->ideal_height;
    long ideal_w = width * this->pnl_wid / this->ideal_width;
    long ideal_h = height * this->pnl_hgt / this->ideal_height;
    long button_size = (this->pnl_wid * 18) / this->ideal_width;
    long list_w = list_width * this->pnl_wid / this->ideal_width;
    long list_h = list_height * this->pnl_hgt / this->ideal_height;
    if (font_num >= 0)
        rge_base_game->get_font(font_num);
    else
        rge_base_game->get_font(10);
    char** list = (char**)calloc(1,4);
    if (list == 0) { this->error_code = 1; return 0; }
    list[0] = (char*)calloc(20,1);
    if (list[0] == 0) return 0;
    strcpy(list[0], " ");
    if (this->error_code == 0) {
        *drop_panel = new TDropDownPanel;
        if (*drop_panel != 0 && (*drop_panel)->error_code == 0) {
            RGE_Font* font = rge_base_game->get_font(font_num);
            if ((*drop_panel)->setup(this->render_area,parent,font->font,font->font_wid,font->font_hgt,0,0,1,0xff,ideal_x,ideal_y,ideal_w,ideal_h,0,0,button_size,ideal_h,0,list_w,list_h,list,1,button_size,0,0,0,0,button_size,button_size)) {
                if (this->button_pics) (*drop_panel)->set_buttons(this->button_pics,0xe,-1,8,10,0xc);
                if (this->use_bevels) (*drop_panel)->set_bevel_info(3,bevel_color1,bevel_color2,bevel_color3,bevel_color4,bevel_color5,bevel_color6);
                (*drop_panel)->set_val_text_color(text_color1,text_color2);
                TListPanel* lp = (*drop_panel)->list_panel;
                lp->set_text_color(text_color1,text_color2);
                lp->set_highlight_text_color(focus_color1,focus_color2);
                (*drop_panel)->val_panel->set_bevel_info(3,bevel_color1,bevel_color2,bevel_color3,bevel_color4,bevel_color5,bevel_color6);
                goto cleanup;
            }
        }
        this->error_code = 1;
    }
cleanup: {
        char** p = list;
        int count = 1;
        do {
            if (*p) { free(*p); *p = 0; }
            ++p;
            --count;
        } while (count != 0);
        free(list);
    }
    return this->error_code == 0;
}

int TEasy_Panel::create_list(TPanel* parent, TListPanel** list_panel,
                             long x, long y, long width, long height,
                             long font_num) {
    struct ScaledPoint {
        long y;
        long x;
    } ideal;

    ideal.x = (x * this->pnl_wid) / this->ideal_width;
    ideal.y = (y * this->pnl_hgt) / this->ideal_height;
    char** list_items;
    RGE_Font* font;

    width = (width * this->pnl_wid) / this->ideal_width;
    long ideal_h = (height * this->pnl_hgt) / this->ideal_height;

    if (font_num >= 0) {
        rge_base_game->get_font(font_num);
    } else {
        rge_base_game->get_font(10);
    }

    list_items = (char**)calloc(1, sizeof(char*));
    if (list_items == 0) {
        this->error_code = 1;
        return 0;
    }
    list_items[0] = (char*)calloc(20, 1);
    if (list_items[0] == 0) {
        goto cleanup_fail;
    }
    strcpy(list_items[0], " ");

    if (this->error_code == 0) {
        TListPanel* list_panel_instance = new TListPanel;
        *list_panel = list_panel_instance;
        if (list_panel_instance != 0 && list_panel_instance->error_code == 0) {
            font = rge_base_game->get_font(font_num);
            if ((*list_panel)->setup(this->render_area, parent, ideal.x, ideal.y, width, ideal_h, font->font, font->font_wid, font->font_hgt, 0, 0, 0, 1, 0xFF, 0, list_items, 1) != 0) {
                (*list_panel)->scroll_cur_line(1, 0, 1);
                goto cleanup_success;
            }
        }
        this->error_code = 1;
    }

cleanup_success: {
        int n = 1;
        char** p = list_items;
        do {
            if (*p != 0) {
                free(*p);
                *p = 0;
            }
            ++p;
            --n;
        } while (n != 0);
    }
    free(list_items);
    if (this->use_bevels != 0) {
        TListPanel* list_panel_instance = *list_panel;
        list_panel_instance->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    }
    (*list_panel)->set_text_color(this->text_color1, this->text_color2);
    (*list_panel)->set_highlight_text_color(this->focus_color1, this->focus_color2);
    return 1;

cleanup_fail:
    return 0;
}

int TEasy_Panel::create_scrollbar(TPanel* parent,
                                  TScrollBarPanel** scrollbar_panel,
                                  TTextPanel* list_panel, long list_size,
                                  long x, long y, long width, long height) {
    long scaled_x = (this->pnl_wid * x) / this->ideal_width;
    long scaled_y = (y * this->pnl_hgt) / this->ideal_height;
    long h = (height * this->pnl_hgt) / this->ideal_height;
    TScrollBarPanel* sb = new TScrollBarPanel;
    *scrollbar_panel = sb;

    if (sb != 0) {
        if (sb->error_code == 0) {
            if (sb->setup(this->render_area, parent, scaled_x, scaled_y, width, h, 0, 0, 0, 0, width, width, list_panel, list_size, TScrollBarPanel::Vertical) != 0) {
                if (list_panel != 0) {
                    list_panel->set_scrollbar(*scrollbar_panel, 0);
                }

                if (this->button_pics != 0) {
                    (*scrollbar_panel)->set_buttons(this->button_pics, -1, 8, 10, 12);
                }

                if (this->use_bevels != 0) {
                    (*scrollbar_panel)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                }

                return 1;
            }
        }
    }

    return 0;
}

int TEasy_Panel::create_auto_scrollbar(TScrollBarPanel** scrollbar_panel,
                                       TTextPanel* list_panel, long width) {
    if (this->create_scrollbar(list_panel->parent_panel, scrollbar_panel, list_panel, 0, 0, 0, width, 0) == 0) {
        return 0;
    }

    list_panel->set_scrollbar(*scrollbar_panel, 1);
    return 1;
}

int TEasy_Panel::create_vert_slider(TPanel* parent,
                                    TVerticalSliderPanel** slider_panel,
                                    long scale, long one_step, long page_step,
                                    long x, long y, long width, long height) {
    long ideal_x = (x * this->pnl_wid) / this->ideal_width;
    long ideal_y = (y * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (width * this->pnl_wid) / this->ideal_width;
    long ideal_h = (height * this->pnl_hgt) / this->ideal_height;

    *slider_panel = new TVerticalSliderPanel;
    if (*slider_panel != 0 && (*slider_panel)->error_code == 0 &&
        (*slider_panel)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, 0, 0, 0, scale, one_step, page_step, 1, 0) != 0) {
        if (this->button_pics != 0) {
            (*slider_panel)->set_buttons(this->button_pics, -1, 8, 10, 12);
        }

        if (this->use_bevels != 0) {
            (*slider_panel)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
        }

        return 1;
    }

    return 0;
}

int TEasy_Panel::create_horz_slider(TPanel* parent,
                                    THorizontalSliderPanel** slider_panel,
                                    long scale, long one_step, long page_step,
                                    long x, long y, long width, long height) {
    long ideal_x = (x * this->pnl_wid) / this->ideal_width;
    long ideal_y = (y * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (width * this->pnl_wid) / this->ideal_width;
    long ideal_h = (height * this->pnl_hgt) / this->ideal_height;

    int result;
    *slider_panel = new THorizontalSliderPanel;
    if (*slider_panel != 0 && (*slider_panel)->error_code == 0 &&
        (*slider_panel)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, 0, 0, 0, scale, one_step, page_step, 1, 0) != 0) {
        if (this->button_pics != 0) {
            (*slider_panel)->set_buttons(this->button_pics, -1, 8, 10, 12);
        }

        if (this->use_bevels != 0) {
            (*slider_panel)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
        }
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

void TEasy_Panel::position_panel(TPanel* panel, long x, long y, long width, long height) {
    panel->set_fixed_position((x * this->pnl_wid) / this->ideal_width, (y * this->pnl_hgt) / this->ideal_height,
                              (width * this->pnl_wid) / this->ideal_width, (height * this->pnl_hgt) / this->ideal_height);
}

void TEasy_Panel::set_focus(int have_focus_in) {
    TPanel::set_focus(have_focus_in);

    if (this->have_focus != 0) {
        if ((this->cursor_file[0] != 0 || this->cursor_id >= 0) && rge_base_game->mouse_pointer != 0) {
            rge_base_game->mouse_pointer->LoadCursors(this->cursor_file, this->cursor_id, 0);
        }

        if (this->render_area != 0 && this->render_area->DrawSystem != 0) {
            void* pal = this->palette;
            if (pal == 0) {
                pal = rge_base_game->prog_palette;
            }
            if (pal != 0 && this->render_area->DrawSystem->Pal != pal) {
                this->render_area->Clear(0, 0);
                this->render_area->DrawSystem->Paint(0);
                this->render_area->DrawSystem->SetPalette(pal);
                this->set_redraw(TPanel::RedrawImmediate);
            }
        }
    }

    if (this->enable_ime != 0) {
        if (this->have_focus != 0) {
            panel_system.EnableIME();
        } else {
            panel_system.DisableIME();
        }
    }
}

void TEasy_Panel::popupOKDialog(long text_id, char* panel_title, int wid, int hgt) {
    char text[256];

    get_string(text_id, text, 256);
    popupOKDialog(text, panel_title, wid, hgt);
}

void TEasy_Panel::popupOKDialog(char* text, char* panel_title, int wid, int hgt) {
    char temp_title[256];

    if (panel_title != 0 && *panel_title != 0) {
        strcpy(temp_title, panel_title);
    } else {
        strcpy(temp_title, "OKDialog");
    }

    if (panel_system.panel(temp_title) != 0) {
        panel_system.destroyPanel(temp_title);
    }

    TMessageDialog* dialog = new TMessageDialog(temp_title);
    dialog->setup(this, this->popup_info_file_name, this->popup_info_id, wid, hgt, 0, text, 90, 30);
}

void TEasy_Panel::popupYesNoDialog(long text_id, char* panel_title, int wid, int hgt) {
    char text[256];

    this->get_string(text_id, text, 256);
    this->popupYesNoDialog(text, panel_title, wid, hgt);
}

void TEasy_Panel::popupYesNoDialog(char* text, char* panel_title, int wid, int hgt) {
    TMessageDialog* dialog;

    if (panel_title != 0 && *panel_title != 0) {
        dialog = new TMessageDialog(panel_title);
    } else {
        dialog = new TMessageDialog("YesNoDialog");
    }

    dialog->setup(this, this->popup_info_file_name, this->popup_info_id, wid, hgt, 2, text, 90, 30);
}

void TEasy_Panel::popupYesNoCancelDialog(long text_id, char* panel_title, int wid, int hgt) {
    char text[256];
    this->get_string(text_id, text, 256);
    this->popupYesNoCancelDialog(text, panel_title, wid, hgt);
}

void TEasy_Panel::popupYesNoCancelDialog(char* text, char* panel_title, int wid, int hgt) {
    TMessageDialog* dialog;

    if (panel_title != 0 && *panel_title != 0) {
        dialog = new TMessageDialog(panel_title);
    } else {
        dialog = new TMessageDialog("YesNoCancelDialog");
    }

    dialog->setup(this, this->popup_info_file_name, this->popup_info_id, wid, hgt, 4, text, 120, 25);
}

void TEasy_Panel::command_help(char* in_parent_panel, long help_string,
                               long help_page, long x, long y) {
    if (help_string >= 0) {
        char* text = this->get_string(help_string);
        if (text || *text != 0) {
            new THelpDialog(this, in_parent_panel, help_string, help_page, x, y);
        }
    }
}

void TEasy_Panel::command_help(char* in_parent_panel, char* help_string,
                               long help_page, long x, long y) {
    if (help_string != 0 && *help_string != 0) {
        new THelpDialog(this, in_parent_panel, help_string, help_page, x, y);
    }
}

void TEasy_Panel::setup_popup_help(void) {
    this->help_mode = 1;
    rge_base_game->set_mouse_cursor(LoadCursorA(NULL, MAKEINTRESOURCEA(TEASY_SCENARIO_EDITOR_CURSOR)));
    rge_base_game->set_mouse_facet(6);
    this->saved_mouse_mode = rge_base_game->mouse_pointer->get_game_enable();
    rge_base_game->mouse_pointer->set_game_enable(0);
}

void TEasy_Panel::clear_popup_help(void) {
    this->help_mode = 0;
    rge_base_game->set_mouse_cursor(LoadCursorA(0, IDC_ARROW));
    rge_base_game->set_mouse_facet(0);
    rge_base_game->mouse_pointer->set_game_enable(this->saved_mouse_mode);
}

long TEasy_Panel::command_do_popup_help(unsigned char mouse_button_in,
                                        long mouse_x, long mouse_y) {
    long help_page;
    char* temp;
    char help_string2[1000];

    temp = help_string2;
    if (this->help_mode == 1) {
        this->help_mode = 0;
        rge_base_game->set_mouse_cursor(LoadCursorA(0, IDC_ARROW));
        rge_base_game->set_mouse_facet(0);
        rge_base_game->mouse_pointer->set_game_enable(this->saved_mouse_mode);
        if (mouse_button_in == 1) {
            if (this->get_help_info(temp, help_page, mouse_x, mouse_y)) {
                this->command_help(this->panel_name, help_string2, help_page, mouse_x, mouse_y);
            }
        }
        return 1;
    }
    return 0;
}

long TEasy_Panel::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    if (fromPanel) {
        if (fromPanel->panelName() && strcmp(fromPanel->panelName(), "OKDialog") == 0) {
            if (actionIn == 0 || actionIn == 1) {
                panel_system.destroyPanel("OKDialog");
            }
            return 1;
        }
        if (fromPanel->panelName() && strcmp(fromPanel->panelName(), "YesNoDialog") == 0) {
            if (actionIn == 0 || actionIn == 1) {
                panel_system.destroyPanel("YesNoDialog");
            }
            return 1;
        }
        if (fromPanel->panelName() && strcmp(fromPanel->panelName(), "YesNoCancelDialog") == 0) {
            if (actionIn == 0 || actionIn == 1 || actionIn == 2) {
                panel_system.destroyPanel("YesNoCancelDialog");
            }
            return 1;
        }
    }
    return TPanel::action(fromPanel, actionIn, a1, a2);
}

void TEasy_Panel::set_system_colors() {
    unsigned long cols;
    int elems;
    PALETTEENTRY pe;

    GetPaletteEntries(this->palette, this->color, 1, &pe);
    cols = (pe.peBlue << 16) | (pe.peGreen << 8) | pe.peRed;
    elems = 5;
    SetSysColors(1, &elems, &cols);

    GetPaletteEntries(this->palette, this->text_color1, 1, &pe);
    cols = (pe.peBlue << 16) | (pe.peGreen << 8) | pe.peRed;
    elems = 8;
    SetSysColors(1, &elems, &cols);
}
