// 004E4800 TribeMainDecisionAIModule::TribeMainDecisionAIModule
// Attempt log:
// 1: natural constructor with member subobject ctors and initialization from packet.
// 2: replaced the AIModule-only base call with the binary-proven
//    MainDecisionAIModule constructor; all 46 direct targets now align.
// 3: added the canonical AIModule gap, MainDecision fields, and virtual
//    declarations.  Output stayed at 50 differing bytes.
// 4: novtable probes on the derived, MainDecision, and AIModule classes were
//    restored.  They removed or moved the vptr code and worsened the result.
// BINARY NOTE: the shipped constructor stores the derived vptr at +0x155,
//    after field initialization.  VC5 emits that store at +0xF7 here.

#ifndef AOE1_TAIMDMD_CONTEXT_H
class TRIBE_Player;
extern int startLoggingAI;
extern "C" void* memset(void*, int, unsigned int);

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
    AIModule(void* p1, int p2, void* player);
    void setPlayer(int p2, char* p3);
    void setLogCommonHistory(int v);
};

class MainDecisionAIModule : public AIModule {
public:
    TRIBE_Player* player;
    void* objects_value;
    int objects_numberValue;
    int objects_pad_FC;
    int objects_maximumSizeValue;
    virtual ~MainDecisionAIModule();
    virtual void setLogHistory(int);
    virtual int save(int);
    virtual int addObject(void*);
    virtual int removeObject(int);
    virtual int objectGroupThatCanPerformAction(int);
    virtual int canPerformAction(int, int);
    MainDecisionAIModule(void* p1, int p2, TRIBE_Player* player);
};

class TribeBuildAIModule : public AIModule { public: char pad[0x5C0 - sizeof(AIModule)]; TribeBuildAIModule(void*, int); void setMainDecisionAI(void*); };
class TribeConstructionAIModule : public AIModule { public: char pad[0x318 - sizeof(AIModule)]; TribeConstructionAIModule(void*, int); void setMainDecisionAI(void*); };
class DiplomacyAIModule : public AIModule { public: char pad[0x150 - sizeof(AIModule)]; DiplomacyAIModule(void*, int); void setMainDecisionAI(void*); };
class EmotionalAIModule : public AIModule { public: char pad[0x1C0 - sizeof(AIModule)]; EmotionalAIModule(void*, int); void setMainDecisionAI(void*); void setOverallState(int); };
class TribeInformationAIModule : public AIModule { public: char pad[0x10090 - sizeof(AIModule)]; TribeInformationAIModule(void*, int); void setMainDecisionAI(void*); void addResourceType(int, int); };
class TribeResourceAIModule : public AIModule { public: char pad[0x0F8 - sizeof(AIModule)]; TribeResourceAIModule(void*, int, int, int, int, int); void setMainDecisionAI(void*); };
class TribeStrategyAIModule : public AIModule { public: char pad[0x5F8 - sizeof(AIModule)]; TribeStrategyAIModule(void*, int); void setMainDecisionAI(void*); };
class TribeTacticalAIModule : public AIModule { public: char pad[0x100C - sizeof(AIModule)]; TribeTacticalAIModule(void*, int); void setMainDecisionAI(void*); };
class TradeAIModule : public AIModule { public: char pad[0x0F4 - sizeof(AIModule)]; TradeAIModule(void*, int); void setMainDecisionAI(void*); };

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    TribeBuildAIModule buildAI; // +104
    TribeConstructionAIModule constructionAI; // +6c4
    DiplomacyAIModule diplomacyAI; // +9dc
    EmotionalAIModule emotionalAI; // +b2c
    TribeInformationAIModule informationAI; // +cec
    TribeResourceAIModule resourceAI; // +10d7c
    TribeStrategyAIModule strategyAI; // +10e74
    TribeTacticalAIModule tacticalAI; // +1146c
    TradeAIModule tradeAI; // +12478
    void* aiPlayer; // +1256c
    int firstUpdate;
    int veryFirstUpdate;
    int updateDelay;
    int lastDiplomacyUpdateTime;
    int lastTacticalUpdateTime;
    int lastTributeChatTime;
    int tributeChatTimeout;
    int waitingOnTribute;
    int tributeExpirationTimeout;
    int tributeAddressed;
    int tributeAmount;
    int decidedInitialDiplomacy;
    int requiredDiplomacyTributeAmount;
    int tributeGiven[9];

    TribeMainDecisionAIModule(void* p1, int p2, char* p3, TRIBE_Player* player, char* p5, char* p6, char* p7);
};
#endif

TribeMainDecisionAIModule::TribeMainDecisionAIModule(void* p1, int p2, char* p3, TRIBE_Player* player, char* p5, char* p6, char* p7)
    : MainDecisionAIModule(p1, p2, player),
      buildAI(p1, p2),
      constructionAI(p1, p2),
      diplomacyAI(p1, p2),
      emotionalAI(p1, p2),
      informationAI(p1, p2),
      resourceAI(p1, p2, 4, 500, 0, 1000),
      strategyAI(p1, p2),
      tacticalAI(p1, p2),
      tradeAI(p1, p2)
{
    this->firstUpdate = 1;
    this->veryFirstUpdate = 1;
    this->aiPlayer = (TRIBE_Player*)player;
    this->updateDelay = p2;
    this->lastDiplomacyUpdateTime = 0;
    this->lastTacticalUpdateTime = 0;
    this->lastTributeChatTime = 0;
    this->tributeChatTimeout = 0;
    this->waitingOnTribute = 0;
    this->tributeExpirationTimeout = 0;
    this->tributeAddressed = 0;
    this->tributeAmount = 0;
    this->decidedInitialDiplomacy = 0;
    this->requiredDiplomacyTributeAmount = 0;
    this->setPlayer(p2, p3);
    if (startLoggingAI != 0) {
        this->setLogCommonHistory(1);
    } else {
        this->setLogCommonHistory(0);
    }

    this->buildAI.setMainDecisionAI(this);
    this->constructionAI.setMainDecisionAI(this);
    this->diplomacyAI.setMainDecisionAI(this);
    this->emotionalAI.setMainDecisionAI(this);
    this->informationAI.setMainDecisionAI(this);
    this->resourceAI.setMainDecisionAI(this);
    this->strategyAI.setMainDecisionAI(this);
    this->tacticalAI.setMainDecisionAI(this);
    this->tradeAI.setMainDecisionAI(this);

    this->buildAI.setPlayer(p2, p3);
    this->constructionAI.setPlayer(p2, p3);
    this->diplomacyAI.setPlayer(p2, p3);
    this->emotionalAI.setPlayer(p2, p3);
    this->informationAI.setPlayer(p2, p3);
    this->resourceAI.setPlayer(p2, p3);
    this->strategyAI.setPlayer(p2, p3);
    this->tacticalAI.setPlayer(p2, p3);
    this->tradeAI.setPlayer(p2, p3);

    this->informationAI.addResourceType(0, 0x30);
    this->informationAI.addResourceType(0, 0x7e);
    this->informationAI.addResourceType(0, 0x3b);
    this->informationAI.addResourceType(0, 0x41);
    this->informationAI.addResourceType(0, 0x34);
    this->informationAI.addResourceType(0, 0x35);
    this->informationAI.addResourceType(0, 0x104);
    this->informationAI.addResourceType(0, 0x107);
    this->informationAI.addResourceType(0, 0x32);
    int i;
    for (i = 0x6f; i <= 0x72; i++) this->informationAI.addResourceType(1, i);
    for (i = 0x86; i <= 0x99; i++) this->informationAI.addResourceType(1, i);
    for (i = 0xc0; i <= 0xc5; i++) this->informationAI.addResourceType(1, i);
    this->informationAI.addResourceType(2, 0x66);
    this->informationAI.addResourceType(3, 0x42);
    for (i = 0x150; i <= 0x153; i++) this->informationAI.addResourceType(3, i);

    this->emotionalAI.setOverallState(0);
    memset(this->tributeGiven, 0, 36);
}
