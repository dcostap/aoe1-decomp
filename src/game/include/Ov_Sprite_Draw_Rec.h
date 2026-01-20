#pragma once
#include "common.h"

struct Ov_Sprite_Draw_Rec {
    Ov_Sprite_Draw_Rec* next;
    Ov_Sprite_Draw_Rec* prev;
    TShape* theShape;
    int thefacet;
    int world_x;
    int world_y;
    int flags;
    int drawLevel;
    int displayfunction;
    ulong LastDrawTime;
    ulong DrawTimeInterval;
    uchar* colortable;
};
static_assert(sizeof(Ov_Sprite_Draw_Rec) == 0x30, "Size mismatch");
