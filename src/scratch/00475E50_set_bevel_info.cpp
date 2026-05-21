// VA: 00475E50 set_bevel_info (168B)
// pnl_edit.cpp lines 474-509
// tried: fixed virtual base/data offsets and thiscall vtable slots; switch/table exact except masked table address.
// tried simple field order, c2/type/c1 locals, swapped formal names, explicit rect locals; VC5 keeps AL/CL/DL byte-param coloring and tail load registers different from original.
// tried /O1 briefly; wrong EBP-frame family, removed flag.
// left in scratch: remaining drift is localized register allocation/scheduling for byte parameter stores and set_rect argument loads; behavior/call slots/field offsets/switch cases look correct.

class TPanel {
public:
    virtual ~TPanel();              // slot 0
    virtual void v1();              // slot 1
    virtual void v2();              // slot 2
    virtual void set_rect(int left, int top, int right, int bottom); // slot 3 (+0x0C)
    virtual void v4();              // slot 4
    virtual void v5();              // slot 5
    virtual void v6();              // slot 6
    virtual void v7();              // slot 7
    virtual void set_redraw(int redraw); // slot 8 (+0x20)

    char gap_04[8];                 // +04..+0B
    int left;                       // +0C
    int top;                        // +10
    int right;                      // +14
    int bottom;                     // +18
};

class TEditPanel : public TPanel {
public:
    char gap_1C[0x134];             // +1C..+14F
    int bevel_type;                 // +150
    unsigned char bevel_color1;     // +154
    unsigned char bevel_color2;     // +155
    unsigned char bevel_color3;     // +156
    unsigned char bevel_color4;     // +157
    unsigned char bevel_color5;     // +158
    unsigned char bevel_color6;     // +159
    char gap_15A[2];
    int bevel_size;                 // +15C

    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
};

void TEditPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6) {
    this->bevel_color1 = (unsigned char)c1;
    this->bevel_color2 = (unsigned char)c2;
    this->bevel_type = type;
    this->bevel_color3 = (unsigned char)c3;
    this->bevel_color4 = (unsigned char)c4;
    this->bevel_color5 = (unsigned char)c5;
    this->bevel_color6 = (unsigned char)c6;

    switch (type) {
    case 1:
    case 2:
    case 5:
        this->bevel_size = 1;
        break;
    case 3:
    case 6:
        this->bevel_size = 2;
        break;
    case 4:
    case 7:
        this->bevel_size = 3;
        break;
    default:
        this->bevel_size = 0;
        break;
    }

    int btm = this->bottom;
    int rgt = this->right;
    int tp = this->top;
    int lft = this->left;
    this->set_rect(lft, tp, rgt, btm);
    this->set_redraw(1);
}
