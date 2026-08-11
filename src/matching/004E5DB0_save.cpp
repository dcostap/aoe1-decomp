// VA: 004E5DB0 save (380B)
// taimdmd.cpp:789-816
//
// Baseline reconstruction: save the inherited decision module, then each
// embedded AI module in source order, followed by the scalar tribute state.
// The dispatching embedded modules expose the common save slot at +0x3c;
// informationAI's save is the one direct non-dispatching call in the original
// sequence.
//
// Attempt log:
// - baseline: natural typed module ownership and source-order save sequence
//   matched all 380 bytes with the default /O2 /Oy flags.
// - ABI probe: modeled informationAI's proven direct save as a nonvirtual
//   member with its own vptr and payload; emitted bytes remained exact.

void rge_write(int file, void* data, int size);

class MainDecisionAIModule {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual int save(int file);

    char bytes[0x100];
};

class TribeBuildAIModule {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual int save(int file);

    char bytes[0x5BC];
};

class TribeConstructionAIModule {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual int save(int file);

    char bytes[0x314];
};

class DiplomacyAIModule {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual int save(int file);

    char bytes[0x14C];
};

class EmotionalAIModule {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual int save(int file);

    char bytes[0x1BC];
};

class TribeInformationAIModule {
public:
    void* vtable;
    char bytes[0x1008C];
    int save(int file);
};

class TribeResourceAIModule {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual int save(int file);

    char bytes[0xF4];
};

class TribeStrategyAIModule {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual int save(int file);

    char bytes[0x5F4];
};

class TribeTacticalAIModule {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual int save(int file);

    char bytes[0x1008];
};

class TradeAIModule {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual int save(int file);

    char bytes[0xF0];
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    EmotionalAIModule emotionalAI;
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;
    TribeTacticalAIModule tacticalAI;
    TradeAIModule tradeAI;

    void* aiPlayer;
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

    int save(int file);
};

int TribeMainDecisionAIModule::save(int file)
{
    MainDecisionAIModule::save(file);

    this->buildAI.save(file);
    this->constructionAI.save(file);
    this->diplomacyAI.save(file);
    this->emotionalAI.save(file);
    this->informationAI.save(file);
    this->resourceAI.save(file);
    this->strategyAI.save(file);
    this->tacticalAI.save(file);
    this->tradeAI.save(file);

    rge_write(file, &this->updateDelay, 4);
    rge_write(file, &this->lastDiplomacyUpdateTime, 4);
    rge_write(file, &this->lastTacticalUpdateTime, 4);
    rge_write(file, &this->lastTributeChatTime, 4);
    rge_write(file, &this->tributeChatTimeout, 4);
    rge_write(file, &this->waitingOnTribute, 4);
    rge_write(file, &this->tributeExpirationTimeout, 4);
    rge_write(file, &this->tributeAddressed, 4);
    rge_write(file, &this->tributeAmount, 4);
    rge_write(file, &this->decidedInitialDiplomacy, 4);
    rge_write(file, &this->requiredDiplomacyTributeAmount, 4);
    rge_write(file, this->tributeGiven, 0x24);

    return 1;
}
