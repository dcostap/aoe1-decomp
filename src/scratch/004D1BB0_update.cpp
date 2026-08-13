// VA: 004D1BB0 TRIBE_Action_Repair::update
// Attempt log:
// baseline: reconstructed the inherited action fields, object/world/player ownership,
// nested state/sub-action dispatch, and repair-distance paths from tact_rep.cpp evidence.
// ABI probe: replaced decompiler-shaped object_delta/command shims with the period
// RGE_Static_Object distance_to_object/heal/notify, RGE_Action_Object turn_towards,
// RGE_Player isAlly, and RGE_Base_Game notification surfaces; calls became 29/29.
// control-flow probe: corrected the state table to the binary's source-order handlers
// 10, 12, 4, 13, 6, 7, 9, 1, 11; state 4 shares the state-13 distance tail.
// liveness probe: retained the nested target recheck, one heal result for both ==1/==2
// tests, global-before-threshold FPU comparisons, and direct three-factor repair rate.
// duplicate probes: state-4 goto versus ordinary inner-switch fall-through and a
// scoped sub-action pointer/result local emitted the same or a worse basin; rolled back.
// final best: a named state-13 target alias restores the original target/object load
// order and leaves 35 positional bytes (96.37% shape, exact call/size/frame parity).
// timer assignment-in-condition probe: the natural x87 source form emitted the
// same bytes as the separate decrement statement; restored the cleaner form.
// remaining localized drift: jump-table relocation bytes, state-4 vtable-register
// coloring, repair-rate FPU operand/push scheduling, and timer store/compare order.
// left in scratch after the 10-hypothesis budget; no inline asm or custom flags.

extern float DAT_0057526c;
extern double DAT_00575270;
extern float DAT_00575278;
extern float DAT_0086bc08;

typedef unsigned char uchar;

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Player;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Master_Action_Object;
class RGE_Task;

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class RGE_Game_World {
public:
    char gap_00[0x84];
    float world_time_delta_seconds; // +84

    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    VPAD4(1)
    VPAD2(5)
    virtual int isAlly(int player_id); // +1C

    char gap_04[0x38];
    RGE_Game_World* world; // +3C
    char gap_40[0x0A];
    short id; // +4A
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xE4];
    float work_rate; // +E4
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD16(1)
    VPAD8(17)
    VPAD4(25)
    VPAD2(29)
    virtual uchar can_attack(); // +7C
    virtual void vf80();
    virtual void vf84();
    virtual int vf88(int, int); // +88
    virtual uchar heal(float); // +8C
    VPAD4(36)
    VPAD16(40)
    VPAD16(56)
    VPAD8(72)
    VPAD2(80)
    virtual void notify(int, int, int, long, long, long); // +148
    VPAD4(83)
    VPAD8(87)
    VPAD16(95)
    VPAD8(111)
    VPAD2(119)
    virtual void vpad121(); // +1E4

    long id; // +04
    RGE_Master_Action_Object* master_obj; // +08
    RGE_Player* owner; // +0C
    char gap_10[0x20];
    float hp; // +30
    char gap_34[4];
    float world_x; // +38
    float world_y; // +3C
    float world_z; // +40
    float attribute_amount_held; // +44
    uchar object_state; // +48

    float distance_to_object(RGE_Static_Object* other);
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual int setup_animated(void*, RGE_Player*, float, float, float); // +1E8
    virtual void stop_moving(); // +1EC
    virtual uchar turn_towards(RGE_Static_Object*, float, float); // +1F0
    virtual int setup_moving(void*, RGE_Player*, float, float, float); // +1F4
    virtual void work2(RGE_Static_Object*, float, float, float, uchar); // +1F8
    virtual void set_task(short); // +1FC
};

class RGE_Action_List {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual uchar update(); // +0C
};

class RGE_Task {
public:
    char gap_00[0x1C];
    float work_rate; // +1C
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

    short action_type; // +04
    char gap_06[2];
    RGE_Action_Object* obj; // +08
    uchar state; // +0C
    char gap_0D[3];
    RGE_Static_Object* target_obj; // +10
    RGE_Static_Object* target_obj2; // +14
    int targetID; // +18
    int target2ID; // +1C
    float target_x; // +20
    float target_y; // +24
    float target_z; // +28
    float timer; // +2C
    RGE_Task* task; // +30
    RGE_Action_List* sub_actions; // +34
    void* sprite; // +38
    uchar subActionValue; // +3C
    char gap_3D[3];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    VPAD8(1)
    VPAD4(9)
    VPAD2(13)
    virtual void vpad15();
    virtual void notification(int, long, long, long, long); // +40
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Action_Repair : public RGE_Action {
public:
    virtual uchar update();
};

uchar TRIBE_Action_Repair::update()
{
    RGE_Static_Object* check_target;
    RGE_Static_Object* target;

    if (this->targetID != -1) {
        if (this->obj->owner->world->object(this->targetID) == 0) {
            goto invalid_target;
        }
    }

    if (this->target2ID != -1) {
        if (this->obj->owner->world->object(this->target2ID) == 0) {
            this->set_target_obj2(0);
        }
    }

    check_target = this->target_obj;
    if (check_target != 0) {
        if (check_target->object_state != 2) {
            goto invalid_target;
        }
        if (this->target_obj != 0 &&
            this->obj->owner->isAlly(this->target_obj->owner->id) == 0) {
            goto invalid_target;
        }
    }

    switch (this->state) {
    case 10:
        switch (this->sub_actions->update()) {
        case 4:
            this->set_target_obj(0);
            this->set_state(0x0B);
            return 0;
        case 1:
        case 2:
        case 3:
        case 5:
            this->set_state(1);
            return 0;
        }
        break;

    case 12:
        this->set_state(1);
        return 0;

    case 4:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 3:
            break;
        case 4:
        case 5:
            goto invalid_target;
        default:
            goto update_done;
        }

    case 13:
        target = this->target_obj;
        DAT_0086bc08 = this->obj->distance_to_object(target) - DAT_0057526c;
        if (DAT_0086bc08 <= DAT_00575270) {
            this->set_state(6);
            return 0;
        }
        this->set_state(10);
        return 0;

    case 6:
        if (this->target_obj == 0) {
            this->set_state(1);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0, 0) != 0) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        if (this->target_obj == 0) {
            this->set_state(1);
            return 0;
        }
        if (this->target_obj->world_x != this->target_x ||
            this->target_y != this->target_obj->world_y) {
            DAT_0086bc08 = this->obj->distance_to_object(this->target_obj) - DAT_0057526c;
            if (DAT_0086bc08 > DAT_00575270) {
                this->set_state(3);
                return 0;
            }
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
            return 0;
        }

        uchar result = this->target_obj->heal(
                this->task->work_rate *
                this->obj->owner->world->world_time_delta_seconds *
                this->obj->master_obj->work_rate);
        if (result == 1) {
            this->set_state(1);
            return 0;
        }
        if (result == 2) {
            this->obj->notify(this->obj->id, this->obj->id,
                              0x1FB, 0x26A, 0, 0);
            rge_base_game->notification(0x6B, this->obj->owner->id,
                                        this->target_obj->id, 0, 0);
            this->set_state(2);
            return 0;
        }
        break;
    }

    case 9:
        if (this->target_obj == 0) {
            break;
        }
        this->timer -= this->obj->owner->world->world_time_delta_seconds;
        if (this->timer <= DAT_00575278) {
            DAT_0086bc08 = this->obj->distance_to_object(this->target_obj) - DAT_0057526c;
            if (DAT_0086bc08 <= DAT_00575270) {
                this->set_state(6);
                return 0;
            }
            this->timer = 1.0f;
            return 0;
        }
        break;

    case 1:
        return 1;

    case 11:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1F9, 0x26A, 0, 0);
        this->set_state(2);
        return 3;
    }

update_done:
    return 0;

invalid_target:
    this->set_target_obj(0);
    this->set_state(1);
    return 0;
}

#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1
