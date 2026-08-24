// VA: 004C85D0 TRIBE_Building_Object::take_building_attribute_from_owner
// PDB source: t_b_obj.cpp, lines 238-245
// ACCEPTED_DRIFT: remaining 1-byte positional diff is SIB byte encoding choice
//   for `cmp byte [edi+eax+0x88],4` vs `cmp byte [eax+edi+0x88],4`. Both
//   encodings are functionally equivalent (same registers, swapped base/index
//   roles in the effective address). VC5 register allocator consistently
//   chooses base=eax, index=edi while the original has base=edi, index=eax.
//   No behavioral difference.
//
// Attempt log:
// - Initial scratch used manual offset variables and raw pointer cast; 59% diff
// - Changed to arrays (attrs[3]/amts[3]/modes[3]) with for-loop; still 59% diff
// - Changed to for-loop with 'float neg_amt' local for the negation; 1 byte diff!
//   The float local was critical for matching the fchs pattern.
// - Variant lab tested 4 modes access forms (direct[], *ptr+, char* cast, rev order):
//   all produce same SIB encoding. Deep allocator heuristic, not source-shape
//   responsive.
// - char* base pointer version: 56% diff (worse structure).
// - do-while with explicit offset variables: 79% diff.

#ifndef T_B_OBJ_CONTEXT_H
class RGE_Player {
public:
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5C();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6C();
    virtual void s70();
    virtual void s74();
    virtual void add_attribute(short, float, int);
};

class Master {
public:
    char gap_00[0x6A];
    short attrs[3];
    float amts[3];
    char gap_7C[0x88 - 0x7C];
    unsigned char modes[3];
};

class TRIBE_Building_Object {
public:
    char gap_00[8];
    Master* master_obj;
    RGE_Player* owner;

    void take_building_attribute_from_owner();
};
#endif

void TRIBE_Building_Object::take_building_attribute_from_owner() {
    for (int i = 0; i < 3; i++) {
        Master* m = this->master_obj;
        if (m->modes[i] >= 4) {
            if (m->attrs[i] >= 0) {
                float neg_amt = -m->amts[i];
                this->owner->add_attribute(m->attrs[i], neg_amt, 0);
            }
        }
    }
}
