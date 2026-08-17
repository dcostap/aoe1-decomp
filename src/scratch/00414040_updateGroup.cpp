// VA: 00414040 UnitAIModule::updateGroup (1831B)
// aiuaimod.cpp
// Attempt log:
// - Replaced the unrelated placeholder with a typed reconstruction from the
//   play-status, group-member, and phase-trigger ownership in the binary.
// - Baseline follows the original three trigger checks, group rebuild path,
//   and phase-255 group fill path. Exact codegen remains under investigation.
// - Corrected object virtual slots (+1B8, +1BC, +1C8), target coordinates,
//   world_time at +04, and the groupList+1 member array from the assembly.
// - Separated the dead-group count from its eight-byte grouping scan offset.
// - Eight probes reached exact call-set parity, but the remaining gap is a
//   broad VC5 frame and block-layout difference. No productive codegen lead
//   remains in this assignment.
// - Tried the period ManagedArray<int>::operator[] donor at both the first
//   comparison and the later lookup. The repeated operator[] added one growth
//   call pair and was rolled back.
// - Kept operator[] only for the first comparison and phase-255 member read;
//   direct value access remains after the separate resize call. This improved
//   the structural check to 1714 differing bytes with exact call parity.
// - Tried initializing the typed groupList sentinel before the phase-255 fill;
//   the original zero store supports this group-layout hypothesis.
// - Rolled back the sentinel initialization: it worsened the positional diff
//   from 1714 to 1767 bytes and increased the rebuilt size by four bytes.
// - This claim tested the combined outer play guard, array-pointer and loop-index
//   spellings, and a repeated phase-command temporary. The best emitted code
//   stayed at 1714 differing bytes and 42 aligned calls.
// - Reversing the equivalent distance threshold improved resync similarity but
//   worsened positional equality to 1762 bytes; restored the clean source.
// - This claim tested 24 distinct structural, lifetime, ABI, and layout probes.
// - Directly rereading currentPhaseValue removed its stack byte and reduced the
//   diff to 1646 bytes. Branch-local member results in trigger types 8 and 9
//   reduced it to 1611 bytes and kept the source natural.
// - Removing dead play initialization and testing a 52-entry groupList reached
//   the best provisional metric: 1601 bytes, exact 0xFC frame, 42 calls.
//   The 52-entry array is not retained because the binary does not prove it.
// - The clean 50-entry array now gives 1602 bytes, frame 0xF4, and 42 calls.
// - Positive guard forms, integer target-ID typing, local declaration scopes,
//   loop-form changes, address aliases, a volatile diagnostic, and threshold
//   variants either duplicated output or worsened the result.
// - Open blocker: the first mismatch is still the early zero-register and
//   target-recovery layout. The remaining drift is broad structural codegen.

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* block);

class UnitAIModule;
class AIPlay;
class AIPlayBook;
class AIPlayPhase;
class AIPlayPhaseTrigger;
class AIPlayPhaseCommand;
class AIPlayStatus;
class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int resize(int newSize);

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            T* newValue = (T*)operator new(newSize * sizeof(T));
            if (newValue != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < newSize;
                     i++) {
                    newValue[i] = this->value[i];
                }
                operator delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }
        return this->value[index];
    }
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    int world_time;
    char gap_08[0x98];
    AIPlayBook* playbook;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x22];
    short maximumHitPoints;
    char gap_28[0x08];
    float hitPoints;
};

#define VPAD1(n) virtual int vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x20];
    float hitPoints;
    char gap_34[0x04];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x04];
    unsigned char object_state;
    char gap_49[0x1B];
    ManagedArray<int> groupMembers;

    VPAD64(1)
    VPAD32(65)
    VPAD8(97)
    VPAD4(105)
    VPAD1(109)
    virtual int groupUnitCommand(int index, int mode);
    virtual int groupUnitCallback(int value);
    VPAD2(112)
    virtual int groupUnitCount();

    UnitAIModule* unitAI();
    float distance_to_position(float x, float y, float z);
};

class AIPlayBook {
public:
    AIPlay* play(int playNumber);
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
};

class AIPlayPhaseCommand {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    char gap_02[2];
    int value1Value;
    int value2Value;
    int value3Value;
};

class AIPlayPhase {
public:
    AIPlayPhaseTrigger* trigger(int index);
    AIPlayPhaseCommand* command(int index);
};

class AIPlay {
public:
    AIPlayPhase* phase(int phaseNumber);
    int groupGivenCommandOnPhase(int group, int commandType, int phase);
    int fillGroups(AIPlayStatus* status, int* groupList, int groupCount,
                   RGE_Game_World* world);
};

struct AIPlayGrouping {
    int id;
    unsigned char groupValue;
    unsigned char typeValue;
    char gap_06[2];
};

class AIPlayStatus {
public:
    AIPlayGrouping groupings[50];
    int playNumberValue;
    int targetValue;
    int originalPointX;
    int originalPointY;
    int originalPointZ;
    char gap_1A4[0x14];
    unsigned char currentPhaseValue;
    char gap_1B9[3];
    int savedAttackerValue;
    int lastPhaseChangeTimeValue;

    unsigned char group(int id);
    int originalHitPoints(int group);
    void setOriginalHitPoints(int group, int value);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    VPAD1(1) VPAD1(2) VPAD1(3) VPAD1(4) VPAD1(5) VPAD1(6)
    VPAD1(7) VPAD1(8) VPAD1(9) VPAD1(10) VPAD1(11)
    virtual int find_unit(int mode, int x, int y);

    RGE_Static_Object* objectValue;
    char gap_08[0x124];
    AIPlayStatus* playStatus;

    RGE_Static_Object* lookupObject(int id);
    int selectNewPlayPhase(int phase, int param_2);
    void updateGroup(unsigned long param_1);
};

#undef VPAD1

void UnitAIModule::updateGroup(unsigned long param_1)
{
    int triggerSatisfied;
    int deadCount;
    AIPlayPhaseTrigger* trigger;
    AIPlay* play;
    AIPlayPhase* phase;
    RGE_Static_Object* target;
    int i;
    int totalHitPoints[5];
    int groupList[50];

    if (this->playStatus != 0 &&
        (play = this->objectValue->owner->world->playbook->play(
             this->playStatus->playNumberValue)) != 0) {
    target = this->lookupObject(this->playStatus->targetValue);
        if (target == 0) {
            i = this->find_unit(1, 0, 0);
            RGE_Static_Object* object = this->objectValue;
            int memberIndex = 0;
            if (object->groupMembers.numberValue > 0) {
                do {
                    if (i != -1) {
                        goto foundTrigger;
                    }

                    object = this->objectValue;
                    if (object->groupMembers[memberIndex] != object->id) {
                        if (object->groupMembers.maximumSizeValue - 1 < memberIndex) {
                            object->groupMembers.resize(memberIndex + 1);
                        }
                        object = this->lookupObject(
                            object->groupMembers.value[memberIndex]);
                        if (object != 0 && object->unitAI() != 0) {
                            UnitAIModule* memberAI = object->unitAI();
                            i = memberAI->find_unit(1, 0, 0);
                        }
                    }

                    object = this->objectValue;
                    ++memberIndex;
                } while (memberIndex < object->groupMembers.numberValue);
            }

            if (i == -1) {
                operator delete(this->playStatus);
                this->playStatus = 0;
                return;
            }

foundTrigger:
            this->playStatus->targetValue = i;
            this->selectNewPlayPhase(
                (unsigned int)this->playStatus->currentPhaseValue, 0);
            target = this->lookupObject(i);
        }

        if (this->playStatus->currentPhaseValue == 0xFD) {
            totalHitPoints[1] = 0;
            totalHitPoints[2] = 0;
            totalHitPoints[3] = 0;
            totalHitPoints[4] = 0;
            int memberCount = 0;
            deadCount = 0;
            if (this->objectValue->groupMembers.numberValue > 0) {
                trigger = (AIPlayPhaseTrigger*)(groupList + 1);
                do {
                    RGE_Static_Object* member = this->lookupObject(
                        this->objectValue->groupMembers[deadCount]);
                    if (member != 0) {
                        *(int*)trigger = member->id;
                        ++memberCount;
                        trigger = (AIPlayPhaseTrigger*)((char*)trigger + 4);
                        int commandIndex = 0;
                        int commandCount = this->objectValue->groupUnitCount();
                        if (commandCount > 0) {
                            do {
                                int commandValue = this->objectValue->groupUnitCommand(
                                    commandIndex, 1);
                                member->groupUnitCallback(commandValue);
                                ++commandIndex;
                                commandCount = this->objectValue->groupUnitCount();
                            } while (commandIndex < commandCount);
                        }
                    }

                    ++deadCount;
                } while (deadCount < this->objectValue->groupMembers.numberValue);
            }

            this->playStatus->lastPhaseChangeTimeValue =
                this->objectValue->owner->world->world_time;
            play->fillGroups(this->playStatus, groupList + 1, memberCount,
                             this->objectValue->owner->world);
            if (memberCount > 0) {
                int* group = groupList + 1;
                int remaining = memberCount;
                do {
                    ++group;
                    RGE_Static_Object* member = this->lookupObject(*group);
                    unsigned char groupNumber =
                        this->playStatus->group(*group);
                    int hitPoints = (int)member->hitPoints;
                    totalHitPoints[groupNumber + 1] += hitPoints;
                    --remaining;
                } while (remaining != 0);
            }

            i = 0;
            do {
                this->playStatus->setOriginalHitPoints(
                    i, totalHitPoints[i + 1]);
                ++i;
            } while (i < 5);
            this->selectNewPlayPhase(0, 0);
            return;
        }

        phase = play->phase((unsigned int)this->playStatus->currentPhaseValue);
        if (phase != 0) {
            totalHitPoints[0] = 0;
            do {
                trigger = phase->trigger(totalHitPoints[0]);
                i = 0;
                if (trigger != 0 && trigger->typeValue != 0) {
                    switch (trigger->typeValue) {
                    case 1: {
                        triggerSatisfied = 1;
                        int group = 0;
                        do {
                            if (triggerSatisfied == 0) {
                                break;
                            }
                            int command = play->groupGivenCommandOnPhase(
                                group, 1, this->playStatus->currentPhaseValue);
                            if (command != -1) {
                                AIPlayPhaseCommand* phaseCommand =
                                    phase->command(command);
                                int groupingOffset = 0;
                                do {
                                    if (triggerSatisfied == 0) {
                                        break;
                                    }
                                    AIPlayGrouping* grouping =
                                        (AIPlayGrouping*)((char*)this->playStatus +
                                                          groupingOffset);
                                    if (grouping->groupValue == group) {
                                        RGE_Static_Object* member =
                                            this->lookupObject(grouping->id);
                                        if (member != 0) {
                                            float distance =
                                                member->distance_to_position(
                                                    (float)phaseCommand->value1Value +
                                                        target->world_x,
                                                    (float)phaseCommand->value2Value +
                                                        target->world_y,
                                                    (float)phaseCommand->value2Value +
                                                        target->world_z);
                                            if ((float)trigger->value1Value < distance) {
                                                triggerSatisfied = 0;
                                            }
                                        }
                                    }
                                    groupingOffset += 8;
                                } while (groupingOffset < 400);
                            }
                            ++group;
                        } while (group < 5);
                        break;
                    }
                    case 2: {
                        int matchingGroups = 0;
                        int deadGroups = 0;
                        int groupingOffset = 0;
                        do {
                            AIPlayGrouping* grouping =
                                (AIPlayGrouping*)((char*)this->playStatus +
                                                  groupingOffset);
                            if ((unsigned int)grouping->groupValue ==
                                (unsigned int)trigger->value1Value) {
                                ++matchingGroups;
                                RGE_Static_Object* member =
                                    this->lookupObject(grouping->id);
                                if (member == 0 || member->object_state > 2) {
                                    ++deadGroups;
                                }
                            }
                            groupingOffset += 8;
                        } while (groupingOffset < 400);
                        if (matchingGroups != 0 &&
                            trigger->value2Value <= (deadGroups * 100) /
                                matchingGroups) {
                            triggerSatisfied = 1;
                        }
                        break;
                    }
                    case 3: {
                        int lostHitPoints = 0;
                        int groupingOffset = 0;
                        do {
                            AIPlayGrouping* grouping =
                                (AIPlayGrouping*)((char*)this->playStatus +
                                                  groupingOffset);
                            if ((unsigned int)grouping->typeValue ==
                                (unsigned int)trigger->value1Value) {
                                RGE_Static_Object* member =
                                    this->lookupObject(grouping->id);
                                if (member != 0) {
                                    lostHitPoints += (int)member->hitPoints;
                                }
                            }
                            groupingOffset += 8;
                        } while (groupingOffset < 400);
                        int original = this->playStatus->originalHitPoints(
                            trigger->value1Value);
                        if (trigger->value2Value <=
                            ((original - lostHitPoints) * 100) /
                                this->playStatus->originalHitPoints(
                                    trigger->value1Value)) {
                            triggerSatisfied = 1;
                        }
                        break;
                    }
                    case 8: {
                        triggerSatisfied = 1;
                        int groupingOffset = 0;
                        do {
                            if (triggerSatisfied == 0) {
                                break;
                            }
                            AIPlayGrouping* grouping =
                                (AIPlayGrouping*)((char*)this->playStatus +
                                                  groupingOffset);
                            if ((unsigned int)grouping->groupValue ==
                                    (unsigned int)trigger->value1Value) {
                                RGE_Static_Object* member =
                                    this->lookupObject(grouping->id);
                                if (member != 0 && member->object_state == 2) {
                                    triggerSatisfied = 0;
                                }
                            }
                            groupingOffset += 8;
                        } while (groupingOffset < 400);
                        break;
                    }
                    case 9: {
                        triggerSatisfied = 1;
                        int groupingOffset = 0;
                        do {
                            if (triggerSatisfied == 0) {
                                break;
                            }
                            AIPlayGrouping* grouping =
                                (AIPlayGrouping*)((char*)this->playStatus +
                                                  groupingOffset);
                            if ((unsigned int)grouping->typeValue ==
                                    (unsigned int)trigger->value1Value) {
                                RGE_Static_Object* member =
                                    this->lookupObject(grouping->id);
                                if (member != 0 &&
                                    (int)member->hitPoints <
                                        member->master_obj->maximumHitPoints) {
                                    triggerSatisfied = 0;
                                }
                            }
                            groupingOffset += 8;
                        } while (groupingOffset < 400);
                        break;
                    }
                    case 10:
                        triggerSatisfied = 1;
                        break;
                    case 11:
                        if (trigger->value1Value <
                            (this->objectValue->owner->world->world_time -
                             this->playStatus->lastPhaseChangeTimeValue) /
                                1000) {
                            triggerSatisfied = 1;
                        }
                        break;
                    default:
                        break;
                    }

                    if (triggerSatisfied &&
                        this->selectNewPlayPhase(trigger->nextPhaseValue, 0) == 1) {
                        return;
                    }
                }
                ++totalHitPoints[0];
            } while (totalHitPoints[0] < 3);
            this->selectNewPlayPhase(
                this->playStatus->currentPhaseValue, 1);
        }
    }
}
