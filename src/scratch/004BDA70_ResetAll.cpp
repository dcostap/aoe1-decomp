// 004BDA70 TSpan_List_Manager::ResetAll
// Source: spanlist.cpp lines 213-237
// Size: 137 bytes
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

    void ResetAll();
};

extern void __cdecl operator_delete(void* ptr);

void TSpan_Node_List::ResetAll()
{
    for (int i = 0; i < this->nextFreeZone; i++) {
        if (this->zonePtrs[i])
            operator_delete(this->zonePtrs[i]);
        this->zonePtrs[i] = 0;
    }
    this->freeHead = 0;
    this->freeBlocks = 0;
    this->nextFreeZone = 0;
    this->freePoolZone = -1;
    this->freePoolIndex = 0;
}
