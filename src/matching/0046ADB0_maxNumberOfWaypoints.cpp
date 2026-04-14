class Path {
public:
    virtual ~Path();
    char gap_0[0x24];
    int field_28;
    int maxNumberOfWaypoints();
};

int Path::maxNumberOfWaypoints() { return this->field_28; }
