class AIModule {
public:
    void logCommonHistory(char* fmt, ...);
};

class TribeMainDecisionAIModule;

class TribeTacticalAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;

    void removeFromTaskLists(int unitId);
    int stopUnit(int unitId, int value);
    void detask(int unitId);
};

void TribeTacticalAIModule::detask(int unitId) {
    if (unitId == -1) {
        this->logCommonHistory((char*)"ERROR DETASKING Unit #%d!", unitId);
        return;
    }
    removeFromTaskLists(unitId);
    stopUnit(unitId, 0x64);
}
