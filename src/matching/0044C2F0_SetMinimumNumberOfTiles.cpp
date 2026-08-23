#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFD8];
    int field_FDC;
    void SetMinimumNumberOfTiles(int v);
};
#endif

void PointMaker::SetMinimumNumberOfTiles(int v) { this->field_FDC = v; }
