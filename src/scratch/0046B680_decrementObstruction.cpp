// attempt 1: instruction order different, params read in wrong order
// attempt 2: extern arrays, same VC5 reordering
// attempt 3: (param1 * 256) + (param2 >> 2), same
// attempt 4: swapped expression terms, same
// attempt 5: local temps a and b, same
// attempt 6: param1 * 255, adds extra push edi
// left in scratch: VC5 always reads param2 ([esp+8]) first instead of param1 ([esp+4])
// this changes register allocation and pushes (original has 2 pushes, rebuilt has 2-3)
// behavior fully correct, size matches (82 bytes), benign codegen drift

extern const unsigned char ObstructionValueShift[4];
extern const unsigned char ObstructionValueMask[4];

class PathingSystem {
public:
    char gap_00[0xCE624];
    unsigned char obstruction_value[256 * 256];

    void decrementObstruction(int param1, int param2);
};

void PathingSystem::decrementObstruction(int param1, int param2) {
    int a = param1 * 255;
    unsigned char* p = &obstruction_value[a + (param2 >> 2)];
    unsigned char val = *p;
    unsigned char shift = ObstructionValueShift[param2 & 3];
    unsigned char ob = (val >> shift) & 3;
    if (ob <= 0) return;
    unsigned char mask = ObstructionValueMask[param2 & 3];
    *p = (mask & val) | ((ob - 1) << shift);
}
