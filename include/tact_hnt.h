#ifndef AOE1_TACT_HNT_H
#define AOE1_TACT_HNT_H

#include "action.h"

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Hunt : public RGE_Action {
public:
    TRIBE_Action_Hunt(int, RGE_Action_Object*);
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, float, float, float);
    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void set_state(unsigned char);
    int targetType;

    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();
};

typedef char tact_hnt_hunt_abi[
    (sizeof(TRIBE_Action_Hunt) == 0x44) ? 1 : -1];

#endif
