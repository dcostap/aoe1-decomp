// VA: 0047D9E0 calc_line_pos (555B)
// Pnl_txt.cpp

class TTextPanel {
public:
    char gap4[0x150];
    int field_154;
    
    int calc_line_pos(int lineIdx);
};

int __cdecl sub_0047E2A0(int lineIdx);

int TTextPanel::calc_line_pos(int lineIdx) {
    int result = sub_0047E2A0(lineIdx);
    if (!result) return 0;
    
    // Calculate line position
    return field_154;
}
