#ifndef AOE1_ACT_GATH_H
#define AOE1_ACT_GATH_H

#include "action.h"

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;

class RGE_Action_Gather : public RGE_Action {
public:
    RGE_Action_Gather(int, RGE_Action_Object*);
    RGE_Action_Gather(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    RGE_Action_Gather(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual ~RGE_Action_Gather();
    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void set_state(unsigned char);
    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();

    int targetType;
};

typedef char rge_action_gather_size_check[
    (sizeof(RGE_Action_Gather) == 0x44) ? 1 : -1];

#endif
