class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFFC];
    int field_1000;
    void SetStartPositionRadius(int v);
};

void PointMaker::SetStartPositionRadius(int v) { this->field_1000 = v; }
