// VA: 0044AFE0 DrawMask (550B)
// fractal.cpp

class RGE_Fractal {
public:
    char gap4[0xFD0];
    int field_FD4;
    int field_FD8;
    char gapFDC[0x1C];
    int field_FF8;
    
    void DrawMask(int x, int y);
};

void RGE_Fractal::DrawMask(int x, int y) {
    if (x > field_FD4) return;
    
    int width = field_FD8;
    if (width > 0) {
        field_FF8 = x + y;
    }
}
