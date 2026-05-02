// PointMaker::MakeArrays
// VA: 0044B2B0 - variant_lab best: dec_jne + cmp_jne (edit_diff=21)

void* __cdecl operator_new(unsigned int size);

class PointMaker {
public:
    char gap_000[0xFD4];
    int Width;
    int Height;
    char gap_FDC[0x28];
    int SizeArrays;
    char gap_1008[0x1C];
    char* ProbArray;
    char* PlacementArray;

    void MakeArrays();
};

void PointMaker::MakeArrays() {
    SizeArrays = Height * Width;
    int count = 9;
    do {
        if (ProbArray != 0) break;
        ProbArray = (char*)operator_new(SizeArrays);
    } while (--count != 0);
    count = 9;
    while (count != 0) {
        if (PlacementArray != 0) return;
        PlacementArray = (char*)operator_new(SizeArrays);
        count--;
    }
}
