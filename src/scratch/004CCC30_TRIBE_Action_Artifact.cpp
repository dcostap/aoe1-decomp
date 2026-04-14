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

class TRIBE_Action_Artifact : public RGE_Action {
public:
    TRIBE_Action_Artifact(int file, RGE_Task* task, float x, float y, float z);
};

TRIBE_Action_Artifact::TRIBE_Action_Artifact(int file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1)
{
    this->task = task;
    this->target_y = y;
    this->vfptr = 0x574EA8;
    this->action_type = 0x6B;
    this->target_x = x;
    this->target_z = z;
}
