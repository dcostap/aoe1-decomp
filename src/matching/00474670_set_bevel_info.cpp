// 00474670 TDropDownPanel::set_bevel_info
// Source: Pnl_drop.cpp lines 327-381
// Attempt log:
// 1: natural four-panel forwarding with switches; virtual helper padded to slot 0xEC and direct scrollbar/button calls.

class BevelVirtualPanel {
public:
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6); // +0xEC
};

class TScrollBarPanel {
public:
    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
};

class TButtonPanel {
public:
    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
};

class TDropDownPanel {
public:
    char gap_00[0xF4];
    BevelVirtualPanel* val_panel;       // +0xF4
    TButtonPanel* btn_panel;            // +0xF8
    BevelVirtualPanel* list_panel;      // +0xFC
    TScrollBarPanel* scbar_panel;       // +0x100

    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
};

void TDropDownPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6)
{
    if (this->val_panel != 0) {
        int mapped;
        switch (type) {
        case 1: mapped = 1; break;
        case 2: mapped = 5; break;
        case 3: mapped = 6; break;
        case 4: mapped = 7; break;
        default: mapped = 0; break;
        }
        this->val_panel->set_bevel_info(mapped, c1, c2, c3, c4, c5, c6);
    }

    if (this->list_panel != 0) {
        int mapped;
        switch (type) {
        case 1: mapped = 1; break;
        case 2: mapped = 2; break;
        case 3: mapped = 3; break;
        case 4: mapped = 4; break;
        default: mapped = 0; break;
        }
        this->list_panel->set_bevel_info(mapped, c1, c2, c3, c4, c5, c6);
    }

    if (this->scbar_panel != 0) {
        int mapped;
        switch (type) {
        case 1: mapped = 1; break;
        case 2: mapped = 2; break;
        case 3: mapped = 3; break;
        case 4: mapped = 4; break;
        default: mapped = 0; break;
        }
        this->scbar_panel->set_bevel_info(mapped, c1, c2, c3, c4, c5, c6);
    }

    if (this->btn_panel != 0) {
        int mapped;
        switch (type) {
        case 1: mapped = 1; break;
        case 2: mapped = 2; break;
        case 3: mapped = 3; break;
        case 4: mapped = 4; break;
        default: mapped = 0; break;
        }
        this->btn_panel->set_bevel_info(mapped, c1, c2, c3, c4, c5, c6);
    }
}
