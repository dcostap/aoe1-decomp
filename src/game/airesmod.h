#pragma once
#include "../common.h"

class ResourceAIModule : public AIModule       {
public:
    char _pad_0x4[0xEC];
    MainDecisionAIModule* md;                // 0xF0
    int numberResourcesValue;                // 0xF4
    int* resourceValue;                      // 0xF8
    int* minValue;                           // 0xFC
    int* maxValue;                           // 0x100
    int** resourceTypesValue;                // 0x104
    int* numberResourceTypesValue;           // 0x108

    ResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~ResourceAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 11] Offset 0x2C (Override)
    virtual int processMessage(AIModuleMessage* param_1); // Ghidra: processMessage

    // [Slot 12] Offset 0x30 (Override)
    virtual int update(int param_1); // Ghidra: update

    // [Slot 13] Offset 0x34 (Override)
    virtual void setCallbackMessage(AIModuleMessage* param_1); // Ghidra: setCallbackMessage

    // [Slot 14] Offset 0x38 (Override)
    virtual int filterOutMessage(AIModuleMessage* param_1); // Ghidra: filterOutMessage

    // --- Non-Virtual Members ---
    void setMainDecisionAI(MainDecisionAIModule* param_1);
    int numberResources();
    int resource(int param_1);
    int resourcesAvailable(ResourceItem* param_1);
    int unavailableResource(ResourceItem* param_1);
    int minValueOfResource(int param_1);
    int maxValueOfResource(int param_1);
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
    int lowestResourceType();
};

static_assert(sizeof(ResourceAIModule) == 0x10C, "ResourceAIModule Size Mismatch");
static_assert(offsetof(ResourceAIModule, numberResourceTypesValue) == 0x108, "ResourceAIModule Offset Mismatch");

