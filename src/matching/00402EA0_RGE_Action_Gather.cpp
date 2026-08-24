#ifndef ACT_GATH_CONTEXT_H
class RGE_Sprite;
class RGE_Action_Object;

void rge_read(int param_1, void* param_2, int param_3);

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object* param_1);
    virtual int vf08(int param_1, RGE_Action_Object* param_2);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int param_1);
    virtual short vf18(void);
    virtual void vf1C(unsigned char param_1);
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

    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);

    short action_type;
    char gap_06[0x2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[0x3];
};

class RGE_Action_Gather : public RGE_Action {
public:
    RGE_Action_Gather(int param_1, RGE_Action_Object* param_2);

    short targetType;
};
#endif

RGE_Action_Gather::RGE_Action_Gather(int param_1, RGE_Action_Object* param_2) : RGE_Action(param_1, param_2, 1) {
    this->action_type = 5;
    rge_read(param_1, &this->targetType, 4);
}
