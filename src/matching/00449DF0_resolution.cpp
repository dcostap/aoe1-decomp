class TDigital_Sound_Driver {
public:
    char gap_0[0x10];
    short field_10;
    short field_12;
    int resolution();
};

int TDigital_Sound_Driver::resolution() {
    return ((int)this->field_10 << 16) | (int)this->field_12;
}
