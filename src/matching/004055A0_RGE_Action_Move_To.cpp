// VA: 004055A0 RGE_Action_Move_To::RGE_Action_Move_To
// PDB source: act_move.cpp

#include <stdlib.h>

#ifndef ACT_MOVE_CONTEXT_H
class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Action_List;

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

    RGE_Action_Move_To(RGE_Action_Object* obj, float x, float y, float z, float range, RGE_Sprite* spr);
};
#endif

RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* obj, float x, float y, float z, float range_val, RGE_Sprite* spr)
    : RGE_Action(obj, 1)
{
    action_type = 1;

    target_x = x;
    target_y = y;
    target_z = z;
    range = range_val;
    sprite = spr;

    if (range_val <= 0.0f)
        range = 0.4f;

    if (spr == 0) {
        void* obj2 = *(void**)((char*)this + 8);
        void* obj3 = *(void**)((char*)obj2 + 8);
        RGE_Sprite* s = *(RGE_Sprite**)((char*)obj3 + 0xBC);
        if (!s)
            sprite = *(RGE_Sprite**)((char*)obj3 + 0x18);
        else
            sprite = s;
    }
}
