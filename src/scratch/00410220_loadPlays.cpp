// 00410220 AIPlayBook::loadPlays(char*)
// PDB owner: AIPlayBook::loadPlays(char*)
// Decorated owner: ?loadPlays@AIPlayBook@@QAEHPAD@Z
//
// Clean reconstruction baseline: AIPlayBook owns a counted array of 0x608-byte
// AIPlay records.  The file is read once to count Play records and again to
// populate the named play/phase/group fields.  The generated packet's odd stack
// aliases are not used as the source model; parser buffers and the real AI play
// aggregates are named below.
//
// Attempt log:
// - baseline /O2: the first source draft omitted the second pass and allocation;
//   corrected to count Play records, clamp, construct AIPlay[], rewind, and parse.
// - /GX is retained in config/flags/00410220_loadPlays.rsp: it restores the
//   oracle's EH-framed array-construction lifetime and exact call set; default
//   flags omit the FS frame.
// - bounded second-pass condition `refPhase < 16000 && fgets(...)` recovers the
//   oracle's single fgets call site (72/72 ordered calls, no call-set gaps).
// - named virtual AIPlayBook conversion surface and the AIPlay/phase/group
//   overloads are complete; parser buffers and generation/copy loops are natural.
// - explicit operator-new plus placement-constructor was diagnostic only: it
//   removed the EH frame and was restored to natural `new AIPlay[]`.
// - left in scratch: current /GX candidate is 66 bytes longer, frame 0x3A4 vs
//   0x3A8, with the remaining drift concentrated in EH prologue/state ordering,
//   scalar parser stack homes, and the late loop tail; no call or CFG behavior
//   uncertainty remains in the reconstructed source.
// - do-while reconstruction moved the positional diff to 4001 bytes, but it
//   emitted a second-pass extra fgets (73/72 calls); rolled back to the exact
//   ordered-call candidate.  The remaining lead is local lifetime/frame shape.
// - corrected the Play-name quote scan to use the proven temp[4] fgets
//   destination and the existing i/temp4 counters; diff improved to 4090.
// - parsed Phase into temp4, then assigned currentPhase; original data flow
//   stores the parsed value through that temporary.  Diff improved to 4073.
// - high-byte comment aliases, a separate Group minimum local, and direct
//   clamp expressions were tested and restored; they reduced source clarity or
//   structural coverage.  One phaseValue1 local now names the shared phase
//   parser value; it emits the same code as the prior value1 spelling.
// - Ghidra stack evidence separates the phase state from the two `%c` outputs.
//   The clean source now keeps phaseState and phaseValue1 separate.
// - direct quote scans and the separated parser state improve structural
//   coverage, but the current natural source remains nonexact.
// - 28 meaningful probes covered flags, headers, ABI surfaces, lifetimes,
//   declaration order, control flow, and local layout.  The best metric-only
//   basin aliases phaseState with value1 and is not behavior-safe.
// - final validation: 72/72 ordered calls, frame 0x3A8, size +95, diff 4280;
//   the remaining blocker is VC5 EH/local-home topology.
// - fresh late-loop evidence: the parser `i` home is not the five-element
//   target-copy index.  A branch-local targetIndex and separate groupIndex /
//   triggerIndex recover the oracle's EDI loop topology.  The natural source
//   now measures size +43, shape 81.78%, and diff 4236 with all 72 calls.
// - reusing the quote end counter and adding the unmapped temp3 local did not
//   change emitted code; the narrow char comment locals remain preferred.
// - canonical-context finish: this owner now uses the reviewed aipbook.cpp
//   declarations and aggregate layouts.  Fresh direct checking improved the
//   diff to 4211, kept the PDB owner and all 72 ordered calls, but did not
//   reach exact bytes.  The canonical wrapper also compiles with /GX.
// - restored after controlled tests: persistent EndPlay cursors, natural
//   comment locals, a branch-local quote counter, and a named new[] result.
//   These forms changed registers or behavior without an exact result.

#define AIPBOOK_CANONICAL_TU 1
#include "../../include/aipbook_context.h"

#ifndef AIPBOOK_CANONICAL_TU
#include <stdio.h>
#include <string.h>
#endif

extern char s_NULL[];
extern char s_NONE[];
extern char s_592A40[];
extern char s_format_percent_s[];
extern char s_mode_r[];
extern char s_format_percent_s_space[];
extern char s_format_comment[];
extern char s_Play[];
extern char s_PlayType[];
extern char s_MinUnits[];
extern char s_MaxUnits[];
extern char s_Power[];
extern char s_Overflow[];
extern char s_Balance[];
extern char s_FirstGroup[];
extern char s_DeathPercentage[];
extern char s_Intelligence[];
extern char s_TargetChar[];
extern char s_TargetType[];
extern char s_NumberGroups[];
extern char s_Group[];
extern char s_Phase[];
extern char s_Trigger[];
extern char s_RTrigger[];
extern char s_EndPlay[];
extern char s_format_skip_string_int[];
extern char s_format_skip_string_string[];
extern char s_format_group_range[];
extern char s_format_command[];
extern char s_format_trigger[];
extern char s_format_play_variant[];

void __cdecl operator_delete(void* block);

#ifndef AIPBOOK_CANONICAL_TU
class AIPlayGroup {
public:
    unsigned char minimumValue[6];
    unsigned char maximumValue[6];

    unsigned char minimum(int index) const;
    void setMinimum(int index, int value);
    unsigned char maximum(int index) const;
    void setMaximum(int index, int value);
};

class AIPlayPhaseCommand {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    char gap_02[2];
    int value1Value;
    int value2Value;
    int value3Value;

    AIPlayPhaseCommand();
    AIPlayPhaseCommand(unsigned char group, unsigned char type,
                       int value1, int value2, int value3);
    AIPlayPhaseCommand(unsigned char group, char* type,
                       int value1, int value2, int value3);
};

class AIPlayPhaseTrigger {
public:
    unsigned char typeValue;
    char gap_01[3];
    int value1Value;
    int value2Value;
    unsigned char phaseValue;
    unsigned char nextPhaseValue;
    char gap_0E[2];
    int randomnessValue;

    AIPlayPhaseTrigger();
    AIPlayPhaseTrigger(char* type, int value1, int value2,
                       unsigned char phase, unsigned char nextPhase,
                       int randomness);
};

class AIPlayPhase {
public:
    AIPlayPhaseCommand commands[5];
    AIPlayPhaseTrigger triggers[3];

    AIPlayPhaseCommand* command(int index);
    int addCommand(AIPlayPhaseCommand& commandValue);
    AIPlayPhaseTrigger* trigger(int index);
    int addTrigger(AIPlayPhaseTrigger& triggerValue);
};

class AIPlay {
public:
    char nameValue[65];
    unsigned char minimumNumberUnitsValue;
    unsigned char maximumNumberUnitsValue;
    unsigned char typeValue;
    unsigned char targetTypeValue[5];
    unsigned char targetCharacteristicValue[5];
    unsigned char powerValue;
    unsigned char overflowValue;
    unsigned char intelligenceValue;
    unsigned char deathPercentageValue;
    unsigned char numberGroupsValue;
    AIPlayGroup groups[5];
    char gap_8F[1];
    AIPlayPhase phases[10];

    AIPlay();
    void setName(char* name);

protected:
    unsigned char convertToIntType(char* name) const;

    friend class AIPlayBook;

public:
    unsigned char targetType(int index) const;
    int addTargetType(unsigned char type);
    unsigned char targetCharacteristic(int index) const;
    int addTargetCharacteristic(unsigned char characteristic);
    AIPlayGroup* group(int index);
    AIPlayPhase* phase(int index);
};

class RGE_Static_Object;

class AIPlayBook {
public:
    // This is the complete named virtual surface from the AIPlayBook ABI.  The
    // data members consequently begin at their real post-vptr offsets.
    virtual ~AIPlayBook();
    virtual int convertTargetNameToIntType(char* name);
    virtual int convertTargetCharacteristicNameToIntType(char* name);
    virtual int convertUnitNameToIntType(char* name);
    virtual int convertUnitToIntType(RGE_Static_Object* object);

    int numberPlaysValue;
    char nameValue[0x40];
    char gap_48[4];
    AIPlay* plays;

    int loadPlays(char* filename);
};

class XYZ {
public:
    int xValue;
    int yValue;
    int zValue;

    XYZ();
    XYZ(int x, int y, int z);
    void rotateXYByFacet(const XYZ& facet, XYZ& output,
                         unsigned char facetIndex);
};
#endif

int AIPlayBook::loadPlays(char* filename) {
    int temp4;
    int phaseValue1;
    int currentPhase;
    int phaseState;
    int j;
    int groupPhase;
    int currentPlay;
    int refPhase;
    int i;
    int temp8;
    int temp7;
    int fileValue;
    FILE* file;
    char temp2[0x100];
    char temp[0x100];
    char temp6[0x100];


    if (filename == 0 || strcmp(filename, s_NONE) == 0) {
        strcpy(this->nameValue, filename != 0 ? s_NONE : s_NULL);
        return 0;
    }

    strncpy(this->nameValue, filename, 0x40);
    sprintf(temp + 4, s_format_percent_s, this->nameValue);
    file = fopen(temp + 4, s_mode_r);
    if (file == 0) {
        return 0;
    }

    if (this->plays != 0) {
        operator_delete(this->plays);
        this->plays = 0;
    }
    this->numberPlaysValue = 0;

    while (fgets(temp + 4, 0x100, file) != 0) {
        if (strlen(temp + 4) == 0) {
            continue;
        }

        sscanf(temp + 4, s_format_percent_s_space, temp2 + 4);
        if (strcmp(temp2 + 4, s_Play) == 0) {
            this->numberPlaysValue += 8;
        }
    }

    if (this->numberPlaysValue > 0x3E80) {
        this->numberPlaysValue = 0x3E80;
    }

    this->plays = new AIPlay[this->numberPlaysValue];
    if (this->plays == 0) {
        return 0;
    }

    rewind(file);
    refPhase = -1;
    phaseState = -1;

    while (refPhase < 0x3E80 && fgets(temp + 4, 0x100, file) != 0) {
        if (strlen(temp + 4) == 0) {
            continue;
        }

        strcpy(temp2 + 4, s_592A40);
        strcpy(temp6 + 4, s_592A40);
        temp4 = 0;
        phaseValue1 = 0;
        i = 0;
        fileValue = 0;
        temp7 = 0;

        // BINARY NOTE: VC5 writes the two comment bytes into byte 3 of int
        // homes.  The adjacent phase state has a separate home.
        if (sscanf(temp + 4, s_format_comment,
                  ((char*)&j) + 3, ((char*)&currentPhase) + 3) == -1) {
            continue;
        }
        if (((char*)&j)[3] == '/' && ((char*)&currentPhase)[3] == '/') {
            continue;
        }

        sscanf(temp + 4, s_format_percent_s_space, temp2 + 4);
        if (strcmp(temp2 + 4, s_Play) == 0) {
            temp4 = 0;
            i = 0;
            while (temp[i + 4] != '"') {
                ++i;
                ++temp4;
            }
            ++i;
            ++temp4;

            phaseValue1 = temp4;
            while (temp[i + 4] != '"') {
                ++i;
                ++phaseValue1;
            }

            if (temp4 < phaseValue1) {
                memcpy(temp2 + 4, temp + temp4 + 4, phaseValue1 - temp4);
            }
            temp2[4 + (phaseValue1 - temp4)] = 0;

            ++refPhase;
            if (refPhase >= 0x3E80) {
                break;
            }
            this->plays[refPhase].setName(temp2 + 4);
        } else if (strcmp(temp2 + 4, s_PlayType) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_string, temp2 + 4);
            this->plays[refPhase].typeValue =
                this->plays[refPhase].convertToIntType(temp2 + 4);
        } else if (strcmp(temp2 + 4, s_MinUnits) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            this->plays[refPhase].minimumNumberUnitsValue = (unsigned char)temp4;
        } else if (strcmp(temp2 + 4, s_MaxUnits) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            this->plays[refPhase].maximumNumberUnitsValue = (unsigned char)temp4;
        } else if (strcmp(temp2 + 4, s_Power) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            this->plays[refPhase].powerValue = (unsigned char)temp4;
        } else if (strcmp(temp2 + 4, s_Overflow) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_string, temp2 + 4);
            if (strcmp(temp2 + 4, s_Balance) == 0) {
                this->plays[refPhase].overflowValue = 1;
            } else if (strcmp(temp2 + 4, s_FirstGroup) == 0) {
                this->plays[refPhase].overflowValue = 2;
            }
        } else if (strcmp(temp2 + 4, s_DeathPercentage) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            if (temp4 < 0) {
                this->plays[refPhase].deathPercentageValue = 0;
            } else if (temp4 > 100) {
                this->plays[refPhase].deathPercentageValue = 100;
            } else {
                this->plays[refPhase].deathPercentageValue = (unsigned char)temp4;
            }
        } else if (strcmp(temp2 + 4, s_Intelligence) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            if (temp4 < 0) {
                this->plays[refPhase].intelligenceValue = 0;
            } else if (temp4 > 100) {
                this->plays[refPhase].intelligenceValue = 100;
            } else {
                this->plays[refPhase].intelligenceValue = (unsigned char)temp4;
            }
        } else if (strcmp(temp2 + 4, s_TargetChar) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_string, temp6 + 4);
            int characteristic = this->convertTargetCharacteristicNameToIntType(temp6 + 4);
            if (characteristic != 0) {
                this->plays[refPhase].addTargetCharacteristic((unsigned char)characteristic);
            }
        } else if (strcmp(temp2 + 4, s_TargetType) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_string, temp6 + 4);
            int type = this->convertTargetNameToIntType(temp6 + 4);
            if (type != 0) {
                this->plays[refPhase].addTargetType((unsigned char)type);
            }
        } else if (strcmp(temp2 + 4, s_NumberGroups) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            this->plays[refPhase].numberGroupsValue = (unsigned char)temp4;
        } else if (strcmp(temp2 + 4, s_Group) == 0 && refPhase != -1 && phaseState == -1) {
            sscanf(temp + 4, s_format_group_range,
                   &temp4, temp6 + 4, &phaseValue1, &i);
            if (temp4 >= 0 && temp4 < 5) {
                int groupType = this->convertUnitNameToIntType(temp6 + 4);
                if (groupType != -1) {
                    int minimumValue = phaseValue1;
                    if (minimumValue < 0) {
                        minimumValue = 0;
                    }
                    this->plays[refPhase].group(temp4)->setMinimum(
                        groupType, (unsigned char)minimumValue);

                    int maximumValue = i;
                    if (maximumValue > 50) {
                        maximumValue = 50;
                    }
                    this->plays[refPhase].group(temp4)->setMaximum(
                        groupType, (unsigned char)maximumValue);
                }
            }
        } else if (strcmp(temp2 + 4, s_Phase) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            // BINARY NOTE: Phase updates the state used by later Group lines.
            phaseState = temp4;
        } else if (strcmp(temp2 + 4, s_Group) == 0 && refPhase != -1 && phaseState != -1) {
            sscanf(temp + 4, s_format_command,
                   &temp4, temp6 + 4, &phaseValue1, &i, &fileValue);
            if (temp4 >= 0 && temp4 < 5) {
                AIPlayPhase* phase = this->plays[refPhase].phase(phaseState);
                    AIPlayPhaseCommand command(
                    (unsigned char)temp4, temp6 + 4, phaseValue1, i, fileValue);
                phase->addCommand(command);
            }
        } else if (strcmp(temp2 + 4, s_Trigger) == 0 && refPhase != -1 && phaseState != -1) {
            sscanf(temp + 4, s_format_trigger,
                   &temp4, temp6 + 4, &phaseValue1, &temp7);
            if (temp4 >= 0 && temp4 < 5) {
                AIPlayPhase* phase = this->plays[refPhase].phase(phaseState);
                AIPlayPhaseTrigger trigger(
                    temp6 + 4, phaseValue1, temp7,
                    (unsigned char)phaseState, (unsigned char)temp4, 0);
                phase->addTrigger(trigger);
            }
        } else if (strcmp(temp2 + 4, s_RTrigger) == 0 && refPhase != -1 && phaseState != -1) {
            sscanf(temp + 4, s_format_command,
                   &temp4, temp6 + 4, &phaseValue1, &temp7, &fileValue);
            if (temp4 >= 0 && temp4 < 5) {
                AIPlayPhase* phase = this->plays[refPhase].phase(phaseState);
                AIPlayPhaseTrigger rtrigger(
                    temp6 + 4, phaseValue1, temp7,
                    (unsigned char)phaseState, (unsigned char)temp4, fileValue);
                phase->addTrigger(rtrigger);
            }
        } else if (strcmp(temp2 + 4, s_EndPlay) == 0 && refPhase != -1) {
            int oldPhase = refPhase;
            phaseState = -1;
            strcpy(temp2 + 4, this->plays[oldPhase].nameValue);
            if (temp2[4] == 'H' && temp2[5] == 'P') {
                this->numberPlaysValue -= 7;
                refPhase = oldPhase;
            } else {
                refPhase = oldPhase + 7;
                temp8 = 1;
                do {
                    sprintf(temp2 + 4, s_format_play_variant,
                            this->plays[oldPhase].nameValue, temp8);
                    this->plays[oldPhase + temp8].setName(temp2 + 4);
                    this->plays[oldPhase + temp8].typeValue =
                        this->plays[oldPhase].typeValue;
                    this->plays[oldPhase + temp8].minimumNumberUnitsValue =
                        this->plays[oldPhase].minimumNumberUnitsValue;
                    this->plays[oldPhase + temp8].maximumNumberUnitsValue =
                        this->plays[oldPhase].maximumNumberUnitsValue;
                    this->plays[oldPhase + temp8].powerValue =
                        this->plays[oldPhase].powerValue;
                    this->plays[oldPhase + temp8].overflowValue =
                        this->plays[oldPhase].overflowValue;
                    this->plays[oldPhase + temp8].deathPercentageValue =
                        this->plays[oldPhase].deathPercentageValue;
                    this->plays[oldPhase + temp8].intelligenceValue =
                        this->plays[oldPhase].intelligenceValue;

                    int targetIndex = 0;
                    do {
                        this->plays[oldPhase + temp8].addTargetType(
                            this->plays[oldPhase].targetType(targetIndex));
                        this->plays[oldPhase + temp8].addTargetCharacteristic(
                            this->plays[oldPhase].targetCharacteristic(targetIndex));
                        ++targetIndex;
                    } while (targetIndex < 5);

                    this->plays[oldPhase + temp8].numberGroupsValue =
                        this->plays[oldPhase].numberGroupsValue;
                    groupPhase = 0;
                    do {
                        AIPlayGroup* source = this->plays[oldPhase].group(groupPhase);
                        AIPlayGroup* destination =
                            this->plays[oldPhase + temp8].group(groupPhase);
                        int groupIndex = 0;
                        do {
                            destination->setMinimum(
                                groupIndex, source->minimum(groupIndex));
                            destination->setMaximum(
                                groupIndex, source->maximum(groupIndex));
                            ++groupIndex;
                        } while (groupIndex < 6);
                        ++groupPhase;
                    } while (groupPhase < 5);

                    groupPhase = 0;
                    do {
                        AIPlayPhase* sourcePhase =
                            this->plays[oldPhase].phase(groupPhase);
                        AIPlayPhase* destinationPhase =
                            this->plays[oldPhase + temp8].phase(groupPhase);
                        currentPlay = 0;
                        do {
                            AIPlayPhaseCommand* command =
                                sourcePhase->command(currentPlay);
                            if (command->typeValue == 1) {
                                XYZ origin(0, 0, 0);
                                XYZ rotatedPoint;
                                XYZ originalPoint(command->value1Value,
                                                  command->value2Value,
                                                  command->value3Value);
                                originalPoint.rotateXYByFacet(
                                    origin, rotatedPoint, (unsigned char)temp8);
                                AIPlayPhaseCommand newCommand(
                                    command->groupValue, command->typeValue,
                                    rotatedPoint.yValue, rotatedPoint.zValue,
                                    originalPoint.xValue);
                                command = &newCommand;
                            }
                            destinationPhase->addCommand(*command);
                            ++currentPlay;
                        } while (currentPlay < 5);

                        int triggerIndex = 0;
                        do {
                            destinationPhase->addTrigger(
                                *sourcePhase->trigger(triggerIndex));
                            ++triggerIndex;
                        } while (triggerIndex < 3);
                        ++groupPhase;
                    } while (groupPhase < 10);

                    ++temp8;
                } while (temp8 < 8);
            }
        }

    }

    fclose(file);
    return 1;
}
