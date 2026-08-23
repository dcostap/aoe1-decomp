#ifndef RMM_LAND_CONTEXT_H
#define RMM_LAND_CONTEXT_H

// Canonical declarations for the complete C:\\msdev\\work\\age1_x1\\rmm_land.cpp
// owner sequence. The land records, map-stack ABI, and generator offsets come
// from the PDB UDT records and the five direct owner ranges.
//
// PDB order: ctor 25-29, generate 33-51, check_terrain_and_zone 57-140,
// chance 146-208, and base_land_generate 213-353. Keep these owners in that
// order in the translation-unit wrapper.

typedef unsigned char uchar;

class RGE_Map;
class RGE_Player;
class RGE_Game_World;
class RGE_Random_Map_Module;
class RGE_Random_Map_Module_List;

// RGE_Tile terrain_type is the packed byte at +0x05. Land generation changes
// its low five bits and leaves the border bits in the same byte unchanged.
struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar terrain_type;
    uchar border_type;
    uchar last_drawn_as;
    uchar last_drawn_shape;
    uchar draw_as;
    uchar draw_attribute;
    uchar last_drawn_shape2;
    uchar objects[0x0C];
};

typedef char rmm_land_tile_size_check[
    (sizeof(RGE_Tile) == 0x18) ? 1 : -1];

struct Map_Stack {
    long x;
    long y;
    float cost;
    float total_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

typedef char rmm_land_stack_size_check[
    (sizeof(Map_Stack) == 0x18) ? 1 : -1];

struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};

class RGE_Random_Map_Module {
protected:
    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    uchar* search_map;
    uchar** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

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

typedef char rmm_land_module_size_check[
    (sizeof(RGE_Random_Map_Module) == 0x30) ? 1 : -1];

class RGE_Map {
public:
    void set_terrain(RGE_Player* player, RGE_Game_World* world,
        int x1, int y1, short x2, short y2,
        uchar terrain, uchar flag1, uchar flag2);
    void clean_terrain(long x, long y, long width, long height,
        uchar terrain);
};

struct RGE_Land_Info_Line {
    long land_size;                         // +0x00
    long terrain_type;                      // +0x04
    long x;                                  // +0x08
    long y;                                  // +0x0C
    long base_size;                         // +0x10
    long area;                              // +0x14
    uchar zone;                             // +0x18
    uchar pad_19[3];                        // +0x19
    long clumpiness_factor;                 // +0x1C
    long wall_1_avoidance_line;             // +0x20
    long wall_2_avoidance_line;             // +0x24
    long wall_3_avoidance_line;             // +0x28
    long wall_4_avoidance_line;             // +0x2C
    uchar wall_fade;                        // +0x30
    uchar pad_31[3];                        // +0x31
};

typedef char rmm_land_info_line_size_check[
    (sizeof(RGE_Land_Info_Line) == 0x34) ? 1 : -1];

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];            // +0x0000
    long land_num;                          // +0x141C
    uchar base_terrain;                     // +0x1420
    uchar pad_1421[3];                      // +0x1421
    long wall_1_avoidance_line;             // +0x1424
    long wall_2_avoidance_line;             // +0x1428
    long wall_3_avoidance_line;             // +0x142C
    long wall_4_avoidance_line;             // +0x1430
    uchar wall_fade;                        // +0x1434
    uchar pad_1435[3];                      // +0x1435
};

typedef char rmm_land_info_size_check[
    (sizeof(RGE_Land_Info) == 0x1438) ? 1 : -1];

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
protected:
    uchar check_terrain_and_zone(uchar unused, uchar land_id,
        long x, long y);
    uchar chance(long x, long y, long land_id);
    uchar base_land_generate();

public:
    RGE_Land_Info info;                     // +0x30

    RGE_RMM_Land_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Land_Info* info);
    virtual uchar generate();
};

typedef char rmm_land_generator_size_check[
    (sizeof(RGE_RMM_Land_Generator) == 0x1468) ? 1 : -1];

// The x87 path in check_terrain_and_zone multiplies area by this double and
// converts the ST0 result with __ftol. The original data symbol is retained.
extern double dbl_571ED0;

// All five random calls in base_land_generate use this ABI and file identity.
// Source lines are 299, 312, 315, 318, and 321 (0x138, 0x13B, 0x13E, 0x141).
extern "C" int __cdecl debug_rand(char* file, int line);

#endif
