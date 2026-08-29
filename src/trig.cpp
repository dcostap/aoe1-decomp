
#include "../include/trig.h"

#include <math.h>

TRIGONOMETRY::TRIGONOMETRY()
{
    int i;

    // Phase 1: 4096-entry table (0 to 2*PI in 4096 steps)
    for (i = 0; i < 0x1000; i++) {
        double rad = (double)i * 0.001533980788;
        sines[i] = (float)sin(rad);
        cose[i] = (float)cos(rad);

        if (i == 0x400 || i == 0xC00)
            tane[i] = 0.0f;
        else
            tane[i] = (float)tan(rad);

        if (i == 0 || i == 0x800)
            atane[i] = 0.0f;
        else
            atane[i] = (float)atan(rad);
    }

    // Phase 2: 360-entry table (degree-based, 0 to 360 in 360 steps)
    for (i = 0; i < 0x168; i++) {
        double rad = (double)i * 0.01745329252;
        sine360[i] = (float)sin(rad);
        cose360[i] = (float)cos(rad);

        if (i == 0x5A || i == 0x10E)
            tane360[i] = 0.0f;
        else
            tane360[i] = (float)tan(rad);

        if (i == 0 || i == 0xB4)
            atane360[i] = 0.0f;
        else
            atane360[i] = (float)atan(rad);
    }
}

int TRIGONOMETRY::RestrictAngle(int param_1)
{
    int value = param_1 % 0x1000;
    return value < 0 ? -value : value;
}

int TRIGONOMETRY::RestrictAngle360(int param_1)
{
    int value = param_1 % 0x168;
    if (value < 0) {
        value = -value;
    }
    return value;
}

float TRIGONOMETRY::sine(int param_1)
{
    int index = this->RestrictAngle(param_1);
    return this->sines[index];
}

float TRIGONOMETRY::cosine(int param_1)
{
    int index = this->RestrictAngle(param_1);
    return this->cose[index];
}

float TRIGONOMETRY::tangent(int param_1)
{
    int index = this->RestrictAngle(param_1);
    return this->tane[index];
}

float TRIGONOMETRY::atangent(int param_1)
{
    int index = this->RestrictAngle(param_1);
    return this->atane[index];
}

float TRIGONOMETRY::sin360(int param_1)
{
    int index = this->RestrictAngle360(param_1);
    return this->sine360[index];
}

float TRIGONOMETRY::cos360(int param_1)
{
    int index = this->RestrictAngle360(param_1);
    return this->cose360[index];
}

float TRIGONOMETRY::tan360(int param_1)
{
    int index = this->RestrictAngle360(param_1);
    return this->tane360[index];
}

float TRIGONOMETRY::atan360(int param_1)
{
    int index = this->RestrictAngle360(param_1);
    return this->atane360[index];
}

TRIGONOMETRY trig;
