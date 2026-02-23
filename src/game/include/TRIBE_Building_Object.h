#pragma once
#include "common.h"
#include "TRIBE_Combat_Object.h"
#include "Production_Queue_Record.h"

class TRIBE_Master_Building_Object;
class RGE_Player;

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6, int param_7);
    TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    TRIBE_Building_Object(int param_1, RGE_Game_World* param_2, int param_3);

    virtual ~TRIBE_Building_Object();
    virtual int setup(int param_1, RGE_Game_World* param_2);

    unsigned char build(float param_1);
    void add_to_production_queue(short param_1, short param_2);
    void remove_from_production_queue(short param_1, short param_2);

    Production_Queue_Record* production_queue;
    short production_queue_size;
    short production_queue_count;
    unsigned char production_queue_enabled;
    RGE_Action_List* production_queue_actions;
    unsigned char production_queue_change_flag;
    unsigned char production_queue_auto_paused;
    short production_queue_need_attr;
    float build_pts;
    int unique_build_id;
    unsigned char culture;
    unsigned char built;
    int DoppleInstalled;
    unsigned long PriorMap1;
    unsigned long PriorMap2;
    unsigned long PriorMap3;
    long PriorTurn1;
    long PriorTurn2;
    long PriorTurn3;

protected:
    // Fully verified. Source of truth: t_b_obj.cpp.asm @ 0x004C83E0
    virtual int setup(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
};
static_assert(sizeof(TRIBE_Building_Object) == 0x204, "Size mismatch");
