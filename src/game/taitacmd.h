#pragma once
#include "../common.h"

class TacticalAIGroup {
public:
    TacticalAIGroup* next;                   // 0x4
    TacticalAIGroup* prev;                   // 0x8
    int idValue;                             // 0xC
    int inUseValue;                          // 0x10
    int typeValue;                           // 0x14
    int subTypeValue;                        // 0x18
    int unitsValue[40];                      // 0x1C
    int unitsOriginalHitPointsValue[40];     // 0xBC
    int numberUnitsValue;                    // 0x15C
    int desiredNumberUnitsValue;             // 0x160
    int commanderValue;                      // 0x164
    int originalHitPointsValue;              // 0x168
    int originalUnitNumberValue;             // 0x16C
    Waypoint locationValue;                  // 0x170
    int actionValue;                         // 0x180
    int targetValue;                         // 0x184
    int targetTypeValue;                     // 0x188
    Waypoint targetLocationValue;            // 0x18C
    Waypoint gatherLocationValue;            // 0x19C
    Waypoint retreatLocationValue;           // 0x1AC
    int priorityValue;                       // 0x1BC
    int waitCodeValue;                       // 0x1C0
    int assistGroupIDValue;                  // 0x1C4
    int assistGroupTypeValue;                // 0x1C8
    ulong consecutiveIdleUnitCountValue;     // 0x1CC
    int playNumberValue;                     // 0x1D0
    uchar numberAttackWaypointsValue;        // 0x1D4
    uchar currentAttackWaypointValue;        // 0x1D5
    Waypoint attackWaypoints[15];            // 0x1D8
    uchar consecutiveGatherAttemptsValue;    // 0x2C8
    int numberObjectsToDestroyValue;         // 0x2CC
    int objectsToDestroyValue[20];           // 0x2D0
    int objectsToDestroyOwnerValue;          // 0x320
    int objectsToDestroyCommanderZoneValue;  // 0x324
    ulong lastAttackRoundupTime;             // 0x328
    ulong lastAddedUnitTimeValue;            // 0x32C

    TacticalAIGroup();
    virtual ~TacticalAIGroup();
    virtual int load(int param_1);
    virtual int save(int param_1);
    virtual int id();
    virtual void setID(int param_1);
    virtual int inUse();
    virtual void setInUse(int param_1);
    virtual int type();
    virtual void setType(int param_1);
    virtual int subType();
    virtual void setSubType(int param_1);
    virtual int addUnit(int param_1, TribeMainDecisionAIModule* param_2);
    virtual int removeUnit(int param_1, TribeMainDecisionAIModule* param_2);
    virtual int removeUnitByIndex(int param_1, TribeMainDecisionAIModule* param_2);
    virtual void removeUnits(TribeMainDecisionAIModule* param_1);
    virtual int removeExtraUnits(TribeMainDecisionAIModule* param_1);
    virtual int removeUnboardedUnits(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2);
    virtual int containsUnit(int param_1);
    virtual int numberUnits();
    virtual int unit(int param_1);
    virtual int unitOriginalHitPoints(int param_1);
    virtual int desiredNumberUnits();
    virtual void setDesiredNumberUnits(int param_1);
    virtual int commander();
    virtual void setSpecificCommander(int param_1, TribeMainDecisionAIModule* param_2);
    virtual int currentHitPoints(TribeMainDecisionAIModule* param_1);
    virtual int originalHitPoints();
    virtual void setOriginalHitPoints(int param_1);
    virtual int originalUnitNumber();
    virtual void setOriginalUnitNumber(int param_1);
    virtual Waypoint* location();
    virtual void setLocation(float param_1, float param_2, float param_3);
    virtual int action();
    virtual void setAction(int param_1);
    virtual int target();
    virtual void setTarget(int param_1);
    virtual int targetType();
    virtual void setTargetType(int param_1);
    virtual Waypoint* targetLocation();
    virtual void setAllLocations(float param_1, float param_2, float param_3);
    virtual void setTargetLocation(float param_1, float param_2, float param_3);
    virtual Waypoint* gatherLocation();
    virtual void setGatherLocation(float param_1, float param_2, float param_3);
    virtual Waypoint* retreatLocation();
    virtual void setRetreatLocation(float param_1, float param_2, float param_3);
    virtual int priority();
    virtual void setPriority(int param_1);
    virtual int waitCode();
    virtual void setWaitCode(int param_1);
    virtual int assistGroupID();
    virtual void setAssistGroupID(int param_1);
    virtual int assistGroupType();
    virtual void setAssistGroupType(int param_1);
    virtual int task(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2, int param_3, int param_4, int param_5);
    virtual int isGathered(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2);
    virtual int isTightGathered(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2);
    virtual int allUnitsIdle(TribeMainDecisionAIModule* param_1, int param_2);
    virtual ulong consecutiveIdleUnitCount();
    virtual void setConsecutiveIdleUnitCount(ulong param_1);
    virtual void incrementConsecutiveIdleUnitCount(ulong param_1);
    virtual uchar numberAttackWaypoints();
    virtual uchar currentAttackWaypoint();
    virtual void setCurrentAttackWaypoint(uchar param_1);
    virtual void addAttackWaypoint(float param_1, float param_2);
    virtual Waypoint* attackWaypoint(uchar param_1);
    virtual int firstIdleUnit(TribeMainDecisionAIModule* param_1);
    virtual int objectToDestroy(int param_1);
    virtual int addObjectToDestroy(int param_1);
};

static_assert(sizeof(TacticalAIGroup) == 0x330, "TacticalAIGroup Size Mismatch");
static_assert(offsetof(TacticalAIGroup, lastAddedUnitTimeValue) == 0x32C, "TacticalAIGroup Offset Mismatch");

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;           // 0xF0
    ManagedArray<int> civilians;             // 0xF4
    ManagedArray<int> civilianExplorers;     // 0x104
    ManagedArray<int> soldiers;              // 0x114
    ManagedArray<int> ungroupedSoldiers;     // 0x124
    ManagedArray<int> boats;                 // 0x134
    ManagedArray<int> warBoats;              // 0x144
    ManagedArray<int> fishingBoats;          // 0x154
    ManagedArray<int> tradeBoats;            // 0x164
    ManagedArray<int> transportBoats;        // 0x174
    ManagedArray<int> artifacts;             // 0x184
    int sn[226];                             // 0x194
    UnitData gatherers[50];                  // 0x51C
    int numberGatherersValue;                // 0x9CC
    int desiredNumberGatherersValue;         // 0x9D0
    TacticalAIGroup groups;                  // 0x9D4
    int groupIDValue;                        // 0xD04
    int numberGroupsValue;                   // 0xD08
    ulong lastGroupAttackTime;               // 0xD0C
    ulong lastGroupRebalanceTime;            // 0xD10
    ulong lastAttackResponseTime;            // 0xD14
    ulong lastBoatAttackResponseTime;        // 0xD18
    ulong lastScalingUpdateValue;            // 0xD1C
    int numberBuildUpdatesSkipped;           // 0xD20
    int randomizedAttackSeparationTime;      // 0xD24
    ManagedArray<int> playersToAttack;       // 0xD28
    ManagedArray<int> playersToDefend;       // 0xD38
    ManagedArray<int> workingArea;           // 0xD48
    ManagedArray<int> unitsTaskedThisUpdate; // 0xD58
    int actualGathererDistribution[4];       // 0xD68
    int desiredGathererDistribution[4];      // 0xD78
    int neededResourceValue[4];              // 0xD88
    int resourceDifferenceValue[4];          // 0xD98
    ResourceItem neededResources;            // 0xDA8
    int attackEnabledValue;                  // 0xE18
    int updateArea;                          // 0xE1C
    int firstNeededResourceUpdateDone;       // 0xE20
    int numberStoragePitsBuilt[4];           // 0xE24
    int numberGranariesBuilt[4];             // 0xE34
    int wonderInProgressValue;               // 0xE44
    int wonderBuiltValue;                    // 0xE48
    PlacementState placementStateValue;      // 0xE4C
    int nextCivilianToTaskValue;             // 0xF7C
    int nextIdleSoldierGroupToTaskValue;     // 0xF80
    int nextActiveSoldierGroupToTaskValue;   // 0xF84
    int builtFirstStoragePit;                // 0xF88
    int builtFirstGranary;                   // 0xF8C
    ulong lastBuildTime;                     // 0xF90
    ulong lastAttackResponseBuildInsertionTime; // 0xF94
    ulong lastCoopTributeDemandTime;         // 0xF98
    ulong lastCoopTributeGiftTime;           // 0xF9C
    ulong lastCoopAttackDemandTime;          // 0xFA0
    int zoomingToNextAge;                    // 0xFA4
    ulong lastUngroupedSoldierTaskTime;      // 0xFA8
    AttackState attackStateValue;            // 0xFAC
    int hitsByPlayer[9];                     // 0xFD8
    int lastUpdateAreaTimeValue;             // 0xFFC
    int averageUpdateAreaTimeValue;          // 0x1000
    int updateAreaAverageCount;              // 0x1004
    int updateAreaAverageTotal;              // 0x1008

    TribeTacticalAIModule(void* param_1, int param_2);
    TribeTacticalAIModule(int param_1, int param_2);
    virtual ~TribeTacticalAIModule();
    virtual char* updateAreaName();
    virtual int update(int param_1);
    virtual void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    virtual int save(int param_1);
    virtual void logGroupDebug(int param_1, char* param_2);
    virtual int doSomething();
    virtual int clearArea(int param_1, float param_2, float param_3, float param_4, float param_5);
    virtual void addObject(RGE_Static_Object* param_1);
    virtual void removeObject(int param_1);
    virtual void evaluateCivilianDistribution();
    virtual int taskCivilians(ulong param_1, ulong param_2);
    virtual void taskIdleSoldiers(ulong param_1, ulong param_2);
    virtual void taskActiveSoldiers(ulong param_1, ulong param_2);
    virtual void playTaskSoldiers(ulong param_1, ulong param_2);
    virtual void taskUngroupedSoldiers();
    virtual void taskBoats();
    virtual void evaluateOpenTasks();
    virtual void evaluateBuildListInsertions();
    virtual int numberCivilians();
    virtual int numberCivilianExplorers();
    virtual int numberGatherers();
    virtual int desiredNumberCivilianExplorers();
    virtual int desiredNumberGatherers();
    virtual int numberSoldiers();
    virtual int numberSoldierExplorers();
    virtual int numberBoats();
    virtual int neededResource(int param_1);
    virtual int neededResourceAmount(int param_1);
    virtual void detask(int param_1);
    virtual int strategicNumber(int param_1);
    virtual void setStrategicNumber(int param_1, int param_2);
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual int numberIdleSoldiers();
    virtual int numberSoldiersWithPriority(int param_1, int param_2, int param_3);
    virtual int numberWarshipsWithPriority(int param_1, int param_2);
    virtual int idleSoldier();
    virtual int idleCivilian(int param_1);
    virtual int idleCivilian(int param_1, XYPoint* param_2, int param_3);
    virtual int civilian(XYPoint* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    virtual int unit(int param_1, int param_2, int param_3);
    virtual int busyWithAction(int param_1, int param_2);
    virtual void displayCivilianDistribution();
    virtual void updateNeededResources();
    virtual void updateGathererDistribution();
    virtual int stopUnit(int param_1, int param_2);
    virtual int moveUnit(int param_1, float param_2, float param_3, int param_4);
    virtual int groupGatherUnit(int param_1, int param_2, float param_3, float param_4, float param_5, float param_6, int param_7);
    virtual int highLevelTaskExplorer(int param_1, int param_2);
    virtual int highLevelTaskGatherer(int param_1, ulong param_2);
    virtual int taskPlay(int param_1, int* param_2, int param_3, int param_4, int param_5, Waypoint* param_6, int param_7);
    virtual int taskBuilder(int param_1, BuildItem* param_2, ConstructionItem* param_3, ulong param_4);
    virtual int taskBuilder(int param_1, RGE_Static_Object* param_2);
    virtual int taskRepairer(int param_1, RGE_Static_Object* param_2);
    virtual int taskGatherer(int param_1, int param_2, int param_3, ulong param_4, int* param_5);
    virtual int taskExplorer(int param_1, int param_2);
    virtual int taskExplorer(int param_1, float param_2, float param_3);
    virtual int taskExplorer(int param_1, float param_2, float param_3, int param_4);
    virtual int taskFollower(int param_1, int param_2, float param_3, int param_4);
    virtual int taskDefender(int param_1, int param_2, float param_3, int param_4);
    virtual int taskWaterExplorer(int param_1);
    virtual int taskWaterTrader(int param_1, int param_2);
    virtual int taskWaterFisher(int param_1, int param_2, float param_3, float param_4);
    virtual int taskAttacker(int param_1, float param_2, float param_3, int param_4, int param_5, Waypoint* param_6, int param_7, int param_8, int param_9);
    virtual int taskDefender(int param_1, int param_2);
    virtual int taskDefender(int param_1, float param_2, float param_3);
    virtual int taskTrain(BuildItem* param_1);
    virtual int taskResearch(BuildItem* param_1);
    virtual int taskToEnter(int param_1, int param_2);
    virtual int taskTransporter(int param_1, float param_2, float param_3);
    virtual void removeFromTaskLists(int param_1);
    virtual int calculatePriority(float param_1);
    virtual void setupSoldierGroups();
    virtual void fillSoldierGroups();
    virtual int numberUngroupedSoldiers();
    virtual int numberExtraGroupedSoldiers();
    virtual int numberUngroupedArtifacts();
    virtual void displaySoldierGroups();
    virtual void setupBoatGroups();
    virtual void fillBoatGroups();
    virtual int numberUngroupedWarBoats();
    virtual int numberExtraGroupedWarBoats();
    virtual int numberUngroupedFishingBoats();
    virtual int numberUngroupedTradeBoats();
    virtual int numberUngroupedTransportBoats();
    virtual void displayBoatGroups();
    virtual TacticalAIGroup* createGroup(int param_1);
    virtual int removeGroup(int param_1);
    virtual int removeAllGroups(int param_1);
    virtual TacticalAIGroup* group(int param_1, int param_2, int param_3, int param_4);
    virtual TacticalAIGroup* bestGroup(int param_1, int param_2, int param_3, XYPoint* param_4, int param_5);
    virtual TacticalAIGroup* readyAndIdleGroup(int param_1, int param_2, XYPoint* param_3);
    virtual int addToGroup(int param_1, int param_2);
    virtual int removeFromGroup(int param_1, int param_2);
    virtual int removeFromGroup(int param_1);
    virtual TacticalAIGroup* groupUnitIsIn(int param_1);
    virtual int numberGroups(int param_1, int param_2);
    virtual int numberUnitsInGroups(int param_1);
    virtual int numberItemsToAttack();
    virtual int itemToCapture();
    virtual int itemToBringToArea();
    virtual int numberItemsToDefend();
    virtual ulong attackLimiterTime(int param_1);
    virtual void resetAttackSeparationTime();
    virtual int setGatherLocation(TacticalAIGroup* param_1);
    virtual int setAllGroupLocations(TacticalAIGroup* param_1);
    virtual void setGroupInfluences(InfluenceMap* param_1);
    virtual int selectBestCommander(TacticalAIGroup* param_1);
    virtual int selectBestCommander(ManagedArray<int>* param_1);
    virtual int dealWithGAIAAttacker(RGE_Static_Object* param_1, RGE_Static_Object* param_2);
    virtual void addWaypoint(int param_1, uchar param_2, uchar param_3);
    virtual int importantGroupLeader(int param_1);
    virtual void enableAttack(int param_1);
    virtual int unexploredArea(int param_1, XYPoint* param_2);
    virtual UnitData* gatherer(int param_1);
    virtual UnitData* addGatherer(int param_1);
    virtual int removeGatherer(int param_1);
    virtual int isGatherer(int param_1);
    virtual int requiredGatherAmount(int param_1);
    virtual void trackUnitGather(int param_1, int param_2, int param_3);
    virtual int deleteUnit(int param_1);
    virtual int numberAvailableStoragePits(int* param_1, int* param_2, int param_3);
    virtual int numberAvailableGranaries(int* param_1, int* param_2);
    virtual int initialExplorationSatisfied();
    virtual void checkForBuildInsertion(int param_1, int param_2, int param_3);
    virtual int isFarmer(RGE_Static_Object* param_1);
    virtual int numberFarmers();
    virtual int inAge(int param_1);
    virtual void stuffAvoidancePath(TacticalAIGroup* param_1, Path* param_2);
    virtual void checkForAttackResponseBuildInsertions(int param_1);
    virtual void checkForCoopTributeDemand();
    virtual void checkForCoopTributeGift();
    virtual void checkForASAPAgeResearch();
    virtual void checkForCoopAttack(int param_1, int param_2, int param_3);
    virtual int processCoopAttack(int param_1, int param_2, int param_3, int param_4);
    virtual int resourceDifference(int param_1);
    virtual int actualGathererCount(int param_1);
    virtual int actualGathererCountByRealResourceID(int param_1);
    virtual int desiredGathererCount(int param_1);
    virtual void taskElephantGatherers(int param_1, int param_2, int param_3);
    virtual void checkTradeBoats();
    virtual int numberGatherersWithTarget(int param_1);
    virtual void checkStaleAttackGroups();
    virtual int numberWaterExplorers();
    virtual void saveTheTown(int param_1);
};

static_assert(sizeof(TribeTacticalAIModule) == 0x100C, "TribeTacticalAIModule Size Mismatch");
static_assert(offsetof(TribeTacticalAIModule, updateAreaAverageTotal) == 0x1008, "TribeTacticalAIModule Offset Mismatch");

