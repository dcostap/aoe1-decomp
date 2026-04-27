// 004BD690 TSpan_Node_List::SetNumZones
// Source: spanlist.cpp lines 96-132
// Size: 135 bytes
//
// Attempt log:
// Probe 1: 135/135B, 22% diff — relocation basin (operator_delete, calloc calls differ)
//   Layout corrected: nextFreeZone (+0x08), usedZones (+0x0C)

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

    void SetNumZones(int newCount);
};

extern void* __cdecl calloc(int num, int size);
extern void __cdecl operator_delete(void* ptr);

void TSpan_Node_List::SetNumZones(int newCount)
{
    if (newCount < this->usedZones)
        return;

    VSpan_Node** newZonePtrs = (VSpan_Node**)calloc(newCount, 4);
    int* newZoneSizePtrs = (int*)calloc(newCount, 4);

    if (this->zonePtrs) {
        int i;
        for (i = 0; i < this->nextFreeZone; i++) {
            newZonePtrs[i] = this->zonePtrs[i];
            newZoneSizePtrs[i] = this->zoneSizePtrs[i];
        }
    }

    if (this->zonePtrs)
        operator_delete(this->zonePtrs);
    if (this->zoneSizePtrs)
        operator_delete(this->zoneSizePtrs);

    this->zonePtrs = newZonePtrs;
    this->zoneSizePtrs = newZoneSizePtrs;
    this->usedZones = newCount;
}
