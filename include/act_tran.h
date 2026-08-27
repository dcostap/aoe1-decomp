#ifndef AOE1_ACT_TRAN_H
#define AOE1_ACT_TRAN_H

#include "action.h"
#include "act_move.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

// RGE_Action_Transport is a 0x40-byte derived action with no own fields.
// act_tran.cpp constructs RGE_Action_Move_To through its canonical owner.
class RGE_Action_Transport : public RGE_Action {
public:
    RGE_Action_Transport(int, RGE_Action_Object*);
    RGE_Action_Transport(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual int stop();
    virtual int next_to_drop_off_terrain();

protected:
    virtual void set_state(unsigned char);

public:
    int targetZone();
};

typedef char rge_action_transport_size_check[
    (sizeof(RGE_Action_Transport) == 0x40) ? 1 : -1];

#endif
