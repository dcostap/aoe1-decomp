class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0xFBC];
    int field_FC0;
    void SetSplitsPerBranch(int v);
};

void PointMaker::SetSplitsPerBranch(int v) { this->field_FC0 = v; }
