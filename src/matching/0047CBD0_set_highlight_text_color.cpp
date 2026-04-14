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
    char gap_4[0x122];
    int field_128;
    int field_12C;

    void set_highlight_text_color(int a, int b);
};

void TTextPanel::set_highlight_text_color(int a, int b) {
    this->field_128 = a;
    this->field_12C = b;
    this->notify(1);
}
