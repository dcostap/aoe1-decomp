#pragma once
#include "common.h"
#include "RGE_Combat_Object.h"

class TRIBE_Master_Combat_Object;
class RGE_Player;
class RGE_Map;

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    TRIBE_Combat_Object(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    TRIBE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3);

    virtual ~TRIBE_Combat_Object();
    virtual int setup(int param_1, RGE_Game_World* param_2);
    virtual RGE_Action_List* create_action_list() override;
    virtual void cancel_object();
    virtual uchar attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2) override;
    virtual uchar do_attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5) override;
    virtual uchar area_attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4, RGE_Static_Object* param_5) override;
    virtual void get_armor(short& param_1, short& param_2) override;
    virtual void get_pierce_armor(short& param_1, short& param_2);

protected:
    // Fully verified. Source of truth: t_c_obj.cpp.asm @ 0x004CA300
    virtual int setup(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual void initUnitAI();

public:
    void do_repair(RGE_Static_Object* param_1);
    int can_debark();
    int lines_intersect(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8);
    int higher_check_for_cliff(RGE_Static_Object* param_1, int param_2, int param_3, float param_4, float param_5, float param_6, float param_7,
                               RGE_Map* param_8, RGE_Static_Object* param_9, float& param_10, int& param_11);
    int higher_than_target(RGE_Static_Object* param_1);
    void reposition_artifact();

    unsigned char own_master;
};
static_assert(sizeof(TRIBE_Combat_Object) == 0x1C8, "Size mismatch");
