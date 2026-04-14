class TEasy_Panel {
public:
    char gap_0[0x328];
    int field_328;
    int field_32C;

    void get_text_colors(int* out1, int* out2);
};

void TEasy_Panel::get_text_colors(int* out1, int* out2) {
    *out1 = this->field_328;
    *out2 = this->field_32C;
}
