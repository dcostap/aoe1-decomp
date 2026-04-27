// 004BD720 TSpan_Node_List::InitNewZone
// Source: spanlist.cpp lines 139-170
// Size: 112 bytes
//
// Attempt log:
// Probe 1: natural C++

#include "..\..\include\game_globals.h"

struct VSpan_Node;

class TSpan_Node_List {
public:
    VSpan_Node** zonePtrs;      // +0x00
    int* zoneSizePtrs;          // +0x04
    int nextFreeZone;           // +0x08
    int usedZones;              // +0x0C
    VSpan_Node* freeHead;       // +0x10
    int freePoolZone;           // +0x14
    int freePoolIndex;          // +0x18
    char _gap_1C[4];            // +0x1C
    int freeBlocks;             // +0x20
    int defaultGrowSize;        // +0x24
    int elementSize;            // +0x28

    void InitNewZone(int growSize);
    void SetNumZones(int newCount);
};

extern void* __cdecl calloc(int num, int size);

void TSpan_Node_List::InitNewZone(int growSize)
{
    if (this->nextFreeZone == this->usedZones)
        SetNumZones(this->nextFreeZone + 4);

    int idx = this->nextFreeZone;
    this->nextFreeZone = idx + 1;
    int entrySize = this->elementSize * growSize;

    this->zoneSizePtrs[idx] = growSize;
    this->zonePtrs[idx] = (VSpan_Node*)calloc(entrySize, 1);
}
