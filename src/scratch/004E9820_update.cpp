// VA: 004E9820 TribeStrategyAIModule::update (1391B)
// taistrmd.cpp
//
// Attempt log:
// baseline reset: replaced the placeholder helper-shaped source with the
// binary-backed strategy module, victory-entry ownership, three ManagedArray
// members, and the exact rule-system call surface. The first baseline tests
// the natural source family shown by the PDB and decompiler.
// corrected the victory-entry fields to their proven +0x0C..+0x28 layout;
// this recovered the target field access schedule without changing calls.
// Added the full period AI virtual surface as a TU-context check; it was a
// codegen duplicate and remains because it is the canonical class context.
// Replaced four manual growth copies with the matched ManagedArray operator[]
// form. This reduced the body from 1539 to 1469 bytes and improved structural
// coverage from 24.65% to 51.63%; the 20-call sequence stayed exact.
// Declaration initialization of the zero loop index was a duplicate. The
// remaining structural gap starts at the entry zero-index scheduling and is
// 78 bytes beyond the original boundary; no register-only tuning is justified.
// claim shardA4-4E9820-r1: corrected the typed main-decision ownership so rule
// evaluation uses md->aiPlayer at +0x1256C, while victory lookup keeps md->player.
// This preserved the call set and improved exact-block coverage from 51.63% to 58.60%.
// moved the natural zero iterator assignment before timeout polling and exposed
// the idle score accumulator before its action loop; size fell by 5 bytes.
// spelled the first idle count and capacity predicates in iterator order; the
// capacity compare moved to the original instruction shape with no size change.
// used the idle result directly for the action execute tail; this removed the
// redundant result copy, reduced the body to 1463 bytes, and reached 1165 diff bytes.
// scoped the score local before the array alias as a diagnostic variant; rolled it
// back because it reached 1189 diff bytes. Best source keeps the typed result tail.
// shardA6 probe lead: keep the final rule-set state behind the same typed array
// alias used by the strategy loops, so operator[] and the follow-up execute call
// share one source-level owner.
// shardA6 result: the typed final rule-set alias was a codegen duplicate; restored
// the direct state spelling because it did not move the first structural hunk.
// luna-r2 probe: collapsed second-phase selected-rule aliases to one typed rule;
// stack-slot evidence supported it, but positional diff worsened 1144 -> 1171,
// so restored the clean source.

extern void* __cdecl operator new(unsigned int size);
extern void __cdecl operator delete(void* pointer);

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x4];
    int id;
    RGE_Master_Static_Object* master_obj;
};

class RGE_Player;

class RGE_Victory_Entry {
public:
    unsigned char command;
    char gap_01[0x3];
    int obj_type;
    RGE_Player* target_player;
    float x0;
    float y0;
    float x1;
    float y1;
    int number;
    int count;
    RGE_Static_Object* this_obj;
    RGE_Static_Object* target_obj;
};

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* condition_raw_info(int index);
};

class RGE_Player {
public:
    char gap_00[0x34];
    RGE_Victory_Conditions* victory_conditions;
};

class TRIBE_Player : public RGE_Player {
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    TRIBE_Player* player;
    char gap_F4[0x12478];
    TRIBE_Player* aiPlayer;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int resize(int newSize);

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            T* newValue = (T*)operator new(newSize * 4);
            if (newValue != 0) {
                int j;
                for (j = 0;
                     j < this->maximumSizeValue && j < newSize;
                     ++j) {
                    newValue[j] = this->value[j];
                }
                operator delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }
        return this->value[index];
    }
};

class VictoryConditionRuleSystem {
public:
    virtual ~VictoryConditionRuleSystem();
    char data[0x388];

    int evaluateAsNonInProgress(TRIBE_Player* player, int rule);
    int evaluateAsInProgress(TRIBE_Player* player, int rule);
    int execute(TRIBE_Player* player, int state, int rule);
    int stopExecution(TRIBE_Player* player, int rule);
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class StrategyAIModule : public AIModule {
public:
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

class TribeStrategyAIModule : public StrategyAIModule {
public:
    TribeMainDecisionAIModule* md;
    int currentVictoryConditionValue;
    char ruleSetNameValue[0x104];
    int targetIDValue;
    int targetTypeValue;
    int secondTargetIDValue;
    int secondTargetTypeValue;
    float targetPoint1_x;
    float targetPoint1_y;
    float targetPoint1_z;
    char targetPoint1_facet;
    char targetPoint1_gap[3];
    float targetPoint2_x;
    float targetPoint2_y;
    float targetPoint2_z;
    char targetPoint2_facet;
    char targetPoint2_gap[3];
    int targetAttributeValue;
    int targetNumberValue;
    int victoryConditionChangeTimeout;
    ManagedArray<int> vcRuleSet;
    ManagedArray<int> executingRules;
    ManagedArray<int> idleRules;
    VictoryConditionRuleSystem vcRules;

    virtual int update(int parameter);
    void setVictoryCondition(int value);
};

int TribeStrategyAIModule::update(int parameter)
{
    int i;
    int result;
    int bestResult;
    int worstRuleResult;
    int ruleResult;
    int rule;
    int* newValue;
    int j;
    RGE_Victory_Entry* victoryEntry;
    unsigned int victoryCondition;

    i = 0;
    this->victoryConditionChangeTimeout++;
    if (this->victoryConditionChangeTimeout >= 0) {
        this->victoryConditionChangeTimeout = i;
        victoryCondition = 0x0B;
        victoryEntry = this->md->player->victory_conditions->condition_raw_info(i);
        if (victoryEntry != 0) {
            victoryCondition = victoryEntry->command;
            if (victoryEntry->target_obj != 0) {
                this->targetIDValue = victoryEntry->target_obj->id;
                this->targetTypeValue = victoryEntry->target_obj->master_obj->id;
            }
            if (victoryEntry->this_obj != 0) {
                this->secondTargetIDValue = victoryEntry->this_obj->id;
                this->secondTargetTypeValue = victoryEntry->this_obj->master_obj->id;
            }
            this->targetPoint1_x = victoryEntry->x0;
            this->targetPoint1_y = victoryEntry->y0;
            this->targetPoint1_z = 1.0f;
            this->targetPoint2_x = victoryEntry->x1;
            this->targetPoint2_y = victoryEntry->y1;
            this->targetPoint2_z = 1.0f;
            this->targetAttributeValue = victoryEntry->number;
            this->targetNumberValue = victoryEntry->count;
        }
        if (victoryCondition != (unsigned int)this->currentVictoryConditionValue) {
            this->setVictoryCondition(victoryCondition);
        }
    }

    result = -1;
    bestResult = 0;
    worstRuleResult = -1;
    if (this->idleRules.numberValue > i) {
        ManagedArray<int>* idleRules = &this->idleRules;
        do {
            if (i > this->idleRules.maximumSizeValue - 1) {
                idleRules->resize(i + 1);
            }
            ruleResult = this->vcRules.evaluateAsNonInProgress(
                this->md->aiPlayer,
                idleRules->value[i]);
            if (bestResult < ruleResult) {
                result = (*idleRules)[i];
                bestResult = ruleResult;
            }
            ++i;
        } while (i < this->idleRules.numberValue);
    }

    if (result != -1 &&
        this->vcRules.execute(
            this->md->aiPlayer,
            this->currentVictoryConditionValue,
            result) == 1) {
        int executingCount = this->executingRules.numberValue;
        ManagedArray<int>* executingRules = &this->executingRules;
        i = 0;
        if (executingCount > 0) {
            do {
                if (this->executingRules.maximumSizeValue <= i) {
                    break;
                }
                if (executingRules->value[i] == result) {
                    goto remove_idle_rule;
                }
                ++i;
            } while (i < executingCount);
        }
        if (this->executingRules.maximumSizeValue - 1 < executingCount) {
            executingRules->resize(executingCount + 1);
        }
        executingRules->value[this->executingRules.numberValue] = result;
        this->executingRules.numberValue++;

remove_idle_rule:
        int idleCount = this->idleRules.maximumSizeValue;
        i = 0;
        if (idleCount > 0) {
            int* idleValue = this->idleRules.value;
            do {
                if (*idleValue == result) {
                    break;
                }
                ++i;
                ++idleValue;
            } while (i < idleCount);
        }
        if (i < idleCount) {
            if (i < idleCount - 1) {
                do {
                    int* currentValue = this->idleRules.value;
                    int nextIndex = i + 1;
                    currentValue[i] = currentValue[nextIndex];
                    i = nextIndex;
                } while (i < this->idleRules.maximumSizeValue - 1);
            }
            this->idleRules.numberValue--;
            if (this->idleRules.numberValue < 0) {
                this->idleRules.numberValue = 0;
            }
        }
    }

    i = 0;
    int bestExecutingRule = -1;
    result = 0x65;
    worstRuleResult = -1;
    if (this->executingRules.numberValue > 0) {
        ManagedArray<int>* executingRules = &this->executingRules;
        do {
            ruleResult = this->vcRules.evaluateAsInProgress(
                this->md->aiPlayer,
                (*executingRules)[i]);
            if (ruleResult < result) {
                if (this->executingRules.maximumSizeValue - 1 < i) {
                    executingRules->resize(i + 1);
                }
                bestExecutingRule = executingRules->value[i];
                result = ruleResult;
            }
            ++i;
            worstRuleResult = bestExecutingRule;
        } while (i < this->executingRules.numberValue);
    }

    if (worstRuleResult != -1 &&
        this->vcRules.stopExecution(this->md->aiPlayer, worstRuleResult) == 1) {
        int executingSize = this->executingRules.maximumSizeValue;
        i = 0;
        if (executingSize > 0) {
            int* executingValue = this->executingRules.value;
            do {
                if (*executingValue == worstRuleResult) {
                    break;
                }
                ++i;
                ++executingValue;
            } while (i < executingSize);
        }
        if (i < executingSize) {
            if (i < executingSize - 1) {
                do {
                    int* currentValue = this->executingRules.value;
                    int nextIndex = i + 1;
                    currentValue[i] = currentValue[nextIndex];
                    i = nextIndex;
                } while (i < this->executingRules.maximumSizeValue - 1);
            }
            this->executingRules.numberValue--;
            if (this->executingRules.numberValue < 0) {
                this->executingRules.numberValue = 0;
            }
        }

        int idleCount = this->idleRules.numberValue;
        ManagedArray<int>* idleRules = &this->idleRules;
        i = 0;
        if (idleCount > 0) {
            do {
                if (this->idleRules.maximumSizeValue <= i) {
                    break;
                }
                if (idleRules->value[i] == worstRuleResult) {
                    goto add_idle_rule;
                }
                ++i;
            } while (i < idleCount);
        }
        if (this->idleRules.maximumSizeValue - 1 < idleCount) {
            idleRules->resize(idleCount + 1);
        }
        idleRules->value[this->idleRules.numberValue] = worstRuleResult;
        this->idleRules.numberValue++;

add_idle_rule:
        ;
    }

    i = 0;
    if (this->vcRuleSet.numberValue > 0) {
        do {
            ruleResult = this->vcRules.evaluateAsNonInProgress(
                this->md->aiPlayer, this->vcRuleSet[i]);
            if (ruleResult == -1) {
                this->vcRules.execute(
                    this->md->aiPlayer,
                    this->currentVictoryConditionValue,
                    this->vcRuleSet[i]);
            }
            ++i;
        } while (i < this->vcRuleSet.numberValue);
    }
    return 1;
}
