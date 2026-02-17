#include "../include/TRIBE_Panel_Time.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Font.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_World.h"
#include "../include/globals.h"
#include <windows.h>

TRIBE_Panel_Time::TRIBE_Panel_Time(TDrawArea* area, TPanel* parent) : TPanel() {
    this->font = nullptr;
    if (rge_base_game != nullptr) {
        RGE_Font* f = rge_base_game->get_font(0x0B);
        if (f != nullptr) {
            this->font = f->font;
        }
    }

    this->color1 = 0xFFFFFF;
    this->color2 = 0;
    this->clock_type = 0;
    this->old_clock_type = 0;
    this->clock_format = 0;
    this->old_clock_format = 0;
    this->player_id = 0;
    this->world = nullptr;
    this->player = nullptr;
    this->start_real_time = 0;
    this->game_time = 0;
    this->last_game_time = 0;
    this->display_time = 0;
    this->last_display_time = 0xFFFFFFFF;
    this->image_clip_region = nullptr;
    this->ImageBuffer = nullptr;
    ZeroMemory(&this->ImageRect, sizeof(this->ImageRect));
    ZeroMemory(&this->UsedImageRect, sizeof(this->UsedImageRect));
    ZeroMemory(&this->UsedScreenRect, sizeof(this->UsedScreenRect));
    this->ImageTextActive = 0;
    this->LastIBWidth = -1;
    this->LastIBHeight = -1;

    if (this->setup(area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
    }
}

TRIBE_Panel_Time::~TRIBE_Panel_Time() {
    if (this->image_clip_region != nullptr) {
        DeleteObject((HGDIOBJ)this->image_clip_region);
        this->image_clip_region = nullptr;
    }

    if (this->ImageBuffer != nullptr) {
        delete this->ImageBuffer;
        this->ImageBuffer = nullptr;
    }
}

void TRIBE_Panel_Time::startup() {
    this->world = (TRIBE_World*)(rge_base_game != nullptr ? rge_base_game->world : nullptr);
    this->start_real_time = GetTickCount();
}

void TRIBE_Panel_Time::set_clock_type(int clock_type_param, int player_id_param) {
    this->clock_type = clock_type_param;
    this->player_id = player_id_param;

    if (player_id_param < 1 || this->world == nullptr || this->world->players == nullptr) {
        this->player = nullptr;
        this->color1 = 0xFFFFFF;
        this->set_redraw(TPanel::Redraw);
        return;
    }

    this->player = (TRIBE_Player*)this->world->players[player_id_param];
    this->color1 = 0xFFFFFF;
    this->set_redraw(TPanel::Redraw);
}
