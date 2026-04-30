// 0047AB20 TScrollBarPanel::set_tab_pos
// PDB: Pnl_scbr.cpp:225-253, 239 bytes
// __thiscall, void, ret 4 (1 param: long pos)
// FLAGS: default
//
// Attempt log:
// probe 1: 9.6% — ECX for denom, CDECL virtual call
// probe 2: 5.0% — virtual call fixed via thunk class with 8 dummy vfuncs
//   remaining: EBX↔ECX swap for denom vs tab_min_x/tab_min_y
//
// Parked at 5.0%. Remaining 12 bytes: pure register encoding swap
// (EBX ↔ ECX). All instructions byte-for-byte identical.

class TScrollBarPanel;

class TScrollBarVirtual {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void notify(int flag);  // vtable slot 8 (offset 0x20)
};

class TScrollBarPanel : public TScrollBarVirtual {
public:
    char gap_04[0xF4];
    int list_len;               // +0xF8
    char gap_FC[0x8];
    int list_num;               // +0x104
    char gap_108[0x18];
    int tabSize;                // +0x120
    int tab_y;                  // +0x124
    int tab_min_y;              // +0x128
    int tab_max_y;              // +0x12C
    char gap_130[0x4];
    int tab_x;                  // +0x134
    int tab_min_x;              // +0x138
    int tab_max_x;              // +0x13C
    char gap_140[0x74];
    int orientationValue;       // +0x1B4 (1=horizontal)

    void calc_item_rects();
    void set_tab_pos(long pos);
};

void TScrollBarPanel::set_tab_pos(long pos) {
    int denom = this->list_len;
    this->list_num = (int)pos;

    if (this->orientationValue == 1) {
        // Horizontal orientation
        if (denom > 0) {
            int half = this->tabSize / 2;
            this->tab_x = ((half + this->tab_max_x - this->tab_min_x) * (int)pos) / denom + this->tab_min_x;
        }

        // Clamp
        if (this->tab_x < this->tab_min_x) {
            this->tab_x = this->tab_min_x;
        } else if (this->tab_x > this->tab_max_x) {
            this->tab_x = this->tab_max_x;
        }
    } else {
        // Vertical orientation
        if (denom > 0) {
            if ((int)pos == denom - 1) {
                this->tab_y = this->tab_max_y;
            } else {
                int half = this->tabSize / 2;
                this->tab_y = ((half + this->tab_max_y - this->tab_min_y) * (int)pos) / denom + this->tab_min_y;
            }
        }

        // Clamp
        if (this->tab_y < this->tab_min_y) {
            this->tab_y = this->tab_min_y;
        } else if (this->tab_y > this->tab_max_y) {
            this->tab_y = this->tab_max_y;
        }
    }

    this->calc_item_rects();
    ((TScrollBarVirtual*)this)->notify(1);
}
