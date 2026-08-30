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
    : TPanel(name)
{
    init_vars();
}

long TEasy_Panel::setup(TDrawArea* area, TPanel* parent, char* info_file, long info_id, int use_area_size,
                        long x, long y, long w, long h, int allow_shadow)
{
    int own_mem;
    int f2g;
    int f2r;
    int back_pic_id_b2;
    int f1b;
    int back_pic_id_c2;
    int f1g;
    int back_pic_id_a2;
    int f1r;
    int pal_id;
    int s2b;
    int background_pos_in;
    int s2g;
    int bc6;
    int s2r;
    int bc4;
    int s1b;
    int bc2;
    int s1g;
    int t2b;
    int s1r;
    int t2r;
    int button_pic_id;
    int t1g;
    int popup_info_id;
    int f2b;
    int bc5;
    int bc3;
    int back_pic_id_a1;
    int bc1;
    int cursor_id;
    int t2g;
    int back_pic_id_c1;
    int t1b;
    int background_color1_in;
    int t1r;
    int shad_amt;
    int back_pic_id_b1;
    int resDataSize;
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
    char popup_info_file_name_in[256];

    f2g = -1;
    this->allow_shadow_area = allow_shadow;
    set_info_file(info_file, info_id);
    if (use_area_size != 0) {
        x = 0;
        y = 0;
        if (area != 0) {
            w = area->Width;
            h = area->Height;
        } else {
            w = 0;
            h = 0;
        }
    } else if (w > 0 && h > 0 && area != 0) {
        if (x == -1) {
            x = area->Width / 2 - w / 2;
        }
        if (y == -1) {
            y = area->Height / 2 - h / 2;
        }
    }
    if (TPanel::setup(area, parent, x, y, w, h, 0) == 0) {
        return 0;
    }
    this->set_ideal_size(w, h);
    if (use_area_size != 0) {
        this->set_positioning((TPanel::PositionMode)1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    unsigned char* data = 0;
    if (shape_file_first != 0 && this->info_file_name != 0 && this->info_file_name[0] != 0) {
        if (strchr(this->info_file_name, '.') == 0) {
            sprintf(info_file_name2, "%s.sin", this->info_file_name);
        } else {
            sprintf(info_file_name2, "%s", this->info_file_name);
        }
        int fd = _open(info_file_name2, _O_BINARY);
        if (fd != -1) {
            _lseek(fd, 0, 2);
            long size = _tell(fd);
            data = (unsigned char*)malloc(size);
            if (data != 0) {
                _lseek(fd, 0, 0);
                _read(fd, data, size);
                own_mem = 1;
            }
            _close(fd);
        }
    }
    if (data == 0) {
        if (this->info_id != -1) {
            data = RESFILE_load(0x62696E61, this->info_id, own_mem, resDataSize);
        }
        if (data == 0) {
            return 1;
        }
    }
    if (sscanf((char*)data,
        "%s %s %s %d %d   %s %s %s %d %d   %s %s %s %d %d   %s %s %d   %s %s %d   %s %s %d   %s %s %d   %s %s %d   %s %d   %s %d    %s %d %d %d %d %d %d   %s %d %d %d   %s %d %d %d   %s %d %d %d   %s %d %d %d  %s %d %d %d  %s %d %d %d",
        temp_label,
        background_pic_file_name_a1, background_pic_file_name_a2,
        &back_pic_id_a1, &back_pic_id_a2,
        temp_label,
        background_pic_file_name_b1, background_pic_file_name_b2,
        &back_pic_id_b1, &back_pic_id_b2,
        temp_label,
        background_pic_file_name_c1, background_pic_file_name_c2,
        &back_pic_id_c1, &back_pic_id_c2,
        temp_label, palette_file_name, &pal_id,
        temp_label, cursor_file_name, &cursor_id,
        temp_label, temp_label, &shad_amt,
        temp_label, button_pics_file_name, &button_pic_id,
        temp_label, popup_info_file_name_in, &popup_info_id,
        temp_label, &background_pos_in,
        temp_label, &background_color1_in,
        temp_label, &bc1, &bc2, &bc3, &bc4, &bc5, &bc6,
        temp_label, &t1r, &t1g, &t1b,
        temp_label, &t2r, &t2g, &t2b,
        temp_label, &f1r, &f1g, &f1b,
        temp_label, &f2r, &f2g, &f2b,
        temp_label, &s1r, &s1g, &s1b,
        temp_label, &s2r, &s2g, &s2b) != -1) {
        set_use_bevels(1);
        if (this->render_area->Width < 800 || stricmp(background_pic_file_name_b1, "none") == 0) {
            set_background(background_pic_file_name_a1, back_pic_id_a1);
            set_background2(background_pic_file_name_a2, back_pic_id_a2);
        } else if (this->render_area->Width < 0x400) {
            set_background(background_pic_file_name_b1, back_pic_id_b1);
            set_background2(background_pic_file_name_b2, back_pic_id_b2);
        } else {
            set_background(background_pic_file_name_c1, back_pic_id_c1);
            set_background2(background_pic_file_name_c2, back_pic_id_c2);
        }
        set_shadow_amount(shad_amt);
        set_palette(palette_file_name, pal_id);
        set_cursor(cursor_file_name, cursor_id);
        set_background_pos(background_pos_in);
        set_background_colors(background_color1_in, background_color1_in);
        set_bevel_colors(bc1, bc2, bc3, bc4, bc5, bc6);
        set_text_colors((unsigned char)t1b << 16 | (unsigned char)t1g << 8 | (unsigned char)t1r,
                        (unsigned char)t2b << 16 | (unsigned char)t2g << 8 | (unsigned char)t2r);
        set_focus_colors((unsigned char)f1b << 16 | (unsigned char)f1g << 8 | (unsigned char)f1r,
                         (unsigned char)f2b << 16 | (unsigned char)f2g << 8 | (unsigned char)f2r);
        set_state_colors((unsigned char)s1b << 16 | (unsigned char)s1g << 8 | (unsigned char)s1r,
                         (unsigned char)s2b << 16 | (unsigned char)s2g << 8 | (unsigned char)s2r);
        set_button_pics(button_pics_file_name, button_pic_id);
        set_popup_info_file(popup_info_file_name_in, popup_info_id);
    }
    if (own_mem == 1) {
        free(data);
    }
    return 1;
}

TEasy_Panel::TEasy_Panel()
    : TPanel()
{
    init_vars();
}

void TEasy_Panel::init_vars() {
    this->ideal_width = 0x280;
    this->ideal_height = 0x1E0;
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

void TEasy_Panel::setup_shadow_area(int force)
{
    char area_name[256];

    TDrawArea* area = this->shadow_area;
    if ((area == 0 || force != 0) &&
        this->background_pic != 0 && this->shadow_color_table != 0) {
        unsigned long old_flags = this->render_area->DrawSystem->Flags;

        if (area == 0) {
            this->render_area->DrawSystem->Flags &= 1;
            sprintf(area_name + 4, "%s Shadow Panel", this->panel_name);
            this->shadow_area = new TDrawArea(area_name + 4, 0);
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

            if (this->shadow_area->Init(this->render_area->DrawSystem,
                                        width, height, 0, 0)) {
                this->shadow_area->Clear(0, this->background_color1);
                if (this->shadow_area->Lock("panel_ez::setup_shadow_area", 1)) {
                    this->background_pic->shape_draw(this->shadow_area,
                                                     0, 0, 0, 0, 0);
                    this->shadow_area->SetShadowTable(this->shadow_color_table);
                    this->shadow_area->DrawShadowBox(0, 0, width - 1, height - 1);
                    this->shadow_area->Unlock("panel_ez::setup_shadow_area");
                }
            }
        }

        this->render_area->DrawSystem->Flags = old_flags;
    }
}

void TEasy_Panel::draw_setup(int p) { this->TPanel::draw_setup(p); }

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

void TEasy_Panel::draw_background(int use_alt)
{
    long y_max;
    long x_min;
    long y_min;
    long x_max;
    long pic_hgt;
    TShape* pic;

    this->draw_setup(0);

    if (use_alt && this->shadow_area) {
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

    if (use_alt && this->background_pic2)
        pic = this->background_pic2;
    else
        pic = this->background_pic;

    if (this->need_redraw == 2 || pic == 0) {
        if (use_alt)
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
            if (use_alt && this->shadow_color_table) {
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
            if (use_alt && this->shadow_color_table) {
                this->render_area->SetShadowTable(this->shadow_color_table);
                this->render_area->DrawShadowBox(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1);
            }
            break;
        }
        default:
            pic->shape_draw(this->render_area, this->pnl_x, this->pnl_y, 0, 0, 0);
            if (use_alt && this->shadow_color_table) {
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

long TEasy_Panel::handle_mouse_down(unsigned char button, long x, long y, int flags, int area) {
    if (this->command_do_popup_help(button, x, y) != 0) {
        return 1;
    }
    return TPanel::handle_mouse_down(button, x, y, flags, area);
}

void TEasy_Panel::set_info_file(char* fname, long id) {
    if (fname) {
        strcpy(this->info_file_name, fname);
    } else {
        this->info_file_name[0] = '\0';
    }
    this->info_id = id;
}

void TEasy_Panel::set_ideal_size(long width, long height) {
    this->ideal_width = width;
    this->ideal_height = height;
}

int TEasy_Panel::set_background(char* filename, long id) {
    char file_name2[260];

    TShape* old = this->background_pic;
    if (old != 0) {
        delete old;
        this->background_pic = 0;
    }

    if (filename != 0 && *filename != 0 && stricmp(filename, "none") != 0) {
        if (strchr(filename, '.') == 0) {
            sprintf(file_name2, "%s.shp", filename);
        } else {
            sprintf(file_name2, "%s", filename);
        }
        this->background_pic = new TShape(file_name2, id);
    } else if (id != -1) {
        this->background_pic = new TShape("", id);
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

int TEasy_Panel::set_background2(char* filename, long id) {
    char file_name2[260];

    TShape* old = this->background_pic2;
    if (old != 0) {
        delete old;
        this->background_pic2 = 0;
    }

    if (filename != 0 && *filename != 0 && stricmp(filename, "none") != 0) {
        if (strchr(filename, '.') == 0) {
            sprintf(file_name2, "%s.shp", filename);
        } else {
            sprintf(file_name2, "%s", filename);
        }
        this->background_pic2 = new TShape(file_name2, id);
    } else if (id != -1) {
        this->background_pic2 = new TShape("", id);
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
    this->brush = GetStockObject(4);
    this->stock_brush = 1;
    brush_color = 0;
}

int TEasy_Panel::set_palette(char* param_1, long param_2)
{
    if (this->palette != 0) {
        panel_system.release_palette(this->palette);
        this->palette = 0;
    }

    if (this->shadow_color_table != 0) {
        delete this->shadow_color_table;
        this->shadow_color_table = 0;
    }

    if (param_2 == -1) {
        if (param_1 != 0 && *param_1 != '\0') {
            if (stricmp(param_1, "none") == 0) {
                return 1;
            }
        } else {
            return 1;
        }
    }

    void* p = panel_system.get_palette(param_1, param_2);
    this->palette = p;
    if (p == 0 || this->shadow_amount <= 0) {
        return 0;
    }

    tagPALETTEENTRY palette_entries[256];
    if (GetPaletteEntries(p, 0, 0x100, palette_entries) != 0) {
            this->shadow_color_table = new RGE_Color_Table(
            this->render_area,
            this->shadow_amount,
            0,
            palette_entries);
    }
    return 1;
}

int TEasy_Panel::set_cursor(char* cursor_name, long cursor_id_value) {
    strcpy(this->cursor_file, cursor_name);
    this->cursor_id = cursor_id_value;
    return 1;
}

void TEasy_Panel::set_use_bevels(int v) { this->use_bevels = v; }

void TEasy_Panel::set_background_pos(int v) { this->background_pos = v; }

void TEasy_Panel::set_bevel_colors(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f) {
    this->bevel_color1 = a;
    this->bevel_color2 = b;
    this->bevel_color3 = c;
    this->bevel_color4 = d;
    this->bevel_color5 = e;
    this->bevel_color6 = f;
}

void TEasy_Panel::set_text_colors(unsigned long a, unsigned long b) {
    this->text_color1 = a;
    this->text_color2 = b;
}

void TEasy_Panel::set_focus_colors(unsigned long a, unsigned long b) {
    this->focus_color1 = a;
    this->focus_color2 = b;
}

void TEasy_Panel::set_state_colors(unsigned long a, unsigned long b) {
    this->state_color1 = a;
    this->state_color2 = b;
}

void TEasy_Panel::set_popup_info_file(char* filename, long id) {
    if (filename) {
        strcpy(popup_info_file_name, filename);
        popup_info_id = id;
        return;
    }
    popup_info_file_name[0] = 0;
    popup_info_id = id;
}

void TEasy_Panel::set_button_pics(char* filename, long id) {
    char file_name2[260];

    TShape* old = this->button_pics;
    if (old != 0) {
        delete old;
        this->button_pics = 0;
    }

    if (filename != 0 && *filename != 0 && stricmp(filename, "none") != 0) {
        if (strchr(filename, '.') == 0) {
            sprintf(file_name2, "%s.shp", filename);
        } else {
            sprintf(file_name2, "%s", filename);
        }
        this->button_pics = new TShape(file_name2, id);
    } else if (id != -1) {
        this->button_pics = new TShape("", id);
    }

    if (this->button_pics != 0 && this->button_pics->is_loaded() == 0) {
        TShape* shape = this->button_pics;
        if (shape != 0) {
            delete shape;
        }
        this->button_pics = 0;
    }
}

void TEasy_Panel::set_shadow_amount(long amount) {
    PALETTEENTRY palette_entries[256];

    if (amount == -1) {
        this->shadow_amount = 0;
    } else {
        this->shadow_amount = amount;
    }

    if (this->shadow_color_table != 0) {
        delete this->shadow_color_table;
        this->shadow_color_table = 0;
    }

    if (this->palette != 0 && this->shadow_amount > 0) {
        if (GetPaletteEntries(this->palette, 0, 0x100, palette_entries)) {
            this->shadow_color_table = new RGE_Color_Table(this->render_area, this->shadow_amount, 0, palette_entries);
        }
    }

    if (this->have_focus != 0) {
        this->set_redraw(TPanel::RedrawImmediate);
    }
}

void TEasy_Panel::set_enable_ime(int value) {
    this->enable_ime = value;
    if (this->have_focus != 0) {
        if (value != 0) {
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

void TEasy_Panel::get_text_colors(unsigned long& out1, unsigned long& out2) {
    out1 = this->text_color1;
    out2 = this->text_color2;
}

void TEasy_Panel::get_focus_colors(unsigned long& out1, unsigned long& out2) {
    out1 = this->focus_color1;
    out2 = this->focus_color2;
}

long TEasy_Panel::get_shadow_amount() { return this->shadow_amount; }

void TEasy_Panel::get_state_colors(unsigned long& out1, unsigned long& out2) {
    out1 = this->state_color1;
    out2 = this->state_color2;
}

char* TEasy_Panel::get_popup_info_file() { return this->popup_info_file_name; }

long TEasy_Panel::get_popup_info_id() { return this->popup_info_id; }

TShape* TEasy_Panel::get_button_pics() { return this->button_pics; }

RGE_Color_Table* TEasy_Panel::get_shadow_color_table() { return this->shadow_color_table; }

int TEasy_Panel::get_enable_ime() { return this->enable_ime; }

int TEasy_Panel::create_button(TPanel* parent, TButtonPanel** out, long id1, long id2, long p5, long p6, long p7, long p8, long p9, long p10, long p11) {
    char text2[120];
    char text1[120];

    this->get_string(id1, text1, 0x78);
    this->get_string(id2, text2, 0x78);
    return this->create_button(parent, out, text1, text2, p5, p6, p7, p8, p9, p10, p11);
}

int TEasy_Panel::create_button(TPanel* panel, TButtonPanel** out, char* text, char* label, long x, long y, long w, long h, long font_id, long sound_id, long user)
{
    TDigital* sound;
    long sx;
    long sy;
    long sw;
    long sh;
    int i;

    sound = 0;
    sx = (x * this->pnl_wid) / this->ideal_width;
    sy = (y * this->pnl_hgt) / this->ideal_height;
    sw = (w * this->pnl_wid) / this->ideal_width;
    sh = (h * this->pnl_hgt) / this->ideal_height;

    TButtonPanel* button = new TButtonPanel;
    *out = button;
    if (*out != 0 && (*out)->error_code == 0) {
        if (sound_id >= 0) {
            sound = rge_base_game->get_sound(sound_id);
        }

        if ((*out)->setup(this->render_area, panel, sx, sy, sw, sh,
                          TButtonPanel::DrawPicture, sound,
                          TButtonPanel::NotifyAction, user) != 0) {
            (*out)->set_sound_number(sound_id);
            RGE_Font* font;
            if (font_id >= 0) {
                font = rge_base_game->get_font(font_id);
            } else {
                font = rge_base_game->get_font(10);
            }
            (*out)->set_text_info(text, font->font, font->font_wid, font->font_hgt, -1, -1);
            if (label != 0) {
                (*out)->set_text(1, label);
            }
            if (this->use_bevels != 0) {
                (*out)->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            }
            i = 0;
            do {
                (*out)->set_text_color(i, this->text_color1, this->text_color2);
                (*out)->set_highlight_text_color(i, this->focus_color1, this->focus_color2);
                ++i;
            } while (i < 9);
            (*out)->set_text_color(1, this->state_color1, this->state_color2);
            (*out)->set_highlight_text_color(1, this->focus_color1, this->focus_color2);
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

int TEasy_Panel::create_check_box(TPanel* panel, TButtonPanel** out, long x, long y, long w, long h, long sound, long id)
{
    TDigital* snd;
    long sx;
    long sy;
    long sw;
    long sh;

    snd = 0;
    sx = x * this->pnl_wid / this->ideal_width;
    sy = y * this->pnl_hgt / this->ideal_height;
    sw = w * this->pnl_wid / this->ideal_width;
    sh = h * this->pnl_hgt / this->ideal_height;
    TButtonPanel* b = new TButtonPanel;
    *out = b;
    if (b != 0 && b->error_code == 0) {
        if (sound >= 0) snd = rge_base_game->get_sound(sound);
        if ((*out)->setup(this->render_area, panel, sx, sy, sw, sh,
                          TButtonPanel::DrawBevelPicture, snd,
                          TButtonPanel::NotifyAction, id)) {
            (*out)->set_sound_number(sound);
            (*out)->set_state_info(2);
            if (this->button_pics) {
                (*out)->setDrawType(TButtonPanel::DrawBevelPicture);
                (*out)->set_picture(0, this->button_pics, 0);
                (*out)->set_picture(1, this->button_pics, 2);
            } else {
                RGE_Font* f = rge_base_game->get_font(0);
                (*out)->set_text_info(s_space, f->font, f->font_wid, f->font_hgt, -1, -1);
                (*out)->set_text(1, s_X);
                (*out)->setDrawType(TButtonPanel::DrawPicture);
            }
            if (this->use_bevels) {
                (*out)->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            }
            (*out)->set_text_color(0, this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(0, this->focus_color1, this->focus_color2);
            (*out)->set_text_color(1, this->state_color1, this->state_color2);
            (*out)->set_highlight_text_color(1, this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_radio_button(TPanel* parent, TButtonPanel** out, long x, long y, long w, long h, long sound_id, long param8)
{
    long ideal_x = x;
    TButtonPanel* button;
    TDigital* sound;
    long sx;
    long sy;
    long sw;
    long sh;

    sound = 0;
    sx = (ideal_x * this->pnl_wid) / this->ideal_width;
    sy = (y * this->pnl_hgt) / this->ideal_height;
    sw = (w * this->pnl_wid) / this->ideal_width;
    sh = (h * this->pnl_hgt) / this->ideal_height;

    button = new TButtonPanel;
    *out = button;
    if (*out != 0 && (*out)->error_code == 0) {
        if (sound_id >= 0) {
            sound = rge_base_game->get_sound(sound_id);
        }

        if ((*out)->setup(this->render_area, parent, sx, sy, sw, sh,
                          TButtonPanel::DrawText, sound,
                          TButtonPanel::NotifyAction, param8)) {
            (*out)->set_sound_number(sound_id);

            if (this->button_pics != 0) {
                (*out)->setDrawType(TButtonPanel::DrawBevelPicture);
                (*out)->set_picture(0, this->button_pics, 4);
                (*out)->set_picture(1, this->button_pics, 6);
            }
            else {
                RGE_Font* font;
                (*out)->setDrawType(TButtonPanel::DrawPicture);
                font = rge_base_game->get_font(0);
                (*out)->set_text_info(s_space, font->font, font->font_wid, font->font_hgt, -1, -1);
                (*out)->set_text(1, s_X);
            }

            if (this->use_bevels != 0) {
                (*out)->set_bevel_info(4, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            }
            (*out)->set_text_color(0, this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(0, this->focus_color1, this->focus_color2);
            (*out)->set_text_color(1, this->state_color1, this->state_color2);
            (*out)->set_highlight_text_color(1, this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** out, int string_id, long p4, long p5, long p6, long p7, long p8, int p9, int p10, int p11) {
    char text[256];

    this->get_string(string_id, text, 0x100);
    return this->create_text(parent, out, text, p4, p5, p6, p7, p8, p9, p10, p11);
}

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** out, char* text, long p4, long p5, long p6, long p7, long font_id, int center_h, int center_v, int word_wrap) {
    long ideal_x = (p4 * this->pnl_wid) / this->ideal_width;
    long ideal_y = (p5 * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (p6 * this->pnl_wid) / this->ideal_width;
    long ideal_h = (p7 * this->pnl_hgt) / this->ideal_height;

    *out = new TTextPanel;
    if (*out != 0 && (*out)->error_code == 0) {
        RGE_Font* font;
        if (font_id >= 0) {
            font = rge_base_game->get_font(font_id);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*out)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, font->font, font->font_wid, font->font_hgt, 0, 0, 0, 0, 0, 0, (char*)0) != 0) {
            if (center_h != 0 && center_v != 0) {
                (*out)->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
            } else if (center_h != 0) {
                (*out)->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignCenter);
            } else if (center_v != 0) {
                (*out)->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignLeft);
            } else {
                (*out)->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignLeft);
            }
            (*out)->set_word_wrap(word_wrap);
            (*out)->set_text(text);
            (*out)->set_text_color(this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** out, char** text, long text_id,
                             long x, long y, long w, long h, long font_id,
                             int center_h, int center_v)
{
    long ideal_x = (x * this->pnl_wid) / this->ideal_width;
    long ideal_y = (y * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (w * this->pnl_wid) / this->ideal_width;
    long ideal_h = (h * this->pnl_hgt) / this->ideal_height;

    TTextPanel* panel = new TTextPanel;
    *out = panel;
    if (panel != 0 && panel->error_code == 0) {
        RGE_Font* font;
        if (font_id >= 0) {
            font = rge_base_game->get_font(font_id);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*out)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h,
                          font->font, font->font_wid, font->font_hgt,
                          0, 0, 0, 0, 0, 0, (char*)0) != 0) {
            (*out)->set_text(text, text_id);
            (*out)->scroll(6, 0, 1);
            if (center_h != 0 && center_v != 0) {
                (*out)->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
            } else if (center_h != 0) {
                (*out)->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignCenter);
            } else if (center_v != 0) {
                (*out)->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignLeft);
            } else {
                (*out)->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignLeft);
            }
            (*out)->set_text_color(this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_input(TPanel* parent, TInputPanel** out, char* text, short max_len, int format,
                              long x, long y, long w, long h, long font_id)
{
    long ideal_x = (x * this->pnl_wid) / this->ideal_width;
    long ideal_y = (y * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (w * this->pnl_wid) / this->ideal_width;
    long ideal_h = (h * this->pnl_hgt) / this->ideal_height;

    *out = new TInputPanel;
    if (*out != 0 && (*out)->error_code == 0) {
        RGE_Font* font;
        if (font_id >= 0) {
            font = rge_base_game->get_font(font_id);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*out)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h,
                          font->font, font->font_wid, font->font_hgt,
                          0, 0, 0, 1, 0xff, 0xff, max_len, 0, text,
                          (TInputPanel::FormatType)format) != 0) {
            if (this->use_bevels != 0) {
                (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                                       this->bevel_color3, this->bevel_color4,
                                       this->bevel_color5, this->bevel_color6);
            }
            (*out)->set_text_color(this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }

    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_edit(TPanel* p1, TEditPanel** p2, char* p3, short p4, int p5,
                              long p6, long p7, long p8, long p9, long p10,
                              int p11, int p12)
{
    int x = (p6 * this->pnl_wid) / this->ideal_width;
    int y = (this->pnl_hgt * p7) / this->ideal_height;
    int width = (p8 * this->pnl_wid) / this->ideal_width;

    *p2 = new TEditPanel;
    if (*p2 != 0 && (*p2)->error_code == 0) {
        RGE_Font* font;
        if (p10 >= 0) {
            font = rge_base_game->get_font(p10);
        } else {
            font = rge_base_game->get_font(10);
        }

        int multiline = (p5 != 7) ? 1 : 0;

        if ((*p2)->setup(this->render_area, p1, x, y, width, p9,
                         font->font, p4, p3,
                         (TEditPanel::FormatType)p5, multiline)) {

            if (this->use_bevels) {
                (*p2)->set_bevel_info(3,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color3, this->bevel_color4,
                    this->bevel_color5, this->bevel_color6);
            }

            (*p2)->set_text_color(this->text_color1, this->text_color2);
            (*p2)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            (*p2)->set_back_color(this->brush, this->brush_color, this->background_color1);
            (*p2)->set_ime_info(p11, p12);

            return 1;
        }
    }

    this->error_code = 1;
    return 0;
}

int TEasy_Panel::create_drop_down(TPanel* parent, TDropDownPanel** drop_panel,
                                  long list_width, long list_height, long x,
                                  long y, long width, long height, long font_num)
{
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
    list[0] = (char*)calloc(0x14,1);
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
cleanup:
    {
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

int TEasy_Panel::create_list(TPanel* parent, TListPanel** out, long x, long y, long w, long h, long font_id)
{
    long ideal_x = (x * this->pnl_wid) / this->ideal_width;
    long ideal_y = (y * this->pnl_hgt) / this->ideal_height;
    char** list_items;
    RGE_Font* font;

    w = (w * this->pnl_wid) / this->ideal_width;
    h = (h * this->pnl_hgt) / this->ideal_height;

    if (font_id >= 0) {
        rge_base_game->get_font(font_id);
    } else {
        rge_base_game->get_font(10);
    }

    list_items = (char**)calloc(1, sizeof(char*));
    if (list_items == 0) {
        this->error_code = 1;
        return 0;
    }
    list_items[0] = (char*)calloc(0x14, 1);
    if (list_items[0] == 0) {
        goto cleanup_fail;
    }
    strcpy(list_items[0], " ");

    if (this->error_code == 0) {
        TListPanel* list = new TListPanel;
        *out = list;
        if (list != 0 && list->error_code == 0) {
            font = rge_base_game->get_font(font_id);
            if ((*out)->setup(this->render_area, parent, ideal_x, ideal_y, w, h, font->font, font->font_wid, font->font_hgt, 0, 0, 0, 1, 0xFF, 0, list_items, 1) != 0) {
                (*out)->scroll_cur_line(1, 0, 1);
                goto cleanup_success;
            }
        }
        this->error_code = 1;
    }

cleanup_success:
    {
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
        TListPanel* list = *out;
        list->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    }
    (*out)->set_text_color(this->text_color1, this->text_color2);
    (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
    return 1;

cleanup_fail:
    return 0;
}

int TEasy_Panel::create_scrollbar(TPanel* parent, TScrollBarPanel** out, TTextPanel* text, long param_4, long param_5, long param_6, long param_7, long param_8) {
    long x = (this->pnl_wid * param_5) / this->ideal_width;
    long y = (param_6 * this->pnl_hgt) / this->ideal_height;
    long h = (param_8 * this->pnl_hgt) / this->ideal_height;
    TScrollBarPanel* sb = new TScrollBarPanel;
    *out = sb;

    if (sb != 0) {
        if (sb->error_code == 0) {
            if (sb->setup(this->render_area, parent, x, y, param_7, h, 0, 0, 0, 0, param_7, param_7, text, param_4, TScrollBarPanel::Vertical) != 0) {
                if (text != 0) {
                    text->set_scrollbar(*out, 0);
                }

                if (this->button_pics != 0) {
                    (*out)->set_buttons(this->button_pics, -1, 8, 10, 12);
                }

                if (this->use_bevels != 0) {
                    (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                }

                return 1;
            }
        }
    }

    return 0;
}

int TEasy_Panel::create_auto_scrollbar(TScrollBarPanel** scrollbar_out, TTextPanel* text, long param_3) {
    if (this->create_scrollbar(text->parent_panel, scrollbar_out, text, 0, 0, 0, param_3, 0) == 0) {
        return 0;
    }

    text->set_scrollbar(*scrollbar_out, 1);
    return 1;
}

int TEasy_Panel::create_vert_slider(TPanel* parent, TVerticalSliderPanel** out, long p3, long p4, long p5, long p6, long p7, long p8, long p9) {
    long ideal_x = (p6 * this->pnl_wid) / this->ideal_width;
    long ideal_y = (p7 * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (p8 * this->pnl_wid) / this->ideal_width;
    long ideal_h = (p9 * this->pnl_hgt) / this->ideal_height;

    *out = new TVerticalSliderPanel;
    if (*out != 0 && (*out)->error_code == 0 &&
        (*out)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, 0, 0, 0, p3, p4, p5, 1, 0) != 0) {
        if (this->button_pics != 0) {
            (*out)->set_buttons(this->button_pics, -1, 8, 10, 12);
        }

        if (this->use_bevels != 0) {
            (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
        }

        return 1;
    }

    return 0;
}

int TEasy_Panel::create_horz_slider(TPanel* parent, THorizontalSliderPanel** out, long p3, long p4, long p5, long p6, long p7, long p8, long p9) {
    long ideal_x = (p6 * this->pnl_wid) / this->ideal_width;
    long ideal_y = (p7 * this->pnl_hgt) / this->ideal_height;
    long ideal_w = (p8 * this->pnl_wid) / this->ideal_width;
    long ideal_h = (p9 * this->pnl_hgt) / this->ideal_height;

    int result;
    *out = new THorizontalSliderPanel;
    if (*out != 0 && (*out)->error_code == 0 &&
        (*out)->setup(this->render_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, 0, 0, 0, p3, p4, p5, 1, 0) != 0) {
        if (this->button_pics != 0) {
            (*out)->set_buttons(this->button_pics, -1, 8, 10, 12);
        }

        if (this->use_bevels != 0) {
            (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
        }
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

void TEasy_Panel::position_panel(TPanel* panel, long x, long y, long w, long h) {
    panel->set_fixed_position(
        (x * this->pnl_wid) / this->ideal_width,
        (y * this->pnl_hgt) / this->ideal_height,
        (w * this->pnl_wid) / this->ideal_width,
        (h * this->pnl_hgt) / this->ideal_height);
}

void TEasy_Panel::set_focus(int focus) {
    TPanel::set_focus(focus);

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

void TEasy_Panel::popupOKDialog(long string_id, char* text, int value1, int value2) {
    char title[256];

    get_string(string_id, title, 0x100);
    popupOKDialog(title, text, value1, value2);
}

void TEasy_Panel::popupOKDialog(char* title, char* panel_name, int a, int b) {
    char temp_title[256];

    if (panel_name != 0 && *panel_name != 0) {
        strcpy(temp_title, panel_name);
    } else {
        strcpy(temp_title, "OKDialog");
    }

    if (panel_system.panel(temp_title) != 0) {
        panel_system.destroyPanel(temp_title);
    }

    TMessageDialog* dialog = new TMessageDialog(temp_title);
    dialog->setup(this, this->popup_info_file_name, this->popup_info_id, a, b, 0, title, 0x5A, 0x1E);
}

void TEasy_Panel::popupYesNoDialog(long string_id, char* param_2, int param_3, int param_4) {
    char text[256];

    this->get_string(string_id, text, 0x100);
    this->popupYesNoDialog(text, param_2, param_3, param_4);
}

void TEasy_Panel::popupYesNoDialog(char* title, char* message, int a, int b) {
    TMessageDialog* dialog;

    if (message != 0 && *message != 0) {
        dialog = new TMessageDialog(message);
    } else {
        dialog = new TMessageDialog("YesNoDialog");
    }

    dialog->setup(this, this->popup_info_file_name, this->popup_info_id, a, b, 2, title, 0x5A, 0x1E);
}

void TEasy_Panel::popupYesNoCancelDialog(long param_1, char* param_2, int param_3, int param_4) {
    char text[256];
    this->get_string(param_1, text, 0x100);
    this->popupYesNoCancelDialog(text, param_2, param_3, param_4);
}

void TEasy_Panel::popupYesNoCancelDialog(char* title, char* message, int a, int b) {
    TMessageDialog* dialog;

    if (message != 0 && *message != 0) {
        dialog = new TMessageDialog(message);
    } else {
        dialog = new TMessageDialog("YesNoCancelDialog");
    }

    dialog->setup(this, this->popup_info_file_name, this->popup_info_id, a, b, 4, title, 0x78, 0x19);
}

void TEasy_Panel::command_help(char* title, long string_id, long a, long b, long c) {
    if (string_id >= 0) {
        char* text = this->get_string(string_id);
        if (text || *text != 0) {
            new THelpDialog(this, title, string_id, a, b, c);
        }
    }
}

void TEasy_Panel::command_help(char* title, char* text, long a, long b, long c) {
    if (text != 0 && *text != 0) {
        new THelpDialog(this, title, text, a, b, c);
    }
}

void TEasy_Panel::setup_popup_help(void) {
    this->help_mode = 1;
    rge_base_game->set_mouse_cursor(LoadCursorA(0, MAKEINTRESOURCEA(0x7F8B)));
    rge_base_game->set_mouse_facet(6);
    this->saved_mouse_mode = rge_base_game->mouse_pointer->get_game_enable();
    rge_base_game->mouse_pointer->set_game_enable(0);
}

void TEasy_Panel::clear_popup_help(void) {
    this->help_mode = 0;
    rge_base_game->set_mouse_cursor(LoadCursorA(0, MAKEINTRESOURCEA(0x7F00)));
    rge_base_game->set_mouse_facet(0);
    rge_base_game->mouse_pointer->set_game_enable(this->saved_mouse_mode);
}

long TEasy_Panel::command_do_popup_help(unsigned char clicked, long x, long y) {
    long help_page;
    char* temp;
    char help_string2[1000];

    temp = help_string2;
    if (this->help_mode == 1) {
        this->help_mode = 0;
        rge_base_game->set_mouse_cursor(LoadCursorA(0, MAKEINTRESOURCEA(0x7F00)));
        rge_base_game->set_mouse_facet(0);
        rge_base_game->mouse_pointer->set_game_enable(this->saved_mouse_mode);
        if (clicked == 1) {
            if (this->get_help_info(temp, help_page, x, y)) {
                this->command_help(this->panel_name, help_string2, help_page, x, y);
            }
        }
        return 1;
    }
    return 0;
}

long TEasy_Panel::action(TPanel* panel, long p2, unsigned long p3, unsigned long p4) {
    if (panel) {
        if (panel->panelName() && strcmp(panel->panelName(), "OKDialog") == 0) {
            if (p2 == 0 || p2 == 1) {
                panel_system.destroyPanel("OKDialog");
            }
            return 1;
        }
        if (panel->panelName() && strcmp(panel->panelName(), "YesNoDialog") == 0) {
            if (p2 == 0 || p2 == 1) {
                panel_system.destroyPanel("YesNoDialog");
            }
            return 1;
        }
        if (panel->panelName() && strcmp(panel->panelName(), "YesNoCancelDialog") == 0) {
            if (p2 == 0 || p2 == 1 || p2 == 2) {
                panel_system.destroyPanel("YesNoCancelDialog");
            }
            return 1;
        }
    }
    return TPanel::action(panel, p2, p3, p4);
}

void TEasy_Panel::set_system_colors() {
    unsigned long color;
    int element;
    PALETTEENTRY pe;
    PALETTEENTRY entry;

    GetPaletteEntries(this->palette, this->color, 1, &entry);
    color = (entry.peBlue << 16) | (entry.peGreen << 8) | entry.peRed;
    element = 5;
    SetSysColors(1, &element, &color);

    GetPaletteEntries(this->palette, this->text_color1, 1, &entry);
    color = (entry.peBlue << 16) | (entry.peGreen << 8) | entry.peRed;
    element = 8;
    SetSysColors(1, &element, &color);
}
