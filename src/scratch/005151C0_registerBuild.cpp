class BuildAIModule_rb {
public:
    void registerBuild(int a, int b);
};

class AIModule_rb {
public:
    char gap_00[0x104];
    BuildAIModule_rb build_ai;
};

class TRIBE_Player_rb {
public:
    void registerBuild(int a, int b);
    char gap_00[0x238];
    AIModule_rb* ai_module;
};

void TRIBE_Player_rb::registerBuild(int a, int b) {
    if (!this->ai_module) return;
    ((BuildAIModule_rb*)((char*)this->ai_module + 0x104))->registerBuild(a, b);
}
