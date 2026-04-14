class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0x1038];
    int field_103C;
    void SetDrawToOneArray();
};

void PointMaker::SetDrawToOneArray() { this->field_103C = 1; }
