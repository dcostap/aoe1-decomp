// 004F7870 TribeTacticalAIModule::numberWarshipsWithPriority
// taitacmd.cpp: 6953-7056
// Attempt log:
// - Prior source factored the repeated ManagedArray growth, duplicate scan,
//   and priority branches into helpers (752B); the packet instead shows two
//   long, source-level near-duplicate loops and the real resize/contains ABI.
// - Baseline candidate restores named warBoats/soldiers/workingArea/
//   unitsTaskedThisUpdate ownership, the binary's three priority modes, and
//   direct world/object/UnitAI calls.  Keep this file in scratch until the
//   repeated-loop register and stack-home topology is audited.
// - Duplicating the three warboat priority append arms recovered their six
//   missing resize/contains sites; restoring the negative soldier arm and
//   sharing its binary-proven workingArea tail recovered the full 47-call
//   multiset.  The best clean reconstruction is still 1425 bytes versus
//   1300, with a 0x14 versus 0x10 frame and first-register topology drift.
// - Separate Ghidra-backed soldier scan variables did not change emitted
//   code.  Left unresolved: source/context needed to keep this in ebp/ebx
//   topology and remove the remaining structural tail drift.
// - Reversed the soldier append forms to match the binary call order: the
//   equality arm scans workingArea, while the greater-priority arm uses
//   contains.  This restored the ordered 47-call surface.
// - Using local_8 as the proven byte offset in the warboat tasked-unit test
//   reduced the frame from 0x14 to 0x10.  The remaining prologue still uses
//   esi for this instead of the original ebp and keeps a 120-byte tail drift.
// - A direct workingArea.numberValue store in the greater arm preserves all
//   47 calls.  A separate pointer alias and declaration reorder had no effect.

struct RGE_Static_Object;
struct UnitAIModule;

struct RGE_Game_World {
    RGE_Static_Object* object(int id);
};

struct RGE_Player {
    char gap_00[0x3C];
    RGE_Game_World* world;
};

struct TribeMainDecisionAIModule {
    char gap_00[0x1256C];
    RGE_Player* aiPlayer;
};

struct UnitAIModule {
    int currentAction();
    int currentOrderPriority();
};

struct RGE_Master_Static_Object {
    char gap_00[0x14];
    short object_group;
};

struct RGE_Static_Object {
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    UnitAIModule* unitAI();
};

class ManagedArrayInt {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int resize(int new_size);
    int contains(const int& value);
};

class TribeTacticalAIModule_4F7870 {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_F4[0x114 - 0xF4];
    ManagedArrayInt soldiers;
    char gap_124[0x144 - 0x124];
    ManagedArrayInt warBoats;
    char gap_154[0xD48 - 0x154];
    ManagedArrayInt workingArea;
    ManagedArrayInt unitsTaskedThisUpdate;

    int numberWarshipsWithPriority(int priority, int compare);
};

int TribeTacticalAIModule_4F7870::numberWarshipsWithPriority(int priority, int compare)
{
    TribeTacticalAIModule_4F7870* local_4;
    ManagedArrayInt* warships;
    ManagedArrayInt* result;
    short objectGroup;
    RGE_Static_Object* object;
    UnitAIModule* ai;
    int value;
    int* values;
    int index;
    int scan;
    TribeTacticalAIModule_4F7870* tactical;
    TribeTacticalAIModule_4F7870* tactical2;
    int count;
    int i;
    int local_c;
    int local_8;

    i = 0;
    local_c = 0;
    local_4 = this;
    local_4->workingArea.numberValue = 0;

    if (local_4->warBoats.numberValue > 0) {
        warships = &local_4->warBoats;
        do {
            if (warships->maximumSizeValue - 1 < local_c)
                warships->resize(local_c + 1);
            local_8 = local_c * 4;
            object = local_4->md->aiPlayer->world->object(warships->value[local_c]);
            if (object != 0 && object->unitAI() != 0) {
                if (warships->maximumSizeValue - 1 < local_c)
                    warships->resize(local_c + 1);

                value = 0;
                if (local_4->unitsTaskedThisUpdate.numberValue > 0) {
                    do {
                        if (local_4->unitsTaskedThisUpdate.maximumSizeValue <= value)
                            break;
                        if (local_4->unitsTaskedThisUpdate.value[value] ==
                            *(int *)((char *)warships->value + local_8))
                            goto next_warboat;
                        ++value;
                    } while (value < local_4->unitsTaskedThisUpdate.numberValue);
                }

                if (compare < 0) {
                    ai = object->unitAI();
                    value = ai->currentAction();
                    if (value != -1) {
                        ai = object->unitAI();
                        value = ai->currentOrderPriority();
                        if (priority <= value)
                            goto next_warboat;
                    }
                    if (warships->maximumSizeValue - 1 < local_c)
                        warships->resize(local_c + 1);
                    result = &local_4->workingArea;
                    local_8 = warships->value[local_c];
                    value = result->contains(local_8);
                    if (value != 1) {
                        value = result->numberValue;
                        if (result->maximumSizeValue - 1 < value)
                            result->resize(value + 1);
                        value = result->numberValue;
                        values = result->value;
                        values[value] = local_8;
                        result->numberValue++;
                    }
                    ++i;
                } else if (compare < 1) {
                    ai = object->unitAI();
                    value = ai->currentAction();
                    if (value != -1) {
                        ai = object->unitAI();
                        value = ai->currentOrderPriority();
                        if (value != priority)
                            goto next_warboat;
                        if (warships->maximumSizeValue - 1 < local_c)
                            warships->resize(local_c + 1);
                        result = &local_4->workingArea;
                        local_8 = warships->value[local_c];
                        value = result->contains(local_8);
                        if (value != 1) {
                            value = result->numberValue;
                            if (result->maximumSizeValue - 1 < value)
                                result->resize(value + 1);
                            result->value[value] = local_8;
                            result->numberValue++;
                        }
                        ++i;
                    }
                } else {
                    ai = object->unitAI();
                    value = ai->currentAction();
                    if (value != -1) {
                        ai = object->unitAI();
                        value = ai->currentOrderPriority();
                        if (priority >= value)
                            goto next_warboat;
                        if (warships->maximumSizeValue - 1 < local_c)
                            warships->resize(local_c + 1);
                        result = &local_4->workingArea;
                        local_8 = warships->value[local_c];
                        value = result->contains(local_8);
                        if (value != 1) {
                            value = result->numberValue;
                            if (result->maximumSizeValue - 1 < value)
                                result->resize(value + 1);
                            result->value[result->numberValue] = local_8;
                            result->numberValue++;
                        }
                        ++i;
                    }
                }
            }
next_warboat:
            ++local_c;
        } while (local_c < local_4->warBoats.numberValue);
    }

    local_c = 0;
    if (this->soldiers.numberValue > 0) {
        warships = &this->soldiers;
        tactical2 = this;
        do {
            if (warships->maximumSizeValue - 1 < local_c)
                warships->resize(local_c + 1);
            object = tactical2->md->aiPlayer->world->object(warships->value[local_c]);
            if (object != 0 && object->unitAI() != 0) {
                if (warships->maximumSizeValue - 1 < local_c)
                    warships->resize(local_c + 1);

                value = tactical2->unitsTaskedThisUpdate.numberValue;
                index = 0;
                tactical = tactical2;
                if (value > 0) {
                    do {
                        if (tactical->unitsTaskedThisUpdate.maximumSizeValue <= index)
                            break;
                        tactical = local_4;
                        if (tactical2->unitsTaskedThisUpdate.value[index] == warships->value[local_c])
                            goto next_soldier;
                        ++index;
                        tactical = local_4;
                    } while (index < value);
                }

                objectGroup = object->master_obj->object_group;
                if (objectGroup == 0x12 || objectGroup == 0x0D) {
                    if (compare < 0) {
                        ai = object->unitAI();
                        value = ai->currentAction();
                        if (value != -1) {
                            ai = object->unitAI();
                            value = ai->currentOrderPriority();
                            if (priority <= value)
                                goto next_soldier;
                        }
                        if (warships->maximumSizeValue - 1 < local_c)
                            warships->resize(local_c + 1);
                        value = tactical2->workingArea.numberValue;
                        scan = 0;
                        local_8 = warships->value[local_c];
                        if (value > 0) {
                            do {
                                if (tactical2->workingArea.maximumSizeValue <= scan)
                                    break;
                                if (tactical2->workingArea.value[scan] == local_8)
                                    goto next_soldier;
                                ++scan;
                            } while (scan < value);
                        }
                        goto append_soldier;
                    } else if (compare < 1) {
                        ai = object->unitAI();
                        value = ai->currentAction();
                        if (value != -1) {
                            ai = object->unitAI();
                            value = ai->currentOrderPriority();
                            if (value != priority)
                                goto next_soldier;

                            if (warships->maximumSizeValue - 1 < local_c)
                                warships->resize(local_c + 1);
                            value = tactical2->workingArea.numberValue;
                            scan = 0;
                            local_8 = warships->value[local_c];
                            if (value > 0) {
                                do {
                                    if (tactical2->workingArea.maximumSizeValue <= scan)
                                        break;
                                    if (tactical2->workingArea.value[scan] == local_8)
                                        goto next_soldier;
                                    ++scan;
                                } while (scan < value);
                            }
                            if (tactical2->workingArea.maximumSizeValue - 1 < value)
                                tactical2->workingArea.resize(value + 1);
                            tactical2->workingArea.value[tactical2->workingArea.numberValue] = local_8;
                            tactical2->workingArea.numberValue++;
                            ++i;
                            goto soldier_done;
                        }
                    } else {
                        ai = object->unitAI();
                        value = ai->currentAction();
                        if (value != -1) {
                            ai = object->unitAI();
                            value = ai->currentOrderPriority();
                            if (priority < value) {
                                if (warships->maximumSizeValue - 1 < local_c)
                                    warships->resize(local_c + 1);
                                result = &tactical2->workingArea;
                                local_8 = warships->value[local_c];
                                value = result->contains(local_8);
                                if (value != 1) {
                                    value = result->numberValue;
                                    if (result->maximumSizeValue - 1 < value)
                                        result->resize(value + 1);
                                    result->value[result->numberValue] = local_8;
                                    result->numberValue++;
                                }
                                ++i;
                            }
                        }
                    }
                }
                goto soldier_done;
append_soldier:
                if (tactical2->workingArea.maximumSizeValue - 1 < value)
                    tactical2->workingArea.resize(value + 1);
                tactical2->workingArea.value[tactical2->workingArea.numberValue] = local_8;
                tactical2->workingArea.numberValue++;
                ++i;
soldier_done:
                ;
            }
next_soldier:
            ++local_c;
        } while (local_c < tactical2->soldiers.numberValue);
    }

    return i;
}
