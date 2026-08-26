// VA: 004C5CB0 RGE_Static_Object::heal(float)
// PDB source: stat_obj.cpp lines 3163-3180 (93 bytes, 30 asm lines)
// Default flags
// Exact match.
// Attempts:
// - Initial scratch natural source had correct behavior but VC5 loaded hp separately and used `fxch`,
//   and inverted the final max-hp block layout.
// - Winning shape: read `amount` through volatile lvalue for both the add and negative check; this forces
//   the original `fld amount; fld amount; fcomp 0.0; fadd hp` duplicate-parameter FPU stack pattern.
// - Spell final max-hp check as positive success arm (`if (maxHp <= this->hp) { hp=max; return 1; } return 0;`)
//   to get original `test ah,41h; je fail` with success fall-through before the fail tail.

unsigned char RGE_Static_Object::heal(float amount) {
    float fVar1 = *(volatile float*)&amount + this->hp;
    this->hp = fVar1;
    if (*(volatile float*)&amount < 0.0f) {
        if (fVar1 < 1.0f) this->hp = 1.0f;
    }
    int maxHp = this->master_obj->hp;
    if (maxHp <= this->hp) {
        this->hp = (float)maxHp;
        return 1;
    }
    return 0;
}
