class RGE_Task;
class RGE_Action_Object;
class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(int file, int flag);

    unsigned short action_type;
    char gap_06[0x1A];

    virtual int setup(int param_1, RGE_Action_Object* param_2);
};

class TRIBE_Action_Repair : public RGE_Action {
public:
    float target_x;
    float target_y;
    float target_z;
    char gap_2C[0x04];
    RGE_Task* task;
    char gap_34[0x0C];
    unsigned char repair_field_40;

    virtual int setup(int param_1, RGE_Action_Object* param_2);
};

extern float save_game_version;
extern void rge_read(int param_1, void* param_2, int param_3);

int TRIBE_Action_Repair::setup(int param_1, RGE_Action_Object* param_2) {
    int result = RGE_Action::setup(param_1, param_2);
    if (save_game_version >= 6.5f) {
        rge_read(param_1, &this->repair_field_40, 1);
    } else {
        this->repair_field_40 = 0;
    }
    return result;
}
