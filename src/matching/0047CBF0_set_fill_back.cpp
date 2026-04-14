class TTextPanel {
public:
    char gap_0[0x14C];
    int field_14C;
    unsigned char field_150;

    void set_fill_back(int a, unsigned char b);
};

void TTextPanel::set_fill_back(int a, unsigned char b) {
    this->field_14C = a;
    this->field_150 = b;
}
