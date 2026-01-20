#pragma once
#include "common.h"
#include "RGE_Action.h"

class RGE_Action_Explore : public RGE_Action {
public:
    // Virtuals (best-effort)
    virtual ~RGE_Action_Explore(); // vt[0] (0x0)
    virtual int setup(RGE_Action_Object* param_1); // vt[1] (0x4)
    virtual int setup(int param_1, RGE_Action_Object* param_2); // vt[2] (0x8)
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1); // vt[3] (0xC)
    virtual void rehook(); // vt[4] (0x10)
    virtual void save(int param_1); // vt[5] (0x14)
    virtual short type(); // vt[6] (0x18)
    virtual void first_in_stack(uchar param_1); // vt[7] (0x1C)
    virtual uchar inside_obj_update(); // vt[8] (0x20)
    virtual uchar idle_update(); // vt[9] (0x24)
    virtual uchar update(); // vt[10] (0x28)
    virtual int stop(); // vt[11] (0x2C)
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt[12] (0x30)
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt[13] (0x34)
    virtual uchar attack_response(RGE_Static_Object* param_1); // vt[14] (0x38)
    virtual uchar relation_response(long param_1, uchar param_2); // vt[15] (0x3C)
    virtual void copy_obj(RGE_Master_Action_Object* param_1); // vt[16] (0x40)
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3); // vt[17] (0x44)
    virtual void get_state_name(char* param_1); // vt[18] (0x48)
    virtual RGE_Static_Object* get_target_obj(); // vt[19] (0x4C)
    virtual RGE_Static_Object* get_target_obj2(); // vt[20] (0x50)
    virtual void set_target_obj(RGE_Static_Object* param_1); // vt[21] (0x54)
    virtual void set_target_obj2(RGE_Static_Object* param_1); // vt[22] (0x58)
    virtual void set_state(uchar param_1); // vt[23] (0x5C)

};
static_assert(sizeof(RGE_Action_Explore) == 0x40, "Size mismatch");
