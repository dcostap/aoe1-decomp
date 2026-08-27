#ifndef RMM_OBJ_H
#define RMM_OBJ_H

#include "m_s_obj.h"
#include "rmm_base.h"

class RGE_Game_World;
class RGE_Player;

struct RGE_Object_Info_Line {
    long obj_id;
    long terrain;
    uchar group_flag;
    uchar scale_flag;
    uchar gap_0a[2];
    long object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
    long object_exclusion_zone;
};

struct RGE_Land_Point_Info_Line {
    long x;
    long y;
    long id;
    long player_id;
};

struct RGE_Object_Info {
    RGE_Object_Info_Line objects[99];
    long object_num;
    RGE_Land_Point_Info_Line lands[99];
    long land_num;
};

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
protected:
    RGE_Game_World* world;
    RGE_Object_Info info;
    uchar terrain_table[32];
    uchar add_terrain;

    void generate_objects(RGE_Object_Info_Line&);
    void make_placement_stack(Map_Stack&, long, long, long, long);
    uchar to_close(RGE_Object_Info_Line&, long, long);
    void remove_area_from_lists(long, long, long);
    void place_objects(RGE_Object_Info_Line&);
    void place_avoid_objects(RGE_Object_Info_Line&, long);
    void place_land_objects(RGE_Object_Info_Line&, long, long, long, long,
                            long);
    void place_group(RGE_Object_Info_Line&, long, long, RGE_Player*);
    void place_cluster(RGE_Object_Info_Line&, long, long, RGE_Player*);
    void set_search_area(long, long, long, uchar);

public:
    RGE_RMM_Object_Generator(RGE_Map*, RGE_Random_Map_Module*,
                             RGE_Game_World*, RGE_Object_Info*, uchar);
    void add_quick_obj(long, long, long);
    virtual uchar generate();
};

#endif
