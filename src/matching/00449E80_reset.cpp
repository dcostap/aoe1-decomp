class TDigital_Sound_Driver {
public:
    char gap_0[0x5C];
    int field_5C;
    int field_60;
    void reset();
};

void TDigital_Sound_Driver::reset() {
    this->field_60 = this->field_5C;
}
