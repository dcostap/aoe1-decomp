// XYZ::rotateXYByFacet
// VA: 0047E5D0
// PDB: point.cpp:86-109
//
// Attempt log:
// - draft 1: inline literal 0.78539f, cos before sin → 21.77% diff
// - draft 2: sin before cos, extern DAT_00571ce8 → 14.97% diff, post-ftol order off
// - draft 3-6: various term orders for y expression → same 14.97% diff
// - Remaining diff: VC5 FPU scheduling chooses sin*dx before cos*dy vs original's cos*dy before sin*dx.
//   Classic register-pressure scheduling difference. Math is identical.
// Left in scratch.

#include "..\..\include\game_globals.h"
#include <math.h>

class XYZ {
public:
    int x;
    int y;
    int z;

    void rotateXYByFacet(const XYZ& facet, XYZ& output, unsigned char facet_idx);
};

void XYZ::rotateXYByFacet(const XYZ& facet, XYZ& output, unsigned char facet_idx)
{
    output.x = this->x;
    output.y = this->y;
    output.z = this->z;

    if (facet_idx)
    {
        int dx = this->x - facet.x;
        int dy = this->y - facet.y;
        float angle = (float)(facet_idx & 0xFF) * 0.7853981852531433f;
        float s = sin(angle);
        float c = cos(angle);
        output.x = (int)(c * dx - s * dy);
        output.y = (int)(dy * c + dx * s);
    }
}
