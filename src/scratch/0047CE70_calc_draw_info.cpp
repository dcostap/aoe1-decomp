// VA: 0047CE70 calc_draw_info (496B)
// Pnl_txt.cpp

class TTextPanel {
public:
    char gap4[0x108];
    int field_10C;
    char gap110[0x30];
    int field_140;
    char gap144[0x20];
    int field_164;
    
    void calc_draw_info();
};

void TTextPanel::calc_draw_info() {
    int count = field_10C;
    field_140 = count + 2;
    
    if (count > 0) {
        field_164 = field_140;
    }
}
