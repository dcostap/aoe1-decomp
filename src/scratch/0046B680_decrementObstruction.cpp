// VA: 0046B680 PathingSystem::decrementObstruction(int, int)
// PDB source: pathsys.cpp lines 658-668 (82 bytes, 28 asm lines)
// Default flags
//
// __thiscall: this in ecx, 2 stack params (int, int). ret 8 cleanup.
//
// Attempt log:
// - attempts 1-10+ (prior): param2 always read first by VC5, causing extra push edi and wrong reg alloc
// - current/best: direct pointer expression below gives exact size 82/82 but still swaps initial param load order and saves EDI; 79.27% positional / 76.83% edit.
// - HollowSnowdrop pass: tried explicit rowOffset/byteIndex/lane locals and a 2D obstruction_value[256][255] surface; both kept the worse param2-first/EDI basin. Rolled back to prior best.

extern const unsigned char ObstructionValueShift[4];
extern const unsigned char ObstructionValueMask[4];

class PathingSystem {
public:
    char gap_00[0xCE624];
    unsigned char obstruction_value[256 * 256];

    void decrementObstruction(int param1, int param2);
};

void PathingSystem::decrementObstruction(int param1, int param2) {
    unsigned char* p = &obstruction_value[param1 * 255];
    p += param2 >> 2;
    unsigned char val = *p;
    unsigned char shiftIdx = param2 & 3;
    unsigned char shift = ObstructionValueShift[shiftIdx];
    unsigned char field = (val >> shift) & 3;
    if (field == 0) return;
    *p = (ObstructionValueMask[shiftIdx] & val) | ((field - 1) << shift);
}
