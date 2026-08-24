#ifndef ACT_BIRD_CONTEXT_H
class RGE_Sprite;
class RGE_Static_Object;

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
};

class RGE_Action_List {
public:
    void delete_list(void);
};

class RGE_Task {
public:
    char gap_00[0x34];
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
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
    char gap_0D[0x1F];
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
};

class RGE_Action_Bird : public RGE_Action {
public:
    void set_state(unsigned char param_1);
};
#endif

extern int __cdecl debug_rand(char* param_1, int param_2);

void RGE_Action_Bird::set_state(unsigned char param_1) {
    RGE_Sprite* sprite;

    this->state = param_1;
    switch (param_1) {
    case 6:
        this->timer = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x4C) * 10) / 0x7FFF + 5);
        sprite = this->task->work_sprite;
        break;

    case 4:
        this->timer = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x44) * 10) / 0x7FFF + 5);
        sprite = this->task->move_sprite;
        break;

    default:
        this->sub_actions->delete_list();
        return;
    }

    if (sprite != 0) {
        this->obj->new_sprite(sprite);
        return;
    }

    this->obj->new_sprite(this->obj->master_obj->sprite);
}
