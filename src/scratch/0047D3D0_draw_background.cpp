// VA: 0047D3D0 draw_background (410B)
// Pnl_txt.cpp

class TTextPanel {
public:
    char gap4[0x1C];
    int field_20;
    char gap24[0x120];
    int field_144;
    
    void draw_background();
};

void TTextPanel::draw_background() {
    if (!field_144) return;
    
    // Draw panel background
    field_20 = 1;
}
