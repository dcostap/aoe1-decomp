#ifndef TAISTRMD_CONTEXT_H
#define TAISTRMD_CONTEXT_H

// Shared declarations for the authentic taistrmd.cpp source prefix.
// PDB types prove the two owning class layouts used below.

class AIModuleMessage;
class TribeMainDecisionAIModule;
class TRIBE_Player;

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

class RGE_Victory_Entry {
public:
    unsigned char command;
    char gap_01[0x3];
    int obj_type;
    class RGE_Player* target_player;
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
    virtual ~RGE_Player();
    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0x1008];
    void setStrategicNumber(int index, int value);
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    TRIBE_Player* player;
    char gap_F4[0x11378];
    TribeTacticalAIModule tacticalAI;
    char gap_12478[0xF4];
    TRIBE_Player* aiPlayer;
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_38[0x200];
    TribeMainDecisionAIModule* playerAI;
};

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

    int contains(const T& valueToFind);
    int resize(int newSize);
    T& operator[](int index);

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
    union {
        TribeMainDecisionAIModule* md;
        int mainDecisionAI_;
    };
    union {
        int currentVictoryConditionValue;
        int currentVictoryCondition_;
    };
    union {
        char ruleSetNameValue[0x104];
        char ruleSetName_[0x104];
    };
    union {
        int targetIDValue;
        int targetID_;
    };
    union {
        int targetTypeValue;
        int targetType_;
    };
    union {
        int secondTargetIDValue;
        int secondTargetID_;
    };
    union {
        int secondTargetTypeValue;
        int secondTargetType_;
    };
    union {
        Waypoint targetPoint1Value;
        Waypoint targetPoint1_;
    };
    union {
        Waypoint targetPoint2Value;
        Waypoint targetPoint2_;
    };
    union {
        int targetAttributeValue;
        int targetAttribute_;
    };
    union {
        int targetNumberValue;
        int targetNumber_;
    };
    int victoryConditionChangeTimeout;
    ManagedArray<int> vcRuleSet;
    ManagedArray<int> executingRules;
    ManagedArray<int> idleRules;
    VictoryConditionRuleSystem vcRules;
    union {
        int difficultyLevel;
        int difficultyLevel_;
    };

    virtual ~TribeStrategyAIModule();
    virtual int update(int parameter);
    virtual int save(int fileHandle);
    TribeStrategyAIModule(void* object, int parameter);
    TribeStrategyAIModule(int playerID, int infile);
    void setMainDecisionAI(int value);
    int loadRules(char* name);
    void setDifficultyLevel(int level);
    void setRule(int rule, int value);
    int rule(int index);
    char* ruleSetName();
    int currentVictoryCondition();
    int targetID();
    int targetType();
    int secondTargetID();
    int secondTargetType();
    Waypoint* targetPoint1();
    Waypoint* targetPoint2();
    int targetAttribute();
    int targetNumber();
    void setVictoryCondition(int value);
    int isRuleExecuting(int ruleID);
    int isRuleIdle(int ruleID);
};

#endif
