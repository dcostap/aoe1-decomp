// ACCEPTED_DRIFT: 1-byte SIB addressing-order drift only: cmp byte [eax+esi],0 vs [esi+eax],0; same address, flags, stores, loop bounds, and return behavior.
// first pass: scan ProbabilityArray and mirror hits into PlacementArray, then add the hit count
// first close build only drifted on the indexed-byte compare encoding; a later local-pointer probe was worse and got rolled back
// next probe: keep the simple field-based loop but spell the index expression from the other operand side

class PointMaker {
public:
    char gap_00[0xFE4];
    int NumTilesActuallyChosen;
    char gap_FE8[0x1C];
    int SizeArrays;
    char gap_1004[0x1C];
    unsigned char* ProbArray;
    unsigned char* PlacementArray;

    void CreateMapBasedOnProbabilityArray(void);
};

void PointMaker::CreateMapBasedOnProbabilityArray(void) {
    int hits = 0;
    int i = 0;

    if (0 < SizeArrays) {
        do {
            if (i[ProbArray] != 0) {
                ++hits;
                i[PlacementArray] = 1;
            }
            ++i;
        } while (i < SizeArrays);
    }

    NumTilesActuallyChosen += hits;
}
