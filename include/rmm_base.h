#ifndef AOE1_RMM_BASE_H
#define AOE1_RMM_BASE_H

// Canonical random-map base ABI. Map and logging owners stay external.

typedef unsigned char uchar;

class RGE_Map;
struct RGE_Tile;
class RGE_Random_Map_Module;

struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
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
    void update_map_info(RGE_Map* new_map);
    void share_resources(uchar** search_map_pointer, uchar*** search_map_rows_pointer,
        Map_Stack** stack_array_pointer, Map_Stack*** stack_offsets_pointer);

    void init_stack(Map_Stack& stack);
    void deinit_stack(Map_Stack& stack);
    void push_stack(Map_Stack& stack, long x, long y, float cost, float tot_cost);
    Map_Stack* pop_stack(Map_Stack& stack, long& x, long& y, float& cost);
    void add_stack_node(Map_Stack* stack, Map_Stack* new_stack);
    void remove_stack_node(Map_Stack* stack);
    void clear_stack();
    uchar check_stack(Map_Stack* stack);
    void randomize_stack(Map_Stack* stack);
    uchar find_path(long x, long y, long& end_x, long& end_y, float* terrain);
    uchar find_path(Map_Stack& path_stack, long x, long y, long& end_x, long& end_y, float* terrain);
    uchar add_module(RGE_Random_Map_Module* module);
    uchar remove_module(RGE_Random_Map_Module* module);
    float get_schedule();

public:
    RGE_Random_Map_Module();
    RGE_Random_Map_Module(RGE_Map* in_map, RGE_Random_Map_Module* parent_module,
        uchar resources_needed);
    ~RGE_Random_Map_Module();
    virtual uchar generate();
};

typedef char rmm_base_module_size_check[
    (sizeof(RGE_Random_Map_Module) == 0x30) ? 1 : -1];
typedef char rmm_base_stack_size_check[(sizeof(Map_Stack) == 0x18) ? 1 : -1];

#endif
