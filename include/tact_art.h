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
    virtual ~TRIBE_Action_Artifact();

    TRIBE_Action_Artifact(int, RGE_Action_Object*);
    TRIBE_Action_Artifact(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Artifact(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    void reset_owner();

protected:
    virtual void set_state(unsigned char);
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    RGE_Player* check_ownership();
};

typedef char tact_art_action_size_check[
    (sizeof(TRIBE_Action_Artifact) == 0x40) ? 1 : -1];

#endif  // AOE1_TACT_ART_H
