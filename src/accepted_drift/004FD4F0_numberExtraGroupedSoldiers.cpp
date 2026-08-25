#ifndef TAITACMD_SHARED_CONTEXT
// VA: 004FD4F0, TribeTacticalAIModule::numberExtraGroupedSoldiers, 473 bytes
// Source: taitacmd.cpp lines 10154-10201
// Attempt log:
// - v1-v9: raw sentinel/group and hand-inlined array reconstruction. The
//   output reached 473 bytes but used a different register and stack basin.
// - clean reconstruction: groups is the embedded 0x330-byte TacticalAIGroup
//   list sentinel, and workingArea is a ManagedArray<int> at +0xd48.
//   This removes decompiler cursor scaffolding from the compiler-facing source.
// - probe 1 baseline: typed reconstruction reached 483 bytes with group in
//   EBX and all 16 calls present, but the outer count calls were reversed.
// - probe 2: reversed the outer count predicate; call order did not change.
// - probe 3: named desiredUnits before the comparison; all 16 call sites then
//   aligned and the diff fell to 65 bytes.
// - probe 4: reordered result/rNum/tempCount declarations; code was unchanged.
// - probe 5: split result and workingArea reset statements; code was unchanged.
// - probe 6: added the ordinary workingArea reference used by exact array
//   donors; the best diff fell to 62 bytes.
// - probe 7: early sentinel return changed CFG and widened the diff; rolled back.
// - probe 8: used a literal zero for the workingArea reset; code was unchanged.
// - probe 9: forced a result stack-home store through a pointer; code was
//   unchanged and the diagnostic form was removed.
// - probe 11: changed the outer list walk to a natural while loop and scoped
//   rNum/tempCount inside the counted-group block; output reached 473 bytes
//   with a 16-byte diff and exact outer CFG, leaving only the result home.
// - probe 12: named numberUnits after desiredUnits and used the original
//   comparison operand order; this reduced the positional diff to 10 bytes.
// - probes 13-16: local scope, declaration order, initialization, and stdlib
//   context changes were codegen duplicates or worse; they were removed.
// - revisit probe 20: replaced the manual vptr field with a natural virtual
//   destructor surface. The emitted code was unchanged, so this typed layout
//   is retained as the cleaner ownership model.
// Prior blocker: current typed source has 473 bytes, all 16 direct calls aligned,
// and a 10-byte positional diff. The remaining drift is three local homes and
// their transient uses: original result/rNum/tempCount use
// [esp+18]/[esp+14]/[esp+10], while current uses [esp+10]/[esp+18]/[esp+14].
// The source keeps canonical ownership.
// ACCEPTED DRIFT: The ten differing bytes consistently permute those three
// nonescaping dword homes. Every read follows its matching write, including
// the push-adjusted rNum update. Register use, calls, values, writes,
// predicates, cleanup, and faults match the reviewed war-boat twin.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint {
    int x;
    int y;
    int z;
    int unk;
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;
    int originalHitPointsValue;
    int originalUnitNumberValue;
    Waypoint locationValue;
    int actionValue;
    int targetValue;
    int targetTypeValue;
    Waypoint targetLocationValue;
    Waypoint gatherLocationValue;
    Waypoint retreatLocationValue;
    int priorityValue;
    int waitCodeValue;
    int assistGroupIDValue;
    int assistGroupTypeValue;
    unsigned long consecutiveIdleUnitCountValue;
    int playNumberValue;
    unsigned char numberAttackWaypointsValue;
    unsigned char currentAttackWaypointValue;
    unsigned char pad_1d6[2];
    Waypoint attackWaypoints[15];
    unsigned char consecutiveGatherAttemptsValue;
    unsigned char pad_2c9[3];
    int numberObjectsToDestroyValue;
    int objectsToDestroyValue[20];
    int objectsToDestroyOwnerValue;
    int objectsToDestroyCommanderZoneValue;
    unsigned long lastAttackRoundupTime;
    unsigned long lastAddedUnitTimeValue;

    int type();
    int numberUnits();
    int unit(int index);
    int desiredNumberUnits();
    int commander();
    int action();
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int add(T valueToAdd) {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == valueToAdd)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int new_size = this->numberValue + 1;
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= new_size)
                        break;
                    new_value[j] = this->value[j];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }

        this->value[this->numberValue] = valueToAdd;
        this->numberValue++;
        return 1;
    }
};

class TribeTacticalAIModule {
public:
    char gap_000[0x9d4];
    TacticalAIGroup groups;
    char gap_after_groups[0xd48 - 0x9d4 - 0x330];
    ManagedArray<int> workingArea;

    int numberExtraGroupedSoldiers();
};

#endif
int TribeTacticalAIModule::numberExtraGroupedSoldiers()
{
    int result = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    TacticalAIGroup* group;

    workingArea.numberValue = 0;
    group = this->groups.next;
    while (group != &this->groups) {
        if (group == 0)
            return result;

        if ((group->type() == 100 || group->type() == 101 ||
             group->type() == 102) &&
            (group->action() == 1 || group->action() == 0)) {
            int desiredUnits = group->desiredNumberUnits();
            int numberUnits = group->numberUnits();
            if (numberUnits > desiredUnits) {
                int rNum = group->numberUnits();
                int tempCount = 0;
                if (rNum > group->desiredNumberUnits()) {
                    while (1) {
                        if (tempCount >= group->numberUnits())
                            break;
                        if (group->unit(tempCount) != group->commander()) {
                            rNum--;
                            workingArea.add(group->unit(tempCount));
                            result++;
                        }
                        tempCount++;
                        if (rNum <= group->desiredNumberUnits())
                            break;
                    }
                }
            }
        }
        group = group->next;
    }
    return result;
}
#else
int TribeTacticalAIModule::numberExtraGroupedSoldiers() {
    return 0;
}
#endif
