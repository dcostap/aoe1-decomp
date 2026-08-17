// TribeInformationAIModule::placeDock (004D9B20)
// PDB source: taiinfmd.cpp:1678-1811
// Size: 922 bytes
//
// Attempt log:
// - Baseline reconstruction restores the typed AI/player/world/map ownership,
//   the zone-map and visible-map call surfaces, and the natural dock-placement
//   scan from the executable.  First checker result is recorded in the target
//   session history.
// - Reordered the zone-count/strategic-threshold statements, restored the
//   binary x-1/y-1 neighbor bounds, and made the zone penalty an int before
//   conversion; this aligned all 17 ordered call sites.
// - Restored the period BaseItem-derived ConstructionItem surface and the
//   same-TU InformationAIModule boundary; the emitted code was unchanged.
// - Scoped the initial md/player aliases in binary load order; this only
//   changed the early register/home basin and was not retained as a separate
//   source model.
// - Corrected RGE_Map::map_zones to its proven +0x8DC4 field after the row
//   table; the typed map ownership is retained.
// - Initialized the binary-observed best score to -1.0f.  This restored the
//   922-byte code size and substantially improved block alignment.
// - Reversed the commutative distance-square terms to recover the oracle's
//   x87 multiply order; promoting the inner y home to function scope emitted
//   the same code and was retained only as ordinary source shape.
// - Reconstructed the minimization predicate as `score < bestScore + random`
//   from the fcompp/test-ah topology; this reduced the remaining positional
//   drift to 126 bytes with exact call/relocation identity.
// - Left in scratch after the bounded pass: current size/call set/relocations
//   match, but the prologue frame/register basin and a localized stack/FPU
//   scheduling suffix remain non-exact.  Best source is natural typed C++;
//   no compiler-only padding, volatile scaffolding, or inline asm retained in
//   the function body.  The nested class surfaces are now PDB-owned.
// - Added the binary-proven separate zone-map output home before zoneCounter
//   and passed it by reference; the distinct LEA homes restored the 0x134 frame
//   and reduced the positional diff from 126 to 116 bytes.
// - Declaration-time md/player aliases were a codegen duplicate.  Making map
//   and visible declaration-time locals improved the diff by one byte.
// - Declaring map before visible preserved the 0x134 frame and reduced the
//   diff to 107 bytes.  Direct zoneCounter indexing was codegen-equivalent.
// - Audit: cvdump type 0x1125 declares zoneCounter as unsigned char[256].
//   Replaced the type-pun fill with memset; VC5 still emits the exact rep stosd.
// - Audit: removed the unused operator new declaration and BuildItem tail gap.
//   Replaced accessed map, world, player, tile, and master-object gaps with
//   PDB-named fields.  Exact checks stayed at 922 bytes and 0.0000% diff.
// - Audit: the first canonical MainDecision hierarchy test moved aiPlayer from
//   +0x1256C to +0x12560 because objects was a void* instead of ManagedArray.
//   The PDB defines MainDecisionAIModule as 0x104 bytes, with player at +0xF0
//   and ManagedArray<int> objects at +0xF4.  The typed field restores +0x1256C.
// - Audit: the PDB defines TribeMainDecisionAIModule as 0x125C8 bytes.  Its
//   module fields run from buildAI +0x104 through tradeAI +0x12478; aiPlayer
//   is a typed TRIBE_Player* at +0x1256C.  The source now owns these fields
//   through canonical module types, with no flattened MainDecision gaps.
// - Audit: replaced the renamed information, strategy, and tactical storage
//   extents with PDB members and nested types.  This includes Waypoint,
//   VictoryConditionRuleSystem, InfluenceMap, ResourceItem, TacticalAIGroup,
//   PlacementState, AttackState, and the complete TribeInformation fields.
// - Audit: cvdump defines UnitData::target at +0x10 and lastTaskTime at +0x14.
//   Adding target restored the 24-byte gatherer stride and the 0x100C tactical
//   subobject size.  The complete typed hierarchy remains an exact match.
// - Restoring the overlapping zoneCounter[0] output home reduced the frame to
//   0x130 and worsened the diff; the separate output home remains.
// - A dock-count value home increased the frame and broke the block shape;
//   it was rolled back.  The remaining lead is early register/liveness order.
// - Focused probes 2-22 tested the cache index, count predicate, declaration
//   order, type width, class surface, headers, and local initialization.
//   The best clean source is 104 differing bytes at the original size and
//   frame.  Calls and boundaries remain exact; the prologue is not exact.
// - Exact same-TU closestDockDistance proves <math.h> context. Direct repeated
//   coordinate expressions make the late x87 range exact. Early register
//   allocation remains the only non-exact region in the current 32-byte result.
// - PDB/type inventories identify md->aiPlayer as TRIBE_Player and the player
//   terrain source as player->master_objects[0x13]->terrain (+0x66 on the
//   master object). Replacing the invented master_player aggregate with this
//   owning array, and using the already loaded AI-world map for map_zones,
//   reduces the clean positional drift from 68 to 32 bytes.
// - Canonical period AI, map, zone-map, and player subtype surfaces were
//   restored without changing the 32-byte result. A natural md alias changed
//   the frame to 0x138 and drifted to 811 bytes, so it is not retained.
// - PDB local order (vMap, gMap, bYTile, zoneMap, x, bXTile, zoneCounter,
//   randSelect, bD, tempInt, y, currentZone, cD) led to the exact early
//   register/home basin. Direct typed player terrain ownership is retained;
//   player and md aliases are not needed.
// - Exact under the pinned default VC5 flags: 922 bytes, 0x134 frame, all
//   17 ordered calls, and 0 positional differences. Reversions show that
//   visible/map homes are required, while scope and cache-index names are not.

#include <math.h>
#include <string.h>

extern "C" int __cdecl debug_rand(char* file, int line);
extern float DAT_00575570;

class BaseItem {
public:
    virtual ~BaseItem();
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

    char* name();
    int typeID() const;
    float xSize() const;
    float ySize() const;
    float zSize() const;
};

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    ConstructionItem(float, float, float, float, float, float, int,
                     char*);
};

class BuildItem : public BaseItem {
public:
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

class RGE_Zone_Map;
class RGE_Zone_Map_List;
class RGE_Game_World;
class RGE_Map;
class RGE_Visible_Map;
class RGE_Player;
class RGE_Static_Object;

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Static_Object** list;
    short number_of_objects;
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    int zone_map_num;
    RGE_Map* map;

    RGE_Zone_Map* get_zone_map(float* terrain_info, long terrain_info_num,
                               int& zone_map_index);
};

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    unsigned char* zone_map; // +0x404
    unsigned char** zone_map_rows; // +0x408
    unsigned char zone_info[257]; // +0x40C
    float* terrain_passability_rules; // +0x510
    int terrain_passability_rules_num; // +0x514
    RGE_Map* map; // +0x518

    unsigned char get_zone_info(long x, long y);
    int numberTilesInZone(unsigned char zone);
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char height : 3;
    unsigned char border_type : 4;
    unsigned char border_shape : 4;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects;
};

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};

struct RGE_Tile_Set {
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    int resource_id;
    unsigned char shape[4];
    void* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char map_lt_cliff_color;
    unsigned char map_rt_cliff_color;
    unsigned char passable_terrain;
    unsigned char impassable_terrain;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    unsigned char tiles[114];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
    short num_obj_type;
};

struct RGE_Border_Set {
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    int resource_id;
    unsigned char shape[4];
    void* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    unsigned char borders[1368];
    unsigned char draw_tile;
    short underlay_terrain;
    short border_style;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    int map_width;
    int map_height;
    int world_width;
    int world_height;
    RGE_Tile_Size tilesizes[19];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];
    RGE_Tile** map_row_offset;
    short num_terrain;
    short num_borders;
    short max_terrain;
    short tile_width;
    short tile_height;
    short tile_half_height;
    short tile_half_width;
    short elev_height;
    short cur_row;
    short cur_col;
    short block_beg_row;
    short block_end_row;
    short block_beg_col;
    short block_end_col;
    unsigned char any_frame_change;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    void* random_map;
    RGE_Game_World* game_world;
    RGE_Zone_Map_List* map_zones;
    void* unified_vis_map;
    void* unit_manager;
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
    int sound_update_index;
    int sprite_update_index;
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
};

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    unsigned long PlayerVisibleMaskValue;
    unsigned long PlayerVisibleMaskInvertValue;
    unsigned long PlayerExploredMaskValue;
    unsigned long PlayerExploredMaskInvertValue;
    unsigned long input_csum;

    unsigned char get_visible(int x, int y);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
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
    unsigned char fog_flag;
    short terrain; // +0x66
};

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
    short master_object_num;
    RGE_Master_Static_Object** master_objects; // +0x24
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    void* victory_conditions;
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
};

class TRIBE_Player : public RGE_Player {
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class TribeMainDecisionAIModule;

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

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player; // +0xF0
    ManagedArray<int> objects; // +0xF4
};

class BuildAIModule : public AIModule {
public:
    BuildItem buildList;
    int buildListLengthValue;
    char buildListNameValue[257];
    char lastBuildItemRequestedValue[257];
    char currentBuildItemRequestedValue[257];
    char nextBuildItemRequestedValue[257];
    int numberItemsIntoBuildListValue;
    ManagedArray<int> typesToIgnore;
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;
};

class ConstructionAIModule : public AIModule {
public:
    int numberConstructionLotsValue;
    ConstructionItem constructionLots;
    int numberRandomConstructionLotsValue;
    ConstructionItem randomConstructionLots;
    char constructionPlanNameValue[0x101];
    float xReferencePointValue;
    float yReferencePointValue;
    float zReferencePointValue;
    int mapXSizeValue;
    int mapYSizeValue;
    int lastPlacementReturnCodeValue;

    ConstructionItem* randomLot(float x, float y);
};

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    TribeMainDecisionAIModule* md;
};

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;
    int dislikeTable[10];
    int likeTable[10];
    unsigned char changeableTable[10];
};

class EmotionalAIModule : public AIModule {
public:
    MainDecisionAIModule* md;
    int stateValue[6];
    char stateNameValue[180];
};

class InformationAIModule : public AIModule {
};

struct XYPoint {
    int x;
    int y;
};

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
};

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    int attackAttempts;
    unsigned char kills;
    float damageCapability;
    float rateOfFire;
    float range;
};

struct BuildingLot {
    int typeID;
    unsigned char status;
    unsigned char x;
    unsigned char y;
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
    short kills;
    unsigned char success;
    unsigned long timeStamp;
    int play;
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
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray<int> farmsTaskedThisUpdate; // +0xF0
    TribeMainDecisionAIModule* md; // +0x100
    int mapXSizeValue;
    int mapYSizeValue;
    int lastUpdateRowValue;
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    ManagedArray<int> importantObjects;
    ManagedArray<int> importantUnits;
    ManagedArray<int> importantMiscs;
    ManagedArray<int> itemsToDefend;
    InfluenceMap pathMap;
    ManagedArray<int> playerObjects;
    ManagedArray<int> playerBuildings;
    XYPoint lastWallPosition;
    XYPoint lastWallPosition2;
    int numberGatesValue;
    XYPoint minGatePosition[4];
    XYPoint maxGatePosition[4];
    int maxBuildingLots;
    BuildingLot* buildingLots;
    int maxAttackMemories;
    AttackMemory* attackMemories;
    int saveLearnInformationValue;
    char learnFileName[256];
    unsigned char fullyExploredZoneValue[255];
    QuadrantLog quadrantLog[4][4];
    int** resourceTypesValue;
    int* numberResourceTypesValue;
    ResourceMemory* resources[4];
    int numResources[4];
    int maxResources[4];
    int dropsitesByAge[4][4];
    int closestDropsiteValue[4];
    int closestDropsiteResourceID[4];
    int numberFoundForestTilesValue;
    int playHistory[16000];
    int unitHistory[11];
    char unitHistoryFilename[256];

    int hasAdjacentTileType(int x, int y, int type);
    int numberDocksInZone(int zone, RGE_Zone_Map* zone_map);
    int closestDockDistance(int x, int y);
    ConstructionItem* placeDock(BuildItem* item, float x, float y,
                                 int terrain_type, int tile_type);
};

class TribeResourceAIModule : public AIModule {
public:
    MainDecisionAIModule* md;
    int numberResourcesValue;
};

class StrategyAIModule : public AIModule {
};

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
};

class VictoryConditionRuleSystem {
public:
    virtual ~VictoryConditionRuleSystem();
    int sn[226];
};

class TribeStrategyAIModule : public StrategyAIModule {
public:
    MainDecisionAIModule* md;
    int currentVictoryConditionValue;
    char ruleSetNameValue[257];
    int targetIDValue;
    int targetTypeValue;
    int secondTargetIDValue;
    int secondTargetTypeValue;
    Waypoint targetPoint1Value;
    Waypoint targetPoint2Value;
    int targetAttributeValue;
    int targetNumberValue;
    int victoryConditionChangeTimeout;
    ManagedArray<int> vcRuleSet;
    ManagedArray<int> executingRules;
    ManagedArray<int> idleRules;
    VictoryConditionRuleSystem vcRules;
    int difficultyLevel;
};

class TacticalAIModule : public AIModule {
};

class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;
};

struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    unsigned long lastTaskTime;
};

struct AttackState {
    int bestTargetID;
    float bestTargetValue;
    int bestTargetMemoryIndex;
    int iterationIndex;
    int attackGroupID;
    int playID;
    unsigned char phase;
    int bestNonWallTargetID;
    float bestNonWallTargetValue;
    int bestNonWallTargetMemoryIndex;
    int active;
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

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;
    int originalHitPointsValue;
    int originalUnitNumberValue;
    Waypoint locationValue;
    int actionValue;
    int targetValue;
    int targetTypeValue;
    Waypoint targetLocationValue;
    Waypoint gatherLocationValue;
    Waypoint retreatLocationValue;
    int priorityValue;
    int waitCodeValue;
    int assistGroupIDValue;
    int assistGroupTypeValue;
    unsigned long consecutiveIdleUnitCountValue;
    int playNumberValue;
    unsigned char numberAttackWaypointsValue;
    unsigned char currentAttackWaypointValue;
    Waypoint attackWaypoints[15];
    unsigned char consecutiveGatherAttemptsValue;
    int numberObjectsToDestroyValue;
    int objectsToDestroyValue[20];
    int objectsToDestroyOwnerValue;
    int objectsToDestroyCommanderZoneValue;
    unsigned long lastAttackRoundupTime;
    unsigned long lastAddedUnitTimeValue;
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

    int strategicNumber(int number);
};

class TradeAIModule : public AIModule {
public:
    MainDecisionAIModule* md;
};

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
    TRIBE_Player* aiPlayer; // PDB +0x1256C
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

    virtual ~TribeMainDecisionAIModule();
};

ConstructionItem* TribeInformationAIModule::placeDock(
    BuildItem* item, float x, float targetY, int terrain_type, int tile_type)
{
    // BINARY NOTE: The zone-map output and cache array use separate homes.
    RGE_Visible_Map* visible = this->md->aiPlayer->visible;
    RGE_Map* map = this->md->aiPlayer->world->map;
    int bestY;
    RGE_Zone_Map* zoneMap;
    int bestX;
    int zoneMapIndex;
    unsigned char zoneCounter[256];
    int randomOffset;
    float bestScore;
    int y;

    bestX = -1;
    bestY = -1;
    bestScore = -1.0f;
    randomOffset = -1;

    memset(zoneCounter, -1, sizeof(zoneCounter));

    zoneMap = map->map_zones->get_zone_map(
        this->md->player->world->terrains[
            this->md->player->master_objects[0x13]->terrain],
        this->md->player->world->terrain_size, zoneMapIndex);

    randomOffset = debug_rand(
        (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x6A9) % 0x32;

    {
        int currentZone = 1;
        if (currentZone < visible->widthValue - 2) {
            do {
                y = 1;
                if (y < visible->heightValue - 2) {
                    do {
                        if (visible->get_visible(currentZone, y) != 0 &&
                            currentZone - 1 >= 0 && y - 1 >= 0 &&
                            currentZone + 1 <= visible->widthValue - 1 &&
                            y + 1 <= visible->heightValue - 1) {
                            if (terrain_type == -1 ||
                                (map->map_row_offset[y][currentZone].terrain_type & 0x1F) == terrain_type) {
                                unsigned char zone = zoneMap->get_zone_info(
                                    currentZone, y);
                                int numberTiles =
                                    zoneMap->numberTilesInZone(zone);
                                int minimumTiles =
                                    this->md->tacticalAI.strategicNumber(0x70);
                                if (numberTiles >= minimumTiles &&
                                    this->hasAdjacentTileType(
                                        currentZone, y, tile_type)) {
                                    ConstructionItem* lot =
                                        this->md->constructionAI.randomLot(
                                            (float)currentZone - DAT_00575570,
                                            (float)y - DAT_00575570);
                                    if (lot == 0) {
                                        float score = ((float)currentZone - x) *
                                                      ((float)currentZone - x) +
                                                      ((float)y - targetY) *
                                                      ((float)y - targetY);
                                        if (zoneCounter[zone] == 0xFF) {
                                            zoneCounter[zone] = (unsigned char)
                                                this->numberDocksInZone(
                                                    (int)zone, zoneMap);
                                        }
                                        // BINARY NOTE: A positive count selects the
                                        // penalty block and emits TEST/JBE.
                                        if (zoneCounter[zone] > 0) {
                                            int zonePenalty =
                                                (int)zoneCounter[zone] * 1000;
                                            score += (float)zonePenalty;
                                        }

                                        {
                                            int closest =
                                                this->closestDockDistance(
                                                    currentZone, y);
                                            if (closest != -1) {
                                                score += (float)(100000 / closest);
                                            }
                                        }

                                        if (bestX == -1 ||
                                            score < bestScore + (float)randomOffset) {
                                            bestScore = score;
                                            bestX = currentZone;
                                            bestY = y;
                                        }
                                    }
                                }
                            }
                        }

                        y++;
                    } while (y < visible->heightValue - 2);
                }

                currentZone++;
            } while (currentZone < visible->widthValue - 2);
        }
    }

    if (bestX != -1) {
        ConstructionItem* result =
            new ConstructionItem((float)bestX - DAT_00575570,
                                 (float)bestY - DAT_00575570,
                                 0.0f, item->xSize(), item->ySize(),
                                 item->zSize(), item->typeID(), item->name());
        return result;
    }
    return 0;
}
