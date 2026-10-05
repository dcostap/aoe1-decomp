#ifndef AOE1_T_B_OBJ_H
#define AOE1_T_B_OBJ_H

// The TRIBE combat hierarchy comes from its canonical owner header.
#include "t_c_obj.h"
#include "tm_b_obj.h"

struct Production_Queue_Record {
    short master_id;
    short unit_count;
};

typedef char production_queue_record_size_check[(sizeof(Production_Queue_Record) == 0x04) ? 1 : -1];

class TRIBE_Building_Object;

class TRIBE_Building_Object : public TRIBE_Combat_Object {
  public:
    TRIBE_Building_Object(
        TRIBE_Master_Building_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, int uID, int do_setup
    );
    TRIBE_Building_Object(
        TRIBE_Master_Building_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, int do_setup
    );
    TRIBE_Building_Object(int infile, RGE_Game_World* gworld, int do_setup);

    virtual ~TRIBE_Building_Object();
    virtual void recycle_out_of_game();
    virtual void destroy_obj();
    virtual uchar heal(float healing);
    virtual void set_object_state(uchar new_object_state);
    virtual void rehook();
    virtual uchar update();
    virtual int explore_terrain(RGE_Player* whos, uchar explore_type, int Override_LOS);
    virtual void save(int outfile);
    virtual void change_ownership(RGE_Player* new_owner);
    virtual void modify(float amount, uchar flag);
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void rotate(long amount);
    virtual void damage(
        int weapon_num, RGE_Armor_Weapon_Info* damage, float attack_modifier, RGE_Player* attacking_player,
        RGE_Static_Object* attacking_object
    );
    virtual void stop();
    virtual void cancel_object();

    unsigned char build(float build_amount);
    void add_to_production_queue(short master_id, short unit_count);
    void remove_from_production_queue(short master_id, short unit_count);
    void cancel_build();
    int work_status(short& work_type, short& work_target, short& progress, char* name, short name_size);
    short get_construction_progress();
    void advance_production_queue();
    void empty_production_queue();
    void enable_production_queue(int enabled);
    void update_production_queue();
    int production_queue_status(short& master_id, short& progress);
    long check(TRIBE_Building_Object** checks);
    void connect();
    void connect2();
    void lay_down_impassable_terrain();
    void lay_down_passable_terrain();
    virtual void take_building_attribute_from_owner();
    virtual void give_building_attribute_to_owner();
    void transform(TRIBE_Master_Building_Object* obj);

    Production_Queue_Record* production_queue;  // +0x1C8
    short production_queue_size;                // +0x1CC
    short production_queue_count;               // +0x1CE
    unsigned char production_queue_enabled;     // +0x1D0
    RGE_Action_List* production_queue_actions;  // +0x1D4
    unsigned char production_queue_change_flag; // +0x1D8
    unsigned char production_queue_auto_paused; // +0x1D9
    short production_queue_need_attr;           // +0x1DA
    float build_pts;                            // +0x1DC
    int unique_build_id;                        // +0x1E0
    unsigned char culture;                      // +0x1E4
    unsigned char built;                        // +0x1E5
    int DoppleInstalled;                        // +0x1E8
    unsigned long PriorMap1;                    // +0x1EC
    unsigned long PriorMap2;                    // +0x1F0
    unsigned long PriorMap3;                    // +0x1F4
    long PriorTurn1;                            // +0x1F8
    long PriorTurn2;                            // +0x1FC
    long PriorTurn3;                            // +0x200

  protected:
    virtual int setup(TRIBE_Master_Building_Object* tobj, RGE_Player* obj_owner, float x, float y, float z);
    virtual int setup(int infile, RGE_Game_World* gworld);
};

typedef char tribe_building_object_size_check[(sizeof(TRIBE_Building_Object) == 0x204) ? 1 : -1];

#endif // AOE1_T_B_OBJ_H
