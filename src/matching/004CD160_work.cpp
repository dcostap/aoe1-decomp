class RGE_Static_Object;
class RGE_Task;

#ifndef AOE1_TACT_ART_TU_CONTEXT
class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    char gap_04[0x0C];
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    RGE_Static_Object* target;
    char gap_14[0x0C];
    float target_x;
    float target_y;
    float target_z;
    RGE_Task* task;
    virtual void set_state(unsigned char v);
    int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};
#endif

int TRIBE_Action_Artifact::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (param_1 != 0) {
        this->target = param_1;
        this->set_state(5);
        return 1;
    }

    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_state(4);
    return 1;
}
