class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0x1020];
    int field_1024;
    int RetrieveProbMap();
};

int PointMaker::RetrieveProbMap() { return this->field_1024; }
