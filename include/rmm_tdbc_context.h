#ifndef RMM_TDBC_CONTEXT_H
#define RMM_TDBC_CONTEXT_H

// Canonical shared declarations for the complete rmm_tdbc.cpp owner sequence.
// The controller and record offsets are the period PDB layout used by the
// target module. The wrapper defines RMM_TDBC_SHARED_CONTEXT before inclusion.

typedef unsigned char uchar;

class RGE_Game_World;
class RGE_Random_Map_Module;
class RGE_Random_Map_Module_List;
class RGE_RMM_Database_Controller;
class TRIBE_RMM_Database_Controller;

struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};

class RGE_Map {
public:
    char gap_00[8];
    long map_width;
    long map_height;
};

class RGE_Random_Map_Module {
protected:
    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    void* map_row_offset;
    union { long map_width; long map_w; };
    union { long map_height; long map_h; };
    float schedule;
    uchar* search_map;
    uchar** search_map_rows;
    void* stack_array;
    void* stack_offsets;

public:
    RGE_Random_Map_Module();
    RGE_Random_Map_Module(RGE_Map*, RGE_Random_Map_Module*, uchar);
    virtual ~RGE_Random_Map_Module();
    virtual uchar generate();
};

typedef char rmm_tdbc_module_size_check[
    (sizeof(RGE_Random_Map_Module) == 0x30) ? 1 : -1];

struct RGE_Land_Info_Line {
    long land_size;
    long terrain_type;
    long x;
    long y;
    long base_size;
    long area;
    uchar zone;
    uchar pad_19[3];
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
    uchar pad_31[3];
};

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];
    long land_num;
    uchar base_terrain;
    uchar pad_1421[3];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
    uchar pad_1435[3];
};

typedef char rmm_tdbc_land_info_size_check[
    (sizeof(RGE_Land_Info) == 0x1438) ? 1 : -1];

struct RGE_Terrain_Info_Line {
    long terrain_size;
    long terrain_generated;
    long terrain_type;
    long clumps;
    long spacing;
    long base_terrain_type;
    long clumpiness_factor;
    long avoid_hot_spots;
};

struct RGE_Terrain_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};

struct RGE_Terrain_Info {
    RGE_Terrain_Info_Line terrain[99];
    long terrain_num;
    RGE_Terrain_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

typedef char rmm_tdbc_terrain_info_size_check[
    (sizeof(RGE_Terrain_Info) == 0x1298) ? 1 : -1];

struct RGE_Land_Data {
    long map_edge_buffer[4];
    long map_edge_fade;
    long land_placement_edge;
    long base_terrain;
    long grown_land_percent;
    long id;
    long land_num;
    void* land;
};

struct RGE_Map_Data_Entry {
    long map_id;
    RGE_Land_Data land_info;
    uchar terrain_info[8];
    uchar object_info[8];
    uchar elevation_info[8];
};

struct RGE_Map_Data {
    long map_num;
    RGE_Map_Data_Entry* maps;
};

struct RGE_Land_Point_Info_Line {
    long x;
    long y;
    long id;
    long player_id;
};

struct RGE_Object_Info_Line {
    long obj_id;
    long terrain;
    uchar group_flag;
    uchar scale_flag;
    uchar pad_0A[2];
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

struct RGE_Object_Info {
    RGE_Object_Info_Line objects[99];
    long object_num;
    RGE_Land_Point_Info_Line lands[99];
    long land_num;
};

typedef char rmm_tdbc_object_info_size_check[
    (sizeof(RGE_Object_Info) == 0x18C8) ? 1 : -1];

struct RGE_Elevation_Info {
    uchar data[0x948];
    long count;
    uchar tail[0x634];
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    long map_type;
    long number_of_players;
    RGE_Land_Info land_info;
    RGE_Terrain_Info terrain_info;
    RGE_Object_Info object_info;
    RGE_Elevation_Info elevation_info;
    RGE_Map_Data map_info;

    RGE_RMM_Database_Controller(int);
    RGE_RMM_Database_Controller(char*, char*, char*, char*);
    virtual ~RGE_RMM_Database_Controller();
    virtual uchar generate();

protected:
    virtual void add_land_module(uchar);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();

public:
    virtual uchar init(RGE_Map*, RGE_Game_World*, uchar, long, uchar);
    virtual uchar de_init();
};

typedef char rmm_tdbc_controller_size_check[
    (sizeof(RGE_RMM_Database_Controller) == 0x4F5C) ? 1 : -1];

class TRIBE_Game {
public:
    int randomizePositions();
    int startingAge();
};

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    TRIBE_RMM_Database_Controller(char*, char*, char*, char*);
    TRIBE_RMM_Database_Controller(int);
    virtual uchar init(RGE_Map*, RGE_Game_World*, uchar, long, uchar);
    virtual uchar de_init();

protected:
    virtual void add_land_module(uchar);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();

protected:
    void add_shallows_module();

public:
    virtual uchar generate();
};

struct RGE_Cliffs_Hot_Spots {
    long x;
    long y;
    long radius;
};

struct RGE_Cliffs_Info {
    long number_of_cliffs_variance;
    long average_cliff_size;
    long cliff_size_variance;
    long cliff_terrain_spacing;
    long cliff_to_cliff_spacing;
    RGE_Cliffs_Hot_Spots hot_spots[99];
    long tail;
    long hot_spot_num;
};

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    RGE_Cliffs_Info info;
    uchar tail[0x18];
    RGE_RMM_Cliffs_Generator(RGE_Map*, RGE_Random_Map_Module*, RGE_Cliffs_Info);
};

struct RGE_Shallows_Info_Line {
    long x;
    long y;
};

struct RGE_Shallows_Info {
    RGE_Shallows_Info_Line shallows[99];
    long shallows_num;
};

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module {
public:
    RGE_Shallows_Info info;
    RGE_RMM_Shallows_Generator(RGE_Map*, RGE_Random_Map_Module*,
                               RGE_Shallows_Info*);
    virtual uchar generate();
};

typedef char rmm_tdbc_shallows_generator_size_check[
    (sizeof(RGE_RMM_Shallows_Generator) == 0x34C) ? 1 : -1];

class TDebuggingLog {
public:
    void Log(char*, ...);
};

extern TDebuggingLog* L;
extern void* rge_base_game;
extern "C" int __cdecl debug_rand(char*, int);
extern "C" void __cdecl DebugLog_Log(void*, char*, int);
extern "C" void __cdecl Log(void*, const char*, ...);
extern double rmm_land_scale;
extern float DAT_00571f48;
extern float DAT_00571f4c;
extern float DAT_00571f50;
extern float DAT_00571f54;
extern double DAT_00571f38;
extern double DAT_00571f40;
extern TDebuggingLog* debug_log;

#endif
