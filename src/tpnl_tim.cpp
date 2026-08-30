#include "../include/tpnl_tim.h"
#include "../include/color.h"
#include "../include/tplayer.h"
#include "../include/tworld.h"

TRIBE_Panel_Time::TRIBE_Panel_Time(TDrawArea* draw_area, TPanel* parent)
    : TPanel()
{
    this->handle_mouse_input = 0;
    this->font = rge_base_game->get_font(0xB)->font;
    this->color1 = 0xFFFFFF;
    this->color2 = 0;
    this->clock_type = 0;
    this->clock_format = 0;
    this->old_clock_type = 0;
    this->old_clock_format = 0;
    this->player_id = 0;
    this->world = 0;
    this->player = 0;
    this->start_real_time = 0;
    this->game_time = 0;
    this->last_game_time = 0;
    this->last_display_time = -1;
    this->ImageBuffer = 0;
    this->LastIBWidth = -1;
    this->LastIBHeight = -1;
    this->ImageTextActive = 0;
    this->image_clip_region = 0;
    if (!this->setup(draw_area, parent, 0, 0, 0, 0, 0)) {
        this->error_code = 1;
    }
}

TRIBE_Panel_Time::~TRIBE_Panel_Time()
{
    TDrawArea* image_buffer;

    if (this->image_clip_region != 0) {
        DeleteObject(this->image_clip_region);
        this->image_clip_region = 0;
    }

    image_buffer = this->ImageBuffer;
    if (image_buffer != 0) {
        delete image_buffer;
        this->ImageBuffer = 0;
    }
}

void TRIBE_Panel_Time::set_rect(long x, long y, long width, long height)
{
    TDrawArea* image_buffer;

    this->TPanel::set_rect(x, y, width, height);

    if (this->pnl_wid <= this->LastIBWidth) {
        if (this->pnl_hgt <= this->LastIBHeight) {
            if (x + this->LastIBWidth < this->render_area->Width) {
                goto skip_recreate;
            }
        }
    }

    if (this->image_clip_region != 0) {
        DeleteObject(this->image_clip_region);
        this->image_clip_region = 0;
    }

    image_buffer = this->ImageBuffer;
    if (image_buffer != 0) {
        delete image_buffer;
        this->ImageBuffer = 0;
    }

    image_buffer = new TDrawArea("time message panel", 0);
    this->ImageBuffer = image_buffer;
    image_buffer->Init(this->render_area->DrawSystem, this->pnl_wid,
                       this->pnl_hgt, 0, 0);

    this->LastIBWidth = this->pnl_wid;
    this->LastIBHeight = this->pnl_hgt;
    this->ImageRect.left = 0;
    this->ImageRect.top = 0;
    this->ImageRect.right = this->pnl_wid - 1;
    this->ImageRect.bottom = this->pnl_hgt - 1;
    this->image_clip_region = CreateRectRgn(
        0, 0, this->pnl_wid - 1, this->pnl_hgt - 1);

skip_recreate:
    if (this->ImageBuffer != 0) {
        this->UsedImageRect = this->ImageRect;
    } else {
        this->LastIBWidth = -1;
        this->LastIBHeight = -1;
    }

    this->need_restore = 1;
    this->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Panel_Time::startup()
{
    this->world = static_cast<TRIBE_World*>(rge_base_game->world);
    this->start_real_time = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tpnl_tim.cpp", 0x92);
}

void TRIBE_Panel_Time::set_clock_type(int clock_type, int player_id)
{
    if (this->clock_type == clock_type) {
        if (this->player == 0) {
            return;
        }
        if (this->player->id == player_id) {
            return;
        }
    }

    this->clock_type = clock_type;

    if (player_id > 0) {
        this->player = static_cast<TRIBE_Player*>(
            this->world->players[player_id]);
    } else {
        this->player = 0;
    }

    if (this->player != 0) {
        switch (this->player->color_table->id) {
        case 0:
            this->color1 = 0x00FF0000;
            this->color2 = 0x00B3B3B3;
            break;
        case 1:
            this->color1 = 0x002139C6;
            this->color2 = 0;
            break;
        case 2:
            this->color1 = 0x0000FFFF;
            this->color2 = 0;
            break;
        case 3:
            this->color1 = 0x004F73A3;
            this->color2 = 0;
            break;
        case 4:
            this->color1 = 0x000F77F3;
            this->color2 = 0;
            break;
        case 5:
            this->color1 = 0x0000C700;
            this->color2 = 0;
            break;
        case 6:
            this->color1 = 0x007B90A2;
            this->color2 = 0;
            break;
        case 7:
            this->color1 = 0x00ADAD00;
            this->color2 = 0;
            break;
        default:
            this->color1 = 0x00FFFFFF;
            this->color2 = 0;
            break;
        }
    } else {
        this->color1 = 0x00FFFFFF;
        this->color2 = 0;
    }

    if (clock_type == 1 || clock_type == 2) {
        this->clock_format = 1;
    } else {
        this->clock_format = 2;
    }

    if (clock_type == 0) {
        this->set_active(0);
    } else {
        this->set_active(1);
    }
    this->set_redraw(TPanel::RedrawNormal);
    this->parent_panel->set_redraw(TPanel::RedrawNormal);
    this->handle_idle();
}

int TRIBE_Panel_Time::get_clock_type()
{
    return this->clock_type;
}

int TRIBE_Panel_Time::get_player_id()
{
    if (this->player != 0) {
        return this->player->id;
    }
    return 0;
}

void TRIBE_Panel_Time::draw()
{
    void* old_font;
    char str[256];
    tagRECT rect;
    int text_flags;

    if (this->render_area == 0) return;
    if (this->visible == 0) return;
    if (this->active == 0) return;

    this->display_changed_count++;
    this->draw_setup(0);

    if (this->clock_format == 1) {
        this->display_time = this->game_time;
    } else {
        this->display_time = ((this->game_time + 4) / 5) * 5;
    }

    if (this->ImageBuffer != 0) {
        if (this->display_time != this->last_display_time ||
            this->clock_type != this->old_clock_type ||
            this->clock_format != this->old_clock_format ||
            this->need_restore) {
            this->render_to_image_buffer();
            if (this->need_restore) {
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

    old_font = this->render_area->GetDc("tpnl_tim::draw");
    if (old_font == 0) {
        goto finish;
    }

    SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
    old_font = SelectObject(this->render_area->DrawDc, this->font);
    SetBkMode(this->render_area->DrawDc, 1);

    if (this->clock_format == 1) {
        int seconds = this->game_time;
        int minutes = 0;
        int hours = 0;
        if (seconds > 0x3B) {
            minutes = seconds / 0x3C;
            seconds = seconds - minutes * 0x3C;
            if (minutes > 0x3B) {
                hours = minutes / 0x3C;
                minutes = minutes - hours * 0x3C;
            }
        }
        {
            float game_speed = rge_base_game->world->game_speed;
            sprintf(str, "%02ld:%02ld:%02ld (%3.1f)", hours, minutes, seconds,
                    game_speed);
        }
        text_flags = 0x20;
    } else {
        int rounded_time = ((this->game_time + 4) / 5) * 5;
        switch (this->clock_type) {
        case 4:
            sprintf(str, this->get_string(0x2C25), rounded_time);
            break;
        case 5:
            sprintf(str, this->get_string(0x2C26), rounded_time);
            break;
        case 6:
            sprintf(str, this->get_string(0x2C27), rounded_time);
            break;
        default:
            sprintf(str, this->get_string(0x2C24), rounded_time);
            break;
        }
        text_flags = 0x22;
    }

    SetTextColor(this->render_area->DrawDc, this->color2);

    {
        int left = this->render_rect.left;
        int top = this->render_rect.top;
        long height = this->pnl_hgt;
        long width = this->pnl_wid;
        ++left;
        ++top;
        width -= 2;
        height -= 2;

        SetRect(&rect, left - 1, top - 1, width + left - 2,
                height + top - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, left - 1, top + 1, width + left - 2,
                height + top);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, left + 1, top - 1, width + left,
                height + top - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, left + 1, top + 1, width + left, height + top);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);

        SetTextColor(this->render_area->DrawDc, this->color1);
        SetRect(&rect, left, top, width + left - 1, height + top - 1);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
    }

    SelectObject(this->render_area->DrawDc, old_font);
    SelectClipRgn(this->render_area->DrawDc, 0);
    this->render_area->ReleaseDc("tpnl_tim::draw");
finish:
    this->draw_finish();
}

void TRIBE_Panel_Time::get_true_render_rect(tagRECT& rect)
{
    if (this->ImageBuffer != 0 && this->render_area != 0 &&
        this->visible != 0 && this->active != 0) {
        rect = this->UsedScreenRect;
        return;
    }
    rect = this->render_rect;
}

long TRIBE_Panel_Time::handle_idle()
{
    this->TPanel::handle_idle();

    switch (this->clock_type) {
    case 0:
        break;
    case 1:
        this->game_time =
            (debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_tim.cpp",
                               0x18A) - this->start_real_time) / 1000;
        break;
    case 2:
        this->game_time = this->world->world_time / 1000;
        break;
    case 3:
        this->game_time = this->world->countdown_clock;
        break;
    case 4:
        if (this->player != 0) {
            long countdown_timer;
            rge_base_game->get_countdown_timer(this->player->id,
                                               countdown_timer);
            this->game_time = countdown_timer;
            break;
        }
        this->game_time = 0;
        break;
    case 5:
        if (this->player != 0 && this->player->artifact_held_time != -1.0f) {
            this->game_time = this->player->artifact_held_time;
            break;
        }
        this->game_time = 0;
        break;
    case 6:
        if (this->player != 0 && this->player->ruin_held_time != -1.0f) {
            this->game_time = this->player->ruin_held_time;
            break;
        }
        this->game_time = 0;
        break;
    }

    if (this->game_time != this->last_game_time) {
        this->set_redraw(TPanel::RedrawNormal);
        this->parent_panel->set_redraw(TPanel::RedrawNormal);
        this->last_game_time = this->game_time;
    }

    return 0;
}

int TRIBE_Panel_Time::render_to_image_buffer()
{
    tagRECT rect;
    void* old_font;
    char str[256];
    int text_flags;

    if (this->ImageBuffer == 0) {
        return 0;
    }

    this->ImageBuffer->PtrClear(&this->ImageRect, 1);
    old_font =
        this->ImageBuffer->GetDc("tpnl_tim::render_to_image_buffer");
    if (old_font == 0) {
        return 0;
    }

    this->ImageBuffer->SetClipRect(&this->ImageRect);
    SelectClipRgn(this->ImageBuffer->DrawDc, this->image_clip_region);
    old_font = SelectObject(this->ImageBuffer->DrawDc, this->font);
    SetBkMode(this->ImageBuffer->DrawDc, 1);

    if (this->clock_format == 1) {
        int seconds = this->game_time;
        int minutes = 0;
        int hours = 0;
        if (seconds > 0x3B) {
            minutes = seconds / 0x3C;
            seconds = seconds - minutes * 0x3C;
            if (minutes > 0x3B) {
                hours = minutes / 0x3C;
                minutes = minutes - hours * 0x3C;
            }
        }
        sprintf(str, "%02ld:%02ld:%02ld (%3.1f)", hours, minutes, seconds,
                rge_base_game->world->game_speed);
        text_flags = 0x20;
    } else {
        int rounded_time = ((this->game_time + 4) / 5) * 5;
        switch (this->clock_type) {
        case 4:
            sprintf(str, this->get_string(0x2C25), rounded_time);
            break;
        case 5:
            sprintf(str, this->get_string(0x2C26), rounded_time);
            break;
        case 6:
            sprintf(str, this->get_string(0x2C27), rounded_time);
            break;
        default:
            sprintf(str, this->get_string(0x2C24), rounded_time);
            break;
        }
        text_flags = 0x22;
    }

    SetTextColor(this->ImageBuffer->DrawDc, this->color2);

    {
        const int width = this->pnl_wid - 1;
        const int height = this->pnl_hgt - 1;

        SetRect(&rect, 0, 0, width - 2, height - 2);
        DrawTextA(this->ImageBuffer->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, 0, 2, width - 2, height);
        DrawTextA(this->ImageBuffer->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, 2, 0, width, height - 2);
        DrawTextA(this->ImageBuffer->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, 2, 2, width, height);
        DrawTextA(this->ImageBuffer->DrawDc, str, -1, &rect, text_flags);

        SetTextColor(this->ImageBuffer->DrawDc, this->color1);
        SetRect(&rect, 1, 1, width - 1, height - 1);
        DrawTextA(this->ImageBuffer->DrawDc, str, -1, &rect, text_flags);
    }

    SelectObject(this->ImageBuffer->DrawDc, old_font);
    SelectClipRgn(this->ImageBuffer->DrawDc, 0);
    this->ImageBuffer->ReleaseDc("tpnl_tim::render_to_image_buffer");

    int width = this->pnl_wid;
    int screen_left = this->render_rect.left;
    int height = this->pnl_hgt;
    this->UsedImageRect.left = 0;
    this->UsedImageRect.top = 0;
    int screen_top = this->render_rect.top;
    --width;
    this->UsedScreenRect.left = screen_left;
    --height;
    screen_left += width;
    this->UsedScreenRect.top = screen_top;
    this->UsedImageRect.right = width;
    this->UsedImageRect.bottom = height;
    this->UsedScreenRect.right = screen_left;
    screen_top += height;
    this->UsedScreenRect.bottom = screen_top;
    this->last_display_time = this->display_time;
    this->old_clock_type = this->clock_type;
    this->old_clock_format = this->clock_format;
    this->ImageTextActive = 1;

    return 1;
}
