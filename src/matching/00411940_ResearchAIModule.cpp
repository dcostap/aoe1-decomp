// 00411940 ResearchAIModule::~ResearchAIModule
// Source: airchmod.cpp lines 80-83
// Size: 105 bytes, 26 asm lines

// MATCHED: use the natural destructor body only. Let VC5 emit the derived vtable
// restore, member TechnologyItem destructor, and AIModule base destructor. Manual
// vtable stores or explicit member destructor calls force extra EDI/save and/or
// duplicate destructor calls, shifting EH state slots.
// Field offsets fixed: removed explicit `void* vtable_ptr` from AIModule (let
// virtual ~AIModule() add it implicitly), giving AIModule size 0xF0 and techTree
// at +0xF4.

class ResourceItem {};
class MainDecisionAIModule {};

class AIModuleID {
public:
    void* vtable_ptr;
    int id;
    char name[64];
};

class AIModule {
public:
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
    if (this->techTreeLengthValue > 0) {
        this->removeOldTechTree();
    }
}
