#pragma once
#include "../common.h"

class ResearchAIModule : public AIModule       {
public:
    char _pad_0x4[0xEC];
    MainDecisionAIModule* md;                // 0xF0
    TechnologyItem techTree;                 // 0xF4
    int techTreeLengthValue;                 // 0x148
    char techTreeNameValue[257];             // 0x14C

    ResearchAIModule(void* param_1, int param_2);
    ResearchAIModule(int param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~ResearchAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // [Slot 15] Offset 0x3C (Override)
    virtual int save(int param_1); // Ghidra: save

    // [Slot 16] Offset 0x40 (Override)
    virtual int buildable(BuildItem* param_1); // Ghidra: buildable

    // [Slot 17] Offset 0x44 (Override)
    virtual void research(BuildItem* param_1); // Ghidra: research

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // --- Non-Virtual Members ---
    void setMainDecisionAI(MainDecisionAIModule* param_1);
    ResourceItem* resourceCost(int param_1);
    int loadTechnologyTree(char* param_1);
    int numberTechnologyItems();
    char* technologyTreeName();
    void removeOldTechTree();
    TechnologyItem* item(int param_1);
};

static_assert(sizeof(ResearchAIModule) == 0x250, "ResearchAIModule Size Mismatch");
static_assert(offsetof(ResearchAIModule, techTreeNameValue) == 0x14C, "ResearchAIModule Offset Mismatch");

