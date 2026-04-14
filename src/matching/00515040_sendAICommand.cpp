class AIModule_sac {
public:
    int sendCommand(int a, int b, int c, int d, int e);
};

class TRIBE_Player_sac {
public:
    int sendAICommand(int a, int b, int c, int d, int e);
    char gap_00[0x238];
    AIModule_sac* ai_module;
};

int TRIBE_Player_sac::sendAICommand(int a, int b, int c, int d, int e) {
    if (!this->ai_module) return 0;
    return this->ai_module->sendCommand(a, b, c, d, e);
}
