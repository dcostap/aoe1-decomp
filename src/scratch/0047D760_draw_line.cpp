// VA: 0047D760 draw_line (634B)
// Pnl_txt.cpp

class TTextPanel {
public:
    char gap4[0xE0];
    int field_E4;
    char gapE8[0x10];
    int field_F8;
    char gapFC[0x28];
    int field_124;
    
    void draw_line(int lineIdx, int a2);
};

void TTextPanel::draw_line(int lineIdx, int a2) {
    field_E4 = lineIdx;
    
    if (field_F8 > 0) {
        field_124 = a2;
    }
}
