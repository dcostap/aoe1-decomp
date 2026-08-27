#ifndef AOE1_TACT_REP_H
#define AOE1_TACT_REP_H

#include "action.h"
#include "act_list.h"
#include "act_obj.h"
#include "m_s_obj.h"
#include "m_ac_obj.h"
#include "move_obj.h"
#include "world.h"
#include "player.h"
#include "task.h"

// The rest of the declaration surface comes from the owner headers above.
// Keep only declarations owned by tact_rep.cpp in this module header.
class TRIBE_Action_Repair : public RGE_Action {
public:
    TRIBE_Action_Repair(int, RGE_Action_Object*, int);
    TRIBE_Action_Repair(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Repair(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual int setup(int, RGE_Action_Object*);
    virtual void save(int);
    virtual void first_in_stack(unsigned char);

protected:
    virtual void set_state(unsigned char);

public:
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    void meet_target();

public:
    unsigned char save_target_command_flag;
};

typedef char tact_rep_action_size_check[
    (sizeof(TRIBE_Action_Repair) == 0x44) ? 1 : -1];

#endif
