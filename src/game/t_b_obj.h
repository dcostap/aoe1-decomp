#pragma once
#include "../common.h"

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    Production_Queue_Record* production_queue; // 0x1C8
    short production_queue_size;             // 0x1CC
    short production_queue_count;            // 0x1CE
    uchar production_queue_enabled;          // 0x1D0
    RGE_Action_List* production_queue_actions; // 0x1D4
    uchar production_queue_change_flag;      // 0x1D8
    uchar production_queue_auto_paused;      // 0x1D9
    short production_queue_need_attr;        // 0x1DA
    float build_pts;                         // 0x1DC
    int unique_build_id;                     // 0x1E0
    uchar culture;                           // 0x1E4
    uchar built;                             // 0x1E5
    int DoppleInstalled;                     // 0x1E8
    ulong PriorMap1;                         // 0x1EC
    ulong PriorMap2;                         // 0x1F0
    ulong PriorMap3;                         // 0x1F4
    long PriorTurn1;                         // 0x1F8
    long PriorTurn2;                         // 0x1FC
    long PriorTurn3;                         // 0x200

    TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6, int param_7);
    TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    TRIBE_Building_Object(int param_1, RGE_Game_World* param_2, int param_3);
    virtual ~TRIBE_Building_Object();
    virtual void recycle_out_of_game();
    virtual int setup(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(int param_1, RGE_Game_World* param_2);
    virtual void take_building_attribute_from_owner();
    virtual void give_building_attribute_to_owner();
    virtual void destroy_obj();
    virtual uchar heal(float param_1);
    virtual void set_object_state(uchar param_1);
    virtual void rehook();
    virtual uchar update();
    virtual int explore_terrain(RGE_Player* param_1, uchar param_2, int param_3);
    virtual void save(int param_1);
    virtual void change_ownership(RGE_Player* param_1);
    virtual void modify(float param_1, uchar param_2);
    virtual void transform(TRIBE_Master_Building_Object* param_1);
    virtual long check(TRIBE_Building_Object** param_1);
    virtual void connect();
    virtual void connect2();
    virtual void lay_down_impassable_terrain();
    virtual void lay_down_passable_terrain();
    virtual void cancel_object();
    virtual void cancel_build();
    virtual uchar build(float param_1);
    virtual int work_status(short* param_1, short* param_2, short* param_3, char* param_4, short param_5);
    virtual short get_construction_progress();
    virtual void copy_obj(RGE_Master_Static_Object* param_1);
    virtual void rotate(long param_1);
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
    virtual void add_to_production_queue(short param_1, short param_2);
    virtual void remove_from_production_queue(short param_1, short param_2);
    virtual void advance_production_queue();
    virtual void empty_production_queue();
    virtual void enable_production_queue(int param_1);
    virtual void update_production_queue();
    virtual int production_queue_status(short* param_1, short* param_2);
    virtual void stop();
};

static_assert(sizeof(TRIBE_Building_Object) == 0x204, "TRIBE_Building_Object Size Mismatch");
static_assert(offsetof(TRIBE_Building_Object, PriorTurn3) == 0x200, "TRIBE_Building_Object Offset Mismatch");

