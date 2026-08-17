// VA: 00404A90 update
// PDB source: ACT_make.cpp lines 61-98
// RGE_Action_Make::update() (277 bytes)
//
// The natural source now uses direct typed member expressions in the fatal
// guard. This matches the body blocks and reduces the positional diff to 41.
// The rebuilt function is 280 bytes, with the original size at 277 bytes.
//
// Original entry saves ESI, reads state, then saves EDI, EBP, and EBX only on
// the non-state-1 path. VC5 saves EBX, EBP, ESI, and EDI at entry in isolation.
// The remaining mismatch is this path-split callee-save sequence and its tails.
// The direct source still gives ESI=this, EDI=target, EBX=inner1, and
// EBP=game-vtable. Its body blocks at +001E..+0104 are exact.
//
// Tested in this pass: split work-product initialization, positive fatal guard,
// switch case order, explicit default, narrow base surface, flattened object
// inheritance, case scope, game_globals.h context, and debug-context flags.
// None changed the 41-byte result. A 128-sample ambient declaration sweep also
// kept the old 182-byte alias result. Keep the direct-member source as clean.

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
            if (this->obj->owner->attributes[0x24] > 0.0) {
                if (this->obj->attribute_amount_held <= 0.0) {
                    rge_base_game->notification(
                        0x7E, this->obj->owner->id, this->obj->id,
                        (int)this->obj->world_x, (int)this->obj->world_y);
                    this->obj->die_die_die();
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
