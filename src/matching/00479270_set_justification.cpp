class TMessagePanel {
public:
    char gap_0[0x320];
    int field_320;
    int field_324;
    int field_328;
    void set_justification(int a, int b, int c);
};

void TMessagePanel::set_justification(int a, int b, int c) {
    this->field_320 = a;
    this->field_324 = b;
    this->field_328 = c;
}
