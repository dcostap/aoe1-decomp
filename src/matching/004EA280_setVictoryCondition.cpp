// 004EA280 TribeStrategyAIModule::setVictoryCondition
// taistrmd.cpp
//
// Attempt log:
// baseline: the old scratch used raw offset aliases, a GoalList shim, and
// incomplete ManagedArray declarations. It had the right rough behavior but
// emitted the wrong operator[]/rule-system calls and crossed the boundary.
// canonical reset: model the three +0x238/+0x248/+0x258 arrays with the exact
// utmarray.h method signatures, the +0x268 VictoryConditionRuleSystem surface,
// the +0xF0 main-decision owner, and reuse the incoming v parameter for each
// contains(const int&) call as proven by the original parameter-home stores.
// typed/local-pointer reconstruction reached exact size and 11-byte drift;
// adding the proven decorated operator[] override removed all four relocation
// false positives. A focused four-way store-shape lab found that a local alias
// for currentVictoryConditionValue is the only source spelling in this TU that
// preserves the target's two-instruction scheduler order. A reference alias is
// retained as the readable exact form; it has no extra behavior or calls.

class TRIBE_Player;

#ifndef TAISTRMD_TU_CONTEXT
class TribeMainDecisionAIModule {
public:
    char gap_00[0x1256C];
    TRIBE_Player* aiPlayer;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int contains(const T& valueToFind);
    int resize(int newSize);
    int add(T valueToAdd);
    T& operator[](int index);
};

class VictoryConditionRuleSystem {
public:
    virtual ~VictoryConditionRuleSystem();
    char data[0x388];
    int evaluateAsNonInProgress(TRIBE_Player* player, int rule);
    int execute(TRIBE_Player* player, int state, int command);
};

class TribeStrategyAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;       // +0xF0
    int currentVictoryConditionValue;    // +0xF4
    char gap_F8[0x140];                  // to +0x238
    ManagedArray<int> vcRuleSet;         // +0x238
    ManagedArray<int> executingRules;    // +0x248
    ManagedArray<int> idleRules;         // +0x258
    VictoryConditionRuleSystem vcRules;  // +0x268

    void setVictoryCondition(int v);
};
#endif

#define ADD_REQUIRED(valueToAdd) do { \
    v = (valueToAdd); \
    if (rules->contains(v) != 1) { \
        if (rules->numberValue > rules->maximumSizeValue - 1) \
            rules->resize(rules->numberValue + 1); \
        rules->value[rules->numberValue] = v; \
        rules->numberValue++; \
    } \
} while (0)

void TribeStrategyAIModule::setVictoryCondition(int v)
{
    int& currentReference = this->currentVictoryConditionValue;
    currentReference = v;
    this->vcRuleSet.numberValue = 0;

    v = 1;
    if (this->vcRuleSet.contains(v) != 1) {
        ManagedArray<int>* firstRules = &this->vcRuleSet;
        if (firstRules->numberValue > firstRules->maximumSizeValue - 1)
            firstRules->resize(firstRules->numberValue + 1);
        firstRules->value[firstRules->numberValue] = v;
        firstRules->numberValue++;
    }

    ManagedArray<int>* rules = &this->vcRuleSet;
    ADD_REQUIRED(2);
    ADD_REQUIRED(0x0C);
    ADD_REQUIRED(0x0D);
    ADD_REQUIRED(0x0E);
    ADD_REQUIRED(0x10);
    ADD_REQUIRED(0x11);
    ADD_REQUIRED(0x12);
    ADD_REQUIRED(0x15);
    ADD_REQUIRED(0x16);
    ADD_REQUIRED(0x17);
    ADD_REQUIRED(0x18);
    ADD_REQUIRED(0x19);

    rules->add(0x1A);
    rules->add(0x1B);
    rules->add(0x1C);
    rules->add(0x1D);
    rules->add(0x1E);
    rules->add(0x1F);
    rules->add(0x20);
    rules->add(0x21);
    rules->add(0x22);
    rules->add(0x23);
    rules->add(0x24);
    rules->add(0x25);
    rules->add(0x26);
    rules->add(0x27);
    rules->add(0x28);
    rules->add(0x29);
    rules->add(0x2A);
    rules->add(0x2B);
    rules->add(0x2C);
    rules->add(0x2D);
    rules->add(0x2E);
    rules->add(0x2F);
    rules->add(0x30);
    rules->add(0x31);

    int i = 0;
    if (this->vcRuleSet.numberValue > 0) {
        do {
            if (this->vcRules.evaluateAsNonInProgress(
                    this->md->aiPlayer, (*rules)[i]) == -2) {
                if (this->vcRules.execute(
                        this->md->aiPlayer,
                        this->currentVictoryConditionValue,
                        (*rules)[i]) == 1) {
                    this->executingRules.add((*rules)[i]);
                } else {
                    this->idleRules.add((*rules)[i]);
                }
            }
            ++i;
        } while (i < this->vcRuleSet.numberValue);
    }
}
