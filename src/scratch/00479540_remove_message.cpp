// quick-win attempt: clear the active message, notify the panel vtable, then clear image text state
// if this misses, the remaining gap is likely just the exact call shape for the slot-0x14 / slot-0x20 virtuals
class TPanel {
public:
    void* vtable_ptr;
    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0xB0];

    virtual void pv0();
    virtual void pv1();
    virtual void pv2();
    virtual void pv3();
    virtual void pv4();
    virtual void pv5(int);
    virtual void pv6();
    virtual void pv7();
    virtual void pv8(int);
};

class TMessagePanel : public TPanel {
public:
    char gap_F4[0x204];
    int showing_message;
    char gap_2FC[0x70];
    int ImageTextActive;

    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8(int);

    void remove_message(void);
};

void TMessagePanel::remove_message(void) {
    if (this->showing_message != 0) {
        this->showing_message = 0;
        this->v5(0);
        this->v8(1);
        if (this->parent_panel != 0) {
            this->parent_panel->pv8(1);
        }
    }
    this->ImageTextActive = 0;
}
