class RGE_Action_Object;
class RGE_Task;

class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(RGE_Action_Object* param_1, int param_2);

    unsigned short action_type;
    char gap_06[0x1A];
};

class RGE_Action_Bird : public RGE_Action {
public:
    float field_20;
    float field_24;
    float field_28;
    char gap_2C[0x04];
    RGE_Task* task;

    RGE_Action_Bird(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
};

RGE_Action_Bird::RGE_Action_Bird(
    RGE_Action_Object* param_1,
    RGE_Task* param_2,
    float param_3,
    float param_4,
    float param_5)
    : RGE_Action(param_1, 1) {
    this->task = param_2;
    this->action_type = 10;
    this->field_20 = param_3;
    this->field_24 = param_4;
    this->field_28 = param_5;
}
