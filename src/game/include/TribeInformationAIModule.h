#pragma once
#include "common.h"
#include "InformationAIModule.h"
#include "AttackMemory.h"
#include "BuildingLot.h"
#include "InfluenceMap.h"
#include "ObjectMemory.h"
#include "QuadrantLog.h"
#include "ResourceMemory.h"
#include "XYPoint.h"

class TribeInformationAIModule : public InformationAIModule {
public:
    TribeInformationAIModule(void* param_1, int param_2);
    TribeInformationAIModule(int param_1, int param_2);

    // Virtuals (best-effort)
    virtual ~TribeInformationAIModule(); // vt[0] (0x0)
    virtual int loggingHistory(); // vt[1] (0x4)
    virtual void setLogHistory(int param_1); // vt[2] (0x8)
    virtual void toggleLogHistory(); // vt[3] (0xC)
    virtual void setHistoryFilename(char* param_1); // vt[4] (0x10)
    virtual int loggingCommonHistory(); // vt[5] (0x14)
    virtual void setLogCommonHistory(int param_1); // vt[6] (0x18)
    virtual void toggleLogCommonHistory(); // vt[7] (0x1C)
    virtual int loadState(char* param_1); // vt[8] (0x20)
    virtual int saveState(char* param_1); // vt[9] (0x24)
    virtual int gleanState(int param_1); // vt[10] (0x28)
    virtual int processMessage(AIModuleMessage* param_1); // vt[11] (0x2C)
    virtual int update(int param_1); // vt[12] (0x30)
    virtual void setCallbackMessage(AIModuleMessage* param_1); // vt[13] (0x34)
    virtual int filterOutMessage(AIModuleMessage* param_1); // vt[14] (0x38)

    int initialize();
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    int save(int param_1);
    void blotExploredMap(int param_1, int param_2, int param_3, int param_4);
    int closestUnexploredTile(int param_1, float param_2, float param_3, float* param_4, float* param_5);
    int fullyExploredZone(int param_1);
    void setFullyExploredZone(int param_1, int param_2);
    int tileUncovered(int param_1, int param_2);
    void setTileExplored(int param_1, int param_2);
    int mapXSize();
    int mapYSize();
    int mapBound(XYPoint& param_1);
    int addImportantObject(RGE_Static_Object* param_1, int param_2);
    int addImportantObject(int param_1);
    int importantObject(int param_1);
    int importantUnit(int param_1);
    int importantResource(int param_1);
    int importantMisc(int param_1);

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
};
static_assert(sizeof(TribeInformationAIModule) == 0x10090, "Size mismatch");
