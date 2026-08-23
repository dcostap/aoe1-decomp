#ifndef RMM_TERR_CONTEXT_H
#define RMM_TERR_CONTEXT_H

// Canonical context for the complete C:\\msdev\\work\\age1_x1\\rmm_terr.cpp
// owner sequence. Layout facts come from the PDB UDT records and direct
// terrain-generator references. Keep this surface shared by every owner.

typedef unsigned char uchar;

class TShape;
class RGE_Sound;
class RGE_Map;
class RGE_Random_Map_Module;
class RGE_RMM_Terrain_Generator;
class RGE_Zone_Map;
class RGE_Zone_Map_List;
struct RGE_Random_Map_Module_List;

#include "map_context.h"

// RGE_Tile is the PDB RGE_Tile record. The terrain/elevation byte is +0x05,
// the border byte is +0x06, and the record stride is 0x18.
struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar terrain_type : 5;
    uchar elevation : 3;
    uchar border_type : 4;
    uchar border_shape : 4;
    uchar last_drawn_as;
    uchar last_drawn_shape;
    uchar draw_as;
    uchar draw_attribute;
    uchar last_drawn_shape2;
    uchar objects[12];
};

typedef char rmm_terr_tile_size_check[(sizeof(RGE_Tile) == 0x18) ? 1 : -1];

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

typedef char rmm_terr_info_line_size_check[
    (sizeof(RGE_Terrain_Info_Line) == 0x20) ? 1 : -1];

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

typedef char rmm_terr_info_size_check[
    (sizeof(RGE_Terrain_Info) == 0x1298) ? 1 : -1];

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

typedef char rmm_terr_stack_size_check[(sizeof(Map_Stack) == 0x18) ? 1 : -1];

// The generator uses the indexed zone-map lookup and the terrain-map lookup.
// The other fields preserve the PDB-owned 0x51C-byte zone-map layout.
class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    uchar* zone_map;
    uchar** zone_map_rows;
    uchar zone_info[257];
    uchar gap_50C[3];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;

    uchar get_zone_info(long x, long y);
};

typedef char rmm_terr_zone_map_size_check[
    (sizeof(RGE_Zone_Map) == 0x51C) ? 1 : -1];

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    long zone_map_num;
    RGE_Map* map;

    long create_zone_map(float* terrain_info, long terrain_info_num);
    RGE_Zone_Map* get_zone_map(long zone_map_index);
};

typedef char rmm_terr_zone_list_size_check[
    (sizeof(RGE_Zone_Map_List) == 0x0C) ? 1 : -1];

struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};

// PDB RGE_Random_Map_Module surface. Unions keep reviewed owner aliases at
// the same binary offsets without adding fields to the 0x30-byte base.
class RGE_Random_Map_Module {
protected:
    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    union {
        RGE_Tile** map_row_offset;
        void* tileInfo;
        // check_borders uses the same +0x10 row table as a byte view.
        uchar** rows;
    };
    union {
        long map_width;
        long width;
    };
    union {
        long map_height;
        long height;
    };
    float schedule;
    union {
        uchar* search_map;
        uchar* byte_map;
    };
    // The modifier/search rows are the distinct +0x24 field.
    uchar** search_map_rows;
    Map_Stack* stack_array;
    union {
        Map_Stack** stack_offsets;
        void** stack_arrays;
    };

    void create_shared_resources();
    void destroy_shared_resources();
    void update_child_resources();
    void update_resources();
    void update_child_map_info();
    void update_map_info(RGE_Map* map);
    void share_resources(uchar** search_map, uchar*** search_map_rows,
        Map_Stack** stack_array, Map_Stack*** stack_offsets);
    void init_stack(Map_Stack* stack);
    void deinit_stack(Map_Stack* stack);
    void push_stack(Map_Stack* stack, long x, long y, float cost,
        float total_cost);
    Map_Stack* pop_stack(Map_Stack* stack, long* x, long* y, float* cost);
    void add_stack_node(Map_Stack* last, Map_Stack* node);
    void remove_stack_node(Map_Stack* node);
    void clear_stack();
    uchar check_stack(Map_Stack* stack);
    void randomize_stack(Map_Stack* stack);
    uchar find_path(long x, long y, long* out_x, long* out_y,
        float* out_cost);
    uchar find_path(Map_Stack* stack, long x, long y, long* out_x,
        long* out_y, float* out_cost);
    uchar add_module(RGE_Random_Map_Module* module);
    uchar remove_module(RGE_Random_Map_Module* module);
    float get_schedule();

public:
    RGE_Random_Map_Module();
    RGE_Random_Map_Module(RGE_Map* map,
        RGE_Random_Map_Module* parent, uchar create_shared);
    virtual ~RGE_Random_Map_Module();
    virtual uchar generate();
};

typedef char rmm_terr_module_size_check[
    (sizeof(RGE_Random_Map_Module) == 0x30) ? 1 : -1];

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
protected:
    RGE_Terrain_Info info;
    RGE_Zone_Map* map_zone;

    uchar water(uchar terrain);
    void check_borders();
    uchar check_terrain(uchar target, long x, long y, long spacing,
        uchar base_terrain);
    void generate_modifiers();
    float fig_chance(long count, long x, long y, long clumpiness_factor);
    long count_map_tiles(uchar terrain);
    void link_stack_randomly(Map_Stack* loc_stack, uchar base_terrain_type);
    void remove_area_from_lists(long x, long y, long spacing);
    uchar base_terrain_generate(RGE_Terrain_Info_Line info_line);

public:
    RGE_RMM_Terrain_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Terrain_Info* info);
    virtual uchar generate();
};

typedef char rmm_terr_generator_size_check[
    (sizeof(RGE_RMM_Terrain_Generator) == 0x12CC) ? 1 : -1];

extern "C" int __cdecl debug_rand(char* file, int line);

#endif
