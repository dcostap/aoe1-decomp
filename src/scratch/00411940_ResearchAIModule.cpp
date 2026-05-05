// 00411940 ResearchAIModule::~ResearchAIModule
// Source: airchmod.cpp lines 80-83
// Size: 105 bytes, 26 asm lines

// EH-framed destructor. Field offsets fixed: removed explicit `void* vtable_ptr`
// from AIModule (let virtual ~AIModule() add it implicitly) — this made
// AIModule 0xF0 bytes and techTree at +0xF4 (matching original).
//
// Remaining diff (58%): same EH codegen basin as load_victory/setup_gaia.
// VC5 generates extra push edi (for techTree ptr), try level at [esp+14h]
// vs [esp+10h], vtable store scheduled after load (before in original).
// Behavioral match, size match.

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
    *(void**)this = (void*)0x56E988;
    if (this->techTreeLengthValue > 0) {
        this->removeOldTechTree();
    }
    this->techTree.~TechnologyItem();
}
