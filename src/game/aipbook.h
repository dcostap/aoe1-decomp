#pragma once
#include "common.h"

class AIPlay {
public:
    char nameValue[65];                      // 0x0
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
    void setName(char* param_1);
    int humanPlay();
    char* typeName();
    uchar targetType(int param_1);
    int isTargetType(uchar param_1);
    int addTargetType(uchar param_1);
    uchar targetCharacteristic(int param_1);
    int isTargetCharacteristic(uchar param_1);
    int addTargetCharacteristic(uchar param_1);
    int gatherTolerance(int param_1, int param_2);
    AIPlayGroup* group(int param_1);
    AIPlayPhase* phase(int param_1);
    int fillGroups(AIPlayStatus* param_1, int* param_2, int param_3, RGE_Game_World* param_4);
    int groupGivenCommandOnPhase(int param_1, int param_2, int param_3);
    uchar convertToIntType(char* param_1);
    char* convertToNameType(uchar param_1);
    int locationsOnMap(int param_1, int param_2, int param_3, int param_4);
};

static_assert(sizeof(AIPlay) == 0x608, "AIPlay Size Mismatch");

// ----------------------------------------------------------------
// GroupingStruct
// Size: 0x8
struct GroupingStruct {
    int id; // 0x0
    uchar groupID; // 0x4
    uchar type; // 0x5
};

class AIPlayBook {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    int numberPlaysValue;                    // 0x4
    char nameValue[65];                      // 0x8
    AIPlay* plays;                           // 0x4C

    virtual int convertTargetNameToIntType(char* param_1);  // vt0[1]+0x4=0x411480
    virtual int convertTargetCharacteristicNameToIntType(char* param_1); // vt0[2]+0x8=0x4114E0
    virtual int convertUnitNameToIntType(char* param_1);    // vt0[3]+0xC=0x411650
    virtual int convertUnitToIntType(RGE_Static_Object* param_1); // vt0[4]+0x10=0x411660
    AIPlayBook();
    ~AIPlayBook();
    int loadPlays(char* param_1);
    AIPlay* play(int param_1);
    AIPlay* play(char* param_1);
    int playNumber(char* param_1);
};

static_assert(sizeof(AIPlayBook) == 0x50, "AIPlayBook Size Mismatch");

class AIPlayGroup {
public:
    uchar minValue[6];                       // 0x0
    uchar maxValue[6];                       // 0x6

    AIPlayGroup();
    uchar minimum(int param_1);
    void setMinimum(int param_1, int param_2);
    uchar maximum(int param_1);
    void setMaximum(int param_1, int param_2);
    void initialize();
};

static_assert(sizeof(AIPlayGroup) == 0xC, "AIPlayGroup Size Mismatch");

class AIPlayPhase {
public:
    AIPlayPhaseCommand commands[5];          // 0x0
    AIPlayPhaseTrigger triggers[3];          // 0x50

    AIPlayPhase();
    AIPlayPhaseCommand* command(int param_1);
    AIPlayPhaseTrigger* trigger(int param_1);
    int addCommand(AIPlayPhaseCommand* param_1);
    int addTrigger(AIPlayPhaseTrigger* param_1);
    void initialize();
};

static_assert(sizeof(AIPlayPhase) == 0x8C, "AIPlayPhase Size Mismatch");

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
    char* nameType();
    uchar convertToIntType(char* param_1);
    char* convertToNameType(uchar param_1);
};

static_assert(sizeof(AIPlayPhaseCommand) == 0x10, "AIPlayPhaseCommand Size Mismatch");

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
    char* nameType();
    uchar convertToIntType(char* param_1);
    char* convertToNameType(uchar param_1);
};

static_assert(sizeof(AIPlayPhaseTrigger) == 0x14, "AIPlayPhaseTrigger Size Mismatch");

class AIPlayStatus {
public:
    GroupingStruct groupings[50];            // 0x0
    int playNumberValue;                     // 0x190
    int targetValue;                         // 0x194
    XYZ originalPointValue;                  // 0x198
    int originalHitPointsValue[5];           // 0x1A4
    uchar currentPhaseValue;                 // 0x1B8
    int savedAttackerValue;                  // 0x1BC
    ulong lastPhaseChangeTimeValue;          // 0x1C0
    uchar deviationValue;                    // 0x1C4

    AIPlayStatus();
    int originalHitPoints(int param_1);
    void setOriginalHitPoints(int param_1, int param_2);
    uchar numberInPlay();
    uchar numberInGroup(int param_1);
    uchar numberOfTypeInGroup(int param_1, int param_2);
    uchar group(int param_1);
    int addGrouping(int param_1, uchar param_2, uchar param_3);
    int removeGrouping(int param_1);
    void zeroAllGroupings();
    void copyUnits(int* param_1, int* param_2);
    void load(int param_1);
    void save(int param_1);
    void copy(AIPlayStatus* param_1);
    void removeDeadUnits(int param_1, RGE_Game_World* param_2);
    void resetHitPoints(int param_1, RGE_Game_World* param_2);
};

static_assert(sizeof(AIPlayStatus) == 0x1C8, "AIPlayStatus Size Mismatch");

