// 004E9260 TribeStrategyAIModule::TribeStrategyAIModule
// taistrmd.cpp
//
// Attempt log:
// baseline reset: canonical StrategyAIModule(void*,int) ABI, virtual derived
// construction, real ManagedArray<int> members, and the period inline add
// implementation. Earlier work used an int-typed base shim and a macro-expanded
// duplicate scan; those produced the wrong constructor relocation and a
// pointer-walk/boolean CFG rather than the donor's indexed ManagedArray scan.
// parameter-home probe: reusing the dead first constructor parameter for the
// serialized name length and rule values reduced the mismatch from 31 bytes to
// 7 bytes and aligned all three indexed add loops.
// frame probes: explicit/scoped value locals, top-of-function declarations,
// address-taken aliases, and an explicit self pointer all collapsed back to a
// 0xC frame and a 20-byte displacement-only drift; these were diagnostic and
// were rolled back.
// left in scratch: best canonical source is the parameter-home/ManagedArray
// reconstruction (7 bytes, 0x10 frame). Remaining drift is the original
// compiler's one-word local-frame reservation around the name-length home.
// same-TU context check: the full AIModule/StrategyAIModule virtual surface
// was added from the class reference. It was a codegen duplicate and is kept
// as the period-plausible declaration context.
// this session: reconfirmed the typed constructor and stack map. The remaining
// seven bytes are local-home displacements at the serialized name/value phase;
// prior parameter-home and liveness basins remain worse at 20 bytes.
// direct reuse of the first parameter for the name length was tested from the
// dossier's entry-relative +4 address evidence; it removed the one-word frame
// reservation and worsened the result to 20 bytes, so the clean local remains.

extern "C" void __cdecl rge_read(int file, void* dst, int size);
extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* pointer);
extern float save_game_version;
extern float DAT_00575690;

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* filename);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* filename);
    virtual int saveState(char* filename);
    virtual int gleanState(int value);
    virtual int processMessage(void* message);
    virtual int update(int parameter);
    virtual void setCallbackMessage(void* message);
    virtual int filterOutMessage(void* message);
    AIModule(char* name, int id, int parameter, void* object);
};

class StrategyAIModule : public AIModule {
public:
    StrategyAIModule(void* object, int parameter);
    virtual ~StrategyAIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* filename);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* filename);
    virtual int saveState(char* filename);
    virtual int gleanState(int value);
    virtual int processMessage(void* message);
    virtual int update(int parameter);
    virtual void setCallbackMessage(void* message);
    virtual int filterOutMessage(void* message);
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0)
    {
    }

    ~ManagedArray() {
        if (this->value != 0) {
            operator_delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }

    int add(T valueToAdd) {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == valueToAdd)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int newSize = this->numberValue + 1;
            T* newValue = (T*)operator_new(newSize * sizeof(T));
            if (newValue != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= newSize)
                        break;
                    newValue[j] = this->value[j];
                }
                operator_delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }

        this->value[this->numberValue] = valueToAdd;
        this->numberValue++;
        return 1;
    }
};

class VictoryConditionRuleSystem {
public:
    virtual ~VictoryConditionRuleSystem();
    VictoryConditionRuleSystem();
    char data[0x388];
};

struct WaypointBytes {
    char data[0x10];
};

class TribeStrategyAIModule : public StrategyAIModule {
public:
    char gap_base[0xEC];
    void* md;                          // +0xF0
    int currentVictoryConditionValue;  // +0xF4
    char ruleSetNameValue[0x101];      // +0xF8
    unsigned char ruleSetNamePadding[3];
    int targetIDValue;                 // +0x1FC
    int targetTypeValue;               // +0x200
    int secondTargetIDValue;           // +0x204
    int secondTargetTypeValue;         // +0x208
    WaypointBytes targetPoint1Value;   // +0x20C
    WaypointBytes targetPoint2Value;   // +0x21C
    int targetAttributeValue;          // +0x22C
    int targetNumberValue;             // +0x230
    int victoryConditionChangeTimeout; // +0x234
    ManagedArray<int> vcRuleSet;       // +0x238
    ManagedArray<int> executingRules;  // +0x248
    ManagedArray<int> idleRules;       // +0x258
    VictoryConditionRuleSystem vcRules;// +0x268
    int difficultyLevel;               // +0x5F4

    virtual ~TribeStrategyAIModule();
    TribeStrategyAIModule(int a, int file);
    int loadRules(char* name);
    void setDifficultyLevel(int level);
};

TribeStrategyAIModule::TribeStrategyAIModule(int a, int file)
    : StrategyAIModule((void*)0, a),
      md(0),
      vcRuleSet(),
      executingRules(),
      idleRules(),
      vcRules(),
      difficultyLevel(0)
{
    rge_read(file, &this->currentVictoryConditionValue, 4);
    rge_read(file, &this->targetIDValue, 4);
    rge_read(file, &this->secondTargetIDValue, 4);
    rge_read(file, &this->secondTargetTypeValue, 4);
    rge_read(file, &this->targetPoint1Value, 0x10);
    rge_read(file, &this->targetPoint2Value, 0x10);
    rge_read(file, &this->targetAttributeValue, 4);
    rge_read(file, &this->targetNumberValue, 4);
    rge_read(file, &this->victoryConditionChangeTimeout, 4);
    if (save_game_version >= DAT_00575690) {
        rge_read(file, &this->difficultyLevel, 4);
    }

    int length;
    rge_read(file, &length, 4);
    rge_read(file, this->ruleSetNameValue, length);
    this->ruleSetNameValue[length] = 0;
    this->loadRules(this->ruleSetNameValue);
    this->setDifficultyLevel(this->difficultyLevel);

    int count;
    int i;
    rge_read(file, &count, 4);
    for (i = 0; i < count; ++i) {
        rge_read(file, &a, 4);
        this->vcRuleSet.add(a);
    }
    rge_read(file, &count, 4);
    for (i = 0; i < count; ++i) {
        rge_read(file, &a, 4);
        this->executingRules.add(a);
    }
    rge_read(file, &count, 4);
    for (i = 0; i < count; ++i) {
        rge_read(file, &a, 4);
        this->idleRules.add(a);
    }
}
