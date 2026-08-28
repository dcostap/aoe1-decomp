#ifndef AOE1_TAITACMD_H
#define AOE1_TAITACMD_H

// Declarations for the original taitacmd.cpp source module.

#include "ai_attack_state.h"
#include "airesitm.h"
#include "aitacmod.h"
#include "waypoint.h"

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

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class Path {
public:
    float length();
    void initToStart();
    float distanceToNextWaypoint();
    int moveToNextWaypoint();
    int numberOfWaypoints();
    Waypoint* currentWaypoint();
};

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
class InfluenceMap {
public:
    int setValue(int, int, int, int, unsigned char);
    int setValue(int, int);
    int decrementValue(int, int, int, int, unsigned char);
};

TacticalAIGroup* createGroup(void* self, int arg);

template <class T>
class ManagedArray {
public:
    union { T* value; T* playersToAttackValue; };
    int numberValue;
    int desiredNumberValue;
    union { int maximumSizeValue; int maximumSize; };

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
typedef ManagedArray<int> ManagedArrayInt;

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

class RGE_Visible_Map {
public:
    float percentExplored();
};

class RGE_Game_World {
public:
    int pad_00;
    unsigned long world_time; // PDB RGE_Game_World +0x04
    char gap_08[0x34];
    short player_num;
    char gap_3E[0xBA];
    unsigned int availableComputerPlayerUpdateTime;
    int difficultyLevel();
    void useComputerPlayerUpdateTime(unsigned int);
    void selectNextComputerPlayer(int);
    RGE_Static_Object* object(int);
    RGE_Player* players[9];
};

#include "player.h"

class TribeAIPlayer : public RGE_Player {
public:
    void builderTask(int, int, float, float, int);
    void taskResourceGatherer(int, int, int, float, float);
    void trainUnit(int, int, int);
    void research(int, int, int);
    unsigned char command_delete_object(RGE_Static_Object*);
    void objectCost(int, int, ResourceItem*, int);
    int objectAvailable(int);
    unsigned char command_give_attribute(int, int, float, float);
    unsigned char command_trade_attribute(int, int);
    unsigned char command_trade_attribute(int, int, float, float);
    float* resources;
};

class TRIBE_World : public RGE_Game_World {
public:
    unsigned long time;
    unsigned char coop_tribute_player;
    unsigned char pad_tribe_world[3];
    int player_count;
    int controllingComputerPlayer;
    TribeAIPlayer* players[9];
};

class AIPlayStatus {};
class RGE_Action {
public:
    char gap_00[0x0C];
    unsigned char state;
    int target2ID;
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
    int currentTargetType();
    float currentTargetX();
    float currentTargetY();
    int currentOrderPriority();
    int hasOrderOnQueue(int);
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
    char* name();
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
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual float calculateDamage();
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual void* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(void*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual Path* findAvoidancePath(XYZPoint*, float, int);
    int canAttack(int, float, int, int, int, int);
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x10];
    RGE_Static_Object* inside_obj;
    ObjectList* objects;
    char gap_28[0x08];
    union { float hp; float hit_points; };
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
    unsigned char have_action();
    unsigned char currentZone();
    unsigned char lookupZone(int, int);
    unsigned char lookupZone(XYPoint point);
    float pathDistance(int, void*, int, int, int);
    float pathDistance2(int, void*, int, int, int, int, int);
    int task(XYZPoint, int, int, int, int, int, int);
    int canMoveTo(int, int, int, float);
    int canPathTo(int, int, int, float, int, void*, int, int, int, int, int);
    int pathPoint(int, float*, void*);
    float distance_to_position(float, float, float);
    float distance_to_object(RGE_Static_Object*);
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
    int numberUnbuiltItemsOfType(int, int);
    int numberItemsOfType(int, int);
};

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];
    char* name();
};

class BuildItem : public BaseItem {
public:
    int buildFrom();
    int typeID();
    int uniqueID();
    float x();
    float y();
    void setInProgress(int);
    void setBuilt(int);
};
class ConstructionItem {
public:
    virtual ~ConstructionItem();
    int typeID();
    float x();
    float y();
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;
    int haveBuildList();
    int insert(int, int, int);
    BuildItem* nextBuildableItem(int);
    void unskipBuildList(int, int);
    int loadBuildList(char*, RGE_Player*);
    int numberBuiltOrInProgressItemsOfType(int, int);
    int mostNeededResource(ResourceItem*, int);
    int readyToResearch(int, int);
    int numberUnbuiltItemsOfType(int, int);
    int numberItemsOfType(int, int);
    int allBuilt(int, int);
    BuildItem* buildItem(int, int, int);
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
    int resourcesAvailable(ResourceItem*);
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
    void setChangeable(int, int);
    void setStance(int, int);
    void changeStance(int, int);
    void setStance(int, int, int);
    void changeStance(int, int, int);
};

class TribeInformationAIModule {
public:
    char gap_00000[0xF0];
    ManagedArray<int> farmsTaskedThisUpdate;
    char gap_00100[0x10090 - 0x100];
    int fullyExploredZone(int zone);
    int groupInfluenceDimension(int);
    int isBoat(int);
    ObjectMemory* artifactToCapture(int);
    ObjectMemory* ruinToCapture(int);
    int isBoat(RGE_Static_Object*);
    int findGatherPosition(XYPoint&, int, int, int, int, RGE_Static_Object*, XYPoint&);
    int numberGameIDsOwnedBy(int player, int gameID);
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
    void mapBound(XYPoint*);
    void setSaveLearnInformation(int);
    void storeAttackMemory(int, unsigned char, unsigned char, unsigned char, unsigned char,
                           unsigned char, unsigned char, int, int, int, int);
    void storeAttackMemory(int, unsigned char, unsigned char, unsigned char, unsigned char,
                           unsigned char, unsigned char, int, unsigned char);
    int closestDropsiteResID(int);
    void updateResourceDropsites(int);
    int closestDropsiteValue[4];
    int numberFoundForestTilesValue;
};

class TribeStrategyAIModule {
public:
    char gap_000[0x5F8];
    int currentVictoryCondition();
    Waypoint* targetPoint1();
    Waypoint* targetPoint2();
    int targetID();
    int secondTargetID();
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray<int> objects;
    RGE_Static_Object* object(int id);
    RGE_Static_Object* object(int, int, int, int, int, int);
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
    TribeAIPlayer* aiPlayer;
    int isEnemy(int player_id);
    int isMoveable(int id);
    void updateBuildAIWithObjects();
    void revokeTributeAlliance(int);
    void revokeTributeAlliance();
};

#include "tactical_group.h"

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
    union { int sn[226]; int strategicNumbers[226]; };
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
    union { int neededResourceValue[4]; int resourceMappingValue[4]; int arr_[4]; };
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
    void __cdecl logGroupDebug(int, char*, ...);
    static void logGroupDebug(TribeTacticalAIModule*, int, char*, ...);
    int clearArea(int, float, float, float, float);
    void addObject(RGE_Static_Object*);
    void removeFromTaskLists(int);
    int removeFromGroup(int);
    int removeFromGroup(int, int);
    int setGatherLocation(TacticalAIGroup*);
    void trackUnitGather(int, int, int);
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
    int civilian(XYPoint&, int, int, int, int, int);
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
    int numberCivilians() const;
    int numberCivilianExplorers() const;
    int numberGatherers() const;
    int desiredNumberCivilianExplorers() const;
    int desiredNumberGatherers() const;
    int numberSoldiers() const;
    int numberBoats() const;
    int neededResource(int) const;
    int neededResourceAmount(int) const;
    void detask(int);
    void setStrategicNumber(int, int);
    int strategicNumber(int);
    int calculatePriority(float);
    int groupGatherUnit(int, int, float, float, float, float, int);
    void resetAttackSeparationTime();
    int importantGroupLeader(int);
    int taskExplorer(int, int);
    int taskExplorer(int, float, float);
    int taskExplorer(int, float, float, int);
    int taskPlay(int, int*, int, int, int, Waypoint*, int);
    int taskWaterFisher(int, int, float, float);
    int taskWaterTrader(int, int);
    void displayCivilianDistribution();
    void updateGathererDistribution();
    int taskCivilians(unsigned long, unsigned long);
    void taskUngroupedSoldiers();
    void taskIdleSoldiers(unsigned long, unsigned long);
    void taskActiveSoldiers(unsigned long, unsigned long);
    int idleCivilian(int);
    int idleCivilian(int, XYPoint&, int);
    int removeGatherer(int);
    UnitData* addGatherer(int);
    int highLevelTaskGatherer(int, unsigned long);
    int highLevelTaskExplorer(int, int);
    int unit(int, int, int);
    int stopUnit(int, int);
    int numberItemsToDefend();
    int numberItemsToAttack();
    int numberUnitsInGroups(int);
    int itemToCapture();
    int itemToBringToArea();
    unsigned long attackLimiterTime(int);
    void checkForCoopAttack(int, int, int);
    TacticalAIGroup* bestGroup(int, int, int, XYPoint*, int);
    TacticalAIGroup* bestGroup(int, int, int, XYPoint&, int);
    TacticalAIGroup* group(int, int, int, int);
    int taskToEnter(int, int);
    int taskTransporter(int, float, float);
    int taskDefender(int, int, float, int);
    int taskDefender(int, int);
    int taskDefender(int, float, float);
    int taskAttacker(int, float, float, int, int, Waypoint*, int, int, int);
    int moveUnit(int, float, float, int);
    int numberGroups(int, int);
    void stuffAvoidancePath(TacticalAIGroup*, Path*);
    TacticalAIGroup* groupUnitIsIn(int);
    TacticalAIGroup* createGroup(int);
    int numberIdleSoldiers();
    int numberSoldiersWithPriority(int, int, int);
    int numberWarshipsWithPriority(int, int);
    int idleSoldier();
    int taskGatherer(int, int, int, unsigned long, int*);
    int taskFollower(int, int, float, int);
    int taskWaterExplorer(int);
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
    int removeGroup(int);
    TacticalAIGroup* readyAndIdleGroup(int, int, XYPoint&);
    TacticalAIGroup* readyAndIdleGroup(int, int, XYPoint*);
    int addToGroup(int, int);
    int setAllGroupLocations(TacticalAIGroup*);
    void setGroupInfluences(InfluenceMap&);
    int selectBestCommander(TacticalAIGroup*);
    int selectBestCommander(ManagedArray<int>&);
    int selectBestCommander(ManagedArray<int>*);
    int inAge(int);
    int resourceDifference(int);
    int actualGathererCount(int);
    int desiredGathererCount(int);
    int dealWithGAIAAttacker(RGE_Static_Object*, RGE_Static_Object*);
    void addWaypoint(int, unsigned char, unsigned char);
    int unexploredArea(int, XYPoint&);
    UnitData* gatherer(int);
    int isGatherer(int);
    int requiredGatherAmount(int);
    int deleteUnit(int);
    int numberAvailableStoragePits(int&, int&, int);
    int numberAvailableStoragePits(RGE_Static_Object**, int*, int);
    int numberAvailableGranaries(int&, int&);
    int numberAvailableGranaries(RGE_Static_Object**, int*);
    void checkForBuildInsertion(int, int, int);
    int isFarmer(RGE_Static_Object*);
    int numberFarmers();
    void checkForAttackResponseBuildInsertions(int);
    int processCoopAttack(int, int, int, int);
    int actualGathererCountByRealResourceID(int);
    void taskElephantGatherers(int, int, int);
    int numberGatherersWithTarget(int);
    int numberWaterExplorers();
};

typedef char taitacmd_verify_group_size[sizeof(TacticalAIGroup) == 0x330 ? 1 : -1];
typedef char taitacmd_verify_module_size[sizeof(TribeTacticalAIModule) == 0x100C ? 1 : -1];

#endif
