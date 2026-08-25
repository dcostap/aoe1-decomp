#ifndef TAITACMD_SHARED_CONTEXT
class AIModule {
public:
    void logCommonHistory(char* fmt, ...);
};
#endif

class TribeMainDecisionAIModule;

#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;

    void removeFromTaskLists(int unitId);
    int stopUnit(int unitId, int value);
    void detask(int unitId);
};
#endif

void TribeTacticalAIModule::detask(int unitId) {
    if (unitId == -1) {
        this->logCommonHistory((char*)"ERROR DETASKING Unit #%d!", unitId);
        return;
    }
    removeFromTaskLists(unitId);
    stopUnit(unitId, 0x64);
}
