#ifndef PATH_TU_CONTEXT
class Path {
public:
    virtual ~Path();
    char gap_0[0x24];
    int field_28;
    int maxNumberOfWaypoints();
};
#endif

#ifdef PATH_TU_CONTEXT
int Path::maxNumberOfWaypoints() const { return this->maxSizeValue; }
#else
int Path::maxNumberOfWaypoints() { return this->field_28; }
#endif
