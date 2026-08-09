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
// Current reconstruction: RGE_Action_Object/RGE_Static_Object ownership and
// owner/task virtual ABIs are canonical; probe 9's scoped guard aliases preserve
// the best 277-byte codegen basin. Direct guard expressions (probe 10) worsened
// size and scheduling, so they were rolled back.
// Main-agent audit restored canonical destructor slots and a symbol-backed game
// global; the validated prologue/register-allocation blocker remains.

#include "..\..\include\game_globals.h"

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0xE0];
    float attribute_amount;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float attribute_modifier;
};

class RGE_Player {
public:
    virtual ~RGE_Player(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74();
    virtual void add_attribute_num(short, float, unsigned char);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x04];
    float* attributes;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68();
    virtual void die_die_die();
    virtual void v70(); virtual void v74(); virtual void v78();
    virtual void v7C(); virtual void v80();
    virtual void set_attribute_amount(float, unsigned char, unsigned char);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    void* sprite;
    char gap_14[0x24];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    float hit_points;
};

class RGE_Task {
public:
    char gap_00[0x14];
    short attribute_id;
    char gap_16[0x06];
    float work_range;
    char gap_20[0x10];
    short attribute_mode;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void notification(int, long, long, long, long);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int v04(RGE_Action_Object*);
    virtual int v08(int, RGE_Action_Object*);
    virtual void* v0C(RGE_Action_Object*);
    virtual void v10(); virtual void v14(int); virtual short v18();
    virtual void v1C(unsigned char); virtual unsigned char v20();
    virtual unsigned char v24(); virtual unsigned char v28(); virtual int v2C();
    virtual int v30(RGE_Static_Object*, float, float, float);
    virtual int v34(RGE_Static_Object*, float, float, float);
    virtual unsigned char v38(RGE_Static_Object*);
    virtual unsigned char v3C(long, unsigned char);
    virtual void v40(void*); virtual void v44(void*, void*, void*);
    virtual void v48(char*); virtual RGE_Static_Object* v4C();
    virtual RGE_Static_Object* v50(); virtual void v54(RGE_Static_Object*);
    virtual void v58(RGE_Static_Object*); virtual void set_state(unsigned char);

    unsigned short action_type;
    unsigned short gap_06;
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x03];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int target_id;
    int target2_id;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
};

class RGE_Action_Make : public RGE_Action {
public:
    virtual unsigned char update();
};

unsigned char RGE_Action_Make::update() {
    switch (this->state) {
    case 6:
        if (this->timer <= 0.0) {
            RGE_Action_Object* obj = this->obj;
            RGE_Player* owner = obj->owner;
            if (owner->attributes[0x24] > 0.0) {
                if (obj->hit_points <= 0.0) {
                    rge_base_game->notification(
                        0x7E, owner->id, obj->id,
                        (int)obj->world_x, (int)obj->world_y);
                    obj->die_die_die();
                }
                return 0;
            }
        }

        {
            float work = this->obj->owner->world->attribute_modifier
                       * this->obj->master_obj->attribute_amount;
            work *= this->task->work_range;
            float old_hit_points = this->obj->hit_points;

            if (this->task->attribute_mode != 0) {
                this->obj->owner->add_attribute_num(
                    this->task->attribute_id, work, 0);
            } else {
                this->obj->set_attribute_amount(work, 1, 1);
            }
            this->timer -= this->obj->hit_points - old_hit_points;
        }
        break;

    case 1:
        return 1;
    }
    return 0;
}
