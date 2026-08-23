// VA: 00401550 RGE_Action_Attack::set_state
// Attempt log:
// initial natural switch with local class surfaces; iterate with check_function.

#ifndef ACT_ATAK_CONTEXT_H
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Task;

class RGE_Action_Object {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void new_sprite(RGE_Sprite*);
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void notify(int,int,int,int,int,int);

    int id;
};

class RGE_Action {
public:
    virtual void vf00();
    virtual int vf04(RGE_Action_Object*);
    virtual int vf08(int,RGE_Action_Object*);
    virtual RGE_Action_List* vf0C(RGE_Action_Object*);
    virtual void vf10();
    virtual void vf14(int);
    virtual short vf18();
    virtual void vf1C(unsigned char);
    virtual unsigned char vf20();
    virtual unsigned char vf24();
    virtual unsigned char vf28();
    virtual int vf2C();
    virtual int vf30(RGE_Static_Object*,float,float,float);
    virtual int vf34(RGE_Static_Object*,float,float,float);
    virtual unsigned char vf38(RGE_Static_Object*);
    virtual unsigned char vf3C(long,unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*,void*,void*);
    virtual void vf48(char*);
    virtual RGE_Static_Object* vf4C();
    virtual RGE_Static_Object* vf50();
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

class RGE_Action_List { public: void delete_list(); void add_action(RGE_Action*); };
class RGE_Combat_Object { public: void reset_attack_timer(); };

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    float range;
};

class RGE_Action_Attack : public RGE_Action {
public:
    virtual void set_state(unsigned char);
    int ready_to_attack(int& rangeStatus);
    RGE_Sprite* move_sprite;
    RGE_Sprite* fight_sprite;
    RGE_Sprite* wait_sprite;
    float range;
    float min_range;
    short missile_id;
    short fire_missile_at_frame;
    unsigned char need_to_attack;
    unsigned char was_same_owner;
    unsigned char indirect_fire_flag;
    unsigned char gap_5B;
};
#endif

void RGE_Action_Attack::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 2:
        this->indirect_fire_flag = 0;
        return;

    case 4: {
        if (this->indirect_fire_flag > 0) {
            this->indirect_fire_flag--;
        }
        RGE_Action_Move_To* action;
        if (this->target_obj != 0) {
            action = new RGE_Action_Move_To(this->obj, this->target_obj, this->range, this->move_sprite);
        } else {
            action = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, this->range, this->move_sprite);
        }
        if (action == 0) {
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x262, 0, 0);
            }
            this->set_state(1);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        this->timer = 0.0f;
        return;
    }

    case 6: {
        if (this->indirect_fire_flag > 0 && this->target_obj != 0) {
            this->indirect_fire_flag = 0;
        }
        int rangeStatus = -1;
        if (this->ready_to_attack(rangeStatus)) {
            ((RGE_Combat_Object*)this->obj)->reset_attack_timer();
            this->set_state(7);
            return;
        }
        if (this->missile_id == -1) {
            this->obj->new_sprite(this->fight_sprite);
        } else {
            this->obj->new_sprite(this->wait_sprite);
        }
        return;
    }

    case 7:
        this->obj->new_sprite(this->fight_sprite);
        this->need_to_attack = 1;
        return;

    case 1:
    case 13:
    case 14:
        this->obj->new_sprite(this->wait_sprite);
        return;

    default:
        return;
    }
}
