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
    char gap_0[0x120];
    int field_120;
    int field_124;

    void set_text_color(int a, int b);
};

void TTextPanel::set_text_color(int a, int b) {
    this->field_120 = a;
    this->field_124 = b;
    this->notify(1);
}
