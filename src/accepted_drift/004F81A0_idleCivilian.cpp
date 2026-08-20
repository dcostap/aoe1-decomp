// VA: 004F81A0 TribeTacticalAIModule::idleCivilian
// Attempt log:
// try 1: 004DF520 query returned no normal target, so selected next eligible unclaimed normal after assigned/prior targets: 004F81A0 idleCivilian.
// try 2: started from prior 004F7E80 idleCivilian reconstruction and expanded toward 976B packet: two-pass civilian scan, reserve-list checks, object lookup, AI idle tests, and mode-sensitive fallback.
// try 3: modeled ManagedArray<int> at +0xF4 with resize-before-access pattern, world pointer at +0xF0, object-table lookup through world->md+0x3C.
// try 4: modeled first exclusion array at +0xD58/+0xD5C/+0xD64 and second at +0x104/+0x108/+0x110, matching packet scan loops.
// try 5: modeled first pass requiring object exists, unitAI exists, not gatherer, not in exclusion lists, and action/order both -1.
// try 6: modeled second pass with mode-sensitive gatherer filter and fallback result for mode 3.
// try 7: added ActionState/UnitAI currentAction/currentOrder call surface corresponding to 004C7420 -> 00413960/00413920 in packet.
// try 8: compiled with default flags: source builds, but rebuilt .text is 720B vs original 976B, too short for compare.
// try 9: probed /GX; no code/size change (still 720B), removed flag file.
// try 10: reviewed original: both passes inline every capacity check, allocation/copy/free grow block, exclusion scan, object lookup, and AI-state calls; current source factors ensure_index/contains_limited, collapsing roughly 250B and preventing full diff.
// probe 11 baseline: restored the period ManagedArray<int> surface and the three-argument XYPoint overload.  First pass uses explicit resize/value accesses; the second-pass object lookup uses the inline operator[] grow path shown at 004F8359.
// bounded-session result: scoped civilian-array pointers recovered the EBX/ESI/EDI
// ownership, separate first/second object locals recovered all four 0x10-byte
// stack homes, and the second gatherer read restored the second inline grow block.
// Reversed capacity comparisons matched every resize branch.  The natural bounded
// contains donor shape remained a register-permuted basin; an expanded local scan
// was tested and rolled back because it grew the function by 62 bytes.
// The late first-pass success label and utmarray.h declaration-order probes were
// codegen duplicates.  Final stdlib.h context is retained: 976B size/frame, 25/25
// ordered calls, and 95.17% exact-block coverage (645 positional diff bytes).
// Remaining localized leads are the four contains inner-loop register permutations,
// the first-pass near success jump/epilogue, and the distance-selection x87 tail.
// resumed claim: direct first-pass return and pointer/reference aliases were codegen duplicates.
// natural first-pass for-loop forms moved the success epilogue late, but added a guard or broadened drift;
// named count and pointer variants were rolled back.  The clean do-while reconstruction remains best.
// left in scratch after the 10-hypothesis budget: typed period-plausible source,
// no inline asm; exact promotion remains unresolved.
// resumed structural probes: an outer-guard for duplicated the count test and
// grew to 879/981B; an explicit positive bottom branch duplicated the clean
// 645B output.  The no-outer for and while forms reproduced the prior 605B
// diagnostic basin, but moved lea esi before the initial jle and lost blocks.
// Restored the clean do-while reconstruction; no structural lead remains.
// resumed claim: 22 distinct source, lifetime, control-flow, and context probes
// passed the 20-probe checkpoint.  Direct tasked-array member expressions
// reduced the diff from 645 to 637 bytes.  The period donor comparison spelling
// recovered the target x87 compare block and reduced it to 636 bytes.
// Structured first-pass continues reduced the best clean source to 618 bytes,
// with 25/25 ordered calls, a 0x10 frame, and 96.68% exact-block coverage.
// Separate second-pass index storage reached 616 bytes but lost exact blocks;
// it was not retained.  Top-tested loops, split guards, extra headers, scoped
// indices, and late labels were neutral or worse and were rolled back.
// Final unresolved facts: the original first-pass tail uses a positive near JL
// backedge and a late first-found epilogue.  VC5 keeps an inverted JGE/JMP tail
// and an early found return for every clean source form tested.
// MANAGEDARRAY AUDIT: resize guards, contains bounds, inline growth, copies,
// publication, and value reads match the executable. No template change is
// required.
// Accepted-drift review: the first-found return is early in the rebuild and
// late in the executable. Both read the same object ID after currentOrder. The
// first loop uses equivalent positive versus inverted tails and one count read.
// All 25 calls, x87 comparisons, array effects, and return values match.

#include <stdlib.h>

void* operator_new(unsigned int size);
void operator_delete(void* ptr);

struct XYPoint {
    int x;
    int y;
};

class UnitAIModule {
public:
    int currentAction();
    int currentOrder();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    void* master_obj;
    char gap_0c[0x34];
    float world_z;

    UnitAIModule* unitAI();
    float distance_to_position(float x, float y, float z);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int objectID);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xf0];
    RGE_Player* player;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int contains(const int& value) const {
        int i;
        int wanted;
        int current;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                return 0;
            current = this->value[i];
            wanted = value;
            if (current == wanted)
                return 1;
        }
        return 0;
    }

    int resize(int newSize);
    int add(T valueToAdd);

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size;
                     i++) {
                    new_value[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class TribeTacticalAIModule {
public:
    char gap_00[0xf0];
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    char gap_114[0xd58 - 0x114];
    ManagedArray<int> unitsTaskedThisUpdate;

    int isGatherer(int objectID);
    int idleCivilian(int mode, XYPoint& position, int chooseMode);
};

int TribeTacticalAIModule::idleCivilian(int mode, XYPoint& position, int chooseMode)
{
    float bestUnitDistance;
    int bestUnitID;
    int i;
    RGE_Static_Object* firstObj;
    RGE_Static_Object* secondObj;

    bestUnitID = -1;
    bestUnitDistance = 0;
    i = 0;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            if (this->unitsTaskedThisUpdate.contains(this->civilians.value[i]) != 0)
                continue;

            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            firstObj = this->md->player->world->object(civilians->value[i]);
            if ((firstObj != 0) && (firstObj->unitAI() != 0)) {
                if (i > civilians->maximumSizeValue - 1)
                    civilians->resize(i + 1);
                if (this->isGatherer(civilians->value[i]) == 0) {
                    if (i > civilians->maximumSizeValue - 1)
                        civilians->resize(i + 1);
                    if (this->civilianExplorers.contains(civilians->value[i]) != 0)
                        continue;
                    if (firstObj->unitAI()->currentAction() == -1 &&
                        firstObj->unitAI()->currentOrder() == -1)
                        return firstObj->id;
                }
            }
            ++i;
        } while (i < this->civilians.numberValue);
    }

    i = 0;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            if (this->unitsTaskedThisUpdate.contains(this->civilians.value[i]) != 0)
                goto second_next;

            secondObj = this->md->player->world->object((*civilians)[i]);
            if ((secondObj != 0) && (secondObj->unitAI() != 0)) {
                if (mode != 0) {
                    if (mode != 3) {
                        if (this->isGatherer((*civilians)[i]) != 0)
                            goto second_next;
                    }
                }
                if ((mode != 0) && (mode != 1)) {
                    if (i > civilians->maximumSizeValue - 1)
                        civilians->resize(i + 1);
                    if (this->civilianExplorers.contains(civilians->value[i]) != 0)
                        goto second_next;
                }

                if (secondObj->unitAI()->currentAction() == -1 &&
                    secondObj->unitAI()->currentOrder() == -1) {
                    float distance = secondObj->distance_to_position(
                        (float)position.x, (float)position.y, secondObj->world_z);
                    if (bestUnitID == -1) {
                        bestUnitDistance = distance;
                        bestUnitID = secondObj->id;
                    }
                    else if ((chooseMode == 1 && bestUnitDistance > distance) ||
                             (chooseMode == 0 && bestUnitDistance < distance)) {
                        bestUnitDistance = distance;
                        bestUnitID = secondObj->id;
                    }
                }
            }
second_next:
            ++i;
        } while (i < this->civilians.numberValue);
    }
    return bestUnitID;
}
