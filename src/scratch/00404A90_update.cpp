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
// Follow-up follow-404A90-r1: split notification coordinate casts into natural
// locals to test call evaluation order; codegen stayed unchanged at 277/182,
// so the probe was rolled back.
//
// Session sa-ce4cd6c0-r1 (10 meaningful probes, 2026-08-11):
// - absolute and volatile game-global forms did not reproduce a reload or
//   change the prologue; restored the ordinary symbol-backed declaration;
// - restored period field ownership (work_rate, world_time_delta_seconds,
//   work_val1/work_flag, attribute_amount_held) and full proven object sizes;
//   output remained unchanged, but this is the cleaner living reconstruction;
// - register-qualified self, header removal, natural if/guard state flow, and
//   a named state snapshot all failed to move the EDI=this / eager-save basin;
// - current source is restored to the switch/direct-state 277-byte basin:
//   exact size/frame/call set, 182 positional bytes differ from the oracle;
//   remaining blocker is staged callee-save/register coloring at byte +5.
// Session sat-404A90-order restored master-first work_rate * world_delta;
// output stayed at 277 bytes / 182-byte diff. A temporary ACT_make.cpp TU
// context from exact donors 00404A10, 00404A40, and 00404A70 was codegen-neutral.

class RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Action_Object();
    char gap_04[0xE0];
    float work_rate;
    char gap_E8[0x14];
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float world_time_delta_seconds;
    char gap_88[0x7C];
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
    char gap_54[0x1CC];
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
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    void* player_object_node;
    char pathingGroupMembers[0x10];
    char groupMembers[0x10];
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char gap_87;
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    char gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    unsigned char waiting;
    char gap_181[0x03];
    void* actions;
    unsigned char command_flag;
    char gap_189[0x03];
    int lastActionValue;
    int lastActionStateValue;
};

class RGE_Task {
public:
    char gap_00[0x14];
    short attribute_type;
    char gap_16[0x06];
    float work_val1;
    char gap_20[0x10];
    short work_flag;
    char gap_32[0x1A];
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
    void* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    char gap_3D[0x03];
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
                if (obj->attribute_amount_held <= 0.0) {
                    rge_base_game->notification(
                        0x7E, owner->id, obj->id,
                        (int)obj->world_x, (int)obj->world_y);
                    obj->die_die_die();
                }
                return 0;
            }
        }

        {
            float work = this->obj->master_obj->work_rate
                       * this->obj->owner->world->world_time_delta_seconds;
            work *= this->task->work_val1;
            float old_attribute_amount = this->obj->attribute_amount_held;

            if (this->task->work_flag != 0) {
                this->obj->owner->add_attribute_num(
                    this->task->attribute_type, work, 0);
            } else {
                this->obj->set_attribute_amount(work, 1, 1);
            }
            this->timer -= this->obj->attribute_amount_held - old_attribute_amount;
        }

        break;

    case 1:
        return 1;
    }
    return 0;
}
