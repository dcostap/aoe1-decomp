// VA: 00414800 UnitAIModule::selectNewPlayPhase (1298B)
// aiuaimod.cpp
// Period-plausible reconstruction of play-phase command selection.
//
// Attempt log:
// - Replaced the raw-pointer placeholder with typed playbook, phase-command,
//   group-member, and UnitAIModule ownership.
// - The source keeps all 25 ordered calls and the original direct-call ABI set.
// - Binary tests covered branch shape, loop form, local scope, point layout,
//   coordinate load order, vtable context, and case-5 result lifetime.
// - The case-5 scan uses groupValue at grouping offset +4. The original loads
//   this byte before lookup. It reuses param_1 for the found object id.
// - The case-5 scan increments its 8-byte cursor after the body and compares
//   it with 0x190.
// - The member filter uses a nested guard and reuses param_1 for the group
//   byte. The original writes that value before group() and compares it after.
// - The play number is read before the object/world/playbook receiver.
// - The case-1 phase byte is a narrow local. The case-3 value is loaded before
//   unitAI(). Cases 4 and 8 load their integer fields before unitAI().
// - The case-5 scan uses a while loop. This emits the original jl backedge.
// - Case 5 reads found->hitPoints and master_obj->maximumHitPoints. These are
//   the object and master fields proven by the corrected canonical ABI.
// - The current natural source is 1216 rebuilt bytes versus 1298 original
//   bytes, with a 0x2C frame and 934 strict differing bytes.
// - Direct order calls improved shape but added one virtual call. They were
//   not retained because the original has 25 ordered calls.
//
// Current status: structural reconstruction remains incomplete. Keep this
// readable common-tail source as the best behavior-backed candidate.
// MANAGEDARRAY AUDIT: group-member capacity checks, resize calls, value reads,
// and field offsets follow the expected template behavior. No shared template
// change is required.
// BLOCKER: The rebuild is 82 bytes short, with a 0x2C frame versus 0x44 and 34
// fewer instructions. Broad register and local-lifetime recovery remains
// incomplete despite all 25 calls aligning.
// Canonical-context pass: this owner now uses the PDB aiuaimod.cpp surfaces.
// Its 1216-byte body, 0x2C frame, 25 calls, and 934-byte diff stay unchanged.
// The corrected object and master hit-point fields follow updateGroup.

#include "../../include/aiuaimod_context.h"

int UnitAIModule::selectNewPlayPhase(int param_1, int param_2)
{
    int phase = 0;
    AIPlayPhase* phaseObject;
    RGE_Static_Object* target;
    AIPlay* play;

    if (this->playStatus == 0) {
        return 0;
    }

    int playNumber = this->playStatus->playNumberValue;
    play = this->objectValue->owner->world->playbook->play(playNumber);
    if (play == 0) {
        return 0;
    }

    if (param_1 == 0xFE) {
        operator delete(this->playStatus);
        this->playStatus = 0;
        return 1;
    }

    phaseObject = play->phase(param_1);
    if (phaseObject == 0) {
        return 0;
    }

    target = this->lookupObject(this->playStatus->targetValue);
    if (target == 0) {
        return 0;
    }

    this->playStatus->currentPhaseValue = (unsigned char)param_1;

    phase = 0;
    do {
        AIPlayPhaseCommand* command = phaseObject->command(phase);
        if (command != 0 && command->typeValue != 0) {
            if ((command->typeValue == 6 || command->typeValue == 7) &&
                param_2 == 0) {
                switch (command->typeValue) {
                case 6:
                    this->playStatus->resetHitPoints(
                        command->groupValue, this->objectValue->owner->world);
                    break;
                case 7:
                    this->playStatus->removeDeadUnits(
                        command->groupValue, this->objectValue->owner->world);
                    break;
                }
            } else {
                int i = 0;
                RGE_Static_Object* member = this->objectValue;
                if (member->groupMembers.numberValue > 0) {
                    do {
                        if (i > member->groupMembers.maximumSizeValue - 1) {
                            member->groupMembers.resize(i + 1);
                        }

                        member = this->lookupObject(
                            member->groupMembers.value[i]);
                        if (member != 0 && member->unitAI() != 0) {
                            param_1 = command->groupValue;
                            if (this->playStatus->group(member->id) !=
                                (unsigned char)param_1) {
                                goto next_member;
                            }
                            if (param_2 == 1 &&
                                member->unitAI()->currentAction() != -1) {
                                goto next_member;
                            }
                            int orderAction;
                            int orderTargetOwner;
                            float orderX;
                            float orderY;
                            float orderZ;
                            UnitAIModule* memberAI;

                            switch (command->typeValue) {
                            case 1: {
                                int distance = (int)member->distance_to_position(
                                    (float)command->value1Value + target->world_x,
                                    (float)command->value2Value + target->world_y,
                                    (float)command->value3Value + target->world_z);
                                unsigned char currentPhase =
                                    this->playStatus->currentPhaseValue;
                                if (distance > play->gatherTolerance(
                                        command->groupValue,
                                        currentPhase)) {
                                    memberAI = member->unitAI();
                                    orderAction = 0x2C6;
                                    param_1 = -1;
                                    orderTargetOwner = -1;
                                    orderX = (float)command->value1Value + target->world_x;
                                    orderY = (float)command->value2Value + target->world_y;
                                    orderZ = (float)command->value3Value + target->world_z;
                                    break;
                                }
                                goto next_member;
                            }
                            case 2: {
                                memberAI = member->unitAI();
                                int targetOwnerId = target->owner->id;
                                int targetId = target->id;
                                orderAction = 0x2BC;
                                orderTargetOwner = targetOwnerId;
                                param_1 = targetId;
                                orderX = -1.0f;
                                orderY = -1.0f;
                                orderZ = -1.0f;
                                break;
                            }
                            case 3:
                                param_1 = this->playStatus->savedAttackerValue;
                                memberAI = member->unitAI();
                                orderAction = 0x2BC;
                                orderTargetOwner = -1;
                                orderX = -1.0f;
                                orderY = -1.0f;
                                orderZ = -1.0f;
                                break;
                            case 4: {
                                int pointX = this->playStatus->originalPointX;
                                int pointY = this->playStatus->originalPointY;
                                int pointZ = this->playStatus->originalPointZ;
                                orderAction = 0x2C6;
                                param_1 = -1;
                                orderTargetOwner = -1;
                                memberAI = member->unitAI();
                                orderX = (float)pointX;
                                orderY = (float)pointY;
                                orderZ = (float)pointZ;
                                break;
                            }
                            case 5: {
                                param_1 = -1;
                                int groupingOffset = 0;
                                while (groupingOffset < 0x190) {
                                    AIPlayGrouping* grouping =
                                        (AIPlayGrouping*)((char*)this->playStatus + groupingOffset);
                                    if (grouping->groupValue == command->value1Value) {
                                        RGE_Static_Object* found =
                                            this->lookupObject(grouping->id);
                                        if (found != 0 &&
                                            (int)found->hitPoints + 1 <
                                                found->master_obj->maximumHitPoints) {
                                            param_1 = found->id;
                                            break;
                                        }
                                    }
                                    groupingOffset += 8;
                                }
                                if (param_1 == -1) {
                                    goto next_member;
                                }
                                memberAI = member->unitAI();
                                orderAction = 0x2BF;
                                orderTargetOwner = -1;
                                orderX = -1.0f;
                                orderY = -1.0f;
                                orderZ = -1.0f;
                                break;
                            }
                            case 8: {
                                int commandX = command->value1Value;
                                int commandY = command->value2Value;
                                int commandZ = command->value3Value;
                                memberAI = member->unitAI();
                                orderAction = 0x2D8;
                                param_1 = -1;
                                orderTargetOwner = -1;
                                orderX = (float)commandX + target->world_x;
                                orderY = (float)commandY + target->world_y;
                                orderZ = (float)commandZ + target->world_z;
                                break;
                            }
                            default:
                                goto next_member;
                            }

                            memberAI->order(
                                this->objectValue->id, orderAction, param_1,
                                orderTargetOwner, orderX, orderY, orderZ,
                                1.0f, 1, 0, 100);
                        }

                    next_member:
                        ++i;
                        member = this->objectValue;
                    } while (i < this->objectValue->groupMembers.numberValue);
                }
            }
        }

        ++phase;
    } while (phase < 5);

    return 1;
}
