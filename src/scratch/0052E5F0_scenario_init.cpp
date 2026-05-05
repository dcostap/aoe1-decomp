// 0052E5F0 TRIBE_World::scenario_init
// EH-framed allocate and construct T_Scenario, store at +0x5C.
// HollowSnowdrop pass: /GX + direct new with sizeof(T_Scenario)=0x514C gives exact 91/91 EH prologue/allocation/ctor family. Remaining drift matches the effects_init siblings: original has short null branch to xor eax and common store; rebuilt stores immediately after ctor and sends null branch to a padded/shared epilogue. Explicit placement-new/null-fallback form previously collapsed to an 80-byte nonmatching body.

class RGE_Game_World;
void* operator new(unsigned int size);

class T_Scenario {
public:
    char gap_0[0x514C];
    T_Scenario(RGE_Game_World* param_1);
};

class TRIBE_World {
public:
    char gap_0[0x5C];
    T_Scenario* scenario;

    void scenario_init(RGE_Game_World* param_1);
};

void TRIBE_World::scenario_init(RGE_Game_World* param_1) {
    T_Scenario* s;
    s = new T_Scenario(param_1);
    this->scenario = s;
}
