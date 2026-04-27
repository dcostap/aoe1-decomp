// attempt 1: natural `this->scenario = new T_Scenario(param_1);` shape
// result: default flags built the same tiny non-EH basin as the sibling world_init case
// attempt 2: testing the /GX world-init context next; keep the note compact and explicit
// attempt 3: the 0x514C allocation means the local T_Scenario stub needs the full post-base padding
// attempt 4: try an explicit temp plus if/else so the EH branch layout mirrors the original merge

class RGE_Game_World;

void* __cdecl operator_new(unsigned int size);
void* operator new(unsigned int size, void* place);

class RGE_Scenario {
public:
    char gap_0[0x1990];
    RGE_Scenario(RGE_Game_World* param_1);
};

class T_Scenario : public RGE_Scenario {
public:
    char gap_0[0x37BC];
    T_Scenario(RGE_Game_World* param_1);
};

class RGE_Game_World {
public:
    char gap_0[0x5C];
    T_Scenario* scenario;

    void scenario_init(RGE_Game_World* param_1);
};

void RGE_Game_World::scenario_init(RGE_Game_World* param_1) {
    T_Scenario* pScenario;

    pScenario = (T_Scenario*)operator_new(0x514C);
    if (pScenario == 0) {
        pScenario = 0;
    } else {
        pScenario = new (pScenario) T_Scenario(param_1);
    }
    this->scenario = pScenario;
}
