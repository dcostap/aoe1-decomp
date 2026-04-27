// VA: 00405620 RGE_Action_Move_To::RGE_Action_Move_To (overloaded)
// PDB source: act_move.cpp
// EH-framed constructor with set_target_obj call
// FLAGS: /GX
//
// Attempt log:
// - First pass: 144 bytes (no EH frame w/o /GX or with /GX)
// - Virtual declaration broke layout (offsets shifted by +4)
// - EH_Dummy struct local: 224 bytes (EH frame present but too much overhead)
// - Need to find the exact trigger for the original EH frame
//
// Left in scratch: cannot reproduce the 23-byte EH frame overhead.
// VC5 only generates FS:[0] EH prolog when the function has local objects
// with destructors or explicit try/catch. The original has neither visible
// in the asm, suggesting the original source file had different context
// (e.g., an enclosing function with EH, or #pragma that forced it).

#include <stdlib.h>

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Action_List;
class RGE_Action;

extern void __cdecl RGE_Action_set_target_obj(RGE_Action* action, RGE_Static_Object* target);

class RGE_Action {
public:
    void* vtable_ptr;          // +0x00
    short action_type;         // +0x04
    char gap_06_07[2];        // +0x06
    RGE_Action_Object* obj;    // +0x08
    unsigned char state;       // +0x0C
    char pad_0D_0F[3];        // +0x0D
    RGE_Static_Object* target_obj;   // +0x10
    RGE_Static_Object* target_obj2;  // +0x14
    int targetID;             // +0x18
    int target2ID;            // +0x1C
    float target_x;            // +0x20
    float target_y;            // +0x24
    float target_z;            // +0x28
    float timer;               // +0x2C
    RGE_Task* task;            // +0x30
    RGE_Action_List* sub_actions;  // +0x34
    RGE_Sprite* sprite;        // +0x38
    unsigned char subActionValue;  // +0x3C
    char pad_3D_3F[3];        // +0x3D

    RGE_Action(RGE_Action_Object* obj, int type);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    float range;               // +0x40

    RGE_Action_Move_To(RGE_Action_Object* obj, RGE_Static_Object* target, float range_val, RGE_Sprite* spr);
};

RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* obj, RGE_Static_Object* target, float range_val, RGE_Sprite* spr)
    : RGE_Action(obj, 1)
{
    vtable_ptr = (void*)0x56E3A0;
    action_type = 1;
    RGE_Action_set_target_obj(this, target);

    if (target) {
        target_x = *(float*)((char*)target + 0x38);
        target_y = *(float*)((char*)target + 0x3C);
        target_z = *(float*)((char*)target + 0x40);
    }

    range = range_val;
    sprite = spr;

    if (range_val <= 0.0f)
        range = 0.4f;

    if (spr == 0) {
        void* obj2 = *(void**)((char*)this + 8);
        void* target_obj_inner = *(void**)((char*)obj2 + 8);
        RGE_Sprite* s = *(RGE_Sprite**)((char*)target_obj_inner + 0xBC);
        if (s)
            sprite = s;
        else
            sprite = *(RGE_Sprite**)((char*)target_obj_inner + 0x18);
    }
}
