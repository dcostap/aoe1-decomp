class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFC4];
    int field_FC8;
    void SetChanceOfNextNode(int v);
};

void PointMaker::SetChanceOfNextNode(int v) { this->field_FC8 = v; }
