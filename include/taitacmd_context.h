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

struct AttackWaypoint {
    char data[16];
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
class InfluenceMap {
public:
    int setValue(int, int, int, int, unsigned char);
    int decrementValue(int, int, int, int, unsigned char);
};

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

class ResourceItem {
public:
    virtual ~ResourceItem();
    char bytes[0x6C];
    ResourceItem(int count);
    int value(int index);
    int value(int index) const;
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
    RGE_Player* players[9];
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Static_Object* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, void*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();
    void builderTask(int, int, float, float, int);
    int computerPlayer();

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

};

struct TimeList {
    unsigned long next;
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
    int currentOrderPriority();
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
    int haveBuildList();
    int insert(int, int, int);
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
    void revokeTributeAlliance(int);
    void revokeTributeAlliance();
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    union { int idValue; int id_; int field_0C; };
    union { int inUseValue; int inUse_; int field_10; };
    union { int typeValue; int type_; int field_14; };
    union { int subTypeValue; int subType_; int field_18; };
    union { int unitsValue[40]; int members[40]; };
    union { int unitsOriginalHitPointsValue[40]; int companion[40]; };
    union { int numberUnitsValue; int numberUnits_; int field_15C; };
    union { int desiredNumberUnitsValue; int desiredNumberUnits_; int field_160; };
    union { int commanderValue; int commander_; int field_164; };
    union { int originalHitPointsValue; int originalHitPoints_; int field_168; };
    union { int originalUnitNumberValue; int originalUnitNumber_; int field_16C; };
    union {
        Waypoint locationValue;
        Waypoint location_;
        char data_170[0x10];
        struct { int field_170; int field_174; int field_178; };
    };
    union { int actionValue; int action_; int field_180; };
    union { int targetValue; int target_; int field_184; };
    union { int targetTypeValue; int targetType_; int field_188; };
    union {
        Waypoint targetLocationValue;
        Waypoint targetLocation_;
        char data_18C[0x10];
        struct { int field_18C; int field_190; int field_194; };
    };
    union {
        Waypoint gatherLocationValue;
        Waypoint gatherLocation_;
        char data_19C[0x10];
        struct { int field_19C; int field_1A0; int field_1A4; };
        struct { float gatherX; float gatherY; float gatherZ; };
    };
    union {
        Waypoint retreatLocationValue;
        Waypoint retreatLocation_;
        char data_1AC[0x10];
        struct { int field_1AC; int field_1B0; int field_1B4; };
    };
    union { int priorityValue; int priority_; int field_1BC; };
    union { int waitCodeValue; int waitCode_; int field_1C0; };
    union { int assistGroupIDValue; int assistGroupID_; int field_1C4; };
    union { int assistGroupTypeValue; int assistGroupType_; int field_1C8; };
    union { unsigned long consecutiveIdleUnitCountValue; unsigned long consecutiveIdleUnitCount_; int field_1CC; };
    union { int playNumberValue; int field_1D0; };
    union { unsigned char numberAttackWaypointsValue; unsigned char numberAttackWaypoints_; unsigned char byte_1D4; };
    union { unsigned char currentAttackWaypointValue; unsigned char currentAttackWaypoint_; unsigned char byte_1D5; };
    unsigned char pad_1D6[2];
    union { Waypoint attackWaypoints[15]; AttackWaypoint waypoints[15]; char data_1D8[0xF0]; };
    union { unsigned char consecutiveGatherAttemptsValue; unsigned char byte_2C8; };
    unsigned char pad_2C9[3];
    union { int numberObjectsToDestroyValue; int numberObjectsToDestroy; int field_2CC; };
    union { int objectsToDestroyValue[20]; int objectsToDestroy[20]; int arr_[20]; char data_2D0[0x50]; };
    union { int objectsToDestroyOwnerValue; int field_320; };
    union { int objectsToDestroyCommanderZoneValue; int field_324; };
    union { unsigned long lastAttackRoundupTime; int field_328; };
    union { unsigned long lastAddedUnitTimeValue; int field_32C; };

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
    int isTightGathered(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    int allUnitsIdle(TribeMainDecisionAIModule*, int);
    unsigned long consecutiveIdleUnitCount() const;
    void setConsecutiveIdleUnitCount(unsigned long);
    void incrementConsecutiveIdleUnitCount(int);
    unsigned char numberAttackWaypoints() const;
    unsigned char currentAttackWaypoint() const;
    void addAttackWaypoint(float, float);
    AttackWaypoint* attackWaypoint(unsigned char);
    int firstIdleUnit(TribeMainDecisionAIModule*);
    int objectToDestroy(int);
    int addObjectToDestroy(int);
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
    int neededResource(int);
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
    int numberAvailableGranaries(int&, int&);
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
