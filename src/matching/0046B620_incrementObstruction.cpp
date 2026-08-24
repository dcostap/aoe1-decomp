// VA: 0046B620 PathingSystem::incrementObstruction
// PDB source: pathsys.cpp, lines 641-652
// Notes from previous attempts:
// - Original keeps shift in cl throughout without spill; VC5 spills cl after shr
// - Trying inline table access to avoid spill

extern const unsigned char ObstructionValueShift[];
extern const unsigned char ObstructionValueMask[];

#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    char gap_00[0xCE624];
    unsigned char obstructionValue[];

    void incrementObstruction(int x, int y);
};
#endif

void PathingSystem::incrementObstruction(int x, int y) {
    unsigned char* ptr = &obstructionValue[x * 255 + (y >> 2)];
    unsigned char val = *ptr;
    unsigned char field = (val >> ObstructionValueShift[y & 3]) & 3;
    if (field >= 3) {
        return;
    }
    *ptr = (ObstructionValueMask[y & 3] & val) | ((field + 1) << ObstructionValueShift[y & 3]);
}
