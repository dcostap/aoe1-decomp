#ifndef AOE1_TAITACMD_CONTEXT_H
#define AOE1_TAITACMD_CONTEXT_H

// Canonical local declarations for the original taitacmd.cpp source module.
// PDB types prove the two main layouts below. Keep this header local until the
// shared AI class surfaces have complete review.

typedef unsigned char uchar;
typedef unsigned long ulong;

extern "C" double __cdecl ceil(double);
extern unsigned long debug_timeGetTime(const char*, int);
extern "C" unsigned long debug_timeGetTime(char*, int);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

struct XYPoint {
    int x;
    int y;
};

struct XYZPoint {
    int x;
    int y;
    int z;
};

class Waypoint {
public:
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char pad_0D[3];
};

class Path;
class BuildItem;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class TacticalAIGroup;
class TribeTacticalAIModule;
class TribeMainDecisionAIModule;
class TribeInformationAIModule;
class TribeStrategyAIModule;
class UnitAIModule;
class ObjectMemory;
class AIModuleMessage;

TacticalAIGroup* createGroup(void* self, int arg);

class AIModule {
public:
    virtual ~AIModule();
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
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
    virtual int filterOutMessage(AIModuleMessage*);
    char gap_004[0xEC];
    void logCommonHistory(char*, ...);
};

class TacticalAIModule : public AIModule {
public:
    virtual ~TacticalAIModule();
    TacticalAIModule(void* owner, int player);
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray(int desired_number = 0)
        : value(0), numberValue(0), desiredNumberValue(desired_number),
          maximumSizeValue(0) {}

    ~ManagedArray()
    {
        if (this->value != 0) {
            delete[] this->value;
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }

    T& operator[](int index)
    {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                int i = 0;
                for (; i < this->maximumSizeValue && i < new_size; i++)
                    new_value[i] = this->value[i];
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int add(T item)
    {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == item)
                return 0;
        }
        if (this->numberValue > this->maximumSizeValue - 1)
            this->resize(this->numberValue + 1);
        this->value[this->numberValue] = item;
        this->numberValue++;
        return 1;
    }

    int contains(const T& item) const
    {
        int i;
        T wanted;
        T current;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                return 0;
            current = this->value[i];
            wanted = item;
            if (current == wanted)
                return 1;
        }
        return 0;
    }

    int remove(T item)
    {
        int i = 0;
        int maximum = this->maximumSizeValue;
        for (; i < maximum; i++) {
            if (this->value[i] == item)
                break;
        }
        if (i >= maximum)
            return 0;
        maximum--;
        if (i < maximum) {
            do {
                this->value[i] = this->value[i + 1];
                i++;
            } while (i < this->maximumSizeValue - 1);
        }
        this->numberValue--;
        if (this->numberValue < 0)
            this->numberValue = 0;
        return 1;
    }

    const int number() const { return this->numberValue; }

    void zeroNumber()
    {
        this->numberValue = 0;
    }

    void setDesiredNumber(int number)
    {
        this->desiredNumberValue = number;
    }

    int resize(int new_size);
};

typedef ManagedArray<int> ManagedArray_int;
typedef ManagedArray<int> ManagedIntArray;

struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    unsigned long lastTaskTime;
};

struct OldUnitData {
    int data1;
    int data2;
    int data3;
    int data4;
    int data5;
};

class ResourceItem {
public:
    virtual ~ResourceItem();
    char bytes[0x6C];
    ResourceItem(int count);
    int value(int index);
    static void setValue(ResourceItem* self, int index, int value);
};

struct PlacementState {
    int buildingTypeID;
    float buildingSize;
    char buildingName[256];
    int builderID;
    int minimumDistance;
    int maximumDistance;
    int active;
    XYPoint bestPoint;
    int bestPointValue;
    int iterationX;
    int randomInfluence;
    BuildItem* buildItem;
};

struct AttackState {
    int bestTargetID;
    float bestTargetValue;
    int bestTargetMemoryIndex;
    int iterationIndex;
    int attackGroupID;
    int playID;
    unsigned char phase;
    unsigned char pad_19[3];
    int bestNonWallTargetID;
    float bestNonWallTargetValue;
    int bestNonWallTargetMemoryIndex;
    int active;
};

class RGE_Visible_Map {
public:
    float percentExplored();
};

class RGE_Game_World {
public:
    int pad_00;
    union { int world_time; int tick; };
    char gap_08[0x34];
    short player_num;
    char gap_3E[0xBA];
    unsigned int availableComputerPlayerUpdateTime;
    int difficultyLevel();
    void useComputerPlayerUpdateTime(unsigned int);
    void selectNextComputerPlayer(int);
    RGE_Static_Object* object(int);
};

#define TAITACMD_VPAD1(n) virtual void vpad##n();
#define TAITACMD_VPAD2(n) TAITACMD_VPAD1(n) TAITACMD_VPAD1(n##_1)
#define TAITACMD_VPAD4(n) TAITACMD_VPAD2(n) TAITACMD_VPAD2(n##_2)
#define TAITACMD_VPAD8(n) TAITACMD_VPAD4(n) TAITACMD_VPAD4(n##_4)
#define TAITACMD_VPAD16(n) TAITACMD_VPAD8(n) TAITACMD_VPAD8(n##_8)
#define TAITACMD_VPAD32(n) TAITACMD_VPAD16(n) TAITACMD_VPAD16(n##_16)
#define TAITACMD_VPAD64(n) TAITACMD_VPAD32(n) TAITACMD_VPAD32(n##_32)

class VPlayerIsEnemy {
public:
    TAITACMD_VPAD4(0)
    TAITACMD_VPAD2(4)
    TAITACMD_VPAD1(6)
    virtual int isEnemy(int player_id);
};

class VObjWeaponRange {
public:
    TAITACMD_VPAD64(0)
    TAITACMD_VPAD2(64)
    TAITACMD_VPAD1(66)
    virtual float weaponRange();
};
class VObjCanMove {
public:
    TAITACMD_VPAD64(0)
    TAITACMD_VPAD32(64)
    TAITACMD_VPAD4(96)
    TAITACMD_VPAD2(100)
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
};
class VObjCanAttack {
public:
    TAITACMD_VPAD64(0)
    TAITACMD_VPAD32(64)
    TAITACMD_VPAD4(96)
    TAITACMD_VPAD1(100)
    virtual int canAttack(int, float, int, int, int, int);
};
class VObjCanPath {
public:
    TAITACMD_VPAD64(0)
    TAITACMD_VPAD32(64)
    TAITACMD_VPAD8(96)
    TAITACMD_VPAD1(104)
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int,
                                                  float*, int, int, int,
                                                  int, int);
};
class VObjPathPoint {
public:
    TAITACMD_VPAD64(0)
    TAITACMD_VPAD32(64)
    TAITACMD_VPAD8(96)
    TAITACMD_VPAD2(104)
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
};
class VObjFindAvoidancePath {
public:
    TAITACMD_VPAD64(0)
    TAITACMD_VPAD32(64)
    TAITACMD_VPAD16(96)
    TAITACMD_VPAD2(112)
    TAITACMD_VPAD1(114)
    virtual Path* findAvoidancePath(XYZPoint*, float, int);
};

class RGE_Player {
public:
    TAITACMD_VPAD32(0)
    TAITACMD_VPAD16(32)
    TAITACMD_VPAD2(48)
    virtual void cmdC8(int commander, int unit, int amount);
    virtual void cmdCC(int commander, int unit);

    char gap_004[0x34];
    RGE_Visible_Map* visibleMap;
    union {
        RGE_Game_World* world;
        struct TimeList* list;
    };
    char gap_040[0x0A];
    union { short id; short player_id; };
    char gap_04C[4];
    float* attributes;

    int isEnemy(int player_id);
};

class AIPlayStatus {};
class RGE_Action {
public:
    char gap_00[0x0C];
    unsigned char state;
};
class RGE_Action_List {
public:
    unsigned char have_action();
    RGE_Action* get_action();
};
class UnitAIModule {
public:
    char gap_000[0x12C];
    AIPlayStatus* playStatus;
    int currentAction();
    int currentOrder();
    int currentTarget();
};
class MasterObject {
public:
    virtual ~MasterObject();
    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
    char gap_16[0x12];
    float los;
    unsigned char obj_max;
};

class RGE_Master_Static_Object : public MasterObject {
public:
    virtual ~RGE_Master_Static_Object();
};
class ObjectList {
public:
    char gap_00[0x08];
    short number_of_objects;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    TAITACMD_VPAD64(obj)
    TAITACMD_VPAD4(obj64)
    virtual int passableTile(float, float, int);
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x10];
    RGE_Static_Object* inside_obj;
    ObjectList* objects;
    char gap_28[0x08];
    float hp;
    char gap_34[0x04];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    char gap_49[0x05];
    unsigned char type;
    char gap_4F[0x135];
    RGE_Action_List* actions;

    UnitAIModule* unitAI();
    unsigned char currentZone();
    unsigned char lookupZone(int, int);
    unsigned char lookupZone(XYPoint point);
    float pathDistance(int, void*, int, int, int);
    float pathDistance2(int, void*, int, int, int, int, int);
    int canMoveTo(int, int, int, float);
    int canPathTo(int, int, int, float, int, void*, int, int, int, int, int);
    int pathPoint(int, float*, void*);
    float distance_to_position(float, float, float);
};

class ObjectMemory {
public:
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    char gap_0E[2];
    int attackAttempts;
};

class BuildAIModule {
public:
    char gap_000[0x05BC];
    int buildListLength();
};

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];
    char* name();
};

class BuildItem : public BaseItem {};
class ConstructionItem;

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;
    BuildItem* nextBuildableItem(int);
    void unskipBuildList(int, int);
    int loadBuildList(char*, RGE_Player*);
    int numberBuiltOrInProgressItemsOfType(int, int);
};

class TribeConstructionAIModule {
public:
    char gap_000[0x314];
    TribeMainDecisionAIModule* md;
    ConstructionItem* placeStructure(BuildItem*, int, PlacementState&,
                                     unsigned long);
};

class TribeResourceAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    int numberResourcesValue;
    int resource(int);
};

class DiplomacyAIModule {
public:
    char bytes[0x150];
    int mostHated(int, int, int, int);
    int mostLiked(int, int);
    int isEnemy(int);
    int isChangeable(int);
    int stance(int, int);
    int isAlly(int);
    int isNeutral(int);
    void setRelation(int, int);
};

class TribeInformationAIModule {
public:
    char gap_00000[0xF0];
    ManagedArray<int> farmsTaskedThisUpdate;
    char gap_00100[0x10090 - 0x100];
    int fullyExploredZone(int zone);
    int numberGameIDsOwnedBy(int player, int gameID);
    ObjectMemory* objectToDefend(int commander_id);
    ObjectMemory* objectMemory(int id);
    ObjectMemory* objectToAttack(int, int, int, int, int&);
    ObjectMemory* objectToAttackByGroup(int, TacticalAIGroup*, AttackState*, ulong);
    ObjectMemory* objectToAttackWithPlay(int, int*, int, int*, int*, int*, int*);
    ObjectMemory* higherPriorityObjectToDefend(int, int, int);
    void blotExploredMap(int, int, int, int);
    void addEnemyInfluences(int, int);
    void addPriorAttackInfluences(int, int);
    int findStagingPoint(XYPoint, XYPoint*, int, int, int, int, int);
    int withinXTilesOfObject(RGE_Static_Object*, int, int, int, int, int);
    int closestDropsiteResID(int);
    void updateResourceDropsites(int);
};

class TribeStrategyAIModule {
public:
    char gap_000[0x5F8];
    int currentVictoryCondition();
    Waypoint* targetPoint1();
    Waypoint* targetPoint2();
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray<int> objects;
    RGE_Static_Object* object(int id);
    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int, int);
    int numberObjectsWithAction(int);
    RGE_Static_Object* mostDamaged(int, int);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    char emotionalAI[0x1C0];
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;
    char gap_1146C[0x1100];
    RGE_Player* aiPlayer;
    int isEnemy(int player_id);
    int isMoveable(int id);
    void updateBuildAIWithObjects();
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    union { int idValue; int id_; };
    union { int inUseValue; int inUse_; };
    union { int typeValue; int type_; };
    union { int subTypeValue; int subType_; };
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    union { int numberUnitsValue; int numberUnits_; };
    union { int desiredNumberUnitsValue; int desiredNumberUnits_; };
    union { int commanderValue; int commander_; };
    union { int originalHitPointsValue; int originalHitPoints_; };
    union { int originalUnitNumberValue; int originalUnitNumber_; };
    union { Waypoint locationValue; Waypoint location_; };
    union { int actionValue; int action_; };
    union { int targetValue; int target_; };
    union { int targetTypeValue; int targetType_; };
    union { Waypoint targetLocationValue; Waypoint targetLocation_; };
    union { Waypoint gatherLocationValue; Waypoint gatherLocation_; };
    union { Waypoint retreatLocationValue; Waypoint retreatLocation_; };
    union { int priorityValue; int priority_; };
    union { int waitCodeValue; int waitCode_; };
    union { int assistGroupIDValue; int assistGroupID_; };
    union { int assistGroupTypeValue; int assistGroupType_; };
    union { unsigned long consecutiveIdleUnitCountValue; unsigned long consecutiveIdleUnitCount_; };
    int playNumberValue;
    unsigned char numberAttackWaypointsValue;
    unsigned char currentAttackWaypointValue;
    unsigned char pad_1D6[2];
    Waypoint attackWaypoints[15];
    unsigned char consecutiveGatherAttemptsValue;
    unsigned char pad_2C9[3];
    int numberObjectsToDestroyValue;
    int objectsToDestroyValue[20];
    int objectsToDestroyOwnerValue;
    int objectsToDestroyCommanderZoneValue;
    unsigned long lastAttackRoundupTime;
    unsigned long lastAddedUnitTimeValue;

    TacticalAIGroup();
    static void load(TacticalAIGroup* self, int file);
    int load(int);
    int save(int);
    int id() const;
    void setID(int);
    int inUse() const;
    void setInUse(int);
    int type() const;
    void setType(int);
    int subType() const;
    void setSubType(int);
    int addUnit(int, TribeMainDecisionAIModule*);
    int removeUnit(int, TribeMainDecisionAIModule*);
    int removeUnitByIndex(int, TribeMainDecisionAIModule*);
    void removeUnits(TribeMainDecisionAIModule*);
    int removeExtraUnits(TribeMainDecisionAIModule*);
    int removeUnboardedUnits(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    int containsUnit(int);
    int numberUnits() const;
    int unit(int);
    int unitOriginalHitPoints(int);
    int desiredNumberUnits() const;
    void setDesiredNumberUnits(int);
    int commander() const;
    void setSpecificCommander(int, TribeMainDecisionAIModule*);
    int currentHitPoints(TribeMainDecisionAIModule*) const;
    int originalHitPoints() const;
    void setOriginalHitPoints(int);
    int originalUnitNumber() const;
    void setOriginalUnitNumber(int);
    const Waypoint& location() const;
    void setCurrentAttackWaypoint(unsigned char);
    void setLocation(float, float, float);
    void setLocation(int, int, int);
    int action() const;
    void setAction(int);
    int target() const;
    void setTarget(int);
    int targetType() const;
    void setTargetType(int);
    const Waypoint& targetLocation() const;
    void setAllLocations(float, float, float);
    void setTargetLocation(float, float, float);
    void setTargetLocation(int, int, int);
    const Waypoint& gatherLocation() const;
    void setGatherLocation(float, float, float);
    void setGatherLocation(int, int, int);
    const Waypoint& retreatLocation() const;
    void setRetreatLocation(float, float, float);
    void setRetreatLocation(int, int, int);
    int priority() const;
    void setPriority(int);
    int waitCode() const;
    void setWaitCode(int);
    int assistGroupID() const;
    void setAssistGroupID(int);
    int assistGroupType() const;
    void setAssistGroupType(int);
    int isGathered(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    int allUnitsIdle(TribeMainDecisionAIModule*, int);
    unsigned long consecutiveIdleUnitCount() const;
    void setConsecutiveIdleUnitCount(unsigned long);
    int task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int, int);
};

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
    union { int desiredNumberGatherersValue; int desiredNumberGatherers; };
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
    union { int neededResourceValue[4]; int resourceMappingValue[4]; };
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
    virtual int save(int);
    virtual int update(int);
    virtual void notify(int, int, int, long, long, long);
    TribeTacticalAIModule(void*, int);
    TribeTacticalAIModule(int, int);
    int removeAllGroups(int);
    char* updateAreaName();
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void enableAttack(int);
    int doSomething();
    void logGroupDebug();
    int clearArea(int, float, float, float, float);
    void addObject(RGE_Static_Object*);
    void removeFromTaskLists(int);
    int removeFromGroup(int);
    void removeObject(int);
    int busyWithAction(int, int);
    void setupSoldierGroups();
    void updateNeededResources();
    void setupBoatGroups();
    void fillBoatGroups();
    void taskBoats();
    void fillSoldierGroups();
    void playTaskSoldiers(unsigned long, unsigned long);
    void saveTheTown(int);
    int taskResearch(BuildItem*);
    int taskTrain(BuildItem*);
    int initialExplorationSatisfied();
    int civilian(XYPoint*, int, int, int, int, int);
    int taskBuilder(int, BuildItem*, ConstructionItem*, unsigned long);
    int taskBuilder(int, RGE_Static_Object*);
    int taskRepairer(int, RGE_Static_Object*);
    void evaluateOpenTasks();
    void checkForCoopTributeDemand();
    void checkForCoopTributeGift();
    void checkForASAPAgeResearch();
    void checkTradeBoats();
    void checkStaleAttackGroups();
    void evaluateBuildListInsertions();
    void evaluateCivilianDistribution();
    int numberSoldierExplorers();
    void displayCivilianDistribution();
    void updateGathererDistribution();
    int taskCivilians(unsigned long, unsigned long);
    void taskIdleSoldiers(unsigned long, unsigned long);
    void taskActiveSoldiers(unsigned long, unsigned long);
    int idleCivilian(int);
    int idleCivilian(int, XYPoint&, int);
    void removeGatherer(int);
    UnitData* addGatherer(int);
    int highLevelTaskGatherer(int, unsigned long);
    int highLevelTaskExplorer(int, int);
    int stopUnit(int, int);
    int numberItemsToDefend();
    int numberItemsToAttack();
    int numberUnitsInGroups(int);
    int itemToCapture();
    int itemToBringToArea();
    unsigned long attackLimiterTime(int);
    void checkForCoopAttack(int, int, int);
    TacticalAIGroup* bestGroup(int, int, int, XYPoint*, int);
    TacticalAIGroup* group(int, int, int, int);
    int taskToEnter(int, int);
    int taskTransporter(int, float, float);
    int taskDefender(int, int, float, int);
    int taskAttacker(int, float, float, int, int, Waypoint*, int, int, int);
    int moveUnit(int, float, float, int);
    int numberGroups(int, int);
    void stuffAvoidancePath(TacticalAIGroup*, Path*);
    TacticalAIGroup* groupUnitIsIn(int);
    TacticalAIGroup* createGroup(int);
};

typedef char taitacmd_verify_group_size[sizeof(TacticalAIGroup) == 0x330 ? 1 : -1];
typedef char taitacmd_verify_module_size[sizeof(TribeTacticalAIModule) == 0x100C ? 1 : -1];

#endif
