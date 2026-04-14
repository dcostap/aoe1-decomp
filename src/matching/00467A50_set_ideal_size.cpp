class TRIBE_Screen_Sed_Open {
public:
    char gap_0[0xF4];
    int field_F4;
    int field_F8;
    void set_ideal_size(int a, int b);
};

void TRIBE_Screen_Sed_Open::set_ideal_size(int a, int b) {
    this->field_F4 = a;
    this->field_F8 = b;
}
