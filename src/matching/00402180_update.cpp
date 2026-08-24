#ifndef ACT_BIRD_CONTEXT_H
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Action;

class Bird_Move_Random {
public:
    char gap_00[0x08];
    int x;
    int y;
};

class Bird_Update_Data {
public:
    char gap_00[0x28];
    Bird_Move_Random* move_random;
    char gap_2C[0x58];
    float timer_step;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    Bird_Update_Data* bird_data;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite;
};

class RGE_Action_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual unsigned char update(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void new_sprite(RGE_Sprite* param_1);

    int gap_04;
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x2C];
    float world_z;
};

class RGE_Action_List {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual unsigned char update(void);

    void delete_list(void);
    void add_action(RGE_Action* param_1);
};

class RGE_Task {
public:
    char gap_00[0x24];
    float work_range;
};

class RGE_Action {
public:
    virtual void vf00(void);
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
    virtual void vf40(RGE_Master_Action_Object* param_1);
    virtual void vf44(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void vf48(char* param_1);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void vf54(RGE_Static_Object* param_1);
    virtual void vf58(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    int gap_04;
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x13];
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[0x03];
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, float param_5, RGE_Sprite* param_6);

    float range;
};

class RGE_Action_Bird : public RGE_Action {
public:
    unsigned char update(void);
};
#endif

extern int __cdecl debug_rand(char* param_1, int param_2);

static const double bird_update_zero = 0.0;

unsigned char RGE_Action_Bird::update(void) {
    RGE_Action_Move_To* move_to;
    Bird_Move_Random* move_random;

    if (bird_update_zero < this->timer) {
        this->timer = this->timer - this->obj->owner->bird_data->timer_step;
    }

    switch (this->state) {
    case 4:
        if (this->timer <= bird_update_zero) {
            this->set_state(6);
        }
        if ((((int)this->sub_actions->update()) & 0xFF) - 1 != 0) {
            return 0;
        }
        this->set_state(3);
        return 0;

    case 6:
        if (this->timer <= bird_update_zero) {
            this->set_state(4);
        }
        if ((((int)this->sub_actions->update()) & 0xFF) - 1 != 0) {
            return 0;
        }
        this->set_state(3);
        return 0;

    case 3:
        move_random = this->obj->owner->bird_data->move_random;
        this->target_x = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x84) * move_random->x) / 0x7FFF);
        this->target_y = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x85) * move_random->y) / 0x7FFF);
        this->target_z = this->obj->world_z;
        move_to = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, this->task->work_range, this->obj->sprite);
        if (move_to == 0) {
            this->set_state(3);
            return 0;
        }
        this->sub_actions->add_action(move_to);
        this->set_state(4);
        return 0;

    case 1:
        return 1;
    }

    return 0;
}
