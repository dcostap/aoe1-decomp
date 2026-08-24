// VA: 004C5F00 RGE_Static_Object::distance_to_position (152 B)
// PDB source: stat_obj.cpp lines 3700-3722
// Default flags: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: Initial rewrite from scratch (was wrong — Manhattan distance only)
// 2: Ternary abs -> 144B, inline fsqrt, FPU spill pattern differs
// 3: Volatile pointer hack -> no change
// 4: <math.h> + sqrt -> correct sqrt but library call (144B)
// 5-9: Various FPU stack approaches (self-contained if blocks, Ghidra pattern)
//   -> all 144B, same FPU stack management (fxch) instead of store-reload
// 10: Volatile floats -> 152B but completely different FPU layout
// Retry 2026-05-19 Boss pass:
// - Tried 15 total variants: parameter-slot reuse, Ghidra temp pattern, volatile dy/params/dx2/both temps, fabs, inverted comparisons, zero local, master local, double sqrt input, dy-first ordering.
// - Best is exact-sized with 13-byte edit diff / 8.5526%: volatile dy forces the original early abs store/reload and all calls/control/return/fsqrt match.
// ACCEPTED_DRIFT_CANDIDATE: remaining differences are localized FPU stack/spill-slot selection in the radius subtraction/clamp region. Rebuilt uses esp+4 for the second temp where original uses esp+8 and computes the same dx2/dy2; final square/sum/fsqrt and clamping behavior are equivalent. No calls or memory effects except stack temps differ.

#include <math.h>

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    char gap_00[0x30];
    float radius_x;
    float radius_y;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;

    float distance_to_position(float x, float y, float z);
};
#endif

float RGE_Static_Object::distance_to_position(float x, float y, float z)
{
    float dx = world_x - x;
    volatile float dy = world_y - y;

    if (dx < 0.0f)
        dx = -dx;
    if (dy < 0.0f)
        dy = -dy;

    float dx2 = dx - master_obj->radius_x;
    float dy2 = dy - master_obj->radius_y;

    if (dx2 < 0.0f)
        dx2 = 0.0f;
    if (dy2 < 0.0f)
        dy2 = 0.0f;

    return sqrt(dx2 * dx2 + dy2 * dy2);
}
