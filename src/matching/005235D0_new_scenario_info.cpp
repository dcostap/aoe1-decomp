// attempt log:
// first pass: EH-framed new helper with the observed 0x514C allocation and ctor(param_1, 0)
// target shape: allocate T_Scenario(0x514C), call ctor with (param_1, 0), return new object or 0

#include "../../include/tribegam_context.h"

#if 0
class RGE_Game_World;
class RGE_Scenario {
public:
    char pad_0[0x1990];
};

class TRIBE_Game {
public:
    RGE_Scenario* new_scenario_info(int param_1);
};

class T_Scenario : public RGE_Scenario {
public:
    char pad_0[0x514C - 0x1990];
    T_Scenario(int param_1, RGE_Game_World* zero);
};
#endif

RGE_Scenario* TRIBE_Game::new_scenario_info(int param_1) {
    return new T_Scenario(param_1, 0);
}
