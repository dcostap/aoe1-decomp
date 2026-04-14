class TEasy_Panel {
public:
    char gap_0[0x328];
    int field_328;
    int field_32C;
    void set_text_colors(int a, int b);
};

void TEasy_Panel::set_text_colors(int a, int b) {
    this->field_328 = a;
    this->field_32C = b;
}
