#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0x1008];
    int field_100C;
    void SetBranchDistance(int v);
};
#endif

void PointMaker::SetBranchDistance(int v) { this->field_100C = v; }
