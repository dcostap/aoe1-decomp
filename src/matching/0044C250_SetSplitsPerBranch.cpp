#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFBC];
    int field_FC0;
    void SetSplitsPerBranch(int v);
};
#endif

void PointMaker::SetSplitsPerBranch(int v) { this->field_FC0 = v; }
