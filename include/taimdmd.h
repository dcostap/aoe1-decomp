#ifndef AOE1_TAIMDMD_H
#define AOE1_TAIMDMD_H

// Declarations for the original taimdmd.cpp source module.

#include "aimdmod.h"
#include "aidipmod.h"
#include "aiemomod.h"
#include "aitrdmod.h"

class TribeMainDecisionAIModule;
class TRIBE_Player;

class BuildAIModule : public AIModule {
public:
    virtual int save(int);
    virtual void displayBuildList();
};

class ConstructionAIModule : public AIModule {
public:
    virtual int save(int);
};

class InformationAIModule : public AIModule {
public:
    virtual int update(int);
};

class ResourceAIModule : public AIModule {
public:
    virtual int save(int);
};

class StrategyAIModule : public AIModule {
public:
    virtual int save(int);
    virtual int update(int);
};

class TacticalAIModule : public AIModule {
public:
    virtual int save(int);
    virtual int update(int);
};


class TribeBuildAIModule : public BuildAIModule {
public:
    char bytes[0x5C0 - sizeof(BuildAIModule)];

    TribeBuildAIModule(void*, int);
    TribeBuildAIModule(int, int);
    virtual ~TribeBuildAIModule();
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    void setup(MainDecisionAIModule*);
    void initialize();
    void skipNextBuildListItem();
    void removeBuiltItem(int);
    int insert(int, int, int);
    int addItem(RGE_Static_Object*, int);
};

typedef char taimdmd_build_size[(sizeof(TribeBuildAIModule) == 0x5C0) ? 1 : -1];

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    char bytes[0x318 - sizeof(ConstructionAIModule)];

    TribeConstructionAIModule(void*, int);
    TribeConstructionAIModule(int, int);
    virtual ~TribeConstructionAIModule();
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    void setup(MainDecisionAIModule*);
    void setReferencePoint(int, int, float, float, float);
};

typedef char taimdmd_construction_size[
    (sizeof(TribeConstructionAIModule) == 0x318) ? 1 : -1];

class TribeInformationAIModule : public InformationAIModule {
public:
    char bytes[0x10090 - sizeof(InformationAIModule)];

    TribeInformationAIModule(void*, int);
    TribeInformationAIModule(int, int);
    virtual ~TribeInformationAIModule();
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    int save(int);
    void setup(MainDecisionAIModule*);
    void addResourceType(int, int);
    int initialize();
    void addObject(RGE_Static_Object*);
    void removeObject(int);
    void lookAtMap();
    int update(int);
};

typedef char taimdmd_information_size[
    (sizeof(TribeInformationAIModule) == 0x10090) ? 1 : -1];

class TribeResourceAIModule : public ResourceAIModule {
public:
    char bytes[0xF8 - sizeof(ResourceAIModule)];

    TribeResourceAIModule(void*, int, int, int, int, int);
    TribeResourceAIModule(int, int);
    virtual ~TribeResourceAIModule();
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    void setup(MainDecisionAIModule*);
};

typedef char taimdmd_resource_size[(sizeof(TribeResourceAIModule) == 0xF8) ? 1 : -1];

class TribeStrategyAIModule : public StrategyAIModule {
public:
    char bytes[0x5F8 - sizeof(StrategyAIModule)];

    TribeStrategyAIModule(void*, int);
    TribeStrategyAIModule(int, int);
    virtual ~TribeStrategyAIModule();
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    void setup(MainDecisionAIModule*);
    int update(int);
};

typedef char taimdmd_strategy_size[(sizeof(TribeStrategyAIModule) == 0x5F8) ? 1 : -1];

class TribeTacticalAIModule : public TacticalAIModule {
public:
    char bytes[0x100C - sizeof(TacticalAIModule)];

    TribeTacticalAIModule(void*, int);
    TribeTacticalAIModule(int, int);
    virtual ~TribeTacticalAIModule();
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    void setup(MainDecisionAIModule*);
    int strategicNumber(int);
    void setStrategicNumber(int, int);
    int processCoopAttack(int, int, int, int);
    void addObject(RGE_Static_Object*);
    void removeObject(int);
    int update(int);
    void detask(int);
};

typedef char taimdmd_tactical_size[(sizeof(TribeTacticalAIModule) == 0x100C) ? 1 : -1];

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
    TRIBE_Player* aiPlayer;
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

    TribeMainDecisionAIModule(void*, int, char*, TRIBE_Player*, char*, char*, char*);
    TribeMainDecisionAIModule(int, char*, TRIBE_Player*, int);
    virtual ~TribeMainDecisionAIModule();
    virtual void setLogHistory(int);
    virtual int update(int);
    virtual int save(int);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);
    virtual int objectGroupThatCanPerformAction(int);
    virtual int canPerformAction(int, int);
    void kick(int);
    int isMoveable(int);
    void updateBuildAIWithObjects();
    void tributeNotify(int, int, int);
    void revokeTributeAlliance();
protected:
    void setTributeChat();
public:
    int processAICommand(int, int, int, int, int);
    int currentScore(int);
    void detask(int);
};

typedef char taimdmd_tribe_main_size[
    (sizeof(TribeMainDecisionAIModule) == 0x125C8) ? 1 : -1];

typedef char taimdmd_player_offset[
    (((char*)&((MainDecisionAIModule*)0)->player - (char*)0) == 0xF0) ? 1 : -1];

typedef char taimdmd_ai_player_offset[
    (((char*)&((TribeMainDecisionAIModule*)0)->aiPlayer - (char*)0) == 0x1256C) ? 1 : -1];

#endif
