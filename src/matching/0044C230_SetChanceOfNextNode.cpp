#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFC4];
    int field_FC8;
    void SetChanceOfNextNode(int v);
};
#endif

void PointMaker::SetChanceOfNextNode(int v) { this->field_FC8 = v; }
