// VA: 004F7590 TribeTacticalAIModule::numberSoldiersWithPriority
// Attempt log:
// try 1: adapted dynamic-array/scanning shape from numberUngroupedSoldiers and packet: reset working list, scan soldiers, resolve object, filter valid/busy/grouped/priority, count unique working soldiers.
// try 2: fixed local layout for busy array near +0xD58 so source compiles.
// try 3: minimal behavioral source compiled but only 400B vs 726B.
// try 4: /Od probe still too small (584B) and wrong basin; removed.
// try 5: inlined soldier array growth at scan index like original dynamic-array pattern.
// try 6: inlined working array growth/copy/delete before adding accepted soldier.
// try 7: modeled reset flag clearing workingNumber at +0xD4C.
// try 8: modeled busy-list duplicate exclusion loop using busyValue/busyNumber/busyMaximum.
// try 9: modeled negative/positive/zero priority comparisons via UnitAI priority/taskPriority calls.
// try 10: /GX probe no size/codegen change; removed.
// left in scratch: the best source reconstruction is 833B vs original 726B;
//   ordered calls and behavior-backed array/priority topology align, but the
//   frame/prologue and several branch/register blocks remain structurally
//   unresolved, so this is not accepted_drift-safe.
// probe 11: restored the PDB-backed parameter order (threshold, priority, reset),
//   the out-of-line ManagedArray resize/contains surface, and the repeated
//   source-level priority arms shown by the original line bands.  This also
//   restores the inline operator[] only for the zero-priority soldiers read.
// probe 12: shared the binary-proven working-area append tail and restored the
//   zero-priority soldier growth as the one inline allocation/copy/delete path;
//   the other soldier reads retain the six out-of-line resize call sites.
// probe 13: laid out the positive-priority arm before the zero-priority arm,
//   matching the original inline positive block and late zero block.
// probe 14: added the period local owner used to preserve this across the
//   busy-array register reuse; no byte-stride cursor was retained yet.
// probe 15: made the repeated int-array element address an explicit proven
//   byte-stride cursor, matching the original EBP offset and zero-arm
//   allocation-size topology.
// probe 16: moved the result declaration ahead of the owner/array locals to
//   test the original EBX=this, EDI=result, EBP=offset callee-save coloring.
// probe 17: corrected the positive-arm threshold ownership and mirrored the
//   original compare operand spellings for bounds/duplicate scans.
// probe 18: restored a natural typed count loop with direct ManagedArray
//   element access; removed the byte-stride cursor and excess owner alias.
//   Result: size moved 833->832 and exact-block coverage improved, but the
//   frame stayed 0x10 and the first structural hunk remained unchanged.
// probe 19: delayed the soldiers pointer until after the count guard; frame
//   stayed exact, but the natural branch source moved to 808B and diff 719.
// probe 20: retained a local byte-size expression for the zero-arm growth;
//   it broke tail merging and added a seventh resize call. Rolled back.
// probe 22: changed busy and working duplicate scans to bounded for loops;
//   frame stayed 0xC, calls stayed aligned, and size moved to 688B with diff
//   649. Probe 23 kept the pre-loop index initialization and reached diff 647.
// probe 24: restored one shared append tail; size became exactly 726B, but
//   compiler layout moved one resize call before the positive arm.
// probe 25: placed that tail in the positive PDB band; shape improved to
//   76.10%, but the label-crossing source was not a clean original model.
// left in scratch: natural branch-local append source, 688B vs 726B, diff
//   647, exact calls and frame. The remaining structural gap is register
//   coloring, block placement, and the original shared append tail order.
// revisit probes:
// - The old countedSoldier label was outside the valid-object block.  The
//   original null object and null UnitAI paths skip the result increment, so
//   the label now stays inside that block.
// - A shared negative/positive append tail restored the original 726-byte
//   size and raised shape similarity to 92.03%; calls and frame also match.
// - Delaying the soldiers alias until after the outer count guard, then
//   assigning the working count before the soldier value, restored the exact
//   prologue and 248-instruction size.  The best current result is 353 strict
//   differing bytes, 93.55% shape similarity, and 78.63% exact-block coverage.
// - Direct working-area expressions, a branch pointer alias, an inline add
//   helper, alternate loop forms, ABI declaration changes, and local-order
//   variants were tested.  They were worse or codegen duplicates.
// MANAGEDARRAY AUDIT: resize guards, inline growth, copies, publication,
// contains bounds, append count, and field offsets match the executable. No
// shared template change is required.
// BLOCKER: After a soldier resize, the executable reads the soldier value
// pointer before the working-area count. The rebuild reads the count first.
// Soldier element and working-array reads therefore have different mutation
// and fault order.

extern "C" {
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* ptr);
}

class RGE_Game_World;
class RGE_Static_Object;
class UnitAIModule;

class ManagedArrayInt {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int resize(int newSize);
    int contains(const int& valueToFind);

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            int* newValue = (int*)operator_new(newSize * 4);
            if (newValue != 0) {
                int i = 0;
                if (0 < this->maximumSizeValue) {
                    do {
                        if (newSize <= i)
                            break;
                        newValue[i] = this->value[i];
                        i = i + 1;
                    } while (i < this->maximumSizeValue);
                }
                operator_delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }
        return this->value[index];
    }
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int objectID);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0x1256C];
    RGE_Player* aiPlayer;
};

class UnitAIModule {
public:
    int currentAction();
    int currentOrderPriority();
};

class RGE_Static_Object {
public:
    char gap_00[8];
    UnitAIModule* unitAI();
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_F4[0x20];
    ManagedArrayInt soldiers;
    char gap_124[0xD48 - 0x124];
    ManagedArrayInt workingArea;
    ManagedArrayInt unitsTaskedThisUpdate;

    int numberSoldiersWithPriority(int threshold, int priority, int reset);
};

int TribeTacticalAIModule::numberSoldiersWithPriority(int threshold, int priority, int reset)
{
    TribeTacticalAIModule* self = this;
    ManagedArrayInt& workingArea = self->workingArea;
    int rNum = 0;

    if (reset == 1)
        workingArea.numberValue = 0;

    reset = 0;
    if (0 < self->soldiers.numberValue) {
        ManagedArrayInt& soldiers = self->soldiers;
        do {
            if (reset > soldiers.maximumSizeValue - 1)
                soldiers.resize(reset + 1);

            RGE_Static_Object* object =
                self->md->aiPlayer->world->object(soldiers.value[reset]);
            if ((object != 0) && (object->unitAI() != 0)) {
                if (reset > soldiers.maximumSizeValue - 1)
                    soldiers.resize(reset + 1);

                int taskedNumber = self->unitsTaskedThisUpdate.numberValue;
                int taskedIndex = 0;
                if (0 < taskedNumber) {
                    for (;
                         taskedIndex < taskedNumber &&
                         taskedIndex < self->unitsTaskedThisUpdate.maximumSizeValue;
                         taskedIndex++) {
                        if (self->unitsTaskedThisUpdate.value[taskedIndex] ==
                            soldiers.value[reset])
                            goto nextSoldier;
                    }
                }

                int value;
                int number;
                if (priority < 0) {
                    if (object->unitAI()->currentAction() != -1) {
                        if (object->unitAI()->currentOrderPriority() >= threshold)
                            goto nextSoldier;
                    }

                    if (reset > soldiers.maximumSizeValue - 1)
                        soldiers.resize(reset + 1);
                    number = workingArea.numberValue;
                    value = soldiers.value[reset];
                    int index = 0;
                    if (0 < number) {
                        for (;
                             index < number && index < workingArea.maximumSizeValue;
                             index++) {
                            if (workingArea.value[index] == value)
                                goto countedSoldier;
                        }
                    }
                    goto appendWorking;
                }
                else if (priority > 0) {
                    if (object->unitAI()->currentAction() != -1) {
                        if (object->unitAI()->currentOrderPriority() > threshold) {
                            if (reset > soldiers.maximumSizeValue - 1)
                                soldiers.resize(reset + 1);
                            number = workingArea.numberValue;
                            value = soldiers.value[reset];
                            int index = 0;
                            if (0 < number) {
                                for (;
                                     index < number && index < workingArea.maximumSizeValue;
                                     index++) {
                                    if (workingArea.value[index] == value)
                                        goto countedSoldier;
                                }
                            }
                            goto appendWorking;
                        }
                    }
                    goto nextSoldier;
                }
                else {
                    if (object->unitAI()->currentAction() != -1) {
                        if (object->unitAI()->currentOrderPriority() == threshold) {
                            if (reset > soldiers.maximumSizeValue - 1) {
                                int* newValue = (int*)operator_new(reset * 4 + 4);
                                if (newValue != 0) {
                                    int copyIndex = 0;
                                    if (0 < soldiers.maximumSizeValue) {
                                        do {
                                            if (reset + 1 <= copyIndex)
                                                break;
                                            newValue[copyIndex] = soldiers.value[copyIndex];
                                            copyIndex = copyIndex + 1;
                                        } while (copyIndex < soldiers.maximumSizeValue);
                                    }
                                    operator_delete(soldiers.value);
                                    soldiers.value = newValue;
                                    soldiers.maximumSizeValue = reset + 1;
                                }
                            }

                            int value = soldiers.value[reset];
                            if (workingArea.contains(value) != 1) {
                                int number = workingArea.numberValue;
                                if (number > workingArea.maximumSizeValue - 1)
                                    workingArea.resize(number + 1);
                                workingArea.value[workingArea.numberValue] = value;
                                workingArea.numberValue = workingArea.numberValue + 1;
                            }
                            rNum = rNum + 1;
                        }
                    }
                    goto nextSoldier;
                }
appendWorking:
                if (number > workingArea.maximumSizeValue - 1)
                    workingArea.resize(number + 1);
                workingArea.value[workingArea.numberValue] = value;
                workingArea.numberValue = workingArea.numberValue + 1;
countedSoldier:
                rNum = rNum + 1;
            }
nextSoldier:
            reset = reset + 1;
        } while (reset < soldiers.numberValue);
    }
    return rNum;
}
