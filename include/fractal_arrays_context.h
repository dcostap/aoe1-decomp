#ifndef FRACTAL_ARRAYS_CONTEXT_H
#define FRACTAL_ARRAYS_CONTEXT_H

class PointMaker {
public:
    char gap_000[0xFD4];
    int Width;
    int Height;
    char gap_FDC[0x1004 - 0xFDC];
    int SizeArrays;
    char gap_1008[0x1024 - 0x1008];
    char* ProbArray;
    char* PlacementArray;
    char gap_102C[0x103C - 0x102C];
    int DrawToOneArrayFlag;

    void ClearArrays();
    void DeleteArrays();
    void MakeArrays();
};

#endif
