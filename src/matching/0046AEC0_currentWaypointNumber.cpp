#ifndef PATH_TU_CONTEXT
class Path {
public:
    virtual ~Path();
    char gap_0[0x2C];
    int field_30;
    const int currentWaypointNumber();
};
#endif

#ifdef PATH_TU_CONTEXT
const int Path::currentWaypointNumber() const { return this->currentWaypointValue; }
#else
const int Path::currentWaypointNumber() { return this->field_30; }
#endif
