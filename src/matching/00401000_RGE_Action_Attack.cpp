#ifndef ACT_ATAK_CONTEXT_H
class RGE_Sprite;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Task;

class RGE_Static_Object {
public:
    RGE_Sprite* get_sprite_pointer(short param_1);
};

void rge_read(int param_1, void* param_2, int param_3);

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object* param_1);
    virtual int vf08(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* vf0C(RGE_Action_Object* param_1);
    virtual void vf10(void);
    virtual void vf14(int param_1);
    virtual short vf18(void);
    virtual void vf1C(unsigned char param_1);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int vf34(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char vf38(RGE_Static_Object* param_1);
    virtual unsigned char vf3C(long param_1, unsigned char param_2);
    virtual void vf40(void* param_1);
    virtual void vf44(void* param_1, void* param_2, void* param_3);
    virtual void vf48(char* param_1);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void vf58(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);

    short action_type;
    char gap_06[0x2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x3];
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
    char gap_3D[0x3];
};

class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Action_Attack(int param_1, RGE_Action_Object* param_2);
    virtual ~RGE_Action_Attack();

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

RGE_Action_Attack::RGE_Action_Attack(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1)
{
    short sprite_id;

    this->action_type = 9;
    rge_read(param_1, &this->range, 4);
    rge_read(param_1, &this->min_range, 4);
    rge_read(param_1, &this->missile_id, 2);
    rge_read(param_1, &this->fire_missile_at_frame, 2);
    rge_read(param_1, &this->need_to_attack, 1);
    rge_read(param_1, &this->was_same_owner, 1);
    rge_read(param_1, &this->indirect_fire_flag, 1);
    rge_read(param_1, &sprite_id, 2);
    this->move_sprite = ((RGE_Static_Object*)this->obj)->get_sprite_pointer(sprite_id);
    rge_read(param_1, &sprite_id, 2);
    this->fight_sprite = ((RGE_Static_Object*)this->obj)->get_sprite_pointer(sprite_id);
    rge_read(param_1, &sprite_id, 2);
    this->wait_sprite = ((RGE_Static_Object*)this->obj)->get_sprite_pointer(sprite_id);
}
