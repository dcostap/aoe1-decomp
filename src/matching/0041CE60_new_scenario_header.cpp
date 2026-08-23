// first pass: natural `return new RGE_Scenario_Header(param_1);` shape against the EH/new prolog
// /GX was required to land the exact ctor-overload basin for the 0x14 allocation
#include "..\..\include\game_types.h"

class RGE_Scenario;
#ifndef BASEGAME_GROUPED_TU
class RGE_Scenario_Header {
public:
    void* vtable_ptr;
    int error_code;
    long version;
    unsigned long checksum;
    char* description;

    RGE_Scenario_Header(RGE_Scenario* param_1);
};

class RGE_Base_Game {
public:
    RGE_Scenario_Header* new_scenario_header(RGE_Scenario* param_1);
};
#endif

RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(RGE_Scenario* param_1) {
    return new RGE_Scenario_Header(param_1);
}
