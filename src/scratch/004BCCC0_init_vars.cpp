class TDigital_iv {
public:
    void init_vars(void);
    int field_00;
    int field_04;
    unsigned char field_08;
    unsigned char field_09;
    unsigned char field_0A;
    char gap_0B[0x21];
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
};

void TDigital_iv::init_vars(void) {
    this->field_00 = 0;
    this->field_04 = 0;
    this->field_08 = 0;
    this->field_09 = 0;
    this->field_0A = 0;
    this->field_2C = 0;
    this->field_30 = 0;
    this->field_34 = 0;
    this->field_38 = 0;
    this->field_1C = 0;
    this->field_20 = 0;
    this->field_24 = 0;
    this->field_28 = 0;
}
