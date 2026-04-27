// attempt 1: EH-framed constructor with base action ctor, vptr store, and 4-byte read into the range field
// blocker: the target is still in the wrong codegen basin; donor-style RGE_Action context and the ctor/dtor surface changed the emitted shape too far, so this stays in scratch for now
#include "..\..\include\game_types.h"

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

    virtual ~RGE_Action_Move_To();
    RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2);
};

extern "C" int __cdecl rge_read(int handle, void* buffer, int count);

RGE_Action_Move_To::~RGE_Action_Move_To() {
}

RGE_Action_Move_To::RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1) {
    *(void**)this = (void*)0x56E3A0;
    *(short*)((char*)this + 4) = 1;
    rge_read(param_1, (char*)this + 0x40, 4);
}
