// PDB source module: C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp.
// Definitions follow the shipped source order.

#include "../include/tpnl_inv.h"
#include "../include/Shape.h"
#include "../include/tplayer.h"
#include "../include/colorlog.h"
#include <stdio.h>
#include <string.h>

extern char s_tpnl_inv_draw[];
extern const char s_fmt_ld[];
// BINARY NOTE: No current canonical owner header declares this C helper.
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

// tpnl_inv.cpp:33-61
TRIBE_Panel_Inven::TRIBE_Panel_Inven(
    TDrawArea* area, TPanel* parent, void* font_, TRIBE_Player* player_)
    : TPanel()
{
    this->font = font_;
    this->save_attr_num = 0;
    this->save_attr = 0;
    this->pics = 0;
    this->idle_time = 0;
    this->player = 0;
    this->back_color = 0;
    this->idle_interval = 500;
    this->font_color = 0xFFFFFF;

    if (this->setup(area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
    } else {
        this->set_player(player_);
    }
}

// tpnl_inv.cpp:67-71
void TRIBE_Panel_Inven::set_text_color(unsigned long color1,
                                       unsigned long color2) {
    this->font_color = color1;
    this->back_color = color2;
    this->set_redraw(TPanel::RedrawNormal);
}

// tpnl_inv.cpp:77-91
TRIBE_Panel_Inven::~TRIBE_Panel_Inven() {
    if (this->save_attr != 0) {
        free(this->save_attr);
        this->save_attr = 0;
    }

    if (this->pics != 0) {
        delete this->pics;
        this->pics = 0;
    }

    // The shipped body calls the base destructor. Compiler cleanup calls it
    // again after this body.
    this->TPanel::~TPanel();
}

// tpnl_inv.cpp:97-158
void TRIBE_Panel_Inven::draw() {
    char str[20];

    if (this->render_area == 0 || this->visible == 0 ||
        this->active == 0) {
        this->need_redraw = TPanel::RedrawNone;
        return;
    }

    if (this->parent_panel != 0)
        this->parent_panel->draw_rect(&this->clip_rect);

    if (this->player == 0) {
        this->need_redraw = TPanel::RedrawNone;
        return;
    }

    this->draw_setup(0);
    if (this->render_area->GetDc(s_tpnl_inv_draw) != 0) {
        void* old_font = SelectObject(this->render_area->DrawDc, this->font);
        SetBkMode(this->render_area->DrawDc, 1);

        long x = this->pnl_x + 0x20;
        long y = this->pnl_y + 2;

        sprintf(str, s_fmt_ld, (long)this->player->attributes[1]);
        SetTextColor(this->render_area->DrawDc, this->back_color);
        TextOutA(this->render_area->DrawDc, x - 1, y + 1, str, strlen(str));
        SetTextColor(this->render_area->DrawDc, this->font_color);
        TextOutA(this->render_area->DrawDc, x, y, str, strlen(str));

        x = this->pnl_x + 0x63;
        sprintf(str, s_fmt_ld, (long)this->player->attributes[0]);
        SetTextColor(this->render_area->DrawDc, this->back_color);
        TextOutA(this->render_area->DrawDc, x - 1, y + 1, str, strlen(str));
        SetTextColor(this->render_area->DrawDc, this->font_color);
        TextOutA(this->render_area->DrawDc, x, y, str, strlen(str));

        x = this->pnl_x + 0xA6;
        sprintf(str, s_fmt_ld, (long)this->player->attributes[3]);
        SetTextColor(this->render_area->DrawDc, this->back_color);
        TextOutA(this->render_area->DrawDc, x - 1, y + 1, str, strlen(str));
        SetTextColor(this->render_area->DrawDc, this->font_color);
        TextOutA(this->render_area->DrawDc, x, y, str, strlen(str));

        x = this->pnl_x + 0xE9;
        sprintf(str, s_fmt_ld, (long)this->player->attributes[2]);
        SetTextColor(this->render_area->DrawDc, this->back_color);
        TextOutA(this->render_area->DrawDc, x - 1, y + 1, str, strlen(str));
        SetTextColor(this->render_area->DrawDc, this->font_color);
        TextOutA(this->render_area->DrawDc, x, y, str, strlen(str));

        SelectObject(this->render_area->DrawDc, old_font);
        this->render_area->ReleaseDc(s_tpnl_inv_draw);
    }
    this->draw_finish();
}

// tpnl_inv.cpp:164-198
long TRIBE_Panel_Inven::handle_idle() {
    this->TPanel::handle_idle();

    int mode = rge_base_game->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        unsigned long now = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp", 0xAD);
        if (now - this->idle_time >= (unsigned long)this->idle_interval) {
            color_log(0xBA, 0xBA, 5);

            int changed = 0;
            short i = 0;
            if (0 < this->save_attr_num) {
                short* saved = this->save_attr;
                float* values = this->player->attributes;
                for (;;) {
                    if (i >= this->save_attr_num)
                        break;
                    if ((short)(int)values[i] != saved[i]) {
                        changed = true;
                        break;
                    }
                    ++i;
                }
            }

            if (changed) {
                color_log(0xBA, 0x16, 5);
                this->save_info();
                this->set_redraw(TPanel::RedrawNormal);
            }

            this->idle_time = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp", 0xC2);
            color_log(0xBA, 0x5F, 5);
        }
    }
    return 0;
}

// tpnl_inv.cpp:204-208
void TRIBE_Panel_Inven::set_player(TRIBE_Player* player) {
    this->player = player;
    this->save_info();
    this->set_redraw(TPanel::RedrawNormal);
}

// tpnl_inv.cpp:214-230
void TRIBE_Panel_Inven::save_info() {
    if (this->save_attr == 0 ||
        this->save_attr_num != this->player->attribute_num) {
        if (this->save_attr != 0) {
            free(this->save_attr);
            this->save_attr = 0;
        }
        this->save_attr_num = this->player->attribute_num;
        this->save_attr = (short*)calloc((int)this->save_attr_num, 2);
    }

    for (int i = 0; i < this->save_attr_num; ++i)
        this->save_attr[i] = (short)(int)this->player->attributes[i];
}

// tpnl_inv.cpp:236-265
unsigned char TRIBE_Panel_Inven::get_help_info(char*& out_str,
                                               long& out_val,
                                               long x, long y) {
    if (this->active == 0)
        return 0;

    if (!this->is_inside(x, y))
        return 0;

    if (x < this->pnl_x + 0x37) {
        sprintf(out_str, this->get_string(0x1D4EE),
                (int)this->player->attributes[1]);
        out_val = -1;
    } else if (x < this->pnl_x + 0x6E) {
        sprintf(out_str, this->get_string(0x1D4ED),
                (int)this->player->attributes[0]);
        out_val = -1;
    } else if (x < this->pnl_x + 0xA5) {
        sprintf(out_str, this->get_string(0x1D4EF),
                (int)this->player->attributes[3]);
        out_val = -1;
    } else {
        sprintf(out_str, this->get_string(0x1D4F0),
                (int)this->player->attributes[2]);
        out_val = -1;
    }

    return 1;
}
