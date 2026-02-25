#include "../include/TRIBE_Panel_Time.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Font.h"
#include "../include/TDrawArea.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_World.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <cstdio>
#include <windows.h>

namespace {
const char* const kTpnlTimSourcePath = "C:\\msdev\\work\\age1_x1\\tpnl_tim.cpp";
const char* const kTpnlTimDraw = "tpnl_tim::draw";
const char* const kTpnlTimRender = "tpnl_tim::render_to_image_buffer";

static void tpnl_tim_set_player_color(TRIBE_Panel_Time* panel) {
    if (panel->player == nullptr) {
        panel->color1 = 0xFFFFFF;
        panel->color2 = 0;
        return;
    }

    switch ((int)panel->player->color_table->id) {
    case 0:
        panel->color1 = 0xFF0000;
        panel->color2 = 0xB3B3B3;
        return;
    case 1:
        panel->color1 = 0x2139C6;
        break;
    case 2:
        panel->color1 = 0x00FFFF;
        break;
    case 3:
        panel->color1 = 0x4F73A3;
        break;
    case 4:
        panel->color1 = 0x0F77F3;
        break;
    case 5:
        panel->color1 = 0x00C700;
        break;
    case 6:
        panel->color1 = 0x7B90A2;
        break;
    case 7:
        panel->color1 = 0xADAD00;
        break;
    default:
        panel->color1 = 0xFFFFFF;
        break;
    }

    panel->color2 = 0;
}

static unsigned long tpnl_tim_display_time(unsigned long game_time, int clock_format) {
    if (clock_format == 1) {
        return game_time;
    }
    return ((game_time + 4) / 5) * 5;
}

static UINT tpnl_tim_format_text(TRIBE_Panel_Time* panel, char* str) {
    if (panel->clock_format == 1) {
        unsigned long seconds = panel->game_time;
        long minutes = 0;
        long hours = 0;
        if ((long)seconds > 0x3B) {
            minutes = (long)seconds / 0x3C;
            seconds = (unsigned long)((long)seconds % 0x3C);
            if (minutes > 0x3B) {
                hours = minutes / 0x3C;
                minutes = minutes % 0x3C;
            }
        }

        sprintf(str, "%02ld:%02ld:%02ld (%3.1f)", hours, minutes, (long)seconds, (double)rge_base_game->world->game_speed);
        return 0x20;
    }

    const long rounded_time = (long)tpnl_tim_display_time(panel->game_time, panel->clock_format);
    int string_id = 0x2C24;
    if (panel->clock_type == 4) {
        string_id = 0x2C25;
    } else if (panel->clock_type == 5) {
        string_id = 0x2C26;
    } else if (panel->clock_type == 6) {
        string_id = 0x2C27;
    }

    sprintf(str, panel->get_string(string_id), rounded_time);
    return 0x22;
}

static void tpnl_tim_draw_text(HDC dc, const char* str, int x, int y, int right, int bottom, UINT draw_flags) {
    tagRECT rect;
    SetRect(&rect, x, y, right - 2, bottom - 2);
    DrawTextA(dc, str, -1, &rect, draw_flags);
    SetRect(&rect, x, y + 2, right - 2, bottom);
    DrawTextA(dc, str, -1, &rect, draw_flags);
    SetRect(&rect, x + 2, y, right, bottom - 2);
    DrawTextA(dc, str, -1, &rect, draw_flags);
    SetRect(&rect, x + 2, y + 2, right, bottom);
    DrawTextA(dc, str, -1, &rect, draw_flags);
}
}

TRIBE_Panel_Time::TRIBE_Panel_Time(TDrawArea* area, TPanel* parent) : TPanel() {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051D790
    RGE_Font* panel_font = rge_base_game->get_font(0x0B);
    this->font = panel_font->font;
    this->color1 = 0xFFFFFF;
    this->color2 = 0;
    this->clock_type = 0;
    this->clock_format = 0;
    this->old_clock_type = 0;
    this->old_clock_format = 0;
    this->player_id = 0;
    this->world = nullptr;
    this->player = nullptr;
    this->start_real_time = 0;
    this->game_time = 0;
    this->last_game_time = 0;
    this->last_display_time = 0xFFFFFFFF;
    this->ImageBuffer = nullptr;
    this->LastIBWidth = -1;
    this->LastIBHeight = -1;
    this->ImageTextActive = 0;
    this->image_clip_region = nullptr;

    if (this->setup(area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
    }
}

TRIBE_Panel_Time::~TRIBE_Panel_Time() {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051D8B0
    if (this->image_clip_region != nullptr) {
        DeleteObject((HGDIOBJ)this->image_clip_region);
        this->image_clip_region = nullptr;
    }

    if (this->ImageBuffer != nullptr) {
        delete this->ImageBuffer;
        this->ImageBuffer = nullptr;
    }
}

void TRIBE_Panel_Time::set_rect(long param_1, long param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051D940
    TPanel::set_rect(param_1, param_2, param_3, param_4);

    if (((this->LastIBWidth < this->pnl_wid) || (this->LastIBHeight < this->pnl_hgt)) ||
        (this->render_area->Width <= param_1 + this->LastIBWidth)) {
        if (this->image_clip_region != nullptr) {
            DeleteObject((HGDIOBJ)this->image_clip_region);
            this->image_clip_region = nullptr;
        }

        if (this->ImageBuffer != nullptr) {
            delete this->ImageBuffer;
            this->ImageBuffer = nullptr;
        }

        this->ImageBuffer = new TDrawArea((char*)"time message panel");
        if (this->ImageBuffer != nullptr) {
            this->ImageBuffer->Init(this->render_area->DrawSystem, this->render_area->Wnd, this->pnl_wid, this->pnl_hgt, 0, 0, 0);
        }

        this->LastIBWidth = this->pnl_wid;
        this->LastIBHeight = this->pnl_hgt;

        const int right = this->pnl_wid - 1;
        const int bottom = this->pnl_hgt - 1;
        this->ImageRect.left = 0;
        this->ImageRect.top = 0;
        this->ImageRect.right = right;
        this->ImageRect.bottom = bottom;
        this->image_clip_region = (void*)CreateRectRgn(0, 0, right, bottom);
    }

    if (this->ImageBuffer == nullptr) {
        this->LastIBWidth = -1;
        this->LastIBHeight = -1;
    } else {
        this->UsedImageRect = this->ImageRect;
    }

    this->need_restore = 1;
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Panel_Time::startup() {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051DAD0
    this->world = (TRIBE_World*)rge_base_game->world;
    this->start_real_time = debug_timeGetTime(kTpnlTimSourcePath, 0x92);
}

void TRIBE_Panel_Time::set_clock_type(int clock_type_param, int player_id_param) {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051DB00
    if (this->clock_type == clock_type_param) {
        if (this->player == nullptr) {
            return;
        }
        if ((int)this->player->id == player_id_param) {
            return;
        }
    }

    this->clock_type = clock_type_param;
    if (player_id_param < 1) {
        this->player = nullptr;
    } else {
        this->player = (TRIBE_Player*)this->world->players[player_id_param];
    }

    tpnl_tim_set_player_color(this);

    if (clock_type_param == 1 || clock_type_param == 2) {
        this->clock_format = 1;
    } else {
        this->clock_format = 2;
    }

    this->set_active(clock_type_param != 0);
    this->set_redraw(TPanel::Redraw);
    this->parent_panel->set_redraw(TPanel::Redraw);
    this->handle_idle();
}

int TRIBE_Panel_Time::get_clock_type() {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051DC60
    return this->clock_type;
}

int TRIBE_Panel_Time::get_player_id() {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051DC70
    if (this->player != nullptr) {
        return (int)this->player->id;
    }
    return 0;
}

void TRIBE_Panel_Time::draw() {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051DC90
    if (this->render_area == nullptr || this->active == 0 || this->visible == 0) {
        return;
    }

    this->draw_setup(0);
    this->display_time = tpnl_tim_display_time(this->game_time, this->clock_format);

    if ((this->ImageBuffer != nullptr) &&
        ((this->display_time != this->last_display_time) ||
         (this->clock_type != this->old_clock_type) ||
         (this->clock_format != this->old_clock_format) ||
         (this->need_restore != 0))) {
        this->render_to_image_buffer();
        if (this->need_restore != 0) {
            this->need_restore = 0;
            this->draw_finish();
            return;
        }
    }

    if (this->ImageTextActive != 0 && this->ImageBuffer != nullptr) {
        this->ImageBuffer->SetTrans(1, 1);
        this->ImageBuffer->Copy(this->render_area, this->UsedScreenRect.left, this->UsedScreenRect.top, &this->UsedImageRect, 1);
        this->ImageBuffer->SetTrans(0, 1);
        this->draw_finish();
        return;
    }

    HDC dc = (HDC)this->render_area->GetDc((char*)kTpnlTimDraw);
    if (dc != nullptr) {
        SelectClipRgn(dc, (HRGN)this->clip_rgn);
        HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);
        SetBkMode(dc, 1);

        char str[256];
        const UINT draw_flags = tpnl_tim_format_text(this, str);

        SetTextColor(dc, this->color2);
        const int x = this->pnl_x;
        const int y = this->pnl_y;
        const int right = this->pnl_wid - 2 + x + 1;
        const int bottom = this->pnl_hgt - 2 + y + 1;
        tpnl_tim_draw_text(dc, str, x, y, right, bottom, draw_flags);

        SetTextColor(dc, this->color1);
        tagRECT rect;
        SetRect(&rect, x + 1, y + 1, right - 1, bottom - 1);
        DrawTextA(dc, str, -1, &rect, draw_flags);

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc((char*)kTpnlTimDraw);
    }

    this->draw_finish();
}

void TRIBE_Panel_Time::get_true_render_rect(tagRECT* param_1) {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051E0E0
    if ((this->ImageBuffer != nullptr) && (this->render_area != nullptr) && (this->active != 0) && (this->visible != 0)) {
        *param_1 = this->UsedScreenRect;
        return;
    }

    param_1->left = this->pnl_x;
    param_1->top = this->pnl_y;
    param_1->right = this->pnl_x + this->pnl_wid - 1;
    param_1->bottom = this->pnl_y + this->pnl_hgt - 1;
}

long TRIBE_Panel_Time::handle_idle() {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051E150
    TPanel::handle_idle();

    switch (this->clock_type) {
    case 0:
        break;
    case 1: {
        const unsigned long now = debug_timeGetTime(kTpnlTimSourcePath, 0x18A);
        this->game_time = (now - this->start_real_time) / 1000;
        break;
    }
    case 2:
        this->game_time = this->world->world_time / 1000;
        break;
    case 3:
        this->game_time = (unsigned long)((long)this->world->countdown_clock);
        break;
    case 4:
        if (this->player == nullptr) {
            this->game_time = 0;
        } else {
            this->game_time = (unsigned long)rge_base_game->countdown_timer[(int)this->player->id];
        }
        break;
    case 5:
        if (this->player == nullptr || this->player->artifact_held_time == -1.0f) {
            this->game_time = 0;
        } else {
            this->game_time = (unsigned long)((long)this->player->artifact_held_time);
        }
        break;
    case 6:
        if (this->player == nullptr || this->player->ruin_held_time == -1.0f) {
            this->game_time = 0;
        } else {
            this->game_time = (unsigned long)((long)this->player->ruin_held_time);
        }
        break;
    default:
        break;
    }

    if (this->game_time != this->last_game_time) {
        this->set_redraw(TPanel::Redraw);
        this->parent_panel->set_redraw(TPanel::Redraw);
        this->last_game_time = this->game_time;
    }

    return 0;
}

int TRIBE_Panel_Time::render_to_image_buffer() {
    // Fully verified. Source of truth: tpnl_tim.cpp.decomp @ 0x0051E2B0
    if (this->ImageBuffer == nullptr) {
        return 0;
    }

    this->ImageBuffer->PtrClear(&this->ImageRect, 1);
    HDC dc = (HDC)this->ImageBuffer->GetDc((char*)kTpnlTimRender);
    if (dc == nullptr) {
        return 0;
    }

    this->ImageBuffer->SetClipRect(&this->ImageRect);
    SelectClipRgn(dc, (HRGN)this->image_clip_region);
    HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);
    SetBkMode(dc, 1);

    char str[256];
    const UINT draw_flags = tpnl_tim_format_text(this, str);

    SetTextColor(dc, this->color2);
    const int x = this->ImageRect.left;
    const int y = this->ImageRect.top;
    const int right = this->pnl_wid - 1;
    const int bottom = this->pnl_hgt - 1;
    tpnl_tim_draw_text(dc, str, x, y, right, bottom, draw_flags);

    SetTextColor(dc, this->color1);
    tagRECT rect;
    SetRect(&rect, x + 1, y + 1, right - 1, bottom - 1);
    DrawTextA(dc, str, -1, &rect, draw_flags);

    SelectObject(dc, old_font);
    SelectClipRgn(dc, 0);
    this->ImageBuffer->ReleaseDc((char*)kTpnlTimRender);

    const int screen_x = this->pnl_x;
    const int screen_y = this->pnl_y;
    const int used_w = this->pnl_wid - 1;
    const int used_h = this->pnl_hgt - 1;

    this->UsedImageRect.left = 0;
    this->UsedImageRect.top = 0;
    this->UsedImageRect.right = used_w;
    this->UsedImageRect.bottom = used_h;

    this->UsedScreenRect.left = screen_x;
    this->UsedScreenRect.top = screen_y;
    this->UsedScreenRect.right = screen_x + used_w;
    this->UsedScreenRect.bottom = screen_y + used_h;

    this->last_display_time = this->display_time;
    this->old_clock_type = this->clock_type;
    this->old_clock_format = this->clock_format;
    this->ImageTextActive = 1;
    return 1;
}
