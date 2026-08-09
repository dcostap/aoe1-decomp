// VA: 004E9100 TribeStrategyAIModule constructor (315B)
// taistrmd.cpp
// EH frame (/GX)
//
// Attempt log:
// baseline reconstruction: period-plausible derived constructor with the
// proven StrategyAIModule base, three ManagedArray-like members, the
// VictoryConditionRuleSystem member, and named Waypoint fields (214-byte
// mismatch; array/member construction was initially modeled in the body).
// tried default-constructing the three destructible arrays and ordering their
// initializers after the scalar fields; mismatch fell to 7 bytes and the
// original call/frame topology aligned.
// moved difficultyLevel(0) into the member-initializer sequence; this placed
// the derived vptr store after the difficulty store and matched exactly.

extern "C" char* __cdecl strcpy(char* destination, const char* source);
void __cdecl operator delete(void* pointer);

class AIModule {
public:
    virtual ~AIModule();
    AIModule(char* name, int id, int parameter, void* object);
};

class StrategyAIModule : public AIModule {
public:
    StrategyAIModule(void* object, int parameter);
};

struct IntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    IntArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0)
    {
    }

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

class VictoryConditionRuleSystem {
public:
    virtual ~VictoryConditionRuleSystem();
    VictoryConditionRuleSystem();
    char data[0x388];
};

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char padding[3];
};

class TribeStrategyAIModule : public StrategyAIModule {
public:
    char gap_base[0xEC];
    void* md;
    int currentVictoryConditionValue;
    char ruleSetNameValue[0x101];
    unsigned char ruleSetNamePadding[3];
    int targetIDValue;
    int targetTypeValue;
    int secondTargetIDValue;
    int secondTargetTypeValue;
    Waypoint targetPoint1Value;
    Waypoint targetPoint2Value;
    int targetAttributeValue;
    int targetNumberValue;
    int victoryConditionChangeTimeout;
    IntArray vcRuleSet;
    IntArray executingRules;
    IntArray idleRules;
    VictoryConditionRuleSystem vcRules;
    int difficultyLevel;

    virtual ~TribeStrategyAIModule();
    TribeStrategyAIModule(void* object, int parameter);
};

TribeStrategyAIModule::TribeStrategyAIModule(void* object, int parameter)
    : StrategyAIModule(object, parameter),
      md(0),
      currentVictoryConditionValue(-1),
      targetIDValue(-1),
      targetTypeValue(-1),
      secondTargetIDValue(-1),
      secondTargetTypeValue(-1),
      targetAttributeValue(-1),
      targetNumberValue(-1),
      victoryConditionChangeTimeout(0),
      vcRuleSet(),
      executingRules(),
      idleRules(),
      vcRules(),
      difficultyLevel(0)
{
    this->targetPoint1Value.x = -1.0f;
    this->targetPoint1Value.y = -1.0f;
    this->targetPoint1Value.z = -1.0f;
    this->targetPoint2Value.x = -1.0f;
    this->targetPoint2Value.y = -1.0f;
    this->targetPoint2Value.z = -1.0f;
    strcpy(this->ruleSetNameValue, "");
}
