#ifndef TAIINFMD_H
#define TAIINFMD_H

#include "aiinfmod.h"
#include "ai_attack_state.h"
#include "ai_placement_state.h"
#include "aiplaybook.h"
#include "infmap.h"
#include "rge_fio.h"
#include "taiinf_records.h"
#include "tactical_group.h"
#include "utmarray.h"
#include "xy_point.h"
#include "game_globals.h"

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

// The module owns these three global InfluenceMap objects.
extern InfluenceMap iMap;
extern InfluenceMap losMap;
extern InfluenceMap attackMap;

void* operator new(unsigned int size);
void operator delete(void* pointer);

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

    TribeInformationAIModule(int pID, int infile);
    virtual ~TribeInformationAIModule();
    TribeInformationAIModule(void* pW, int pID);
    int initialize();
    virtual int update(int timeLimit);
    int save(int outfile);
    void setMainDecisionAI(TribeMainDecisionAIModule* value);
    int closestUnexploredTile(int uID, float cX, float cY, float* uX, float* uY);
    ObjectMemory* addObjectMemory(RGE_Static_Object* obj);
    ObjectMemory* addObjectMemory(
        int id, short type, short group, unsigned char x, unsigned char y, unsigned char z, unsigned char owner,
        short hp, int attempts, unsigned char kills, float damage, float rate, float weaponRange,
        RGE_Static_Object* object
    );
    int addImportantObject(RGE_Static_Object* oObj, int addedFromAlliedCP);
    int addImportantObject(int oID);
    int mapBound(XYPoint& pt);
    void blotExploredMap(int minX, int minY, int maxX, int maxY);
    int fullyExploredZone(int id);
    void setFullyExploredZone(int id, int v);
    int tileUncovered(int x, int y);
    void setTileExplored(int x, int y);
    int ownerOfGameID(int id);
    int gameIDOfResourceObject(
        int rType, int gathererID, float& roXPos, float& roYPos, int& dropsiteID, int* exclusions, int numExclusions
    );
    int gameIDsOfObjectType(int oType, int** objects, int** owners, int ownerNumber);
    int gameIDsOwnedBy(int oType, int** objects, int ownerNumber);
    int numberGameIDsOwnedBy(int oType, int ownerNumber);
    ConstructionItem* placeDock(BuildItem* bi, float cX, float cY, int centerType, int edgeType);
    int numberDocksInZone(int zone, RGE_Zone_Map* zoneMap);
    int closestDockDistance(int x, int y);
    int hasAdjacentTileType(int x, int y, int aType);
    int mapXSize();
    int mapYSize();
    void addEnemyInfluences(int ownerID, int targetID);
    void addPriorAttackInfluences(int ownerID, int targetID);
    int isBuilding(RGE_Static_Object* obj);
    int isUnitBuilding(RGE_Static_Object* obj);
    int isBoat(RGE_Static_Object* obj);
    int isWall(RGE_Static_Object* obj);
    int isTower(RGE_Static_Object* obj);
    int influenceCanPlaceStructure(BuildItem* bi);
    ConstructionItem* influencePlaceStructure(
        BuildItem* bi, int builderID, int alternateType, float alternateSize, char* alternateName, int alternateMinD,
        int alternateMaxD, int alternateX, int alternateY, PlacementState& placementState, unsigned long startTime
    );
    void addObject(RGE_Static_Object* obj);
    void removeObject(int objID);
    ObjectMemory* objectToAttackWithPlay(
        int ownerID, int* soldiers, int numSoldiers, int& playToRun, int* playUnits, int& numberPlayUnits,
        int& playCommander
    );
    ObjectMemory* objectToAttack(
        int ownerID, int ignoreSiegeTargets, int ignoreBoatTargets, int unitID, int& validAttack
    );
    ObjectMemory* objectToAttack(
        int ownerID, int ignoreSiegeTargets, int ignoreBoatTargets, int unitID, int* validAttack
    );
    ObjectMemory* objectToAttackByGroup(
        int ownerID, TacticalAIGroup* group, AttackState& attackState, unsigned long startTime
    );
    ObjectMemory* objectToAttackByGroup2(int ownerID, int* soldiers, int numberSoldiers);
    int isBoatAccessible(RGE_Static_Object* unit, int target);
    int isLandAccessible(RGE_Static_Object* unit, int target);
    int numberItemsToDefend();
    ObjectMemory* higherPriorityObjectToDefend(int unitID, int oType, int oGroup);
    int checkDefend(RGE_Static_Object* obj);
    ObjectMemory* objectToTradeWith(int unitID);
    int findGatherPosition(
        XYPoint& centerPoint, int num, int landTroops, int desiredDistance, int maximumDistanceVariation,
        RGE_Static_Object* testUnit, XYPoint& rPoint
    );
    void setupInfluenceMap(
        int placementType, int buildingType, XYPoint& centerPoint, XYPoint& minArea, XYPoint& maxArea
    );
    int groupInfluenceDimension(int dim);
    ObjectMemory findObjectMemoryLimits(int ownerID, int unitID, int& numberNonSiegeTargets, int& numberNonBoatTargets);
    int isNextTo(XYPoint& one, XYPoint& two, int countDiagonal);
    int facetTo(XYPoint& one, XYPoint& two);
    int placementCode(int typeID);
    BuildingLot* availableLot(int typeID);
    int invalidLot(int typeID, unsigned char x, unsigned char y);
    int undesirableLot(int typeID, unsigned char xRange, unsigned char yRange, int coordOffset);
    void storeLot(int typeID, unsigned char x, unsigned char y, unsigned char status);
    void removeLot(int typeID, unsigned char x, unsigned char y, unsigned char newStatus);
    void setupWalls(
        int x, int y, int minimumDistance, int maximumDistance, int pattern, int numberGates, int gateSize,
        int townWalls
    );
    int insideGate(int numGates, int x, int y);
    int storeAttackMemory(
        unsigned char type, unsigned char x1, unsigned char y1, unsigned char attackingOwner, unsigned char targetOwner,
        short kills, unsigned char success, unsigned long timeStamp, int play
    );
    int storeAttackMemory(
        unsigned char type, unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2,
        unsigned char attackingOwner, unsigned char targetOwner, short kills, unsigned char success,
        unsigned long timeStamp, int play
    );
    int storeAttackMemory(
        unsigned char p1, unsigned char p2, unsigned char p3, unsigned char p4, unsigned char p5, unsigned char p6,
        unsigned char p7, short p8, unsigned char p9, unsigned int p10, int p11
    );
    void removeAttackMemory(int id);
    AttackMemory* attackMemory(int id);
    void setSaveLearnInformation(int v);
    void loadLearnInfo(char* name);
    int unexploredPlayerLocation(int uID, XYPoint& rPoint);
    int numberUnitsWithinXTiles(int playerID, int x, int y, int numTiles);
    int withinXTilesOfAttackOnPlayer(RGE_Static_Object* obj, int numTiles, int victimID);
    int withinXTilesOfEnemyTowncenter(RGE_Static_Object* obj, int distance);
    int withinXTilesOfObject(RGE_Static_Object* obj, int distance, int oT1, int oT2, int oT3, int oT4);
    int findStagingPoint(
        XYPoint startPoint, XYPoint& rPoint, int useTransport, int landTerrainRequired, int targetID, int stageDistance,
        int unitID
    );
    int setupLOSMap(int ownerID, int x, int y);
    int setupAttackMap(int ownerID, int x, int y);
    int resourceType(int r, int t);
    int setResourceObjectValid(int rType, int id, int newValid);
    int addResourceObject(RGE_Static_Object* obj);
    float findClosestDropsite(RGE_Static_Object* resourceObj, int countTownCenter, int& dropsiteID);
    RGE_Static_Object* findClosestReturnDropsite(RGE_Static_Object* unitObj);
    void updateAllResourceDropsites();
    void updateResourceDropsites(int rType);
    int amountForageBushesInXTiles(int x, int y, int distance);
    int amountResourceTypesInXTiles(int type, int x, int y, int distance);
    float damagePerSecond(int id, int x, int y);
    int benefitToKillUnit(int id);
    int costToLoseUnit(int id);
    int inRangeOfUnits(int playerID, int x, int y, int useJustRange);
    ObjectMemory* wonderToAttack(int playerID);
    ObjectMemory* ruinToCapture(int playerID);
    ObjectMemory* artifactToCapture(int playerID);
    int resourceTypeToPlaceDropsiteBy(int dropsiteType);
    int dropsitesWithinRequiredDistance(int& numDS, int rType, int maxDistance);
    int numberAvailableStoragePits(int rType);
    int numberAvailableGranaries();
    void lookAtMap();
    float damageInflictedPerSecond(TacticalAIGroup* group, RGE_Static_Object* obj);
    float damageInflictedPerSecond(int* group, int groupSize, RGE_Static_Object* obj);
    float timeToBeKilled(TacticalAIGroup* group, RGE_Static_Object* obj);
    float timeToBeKilled(int* group, int groupSize, RGE_Static_Object* obj);
    int numberStoragePits();
    int numberGranaries();
    int closestDropsiteResID(int rType) const;
    int calculatePlayVariation(int playID);
    int convertUnitToIntType(RGE_Static_Object* obj) const;
    void loadUnitHistory();
    void unitsThatAreMostBuilt(int& rVal1, int& rVal2);
    void unitsThatAreLeastBuilt(int& rVal1, int& rVal2);
    int percentTilesExploredInPositionQuadrant(int x, int y);
    int acceptablePotentialDropsiteArea(int x, int y);
    ObjectMemory* objectToDefend(int unitID);
    int defendPriority(int oType, int oGroup);
    ObjectMemory* objectMemory(int id);
    int importantObject(int oType);
    int importantUnit(int oType);
    int importantResource(int oType);
    int importantMisc(int oType);
    void addResourceType(int r, int t);
};

typedef char taiinfmd_information_size[(sizeof(TribeInformationAIModule) == 0x10090) ? 1 : -1];

typedef char taiinfmd_managed_array_size[(sizeof(ManagedArray<int>) == 0x10) ? 1 : -1];

#endif
