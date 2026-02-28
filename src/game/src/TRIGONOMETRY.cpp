#include "../include/TRIGONOMETRY.h"
#include "../include/globals.h"

#include <math.h>

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A730
TRIGONOMETRY::TRIGONOMETRY() {
    for (int i = 0; i < 0x1000; ++i) {
        const double angle = (double)i * 0.001533980788;
        sines[i] = (float)sin(angle);
        cose[i] = (float)cos(angle);
        if (i == 0x400 || i == 0xC00) {
            tane[i] = 0.0f;
        } else {
            tane[i] = (float)tan(angle);
        }
        if (i == 0 || i == 0x800) {
            atane[i] = 0.0f;
        } else {
            atane[i] = (float)atan(angle);
        }
    }

    for (int i = 0; i < 0x168; ++i) {
        const double angle = (double)i * 0.01745329252;
        sine360[i] = (float)sin(angle);
        cose360[i] = (float)cos(angle);
        if (i == 0x5A || i == 0x10E) {
            tane360[i] = 0.0f;
        } else {
            tane360[i] = (float)tan(angle);
        }
        if (i == 0 || i == 0xB4) {
            atane360[i] = 0.0f;
        } else {
            atane360[i] = (float)atan(angle);
        }
    }
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A830
int TRIGONOMETRY::RestrictAngle(int param_1) {
    const uint uVar2 = (uint)param_1 >> 0x1f;
    int iVar1 = (((param_1 ^ (int)uVar2) - (int)uVar2) & 0xfff) ^ (int)uVar2;
    iVar1 = iVar1 - (int)uVar2;
    if (iVar1 < 0) {
        iVar1 = -iVar1;
    }
    return iVar1;
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A850
int TRIGONOMETRY::RestrictAngle360(int param_1) {
    int iVar1 = param_1 % 0x168;
    if (iVar1 < 0) {
        iVar1 = -iVar1;
    }
    return iVar1;
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A870
float TRIGONOMETRY::sine(int param_1) {
    return sines[RestrictAngle(param_1)];
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A890
float TRIGONOMETRY::cosine(int param_1) {
    return cose[RestrictAngle(param_1)];
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A8B0
float TRIGONOMETRY::tangent(int param_1) {
    return tane[RestrictAngle(param_1)];
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A8D0
float TRIGONOMETRY::atangent(int param_1) {
    return atane[RestrictAngle(param_1)];
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A8F0
float TRIGONOMETRY::sin360(int param_1) {
    return sine360[RestrictAngle360(param_1)];
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A910
float TRIGONOMETRY::cos360(int param_1) {
    return cose360[RestrictAngle360(param_1)];
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A930
float TRIGONOMETRY::tan360(int param_1) {
    return tane360[RestrictAngle360(param_1)];
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A950
float TRIGONOMETRY::atan360(int param_1) {
    return atane360[RestrictAngle360(param_1)];
}

// Fully verified. Source of truth: trig.cpp.decomp @ 0x0052A980
void E1() {
    // No-op: global `trig` is initialized at static startup.
}
