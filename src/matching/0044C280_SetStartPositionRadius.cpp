#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFFC];
    int field_1000;
    void SetStartPositionRadius(int v);
};
#endif

void PointMaker::SetStartPositionRadius(int v) { this->field_1000 = v; }
