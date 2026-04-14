class RGE_Task;

class RGE_Action {
public:
    virtual void dtor(void);

    short action_type;
    char gap_06[0x1A];
    float target_x;
    float target_y;
    float target_z;
    char gap_2C[0x04];
    RGE_Task* task;

    RGE_Action(int file, int flag);
};

class RGE_Action_Explore : public RGE_Action {
public:
    virtual void dtor(void);

    RGE_Action_Explore(int file, RGE_Task* task, float x, float y, float z);
};

RGE_Action_Explore::RGE_Action_Explore(int file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1)
{
    this->task = task;
    this->target_y = y;
    this->action_type = 4;
    this->target_x = x;
    this->target_z = z;
}
