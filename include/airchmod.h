#ifndef AOE1_AIRCHMOD_H
#define AOE1_AIRCHMOD_H

#include "aimodule.h"
#include "aitchitm.h"

class MainDecisionAIModule;
class BuildItem;

class ResearchAIModule : public AIModule {
public:
    ResearchAIModule(void* ptr, int arg);
    ResearchAIModule(int file, int arg);
    virtual ~ResearchAIModule();

    MainDecisionAIModule* md;
    TechnologyItem techTree;
    int techTreeLengthValue;
    char techTreeNameValue[260];

    void setMainDecisionAI(MainDecisionAIModule* value);
    virtual int save(int file);
    virtual int buildable(BuildItem* item);
    virtual void research(BuildItem* item);
    int loadTechnologyTree(char* filename);
    ResourceItem* resourceCost(int id);
    int numberTechnologyItems() const;
    char* technologyTreeName();

protected:
    void removeOldTechTree();
    TechnologyItem* item(int id);
};

#endif
