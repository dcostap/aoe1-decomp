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

class TRIBE_Action_Repair : public RGE_Action {
public:
    char gap_34[0x0C];
    unsigned char repair_field_40;

    TRIBE_Action_Repair(int file, RGE_Task* task, float x, float y, float z);
};

TRIBE_Action_Repair::TRIBE_Action_Repair(int file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1)
{
    this->task = task;
    this->target_y = y;
    this->vfptr = 0x575208;
    this->action_type = 0x6A;
    this->target_x = x;
    this->target_z = z;
    this->repair_field_40 = 0;
}
