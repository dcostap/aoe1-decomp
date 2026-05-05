// VA: 004C5CB0 RGE_Static_Object::heal(float)
// PDB source: stat_obj.cpp lines 3163-3180 (93 bytes, 30 asm lines)
// Default flags
//
// __thiscall: this in ecx, 1 stack param (float amount). ret 4 cleanup.
// 76/93 edit-match bytes. Left in scratch.
//
// Stable VC5 heuristic differences:
//
// 1. FPU stack scheduling: Original computes `fVar1 = amount + hp` by duplicating `amount`
//    on the FPU stack (`fld amount; fld amount; fcomp 0.0; fadd hp`), where the duplicate
//    is consumed by the comparison and the original by the addition. VC5 loads `amount`
//    and `hp` separately, adds them, then uses `fxch` to swap back for comparison.
//    No C++ restructuring can force the fld-st0 duplicate pattern.
//
// 2. Block ordering (max check): Original puts `return 0` as the label/taken branch and
//    `cap+return 1` as fall-through. VC5 inverts this.
//
// Everything else:
// - movsx for master_obj->hp (short to int) ✓
// - fild to float conversion ✓
// - 1.0f constant (0x3F800000) for the clamp ✓
// - int maxHp comparison via fcom✓
// - return 0/1 in al ✓

class RGE_Master_Static_Object {
public:
    char gap_00[0x26];
    short hp;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    int id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x24];
    float hp;

    unsigned char heal(float amount);
};

unsigned char RGE_Static_Object::heal(float amount) {
    float fVar1 = amount + this->hp;
    this->hp = fVar1;
    if (amount < 0.0f) {
        if (fVar1 < 1.0f) {
            this->hp = 1.0f;
        }
    }
    int maxHp = this->master_obj->hp;
    if (maxHp > this->hp) return 0;
    this->hp = (float)maxHp;
    return 1;
}
