// 0040B120 ConstructionAIModule::~ConstructionAIModule
// Size: 121 bytes
// FLAGS: /GX (EH frame)

class ConstructionItem {
public:
    ~ConstructionItem();
    char gap_00[0x84];
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class ConstructionAIModule : public AIModule {
public:
    virtual ~ConstructionAIModule();

    void removeOldLots();

    int numberConstructionLotsValue;         // +0xF0
    ConstructionItem constructionLots;        // +0xF4
    ConstructionItem randomConstructionLots;  // +0x178
};

ConstructionAIModule::~ConstructionAIModule() {
    if (this->numberConstructionLotsValue > 0) {
        removeOldLots();
    }
    // Auto-destruction of member objects handles:
    // randomConstructionLots.~ConstructionItem();  // EH state 1
    // constructionLots.~ConstructionItem();        // EH state 0
    // Base destructor handles AIModule::~AIModule() // EH state -1
}
