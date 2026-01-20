#pragma once
#include "common.h"

struct RGE_Sound {
    short play_at_update_count;
    short sound_num;
    RGE_Sound_Info* sounds;
    ulong cache_time;
    short id;
};
static_assert(sizeof(RGE_Sound) == 0x10, "Size mismatch");
