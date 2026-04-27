// attempt log:
// first pass: EH-framed new helper with the observed 0x1990 allocation and ctor(this->param, 0)
// second pass: give the scenario class an explicit 0x1990 surface so VC5 emits the requested allocation size
// target shape: allocate RGE_Scenario(0x1990), call ctor with (param_1, 0), return new object or 0

class RGE_Scenario;

class RGE_Base_Game {
public:
    RGE_Scenario* new_scenario_info(int param_1);
};

class RGE_Scenario {
public:
    char pad_0[0x1990];
    RGE_Scenario(int param_1, int zero);
};

RGE_Scenario* RGE_Base_Game::new_scenario_info(int param_1) {
    return new RGE_Scenario(param_1, 0);
}
