// VA: 0040A060 BaseObject::BaseObject (parameterized constructor)
// PDB source: aibobj.cpp
// Attempt log:
// - v1: member assignments, category first -> 49% diff (reads both params before push esi)
// - v2: explicit offset writes -> 61.5% diff
// - v3: reordered maxHit after numberGroupsValue -> 42.5% diff
// - v4: swapped type/category order -> 42% diff  
// - v5: operator_new pushed right after type -> 82.5% diff (scheduling disaster)
// - v6: temp alloc_size var -> 208 bytes (8 too big)
// - session baseline: typed pointer/float ownership preserved the same 42% basin.
// - session probes: first-field permutations, register-qualified parameters, comma/local zero
//   variants, and scalar initializer-list forms were unchanged or worse; no exact basin found.
// Best source reconstruction: natural typed fields, direct body assignments, operator_new(4), strncpy.
// Basin: param read order differences cause register allocation drift.
// VC5 interleaves push esi between first and second param read; C++ doesn't force this.

#include <string.h>
#include <stdlib.h>

extern "C" {
    void* __cdecl operator_new(size_t size);
}

struct BaseObject {
    void* vtable;          // +0x00
    BaseObject* next;      // +0x04
    BaseObject* prev;      // +0x08
    int numberGroupsValue; // +0x0C
    int* groupIDValue;     // +0x10
    int categoryIDValue;   // +0x14
    int typeIDValue;       // +0x18
    int gameIDValue;       // +0x1C
    char nameValue[64];    // +0x20
    float xPositionValue;  // +0x60
    float yPositionValue;  // +0x64
    float zPositionValue;  // +0x68
    float xSizeValue;      // +0x6C
    float ySizeValue;      // +0x70
    float zSizeValue;      // +0x74
    int hitPointValue;     // +0x78
    int minHitPointValue;  // +0x7C
    int maxHitPointValue;  // +0x80
    int busyValue;         // +0x84
    int currentTaskValue;  // +0x88
    int currentTargetValue;// +0x8C
    int currentTargetTypeValue; // +0x90
    float currentTargetXPositionValue; // +0x94
    float currentTargetYPositionValue; // +0x98
    float currentTargetZPositionValue; // +0x9C

    BaseObject(int a, int category, int type, int game, char* name,
        float xSize, float ySize, float zSize,
        float xPos, float yPos, float zPos,
        int hitPt, int minHit, int maxHit);
};

BaseObject::BaseObject(int a, int category, int type, int game, char* name,
    float xSize, float ySize, float zSize,
    float xPos, float yPos, float zPos,
    int hitPt, int minHit, int maxHit)
{
    typeIDValue = type;
    categoryIDValue = category;
    gameIDValue = game;
    xPositionValue = xPos;
    yPositionValue = yPos;
    zPositionValue = zPos;
    xSizeValue = xSize;
    ySizeValue = ySize;
    zSizeValue = zSize;
    hitPointValue = hitPt;
    minHitPointValue = minHit;
    next = 0;
    prev = 0;
    numberGroupsValue = 1;
    maxHitPointValue = maxHit;
    busyValue = 0;
    currentTaskValue = -1;
    currentTargetValue = -1;
    currentTargetTypeValue = -1;
    currentTargetXPositionValue = 0;
    currentTargetYPositionValue = 0;
    currentTargetZPositionValue = 0;
    vtable = (void*)0x56E798;

    groupIDValue = (int*)operator_new(4);
    groupIDValue[0] = a;

    strncpy(nameValue, name, 63);
}
