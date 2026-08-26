// attempt 1: natural `return new TRIBE_Scenario_Header(param_1);` shape
// result: default flags were too small; this sibling also needs the /GX new-helper basin
// attempt 2: keep the type surface exact and let the compiler own the constructor/prolog lowering

#include "../../include/tribegam_context.h"

RGE_Scenario_Header* TRIBE_Game::new_scenario_header(int param_1) {
    return new TRIBE_Scenario_Header(param_1);
}
