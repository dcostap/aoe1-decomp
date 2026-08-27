#ifndef AOE1_AIPBOOK_H
#define AOE1_AIPBOOK_H

// Declarations for the original aipbook.cpp source module.
// PDB type records prove each aggregate size and field offset below.

class RGE_Static_Object;
class RGE_Game_World;
class AIPlayStatus;

class XYZ {
public:
    int xValue;                         // +0x00
    int yValue;                         // +0x04
    int zValue;                         // +0x08

    XYZ();
    XYZ(int x, int y, int z);
    void rotateXYByFacet(const XYZ& facet, XYZ& output,
                         unsigned char facetIndex);
};

class AIPlayPhaseCommand {
public:
    unsigned char groupValue;           // +0x00
    unsigned char typeValue;            // +0x01
    unsigned char pad_02[2];            // +0x02
    int value1Value;                    // +0x04
    int value2Value;                    // +0x08
    int value3Value;                    // +0x0C

    AIPlayPhaseCommand();
    AIPlayPhaseCommand(unsigned char group, unsigned char type,
                       int value1, int value2, int value3);
    AIPlayPhaseCommand(unsigned char group, char* type,
                       int value1, int value2, int value3);
    char* nameType() const;

protected:
    unsigned char convertToIntType(char* name) const;
    char* convertToNameType(unsigned char type) const;
};

class AIPlayPhaseTrigger {
public:
    unsigned char typeValue;            // +0x00
    unsigned char pad_01[3];            // +0x01
    int value1Value;                    // +0x04
    int value2Value;                    // +0x08
    unsigned char phaseValue;           // +0x0C
    unsigned char nextPhaseValue;       // +0x0D
    unsigned char pad_0E[2];            // +0x0E
    int randomnessValue;                // +0x10

    AIPlayPhaseTrigger();
    AIPlayPhaseTrigger(unsigned char type, int value1, int value2,
                       unsigned char phase, unsigned char nextPhase,
                       int randomness);
    AIPlayPhaseTrigger(char* type, int value1, int value2,
                       unsigned char phase, unsigned char nextPhase,
                       int randomness);
    char* nameType() const;

protected:
    unsigned char convertToIntType(char* name) const;
    char* convertToNameType(unsigned char type) const;
};

class AIPlayPhase {
public:
    AIPlayPhaseCommand commands[5];      // +0x00
    AIPlayPhaseTrigger triggers[3];      // +0x50

    AIPlayPhase();
    AIPlayPhaseCommand* command(int index);
    AIPlayPhaseTrigger* trigger(int index);
    int addCommand(AIPlayPhaseCommand& commandValue);
    int addTrigger(AIPlayPhaseTrigger& triggerValue);

protected:
    void initialize();
};

class AIPlayGroup {
public:
    unsigned char minimumValues[6];     // +0x00
    unsigned char maximumValues[6];     // +0x06

    AIPlayGroup();
    unsigned char minimum(int index) const;
    void setMinimum(int index, int value);
    unsigned char maximum(int index) const;
    void setMaximum(int index, int value);

protected:
    void initialize();
};

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
    void setName(char* name);
    int humanPlay() const;
    char* typeName() const;
    unsigned char targetType(int index) const;
    int isTargetType(unsigned char type) const;
    int addTargetType(unsigned char type);
    unsigned char targetCharacteristic(int index) const;
    int isTargetCharacteristic(unsigned char characteristic) const;
    int addTargetCharacteristic(unsigned char characteristic);
    int gatherTolerance(int group, int phaseNumber);
    AIPlayGroup* group(int index);
    AIPlayPhase* phase(int index);
    int fillGroups(AIPlayStatus* status, int* units, int unitCount,
                   RGE_Game_World* world);
    int groupGivenCommandOnPhase(int group, int type, int phaseNumber);

protected:
    unsigned char convertToIntType(char* name) const;
    char* convertToNameType(unsigned char type) const;

public:
    int locationsOnMap(int x1, int y1, int x2, int y2);

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
    int originalHitPoints(int groupNumber) const;
    void setOriginalHitPoints(int groupNumber, int value);
    unsigned char numberInPlay() const;
    unsigned char numberInGroup(int groupNumber);
    unsigned char numberOfTypeInGroup(int groupNumber, int type);
    unsigned char group(int id);
    int addGrouping(int id, unsigned char groupID, unsigned char type);
    int removeGrouping(int id);
    void zeroAllGroupings();
    void copyUnits(int* units, int& count);
    void load(int file);
    void save(int file);
    void copy(AIPlayStatus* other);
    void removeDeadUnits(int groupNumber, RGE_Game_World* world);
    void resetHitPoints(int groupNumber, RGE_Game_World* world);
};

class AIPlayBook {
public:
    virtual ~AIPlayBook();
    virtual int convertTargetNameToIntType(char* name) const;
    virtual int convertTargetCharacteristicNameToIntType(char* name) const;
    virtual int convertUnitNameToIntType(char* name) const;
    virtual int convertUnitToIntType(RGE_Static_Object* object) const;

    int numberPlaysValue;                // +0x04
    char nameValue[65];                  // +0x08
    unsigned char pad_49[3];             // +0x49
    AIPlay* plays;                       // +0x4C

    AIPlayBook();
    int loadPlays(char* filename);
    AIPlay* play(int index);
    AIPlay* play(char* name);
    int playNumber(char* name);
};

class RGE_Static_Object {
public:
    unsigned char gap_00[0x30];
    float hitPointsValue;                // +0x30
    unsigned char gap_34[0x14];
    unsigned char object_state;          // +0x48
};

class RGE_Game_World {
public:
    unsigned char gap_00[0xA0];
    AIPlayBook* playbook;                // +0xA0

    RGE_Static_Object* object(int id);
};

typedef char aipbook_xyz_size[(sizeof(XYZ) == 0x0C) ? 1 : -1];
typedef char aipbook_command_size[(sizeof(AIPlayPhaseCommand) == 0x10) ? 1 : -1];
typedef char aipbook_trigger_size[(sizeof(AIPlayPhaseTrigger) == 0x14) ? 1 : -1];
typedef char aipbook_phase_size[(sizeof(AIPlayPhase) == 0x8C) ? 1 : -1];
typedef char aipbook_group_size[(sizeof(AIPlayGroup) == 0x0C) ? 1 : -1];
typedef char aipbook_play_size[(sizeof(AIPlay) == 0x608) ? 1 : -1];
typedef char aipbook_grouping_size[(sizeof(AIPlayStatus::GroupingStruct) == 0x08) ? 1 : -1];
typedef char aipbook_status_size[(sizeof(AIPlayStatus) == 0x1C8) ? 1 : -1];
typedef char aipbook_book_size[(sizeof(AIPlayBook) == 0x50) ? 1 : -1];

#endif
