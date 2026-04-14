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
    char gap_0[0x110];
    int field_110;
    int field_114;

    void set_alignment(int a, int b);
};

void TTextPanel::set_alignment(int a, int b) {
    this->field_110 = a;
    this->field_114 = b;
    this->notify(1);
}
