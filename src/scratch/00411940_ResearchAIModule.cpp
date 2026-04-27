// attempt 1: EH-framed ResearchAIModule destructor with explicit vptr store, tech-tree guard, member destructor, and base dtor call
// blocker watch: the target is a tiny EH helper; current mismatch is a bad EH/prolog basin with the techTreeLength load drifting to the wrong offset and an extra saved-register shape, so this is paused in scratch
#include "..\..\include\game_types.h"

class ResourceItem;
class MainDecisionAIModule;

class AIModuleID {
public:
    void* vtable_ptr;
    int id;
    char name[64];
};

class AIModule {
public:
    void* vtable_ptr;
    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;

    virtual ~AIModule();
};

class TechnologyItem {
public:
    void* vtable_ptr;
    TechnologyItem* next;
    TechnologyItem* prev;
    int idValue;
    char nameValue[64];
    ResourceItem* resourceCostValue;

    ~TechnologyItem();
};

class ResearchAIModule : public AIModule {
public:
    MainDecisionAIModule* md;
    TechnologyItem techTree;
    int techTreeLengthValue;
    char techTreeNameValue[257];

    ~ResearchAIModule();
    void removeOldTechTree();
};

ResearchAIModule::~ResearchAIModule() {
    *(void**)this = (void*)0x56E988;
    if (this->techTreeLengthValue > 0) {
        this->removeOldTechTree();
    }
    this->techTree.~TechnologyItem();
}
