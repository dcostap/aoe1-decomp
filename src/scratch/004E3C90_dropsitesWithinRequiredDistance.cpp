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

extern "C" void* __cdecl operator_new(unsigned long sz);
extern "C" void __cdecl operator_delete(void* p);

class RGE_Static_Object;

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

struct ResourceInfo {
    int id;
    char gap_04[9];
    unsigned char gone;
    unsigned char dropDistance;
    char gap_0f[1];
    int dropsiteID;
};

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray_int()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}

    ~ManagedArray_int() {
        if (this->value != 0)
            operator_delete(this->value);
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
            int* newValue = (int*)operator_new(newSize * 4);
            if (newValue != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= newSize)
                        break;
                    newValue[j] = this->value[j];
                }
                operator_delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }

        this->value[this->numberValue] = val;
        this->numberValue++;
        return 1;
    }
};

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    MainDecisionAIModule* md;
    char gap_104[0x4D0 - 0x104];
    ResourceInfo* resources[4];
    int numResources[4];

    int dropsitesWithinRequiredDistance(int& numApplicableResources,
                                        int resourceType,
                                        int requiredDistance);
};

int TribeInformationAIModule::dropsitesWithinRequiredDistance(
    int& numApplicableResources, int resourceType, int requiredDistance)
{
    int totalApplicable;
    int index;
    int byteOffset;

    numApplicableResources = 0;
    totalApplicable = 0;
    ManagedArray_int dropsites;
    index = 0;

    if (this->numResources[resourceType] > 0) {
        byteOffset = 0;
        do {
            if (*(unsigned char*)((char*)this->resources[resourceType] + byteOffset + 0x0D) != 1) {
                if (this->md->object(
                        *(int*)((char*)this->resources[resourceType] + byteOffset)) != 0) {
                    ++totalApplicable;
                    if ((int)(unsigned int)*(unsigned char*)((char*)this->resources[resourceType] + byteOffset + 0x0E)
                            <= requiredDistance) {
                        if (dropsites.contains(
                                *(int*)((char*)this->resources[resourceType] + byteOffset + 0x10)) == 0) {
                            ++numApplicableResources;
                            int dropsiteID =
                                *(int*)((char*)this->resources[resourceType] + byteOffset + 0x10);
                            dropsites.add(dropsiteID);
                        }
                    }
                }
            }

            ++index;
            byteOffset += 0x14;
        } while (index < this->numResources[resourceType]);
    }

    if (totalApplicable > 0)
        return 1;
    return 0;
}
