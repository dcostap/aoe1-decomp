// 004BD8B0 TSpan_List_Manager::TSpan_List_Manager
// Source: spanlist.cpp
// Size: 234 bytes
//
// Attempt log:
// Probe 1: structural

#include "..\..\include\game_globals.h"

struct VSpan_Node {
    VSpan_Node* Next;
    char _pad[12];
};

class TSpan_Node_List {
public:
    VSpan_Node** zonePtrs;
    int* zoneSizePtrs;
    int nextFreeZone;
    int usedZones;
    VSpan_Node* freeHead;
    int freePoolZone;
    int freePoolIndex;
    char _gap_1C[4];
    int freeBlocks;
    int defaultGrowSize;
    int elementSize;
};

class TSpan_List_Manager : public TSpan_Node_List {
public:
    char _gap_2C[0x44];

    TSpan_List_Manager();
};

TSpan_List_Manager::TSpan_List_Manager()
{
    this->zonePtrs = 0;
    this->zoneSizePtrs = 0;
    this->nextFreeZone = 0;
    this->usedZones = 0;
    this->freeHead = 0;
    this->freePoolZone = -1;
    this->freePoolIndex = 0;
    this->freeBlocks = 0;
    this->defaultGrowSize = 32;
    this->elementSize = sizeof(VSpan_Node);
}
