#include "../include/TRIBE_Panel_Inven.h"

#include "../include/TDrawArea.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TShape.h"
#include "../include/TRIBE_Player.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char kTpnlInvSourcePath[] = "C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp";
static const char kTpnlInvDrawTag[] = "tpnl_inv::draw";

TRIBE_Panel_Inven::TRIBE_Panel_Inven(TDrawArea* area, TPanel* parent, void* font_param, TRIBE_Player* player_param)
    : TPanel() {
    // Fully verified. Source of truth: tpnl_inv.cpp.decomp @ 0x0051A5C0
    this->font = font_param;
    this->save_attr_num = 0;
    this->save_attr = nullptr;
    this->pics = nullptr;
    this->idle_time = 0;
    this->player = nullptr;
    this->back_color = 0;
    this->idle_interval = 500;
    this->font_color = 0xFFFFFF;

    if (this->setup(area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_player(player_param);
}

TRIBE_Panel_Inven::~TRIBE_Panel_Inven() {
    // Fully verified. Source of truth: tpnl_inv.cpp.decomp @ 0x0051A6D0
    if (this->save_attr != nullptr) {
        free(this->save_attr);
        this->save_attr = nullptr;
    }

    if (this->pics != nullptr) {
        delete this->pics;
        this->pics = nullptr;
    }
}

void TRIBE_Panel_Inven::set_text_color(unsigned long color1, unsigned long color2) {
    // Fully verified. Source of truth: tpnl_inv.cpp.decomp @ 0x0051A6B0
    this->font_color = color1;
    this->back_color = color2;
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Panel_Inven::draw() {
    // Fully verified. Source of truth: tpnl_inv.cpp.decomp @ 0x0051A770
    char str[20];

    if ((this->render_area != nullptr) && (this->visible != 0) && (this->active != 0)) {
        if (this->parent_panel != nullptr) {
            this->parent_panel->draw_rect(&this->clip_rect);
        }

        if (this->player != nullptr) {
            this->draw_setup(0);

            HDC dc = (HDC)this->render_area->GetDc((char*)kTpnlInvDrawTag);
            if (dc != nullptr) {
                void* old_font = SelectObject(dc, this->font);
                SetBkMode(dc, 1);

                long x = this->pnl_x + 0x20;
                const long y = this->pnl_y + 2;

                sprintf(str, "%ld", (long)this->player->attributes[1]);
                SetTextColor(dc, (COLORREF)this->back_color);
                TextOutA(dc, x - 1, y + 1, str, (int)strlen(str));
                SetTextColor(dc, (COLORREF)this->font_color);
                TextOutA(dc, x, y, str, (int)strlen(str));

                x = this->pnl_x + 0x63;
                sprintf(str, "%ld", (long)this->player->attributes[0]);
                SetTextColor(dc, (COLORREF)this->back_color);
                TextOutA(dc, x - 1, y + 1, str, (int)strlen(str));
                SetTextColor(dc, (COLORREF)this->font_color);
                TextOutA(dc, x, y, str, (int)strlen(str));

                x = this->pnl_x + 0xA6;
                sprintf(str, "%ld", (long)this->player->attributes[3]);
                SetTextColor(dc, (COLORREF)this->back_color);
                TextOutA(dc, x - 1, y + 1, str, (int)strlen(str));
                SetTextColor(dc, (COLORREF)this->font_color);
                TextOutA(dc, x, y, str, (int)strlen(str));

                x = this->pnl_x + 0xE9;
                sprintf(str, "%ld", (long)this->player->attributes[2]);
                SetTextColor(dc, (COLORREF)this->back_color);
                TextOutA(dc, x - 1, y + 1, str, (int)strlen(str));
                SetTextColor(dc, (COLORREF)this->font_color);
                TextOutA(dc, x, y, str, (int)strlen(str));

                SelectObject(dc, old_font);
                this->render_area->ReleaseDc((char*)kTpnlInvDrawTag);
            }

            this->draw_finish();
            return;
        }
    }

    this->need_redraw = TPanel::NoRedraw;
}

long TRIBE_Panel_Inven::handle_idle() {
    // Fully verified. Source of truth: tpnl_inv.cpp.decomp @ 0x0051AAD0
    TPanel::handle_idle();

    const int prog_mode = rge_base_game->prog_mode;
    if (((prog_mode == 4) || (prog_mode == 6) || (prog_mode == 7) || (prog_mode == 5)) &&
        (this->idle_interval <= debug_timeGetTime(kTpnlInvSourcePath, 0xAD) - this->idle_time)) {
        color_log(0xBA, 0xBA, 5);

        int changed = 0;
        if (this->save_attr_num > 0) {
            short i = 0;
            float* attributes = this->player->attributes;
            short* save_attr = this->save_attr;
            while (i < this->save_attr_num) {
                if ((short)((long)attributes[i]) != save_attr[i]) {
                    changed = 1;
                    break;
                }
                ++i;
            }
        }

        if (changed != 0) {
            color_log(0xBA, 0x16, 5);
            this->save_info();
            this->set_redraw(TPanel::Redraw);
        }

        this->idle_time = debug_timeGetTime(kTpnlInvSourcePath, 0xC2);
        color_log(0xBA, '_', 5);
    }

    return 0;
}

void TRIBE_Panel_Inven::set_player(TRIBE_Player* player_param) {
    // Fully verified. Source of truth: tpnl_inv.cpp.decomp @ 0x0051ABF0
    this->player = player_param;
    this->save_info();
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Panel_Inven::save_info() {
    // Fully verified. Source of truth: tpnl_inv.cpp.decomp @ 0x0051AC10
    short* save_attr = this->save_attr;
    if (save_attr != nullptr) {
        if (this->save_attr_num == this->player->attribute_num) {
            goto SAVE_INFO_COPY_ATTR;
        }

        free(save_attr);
        this->save_attr = nullptr;
    }

    this->save_attr_num = this->player->attribute_num;
    this->save_attr = (short*)calloc((int)this->save_attr_num, 2);

SAVE_INFO_COPY_ATTR:
    if (this->save_attr_num > 0) {
        for (int i = 0; i < this->save_attr_num; ++i) {
            this->save_attr[i] = (short)((long)this->player->attributes[i]);
        }
    }
}

uchar TRIBE_Panel_Inven::get_help_info(char** param_1, long* param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: tpnl_inv.cpp.decomp @ 0x0051ACA0
    if (this->active == 0) {
        return 0;
    }
    if (this->is_inside(param_3, param_4) == 0) {
        return 0;
    }

    if (param_3 < this->pnl_x + 0x37) {
        sprintf(*param_1, this->get_string(0x1D4EE), (long)this->player->attributes[1]);
        *param_2 = -1;
        return 1;
    }
    if (param_3 < this->pnl_x + 0x6E) {
        sprintf(*param_1, this->get_string(0x1D4ED), (long)this->player->attributes[0]);
        *param_2 = -1;
        return 1;
    }
    if (param_3 < this->pnl_x + 0xA5) {
        sprintf(*param_1, this->get_string(0x1D4EF), (long)this->player->attributes[3]);
        *param_2 = -1;
        return 1;
    }

    sprintf(*param_1, this->get_string(0x1D4F0), (long)this->player->attributes[2]);
    *param_2 = -1;
    return 1;
}
