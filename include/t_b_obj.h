#ifndef AOE1_T_B_OBJ_H
#define AOE1_T_B_OBJ_H

// Declarations owned by the PDB source module t_b_obj.cpp.
// The TRIBE combat hierarchy comes from its canonical owner header.
#include "t_c_obj.h"

struct Production_Queue_Record;

class TRIBE_Master_Building_Object;
class TRIBE_Building_Object;

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    TRIBE_Building_Object(TRIBE_Master_Building_Object*, RGE_Player*,
                          float, float, float, int, int);
    TRIBE_Building_Object(TRIBE_Master_Building_Object*, RGE_Player*,
                          float, float, float, int);
    TRIBE_Building_Object(int, RGE_Game_World*, int);

    virtual ~TRIBE_Building_Object();
    virtual void recycle_out_of_game();
    virtual void destroy_obj();
    virtual uchar heal(float);
    virtual void set_object_state(uchar);
    virtual void rehook();
    virtual uchar update();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void save(int);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void rotate(long);
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);
    virtual void stop();
    virtual void cancel_object();

    unsigned char build(float);
    void add_to_production_queue(short, short);
    void remove_from_production_queue(short, short);
    void cancel_build();
    int work_status(short&, short&, short&, char*, short);
    short get_construction_progress();
    void advance_production_queue();
    void empty_production_queue();
    void enable_production_queue(int);
    void update_production_queue();
    int production_queue_status(short&, short&);
    long check(TRIBE_Building_Object**);
    void connect();
    void connect2();
    void lay_down_impassable_terrain();
    void lay_down_passable_terrain();
    virtual void take_building_attribute_from_owner();
    virtual void give_building_attribute_to_owner();
    void transform(TRIBE_Master_Building_Object*);

    Production_Queue_Record* production_queue; // +0x1C8
    short production_queue_size;               // +0x1CC
    short production_queue_count;              // +0x1CE
    unsigned char production_queue_enabled;    // +0x1D0
    unsigned char _pad_1D1[3];                 // +0x1D1
    RGE_Action_List* production_queue_actions; // +0x1D4
    unsigned char production_queue_change_flag; // +0x1D8
    unsigned char production_queue_auto_paused; // +0x1D9
    short production_queue_need_attr;           // +0x1DA
    float build_pts;                            // +0x1DC
    int unique_build_id;                        // +0x1E0
    unsigned char culture;                       // +0x1E4
    unsigned char built;                         // +0x1E5
    unsigned char _pad_1E6[2];                  // +0x1E6
    int DoppleInstalled;                        // +0x1E8
    unsigned long PriorMap1;                    // +0x1EC
    unsigned long PriorMap2;                    // +0x1F0
    unsigned long PriorMap3;                    // +0x1F4
    long PriorTurn1;                            // +0x1F8
    long PriorTurn2;                            // +0x1FC
    long PriorTurn3;                            // +0x200

protected:
    virtual int setup(TRIBE_Master_Building_Object*, RGE_Player*, float,
                      float, float);
    virtual int setup(int, RGE_Game_World*);
};

typedef char tribe_building_object_size_check[
    (sizeof(TRIBE_Building_Object) == 0x204) ? 1 : -1];

#endif  // AOE1_T_B_OBJ_H
