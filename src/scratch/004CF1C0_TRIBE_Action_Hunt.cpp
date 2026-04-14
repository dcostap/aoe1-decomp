class RGE_Task;

class RGE_Action {
public:
    int vfptr;
    short action_type;
    char gap_06[0x1A];
    float target_x;
    float target_y;
    float target_z;
    char gap_2C[0x04];
    RGE_Task* task;

    RGE_Action(int file, int flag);
};

class TRIBE_Action_Hunt : public RGE_Action {
public:
    char gap_34[0x0C];
    int hunt_field_40;

    TRIBE_Action_Hunt(int file, RGE_Task* task, float x, float y, float z);
};

TRIBE_Action_Hunt::TRIBE_Action_Hunt(int file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1)
{
    this->task = task;
    this->target_y = y;
    this->vfptr = 0x5750F0;
    this->action_type = 0x6E;
    this->target_x = x;
    this->target_z = z;
    this->hunt_field_40 = -1;
}
