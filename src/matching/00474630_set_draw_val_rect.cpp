class TTextPanel {
public:
    void set_outline(int rect, unsigned char color);
};

class TDropDownPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void redraw(int value);

    char gap_04[0xF0];
    TTextPanel* val_panel;
    char gap_F8[0x40];
    unsigned char outline_color;
    char gap_139[0x07];
    int draw_val_rect;

    void set_draw_val_rect(int value);
};

void TDropDownPanel::set_draw_val_rect(int value) {
    this->draw_val_rect = value;
    if (this->val_panel != 0) {
        this->val_panel->set_outline(value, this->outline_color);
        this->redraw(1);
    }
}
