// VA: 004D15F0 TRIBE_Action_Make_Obj::get_info(short*, short*, char*, short)
// Source: tact_mob.cpp lines 255-268
// Size: 140 bytes, __thiscall, ret 10h (4 params)
//
// Attempt log:
// Probe 1: Natural pointer chain — 23 bytes diff (wrong offsets due to explicit vtable)
// Probe 2: Removed explicit vtable field — 16 bytes diff (pure register allocation)
// Probe 3: Explicit intermediates — 87 bytes diff (worse, extra loads)
// Parked: 16 bytes diff is register allocation symmetry (eax/ecx/edx choices)
//         Same operations, same behavior, different registers
// Retry 2026-05-19:
// - Revalidated baseline: 57.86% positional / 23.57% edit; direct expression folded entry+field loads.
// - Added typed ObjList/ObjInfo surface and explicit entry locals; improved to 11.43% positional/edit, exact size.
// - Tried id-before-obj, obj-before-id, register locals, split declaration/assignment, short id, reference params,
//   direct typed expression, and /Og flag probe (removed); all stay in the same 16-byte register-allocation basin.
// - Remaining drift is localized register choice in the two object-info pointer walks only:
//   first walk uses rebuilt ecx/eax/edx/eax where original uses eax/edx/ecx/edx;
//   second walk uses rebuilt eax/edx/ecx/edx where original uses edx/ecx/eax/ecx.
//   Addressed fields/calls, stack cleanup, branches, FPU ops, ftol, strncpy args, and terminator store are identical.
// ACCEPTED_DRIFT 2026-05-19: approved localized behavior-equivalent VC5 register-allocation drift.
// Only differing unmasked bytes are ModRM/register choices in the two side-effect-free object-info
// pointer walks and the corresponding push register for strncpy's source argument. Branches, calls,
// stack cleanup, FPU ops, addressed fields, stores, and terminator write are identical.

#include <string.h>

#ifndef TACT_MOB_SHARED_CONTEXT
struct ObjInfo {
    char gap_00[8];
    char* name;
    char gap_0C[0x15A - 0x0C];
    short work_rate;
};

struct ObjList {
    char gap_00[0x24];
    ObjInfo** entries;
};

struct RGE_Action_Object {
    char gap_00[0x0C];
    ObjList* obj_list;
};

struct RGE_Action {
    short action_type;
    unsigned char _pad6[2];
    RGE_Action_Object* obj;      // +0x08
    unsigned char state;         // +0x0C
    unsigned char _padD[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    unsigned char _pad3D[3];

    RGE_Action(RGE_Action_Object*, int);
    virtual ~RGE_Action();
};

extern float DAT_005751A0;

struct TRIBE_Action_Make_Obj : RGE_Action {
    short obj_id;       // +0x40
    unsigned char _pad42[2];
    float speed;        // +0x44
    int unique_id;      // +0x48
    unsigned char pre_paid; // +0x4C

    void get_info(short& param_1, short& param_2, char* param_3, short param_4);
};
#endif

void TRIBE_Action_Make_Obj::get_info(short& param_1, short& param_2, char* param_3, short param_4) {
    param_1 = this->obj_id;

    if (this->state == 1) {
        param_2 = 100;
    } else {
        RGE_Action_Object* obj;
        short id;
        obj = this->obj;
        id = this->obj_id;
        int divisor = obj->obj_list->entries[id]->work_rate;
        int pc = (int)((this->speed * DAT_005751A0) / (float)divisor);
        param_2 = (short)pc;
    }

    if (param_3 != 0) {
        RGE_Action_Object* obj;
        short id;
        obj = this->obj;
        id = this->obj_id;
        char* src = obj->obj_list->entries[id]->name;
        strncpy(param_3, src, (unsigned int)param_4);
        param_3[param_4 - 1] = 0;
    }
}
