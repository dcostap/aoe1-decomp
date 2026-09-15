#pragma once

#include "action.h"

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Trade : public RGE_Action {
public:
    virtual void save(int outfile);
    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
    virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);

    TRIBE_Action_Trade(int infile, RGE_Action_Object* obj_in);
    TRIBE_Action_Trade(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in);
    TRIBE_Action_Trade(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);

protected:
    virtual void set_state(unsigned char new_state);
    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();

public:
    float pick_up_x;
    float pick_up_y;
};

typedef char tact_trd_action_trade_size_check[
    (sizeof(TRIBE_Action_Trade) == 0x48) ? 1 : -1];
