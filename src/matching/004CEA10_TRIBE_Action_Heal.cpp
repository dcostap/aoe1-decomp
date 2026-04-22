class RGE_Task;

class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(int file, int flag);

    unsigned short action_type;
    char gap_06[0x1A];
};

class TRIBE_Action_Heal : public RGE_Action {
public:
    float target_x;
    float target_y;
    float target_z;
    char gap_2C[0x04];
    RGE_Task* task;

    TRIBE_Action_Heal(int file, RGE_Task* task, float x, float y, float z);
};

TRIBE_Action_Heal::TRIBE_Action_Heal(int file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1) {
    this->task = task;
    this->action_type = 0x69;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}
