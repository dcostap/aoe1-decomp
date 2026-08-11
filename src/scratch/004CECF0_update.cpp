// 004CECF0 TRIBE_Action_Heal::update
// Source: tact_hea.cpp lines 175-365
// Size: 739 bytes, no EH
//
// Attempt log:
// Probe 1 (baseline): restored the period typed action/static-object/player/world
// surfaces, the target/task/master ownership, and the two natural nested switches.
// The previous scratch file was only an old metric note; this is the clean source
// reconstruction before codegen probes.
// Probe 2: combined shared transition labels and one expression rewrite moved the
// compiler into an EBX-framed 824-byte basin; rolled back.
// Probe 3: separating the target-state invalid guard from the ally guard preserved
// the binary's redundant target null test and improved the source to 840 bytes.
// Probe 4: the same guard plus a shared state-D tail reached 739 bytes and the
// current best 92.16% shape; the remaining gap is switch-table/block placement.
// Probes 5-8: state-D/early/state-6 label permutations and the derived set_state
// declaration did not improve the emitted basin; retained the best labeled CFG.
// Probes 9-10: the effective TU view must expose the float heal call at vslot
// +0x8C; hiding the unused int overload from this local surface changes the call
// from +0x88 to +0x8C without changing behavior or size.
// Probe 11: a separate declaration-only state view did not prevent VC5 tail
// merging; removed from the living source after recording the negative result.
// Best current check: 739-byte output, 469 positional diff bytes, 26/27 calls;
// remaining structural gap is one merged +0x5C state-3 call and local switch data
// placement. Leave in scratch for a later worker rather than forcing a match.

extern float DAT_005750e0;
extern double DAT_005750e8;

typedef unsigned char uchar;

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Game_World;
class RGE_Player;
class RGE_Master_Action_Object;
class RGE_Task;
class RGE_Sprite;

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float world_time_delta_seconds;             // +0x84

    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    VPAD4(1)
    VPAD2(5)
    virtual int isAlly(int player_id);          // +0x1C

    char gap_04[0x38];
    RGE_Game_World* world;                      // +0x3C
    char gap_40[0x08];
    uchar type;                                  // +0x48
    uchar gap_49;
    short id;                                    // +0x4A
    char gap_4C[4];
    float* attributes;                           // +0x50
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xE4];
    float work_rate;                             // +0xE4
};

class RGE_Sprite {
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD16(1)
    VPAD8(17)
    VPAD4(25)
    VPAD2(29)
    virtual uchar can_attack();                  // +0x7C
    virtual void vf80();                         // +0x80
    virtual void vf84();                         // +0x84
    virtual int heal_int(int, int);              // +0x88
    virtual uchar heal(float);                   // +0x8C
    VPAD4(36)
    VPAD16(40)
    VPAD16(56)
    VPAD8(72)
    VPAD2(80)
    virtual void notify(int, int, int, int, int, int); // +0x148

    long id;                                     // +0x04
    RGE_Master_Action_Object* master_obj;       // +0x08
    RGE_Player* owner;                           // +0x0C
    RGE_Sprite* sprite;                          // +0x10
    RGE_Sprite* old_sprite;                      // +0x14
    void* sprite_list;                           // +0x18
    void* tile;                                  // +0x1C
    RGE_Static_Object* inside_obj;               // +0x20
    void* objects;                               // +0x24
    short screen_x_offset;                       // +0x28
    short screen_y_offset;                       // +0x2A
    short shadow_x_offset;                       // +0x2C
    short shadow_y_offset;                       // +0x2E
    float hp;                                    // +0x30
    uchar curr_damage_percent;                   // +0x34
    uchar facet;                                 // +0x35
    uchar selected;                              // +0x36
    uchar selected_group;                        // +0x37
    float world_x;                               // +0x38
    float world_y;                               // +0x3C
    float world_z;                               // +0x40
    float attribute_amount_held;                 // +0x44
    uchar object_state;                          // +0x48

    float distance_to_object(RGE_Static_Object* other);
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual void vf14C(); virtual void vf150(); virtual void vf154();
    virtual void vf158(); virtual void vf15C(); virtual void vf160();
    virtual void vf164(); virtual void vf168(); virtual void vf16C();
    virtual void vf170(); virtual void vf174(); virtual void vf178();
    virtual void vf17C(); virtual void vf180(); virtual void vf184();
    virtual void vf188(); virtual void vf18C(); virtual void vf190();
    virtual void vf194(); virtual void vf198(); virtual void vf19C();
    virtual void vf1A0(); virtual void vf1A4(); virtual void vf1A8();
    virtual void vf1AC(); virtual void vf1B0(); virtual void vf1B4();
    virtual void vf1B8(); virtual void vf1BC(); virtual void vf1C0();
    virtual void vf1C4(); virtual void vf1C8(); virtual void vf1CC();
    virtual void vf1D0(); virtual void vf1D4(); virtual void vf1D8();
    virtual void vf1DC(); virtual void vf1E0(); virtual void vf1E4();
    virtual void vf1E8(); virtual void vf1EC();
    virtual uchar can_attack(RGE_Static_Object*, int, int); // +0x1F0
};

class RGE_Action_List {
public:
    virtual RGE_Action_Object* create_action(int, short);
    virtual RGE_Action_Object* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual uchar inside_obj_update();
    virtual uchar update();                         // +0x0C

    RGE_Action_Object* obj;
    void* list;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(uchar);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual uchar attack_response(RGE_Static_Object*);
    virtual uchar relation_response(long, uchar);
    virtual void copy_obj(void*);
    virtual void copy_obj_sprites(void*, void*, void*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short action_type;                             // +0x04
    char gap_06[2];
    RGE_Action_Object* obj;                       // +0x08
    uchar state;                                   // +0x0C
    char gap_0D[3];
    RGE_Static_Object* target_obj;                // +0x10
    RGE_Static_Object* target_obj2;               // +0x14
    int targetID;                                  // +0x18
    int target2ID;                                // +0x1C
    float target_x;                                // +0x20
    float target_y;                                // +0x24
    float target_z;                                // +0x28
    float timer;                                   // +0x2C
    RGE_Task* task;                                // +0x30
    RGE_Action_List* sub_actions;                 // +0x34
    RGE_Sprite* sprite;                            // +0x38
    uchar subActionValue;                          // +0x3C
    char gap_3D[3];
};

class RGE_Task {
public:
    char gap_00[0x14];
    short attribute_type;                          // +0x14
    char gap_16[6];
    float work_rate;                               // +0x1C
    char gap_20[4];
    float range;                                   // +0x24
    char gap_28[0x0C];
    RGE_Sprite* move_sprite;                       // +0x34
    RGE_Sprite* work_sprite;                       // +0x38
    RGE_Sprite* work_sprite2;                      // +0x3C
    RGE_Sprite* carry_sprite;                      // +0x40
    void* work_sound;                              // +0x44
};

class TRIBE_Action_Heal : public RGE_Action {
public:
    virtual void set_state(uchar);
    virtual uchar update();
};

uchar TRIBE_Action_Heal::update()
{
    float work;

    if (this->targetID != -1 &&
        this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
        this->set_state(3);
        return 0;
    }

    if (this->target2ID != -1 &&
        this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state != 2) {
        this->set_target_obj(0);
        this->set_state(3);
        return 0;
    }

    if (this->target_obj != 0 &&
        this->obj->owner->isAlly(this->target_obj->owner->id) == 0) {
        this->set_state(1);
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1FB, 0x25B, 0, 0);
        return 4;
    }

    switch (this->state) {
    case 4:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 5:
            goto state_early;
        case 3:
            goto state_done;
        case 4:
            this->set_target_obj(0);
            this->set_state(0x0B);
            return 0;
        default:
            break;
        }
        break;

state_early:
        this->set_state(3);
        return 0;

    case 0x0B:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
            goto state_ready;
        case 3:
            goto state_done;
        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(0x0B);
            return 0;
        default:
            break;
        }
        break;

state_done:
        this->set_state(0x0D);
        return 0;

state_ready:
        this->set_state(6);
        return 0;

    case 6:
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        if (this->obj->can_attack(this->target_obj, 0, 0) != 0) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }

        if (this->target_obj->world_x != this->target_x ||
            this->target_y != this->target_obj->world_y) {
            float distance = this->obj->distance_to_object(this->target_obj);
            if (this->task->range < distance && DAT_005750e8 < distance) {
                this->set_state(3);
                return 0;
            }
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
            return 0;
        }

        work = this->task->work_rate * this->obj->master_obj->work_rate;
        work *= this->obj->owner->world->world_time_delta_seconds;
        if (this->obj->owner->attributes[0x38] > DAT_005750e0) {
            work *= this->obj->owner->attributes[0x38];
        }

        uchar result = this->target_obj->heal(work);
        if (result == 1) {
            this->set_state(3);
            return 0;
        }
        if (result == 2) {
            this->obj->notify(this->obj->id, this->obj->id,
                              0x1FB, 0x25B, 0, 0);
            this->set_state(2);
            return 0;
        }
        break;
    }

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1F9, 0x25B, 0, 0);
        this->set_state(2);
        return 3;
    }

    return 0;
}

#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1
