#pragma once
#include "common.h"

struct RGE_Sound_Info {
    char name[13];
    long resource_id;
    short percent;
    TDigital* digital_sound;
    uchar loaded;
    ulong time;
};
static_assert(sizeof(RGE_Sound_Info) == 0x24, "Size mismatch");
