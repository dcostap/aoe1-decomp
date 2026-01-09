#pragma once
#include "common.h"

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    short obj_id;                            // 0x40
    float work_done;                         // 0x44
    int unique_id;                           // 0x48
    uchar pre_paid;                          // 0x4C

    virtual void save(int param_1);                         // vt0[5]+0x14=0x4D0F70
    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x4D0FC0
    virtual uchar update();                                 // vt0[10]+0x28=0x4D10F0
    virtual int stop();                                     // vt0[11]+0x2C=0x4D1550
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x4D10E0
    TRIBE_Action_Make_Obj(int param_1, RGE_Action_Object* param_2);
    TRIBE_Action_Make_Obj(RGE_Action_Object* param_1, short param_2, int param_3, uchar param_4);
    ~TRIBE_Action_Make_Obj();
    uchar place_obj(RGE_Static_Object** param_1);
    void get_info(short* param_1, short* param_2, char* param_3, short param_4);
};

static_assert(sizeof(TRIBE_Action_Make_Obj) == 0x50, "TRIBE_Action_Make_Obj Size Mismatch");

