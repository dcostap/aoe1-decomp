#include <string.h>

#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    char gap_00[0x1004];
    int SizeArrays;
    char gap_1008[0x1C];
    char* ProbArray;
    char* PlacementArray;
    char gap_102C[0x10];
    int DrawToOneArrayFlag;

    void ClearArrays();
};
#endif

void PointMaker::ClearArrays() {
    if (DrawToOneArrayFlag == 0 && PlacementArray != 0) {
        memset(PlacementArray, 0, SizeArrays);
    }
    if (ProbArray != 0) {
        memset(ProbArray, 0, SizeArrays);
    }
}
