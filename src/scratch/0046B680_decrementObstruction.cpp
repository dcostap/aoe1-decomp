// VA: 0046B680 PathingSystem::decrementObstruction(int, int)
// PDB source: pathsys.cpp lines 658-668 (82 bytes, 28 asm lines)
// Default flags
//
// BLOCKER: remaining mismatch is a stable decrement-only VC5 register/scheduling
// basin. The nearby matched incrementObstruction source surface compiles to a
// very close but larger EDI family: y loads before x, pushes EDI, uses EDI for
// row offset, then pops EDI. Original decrement is a more compact family:
// x loads first into EAX, y into EDX, only EBX/ESI are saved, row offset is
// computed in ESI, then ECX is adjusted by that row offset before byte-indexing.
//
// Attempt log:
// - attempts 1-10+ (prior): param2 always read first by VC5, causing extra push edi and wrong reg alloc.
// - prior best: direct pointer expression gave exact size 82/82 but swapped initial param load order and saved EDI; 79.27% positional / 76.83% edit.
// - HollowSnowdrop pass: tried explicit rowOffset/byteIndex/lane locals and a 2D obstruction_value[256][255] surface; both kept the worse param2-first/EDI basin.
// - ZestyPond 1: row/col locals declared in source order plus positive field guard: still param2-first/EDI.
// - ZestyPond 2: split row offset, row pointer, byte index in source order: worse, still param2-first and EDI.
// - ZestyPond 3: inline shift table access: removed CL spill but lost EBX/changed val register and conditional EBX save.
// - ZestyPond 4: volatile param1 read: made row load first but into EDX, still EDI and conditional EBX.
// - ZestyPond 5: 2D row surface with inline shift: same as inline flat family.
// - ZestyPond 6: register row/col locals with named shift: same wrong family.
// - ZestyPond 7: direct hardcoded table addresses rather than extern arrays: no improvement.
// - ZestyPond 8: mirrored exact matched incrementObstruction source surface/topology: much closer body but extra EDI and reversed initial loads.
// - ZestyPond 9: this-relative adjusted alias to encourage add ecx,rowOffset and avoid EDI: optimized back to increment-style EDI.
// - ZestyPond 10: reuse y parameter as lane after separate byteIndex local: smaller edit diff but still EDI and shifted prologue.
// - ZestyPond 11: positive field guard on mirror surface recovered original jbe body branch; remaining blocker is prologue/EDI basin.
// - variant_lab: 96 default variants and 1152 vc5-risky variants over flat/2D surface, pointer shapes, lane type, named/inline shift, guard polarity, and flags found no exact match. Best edit diff family was /O1 but wrong 80-byte loop/prologue; best default body is the mirror-increment source below.

extern const unsigned char ObstructionValueShift[];
extern const unsigned char ObstructionValueMask[];

class PathingSystem {
public:
    char gap_00[0xCE624];
    unsigned char obstructionValue[];

    void decrementObstruction(int x, int y);
};

void PathingSystem::decrementObstruction(int x, int y) {
    unsigned char* ptr = &obstructionValue[x * 255 + (y >> 2)];
    unsigned char val = *ptr;
    unsigned char field = (val >> ObstructionValueShift[y & 3]) & 3;
    if (field > 0) {
        *ptr = (ObstructionValueMask[y & 3] & val) | ((field - 1) << ObstructionValueShift[y & 3]);
    }
}
