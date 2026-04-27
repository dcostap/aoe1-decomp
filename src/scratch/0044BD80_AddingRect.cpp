// VA: 0044BD80 AddingRect (516B)
// fractal.cpp

class RGE_Fractal {
public:
    char gap4[0xFD0];
    int field_FD4;
    int field_FD8;
    char gapFDC[0x28];
    int field_1004;
    
    void AddingRect(int x, int y, int w, int h);
};

void RGE_Fractal::AddingRect(int x, int y, int w, int h) {
    int stride = field_FD4;
    if (stride <= 0) return;
    
    int pos = y * stride + x;
    field_1004 = pos;
}
