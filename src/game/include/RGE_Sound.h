#pragma once
#include "common.h"

class RGE_Sound_Info {
public:
    char name[13]; // +0x0 (Size: 0xD)
    unsigned char _pad_0[0x3]; // 0x000d (Gap: 3)
    long resource_id; // +0x10 (Size: 0x4)
    short percent; // +0x14 (Size: 0x2)
    unsigned char _pad_1[0x2]; // 0x0016 (Gap: 2)
    TDigital* digital_sound; // +0x18 (Size: 0x4)
    unsigned char loaded; // +0x1C (Size: 0x1)
    unsigned char _pad_2[0x3]; // 0x001d (Gap: 3)
    unsigned long time; // +0x20 (Size: 0x4)
};

class RGE_Sound {
public:
    short play_at_update_count; // +0x0 (Size: 0x2)
    short sound_num; // +0x2 (Size: 0x2)
    RGE_Sound_Info* sounds; // +0x4 (Size: 0x4)
    unsigned long cache_time; // +0x8 (Size: 0x4)
    short id; // +0xC (Size: 0x2)
    unsigned char _pad_end[0x2]; // 0x000e (Gap: 2)
};
static_assert(sizeof(RGE_Sound) == 0x10, "Size mismatch");
static_assert(sizeof(RGE_Sound_Info) == 0x24, "Size mismatch");
