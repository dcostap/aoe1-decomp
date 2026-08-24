#ifndef ACT_EXPL_CONTEXT_H
class RGE_Master_Moving_Object;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Action_List;

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
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int vf34(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char vf38(RGE_Static_Object* param_1);
    virtual unsigned char vf3C(long param_1, unsigned char param_2);
    virtual void vf40(RGE_Master_Moving_Object* param_1);
    virtual void vf44(RGE_Master_Moving_Object* param_1, void* param_2, void* param_3);
    virtual void vf48(char* param_1);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    int gap_04;
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x13];
    float target_x;
    float target_y;
    float target_z;
};

class RGE_Action_Explore : public RGE_Action {
public:
    int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};
#endif

int RGE_Action_Explore::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if ((param_2 < 0.0f) || (param_3 < 0.0f)) {
        this->set_state(3);
        return 1;
    }
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_state(11);
    return 1;
}
