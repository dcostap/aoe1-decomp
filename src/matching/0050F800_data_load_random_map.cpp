// first pass: use the natural new+ctor assignment shape against the EH prolog
// default flags landed in the wrong size basin; /GX was needed for the exact EH/new prolog
#include "..\..\include\game_types.h"

#ifndef TMAP_GROUP_CONTEXT
class TRIBE_RMM_Database_Controller {
public:
    char pad_00[0x4F5C];
    TRIBE_RMM_Database_Controller(int param_1);
};
class TRIBE_Map {
public:
    char pad_00[0x8DBC];
    TRIBE_RMM_Database_Controller* random_map_controller;

    void data_load_random_map(int param_1);
};
#endif

void TRIBE_Map::data_load_random_map(int param_1) {
    this->random_map_controller = new TRIBE_RMM_Database_Controller(param_1);
}
