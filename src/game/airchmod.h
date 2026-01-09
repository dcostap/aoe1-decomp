#pragma once
#include "common.h"

class ResearchAIModule : public AIModule {
public:
    MainDecisionAIModule* md;                // 0xF0
    TechnologyItem techTree;                 // 0xF4
    int techTreeLengthValue;                 // 0x148
    char techTreeNameValue[257];             // 0x14C

    virtual int save(int param_1);                          // vt0[15]+0x3C=0x4119C0
    virtual int buildable(BuildItem* param_1);              // vt0[16]+0x40=0x411B60
    virtual void research(BuildItem* param_1);              // vt0[17]+0x44=0x411B70
    ResearchAIModule(void* param_1, int param_2);
    ResearchAIModule(int param_1, int param_2);
    ~ResearchAIModule();
    void setMainDecisionAI(MainDecisionAIModule* param_1);
    ResourceItem* resourceCost(int param_1);
    int loadTechnologyTree(char* param_1);
    int numberTechnologyItems();
    char* technologyTreeName();
    void removeOldTechTree();
    TechnologyItem* item(int param_1);
};

static_assert(sizeof(ResearchAIModule) == 0x250, "ResearchAIModule Size Mismatch");

