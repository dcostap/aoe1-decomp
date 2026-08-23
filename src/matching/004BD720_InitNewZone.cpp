// 004BD720 TSpan_Node_List::InitNewZone
// Source: spanlist.cpp lines 139-170
// Size: 112 bytes
// Attempt log:
// - natural C++ scaffold used calloc and omitted counters/free pool updates.
// - switched to malloc and full observed fields.

#ifndef SPANLIST_SHARED_CONTEXT
struct VSpan_Node;

class TSpan_Node_List {
public:
    VSpan_Node** zonePtrs;      // +0x00
    int* zoneSizePtrs;          // +0x04
    int usedZones;              // +0x08
    int maxZones;               // +0x0C
    VSpan_Node* freeHead;       // +0x10
    int freePoolZone;           // +0x14
    int freePoolIndex;          // +0x18
    int totalBlocks;            // +0x1C
    int freeBlocks;             // +0x20
    int defaultGrowSize;        // +0x24
    int elementSize;            // +0x28
    char gap_2C[8];             // +0x2C
    int newZoneCount;           // +0x34

    void InitNewZone(int growSize);
    void SetNumZones(int newCount);
};
#endif

extern "C" void* __cdecl malloc(unsigned int size);

void TSpan_Node_List::InitNewZone(int growSize)
{
    if (this->usedZones == this->maxZones) {
        SetNumZones(this->usedZones + 4);
    }

    int idx = this->usedZones;
    int grow = growSize;
    int* sizes = this->zoneSizePtrs;
    this->usedZones = idx + 1;
    int bytes = this->elementSize * grow;
    sizes[idx] = grow;
    this->zonePtrs[idx] = (VSpan_Node*)malloc(bytes);

    this->newZoneCount++;
    this->totalBlocks += growSize;
    this->freeBlocks += growSize;

    if (this->freePoolZone == -1) {
        this->freePoolZone = idx;
        this->freePoolIndex = 0;
    }
}
