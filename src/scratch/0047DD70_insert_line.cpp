// VA: 0047DD70 insert_line (541B)
// Pnl_txt.cpp

class TTextPanel {
public:
    char gap4[0xF0];
    int field_F4;
    char gapF8[0x88];
    int field_180;
    
    void insert_line(int a1, int a2);
};

void* __cdecl malloc4(unsigned size);

void TTextPanel::insert_line(int a1, int a2) {
    void* buf = malloc4(0x10 * a1);
    if (!buf) return;
    
    // Insert line at position
    field_F4 = (int)buf;
}
