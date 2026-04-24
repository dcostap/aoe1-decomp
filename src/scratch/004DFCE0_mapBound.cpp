// attempt 1: simple if/else structure; 80 bytes (4 short), VC5 optimizes early returns
// attempt 2: int ret = 1; explicit return var; same 80 bytes
// attempt 3: unified else-if for y check; same 80 bytes
// attempt 4: int ret = 0; ret = 1 after x check; same 80 bytes
// attempt 5: goto pattern matching Ghidra decompiler; same 80 bytes
// Original has 'mov eax,1' at 3 separate code points; VC5 consolidates
// Left in scratch: benign codegen optimization difference, behavior fully correct

struct XYPoint {
    int x;
    int y;
};

class TribeInformationAIModule {
public:
    char gap_00[0x104];
    int mapXSizeValue;
    int mapYSizeValue;

    int mapBound(XYPoint* pt);
};

int TribeInformationAIModule::mapBound(XYPoint* pt) {
    if (pt->x < 0) {
        pt->x = 0;
    } else if (pt->x >= mapXSizeValue) {
        pt->x = mapXSizeValue - 1;
    }
    if (pt->y < 0) {
        pt->y = 0;
    } else if (pt->y >= mapYSizeValue) {
        pt->y = mapYSizeValue - 1;
    }
    return 1;
}
