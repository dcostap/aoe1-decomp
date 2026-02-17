#include "../include/TRIBE_Panel_Pop.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Font.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_World.h"
#include "../include/globals.h"
#include <windows.h>

TRIBE_Panel_Pop::TRIBE_Panel_Pop(TDrawArea* area, TPanel* parent) : TPanel() {
    this->font = nullptr;
    if (rge_base_game != nullptr) {
        RGE_Font* f = rge_base_game->get_font(0x0B);
        if (f != nullptr) {
            this->font = f->font;
        }
    }

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

TRIBE_Panel_Pop::~TRIBE_Panel_Pop() {
    if (this->image_clip_region != nullptr) {
        DeleteObject((HGDIOBJ)this->image_clip_region);
        this->image_clip_region = nullptr;
    }

    if (this->ImageBuffer != nullptr) {
        delete this->ImageBuffer;
        this->ImageBuffer = nullptr;
    }
}

void TRIBE_Panel_Pop::startup() {
    this->world = (TRIBE_World*)(rge_base_game != nullptr ? rge_base_game->world : nullptr);
    this->player = nullptr;
    if (this->world != nullptr && this->world->players != nullptr) {
        int curr = (int)this->world->curr_player;
        if (curr >= 0) {
            this->player = (TRIBE_Player*)this->world->players[curr];
        }
    }
    this->pop = 0;
    this->max_pop = 0;
}

int TRIBE_Panel_Pop::get_player_id() {
    if (this->player == nullptr) {
        return 0;
    }
    return (int)this->player->id;
}
