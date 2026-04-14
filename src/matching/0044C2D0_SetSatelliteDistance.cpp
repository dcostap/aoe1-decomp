class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0x1004];
    int field_1008;
    void SetSatelliteDistance(int v);
};

void PointMaker::SetSatelliteDistance(int v) { this->field_1008 = v; }
