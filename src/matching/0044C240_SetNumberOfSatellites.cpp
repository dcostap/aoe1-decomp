#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFC0];
    int field_FC4;
    void SetNumberOfSatellites(int v);
};
#endif

void PointMaker::SetNumberOfSatellites(int v) { this->field_FC4 = v; }
