// VA: 004E4790 TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int, int)
// PDB source: taiinfmd.cpp lines 8565-8574
// Default flags
//
// attempt log:
// Attempt 1: natural C++ expression → 88/105 match, 59 positional diff
//   Problem: VC5 reorders: computes mapX/4, THEN starts qy before imul*mapY
//   Original order: sar mapX/4 → imul*mapY → cdq/and/add → THEN qy
//   Our order:      sar mapX/4 → LOAD param_2, compute qy → THEN imul*mapY
// Attempt 2: separate lines for denom = X/4; denom*=Y → 78/105 (worse)
// Attempt 3: final_denom before qy → 88/105 (same as 1)
// Attempt 4: local int mx, int my → different reg alloc, worse
// Attempt 5: virtual function in class → 62/105, first mismatch at 0 (vtable shifts offsets)
//
// Root cause: VC5 reorders independent denom/qy computations around mapY.
// In native TU context (taiinfmd.cpp), the full file's register pressure
// and scheduling heuristics produce a different ordering than single-function
// compilation. The operations are semantically equivalent but structurally
// diverge after the first sar+imul scheduling point.
//
// Note: The ((int*)this)[idx] access pattern works without a vtable at +0
// because the class apparently has no compiler-managed vtable in this build.

class TribeInformationAIModule {
public:
    char gap_00[0x104];
    int mapX;
    int mapY;

    int percentTilesExploredInPositionQuadrant(int param_1, int param_2);
};

int TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int param_1, int param_2) {
    if (this->mapX == -1) return 0;

    int qx = (param_1 * 4) / this->mapX;
    int denom = (this->mapX / 4) * this->mapY;
    denom = denom + (denom >> 31 & 3);
    int qy = (param_2 * 4) / this->mapY;
    int final_denom = denom >> 2;

    int idx = (qy + qx * 4 + 0x56) * 3;
    int value = ((int*)this)[idx];
    return (value * 100) / final_denom;
}
