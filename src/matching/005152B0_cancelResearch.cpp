class BuildAIModule_crs {
public:
    void cancelResearch(int a, int b, int c, int d);
};

class AIModule_crs {
public:
    char gap_00[0x104];
    BuildAIModule_crs build_ai;
};

class TRIBE_Player_crs {
public:
    void cancelResearch(int a, int b, int c, int d);
    char gap_00[0x238];
    AIModule_crs* ai_module;
};

void TRIBE_Player_crs::cancelResearch(int a, int b, int c, int d) {
    if (!this->ai_module) {
        return;
    }
    ((BuildAIModule_crs*)((char*)this->ai_module + 0x104))->cancelResearch(a, b, c, d);
}
