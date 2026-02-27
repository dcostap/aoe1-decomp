#pragma once
#include "common.h"

class ResourceItem;

class ResourceAIModule {
public:
    ResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);

    // Virtuals (best-effort)
    virtual ~ResourceAIModule(); // vt[0] (0x0)
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

    void setMainDecisionAI(MainDecisionAIModule* param_1);
    int numberResources() const;
    int resource(int param_1) const;
    int resourcesAvailable(ResourceItem* param_1);
    int unavailableResource(ResourceItem* param_1);
    int minValueOfResource(int param_1) const;
    int maxValueOfResource(int param_1) const;
    void setResource(int param_1, int param_2);
    void setResources(ResourceItem* param_1);
    void incrementResource(int param_1, int param_2);
    void incrementResources(ResourceItem* param_1);
    void decrementResource(int param_1, int param_2);
    void decrementResources(ResourceItem* param_1);
    void setResourceMin(int param_1, int param_2);
    void setResourceMax(int param_1, int param_2);
    void addResourceType(int param_1, int param_2);
    int isResourceType(int param_1, int param_2);
    int numberResourceTypes(int param_1);
    int lowestResourceType() const;

    int padding0;
    int padding1;
    int padding2;
    int padding3;
    int padding4;
    int padding5;
    int padding6;
    int padding7;
    int padding8;
    int padding9;
    int padding10;
    int padding11;
    int padding12;
    int padding13;
    int padding14;
    int padding15;
    int padding16;
    int padding17;
    int padding18;
    int padding19;
    int padding20;
    int padding21;
    int padding22;
    int padding23;
    int padding24;
    int padding25;
    int padding26;
    int padding27;
    int padding28;
    int padding29;
    int padding30;
    int padding31;
    int padding32;
    int padding33;
    int padding34;
    int padding35;
    int padding36;
    int padding37;
    int padding38;
    int padding39;
    int padding40;
    int padding41;
    int padding42;
    int padding43;
    int padding44;
    int padding45;
    int padding46;
    int padding47;
    int padding48;
    int padding49;
    int padding50;
    int padding51;
    int padding52;
    int padding53;
    int padding54;
    int padding55;
    int padding56;
    int padding57;
    int padding58;
    MainDecisionAIModule* md;
    int numberResourcesValue;
    int* resourceValue;
    int* minValue;
    int* maxValue;
    int** resourceTypesValue;
    int* numberResourceTypesValue;
};
static_assert(sizeof(ResourceAIModule) == 0x10C, "Size mismatch");
