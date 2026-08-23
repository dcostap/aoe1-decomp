// VA: 0040FF70 AIPlayStatus::save (214B)
// PDB source: aipbook.cpp lines 868-882
// BINARY NOTE: This is the inverse of load. It writes all 400 grouping bytes
// after the phase byte, then writes savedAttacker and lastPhaseChangeTime.
// The shipped code reuses the incoming file home for each point coordinate.
#ifndef AIPBOOK_CANONICAL_TU
#include "..\..\include\game_globals.h"
#endif

void rge_write(int file, void* data, int size);

#ifndef AIPBOOK_CANONICAL_TU
struct PointValue {
    int xValue;
    int yValue;
    int zValue;
};

struct AIPlayStatus {
    char core[0x190];
    int playNumberValue;              // +0x190
    int targetValue;                  // +0x194
    PointValue originalPointValue;    // +0x198 (x, y, z)
    int originalHitPointsValue[5];    // +0x1A4 (5 ints)
    unsigned char currentPhaseValue;  // +0x1B8
    char pad_1B9[3];
    int savedAttackerValue;           // +0x1BC
    int lastPhaseChangeTimeValue;     // +0x1C0
    
    void save(int file);
};
#endif

void AIPlayStatus::save(int file) {
    int iVar1 = file;
    
    rge_write(file, &playNumberValue, 4);
    rge_write(iVar1, &targetValue, 4);
    file = originalPointValue.xValue;
    rge_write(iVar1, &file, 4);
    file = originalPointValue.yValue;
    rge_write(iVar1, &file, 4);
    file = originalPointValue.zValue;
    rge_write(iVar1, &file, 4);
    rge_write(iVar1, originalHitPointsValue, 20);
    rge_write(iVar1, &currentPhaseValue, 1);
    rge_write(iVar1, this, 400);
    rge_write(iVar1, &savedAttackerValue, 4);
    rge_write(iVar1, &lastPhaseChangeTimeValue, 4);
}
