#ifndef RMM_OBJ_H
#define RMM_OBJ_H

// Declarations for C:\\msdev\\work\\age1_x1\\rmm_obj.cpp.
// The base stack ABI is shared with the other random-map modules.

#include "rmm_obj_base_context.h"

struct _iobuf;
class RGE_Player;
class RGE_Player_Info;
class RGE_Sound;
class RGE_Scenario;
class RGE_Static_Object;
class TSound_Driver;
class TCommunications_Handler;

// The virtual order and world fields are the PDB-qualified surface used by
// this module. The complete class keeps the called slots stable.
class RGE_Game_World {
public:
    virtual uchar data_load_world(_iobuf*);
    virtual uchar data_load_terrain_tables(char*);
    virtual uchar data_load_players(char*);
    virtual uchar data_load_objects(char*);
    virtual uchar data_load_sounds(char*);
    virtual uchar data_load_color_tables(char*);
    virtual uchar data_load_sprites(char*);
    virtual void data_load_players_type(short, short, _iobuf*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short,
        short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual uchar init_player_type(int, short, uchar);
    virtual uchar init_player(int);
    virtual void load_player(int, uchar, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info*);
    virtual uchar new_random_game(RGE_Player_Info*);
    virtual void save(int);
    virtual void scenario_make_player(short, uchar, uchar, uchar, char*);
    virtual void scenario_make_map(int);
    virtual uchar load_scenario(RGE_Player_Info*);
    virtual uchar load_scenario(char*, RGE_Player_Info*);
    virtual void load_scenario1(int, RGE_Player_Info*);
    virtual void load_scenario2(int, RGE_Player_Info*);
    virtual void load_scenario3(int, RGE_Player_Info*);
    virtual void load_scenario4(int, RGE_Player_Info*);
    virtual void load_scenario5(int, RGE_Player_Info*);
    virtual void load_scenario6(int, RGE_Player_Info*);
    virtual void load_scenario7(int, RGE_Player_Info*);
    virtual void load_scenario8(int, RGE_Player_Info*);
    virtual void logStatus(_iobuf*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual uchar data_load(char*, char*);
    virtual uchar init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual uchar update();
    virtual uchar get_game_state();
    virtual uchar check_game_state();
    virtual uchar load_world(int);
    virtual uchar load_game(char*);
    virtual uchar new_game(RGE_Player_Info*, int);
    virtual uchar new_scenario(RGE_Player_Info*, int);
    virtual uchar save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual uchar save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(uchar);
    virtual void scenario_init(RGE_Game_World*);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);

    char gap_04[0x38];
    short player_num;
    char gap_3e[2];
    RGE_Player** players;
    char gap_44[0x0c];
    short terrain_num;
    short terrain_size;
    float** terrains;
    char gap_58[0xac];
};

class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Zone_Map;
class RGE_Zone_Map_List;

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

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
protected:
    RGE_Game_World* world;
    RGE_Object_Info info;
    uchar terrain_table[32];
    uchar add_terrain;

    void generate_objects(RGE_Object_Info_Line& line);
    void make_placement_stack(Map_Stack& stack, long x, long y,
        long unused, long range);
    uchar to_close(RGE_Object_Info_Line& line, long x, long y);
    void remove_area_from_lists(long left, long right, long y);
    void place_objects(RGE_Object_Info_Line& line);
    void place_avoid_objects(RGE_Object_Info_Line& line, long radius);
    void place_land_objects(RGE_Object_Info_Line& line, long x, long y,
        long inner_radius, long outer_radius, long index);
    void place_group(RGE_Object_Info_Line& line, long x, long y,
        RGE_Player* player);
    void place_cluster(RGE_Object_Info_Line& line, long x, long y,
        RGE_Player* player);
    void set_search_area(long x, long y, long radius, uchar fill);

public:
    RGE_RMM_Object_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Game_World* world,
        RGE_Object_Info* info, uchar add_terrain);
    void add_quick_obj(long object_id, long number_of_groups,
        long object_exclusion_zone);
    virtual uchar generate();
};

// The cluster routine uses the adjacent placement and alignment slots through
// this narrow, PDB-backed view of the same master-object vtable.
class RGE_RMM_Cluster_Master_View {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual uchar check_placement(RGE_Player*, float, float, int*,
        uchar, uchar, uchar, uchar, uchar, uchar);
    virtual uchar alignment(float&, float&, RGE_Game_World*, uchar);
    char gap_04[0x30 - 0x04];
    float radius_x;
    float radius_y;
};

#endif
