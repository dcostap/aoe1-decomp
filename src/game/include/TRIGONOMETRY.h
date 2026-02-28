#pragma once
#include "common.h"

class TRIGONOMETRY {
public:
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
