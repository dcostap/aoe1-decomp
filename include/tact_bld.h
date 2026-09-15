#ifndef AOE1_TACT_BLD_H
#define AOE1_TACT_BLD_H

#include "action.h"

class TRIBE_Action_Build : public RGE_Action {
public:
    TRIBE_Action_Build(int infile, RGE_Action_Object* obj_in);
    TRIBE_Action_Build(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in);
    TRIBE_Action_Build(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);

    virtual void first_in_stack(unsigned char first_time);

protected:
    virtual void set_state(unsigned char new_state);

public:
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
    virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
};

typedef char tact_bld_action_size[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_bld_build_size[
    (sizeof(TRIBE_Action_Build) == 0x40) ? 1 : -1];

#endif  // AOE1_TACT_BLD_H
