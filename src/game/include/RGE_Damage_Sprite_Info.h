#pragma once
#include "common.h"

struct RGE_Damage_Sprite_Info {
    RGE_Sprite* sprite;
    uchar damage_percent;
    uchar flag;
};
static_assert(sizeof(RGE_Damage_Sprite_Info) == 0x8, "Size mismatch");
