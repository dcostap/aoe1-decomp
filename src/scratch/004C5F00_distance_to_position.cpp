// VA: 004C5F00 RGE_Static_Object::distance_to_position (152 B)
// PDB source: stat_obj.cpp lines 3700-3722
// Default flags: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: Initial rewrite from scratch (was wrong — Manhattan distance only)
// 2: Ternary abs → 144B, inline fsqrt, FPU spill pattern differs
// 3: Volatile pointer hack → no change
// 4: <math.h> + sqrt → correct sqrt but library call (144B)
// 5-9: Various FPU stack approaches (self-contained if blocks, Ghidra pattern)
//   → all 144B, same FPU stack management (fxch) instead of store-reload
// 10: Volatile floats → 152B but completely different FPU layout
//
// Left in scratch: FPU register allocation pattern differs from original.
// Original uses fstp/fld store-reload for dy while testing dx.
// Rebuilt uses fxch/fchs/fxch to keep both in FPU stack.
// 144 bytes (8 short of 152) due to optimized FPU pattern.
// sqrt is inlined as fsqrt with <math.h> + /O2.
// Not proposing accepted_drift: 144 vs 152 size mismatch.

#include <math.h>

class RGE_Master_Static_Object {
public:
    char gap_00[0x30];
    float radius_x;   // +0x30
    float radius_y;   // +0x34
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x2C];
    float world_x;    // +0x38
    float world_y;    // +0x3C

    float distance_to_position(float x, float y, float z);
};

float RGE_Static_Object::distance_to_position(float x, float y, float z)
{
    float dx = this->world_x - x;
    float dy = this->world_y - y;

    if (dx < 0.0f) dx = -dx;
    if (dy < 0.0f) dy = -dy;

    float dx2 = dx - this->master_obj->radius_x;
    float dy2 = dy - this->master_obj->radius_y;

    if (dx2 < 0.0f) dx2 = 0.0f;
    if (dy2 < 0.0f) dy2 = 0.0f;

    return sqrt(dx2 * dx2 + dy2 * dy2);
}
