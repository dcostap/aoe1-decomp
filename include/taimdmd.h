#ifndef AOE1_TAIMDMD_H
#define AOE1_TAIMDMD_H

// Declarations for the original taimdmd.cpp source module.

#include "aimdmod.h"
#include "aidipmod.h"
#include "aiemomod.h"
#include "aitrdmod.h"
#include "taiconmd.h"
#include "tairesmd.h"

class TribeMainDecisionAIModule;
class TRIBE_Player;
class TacticalAIGroup;

class BuildAIModule : public AIModule {
public:
    virtual int save(int);
    virtual void displayBuildList();
};

class InformationAIModule : public AIModule {
public:
    virtual int update(int);
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
    int addBuiltItem(RGE_Static_Object*, int);
    char* buildListName();
    int buildListLength();
    int numberItemsIntoBuildList();
    char* lastBuildItemRequested();
    char* currentBuildItemRequested();
    char* nextBuildItemRequested();
    void cancelBuildItem(int, int, int, float, float, int, int);
    int loadBuildList(char*, RGE_Player*);
    int addTrainedUnit(int, int, int, int);
    int cancelTrainUnit(int, int, int, int);
    int addResearch(int, int, int);
    int cancelResearch(int, int, int, int);
};

typedef char taimdmd_build_size[(sizeof(TribeBuildAIModule) == 0x5C0) ? 1 : -1];

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
    ConstructionItem* placeDock(BuildItem*, float, float, int, int);
    int influenceCanPlaceStructure(BuildItem*);
    ConstructionItem* influencePlaceStructure(
        BuildItem*, int, int, float, char*, int, int, int, int,
        PlacementState&, unsigned long);
    void storeLot(int, unsigned char, unsigned char, unsigned char);
    void loadLearnInfo(char*);
    void loadUnitHistory();
    void unitsThatAreMostBuilt(int*, int*);
    int fullyExploredZone(int);
    int closestUnexploredTile(int, float, float, float*, float*);
    int addImportantObject(int);
};

typedef char taimdmd_information_size[
    (sizeof(TribeInformationAIModule) == 0x10090) ? 1 : -1];

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
    int loadRules(char*);
    void setDifficultyLevel(int);
    int rule(int);
    void setRule(int, int);
    char* ruleSetName();
    int strategicNumber(int);
};

typedef char taimdmd_strategy_size[(sizeof(TribeStrategyAIModule) == 0x5F8) ? 1 : -1];

class TribeTacticalAIModule : public TacticalAIModule {
public:
    char bytes[0x100C - sizeof(TacticalAIModule) - 12];

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
    int neededResource(int) const;
    int neededResourceAmount(int) const;
    int actualGathererCount(int);
    int desiredGathererCount(int);
    int numberGatherers() const;
    int desiredNumberGatherers() const;
    int numberCivilianExplorers() const;
    int desiredNumberCivilianExplorers() const;
    int numberCivilians() const;
    int numberSoldiers() const;
    int numberBoats() const;
    int resourceDifference(int);
    char* updateAreaName();
    TacticalAIGroup* groupUnitIsIn(int);
    int removeGroup(int);
    int taskExplorer(int, float, float);
    void trackUnitGather(int, int, int);
    void notify(int, int, int, long, long, long);
    int attackEnabledValue;
    int lastUpdateAreaTimeValue;
    int averageUpdateAreaTimeValue;
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
