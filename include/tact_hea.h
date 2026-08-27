#ifndef AOE1_TACT_HEA_H
#define AOE1_TACT_HEA_H

// Declarations owned by the tact_hea.cpp source module.
#include "action.h"
#include "act_move.h"
#include "act_list.h"
#include "act_obj.h"
#include "stat_obj.h"
#include "m_s_obj.h"
#include "m_ac_obj.h"
#include "move_obj.h"
#include "t_c_obj.h"
#include "t_b_obj.h"

class RGE_Task;

class TRIBE_Action_Heal : public RGE_Action {
public:
    TRIBE_Action_Heal(int, RGE_Action_Object*);
    TRIBE_Action_Heal(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Heal(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void set_state(unsigned char);
};

typedef char tact_hea_action_size[
    (sizeof(TRIBE_Action_Heal) == 0x40) ? 1 : -1];

#endif  // AOE1_TACT_HEA_H
