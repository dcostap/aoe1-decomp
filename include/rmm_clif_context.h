#ifndef RMM_CLIF_CONTEXT_H
#define RMM_CLIF_CONTEXT_H

// Canonical shared surface for the PDB-ordered rmm_clif.cpp owner wrapper.
// Field offsets follow the reviewed RGE_Random_Map_Module and cliff layout.

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);

class RGE_Map;
class RGE_Random_Map_Module;
class RGE_RMM_Cliffs_Generator;

struct Map_Stack {
    long x;
    long y;
    float cost;
    float total_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

typedef char RMM_Clif_Stack_Size_Check[
    (sizeof(Map_Stack) == 0x18) ? 1 : -1];

struct RGE_Tile {
    char gap_00[5];
    uchar terrain_code;
    char gap_06[0x18 - 0x06];
};

typedef char RMM_Clif_Tile_Size_Check[
    (sizeof(RGE_Tile) == 0x18) ? 1 : -1];

class RGE_Random_Map_Module {
protected:
    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    uchar* search_map;
    uchar** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void clear_stack();
    void init_stack(Map_Stack* stack);
    void push_stack(Map_Stack* stack, long x, long y, float cost,
                    float total_cost);
    Map_Stack* pop_stack(Map_Stack* stack, long* out_x, long* out_y,
                         float* out_cost);
    void remove_stack_node(Map_Stack* node);
    void randomize_stack(Map_Stack* stack);

public:
    RGE_Random_Map_Module();
    RGE_Random_Map_Module(RGE_Map* map, RGE_Random_Map_Module* parent,
                          uchar create_shared);
    ~RGE_Random_Map_Module();
    virtual uchar generate();
};

typedef char RMM_Clif_Base_Size_Check[
    (sizeof(RGE_Random_Map_Module) == 0x30) ? 1 : -1];

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual uchar do_terrain_brush(long, long, long, uchar);
    virtual uchar do_terrain_brush_stroke(long, long, long, long, long, uchar);
    virtual uchar do_elevation_brush(long, long, long, uchar);
    virtual uchar do_elevation_brush_stroke(long, long, long, long, long,
                                            uchar);
    virtual uchar do_cliff_brush(long, long, uchar, uchar);
    virtual uchar do_cliff_brush_stroke(long, long, long, long, uchar, uchar);
};

struct RGE_Cliffs_Hot_Spots {
    long x;
    long y;
    long radius;
};

struct RGE_Cliffs_Info {
    long number_of_cliffs;
    long number_of_cliffs_variance;
    long average_cliff_size;
    long cliff_size_variance;
    long cliff_terrain_spacing;
    long cliff_to_cliff_spacing;
    RGE_Cliffs_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

typedef char RMM_Clif_Info_Size_Check[
    (sizeof(RGE_Cliffs_Info) == 0x4C0) ? 1 : -1];

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    virtual uchar generate();

    RGE_Cliffs_Info info;
    Map_Stack valid_cliff_sites;

    RGE_RMM_Cliffs_Generator(RGE_Map* map, RGE_Random_Map_Module* module,
                             RGE_Cliffs_Info cliffs_info);
    void setup_cliff_maps();
    void generate_cliff();
    uchar check_for_valid_cliff_site(long direction, long& y,
                                     long& valid_height, long index);
    void invalidate_cliff_area(long x, long y, long spacing);
};

typedef char RMM_Clif_Generator_Size_Check[
    (sizeof(RGE_RMM_Cliffs_Generator) == 0x508) ? 1 : -1];

#endif
