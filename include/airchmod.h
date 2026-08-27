#ifndef AOE1_AIRCHMOD_H
#define AOE1_AIRCHMOD_H

#include "aitchitm.h"

class MainDecisionAIModule;
class BuildItem;
class AIModuleMessage;

class AIModule {
public:
    virtual ~AIModule();

    // Keep the inherited slots in the original order.  The executable puts
    // ResearchAIModule::save after these slots, not after the destructor.
    virtual int loggingHistory() const;
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory() const;
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);

    AIModule(char* name, int line, int arg, void* ptr);
    void __cdecl logCommonHistory(char*, ...);

protected:
    virtual int filterOutMessage(AIModuleMessage*);

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

#endif
