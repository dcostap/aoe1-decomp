#pragma once
#include "common.h"
#include "AttackState.h"
#include "PlacementState.h"
#include "ResourceItem.h"
#include "TacticalAIGroup.h"
#include "TacticalAIModule.h"
#include "UnitData.h"

struct XYPoint;
class BuildItem;
class ConstructionItem;
class InfluenceMap;
class Path;

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeTacticalAIModule(void* param_1, int param_2);
    TribeTacticalAIModule(int param_1, int param_2);

    // Virtuals (best-effort)
    virtual ~TribeTacticalAIModule(); // vt[0] (0x0)
    virtual int loggingHistory(); // vt[1] (0x4)
    virtual void setLogHistory(int param_1); // vt[2] (0x8)
    virtual void toggleLogHistory(); // vt[3] (0xC)
    virtual void setHistoryFilename(char* param_1); // vt[4] (0x10)
    virtual int loggingCommonHistory(); // vt[5] (0x14)
    virtual void setLogCommonHistory(int param_1); // vt[6] (0x18)
    virtual void toggleLogCommonHistory(); // vt[7] (0x1C)
    virtual int loadState(char* param_1); // vt[8] (0x20)
    virtual int saveState(char* param_1); // vt[9] (0x24)
    virtual int gleanState(int param_1); // vt[10] (0x28)
    virtual int processMessage(AIModuleMessage* param_1); // vt[11] (0x2C)
    virtual int update(int param_1); // vt[12] (0x30)
    virtual void setCallbackMessage(AIModuleMessage* param_1); // vt[13] (0x34)
    virtual int filterOutMessage(AIModuleMessage* param_1); // vt[14] (0x38)
    virtual int save(int param_1); // vt[15] (0x3C)
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt[16] (0x40)

    char* updateAreaName();
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    int numberCivilians() const;
    int numberCivilianExplorers() const;
    int numberGatherers() const;
    int desiredNumberCivilianExplorers() const;
    int desiredNumberGatherers() const;
    int numberSoldiers() const;
    int numberSoldierExplorers();
    int numberBoats() const;
    int neededResource(int param_1) const;
    int neededResourceAmount(int param_1) const;
    void detask(int param_1);
    int strategicNumber(int param_1);
    void setStrategicNumber(int param_1, int param_2);
    void logGroupDebug(int param_1, char* param_2, ...);
    int clearArea(int param_1, float param_2, float param_3, float param_4, float param_5);
    void addObject(RGE_Static_Object* param_1);
    void removeObject(int param_1);
    void evaluateCivilianDistribution();
    int taskCivilians(unsigned long param_1, unsigned long param_2);
    void taskIdleSoldiers(unsigned long param_1, unsigned long param_2);
    void taskActiveSoldiers(unsigned long param_1, unsigned long param_2);
    void playTaskSoldiers(unsigned long param_1, unsigned long param_2);
    void taskUngroupedSoldiers();
    void taskBoats();
    void evaluateOpenTasks();
    void evaluateBuildListInsertions();
    int doSomething();
    void enableAttack(int param_1);
    TacticalAIGroup* createGroup(int param_1);
    int removeGroup(int param_1);
    int removeAllGroups(int param_1);
    TacticalAIGroup* group(int param_1, int param_2, int param_3, int param_4);
    int addToGroup(int param_1, int param_2);
    int removeFromGroup(int param_1, int param_2);
    int removeFromGroup(int param_1);
    TacticalAIGroup* groupUnitIsIn(int param_1);
    TacticalAIGroup* addGroup(int param_1);
    TacticalAIGroup* findGroup(int param_1, int param_2, int param_3, int param_4);
    TacticalAIGroup* getGroup(int param_1);
    int numberIdleSoldiers();
    int numberSoldiersWithPriority(int param_1, int param_2, int param_3);
    int numberWarshipsWithPriority(int param_1, int param_2);
    int idleSoldier();
    int idleCivilian(int param_1);
    int idleCivilian(int param_1, XYPoint* param_2, int param_3);
    int civilian(XYPoint* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    int unit(int param_1, int param_2, int param_3);
    int busyWithAction(int param_1, int param_2);
    void displayCivilianDistribution();
    void updateNeededResources();
    void updateGathererDistribution();
    int stopUnit(int param_1, int param_2);
    int moveUnit(int param_1, float param_2, float param_3, int param_4);
    int groupGatherUnit(int param_1, int param_2, float param_3, float param_4, float param_5, float param_6, int param_7);
    int highLevelTaskExplorer(int param_1, int param_2);
    int highLevelTaskGatherer(int param_1, unsigned long param_2);
    int taskPlay(int param_1, int* param_2, int param_3, int param_4, int param_5, Waypoint* param_6, int param_7);
    int taskBuilder(int param_1, BuildItem* param_2, ConstructionItem* param_3, unsigned long param_4);
    int taskBuilder(int param_1, RGE_Static_Object* param_2);
    int taskRepairer(int param_1, RGE_Static_Object* param_2);
    int taskGatherer(int param_1, int param_2, int param_3, unsigned long param_4, int* param_5);
    int taskExplorer(int param_1, int param_2);
    int taskExplorer(int param_1, float param_2, float param_3);
    int taskExplorer(int param_1, float param_2, float param_3, int param_4);
    int taskFollower(int param_1, int param_2, float param_3, int param_4);
    int taskDefender(int param_1, int param_2, float param_3, int param_4);
    int taskWaterExplorer(int param_1);
    int taskWaterTrader(int param_1, int param_2);
    int taskWaterFisher(int param_1, int param_2, float param_3, float param_4);
    int taskAttacker(int param_1, float param_2, float param_3, int param_4, int param_5, Waypoint* param_6, int param_7, int param_8, int param_9);
    int taskDefender(int param_1, int param_2);
    int taskDefender(int param_1, float param_2, float param_3);
    int taskTrain(BuildItem* param_1);
    int taskResearch(BuildItem* param_1);
    int taskToEnter(int param_1, int param_2);
    int taskTransporter(int param_1, float param_2, float param_3);
    void removeFromTaskLists(int param_1);
    int calculatePriority(float param_1);
    void setupSoldierGroups();
    void fillSoldierGroups();
    int numberUngroupedSoldiers();
    int numberExtraGroupedSoldiers();
    int numberUngroupedArtifacts();
    void displaySoldierGroups();
    void setupBoatGroups();
    void fillBoatGroups();
    int numberUngroupedWarBoats();
    int numberExtraGroupedWarBoats();
    int numberUngroupedFishingBoats();
    int numberUngroupedTradeBoats();
    int numberUngroupedTransportBoats();
    void displayBoatGroups();
    TacticalAIGroup* bestGroup(int param_1, int param_2, int param_3, XYPoint* param_4, int param_5);
    TacticalAIGroup* readyAndIdleGroup(int param_1, int param_2, XYPoint* param_3);
    int numberGroups(int param_1, int param_2);
    int numberUnitsInGroups(int param_1);
    int numberItemsToAttack();
    int itemToCapture();
    int itemToBringToArea();
    int numberItemsToDefend();
    unsigned long attackLimiterTime(int param_1);
    void resetAttackSeparationTime();
    int setGatherLocation(TacticalAIGroup* param_1);
    int setAllGroupLocations(TacticalAIGroup* param_1);
    void setGroupInfluences(InfluenceMap* param_1);
    int selectBestCommander(TacticalAIGroup* param_1);
    int selectBestCommander(ManagedArray<int>* param_1);
    int dealWithGAIAAttacker(RGE_Static_Object* param_1, RGE_Static_Object* param_2);
    void addWaypoint(int param_1, unsigned char param_2, unsigned char param_3);
    int importantGroupLeader(int param_1);
    int unexploredArea(int param_1, XYPoint* param_2);
    UnitData* gatherer(int param_1);
    UnitData* addGatherer(int param_1);
    int removeGatherer(int param_1);
    int isGatherer(int param_1);
    int requiredGatherAmount(int param_1);
    void trackUnitGather(int param_1, int param_2, int param_3);
    int deleteUnit(int param_1);
    int numberAvailableStoragePits(int* param_1, int* param_2, int param_3);
    int numberAvailableGranaries(int* param_1, int* param_2);
    int initialExplorationSatisfied();
    void checkForBuildInsertion(int param_1, int param_2, int param_3);
    int isFarmer(RGE_Static_Object* param_1);
    int numberFarmers();
    int inAge(int param_1);
    void stuffAvoidancePath(TacticalAIGroup* param_1, Path* param_2);
    void checkForAttackResponseBuildInsertions(int param_1);
    void checkForCoopTributeDemand();
    void checkForCoopTributeGift();
    void checkForASAPAgeResearch();
    void checkForCoopAttack(int param_1, int param_2, int param_3);
    int processCoopAttack(int param_1, int param_2, int param_3, int param_4);
    int resourceDifference(int param_1);
    int actualGathererCount(int param_1);
    int actualGathererCountByRealResourceID(int param_1);
    int desiredGathererCount(int param_1);
    void taskElephantGatherers(int param_1, int param_2, int param_3);
    void checkTradeBoats();
    int numberGatherersWithTarget(int param_1);
    void checkStaleAttackGroups();
    int numberWaterExplorers();
    void saveTheTown(int param_1);

    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;
    int sn[226];
    UnitData gatherers[50];
    int numberGatherersValue;
    int desiredNumberGatherersValue;
    TacticalAIGroup groups;
    int groupIDValue;
    int numberGroupsValue;
    unsigned long lastGroupAttackTime;
    unsigned long lastGroupRebalanceTime;
    unsigned long lastAttackResponseTime;
    unsigned long lastBoatAttackResponseTime;
    unsigned long lastScalingUpdateValue;
    int numberBuildUpdatesSkipped;
    int randomizedAttackSeparationTime;
    ManagedArray<int> playersToAttack;
    ManagedArray<int> playersToDefend;
    ManagedArray<int> workingArea;
    ManagedArray<int> unitsTaskedThisUpdate;
    int actualGathererDistribution[4];
    int desiredGathererDistribution[4];
    int neededResourceValue[4];
    int resourceDifferenceValue[4];
    ResourceItem neededResources;
    int attackEnabledValue;
    int updateArea;
    int firstNeededResourceUpdateDone;
    int numberStoragePitsBuilt[4];
    int numberGranariesBuilt[4];
    int wonderInProgressValue;
    int wonderBuiltValue;
    PlacementState placementStateValue;
    int nextCivilianToTaskValue;
    int nextIdleSoldierGroupToTaskValue;
    int nextActiveSoldierGroupToTaskValue;
    int builtFirstStoragePit;
    int builtFirstGranary;
    unsigned long lastBuildTime;
    unsigned long lastAttackResponseBuildInsertionTime;
    unsigned long lastCoopTributeDemandTime;
    unsigned long lastCoopTributeGiftTime;
    unsigned long lastCoopAttackDemandTime;
    int zoomingToNextAge;
    unsigned long lastUngroupedSoldierTaskTime;
    AttackState attackStateValue;
    int hitsByPlayer[9];
    int lastUpdateAreaTimeValue;
    int averageUpdateAreaTimeValue;
    int updateAreaAverageCount;
    int updateAreaAverageTotal;
};
static_assert(sizeof(TribeTacticalAIModule) == 0x100C, "Size mismatch");
