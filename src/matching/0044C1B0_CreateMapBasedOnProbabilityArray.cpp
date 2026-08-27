// BINARY NOTE: The direct indexed-array form now matches in the authentic
// fractal.cpp wrapper. It preserves the scan, stores, and hit-count update.

#ifndef FRACTAL_ARRAYS_CONTEXT_H
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
#endif

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
