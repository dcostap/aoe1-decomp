// 00474550 TDropDownPanel::set_rect (Pnl_drop.cpp:262-283, 144B)
// FLAGS: default
// MATCH: 0.0000% (144/144 bytes exact)

class TPanel {
public:
    char gap_00[0x14];
    long field_14;
    long field_18;
    char gap_1C[0xE8];
    long mode;            // +0x104
    char gap_108[4];
    long val_wid;         // +0x10C
    long val_hgt;         // +0x110
    long btn_wid;         // +0x114
    char gap_118[4];
    long list_wid;        // +0x11C
    long list_hgt;        // +0x120

    void set_rect(long p1, long p2, long p3, long p4);
};

class TDropDownPanel : public TPanel {
public:
    void set_rect(long p1, long p2, long p3, long p4);
    void set_mode(int mode);
};

void TDropDownPanel::set_rect(long p1, long p2, long p3, long p4)
{
    TPanel::set_rect(p1, p2, p3, p4);

    if (this->mode == 1) {
        this->val_wid = (this->field_14 - this->btn_wid) - 1;
        this->val_hgt = this->field_18;
        this->set_mode(0);
        this->set_mode(1);
        return;
    }

    if (this->mode == 2) {
        this->list_wid = this->field_14;
        this->list_hgt = (this->field_18 - this->val_hgt) - 1;
        this->set_mode(1);
        this->set_mode(2);
    }
}
