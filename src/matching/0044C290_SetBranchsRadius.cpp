#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFF4];
    int field_FF8;
    void SetBranchsRadius(int v);
};
#endif

void PointMaker::SetBranchsRadius(int v) { this->field_FF8 = v; }
