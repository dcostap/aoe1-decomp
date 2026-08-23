#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFC8];
    int field_FCC;
    void SetMaxNumberOfBranches(int v);
};
#endif

void PointMaker::SetMaxNumberOfBranches(int v) { this->field_FCC = v; }
