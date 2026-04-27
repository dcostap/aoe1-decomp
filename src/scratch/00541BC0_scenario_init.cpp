// attempt 1: natural EH/new helper shape from the asm
// result: signature is void, not a returning helper; keep the body as a simple store
// attempt 2: explicit temp + null branch to mirror the asm's local/save/store pattern
// attempt 3: switch to explicit operator_new + conditional placement-construction, matching the helper call chain
// attempt 4: assign the placement-new result back into the temp so the post-branch store stays natural
// default flags first; if the body stays in the tiny non-EH basin, test the sibling-style /GX context and record it here

class RGE_Game_World;

void* __cdecl operator_new(unsigned int size);
void* __cdecl operator new(unsigned int size, void* place);

class RGE_Scenario {
public:
    char gap_0[0x1990];
    RGE_Scenario(RGE_Game_World* param_1);
};

class RGE_Game_World {
public:
    char gap_0[0x5C];
    RGE_Scenario* scenario;

    void scenario_init(RGE_Game_World* param_1);
};

void RGE_Game_World::scenario_init(RGE_Game_World* param_1) {
    RGE_Scenario* pScenario;

    pScenario = (RGE_Scenario*)operator_new(0x1990);
    if (pScenario != 0) {
        pScenario = new (pScenario) RGE_Scenario(param_1);
    }
    this->scenario = pScenario;
}
