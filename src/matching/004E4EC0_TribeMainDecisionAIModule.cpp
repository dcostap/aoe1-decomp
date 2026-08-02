// VA: 004E4EC0 ~TribeMainDecisionAIModule (213B)
// taimdmd.cpp:236-237
// Baseline: natural VC5 virtual destructor with the binary-proven member order and sizes.
// FLAGS: /GX
// Attempt log: baseline matches exactly; /GX is retained for the binary-observed EH frame.

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class MainDecisionAIModule : public AIModule {
public:
    void* player; // +0xF0
    char gap_F4[0x10];
    virtual ~MainDecisionAIModule();
};

class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    char bytes[0x5BC];
};

class TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
    char bytes[0x314];
};

class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    char bytes[0x14C];
};

class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    char bytes[0x1BC];
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char bytes[0x1008C];
};

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char bytes[0xF4];
};

class TribeStrategyAIModule {
public:
    virtual ~TribeStrategyAIModule();
    char bytes[0x5F4];
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char bytes[0x1008];
};

class TradeAIModule {
public:
    virtual ~TradeAIModule();
    char bytes[0xF0];
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI; // +0x104
    TribeConstructionAIModule constructionAI; // +0x6C4
    DiplomacyAIModule diplomacyAI; // +0x9DC
    EmotionalAIModule emotionalAI; // +0xB2C
    TribeInformationAIModule informationAI; // +0xCEC
    TribeResourceAIModule resourceAI; // +0x10D7C
    TribeStrategyAIModule strategyAI; // +0x10E74
    TribeTacticalAIModule tacticalAI; // +0x1146C
    TradeAIModule tradeAI; // +0x12478
    void* aiPlayer; // +0x1256C
    int firstUpdate;
    int veryFirstUpdate;
    int updateDelay;
    unsigned long lastDiplomacyUpdateTime;
    unsigned long lastTacticalUpdateTime;
    unsigned long lastTributeChatTime;
    unsigned long tributeChatTimeout;
    int waitingOnTribute;
    int tributeExpirationTimeout;
    int tributeAddressed;
    int tributeAmount;
    int decidedInitialDiplomacy;
    int requiredDiplomacyTributeAmount;
    int tributeGiven[9];

    virtual ~TribeMainDecisionAIModule();
};

TribeMainDecisionAIModule::~TribeMainDecisionAIModule()
{
}
