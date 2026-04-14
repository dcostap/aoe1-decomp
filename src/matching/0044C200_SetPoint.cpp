class PointMaker {
public:
    char gap_0[0xFB8];
    int field_FB8;
    int field_FBC;
    void SetPoint(int a, int b);
};

void PointMaker::SetPoint(int a, int b) {
    this->field_FB8 = a;
    this->field_FBC = b;
}
