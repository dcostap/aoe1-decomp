class PointMaker {
public:
    virtual ~PointMaker();
    char gap_0[0x1024];
    int field_1028;
    int RetrieveMap();
};

int PointMaker::RetrieveMap() { return this->field_1028; }
