// VA: 00410050 AIPlayStatus::copy (170B)
// PDB source: aipbook.cpp lines 887-901
// Copies AI player status from another AIPlayStatus
#include "..\..\include\game_globals.h"
#include <string.h>

struct PointValue {
    int xValue;
    int yValue;
    int zValue;
};

struct GroupingStruct {
    int id;                 // offset 0
    unsigned char field1;   // offset 4
    unsigned char field2;   // offset 5
    unsigned char pad[2];   // offset 6-7
};

struct AIPlayStatus {
    char groupings_area[4]; // offset 0 - first 4 bytes are part of groupings area
    GroupingStruct groupings[50];  // offset 4 (50 * 8 = 400 bytes)
    int playNumberValue;              // +0x190
    int targetValue;                  // +0x194
    PointValue originalPointValue;    // +0x198 (x, y, z)
    int originalHitPointsValue[5];    // +0x1A4 (5 ints)
    unsigned char currentPhaseValue;  // +0x1B8
    char pad_1B9[3];
    int savedAttackerValue;           // +0x1BC
    int lastPhaseChangeTimeValue;     // +0x1C0
    
    void copy(AIPlayStatus* other);
};

void AIPlayStatus::copy(AIPlayStatus* other) {
    playNumberValue = other->playNumberValue;
    targetValue = other->targetValue;
    originalPointValue = other->originalPointValue;
    currentPhaseValue = other->currentPhaseValue;
    savedAttackerValue = other->savedAttackerValue;
    lastPhaseChangeTimeValue = other->lastPhaseChangeTimeValue;
    
    memcpy(groupings, other->groupings, 50 * sizeof(GroupingStruct));
    memcpy(originalHitPointsValue, other->originalHitPointsValue, 5 * sizeof(int));
}
