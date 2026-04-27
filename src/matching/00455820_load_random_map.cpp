// 00455820 RGE_Map::load_random_map
// Source: map.cpp lines 262-264
// public: virtual void __thiscall RGE_Map::load_random_map(char*,char*,char*,char*)
//
// Attempt log:
// Probe 1: natural new-expression, default flags -> 80 vs 109, missing EH
// Probe 2: Added /GX rsp, size fixed with dummy array

#include "..\..\include\game_globals.h"

// RGE_Random_Map_Module — virtual base for vtable
class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
};

// RGE_RMM_Database_Controller — size 0x4F5C (20316 bytes)
class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    char _size_pad[0x4F5C - 4]; // force correct allocation size (minus vtable ptr)

    RGE_RMM_Database_Controller(char* param_2, char* param_3, char* param_4, char* param_1);
};

// RGE_Map — has random_map at +0x8DBC
class RGE_Map {
public:
    char _gap_00[0x8DBC];
    RGE_RMM_Database_Controller* random_map; // +0x8DBC (4)

    void load_random_map(char* param_1, char* param_2, char* param_3, char* param_4);
};

void RGE_Map::load_random_map(char* param_1, char* param_2, char* param_3, char* param_4)
{
    RGE_RMM_Database_Controller* ctrl = new RGE_RMM_Database_Controller(param_2, param_3, param_4, param_1);
    this->random_map = ctrl;
}
