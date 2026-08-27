#ifndef AOE1_ACT_ATAK_H
#define AOE1_ACT_ATAK_H

#include "action.h"

class RGE_Action_Object;
class RGE_Master_Action_Object;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Task;

// Declarations for the complete C:\\msdev\\work\\age1_x1\\Act_atak.cpp module.
class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Action_Attack(int, RGE_Action_Object*);
    RGE_Action_Attack(RGE_Action_Object*, RGE_Static_Object*, RGE_Sprite*,
                      RGE_Sprite*, RGE_Sprite*, float, float, short, short);
    RGE_Action_Attack(RGE_Action_Object*, float, float, float, RGE_Sprite*,
                      RGE_Sprite*, RGE_Sprite*, float, float, short, short);
    virtual ~RGE_Action_Attack();

    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int stop();
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*,
                                  RGE_Task*);
    virtual void set_state(unsigned char);

    RGE_Sprite* move_sprite;
    RGE_Sprite* fight_sprite;
    RGE_Sprite* wait_sprite;
    float range;
    float min_range;
    short missile_id;
    short fire_missile_at_frame;
    unsigned char need_to_attack;
    unsigned char was_same_owner;
    unsigned char indirect_fire_flag;

    int ready_to_attack(int&);
    void do_attack();
};

typedef char rge_action_attack_size_check[
    (sizeof(RGE_Action_Attack) == 0x5C) ? 1 : -1];

#endif
