class Path {
public:
    char gap_0[0x2C];
    int field_2C;
    int field_30;
    void killPath();
};

void Path::killPath() {
    this->field_2C = 0;
    this->field_30 = 0;
}
