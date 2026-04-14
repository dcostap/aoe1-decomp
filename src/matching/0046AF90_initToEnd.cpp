class Path {
public:
    char gap_0[0x2C];
    int field_2C;
    int field_30;
    void initToEnd();
};

void Path::initToEnd() {
    this->field_30 = this->field_2C - 1;
}
