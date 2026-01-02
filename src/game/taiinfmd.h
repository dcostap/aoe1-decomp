#pragma once
#include "../common.h"

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray<int> farmsTaskedThisUpdate; // 0xF0
    TribeMainDecisionAIModule* md;           // 0x100
    int mapXSizeValue;                       // 0x104
    int mapYSizeValue;                       // 0x108
    int lastUpdateRowValue;                  // 0x10C
    int maxImportantObjectMemory;            // 0x110
    ObjectMemory* importantObjectMemory;     // 0x114
    ManagedArray<int> importantObjects;      // 0x118
    ManagedArray<int> importantUnits;        // 0x128
    ManagedArray<int> importantMiscs;        // 0x138
    ManagedArray<int> itemsToDefend;         // 0x148
    InfluenceMap pathMap;                    // 0x158
    ManagedArray<int> playerObjects;         // 0x180
    ManagedArray<int> playerBuildings;       // 0x190
    XYPoint lastWallPosition;                // 0x1A0
    XYPoint lastWallPosition2;               // 0x1A8
    int numberGatesValue;                    // 0x1B0
    XYPoint minGatePosition[4];              // 0x1B4
    XYPoint maxGatePosition[4];              // 0x1D4
    int maxBuildingLots;                     // 0x1F4
    BuildingLot* buildingLots;               // 0x1F8
    int maxAttackMemories;                   // 0x1FC
    AttackMemory* attackMemories;            // 0x200
    int saveLearnInformationValue;           // 0x204
    char learnFileName[256];                 // 0x208
    uchar fullyExploredZoneValue[255];       // 0x308
    QuadrantLog* quadrantLog[4];             // 0x408
    int** resourceTypesValue;                // 0x4C8
    int* numberResourceTypesValue;           // 0x4CC
    ResourceMemory* resources[4];            // 0x4D0
    int numResources[4];                     // 0x4E0
    int maxResources[4];                     // 0x4F0
    int* dropsitesByAge[4];                  // 0x500
    int closestDropsiteValue[4];             // 0x540
    int closestDropsiteResourceID[4];        // 0x550
    int numberFoundForestTilesValue;         // 0x560
    int playHistory[16000];                  // 0x564
    int unitHistory[11];                     // 0xFF64
    char unitHistoryFilename[256];           // 0xFF90

    TribeInformationAIModule(void* param_1, int param_2);
    TribeInformationAIModule(int param_1, int param_2);
    virtual ~TribeInformationAIModule();
    virtual int initialize();
    virtual int update(int param_1);
    virtual void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    virtual int save(int param_1);
    virtual void blotExploredMap(int param_1, int param_2, int param_3, int param_4);
    virtual int closestUnexploredTile(int param_1, float param_2, float param_3, float* param_4, float* param_5);
    virtual int fullyExploredZone(int param_1);
    virtual void setFullyExploredZone(int param_1, int param_2);
    virtual int tileUncovered(int param_1, int param_2);
    virtual void setTileExplored(int param_1, int param_2);
    virtual int ownerOfGameID(int param_1);
    virtual int gameIDOfResourceObject(int param_1, int param_2, float* param_3, float* param_4, int* param_5, int* param_6, int param_7);
    virtual int gameIDsOfObjectType(int param_1, int** param_2, int** param_3, int param_4);
    virtual int gameIDsOwnedBy(int param_1, int** param_2, int param_3);
    virtual int numberGameIDsOwnedBy(int param_1, int param_2);
    virtual ConstructionItem* placeDock(BuildItem* param_1, float param_2, float param_3, int param_4, int param_5);
    virtual int numberDocksInZone(int param_1, RGE_Zone_Map* param_2);
    virtual int closestDockDistance(int param_1, int param_2);
    virtual int hasAdjacentTileType(int param_1, int param_2, int param_3);
    virtual int mapXSize();
    virtual int mapYSize();
    virtual void addEnemyInfluences(int param_1, int param_2);
    virtual void addPriorAttackInfluences(int param_1, int param_2);
    virtual ObjectMemory* objectMemory(int param_1);
    virtual ObjectMemory* addObjectMemory(RGE_Static_Object* param_1);
    virtual ObjectMemory* addObjectMemory(int param_1, short param_2, short param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7, short param_8, int param_9, uchar param_10, float param_11, float param_12, float param_13, RGE_Static_Object* param_14);
    virtual int addImportantObject(RGE_Static_Object* param_1, int param_2);
    virtual int addImportantObject(int param_1);
    virtual int importantObject(int param_1);
    virtual int importantUnit(int param_1);
    virtual int importantResource(int param_1);
    virtual int importantMisc(int param_1);
    virtual int isBuilding(RGE_Static_Object* param_1);
    virtual int isUnitBuilding(RGE_Static_Object* param_1);
    virtual int isBoat(RGE_Static_Object* param_1);
    virtual int isWall(RGE_Static_Object* param_1);
    virtual int isTower(RGE_Static_Object* param_1);
    virtual int isBoatAccessible(RGE_Static_Object* param_1, int param_2);
    virtual int isLandAccessible(RGE_Static_Object* param_1, int param_2);
    virtual int influenceCanPlaceStructure(BuildItem* param_1);
    virtual ConstructionItem* influencePlaceStructure(BuildItem* param_1, int param_2, int param_3, float param_4, char* param_5, int param_6, int param_7, int param_8, int param_9, PlacementState* param_10, ulong param_11);
    virtual void addObject(RGE_Static_Object* param_1);
    virtual void removeObject(int param_1);
    virtual ObjectMemory* objectToAttackWithPlay(int param_1, int* param_2, int param_3, int* param_4, int* param_5, int* param_6, int* param_7);
    virtual ObjectMemory* objectToAttack(int param_1, int param_2, int param_3, int param_4, int* param_5);
    virtual ObjectMemory* objectToAttackByGroup(int param_1, TacticalAIGroup* param_2, AttackState* param_3, ulong param_4);
    virtual ObjectMemory* objectToAttackByGroup2(int param_1, int* param_2, int param_3);
    virtual ObjectMemory* objectToDefend(int param_1);
    virtual ObjectMemory* higherPriorityObjectToDefend(int param_1, int param_2, int param_3);
    virtual int defendPriority(int param_1, int param_2);
    virtual int checkDefend(RGE_Static_Object* param_1);
    virtual int numberItemsToDefend();
    virtual ObjectMemory* objectToTradeWith(int param_1);
    virtual int findGatherPosition(XYPoint* param_1, int param_2, int param_3, int param_4, int param_5, RGE_Static_Object* param_6, XYPoint* param_7);
    virtual void setupInfluenceMap(int param_1, int param_2, XYPoint* param_3, XYPoint* param_4, XYPoint* param_5);
    virtual int mapBound(XYPoint* param_1);
    virtual int groupInfluenceDimension(int param_1);
    virtual ObjectMemory* findObjectMemoryLimits(ObjectMemory* __return_storage_ptr__, int param_1, int param_2, int* param_3, int* param_4);
    virtual int isNextTo(XYPoint* param_1, XYPoint* param_2, int param_3);
    virtual int facetTo(XYPoint* param_1, XYPoint* param_2);
    virtual int placementCode(int param_1);
    virtual void storeLot(int param_1, uchar param_2, uchar param_3, uchar param_4);
    virtual void removeLot(int param_1, uchar param_2, uchar param_3, uchar param_4);
    virtual BuildingLot* availableLot(int param_1);
    virtual int invalidLot(int param_1, uchar param_2, uchar param_3);
    virtual int undesirableLot(int param_1, uchar param_2, uchar param_3, int param_4);
    virtual void setupWalls(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8);
    virtual int insideGate(int param_1, int param_2, int param_3);
    virtual int storeAttackMemory(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, short param_6, uchar param_7, ulong param_8, int param_9);
    virtual int storeAttackMemory(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7, short param_8, uchar param_9, ulong param_10, int param_11);
    virtual void removeAttackMemory(int param_1);
    virtual AttackMemory* attackMemory(int param_1);
    virtual void loadLearnInfo(char* param_1);
    virtual void setSaveLearnInformation(int param_1);
    virtual int unexploredPlayerLocation(int param_1, XYPoint* param_2);
    virtual int numberUnitsWithinXTiles(int param_1, int param_2, int param_3, int param_4);
    virtual int withinXTilesOfAttackOnPlayer(RGE_Static_Object* param_1, int param_2, int param_3);
    virtual int withinXTilesOfEnemyTowncenter(RGE_Static_Object* param_1, int param_2);
    virtual int withinXTilesOfObject(RGE_Static_Object* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    virtual int findStagingPoint(XYPoint param_1, XYPoint* param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    virtual int setupLOSMap(int param_1, int param_2, int param_3);
    virtual int setupAttackMap(int param_1, int param_2, int param_3);
    virtual void addResourceType(int param_1, int param_2);
    virtual int resourceType(int param_1, int param_2);
    virtual int addResourceObject(RGE_Static_Object* param_1);
    virtual float findClosestDropsite(RGE_Static_Object* param_1, int param_2, int* param_3);
    virtual RGE_Static_Object* findClosestReturnDropsite(RGE_Static_Object* param_1);
    virtual void updateAllResourceDropsites();
    virtual void updateResourceDropsites(int param_1);
    virtual int setResourceObjectValid(int param_1, int param_2, int param_3);
    virtual int numberStoragePits();
    virtual int numberGranaries();
    virtual int amountForageBushesInXTiles(int param_1, int param_2, int param_3);
    virtual int amountResourceTypesInXTiles(int param_1, int param_2, int param_3, int param_4);
    virtual float damagePerSecond(int param_1, int param_2, int param_3);
    virtual int costToLoseUnit(int param_1);
    virtual int benefitToKillUnit(int param_1);
    virtual int inRangeOfUnits(int param_1, int param_2, int param_3, int param_4);
    virtual ObjectMemory* wonderToAttack(int param_1);
    virtual ObjectMemory* ruinToCapture(int param_1);
    virtual ObjectMemory* artifactToCapture(int param_1);
    virtual int resourceTypeToPlaceDropsiteBy(int param_1);
    virtual int dropsitesWithinRequiredDistance(int* param_1, int param_2, int param_3);
    virtual int numberAvailableStoragePits(int param_1);
    virtual int numberAvailableGranaries();
    virtual void lookAtMap();
    virtual float damageInflictedPerSecond(TacticalAIGroup* param_1, RGE_Static_Object* param_2);
    virtual float damageInflictedPerSecond(int* param_1, int param_2, RGE_Static_Object* param_3);
    virtual float timeToBeKilled(TacticalAIGroup* param_1, RGE_Static_Object* param_2);
    virtual float timeToBeKilled(int* param_1, int param_2, RGE_Static_Object* param_3);
    virtual int closestDropsiteResID(int param_1);
    virtual int calculatePlayVariation(int param_1);
    virtual int convertUnitToIntType(RGE_Static_Object* param_1);
    virtual void loadUnitHistory();
    virtual void unitsThatAreMostBuilt(int* param_1, int* param_2);
    virtual void unitsThatAreLeastBuilt(int* param_1, int* param_2);
    virtual int acceptablePotentialDropsiteArea(int param_1, int param_2);
    virtual int percentTilesExploredInPositionQuadrant(int param_1, int param_2);
};

static_assert(sizeof(TribeInformationAIModule) == 0x10090, "TribeInformationAIModule Size Mismatch");
static_assert(offsetof(TribeInformationAIModule, unitHistoryFilename) == 0xFF90, "TribeInformationAIModule Offset Mismatch");

