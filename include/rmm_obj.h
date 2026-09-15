#ifndef RMM_OBJ_H
#define RMM_OBJ_H

#include "rmm_base.h"

class RGE_Game_World;
class RGE_Player;

struct RGE_Object_Info_Line {
    long obj_id;
    long terrain;
    uchar group_flag;
    uchar scale_flag;
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

typedef char rge_object_info_line_size_check[
    (sizeof(RGE_Object_Info_Line) == 0x30) ? 1 : -1];
typedef char rge_land_point_info_line_size_check[
    (sizeof(RGE_Land_Point_Info_Line) == 0x10) ? 1 : -1];
typedef char rge_object_info_size_check[
    (sizeof(RGE_Object_Info) == 0x18C8) ? 1 : -1];

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
protected:
    RGE_Game_World* world;
    RGE_Object_Info info;
    uchar terrain_table[32];
    uchar add_terrain;

    void generate_objects(RGE_Object_Info_Line& info_line);
    void make_placement_stack(Map_Stack& stack, long x, long y,
        long inner_radius, long outer_radius);
    uchar to_close(RGE_Object_Info_Line& info_line, long x, long y);
    void remove_area_from_lists(long x, long y, long spacing);
    void place_objects(RGE_Object_Info_Line& info_line);
    void place_avoid_objects(RGE_Object_Info_Line& info_line, long inner_radius);
    void place_land_objects(RGE_Object_Info_Line& info_line, long map_x,
        long map_y, long inner_radius, long outer_radius, long land_id);
    void place_group(RGE_Object_Info_Line& info_line, long map_x, long map_y,
        RGE_Player* player);
    void place_cluster(RGE_Object_Info_Line& info_line, long map_x, long map_y,
        RGE_Player* player);
    void set_search_area(long x, long y, long radius, uchar set_num);

public:
    RGE_RMM_Object_Generator(RGE_Map* in_map,
        RGE_Random_Map_Module* parent_module, RGE_Game_World* in_world,
        RGE_Object_Info* in_info, uchar add_terrain_objects);
    void add_quick_obj(long obj_id, long count, long er);
    virtual uchar generate();
};

#endif
