#ifndef AOE1_AIPBOOK_H
#define AOE1_AIPBOOK_H


#include "aiplaybook.h"
#include "ai_play_group.h"
#include "ai_play_phase.h"
#include "point.h"

class RGE_Game_World;
class AIPlayStatus;

class AIPlay {
public:
    char nameValue[65];                  // +0x000
    unsigned char minimumNumberUnitsValue; // +0x041
    unsigned char maximumNumberUnitsValue; // +0x042
    unsigned char typeValue;             // +0x043
    unsigned char targetTypeValue[5];    // +0x044
    unsigned char targetCharacteristicValue[5]; // +0x049
    unsigned char powerValue;            // +0x04E
    unsigned char overflowValue;         // +0x04F
    unsigned char intelligenceValue;     // +0x050
    unsigned char deathPercentageValue;  // +0x051
    unsigned char numberGroupsValue;     // +0x052
    AIPlayGroup groups[5];               // +0x053
    unsigned char pad_08F;               // +0x08F
    AIPlayPhase phases[10];              // +0x090

    AIPlay();
    void setName(char* n);
    int humanPlay() const;
    char* typeName() const;
    unsigned char targetType(int n) const;
    int isTargetType(unsigned char v) const;
    int addTargetType(unsigned char v);
    unsigned char targetCharacteristic(int n) const;
    int isTargetCharacteristic(unsigned char v) const;
    int addTargetCharacteristic(unsigned char v);
    int gatherTolerance(int groupID, int phaseID);
    AIPlayGroup* group(int n);
    AIPlayPhase* phase(int n);
    int fillGroups(AIPlayStatus* playStatus, int* groupMembers, int numberGroupMembers, RGE_Game_World* world);
    int groupGivenCommandOnPhase(int gID, int cType, int pID);

protected:
    unsigned char convertToIntType(char* t) const;
    char* convertToNameType(unsigned char t) const;

public:
    int locationsOnMap(int targetX, int targetY, int mapXSize, int mapYSize);

    friend class AIPlayBook;
};

class AIPlayStatus {
public:
    class GroupingStruct {
    public:
        int id;                         // +0x00
        unsigned char groupID;           // +0x04
        unsigned char type;              // +0x05
        unsigned char pad_06[2];        // +0x06
    };

    GroupingStruct groupings[50];       // +0x000
    int playNumberValue;                // +0x190
    int targetValue;                    // +0x194
    XYZ originalPointValue;             // +0x198
    int originalHitPointsValue[5];      // +0x1A4
    unsigned char currentPhaseValue;    // +0x1B8
    unsigned char pad_1B9[3];           // +0x1B9
    int savedAttackerValue;             // +0x1BC
    unsigned long lastPhaseChangeTimeValue; // +0x1C0
    unsigned char deviationValue;       // +0x1C4
    unsigned char pad_1C5[3];           // +0x1C5

    AIPlayStatus();
    int originalHitPoints(int n) const;
    void setOriginalHitPoints(int n, int v);
    XYZ originalPoint() const { return this->originalPointValue; }
    unsigned char numberInPlay() const;
    unsigned char numberInGroup(int n);
    unsigned char numberOfTypeInGroup(int n, int type);
    unsigned char group(int uID);
    int addGrouping(int uID, unsigned char gID, unsigned char type);
    int removeGrouping(int uID);
    void zeroAllGroupings();
    void copyUnits(int* array, int& count);
    void load(int infile);
    void save(int outfile);
    void copy(AIPlayStatus* ps);
    void removeDeadUnits(int gID, RGE_Game_World* world);
    void resetHitPoints(int gID, RGE_Game_World* world);
};

typedef char aipbook_xyz_size[(sizeof(XYZ) == 0x0C) ? 1 : -1];
typedef char aipbook_command_size[(sizeof(AIPlayPhaseCommand) == 0x10) ? 1 : -1];
typedef char aipbook_trigger_size[(sizeof(AIPlayPhaseTrigger) == 0x14) ? 1 : -1];
typedef char aipbook_phase_size[(sizeof(AIPlayPhase) == 0x8C) ? 1 : -1];
typedef char aipbook_group_size[(sizeof(AIPlayGroup) == 0x0C) ? 1 : -1];
typedef char aipbook_play_size[(sizeof(AIPlay) == 0x608) ? 1 : -1];
typedef char aipbook_grouping_size[(sizeof(AIPlayStatus::GroupingStruct) == 0x08) ? 1 : -1];
typedef char aipbook_status_size[(sizeof(AIPlayStatus) == 0x1C8) ? 1 : -1];

#endif
