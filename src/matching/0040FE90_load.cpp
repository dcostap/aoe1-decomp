// VA: 0040FE90 AIPlayStatus::load (214B)
// PDB source: aipbook.cpp lines 848-863
// Loads AI player status from file
#include "..\..\include\game_globals.h"

void rge_read(int file, void* data, int size);

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
    
    void load(int file);
};

void AIPlayStatus::load(int file) {
    int iVar1 = file;
    
    rge_read(file, &playNumberValue, 4);
    rge_read(iVar1, &targetValue, 4);
    rge_read(iVar1, &file, 4);
    originalPointValue.xValue = file;
    rge_read(iVar1, &file, 4);
    originalPointValue.yValue = file;
    rge_read(iVar1, &file, 4);
    originalPointValue.zValue = file;
    rge_read(iVar1, originalHitPointsValue, 20);
    rge_read(iVar1, &currentPhaseValue, 1);
    rge_read(iVar1, this, 400);
    rge_read(iVar1, &savedAttackerValue, 4);
    rge_read(iVar1, &lastPhaseChangeTimeValue, 4);
}
