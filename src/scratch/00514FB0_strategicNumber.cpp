class StrategyAIModule_sn {
public:
    int strategicNumber(int index);
};

class AIModule_sn {
public:
    char gap_00[0x1146C];
    StrategyAIModule_sn strategy;
};

class TRIBE_Player_sn {
public:
    int strategicNumber(int index);
    char gap_00[0x238];
    AIModule_sn* ai_module;
};

int TRIBE_Player_sn::strategicNumber(int index) {
    if (!this->ai_module) return -1;
    return ((StrategyAIModule_sn*)((char*)this->ai_module + 0x1146C))->strategicNumber(index);
}
