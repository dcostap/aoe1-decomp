// quick-win attempt log:
// target is 004CF090 TRIBE_Action_Hunt::TRIBE_Action_Hunt(int,RGE_Action_Object*) from tact_hnt.cpp
// starting from the oracle shape: EH frame, base RGE_Action(this,param1,param2,1), then vptr/word
// init and the rge_read(param1, this+0x40, 4) helper call. /GX was tested, but VC5 still only
// emitted a 64-byte .text body instead of the 103-byte EH frame, so this is paused in scratch.

class RGE_Action_Object;

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    unsigned char _pad_0[2];
    RGE_Action_Object* obj;
    unsigned char state;
    unsigned char _pad_1[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    unsigned char _pad_end[3];

    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
};

extern void rge_read(int, void*, int);

class TRIBE_Action_Hunt : public RGE_Action {
public:
    int targetType;

    TRIBE_Action_Hunt(int param_1, RGE_Action_Object* param_2);
};

TRIBE_Action_Hunt::TRIBE_Action_Hunt(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1)
{
    vtable_ptr = (void*)0x5750F0;
    action_type = 0x6E;
    rge_read(param_1, &targetType, 4);
}
