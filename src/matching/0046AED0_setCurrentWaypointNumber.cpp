#ifndef PATH_TU_CONTEXT
class Path {
public:
    virtual ~Path();
    char gap_0[0x2C];
    int field_30;
    void setCurrentWaypointNumber(int v);
};
#endif

#ifdef PATH_TU_CONTEXT
void Path::setCurrentWaypointNumber(int v) { this->currentWaypointValue = v; }
#else
void Path::setCurrentWaypointNumber(int v) { this->field_30 = v; }
#endif
