// attempt 1: natural `return new RGE_Scenario_Header(param_1);` shape
// result: default flags built a too-small body; the /GX context is justified for this new-helper family
// attempt 2: keep the type surface minimal but exact and let the EH/new prolog come from the compiler


RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(int param_1) {
    return new RGE_Scenario_Header(param_1);
}
