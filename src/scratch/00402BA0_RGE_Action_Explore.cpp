// STATUS: scratch
// FLAGS: config\flags\00402BA0_RGE_Action_Explore.rsp

class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Action_List;
class RGE_Action_Object;

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
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    RGE_Action(RGE_Action_Object* obj, int value);

    short action_type;
    char gap_06[2];
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
    char gap_3D[3];
};

class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z);
    virtual ~RGE_Action_Explore();
};

RGE_Action_Explore::RGE_Action_Explore(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z)
    : RGE_Action(obj, 1) {
    RGE_Task* task_local = task;
    float y_local = y;

    this->task = task_local;
    this->target_y = y_local;
    this->action_type = 4;
    this->target_x = x;
    this->target_z = z;
}
