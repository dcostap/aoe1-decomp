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
    void update_map_info(RGE_Map*);
    void share_resources(uchar**, uchar***, Map_Stack**, Map_Stack***);

    void init_stack(Map_Stack&);
    void deinit_stack(Map_Stack&);
    void push_stack(Map_Stack&, long, long, float, float);
    Map_Stack* pop_stack(Map_Stack&, long&, long&, float&);
    void add_stack_node(Map_Stack*, Map_Stack*);
    void remove_stack_node(Map_Stack*);
    void clear_stack();
    uchar check_stack(Map_Stack*);
    void randomize_stack(Map_Stack*);
    uchar find_path(long, long, long&, long&, float*);
    uchar find_path(Map_Stack&, long, long, long&, long&, float*);
    uchar add_module(RGE_Random_Map_Module*);
    uchar remove_module(RGE_Random_Map_Module*);
    float get_schedule();

public:
    RGE_Random_Map_Module();
    RGE_Random_Map_Module(RGE_Map*, RGE_Random_Map_Module*, uchar);
    ~RGE_Random_Map_Module();
    virtual uchar generate();
};

typedef char rmm_base_module_size_check[
    (sizeof(RGE_Random_Map_Module) == 0x30) ? 1 : -1];
typedef char rmm_base_stack_size_check[(sizeof(Map_Stack) == 0x18) ? 1 : -1];

#endif
