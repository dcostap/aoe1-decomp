// VA: 00405510 | RGE_Action_Move_To::RGE_Action_Move_To(int, RGE_Action_Object*) | act_move.cpp:40-43 | 103 bytes
// /GX per-function rsp at config/flags/00405510_RGE_Action_Move_To.rsp.
//
// Attempt log:
// [1] No destructor + init list: 64 bytes, no SEH frame — /GX alone not enough.
//     Our VC5 (5.10.7322) only adds EH frames for functions with new/delete.
// [2] try/catch: adds unwanted catch block — wrong approach.
// [3] __try/__finally: CW events EH, not C++ EH — wrong type.
// [4] Destructor declared/defined: destructor placed at offset 0 of .text.
// [5] Destructor after constructor: constructor at offset 0 (64 bytes, no SEH).
// [6] Dummy new/delete: adds call instructions, not just EH frame.
//
// Verdict: The original has an SEH frame (push -1, handler, [fs:0] sequence) that
// our VC5 does NOT generate without new/delete. Our VC5 (5.10.7322) only adds
// C++ EH frames when EH-relevant constructs (new/delete) are present, while the
// original VC5 version added EH frames for constructors that call extern functions.
// This is a VC5 version artifact, similar to the 00541D00 null-check insertion.
// Without SEH frame: 64 bytes (39 bytes short). All instructions match structurally.
//
// Blocked: VC5 EH frame generation gap.

#include "../../include/game_types.h"

class RGE_Action_Object;
class RGE_Action_List;
class RGE_Static_Object;
class RGE_Master_Action_Object;
class RGE_Task;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* param_1);
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(unsigned char param_1);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char attack_response(RGE_Static_Object* param_1);
    virtual unsigned char relation_response(long param_1, unsigned char param_2);
    virtual void copy_obj(RGE_Master_Action_Object* param_1);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void get_state_name(char* param_1);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);
    char gap_04[0x14];
    int targetID;
    int target2ID;

    RGE_Action(int mode, RGE_Action_Object* object, int doSetup);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    float range;

    RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2);
};

extern "C" int __cdecl rge_read(int handle, void* buffer, int count);

RGE_Action_Move_To::RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1) {
    *(void**)this = (void*)0x56E3A0;
    *(short*)((char*)this + 4) = 1;
    rge_read(param_1, (char*)this + 0x40, 4);
}
