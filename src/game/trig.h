#pragma once
#include "../common.h"

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
    virtual int RestrictAngle(int param_1);
    virtual int RestrictAngle360(int param_1);
    virtual float sine(int param_1);
    virtual float cosine(int param_1);
    virtual float tangent(int param_1);
    virtual float atangent(int param_1);
    virtual float sin360(int param_1);
    virtual float cos360(int param_1);
    virtual float tan360(int param_1);
    virtual float atan360(int param_1);
};

static_assert(sizeof(TRIGONOMETRY) == 0x11680, "TRIGONOMETRY Size Mismatch");
static_assert(offsetof(TRIGONOMETRY, atane360) == 0x110E0, "TRIGONOMETRY Offset Mismatch");

