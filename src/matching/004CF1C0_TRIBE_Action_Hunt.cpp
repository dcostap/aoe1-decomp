#ifndef TACT_HNT_SHARED_CONTEXT
class RGE_Task;

class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(int file, int flag);

    unsigned short action_type;
    char gap_06[0x1A];
};

class TRIBE_Action_Hunt : public RGE_Action {
public:
    float target_x;
    float target_y;
    float target_z;
    char gap_2C[0x04];
    RGE_Task* task;
    char gap_34[0x0C];
    int hunt_field_40;

    TRIBE_Action_Hunt(int file, RGE_Task* task, float x, float y, float z);
};
#endif

TRIBE_Action_Hunt::TRIBE_Action_Hunt(int file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1) {
#ifdef TACT_HNT_SHARED_CONTEXT
    this->task = task;
    this->action_type = 0x6E;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->targetType = -1;
#else
    this->task = task;
    this->action_type = 0x6E;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->hunt_field_40 = -1;
#endif
}
