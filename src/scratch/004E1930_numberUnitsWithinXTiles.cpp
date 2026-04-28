// 004E1930 numberUnitsWithinXTiles
// TribeInformationAIModule::numberUnitsWithinXTiles
// Source: taiinfmd.cpp lines 6656-6676
// Size: 197 bytes
//
// Status: PARKED - VC5 codegen structure drift
//
// Attempt log:
// Probe 1: natural C++ with type stubs (wrong field offsets)
// Probe 2: inheritance-based offsets, while loop with boolean
// Probe 3: do-while goto/shared distance (192 bytes, too short)
// Probe 4: goto with exact original branch pattern (192 bytes)
// Probe 5: do-while with continue pattern (192 bytes, too short)
// Probe 6: do-while with boolean doCheck (197 bytes, 27.9% edit diff)
//
// Remaining diff (73% positional, 27.9% edit):
//   1. Inverted branch: orig uses je (== -1, to enemy_check),
//      rebuilt uses jne (!= -1, to else path)
//   2. Missing redundant cmp playerFilter,-1; jne do_dist after
//      owner match (orig has it, it's always taken)
//   3. sete/mov/test for boolean vs direct jne in original
//   4. jmp to shared result check in -1 path (rebuilt) vs
//      fall-through in original
//   5. Register allocation differences throughout
//
// All field offsets, call targets, stack cleanup, and return
// values are correct. Control flow shape and register allocation
// are VC5 TU-context dependent patterns.

#include <stdlib.h>

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

class RGE_Player {
public:
    virtual void vt_pad_00();
    virtual void vt_pad_01();
    virtual void vt_pad_02();
    virtual void vt_pad_03();
    virtual void vt_pad_04();
    virtual void vt_pad_05();
    virtual int isEnemy(int playerNum);
};

struct TribeInformationAIModule_base {
    char pad[0xF0];
};

class TribeInformationAIModule : public TribeInformationAIModule_base {
public:
    char gap_F0[0x10];
    void* md;                  // +0x100
    int mapXSizeValue;         // +0x104
    int mapYSizeValue;         // +0x108
    int lastUpdateRowValue;    // +0x10C
    int maxImportantObjectMemory; // +0x110
    ObjectMemory* importantObjectMemory; // +0x114

    int numberUnitsWithinXTiles(int playerFilter, int xCenter, int yCenter, int radius);
};

int TribeInformationAIModule::numberUnitsWithinXTiles(int playerFilter, int xCenter, int yCenter, int radius)
{
    int radiusSquared = radius * radius;
    int resultCount = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            int doCheck;
            if (playerFilter == -1) {
                RGE_Player* aiPlayer = *(RGE_Player**)((char*)this->md + 0xF0);
                doCheck = aiPlayer->isEnemy(this->importantObjectMemory[i].owner);
            } else {
                doCheck = ((int)this->importantObjectMemory[i].owner == playerFilter);
            }
            if (doCheck) {
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
