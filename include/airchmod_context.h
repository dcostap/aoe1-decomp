#ifndef AOE1_AIRCHMOD_CONTEXT_H
#define AOE1_AIRCHMOD_CONTEXT_H

#include "aitchitm.h"

class MainDecisionAIModule;
class BuildItem;

class AIModule {
public:
    AIModule(char* name, int line, int arg, void* ptr);
    virtual ~AIModule();
    void __cdecl logCommonHistory(char*, ...);

    char gap[0xEC];
};

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

void rge_write(int file, void* data, int size);

#endif
