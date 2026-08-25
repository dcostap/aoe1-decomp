// 004E1930 numberUnitsWithinXTiles
// TribeInformationAIModule::numberUnitsWithinXTiles
// Source: taiinfmd.cpp lines 6656-6676
// Size: 197 bytes
//
// Status: exact validated match
//
// Attempt log:
// Probe 1: natural C++ with type stubs (wrong field offsets)
// Probe 2: inheritance-based offsets, while loop with boolean
// Probe 3: do-while goto/shared distance (192 bytes, too short)
// Probe 4: goto with exact original branch pattern (192 bytes)
// Probe 5: do-while with continue pattern (192 bytes, too short)
// Probe 6: do-while with boolean doCheck (197 bytes, 27.9% edit diff)
// Session probe 1: typed md->player surface plus explicit owner-dispatch labels
// moved the branch family but was 8 bytes short; rolled back as less natural.
// Session probe 2: combined owner-or-enemy gate with a nested sentinel test
// produced exact bytes; rewrote it as a natural nested boolean expression.
// Session probe 3: removed the diagnostic labels; emitted code stayed exact.
//
// Exact reconstruction: important-object records are 0x24 bytes; md->player is
// the typed owner-check surface at +0xF0; the combined owner/enemy predicate
// preserves the original redundant playerFilter sentinel comparison.

#include <stdlib.h>

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct ObjectMemory {
    int id;                    // +0x00
    short type;                // +0x04
    short group;               // +0x06
    unsigned char x;           // +0x08
    unsigned char y;           // +0x09
    unsigned char z;           // +0x0A
    unsigned char owner;       // +0x0B
    short hitPoints;           // +0x0C
    unsigned char pad_0E[2];   // +0x0E
    int attackAttempts;        // +0x10
    unsigned char kills;       // +0x14
    unsigned char pad_15[3];   // +0x15
    float damageCapability;    // +0x18
    float rateOfFire;          // +0x1C
    float range;              // +0x20
};

#endif
class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual int isEnemy(int playerNum);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;             // +0xF0
};

struct TribeInformationAIModule_base {
    char pad[0xF0];
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule : public TribeInformationAIModule_base {
public:
    char gap_F0[0x10];
    MainDecisionAIModule* md;  // +0x100
    int mapXSizeValue;         // +0x104
    int mapYSizeValue;         // +0x108
    int lastUpdateRowValue;    // +0x10C
    int maxImportantObjectMemory; // +0x110
    ObjectMemory* importantObjectMemory; // +0x114

    int numberUnitsWithinXTiles(int playerFilter, int xCenter, int yCenter, int radius);
};
#endif

#endif
int TribeInformationAIModule::numberUnitsWithinXTiles(int playerFilter, int xCenter, int yCenter, int radius)
{
    int radiusSquared = radius * radius;
    int resultCount = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if ((playerFilter == -1 ||
                 (int)this->importantObjectMemory[i].owner == playerFilter) &&
                (playerFilter != -1 ||
                 this->md->player->isEnemy(this->importantObjectMemory[i].owner) != 0)) {
                int dx = (int)this->importantObjectMemory[i].x - xCenter;
                int dy = (int)this->importantObjectMemory[i].y - yCenter;
                if (dx * dx + dy * dy <= radiusSquared) {
                    resultCount++;
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return resultCount;
}
