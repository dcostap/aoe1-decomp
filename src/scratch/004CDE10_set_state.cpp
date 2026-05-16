// 004CDE10 TRIBE_Action_Convert::set_state
// Attempt log:
// 1: natural implementation from packet/decompiler with /GX for new+ctor EH, but overlarge manual vtable surface had a compile error.
// 2: reduced typed surface with only required virtual slots: compile failed because raw __thiscall function pointer casts are forbidden/unsupported in VC5.
// 3: replace raw casts with padded virtual declarations for slots +0x148 and +0x94: compiles with /GX, but very broad mismatch (extra EBX save, if-chain instead of jump table, wrong object surfaces).
// 4: test without /GX to see whether prologue/register pressure improves: no EH frame and object too short; /GX is required.
// 5: add explicit empty switch cases to encourage VC5 jump table and call set_state via base pointer for virtual dispatch: no improvement; still if-chain and extra EBX save.
// 6: inspected prologue: extra EBX comes from current typed virtual/helper surface and shifts parameter/local stack offsets immediately.
// 7: inspected original switch: exact source needs dense jump table for states 1..14 with default routed to epilogue; current source still compiles to compare chain despite empty cases.
// 8: verified /GX is necessary for EH registration and new+ctor local_4 state; non-/GX object was too short and invalid for this function.
// 9: replaced forbidden __thiscall raw slot casts with padded virtual declarations; compile-safe but bloats source surface and likely causes register pressure.
// 10: left in scratch: behavior outline and calls are partially understood, but object/vtable surfaces and switch/EH source shape are too wrong for accepted drift.

typedef unsigned char uchar;
#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class RGE_Action_List { public: void delete_list(); void add_action(void*); };
class RGE_Sprite;
class RGE_Sound { public: void play(int); };
class RGE_Task { public: char pad00[0x20]; float timer; char pad24[0x10]; RGE_Sprite* sprite; float x; float y; float z; RGE_Sound* sound; };

class RGE_Action_Object {
public:
    VPAD32(0) VPAD4(32)
    virtual void vt94(int, int, int, int, int); // slot 37 = +0x94
    VPAD32(38) VPAD8(70) VPAD4(78)
    virtual void open_graphic(int,int,int,int,int,int); // slot 82 = +0x148
    char pad04[0x34]; int f38; int f3c; int f40;
};
class RGE_Game_Object {
public:
    VPAD8(0) VPAD4(8) VPAD2(12)
    virtual void set_graphic(int); // slot 14 = +0x38
    char pad04[4]; RGE_Action_Object* action_object;
};
class RGE_Animated_Object : public RGE_Game_Object {
public:
    char pad0c[0x18-0x0c]; void* graphic_info;
};
class RGE_Action_Target {
public:
    void* vptr; char pad04[0x0c-4]; RGE_Action_Object* action_object; char pad10[0x38-0x10]; float x; float y; float z;
};
class RGE_Action_Move_To { public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Action_Target*, float, RGE_Sprite*);
    void setSubAction(uchar);
};
class RGE_Action { public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18();
    virtual void first_in_stack(uchar); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C(); virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C(); virtual void vf50(); virtual void set_target_obj(RGE_Action_Target*); virtual void vf58(); virtual void set_state(uchar);
    short action_type; uchar pad06[2]; RGE_Action_Object* object; uchar state; uchar pad0d[3]; RGE_Action_Target* target_obj; RGE_Action_Target* target_obj2; int targetID; int target2ID; float target_x; float target_y; float target_z; float timer; RGE_Task* task; RGE_Action_List* action_list;
};
class TRIBE_Action_Convert : public RGE_Action { public: uchar was_same_owner; char gap41[3]; float requiredRange; void set_state(uchar); };

void TRIBE_Action_Convert::set_state(uchar new_state) {
    this->action_list->delete_list();
    this->state = new_state;
    switch (new_state) {
    case 3:
        this->object->open_graphic(this->object->f38, this->object->f38, 0x202, 0x25c, 0, 0);
    case 1: case 2: case 13: case 14:
        ((RGE_Game_Object*)this->object)->set_graphic((int)((RGE_Animated_Object*)this->object)->graphic_info);
        return;
    case 11: {
        RGE_Action_Move_To* a = new RGE_Action_Move_To(this->object, this->target_x, this->target_y, this->target_z, this->requiredRange, this->task->sprite);
        if (!a) { ((RGE_Action*)this)->set_state(13); return; }
        a->setSubAction(1); this->action_list->add_action(a); return;
    }
    case 4: {
        RGE_Action_Target* t = this->target_obj; this->target_x=t->x; this->target_y=t->y; this->target_z=t->z;
        RGE_Action_Move_To* a = new RGE_Action_Move_To(this->object, t, this->requiredRange, this->task->sprite);
        if (!a) { ((RGE_Action*)this)->set_state(13); return; }
        this->action_list->add_action(a); a->setSubAction(1); return;
    }
    case 5:
        return;
    case 6:
        ((RGE_Game_Object*)this->object)->set_graphic((int)this->task->sprite); return;
    case 7:
        ((RGE_Game_Object*)this->object)->set_graphic((int)this->task->x);
        if (this->task->sound) this->task->sound->play(1);
        if (this->target_obj && *(short*)((char*)this->target_obj->action_object + 0x4a) > 0) {
            this->target_obj->action_object->vt94(0x70, this->object->f38, this->object->f3c, this->object->f40, 0);
        }
        this->timer = this->task->timer; return;
    case 8:
    case 9:
    case 10:
    case 12:
        return;
    default: return;
    }
}
