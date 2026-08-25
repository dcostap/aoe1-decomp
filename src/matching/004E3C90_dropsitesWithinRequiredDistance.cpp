// VA: 004E3C90 TribeInformationAIModule::dropsitesWithinRequiredDistance
// Source: taiinfmd.cpp lines 8019-8074
// Attempt log:
// 1-11: prior decompiler-shaped and manual ManagedArray growth variants. They
// matched size but stayed in the wrong register and local-home basin.
// 12: reset to the period ManagedArray contains/add source family. The binary
// has both duplicate scans, so use contains followed by add and let VC5 inline
// both natural member functions.
// 13: explicit split returns restored the second destructor cleanup site.
// 14: placing the ManagedArray declaration after the output reset improved the
// local lifetime schedule; the no-constructor diagnostic was rolled back.
// 15: PDB reference output parameter was retained; it emitted the same code.
// 16: rereading resources[type] for every proven field matched the original
// reload pattern and reduced the diff from 454 to 230 bytes.
// 17: declaration-order and contains-temporary probes were neutral or worse.
// 18: moving total initialization before the array and swapping increment order
// were rolled back. Best current reconstruction is 518 bytes, diff 230.
// 19: an early local copy of resourceType was a codegen duplicate; rolled back.
// 20: moved byteOffset initialization into the positive-resource path because
// the original stores that cursor only after the count guard; testing that
// natural guarded-path lifetime against the current pre-guard initialization.
// 21: restored a natural boolean return as a cleanup-shape probe; it removed
// one final delete call and shortened the function, so the clean split returns
// remain the best structural reconstruction.
// 22: moved totalApplicable initialization before ManagedArray construction
// while retaining guarded byteOffset initialization; the first mismatch moved
// from entry initialization to the final cleanup branch and diff fell to 75.
// 23: matched the canonical same-TU ManagedArray destructor body, including
// post-delete field clearing; emitted code was unchanged, so the missing final
// EH-state transition is not caused by the local destructor body.
// 24: normal C++ global operator new/delete declarations restored the original
// EH completion-state store and reduced the diagnostic diff to 54 bytes.
// C-linkage allocation declarations remained in the older 75-byte basin.
// 25: direct ResourceInfo[index] field access emitted the same code as the
// byte-offset spelling.  The source now keeps typed resource ownership.
// 26: removing the source-dead byte cursor also emitted the same code; VC5
// derives and retains the proven 0x14-byte record induction naturally.
// 27: the remaining mismatch is the final two-return destructor block: the
// original jumps from the positive cleanup to the common epilogue, while VC5
// places that epilogue before the negative cleanup.  Calls, frame, and all
// preceding bytes match; no policy-valid source form has changed that basin.
// Main review replaced direct global allocation calls with ordinary
// new[]/delete[]. The emitted code is unchanged.
// Accepted-drift review: the first 452 bytes and all five calls match. Both
// return paths set EH state to minus one, delete the same non-null array, and
// return the same Boolean value. The rebuild duplicates the register-pop and
// FS-chain epilogue around the negative cleanup. No call, external access, or
// object access occurs in the changed tail after delete[].
// Exact translation-unit finish: the real earlier taiinfmd.cpp helper at
// 004DAFF0 selects the original destructor-return layout. The unchanged typed
// ManagedArray source then matches all 509 bytes and five calls. Target-only
// compilation emits the reviewed duplicated-tail drift.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

#endif
    ManagedArray_int()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}

    ~ManagedArray_int() {
        if (this->value != 0)
            delete[] this->value;
        this->value = 0;
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }

    int contains(const int& wanted) const {
        int i;
        int wantedCopy;
        int current;

        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                return 0;
            current = this->value[i];
            wantedCopy = wanted;
            if (current == wantedCopy)
                return 1;
        }
        return 0;
    }

    int add(int val) {
        int i;

        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == val)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int newSize = this->numberValue + 1;
            int* newValue = new int[newSize];
            if (newValue != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= newSize)
                        break;
                    newValue[j] = this->value[j];
                }
                delete[] this->value;
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }

        this->value[this->numberValue] = val;
        this->numberValue++;
        return 1;
    }
};

#endif
int TribeInformationAIModule::dropsitesWithinRequiredDistance(
    int& numApplicableResources, int resourceType, int requiredDistance)
{
    int totalApplicable;
    int index;

    numApplicableResources = 0;
    totalApplicable = 0;
    ManagedArray_int dropsites;
    index = 0;

    if (this->numResources[resourceType] > 0) {
        do {
            if (this->resources[resourceType][index].gone != 1) {
                if (this->md->object(this->resources[resourceType][index].id) != 0) {
                    ++totalApplicable;
                    if ((int)this->resources[resourceType][index].dropDistance <= requiredDistance) {
                        if (dropsites.contains(this->resources[resourceType][index].dropsiteID) == 0) {
                            ++numApplicableResources;
                            int dropsiteID = this->resources[resourceType][index].dropsiteID;
                            dropsites.add(dropsiteID);
                        }
                    }
                }
            }

            ++index;
        } while (index < this->numResources[resourceType]);
    }

    if (totalApplicable > 0) {
        return 1;
    } else {
        return 0;
    }
}
