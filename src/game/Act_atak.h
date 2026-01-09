#pragma once
#include "common.h"

class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Sprite* move_sprite;                 // 0x40
    RGE_Sprite* fight_sprite;                // 0x44
    RGE_Sprite* wait_sprite;                 // 0x48
    float range;                             // 0x4C
    float min_range;                         // 0x50
    short missile_id;                        // 0x54
    short fire_missile_at_frame;             // 0x56
    uchar need_to_attack;                    // 0x58
    uchar was_same_owner;                    // 0x59
    uchar indirect_fire_flag;                // 0x5A

    virtual void save(int param_1);                         // vt0[5]+0x14=0x4013B0
    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x4014B0
    virtual uchar update();                                 // vt0[10]+0x28=0x401780
    virtual int stop();                                     // vt0[11]+0x2C=0x401540
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[13]+0x34=0x401AD0
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3); // vt0[17]+0x44=0x401F00
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x401550
    RGE_Action_Attack(int param_1, RGE_Action_Object* param_2);
    RGE_Action_Attack(RGE_Action_Object* param_1, RGE_Static_Object* param_2, RGE_Sprite* param_3, RGE_Sprite* param_4, RGE_Sprite* param_5, float param_6, float param_7, short param_8, short param_9);
    RGE_Action_Attack(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, RGE_Sprite* param_5, RGE_Sprite* param_6, RGE_Sprite* param_7, float param_8, float param_9, short param_10, short param_11);
    ~RGE_Action_Attack();
    int ready_to_attack(int* param_1);
    void do_attack();
};

static_assert(sizeof(RGE_Action_Attack) == 0x5C, "RGE_Action_Attack Size Mismatch");

