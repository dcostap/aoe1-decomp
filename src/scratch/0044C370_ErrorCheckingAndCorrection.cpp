// VA: 0044C370 ErrorCheckingAndCorrection (318B)
// fractal.cpp

class RGE_Fractal {
public:
    char gap4[0xFD0];
    int field_FD4;
    int field_FD8;
    char gapFDC[0x1C];
    int field_FF8;
    char gapFFC[0x8];
    int field_1004;
    
    void ErrorCheckingAndCorrection();
};

void RGE_Fractal::ErrorCheckingAndCorrection() {
    int area = field_FD4 * field_FD8;
    field_1004 = area;
    
    if (field_FF8 > field_FD4) {
        // Correction needed
        int correction = field_FF8 * 2;
    }
}
