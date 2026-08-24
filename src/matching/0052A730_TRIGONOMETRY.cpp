// VA: 0052A730 TRIGONOMETRY
// PDB source: trig.cpp
// Constructor that builds trig lookup tables (sin, cos, tan, cotan)

#include <math.h>

#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
public:
    float sines[4096];        // +0x0000
    float cose[4096];         // +0x4000
    float tane[4096];         // +0x8000
    float atane[4096];        // +0xC000

    float sine360[360];       // +0x10000
    float cose360[360];       // +0x105A0
    float tane360[360];       // +0x10B40
    float atane360[360];      // +0x110E0

    TRIGONOMETRY();
};
#endif

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
