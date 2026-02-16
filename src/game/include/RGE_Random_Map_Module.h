#pragma once
#include "common.h"
#include "RGE_Random_Map_Module_List.h"
#include "Map_Stack.h"

class RGE_Random_Map_Module {
public:
    RGE_Random_Map_Module();
    RGE_Random_Map_Module(RGE_Map* param_1, RGE_Random_Map_Module* param_2, uchar param_3);
    ~RGE_Random_Map_Module();

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

    float get_schedule();
    uchar add_module(RGE_Random_Map_Module* param_1);
    uchar remove_module(RGE_Random_Map_Module* param_1);
    void create_shared_resources();
    void destroy_shared_resources();
    void update_child_resources();
    void update_resources();
    void update_child_map_info();
    void update_map_info(RGE_Map* param_1);
    void share_resources(uchar** param_1, uchar*** param_2, Map_Stack** param_3, Map_Stack*** param_4);
    void init_stack(Map_Stack* param_1);
    void deinit_stack(Map_Stack* param_1);
    void push_stack(Map_Stack* param_1, long param_2, long param_3, float param_4, float param_5);
    Map_Stack* pop_stack(Map_Stack* param_1, long* param_2, long* param_3, float* param_4);
    void add_stack_node(Map_Stack* param_1, Map_Stack* param_2);
    void remove_stack_node(Map_Stack* param_1);
    void clear_stack();
    uchar check_stack(Map_Stack* param_1);
    void randomize_stack(Map_Stack* param_1);
    uchar find_path(long param_1, long param_2, long* param_3, long* param_4, float* param_5);
    uchar find_path(Map_Stack* param_1, long param_2, long param_3, long* param_4, long* param_5, float* param_6);

    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;
};
static_assert(sizeof(RGE_Random_Map_Module) == 0x30, "Size mismatch");
