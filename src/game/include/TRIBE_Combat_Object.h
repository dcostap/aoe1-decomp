#pragma once
#include "common.h"
#include "RGE_Combat_Object.h"

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    TRIBE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3);

    virtual ~TRIBE_Combat_Object();
    virtual int setup(int param_1, RGE_Game_World* param_2);

protected:
    virtual void initUnitAI();

public:
    void do_repair(RGE_Static_Object* param_1);

    unsigned char own_master;
};
static_assert(sizeof(TRIBE_Combat_Object) == 0x1C8, "Size mismatch");
