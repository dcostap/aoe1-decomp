#pragma once
#include "common.h"
#include "RGE_Action_List.h"

class TRIBE_Action_List : public RGE_Action_List {
public:
    // Virtuals (best-effort)
    virtual RGE_Action* create_action(int param_1, short param_2); // vt[0] (0x0)
    virtual RGE_Action* create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5); // vt[1] (0x4)
    virtual uchar inside_obj_update(); // vt[2] (0x8)
    virtual uchar update(); // vt[3] (0xC)
    virtual void get_action_name(char* param_1); // vt[4] (0x10)
    virtual void copy_obj(RGE_Master_Action_Object* param_1); // vt[5] (0x14)
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3); // vt[6] (0x18)

};
static_assert(sizeof(TRIBE_Action_List) == 0xC, "Size mismatch");
