// VA: 004E9DA0 TribeStrategyAIModule::save
// Attempt log:
// try 1: packet-grounded save implementation: fixed scalar writes, strcpy/strlen rule-set name serialization,
// and three grow-while-saving integer arrays mirroring UnitAIModule::save pattern.
// BINARY NOTE: the first ten writes begin at +0xF4 and skip targetType at
// +0x200; the canonical class layout also places md at +0xF0.
// The standalone declaration mirrors that inherited layout for source checks.

#include <string.h>

void __cdecl rge_write(int fd, const void* data, int size);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* p);

#ifndef TAISTRMD_TU_CONTEXT
struct Waypoint { char data[16]; };

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class TribeStrategyAIModule {
public:
    virtual int save(int fd);
    char gap_04[0xEC];
    int md;                         // +f0
    int currentVictoryConditionValue; // +f4
    char ruleSetNameValue[0x104];   // +f8
    int targetIDValue;              // +1fc
    int targetTypeValue;            // +200
    int secondTargetIDValue;        // +204
    int secondTargetTypeValue;      // +208
    Waypoint targetPoint1Value;     // +20c
    Waypoint targetPoint2Value;     // +21c
    int targetAttributeValue;       // +22c
    int targetNumberValue;          // +230
    int victoryConditionChangeTimeout; // +234
    ManagedArray<int> vcRuleSet;    // +238
    ManagedArray<int> executingRules; // +248
    ManagedArray<int> idleRules;    // +258
    char gap_268[0x5f4 - 0x268];
    int difficultyLevel;            // +5f4
};
#endif

int TribeStrategyAIModule::save(int fd)
{
    int temp;
    char tempString[260];
    int i;

    rge_write(fd, &this->currentVictoryConditionValue, 4);
    rge_write(fd, &this->targetIDValue, 4);
    rge_write(fd, &this->secondTargetIDValue, 4);
    rge_write(fd, &this->secondTargetTypeValue, 4);
    rge_write(fd, &this->targetPoint1Value, 16);
    rge_write(fd, &this->targetPoint2Value, 16);
    rge_write(fd, &this->targetAttributeValue, 4);
    rge_write(fd, &this->targetNumberValue, 4);
    rge_write(fd, &this->victoryConditionChangeTimeout, 4);
    rge_write(fd, &this->difficultyLevel, 4);

    strcpy(tempString, this->ruleSetNameValue);
    temp = strlen(tempString);
    rge_write(fd, &temp, 4);
    rge_write(fd, tempString, strlen(tempString));

    temp = this->vcRuleSet.numberValue;
    rge_write(fd, &temp, 4);
    for (i = 0; i < this->vcRuleSet.numberValue; i++) {
        if (i > this->vcRuleSet.maximumSizeValue - 1) {
            int newMax = i + 1;
            int* newArr = (int*)operator new(i * 4 + 4);
            if (newArr) {
                int j;
                for (j = 0; j < this->vcRuleSet.maximumSizeValue && j < newMax; j++) {
                    newArr[j] = this->vcRuleSet.value[j];
                }
                operator delete(this->vcRuleSet.value);
                this->vcRuleSet.value = newArr;
                this->vcRuleSet.maximumSizeValue = newMax;
            }
        }
        temp = this->vcRuleSet.value[i];
        rge_write(fd, &temp, 4);
    }

    temp = this->executingRules.numberValue;
    rge_write(fd, &temp, 4);
    for (i = 0; i < this->executingRules.numberValue; i++) {
        if (i > this->executingRules.maximumSizeValue - 1) {
            int newMax = i + 1;
            int* newArr = (int*)operator new(i * 4 + 4);
            if (newArr) {
                int j;
                for (j = 0; j < this->executingRules.maximumSizeValue && j < newMax; j++) {
                    newArr[j] = this->executingRules.value[j];
                }
                operator delete(this->executingRules.value);
                this->executingRules.value = newArr;
                this->executingRules.maximumSizeValue = newMax;
            }
        }
        temp = this->executingRules.value[i];
        rge_write(fd, &temp, 4);
    }

    temp = this->idleRules.numberValue;
    rge_write(fd, &temp, 4);
    for (i = 0; i < this->idleRules.numberValue; i++) {
        if (i > this->idleRules.maximumSizeValue - 1) {
            int newMax = i + 1;
            int* newArr = (int*)operator new(i * 4 + 4);
            if (newArr) {
                int j;
                for (j = 0; j < this->idleRules.maximumSizeValue && j < newMax; j++) {
                    newArr[j] = this->idleRules.value[j];
                }
                operator delete(this->idleRules.value);
                this->idleRules.value = newArr;
                this->idleRules.maximumSizeValue = newMax;
            }
        }
        temp = this->idleRules.value[i];
        rge_write(fd, &temp, 4);
    }

    return 1;
}
