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
    int rNum = 0;
    ManagedArrayInt* soldierArray;
    RGE_Static_Object* object;
    UnitAIModule* ai;
    int action;
    int order;
    int taskedNumber;
    int taskedIndex;
    int number;
    int value;
    int index;
    int* newValue;
    int copyIndex;

    if (reset == 1)
        this->workingArea.numberValue = 0;

    reset = 0;
    if (0 < this->soldiers.numberValue) {
        soldierArray = &this->soldiers;
        do {
            if (reset > soldierArray->maximumSizeValue - 1)
                soldierArray->resize(reset + 1);

            object = this->md->aiPlayer->world->object(soldierArray->value[reset]);
            if ((object != 0) && (object->unitAI() != 0)) {
                if (reset > soldierArray->maximumSizeValue - 1)
                    soldierArray->resize(reset + 1);

                taskedNumber = this->unitsTaskedThisUpdate.numberValue;
                taskedIndex = 0;
                if (0 < taskedNumber) {
                    do {
                        if (taskedIndex >= this->unitsTaskedThisUpdate.maximumSizeValue)
                            break;
                        if (this->unitsTaskedThisUpdate.value[taskedIndex] ==
                            soldierArray->value[reset])
                            goto nextSoldier;
                        taskedIndex = taskedIndex + 1;
                    } while (taskedIndex < taskedNumber);
                }

                if (priority < 0) {
                    ai = object->unitAI();
                    action = ai->currentAction();
                    if (action != -1) {
                        ai = object->unitAI();
                        order = ai->currentOrderPriority();
                        if (threshold <= order)
                            goto nextSoldier;
                    }

                    if (reset > soldierArray->maximumSizeValue - 1)
                        soldierArray->resize(reset + 1);

                    number = this->workingArea.numberValue;
                    value = soldierArray->value[reset];
                    index = 0;
                    if (0 < number) {
                        do {
                            if (index >= this->workingArea.maximumSizeValue)
                                break;
                            if (this->workingArea.value[index] == value)
                                goto countedSoldier;
                            index = index + 1;
                        } while (index < number);
                    }

                    goto appendSoldier;
                }
                else if (priority > 0) {
                    ai = object->unitAI();
                    action = ai->currentAction();
                    if (action != -1) {
                        ai = object->unitAI();
                        order = ai->currentOrderPriority();
                        if (threshold < order) {
                            if (reset > soldierArray->maximumSizeValue - 1)
                                soldierArray->resize(reset + 1);

                            value = soldierArray->value[reset];
                            number = this->workingArea.numberValue;
                            index = 0;
                            if (0 < number) {
                                do {
                                    if (index >= this->workingArea.maximumSizeValue)
                                        break;
                                    if (this->workingArea.value[index] == value)
                                        goto countedSoldier;
                                    index = index + 1;
                                } while (index < number);
                            }

                            goto appendSoldier;
                        }
                    }
                    goto nextSoldier;
                }
                else {
                    ai = object->unitAI();
                    action = ai->currentAction();
                    if (action != -1) {
                        ai = object->unitAI();
                        order = ai->currentOrderPriority();
                        if (order == threshold) {
                            if (reset > soldierArray->maximumSizeValue - 1) {
                                newValue = (int*)operator_new(reset * 4 + 4);
                                if (newValue != 0) {
                                    copyIndex = 0;
                                    if (0 < soldierArray->maximumSizeValue) {
                                        do {
                                            if (reset + 1 <= copyIndex)
                                                break;
                                            newValue[copyIndex] =
                                                soldierArray->value[copyIndex];
                                            copyIndex = copyIndex + 1;
                                        } while (copyIndex < soldierArray->maximumSizeValue);
                                    }
                                    operator_delete(soldierArray->value);
                                    soldierArray->value = newValue;
                                    soldierArray->maximumSizeValue = reset + 1;
                                }
                            }

                            value = soldierArray->value[reset];
                            if (this->workingArea.contains(value) != 1) {
                                number = this->workingArea.numberValue;
                                if (number > this->workingArea.maximumSizeValue - 1)
                                    this->workingArea.resize(number + 1);
                                this->workingArea.value[this->workingArea.numberValue] = value;
                                this->workingArea.numberValue =
                                    this->workingArea.numberValue + 1;
                            }
                            rNum = rNum + 1;
                        }
                    }
                    goto nextSoldier;
                }
            }
appendSoldier:
                    if (number > this->workingArea.maximumSizeValue - 1)
                        this->workingArea.resize(number + 1);
                    this->workingArea.value[this->workingArea.numberValue] = value;
                    this->workingArea.numberValue = this->workingArea.numberValue + 1;
            goto countedSoldier;
countedSoldier:
            rNum = rNum + 1;
nextSoldier:
            reset = reset + 1;
        } while (reset < soldierArray->numberValue);
    }
    return rNum;
}
