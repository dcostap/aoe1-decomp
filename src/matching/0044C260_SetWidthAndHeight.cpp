class PointMaker {
public:
    char gap_0[0xFD4];
    int field_FD4;
    int field_FD8;
    void SetWidthAndHeight(int a, int b);
};

void PointMaker::SetWidthAndHeight(int a, int b) {
    this->field_FD4 = a;
    this->field_FD8 = b;
}
