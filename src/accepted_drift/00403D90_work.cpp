// VA: 00403D90, RGE_Action_Gather::work, 257 bytes
// Source: ACT_GATH.cpp lines 837-887
// ACCEPTED_DRIFT: 6 bytes diff (2.33%) in null path internal scheduling only
//
// Remaining drift: the null path loads 3 params from the stack and stores
// to target_x/y/z in a different order than the original. The mapping is
// identical (param_4→target_z, param_2→target_x, param_3→target_y), just
// the compiler schedules the 3 independent loads/stores differently.
// Original: load p4→ecx, p2→edx, p3→eax → store tz(0x28), tx(0x20), ty(0x24)
// Rebuilt:  load p3→ecx, p4→edx, p2→eax → store ty(0x24), tz(0x28), tx(0x20)
//
// This is purely a scheduling artifact - behavior, register mapping, and
// final field values are identical. Not worth more iterations.
//
// Attempt log:
// - v1: wrong branch layout for null check (fall-through vs jump), 256 bytes
// - v2: right branch layout (if param_1), first 167 bytes match, reg alloc diff
// - v3: raw offset access for world_x/y/z, null path store order diff
// - v4: master_id comparison matches, null path param ordering still off
// - v5: chained assignment didn't fix null path order
// - v6: volatile store for target_z didn't help
// - v7: explicit vtable load between stores didn't change scheduling
// - v8: integer array indexing didn't prevent reordering
// FLAGS: /nologo /c /O2 /Oy

#ifndef ACT_GATH_CONTEXT_H
#include <stddef.h>

typedef unsigned char uchar;

// RGE_Action (size 0x40)
class RGE_Action {
public:
    void* vtable_ptr;      // +0x00
    short action_type;     // +0x04
    uchar gap_06[2];       // +0x06
    void* obj;             // +0x08
    uchar state;           // +0x0C
    uchar gap_0D[3];       // +0x0D
    void* target_obj;      // +0x10
    void* target_obj2;     // +0x14
    int targetID;          // +0x18
    int target2ID;         // +0x1C
    float target_x;        // +0x20
    float target_y;        // +0x24
    float target_z;        // +0x28
    float timer;           // +0x2C
    void* task;            // +0x30
    void* sub_actions;     // +0x34
    void* sprite;          // +0x38
    uchar subActionValue;  // +0x3C
    uchar gap_3D[3];       // +0x3D
};

// RGE_Action_Gather (size 0x44, inherits RGE_Action)
class RGE_Action_Gather : public RGE_Action {
public:
    int targetType;        // +0x40

    int work(void* param_1, float param_2, float param_3, float param_4);
};
#endif

// Helper struct with 24 virtual slots for vtable dispatch
#ifndef ACT_GATH_CONTEXT_H
struct RGE_Action_VTable {
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
    virtual void func54(int arg);   // slot 21 -> vtable[0x54]
    virtual void func58(int arg);   // slot 22 -> vtable[0x58]
    virtual void func5C(int arg);   // slot 23 -> vtable[0x5C]
};
#endif

#ifdef ACT_GATH_CONTEXT_H
int RGE_Action_Gather::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4)
#else
int RGE_Action_Gather::work(void* param_1, float param_2, float param_3, float param_4)
#endif
{
    if (param_1) {
        if (param_1 == target_obj && (state == 4 || state == 6 || state == 7)) {
            return 1;
        }

        void* obj_ptr = obj;
        if (*(void**)((char*)param_1 + 0x0C) == *(void**)((char*)obj_ptr + 0x0C)) {
            void* param_master = *(void**)((char*)param_1 + 8);
            void* obj_master = *(void**)((char*)obj_ptr + 8);
            short master_id = *(short*)((char*)param_master + 0x10);
            if ((master_id == *(short*)((char*)obj_master + 0xE8) ||
                 master_id == *(short*)((char*)obj_master + 0xEA)) &&
                *(float*)((char*)obj_ptr + 0x44) > 0.0f) {
                timer = 0.0f;
                ((RGE_Action_VTable*)this)->func54(0);
                target_x = -1.0f;
                target_y = -1.0f;
                target_z = -1.0f;
                ((RGE_Action_VTable*)this)->func58((int)param_1);
                ((RGE_Action_VTable*)this)->func5C(8);
                return 1;
            }
        }

        ((RGE_Action_VTable*)this)->func54((int)param_1);
        target_x = *(float*)((char*)param_1 + 0x38);
        target_y = *(float*)((char*)param_1 + 0x3C);
        target_z = *(float*)((char*)param_1 + 0x40);
        ((RGE_Action_VTable*)this)->func58(0);
        ((RGE_Action_VTable*)this)->func5C(4);
    } else {
        target_z = param_4;
        target_x = param_2;
        target_y = param_3;
        ((RGE_Action_VTable*)this)->func54(0);
        ((RGE_Action_VTable*)this)->func5C(0x0F);
    }
    return 1;
}
