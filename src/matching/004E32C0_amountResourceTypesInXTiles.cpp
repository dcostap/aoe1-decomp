// 004E32C0 TribeInformationAIModule::amountResourceTypesInXTiles
// Source: taiinfmd.cpp lines 7615-7635, size 197 bytes
//
// Attempt log:
// Baseline: canonical ResourceMemory scan with a carried row pointer emitted the
// right size/frame/calls but differed from the prologue and row setup (174 bytes).
// Probe 2: total-before-index initialization improved the setup but left a 2-byte
// size overrun and wrong resource-base coloring (146 bytes).
// Probe 3: repeating direct resources[type_index] expressions, rather than naming
// the row pointer, produced an exact 197-byte match.
// Probe 4: promoted the proven 0x14-byte ResourceMemory array and named fields;
// emitted code remained exact.
// Probes 5-6: natural ResourceMemory* row/id locals changed only the object-call
// argument scheduling (9 bytes); restored the exact direct-expression form.
// Final: default flags, no inline asm/custom flags; 197/197 bytes match.

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

struct ResourceMemory {
    int id;                  // +0x00
    unsigned char x;         // +0x04
    unsigned char y;         // +0x05
    unsigned char gatherAttempts; // +0x06
    unsigned char gap_07;    // +0x07
    int gatherValue;         // +0x08
    unsigned char valid;     // +0x0C
    unsigned char gone;      // +0x0D
    unsigned char dropDistance; // +0x0E
    unsigned char resourceType; // +0x0F
    int dropsiteID;          // +0x10
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
    ResourceMemory* resources[4];  // +0x4D0 (array of 0x14-byte resource records)
    int numResources[4];           // +0x4E0 (array of counts, indexed by type_index)

    int amountResourceTypesInXTiles(int type_index, int x, int y, int distance);
};

int TribeInformationAIModule::amountResourceTypesInXTiles(int type_index, int x, int y, int distance)
{
    float total = 0.0f;
    int i = 0;

    if (this->numResources[type_index] > 0) {
        int offset = 0;
        do {
            if (((ResourceMemory*)((char*)this->resources[type_index] + offset))->gone != 1) {
                RGE_Static_Object* obj = this->md->object(
                    ((ResourceMemory*)((char*)this->resources[type_index] + offset))->id);
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
