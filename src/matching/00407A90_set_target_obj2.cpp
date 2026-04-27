// RGE_Action::set_target_obj2
// VA: 00407A90
// PDB: action.cpp:371-389
// No EH framing

#include "../../include/game_globals.h"

// Local stubs from matching 004074F0_RGE_Action.cpp
class RGE_Static_Object;
class RGE_Action_List;

// RGE_Static_Object virtual slot stubs for dispatch
// Slots used: 48 (0xC0) and 49 (0xC4)
class RGE_Static_Object {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual void d3(); virtual void d4(); virtual void d5();
    virtual void d6(); virtual void d7(); virtual void d8();
    virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17();
    virtual void d18(); virtual void d19(); virtual void d20();
    virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26();
    virtual void d27(); virtual void d28(); virtual void d29();
    virtual void d30(); virtual void d31(); virtual void d32();
    virtual void d33(); virtual void d34(); virtual void d35();
    virtual void d36(); virtual void d37(); virtual void d38();
    virtual void d39(); virtual void d40(); virtual void d41();
    virtual void d42(); virtual void d43(); virtual void d44();
    virtual void d45(); virtual void d46(); virtual void d47();
    virtual void vfn48(void* obj, short action_type, int flag);  // slot 48, offset 0xC0
    virtual void vfn49(void* obj);  // slot 49, offset 0xC4

    int id;  // +0x04
};

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    char gap_06[2];
    void* obj;
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    void set_target_obj2(RGE_Static_Object* target);
};

// RGE_Game_World::object(id) — call at 0x00545D30h
// Accessed via obj->field_0C->field_3C
class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

// Helper to get game world from obj
// obj->field_0C is at offset 0x0C, that struct has game_world at offset 0x3C
inline RGE_Game_World* get_game_world(void* obj) {
    return *(RGE_Game_World**)(*(int*)((char*)obj + 0x0C) + 0x3C);
}

void RGE_Action::set_target_obj2(RGE_Static_Object* target)
{
    // Clean up old target_obj2 if different from new
    if (this->target_obj2 && this->target_obj2 != target) {
        RGE_Game_World* world = get_game_world(this->obj);
        RGE_Static_Object* old_target = world->object(this->target2ID);
        if (old_target) {
            old_target->vfn49(this->obj);
        }
    }

    if (this->target_obj2 != target) {
        this->target_obj2 = target;
        if (target) {
            this->target2ID = *(int*)((char*)target + 4);
            target->vfn48(this->obj, this->action_type, 0);
        } else {
            this->target2ID = -1;
        }
    }
}
