#pragma once
#include "common.h"

class TRIGONOMETRY {
public:
    float sines[4096];                       // 0x0
    float cose[4096];                        // 0x4000
    float tane[4096];                        // 0x8000
    float atane[4096];                       // 0xC000
    float sine360[360];                      // 0x10000
    float cose360[360];                      // 0x105A0
    float tane360[360];                      // 0x10B40
    float atane360[360];                     // 0x110E0

    TRIGONOMETRY();
    int RestrictAngle(int param_1);
    int RestrictAngle360(int param_1);
    float sine(int param_1);
    float cosine(int param_1);
    float tangent(int param_1);
    float atangent(int param_1);
    float sin360(int param_1);
    float cos360(int param_1);
    float tan360(int param_1);
    float atan360(int param_1);
};

static_assert(sizeof(TRIGONOMETRY) == 0x11680, "TRIGONOMETRY Size Mismatch");

