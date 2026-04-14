class Path {
public:
    virtual ~Path();
    char gap_0[0x28];
    int field_2C;
    int numberOfWaypoints();
};

int Path::numberOfWaypoints() { return this->field_2C; }
