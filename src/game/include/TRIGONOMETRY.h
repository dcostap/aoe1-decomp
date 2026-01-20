#pragma once
#include "common.h"

struct TRIGONOMETRY {
    float sines[4096];
    float cose[4096];
    float tane[4096];
    float atane[4096];
    float sine360[360];
    float cose360[360];
    float tane360[360];
    float atane360[360];
};
static_assert(sizeof(TRIGONOMETRY) == 0x11680, "Size mismatch");
