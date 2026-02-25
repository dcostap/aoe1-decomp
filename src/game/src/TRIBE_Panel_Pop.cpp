#include "../include/TRIBE_Panel_Pop.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Font.h"
#include "../include/TDrawArea.h"
#include "../include/TRIBE_Game.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_World.h"
#include "../include/globals.h"

#include <cstdio>
#include <windows.h>

namespace {
const char* const kTpnlPopDraw = "tpnl_tim::draw";
const char* const kTpnlPopRender = "tpnl_tim::render_to_image_buffer";

static int tpnl_pop_ftol(float value) {
    return (int)((long)value);
}

static void tpnl_pop_get_values(TRIBE_Player* player, int* out_pop, int* out_max_pop) {
    const float* attributes = player->attributes;
    const int pop_value = tpnl_pop_ftol(attributes[11]);
    int max_pop_value = pop_value + tpnl_pop_ftol(attributes[4]);
    const int pop_cap = tpnl_pop_ftol(attributes[32]);
    if (pop_cap < max_pop_value) {
        max_pop_value = pop_cap;
    }

    *out_pop = pop_value;
    *out_max_pop = max_pop_value;
}

static void tpnl_pop_draw_text(HDC dc, const char* str, int x, int y, int right, int bottom) {
    tagRECT rect;
    SetRect(&rect, x, y, right - 2, bottom - 2);
    DrawTextA(dc, str, -1, &rect, 0x21);
    SetRect(&rect, x, y + 2, right - 2, bottom);
    DrawTextA(dc, str, -1, &rect, 0x21);
    SetRect(&rect, x + 2, y, right, bottom - 2);
    DrawTextA(dc, str, -1, &rect, 0x21);
    SetRect(&rect, x + 2, y + 2, right, bottom);
    DrawTextA(dc, str, -1, &rect, 0x21);
}
}

TRIBE_Panel_Pop::TRIBE_Panel_Pop(TDrawArea* area, TPanel* parent) : TPanel() {
    // Fully verified. Source of truth: tpnl_pop.cpp.decomp @ 0x0051CCA0
    RGE_Font* panel_font = rge_base_game->get_font(0x0B);
    this->font = panel_font->font;
    this->color1 = 0xFFFFFF;
    this->color2 = 0;
    this->color3 = 0x00FFFF;
    this->player_id = 0;
    this->world = nullptr;
    this->player = nullptr;
    this->pop = 0;
    this->max_pop = 0;
    this->mode = 0;
    this->timer = 0.0f;
    this->ImageBuffer = nullptr;
    this->LastIBWidth = -1;
    this->LastIBHeight = -1;
    this->ImageTextActive = 0;
    this->image_clip_region = nullptr;

    if (this->setup(area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
    }
}

TRIBE_Panel_Pop::~TRIBE_Panel_Pop() {
    // Fully verified. Source of truth: tpnl_pop.cpp.decomp @ 0x0051CDB0
    if (this->image_clip_region != nullptr) {
        DeleteObject((HGDIOBJ)this->image_clip_region);
        this->image_clip_region = nullptr;
    }

    if (this->ImageBuffer != nullptr) {
        delete this->ImageBuffer;
        this->ImageBuffer = nullptr;
    }
}

void TRIBE_Panel_Pop::set_rect(long param_1, long param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: tpnl_pop.cpp.decomp @ 0x0051CE40
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

void TRIBE_Panel_Pop::startup() {
    // Fully verified. Source of truth: tpnl_pop.cpp.decomp @ 0x0051CFD0
    this->world = (TRIBE_World*)rge_base_game->world;
    this->player = (TRIBE_Player*)rge_base_game->get_player();
    tpnl_pop_get_values(this->player, &this->pop, &this->max_pop);
}

int TRIBE_Panel_Pop::get_player_id() {
    // Fully verified. Source of truth: tpnl_pop.cpp.decomp @ 0x0051D040
    if (this->player != nullptr) {
        return (int)this->player->id;
    }
    return 0;
}

void TRIBE_Panel_Pop::draw() {
    // Fully verified. Source of truth: tpnl_pop.cpp.decomp @ 0x0051D060
    if (this->render_area == nullptr || this->active == 0 || this->visible == 0) {
        return;
    }

    this->draw_setup(0);
    this->player = (TRIBE_Player*)rge_base_game->get_player();

    bool changed_mode = false;
    if (this->mode == 0 && ((TRIBE_Game*)rge_base_game)->queue_is_waiting_on_pop_counter[(int)this->player->id] > 0) {
        this->mode = 1;
        this->timer = 0.0f;
        changed_mode = true;
    }

    if (this->mode != 0) {
        this->timer = this->player->world->world_time_delta_seconds + this->timer;
        if (this->timer > 1.0f) {
            changed_mode = true;
            this->mode = (unsigned char)(this->mode + 1);
            this->timer = 0.0f;
            if (this->mode > 2) {
                this->mode = 0;
            }
        }
    }

    int pop_value = 0;
    int max_pop_value = 0;
    tpnl_pop_get_values(this->player, &pop_value, &max_pop_value);

    if ((this->ImageBuffer != nullptr) &&
        (changed_mode || this->need_restore != 0 || this->pop != pop_value || this->max_pop != max_pop_value)) {
        this->pop = pop_value;
        this->max_pop = max_pop_value;
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

    HDC dc = (HDC)this->render_area->GetDc((char*)kTpnlPopDraw);
    if (dc != nullptr) {
        SelectClipRgn(dc, (HRGN)this->clip_rgn);
        HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);
        SetBkMode(dc, 1);

        char str[256];
        sprintf(str, "%s%ld/%ld", this->get_string(0x2B2A), (long)this->pop, (long)this->max_pop);

        SetTextColor(dc, this->color2);
        const int x = this->pnl_x;
        const int y = this->pnl_y;
        const int right = this->pnl_wid - 2 + x + 1;
        const int bottom = this->pnl_hgt - 2 + y + 1;
        tpnl_pop_draw_text(dc, str, x, y, right, bottom);

        TDrawArea* color_target = (this->mode == 1) ? this->ImageBuffer : this->render_area;
        SetTextColor((HDC)color_target->DrawDc, (this->mode == 1) ? this->color3 : this->color1);
        tagRECT rect;
        SetRect(&rect, x + 1, y + 1, right - 1, bottom - 1);
        DrawTextA(dc, str, -1, &rect, 0x21);

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc((char*)kTpnlPopDraw);
    }

    this->draw_finish();
}

void TRIBE_Panel_Pop::get_true_render_rect(tagRECT* param_1) {
    // Fully verified. Source of truth: tpnl_pop.cpp.decomp @ 0x0051D470
    if ((this->ImageBuffer != nullptr) && (this->render_area != nullptr) && (this->active != 0) && (this->visible != 0)) {
        *param_1 = this->UsedScreenRect;
        return;
    }

    param_1->left = this->pnl_x;
    param_1->top = this->pnl_y;
    param_1->right = this->pnl_x + this->pnl_wid - 1;
    param_1->bottom = this->pnl_y + this->pnl_hgt - 1;
}

long TRIBE_Panel_Pop::handle_idle() {
    // Fully verified. Source of truth: tpnl_pop.cpp.decomp @ 0x0051D4E0
    TPanel::handle_idle();
    return 0;
}

int TRIBE_Panel_Pop::render_to_image_buffer() {
    // Fully verified. Source of truth: tpnl_pop.cpp.decomp @ 0x0051D4F0
    if (this->ImageBuffer == nullptr) {
        return 0;
    }

    this->ImageBuffer->PtrClear(&this->ImageRect, 1);
    HDC dc = (HDC)this->ImageBuffer->GetDc((char*)kTpnlPopRender);
    if (dc == nullptr) {
        return 0;
    }

    this->ImageBuffer->SetClipRect(&this->ImageRect);
    SelectClipRgn(dc, (HRGN)this->image_clip_region);
    HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);
    SetBkMode(dc, 1);

    char str[256];
    sprintf(str, "%s%ld/%ld", this->get_string(0x2B2A), (long)this->pop, (long)this->max_pop);

    SetTextColor(dc, this->color2);
    const int x = this->ImageRect.left;
    const int y = this->ImageRect.top;
    const int right = this->pnl_wid - 1;
    const int bottom = this->pnl_hgt - 1;
    tpnl_pop_draw_text(dc, str, x, y, right, bottom);

    SetTextColor(dc, (this->mode == 1) ? this->color3 : this->color1);
    tagRECT rect;
    SetRect(&rect, x + 1, y + 1, right - 1, bottom - 1);
    DrawTextA(dc, str, -1, &rect, 0x21);

    SelectObject(dc, old_font);
    SelectClipRgn(dc, 0);
    this->ImageBuffer->ReleaseDc((char*)kTpnlPopRender);

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

    this->ImageTextActive = 1;
    return 1;
}
