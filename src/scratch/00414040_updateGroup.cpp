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
// - Restored the PDB-listed gatherDistance as the distance result local. The
//   reversed distance > threshold form recovers the original fcompp/test 41h
//   x87 predicate shape and reduced the clean diff to 1600 bytes.
// - Restored the PDB-listed newTarget, groupCount, and a locals. A dedicated i
//   counter for the three-trigger phase loop moved the frame to 0xF8 and the
//   diff to 1598 bytes. A typed int* group-list cursor raises shape similarity
//   to 75.25% with 27.38% exact-block coverage.
// - BINARY NOTE: the phase-255 path zeros all five totalHitPoints entries.
//   It indexes that typed array by group and publishes totalHitPoints[i].
//   The group-list cursor starts at groupList + 1 and advances after each
//   member. These forms preserve the observed typed array addresses.
// - Open blocker: the executable frame is 0xFC and this natural source frame
//   is 0xF8. The first mismatch remains the prologue. Direct calls and their
//   order match, but broad control-flow drift remains.
// MANAGEDARRAY AUDIT: group-member growth guards, copies, publication, resize,
// value reads, and field offsets follow the expected template behavior. No
// shared template change is required.
// BLOCKER: The executable frame is 0xFC and the natural source frame is 0xF8.
// A 52-entry group list fixes only the frame and adds unsupported local storage.
// Broad CFG drift also remains despite all 42 calls aligning.
// Canonical-context pass: this owner uses the PDB aiuaimod.cpp surfaces and
// the real bestUnitToAttack slot at vtable +0x30. The source has 42 direct
// calls in the oracle order. The full prefix through 00414800 keeps this body
// in the same code-generation basin. Do not change 00413AB0 queue indexing
// or its timer and current-order publication while testing this owner.
// - Captain probe: a separate initial-target local was codegen-identical and
//   was restored. The grouped result remains 1520 differing bytes, 0xF8 frame.

#include "../../include/aiuaimod_context.h"

void UnitAIModule::updateGroup(unsigned long param_1)
{
    RGE_Static_Object* target;
    int newTarget;
    AIPlay* play;
    AIPlayPhase* phase;
    int totalHitPoints[5];
    int groupList[50];
    int triggerSatisfied;
    AIPlayPhaseTrigger* trigger;
    float gatherDistance;
    int deadCount;
    int a;
    int groupCount;

    if (this->playStatus &&
        (play = this->objectValue->owner->world->playbook->play(
             this->playStatus->playNumberValue)) != 0) {
        target = this->lookupObject(this->playStatus->targetValue);
        if (!target) {
            newTarget = this->bestUnitToAttack(1, 0, (float*)0);
            RGE_Static_Object* object = this->objectValue;
            int memberIndex = 0;
            if (object->groupMembers.numberValue > 0) {
                do {
                    if (newTarget != -1) {
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
                            newTarget = memberAI->bestUnitToAttack(1, 0, (float*)0);
                        }
                    }

                    object = this->objectValue;
                    ++memberIndex;
                } while (memberIndex < object->groupMembers.numberValue);
            }

            if (newTarget == -1) {
                operator delete(this->playStatus);
                this->playStatus = 0;
                return;
            }

foundTrigger:
            this->playStatus->targetValue = newTarget;
            this->selectNewPlayPhase(
                (unsigned int)this->playStatus->currentPhaseValue, 0);
            target = this->lookupObject(newTarget);
        }

        if (this->playStatus->currentPhaseValue == 0xFD) {
            totalHitPoints[0] = 0;
            totalHitPoints[1] = 0;
            totalHitPoints[2] = 0;
            totalHitPoints[3] = 0;
            totalHitPoints[4] = 0;
            groupCount = 0;
            deadCount = 0;
            if (this->objectValue->groupMembers.numberValue > 0) {
                int* groupListCursor = groupList + 1;
                do {
                    RGE_Static_Object* member = this->lookupObject(
                        this->objectValue->groupMembers[deadCount]);
                    if (member != 0) {
                        *groupListCursor = member->id;
                        ++groupCount;
                        ++groupListCursor;
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
            play->fillGroups(this->playStatus, groupList + 1, groupCount,
                             this->objectValue->owner->world);
            if (groupCount > 0) {
                int* group = groupList + 1;
                int remaining = groupCount;
                do {
                    RGE_Static_Object* member = this->lookupObject(*group);
                    totalHitPoints[this->playStatus->group(*group)] +=
                        (int)member->hitPoints;
                    --remaining;
                    ++group;
                } while (remaining != 0);
            }

            int i = 0;
            do {
                this->playStatus->setOriginalHitPoints(
                    i, totalHitPoints[i]);
                ++i;
            } while (i < 5);
            this->selectNewPlayPhase(0, 0);
            return;
        }

        phase = play->phase((unsigned int)this->playStatus->currentPhaseValue);
        if (phase) {
            int i = 0;
            do {
                trigger = phase->trigger(i);
                if (trigger != 0 && trigger->typeValue != 0) {
                    switch (trigger->typeValue) {
                    case 1: {
                        triggerSatisfied = 1;
                        a = 0;
                        while (triggerSatisfied != 0) {
                            int command = play->groupGivenCommandOnPhase(
                                a, 1, this->playStatus->currentPhaseValue);
                            if (command != -1) {
                                AIPlayPhaseCommand* phaseCommand =
                                    phase->command(command);
                                int groupingOffset = 0;
                                while (triggerSatisfied != 0 &&
                                       groupingOffset < 400) {
                                    AIPlayGrouping* grouping =
                                        (AIPlayGrouping*)((char*)this->playStatus +
                                                          groupingOffset);
                                    if (grouping->groupValue == a) {
                                        RGE_Static_Object* member =
                                            this->lookupObject(grouping->id);
                                        if (member != 0) {
                                            gatherDistance =
                                                member->distance_to_position(
                                                    (float)phaseCommand->value1Value +
                                                        target->world_x,
                                                    (float)phaseCommand->value2Value +
                                                        target->world_y,
                                                    (float)phaseCommand->value2Value +
                                                        target->world_z);
                                            if (gatherDistance >
                                                (float)trigger->value1Value) {
                                                triggerSatisfied = 0;
                                            }
                                        }
                                    }
                                    groupingOffset += 8;
                                }
                            }
                            ++a;
                            if (a >= 5) {
                                break;
                            }
                        }
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
                ++i;
            } while (i < 3);
            this->selectNewPlayPhase(
                this->playStatus->currentPhaseValue, 1);
        }
    }
}
