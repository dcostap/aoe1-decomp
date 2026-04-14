class Path {
public:
    virtual ~Path();
    char gap_0[0x2C];
    int field_30;
    int currentWaypointNumber();
};

int Path::currentWaypointNumber() { return this->field_30; }
