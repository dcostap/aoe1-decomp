#ifndef AOE1_TACT_REP_H
#define AOE1_TACT_REP_H

#include "action.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

// The rest of the declaration surface comes from the owner headers above.
// Keep only declarations owned by tact_rep.cpp in this module header.
class TRIBE_Action_Repair : public RGE_Action {
public:
    TRIBE_Action_Repair(int infile, RGE_Action_Object* obj_in, int do_setup);
    TRIBE_Action_Repair(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in);
    TRIBE_Action_Repair(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);

    virtual int setup(int infile, RGE_Action_Object* obj_in);
    virtual void save(int outfile);
    virtual void first_in_stack(unsigned char first_time);

protected:
    virtual void set_state(unsigned char new_state);

public:
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
    virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);

protected:
    void meet_target();

public:
    unsigned char save_target_command_flag;
};

typedef char tact_rep_action_size_check[
    (sizeof(TRIBE_Action_Repair) == 0x44) ? 1 : -1];

#endif
