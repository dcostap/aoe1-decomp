class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFF8];
    int field_FFC;
    void SetSatelliteRadius(int v);
};

void PointMaker::SetSatelliteRadius(int v) { this->field_FFC = v; }
