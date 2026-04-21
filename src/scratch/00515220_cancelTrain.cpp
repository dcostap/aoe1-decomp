class BuildAIModule_ct {
public:
    void cancelTrain(int a, int b, int c, int d);
};

class AIModule_ct {
public:
    char gap_00[0x104];
    BuildAIModule_ct build_ai;
};

class TRIBE_Player_ct {
public:
    void cancelTrain(int a, int b, int c, int d);
    char gap_00[0x238];
    AIModule_ct* ai_module;
};

void TRIBE_Player_ct::cancelTrain(int a, int b, int c, int d) {
    if (!this->ai_module) return;
    ((BuildAIModule_ct*)((char*)this->ai_module + 0x104))->cancelTrain(a, a, b, c);
}
