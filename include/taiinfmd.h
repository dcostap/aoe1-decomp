#ifndef TAIINFMD_H
#define TAIINFMD_H

// Declarations for the original taiinfmd.cpp source module.
// PDB order starts with the three static initializers and the constructor
// pair, then continues through TribeInformationAIModule.

#include "aiinfmod.h"
#include "ai_attack_state.h"
#include "ai_placement_state.h"
#include "aiplaybook.h"
#include "infmap.h"
#include "taiinf_records.h"
#include "tactical_group.h"
#include "utmarray.h"
#include "xy_point.h"

#ifndef uchar
typedef unsigned char uchar;
#endif
#ifndef ulong
typedef unsigned long ulong;
#endif

typedef ManagedArray<int> ManagedArray_int;

class RGE_Base_Game;
class RGE_Game_Info;
class RGE_Game_World;
class RGE_Map;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Static_Object;
class RGE_Visible_Map;
class RGE_Zone_Map;
class RGE_Zone_Map_List;
class TribeMainDecisionAIModule;
class UnitAIModule;
class BuildItem;
class ConstructionItem;
class PathingSystem;
class RGE_Action;
class RGE_Action_List;

// The shipped module uses these three fixed global InfluenceMap objects.
extern InfluenceMap* const iMap;
extern InfluenceMap* const losMap;
extern InfluenceMap* const attackMap;
extern PathingSystem aiPathSystem;

void* operator new(unsigned int size);
void operator delete(void* pointer);
extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* pointer);

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray<int> farmsTaskedThisUpdate;
    TribeMainDecisionAIModule* md;
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
    int gameIDsOwnedBy(int ownerFilter, int** out, int ownerId);
    int numberGameIDsOwnedBy(int param1, int param2);
    ConstructionItem* placeDock(BuildItem* item, float x, float targetY,
                                 int terrainType, int tileType);
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
    int withinXTilesOfEnemyTowncenter(RGE_Static_Object* object, int tiles);
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

typedef RGE_Static_Object RGE_Obj;
typedef RGE_Master_Static_Object RGE_Master_Object;

typedef char taiinfmd_information_size[
    (sizeof(TribeInformationAIModule) == 0x10090) ? 1 : -1];

typedef char taiinfmd_managed_array_size[
    (sizeof(ManagedArray<int>) == 0x10) ? 1 : -1];

extern "C" void __cdecl rge_read(int file, void* buffer, int size);
extern "C" int __cdecl rge_open(char* path, int mode, int attr = 0);
extern "C" void __cdecl rge_write(int file, void* buffer, int size);
extern "C" int debug_rand(char* file, int line);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" long __cdecl _ftol();
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
