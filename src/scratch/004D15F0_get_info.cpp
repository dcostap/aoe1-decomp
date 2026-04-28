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

#include <string.h>

struct RGE_Action_Object;

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

    void get_info(short* param_1, short* param_2, char* param_3, short param_4);
};

void TRIBE_Action_Make_Obj::get_info(short* param_1, short* param_2, char* param_3, short param_4) {
    *param_1 = this->obj_id;

    if (this->state == 1) {
        *param_2 = 100;
    } else {
        int divisor = *(short*)(*(int*)(*(int*)((char*)this->obj + 0x0C) + 0x24) + (int)this->obj_id * 4 + 0x15A);
        int pc = (int)((this->speed * DAT_005751A0) / (float)divisor);
        *param_2 = (short)pc;
    }

    if (param_3 != 0) {
        char* src = *(char**)(*(int*)(*(int*)((char*)this->obj + 0x0C) + 0x24) + (int)this->obj_id * 4 + 0x08);
        strncpy(param_3, src, (unsigned int)param_4);
        param_3[param_4 - 1] = 0;
    }
}
