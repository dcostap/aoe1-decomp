class BuildAIModule_rt {
public:
    void registerTrain(int a, int b, int c, int d);
};

class AIModule_rt {
public:
    char gap_00[0x104];
    BuildAIModule_rt build_ai;
};

class TRIBE_Player_rt {
public:
    void registerTrain(int a, int b, int c, int d);
    char gap_00[0x238];
    AIModule_rt* ai_module;
};

void TRIBE_Player_rt::registerTrain(int a, int b, int c, int d) {
    if (!this->ai_module) {
        return;
    }
    ((BuildAIModule_rt*)((char*)this->ai_module + 0x104))->registerTrain(a, b, c, d);
}
