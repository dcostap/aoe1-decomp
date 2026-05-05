// 0052E590 TRIBE_World::scenario_init(int, RGE_Game_World*)
// EH-framed allocate and construct T_Scenario, store at +0x5C.
// HollowSnowdrop pass: /GX + direct new with sizeof(T_Scenario)=0x514C gets exact 96/96 EH prologue/allocation/ctor family including two ctor args. Remaining drift is same common-tail blocker as sibling scenario/effects init helpers: original null branch goes to xor eax and common store; rebuilt stores after ctor and sends null branch to padded/shared epilogue.

class RGE_Game_World;
void* operator new(unsigned int size);

class T_Scenario {
public:
    char gap_0[0x514C];
    T_Scenario(int param_1, RGE_Game_World* param_2);
};

class TRIBE_World {
public:
    char gap_0[0x5C];
    T_Scenario* scenario;

    void scenario_init(int param_1, RGE_Game_World* param_2);
};

void TRIBE_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    T_Scenario* s;
    s = new T_Scenario(param_1, param_2);
    this->scenario = s;
}
