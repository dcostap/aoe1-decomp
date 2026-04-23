class TribeBuildAIModule {
public:
    char gap_0[0x5C0];
    void removeBuiltItem(int object_id);
};

class TribeConstructionAIModule {
public:
    char gap_0[0x318];
};

class DiplomacyAIModule {
public:
    char gap_0[0x150];
};

class EmotionalAIModule {
public:
    char gap_0[0x1C0];
};

class TribeInformationAIModule {
public:
    char gap_0[0x10090];
    void removeObject(int object_id);
};

class TribeResourceAIModule {
public:
    char gap_0[0xF8];
};

class TribeStrategyAIModule {
public:
    char gap_0[0x5F8];
};

class TribeTacticalAIModule {
public:
    char gap_0[0x100C];
    void removeObject(int object_id);
};

class TradeAIModule {
public:
    char gap_0[0xF4];
};

class MainDecisionAIModule {
public:
    int removeObject(int object_id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_0[0x104];
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    EmotionalAIModule emotionalAI;
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;
    TribeTacticalAIModule tacticalAI;
    TradeAIModule tradeAI;

    int removeObject(int object_id);
};

int TribeMainDecisionAIModule::removeObject(int object_id) {
    this->tacticalAI.removeObject(object_id);
    this->buildAI.removeBuiltItem(object_id);
    this->informationAI.removeObject(object_id);
    return MainDecisionAIModule::removeObject(object_id);
}
