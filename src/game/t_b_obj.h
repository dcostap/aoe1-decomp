#pragma once
#include "common.h"

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

    virtual void recycle_out_of_game();                     // vt0[2]+0x8=0x4C8370
    virtual uchar update();                                 // vt0[9]+0x24=0x4C8A80
    virtual void rehook();                                  // vt0[11]+0x2C=0x4C8A60
    virtual void save(int param_1);                         // vt0[12]+0x30=0x4C8BC0
    virtual void change_ownership(RGE_Player* param_1);     // vt0[17]+0x44=0x4C8CB0
    virtual void modify(float param_1, uchar param_2);      // vt0[18]+0x48=0x4C8E60
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[22]+0x58=0x4C9710
    virtual void set_object_state(uchar param_1);           // vt0[23]+0x5C=0x4C8740
    virtual void destroy_obj();                             // vt0[26]+0x68=0x4C8690
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5); // vt0[28]+0x70=0x4C9770
    virtual void rotate(long param_1);                      // vt0[30]+0x78=0x4C9760
    virtual uchar heal(float param_1);                      // vt0[35]+0x8C=0x4C86C0
    virtual void stop();                                    // vt0[41]+0xA4=0x4CA0B0
    virtual int explore_terrain(RGE_Player* param_1, uchar param_2, int param_3); // vt0[54]+0xD8=0x4C8B80
    virtual int setup(int param_1, RGE_Game_World* param_2); // vt0[118]+0x1D8=0x4C8490
    virtual void cancel_object();                           // vt0[144]+0x240=0x4C9480
    virtual void take_building_attribute_from_owner();      // vt0[150]+0x258=0x4C85D0
    virtual void give_building_attribute_to_owner();        // vt0[151]+0x25C=0x4C8630
    virtual int setup(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[152]+0x260=0x4C83E0
    TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6, int param_7);
    TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    TRIBE_Building_Object(int param_1, RGE_Game_World* param_2, int param_3);
    ~TRIBE_Building_Object();
    void transform(TRIBE_Master_Building_Object* param_1);
    long check(TRIBE_Building_Object** param_1);
    void connect();
    void connect2();
    void lay_down_impassable_terrain();
    void lay_down_passable_terrain();
    void cancel_build();
    uchar build(float param_1);
    int work_status(short* param_1, short* param_2, short* param_3, char* param_4, short param_5);
    short get_construction_progress();
    void add_to_production_queue(short param_1, short param_2);
    void remove_from_production_queue(short param_1, short param_2);
    void advance_production_queue();
    void empty_production_queue();
    void enable_production_queue(int param_1);
    void update_production_queue();
    int production_queue_status(short* param_1, short* param_2);
};

static_assert(sizeof(TRIBE_Building_Object) == 0x204, "TRIBE_Building_Object Size Mismatch");

