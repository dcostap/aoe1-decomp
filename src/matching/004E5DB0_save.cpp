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

#ifndef AOE1_TAIMDMD_CONTEXT_H
void rge_write(int file, void* data, int size);

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    virtual int save(int file);

    char bytes[0x100];
};

class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    virtual int save(int file);

    char bytes[0x5BC];
};

class TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    virtual int save(int file);

    char bytes[0x314];
};

class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    virtual int save(int file);

    char bytes[0x14C];
};

class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    virtual int save(int file);

    char bytes[0x1BC];
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    char bytes[0x1008C];
    int save(int file);
};

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    virtual int save(int file);

    char bytes[0xF4];
};

class TribeStrategyAIModule {
public:
    virtual ~TribeStrategyAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    virtual int save(int file);

    char bytes[0x5F4];
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    virtual int save(int file);

    char bytes[0x1008];
};

class TradeAIModule {
public:
    virtual ~TradeAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
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
#endif

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
