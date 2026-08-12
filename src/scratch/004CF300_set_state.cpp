// VA: 004CF300 TRIBE_Action_Hunt::set_state
// PDB source: tact_hnt.cpp
// Attempt log:
// - Replaced the old decompiler-shaped pointer scaffold with the canonical
//   RGE_Action/TRIBE_Action_Hunt ownership and the tact_hnt state switch.
// - Baseline probe: typed action constructors, task/master fields, and the
//   original shared switch tails remain to be checked against VC5 output.
// - Baseline result: exact size, frame, saved registers, and 93.56% shape;
//   remaining structural gap is the switch table and two move-sprite calls.
// - Two state-split probes worsened the ordered calls and size. Restored the
//   baseline. Leave this natural reconstruction in scratch for the next pass.

class RGE_Sprite;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Task;
class RGE_Player;
class RGE_Object_List;
class RGE_Sound;

class RGE_Master_Action_Object {
public:
    char gap_00[0xE8];
    short drop_site;
    short backup_drop_site;
    char gap_EC[0x34];
    short missile_id;                 // +124
    char gap_126[4];
    short fire_missile_at_frame;      // +12A
    char gap_12C[0x0C];
    float weapon_range;               // +138
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;
    int computerPlayer(void);
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char facet;
};

class RGE_Action_Object {
public:
    virtual void vf00(void); virtual void vf04(void); virtual void vf08(void);
    virtual void vf0C(void); virtual void vf10(void); virtual void vf14(void);
    virtual void vf18(void); virtual void vf1C(void); virtual void vf20(void);
    virtual void vf24(void); virtual void vf28(void); virtual void vf2C(void);
    virtual void vf30(void); virtual void vf34(void);
    virtual void new_sprite(RGE_Sprite*);
    virtual void vf3C(void); virtual void vf40(void); virtual void vf44(void);
    virtual void vf48(void); virtual void vf4C(void); virtual void vf50(void);
    virtual void vf54(void); virtual void vf58(void); virtual void vf5C(void);
    virtual void vf60(void); virtual void vf64(void); virtual void vf68(void);
    virtual void vf6C(void); virtual void vf70(void); virtual void vf74(void);
    virtual void vf78(void); virtual void vf7C(void);
    virtual void set_facet(short, int);
    virtual void vf84(void); virtual void vf88(void); virtual void vf8C(void);
    virtual void vf90(void); virtual void vf94(void); virtual void vf98(void);
    virtual void vf9C(void); virtual void vfA0(void); virtual void vfA4(void);
    virtual void vfA8(void); virtual void vfAC(void); virtual void vfB0(void);
    virtual void vfB4(void); virtual void vfB8(void); virtual void vfBC(void);
    virtual void vfC0(void); virtual void vfC4(void); virtual void vfC8(void);
    virtual void vfCC(void); virtual void vfD0(void); virtual void vfD4(void);
    virtual void vfD8(void); virtual void vfDC(void); virtual void vfE0(void);
    virtual void vfE4(void); virtual void vfE8(void); virtual void vfEC(void);
    virtual void vfF0(void); virtual void vfF4(void); virtual void vfF8(void);
    virtual void vfFC(void); virtual void vf100(void); virtual void vf104(void);
    virtual void vf108(void); virtual void vf10C(void); virtual void vf110(void);
    virtual void vf114(void); virtual void vf118(void); virtual void vf11C(void);
    virtual void vf120(void); virtual void vf124(void); virtual void vf128(void);
    virtual void vf12C(void); virtual void vf130(void); virtual void vf134(void);
    virtual void vf138(void); virtual void vf13C(void); virtual void vf140(void);
    virtual void vf144(void);
    virtual void notify(int, int, int, int, int, int);

    int id;
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char facet;
};

class RGE_Task {
public:
    char gap_00[0x14];
    short attribute_type;
    char gap_16[0x1E];
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
    RGE_Sound* work_sound;
    RGE_Sound* work_sound2;
    float work_range_at_end;
};

class RGE_Action {
public:
    virtual void vf00(void);
    virtual int vf04(RGE_Action_Object*);
    virtual int vf08(int, RGE_Action_Object*);
    virtual RGE_Action_List* vf0C(RGE_Action_Object*);
    virtual void vf10(void); virtual void vf14(int); virtual short vf18(void);
    virtual void vf1C(unsigned char); virtual unsigned char vf20(void);
    virtual unsigned char vf24(void); virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(RGE_Static_Object*, float, float, float);
    virtual int vf34(RGE_Static_Object*, float, float, float);
    virtual unsigned char vf38(RGE_Static_Object*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*); virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
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
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    void setSubAction(unsigned char);
};

class RGE_Action_List {
public:
    void delete_list(void);
    void add_action(RGE_Action*);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    float range;
};

class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Action_Attack(RGE_Action_Object*, RGE_Static_Object*, RGE_Sprite*,
                      RGE_Sprite*, RGE_Sprite*, float, float, short, short);
};

class RGE_Sound {
public:
    void play(int);
};

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_master_ids(long, long, float, float,
                                          unsigned char, unsigned char,
                                          RGE_Static_Object*);
};

class TRIBE_Action_Hunt : public RGE_Action {
public:
    virtual void set_state(unsigned char);
    int targetType;

    RGE_Sprite* get_move_sprite(void);
    RGE_Sprite* get_wait_sprite(void);
};

float hunt_state_zero = 0.0f;

void TRIBE_Action_Hunt::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 1:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x265,
                          this->targetType, 0);
        this->obj->new_sprite(this->get_wait_sprite());
        this->timer = -10.0f;
        return;

    case 2:
        this->obj->new_sprite(this->get_wait_sprite());
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->timer = 0.0f;
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 3:
    case 11:
    case 15: {
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj, this->target_x, this->target_y, this->target_z,
            0.0f, this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;
    }

    case 4: {
        this->timer = 0.0f;
        if (this->target_obj == 0) {
            this->set_state(0x0D);
            return;
        }
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        if (this->target_obj->object_state <= 2) {
            this->set_state(0x0C);
            return;
        }
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj, this->target_obj, this->task->work_range_at_end,
            this->get_move_sprite());
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 5: {
        RGE_Action_Attack* action = new RGE_Action_Attack(
            this->obj, this->target_obj, this->get_move_sprite(),
            this->task->work_sprite, 0, this->task->work_range_at_end,
            this->obj->master_obj->weapon_range,
            this->obj->master_obj->missile_id,
            this->obj->master_obj->fire_missile_at_frame);
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 6:
        this->timer = 0.0f;
        if (this->task->attribute_type != this->obj->facet) {
            this->obj->set_facet(this->task->attribute_type, 0);
        }
        this->obj->new_sprite(this->task->work_sprite2);
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
        }
        return;

    case 7:
        this->timer = 0.0f;
        this->obj->new_sprite(this->task->work_sprite);
        return;

    case 8:
        if (this->obj->attribute_amount_held > hunt_state_zero) {
            if (this->target_obj2 == 0) {
                if (this->obj->master_obj->drop_site != -1) {
                    this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                        this->obj->master_obj->drop_site,
                        this->obj->master_obj->backup_drop_site,
                        this->obj->world_x, this->obj->world_y, 1, 2,
                        (RGE_Static_Object*)this->obj));
                } else {
                    this->set_target_obj2(0);
                }
            }
            if (this->target_obj2 != 0) {
                RGE_Action_Move_To* action = new RGE_Action_Move_To(
                    this->obj, this->target_obj2, this->task->work_range_at_end,
                    this->get_move_sprite());
                if (action == 0) {
                    this->set_state(0x0D);
                    return;
                }
                this->sub_actions->add_action(action);
                action->setSubAction(1);
                return;
            }
            this->obj->notify(this->obj->id, this->obj->id, 0x203, 0x265, 0, 0);
            if (this->obj->owner->computerPlayer() == 0) {
                this->set_state(2);
            } else {
                this->set_state(1);
            }
            return;
        }
        if (this->target_obj2 != 0 &&
            this->target_obj2->attribute_amount_held <= hunt_state_zero) {
            this->set_target_obj2(0);
        }
        this->set_state(3);
        return;

    case 12:
    case 13:
    case 14:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_wait_sprite());
        return;

    default:
        return;
    }
}
