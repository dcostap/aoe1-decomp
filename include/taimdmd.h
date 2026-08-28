#ifndef AOE1_TAIMDMD_H
#define AOE1_TAIMDMD_H

// Declarations for the original taimdmd.cpp source module.

#include "aimdmod.h"
#include "aidipmod.h"
#include "aiemomod.h"
#include "aitrdmod.h"
#include "taiconmd.h"
#include "tairesmd.h"
#define AOE1_TAITACMD_TACTICAL_ONLY
#include "taitacmd.h"
#undef AOE1_TAITACMD_TACTICAL_ONLY

class TribeMainDecisionAIModule;
class TRIBE_Player;
class TacticalAIGroup;

class BuildAIModule : public AIModule {
public:
    virtual int save(int);
    virtual void displayBuildList();
    int numberUnbuiltItemsOfType(int, int);
    int numberItemsOfType(int, int);
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
    int haveBuildList();
    BuildItem* nextBuildableItem(int);
    void unskipBuildList(int, int);
    int numberBuiltOrInProgressItemsOfType(int, int);
    int mostNeededResource(ResourceItem*, int);
    int readyToResearch(int, int);
    int numberUnbuiltItemsOfType(int, int);
    int numberItemsOfType(int, int);
    int allBuilt(int, int);
    BuildItem* buildItem(int, int, int);
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
    ManagedArray<int> farmsTaskedThisUpdate;
    char bytes[0x10090 - sizeof(InformationAIModule) - sizeof(ManagedArray<int>) - 0x14];
    int closestDropsiteValue[4];
    int numberFoundForestTilesValue;

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
    int groupInfluenceDimension(int);
    int isBoat(int);
    ObjectMemory* artifactToCapture(int);
    ObjectMemory* ruinToCapture(int);
    int isBoat(RGE_Static_Object*);
    int findGatherPosition(XYPoint&, int, int, int, int, RGE_Static_Object*, XYPoint&);
    int numberGameIDsOwnedBy(int, int);
    int gameIDOfResourceObject(int, int, float&, float&, int&, int*, int);
    int gameIDOfResourceObject(int, int, float*, float*, int*, int*, int);
    void setResourceObjectValid(int, int, int);
    int acceptablePotentialDropsiteArea(int, int);
    int numberAvailableStoragePits(int);
    int numberAvailableGranaries(int);
    int numberAvailableGranaries();
    int setTileExplored(int, int);
    int unexploredPlayerLocation(int, int);
    int unexploredPlayerLocation(int, XYPoint*);
    int tileUncovered(int, int);
    int mapXSize();
    int mapYSize();
    int numberUnitsWithinXTiles(RGE_Static_Object*, int, int, int, int, int);
    int numberUnitsWithinXTiles(int, int, int, int);
    ObjectMemory* objectToTradeWith(int);
    RGE_Static_Object* findClosestReturnDropsite(RGE_Static_Object*);
    ObjectMemory* objectToDefend(int);
    ObjectMemory* objectMemory(int);
    ObjectMemory* objectToAttack(int, int, int, int, int&);
    ObjectMemory* objectToAttackByGroup(int, TacticalAIGroup*, AttackState*, ulong);
    ObjectMemory* objectToAttackWithPlay(int, int*, int, int*, int*, int*, int*);
    ObjectMemory* higherPriorityObjectToDefend(int, int, int);
    void blotExploredMap(int, int, int, int);
    void addEnemyInfluences(int, int);
    void addPriorAttackInfluences(int, int);
    int findStagingPoint(XYPoint, XYPoint*, int, int, int, int, int);
    int withinXTilesOfObject(RGE_Static_Object*, int, int, int, int, int);
    void mapBound(XYPoint*);
    void setSaveLearnInformation(int);
    void storeAttackMemory(int, unsigned char, unsigned char, unsigned char, unsigned char,
                           unsigned char, unsigned char, int, int, int, int);
    void storeAttackMemory(int, unsigned char, unsigned char, unsigned char, unsigned char,
                           unsigned char, unsigned char, int, unsigned char);
    int closestDropsiteResID(int);
    void updateResourceDropsites(int);
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
    int currentVictoryCondition();
    Waypoint* targetPoint1();
    Waypoint* targetPoint2();
    int targetID();
    int secondTargetID();
    int loadRules(char*);
    void setDifficultyLevel(int);
    int rule(int);
    void setRule(int, int);
    char* ruleSetName();
    int strategicNumber(int);
};

typedef char taimdmd_strategy_size[(sizeof(TribeStrategyAIModule) == 0x5F8) ? 1 : -1];

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
