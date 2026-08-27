#ifndef TAIINFMD_H
#define TAIINFMD_H

// Canonical declarations for the authentic taiinfmd.cpp module.
// The PDB order is 004D6AD0, 004D6B70, then 004D7070.

typedef unsigned char uchar;
typedef unsigned long ulong;

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

void* operator new(unsigned int size);
void operator delete(void* ptr);

class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[64];
};

class AIModule {
public:
    virtual ~AIModule();
    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

class RGE_Static_Object;

class InformationAIModule : public AIModule {
public:
    InformationAIModule(void* param1, int param2);
    virtual ~InformationAIModule();
    int addImportantObject(RGE_Static_Object* object, int recurse);
    void logCommonHistory(char* format, ...);
    void logCommonHistory(void* self, const char* format, ...);
};

struct XYPoint;

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}
    ~ManagedArray();

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            T* newValue = (T*)operator new(newSize * sizeof(T));
            if (newValue != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < newSize; i++) {
                    newValue[i] = this->value[i];
                }
                operator delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }
        return this->value[index];
    }

    int contains(const T& item);
    void resize(int newSize);
    int add(T val);
};

template <class T>
int ManagedArray<T>::contains(const T& item)
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

template <class T>
int ManagedArray<T>::add(T val)
{
    int i;

    for (i = 0; i < this->numberValue; i++) {
        if (i >= this->maximumSizeValue)
            break;
        if (this->value[i] == val)
            return 0;
    }
    if (this->numberValue > this->maximumSizeValue - 1) {
        int newSize = this->numberValue + 1;
        T* newValue = (T*)operator_new(newSize * sizeof(T));
        if (newValue != 0) {
            int j;
            for (j = 0; j < this->maximumSizeValue; j++) {
                if (j >= newSize)
                    break;
                newValue[j] = this->value[j];
            }
            operator_delete(this->value);
            this->value = newValue;
            this->maximumSizeValue = newSize;
        }
    }
    this->value[this->numberValue] = val;
    this->numberValue++;
    return 1;
}

typedef ManagedArray<int> ManagedArray_int;

class InfluenceMap {
public:
    virtual ~InfluenceMap();
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;
    unsigned char** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    unsigned char unchangeableLimitValue;
    unsigned char _pad_end[3];
    InfluenceMap(int xSize, int ySize, unsigned char fillValue);
    void load(int file);
    void save(int file);
    int initialize(unsigned char value);
    void setUnchangeableLimit(unsigned char value);
    void setReferencePoint(int x, int y);
    int setValue(int x1, int y1, int x2, int y2, unsigned char value);
    int incrementValue(int x1, int y1, int x2, int y2, int value);
    int decrementValue(int x1, int y1, int x2, int y2, int value);
    int decrementValue(int x, int y, unsigned char value);
    int setConnectionCount(const XYPoint& min, const XYPoint& max,
                           int threshold, int p4, int p5, int p6);
    int maxValue();
    int connectionsIncluding(XYPoint* min, XYPoint* max,
                             unsigned char base, unsigned char wanted,
                             int mode1, int mode2, int allDirections);
    int lookupValue(int x, int y);
    void setValue(int x, int y, int value);
};
extern InfluenceMap* const iMap;
extern InfluenceMap* const losMap;
extern InfluenceMap* const attackMap;

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    unsigned char _pad_0[2];
    int attackAttempts;
    unsigned char kills;
    unsigned char _pad_1[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

struct BuildingLot {
    int typeID;
    unsigned char status;
    unsigned char x;
    unsigned char y;
    unsigned char _pad_end[1];
};

struct AttackMemory {
    int id;
    unsigned char type;
    unsigned char minX;
    unsigned char minY;
    unsigned char maxX;
    unsigned char maxY;
    unsigned char attackingOwner;
    unsigned char targetOwner;
    unsigned char _pad_0[1];
    short kills;
    unsigned char success;
    unsigned char _pad_1[1];
    unsigned long timeStamp;
    int play;
};

struct XYPoint {
    int x;
    int y;
};

struct QuadrantLog {
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};

struct ResourceMemory {
    int id;
    unsigned char x;
    unsigned char y;
    unsigned char gatherAttempts;
    unsigned char _pad_0[1];
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

struct ResourceTypeBlock {
    ResourceMemory* resArray;
    char _pad0[0x0C];
    int count;
    char _pad1[0x5C];
    int closestValue;
    int _pad2[3];
    int closestResID;
};

class TribeMainDecisionAIModule;
class BuildItem;
class ConstructionItem;
struct PlacementState {
    int buildingTypeID;
    float buildingSize;
    char buildingName[0x100];
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
    unsigned char _pad_0[3];
    int bestNonWallTargetID;
    float bestNonWallTargetValue;
    int bestNonWallTargetMemoryIndex;
    int active;
};
struct GameInfo;
class PathingSystem {
public:
    unsigned char lookupMisc(int row, int column);
    void setMisc(int row, int column, unsigned char value);
};
extern PathingSystem aiPathSystem;
class RGE_Player;
class UnitAIModule;
class RGE_Action {
public:
    short actionType();
    unsigned char state;
    float timer;
};

class RGE_Action_List {
public:
    unsigned char have_action();
    RGE_Action* get_action();
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    char* nameValue;
    short string_id;
    short string_id2;
    union {
        short id;
        short master_id;
    };
    short copy_id;
    union {
        short object_group;
        short objectGroup;
        short type;
        short unitType;
    };
    void* sprite;
    void* death_sprite;
    void* undead_sprite;
    unsigned char undead_flag;
    short hp;
    float los;
    unsigned char obj_max;
    float radius_x;
    float radius_y;
    float radius_z;
    void* selected_sound;
    void* created_sound;
    void* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char hide_in_scenario_editor;
    short portrait_pict;
    unsigned char available;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    unsigned char elevation_flag;
    unsigned char fogFlag;
    short terrain;
    int check_placement(int x, int y, int mode);
    unsigned char check_placement(RGE_Player* player, float x, float y,
                                  int* result, unsigned char p5,
                                  unsigned char p6, unsigned char p7,
                                  unsigned char p8, unsigned char p9,
                                  unsigned char p10);
};

typedef RGE_Master_Static_Object RGE_Master_Object;
typedef RGE_Master_Static_Object MasterObject;
struct TaiSubObject {
    char gap[0x14];
    short field_14;
    void save(int file);
};

class RGE_Zone_Map {
public:
    unsigned char get_zone_info(long x, long y);
    int numberTilesInZone(unsigned char zone);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map* get_zone_map(float* terrain, long terrainSize,
                               int& zoneIndex);
};

class RGE_Game_World;
class RGE_Map;

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;
    union {
        int widthValue;
        int width;
    };
    union {
        int heightValue;
        int height;
    };
    unsigned char get_visible(int x, int y);
};

struct RGE_Tile_List_Node {
    int x;
    int y;
};

class RGE_Tile_List {
private:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;

public:
    void get_list_info(RGE_Tile_List_Node** list, int* count);
    int get_new_count();
};

struct TileObjNode {
    union {
        RGE_Static_Object* object;
        RGE_Static_Object* obj;
    };
    TileObjNode* next;
};
typedef TileObjNode RGE_Object_List_Node;

struct RGE_Tile_Object_List {
    virtual ~RGE_Tile_Object_List();
    TileObjNode* list;
};

struct RGE_Tile {
    char gap_00[5];
    union {
        unsigned char terrainType;
        unsigned char terrain_type;
        unsigned char terrain;
    };
    char gap_06[6];
    RGE_Tile_Object_List objects;
    char gap_14[4];
};

class RGE_Map {
public:
    char gap_00[8];
    int mapWidth;
    int mapHeight;
    char gap_10[0x8d7c];
    union {
        RGE_Tile** mapRowOffset;
        RGE_Tile** map_row_offset;
    };
    char map_zones_gap[0x34];
    RGE_Zone_Map_List* map_zones;
    unsigned char get_terrain(short x, short y);
};

struct TaiTerrain {
    char gap0[8];
    int width;
    int height;
    char gap10[0x8d8c - 0x10];
    unsigned char** rows;
};

struct TaiWorld {
    char gap[0x28];
    TaiTerrain* terrain;
};

struct TaiPlayer {
    char gap[0x3c];
    union {
        TaiWorld* world;
        TaiWorld* worlda;
    };
};

struct TaiMD {
    char gap[0x1256c];
    TaiPlayer* aiPlayer;
};

typedef TaiTerrain Terrain;
typedef TaiWorld WorldA;
typedef TaiPlayer AiPlayer;
typedef TaiMD MD;

struct XYZPoint {
    int x;
    int y;
    int z;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    union {
        int id;
        int obj_id;
    };
    union {
        RGE_Master_Static_Object* master_obj;
        RGE_Master_Static_Object* master;
        TaiSubObject* field_08;
    };
    union {
        RGE_Player* owner;
        RGE_Player* player;
    };
    int state;
    int amount;
    char gap_10[0x28];
    union {
        float x;
        float world_x;
        float x_pos;
    };
    union {
        float y;
        float world_y;
        float y_pos;
    };
    float field_30;
    float field_38;
    float field_3C;
    float field_40;
    float world_z;
    float z;
    short attribute_type_held;
    short _pad_attribute_type;
    float attribute_amount_held;
    float forageAmount;
    float range();
    RGE_Action_List* action_list;
    float get100();
    float get108();
    float get10C();
    int passableTile(float x, float y, int mode);
    unsigned char lookupZone(int x, int y);
    int canPath(struct XYZPoint point, float los, int mode, float* path,
                int flag, int arg6, int arg7);
    int canPath(float x, float y, int mode);
    int canPath(int objectID, float range);
    int canPathWithObstructions(int objectID, float range, float* path,
                                int flag, int owner, int mode,
                                ManagedArray<int>* excluded);
    int canLinePath(int x1, int y1, int x2, int y2, float distance,
                    int mode);
    int canLinePath(XYPoint* current, XYPoint* from, float distance,
                    XYPoint* line, int mode);
    float get104(RGE_Static_Object* object);
    float damageCapability();
    float damageCapability(RGE_Static_Object* object);
    float rateOfFire();
    int findClosestPointInTerrainType(int terrain, int x, int y, int radius,
                                      int* outX, int* outY);
    int findClosestPointInTerrainType(XYPoint start, XYPoint* out,
                                      int terrainType, int terrain, int radius);
    int canLinePath(XYPoint current, XYPoint target, float distance,
                    XYPoint out, int mode);
    UnitAIModule* unitAI();
    float weaponRange();
    float maximumSpeed();
    float speed();
    int withinRangeOfZoneAtPoint(unsigned char zone, float distance,
                                 XYPoint* point);
    float distance_to_position(float x, float y, float z);
    int distance_to_object(RGE_Static_Object* object);
    unsigned char object_state;
    float hp;
    unsigned char currentZone();
};

typedef RGE_Static_Object RGE_Obj;

class RGE_Game_World;
class AIPlayBook;
class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char _pad_21;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    union {
        RGE_Visible_Map* visible;
        RGE_Visible_Map* visMap;
    };
    RGE_Game_World* world;
    void* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char _pad_49;
    short id;
    short attribute_num;
    short _pad_4E;
    float* attributes;
    unsigned char culture;
    char _pad_55[3];
    RGE_Tile_List tileList;
    int relation(int otherPlayer);
    int computerPlayer();
    int isAlly(int otherPlayer);
    int isEnemy(int otherPlayer);
    int isActive(int playerNumber);
    int query18(int playerNumber);
    int playerVisible(int playerNumber);
    int objectCostByType(int type);
    TribeMainDecisionAIModule* playerAI;
    int player_num;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned int world_time;
    unsigned int old_world_time;
    unsigned int world_time_delta;
    float timer;
    unsigned int old_time;
    float game_speed;
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    unsigned char _pad_1F;
    int sound_update_index;
    int map_gap;
    RGE_Map* map;
    short sound_num;
    void* sounds;
    short sprite_num;
    void* sprites;
    short player_num;
    RGE_Player** players;
    short master_player_num;
    void* master_players;
    void* effects;
    short terrain_num;
    short terrain_size;
    float** terrains;
    AIPlayBook* playbook;
    unsigned char controllingComputerPlayer;
    int playerNumber;
    unsigned int availableComputerPlayerUpdateTime;
    RGE_Static_Object* object(int index);
    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5,
                              int p6, int p7, int p8, int p9, int p10);
};

struct AIPlayGrouping {
    int id;
    unsigned char groupValue;
    unsigned char typeValue;
    unsigned char gap_06[2];
};

struct AIPlayPoint {
    int xValue;
    int yValue;
    int zValue;
};

class AIPlayStatus {
public:
    AIPlayGrouping groupings[50];
    int playNumberValue;
    int targetValue;
    AIPlayPoint originalPointValue;
    int originalHitPointsValue[5];
    unsigned char currentPhaseValue;
    unsigned char gap_1B9[3];
    int savedAttackerValue;
    int lastPhaseChangeTimeValue;
    unsigned char deviationValue;

    AIPlayStatus();
    void copyUnits(int* units, int& count);
};

class AIPlayPhaseCommand {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    unsigned char gap_02[2];
    int value1Value;
    int value2Value;
};

class AIPlayPhase {
public:
    AIPlayPhaseCommand* command(int index);
};

class AIPlay {
public:
    unsigned char gap_00[0x43];
    unsigned char typeValue;
    unsigned char gap_44[0x0D];
    unsigned char deathPercentageValue;

    int humanPlay() const;
    AIPlayPhase* phase(int phaseNumber);
    int fillGroups(AIPlayStatus* status, int* unitIds, int unitCount,
                   RGE_Game_World* world);
};

class AIPlayBook {
public:
    void* plays;
    int numberPlaysValue;

    AIPlay* play(int playNumber);
};

class UnitAIModule {
public:
    int mostDangerousEnemy(int id);
    int mostDangerousEnemy(float* value);
    int seekAndDestroy(int target, int a = 0, int b = 0, int c = 0);
    int currentTarget();
    int can_attack_mem(int objectID);
};

struct VisibleMapHolder {
    RGE_Visible_Map* map;
};

class BuildAIModule {
public:
    int numberBuiltItemsOfType(int type, int owner);
    int numberBuiltOrInProgressItemsOfType(int type, int owner);
};

struct AttackMapStruct {
    char gap_00[0x4A];
    unsigned short compareOwner;
};

class MainDecisionAIModule;

class BaseItem {
public:
    virtual ~BaseItem();
    int typeID() const;
    float xSize() const;
    float ySize() const;
    float zSize() const;
    char* name();
    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char nameValue[64];
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;
};

class BuildItem : public BaseItem {
public:
    virtual ~BuildItem();
    BuildItem* next;
    BuildItem* prev;
    int buildCategoryValue;
    int numberValue;
    int priorityValue;
    int progressValue;
    int builtValue;
    int buildAttemptsValue;
    int buildFromValue;
    int terrainSetValue;
    int terrainAdjacencyValue[2];
    int placeOnElevationValue;
    int numberBuildsValue;
    int buildCapValue;
    int skipCyclesValue;
    unsigned char permanentSkipValue;
};

class ConstructionItem : public BaseItem {
public:
    virtual ~ConstructionItem();
    ConstructionItem(float p1, float p2, float p3, float p4,
                     float p5, float p6, int p7, char* p8);
    ConstructionItem(ConstructionItem* item);
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;
};

class TacticalAIGroup {
public:
    int numberUnits();
    int commander();
    int numberObjectsToDestroyValue;
    int objectsToDestroyOwnerValue;
    int objectsToDestroyCommanderZoneValue;
    int objectToDestroy(int index);
    int addObjectToDestroy(int index);
    int unit(int index);
};

class ConstructionAIModule {
public:
    ConstructionItem* randomLot(float x, float y);
};

class TribeTacticalAIModule {
public:
    TacticalAIGroup* bestGroup(int action, int mode, int maxDistance,
                               XYPoint* point, int zone);
    int strategicNumber(int id);
    int numberGatherersWithTarget(int id);
    int actualGathererCountByRealResourceID(int id);
    int inAge(int age);
    void setGroupInfluences(InfluenceMap* map);
    MainDecisionAIModule* mainDecisionAI;
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    RGE_Player* player;
    AttackMapStruct* attackInfo;
    RGE_Player* costTableOwner;
    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
    char gap_F4[0x5D0];
    ConstructionAIModule constructionAIAt6C4;
    char gap_6C5[0x10DA7];
    TribeTacticalAIModule tacticalAI;
    BuildAIModule buildAI;
    char gap_1146D[0x10FB];
    RGE_Player* aiPlayer;
    ConstructionAIModule constructionAI;
    InformationAIModule informationAI;
    RGE_Player* costTableOwner;
    RGE_Static_Object* object(int id);
    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5,
                              int p6, int p7, int p8, int p9, int p10);
};

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray<int> farmsTaskedThisUpdate;
    union {
        TribeMainDecisionAIModule* md;
        int field_100;
    };
    union {
        int mapXSizeValue;
        int mapX;
        int map_w;
        int f104;
    };
    union {
        int mapYSizeValue;
        int mapY;
        int map_h;
        int f108;
    };
    union {
        int lastUpdateRowValue;
        int f10C;
    };
    union {
        int maxImportantObjectMemory;
        int n110;
        int max;
    };
    union {
        ObjectMemory* importantObjectMemory;
        char* p114;
        ObjectMemory* mems;
    };
    ManagedArray<int> importantObjects;
    ManagedArray<int> importantUnits;
    ManagedArray<int> importantMiscs;
    ManagedArray<int> itemsToDefend;
    InfluenceMap pathMap;
    ManagedArray<int> playerObjects;
    ManagedArray<int> playerBuildings;
    union {
        XYPoint lastWallPosition;
        double f1A0;
    };
    union {
        XYPoint lastWallPosition2;
        double f1A8;
    };
    union {
        int numberGatesValue;
        int f1B0;
    };
    union {
        XYPoint minGatePosition[4];
        struct { int lo, hi; } d1B4[4];
    };
    union {
        XYPoint maxGatePosition[4];
        struct { int lo, hi; } d1D4[4];
    };
    union {
        int maxBuildingLots;
        int n1F4;
    };
    union {
        BuildingLot* buildingLots;
        char* p1F8;
    };
    union {
        int maxAttackMemories;
        int n1FC;
    };
    union {
        AttackMemory* attackMemories;
        char* p200;
    };
    union {
        int saveLearnInformationValue;
        int field_204;
        int f204;
    };
    char learnFileName[256];
    unsigned char fullyExploredZoneValue[255];
    union {
        QuadrantLog quadrantLog[4][4];
        char buf408[0xc0];
    };
    int** resourceTypesValue;
    int* numberResourceTypesValue;
    union {
        ResourceMemory* resources[4];
        ResourceMemory* resourcePtrs[4];
        void* ptr4D0[4];
    };
    union {
        int numResources[4];
        int e4E0[4];
    };
    union {
        int maxResources[4];
        int c4F0[4];
    };
    union {
        int dropsitesByAge[4][4];
        char s500[0x40];
    };
    union {
        int closestDropsiteValue[4];
        int bestdv[4];
        char s540[0x10];
    };
    union {
        int closestDropsiteResourceID[4];
        int bestid[4];
        int dropsiteIds[4];
        char s550[0x10];
    };
    union {
        int numberFoundForestTilesValue;
        int f560;
    };
    union {
        int playHistory[16000];
        char big564[0xfa00];
    };
    int unitHistory[11];
    char unitHistoryFilename[256];
    int includeObject(RGE_Static_Object* object);
    void addDocks();
    void addHouse(RGE_Static_Object* object);

    TribeInformationAIModule(int param1, int param2);
    virtual ~TribeInformationAIModule();
    TribeInformationAIModule(void* param1, int param2);
    int initialize();
    virtual int update(int param1);
    int save(int handle);
    void setMainDecisionAI(TribeMainDecisionAIModule* value);
    int closestUnexploredTile(int objectId, float x, float y,
                              float* outX, float* outY);
    ObjectMemory* addObjectMemory(RGE_Static_Object* object);
    ObjectMemory* addObjectMemory(int id, short type, short group,
                                  unsigned char x, unsigned char y,
                                  unsigned char z, unsigned char owner,
                                  short hp, int attempts, unsigned char kills,
                                  float damage, float rate, float range,
                                  RGE_Static_Object* object);
    int addImportantObject(RGE_Static_Object* object, int recurse);
    int addImportantObject(int objectID);
    int mapBound(XYPoint* point);
    int mapBound(XYPoint& point);
    void blotExploredMap(int p1, int p2, int p3, int p4);
    int fullyExploredZone(int gameID);
    void setFullyExploredZone(int gameID, int explored);
    int tileUncovered(int x, int y);
    void setTileExplored(int x, int y);
    int ownerOfGameID(int gameID);
    int gameIDOfResourceObject(int resType, int gathererId, float& outX,
                               float& outY, int& outResourceId, int* exclude,
                               int excludeCount);
    int gameIDsOfObjectType(int objectType, int** ids, int** owners,
                            int playerFilter);
    int gameIDsOwnedBy(int owner_filter, int** out, int owner_id);
    int numberGameIDsOwnedBy(int param1, int param2);
    ConstructionItem* placeDock(BuildItem* item, float x, float targetY,
                                int terrain_type, int tile_type);
    int numberDocksInZone(int param1, RGE_Zone_Map* map);
    int closestDockDistance(int x, int y);
    int hasAdjacentTileType(int x, int y, int type);
    int mapXSize();
    int mapYSize();
    void addEnemyInfluences(int player, int excludeId);
    void addPriorAttackInfluences(int targetOwner, int unused);
    int isBuilding(RGE_Static_Object* object);
    int isUnitBuilding(RGE_Static_Object* object);
    int isBoat(RGE_Static_Object* object);
    int isWall(RGE_Static_Object* object);
    int isTower(RGE_Static_Object* object);
    int influenceCanPlaceStructure(BuildItem* value);
    ConstructionItem* influencePlaceStructure(
        BuildItem* item, int builderID, int objectType, float objectSize,
        char* objectName, int minimumDistance, int centerX, int centerY,
        int maxClearX, PlacementState& state, unsigned long currentTime);
    void addObject(RGE_Static_Object* object);
    void removeObject(int objectID);
    ObjectMemory* objectToAttackWithPlay(int group, int* unitIds, int count,
                                         int& playNumber, int* outputUnits,
                                         int& outputCount, int& outputUnit);
    ObjectMemory* objectToAttack(int player, int siegeWeapons, int boats,
                                 int objectNumber, int& output);
    ObjectMemory* objectToAttack(int player, int siegeWeapons, int boats,
                                 int objectNumber, int* output);
    ObjectMemory* objectToAttackByGroup(int owner, TacticalAIGroup* group,
                                        AttackState& state,
                                        unsigned long currentTime);
    ObjectMemory* objectToAttackByGroup(int owner, TacticalAIGroup* group,
                                        AttackState* state,
                                        unsigned long currentTime);
    ObjectMemory* objectToAttackByGroup2(int group, int* ids, int count);
    int isBoatAccessible(RGE_Static_Object* object, int id);
    int isLandAccessible(RGE_Static_Object* object, int id);
    int numberItemsToDefend();
    ObjectMemory* higherPriorityObjectToDefend(int objectID, int type,
                                                int group);
    int checkDefend(RGE_Static_Object* object);
    ObjectMemory* objectToTradeWith(int objectID);
    int findGatherPosition(XYPoint& point, int group, int clearDistance,
                           int minDistance, int maxDistance,
                           RGE_Static_Object* object, XYPoint& out);
    void setupInfluenceMap(int mode, int objectType, XYPoint& unused,
                           XYPoint& from, XYPoint& to);
    void setupInfluenceMap(int mode, int objectType, XYPoint* unused,
                           XYPoint* from, XYPoint* to);
    int groupInfluenceDimension(int dimension);
    ObjectMemory findObjectMemoryLimits(int owner, int objectID, int& c1,
                                        int& c2);
    ObjectMemory findObjectMemoryLimits(int owner, int objectID, int* c1,
                                        int* c2);
    int isNextTo(XYPoint* p1, XYPoint* p2, int mode);
    int isNextTo(XYPoint& p1, XYPoint& p2, int mode);
    int facetTo(XYPoint& from, XYPoint& to);
    int placementCode(int value);
    BuildingLot* availableLot(int typeID);
    int invalidLot(int typeID, unsigned char x, unsigned char y);
    int undesirableLot(int typeID, unsigned char xRange,
                       unsigned char yRange, int coordOffset);
    void storeLot(int typeID, unsigned char x, unsigned char y,
                  unsigned char built);
    void removeLot(int typeID, unsigned char x, unsigned char y,
                   unsigned char status);
    void setupWalls(int param1, int param2, int param3, int param4,
                    int param5, int param6, int param7, int param8);
    int insideGate(int param1, int param2, int param3);
    int storeAttackMemory(unsigned char p1, unsigned char p2,
                          unsigned char p3, unsigned char p4,
                          unsigned char p5, short p6, unsigned char p7,
                          unsigned long p8, int p9);
    int storeAttackMemory(unsigned char p1, unsigned char p2,
                          unsigned char p3, unsigned char p4,
                          unsigned char p5, unsigned char p6,
                          unsigned char p7, short p8, unsigned char p9,
                          unsigned long p10, int p11);
    int storeAttackMemory(unsigned char p1, unsigned char p2,
                          unsigned char p3, unsigned char p4,
                          unsigned char p5, unsigned char p6,
                          unsigned char p7, short p8, unsigned char p9,
                          unsigned int p10, int p11);
    void removeAttackMemory(int index);
    AttackMemory* attackMemory(int index);
    void setSaveLearnInformation(int value);
    void loadLearnInfo(char* suffix);
    int unexploredPlayerLocation(int objectID, XYPoint& out);
    int numberUnitsWithinXTiles(int playerFilter, int xCenter, int yCenter,
                                int radius);
    int withinXTilesOfAttackOnPlayer(RGE_Static_Object* target, int tiles,
                                     int playerID);
    int withinXTilesOfEnemyTowncenter(RGE_Obj* object, int tiles);
    int withinXTilesOfObject(RGE_Static_Object* object, int tileRange,
                             int type1, int type2, int type3, int type4);
    int findStagingPoint(XYPoint startPoint, XYPoint& result, int useTransport,
                         int landTerrainRequired, int targetID,
                         int stageDistance, int unitID);
    int setupLOSMap(int owner, int refX, int refY);
    int setupAttackMap(int param1, int param2, int param3);
    int resourceType(int resourceTypeIndex, int resourceId);
    int setResourceObjectValid(int resourceType, int resourceId, int valid);
    int addResourceObject(RGE_Static_Object* object);
    float findClosestDropsite(RGE_Static_Object* object, int mode,
                              int& dropsiteID);
    float findClosestDropsite(RGE_Static_Object* object, int mode,
                              int* dropsiteID);
    RGE_Static_Object* findClosestReturnDropsite(RGE_Static_Object* unit);
    void updateAllResourceDropsites();
    void updateResourceDropsites(int resourceType);
    int amountForageBushesInXTiles(int x, int y, int maxDistance);
    int amountResourceTypesInXTiles(int typeIndex, int x, int y, int distance);
    float damagePerSecond(int unitID, int x, int y);
    int benefitToKillUnit(int unitID);
    int costToLoseUnit(int unitID);
    int inRangeOfUnits(int playerFilter, int x, int y, int mapRange);
    ObjectMemory* wonderToAttack(int playerID);
    ObjectMemory* ruinToCapture(int playerFilter);
    ObjectMemory* artifactToCapture(int playerID);
    int resourceTypeToPlaceDropsiteBy(int resourceType);
    int dropsitesWithinRequiredDistance(int& numApplicableResources,
                                        int resourceType, int requiredDistance);
    int numberAvailableStoragePits(int resourceType);
    int numberAvailableGranaries();
    void lookAtMap();
    float damageInflictedPerSecond(TacticalAIGroup* group,
                                   RGE_Static_Object* target);
    float damageInflictedPerSecond(int* ids, int count,
                                   RGE_Static_Object* target);
    float timeToBeKilled(TacticalAIGroup* group, RGE_Static_Object* target);
    float timeToBeKilled(int* ids, int count, RGE_Static_Object* target);
    int numberStoragePits();
    int numberGranaries();
    int closestDropsiteResID(int index) const;
    int calculatePlayVariation(int value);
    int convertUnitToIntType(RGE_Static_Object* object) const;
    void loadUnitHistory();
    void unitsThatAreMostBuilt(int& first, int& second);
    void unitsThatAreLeastBuilt(int& first, int& second);
    int percentTilesExploredInPositionQuadrant(int x, int y);
    int acceptablePotentialDropsiteArea(int param1, int param2);
    ObjectMemory* objectToDefend(int objectID);
    int defendPriority(int type, int group);
    ObjectMemory* objectMemory(int id);
    int importantObject(int type);
    int importantUnit(int type);
    int importantResource(int type);
    int importantMisc(int type);
    void addResourceType(int resourceIndex, int typeValue);
};

struct RGE_Game_Info {
    char* get_current_player_name();
};

struct RGE_Base_Game {
    char _pad[4];
    union {
        RGE_Game_Info* player_game_info;
        RGE_Game_Info* info;
    };
    int singlePlayerGame();
};

extern "C" void __cdecl rge_read(int file, void* buffer, int size);
extern "C" int __cdecl rge_open(char* path, int mode, int attr = 0);
extern "C" void __cdecl rge_write(int file, void* buffer, int size);
extern "C" int debug_rand(char* file, int line);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" long __cdecl _ftol();
extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);
extern float save_game_version;
extern float DAT_00575564;
extern float DAT_00575550;
extern float DAT_00575554;
extern float DAT_00575558;
extern float DAT_0057555c;
extern float DAT_00575560;
extern float DAT_00575574;
extern float DAT_00575578;
extern float DAT_0057557c;
extern float DAT_00575580;
extern float DAT_00575584;
extern float DAT_005755B0;
extern float DAT_005755B4;
extern float DAT_005755B8;
extern float DAT_005755BC;
extern float _flt_5755B8;
extern float _flt_5755BC;
extern RGE_Base_Game* rge_base_game;

#endif
