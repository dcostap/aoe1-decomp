// attempt 1: natural `return new TRIBE_Scenario_Header(param_1);` shape
// result: default flags were too small; this sibling also needs the /GX new-helper basin
// attempt 2: keep the type surface exact and let the compiler own the constructor/prolog lowering

#include "../../include/tribegam_context.h"

#if 0
class RGE_Scenario_Header {
public:
    void* vtable_ptr;
    int error_code;
    long version;
    unsigned long checksum;
    char* description;

    RGE_Scenario_Header(int param_1);
};

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    int any_sp_victory;
    int active_player_count;

    TRIBE_Scenario_Header(int param_1);
};

class TRIBE_Game {
public:
    RGE_Scenario_Header* new_scenario_header(int param_1);
};
#endif

RGE_Scenario_Header* TRIBE_Game::new_scenario_header(int param_1) {
    return new TRIBE_Scenario_Header(param_1);
}
