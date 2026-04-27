// VA: 0047BF40 TTextPanel ctor (325B)
// Pnl_txt.cpp

void __cdecl sub_004648B0(void* this_);

class TTextPanel {
public:
    char gap4[0x14C];
    char field_150;
    char gap151[0x9];
    int field_15C;
    char gap160[0x120];
    int field_280;
    
    TTextPanel(int a1, int a2, int a3, int a4);
};

TTextPanel::TTextPanel(int a1, int a2, int a3, int a4) {
    sub_004648B0(this);
    
    field_150 = -1;
    field_15C = 0;
    field_280 = 0;
}
