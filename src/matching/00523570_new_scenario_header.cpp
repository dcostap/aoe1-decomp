// first pass: natural `return new TRIBE_Scenario_Header(param_1);` shape against the EH/new prolog
// /GX was required to land the exact ctor-overload basin for the 0x1C allocation
#include "..\..\include\game_types.h"

class RGE_Scenario;
class RGE_Scenario_Header {
public:
    void* vtable_ptr;
    int error_code;
    long version;
    unsigned long checksum;
    char* description;
};

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    int any_sp_victory;
    int active_player_count;

    TRIBE_Scenario_Header(RGE_Scenario* param_1);
};

class TRIBE_Game {
public:
    TRIBE_Scenario_Header* new_scenario_header(RGE_Scenario* param_1);
};

TRIBE_Scenario_Header* TRIBE_Game::new_scenario_header(RGE_Scenario* param_1) {
    return new TRIBE_Scenario_Header(param_1);
}
