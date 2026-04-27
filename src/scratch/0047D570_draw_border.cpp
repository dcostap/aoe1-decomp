// VA: 0047D570 draw_border (453B)
// Pnl_txt.cpp

class TTextPanel {
public:
    char gap4[0x1C];
    int field_20;
    char gap24[0x14C];
    int field_170;
    
    void draw_border();
};

int __cdecl sub_00444270(int a1, int a2);

void TTextPanel::draw_border() {
    if (!field_170) return;
    
    int result = sub_00444270(field_20, 0x5854E0);
    if (!result) return;
    
    // Draw border around panel
}
