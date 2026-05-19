// VA: 00402F40 RGE_Action_Gather::RGE_Action_Gather
// Existing tries: /GX/ordering/layout/parent param probes; blocker was constructor/register ordering.
// try 11: fix parent ctor surface to observed two args (param_1, 1) and make targetType int at +0x40.

class RGE_Sprite;
class RGE_Action_Object;
class RGE_Task;
class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Action_Object* obj;
    char gap_0C[0x2C];
    int target_x;
    int target_y;
    int target_z;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object*);
    virtual int vf08(int, RGE_Action_Object*);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int);
    virtual short vf18(void);
    virtual void vf1C(unsigned char);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void*, float, float, float);
    virtual int vf34(void*, float, float, float);
    virtual unsigned char vf38(void*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual void* vf4C(void);
    virtual void* vf50(void);
    virtual void set_target_obj(void*);
    virtual void vf58(void*);
    virtual void set_state(unsigned char);

    RGE_Action(RGE_Action_Object*, int);

    short action_type;
    char gap_06[0x2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    int target_x;
    int target_y;
    int target_z;
    float timer;
    void* task;
    void* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[0x3];
};

class RGE_Action_Gather : public RGE_Action {
public:
    RGE_Action_Gather(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    int targetType;
};

RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3)
    : RGE_Action(param_1, 1) {
    this->task = param_2;
    this->action_type = 5;
    this->set_target_obj(param_3);
    if (param_3) {
        this->target_x = param_3->target_x;
        this->target_y = param_3->target_y;
        this->target_z = param_3->target_z;
        this->targetType = *(short*)((char*)param_3->obj + 0x10);
    }
}
