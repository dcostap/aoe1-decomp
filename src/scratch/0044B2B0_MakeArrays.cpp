// VA: 0044B2B0
// PointMaker::MakeArrays()
// Source: fractal.cpp lines 194-206

void* __cdecl operator_new(unsigned int size);

class PointMaker {
public:
    char gap_000[0xFD4];
    int Width;           // +0xFD4
    int Height;          // +0xFD8
    char gap_FDC[0x28];
    int SizeArrays;      // +0x1004
    char gap_1008[0x1C];
    char* ProbArray;     // +0x1024
    char* PlacementArray;// +0x1028

    void MakeArrays();
};

void PointMaker::MakeArrays() {
    int size = Height * Width;
    SizeArrays = size;

    int count = 9;
    do {
        if (ProbArray != 0) break;
        ProbArray = (char*)operator_new(size);
    } while (count-- != 0);

    count = 9;
    do {
        if (PlacementArray != 0) return;
        PlacementArray = (char*)operator_new(size);
    } while (count-- != 0);
}
