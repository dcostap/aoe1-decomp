// VA: 004E9730 ~TribeStrategyAIModule (232B)
// taistrmd.cpp
// EH frame (/GX)
//
// Attempt log:
// (baseline) Natural virtual-destructor surface: real StrategyAIModule base
//   (vptr-only, virtual dtor), VictoryConditionRuleSystem member with virtual
//   dtor, and three IntArray members with inline delete+zero dtors. Empty
//   derived dtor body; VC5 auto-restores the TribeStrategyAIModule vftable,
//   destroys vcRules/idleRules/executingRules/vcRuleSet in reverse
//   declaration order (EH states 3/2/1/0), then calls ~StrategyAIModule.

void __cdecl operator delete(void* ptr);

#ifndef TAISTRMD_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
};

class StrategyAIModule : public AIModule {
public:
    virtual ~StrategyAIModule();
};

class VictoryConditionRuleSystem {
public:
    virtual ~VictoryConditionRuleSystem();
};

struct IntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    ~IntArray() {
        if (this->value != 0) {
            operator delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }
};

class TribeStrategyAIModule : public StrategyAIModule {
public:
    char gap_base[0xEC];               // +0x04 to +0xEF
    void* md;                          // +0xF0
    int currentVictoryConditionValue;  // +0xF4
    char ruleSetNameValue[0x104];      // +0xF8
    int targetIDValue;                 // +0x1FC
    int pad200;                        // +0x200
    int secondTargetIDValue;           // +0x204
    int secondTargetTypeValue;         // +0x208
    char targetPoint1Value[0x10];      // +0x20C
    char targetPoint2Value[0x10];      // +0x21C
    int targetAttributeValue;          // +0x22C
    int targetNumberValue;             // +0x230
    int victoryConditionChangeTimeout; // +0x234
    IntArray vcRuleSet;                // +0x238
    IntArray executingRules;           // +0x248
    IntArray idleRules;                // +0x258
    VictoryConditionRuleSystem vcRules; // +0x268
    char gap_26C[0x388];               // +0x26C to +0x5F3
    int difficultyLevel;               // +0x5F4

    virtual ~TribeStrategyAIModule();
};
#endif

TribeStrategyAIModule::~TribeStrategyAIModule() {
    // vptr restored, members and base destroyed automatically by VC5
}
