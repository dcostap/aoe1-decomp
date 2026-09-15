#ifndef AOE1_AIRCHMOD_H
#define AOE1_AIRCHMOD_H

#include "aimodule.h"
#include "aitchitm.h"

class MainDecisionAIModule;
class BuildItem;

class ResearchAIModule : public AIModule {
public:
    ResearchAIModule(void* pW, int playerID);
    ResearchAIModule(int playerID, int infile);
    virtual ~ResearchAIModule();

    MainDecisionAIModule* md;
    TechnologyItem techTree;
    int techTreeLengthValue;
    char techTreeNameValue[260];

    void setMainDecisionAI(MainDecisionAIModule* m);
    virtual int save(int outfile);
    virtual int buildable(BuildItem* bi);
    virtual void research(BuildItem* bi);
    int loadTechnologyTree(char* lName);
    ResourceItem* resourceCost(int id);
    int numberTechnologyItems() const;
    char* technologyTreeName();

protected:
    void removeOldTechTree();
    TechnologyItem* item(int id);
};

#endif
