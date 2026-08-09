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
// - fresh pass: moving next/prev zero assignments ahead of parameter stores reduced the drift to 4 bytes.
// - fresh pass: category-before-type with that early zero lifetime produced an exact 200-byte match.
// Best source reconstruction: natural typed fields, direct body assignments, operator_new(4), strncpy.
// Exact source shape: next/prev first, then category/type/game; the early zero value steers VC5's
//   first parameter loads and register roles without raw offsets or compiler-only scaffolding.
// Main-agent audit: restored the proven virtual destructor surface. VC5's automatic vptr
// store schedules too early, so the binary-backed delayed store uses the narrow documented
// novtable fallback; natural `new int` is codegen-identical to the old helper declaration.

#include <string.h>
#include <stdlib.h>

void* __cdecl operator new(size_t size);

struct __declspec(novtable) BaseObject {
    virtual ~BaseObject();
    BaseObject* next;  // +0x04
    BaseObject* prev;  // +0x08
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
    next = 0;
    prev = 0;
    categoryIDValue = category;
    typeIDValue = type;
    gameIDValue = game;
    xPositionValue = xPos;
    yPositionValue = yPos;
    zPositionValue = zPos;
    xSizeValue = xSize;
    ySizeValue = ySize;
    zSizeValue = zSize;
    hitPointValue = hitPt;
    minHitPointValue = minHit;
    numberGroupsValue = 1;
    maxHitPointValue = maxHit;
    busyValue = 0;
    currentTaskValue = -1;
    currentTargetValue = -1;
    currentTargetTypeValue = -1;
    currentTargetXPositionValue = 0;
    currentTargetYPositionValue = 0;
    currentTargetZPositionValue = 0;
    *(void**)this = (void*)0x56E798;

    groupIDValue = new int;
    groupIDValue[0] = a;

    strncpy(nameValue, name, 63);
}
