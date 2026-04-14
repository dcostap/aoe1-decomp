class TMousePointer {
public:
    virtual ~TMousePointer();
    char gap_4[0xB4];
    int field_B8;
    char gap_BC[0x70];
    int field_12C;
    void reset();
};

void TMousePointer::reset() {
    this->field_B8 = 0;
    this->field_12C = 0;
}
