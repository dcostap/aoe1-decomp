#ifndef TAITACMD_SHARED_CONTEXT
// VA: 00501D70 TribeTacticalAIModule::checkForBuildInsertion(int,int,int)
// PDB source: taitacmd.cpp:12391-12497
// FLAGS: config/flags/00501D70_checkForBuildInsertion.rsp (/GX)
// Attempt log:
// - The old source used raw module offsets and a synthetic vtable. It reached
//   the target size but had the wrong frame and broad block layout.
// - Fresh reconstruction uses the same-TU module ownership and named fields.
//   The original switch body order remains a codegen question.
// - Corrected the complete nested layout. buildAI ends at +0x6C4,
//   informationAI starts at +0xCEC, and closestDropsiteValue is at +0x540.
// - The typed source is period-plausible and has no inline assembly or raw
//   module-offset macros. Keep it in scratch for parent-agent promotion.

#ifndef TAITACMD_SHARED_CONTEXT
class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem(int count);
    ResourceItem* next;
    ResourceItem* previous;
    int values[8];
    int sortedValues[8];
    int sortedIndexes[8];
    int numberValue;

    int value(int index);
    void setValue(int index, int value);
};

class TRIBE_Player {
public:
    void objectCost(int objectID, int unused, ResourceItem* item, int unused2);
    int objectAvailable(int objectID);
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class BuildAIModule : public AIModule {
public:
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char gap_F0[0x5C0 - 0xF0];

    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* filename);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* filename);
    virtual int saveState(char* filename);
    virtual int gleanState(int value);
    virtual int processMessage(void* message);
    virtual int update(int value);
    virtual void setCallbackMessage(void* message);
    virtual int filterOutMessage(void* message);
    virtual int save(int value);
    virtual void displayBuildList();
    virtual int loadBuildList(char* filename, void* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int mode);

    int allBuilt(int category, int type);
    int insert(int type, int count, int priority);
};

class TribeResourceAIModule : public AIModule {
public:
    char gap_F0[0x08];
    int resourcesAvailable(ResourceItem* item);
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0x540 - 0x04];
    int closestDropsiteValue[4];
    int closestDropsiteResourceID[4];
    int numberFoundForestTilesValue;
    char gap_564[0x10090 - 0x564];
};

class MainDecisionAIModule : public AIModule {
public:
    void* player;
    char gap_F4[0x10];
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    char gap_6C4[0xCEC - 0x6C4];
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    char gap_10E74[0x1256C - 0x10E74];
    TRIBE_Player* aiPlayer;
};

class TacticalAIModule : public AIModule {
public:
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    char gap_F4[0x32C];
    int strategicNumberA3;
    char gap_424[0xA4];
    int strategicNumber44;
    int strategicNumber32;
    int strategicNumber4F;
    char gap_4D4[0x30];
    int strategicNumberDC;
    char gap_508[0x04];
    int strategicNumberDE;

    int numberAvailableGranaries(int& unbuilt, int& granaries);
    int inAge(int age);
    void checkForBuildInsertion(int type, int count, int priority);
};

#endif
void TribeTacticalAIModule::checkForBuildInsertion(int type, int count, int priority)
{
    switch (type) {
    case 0x32:
        if (this->strategicNumber32 != 1 || this->inAge(4) == 0)
            break;
        {
            ResourceItem itemCost(4);
            for (int i = 0; i < count; ++i)
                itemCost.setValue(i, itemCost.value(i) * count);
            this->md->aiPlayer->objectCost(0x32, -1, &itemCost, 1);
            if (this->md->resourceAI.resourcesAvailable(&itemCost) == 0)
                break;
            if (this->md->aiPlayer->objectAvailable(0x32) == 0)
                break;
            if (this->md->buildAI.allBuilt(0, 0) == 0)
                break;
            if (this->md->buildAI.numberBuiltOrInProgressItemsOfType(0x32, 0) >=
                this->strategicNumberDC)
                break;
            this->md->buildAI.insert(0x32, count, priority);
        }
        break;

    case 0x44:
        if (this->strategicNumber44 != 1)
            break;
        if (this->md->informationAI.closestDropsiteValue[0] == -1)
            break;
        {
            int unbuilt = 0;
            int granaries = 0;
            int available = this->numberAvailableGranaries(unbuilt, granaries);
            if (granaries <= 0 && available > 0 &&
                this->strategicNumberA3 <
                    this->md->informationAI.closestDropsiteValue[0]) {
                this->md->buildAI.insert(0x44, count, priority);
            }
        }
        break;

    case 0x4F:
        if (this->strategicNumber4F != 1)
            break;
        {
            ResourceItem itemCost(4);
            for (int i = 0; i < count; ++i)
                itemCost.setValue(i, itemCost.value(i) * count);
            this->md->aiPlayer->objectCost(0x4F, -1, &itemCost, 1);
            if (this->md->resourceAI.resourcesAvailable(&itemCost) == 0)
                break;
            if (this->md->aiPlayer->objectAvailable(0x4F) == 0)
                break;
            if (this->md->buildAI.allBuilt(0, 0) == 0)
                break;
            if (this->md->buildAI.numberBuiltOrInProgressItemsOfType(0x4F, 0) >=
                this->strategicNumberDE)
                break;
            this->md->buildAI.insert(0x4F, count, priority);
        }
        break;
    }
}
#else
void TribeTacticalAIModule::checkForBuildInsertion(int, int, int) {}
#endif
