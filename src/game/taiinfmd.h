#pragma once
#include "common.h"

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

    virtual int update(int param_1);                        // vt0[12]+0x30=0x4D8300
    TribeInformationAIModule(void* param_1, int param_2);
    TribeInformationAIModule(int param_1, int param_2);
    ~TribeInformationAIModule();
    int initialize();
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    int save(int param_1);
    void blotExploredMap(int param_1, int param_2, int param_3, int param_4);
    int closestUnexploredTile(int param_1, float param_2, float param_3, float* param_4, float* param_5);
    int fullyExploredZone(int param_1);
    void setFullyExploredZone(int param_1, int param_2);
    int tileUncovered(int param_1, int param_2);
    void setTileExplored(int param_1, int param_2);
    int ownerOfGameID(int param_1);
    int gameIDOfResourceObject(int param_1, int param_2, float* param_3, float* param_4, int* param_5, int* param_6, int param_7);
    int gameIDsOfObjectType(int param_1, int** param_2, int** param_3, int param_4);
    int gameIDsOwnedBy(int param_1, int** param_2, int param_3);
    int numberGameIDsOwnedBy(int param_1, int param_2);
    ConstructionItem* placeDock(BuildItem* param_1, float param_2, float param_3, int param_4, int param_5);
    int numberDocksInZone(int param_1, RGE_Zone_Map* param_2);
    int closestDockDistance(int param_1, int param_2);
    int hasAdjacentTileType(int param_1, int param_2, int param_3);
    int mapXSize();
    int mapYSize();
    void addEnemyInfluences(int param_1, int param_2);
    void addPriorAttackInfluences(int param_1, int param_2);
    ObjectMemory* objectMemory(int param_1);
    ObjectMemory* addObjectMemory(RGE_Static_Object* param_1);
    ObjectMemory* addObjectMemory(int param_1, short param_2, short param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7, short param_8, int param_9, uchar param_10, float param_11, float param_12, float param_13, RGE_Static_Object* param_14);
    int addImportantObject(RGE_Static_Object* param_1, int param_2);
    int addImportantObject(int param_1);
    int importantObject(int param_1);
    int importantUnit(int param_1);
    int importantResource(int param_1);
    int importantMisc(int param_1);
    int isBuilding(RGE_Static_Object* param_1);
    int isUnitBuilding(RGE_Static_Object* param_1);
    int isBoat(RGE_Static_Object* param_1);
    int isWall(RGE_Static_Object* param_1);
    int isTower(RGE_Static_Object* param_1);
    int isBoatAccessible(RGE_Static_Object* param_1, int param_2);
    int isLandAccessible(RGE_Static_Object* param_1, int param_2);
    int influenceCanPlaceStructure(BuildItem* param_1);
    ConstructionItem* influencePlaceStructure(BuildItem* param_1, int param_2, int param_3, float param_4, char* param_5, int param_6, int param_7, int param_8, int param_9, PlacementState* param_10, ulong param_11);
    void addObject(RGE_Static_Object* param_1);
    void removeObject(int param_1);
    ObjectMemory* objectToAttackWithPlay(int param_1, int* param_2, int param_3, int* param_4, int* param_5, int* param_6, int* param_7);
    ObjectMemory* objectToAttack(int param_1, int param_2, int param_3, int param_4, int* param_5);
    ObjectMemory* objectToAttackByGroup(int param_1, TacticalAIGroup* param_2, AttackState* param_3, ulong param_4);
    ObjectMemory* objectToAttackByGroup2(int param_1, int* param_2, int param_3);
    ObjectMemory* objectToDefend(int param_1);
    ObjectMemory* higherPriorityObjectToDefend(int param_1, int param_2, int param_3);
    int defendPriority(int param_1, int param_2);
    int checkDefend(RGE_Static_Object* param_1);
    int numberItemsToDefend();
    ObjectMemory* objectToTradeWith(int param_1);
    int findGatherPosition(XYPoint* param_1, int param_2, int param_3, int param_4, int param_5, RGE_Static_Object* param_6, XYPoint* param_7);
    void setupInfluenceMap(int param_1, int param_2, XYPoint* param_3, XYPoint* param_4, XYPoint* param_5);
    int mapBound(XYPoint* param_1);
    int groupInfluenceDimension(int param_1);
    ObjectMemory* findObjectMemoryLimits(int param_1, int param_2, int* param_3, int* param_4);
    int isNextTo(XYPoint* param_1, XYPoint* param_2, int param_3);
    int facetTo(XYPoint* param_1, XYPoint* param_2);
    int placementCode(int param_1);
    void storeLot(int param_1, uchar param_2, uchar param_3, uchar param_4);
    void removeLot(int param_1, uchar param_2, uchar param_3, uchar param_4);
    BuildingLot* availableLot(int param_1);
    int invalidLot(int param_1, uchar param_2, uchar param_3);
    int undesirableLot(int param_1, uchar param_2, uchar param_3, int param_4);
    void setupWalls(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8);
    int insideGate(int param_1, int param_2, int param_3);
    int storeAttackMemory(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, short param_6, uchar param_7, ulong param_8, int param_9);
    int storeAttackMemory(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7, short param_8, uchar param_9, ulong param_10, int param_11);
    void removeAttackMemory(int param_1);
    AttackMemory* attackMemory(int param_1);
    void loadLearnInfo(char* param_1);
    void setSaveLearnInformation(int param_1);
    int unexploredPlayerLocation(int param_1, XYPoint* param_2);
    int numberUnitsWithinXTiles(int param_1, int param_2, int param_3, int param_4);
    int withinXTilesOfAttackOnPlayer(RGE_Static_Object* param_1, int param_2, int param_3);
    int withinXTilesOfEnemyTowncenter(RGE_Static_Object* param_1, int param_2);
    int withinXTilesOfObject(RGE_Static_Object* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    int findStagingPoint(XYPoint param_1, XYPoint* param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    int setupLOSMap(int param_1, int param_2, int param_3);
    int setupAttackMap(int param_1, int param_2, int param_3);
    void addResourceType(int param_1, int param_2);
    int resourceType(int param_1, int param_2);
    int addResourceObject(RGE_Static_Object* param_1);
    float findClosestDropsite(RGE_Static_Object* param_1, int param_2, int* param_3);
    RGE_Static_Object* findClosestReturnDropsite(RGE_Static_Object* param_1);
    void updateAllResourceDropsites();
    void updateResourceDropsites(int param_1);
    int setResourceObjectValid(int param_1, int param_2, int param_3);
    int numberStoragePits();
    int numberGranaries();
    int amountForageBushesInXTiles(int param_1, int param_2, int param_3);
    int amountResourceTypesInXTiles(int param_1, int param_2, int param_3, int param_4);
    float damagePerSecond(int param_1, int param_2, int param_3);
    int costToLoseUnit(int param_1);
    int benefitToKillUnit(int param_1);
    int inRangeOfUnits(int param_1, int param_2, int param_3, int param_4);
    ObjectMemory* wonderToAttack(int param_1);
    ObjectMemory* ruinToCapture(int param_1);
    ObjectMemory* artifactToCapture(int param_1);
    int resourceTypeToPlaceDropsiteBy(int param_1);
    int dropsitesWithinRequiredDistance(int* param_1, int param_2, int param_3);
    int numberAvailableStoragePits(int param_1);
    int numberAvailableGranaries();
    void lookAtMap();
    float damageInflictedPerSecond(TacticalAIGroup* param_1, RGE_Static_Object* param_2);
    float damageInflictedPerSecond(int* param_1, int param_2, RGE_Static_Object* param_3);
    float timeToBeKilled(TacticalAIGroup* param_1, RGE_Static_Object* param_2);
    float timeToBeKilled(int* param_1, int param_2, RGE_Static_Object* param_3);
    int closestDropsiteResID(int param_1);
    int calculatePlayVariation(int param_1);
    int convertUnitToIntType(RGE_Static_Object* param_1);
    void loadUnitHistory();
    void unitsThatAreMostBuilt(int* param_1, int* param_2);
    void unitsThatAreLeastBuilt(int* param_1, int* param_2);
    int acceptablePotentialDropsiteArea(int param_1, int param_2);
    int percentTilesExploredInPositionQuadrant(int param_1, int param_2);
};

static_assert(sizeof(TribeInformationAIModule) == 0x10090, "TribeInformationAIModule Size Mismatch");

