// VA: 0052A730 TRIGONOMETRY
// PDB source: trig.cpp
// Constructor that builds trig lookup tables (sin, cos, tan, cotan)

#include <math.h>

class TRIGONOMETRY {
public:
    float sines[4096];        // +0x0000
    float cosines[4096];      // +0x4000
    float tanges[4096];       // +0x8000
    float cotanges[4096];     // +0xC000

    float sines360[360];      // +0x10000
    float cosines360[360];    // +0x105A0
    float tanges360[360];     // +0x10B40
    float cotanges360[360];   // +0x110E0

    TRIGONOMETRY();
};

TRIGONOMETRY::TRIGONOMETRY()
{
    int i;

    // Phase 1: 4096-entry table (0 to 2*PI in 4096 steps)
    for (i = 0; i < 0x1000; i++) {
        double rad = (double)i * 0.001533980788;
        sines[i] = (float)sin(rad);
        cosines[i] = (float)cos(rad);

        if (i == 0x400 || i == 0xC00)
            tanges[i] = 0.0f;
        else
            tanges[i] = (float)tan(rad);

        if (i == 0 || i == 0x800)
            cotanges[i] = 0.0f;
        else
            cotanges[i] = (float)atan(rad);
    }

    // Phase 2: 360-entry table (degree-based, 0 to 360 in 360 steps)
    for (i = 0; i < 0x168; i++) {
        double rad = (double)i * 0.01745329252;
        sines360[i] = (float)sin(rad);
        cosines360[i] = (float)cos(rad);

        if (i == 0x5A || i == 0x10E)
            tanges360[i] = 0.0f;
        else
            tanges360[i] = (float)tan(rad);

        if (i == 0 || i == 0xB4)
            cotanges360[i] = 0.0f;
        else
            cotanges360[i] = (float)atan(rad);
    }
}
