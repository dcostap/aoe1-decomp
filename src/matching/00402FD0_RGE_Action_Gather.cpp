#ifndef ACT_GATH_CONTEXT_H
class RGE_Task;

class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(int file, int flag);

    unsigned short action_type;
    char gap_06[0x1A];
};

class RGE_Action_Gather : public RGE_Action {
public:
    float target_x;
    float target_y;
    float target_z;
    char gap_2C[0x04];
    RGE_Task* task;
    char gap_34[0x0C];
    int gather_field_40;

    RGE_Action_Gather(int file, RGE_Task* task, float x, float y, float z);
};
#endif

RGE_Action_Gather::RGE_Action_Gather(int file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1) {
    this->task = task;
    this->action_type = 5;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->gather_field_40 = -1;
}
