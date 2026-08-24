#ifndef PATH_TU_CONTEXT
class Path {
public:
    virtual ~Path();
    char gap_0[0x2C];
    int field_30;
    void initToStart();
};
#endif

#ifdef PATH_TU_CONTEXT
void Path::initToStart() { this->currentWaypointValue = 0; }
#else
void Path::initToStart() { this->field_30 = 0; }
#endif
