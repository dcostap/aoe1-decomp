class TEasy_Panel {
public:
    char gap_0[0x330];
    int field_330;
    int field_334;

    void get_focus_colors(int* out1, int* out2);
};

void TEasy_Panel::get_focus_colors(int* out1, int* out2) {
    *out1 = this->field_330;
    *out2 = this->field_334;
}
