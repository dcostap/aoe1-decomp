#pragma once
#include "../common.h"
#include "map.h"

class RGE_Random_Map_Module;

// ----------------------------------------------------------------
// RGE_Random_Map_Module_List
// Size: 0x8
struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module * module; // 0x0
    RGE_Random_Map_Module_List * next; // 0x4
};

class RGE_Random_Map_Module {
public:
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

    RGE_Random_Map_Module(RGE_Map* param_1, RGE_Random_Map_Module* param_2, uchar param_3);
    virtual ~RGE_Random_Map_Module();
    virtual float get_schedule();
    virtual uchar generate();
    virtual uchar add_module(RGE_Random_Map_Module* param_1);
    virtual uchar remove_module(RGE_Random_Map_Module* param_1);
    virtual void create_shared_resources();
    virtual void destroy_shared_resources();
    virtual void update_child_resources();
    virtual void update_resources();
    virtual void update_child_map_info();
    virtual void update_map_info(RGE_Map* param_1);
    virtual void share_resources(uchar** param_1, uchar*** param_2, Map_Stack** param_3, Map_Stack*** param_4);
    virtual void init_stack(Map_Stack* param_1);
    virtual void deinit_stack(Map_Stack* param_1);
    virtual void push_stack(Map_Stack* param_1, long param_2, long param_3, float param_4, float param_5);
    virtual Map_Stack* pop_stack(Map_Stack* param_1, long* param_2, long* param_3, float* param_4);
    virtual void add_stack_node(Map_Stack* param_1, Map_Stack* param_2);
    virtual void remove_stack_node(Map_Stack* param_1);
    virtual void clear_stack();
    virtual uchar check_stack(Map_Stack* param_1);
    virtual void randomize_stack(Map_Stack* param_1);
    virtual uchar find_path(long param_1, long param_2, long* param_3, long* param_4, float* param_5);
    virtual uchar find_path(Map_Stack* param_1, long param_2, long param_3, long* param_4, long* param_5, float* param_6);
};

static_assert(sizeof(RGE_Random_Map_Module) == 0x30, "RGE_Random_Map_Module Size Mismatch");
static_assert(offsetof(RGE_Random_Map_Module, stack_offsets) == 0x2C, "RGE_Random_Map_Module Offset Mismatch");

