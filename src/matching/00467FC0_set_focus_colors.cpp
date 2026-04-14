class TEasy_Panel {
public:
    char gap_0[0x330];
    int field_330;
    int field_334;
    void set_focus_colors(int a, int b);
};

void TEasy_Panel::set_focus_colors(int a, int b) {
    this->field_330 = a;
    this->field_334 = b;
}
