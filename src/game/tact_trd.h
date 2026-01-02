#pragma once
#include "../common.h"

class TRIBE_Action_Trade : public RGE_Action {
public:
    float pick_up_x;                         // 0x40
    float pick_up_y;                         // 0x44

    TRIBE_Action_Trade(int param_1, RGE_Action_Object* param_2);
    virtual ~TRIBE_Action_Trade();
    TRIBE_Action_Trade(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    TRIBE_Action_Trade(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    virtual void save(int param_1);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual RGE_Sprite* get_move_sprite();
    virtual RGE_Sprite* get_wait_sprite();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};

static_assert(sizeof(TRIBE_Action_Trade) == 0x48, "TRIBE_Action_Trade Size Mismatch");
static_assert(offsetof(TRIBE_Action_Trade, pick_up_y) == 0x44, "TRIBE_Action_Trade Offset Mismatch");

