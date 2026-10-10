#ifndef AOE1_TAITACMD_H
#define AOE1_TAITACMD_H

#include "ai_attack_state.h"
#include "ai_placement_state.h"
#include "airesitm.h"
#include "aitacmod.h"
#include "tactical_group.h"
#include "tactical_old_unit_data.h"
#include "tactical_unit_data.h"
#include "utmarray.h"

typedef unsigned char uchar;
typedef unsigned long ulong;

class BuildItem;
class ConstructionItem;
class InfluenceMap;
class Path;
class RGE_Player;
class RGE_Static_Object;
class TribeMainDecisionAIModule;
struct ObjectMemory;
struct XYPoint;
struct Waypoint;

// Strategic-number indices into the AI `sn` arrays. The names are the original
// comments from the shipped data2/*.per personality files. Unnamed indices stay numeric.
#define SNPercentCivilianExplorers         0
#define SNPercentCivilianBuilders          1
#define SNPercentCivilianGatherers         2
#define SNCapCivilianExplorers             3
#define SNCapCivilianBuilders              4
#define SNCapCivilianGatherers             5
#define SNMinimumAttackGroupSize           16
#define SNTotalNumberExplorers             18
#define SNPercentEnemySightedResponse      19
#define SNEnemySightedResponseDistance     20
#define SNSentryDistance                   22
#define SNArtifactReturnDistance           23
#define SNPercentVictoryClamp              24
#define SNMinimumDefendGroupSize           25
#define SNMaximumAttackGroupSize           26
#define SNMaximumDefendGroupSize           28
#define SNMinimumPeaceLikeLevel            29
#define SNPercentHealthRetreat             30
#define SNPercentDeathRetreat              31
#define SNPercentExplorationRequired       32
#define SNZeroPriorityDistance             34
#define SNMinimumCivilianExplorers         35
#define SNNumberAttackGroups               36
#define SNAttackGroupMakeup                37
#define SNNumberDefendGroups               38
#define SNDefendGroupMakeup                39
#define SNGroupFillMethod                  40
#define SNAttackGroupGatherSpacing         41
#define SNNumberExploreGroups              42
#define SNMinimumExploreGroupSize          43
#define SNMaximumExploreGroupSize          44
#define SNExploreGroupMakeup               45
#define SNAttackSeparationTime             46
#define SNAttackCoordination               47
#define SNAttackResponseSeparationTime     48
#define SNRetreatAfterTargetDestroyed      49
#define SNGoldDefendPriority               50
#define SNStoneDefendPriority              51
#define SNForageDefendPriority             52
#define SNChokePointDefendPriority         53
#define SNRuinsDefendPriority              54
#define SNArtifactDefendPriority           55
#define SNTownDefendPriority               56
#define SNDefenseDistance                  57
#define SNNumberBoatAttackGroups           58
#define SNMinimumBoatAttackGroupSize       59
#define SNMaximumBoatAttackGroupSize       60
#define SNNumberBoatExploreGroups          61
#define SNMinimumBoatExploreGroupSize      62
#define SNMaximumBoatExploreGroupSize      63
#define SNDesiredNumberTradeEscorts        64
#define SNDesiredNumberFishEscorts         65
#define SNDesiredNumberTransportEscorts    66
#define SNNumberBoatDefendGroups           67
#define SNMinimumBoatDefendGroupSize       68
#define SNMaximumBoatDefendGroupSize       69
#define SNDockDefendPriority               70
#define SNLockAttackAndAttackResponse      71
#define SNSentryDistanceVariation          72
#define SNMinimumTownSize                  73
#define SNMaximumTownSize                  74
#define SNGroupCommanderSelectionMethod    75
#define SNConsecutiveIdleUnitLimit         76
#define SNTargetEvaluationDistance         77
#define SNTargetEvaluationHitpoints        78
#define SNTargetEvaluationDamageCapability 79
#define SNTargetEvaluationKills            80
#define SNTargetEvaluationAllyProximity    81
#define SNTargetEvaluationROF              82
#define SNTargetEvaluationRandomness       83
#define SNNumberWallGates                  84
#define SNSizeWallGates                    85
#define SNStoragePitMaxDistance            86
#define SNGranaryMaxDistance               87
#define SNTacticalUpdateFrequency          88
#define SNTargetEvaluationAttackAttempts   89
#define SNTargetEvaluationRange            90
#define SNPercentUnitHealthRetreat         91
#define SNDefendOverlapDistance            92
#define SNScaleMinimumAttackGroupSize      93
#define SNScaleMaximumAttackGroupSize      94
#define SNScalePercentHealthRetreat        95
#define SNScalePercentDeathRetreat         96
#define SNScalePercentUnitHealthRetreat    97
#define SNAttackGroupSizeRandomness        98
#define SNScalingFrequency                 99
#define SNMaximumGAIAAttackResponse        100
#define SNBuildFrequency                   101
#define SNAttackSeparationTimeRandomness   102
#define SNAttackIntelligence               103
#define SNInitialAttackDelay               104
#define SNTributeAmount                    124
#define SNTributeChatFrequency             125
#define SNTributeChatRandomness            126
#define SNTributeTimeout                   127
#define SNTributePlayer                    128
#define SNTributeSuccessOutcome            129
#define SNTributeFailureOutcome            130
#define SNGroupLeaderDefenseDistance       131
#define SNTributePersistence               132
#define SNTributeRevokeOnAttack            133
#define SNBlotExplorationMap               135
#define SNTaskUngroupedSoldiers            143
#define SNNumberMaxSkipCycles              146
#define SNSpecificBuildItemToBuild         175
#define SNSpecificBuildItemTime            176
#define SNPercentageExploreExterminators   198
#define SNAutoBuildFarms                   206
#define SNEasiestReactionPercentage        218
#define SNEasierReactionPercentage         219

class TribeTacticalAIModule : public TacticalAIModule {
  public:
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

    virtual ~TribeTacticalAIModule();
    virtual int save(int outfile);
    virtual int update(int timeLimit);
    virtual void notify(int callerID, int recipientID, int mType, long p1, long p2, long p3);
    TribeTacticalAIModule(void* pW, int pID);
    TribeTacticalAIModule(int pID, int infile);
    int removeAllGroups(int tID);
    char* updateAreaName();
    void setMainDecisionAI(TribeMainDecisionAIModule* m);
    void enableAttack(int type);
    int doSomething();
    void __cdecl logGroupDebug(int gID, char* textIn, ...);
    int clearArea(int id, float minX, float minY, float maxX, float maxY);
    void addObject(RGE_Static_Object* bo);
    void removeFromTaskLists(int gID);
    int removeFromGroup(int uID);
    int removeFromGroup(int uID, int gID);
    int setGatherLocation(TacticalAIGroup* g);
    void trackUnitGather(int unitID, int attributeID, int amount);
    void removeObject(int id);
    int busyWithAction(int id, int a);
    void setupSoldierGroups();
    void updateNeededResources();
    void setupBoatGroups();
    void fillBoatGroups();
    void taskBoats();
    void fillSoldierGroups();
    void playTaskSoldiers(unsigned long startTime, unsigned long availableTime);
    void saveTheTown(int idToKill);
    int taskResearch(BuildItem* researchItem);
    int taskTrain(BuildItem* trainItem);
    int initialExplorationSatisfied();
    int civilian(XYPoint& point, int closestToPoint, int a1, int a2, int a3, int useFarmers);
    int taskBuilder(int builder, BuildItem* newBuilding, ConstructionItem* ci, unsigned long startTime);
    int taskBuilder(int builder, RGE_Static_Object* building);
    int taskRepairer(int builder, RGE_Static_Object* building);
    void evaluateOpenTasks();
    void checkForCoopTributeDemand();
    void checkForCoopTributeGift();
    void checkForASAPAgeResearch();
    void checkTradeBoats();
    void checkStaleAttackGroups();
    void evaluateBuildListInsertions();
    void evaluateCivilianDistribution();
    int numberSoldierExplorers();
    int numberCivilians() const;
    int numberCivilianExplorers() const;
    int numberGatherers() const;
    int desiredNumberCivilianExplorers() const;
    int desiredNumberGatherers() const;
    int numberSoldiers() const;
    int numberBoats() const;
    int neededResource(int n) const;
    int neededResourceAmount(int n) const;
    void detask(int uid);
    void setStrategicNumber(int sNum, int v);
    int strategicNumber(int sNum);
    int calculatePriority(float distance);
    int groupGatherUnit(int uID, int tID, float x, float y, float z, float range, int priority);
    void resetAttackSeparationTime();
    int importantGroupLeader(int cID);
    int taskExplorer(int eID, int civilian);
    int taskExplorer(int eID, float x, float y);
    int taskExplorer(int eID, float x, float y, int civilian);
    int taskPlay(int commander, int* groupUnits, int groupCount, int target, int play, Waypoint* path, int pathLength);
    int taskWaterFisher(int unitID, int targetID, float x, float y);
    int taskWaterTrader(int unitID, int targetID);
    void displayCivilianDistribution();
    void updateGathererDistribution();
    int taskCivilians(unsigned long startTime, unsigned long availableTime);
    void taskUngroupedSoldiers();
    void taskIdleSoldiers(unsigned long startTime, unsigned long availableTime);
    void taskActiveSoldiers(unsigned long startTime, unsigned long availableTime);
    int idleCivilian(int checkGroup);
    int idleCivilian(int checkGroup, XYPoint& point, int closestToPoint);
    int removeGatherer(int id);
    UnitData* addGatherer(int id);
    int highLevelTaskGatherer(int unitID, unsigned long startTime);
    int highLevelTaskExplorer(int unitID, int civilian);
    int unit(int action, int target, int targetType);
    int stopUnit(int uID, int priority);
    int numberItemsToDefend();
    int numberItemsToAttack();
    int numberUnitsInGroups(int type);
    int itemToCapture();
    int itemToBringToArea();
    unsigned long attackLimiterTime(int snType);
    void checkForCoopAttack(int playerToAttack, int x, int y);
    TacticalAIGroup* bestGroup(int type, int action, int distance, XYPoint& point, int zone);
    TacticalAIGroup* group(int gID, int type, int action, int targetID);
    int taskToEnter(int unitID, int targetID);
    int taskTransporter(int unitID, float x, float y);
    int taskDefender(int uID, int tID, float range, int priority);
    int taskDefender(int defender, int targetID);
    int taskDefender(int defender, float x, float y);
    int taskAttacker(
        int soldierID, float xLocation, float yLocation, int targetID, int targetOwner, Waypoint* path, int pathLength,
        int commanderID, int idleAttackRoundup
    );
    int moveUnit(int uID, float x, float y, int priority);
    int numberGroups(int type, int action);
    void stuffAvoidancePath(TacticalAIGroup* group, Path* path);
    TacticalAIGroup* groupUnitIsIn(int uID);
    TacticalAIGroup* createGroup(int initID);
    int numberIdleSoldiers();
    int numberSoldiersWithPriority(int priority, int flag, int zeroWorkingArea);
    int numberWarshipsWithPriority(int priority, int flag);
    int idleSoldier();
    int taskGatherer(int id, int resourceType, int limitedTaskLimit, unsigned long startTime, int* triedTasking);
    int taskFollower(int uID, int tID, float range, int priority);
    int taskWaterExplorer(int explorer);
    int numberUngroupedSoldiers();
    int numberExtraGroupedSoldiers();
    int numberUngroupedArtifacts();
    void displaySoldierGroups();
    int numberUngroupedWarBoats();
    int numberExtraGroupedWarBoats();
    int numberUngroupedFishingBoats();
    int numberUngroupedTradeBoats();
    int numberUngroupedTransportBoats();
    void displayBoatGroups();
    int removeGroup(int gID);
    TacticalAIGroup* readyAndIdleGroup(int type, int distance, XYPoint& point);
    int addToGroup(int uID, int gID);
    int setAllGroupLocations(TacticalAIGroup* g);
    void setGroupInfluences(InfluenceMap& iMap);
    int selectBestCommander(TacticalAIGroup* temp);
    int selectBestCommander(ManagedArray<int>& temp);
    int inAge(int age);
    int resourceDifference(int n);
    int actualGathererCount(int n);
    int desiredGathererCount(int n);
    int dealWithGAIAAttacker(RGE_Static_Object* attacker, RGE_Static_Object* victim);
    void addWaypoint(int recipient, unsigned char x, unsigned char y);
    int unexploredArea(int uID, XYPoint& rPoint);
    UnitData* gatherer(int id);
    int isGatherer(int id);
    int requiredGatherAmount(int rType);
    int deleteUnit(int unitID);
    int numberAvailableStoragePits(int& numStoragePits, int& numUnbuiltStoragePits, int rType);
    int numberAvailableGranaries(int& numGranaries, int& numUnbuiltGranaries);
    void checkForBuildInsertion(int type, int number, int position);
    int isFarmer(RGE_Static_Object* temp);
    int numberFarmers();
    void checkForAttackResponseBuildInsertions(int playerID);
    int processCoopAttack(int caller, int playerToAttack, int x, int y);
    int actualGathererCountByRealResourceID(int n);
    void taskElephantGatherers(int mainHunterID, int numberToTask, int targetID);
    int numberGatherersWithTarget(int targetID);
    int numberWaterExplorers();
};

typedef char taitacmd_verify_group_size[sizeof(TacticalAIGroup) == 0x330 ? 1 : -1];
typedef char taitacmd_verify_module_size[sizeof(TribeTacticalAIModule) == 0x100C ? 1 : -1];

#endif
