#ifndef TAITACMD_SHARED_CONTEXT
// VA: 004FD6D0 TribeTacticalAIModule::numberUngroupedArtifacts
// Source: taitacmd.cpp lines 10206-10220
// Attempt log:
// 1: natural reconstruction from packet/decompiler, preserving explicit array growth loops: broad mismatch, compiler used EAX/EBP differently and omitted early push ebp.
// 2: closer decompiler-shaped source with local_c/local_4 names and direct indexed array accesses: much closer prologue but only 8-byte frame.
// 3: make i volatile to force the third stack local slot seen in original; got 0x0c frame but stack slots are permuted.
// 4: reorder local declarations to try local_c at +8, i at +0c, local_4 at +10; no stack-slot improvement.
// 5: invert first capacity condition source to try cmp ebp,eax / jle skip shape; fixed first branch polarity but copy loops still wrong.
// 6: tried separate volatile frame_pad with nonvolatile i; frame collapsed back to 8 bytes and worsened, rolled back.
// 7: keep volatile i as best frame/prologue family; remaining drift is stack-slot permutation and copy-loop register topology.
// 8: swap initial local assignment order to probe stack slot store order; swapped first two stores but still no +8 rNum slot and broad loop drift.
// 9: tried narrow /O1 flag as code-size/control-flow probe; produced EBP frame and worse, flag removed.
// 10: left in scratch: behavior/call surface understood, but remaining mismatch is broad VC5 stack-slot allocation and dynamic-array copy-loop register topology. Best /O2 family has correct 0x0c frame, push ebp/esi, branch polarity for first grow check, but rNum/local_4/i stack slots are permuted and copy loops use ECX/shl instead of original EAX inc/index form; not accepted-drift-safe.
// Probe 1 (current claim): restored the period ManagedArray<int>::operator[] surface and
// natural indexed source for both artifact accesses and the working-area append. This
// is the canonical ownership hypothesis; the next check distinguishes source topology
// from the prior hand-expanded/volatile experiment.
// Probe 2: moved the artifact value to a function-scope ordinary local so it can
// remain live across the working-area growth call, matching the oracle's callee-saved
// artifact register and spilled outer-index topology.
// Probe 3: reversed the duplicate-scan boundary spelling to the binary's
// `j >= maximumSizeValue` compare direction, avoiding the zero-folded max test.
// Variant lab (probe 4): a 16-case natural source lab showed that declaring the
// outer index before the result keeps the exact-size/frame/call-set basin and
// improves the positional frontier; direct repeated artifact expressions were
// 649 bytes, while named artifact plus `i`-first was the best group.
// Final current-claim probes: the element-reference/byte-offset spelling was
// codegen-duplicate; canonical full inheritance/member context and class (not
// struct) TacticalAIGroup ABI were also codegen-duplicate. The prior readable
// i-first/named-artifact candidate is retained in history as the old baseline.
// Probe 14: replaced the explicit duplicate scan and growth path with the
// typed ManagedArray::add surface used by exact same-TU sibling counters. This
// restored the original count/loop/lifetime shape and matched all 510 bytes.
// Prior pause metrics: 510-byte size/frame/call-set parity, 7/7 ordered calls,
// 82.50% shape, 58.17% exact-block coverage, 350 positional diff bytes.
// Exact result: 510-byte size/frame/call-set parity and 100% positional match;
// no accepted-drift or inline-asm claim.

extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup;
class TribeMainDecisionAIModule;

struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_data = (int*)operator_new(new_size * 4);
            if (new_data != 0) {
                for (int i = 0;
                         i < this->maximumSizeValue && i < new_size;
                         i++) {
                    new_data[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int add(int valueToAdd) {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == valueToAdd)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int new_size = this->numberValue + 1;
            int* new_data = (int*)operator_new(new_size * 4);
            if (new_data != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= new_size)
                        break;
                    new_data[j] = this->value[j];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }

        this->value[this->numberValue] = valueToAdd;
        this->numberValue++;
        return 1;
    }
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArrayInt civilians;
    ManagedArrayInt civilianExplorers;
    ManagedArrayInt soldiers;
    ManagedArrayInt ungroupedSoldiers;
    ManagedArrayInt boats;
    ManagedArrayInt warBoats;
    ManagedArrayInt fishingBoats;
    ManagedArrayInt tradeBoats;
    ManagedArrayInt transportBoats;
    ManagedArrayInt artifacts;
    char gap_194[0xD48 - 0x194];
    ManagedArrayInt workingArea;

    TacticalAIGroup* groupUnitIsIn(int unit);
    int numberUngroupedArtifacts();
};

#endif
int TribeTacticalAIModule::numberUngroupedArtifacts()
{
    int rNum = 0;
    int i = 0;
    ManagedArrayInt& workingArea = this->workingArea;
    ManagedArrayInt& artifacts = this->artifacts;

    workingArea.numberValue = 0;
    if (artifacts.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(artifacts[i]) == 0) {
                workingArea.add(artifacts[i]);
                rNum++;
            }
            i++;
        } while (i < artifacts.numberValue);
    }
    return rNum;
}
#else
int TribeTacticalAIModule::numberUngroupedArtifacts() {
    return 0;
}
#endif
