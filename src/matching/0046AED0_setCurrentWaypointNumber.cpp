class Path {
public:
    virtual ~Path();
    char gap_0[0x2C];
    int field_30;
    void setCurrentWaypointNumber(int v);
};

void Path::setCurrentWaypointNumber(int v) { this->field_30 = v; }
