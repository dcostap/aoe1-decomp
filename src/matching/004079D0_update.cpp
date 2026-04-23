class RGE_Action_List;
class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;

class RGE_Action {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54(int param_1);
    virtual void vf58(int param_1);

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

    unsigned char update();
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int param_1, short param_2);
    virtual RGE_Action* create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5);
    virtual unsigned char inside_obj_update();
    virtual unsigned char update();
    RGE_Action_Object* obj;
    void* list;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    int id;
    char gap_08[0x40];
    unsigned char object_state;
};

unsigned char RGE_Action::update()
{
    if (this->target_obj != 0 && this->target_obj->object_state >= 7)
        this->vf54(0);

    if (this->target_obj2 != 0 && this->target_obj2->object_state >= 7)
        this->vf58(0);

    if (this->sub_actions->list != 0)
        return this->sub_actions->update();

    if (this->state != 1)
        return 0;

    return 1;
}
