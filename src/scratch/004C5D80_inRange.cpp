// VA: 004C5D80 RGE_Static_Object::inRange
// PDB source: stat_obj.cpp
// Attempt log:
// 2026-05-31: Replaced stub with decompiler/natural distance-minus-radii behavior; natural source compiled 192B, too small vs 199B.
// 2026-05-31: Best kept variant uses volatile dy plus volatile x; it reaches exact size and matches the original push/local prefix through offset 71, but volatile x stores too early and the remaining x/y radius subtraction and final range compare FPU stack schedule differs broadly (33.17% positional). Not accepted_drift quality.
// 2026-05-31: Tried parameter-slot reuse and x-clamp-before-y forms; they fell back to 192B/no-push families. /Op produced a broad wrong frame.
// 2026-08-02 sa_eaf547d0_r1: baseline restored the natural typed dx/dy/x/y distance-minus-radii source (182B, 197 differing bytes); the compiler's no-push basin is structurally wrong.
// 2026-08-02 sa_eaf547d0_r1: rechecked the prior volatile-dy/volatile-x diagnostic (199B, 77 differing bytes, exact prefix through +0047); its early volatile x store remains the first structural mismatch at the radius FPU block.
// 2026-08-02 sa_eaf547d0_r1: normal-x, address-taken/array x, target-pointer alias, delayed x materialization, x-before-y, and in-place dx/dy variants all returned no-push or broad structural basins; a 120-case radius-expression/final-expression lab found no exact variant (best size-eligible family remained 66 positional bytes off).
// 2026-08-02 sa_eaf547d0_r1: left in clean natural source after the 10-hypothesis budget; blocker is unresolved VC5 x87 scheduling/stack-home shape from +0047, not calls, layout offsets, or behavior.

class RGE_Master_Object {
public:
    char gap_00[0x30];
    float radius_x;
    float radius_y;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Object* master_obj; // +0x08
    char gap_0C[0x2C];
    float world_x; // +0x38
    float world_y; // +0x3C

    int inRange(RGE_Static_Object* other, float range);
};

int RGE_Static_Object::inRange(RGE_Static_Object* other, float range)
{
    float dx = other->world_x - this->world_x;
    float dy = other->world_y - this->world_y;

    if (dx < 0.0f) {
        dx = -dx;
    }
    if (dy < 0.0f) {
        dy = -dy;
    }

    float x = dx - this->master_obj->radius_x - other->master_obj->radius_x;
    float y = dy - this->master_obj->radius_y - other->master_obj->radius_y;

    if (x < 0.0f) {
        x = 0.0f;
    }
    if (y < 0.0f) {
        y = 0.0f;
    }

    if (y * y + x * x < range * range) {
        return 1;
    }
    return 0;
}
