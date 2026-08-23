#ifndef RMM_OBJ_CONTEXT_H
#define RMM_OBJ_CONTEXT_H

// Canonical declarations for the original rmm_obj.cpp owner sequence.
// Layout and call slots come from rmm_base.cpp and rmm_obj.cpp listings.
// BINARY NOTE: base stack helpers use protected reference parameters.
// BINARY NOTE: make_placement_stack is a protected derived reference method.

typedef unsigned char uchar;

class RGE_Map;
class RGE_Random_Map_Module_List;
class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Zone_Map;
class RGE_Zone_Map_List;

struct Map_Stack {
    long x;
    long y;
    float cost;
    float total_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Tile {
    char gap_00[5];
    uchar terrain;
    char gap_06[0x18 - 0x06];
};

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

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
    char gap_44[0x10];
    float** terrains;
};

class RGE_Zone_Map {
public:
    char gap_00[0x408];
    uchar** zone_map_rows;
    uchar get_zone_info(long x, long y);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    long zone_map_num;
    RGE_Map* map;
    RGE_Zone_Map* get_zone_map(float* terrain, long flags, int& index);
    void delete_zone_maps();
};

class RGE_Map {
public:
    char gap_00[0x8DC4];
    union { RGE_Zone_Map_List* map_zones; RGE_Zone_Map_List* zone_map_list; };
    void* give_up_map_offsets();
    int get_map_width();
    int get_map_height();
    void set_terrain(void* player, RGE_Game_World* world,
        int a, int b, short width, short height,
        int c, int d, int e);
};

class RGE_Master_Static_Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual uchar can_place(RGE_Player*, float, float,
        int, int, int, int, int, int, int);
    char gap_04[0x30 - 0x04];
    float radius_x;
    float radius_y;
    char gap_38[0x66 - 0x38];
    short terrain;
};

class RGE_Player {
public:
    virtual void p00(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36();
    virtual void place_object(long object_id, float x, float y, int a, int b);
    char gap_04[0x24 - 0x04];
    RGE_Master_Static_Object** master_objects;
};

class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
    virtual uchar generate();

    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    union { long map_width; long width; };
    union { long map_height; long height; };
    float schedule;
    union { uchar* search_map; uchar* byte_map; };
    union { uchar** search_map_rows; uchar** rows; };
    Map_Stack* stack_array;
    union { Map_Stack** stack_offsets; void** map_rows; };

    RGE_Random_Map_Module(RGE_Map* map,
        RGE_Random_Map_Module* parent, uchar create_shared);

protected:
    void clear_stack();
    void init_stack(Map_Stack& stack);
    void deinit_stack(Map_Stack& stack);
    void add_stack_node(Map_Stack* last, Map_Stack* node);
    void remove_stack_node(Map_Stack* node);
    Map_Stack* pop_stack(Map_Stack& stack,
        long& out_col, long& out_x, float& out_cost);
};

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    RGE_Object_Info info;
    uchar terrain_table[32];
    uchar add_terrain;

    RGE_RMM_Object_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Game_World* world,
        RGE_Object_Info* info, uchar add_terrain);
    virtual uchar generate();
    void add_quick_obj(long object_id, long number_of_groups,
        long object_exclusion_zone);
    void generate_objects(RGE_Object_Info_Line& line);
    uchar to_close(RGE_Object_Info_Line* line, long x, long y);
    void set_search_area(long x, long y, long radius, uchar fill);
    void remove_area_from_lists(long left, long right, long y);
    void place_avoid_objects(RGE_Object_Info_Line& line, long radius);
    void place_objects(RGE_Object_Info_Line& line);
    void place_land_objects(RGE_Object_Info_Line& line, long x, long y,
        long inner_radius, long outer_radius, long index);
    void place_group(RGE_Object_Info_Line& line, long x, long y,
        RGE_Player* player);
    void place_cluster(RGE_Object_Info_Line& line, long x, long y,
        RGE_Player* player);

protected:
    void make_placement_stack(Map_Stack& stack, long x, long y,
        long unused, long range);
};

#endif
