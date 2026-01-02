#pragma once
#include "../common.h"

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    short tech_id;                           // 0x40
    int unique_id;                           // 0x44

    TRIBE_Action_Make_Tech(int param_1, RGE_Action_Object* param_2);
    TRIBE_Action_Make_Tech(RGE_Action_Object* param_1, short param_2, int param_3);
    virtual ~TRIBE_Action_Make_Tech();
    virtual void save(int param_1);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual int stop();
    virtual void get_info(short* param_1, short* param_2, char* param_3, short param_4);
};

static_assert(sizeof(TRIBE_Action_Make_Tech) == 0x48, "TRIBE_Action_Make_Tech Size Mismatch");
static_assert(offsetof(TRIBE_Action_Make_Tech, unique_id) == 0x44, "TRIBE_Action_Make_Tech Offset Mismatch");

