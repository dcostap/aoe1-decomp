// first pass: natural `return new TRIBE_Scenario_Header(param_1);` shape against the EH/new prolog
// /GX was required to land the exact ctor-overload basin for the 0x1C allocation
#include "..\..\include\game_types.h"
#include "../../include/tribegam_context.h"

RGE_Scenario_Header* TRIBE_Game::new_scenario_header(RGE_Scenario* param_1) {
    return new TRIBE_Scenario_Header(param_1);
}
