// 004E3210 TribeInformationAIModule::amountForageBushesInXTiles
// Source: taiinfmd.cpp lines 7592-7609, size 170 bytes
// Attempt log:
// 1: wrong offsets (4D4 instead of 4E0). Fixed gap[0x0C].
// 2: sub esp 0Ch (cached num local). Fixed: use this->numResources directly, total before i.
// 3: byte-identical prologue (sub esp,8; push ebx/edi; xor ebx,ebx; mov dword [esp+8],0).
// 4: MATCH. Key fix: do not name an entry local for the resource row. Direct
//    indexed field access keeps the resources base in EAX and removes the extra
//    EDX/mov pressure that lengthened the first jle to near form.
// 5: replaced the raw resource cursor with the complete ResourceMemory record and
//    indexed fields. Standalone MATCH; the grouped result stayed 3 bytes off because
//    the shared RGE_Static_Object object layout remains unresolved.
// FLAGS: none

#include <math.h>

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct ResourceMemory {
    int id;
    unsigned char x;
    unsigned char y;
    unsigned char gatherAttempts;
    unsigned char pad_07;
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

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
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    void* attackInfo;        // +0xF0
    RGE_Static_Object* object(int object_id);
};

#endif
#ifndef TAIINFMD_PREFIX_CONTEXT
struct TribeInformationAIModule {
    virtual ~TribeInformationAIModule();
    char gap_04[0xFC];
    MainDecisionAIModule* md;      // +0x100
    char gap_104[0x3CC];           // +0x104 to +0x4CF
    ResourceMemory* resources[4];  // +0x4D0
    int numResources[4];           // +0x4E0

    int amountForageBushesInXTiles(int x, int y, int max_distance);
};
#endif

#endif
int TribeInformationAIModule::amountForageBushesInXTiles(int x, int y, int max_distance)
{
    float total = 0.0f;
    int i = 0;
    if (this->numResources[0] > 0) {
        do {
            if (this->resources[0][i].gone != 1) {
                RGE_Static_Object* obj = this->md->object(this->resources[0][i].id);
                if (obj != 0 && obj->master_obj->id == 0x3B) {
                    float dx = obj->x - (float)x; float dy = obj->y - (float)y;
                    if ((int)(sqrt(dx * dx + dy * dy)) <= max_distance) total += obj->forageAmount;
                }
            }
            i++;
        } while (i < this->numResources[0]);
    }
    return (int)total;
}
