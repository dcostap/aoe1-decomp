#ifndef RMM_OBJ_BASE_CONTEXT_H
#define RMM_OBJ_BASE_CONTEXT_H

// PDB-backed rmm_obj.cpp view of RGE_Random_Map_Module.
// The PDB type record lists these fields and protected methods in this order.

typedef unsigned char uchar;

class RGE_Map;
class RGE_Random_Map_Module;
class RGE_Random_Map_Module_List;

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

struct RGE_Tile {
    char gap_00[5];
    uchar terrain;
    char gap_06[0x18 - 0x06];
};

class RGE_Random_Map_Module {
protected:
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

#endif
