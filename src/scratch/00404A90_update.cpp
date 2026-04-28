// VA: 00404A90 update
// PDB source: ACT_make.cpp lines 61-98
// RGE_Action_Make::update() (277 bytes)
//
// Remaining gap after ~40min targeted investigation:
// Standalone VC5 compilation produces correct control flow, vtable calls,
// field offsets, and FP math, but VC5's register allocator assigns:
//   edi=this, esi=target, ebx=inner1, eax=game_vtable
// instead of original:
//   esi=this, edi=target, ebx=inner1, ebp=game_vtable
//
// Attempts tried (all at 277 bytes, all mismatch at byte 5):
// 1) switch for state check -> correct dec/je/sub/jne pattern
// 2) virtual methods on target -> correct call [vtable+offset] (all 4 calls)
// 3) typed RGE_Base_Game::notification call -> correct vtable double-deref
// 4) delayed target/inner1 locals after FP gates -> no register change
// 5) scoped blocks to isolate target/inner1 -> same reg alloc
// 6) inverted condition logic (goto-free) -> same reg alloc
// 7) flag variables vs direct paths -> same reg alloc
// All fail at byte 5: original pushes esi only, rebuilt pushes ebx,esi,edi
// This is a TU-context boundary case (compiled as part of full ACT_make.cpp).

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

class RGE_Action_Make_Target {
public:
    virtual void d00(); virtual void d04(); virtual void d08(); virtual void d0C();
    virtual void d10(); virtual void d14(); virtual void d18(); virtual void d1C();
    virtual void d20(); virtual void d24(); virtual void d28(); virtual void d2C();
    virtual void d30(); virtual void d34(); virtual void d38(); virtual void d3C();
    virtual void d40(); virtual void d44(); virtual void d48(); virtual void d4C();
    virtual void d50(); virtual void d54(); virtual void d58(); virtual void d5C();
    virtual void d60(); virtual void d64(); virtual void d68();
    virtual void vfunc6C();
    virtual void d70(); virtual void d74();
    virtual void vfunc78(short, float, int);
    virtual void d7C(); virtual void d80();
    virtual void vfunc84(float, int, int);

    int field_04;
    RGE_Action_Make_SubObj* field_08;
    RGE_Action_Make_Target_Inner1* field_0C;
    char gap_10[0x28];
    float field_38;
    float field_3C;
    char gap_40[0x04];
    float field_44;
};

class RGE_Base_Game {
public:
    virtual void d00(); virtual void d04(); virtual void d08(); virtual void d0C();
    virtual void d10(); virtual void d14(); virtual void d18(); virtual void d1C();
    virtual void d20(); virtual void d24(); virtual void d28(); virtual void d2C();
    virtual void d30(); virtual void d34(); virtual void d38(); virtual void d3C();
    virtual void notification(int, long, long, long, long);  // vt[16] = 0x40
};

class RGE_Action_Make {
public:
    unsigned char update();
    char gap_00[0x08];
    RGE_Action_Make_Target* field_08;
    unsigned char field_0C;
    char gap_0D[0x1F];
    float field_2C;
    void* field_30;
};

unsigned char RGE_Action_Make::update() {
    switch (field_0C) {
    case 1:
        return 1;
    case 6: {
        RGE_Action_Make_Target* target = field_08;
        RGE_Action_Make_Target_Inner1* inner1 = target->field_0C;
        float work;
        float old_field_44;

        if (field_2C > 0.0) {
            goto do_attrib;
        }
        if (((RGE_Action_Make_Target_Sub*)inner1->field_50)->field_90 > 0.0) {
            if (target->field_44 > 0.0) {
                return 0;
            }
            ((RGE_Base_Game*)rge_base_game)->notification(
                0x7E, inner1->field_4A, target->field_04,
                (int)target->field_38, (int)target->field_3C);
            target->vfunc6C();
            return 0;
        }

do_attrib:
        work = target->field_08->field_E4 * inner1->field_3C->field_84
             * *(float*)((char*)field_30 + 0x1C);
        old_field_44 = target->field_44;
        if (*(short*)((char*)field_30 + 0x30) == 0) {
            target->vfunc84(work, 1, 1);
        } else {
            target->vfunc78(*(short*)((char*)field_30 + 0x14), work, 0);
        }
        field_2C -= target->field_44 - old_field_44;
        break;
    }
    }
    return 0;
}
