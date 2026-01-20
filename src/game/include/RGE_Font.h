#pragma once
#include "common.h"

struct RGE_Font {
    void* font;
    long font_wid;
    long font_hgt;
};
static_assert(sizeof(RGE_Font) == 0xC, "Size mismatch");
