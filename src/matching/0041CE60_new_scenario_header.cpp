// first pass: natural `return new RGE_Scenario_Header(param_1);` shape against the EH/new prolog
// /GX was required to land the exact ctor-overload basin for the 0x14 allocation
#include "..\..\include\game_types.h"

class RGE_Scenario;

RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(RGE_Scenario* param_1) {
    return new RGE_Scenario_Header(param_1);
}
