class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void set_redraw(int mode);
};

class TButtonPanel : public TPanel {
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x14];
    int field_14;
    char gap_18[0x4C8 - 0x18];
    TButtonPanel* button_panel[17];

    void set_map_buttons_redraw(int mode);
};

void TRIBE_Screen_Game::set_map_buttons_redraw(int mode) {
    if (this->field_14 < 0x320) {
        this->button_panel[5]->set_redraw(mode);
        this->button_panel[11]->set_redraw(mode);
    }
    this->button_panel[15]->set_redraw(mode);
    this->button_panel[16]->set_redraw(mode);
}
