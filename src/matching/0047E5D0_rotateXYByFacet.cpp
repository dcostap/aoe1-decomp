// MATCHED. Exact 147-byte match confirmed via local check_function.py.
// Key fix: separate c*dy into a named temp `float y1 = c * dy` before using
// it in `y1 + s * dx`, forcing VC5 to evaluate cos*dy first (original fmul st2
// before fmul st3 order after __ftol). Without the temp, VC5 evaluates s*dx
// first, producing wrong FPU fxch/fmul ordering.

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
        float y1 = c * dy;
        output.y = (int)(y1 + s * dx);
    }
}
