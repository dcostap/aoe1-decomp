// VA: 004E3C90 TribeInformationAIModule::dropsitesWithinRequiredDistance
// Source: taiinfmd.cpp lines 8019-8074
// Attempt log:
// 1: initial reconstruction from packet/decompiler with local ManagedArray_int and inline add/resize.
// 2: added /GX flag because original has VC5 EH registration for local destructor cleanup.
// 3: changed resource loop to separate index+byte-offset instead of offset/0x14 division.
// 4: rewrote final return as explicit if/else to avoid VC5 setg merge and try original delete branches.
// 5: moved ManagedArray construction after *param=0 to match original pre-save-register store.
// 6: inlined ManagedArray add/resize body instead of member call to expose stack-field codegen.
// 7: removed ManagedArray constructor and manually zeroed fields; worsened early ordering but kept for explicit fields.
// 8: switched duplicate/add logic to ManagedArray::numberValue as the active count (original stores count at +4); no early change.
// 9: restored constructor initialization to regain closer first mismatch offset.
// 10: introduced self local and used it for member accesses; worsened overall diff, rolled back.
// 11: switched first parameter from reference to pointer to match PDB/decompiler stack use; no codegen change.
// left in scratch: /GX is required to reproduce the original EH prologue/cleanup shape, but the body is still in the wrong VC5 register-allocation basin. Best current version has correct size but broad mismatch; first mismatch is early stack/local initialization after zeroing *param (rebuilt zeroes ebp/ebx and maps ManagedArray fields to different registers/slots instead of original ebx=this, edi=0, stack ManagedArray fields).

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

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray_int() : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}
    ~ManagedArray_int() { if (value != 0) operator_delete(value); }

};

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    MainDecisionAIModule* md;
    char gap_104[0x4D0 - 0x104];
    ResourceInfo* resources[4];
    int numResources[4];

    int dropsitesWithinRequiredDistance(int* numApplicableResources, int resourceType, int requiredDistance);
};

int TribeInformationAIModule::dropsitesWithinRequiredDistance(int* numApplicableResources, int resourceType, int requiredDistance)
{
    int totalApplicable;
    int offset;
    int index;

    *numApplicableResources = 0;
    ManagedArray_int dropsites;
    totalApplicable = 0;
    offset = 0;
    index = 0;
    if (this->numResources[resourceType] > 0) {
        do {
            ResourceInfo* res = (ResourceInfo*)((char*)this->resources[resourceType] + offset);
            if (res->gone != 1) {
                if (this->md->object(res->id) != 0) {
                    ++totalApplicable;
                    if ((int)(unsigned int)res->dropDistance <= requiredDistance) {
                        int i = 0;
                        if (dropsites.numberValue > 0) {
                            int* p = dropsites.value;
                            do {
                                if (i >= dropsites.maximumSizeValue) {
                                    break;
                                }
                                if (*p == res->dropsiteID) {
                                    goto next_resource;
                                }
                                ++i;
                                ++p;
                            } while (i < dropsites.numberValue);
                        }
                        ++*numApplicableResources;
                        {
                            int dropsiteID = res->dropsiteID;
                            i = 0;
                            if (dropsites.numberValue > 0) {
                                int* p = dropsites.value;
                                do {
                                    if (i >= dropsites.maximumSizeValue) {
                                        break;
                                    }
                                    if (*p == dropsiteID) {
                                        goto next_resource;
                                    }
                                    ++i;
                                    ++p;
                                } while (i < dropsites.numberValue);
                            }
                            if (dropsites.maximumSizeValue - 1 < dropsites.numberValue) {
                                int newMax = dropsites.numberValue + 1;
                                int* newValue = (int*)operator_new(newMax * 4);
                                if (newValue != 0) {
                                    int copyIndex = 0;
                                    if (dropsites.maximumSizeValue > 0) {
                                        int* dst = newValue;
                                        do {
                                            if (copyIndex >= newMax) {
                                                break;
                                            }
                                            *dst = *(int*)((char*)dropsites.value + ((char*)dst - (char*)newValue));
                                            ++copyIndex;
                                            ++dst;
                                        } while (copyIndex < dropsites.maximumSizeValue);
                                    }
                                    operator_delete(dropsites.value);
                                    dropsites.value = newValue;
                                    dropsites.maximumSizeValue = newMax;
                                }
                            }
                            ++dropsites.numberValue;
                            dropsites.value[dropsites.numberValue - 1] = dropsiteID;
                        }
                    }
                }
            }
next_resource:
            ++index;
            offset += 0x14;
        } while (index < this->numResources[resourceType]);
    }

    if (totalApplicable > 0) {
        return 1;
    }
    return 0;
}
