// VA: 0044BB60 DrawCurrentBranchIntoProbArray (357B)
// fractal.cpp

class RGE_Fractal {
public:
    char gap4[0xFF4];
    int field_FF8;
    char gapFFC[0x8];
    int field_1004;
    
    void DrawCurrentBranchIntoProbArray(int branchIdx);
};

void RGE_Fractal::DrawCurrentBranchIntoProbArray(int branchIdx) {
    int x = *(int*)((char*)this + 8 + branchIdx * 8);
    int y = *(int*)((char*)this + 0x0C + branchIdx * 8);
    
    int probVal = field_FF8;
    if (probVal > 0) {
        field_1004 = x + y;
    }
}
