#ifndef TAITACMD_SHARED_CONTEXT
#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup;

class TribeStrategyAIModule {
public:
    int currentVictoryCondition();
    int targetID();
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeStrategyAIModule* md;

    TacticalAIGroup* group(int a, int b, int c, int d);
    int itemToCapture(void);
};

#endif
int TribeTacticalAIModule::itemToCapture(void) {
    int targetId;

    if (((TribeStrategyAIModule*)((char*)this->md + 0x10E74))->currentVictoryCondition() == 0) {
        targetId = ((TribeStrategyAIModule*)((char*)this->md + 0x10E74))->targetID();
        if (this->group(-1, -1, -1, targetId) == 0) {
            return targetId;
        }
    }
    return -1;
}
#else
int TribeTacticalAIModule::itemToCapture() { return 0; }
#endif
