// 004E9260 TribeStrategyAIModule::TribeStrategyAIModule
// Attempt log:
// try 1: direct constructor reconstruction with /GX, local layout, helper unique-int insertion compiled too small/out-of-line (.text 784).
// try 2: macro-expanded the three unique-int insertion loops; exact size but broad mismatch, initial EH missing until destructor surfaces added.
// try 3: added nontrivial base/member destructors; EH prologue appeared, first mismatch moved to +47.
// try 4: fixed inherited/base padding from 0xEC to 0xF0; field offsets now align, edit diff improved.
// try 5: made IntArray zeroing occur through initializer-list/inline constructor so zero stores precede VictoryConditionRuleSystem construction like original; first mismatch moved to +54, edit diff ~41.5%, but loop codegen still broad mismatch.
// left in scratch: constructor call set/field offsets/read sequence are mostly modeled, but exact match likely needs true class declarations/initializer list and natural ManagedArray<int>::add/contains implementation rather than local macro loops.

extern "C" void rge_read(int file, void* dst, int size);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern float save_game_version;

class StrategyAIModule { public: StrategyAIModule(int zero, int a); ~StrategyAIModule(); };
class VictoryConditionRuleSystem { public: VictoryConditionRuleSystem(); ~VictoryConditionRuleSystem(); char data[0x38C]; };

struct IntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    IntArray() : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}
};

class TribeStrategyAIModule : public StrategyAIModule {
public:
    char gap_base[0xF0];          // to 0xf0 after vptr/base
    void* md;                    // f0
    int currentVictoryConditionValue; // f4
    char ruleSetNameValue[0x104]; // f8
    int targetIDValue;           // 1fc
    int pad200;
    int secondTargetIDValue;     // 204
    int secondTargetTypeValue;   // 208
    char targetPoint1Value[0x10];// 20c
    char targetPoint2Value[0x10];// 21c
    int targetAttributeValue;    // 22c
    int targetNumberValue;       // 230
    int victoryConditionChangeTimeout; //234
    IntArray vcRuleSet;          //238
    IntArray executingRules;     //248
    IntArray idleRules;          //258
    VictoryConditionRuleSystem vcRules; //268
    int difficultyLevel;         //5f4

    TribeStrategyAIModule(int a, int file);
    int loadRules(char* name);
    void setDifficultyLevel(int level);
};

#define ADD_UNIQUE(ARR, VAL) do { \
    IntArray* a_ = (ARR); \
    int n_ = a_->numberValue; \
    int j_ = 0; \
    int found_ = 0; \
    if (n_ > 0) { \
        do { \
            if (j_ >= a_->maximumSizeValue) break; \
            if (a_->value[j_] == (VAL)) { found_ = 1; break; } \
            ++j_; \
        } while (j_ < n_); \
    } \
    if (!found_) { \
    if (n_ > a_->maximumSizeValue - 1) { \
        int newCap_ = n_ + 1; \
        int* p_ = (int*)operator new(newCap_ * 4); \
        if (p_) { \
            j_ = 0; \
            if (a_->maximumSizeValue > 0) { \
                do { \
                    if (j_ >= newCap_) break; \
                    p_[j_] = a_->value[j_]; \
                    ++j_; \
                } while (j_ < a_->maximumSizeValue); \
            } \
            operator delete(a_->value); \
            a_->value = p_; \
            a_->maximumSizeValue = newCap_; \
        } \
    } \
    a_->value[a_->numberValue] = (VAL); \
    ++a_->numberValue; \
    } \
} while(0)

TribeStrategyAIModule::TribeStrategyAIModule(int a, int file) : StrategyAIModule(0, a), md(0), vcRuleSet(), executingRules(), idleRules(), vcRules()
{
    this->difficultyLevel = 0;

    rge_read(file, &this->currentVictoryConditionValue, 4);
    rge_read(file, &this->targetIDValue, 4);
    rge_read(file, &this->secondTargetIDValue, 4);
    rge_read(file, &this->secondTargetTypeValue, 4);
    rge_read(file, &this->targetPoint1Value, 0x10);
    rge_read(file, &this->targetPoint2Value, 0x10);
    rge_read(file, &this->targetAttributeValue, 4);
    rge_read(file, &this->targetNumberValue, 4);
    rge_read(file, &this->victoryConditionChangeTimeout, 4);
    if (save_game_version >= 1.5f) {
        rge_read(file, &this->difficultyLevel, 4);
    }

    int len;
    rge_read(file, &len, 4);
    rge_read(file, this->ruleSetNameValue, len);
    this->ruleSetNameValue[len] = 0;
    this->loadRules(this->ruleSetNameValue);
    this->setDifficultyLevel(this->difficultyLevel);

    int count, v;
    rge_read(file, &count, 4);
    for (int i = 0; i < count; ++i) {
        rge_read(file, &v, 4);
        ADD_UNIQUE(&this->vcRuleSet, v);
    }
    rge_read(file, &count, 4);
    for (i = 0; i < count; ++i) {
        rge_read(file, &v, 4);
        ADD_UNIQUE(&this->executingRules, v);
    }
    rge_read(file, &count, 4);
    for (i = 0; i < count; ++i) {
        rge_read(file, &v, 4);
        ADD_UNIQUE(&this->idleRules, v);
    }
}
