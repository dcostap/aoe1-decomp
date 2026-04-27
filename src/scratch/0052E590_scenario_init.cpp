// attempt 1: natural `this->scenario = new T_Scenario(param_1, param_2);` shape
// result: default flags hit the same tiny basin as the sibling overloads
// attempt 2: testing the sibling-style /GX context once; keep it compact and stop early if it stays sticky
// attempt 3: explicit temp / placement-new spelling, matching the observed save-null-store shape
// result: still in the EH/prolog basin; the custom /GX context alone is not enough to finish this one cleanly

class RGE_Game_World;

void* __cdecl operator_new(unsigned int size);
void* operator new(unsigned int size, void* place);

class RGE_Scenario {
public:
    char gap_0[0x1990];
    RGE_Scenario(int param_1, RGE_Game_World* param_2);
};

class T_Scenario : public RGE_Scenario {
public:
    char gap_0[0x3FBC];
    T_Scenario(int param_1, RGE_Game_World* param_2);
};

class RGE_Game_World {
public:
    char gap_0[0x5C];
    T_Scenario* scenario;

    void scenario_init(int param_1, RGE_Game_World* param_2);
};

void RGE_Game_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    T_Scenario* pScenario;

    pScenario = (T_Scenario*)operator_new(0x514C);
    if (pScenario != 0) {
        pScenario = new (pScenario) T_Scenario(param_1, param_2);
    }
    this->scenario = pScenario;
}
