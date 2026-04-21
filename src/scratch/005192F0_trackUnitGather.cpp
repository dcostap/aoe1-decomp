class TacticalAIModule_tug {
public:
    void trackUnitGather(int a, int b, int c);
};

class AIModule_tug {
public:
    char gap_00[0x1146C];
    TacticalAIModule_tug tactical;
};

class TRIBE_Player_tug {
public:
    void trackUnitGather(int a, int b, int c);
    char gap_00[0x238];
    AIModule_tug* ai_module;
};

void TRIBE_Player_tug::trackUnitGather(int a, int b, int c) {
    if (!this->ai_module) return;
    ((TacticalAIModule_tug*)((char*)this->ai_module + 0x1146C))->trackUnitGather(a, b, c);
}
