#include "../include/tpnl_pop.h"

TRIBE_Panel_Pop::TRIBE_Panel_Pop(TDrawArea* area, TPanel* parent) {
    RGE_Font* f;

    this->handle_mouse_input = 0;
    f = rge_base_game->get_font(0xB);
    this->font = f->font_data;
    this->color1 = 0xFFFFFF;
    this->color2 = 0;
    this->color3 = 0xFFFF;
    this->player_id = 0;
    this->world = 0;
    this->player = 0;
    this->pop = 0;
    this->max_pop = 0;
    this->mode = 0;
    this->timer = 0.0f;
    this->ImageBuffer = 0;
    this->LastIBWidth = -1;
    this->LastIBHeight = -1;
    this->ImageTextActive = 0;
    this->image_clip_region = 0;
    if (TPanel::setup(area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
    }
}

TRIBE_Panel_Pop::~TRIBE_Panel_Pop() {
    TDrawArea* buf;

    if (this->image_clip_region != 0) {
        DeleteObject(this->image_clip_region);
        this->image_clip_region = 0;
    }
    buf = this->ImageBuffer;
    if (buf != 0) {
        buf->~TDrawArea();
        operator_delete(buf);
        this->ImageBuffer = 0;
    }
}

void TRIBE_Panel_Pop::set_rect(long param_1, long param_2, long param_3,
                               long param_4) {
    TPanel::set_rect(param_1, param_2, param_3, param_4);

    if (this->pnl_wid > this->LastIBWidth) goto need_realloc;
    if (this->pnl_hgt > this->LastIBHeight) goto need_realloc;
    if (param_1 + this->LastIBWidth >= this->render_area->width) goto need_realloc;
    goto skip_realloc;

need_realloc:
    {
        if (this->image_clip_region != 0) {
            DeleteObject(this->image_clip_region);
            this->image_clip_region = 0;
        }

        TDrawArea* buf = this->ImageBuffer;
        if (buf != 0) {
            buf->~TDrawArea();
            operator_delete(buf);
            this->ImageBuffer = 0;
        }

        buf = new TDrawArea("time message panel", 0);
        this->ImageBuffer = buf;
        buf->Init(this->render_area->draw_sys, this->pnl_wid, this->pnl_hgt, 0,
                  0);

        this->LastIBWidth = this->pnl_wid;
        this->LastIBHeight = this->pnl_hgt;

        this->ImageRect.left = 0;
        this->ImageRect.top = 0;
        this->ImageRect.right = this->pnl_wid - 1;
        this->ImageRect.bottom = this->pnl_hgt - 1;

        this->image_clip_region = CreateRectRgn(0, 0, this->pnl_wid - 1,
                                                this->pnl_hgt - 1);
    }

skip_realloc:
    if (this->ImageBuffer != 0) {
        this->UsedImageRect = this->ImageRect;
    } else {
        this->LastIBWidth = -1;
        this->LastIBHeight = -1;
    }

    this->need_restore = 1;
    this->set_redraw(1);
}

void TRIBE_Panel_Pop::startup() {
    this->world = rge_base_game->world;
    RGE_Player* p = (RGE_Player*)rge_base_game->get_player();
    this->player = p;

    this->pop = (int)(p->attributes[0x2C / 4]);
    this->max_pop = this->pop + (int)(p->attributes[0x10 / 4]);
    int limit = (int)(p->attributes[0x80 / 4]);
    if (this->max_pop > limit) {
        this->max_pop = limit;
    }
}

int TRIBE_Panel_Pop::get_player_id() {
    if (this->member_10C) {
        return this->member_10C->field_4A;
    }
    return 0;
}

void TRIBE_Panel_Pop::draw() {
    char str[256];
    HGDIOBJ old_font;
    RECT rect;
    unsigned char changed_mode;

    if (this->render_area == 0)
        return;
    if (this->visible == 0)
        return;
    if (this->active == 0)
        return;

    this->display_changed_count++;
    this->draw_setup(0);

    RGE_Player* player = rge_base_game->get_player();
    this->player = player;
    changed_mode = 0;

    if (this->mode == 0) {
        if (rge_base_game->need_counts[player->player_id] > 0) {
            this->mode = 1;
            this->timer = 0.0f;
            changed_mode = 1;
        }
    }

    if (this->mode > 0) {
        this->timer += player->world->world_time_delta_seconds;
        if (this->timer > 1.0f) {
            changed_mode = 1;
            this->timer = 0.0f;
            if (++this->mode > 2)
                this->mode = 0;
        }
    }

    {
        int pop = (int)player->attributes[0x2C / 4];
        int max_pop = pop + (int)player->attributes[0x10 / 4];
        int max_available = (int)player->attributes[0x80 / 4];
        if (max_pop > max_available)
            max_pop = max_available;

        if (this->ImageBuffer != 0 &&
            (changed_mode != 0 || this->need_restore != 0 ||
             this->pop != pop || this->max_pop != max_pop)) {
            this->pop = pop;
            this->max_pop = max_pop;
            this->render_to_image_buffer();
            if (this->need_restore != 0) {
                this->need_restore = 0;
                goto finish;
            }
        }
    }

    if (this->ImageTextActive != 0 && this->ImageBuffer != 0) {
        this->ImageBuffer->SetTrans(1, 1);
        this->ImageBuffer->Copy(this->render_area,
                                this->UsedScreenRect.left,
                                this->UsedScreenRect.top,
                                &this->UsedImageRect, 1);
        this->ImageBuffer->SetTrans(0, 1);
        goto finish;
    }

    if (this->render_area->GetDc((char*)"tpnl_tim::draw") != 0) {
        SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
        old_font = SelectObject(this->render_area->DrawDc, (HGDIOBJ)this->font);
        SetBkMode(this->render_area->DrawDc, 1);
        sprintf(str, "%s%ld/%ld", this->get_string(0x2B2A),
                this->pop, this->max_pop);

        SetTextColor(this->render_area->DrawDc, this->color2);

        long left = this->render_rect.left;
        long top = this->render_rect.top;
        long height = this->pnl_hgt;
        long width = this->pnl_wid;
        ++left;
        ++top;
        width -= 2;
        height -= 2;
        SetRect(&rect, left - 1, top - 1, width + left - 2, height + top - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);
        SetRect(&rect, left - 1, top + 1, width + left - 2, height + top);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);
        SetRect(&rect, left + 1, top - 1, width + left, height + top - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);
        SetRect(&rect, left + 1, top + 1, width + left, height + top);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);

        if (this->mode == 1) {
            // The shipped code changes the image buffer DC, then draws on the
            // render-area DC. Keep this receiver mismatch.
            SetTextColor(this->ImageBuffer->DrawDc, this->color3);
        } else {
            SetTextColor(this->render_area->DrawDc, this->color1);
        }

        SetRect(&rect, left, top, width + left - 1, height + top - 1);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);

        SelectObject(this->render_area->DrawDc, old_font);
        SelectClipRgn(this->render_area->DrawDc, 0);
        this->render_area->ReleaseDc((char*)"tpnl_tim::draw");
    }

finish:
    this->draw_finish();
}

void TRIBE_Panel_Pop::get_true_render_rect(RECT& rect) {
    if (this->ImageBuffer && this->render_area && this->visible &&
        this->active) {
        rect = this->UsedScreenRect;
    } else {
        rect = this->render_rect;
    }
}

long TRIBE_Panel_Pop::handle_idle() {
    TPanel::handle_idle();
    return 0;
}

static char tag[] = "tpnl_tim::render_to_image_buffer";

int TRIBE_Panel_Pop::render_to_image_buffer() {
    RECT rect;
    void* old_font;
    char str[256];

    if (this->ImageBuffer == 0) return 0;
    this->ImageBuffer->PtrClear(&this->ImageRect, 1);
    if (this->ImageBuffer->GetDc(tag) == 0) return 0;
    this->ImageBuffer->SetClipRect(&this->ImageRect);
    SelectClipRgn(this->ImageBuffer->DrawDc, this->image_clip_region);
    old_font = SelectObject(this->ImageBuffer->DrawDc, this->font);
    SetBkMode(this->ImageBuffer->DrawDc, 1);
    sprintf(str + 4, "%s%ld/%ld", this->TPanel::get_string(0x2b2a),
            this->pop, this->max_pop);
    SetTextColor(this->ImageBuffer->DrawDc, this->color2);
    long width = this->pnl_wid;
    long height = this->pnl_hgt;
    SetRect(&rect, 0, 0, width - 3, height - 3);
    DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetRect(&rect, 0, 2, width - 3, height - 1);
    DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetRect(&rect, 2, 0, width - 1, height - 3);
    DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetRect(&rect, 2, 2, width - 1, height - 1);
    DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetTextColor(this->ImageBuffer->DrawDc,
                 this->mode == 1 ? this->color3 : this->color1);
    --height;
    --width;
    SetRect(&rect, 1, 1, width, height);
    DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SelectObject(this->ImageBuffer->DrawDc, old_font);
    SelectClipRgn(this->ImageBuffer->DrawDc, 0);
    this->ImageBuffer->ReleaseDc(tag);

    int right = this->pnl_wid - 1;
    int bottom = this->pnl_hgt - 1;
    this->UsedImageRect.left = 0;
    this->UsedImageRect.top = 0;
    this->UsedScreenRect.left = this->render_rect.left;
    this->UsedScreenRect.top = this->render_rect.top;
    this->UsedImageRect.right = right;
    this->UsedImageRect.bottom = bottom;
    this->UsedScreenRect.right = this->render_rect.left + right;
    this->UsedScreenRect.bottom = this->render_rect.top + bottom;
    this->ImageTextActive = 1;
    return 1;
}
