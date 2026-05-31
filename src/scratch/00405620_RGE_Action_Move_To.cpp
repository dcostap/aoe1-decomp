// VA: 00405620 RGE_Action_Move_To::RGE_Action_Move_To
// act_move.cpp
// Retry 2026-05-26: modeled base as non-virtual destructible RGE_Action to get VC5 /GX EH frame without layout shift.
// Best result: exact size 186B, setup/base call/vptr/target/range/FPU code all match; remaining diff is late sprite fallback block layout.
// Tried 10 variants: old extern set_target surface, virtual/nonvirtual base dtor, novtable/manual vptr, this->obj reload vs saved obj,
// if(s)/else, if(!s)/else, temp-final assignment, volatile temp, two independent ifs, and goto-shaped fallback. Best is current.
// Left in scratch: MISMATCH 24 positional / 17 edit bytes at +137. Drift is localized to the final `if (spr==0)` fallback:
// original uses `jne shared_epilogue`, then inner `if(s) sprite=s; else sprite=o->sprite18;` with a shared epilogue; rebuilt emits
// equivalent fallback values but arranges the inner/outer branches differently around the EH epilogue. Not proposing accepted_drift yet
// unless reviewer accepts this localized equivalent tail-layout drift.
// 2026-05-31 retry: explicit goto-shaped fallback and inverted `if (s != 0)` worsened (outer branch jumps past the original-sized body;
// two-independent-if version adds extra tests). A final-sprite temp lowered edit diff to 13 but used a common `mov [esi+38],eax`
// store instead of the original two branch-local stores, so kept the better positional baseline.

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Action_List;

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Action_Object {
public:
    char gap_00[8];
    RGE_Static_Object* obj;
};

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    char gap_06_07[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char pad_0D_0F[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char pad_3D_3F[3];

    ~RGE_Action();
    RGE_Action(RGE_Action_Object* obj, int type);
    void set_target_obj(RGE_Static_Object* target);
};

class __declspec(novtable) RGE_Action_Move_To : public RGE_Action {
public:
    float range;

    RGE_Action_Move_To(RGE_Action_Object* obj, RGE_Static_Object* target, float range_val, RGE_Sprite* spr);
};

RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* obj, RGE_Static_Object* target, float range_val, RGE_Sprite* spr)
    : RGE_Action(obj, 1)
{
    *(int*)this = 0x56E3A0;
    action_type = 1;
    set_target_obj(target);

    if (target) {
        target_x = target->world_x;
        target_y = target->world_y;
        target_z = target->world_z;
    }

    range = range_val;
    sprite = spr;

    if (range_val <= 0.0f)
        range = 0.4f;

    if (spr == 0) {
        RGE_Static_Object* o = this->obj->obj;
        RGE_Sprite* s = *(RGE_Sprite**)((char*)o + 0xBC);
        if (s == 0) {
            sprite = *(RGE_Sprite**)((char*)o + 0x18);
        } else {
            sprite = s;
        }
    }
}
