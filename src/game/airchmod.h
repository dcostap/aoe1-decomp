#pragma once
#include "../common.h"

class ResearchAIModule : public AIModule {
public:
    MainDecisionAIModule* md;                // 0xF0
    TechnologyItem techTree;                 // 0xF4
    int techTreeLengthValue;                 // 0x148
    char techTreeNameValue[257];             // 0x14C

    ResearchAIModule(void* param_1, int param_2);
    ResearchAIModule(int param_1, int param_2);
    virtual ~ResearchAIModule();
    virtual void setMainDecisionAI(MainDecisionAIModule* param_1);
    virtual int save(int param_1);
    virtual ResourceItem* resourceCost(int param_1);
    virtual int buildable(BuildItem* param_1);
    virtual void research(BuildItem* param_1);
    virtual int loadTechnologyTree(char* param_1);
    virtual int numberTechnologyItems();
    virtual char* technologyTreeName();
    virtual void removeOldTechTree();
    virtual TechnologyItem* item(int param_1);
};

static_assert(sizeof(ResearchAIModule) == 0x250, "ResearchAIModule Size Mismatch");
static_assert(offsetof(ResearchAIModule, techTreeNameValue) == 0x14C, "ResearchAIModule Offset Mismatch");

