#ifndef RMM_ELEV_CONTEXT_H
#define RMM_ELEV_CONTEXT_H

// Canonical declarations for the complete rmm_elev.cpp owner sequence.
// The random-map base and stack helper ABI follow the reviewed rmm_obj base
// surface. Tile, elevation-record, and map layouts follow the elevation PDB
// type records and the exact owner access patterns.

typedef unsigned char uchar;

class RGE_Map;
class RGE_Random_Map_Module;
class RGE_Random_Map_Module_List;
class RGE_Object_Node;

struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};

struct Map_Stack {
    long x;
    long y;
    float cost;
    float total_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();

    RGE_Object_Node* list;
    short number_of_objects;
    uchar pad_0A[2];
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar terrain_type : 5;
    uchar height : 3;
    uchar border_type : 4;
    uchar border_shape : 4;
    uchar last_drawn_as;
    uchar last_drawn_shape;
    uchar draw_as;
    uchar draw_attribute;
    uchar last_drawn_shape2;
    RGE_Object_List objects;
};

struct RGE_Elevation_Info_Line {
    long elevation_size;
    long elevation;
    long clumps;
    long spacing;
    long base_elevation;
    long base_terrain_type;
};

struct RGE_Elevation_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};

struct RGE_Elevation_Info {
    RGE_Elevation_Info_Line elevation[99];
    long elevation_num;
    RGE_Elevation_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

class RGE_Random_Map_Module {
protected:
    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    union { long map_width; long width; long size; };
    union { long map_height; long height; };
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
    ~RGE_Random_Map_Module();
    virtual uchar generate();
};

class RGE_Map {
public:
    void clean_elevation(long x, long y, long width, long height,
        uchar elevation);
};

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
protected:
    RGE_Elevation_Info info;

    uchar check_start_elevation(long x, long y, uchar terrain,
        uchar elevation, uchar range);
    uchar check_elevation(uchar elevation, long x, long y, long radius,
        uchar terrain, uchar min_elevation);
    void generate_modifiers();
    float fig_chance(long p0, long p1, long p2);
    long count_map_tiles(uchar tile_type);
    void link_stack_randomly(Map_Stack* stack);
    void remove_area_from_lists(long x, long y, long radius);
    uchar base_elevation_generate(RGE_Elevation_Info_Line line);

public:
    RGE_RMM_Elevation_Generator(RGE_Map* map,
        RGE_Random_Map_Module* module, RGE_Elevation_Info* info);
    virtual uchar generate();
};

#endif
