#include "../../include/tscenaro_context.h"

TRIBE_Scenario_Header::TRIBE_Scenario_Header(T_Scenario* scenario)
    : RGE_Scenario_Header(scenario) {
    any_sp_victory = scenario->any_sp_victory();
    active_player_count = scenario->active_player_count();
}
