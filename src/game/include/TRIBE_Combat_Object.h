#pragma once
#include "common.h"
#include "RGE_Combat_Object.h"

class TRIBE_Master_Combat_Object;
class RGE_Player;

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    TRIBE_Combat_Object(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    TRIBE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3);

    virtual ~TRIBE_Combat_Object();
    virtual int setup(int param_1, RGE_Game_World* param_2);
    virtual RGE_Action_List* create_action_list() override;

protected:
    // Fully verified. Source of truth: t_c_obj.cpp.asm @ 0x004CA300
    virtual int setup(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual void initUnitAI();

public:
    void do_repair(RGE_Static_Object* param_1);

    unsigned char own_master;
};
static_assert(sizeof(TRIBE_Combat_Object) == 0x1C8, "Size mismatch");
