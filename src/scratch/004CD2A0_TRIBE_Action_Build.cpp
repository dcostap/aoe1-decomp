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

class TRIBE_Action_Build : public RGE_Action {
public:
    TRIBE_Action_Build(int file, RGE_Task* task, float x, float y, float z);
};

TRIBE_Action_Build::TRIBE_Action_Build(int file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1)
{
    this->task = task;
    this->target_y = y;
    this->vfptr = 0x574F18;
    this->action_type = 0x65;
    this->target_x = x;
    this->target_z = z;
}
