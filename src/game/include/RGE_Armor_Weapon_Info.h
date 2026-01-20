#pragma once
#include "common.h"

struct RGE_Armor_Weapon_Info {
    short type;
    short value;
};
static_assert(sizeof(RGE_Armor_Weapon_Info) == 0x4, "Size mismatch");
