// attempt 1: straightforward RMM object-generator ctor with base ctor, vptr setup, world store, and info copy/zero path
// blocker watch: the shape should stay a natural ctor; if VC5 drifts, first probes are memcpy vs manual dword copy and whether the 0x632 copy wants a local pointer walk
#include "..\..\include\game_types.h"
#include <string.h>

class RGE_Map;
class RGE_Random_Map_Module;
class RGE_Game_World;

class RGE_Object_Info {
public:
    unsigned char data[0x18C8];
};

class RGE_Random_Map_Module {
public:
    void* vtable_ptr;
    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    void* map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    void* stack_array;
    void** stack_offsets;

    RGE_Random_Map_Module(RGE_Map* param_1, RGE_Random_Map_Module* param_2, unsigned char param_3);
};

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    RGE_Object_Info info;
    unsigned char terrain_table[32];
    unsigned char add_terrain;

    RGE_RMM_Object_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Game_World* param_3, RGE_Object_Info* param_4, unsigned char param_5);
};

RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Game_World* param_3, RGE_Object_Info* param_4, unsigned char param_5)
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->vtable_ptr = (void*)0x571ED8;
    this->world = param_3;
    if (param_4 != 0) {
        memcpy(&this->info, param_4, sizeof(RGE_Object_Info));
    } else {
        *(long*)((char*)&this->info + 0x1290) = 0;
        *(long*)((char*)&this->info + 0x18C4) = 0;
    }
    this->schedule = 3.0f;
    this->add_terrain = param_5;
}
