class BuildAIModule_rrs {
public:
    void registerResearch(int a, int b, int c);
};

class AIModule_rrs {
public:
    char gap_00[0x104];
    BuildAIModule_rrs build_ai;
};

class TRIBE_Player_rrs {
public:
    void registerResearch(int a, int b, int c);
    char gap_00[0x238];
    AIModule_rrs* ai_module;
};

void TRIBE_Player_rrs::registerResearch(int a, int b, int c) {
    if (!this->ai_module) return;
    ((BuildAIModule_rrs*)((char*)this->ai_module + 0x104))->registerResearch(a, b, c);
}
