// 004CF090 TRIBE_Action_Hunt::TRIBE_Action_Hunt (tact_hnt.cpp:70-73, 103B)
// BLOCKER: SEH frame format difference.
// Original uses compact ESP-based SEH (push -1, push handler, fs:[0] setup, push ecx).
// Our VC5 generates EBP-based SEH for __try/__except and drops try/catch entirely.
// Attempts:
// 1. No EH: 64 bytes (correct logic, no EH frame at all)
// 2. __try/__except with /GX: 103 bytes but EBP-based frame, completely different layout
// 3. try/catch with /GX: 64 bytes (empty catch optimized away)
// No C++ source or flag fix found. VC5-version difference in SEH frame format.

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

extern "C" void __cdecl rge_read(int, void*, int);

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
