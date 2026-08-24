// 0050F860 TRIBE_Map::load_random_map
// Source: tmap.cpp lines 199-201
// public: virtual void __thiscall TRIBE_Map::load_random_map(char*,char*,char*,char*)
//
// Attempt log:
// Probe 1: natural new-expression, default flags

#include "..\..\include\game_globals.h"

#ifndef TMAP_GROUP_CONTEXT
class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
};
#endif

#ifndef TMAP_GROUP_CONTEXT
class TRIBE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    char _size_pad[0x4F5C - 4];
    TRIBE_RMM_Database_Controller(char* param_2, char* param_3, char* param_4, char* param_1);
};
#endif

#ifndef TMAP_GROUP_CONTEXT
class TRIBE_Map {
public:
    char _gap_00[0x8DBC];
    void* random_map; // +0x8DBC (4)

    void load_random_map(char* param_1, char* param_2, char* param_3, char* param_4);
};
#endif

void TRIBE_Map::load_random_map(char* param_1, char* param_2, char* param_3, char* param_4)
{
    TRIBE_RMM_Database_Controller* ctrl = new TRIBE_RMM_Database_Controller(param_2, param_3, param_4, param_1);
    this->random_map = ctrl;
}
