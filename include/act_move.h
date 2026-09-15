#ifndef AOE1_ACT_MOVE_H
#define AOE1_ACT_MOVE_H

#include "action.h"

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(int infile, RGE_Action_Object* obj_in);
    RGE_Action_Move_To(RGE_Action_Object* obj_in, float x, float y, float z,
                       float range_in, RGE_Sprite* sprite_in);
    RGE_Action_Move_To(RGE_Action_Object* obj_in, RGE_Static_Object* target_obj_in,
                       float range_in, RGE_Sprite* sprite_in);
    virtual ~RGE_Action_Move_To();
    virtual void save(int outfile);
    virtual void first_in_stack(unsigned char first_time);

protected:
    virtual void set_state(unsigned char new_state);

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
