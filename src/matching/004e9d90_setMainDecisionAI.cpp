#ifndef TAISTRMD_TU_CONTEXT
struct Waypoint {
    char data[12];
};

class TribeMainDecisionAIModule;

class TribeStrategyAIModule {
public:
    virtual ~TribeStrategyAIModule();
    char gap_04[0xEC];
    union {
        TribeMainDecisionAIModule* md;
        int mainDecisionAI_;
    };
    int currentVictoryCondition_;
    char ruleSetName_[0x104];
    int targetID_;
    int targetType_;
    int secondTargetID_;
    int secondTargetType_;
    Waypoint targetPoint1_;
    char gap_218[4];
    Waypoint targetPoint2_;
    char gap_228[4];
    int targetAttribute_;
    int targetNumber_;

    void setMainDecisionAI(TribeMainDecisionAIModule* v);
};
#endif

void TribeStrategyAIModule::setMainDecisionAI(TribeMainDecisionAIModule* v) {
    this->md = v;
}
