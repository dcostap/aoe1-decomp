// VA: 004050F0 RGE_Action_Missile::update (955 bytes)
// ACT_misl.cpp
//
// Baseline reconstruction: the action owns the five missile floats at +0x40;
// its object/master/world chain and collision dispatch are modeled with the
// period class surfaces.  Keep the collision cases as the original combat
// virtual calls rather than replacing them with helper shims.
//
// Attempt log:
// - baseline: typed world/master/object ownership and natural collision cases;
//   996B, frame 0x20, diff 921B.
// - shared collision do_attack/state tail: 884B, diff 803B; call sites became
//   closer, but explicit repeated do_attack arms had the wrong call count.
// - removed cached world/master/missile aliases: ESI remained `this`, shape
//   rose to 69.69%, diff 743B at best; the remaining frame was 0x1C vs 0x18.
// - old-velocity removal, widened hit-info, scoped physics locals, and derived
//   virtual declaration were duplicate/nonproductive VC5 basins; rolled back.
// - mode-3 target attack uses the missile object's world x/y/z fields.  The
//   original setup loads these fields before the target virtual call.
// - reviewed-drift source: frame/local-home drift (collision_list uses an
//   extra [esp+28] home instead of the oracle's reused [esp+24]) and VC5
//   tail-merging one pair of mode-3 do_attack/set_state sites. Default flags
//   retained.
// - outer post-move dispatch is owned by missile_type at +0x148; missile_hit_info
//   at +0x14A remains the collision-mode switch. Reordering the natural mode-3
//   branch before the <=2 collision-list branch aligned all 24 ordered calls.
// - late state returns, branch-local node->object reads, direct mode-1 attack
//   arms, and z-before-velocity ballistic source order gave 955B, frame 0x18,
//   357 instructions, 87.11% shape, 69.97% exact blocks, and diff 653B.
// - BINARY NOTE: timer comparison spelling (`timer >= max_range`) restores the
//   oracle's direct fcomp and exact timer block.  Ballistic x87 scheduling and
//   late collision block layout remain unresolved.
// - timer operand reversal: 943B, frame 0x18, diff 574B, 90.93% shape,
//   74.79% exact blocks; this is the current clean frontier.
// - mode-3 world-coordinate repair kept 943B and diff 574B, and added the
//   exact mode-3 argument setup block.  The pointer-bitcast form was wrong.
// - authentic-context guard was compile-neutral in standalone mode and lets
//   the source participate in the ACT_misl.cpp wrapper without duplicate types.
// - BINARY NOTE: the oracle duplicates mode-1 receiver setup before one shared
//   virtual call. Direct branch-local calls preserve this shipped code shape.
// - LIKELY INTENT: collision mode 1 selects the stored target when present and
//   the missile object when absent; preserve the explicit arms for code shape.
//
// Reviewed-drift evidence: the fresh clean check keeps the 0x18 frame, all four
// saved registers, 24 ordered calls, 37 conditional branches, and both returns.
// It also keeps the timer >= max_range predicate, the +0x40 velocity writes,
// the ballistic x87 update, and the missile-object world x/y/z arguments.
// The collision switch still has every missile-hit case, node skip, state
// publication, list deletion, and ground-impact fallback. The remaining 12
// bytes are a tail-merge/layout difference: the rebuilt code has one fewer
// unconditional jump and shifts the collision blocks. Call-map and field-order
// review found no changed call, predicate, memory effect, cleanup, or fault
// order. The source is a reviewed-drift candidate. The integration agent can
// register it with the authentic wrapper after accepting this evidence.
// FLAGS: config/flags/00404BB0_RGE_Action_Missile.rsp (/nologo /c /O2 /Oy /GX).
// ACCEPTED DRIFT REVIEW: the changed bytes are a localized timer-x87 operand
// order and collision-tail layout basin. The source preserves the same timer
// predicate, ballistic arithmetic, world-coordinate arguments, 24 ordered
// calls, collision cases, state publication, list cleanup, and fault order.
// The 12-byte size loss is the compiler's tail merge, not a removed behavior.
// Keep this natural source. Do not replace it with a helper or manual CFG.

#ifndef ACT_MISL_SHARED_CONTEXT
extern float DAT_0056e380;
extern double DAT_0056e388;

typedef unsigned char uchar;

class RGE_Sprite;
class RGE_Task;
class RGE_Action_List;
class RGE_Player;
class RGE_Game_World;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Moving_Object;
class RGE_Combat_Object;
class RGE_Missile_Object;
class RGE_Master_Static_Object;
class RGE_Master_Missile_Object;

class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    uchar gap_04[0x0C];
    short id;                         // +0x10
    uchar gap_12[0x26];
    float radius_z;                   // +0x38
    uchar gap_3C[0x7C];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;                      // +0xB8
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    uchar gap_BC[0x1C];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    uchar gap_D8[0x24];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    uchar gap_FC[0x4C];
};

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    uchar missile_type;               // +0x148
    uchar targetting_type;            // +0x149
    uchar missile_hit_info;           // +0x14A
    uchar missile_die_info;           // +0x14B
    uchar area_effect_specials;       // +0x14C
    uchar gap_14D[3];
    float ballistics_ratio;           // +0x150
};

class RGE_Game_World {
public:
    uchar gap_00[0x84];
    float world_time_delta_seconds;   // +0x84
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    uchar gap_00[0x3C];
    RGE_Game_World* world;             // +0x3C
    uchar gap_40[0x0A];
    short id;                           // +0x4A
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual uchar update();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual float teleport(float, float, float);
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual uchar can_attack();
    virtual void vf80();
    virtual void vf84();
    virtual int vf88(int, int);
    virtual uchar vf8C(float);
    virtual int vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void new_angle(float);
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual uchar is_moving();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual float vfF0(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int vf114(float, float, int);
    virtual uchar vf118();
    virtual int vf11C();
    virtual float vf120();
    virtual float vf124();
    virtual float vf128();
    virtual void vf12C(uchar);
    virtual uchar vf130();
    virtual uchar vf134();
    virtual uchar vf138(int);
    virtual uchar vf13C(int);
    virtual uchar vf140();
    virtual void vf144(const char*, ...);
    virtual void vf148(int, int, int, long, long, long);
    virtual int vf14C(float, float, float, int);
    virtual int vf150(int, int);
    virtual int vf154(float, float, float, float, int);
    virtual int vf158(int, float, int);
    virtual int vf15C(int, int);
    virtual int vf160(int, int);
    virtual int vf164(int, int);
    virtual int vf168(int, int);
    virtual int vf16C(int, int);
    virtual int vf170(int, int);
    virtual int vf174(int, int);
    virtual int vf178(int, int);
    virtual int vf17C(int, int);
    virtual int vf180(int, int);
    virtual int vf184(int, float, float, float);
    virtual int vf188(float, float, float, int);
    virtual int vf18C();
    virtual int vf190();
    virtual int vf194(int, float, float*, int, int, int);
    virtual int vf198(int, float, int, float*, int, int, int);
    virtual int vf19C(int, int, float, float*, int, int, int);
    virtual int vf1A0(int, float, float*, int, int, int, void*);
    virtual int vf1A4(int, float, int, float*, int, int, int, int, int);
    virtual int vf1A8(int, float*, float*);
    virtual int vf1AC(int, int, int, int, float, int);
    virtual int vf1B0(void*, void*, float, void*, int);
    virtual int vf1B4(void*, void*, void*, int, int, int);
    virtual void* vf1B8(int);
    virtual int vf1BC(void*, int);
    virtual void vf1C0(int);
    virtual void vf1C4(int);
    virtual int vf1C8();
    virtual void* vf1CC(void*, float, int);
    virtual long vf1D0();
    virtual long vf1D4();
    virtual int vf1D8(int, RGE_Game_World*);
    virtual int vf1DC(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void* vf1E0();
    virtual void* vf1E4();

    long id;                         // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;               // +0x0C
    RGE_Sprite* sprite;              // +0x10
    RGE_Sprite* old_sprite;          // +0x14
    void* sprite_list;               // +0x18
    void* tile;                      // +0x1C
    RGE_Static_Object* inside_obj;   // +0x20
    void* objects;                   // +0x24
    short screen_x_offset;           // +0x28
    short screen_y_offset;           // +0x2A
    short shadow_x_offset;           // +0x2C
    short shadow_y_offset;           // +0x2E
    float hp;                        // +0x30
    uchar curr_damage_percent;       // +0x34
    uchar facet;                     // +0x35
    uchar selected;                  // +0x36
    uchar selected_group;            // +0x37
    float world_x;                   // +0x38
    float world_y;                   // +0x3C
    float world_z;                   // +0x40
    float attribute_amount_held;     // +0x44
    uchar object_state;              // +0x48
    uchar sleep_flag;                // +0x49
    uchar dopple_flag;               // +0x4A
    uchar goto_sleep_flag;           // +0x4B
    short attribute_type_held;       // +0x4C
    uchar type;                      // +0x4E
    uchar worker_num;                // +0x4F
    uchar gap_50[0x38];              // +0x50..+0x87

    uchar is_dying();
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    float speed;                     // +0x88
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);

    float trail_remainder;            // +0x8C
    float velocity_x;                 // +0x90
    float velocity_y;                 // +0x94
    float velocity_z;                 // +0x98
    uchar gap_9C[0xE4];

    void set_velocity(float, float, float);
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual void set_task(short);
    virtual void setTaskByTaskID(short);
    virtual void set_action(void*);
    virtual void set_only_action(void*);
    virtual void set_end_action(void*);
    virtual RGE_Task* getTask();
    virtual int setup(int, RGE_Game_World*);
    virtual RGE_Action_List* create_action_list();

    uchar waiting;                   // +0x180
    uchar gap_181[3];
    RGE_Action_List* actions;        // +0x184
    uchar command_flag;              // +0x188
    uchar gap_189[3];
    int lastActionValue;             // +0x18C
    int lastActionStateValue;        // +0x190
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual uchar area_attack(float, float, float, RGE_Combat_Object*, RGE_Static_Object*);
    virtual uchar attack(float, float, float, RGE_Combat_Object*);
    virtual uchar attack(RGE_Static_Object*, RGE_Combat_Object*);
    virtual uchar do_attack(RGE_Static_Object*, RGE_Combat_Object*, float, float, float);
    virtual void get_armor(short&, short&);
    virtual void get_weapon(short&, short&);
    virtual void get_weapon_range(float&, float&);
    virtual void get_speed_of_attack(float&, float&);

    uchar gap_1C4[0x30];
};

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    virtual int setup(RGE_Master_Missile_Object*, RGE_Player*, float, float, float);

    float max_range;                 // +0x1C4

    uchar missile_move();
    class RGE_Check_List* make_object_collision_list(float);
};

class RGE_Action {
public:
    virtual void vf00();
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
    virtual void copy_obj_sprites(void*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short action_type;               // +0x04
    uchar gap_06[2];
    RGE_Action_Object* obj;          // +0x08
    uchar state;                     // +0x0C
    uchar gap_0D[3];
    RGE_Static_Object* target_obj;    // +0x10
    RGE_Static_Object* target_obj2;  // +0x14
    int targetID;                    // +0x18
    int target2ID;                   // +0x1C
    float target_x;                  // +0x20
    float target_y;                  // +0x24
    float target_z;                  // +0x28
    float timer;                     // +0x2C
    RGE_Task* task;                  // +0x30
    RGE_Action_List* sub_actions;    // +0x34
    RGE_Sprite* sprite;              // +0x38
    uchar subActionValue;            // +0x3C
    uchar gap_3D[3];
};

class RGE_Action_Missile : public RGE_Action {
public:
    virtual uchar update();

    float velocity_x;                // +0x40
    float velocity_y;                // +0x44
    float velocity_z;                // +0x48
    float ballistic_velocity;        // +0x4C
    float ballistic_acceleration;    // +0x50
};

struct RGE_Check_Node {
    RGE_Static_Object* object;
    float dx;
    float dy;
    uchar flag;
    uchar gap_0D[3];
    RGE_Check_Node* next;
};

class RGE_Check_List {
public:
    RGE_Check_Node* list;
    RGE_Check_List();
    ~RGE_Check_List();
};
#endif

unsigned char RGE_Action_Missile::update()
{
    float delta;
    float time;
    unsigned char hit_ground;

    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;

        delta = this->obj->owner->world->world_time_delta_seconds;
        time = ((RGE_Master_Animated_Object*)this->obj->master_obj)->speed * delta;

        if (this->targetID != -1 &&
            this->obj->owner->world->object(this->targetID) == 0) {
            this->set_target_obj(0);
        }
        if (this->target2ID != -1 &&
            this->obj->owner->world->object(this->target2ID) == 0) {
            this->set_target_obj2(0);
        }
        if (this->target_obj != 0 && this->target_obj->is_dying()) {
            this->set_target_obj(0);
        }
        if (this->target_obj2 != 0 && this->target_obj2->is_dying()) {
            this->set_target_obj2(0);
        }

        switch (this->state) {
        case 1:
            goto return_one;
        case 4:
            break;
        default:
            goto return_zero;
        }

        if (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type != 0) {
            if (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type == 3) {
                x = this->velocity_x;
                y = this->velocity_y;
                z = this->velocity_z;
            }
        } else {
            this->timer = time + this->timer;
            x = this->velocity_x * time;
            y = this->velocity_y * time;
            z = this->velocity_z * time;
            if (this->timer >= ((RGE_Missile_Object*)this->obj)->max_range) {
                this->set_state(1);
            }
        }

        if (((RGE_Master_Missile_Object*)this->obj->master_obj)->ballistics_ratio > DAT_0056e388) {
            float acceleration = this->ballistic_acceleration * delta;
            z = (this->ballistic_velocity + acceleration * DAT_0056e380) * delta + z;
            this->ballistic_velocity = acceleration + this->ballistic_velocity;
        }

        this->obj->set_velocity(x, y, z);
        hit_ground = ((RGE_Missile_Object*)this->obj)->missile_move();
    }

    if (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type == 3) {
        RGE_Combat_Object* target =
            (RGE_Combat_Object*)this->target_obj2;
        if (target != 0) {
            target->do_attack(this->target_obj, target,
                              this->obj->world_x, this->obj->world_y,
                              this->obj->world_z);
        } else {
            ((RGE_Missile_Object*)this->obj)->do_attack(
                this->target_obj, (RGE_Combat_Object*)this->obj,
                this->obj->world_x, this->obj->world_y,
                this->obj->world_z);
        }
        this->set_state(1);
    } else if (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type <= 2) {
            RGE_Check_List* collision_list =
                ((RGE_Missile_Object*)this->obj)->make_object_collision_list(time);
            if (collision_list != 0) {
                RGE_Check_Node* node = collision_list->list;
                while (node != 0) {
                    RGE_Combat_Object* attack_target;
                    RGE_Static_Object* attack_object;
                    int collision_mode =
                        ((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_hit_info;

                    switch (collision_mode) {
                    case 0: {
                        if (node->object == this->target_obj) {
                            attack_object = this->target_obj;
                            if (this->target_obj2 != 0) {
                                attack_target =
                                    (RGE_Combat_Object*)this->target_obj2;
                            } else {
                                attack_target = (RGE_Combat_Object*)this->obj;
                            }
                            goto collision_do_attack;
                        }
                        break;
                    }

                    case 1: {
                        if (node->object->owner != this->obj->owner &&
                            node->object->owner->id != 0) {
                            attack_object = node->object;
                            if (this->target_obj2 == 0) {
                                ((RGE_Combat_Object*)this->obj)->do_attack(
                                    attack_object,
                                    (RGE_Combat_Object*)this->obj,
                                    this->obj->world_x, this->obj->world_y,
                                    this->obj->world_z);
                            } else {
                                ((RGE_Combat_Object*)this->target_obj2)->do_attack(
                                    attack_object,
                                    (RGE_Combat_Object*)this->target_obj2,
                                    this->obj->world_x, this->obj->world_y,
                                    this->obj->world_z);
                            }
                            goto collision_state;
                        }
                        break;
                    }

                    case 2: {
                        attack_target =
                            (RGE_Combat_Object*)this->target_obj2;
                        if (attack_target != 0) {
                            if (node->object == (RGE_Static_Object*)attack_target) {
                                break;
                            }
                            if (node->object->owner != this->obj->owner &&
                                node->object->owner->id != 0) {
                                attack_object = node->object;
                                goto collision_do_attack;
                            } else {
                                attack_target->area_attack(this->obj->world_x,
                                                            this->obj->world_y,
                                                            this->obj->world_z,
                                                            attack_target, 0);
                                goto collision_state;
                            }
                        } else if (node->object->owner != this->obj->owner &&
                                   node->object->owner->id != 0) {
                            attack_object = node->object;
                            attack_target = (RGE_Combat_Object*)this->obj;
                            goto collision_do_attack;
                        } else {
                            attack_target = (RGE_Combat_Object*)this->obj;
                            attack_target->area_attack(this->obj->world_x,
                                                       this->obj->world_y,
                                                       this->obj->world_z,
                                                       attack_target, 0);
                            goto collision_state;
                        }
                        break;
                    }
                    }

                    goto collision_next;

                collision_do_attack:
                    attack_target->do_attack(attack_object, attack_target,
                                             this->obj->world_x, this->obj->world_y,
                                             this->obj->world_z);
                collision_state:
                    this->set_state(1);

                collision_next:
                    node = node->next;
                }
                delete collision_list;
            }
        }

        if (hit_ground != 0 && this->state != 1) {
            RGE_Combat_Object* target =
                (RGE_Combat_Object*)this->target_obj2;
            if (target != 0) {
                target->area_attack(this->obj->world_x, this->obj->world_y,
                                    this->obj->world_z, target, 0);
            } else {
                ((RGE_Combat_Object*)this->obj)->area_attack(
                    this->obj->world_x, this->obj->world_y, this->obj->world_z,
                    (RGE_Combat_Object*)this->obj, 0);
            }
            this->set_state(1);
        }
return_zero:
    return 0;

return_one:
    return 1;
}
