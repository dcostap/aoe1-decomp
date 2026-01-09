#pragma once
#include "common.h"

class TacticalAIGroup {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
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
    ~TacticalAIGroup();
    int load(int param_1);
    int save(int param_1);
    int id();
    void setID(int param_1);
    int inUse();
    void setInUse(int param_1);
    int type();
    void setType(int param_1);
    int subType();
    void setSubType(int param_1);
    int addUnit(int param_1, TribeMainDecisionAIModule* param_2);
    int removeUnit(int param_1, TribeMainDecisionAIModule* param_2);
    int removeUnitByIndex(int param_1, TribeMainDecisionAIModule* param_2);
    void removeUnits(TribeMainDecisionAIModule* param_1);
    int removeExtraUnits(TribeMainDecisionAIModule* param_1);
    int removeUnboardedUnits(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2);
    int containsUnit(int param_1);
    int numberUnits();
    int unit(int param_1);
    int unitOriginalHitPoints(int param_1);
    int desiredNumberUnits();
    void setDesiredNumberUnits(int param_1);
    int commander();
    void setSpecificCommander(int param_1, TribeMainDecisionAIModule* param_2);
    int currentHitPoints(TribeMainDecisionAIModule* param_1);
    int originalHitPoints();
    void setOriginalHitPoints(int param_1);
    int originalUnitNumber();
    void setOriginalUnitNumber(int param_1);
    Waypoint* location();
    void setLocation(float param_1, float param_2, float param_3);
    int action();
    void setAction(int param_1);
    int target();
    void setTarget(int param_1);
    int targetType();
    void setTargetType(int param_1);
    Waypoint* targetLocation();
    void setAllLocations(float param_1, float param_2, float param_3);
    void setTargetLocation(float param_1, float param_2, float param_3);
    Waypoint* gatherLocation();
    void setGatherLocation(float param_1, float param_2, float param_3);
    Waypoint* retreatLocation();
    void setRetreatLocation(float param_1, float param_2, float param_3);
    int priority();
    void setPriority(int param_1);
    int waitCode();
    void setWaitCode(int param_1);
    int assistGroupID();
    void setAssistGroupID(int param_1);
    int assistGroupType();
    void setAssistGroupType(int param_1);
    int task(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2, int param_3, int param_4, int param_5);
    int isGathered(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2);
    int isTightGathered(TribeTacticalAIModule* param_1, TribeMainDecisionAIModule* param_2);
    int allUnitsIdle(TribeMainDecisionAIModule* param_1, int param_2);
    ulong consecutiveIdleUnitCount();
    void setConsecutiveIdleUnitCount(ulong param_1);
    void incrementConsecutiveIdleUnitCount(ulong param_1);
    uchar numberAttackWaypoints();
    uchar currentAttackWaypoint();
    void setCurrentAttackWaypoint(uchar param_1);
    void addAttackWaypoint(float param_1, float param_2);
    Waypoint* attackWaypoint(uchar param_1);
    int firstIdleUnit(TribeMainDecisionAIModule* param_1);
    int objectToDestroy(int param_1);
    int addObjectToDestroy(int param_1);
};

static_assert(sizeof(TacticalAIGroup) == 0x330, "TacticalAIGroup Size Mismatch");

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

    virtual int update(int param_1);                        // vt0[12]+0x30=0x4EEF40
    virtual int save(int param_1);                          // vt0[15]+0x3C=0x4EF4E0
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt0[16]+0x40=0x4F62C0
    TribeTacticalAIModule(void* param_1, int param_2);
    TribeTacticalAIModule(int param_1, int param_2);
    ~TribeTacticalAIModule();
    char* updateAreaName();
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    void logGroupDebug(int param_1, char* param_2);
    int doSomething();
    int clearArea(int param_1, float param_2, float param_3, float param_4, float param_5);
    void addObject(RGE_Static_Object* param_1);
    void removeObject(int param_1);
    void evaluateCivilianDistribution();
    int taskCivilians(ulong param_1, ulong param_2);
    void taskIdleSoldiers(ulong param_1, ulong param_2);
    void taskActiveSoldiers(ulong param_1, ulong param_2);
    void playTaskSoldiers(ulong param_1, ulong param_2);
    void taskUngroupedSoldiers();
    void taskBoats();
    void evaluateOpenTasks();
    void evaluateBuildListInsertions();
    int numberCivilians();
    int numberCivilianExplorers();
    int numberGatherers();
    int desiredNumberCivilianExplorers();
    int desiredNumberGatherers();
    int numberSoldiers();
    int numberSoldierExplorers();
    int numberBoats();
    int neededResource(int param_1);
    int neededResourceAmount(int param_1);
    void detask(int param_1);
    int strategicNumber(int param_1);
    void setStrategicNumber(int param_1, int param_2);
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
    int highLevelTaskGatherer(int param_1, ulong param_2);
    int taskPlay(int param_1, int* param_2, int param_3, int param_4, int param_5, Waypoint* param_6, int param_7);
    int taskBuilder(int param_1, BuildItem* param_2, ConstructionItem* param_3, ulong param_4);
    int taskBuilder(int param_1, RGE_Static_Object* param_2);
    int taskRepairer(int param_1, RGE_Static_Object* param_2);
    int taskGatherer(int param_1, int param_2, int param_3, ulong param_4, int* param_5);
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
    TacticalAIGroup* createGroup(int param_1);
    int removeGroup(int param_1);
    int removeAllGroups(int param_1);
    TacticalAIGroup* group(int param_1, int param_2, int param_3, int param_4);
    TacticalAIGroup* bestGroup(int param_1, int param_2, int param_3, XYPoint* param_4, int param_5);
    TacticalAIGroup* readyAndIdleGroup(int param_1, int param_2, XYPoint* param_3);
    int addToGroup(int param_1, int param_2);
    int removeFromGroup(int param_1, int param_2);
    int removeFromGroup(int param_1);
    TacticalAIGroup* groupUnitIsIn(int param_1);
    int numberGroups(int param_1, int param_2);
    int numberUnitsInGroups(int param_1);
    int numberItemsToAttack();
    int itemToCapture();
    int itemToBringToArea();
    int numberItemsToDefend();
    ulong attackLimiterTime(int param_1);
    void resetAttackSeparationTime();
    int setGatherLocation(TacticalAIGroup* param_1);
    int setAllGroupLocations(TacticalAIGroup* param_1);
    void setGroupInfluences(InfluenceMap* param_1);
    int selectBestCommander(TacticalAIGroup* param_1);
    int selectBestCommander(ManagedArray<int>* param_1);
    int dealWithGAIAAttacker(RGE_Static_Object* param_1, RGE_Static_Object* param_2);
    void addWaypoint(int param_1, uchar param_2, uchar param_3);
    int importantGroupLeader(int param_1);
    void enableAttack(int param_1);
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
};

static_assert(sizeof(TribeTacticalAIModule) == 0x100C, "TribeTacticalAIModule Size Mismatch");

