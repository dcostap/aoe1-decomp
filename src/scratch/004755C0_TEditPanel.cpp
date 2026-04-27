// VA: 004755C0 TEditPanel ctor (170B)
// pnl_edit.cpp lines 50-75

void __cdecl TPanel_ctor(void* this_);

class TEditPanel {
public:
    void* vtable;
    char gap4[0xF0 - 4];
    int field_F4;
    short field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    char gap128[(0x150 - 0x128)];
    int field_150;
    char field_154, field_155, field_156, field_157, field_158, field_159;
    char gap15A[(0x15C - 0x15A)];
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    
    TEditPanel() {
        TPanel_ctor(this);
        field_F4 = 0;
        field_FC = 0;
        field_F8 = 0;
        field_108 = 0;
        field_110 = 0;
        field_114 = 0;
        field_118 = 0;
        field_11C = 0;
        field_120 = 0;
        field_124 = 0;
        field_15C = 0;
        field_154 = 0;
        field_155 = 0;
        field_156 = 0;
        field_157 = 0;
        field_158 = 0;
        field_159 = 0;
        field_160 = 0;
        field_164 = 0;
        field_168 = 0;
        field_150 = 1;
        field_104 = 1;
    }
};
