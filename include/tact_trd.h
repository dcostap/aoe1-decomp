#pragma once

#include "action.h"

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Trade : public RGE_Action {
public:
    virtual ~TRIBE_Action_Trade();
    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

    TRIBE_Action_Trade(int, RGE_Action_Object*);
    TRIBE_Action_Trade(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Trade(RGE_Action_Object*, RGE_Task*, float, float, float);

protected:
    virtual void set_state(unsigned char);
    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();

public:
    float pick_up_x;
    float pick_up_y;
};

typedef char tact_trd_action_trade_size_check[
    (sizeof(TRIBE_Action_Trade) == 0x48) ? 1 : -1];
