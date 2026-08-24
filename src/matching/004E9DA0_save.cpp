// VA: 004E9DA0 TribeStrategyAIModule::save
// Attempt log:
// try 1: packet-grounded save implementation: fixed scalar writes, strcpy/strlen rule-set name serialization,
// and three grow-while-saving integer arrays mirroring UnitAIModule::save pattern.

#include <string.h>

void __cdecl rge_write(int fd, const void* data, int size);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* p);

#ifndef TAISTRMD_TU_CONTEXT
struct Waypoint { char data[16]; };

class TribeStrategyAIModule {
public:
    virtual int save(int fd);
    char gap_04[0xF0];
    int mainDecisionAI_;            // +f4
    char ruleSetName_[0x104];       // +f8
    int currentVictoryCondition_;   // +1fc
    int gap_200;                    // +200
    int targetID_;                  // +204
    int targetType_;                // +208
    Waypoint targetPoint1_;         // +20c
    Waypoint targetPoint2_;         // +21c
    int targetAttribute_;           // +22c
    int targetNumber_;              // +230
    int secondTargetID_;            // +234
    int* list1_;                    // +238
    int list1Count_;                // +23c
    int gap240_;                    // +240
    int list1Max_;                  // +244
    int* list2_;                    // +248
    int list2Count_;                // +24c
    int gap250_;                    // +250
    int list2Max_;                  // +254
    int* list3_;                    // +258
    int list3Count_;                // +25c
    int gap260_;                    // +260
    int list3Max_;                  // +264
    char gap_268[0x5f4 - 0x268];
    int difficultyLevel_;           // +5f4
};
#endif

int TribeStrategyAIModule::save(int fd)
{
    int temp;
    char tempString[260];
    int i;

    rge_write(fd, &this->md, 4);
    rge_write(fd, &this->currentVictoryConditionValue, 4);
    rge_write(fd, &this->targetIDValue, 4);
    rge_write(fd, &this->targetTypeValue, 4);
    rge_write(fd, &this->targetPoint1Value, 16);
    rge_write(fd, &this->targetPoint2Value, 16);
    rge_write(fd, &this->targetAttributeValue, 4);
    rge_write(fd, &this->targetNumberValue, 4);
    rge_write(fd, &this->secondTargetIDValue, 4);
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
