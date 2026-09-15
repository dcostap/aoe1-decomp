#ifndef AOE1_ACT_ATAK_H
#define AOE1_ACT_ATAK_H

#include "action.h"

class RGE_Action_Object;
class RGE_Master_Action_Object;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Task;

class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Action_Attack(int infile, RGE_Action_Object* obj_in);
    RGE_Action_Attack(RGE_Action_Object* obj_in, RGE_Static_Object* target_obj_in,
                      RGE_Sprite* move_sprite_in, RGE_Sprite* fight_sprite_in,
                      RGE_Sprite* wait_sprite_in, float range_in, float min_range_in,
                      short missile_id_in, short fire_missile_at_frame_in);
    RGE_Action_Attack(RGE_Action_Object* obj_in, float x, float y, float z,
                      RGE_Sprite* move_sprite_in, RGE_Sprite* fight_sprite_in,
                      RGE_Sprite* wait_sprite_in, float range_in, float min_range_in,
                      short missile_id_in, short fire_missile_at_frame_in);
    virtual ~RGE_Action_Attack();

    virtual void save(int outfile);
    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char update();
    virtual int stop();
    virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);

protected:
    virtual void copy_obj_sprites(RGE_Master_Action_Object* source, RGE_Task* task, RGE_Task* new_task);
    virtual void set_state(unsigned char new_state);

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

    int ready_to_attack(int& rangeState);
    void do_attack();
};

typedef char rge_action_attack_size_check[
    (sizeof(RGE_Action_Attack) == 0x5C) ? 1 : -1];

#endif
