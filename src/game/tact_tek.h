#pragma once
#include "common.h"

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    short tech_id;                           // 0x40
    int unique_id;                           // 0x44

    virtual void save(int param_1);                         // vt0[5]+0x14=0x4D2370
    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x4D23B0
    virtual uchar update();                                 // vt0[10]+0x28=0x4D2450
    virtual int stop();                                     // vt0[11]+0x2C=0x4D2550
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x4D2440
    TRIBE_Action_Make_Tech(int param_1, RGE_Action_Object* param_2);
    TRIBE_Action_Make_Tech(RGE_Action_Object* param_1, short param_2, int param_3);
    ~TRIBE_Action_Make_Tech();
    void get_info(short* param_1, short* param_2, char* param_3, short param_4);
};

static_assert(sizeof(TRIBE_Action_Make_Tech) == 0x48, "TRIBE_Action_Make_Tech Size Mismatch");

