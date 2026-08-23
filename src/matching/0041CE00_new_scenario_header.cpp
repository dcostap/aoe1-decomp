// attempt 1: natural `return new RGE_Scenario_Header(param_1);` shape
// result: default flags built a too-small body; the /GX context is justified for this new-helper family
// attempt 2: keep the type surface minimal but exact and let the EH/new prolog come from the compiler

#ifndef BASEGAME_GROUPED_TU
class RGE_Scenario_Header {
public:
    void* vtable_ptr;
    int error_code;
    long version;
    unsigned long checksum;
    char* description;

    RGE_Scenario_Header(int param_1);
};

class RGE_Base_Game {
public:
    RGE_Scenario_Header* new_scenario_header(int param_1);
};
#endif

RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(int param_1) {
    return new RGE_Scenario_Header(param_1);
}
