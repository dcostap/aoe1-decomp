#ifndef AOE1_TACT_ART_H
#define AOE1_TACT_ART_H

// Declaration surface owned by tact_art.cpp.

#include "action.h"

class RGE_Action_Object;
class RGE_Player;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Artifact : public RGE_Action {
public:

    TRIBE_Action_Artifact(int infile, RGE_Action_Object* obj_in);
    TRIBE_Action_Artifact(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in);
    TRIBE_Action_Artifact(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);

    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char update();
    void reset_owner();

protected:
    virtual void set_state(unsigned char new_state);
    virtual int stop();
    virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
    virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
    RGE_Player* check_ownership();
};

typedef char tact_art_action_size_check[
    (sizeof(TRIBE_Action_Artifact) == 0x40) ? 1 : -1];

#endif  // AOE1_TACT_ART_H
