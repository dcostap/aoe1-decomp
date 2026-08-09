// VA: 00460DB0 boundAngle (243B)
// move_obj.cpp
// Attempt log:
// 1: Natural pointer normalization and nearest-facet reconstruction; structural mismatch (245B).
// 2-4: Separate wrappedAngle and arm/guard order probes; inverted arm layout was the key lead.
// 5: Negative arm first with positive else matched all structure except one positive-loop FPU store/compare ordering (7 bytes).
// 6: Deferred positive store enlarged the function; rolled back.
// 8: Chained positive assignment and do/while variants emitted the same 7-byte drift.
// Variant lab: seven positive-loop spellings produced three codegen groups; no exact group.
// Best clean source retained below; remaining drift is fcom/fstp versus fst/fcomp at +0x43.

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap0[0x1E0 - 4];

    void boundAngle(float* angle, int numberFacets);
};

extern float DAT_00570b48;
extern float DAT_00570b4c;
extern float DAT_00570b50;
extern double DAT_00570b98;
extern float DAT_00570b88;
extern float DAT_00570bfc;
extern double DAT_00570c00;

void RGE_Moving_Object::boundAngle(float* angle, int numberFacets) {
    float wrappedAngle = *angle;

    if (*angle < DAT_00570b48) {
        do {
            wrappedAngle -= DAT_00570b4c;
        } while (wrappedAngle < DAT_00570b48);
        *angle = wrappedAngle;
    } else {
        while (wrappedAngle > DAT_00570b50) {
            *angle = wrappedAngle = *angle - DAT_00570b50;
        }
    }

    if (numberFacets != -1) {
        float facetAngle;
        if (numberFacets == 8) {
            facetAngle = 0.785398185f;
        } else {
            facetAngle = 0.392699093f;
        }

        int closestFacet = -1;
        int i = 0;
        if (numberFacets >= 0) {
            do {
                float difference = *angle - (float)i * facetAngle;
                if (difference < DAT_00570b98) {
                    difference = -difference;
                }
                if (difference < facetAngle) {
                    facetAngle = difference;
                    closestFacet = i;
                }
                if (facetAngle < DAT_00570c00) {
                    break;
                }
                ++i;
            } while (i <= numberFacets);
        }

        if (numberFacets == 8) {
            *angle = (float)closestFacet * DAT_00570b88;
        } else {
            *angle = (float)closestFacet * DAT_00570bfc;
        }
    }
}
