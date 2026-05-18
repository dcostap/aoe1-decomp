// VA: 004E9DA0 TribeStrategyAIModule::save
// Attempt log:
// try 1: packet-grounded save implementation: fixed scalar writes, strcpy/strlen rule-set name serialization,
// and three grow-while-saving integer arrays mirroring UnitAIModule::save pattern.

#include <string.h>

void __cdecl rge_write(int fd, const void* data, int size);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* p);

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

int TribeStrategyAIModule::save(int fd)
{
    int temp;
    char tempString[260];
    int i;

    rge_write(fd, &this->mainDecisionAI_, 4);
    rge_write(fd, &this->currentVictoryCondition_, 4);
    rge_write(fd, &this->targetID_, 4);
    rge_write(fd, &this->targetType_, 4);
    rge_write(fd, &this->targetPoint1_, 16);
    rge_write(fd, &this->targetPoint2_, 16);
    rge_write(fd, &this->targetAttribute_, 4);
    rge_write(fd, &this->targetNumber_, 4);
    rge_write(fd, &this->secondTargetID_, 4);
    rge_write(fd, &this->difficultyLevel_, 4);

    strcpy(tempString, this->ruleSetName_);
    temp = strlen(tempString);
    rge_write(fd, &temp, 4);
    rge_write(fd, tempString, strlen(tempString));

    temp = this->list1Count_;
    rge_write(fd, &temp, 4);
    for (i = 0; i < this->list1Count_; i++) {
        if (i > this->list1Max_ - 1) {
            int newMax = i + 1;
            int* newArr = (int*)operator new(i * 4 + 4);
            if (newArr) {
                int j;
                for (j = 0; j < this->list1Max_ && j < newMax; j++) {
                    newArr[j] = this->list1_[j];
                }
                operator delete(this->list1_);
                this->list1_ = newArr;
                this->list1Max_ = newMax;
            }
        }
        temp = this->list1_[i];
        rge_write(fd, &temp, 4);
    }

    temp = this->list2Count_;
    rge_write(fd, &temp, 4);
    for (i = 0; i < this->list2Count_; i++) {
        if (i > this->list2Max_ - 1) {
            int newMax = i + 1;
            int* newArr = (int*)operator new(i * 4 + 4);
            if (newArr) {
                int j;
                for (j = 0; j < this->list2Max_ && j < newMax; j++) {
                    newArr[j] = this->list2_[j];
                }
                operator delete(this->list2_);
                this->list2_ = newArr;
                this->list2Max_ = newMax;
            }
        }
        temp = this->list2_[i];
        rge_write(fd, &temp, 4);
    }

    temp = this->list3Count_;
    rge_write(fd, &temp, 4);
    for (i = 0; i < this->list3Count_; i++) {
        if (i > this->list3Max_ - 1) {
            int newMax = i + 1;
            int* newArr = (int*)operator new(i * 4 + 4);
            if (newArr) {
                int j;
                for (j = 0; j < this->list3Max_ && j < newMax; j++) {
                    newArr[j] = this->list3_[j];
                }
                operator delete(this->list3_);
                this->list3_ = newArr;
                this->list3Max_ = newMax;
            }
        }
        temp = this->list3_[i];
        rge_write(fd, &temp, 4);
    }

    return 1;
}
