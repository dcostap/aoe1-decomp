class TTextPanel {
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
    char gap_4[0x116];
    int field_11C;

    void set_style(int value);
};

void TTextPanel::set_style(int value) {
    this->field_11C = value;
    this->notify(1);
}
