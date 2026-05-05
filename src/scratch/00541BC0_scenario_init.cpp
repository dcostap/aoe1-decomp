// 00541BC0 RGE_Game_World::scenario_init
// EH-framed allocate and construct RGE_Scenario, store at +0x5C.
// HollowSnowdrop pass: /GX + direct new with sizeof(RGE_Scenario)=0x1990 gives exact 91/91 EH prologue/allocation/ctor family. Remaining drift is the same common-tail blocker as 0052E5F0: original has short null branch to xor eax and common store; rebuilt stores immediately after ctor and sends null branch to padded/shared epilogue.

class RGE_Game_World;
void* operator new(unsigned int size);

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
    RGE_Scenario* s;
    s = new RGE_Scenario(param_1);
    this->scenario = s;
}
