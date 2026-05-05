// ACCEPTED_DRIFT
// VA: 0044B2B0 PointMaker::MakeArrays (112 B)
// PDB source: fractal.cpp lines 194-206
// Flags: default (no custom flags)
// 
// 2 bytes diff out of 112 (98.2% match):
// mov eax, [esi+0xFD8] vs mov eax, [esi+0xFD4]; imul operand bytes swapped
// cause: VC5 internal evaluation order for commutative multiplication operands.
// Original loads Height first (from +0xFD8), rebuilt loads Width first (from +0xFD4).
// Behaviorally identical: Height * Width == Width * Height.
// All other code identical: prologue, loop structure, loop counter, allocation,
// member storage, epilogue.
//
// Key matching insight: "while (count-- != 0)" generates the exact peeled loop
// structure without null checks on operator_new. "do-while (count-- != 0)" with
// the same counter generates extra "test eax, eax; je alloc" null checks.
// Counter must be 10 instead of 9 to compensate for while-loop peeling.

void* __cdecl operator new(unsigned int size);

class PointMaker {
public:
    char gap_000[0xFD4];
    int Width;              // +0xFD4
    int Height;             // +0xFD8
    char gap_FDC[0x1004 - 0xFD8 - 4];
    int SizeArrays;         // +0x1004
    char gap_1008[0x1024 - 0x1004 - 4];
    char* ProbArray;        // +0x1024
    char* PlacementArray;   // +0x1028

    void MakeArrays();
};

void PointMaker::MakeArrays()
{
    this->SizeArrays = this->Height * this->Width;
    int count = 10;
    while (count-- != 0) {
        if (this->ProbArray != 0) break;
        this->ProbArray = (char*)operator new(this->SizeArrays);
    }
    count = 10;
    while (count-- != 0) {
        if (this->PlacementArray != 0) break;
        this->PlacementArray = (char*)operator new(this->SizeArrays);
    }
}
