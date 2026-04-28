// 004E32C0 TribeInformationAIModule::amountResourceTypesInXTiles
// Source: taiinfmd.cpp lines 7615-7635, size 197 bytes
//
// Attempt log:
// 1: wrong param count (5 instead of 4) → ret mismatch
// 2: wrong class layout (missing array fields) → offset shifts
// 3-6: register allocation drift (eax↔edx↔ecx for resource base, id, master_obj).
//       An extra `mov eax, ebx; add eax, edx` appears instead of `add eax, ebx`
//       because VC5 loads the base into edx instead of eax.
// 7: initialization order: VC5 swaps `int i = 0; float total = 0.0f;` order
//    and uses register-zero for second init.
//
// FPU distance calculation (fild/fsubr/fxch/fmul/fsqrt/call __ftol) is byte-identical.
// Stack layout, loop structure, field offsets, and epilogue all match.
// Remaining drift (36 edit bytes): register allocation and branch encoding.
// Sister function 004E3210_amountForageBushesInXTiles has the exact same pattern
// and is parked in scratch.
// Left in scratch: VC5 register/scheduling drift only.

#include <math.h>

struct MasterObj {
    char gap_00[0x10];
    short id;                // +0x10
};

struct RGE_Static_Object {
    char gap_00[0x04];
    int id;                  // +0x04
    MasterObj* master_obj;   // +0x08
    char gap_0C[0x2C];       // +0x0C to +0x37
    float x;                 // +0x38
    float y;                 // +0x3C
    char gap_40[0x04];
    float forageAmount;      // +0x44
};

class MainDecisionAIModule {
public:
    virtual void _vf00();
    char gap_04[0xEC];
    void* attackInfo;        // +0xF0
    RGE_Static_Object* object(int object_id);
};

struct TribeInformationAIModule {
    virtual void _vf00();
    char gap_04[0xFC];
    MainDecisionAIModule* md;      // +0x100
    char gap_104[0x3CC];           // +0x104 to +0x4CF
    void* resourcePtrs[4];         // +0x4D0 (array of pointers, indexed by type_index)
    int numResources[4];           // +0x4E0 (array of counts, indexed by type_index)

    int amountResourceTypesInXTiles(int type_index, int x, int y, int distance);
};

int TribeInformationAIModule::amountResourceTypesInXTiles(int type_index, int x, int y, int distance)
{
    int i = 0;
    float total = 0.0f;

    if (this->numResources[type_index] > 0) {
        int offset = 0;
        do {
            char* entry = (char*)this->resourcePtrs[type_index] + offset;
            if (*(unsigned char*)(entry + 0x0D) != 1) {
                RGE_Static_Object* obj = this->md->object(*(int*)entry);
                if (obj != 0 && (type_index != 0 || obj->master_obj->id != 0x3B)) {
                    float dx = obj->x - (float)x;
                    float dy = obj->y - (float)y;
                    if ((int)(sqrt(dx * dx + dy * dy)) <= distance) {
                        total += obj->forageAmount;
                    }
                }
            }
            i++;
            offset += 0x14;
        } while (i < this->numResources[type_index]);
    }

    return (int)total;
}
