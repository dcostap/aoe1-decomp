// attempt 1: pointer field + pointer math; total mismatch at offset 1 (prologue, all different)
// attempt 2: byte array + extern globals; first 52 bytes match, mismatch at +52 (VC5 saves cl to [esp+14h])
// attempt 3: mask computed early; param order swapped back (edx/eax reversed at offset 1)
// attempt 4: named ob var; same as attempt 2, cl saved to stack
// Original: keeps shift in cl through both shr and shl without spill; VC5 spills cl after shr
// Left in scratch: VC5 register liveness analysis differs, benign codegen drift, behavior correct

const unsigned char ObstructionValueShift[] = { 0, 2, 4, 6 };
const unsigned char ObstructionValueMask[] = { 0xFC, 0xF3, 0x3F, 0xCF };

class PathingSystem {
public:
    char gap_00[0xCE624];
    unsigned char obstructionValue[0x10000];

    void incrementObstruction(int x, int y);
};

void PathingSystem::incrementObstruction(int x, int y) {
    unsigned char* ptr = obstructionValue + x * 255 + (y >> 2);
    unsigned char val = *ptr;
    unsigned char shift = ObstructionValueShift[y & 3];
    if (((val >> shift) & 3) >= 3) {
        return;
    }
    unsigned char mask = ObstructionValueMask[y & 3];
    unsigned char inc = ((val >> shift) & 3) + 1;
    *ptr = (mask & val) | (inc << shift);
}
