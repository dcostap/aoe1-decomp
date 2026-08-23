#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0x1004];
    int field_1008;
    void SetSatelliteDistance(int v);
};
#endif

void PointMaker::SetSatelliteDistance(int v) { this->field_1008 = v; }
