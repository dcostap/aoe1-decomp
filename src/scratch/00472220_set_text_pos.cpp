class TButtonPanel {
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
    char gap_0[0x1E0];
    int field_1E0;
    int field_1E4;

    void set_text_pos(int a, int b);
};

void TButtonPanel::set_text_pos(int a, int b) {
    this->field_1E0 = a;
    this->field_1E4 = b;
    this->notify(1);
}
