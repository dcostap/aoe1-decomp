#pragma once
#include "../common.h"

class AIPlayPhase : public AIPlayPhaseCommand {
public:
    AIPlayPhaseTrigger triggers[3];          // 0x50

    AIPlayPhase();
    virtual AIPlayPhaseCommand* command(int param_1);
    virtual AIPlayPhaseTrigger* trigger(int param_1);
    virtual int addCommand(AIPlayPhaseCommand* param_1);
    virtual int addTrigger(AIPlayPhaseTrigger* param_1);
    virtual void initialize();
};

static_assert(sizeof(AIPlayPhase) == 0x8C, "AIPlayPhase Size Mismatch");
static_assert(offsetof(AIPlayPhase, triggers) == 0x50, "AIPlayPhase Offset Mismatch");

class AIPlayStatus : public XYZ {
public:
    int playNumberValue;                     // 0x190
    int targetValue;                         // 0x194
    XYZ originalPointValue;                  // 0x198
    int originalHitPointsValue[5];           // 0x1A4
    uchar currentPhaseValue;                 // 0x1B8
    int savedAttackerValue;                  // 0x1BC
    ulong lastPhaseChangeTimeValue;          // 0x1C0
    uchar deviationValue;                    // 0x1C4

    AIPlayStatus();
    virtual int originalHitPoints(int param_1);
    virtual void setOriginalHitPoints(int param_1, int param_2);
    virtual uchar numberInPlay();
    virtual uchar numberInGroup(int param_1);
    virtual uchar numberOfTypeInGroup(int param_1, int param_2);
    virtual uchar group(int param_1);
    virtual int addGrouping(int param_1, uchar param_2, uchar param_3);
    virtual int removeGrouping(int param_1);
    virtual void zeroAllGroupings();
    virtual void copyUnits(int* param_1, int* param_2);
    virtual void load(int param_1);
    virtual void save(int param_1);
    virtual void copy(AIPlayStatus* param_1);
    virtual void removeDeadUnits(int param_1, RGE_Game_World* param_2);
    virtual void resetHitPoints(int param_1, RGE_Game_World* param_2);
};

static_assert(sizeof(AIPlayStatus) == 0x1C8, "AIPlayStatus Size Mismatch");
static_assert(offsetof(AIPlayStatus, deviationValue) == 0x1C4, "AIPlayStatus Offset Mismatch");

class AIPlayPhaseTrigger {
public:
    uchar typeValue;                         // 0x0
    int value1Value;                         // 0x4
    int value2Value;                         // 0x8
    uchar phaseValue;                        // 0xC
    uchar nextPhaseValue;                    // 0xD
    int randomnessValue;                     // 0x10

    AIPlayPhaseTrigger();
    AIPlayPhaseTrigger(uchar param_1, int param_2, int param_3, uchar param_4, uchar param_5, int param_6);
    AIPlayPhaseTrigger(char* param_1, int param_2, int param_3, uchar param_4, uchar param_5, int param_6);
    virtual char* nameType();
    virtual uchar convertToIntType(char* param_1);
    virtual char* convertToNameType(uchar param_1);
};

static_assert(sizeof(AIPlayPhaseTrigger) == 0x14, "AIPlayPhaseTrigger Size Mismatch");
static_assert(offsetof(AIPlayPhaseTrigger, randomnessValue) == 0x10, "AIPlayPhaseTrigger Offset Mismatch");

class AIPlay : public AIPlayGroup {
public:
    uchar minimumNumberUnitsValue;           // 0x41
    uchar maximumNumberUnitsValue;           // 0x42
    uchar typeValue;                         // 0x43
    uchar targetTypeValue[5];                // 0x44
    uchar targetCharacteristicValue[5];      // 0x49
    uchar powerValue;                        // 0x4E
    uchar overflowValue;                     // 0x4F
    uchar intelligenceValue;                 // 0x50
    uchar deathPercentageValue;              // 0x51
    uchar numberGroupsValue;                 // 0x52
    AIPlayGroup groups[5];                   // 0x53
    AIPlayPhase phases[10];                  // 0x90

    AIPlay();
    virtual void setName(char* param_1);
    virtual int humanPlay();
    virtual char* typeName();
    virtual uchar targetType(int param_1);
    virtual int isTargetType(uchar param_1);
    virtual int addTargetType(uchar param_1);
    virtual uchar targetCharacteristic(int param_1);
    virtual int isTargetCharacteristic(uchar param_1);
    virtual int addTargetCharacteristic(uchar param_1);
    virtual int gatherTolerance(int param_1, int param_2);
    virtual AIPlayGroup* group(int param_1);
    virtual AIPlayPhase* phase(int param_1);
    virtual int fillGroups(AIPlayStatus* param_1, int* param_2, int param_3, RGE_Game_World* param_4);
    virtual int groupGivenCommandOnPhase(int param_1, int param_2, int param_3);
    virtual uchar convertToIntType(char* param_1);
    virtual char* convertToNameType(uchar param_1);
    virtual int locationsOnMap(int param_1, int param_2, int param_3, int param_4);
};

static_assert(sizeof(AIPlay) == 0x608, "AIPlay Size Mismatch");
static_assert(offsetof(AIPlay, phases) == 0x90, "AIPlay Offset Mismatch");

class AIPlayGroup {
public:
    uchar minValue[6];                       // 0x0
    uchar maxValue[6];                       // 0x6

    AIPlayGroup();
    virtual uchar minimum(int param_1);
    virtual void setMinimum(int param_1, int param_2);
    virtual uchar maximum(int param_1);
    virtual void setMaximum(int param_1, int param_2);
    virtual void initialize();
};

static_assert(sizeof(AIPlayGroup) == 0xC, "AIPlayGroup Size Mismatch");
static_assert(offsetof(AIPlayGroup, maxValue) == 0x6, "AIPlayGroup Offset Mismatch");

class AIPlayBook {
public:
    int numberPlaysValue;                    // 0x4
    char nameValue[65];                      // 0x8
    AIPlay* plays;                           // 0x4C

    AIPlayBook();
    virtual ~AIPlayBook();
    virtual int loadPlays(char* param_1);
    virtual AIPlay* play(int param_1);
    virtual AIPlay* play(char* param_1);
    virtual int playNumber(char* param_1);
    virtual int convertTargetNameToIntType(char* param_1);
    virtual int convertTargetCharacteristicNameToIntType(char* param_1);
    virtual int convertUnitNameToIntType(char* param_1);
    virtual int convertUnitToIntType(RGE_Static_Object* param_1);
};

static_assert(sizeof(AIPlayBook) == 0x50, "AIPlayBook Size Mismatch");
static_assert(offsetof(AIPlayBook, plays) == 0x4C, "AIPlayBook Offset Mismatch");

class AIPlayPhaseCommand {
public:
    uchar groupValue;                        // 0x0
    uchar typeValue;                         // 0x1
    int value1Value;                         // 0x4
    int value2Value;                         // 0x8
    int value3Value;                         // 0xC

    AIPlayPhaseCommand();
    AIPlayPhaseCommand(uchar param_1, uchar param_2, int param_3, int param_4, int param_5);
    AIPlayPhaseCommand(uchar param_1, char* param_2, int param_3, int param_4, int param_5);
    virtual char* nameType();
    virtual uchar convertToIntType(char* param_1);
    virtual char* convertToNameType(uchar param_1);
};

static_assert(sizeof(AIPlayPhaseCommand) == 0x10, "AIPlayPhaseCommand Size Mismatch");
static_assert(offsetof(AIPlayPhaseCommand, value3Value) == 0xC, "AIPlayPhaseCommand Offset Mismatch");

