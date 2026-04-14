class TRIBE_Panel_Button {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void notify(int param);
    char gap_0[0x2BC];
    int field_2BC;

    void set_garrison_number(int value);
};

void TRIBE_Panel_Button::set_garrison_number(int value) {
    this->field_2BC = value;
    this->notify(1);
}
