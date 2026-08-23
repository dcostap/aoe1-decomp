// fixed local TPanel surface: vptr is implicit; this restores parent/message offsets and vf14/vf20 calls
#ifndef AOE1_PNL_MSG_CONTEXT_H
class TPanel {
public:
    virtual void pv0();
    virtual void pv1();
    virtual void pv2();
    virtual void pv3();
    virtual void pv4();
    virtual void set_active(int);
    virtual void pv6();
    virtual void pv7();
    virtual void set_redraw(int);

    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0xB0];
};

class TMessagePanel : public TPanel {
public:
    char gap_F4[0x204];
    int showing_message;
    char gap_2FC[0x70];
    int ImageTextActive;

    void remove_message(void);
};
#endif

void TMessagePanel::remove_message(void) {
    if (this->showing_message != 0) {
        this->showing_message = 0;
        this->set_active(0);
        this->set_redraw(1);
        if (this->parent_panel != 0) {
            this->parent_panel->set_redraw(1);
        }
    }
    this->ImageTextActive = 0;
}
