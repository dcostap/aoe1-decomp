class TEditPanel {
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
    char gap_0[0x114];
    int field_114;
    int field_118;

    void set_text_color(int a, int b);
};

void TEditPanel::set_text_color(int a, int b) {
    this->field_114 = a;
    this->field_118 = b;
    this->notify(1);
}
