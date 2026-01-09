#pragma once
#include "common.h"

// ----------------------------------------------------------------
// RGE_Random_Map_Module_List
// Size: 0x8
struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module * module; // 0x0
    RGE_Random_Map_Module_List * next; // 0x4
};

class RGE_Random_Map_Module {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    RGE_Random_Map_Module* parent;           // 0x4
    RGE_Random_Map_Module_List* list;        // 0x8
    RGE_Map* map;                            // 0xC
    RGE_Tile** map_row_offset;               // 0x10
    long map_width;                          // 0x14
    long map_height;                         // 0x18
    float schedule;                          // 0x1C
    uchar* search_map;                       // 0x20
    uchar** search_map_rows;                 // 0x24
    Map_Stack* stack_array;                  // 0x28
    Map_Stack** stack_offsets;               // 0x2C

    virtual uchar generate();                               // vt0[0]+0x0=0x4808D0
    RGE_Random_Map_Module(RGE_Map* param_1, RGE_Random_Map_Module* param_2, uchar param_3);
    ~RGE_Random_Map_Module();
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
};

static_assert(sizeof(RGE_Random_Map_Module) == 0x30, "RGE_Random_Map_Module Size Mismatch");

