#ifndef AOE1_TACT_HEA_H
#define AOE1_TACT_HEA_H

#include "action.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Heal : public RGE_Action {
public:
    TRIBE_Action_Heal(int infile, RGE_Action_Object* obj_in);
    TRIBE_Action_Heal(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in);
    TRIBE_Action_Heal(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);

    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char update();
    virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);

protected:
    virtual void set_state(unsigned char new_state);
};

typedef char tact_hea_action_size[
    (sizeof(TRIBE_Action_Heal) == 0x40) ? 1 : -1];

#endif  // AOE1_TACT_HEA_H
