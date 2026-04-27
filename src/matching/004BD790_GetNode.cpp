// 004BD790 TSpan_Node_List::GetNode
// Source: spanlist.cpp lines 177-228
// public: VSpan_Node* __thiscall TSpan_Node_List::GetNode(void)
//
// Attempt log:
// Probe 1: natural pool-allocator — wrong sizeof(VSpan_Node) (4 vs 16), extra register
// Probe 2: padded VSpan_Node to 16 bytes — still extra push ebx
// Probe 3: inline locals to match register allocation

#include "..\..\include\game_globals.h"

struct VSpan_Node {
    VSpan_Node* Next;
    char _pad[12];
};

class TSpan_Node_List {
public:
    VSpan_Node** zonePtrs;
    int* zoneSizePtrs;
    int usedZones;
    char _gap_0C[4];
    VSpan_Node* freeHead;
    int freePoolZone;
    int freePoolIndex;
    char _gap_1C[4];
    int freeBlocks;
    int defaultGrowSize;

    void InitNewZone(int growSize);
    VSpan_Node* GetNode();
};

VSpan_Node* TSpan_Node_List::GetNode()
{
    if (this->freeBlocks == 0) {
        this->InitNewZone(this->defaultGrowSize);
    }

    if (this->freeHead != 0) {
        VSpan_Node* node = this->freeHead;
        this->freeHead = node->Next;
        this->freeBlocks--;
        return node;
    }

    int zone = this->freePoolZone;
    VSpan_Node* result = this->zonePtrs[zone] + this->freePoolIndex;

    this->freeBlocks--;
    this->freePoolIndex++;

    if (this->freePoolIndex == this->zoneSizePtrs[zone]) {
        this->freePoolZone = zone + 1;
        this->freePoolIndex = 0;
        if (zone + 1 == this->usedZones) {
            this->freePoolZone = -1;
        }
    }

    return result;
}
