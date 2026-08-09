// 00401780 RGE_Action_Attack::update
// PDB source: Act_atak.cpp:409-704
//
// Canonical typed reconstruction.  The executable uses the inherited action,
// static-object, player, active-sprite-list, and combat-object surfaces below;
// the virtual padding preserves their proven slots without raw vtable calls.
//
// Attempt log:
// - Replaced the prior raw-offset/hand-cast-vtable source with a natural typed
//   action/static/player/world/sprite-list/combat surface and state switch.
// - Corrected static-object notify slot (+0x148), player id (+0x4A), and the
//   byte-width state-2 return; these are binary-backed layout/width facts.
// - Removing long-lived object/target aliases recovered the original two-register
//   prologue and exact-size frontier: 592 positional bytes, 81.88% shape,
//   60.82% exact-block coverage; call set remains one virtual-state-site short.
// - A positive-arm notification-tail spelling was tested and rolled back because
//   it added 66 bytes and worsened topology.  Keep this simpler natural source.
// - Binary-backed local goto/case-order probes improved one branch or call-order
//   metric in isolation (best local ally return: 571 bytes, best late case order:
//   93.55% call alignment) but introduced broad size/tail drift; all were rolled
//   back as compiler-steering diagnostics.
// - Explicit global target-notify tails and case-4-first handler permutations
//   remained structurally worse despite better call-site alignment. The clean
//   canonical switch is retained.
// Remaining lead: align the nested action-list switch/case placement and the
//   shared ally/inside-target notification tails; do not restore raw scaffolding.
// Main-agent audit restored canonical world/action destructor ownership;
// typed state-machine ownership remains authoritative.

typedef unsigned char uchar;

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Combat_Object;
class RGE_Game_World;
class RGE_Master_Action_Object;
class RGE_Player;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Active_Sprite_List;
class RGE_Tile;
class RGE_Object_List;

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class RGE_Sprite {
public:
    char gap_00[0x5E];
    short frame;
    char gap_60[0x10];
    uchar flags;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD16(1)
    VPAD8(17)
    VPAD4(25)
    VPAD2(29)
    virtual uchar can_attack();                 // +0x7C
    VPAD16(32)
    VPAD16(48)
    VPAD16(64)
    VPAD2(80)
    virtual void notify(int, int, int, long, long, long); // +0x148

    long id;                                    // +0x04
    RGE_Master_Action_Object* master_obj;      // +0x08
    RGE_Player* owner;                          // +0x0C
    RGE_Sprite* sprite;                         // +0x10
    RGE_Sprite* old_sprite;                     // +0x14
    RGE_Active_Sprite_List* sprite_list;       // +0x18
    RGE_Tile* tile;                             // +0x1C
    RGE_Static_Object* inside_obj;              // +0x20
    RGE_Object_List* objects;                   // +0x24
    short screen_x_offset;                      // +0x28
    short screen_y_offset;                      // +0x2A
    short shadow_x_offset;                      // +0x2C
    short shadow_y_offset;                      // +0x2E
    float hp;                                   // +0x30
    uchar curr_damage_percent;                 // +0x34
    uchar facet;                               // +0x35
    uchar selected;                            // +0x36
    uchar selected_group;                      // +0x37
    float world_x;                              // +0x38
    float world_y;                              // +0x3C
    float world_z;                              // +0x40
    float attribute_amount_held;                // +0x44
    uchar object_state;                         // +0x48
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    void reset_attack_timer();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    VPAD4(1)
    VPAD2(5)
    virtual int isAlly(int);                    // +0x1C

    char gap_04[0x38];
    RGE_Game_World* world;                      // +0x3C
    char gap_40[0x08];
    uchar type;                                 // +0x48
    uchar gap_49;                               // +0x49
    short id;                                   // +0x4A
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float world_time_delta_seconds;             // +0x84

    RGE_Static_Object* object(int id);
};

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite*);
    virtual void update(float, float);
    virtual void draw(short, short, short, short, short, void*, void*);
    virtual void normal_draw(short, short, short, void*, void*);
    virtual void shadow_draw(short, short, short, void*, void*, uchar);
    virtual uchar is_animating(RGE_Sprite*);
    virtual void set_frame(RGE_Sprite*, short);
    virtual uchar frame_passed(RGE_Sprite*, short); // +0x20
    virtual uchar looped(RGE_Sprite*);              // +0x24
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object*);
    virtual int vf08(int, RGE_Action_Object*);
    virtual RGE_Action_List* vf0C(RGE_Action_Object*);
    virtual void vf10();
    virtual void vf14(int);
    virtual short vf18();
    virtual void vf1C(uchar);
    virtual uchar vf20();
    virtual uchar vf24();
    virtual uchar vf28();
    virtual int vf2C();
    virtual int vf30(RGE_Static_Object*, float, float, float);
    virtual int vf34(RGE_Static_Object*, float, float, float);
    virtual uchar vf38(RGE_Static_Object*);
    virtual uchar vf3C(long, uchar);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual RGE_Static_Object* vf4C();
    virtual RGE_Static_Object* vf50();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short action_type;                          // +0x04
    char gap_06[2];                             // +0x06
    RGE_Action_Object* obj;                     // +0x08
    uchar state;                                // +0x0C
    char gap_0D[3];                              // +0x0D
    RGE_Static_Object* target_obj;              // +0x10
    RGE_Static_Object* target_obj2;             // +0x14
    int targetID;                               // +0x18
    int target2ID;                              // +0x1C
    float target_x;                             // +0x20
    float target_y;                             // +0x24
    float target_z;                             // +0x28
    float timer;                                // +0x2C
    RGE_Task* task;                             // +0x30
    RGE_Action_List* sub_actions;              // +0x34
    RGE_Sprite* sprite;                         // +0x38
    uchar subActionValue;                      // +0x3C
    char gap_3D[3];                             // +0x3D
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual uchar inside_obj_update();
    virtual uchar update();                    // +0x0C

    RGE_Action_Object* obj;                     // +0x10
    void* list;                                 // +0x14
};

class RGE_Action_Attack : public RGE_Action {
public:
    virtual uchar update();

    RGE_Sprite* move_sprite;                    // +0x40
    RGE_Sprite* fight_sprite;                   // +0x44
    RGE_Sprite* wait_sprite;                   // +0x48
    float range;                                // +0x4C
    float min_range;                            // +0x50
    short missile_id;                           // +0x54
    short fire_missile_at_frame;               // +0x56
    uchar need_to_attack;                      // +0x58
    uchar was_same_owner;                      // +0x59
    uchar indirect_fire_flag;                  // +0x5A
    uchar gap_5B;                              // +0x5B

    int ready_to_attack(int& rangeStatus);
    void do_attack();
};

uchar RGE_Action_Attack::update()
{
    this->timer += this->obj->owner->world->world_time_delta_seconds;

    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
        this->set_state(2);
        return 5;
    }

    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state >= 3) {
        this->set_target_obj(0);
        this->set_state(2);
        return 5;
    }

    if (this->target_obj != 0 && this->obj->owner->id != 0 &&
        this->obj->owner->isAlly(this->target_obj->owner->id) != 0) {
        this->set_state(1);
        if (this->subActionValue != 0) {
            return 4;
        }
        this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x258, this->targetID, 0);
        return 4;
    }

    if (this->target_obj != 0 && this->target_obj->inside_obj != 0) {
        this->set_state(1);
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x258, this->targetID, 0);
        }
        return 4;
    }

    switch (this->state) {
    case 1:
        return 1;

    case 2:
        if (this->obj->sprite_list->looped(this->obj->sprite) == 1) {
            this->set_target_obj(0);
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x258, 0, 0);
            }
            this->set_state(1);
            return this->subActionValue == 1 ? (uchar)5 : (uchar)2;
        }
        return 0;

    case 4:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        case 3:
            this->set_state(13);
            if (this->subActionValue != 0) {
                return 3;
            }
            this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x258, 0, 0);
            return 3;
        case 4:
            this->set_state(14);
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x258, this->targetID, 0);
            }
            return 4;
        default:
            return 0;
        }

    case 6: {
        int rangeStatus = -1;
        if (this->ready_to_attack(rangeStatus) != 0) {
            ((RGE_Combat_Object*)this->obj)->reset_attack_timer();
            this->set_state(7);
        }
        return 0;
    }

    case 7: {
        if (this->need_to_attack == 0) {
            if (this->obj->can_attack() == 1) {
                if (this->target_obj == 0 && this->indirect_fire_flag == 0) {
                    this->set_state(2);
                    return 0;
                }
                ((RGE_Combat_Object*)this->obj)->reset_attack_timer();
                this->set_state(6);
                if (this->state != 13 && this->state != 4) {
                    this->set_state(7);
                }
            }

            if (this->need_to_attack == 0) {
                if (this->obj->sprite_list->looped(this->obj->sprite) != 1 &&
                    (this->obj->sprite->flags & 1) != 0) {
                    return 0;
                }
                if (this->target_obj == 0 && this->indirect_fire_flag == 0) {
                    this->set_state(2);
                    return 0;
                }
                this->set_state(6);
                return 0;
            }
        }

        short frame = this->fire_missile_at_frame;
        if (frame == 0) {
            frame = (short)((float)this->obj->sprite->frame * 0.5f);
        }
        if (this->obj->sprite_list->frame_passed(this->obj->sprite, frame) != 0) {
            this->do_attack();
        }
        return 0;
    }

    case 13:
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x258, 0, 0);
        return 3;

    default:
        return 0;
    }
}

#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1
