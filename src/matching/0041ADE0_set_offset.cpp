class RGE_Active_Sprite {
public:
    char gap_0[0xC];
    int field_C;
    int field_10;
    void set_offset(int a, int b);
};

void RGE_Active_Sprite::set_offset(int a, int b) {
    this->field_C = a;
    this->field_10 = b;
}
