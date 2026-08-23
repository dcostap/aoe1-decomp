#ifndef TAISTRMD_CONTEXT_H
#define TAISTRMD_CONTEXT_H

// Shared declarations for the authentic taistrmd.cpp source prefix.
// PDB types prove the two owning class layouts used below.

class AIModuleMessage;
class TribeMainDecisionAIModule;
class TRIBE_Player;

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

class AIModule {
public:
    char gap_04[0xEC];

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
    virtual int processMessage(AIModuleMessage* message);
    virtual int update(int parameter);
    virtual void setCallbackMessage(AIModuleMessage* message);
    virtual int filterOutMessage(AIModuleMessage* message);

    AIModule(char* name, int id, int parameter, void* object);
};

class StrategyAIModule : public AIModule {
public:
    virtual ~StrategyAIModule();
    StrategyAIModule(void* object, int parameter);
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

    ~ManagedArray()
    {
        if (this->value != 0) {
            operator delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }

    int add(T valueToAdd)
    {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == valueToAdd)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int newSize = this->numberValue + 1;
            T* newValue = new T[newSize];
            if (newValue != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= newSize)
                        break;
                    newValue[j] = this->value[j];
                }
                delete[] this->value;
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
    int sn[226];

    VictoryConditionRuleSystem();
    int loadRules(char* filename);
    void setRule(int index, int value);
    int rule(int index);
    int evaluateAsInProgress(TRIBE_Player* player, int rule);
    int evaluateAsNonInProgress(TRIBE_Player* player, int rule);
    int stopExecution(TRIBE_Player* player, int rule);
    int execute(TRIBE_Player* player, int state, int command);
    void modifyForDifficultyLevel(int level);
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
    TribeMainDecisionAIModule* md;
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
    ManagedArray<int> vcRuleSet;
    ManagedArray<int> executingRules;
    ManagedArray<int> idleRules;
    VictoryConditionRuleSystem vcRules;
    int difficultyLevel;

    virtual ~TribeStrategyAIModule();
    TribeStrategyAIModule(void* object, int parameter);
    TribeStrategyAIModule(int playerID, int infile);
    int loadRules(char* name);
    void setDifficultyLevel(int level);
};

#endif
