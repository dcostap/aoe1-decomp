#include "../include/tpnl_tim.h"

char s_time_message_panel[] = "time message panel";
const char s_tpnl_tim_draw[] = "tpnl_tim::draw";
const char s_tpnl_tim_render_to_image_buffer[] =
    "tpnl_tim::render_to_image_buffer";
const char s_clock_hms_fmt[] = "%02ld:%02ld:%02ld (%3.1f)";

TRIBE_Panel_Time::TRIBE_Panel_Time(TDrawArea* draw_area, TPanel* parent)
    : TPanel()
{
    this->handle_mouse_input = 0;
    this->font = *(void**)rge_base_game->get_font(0xB);
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
    this->current_display_value = 0;
    this->last_display_value = 0;
    this->old_display_time = -1;
    this->image_buffer = 0;
    this->last_ib_width = -1;
    this->last_ib_height = -1;
    this->image_text_active = 0;
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

    image_buffer = this->image_buffer;
    if (image_buffer != 0) {
        image_buffer->~TDrawArea();
        operator delete(image_buffer);
        this->image_buffer = 0;
    }
}

void TRIBE_Panel_Time::set_rect(long x, long y, long width, long height)
{
    TDrawArea* image_buffer;

    this->TPanel::set_rect(x, y, width, height);

    if (this->pnl_wid <= this->last_ib_width) {
        if (this->pnl_hgt <= this->last_ib_height) {
            if (x + this->last_ib_width < this->render_area->width) {
                goto skip_recreate;
            }
        }
    }

    if (this->image_clip_region != 0) {
        DeleteObject(this->image_clip_region);
        this->image_clip_region = 0;
    }

    image_buffer = this->image_buffer;
    if (image_buffer != 0) {
        image_buffer->~TDrawArea();
        operator delete(image_buffer);
        this->image_buffer = 0;
    }

    image_buffer = new TDrawArea(s_time_message_panel, 0);
    this->image_buffer = image_buffer;
    image_buffer->Init(*(TDrawSystem**)this->render_area, this->pnl_wid,
                       this->pnl_hgt, 0, 0);

    this->last_ib_width = this->pnl_wid;
    this->last_ib_height = this->pnl_hgt;
    this->image_rect.left = 0;
    this->image_rect.top = 0;
    this->image_rect.right = this->pnl_wid - 1;
    this->image_rect.bottom = this->pnl_hgt - 1;
    this->image_clip_region = CreateRectRgn(
        0, 0, this->pnl_wid - 1, this->pnl_hgt - 1);

skip_recreate:
    if (this->image_buffer != 0) {
        this->used_image_rect = this->image_rect;
    } else {
        this->last_ib_width = -1;
        this->last_ib_height = -1;
    }

    this->need_restore = 1;
    this->set_redraw(1);
}

void TRIBE_Panel_Time::startup()
{
    this->world = rge_base_game->world;
    this->start_real_time = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tpnl_tim.cpp", 0x92);
}

void TRIBE_Panel_Time::set_clock_type(int clock_type, int player_id)
{
    if (this->clock_type == clock_type) {
        if (this->player == 0) {
            return;
        }
        if (this->player->player_id == player_id) {
            return;
        }
    }

    this->clock_type = clock_type;

    if (player_id > 0) {
        this->player = this->world->players[player_id];
    } else {
        this->player = 0;
    }

    if (this->player != 0) {
        switch (this->player->civ_info->civ_id) {
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
    this->set_redraw(1);
    this->parent_panel->set_redraw(1);
    this->handle_idle();
}

int TRIBE_Panel_Time::get_clock_type()
{
    return this->clock_type;
}

int TRIBE_Panel_Time::get_player_id()
{
    if (this->player != 0) {
        return this->player->player_id;
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
        this->display_time = this->current_display_value;
    } else {
        this->display_time = ((this->current_display_value + 4) / 5) * 5;
    }

    if (this->image_buffer != 0) {
        if (this->display_time != (unsigned int)this->old_display_time ||
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

    if (this->image_text_active != 0 && this->image_buffer != 0) {
        this->image_buffer->SetTrans(1, 1);
        this->image_buffer->Copy(this->render_area,
                                 this->used_screen_rect.left,
                                 this->used_screen_rect.top,
                                 &this->used_image_rect, 1);
        this->image_buffer->SetTrans(0, 1);
        goto finish;
    }

    old_font = this->render_area->GetDc((char*)s_tpnl_tim_draw);
    if (old_font == 0) {
        goto finish;
    }

    SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
    old_font = SelectObject(this->render_area->DrawDc, this->font);
    SetBkMode(this->render_area->DrawDc, 1);

    if (this->clock_format == 1) {
        int seconds = this->current_display_value;
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
            sprintf(str, s_clock_hms_fmt, hours, minutes, seconds,
                    game_speed);
        }
        text_flags = 0x20;
    } else {
        int rounded_time = ((this->current_display_value + 4) / 5) * 5;
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
    this->render_area->ReleaseDc((char*)s_tpnl_tim_draw);
finish:
    this->draw_finish();
}

void TRIBE_Panel_Time::get_true_render_rect(tagRECT& rect)
{
    if (this->image_buffer != 0 && this->render_area != 0 &&
        this->visible != 0 && this->active != 0) {
        rect = this->used_screen_rect;
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
        this->current_display_value =
            (debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_tim.cpp",
                               0x18A) - this->start_real_time) / 1000;
        break;
    case 2:
        this->current_display_value = this->world->world_time / 1000;
        break;
    case 3:
        this->current_display_value = (int)this->world->field_118;
        break;
    case 4:
        if (this->player != 0) {
            long countdown_timer;
            rge_base_game->get_countdown_timer(
                this->player->player_id, &countdown_timer);
            this->current_display_value = countdown_timer;
            break;
        }
        this->current_display_value = 0;
        break;
    case 5:
        if (this->player != 0 && this->player->artifact_held_time != -1.0f) {
            this->current_display_value = (int)this->player->artifact_held_time;
            break;
        }
        this->current_display_value = 0;
        break;
    case 6:
        if (this->player != 0 && this->player->ruin_held_time != -1.0f) {
            this->current_display_value = (int)this->player->ruin_held_time;
            break;
        }
        this->current_display_value = 0;
        break;
    }

    if (this->current_display_value != this->last_display_value) {
        this->set_redraw(1);
        this->parent_panel->set_redraw(1);
        this->last_display_value = this->current_display_value;
    }

    return 0;
}

int TRIBE_Panel_Time::render_to_image_buffer()
{
    void* old_font;
    char str[256];
    tagRECT rect;
    long width;
    long height;
    int text_flags;

    if (this->image_buffer == 0) {
        return 0;
    }

    this->image_buffer->PtrClear(&this->image_rect, 1);
    old_font = this->image_buffer->GetDc(
        (char*)s_tpnl_tim_render_to_image_buffer);
    if (old_font == 0) {
        return 0;
    }

    this->image_buffer->SetClipRect(&this->image_rect);
    SelectClipRgn(this->image_buffer->DrawDc, this->image_clip_region);
    old_font = SelectObject(this->image_buffer->DrawDc, this->font);
    SetBkMode(this->image_buffer->DrawDc, 1);

    if (this->clock_format == 1) {
        int seconds = this->current_display_value;
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
        sprintf(str, s_clock_hms_fmt, hours, minutes, seconds,
                rge_base_game->world->game_speed);
        text_flags = 0x20;
    } else {
        int rounded_time = ((this->current_display_value + 4) / 5) * 5;
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

    SetTextColor(this->image_buffer->DrawDc, this->color2);

    width = this->pnl_wid - 1;
    height = this->pnl_hgt - 1;

    SetRect(&rect, 0, 0, width - 2, height - 2);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);
    SetRect(&rect, 0, 2, width - 2, height);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);
    SetRect(&rect, 2, 0, width, height - 2);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);
    SetRect(&rect, 2, 2, width, height);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);

    SetTextColor(this->image_buffer->DrawDc, this->color1);
    --width;
    --height;
    SetRect(&rect, 1, 1, width, height);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);

    SelectObject(this->image_buffer->DrawDc, old_font);
    SelectClipRgn(this->image_buffer->DrawDc, 0);
    this->image_buffer->ReleaseDc(
        (char*)s_tpnl_tim_render_to_image_buffer);

    this->used_image_rect.left = 0;
    this->used_image_rect.top = 0;
    this->used_screen_rect.left = this->render_rect.left;
    this->used_screen_rect.top = this->render_rect.top;
    this->used_image_rect.right = this->pnl_wid - 1;
    this->used_image_rect.bottom = this->pnl_hgt - 1;
    this->used_screen_rect.right =
        this->render_rect.left + this->pnl_wid - 1;
    this->used_screen_rect.bottom =
        this->render_rect.top + this->pnl_hgt - 1;
    this->old_display_time = this->display_time;
    this->old_clock_type = this->clock_type;
    this->old_clock_format = this->clock_format;
    this->image_text_active = 1;

    return 1;
}
