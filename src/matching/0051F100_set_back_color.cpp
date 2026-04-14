class Time_Line_Panel {
public:
    char gap_0[0x4B4];
    int field_4B4;
    unsigned char field_4B8;

    void set_back_color(int a, unsigned char b);
};

void Time_Line_Panel::set_back_color(int a, unsigned char b) {
    this->field_4B4 = a;
    this->field_4B8 = b;
}
