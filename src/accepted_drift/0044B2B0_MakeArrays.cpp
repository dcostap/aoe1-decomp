// VA: 0044B2B0 PointMaker::MakeArrays (112 B)
// PDB source: fractal.cpp lines 194-206
// Flags: default (config/flags/default.rsp)
//
// BINARY NOTE: SizeArrays uses signed int multiplication. Keep Height * Width
// and its natural VC5 overflow behavior. Do not use a checked product.
// BINARY NOTE: Both loops use `while (count-- != 0)` with count set to 10.
// VC5 emits 9 as the initial value, then tests the saved value after each call.
// This gives ten allocation attempts without an extra allocator null check.
// BINARY NOTE: Each returned pointer is published before the retry counter
// test. A failed second allocation leaves ProbArray published and retries only
// PlacementArray. operator new exceptions propagate; this function has no EH
// cleanup or array-byte initialization. ClearArrays owns later zeroing.
//
// Full-owner audit: the complete SetDefaultValues-through-MapCleanUp sequence
// keeps the correct boundary and calls, but emits a two-byte Width-first drift.
// The shorter registered prefix emitted Height-first bytes. Keep this owner
// as reviewed drift until the integration owner selects one authentic context.

void* __cdecl operator new(unsigned int size);

#ifndef FRACTAL_ARRAYS_CONTEXT_H
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
#endif

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
