// VA: 004CD9E0 TRIBE_Action_Convert::TRIBE_Action_Convert(int, RGE_Action_Object*)
// Source: tact_cnv.cpp lines 48-52
// Size: 126 bytes, __thiscall, ret 8 (2 params)
// FLAGS: /GX (EH frame)
// Reads action data from saved game file

#ifndef TACT_CNV_SHARED_CONTEXT
struct RGE_Action_Object;
struct RGE_Task;

struct RGE_Action {
    virtual ~RGE_Action();
    short action_type;
    unsigned char _pad6[2];
    void* obj;
    unsigned char state;
    unsigned char _padD[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    void* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    unsigned char _pad3D[3];

    RGE_Action(int, RGE_Action_Object*, int);
};

struct TRIBE_Action_Convert : RGE_Action {
    unsigned char was_same_owner;
    unsigned char _pad41[3];
    float requiredRange;

    TRIBE_Action_Convert(int, RGE_Action_Object*);
};

void __cdecl rge_read(int, void*, unsigned int);

#endif

TRIBE_Action_Convert::TRIBE_Action_Convert(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1), requiredRange(1.0f)
{
    this->action_type = 0x68;
    rge_read(param_1, &this->was_same_owner, 1);
    rge_read(param_1, &this->requiredRange, 4);
}
