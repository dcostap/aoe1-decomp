// VA: 00404A90 update
// PDB source: ACT_make.cpp
//
// Attempt log:
// - tried if/else chain with __stdcall function pointers (272 bytes, 5 short)
//   -> call pattern was wrong (add ecx,0x84; call ecx instead of call [vtable+0x84])
// - tried virtual methods with 34 stubs -> correct call [vtable+0x84] pattern
//   -> 304 bytes, too big. Register save pushes 4 at top (vs original's 1)
// - tried switch for state check -> generated dec/sub/jne pattern (correct!)
//   -> but still 304 bytes due to register save differences
// - tried moving locals into case block -> no improvement (function-wide reg alloc)
// - tried raw function pointer through vtable slot -> 176 bytes but no args on calls
// - tried struct-only (no virtual methods) -> wrong call pattern (computed address)
// - tried nested blocks to isolate local declarations -> no register save improvement
// - tried different local scope patterns -> same issue
//
// Remaining gap: VC5 register save pattern pushes all callee-saved regs at function
// top when virtual methods are declared in the class, while the original delays
// pushes of edi/ebp/ebx until after the state==1 early-return check.
// State check uses cmp/jne instead of original's dec/je/sub/jne in if-else form.
// Exact match requires the specific register allocation (esi for this) and
// delayed register save pattern that we can't control from C.
// Left in scratch because the remaining mismatch is register allocation / block-layout drift.

#include "..\..\include\game_globals.h"

struct RGE_Action_Make_SubObj {
    char gap_00[0xE4];
    float field_E4;
};

struct RGE_Action_Make_Target_Inner2 {
    char gap_00[0x84];
    float field_84;
};

struct RGE_Action_Make_Target_Inner1 {
    char gap_00[0x3C];
    RGE_Action_Make_Target_Inner2* field_3C;
    char gap_40[0x10];
    short field_4A;
    char gap_4C[0x04];
    void* field_50;
};

struct RGE_Action_Make_Target_Sub {
    char gap_00[0x90];
    float field_90;
};

// Target class with enough virtual stubs for slots 27(vfunc6C), 30(vfunc78), 33(vfunc84)
class RGE_Action_Make_Target {
public:
    virtual void d00(); virtual void d04(); virtual void d08(); virtual void d0C();
    virtual void d10(); virtual void d14(); virtual void d18(); virtual void d1C();
    virtual void d20(); virtual void d24(); virtual void d28(); virtual void d2C();
    virtual void d30(); virtual void d34(); virtual void d38(); virtual void d3C();
    virtual void d40(); virtual void d44(); virtual void d48(); virtual void d4C();
    virtual void d50(); virtual void d54(); virtual void d58(); virtual void d5C();
    virtual void d60(); virtual void d64(); virtual void d68();
    virtual void vfunc6C();        // slot 27 (0x6C)
    virtual void d70(); virtual void d74();
    virtual void vfunc78(short, float, int);  // slot 30 (0x78)
    virtual void d7C(); virtual void d80();
    virtual void vfunc84(float, int, int);    // slot 33 (0x84)

    int field_04;
    RGE_Action_Make_SubObj* field_08;
    RGE_Action_Make_Target_Inner1* field_0C;
    char gap_10[0x28];
    float field_38;
    float field_3C;
    char gap_40[0x04];
    float field_44;
};

// GameStub mirrors RGE_Base_Game vtable for notification() at slot 16 (0x40)
class GameStub {
public:
    virtual void d00(); virtual void d04(); virtual void d08(); virtual void d0C();
    virtual void d10(); virtual void d14(); virtual void d18(); virtual void d1C();
    virtual void d20(); virtual void d24(); virtual void d28(); virtual void d2C();
    virtual void d30(); virtual void d34(); virtual void d38(); virtual void d3C();
    virtual void notification(int p1, long p2, long p3, long p4, long p5); // vt[16]
};

class RGE_Action_Make {
public:
    char gap_00[0x08];
    RGE_Action_Make_Target* field_08;
    unsigned char field_0C;
    char gap_0D[0x1F];
    float field_2C;
    void* field_30;

    unsigned char update();
};

unsigned char RGE_Action_Make::update() {
    if (field_0C == 1) {
        return 1;
    }
    if (field_0C == 6) {
        RGE_Action_Make_Target* target = field_08;
        RGE_Action_Make_Target_Inner1* inner1 = (RGE_Action_Make_Target_Inner1*)target->field_0C;
        float work;
        float old_field_44;

        if (field_2C > 0.0
            || ((RGE_Action_Make_Target_Sub*)inner1->field_50)->field_90 <= 0.0)
        {
            // attribute computation + field_2C update (lines 70-80)
            work = target->field_08->field_E4
                 * inner1->field_3C->field_84
                 * *(float*)((char*)field_30 + 0x1C);
            old_field_44 = target->field_44;
            if (*(short*)((char*)field_30 + 0x30) == 0) {
                target->vfunc84(work, 1, 1);
            } else {
                target->vfunc78(*(short*)((char*)field_30 + 0x14), work, 0);
            }
            field_2C -= target->field_44 - old_field_44;
        } else if (target->field_44 > 0.0) {
            return 0;
        } else {
            // rge_base_game notification + target->vfunc6C (lines 85-88)
            int ftmp1 = (int)target->field_38;
            int ftmp2 = (int)target->field_3C;
            ((GameStub*)rge_base_game)->notification(0x7E, inner1->field_4A, target->field_04, ftmp1, ftmp2);
            target->vfunc6C();
            return 0;
        }
    }
    return 0;
}
