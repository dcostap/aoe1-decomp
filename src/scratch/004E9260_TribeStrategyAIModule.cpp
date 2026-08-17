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
// scoped the name-length local through loadRules only; VC5 shrank the frame to
// 0xC and worsened the mismatch to 19 bytes, so this lifetime variant was
// restored. The unresolved lead remains the original parameter-home hunk.
// continuation: a local serialized value plus parameter-home name/loop reads
// reached the same 7-byte basin; an address-taken value pointer was a codegen
// duplicate. A four-way /GX variant lab confirmed the local-name form is the
// best invariant-preserving source; parameter-name forms either lose the frame
// slot or retain the same later drift. Restored this clean typed source.
// this session: parameter-home length/value reuse plus one named serialized
// value local fell to a 0xC frame and the prior 20-byte basin; restored.
// moving count/index declarations to function entry, then declaring length
// with them, produced the same 7-byte codegen and no new stack layout.
// a declaration-order lab produced only the known 11-byte and 20-byte groups;
// a debug-context flag lab lacked the EH frame and was not a valid lead.
// left in scratch: clean typed constructor remains 7 bytes off in seven
// stack-home displacement bytes at the length and add-value temporary sites.
// explicit function-level value local reached a 4-byte diff and exact loop
// bodies, but moved the base self-home and name-length homes by one word.
// loop-scoped value locals were a codegen duplicate of the clean source.
// a two-element value-buffer diagnostic reached 2 bytes but changed the
// base self-home and one indexed name terminator byte; it was not plausible.
// new focused labs: combined /GX with /Zd, /Zi, and /Z7; varied the indexed
// terminator spelling; all produced the same two-byte aggregate candidate.
// Moving ManagedArray::add outside the class, changing its inline spelling,
// reducing the base virtual surface, adding likely CRT headers, moving local
// declarations, and using pointer/reference self aliases did not fix the home.
// Pair structs behave like int[2]; scalar chains collapse to the 0xC frame.
// Risky VC5 optimization flags produced no exact invariant-preserving group.
// The remaining fact is one uncolored frame word: natural parameter reuse has
// the correct physical hidden-self home but a 0xC frame, while an 8-byte value
// aggregate restores 0x10 and moves that hidden home to the loop-index slot.
// final unresolved pass: 20 meaningful probes retained this clean source at
// 4 differing displacement bytes, with 28 calls, size, and 0x10 frame exact.
// BINARY NOTE: the original reads the name length and each rule value through
// the entry +4 constructor-parameter home. Direct parameter reuse loses one
// frame word and gives a 20-byte mismatch. Local-name, type, scope, header,
// ambient-declaration, and flag probes found no exact source basin.
// LIKELY INTENT: the shipped source reused parameter a as a wire temporary;
// the clean local form remains the smallest period-plausible source here.
// Object audit: original and current FPO, 0x10 frame, calls, EH metadata, ABI,
// compiler, and boundaries match. PDB has no block, inline, or range records
// beyond its named reused homes. No object evidence supports an alias for the
// remaining four stack displacements.

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

    int value;
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
        value = a;
        this->vcRuleSet.add(value);
    }
    rge_read(file, &count, 4);
    for (i = 0; i < count; ++i) {
        rge_read(file, &a, 4);
        value = a;
        this->executingRules.add(value);
    }
    rge_read(file, &count, 4);
    for (i = 0; i < count; ++i) {
        rge_read(file, &a, 4);
        value = a;
        this->idleRules.add(value);
    }
}
