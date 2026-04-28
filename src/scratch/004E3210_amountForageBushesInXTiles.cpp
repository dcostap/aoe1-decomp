// 004E3210 TribeInformationAIModule::amountForageBushesInXTiles
// Source: taiinfmd.cpp lines 7592-7609, size 170 bytes
// Attempt log:
// 1: wrong offsets (4D4 instead of 4E0). Fixed gap[0x0C].
// 2: sub esp 0Ch (cached num local). Fixed: use this->numResources directly, total before i.
// 3: byte-identical prologue (sub esp,8; push ebx/edi; xor ebx,ebx; mov dword [esp+8],0).
// FLAGS: none
// Left in scratch: 48 edit bytes diff. All remaining differences are register allocation
// (eax↔edx↔ecx for resources base, id, master_obj) and jle short vs near branch encoding.
// FPU distance calculation (fild/fsubr/fxch/fmul/faddp/fsqrt/call __ftol) is byte-identical.
// Prologue, stack layout, loop structure, and field offsets all match.

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
    void* resources;               // +0x4D0
    char gap_4D4[0x0C];            // +0x4D4 to +0x4DF
    int numResources;              // +0x4E0

    int amountForageBushesInXTiles(int x, int y, int max_distance);
};

int TribeInformationAIModule::amountForageBushesInXTiles(int x, int y, int max_distance)
{
    float total = 0.0f;
    int i = 0;

    if (this->numResources > 0) {
        int offset = 0;
        do {
            char* entry = (char*)this->resources + offset;
            if (*(unsigned char*)(entry + 0x0D) != 1) {
                RGE_Static_Object* obj = this->md->object(*(int*)entry);
                if (obj != 0 && obj->master_obj->id == 0x3B) {
                    float dx = obj->x - (float)x;
                    float dy = obj->y - (float)y;
                    if ((int)(sqrt(dx * dx + dy * dy)) <= max_distance) {
                        total += obj->forageAmount;
                    }
                }
            }
            i++;
            offset += 0x14;
        } while (i < this->numResources);
    }

    return (int)total;
}
