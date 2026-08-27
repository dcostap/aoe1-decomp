#ifndef AOE1_ACT_MOVE_H
#define AOE1_ACT_MOVE_H

#include "action.h"
#include "act_obj.h"

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(int, RGE_Action_Object*);
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float,
                       RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float,
                       RGE_Sprite*);
    virtual ~RGE_Action_Move_To();
    virtual void save(int);
    virtual void first_in_stack(unsigned char);

protected:
    virtual void set_state(unsigned char);

public:
    virtual unsigned char update();

protected:
    unsigned char is_in_range();

public:
    float range;
};

typedef char rge_action_move_to_size_check[
    (sizeof(RGE_Action_Move_To) == 0x44) ? 1 : -1];

#endif
